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
     tDistanceFunction = 334,
     tDefineConstant = 335,
     tUndefineConstant = 336,
     tDefineNumber = 337,
     tDefineStruct = 338,
     tNameStruct = 339,
     tDimNameSpace = 340,
     tAppend = 341,
     tDefineString = 342,
     tSetNumber = 343,
     tSetTag = 344,
     tSetString = 345,
     tPoint = 346,
     tCircle = 347,
     tEllipse = 348,
     tCurve = 349,
     tSphere = 350,
     tPolarSphere = 351,
     tSurface = 352,
     tSpline = 353,
     tVolume = 354,
     tBox = 355,
     tCylinder = 356,
     tCone = 357,
     tTorus = 358,
     tEllipsoid = 359,
     tQuadric = 360,
     tShapeFromFile = 361,
     tRectangle = 362,
     tDisk = 363,
     tWire = 364,
     tGeoEntity = 365,
     tCharacteristic = 366,
     tLength = 367,
     tParametric = 368,
     tElliptic = 369,
     tRefineMesh = 370,
     tAdaptMesh = 371,
     tRelocateMesh = 372,
     tReorientMesh = 373,
     tSetFactory = 374,
     tThruSections = 375,
     tWedge = 376,
     tFillet = 377,
     tChamfer = 378,
     tPlane = 379,
     tRuled = 380,
     tTransfinite = 381,
     tPhysical = 382,
     tCompound = 383,
     tPeriodic = 384,
     tParent = 385,
     tUsing = 386,
     tPlugin = 387,
     tDegenerated = 388,
     tRecursive = 389,
     tRotate = 390,
     tTranslate = 391,
     tSymmetry = 392,
     tDilate = 393,
     tExtrude = 394,
     tLevelset = 395,
     tAffine = 396,
     tBooleanUnion = 397,
     tBooleanIntersection = 398,
     tBooleanDifference = 399,
     tBooleanSection = 400,
     tBooleanFragments = 401,
     tThickSolid = 402,
     tRecombine = 403,
     tSmoother = 404,
     tSplit = 405,
     tDelete = 406,
     tCoherence = 407,
     tIntersect = 408,
     tMeshAlgorithm = 409,
     tReverseMesh = 410,
     tLayers = 411,
     tScaleLast = 412,
     tHole = 413,
     tAlias = 414,
     tAliasWithOptions = 415,
     tCopyOptions = 416,
     tQuadTriAddVerts = 417,
     tQuadTriNoNewVerts = 418,
     tRecombLaterals = 419,
     tTransfQuadTri = 420,
     tText2D = 421,
     tText3D = 422,
     tInterpolationScheme = 423,
     tTime = 424,
     tCombine = 425,
     tBSpline = 426,
     tBezier = 427,
     tNurbs = 428,
     tNurbsOrder = 429,
     tNurbsKnots = 430,
     tColor = 431,
     tColorTable = 432,
     tFor = 433,
     tIn = 434,
     tEndFor = 435,
     tIf = 436,
     tElseIf = 437,
     tElse = 438,
     tEndIf = 439,
     tExit = 440,
     tAbort = 441,
     tField = 442,
     tReturn = 443,
     tCall = 444,
     tSlide = 445,
     tMacro = 446,
     tShow = 447,
     tHide = 448,
     tGetValue = 449,
     tGetStringValue = 450,
     tGetEnv = 451,
     tGetString = 452,
     tGetNumber = 453,
     tUnique = 454,
     tHomology = 455,
     tCohomology = 456,
     tBetti = 457,
     tExists = 458,
     tFileExists = 459,
     tGetForced = 460,
     tGetForcedStr = 461,
     tGMSH_MAJOR_VERSION = 462,
     tGMSH_MINOR_VERSION = 463,
     tGMSH_PATCH_VERSION = 464,
     tGmshExecutableName = 465,
     tSetPartition = 466,
     tNameToString = 467,
     tStringToName = 468,
     tAFFECTDIVIDE = 469,
     tAFFECTTIMES = 470,
     tAFFECTMINUS = 471,
     tAFFECTPLUS = 472,
     tOR = 473,
     tAND = 474,
     tNOTEQUAL = 475,
     tEQUAL = 476,
     tGREATERGREATER = 477,
     tLESSLESS = 478,
     tGREATEROREQUAL = 479,
     tLESSOREQUAL = 480,
     UNARYPREC = 481,
     tMINUSMINUS = 482,
     tPLUSPLUS = 483
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
#define tDistanceFunction 334
#define tDefineConstant 335
#define tUndefineConstant 336
#define tDefineNumber 337
#define tDefineStruct 338
#define tNameStruct 339
#define tDimNameSpace 340
#define tAppend 341
#define tDefineString 342
#define tSetNumber 343
#define tSetTag 344
#define tSetString 345
#define tPoint 346
#define tCircle 347
#define tEllipse 348
#define tCurve 349
#define tSphere 350
#define tPolarSphere 351
#define tSurface 352
#define tSpline 353
#define tVolume 354
#define tBox 355
#define tCylinder 356
#define tCone 357
#define tTorus 358
#define tEllipsoid 359
#define tQuadric 360
#define tShapeFromFile 361
#define tRectangle 362
#define tDisk 363
#define tWire 364
#define tGeoEntity 365
#define tCharacteristic 366
#define tLength 367
#define tParametric 368
#define tElliptic 369
#define tRefineMesh 370
#define tAdaptMesh 371
#define tRelocateMesh 372
#define tReorientMesh 373
#define tSetFactory 374
#define tThruSections 375
#define tWedge 376
#define tFillet 377
#define tChamfer 378
#define tPlane 379
#define tRuled 380
#define tTransfinite 381
#define tPhysical 382
#define tCompound 383
#define tPeriodic 384
#define tParent 385
#define tUsing 386
#define tPlugin 387
#define tDegenerated 388
#define tRecursive 389
#define tRotate 390
#define tTranslate 391
#define tSymmetry 392
#define tDilate 393
#define tExtrude 394
#define tLevelset 395
#define tAffine 396
#define tBooleanUnion 397
#define tBooleanIntersection 398
#define tBooleanDifference 399
#define tBooleanSection 400
#define tBooleanFragments 401
#define tThickSolid 402
#define tRecombine 403
#define tSmoother 404
#define tSplit 405
#define tDelete 406
#define tCoherence 407
#define tIntersect 408
#define tMeshAlgorithm 409
#define tReverseMesh 410
#define tLayers 411
#define tScaleLast 412
#define tHole 413
#define tAlias 414
#define tAliasWithOptions 415
#define tCopyOptions 416
#define tQuadTriAddVerts 417
#define tQuadTriNoNewVerts 418
#define tRecombLaterals 419
#define tTransfQuadTri 420
#define tText2D 421
#define tText3D 422
#define tInterpolationScheme 423
#define tTime 424
#define tCombine 425
#define tBSpline 426
#define tBezier 427
#define tNurbs 428
#define tNurbsOrder 429
#define tNurbsKnots 430
#define tColor 431
#define tColorTable 432
#define tFor 433
#define tIn 434
#define tEndFor 435
#define tIf 436
#define tElseIf 437
#define tElse 438
#define tEndIf 439
#define tExit 440
#define tAbort 441
#define tField 442
#define tReturn 443
#define tCall 444
#define tSlide 445
#define tMacro 446
#define tShow 447
#define tHide 448
#define tGetValue 449
#define tGetStringValue 450
#define tGetEnv 451
#define tGetString 452
#define tGetNumber 453
#define tUnique 454
#define tHomology 455
#define tCohomology 456
#define tBetti 457
#define tExists 458
#define tFileExists 459
#define tGetForced 460
#define tGetForcedStr 461
#define tGMSH_MAJOR_VERSION 462
#define tGMSH_MINOR_VERSION 463
#define tGMSH_PATCH_VERSION 464
#define tGmshExecutableName 465
#define tSetPartition 466
#define tNameToString 467
#define tStringToName 468
#define tAFFECTDIVIDE 469
#define tAFFECTTIMES 470
#define tAFFECTMINUS 471
#define tAFFECTPLUS 472
#define tOR 473
#define tAND 474
#define tNOTEQUAL 475
#define tEQUAL 476
#define tGREATERGREATER 477
#define tLESSLESS 478
#define tGREATEROREQUAL 479
#define tLESSOREQUAL 480
#define UNARYPREC 481
#define tMINUSMINUS 482
#define tPLUSPLUS 483




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
#line 736 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 749 "Gmsh.tab.cpp"

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
#define YYLAST   16320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  251
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  608
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   483

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   236,     2,   248,     2,   233,   235,     2,
     241,   242,   231,   229,   250,   230,   247,   232,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     223,     2,   224,   218,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   243,     2,   244,   240,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   245,   234,   246,   249,     2,     2,     2,
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
     215,   216,   217,   219,   220,   221,   222,   225,   226,   227,
     228,   237,   238,   239
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
    1504,  1507,  1524,  1536,  1543,  1552,  1561,  1572,  1574,  1577,
    1580,  1582,  1586,  1590,  1595,  1600,  1602,  1604,  1610,  1622,
    1636,  1637,  1645,  1646,  1660,  1661,  1677,  1678,  1685,  1695,
    1698,  1702,  1713,  1727,  1729,  1732,  1738,  1746,  1749,  1752,
    1756,  1759,  1763,  1766,  1770,  1780,  1787,  1789,  1791,  1793,
    1795,  1797,  1798,  1801,  1805,  1809,  1814,  1824,  1829,  1844,
    1845,  1849,  1850,  1852,  1853,  1856,  1857,  1860,  1861,  1864,
    1871,  1879,  1886,  1892,  1896,  1905,  1914,  1923,  1932,  1941,
    1947,  1952,  1959,  1971,  1983,  2002,  2021,  2034,  2047,  2060,
    2071,  2076,  2081,  2086,  2091,  2096,  2099,  2103,  2110,  2112,
    2114,  2116,  2119,  2125,  2133,  2144,  2146,  2150,  2153,  2156,
    2159,  2163,  2167,  2171,  2175,  2179,  2183,  2187,  2191,  2195,
    2199,  2203,  2207,  2211,  2215,  2219,  2223,  2227,  2231,  2237,
    2242,  2247,  2252,  2257,  2262,  2267,  2272,  2277,  2282,  2287,
    2294,  2299,  2304,  2309,  2314,  2319,  2324,  2329,  2334,  2341,
    2348,  2355,  2360,  2362,  2364,  2366,  2368,  2370,  2372,  2374,
    2376,  2378,  2380,  2382,  2383,  2390,  2392,  2397,  2404,  2406,
    2411,  2416,  2421,  2428,  2434,  2442,  2451,  2462,  2467,  2472,
    2479,  2484,  2488,  2491,  2497,  2503,  2507,  2513,  2520,  2529,
    2536,  2545,  2552,  2557,  2565,  2572,  2579,  2586,  2591,  2598,
    2603,  2604,  2607,  2608,  2611,  2612,  2620,  2622,  2626,  2628,
    2630,  2633,  2634,  2638,  2640,  2643,  2646,  2650,  2654,  2666,
    2676,  2684,  2692,  2694,  2698,  2700,  2702,  2705,  2709,  2714,
    2720,  2722,  2726,  2728,  2731,  2735,  2739,  2745,  2750,  2755,
    2758,  2763,  2766,  2770,  2774,  2791,  2797,  2799,  2801,  2803,
    2807,  2813,  2821,  2826,  2831,  2836,  2843,  2850,  2859,  2868,
    2873,  2888,  2893,  2898,  2900,  2902,  2906,  2910,  2920,  2928,
    2930,  2936,  2940,  2947,  2949,  2953,  2955,  2957,  2962,  2967,
    2971,  2977,  2984,  2993,  3000,  3006,  3012,  3018,  3024,  3026,
    3031,  3033,  3035,  3037,  3039,  3044,  3051,  3056,  3063,  3069,
    3077,  3082,  3087,  3092,  3101,  3106,  3111,  3116,  3121,  3130,
    3139,  3146,  3151,  3158,  3163,  3165,  3170,  3175,  3176,  3183,
    3188,  3191,  3196,  3201,  3203,  3205,  3209,  3211,  3213,  3217,
    3221,  3225,  3231,  3239,  3245,  3251,  3260,  3262,  3264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     252,     0,    -1,   253,    -1,     1,     6,    -1,    -1,   253,
     254,    -1,   256,    -1,   257,    -1,   277,    -1,   119,   241,
     353,   242,     6,    -1,   295,    -1,   301,    -1,   305,    -1,
     306,    -1,   307,    -1,   308,    -1,   312,    -1,   321,    -1,
     322,    -1,   328,    -1,   329,    -1,   311,    -1,   310,    -1,
     309,    -1,   304,    -1,   331,    -1,   224,    -1,   225,    -1,
      44,   241,   353,   242,     6,    -1,    45,   241,   353,   242,
       6,    -1,    44,   241,   353,   242,   255,   353,     6,    -1,
      44,   241,   353,   250,   349,   242,     6,    -1,    45,   241,
     353,   250,   349,   242,     6,    -1,    44,   241,   353,   250,
     349,   242,   255,   353,     6,    -1,   363,   353,   245,   258,
     246,     6,    -1,   159,     4,   243,   332,   244,     6,    -1,
     160,     4,   243,   332,   244,     6,    -1,   161,     4,   243,
     332,   250,   332,   244,     6,    -1,    -1,   258,   261,    -1,
     258,   265,    -1,   258,   268,    -1,   258,   270,    -1,   258,
     271,    -1,   332,    -1,   259,   250,   332,    -1,   332,    -1,
     260,   250,   332,    -1,    -1,    -1,     4,   262,   241,   259,
     242,   263,   245,   260,   246,     6,    -1,   353,    -1,   264,
     250,   353,    -1,    -1,   166,   241,   332,   250,   332,   250,
     332,   242,   266,   245,   264,   246,     6,    -1,   353,    -1,
     267,   250,   353,    -1,    -1,   167,   241,   332,   250,   332,
     250,   332,   250,   332,   242,   269,   245,   267,   246,     6,
      -1,   168,   245,   345,   246,   245,   345,   246,     6,    -1,
     168,   245,   345,   246,   245,   345,   246,   245,   345,   246,
     245,   345,   246,     6,    -1,    -1,   169,   272,   245,   260,
     246,     6,    -1,     7,    -1,   217,    -1,   216,    -1,   215,
      -1,   214,    -1,   239,    -1,   238,    -1,   241,    -1,   243,
      -1,   242,    -1,   244,    -1,    80,   243,   279,   244,     6,
      -1,    81,   243,   283,   244,     6,    -1,   337,     6,    -1,
      88,   275,   354,   250,   332,   276,     6,    -1,    90,   275,
     363,   250,   354,   276,     6,    -1,   363,   273,   346,     6,
      -1,   363,   274,     6,    -1,   363,   275,   276,   273,   346,
       6,    -1,   363,   275,   245,   349,   246,   276,   273,   346,
       6,    -1,   363,   243,   332,   244,   273,   332,     6,    -1,
     363,   243,   332,   244,   274,     6,    -1,   363,   241,   332,
     242,   273,   332,     6,    -1,   363,   241,   332,   242,   274,
       6,    -1,   363,     7,   354,     6,    -1,   363,   275,   276,
       7,    46,   275,   276,     6,    -1,   363,   275,   276,     7,
      46,   275,   358,   276,     6,    -1,   363,   275,   276,   217,
      46,   275,   358,   276,     6,    -1,   363,   247,     4,     7,
     354,     6,    -1,   363,   243,   332,   244,   247,     4,     7,
     354,     6,    -1,   363,   247,     4,   273,   332,     6,    -1,
     363,   243,   332,   244,   247,     4,   273,   332,     6,    -1,
     363,   247,     4,   274,     6,    -1,   363,   243,   332,   244,
     247,     4,   274,     6,    -1,   363,   247,   176,   247,     4,
       7,   350,     6,    -1,   363,   243,   332,   244,   247,   176,
     247,     4,     7,   350,     6,    -1,   363,   247,   177,     7,
     351,     6,    -1,   363,   243,   332,   244,   247,   177,     7,
     351,     6,    -1,   363,   187,     7,   346,     6,    -1,   187,
     243,   332,   244,     7,     4,     6,    -1,   187,   243,   332,
     244,     7,   100,     6,    -1,   187,   243,   332,   244,     7,
     101,     6,    -1,   187,   243,   332,   244,   247,     4,     7,
     332,     6,    -1,   187,   243,   332,   244,   247,     4,     7,
     354,     6,    -1,   187,   243,   332,   244,   247,     4,     7,
     245,   349,   246,     6,    -1,   187,   243,   332,   244,   247,
       4,     6,    -1,   132,   241,     4,   242,   247,     4,     7,
     332,     6,    -1,   132,   241,     4,   242,   247,     4,     7,
     354,     6,    -1,    -1,   250,    -1,    -1,   279,   278,   363,
      -1,   279,   278,   363,     7,   332,    -1,    -1,   279,   278,
     363,     7,   245,   346,   280,   285,   246,    -1,    -1,   279,
     278,   363,   275,   276,     7,   245,   346,   281,   285,   246,
      -1,   279,   278,   363,     7,   354,    -1,    -1,   279,   278,
     363,     7,   245,   354,   282,   289,   246,    -1,    -1,   283,
     278,   353,    -1,   332,     7,   354,    -1,   284,   250,   332,
       7,   354,    -1,   348,     7,   363,   241,   242,    -1,    -1,
     250,   287,    -1,    -1,   287,    -1,   288,    -1,   287,   250,
     288,    -1,     4,   346,    -1,     4,    -1,     4,   245,   284,
     246,    -1,     4,   354,    -1,     4,   357,    -1,    -1,   250,
     290,    -1,   291,    -1,   290,   250,   291,    -1,     4,   332,
      -1,     4,   354,    -1,   191,   354,    -1,     4,   359,    -1,
       4,   357,    -1,   332,    -1,   354,    -1,   354,   250,   332,
      -1,    -1,   179,    95,   245,   332,   246,    -1,   131,    91,
     245,   349,   246,    -1,   131,   110,   245,   349,   246,    -1,
      -1,   124,   343,    -1,    91,   241,   332,   242,     7,   343,
       6,    -1,    94,   241,   332,   242,     7,   346,     6,    -1,
      98,   241,   332,   242,     7,   346,     6,    -1,    92,   241,
     332,   242,     7,   346,   294,     6,    -1,    93,   241,   332,
     242,     7,   346,   294,     6,    -1,   171,   241,   332,   242,
       7,   346,     6,    -1,   172,   241,   332,   242,     7,   346,
       6,    -1,   173,   241,   332,   242,     7,   346,   175,   346,
     174,   332,     6,    -1,   109,   241,   332,   242,     7,   346,
       6,    -1,    94,     4,   241,   332,   242,     7,   346,     6,
      -1,   124,    97,   241,   332,   242,     7,   346,     6,    -1,
      97,   241,   332,   242,     7,   346,   293,     6,    -1,   125,
      97,   241,   332,   242,     7,   346,   293,     6,    -1,    13,
      14,     6,    -1,    14,    97,   332,     6,    -1,   113,    97,
     241,   332,   242,     7,     5,     5,     5,     6,    -1,    95,
     241,   332,   242,     7,   346,     6,    -1,    96,   241,   332,
     242,     7,   346,     6,    -1,   100,   241,   332,   242,     7,
     346,     6,    -1,   103,   241,   332,   242,     7,   346,     6,
      -1,   107,   241,   332,   242,     7,   346,     6,    -1,   108,
     241,   332,   242,     7,   346,     6,    -1,   101,   241,   332,
     242,     7,   346,     6,    -1,   102,   241,   332,   242,     7,
     346,     6,    -1,   121,   241,   332,   242,     7,   346,     6,
      -1,   147,   241,   332,   242,     7,   346,     6,    -1,    97,
       4,   241,   332,   242,     7,   346,     6,    -1,    99,   241,
     332,   242,     7,   346,     6,    -1,   120,   241,   332,   242,
       7,   346,     6,    -1,   125,   120,   241,   332,   242,     7,
     346,     6,    -1,   128,   298,   241,   332,   242,     7,   346,
       6,    -1,   128,   298,   241,   332,   242,     7,   346,     4,
     245,   345,   246,     6,    -1,    -1,   127,   297,   296,   241,
     292,   242,   273,   346,     6,    -1,    91,    -1,    94,    -1,
      97,    -1,    99,    -1,   110,   245,   332,   246,    -1,    94,
      -1,    97,    -1,    99,    -1,   110,   245,   332,   246,    -1,
      94,    -1,    97,    -1,   110,   245,   332,   246,    -1,    91,
      -1,    94,    -1,    97,    -1,   110,   245,   332,   246,    -1,
     136,   343,   245,   302,   246,    -1,   135,   245,   343,   250,
     343,   250,   332,   246,   245,   302,   246,    -1,   137,   343,
     245,   302,   246,    -1,   138,   245,   343,   250,   332,   246,
     245,   302,   246,    -1,   138,   245,   343,   250,   343,   246,
     245,   302,   246,    -1,     4,   245,   302,   246,    -1,   153,
      94,   245,   349,   246,    97,   245,   332,   246,    -1,   150,
      94,   241,   332,   242,   245,   349,   246,     6,    -1,   303,
      -1,   301,    -1,    -1,   303,   295,    -1,   303,   297,   245,
     349,   246,     6,    -1,   303,   127,   297,   245,   349,   246,
       6,    -1,   303,   130,   297,   245,   349,   246,     6,    -1,
     303,   297,   245,     8,   246,     6,    -1,   303,   127,   297,
     245,     8,   246,     6,    -1,   140,   124,   241,   332,   242,
       7,   346,     6,    -1,   140,    91,   241,   332,   242,     7,
     245,   345,   246,     6,    -1,   140,   124,   241,   332,   242,
       7,   245,   343,   250,   343,   250,   349,   246,     6,    -1,
     140,   124,   241,   332,   242,     7,   245,   343,   250,   343,
     250,   343,   250,   349,   246,     6,    -1,   140,    95,   241,
     332,   242,     7,   245,   343,   250,   349,   246,     6,    -1,
     140,   101,   241,   332,   242,     7,   245,   343,   250,   343,
     250,   349,   246,     6,    -1,   140,   102,   241,   332,   242,
       7,   245,   343,   250,   343,   250,   349,   246,     6,    -1,
     140,   104,   241,   332,   242,     7,   245,   343,   250,   343,
     250,   349,   246,     6,    -1,   140,   105,   241,   332,   242,
       7,   245,   343,   250,   343,   250,   349,   246,     6,    -1,
     140,     4,   241,   332,   242,     7,   346,     6,    -1,   140,
       4,   241,   332,   242,     7,     5,     6,    -1,   140,     4,
     245,   332,   246,     6,    -1,   151,   245,   303,   246,    -1,
     134,   151,   245,   303,   246,    -1,   151,   187,   243,   332,
     244,     6,    -1,   151,     4,   243,   332,   244,     6,    -1,
     151,   363,     6,    -1,   151,     4,     4,     6,    -1,   151,
      83,     6,    -1,   176,   350,   245,   303,   246,    -1,   134,
     176,   350,   245,   303,   246,    -1,   211,   332,   245,   303,
     246,    -1,   192,   245,     8,   246,    -1,   192,     5,     6,
      -1,   193,   245,     8,   246,    -1,   193,     5,     6,    -1,
     192,   245,   303,   246,    -1,   134,   192,   245,   303,   246,
      -1,   193,   245,   303,   246,    -1,   134,   193,   245,   303,
     246,    -1,   363,   354,     6,    -1,    73,   241,   360,   242,
       6,    -1,   363,   363,   243,   332,   244,   353,     6,    -1,
     363,   363,   363,   243,   332,   244,     6,    -1,   363,   332,
       6,    -1,   132,   241,     4,   242,   247,     4,     6,    -1,
     170,     4,     6,    -1,   185,     6,    -1,   186,     6,    -1,
      70,     6,    -1,    71,     6,    -1,    64,     6,    -1,    64,
     245,   332,   250,   332,   250,   332,   250,   332,   250,   332,
     250,   332,   246,     6,    -1,    65,     6,    -1,    66,     6,
      -1,    78,     6,    -1,   115,     6,    -1,   116,   245,   349,
     246,   245,   349,   246,   245,   345,   246,   245,   332,   250,
     332,   246,     6,    -1,   190,   241,   245,   349,   246,   250,
     354,   250,   354,   242,     6,    -1,   178,   241,   332,     8,
     332,   242,    -1,   178,   241,   332,     8,   332,     8,   332,
     242,    -1,   178,     4,   179,   245,   332,     8,   332,   246,
      -1,   178,     4,   179,   245,   332,     8,   332,     8,   332,
     246,    -1,   180,    -1,   191,     4,    -1,   191,   354,    -1,
     188,    -1,   189,   363,     6,    -1,   189,   354,     6,    -1,
     181,   241,   332,   242,    -1,   182,   241,   332,   242,    -1,
     183,    -1,   184,    -1,   139,   343,   245,   303,   246,    -1,
     139,   245,   343,   250,   343,   250,   332,   246,   245,   303,
     246,    -1,   139,   245,   343,   250,   343,   250,   343,   250,
     332,   246,   245,   303,   246,    -1,    -1,   139,   343,   245,
     303,   313,   317,   246,    -1,    -1,   139,   245,   343,   250,
     343,   250,   332,   246,   245,   303,   314,   317,   246,    -1,
      -1,   139,   245,   343,   250,   343,   250,   343,   250,   332,
     246,   245,   303,   315,   317,   246,    -1,    -1,   139,   245,
     303,   316,   317,   246,    -1,   139,   245,   303,   246,   131,
     109,   245,   332,   246,    -1,   120,   346,    -1,   125,   120,
     346,    -1,   122,   245,   349,   246,   245,   349,   246,   245,
     349,   246,    -1,   123,   245,   349,   246,   245,   349,   246,
     245,   349,   246,   245,   349,   246,    -1,   318,    -1,   317,
     318,    -1,   156,   245,   332,   246,     6,    -1,   156,   245,
     346,   250,   346,   246,     6,    -1,   157,     6,    -1,   148,
       6,    -1,   148,   332,     6,    -1,   162,     6,    -1,   162,
     164,     6,    -1,   163,     6,    -1,   163,   164,     6,    -1,
     158,   241,   332,   242,     7,   346,   131,   332,     6,    -1,
     131,     4,   243,   332,   244,     6,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,    -1,   151,     6,
      -1,   134,   151,     6,    -1,   151,   332,     6,    -1,   134,
     151,   332,     6,    -1,   319,   245,   303,   320,   246,   245,
     303,   320,   246,    -1,   106,   241,   353,   242,    -1,   319,
     241,   332,   242,     7,   245,   303,   320,   246,   245,   303,
     320,   246,     6,    -1,    -1,   131,     4,   332,    -1,    -1,
       4,    -1,    -1,     7,   346,    -1,    -1,     7,   332,    -1,
      -1,   141,   346,    -1,   111,   112,   347,     7,   332,     6,
      -1,   126,    94,   347,     7,   332,   323,     6,    -1,   126,
      97,   347,   325,   324,     6,    -1,   126,    99,   347,   325,
       6,    -1,   165,   347,     6,    -1,    89,    91,   241,   332,
     250,   332,   242,     6,    -1,    89,    94,   241,   332,   250,
     332,   242,     6,    -1,    89,    97,   241,   332,   250,   332,
     242,     6,    -1,    89,    99,   241,   332,   250,   332,   242,
       6,    -1,   154,    97,   245,   349,   246,     7,   332,     6,
      -1,   148,    97,   347,   326,     6,    -1,   148,    99,   347,
       6,    -1,   149,    97,   347,     7,   332,     6,    -1,   129,
      94,   245,   349,   246,     7,   245,   349,   246,   327,     6,
      -1,   129,    97,   245,   349,   246,     7,   245,   349,   246,
     327,     6,    -1,   129,    94,   245,   349,   246,     7,   245,
     349,   246,   135,   245,   343,   250,   343,   250,   332,   246,
       6,    -1,   129,    97,   245,   349,   246,     7,   245,   349,
     246,   135,   245,   343,   250,   343,   250,   332,   246,     6,
      -1,   129,    94,   245,   349,   246,     7,   245,   349,   246,
     136,   343,     6,    -1,   129,    97,   245,   349,   246,     7,
     245,   349,   246,   136,   343,     6,    -1,   129,    97,   332,
     245,   349,   246,     7,   332,   245,   349,   246,     6,    -1,
     297,   245,   349,   246,   179,   297,   245,   332,   246,     6,
      -1,   155,   299,   347,     6,    -1,   117,   300,   347,     6,
      -1,   118,    99,   346,     6,    -1,   133,    94,   346,     6,
      -1,   128,   298,   346,     6,    -1,   152,     6,    -1,   152,
       4,     6,    -1,   152,    91,   245,   349,   246,     6,    -1,
     200,    -1,   201,    -1,   202,    -1,   330,     6,    -1,   330,
     245,   346,   246,     6,    -1,   330,   245,   346,   250,   346,
     246,     6,    -1,   330,   241,   346,   242,   245,   346,   250,
     346,   246,     6,    -1,   333,    -1,   241,   332,   242,    -1,
     230,   332,    -1,   229,   332,    -1,   236,   332,    -1,   332,
     230,   332,    -1,   332,   229,   332,    -1,   332,   231,   332,
      -1,   332,   232,   332,    -1,   332,   234,   332,    -1,   332,
     235,   332,    -1,   332,   233,   332,    -1,   332,   240,   332,
      -1,   332,   223,   332,    -1,   332,   224,   332,    -1,   332,
     228,   332,    -1,   332,   227,   332,    -1,   332,   222,   332,
      -1,   332,   221,   332,    -1,   332,   220,   332,    -1,   332,
     219,   332,    -1,   332,   225,   332,    -1,   332,   226,   332,
      -1,   332,   218,   332,     8,   332,    -1,    16,   275,   332,
     276,    -1,    17,   275,   332,   276,    -1,    18,   275,   332,
     276,    -1,    19,   275,   332,   276,    -1,    20,   275,   332,
     276,    -1,    21,   275,   332,   276,    -1,    22,   275,   332,
     276,    -1,    23,   275,   332,   276,    -1,    24,   275,   332,
     276,    -1,    26,   275,   332,   276,    -1,    27,   275,   332,
     250,   332,   276,    -1,    28,   275,   332,   276,    -1,    29,
     275,   332,   276,    -1,    30,   275,   332,   276,    -1,    31,
     275,   332,   276,    -1,    32,   275,   332,   276,    -1,    33,
     275,   332,   276,    -1,    34,   275,   332,   276,    -1,    35,
     275,   332,   276,    -1,    36,   275,   332,   250,   332,   276,
      -1,    37,   275,   332,   250,   332,   276,    -1,    38,   275,
     332,   250,   332,   276,    -1,    25,   275,   332,   276,    -1,
       3,    -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,
     207,    -1,   208,    -1,   209,    -1,    75,    -1,    76,    -1,
      77,    -1,    -1,    82,   275,   332,   334,   285,   276,    -1,
     337,    -1,   198,   275,   353,   276,    -1,   198,   275,   353,
     250,   332,   276,    -1,   339,    -1,   363,   243,   332,   244,
      -1,   363,   241,   332,   242,    -1,   203,   241,   339,   242,
      -1,   203,   241,   339,   247,   340,   242,    -1,   205,   241,
     339,   335,   242,    -1,   205,   241,   339,   247,   340,   335,
     242,    -1,   205,   241,   339,   275,   332,   276,   335,   242,
      -1,   205,   241,   339,   247,   340,   275,   332,   276,   335,
     242,    -1,   204,   241,   354,   242,    -1,   248,   363,   275,
     276,    -1,   248,   339,   247,   340,   275,   276,    -1,    85,
     275,   363,   276,    -1,    85,   275,   276,    -1,   363,   274,
      -1,   363,   243,   332,   244,   274,    -1,   363,   241,   332,
     242,   274,    -1,   363,   247,   340,    -1,   363,     9,   363,
     247,   340,    -1,   363,   247,   340,   241,   332,   242,    -1,
     363,     9,   363,   247,   340,   241,   332,   242,    -1,   363,
     247,   340,   243,   332,   244,    -1,   363,     9,   363,   247,
     340,   243,   332,   244,    -1,   363,   243,   332,   244,   247,
       4,    -1,   363,   247,     4,   274,    -1,   363,   243,   332,
     244,   247,     4,   274,    -1,   194,   241,   353,   250,   332,
     242,    -1,    56,   241,   346,   250,   346,   242,    -1,    57,
     275,   353,   250,   353,   276,    -1,    55,   275,   353,   276,
      -1,    58,   275,   353,   250,   353,   276,    -1,    63,   241,
     360,   242,    -1,    -1,   250,   332,    -1,    -1,   250,   353,
      -1,    -1,    83,   339,   342,   338,   243,   286,   244,    -1,
     363,    -1,   363,     9,   363,    -1,     4,    -1,    86,    -1,
      86,   332,    -1,    -1,   241,   341,   242,    -1,   344,    -1,
     230,   343,    -1,   229,   343,    -1,   343,   230,   343,    -1,
     343,   229,   343,    -1,   245,   332,   250,   332,   250,   332,
     250,   332,   250,   332,   246,    -1,   245,   332,   250,   332,
     250,   332,   250,   332,   246,    -1,   245,   332,   250,   332,
     250,   332,   246,    -1,   241,   332,   250,   332,   250,   332,
     242,    -1,   346,    -1,   345,   250,   346,    -1,   332,    -1,
     348,    -1,   245,   246,    -1,   245,   349,   246,    -1,   230,
     245,   349,   246,    -1,   332,   231,   245,   349,   246,    -1,
     346,    -1,   245,     8,   246,    -1,     5,    -1,   230,   348,
      -1,   332,   231,   348,    -1,   332,     8,   332,    -1,   332,
       8,   332,     8,   332,    -1,    91,   245,   332,   246,    -1,
      91,   245,     8,   246,    -1,    91,     5,    -1,   298,   245,
       8,   246,    -1,   298,     5,    -1,   127,   297,   347,    -1,
     130,   297,   346,    -1,   297,   179,    64,   245,   332,   250,
     332,   250,   332,   250,   332,   250,   332,   250,   332,   246,
      -1,    64,   297,   245,   332,   246,    -1,   301,    -1,   312,
      -1,   321,    -1,   363,   275,   276,    -1,   363,   247,   340,
     275,   276,    -1,   363,     9,   363,   247,   340,   275,   276,
      -1,    39,   243,   363,   244,    -1,    39,   243,   348,   244,
      -1,    39,   241,   348,   242,    -1,    39,   275,   245,   349,
     246,   276,    -1,   363,   275,   245,   349,   246,   276,    -1,
      40,   275,   332,   250,   332,   250,   332,   276,    -1,    41,
     275,   332,   250,   332,   250,   332,   276,    -1,    42,   275,
     353,   276,    -1,    43,   275,   332,   250,   332,   250,   332,
     250,   332,   250,   332,   250,   332,   276,    -1,   199,   275,
     348,   276,    -1,    32,   275,   348,   276,    -1,   332,    -1,
     348,    -1,   349,   250,   332,    -1,   349,   250,   348,    -1,
     245,   332,   250,   332,   250,   332,   250,   332,   246,    -1,
     245,   332,   250,   332,   250,   332,   246,    -1,   363,    -1,
       4,   247,   176,   247,     4,    -1,   245,   352,   246,    -1,
     363,   243,   332,   244,   247,   177,    -1,   350,    -1,   352,
     250,   350,    -1,   354,    -1,   363,    -1,   363,   243,   332,
     244,    -1,   363,   241,   332,   242,    -1,   363,   247,   340,
      -1,   363,     9,   363,   247,   340,    -1,   363,   247,   340,
     241,   332,   242,    -1,   363,     9,   363,   247,   340,   241,
     332,   242,    -1,   363,   243,   332,   244,   247,     4,    -1,
     127,    91,   245,   332,   246,    -1,   127,    94,   245,   332,
     246,    -1,   127,    97,   245,   332,   246,    -1,   127,    99,
     245,   332,   246,    -1,     5,    -1,   212,   243,   363,   244,
      -1,    67,    -1,   210,    -1,    72,    -1,    74,    -1,   196,
     241,   353,   242,    -1,   195,   241,   353,   250,   353,   242,
      -1,   197,   275,   353,   276,    -1,   197,   275,   353,   250,
     353,   276,    -1,   206,   241,   339,   336,   242,    -1,   206,
     241,   339,   247,   340,   336,   242,    -1,    48,   275,   360,
     276,    -1,    49,   241,   353,   242,    -1,    50,   241,   353,
     242,    -1,    51,   241,   353,   250,   353,   250,   353,   242,
      -1,    46,   275,   360,   276,    -1,    60,   275,   353,   276,
      -1,    61,   275,   353,   276,    -1,    62,   275,   353,   276,
      -1,    59,   275,   332,   250,   353,   250,   353,   276,    -1,
      54,   275,   353,   250,   332,   250,   332,   276,    -1,    54,
     275,   353,   250,   332,   276,    -1,    47,   275,   353,   276,
      -1,    47,   275,   353,   250,   349,   276,    -1,    68,   275,
     353,   276,    -1,    69,    -1,    53,   275,   353,   276,    -1,
      52,   275,   353,   276,    -1,    -1,    87,   275,   354,   355,
     289,   276,    -1,    84,   275,   356,   276,    -1,   248,   332,
      -1,   363,     9,   248,   332,    -1,    46,   275,   359,   276,
      -1,   360,    -1,   359,    -1,   245,   360,   246,    -1,   353,
      -1,   361,    -1,   360,   250,   353,    -1,   360,   250,   361,
      -1,   363,   241,   242,    -1,   363,   247,   340,   241,   242,
      -1,   363,     9,   363,   247,   340,   241,   242,    -1,     4,
     249,   245,   332,   246,    -1,   362,   249,   245,   332,   246,
      -1,   213,   243,   353,   244,   249,   245,   332,   246,    -1,
       4,    -1,   362,    -1,   213,   243,   353,   244,    -1
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
    3413,  3422,  3486,  3502,  3519,  3536,  3558,  3580,  3615,  3623,
    3631,  3637,  3644,  3651,  3671,  3697,  3709,  3720,  3738,  3756,
    3775,  3774,  3799,  3798,  3825,  3824,  3849,  3848,  3871,  3887,
    3904,  3921,  3944,  3972,  3975,  3981,  3993,  4013,  4017,  4021,
    4025,  4029,  4033,  4037,  4041,  4050,  4063,  4064,  4065,  4066,
    4067,  4071,  4072,  4073,  4074,  4075,  4078,  4102,  4121,  4144,
    4147,  4163,  4166,  4183,  4186,  4192,  4195,  4202,  4205,  4212,
    4234,  4275,  4319,  4358,  4383,  4395,  4407,  4419,  4431,  4440,
    4470,  4496,  4522,  4554,  4581,  4607,  4633,  4659,  4685,  4707,
    4718,  4766,  4820,  4835,  4847,  4858,  4865,  4880,  4894,  4895,
    4896,  4900,  4906,  4918,  4936,  4964,  4965,  4966,  4967,  4968,
    4969,  4970,  4971,  4972,  4979,  4980,  4981,  4982,  4983,  4984,
    4985,  4986,  4987,  4988,  4989,  4990,  4991,  4992,  4993,  4994,
    4995,  4996,  4997,  4998,  4999,  5000,  5001,  5002,  5003,  5004,
    5005,  5006,  5007,  5008,  5009,  5010,  5011,  5012,  5013,  5014,
    5015,  5016,  5025,  5026,  5027,  5028,  5029,  5030,  5031,  5032,
    5033,  5034,  5035,  5040,  5039,  5047,  5049,  5054,  5059,  5063,
    5068,  5073,  5077,  5081,  5085,  5089,  5093,  5097,  5103,  5119,
    5124,  5130,  5136,  5155,  5176,  5209,  5213,  5218,  5222,  5226,
    5230,  5235,  5240,  5250,  5260,  5265,  5276,  5285,  5290,  5295,
    5323,  5324,  5330,  5331,  5337,  5336,  5359,  5361,  5366,  5375,
    5377,  5383,  5384,  5389,  5393,  5397,  5401,  5405,  5412,  5416,
    5420,  5424,  5431,  5436,  5443,  5448,  5452,  5457,  5461,  5469,
    5480,  5484,  5488,  5502,  5510,  5518,  5525,  5535,  5558,  5563,
    5569,  5574,  5580,  5591,  5597,  5603,  5608,  5618,  5628,  5638,
    5650,  5654,  5659,  5671,  5675,  5679,  5683,  5701,  5709,  5717,
    5746,  5756,  5772,  5783,  5788,  5792,  5796,  5808,  5812,  5824,
    5841,  5851,  5855,  5870,  5875,  5882,  5886,  5891,  5905,  5921,
    5925,  5929,  5933,  5937,  5945,  5951,  5957,  5963,  5972,  5976,
    5980,  5988,  5994,  6000,  6004,  6012,  6020,  6027,  6036,  6040,
    6044,  6059,  6073,  6087,  6099,  6115,  6124,  6133,  6143,  6154,
    6162,  6170,  6174,  6193,  6200,  6206,  6213,  6221,  6220,  6230,
    6254,  6256,  6262,  6267,  6269,  6274,  6279,  6284,  6286,  6290,
    6302,  6316,  6320,  6327,  6335,  6343,  6354,  6356,  6359
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
  "tTotalMemory", "tCreateTopology", "tDistanceFunction",
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
     465,   466,   467,   468,   469,   470,   471,   472,    63,   473,
     474,   475,   476,    60,    62,   477,   478,   479,   480,    43,
      45,    42,    47,    37,   124,    38,    33,   481,   482,   483,
      94,    40,    41,    91,    93,   123,   125,    46,    35,   126,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   251,   252,   252,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   255,   255,   256,   256,
     256,   256,   256,   256,   257,   257,   257,   257,   258,   258,
     258,   258,   258,   258,   259,   259,   260,   260,   262,   263,
     261,   264,   264,   266,   265,   267,   267,   269,   268,   270,
     270,   272,   271,   273,   273,   273,   273,   273,   274,   274,
     275,   275,   276,   276,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   278,   278,   279,   279,   279,   280,   279,   281,   279,
     279,   282,   279,   283,   283,   284,   284,   284,   285,   285,
     286,   286,   287,   287,   288,   288,   288,   288,   288,   289,
     289,   290,   290,   291,   291,   291,   291,   291,   292,   292,
     292,   293,   293,   293,   293,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   296,
     295,   297,   297,   297,   297,   297,   298,   298,   298,   298,
     299,   299,   299,   300,   300,   300,   300,   301,   301,   301,
     301,   301,   301,   301,   301,   302,   302,   303,   303,   303,
     303,   303,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   305,   305,   305,   305,
     305,   305,   305,   306,   306,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   310,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   312,   312,   312,
     313,   312,   314,   312,   315,   312,   316,   312,   312,   312,
     312,   312,   312,   317,   317,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   319,   319,   319,   319,
     319,   320,   320,   320,   320,   320,   321,   321,   322,   323,
     323,   324,   324,   325,   325,   326,   326,   327,   327,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   329,   329,   330,   330,
     330,   331,   331,   331,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     335,   335,   336,   336,   338,   337,   339,   339,   340,   341,
     341,   342,   342,   343,   343,   343,   343,   343,   344,   344,
     344,   344,   345,   345,   346,   346,   346,   346,   346,   346,
     347,   347,   347,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   349,   349,   349,   349,   350,   350,   350,
     350,   351,   351,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   355,   354,   354,
     356,   356,   357,   358,   358,   359,   360,   360,   360,   360,
     361,   361,   361,   362,   362,   362,   363,   363,   363
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
       2,    16,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     2,
       3,    10,    13,     1,     2,     5,     7,     2,     2,     3,
       2,     3,     2,     3,     9,     6,     1,     1,     1,     1,
       1,     0,     2,     3,     3,     4,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     6,
       7,     6,     5,     3,     8,     8,     8,     8,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     1,     4,     6,     1,     4,
       4,     4,     6,     5,     7,     8,    10,     4,     4,     6,
       4,     3,     2,     5,     5,     3,     5,     6,     8,     6,
       8,     6,     4,     7,     6,     6,     6,     4,     6,     4,
       0,     2,     0,     2,     0,     7,     1,     3,     1,     1,
       2,     0,     3,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     3,     1,     2,     3,     3,     5,     4,     4,     2,
       4,     2,     3,     3,    16,     5,     1,     1,     1,     3,
       5,     7,     4,     4,     4,     6,     6,     8,     8,     4,
      14,     4,     4,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     3,
       5,     6,     8,     6,     5,     5,     5,     5,     1,     4,
       1,     1,     1,     1,     4,     6,     4,     6,     5,     7,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     8,
       6,     4,     6,     4,     1,     4,     4,     0,     6,     4,
       2,     4,     4,     1,     1,     3,     1,     1,     3,     3,
       3,     5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   606,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,     0,   192,     0,     0,
     193,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,   317,
     318,   319,   320,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,   285,   286,     0,     0,     0,
     280,     0,     0,     0,     0,     0,   368,   369,   370,     0,
       0,     5,     6,     7,     8,    10,     0,    11,    24,    12,
      13,    14,    15,    23,    22,    21,    16,     0,    17,    18,
      19,    20,     0,    25,     0,   607,     0,   217,     0,     0,
       0,     0,     0,   265,     0,   267,   268,   263,   264,     0,
     269,   113,   123,   606,   481,   476,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,   203,   204,
     205,     0,     0,     0,     0,   422,   423,   425,   426,   424,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   430,   431,   432,     0,     0,   191,
     196,   197,   198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   427,   428,   429,     0,     0,     0,
       0,     0,     0,     0,     0,   516,   517,     0,   518,   494,
     375,   435,   438,   299,   495,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   189,
     196,   197,   198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   606,     0,     0,
     217,     0,     0,   365,     0,     0,     0,   200,   201,     0,
       0,     0,     0,     0,   502,     0,     0,   500,     0,     0,
       0,     0,     0,   606,     0,     0,   539,     0,     0,     0,
       0,   261,   262,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   560,     0,
     584,   562,   563,     0,     0,     0,     0,     0,     0,   561,
       0,     0,     0,     0,   278,   279,     0,   217,     0,   217,
       0,     0,     0,   476,     0,     0,     0,   217,   371,     0,
       0,    76,     0,    63,     0,     0,    67,    66,    65,    64,
      69,    68,    70,    71,     0,     0,     0,     0,     0,     0,
     545,   476,     0,   216,     0,   215,     0,   170,     0,     0,
     545,   546,     0,     0,   596,     0,   597,   546,   111,   111,
       0,   474,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   533,   534,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   378,
       0,   377,   503,   379,     0,   496,     0,     0,   476,     0,
     511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,   452,     0,     0,     0,
       0,     0,     0,     0,   300,     0,   333,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,     0,   217,
     217,     0,   485,   484,     0,     0,     0,     0,   217,   217,
       0,     0,     0,     0,   296,     0,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,   242,     0,     0,   240,   366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   343,   260,
       0,     0,     0,     0,     0,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,   281,     0,   247,     0,     0,   249,     0,
       0,     0,   377,     0,   217,     0,     0,     0,     0,     0,
       0,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    72,
      73,     0,     0,   258,    38,   254,     0,     0,     0,     0,
       0,   212,     0,     0,     0,     0,     0,   218,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,     0,
     479,     0,     0,   477,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   327,     0,     0,     0,   195,
       0,     0,     0,     0,     0,     0,   361,   362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   433,   451,
       0,     0,     0,     0,   512,   513,     0,     0,     0,     0,
       0,   470,     0,   376,   497,     0,     0,     0,     0,   505,
       0,   395,   394,   393,   392,   388,   389,   396,   397,   391,
     390,   381,   380,     0,   382,   504,   383,   386,   384,   385,
     387,   477,     0,     0,   478,   455,     0,   519,     0,     0,
       0,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,   364,     0,     0,     0,     0,   363,     0,   217,     0,
       0,     0,     0,     0,   487,   486,     0,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   350,     0,     0,   241,
       0,     0,   236,     0,     0,     0,     0,   360,     0,     0,
       0,   376,   501,     0,     0,     0,     0,     0,     0,     0,
       0,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,     0,     0,     0,   472,     0,     0,   246,   250,
     248,   252,     0,   382,     0,   477,   455,   608,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,   376,     0,    63,     0,     0,     0,     0,
      79,     0,    63,    64,     0,     0,   477,     0,     0,   455,
       0,     0,     0,   189,     0,     0,     0,   603,    28,    26,
      27,     0,     0,     0,     0,     0,   478,   549,    29,     0,
       0,   255,   598,   599,     0,   600,   549,    74,   114,    75,
     124,   480,   482,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   535,   536,   206,     9,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   421,   408,     0,   410,   411,   412,
     413,   414,   532,   415,   416,   417,     0,     0,     0,   524,
     523,   522,     0,     0,     0,   529,     0,   467,     0,     0,
       0,   469,     0,   128,   450,   508,   507,   199,     0,     0,
     436,   531,   441,     0,   447,     0,     0,     0,     0,   498,
       0,     0,   448,     0,   510,     0,     0,     0,     0,   440,
     439,   462,    70,    71,     0,     0,     0,     0,     0,     0,
       0,   376,   329,   334,   332,     0,   342,     0,   148,   149,
     199,   376,     0,     0,     0,     0,   237,     0,   251,   253,
       0,     0,     0,   207,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     0,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,   349,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,     0,     0,   574,     0,   581,   570,   571,   572,     0,
     586,   585,     0,     0,   575,   576,   577,   583,   590,   589,
       0,   139,     0,   564,     0,   566,     0,     0,     0,   559,
       0,   245,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,   372,     0,   604,     0,     0,     0,     0,
     101,    63,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    61,     0,    39,    40,    41,    42,    43,     0,
     440,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   548,   547,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   131,   132,     0,     0,     0,
       0,     0,     0,     0,   155,   155,     0,     0,     0,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   339,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   515,     0,     0,     0,     0,
       0,   470,   471,     0,   443,     0,     0,     0,   506,   398,
     499,   456,   454,     0,   453,     0,     0,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,   307,     0,   310,     0,
     312,     0,   297,   304,     0,     0,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   351,     0,   239,   238,
     367,     0,     0,    35,    36,     0,     0,     0,     0,   540,
       0,     0,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,   473,   568,
       0,   456,     0,     0,   217,   323,     0,   324,   217,     0,
       0,   554,   555,   556,   557,     0,    86,     0,     0,     0,
       0,    84,    91,    93,     0,   543,     0,    99,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,    34,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    31,     0,   550,     0,     0,    32,     0,
     550,   601,     0,   115,   120,     0,     0,     0,   134,   137,
     138,   475,     0,    77,     0,     0,     0,     0,    78,   157,
       0,     0,     0,     0,   158,   173,   174,     0,     0,     0,
       0,   159,   184,   175,   179,   180,   176,   177,   178,   165,
       0,     0,   409,   418,   419,   420,   525,     0,     0,     0,
     465,   466,   468,   129,   434,   464,   437,   442,     0,     0,
     470,   185,   449,     0,    70,    71,     0,   461,   457,   459,
     526,   181,     0,     0,     0,   151,     0,     0,   340,     0,
     150,     0,     0,     0,     0,   259,     0,     0,     0,     0,
     217,   217,     0,     0,   309,   494,     0,     0,   311,   313,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,     0,     0,     0,     0,   162,   163,
       0,     0,     0,     0,   102,   103,   104,   108,     0,   582,
       0,     0,   580,     0,   591,     0,     0,   140,   141,   588,
     565,   567,     0,     0,     0,     0,     0,     0,   321,   325,
     321,     0,   373,    85,    63,     0,     0,     0,     0,    83,
       0,   541,     0,     0,     0,     0,     0,     0,   594,   593,
       0,     0,     0,     0,     0,   492,     0,     0,   461,   256,
     457,   257,     0,     0,     0,     0,     0,   222,   219,     0,
       0,   553,   551,     0,     0,   116,   121,     0,     0,     0,
     533,   534,   133,   344,   345,   346,   347,   156,   160,   161,
     166,   183,     0,     0,     0,   168,     0,     0,     0,     0,
       0,     0,   444,     0,     0,     0,     0,   521,   463,     0,
       0,   167,     0,   186,   330,     0,     0,   187,     0,     0,
       0,     0,     0,     0,   491,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   224,     0,     0,   348,
      37,     0,   538,     0,     0,   275,   274,     0,     0,     0,
       0,     0,     0,   143,   144,   147,   146,   145,     0,   569,
       0,   605,     0,     0,     0,     0,     0,     0,    96,     0,
       0,    97,   544,     0,     0,     0,    88,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    46,     0,   223,   220,
     221,    33,     0,     0,   602,   128,   139,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,   527,   528,
       0,   470,   445,     0,   458,   460,     0,     0,   169,   190,
       0,   337,   337,     0,   109,   110,   217,     0,   210,   211,
     298,     0,   305,     0,     0,   217,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   213,     0,     0,     0,     0,
     105,   106,   573,   579,   578,   142,     0,     0,     0,   326,
       0,    92,    94,     0,   100,     0,    82,   595,    89,    90,
      49,     0,     0,     0,     0,   493,     0,     0,   458,   552,
       0,     0,     0,   118,   592,     0,   125,     0,     0,     0,
       0,   172,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
     315,     0,     0,   292,     0,   225,     0,     0,     0,     0,
       0,     0,     0,   537,   276,     0,     0,   359,   217,   374,
       0,   542,     0,    45,     0,     0,     0,    62,    47,     0,
     117,   122,   128,     0,     0,   153,   154,   152,     0,     0,
     446,     0,     0,     0,     0,     0,   338,   352,     0,     0,
     353,     0,   208,     0,   306,     0,   288,     0,   217,     0,
       0,     0,     0,     0,     0,   164,   107,   272,   321,    98,
       0,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,     0,   188,     0,   356,     0,   357,   358,   488,     0,
       0,   294,   228,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    59,     0,     0,   119,     0,     0,     0,
     302,     0,     0,   314,   293,   289,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   229,   230,   231,   232,     0,
     226,   328,    50,     0,    57,     0,   266,     0,   530,     0,
       0,     0,   295,     0,     0,    51,     0,     0,   271,     0,
       0,     0,   227,     0,     0,     0,     0,   514,     0,     0,
      54,    52,     0,    55,     0,   354,   355,     0,     0,    60,
      58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   111,  1041,   112,   113,  1025,  1859,  1865,
    1314,  1523,  2012,  2144,  1315,  2115,  2162,  1316,  2146,  1317,
    1318,  1527,   425,   576,   577,  1111,   114,   757,   448,  1875,
    2022,  1876,   449,  1749,  1387,  1344,  1345,  1346,  1484,  1687,
    1688,  1177,  1580,  1571,   737,   588,   263,   264,   340,   192,
     265,   434,   435,   118,   119,   120,   121,   122,   123,   124,
     125,   266,  1209,  2047,  2106,   921,  1205,  1206,   267,  1002,
     268,   129,  1416,  1175,   896,   935,  1982,   130,   131,   132,
     133,   269,   270,  1133,  1148,  1268,   271,   762,   272,   885,
     761,   451,   603,   309,  1724,   347,   348,   274,   546,   355,
    1302,  1516,   444,   440,  1261,   979,  1560,  1717,  1718,   964,
     446,   135,   403
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1841
static const yytype_int16 yypact[] =
{
   12238,    78,    89, 12391, -1841, -1841,  -130,    63,    48,  -114,
     -56,    51,   149,   197,   210,   279,    53,   298,    65,    70,
      25,  -182,   353,  -182,    94,   148,   186,    46,   192,   198,
      64,   204,   241,   248,   253,   265,   284,   303,   370,   406,
     414,   206,   344,   576,   677,   455,   129,   613,   476,  6578,
     493,   496,   499,   653,   -45,   661,   557,   454,   508,   516,
     696,   -91,   502,   412,   412,   554,   461,   471, -1841, -1841,
   -1841, -1841, -1841,   584,    74,   751,   716,    37,    52,   729,
     770,     0,   865,   871,   873,  5622,   883,   647,   658,   666,
      38,    66, -1841,   686,   717, -1841, -1841,   888,   912,   731,
   -1841,  2389,   748,  5974,    20,    28, -1841, -1841, -1841, 11328,
     774, -1841, -1841, -1841, -1841, -1841,   753, -1841, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841,  -101, -1841, -1841,
   -1841, -1841,    61, -1841,   994,   783,  5381,    77,   798,  1044,
   11328,  5735,  5735, -1841, 11328, -1841, -1841, -1841, -1841,  5735,
   -1841, -1841, -1841,   814,   823,  1058, -1841, -1841,  6213,   829,
     833,   844,   845,    25, 11328, 11328, 11328,   850, 11328, 11328,
   11328,   851, 11328, 11328, 11328, 11328, 11328, 11328, 11328,  5735,
   11328, 11328, 11328, 11328,  5622,   852, -1841,  9197, -1841, -1841,
   -1841,   849,  5622,  6817,  5735, -1841, -1841, -1841, -1841, -1841,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,   345,  -182,  -182,  -182,  -182,  -182,   854,
    -182,  -182,   855,   557, -1841, -1841, -1841,  -182,  -182,    31,
     918,   919,   921,   857,  6817,   984,   557,   557,   866,  -182,
    -182,   867,   868,   869, -1841, -1841, -1841, 11328,  7056, 11328,
   11328,  7295,    25,   932,    32, -1841, -1841,   870, -1841,  4505,
   -1841, -1841, -1841, -1841, -1841,   170, 11328,  9197,  9197,   872,
     875,  7534,  5622,  5622,  5622, -1841, -1841, -1841, -1841, -1841,
   -1841, -1841, -1841,   874,  7773,   876,  4248,  1108,  6817,   877,
      38,   879,   884,   412,   412,   412, 11328, 11328,   367, -1841,
     464,   412, 10074,   484,    -5,   887,   889,   892,   894,   895,
     896,   900, 11328,  5622,  5622,  5622,   901,    17,  1111,   891,
   -1841,  1112,  1114, -1841,   898,   899,   903, -1841, -1841,   904,
    5622,   902,   907,   908, -1841, 11328,  5861, -1841,  1146,  1148,
   11328, 11328, 11328,   458, 11328,   910, -1841,   935, 11328, 11328,
   11328, -1841, -1841, 11328, -1841,  -182,  -182,  -182,   915,   917,
     920,  -182,  -182,  -182,  -182,  -182,  -182,  -182, -1841,  -182,
   -1841, -1841, -1841,  -182,  -182,   925,   926,  -182,   947, -1841,
     916,  1154,  1156,   944, -1841, -1841,  1187,  1186,  1189,  1188,
    -182, 11328, 13962,   177,  5735,  9197, 11328, -1841, -1841,  6817,
    6817, -1841,   954,  6213,   401,  1193, -1841, -1841, -1841, -1841,
   -1841, -1841, 11328, 11328,    30,  6817,  1195,   155,   398,   957,
    1197,    87,   959, -1841,   963, 12601, 11328, -1841,   950,   -93,
   -1841,    86,   -67,  4829, -1841,     6, -1841,    95,  -132,   -48,
    1119, -1841,    25,   960, 11328, 11328, 11328, 11328,   961, 14478,
   14503, 14528, 11328, 14553, 14578, 14603, 11328, 14628, 14653, 14678,
   14703, 14728, 14753, 14778,   970, 14803, 14828, 14853,  4645,  1206,
   11328,  9197,  4539, -1841,     3, 11328,  1208,  1209,   976, 11328,
   11328, 11328, 11328, 11328, 11328, 11328, 11328, 11328, 11328, 11328,
   11328, 11328, 11328, 11328, 11328,  9197, 11328, 11328, 11328, 11328,
   11328, 11328,  9197,  9197,   974, 11328, 11328,  5735, 11328,  5735,
    6817,  5735,  5735,  5735,   975, 11328,    44, -1841, 10150, 11328,
    6817,  5622,  6817,  5735,  5735,  9197,    25,  6213,    25,   981,
    9197,   981, -1841,   981, 14878, -1841,   100,   977,    71,  1158,
   -1841,  1215, 11328, 11328, 11328, 11328, 11328, 11328, 11328, 11328,
   11328, 11328, 11328, 11328, 11328, 11328,  8012, 11328, 11328, 11328,
   11328, 11328,    25, 11328, 11328,  1221, -1841,   660, 14903,   134,
     164, 11328, 11328, 11328, -1841,  1219,  1220,  1220,   987, 11328,
   11328,  1223,  9197,  9197, 13990,   991,  1228, -1841,   990, -1841,
   -1841,  -167, -1841, -1841,  6753,  6992,   412,   412,    77,    77,
    -164, 10074, 10074, 11328,  4409,  -151, -1841, 11328, 11328, 11328,
   11328, 11328, 11328, 11328, 11328, 11328, 14928,  1229,  1231,  1232,
   11328,  1234, 11328, -1841, 11328, 11356, -1841, -1841,  9197,  9197,
    9197, 11328,  1236, 11328, 11328, 11328, 14953,   992, -1841, -1841,
   14978, 15003, 15028,  1067,  7231, -1841,  1002,  4611, 15053, 15078,
   14073,  5735,  5735,  5735,  5735,  5735,  5735,  5735,  5735,  5735,
   11328,  5735,  5735,  5735,  5735,    22,  6213,  5735,  5735,  5735,
      25,    25, -1841, -1841,  9197, -1841,  1003, 11486, -1841,  1005,
   11553, 11328,   981, 11328, -1841,    25, 11328, 11328,  1221,  1004,
     328, 15103, 12534,  1014,   394, 11328,  1251,  1013,  1015,  1017,
    1018,  6817, 15128, 14100,   215,  1019,  1258,  1261, -1841, -1841,
   -1841,  9197,   221, -1841, -1841, -1841,    25, 11328, 11328,  1221,
    1025, -1841,  1028,   -44,   557,   454,   557, -1841,  1026, 13092,
   -1841,   152,  9197,    25, 11328, 11328,  1266,  1267,  9197, 11328,
    1268,  5735,    25, 10384,  1266,  1270, -1841,    25,  1271,  5735,
   11328,  1030,  1035, -1841, 11328,  7470,  7709,  7948,  8187,  6213,
    1273,  1274,  1275, 15153,  1276,  1277,  1278, 15178,  1288,  1289,
    1290,  1296,  1297,  1303,  1304, -1841,  1306,  1308,  1310, -1841,
   11328, 15203,  9197,  1074,  9197, 13121, -1841, -1841,  1314, 14046,
   14046, 14046, 14046, 14046, 14046, 14046, 14046, 14046, 14046, 14046,
    8421, 14046, 14046, 14046, 14046,   544,   541, 14046, 14046, 14046,
    8655,  8894,  9133,  4539,  1079,  1078,   147,  9197,  9465,  9789,
     541, 10019,   541,  1076,  1080,  1081,    81, 11328,  5291, -1841,
     541,  1082, 13150, 13179, -1841, -1841,  1084,   -72,   541,  -139,
    1090,   402,   400,  1328, -1841,  1266,   541,  1091,  1092,  5070,
    5252,  2851,  1305,   605,   605,   681,   681,   681,   681,   681,
     681,   561,   561,  9197,   487, -1841,   487,   487,   981,   981,
     981,  1094, 15228, 14127,   -77,   676,  9197, -1841,  1330,  1097,
    1099, 15253, 15278, 15303, 11328,  6817,  1335,  1339,  9840, 13208,
   15328, -1841,   567,   569,  9197,  1100, -1841, 11610, -1841, 11677,
   11734,   412, 11328, 11328, -1841, -1841,  1102,  1103, 10074,  3922,
    1224,   452,   412, 11801, 15353, 13237, 15378, 15403, 15428, 15453,
   15478, 15503, 15528,  1343, 11328,  1340, -1841, 11328, 15553, -1841,
   14154, 14181, -1841,   572,   597,   626, 13266, -1841, 14208, 14235,
   10106, -1841, -1841,  1344,  1345,  1347,  1109, 11328, 11858, 11328,
   11328, -1841, -1841,    42,   -13,   292,   -13,  1116,  1117,  1110,
     541,   541,  1113, 10335,   541,   541,   541,   541, 11328,   541,
    1352, -1841,  1115,  1120,   315,   249,  1122,   628, -1841, -1841,
   -1841, -1841, 14046,   487, 11925,  1121,   695,  1123,  1185,  1362,
    1222, 10467,  1124,  1126,  1368,  6817, 13295, -1841, 11328, 11328,
   11328, 11328,  1369,   365,   102,  6213, 11328,  1370,  1373,    39,
   -1841,   634,  1334,  1336,  6817,    26,  1134, 15578, 14262,   178,
   11328, 11328,  1142,  1143,  1149,  1144,  8251, -1841, -1841, -1841,
   -1841,  5735,    97,  1145, 15603, 14289, -1841,  1150, -1841,   318,
   10416, -1841, -1841, -1841,  1147, -1841,  1155, -1841,    21, -1841,
   -1841,  5291, -1841,  1391, 14046, 11328, 11328, 11328, 11328,   541,
     412,  6817,  6817,  1390,  6817,  6817,  6817,  1392,  6817,  6817,
    6817,  6817,  6817,  6817,  6817,  6817,  6817,  6817,  1337,  1393,
    9197,  4539, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, 11328, -1841, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, 11328, 11328, 11328, -1841,
   -1841, -1841,   635, 11328, 11328, -1841, 11328, -1841,  6817,  5735,
    5735, -1841, 13324,  1152, -1841, -1841, -1841,  1225, 11328, 11328,
   -1841, -1841, -1841,  1266, -1841,  1266, 11328, 11328,  1161, -1841,
    6817,  -182, -1841, 11328, -1841, 11328, 11328,   636,  1266,   -77,
    -122, -1841, 11328, 11328,   541,   643,  6817,  9197,  9197,  1398,
    1399,  1400,  2549, -1841, -1841,  1406, -1841,  1171,  5291,  1164,
   -1841,  1409,  1411,  1413,   650,  1394, -1841, 11982, -1841, -1841,
    -124, 10652, 10733, -1841, -1841, 13353,  -158,  1312,  1418, 10701,
    1178,  1419,  1183,    33,    45,   436, -1841,  -116, -1841,   452,
    1421,  1420,  1422,  1423,  1424,  1426,  1427,  1431,  1432,  6817,
    5291, -1841,  1495,  1196,  1434,  1436,  1438,  1348,  1440, -1841,
    1442,  1443, 11328,  6817,  6817,  6817,  1451, 10963, -1841,  5316,
     631,    36,  1452, -1841,  9197, -1841, -1841, -1841, -1841,  5735,
   -1841, -1841, 11328,  5735, -1841, -1841, -1841, -1841,  5291, -1841,
    1210,  1207,  5735, -1841,  5735, -1841,  1266,  5735,  1217, -1841,
    1211, -1841,  1266, 11328, 11328,  1238,   557,  1242, 10784, -1841,
    1785,  1243,  6817, -1841,  1214, -1841, 13382, 13411, 13440, 13469,
   -1841, -1841, 11328,  1456,    34, 11328,  1483,  1484,  1973, -1841,
    1485,    38,  1487,  1248,   541,  -182,  -182,  1489, -1841,  1255,
    1256,  1253, -1841,  1494, -1841, -1841, -1841, -1841, -1841,  1266,
     465,   893, 11328, 14316, 15628, 11328,  8485, 11328,  9197,  1257,
     674,  1496,   171,  1266, -1841,  1259, 11328,  1498, 11328,  1266,
   11018,  9431,   541,  4878,  1263,  1260, -1841,  1499, 15653, 15678,
   15703, 15728,  1502,   115,  1385,  1385,  6817,  1506,  1507,  1508,
    6817,   -86,  1509,  1510,  1513,  1514,  1515,  1516,  1518,  1536,
    1537, -1841,  1539,   679, 14046, 14046, 14046, 14046,   541, 11050,
   11196, 12036,  1309,   541,   541, -1841,  1391,   541, 15753, 14046,
    1311,   162,  5291, 14046, -1841,  1540,   541, 12531,  5291,  5291,
   -1841,   707, -1841,  1544, -1841, 15778, 14343, -1841,   541,  1546,
     682,   684,  6817,  6817,  6817,  1570,  1569, -1841,   226, 11328,
    6817,  1331,  1333,  1543,   363, -1841, 11328, 11328, 11328,  1338,
    1341,  1342,  1349, -1841,  2426,  6817, -1841, 11328, -1841,  1573,
   -1841,  1574, -1841, -1841, 10074,   568,  6100, -1841,  1346,  1350,
    1353,  1354,  1355,  1356,  8719,  1575, -1841,  9197, -1841, -1841,
   -1841,  1358, 11328, -1841, -1841, 14370,  1576,  1578,  1410, -1841,
   11328, 11328, 11328, -1841,  1582,  1584,  1587,   506,   509,  1357,
    3358,  1359, 11328,    27,   541,  1364,   541,  1360, -1841, -1841,
    6213,   708, 11328,  1366, -1841, -1841,  2576, -1841, -1841,  1363,
    1588, -1841, -1841, -1841, -1841,  2817, -1841,   481,  1365,  1597,
    2961, -1841, -1841, -1841,    38, -1841,   685, -1841, 11328,   226,
    1240,  1915, -1841,  1375, 11328, 11328,  6817,  1372, -1841,   281,
    1610,  1612, 15803,  1613,  1328, 15828,  1374,   687, 15853,   713,
    1615,  1616, -1841, -1841,  5735,  1382,  1620, 15878, -1841, 12564,
    1384, -1841,  5134,  5291, -1841,  1624,  -182,  7295, -1841, -1841,
   -1841, -1841,  1391, -1841,  1621,  1626,  1627,  1628, -1841, -1841,
     412,  1629,  1630,  1631, -1841, -1841, -1841,  1634,   -37,  1547,
    1635, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
    1639,  1402, -1841, -1841, -1841, -1841, -1841, 11328, 11328, 11328,
   -1841, -1841, -1841,  1260, -1841, -1841, -1841, -1841, 11328,  1403,
    1401, -1841, -1841, 11328, 11328, 11328,   541,   -77, -1841, -1841,
   -1841, -1841,  1404,  1405,  1642,   -86,  1647, 11328, -1841,  6817,
    5291,   794,  9197,  9197, 11328, -1841,  9840, 13498, 15903,  4573,
      77,    77, 11328, 11328, -1841,   133,  1407, 15928, -1841, -1841,
   13527,  -100, -1841,  1648,  1649,  6817,   412,   412,   412,   412,
     412,  6339,  1650, -1841,   718, 11328,  3132,  1653, -1841, -1841,
    6817,  6275,   239, 15953, -1841, -1841, -1841, -1841,  9516, -1841,
    5735, 11328, -1841,  5735,  5291,  9755,  6213,  1412, -1841, -1841,
   -1841, -1841,  1428,  1414, 11328, 11328, 13556, 11328, 12534, -1841,
   12534,  6817, -1841, -1841,  6213, 11328,  1654,  1657,    39, -1841,
    1659, -1841,    38, 14397,  6817,  5735,  1660,   541, -1841,  1425,
     541, 11328, 12597, 12630,   720, -1841, 11328, 11328,   582, -1841,
    1433, -1841,  1400,  1662,  1663,  1409,  1665, -1841, -1841,  1666,
   11328, -1841, -1841, 11328, 11094, -1841, -1841,  1437,  1915,   723,
    4366,  1656, -1841, -1841, -1841, -1841, -1841,   325, -1841, -1841,
   -1841, -1841,  1439,  1441,  1444, -1841,  1668,  6817, 14046, 14046,
   12663, 14046, -1841,  1446, 12696, 15978, 14424, -1841, -1841,  9197,
    9197, -1841,  1670, -1841,  5291,  1675,  1445, -1841,   725,   726,
   14018,  3275,  1677,  1447, -1841, -1841, 11328,  1448,  1449, 13585,
   14451,  1679,  6817,  1684,  1455, 11328, -1841, -1841,   733,   -98,
     -82,   -76,   -42,   -31,  8958,   -29, -1841,  1687, 13614, -1841,
   -1841,  1522, -1841, 11328, 11328, -1841, -1841,  9197,  3539,  1696,
    1461, 14046,   541,  5291, -1841, -1841, -1841, -1841,    27, -1841,
    6213, -1841, 13643,  1458,  1460,  1462,  1701,  3707, -1841,  1703,
    1725, -1841, -1841,  1486,  1726,   735, -1841,  1728,  1730,   335,
    5291, 11328, 11328,  1492,  6817,   736,  5291, 16003, -1841, -1841,
   -1841, -1841, 16028, 12729, -1841,  1152,  1207,  6817,   541, -1841,
   11328,  6213,    25,  9197,  9197, 11328,  1732,   738, -1841, -1841,
   11328,  1401, -1841, 11328, -1841, -1841,   741,   744, -1841, -1841,
    6817,   646,   667,  9197, -1841, -1841,    77,  6514, -1841, -1841,
   -1841,  1733, -1841,  1497,  6817, -1841, 13672,  1736,  9197,   412,
     412,   412,   412,   412, -1841, -1841, 11328, 13701, 13730,   746,
   -1841, -1841, -1841, -1841, -1841, -1841,  1504,  1738,  1503, -1841,
    1741, -1841, -1841,    38, -1841,  1572, -1841, -1841, -1841, -1841,
   -1841, 11328, 12762, 12795,  6817, -1841,  1744, 11328,  1511, -1841,
   11328,  1512,  1517, -1841, -1841,  1246, -1841,  1519,   749,   755,
   13759, -1841,  1520, 12828,  1524, 12861, -1841,  1523,   757,  1525,
     412,  6817,  1746,  1526,   412,  1747,   760,  1521, -1841, 11328,
   -1841,  1748,  1638, 12049,  1527, -1841,   762,   -25,    13,   196,
     247,   251,  3742, -1841, -1841,  1749,  1751, -1841, -1841, -1841,
    1753, -1841,  1528,  5291, 11328, 11328,   763, -1841,  5291, 12894,
   -1841, -1841,  1152,  6213,  1532, -1841, -1841, -1841, 11328, 11328,
   -1841, 11328,  9197,  1755,   412,   145, -1841, -1841,   412,   163,
   -1841,  1756, -1841, 13788, -1841, 11328, -1841,   452, -1841,  1772,
    9197,  9197,  9197,  9197,  8958, -1841, -1841, -1841, 12534, -1841,
   11328, 16053, 12927,    58, 11328,  1533, -1841, -1841, 12960, 12993,
   13026,   765, -1841,   254, -1841,   257, -1841, -1841, -1841,  4160,
     580, 12106, -1841,   768,   773,   776,   778,   261,   779,  1534,
     781, -1841, 11328, -1841,  6817, 13817, -1841, 11328, 11328, 11328,
   -1841,   412,   412, -1841, -1841, -1841,   452,  1775,  1776,  1777,
    1778,  9197,  1779,  1780,  1781,  1545, 16078,   784,  1782, 13846,
   14046, 13059,   311,   320,   649, -1841, -1841, -1841, -1841,   789,
   -1841, -1841, -1841,  5735, -1841,  1548, -1841,  1783, -1841, 11328,
   11328, 11328, -1841,  1788,   796, -1841,  1550,  6817, -1841, 13875,
   13904, 13933, -1841,  1790,  5735,  5735,   815, -1841,  1791,  1792,
   -1841, -1841,   816, -1841,  1794, -1841, -1841,  1795,  5735, -1841,
   -1841, -1841
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1841, -1841, -1841, -1841,   470, -1841, -1841, -1841, -1841,  -257,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841, -1841,  -703,  -123,  3977,  3270, -1841,  1361, -1841, -1841,
   -1841, -1841, -1841, -1841, -1840, -1841,   418,   244,   -69, -1841,
     -30, -1841,   184,   457,  1810, -1841,    -1,   -47, -1841, -1841,
      -2,  -600,  -307, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841,  1811, -1841, -1841, -1841, -1841, -1203, -1201,  1812, -1680,
    1813, -1841, -1841, -1841,  1230, -1841,   -84, -1841, -1841, -1841,
   -1841,  1998, -1841, -1841, -1376,   332,  1817, -1841,     7,  -587,
   -1841, -1841,   235, -1841, -1639,   -27,  -160,  2665,  2579,  -297,
     113, -1841,  1711,   -89, -1841, -1841,   137,   302, -1641,  -142,
    1075, -1841,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -554
static const yytype_int16 yytable[] =
{
     136,   117,   116,   598,  1443,   614,  1445,   445,   916,   917,
     294,  1016,   391,   426,   395,  1609,  1808,   155,  1843,  1024,
    1844,   631,   273,   635,   479,   396,   153,   154,  1341,   153,
    1308,  1685,   486,   398,   714,  1961,   527,   550,  1507,  1438,
    1474,   327,   353,   153,  1836,  1578,   275,   430,   153,  1241,
     167,  1440,   280,   280,  1762,   289,   332,   143,   333,   156,
     299,   157,   606,   607,  2093,   606,   607,   408,   171,   453,
     357,   606,   607,  1763,   331,   281,  1032,   139,   606,   607,
     452,   432,   275,   911,     4,   300,   918,   356,  1430,     5,
     687,   153,   690,  1579,   337,   743,   726,   338,   392,   922,
     702,   301,   302,  1142,   752,   606,   607,  1878,  1143,  1291,
     339,   996,   755,   606,   607,   137,   420,   421,   756,   138,
     328,  1569,   585,   586,   587,  1403,  1426,   141,  1887,   606,
     607,   606,   607,   431,  1444,   433,  1475,  1476,   441,   441,
     406,   552,  1029,   334,   407,   140,   447,   606,   607,   741,
    1805,  2074,  1918,   606,   607,   145,   572,   742,  1038,  1047,
     458,   420,   421,   627,   628,   629,   487,  1056,  1919,  2076,
     719,   323,   720,   324,  1920,   747,   441,  1543,  1139,   572,
     642,   275,  2065,   748,   275,   142,   695,   606,   607,   275,
     275,   441,  1309,  1310,  1311,  1312,   758,  1439,   606,   607,
     606,   607,   756,   146,   606,   607,   715,   716,  1921,  1441,
    1508,  1509,    62,    63,    64,    65,   147,   273,  1686,  1922,
     188,  1923,  1015,   189,   329,  2050,   190,    76,  1022,   719,
      79,   720,   524,  1291,  1773,   110,   617,   751,   110,   191,
     618,   275,   606,   607,  1443,   531,   532,  1824,   750,   793,
     110,   110,   110,   794,   584,   275,   751,   110,   275,   548,
     632,  1978,   156,  2051,   157,   397,   138,   591,  1151,   547,
     978,   596,  1313,   399,   275,   275,   528,   551,   275,   275,
     275,   275,   330,   354,  1301,   148,   719,   168,   720,  1242,
     907,   275,   909,   910,   149,   275,   144,   356,   308,   310,
     110,   313,   409,  2094,   150,   172,   410,   358,   151,   923,
    1292,  1295,   156,   152,   157,  2016,   416,   417,   418,   419,
     275,   275,   275,  1131,   706,   420,   421,   744,   727,   745,
     728,   751,  -546,   746,   729,   164,   753,   275,   745,  1332,
     420,   421,   754,   275,   606,   607,   854,   794,   958,  1294,
     794,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,  1635,
    1636,   844,  1291,   571,   606,   607,  1039,  1040,  2089,  1801,
     889,   836,   703,   704,   794,   420,   421,   994,   573,   165,
     574,  1121,   606,   607,   575,  1039,  1040,   719,   717,   720,
     721,   441,   275,   156,   723,   157,   275,   275,   420,   421,
     890,   573,  1146,   574,   794,   420,   421,   575,   696,  1322,
     697,  1274,   275,  -549,   698,   606,   607,   166,   730,   416,
     417,   418,   419,   169,   738,   416,   417,   418,  1023,   170,
     416,   417,   418,   419,   159,   173,  2052,   160,   850,   763,
     161,   183,   162,   420,   421,  2117,   184,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,   314,   606,   607,   275,   571,
     606,   607,   174,   606,   607,  1825,   606,   607,  1704,   175,
     606,   607,   707,   833,   176,   708,  1266,  2053,   709,  1267,
     710,  2054,   275,   584,  2101,   845,   177,  2102,  2156,   275,
     826,  2111,  1677,  1678,   441,  1974,   441,   275,   441,   441,
     447,   966,  1727,   840,  1695,   178,  -550,   275,   275,   275,
     441,   441,   275,   155,   719,   155,   720,   275,   601,   602,
     606,   607,  1244,   849,   179,   851,   610,   615,   290,   606,
     607,   291,   552,   292,   606,   607,  1390,   719,  1391,   720,
    1337,  2140,   315,   275,   293,  1264,   316,  1198,   794,   881,
    2141,  1401,   317,   318,   998,   319,   320,  1950,   794,   416,
     417,   418,   419,  1198,  1199,  1951,   512,   981,   513,   275,
     275,  1017,  1200,  1201,  1202,   321,   606,   607,  1203,  1204,
    1199,  1187,   295,   420,   421,   296,   433,   433,  1200,  1201,
    1202,   180,   608,   738,  1203,  1204,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,   738,   275,   275,   275,   571,  1472,
    1004,   304,   305,   156,  1005,   157,  1149,   181,   285,  1145,
     794,   286,  1146,   306,   287,   182,   288,   307,   447,   441,
     447,   441,   441,   441,   441,   441,   441,    41,   441,   441,
     441,   441,   980,   185,   441,   441,   441,   155,   986,  1487,
    1069,   275,  1442,   186,  1012,  1491,   738,   985,  1034,   738,
     304,   305,   995,   606,   607,   416,   417,   418,   419,  1198,
     187,   738,   306,   420,   421,   653,   312,   138,   275,   609,
    -548,  1198,   193,   606,   607,  1629,  1199,   194,   275,   420,
     421,   569,   570,  1026,  1200,  1201,  1202,   571,  1199,   616,
    1203,  1204,  1529,  1033,   276,  1035,  1200,  1201,  1202,   275,
    1043,   277,  1203,  1204,   278,   275,  1545,   303,   447,  1054,
     279,   719,  1550,   720,  1058,   282,   441,   297,   283,   794,
     284,  1161,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   792,   567,   568,   569,   570,
    1198,  1979,  1980,   719,   571,   720,   719,  1981,   720,   275,
     298,   275,   693,   567,   568,   569,   570,  1199,  1786,   311,
    1787,   571,  1983,  1984,  1705,  1200,  1201,  1202,  1981,  1179,
     326,  1203,  1204,  1182,  1652,  1183,  1714,   794,  1226,   794,
     420,   421,   794,   335,   275,   322,  2104,  -553,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,   914,   915,  1227,  2080,   571,   602,   794,   325,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,   336,  1173,   341,
     275,   571,  1228,  1473,  1270,   342,   794,   343,   794,  1443,
    1304,  1378,  1400,   275,   794,   794,   794,   349,   350,  1408,
    1293,  1296,   275,   794,   361,  2142,  1423,   153,   364,   351,
     794,   275,   719,  2124,   720,   886,   738,   352,   738,   738,
     564,   565,   693,   567,   568,   569,   570,  1162,   362,  1163,
    1541,   571,   738,  1443,   794,  1591,  1297,   359,  1622,   794,
    1623,  1711,   794,  1734,   794,  1712,  1273,   794,  1274,   365,
     366,   367,   368,   369,   370,   371,   372,   373,  1614,  1694,
    1615,  1695,   374,   375,   376,   377,   740,   738,   360,  1736,
     378,   379,   380,   794,  1817,   381,  1863,   382,   794,  1879,
    1864,  1901,  1902,  1880,   363,   794,   794,   383,  1284,  1917,
     384,  1947,  1956,  1864,  1972,   751,  1957,  1976,  1864,   393,
    1977,   794,  2005,   738,   794,  2025,   794,  1307,   405,   794,
     411,  2026,   275,  2033,  1515,   794,  2041,  1864,  2049,  2063,
     794,  2100,   794,  1864,  2107,   794,  1303,   404,   794,  2108,
     414,   275,  2109,   794,  2110,  2112,   794,  2114,   794,   794,
    2135,  1957,   412,   275,  1864,  2143,  1402,  1404,   441,   794,
    1797,  1798,  2153,   436,  1354,  1355,  2154,  1357,  1358,  1359,
     437,  1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,
    1370,  2164,  2167,   138,   450,  1864,  2168,   452,   275,   275,
     454,   275,   275,   275,   455,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   456,   457,   275,   385,   386,
     387,   462,   466,   480,   485,   520,   523,  -192,  -193,   388,
    -194,  1382,   529,   389,   530,   390,   110,   533,   536,   537,
     538,   549,   595,   581,   656,   407,   582,   633,   636,   589,
     637,   592,   597,  1395,   599,   275,   441,   441,   619,   600,
     620,   420,   421,   621,   634,   622,   623,   624,  -547,  1409,
    1530,   625,   630,   638,   639,   643,  1190,   275,   640,   641,
     644,   645,   648,  1196,   649,   655,   664,  1207,   665,   681,
     682,   666,   683,   275,   275,   275,   677,   678,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,   738,  1698,   680,   684,
     571,  1700,  1455,   685,   686,   688,   689,  1402,  1404,   705,
     711,   718,   724,   725,   137,   760,  1466,  1467,  1468,   731,
     764,   769,   785,   790,   796,   797,   275,  1710,   798,   827,
     837,   571,   857,   858,   855,   884,   894,   895,   898,   901,
     275,   275,   275,   905,   906,   908,   934,   936,   952,   937,
     939,   275,   947,   956,   153,   364,   441,   959,   997,   988,
     441,   990,  1554,  2023,  1559,  1499,  1003,  1007,  1008,   441,
    1009,   441,  1010,  1011,   441,  1019,  1018,  1020,  1030,  1031,
    1046,  1036,  1062,  1048,  1051,  1493,  1057,  1059,  1063,   275,
    1070,  1071,  1072,  1074,  1075,  1076,   365,   366,   367,   368,
     369,   370,   371,   372,   373,  1078,  1079,  1080,   356,   374,
     375,   376,   377,  1081,  1082,  1353,  1987,   378,   379,   380,
    1083,  1084,   381,  1085,   382,  1086,  1558,  1087,   441,  1090,
    1094,  1119,  1120,   275,   383,   275,  1128,   384,  1135,  1573,
    1129,  1130,  1144,  1577,  1138,  1150,  1153,  1166,  1154,  1174,
     275,  1158,  1167,  1371,  1168,  1176,  1221,  1185,  1193,  1194,
    1219,  1233,  1234,   275,  1235,  1197,  1236,   275,  1247,  1248,
    1249,  1260,  1263,  1252,  1276,  1262,  1269,   414,  1272,  1277,
    1281,  1282,  1275,  1278,  1283,  1290,  1299,  1300,  1719,  1719,
    1305,  1319,  1306,  1325,  1706,  1624,  1625,  1626,  1326,  1328,
    1327,  1336,  1333,  1631,  1339,  1343,  1340,  1356,  1424,  1360,
    1372,  1693,  1386,  1394,  -195,  1412,  1413,  1414,  1646,   275,
     275,   275,  1417,  1418,  1419,  1852,  1420,   275,  1421,  1654,
    1422,  1431,  1432,  1435,  1437,  1436,  1447,  1662,  1446,  1448,
    1449,  1450,   275,  1451,  1452,   385,   386,   387,  1453,  1454,
    1458,  1457,  1459,   275,  1460,  1461,   388,  1462,  1463,  1464,
     389,   275,   390,   110,   275,  1469,  1477,  1483,  1482,  1489,
    1500,  1490,  1506,  1746,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,   719,  1492,   720,  1715,   571,  1494,  1498,  1511,
    1512,  1518,  1514,  1517,  1778,  1522,  1524,  1525,  1526,  1725,
    1528,  1456,  1542,  1540,  1548,  1563,  1546,  1561,  1568,  1570,
    1562,   356,  1574,  1575,  1576,  1581,  1582,   447,   447,  1583,
    1584,  1585,  1586,   275,  1587,  1745,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,   441,  1588,  1589,  1590,   571,  1611,  1792,  1617,   275,
    1634,  1600,  1621,  1607,   275,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,  1855,  1627,  1628,  1632,   571,  1633,  1648,
    1649,  1663,  1668,  1640,  1669,  1670,  1641,  1642,  1674,  1829,
    1675,  1655,  1643,  1676,  1702,  1656,  1834,  1837,  1657,  1658,
    1659,  1660,  1785,  1665,  1708,  1778,  1690,  1680,  1993,  1683,
    1267,  1697,  1707,  1701,  1728,  1846,  1721,  1726,  1729,  1731,
    1733,  1737,  1738,  1740,  1741,  1744,   275,  1753,  1725,   275,
     275,  1747,  1754,  1755,  1756,  1758,  1759,  1760,   433,   433,
    1761,  1765,  1764,  1821,  1766,  1772,  2010,  1767,  1781,  1779,
    1780,  1146,   275,  1783,  1806,  1807,  1816,  1802,   275,  1820,
    1848,  1849,  1838,  1882,  1840,  1851,  1856,   275,  1868,  1869,
    1839,  1870,  1871,  1886,  1845,   751,  1898,   441,  -551,  1651,
     441,  1899,  1877,  1905,  1883,  1912,  1884,  1854,  1892,  1885,
    1900,  1914,  1906,  1924,  1908,  1909,  1926,   738,   275,   738,
    1915,  2058,  1931,  1932,  1938,  1303,  1939,  1941,  1940,   356,
    1943,   275,   447,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,  1944,  1946,  1945,  1948,   571,  1949,  1954,  1971,  1990,
    1725,  2081,  1995,  1991,  2007,   447,  2006,  2009,  2008,  2011,
    2017,  1936,  2037,  2040,  2044,  2056,  -552,  2057,  2020,  2059,
    2024,  2072,  2077,  2021,   275,  2028,  2030,  2042,  2032,  2045,
    2034,  2038,  2048,  2060,  2067,  1913,   275,   275,  2082,  2096,
    2113,  2125,  2126,  2127,  2128,  2130,  2131,  2132,  2136,  2148,
    2133,  1497,  1966,  2147,  2152,  2155,  2160,  2165,  2166,   275,
    2169,  2170,  1544,  2090,  1603,  1757,  1752,  1962,  1935,  1782,
     759,   275,  1572,   115,   126,   127,   128,   897,  1985,  1692,
     134,  1850,  1835,  1720,   275,     0,  1053,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1955,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
    1963,     0,   439,   442,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1725,   275,     0,     0,     0,     0,  1967,
     275,   275,     0,     0,     0,     0,     0,  1992,     0,     0,
     474,  1809,  1810,  1811,  1812,  1813,  1815,   275,     0,     0,
     275,     0,     0,     0,   433,   488,     0,     0,     0,     0,
       0,   275,     0,     0,     0,   275,     0,     0,     0,   153,
     364,     0,     0,     0,     0,     0,     0,  1725,     0,     0,
       0,     0,     0,     0,  2066,     0,     0,     0,     0,     0,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,  2036,     0,     0,     0,     0,     0,
       0,   365,   366,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,   374,   375,   376,   377,   275,  1513,
       0,     0,   378,   379,   380,     0,     0,   381,     0,   382,
       0,     0,   738,     0,     0,     0,     0,     0,     0,   383,
       0,     0,   384,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   414,     0,     0,     0,     0,   275,   275,   275,
     275,   275,     0,     0,     0,     0,     0,   738,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1725,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,   275,     0,
     385,   386,   387,     0,     0,   699,     0,     0,     0,     0,
    1725,   388,     0,     0,     0,   389,     0,   390,   110,     0,
     441,     0,     0,     0,   428,     0,     0,     0,   438,     0,
       0,     0,   443,     0,   275,     0,     0,     0,     0,     0,
       0,   441,   441,     0,  1997,  1998,  1999,  2000,  2001,     0,
    1715,     0,   459,   460,   461,   441,   463,   464,   465,     0,
     467,   468,   469,   470,   471,   472,   473,     0,   475,   476,
     477,   478,     0,     0,     0,   482,     0,     0,     0,     0,
       0,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  2035,     0,     0,     0,  2039,
       0,     0,     0,     0,     0,     0,     0,     0,   830,     0,
     832,     0,   834,   835,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   846,   847,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,   541,   543,   544,   482,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2073,
       0,     0,     0,  2075,   578,   482,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2087,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,   605,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2122,  2123,     0,     0,
       0,     0,     0,   646,   482,     0,     0,     0,   650,   651,
     652,     0,   654,     0,     0,     0,   657,   658,   659,     0,
       0,   660,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   965,     0,   967,   968,   969,   970,   971,
     972,     0,   974,   975,   976,   977,     0,     0,   982,   983,
     984,     0,     0,   153,   364,     0,     0,     0,     0,   692,
       0,     0,     0,   482,   701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     712,   713,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1644,     0,   739,   365,   366,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,   374,   375,
     376,   377,   765,   766,   767,   768,   378,   379,   380,     0,
     773,   381,  1052,   382,   777,     0,     0,     0,     0,     0,
    1060,     0,     0,   383,     0,     0,   384,     0,   791,   541,
       0,     0,     0,   795,     0,     0,     0,   799,   800,   801,
     802,   803,   804,   805,   806,   807,   808,   809,   810,   811,
     812,   813,   814,   815,   817,   818,   819,   820,   821,   822,
     823,   823,     0,   828,   829,     0,   831,     0,     0,     0,
       0,     0,     0,   838,     0,     0,   842,   843,     0,     0,
       0,     0,     0,   823,     0,     0,     0,     0,   482,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,   871,   872,   874,   876,   877,   878,   879,   880,
       0,   882,   883,     0,     0,     0,     0,     0,     0,   891,
     892,   893,  1699,     0,   385,   386,   387,   899,   900,     0,
     482,   482,     0,     0,     0,   388,     0,     0,     0,   389,
       0,   390,   110,     0,     0,     0,     0,     0,     0,   539,
     692,   919,     0,     0,     0,   924,   925,   926,   927,   928,
     929,   930,   931,   932,     0,     0,     0,     0,   938,     0,
     940,     0,   941,     0,     0,     0,   482,   482,   482,   946,
       0,   948,   949,   950,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,   973,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1415,     0,   482,     0,     0,     0,     0,     0,     0,   992,
       0,   993,     0,     0,   882,   883,     0,     0,     0,     0,
       0,     0,     0,  1006,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
       0,     0,     0,     0,     0,  1027,  1028,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,     0,  1044,  1045,     0,     0,   482,  1050,     0,     0,
       0,  1044,  1331,     0,     0,     0,     0,     0,  1061,     0,
       0,     0,  1064,     0,     0,     0,   484,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,  1088,   571,
     874,     0,  1091,     0,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,     0,  1703,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1132,     0,     0,     0,     0,
    1383,  1384,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   483,     0,     0,     0,   579,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   482,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   482,     0,     0,     0,     0,     0,
       0,     0,  1172,     0,     0,     0,  1178,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
    1191,  1192,     0,     0,     0,     0,  1195,     0,     0,     0,
       0,     0,     0,   542,     0,     0,   483,     0,     0,     0,
       0,     0,  1220,     0,     0,  1222,     0,     0,     0,     0,
       0,     0,   483,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1237,     0,  1239,  1240,     0,
    1479,     0,     0,     0,  1481,     0,     0,  1709,     0,     0,
       0,     0,     0,  1485,     0,  1486,  1258,     0,  1488,     0,
       0,     0,     0,     0,   700,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1280,
       0,     0,     0,     0,     0,     0,  1286,  1287,  1288,  1289,
       0,   483,     0,     0,  1298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1323,  1324,
       0,     0,  1531,     0,   482,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,  1348,  1349,  1350,  1351,     0,     0,     0,
     483,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,   482,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1374,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1375,  1376,  1377,     0,     0,   852,
       0,  1379,  1380,     0,  1381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1388,  1389,  1819,     0,
       0,     0,     0,     0,  1392,  1393,   542,     0,     0,     0,
       0,  1397,     0,  1398,  1399,     0,     0,     0,     0,     0,
    1405,  1406,     0,     0,     0,   482,   482,     0,     0,     0,
     816,   902,   903,     0,     0,     0,     0,   824,   825,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,  1434,     0,     0,
     848,   571,     0,     0,     0,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   943,   944,   945,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1465,   875,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
    1480,     0,     0,     0,     0,  1739,     0,   483,   483,     0,
       0,     0,     0,   987,     0,     0,     0,     0,     0,     0,
       0,  1405,  1406,     0,     0,     0,  1496,     0,     0,     0,
       0,  1904,     0,     0,     0,     0,     0,     0,     0,     0,
    1505,     0,     0,  1510,     0,     0,     0,     0,     0,     0,
    1021,     0,     0,   483,   483,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1532,  1042,     0,  1535,   482,  1538,   482,  1049,     0,     0,
       0,     0,     0,     0,  1547,     0,  1549,     0,  1547,  1553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   483,     0,     0,     0,
       0,  1830,     0,     0,  1832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1122,   483,     0,     0,
       0,     0,     0,   483,     0,     0,     0,  1630,     0,     0,
       0,     0,     0,     0,  1637,  1638,  1639,     0,     0,     0,
       0,     0,     0,  1645,     0,  1647,     0,     0,     0,     0,
       0,     0,  1650,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1157,     0,     0,   482,     0,   875,     0,  1092,
    1666,     0,     0,     0,     0,  1165,     0,     0,  1671,  1672,
    1673,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1684,     0,     0,  1184,     0,     0,     0,     0,     0,     0,
    1696,     0,   483,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,  1713,     0,     0,     0,
       0,     0,  1722,  1723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   483,     0,
       0,     0,     0,     0,     0,  1930,     0,     0,     0,     0,
       0,   483,     0,     0,     0,  1750,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
       0,     0,     0,     0,     0,     0,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,  1768,  1769,  1770,   571,     0,
     719,     0,   720,     0,     0,     0,  1771,     0,  1681,     0,
       0,  1774,  1775,  1776,     0,  1330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1784,     0,     0,     0,     0,
     482,   482,  1790,     0,  1791,     0,     0,     0,     0,     0,
    1799,  1800,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
       0,     0,     0,  1818,     0,     0,     0,     0,     0,  1373,
       0,     0,     0,     0,     0,     0,  1828,     0,     0,  1831,
       0,     0,     0,  1833,     0,     0,     0,     0,     0,     0,
       0,     0,  1775,  1776,     0,  1842,     0,   722,     0,     0,
       0,   483,     0,  1847,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1942,     0,     0,     0,     0,     0,  1860,
       0,     0,     0,     0,  1866,  1867,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1872,     0,
       0,  1873,  1872,     0,     0,     0,  1410,  1411,  2055,     0,
       0,     0,     0,     0,     0,   483,     0,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,   482,   482,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1907,     0,   839,     0,     0,     0,
       0,     0,     0,  1916,     0,     0,     0,     0,     0,     0,
       0,     0,   541,     0,     0,     0,     0,     0,     0,     0,
       0,  1927,  1928,  1478,     0,   482,     0,     0,     0,     0,
       0,     0,   483,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2145,     0,     0,   887,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1952,
    1953,     0,     0,     0,     0,  2161,  2163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1965,  2171,
       0,   482,   482,  1970,     0,     0,     0,     0,  1973,     0,
       0,  1975,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   482,     0,     0,     0,  1537,     0,  1539,     0,   483,
       0,     0,     0,     0,     0,     0,   482,     0,     0,     0,
       0,     0,     0,     0,  2002,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,  2013,
       0,     0,     0,     0,     0,  2018,     0,     0,  2019,     0,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,  2043,     0,     0,
       0,   483,     0,   483,     0,     0,     0,     0,   158,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2061,  2062,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2068,  2069,     0,  2070,
     482,     0,     0,     0,     0,     0,  1664,     0,     0,     0,
       0,     0,     0,  2079,     0,     0,     0,     0,   482,   482,
     482,   482,   482,     0,     0,     0,     0,     0,  1866,     0,
       0,     0,  2095,     0,     0,     0,     0,     0,     0,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
       0,  1107,  1108,  1109,  1110,     0,  1112,  1113,  1114,  1115,
    2116,     0,     0,     0,     0,  2119,  2120,  2121,     0,     0,
    1125,     0,  1127,     0,     0,     0,     0,     0,     0,   482,
    1134,     0,     0,   427,     0,     0,     0,  1140,  1141,     0,
       0,     0,   483,     0,     0,     0,  1152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2149,  2150,  2151,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,   951,     0,  2103,     0,     0,     0,
       0,     0,   912,     0,     0,     0,     0,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     514,   515,   516,   517,   518,   519,     0,   521,   522,     0,
       0,  1788,  1789,     0,   525,   526,     0,     0,     0,     0,
       0,     0,  1751,     0,     0,     0,   534,   535,     0,     0,
       0,     0,     0,     0,  1243,  1245,  1246,     0,     0,     0,
    1250,  1251,     0,     0,  1254,  1255,  1256,  1257,     0,  1259,
       0,   195,   153,     0,  1265,     0,     0,     0,   196,   197,
     198,     0,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     400,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,   483,     0,
       0,     0,     0,   228,   229,   230,   231,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,   483,     0,     0,     0,
     237,    20,     0,   238,  1347,     0,     0,     0,     0,  1352,
       0,     0,   661,   662,   663,     0,     0,     0,   667,   668,
     669,   670,   671,   672,   673,     0,   674,     0,  1896,  1897,
     675,   676,     0,     0,   679,     0,     0,     0,     0,     0,
       0,     0,     0,  1881,   552,     0,     0,   691,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,  1929,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1407,     0,     0,     0,     0,     0,
       0,     0,   248,     0,   483,   483,   249,     0,     0,     0,
       0,   251,   252,   253,     0,   254,   255,   256,     0,     0,
       0,   110,  1968,  1969,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   401,   542,
       0,     0,  1986,     0,   259,     0,     0,     0,     0,   345,
       0,     0,   483,   593,     0,     0,   262,  1996,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,   552,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,   856,     0,     0,     0,   732,
      50,     0,     0,    53,   733,     0,   734,   735,     0,   736,
       0,     0,     0,     0,     0,     0,     0,   552,   483,   483,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   483,     0,
       0,     0,     0,     0,  1519,     0,     0,     0,     0,     0,
      87,    88,    89,   483,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   792,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,  2071,  1555,     0,     0,     0,     0,     0,     0,   960,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2083,
    2084,  2085,  2086,  2088,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1592,  1593,  1594,  1595,  1596,     0,
       0,     0,     0,  1601,  1602,   920,     0,  1604,     0,  1606,
       0,     0,     0,  1610,     0,     0,  1612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1620,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2129,     0,     0,     0,     0,     0,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,   483,   483,   483,   483,
       0,     0,     0,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,  1679,     0,
    1682,     0,     0,     0,  1689,     0,  1691,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     792,   567,   568,   569,   570,     0,   483,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1716,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,  1795,
       0,     0,     0,  1796,     0,     0,     0,     0,  1147,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1164,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,   195,     6,   364,     0,   571,  1777,     0,   196,   197,
     198,   789,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,     0,     0,  1556,   366,   367,   368,   369,   370,
     371,   372,   373,   228,   229,   230,   231,   374,   375,   376,
     377,   232,   233,     0,     0,   378,   379,   380,     0,     0,
     381,     0,   382,   234,   235,   236,     0,     0,     0,     0,
     237,    20,   383,   238,     0,   384,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,   242,     0,     0,
       0,     0,     0,     0,    37,     0,     0,  1857,   243,     0,
    1858,     0,     0,     0,     0,     0,     0,     0,   244,     0,
      51,    52,     0,   245,     0,   246,     0,     0,   247,     0,
       0,     0,     0,    62,    63,    64,    65,    66,     0,     0,
      68,    69,    70,    71,    72,     0,     0,     0,    76,     0,
       0,    79,     0,     0,     0,  1342,     0,     0,  1888,  1889,
       0,  1891,     0,     0,     0,     0,     0,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,   248,   385,   386,   387,   249,   250,  1155,   749,
       0,   251,   252,   253,   388,   254,   255,   256,   389,     0,
     390,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1933,  1934,     0,     0,     0,     0,   257,   258,     0,
       0,     0,     0,     0,   259,     0,     0,     0,     0,   345,
       0,     0,     0,  1557,     0,     0,   262,     0,  1396,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     6,   364,
       0,     0,     0,     0,   196,   197,   198,     0,  1964,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,     0,     0,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   228,
     229,   230,   231,   374,   375,   376,   377,   232,   233,     0,
       0,   378,   379,   380,     0,     0,   381,     0,   382,   234,
     235,   236,     0,     0,     0,     0,   237,    20,   383,   238,
       0,   384,     0,     0,     0,   239,     0,     0,   240,     0,
       0,   241,     0,   242,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,    51,    52,     0,   245,
    1156,   246,     0,     0,   247,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     0,     0,    68,    69,    70,    71,
      72,     0,  1520,  1521,    76,     0,     0,    79,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1471,     0,     0,     0,   248,   385,
     386,   387,   249,   250,     0,     0,     0,   251,   252,   253,
     388,   254,   255,   256,   389,     0,   390,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   258,     0,     0,     0,  1608,     0,
     259,     0,     0,     0,     0,   345,     0,     0,  1616,   261,
       0,     0,   262,     0,   195,   153,   364,     0,   413,     0,
    2138,   196,   197,   198,     0,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   400,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,     0,     0,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   228,   229,   230,   231,
     374,   375,   376,   377,   232,     0,     0,     0,   378,   379,
     380,     0,     0,   381,     0,   382,   234,   235,   236,     0,
       0,     0,     0,   237,    20,   383,   238,     0,   384,     0,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   414,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,  1748,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   415,     0,
       0,     0,     0,     0,     0,   248,   385,   386,   387,   249,
       0,     0,     0,     0,   251,   252,   253,   388,   254,   255,
     256,   389,     0,   390,   110,   416,   417,   418,   419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   401,     0,     0,     0,     0,     0,   259,     0,   420,
     421,     0,   422,     0,   423,   195,     6,   344,   424,   262,
       0,     0,   196,   197,   198,     0,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
     231,     0,     0,     0,     0,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
       0,     0,     0,     0,   237,    20,     0,   238,     0,     0,
       0,     0,     0,   239,     0,     0,   240,     0,     0,   241,
       0,   242,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,   153,
     364,     0,   244,     0,    51,    52,     0,   245,     0,   246,
       0,     0,   247,     0,     0,     0,     0,    62,    63,    64,
      65,    66,     0,     0,    68,    69,    70,    71,    72,     0,
       0,     0,    76,     0,     0,    79,     0,     0,     0,     0,
       0,   365,   366,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,   374,   375,   376,   377,     0,     0,
       0,     0,   378,   379,   380,     0,     0,   381,     0,   382,
       0,     0,     0,     0,     0,     0,   248,     0,     0,   383,
     249,   250,   384,     0,     0,   251,   252,   253,     0,   254,
     255,   256,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,   258,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   414,   345,   195,     6,     0,   346,     0,   647,
     262,   196,   197,   198,     0,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   230,   231,
       0,     0,     0,     0,   232,   233,     0,     0,     0,     0,
     385,   386,   387,     0,     0,     0,   234,   235,   236,     0,
       0,   388,     0,   237,    20,   389,   238,   390,   110,     0,
       0,     0,   239,     0,     0,   240,     0,     0,   241,     0,
     242,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   243,     0,     0,     0,     0,     0,     0,   394,   364,
       0,   244,     0,    51,    52,     0,   245,     0,   246,     0,
       0,   247,     0,     0,     0,     0,    62,    63,    64,    65,
      66,     0,     0,    68,    69,    70,    71,    72,     0,     0,
       0,    76,     0,     0,    79,     0,     0,     0,     0,     0,
     365,   366,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,   374,   375,   376,   377,     0,     0,     0,
       0,   378,   379,   380,     0,     0,   381,     0,   382,     0,
       0,     0,     0,     0,     0,   248,     0,     0,   383,   249,
     250,   384,     0,     0,   251,   252,   253,     0,   254,   255,
     256,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   481,     0,     0,     0,     0,     0,   259,     0,     0,
       0,     0,   345,   195,     6,  1653,     0,   545,     0,   262,
     196,   197,   198,     0,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,   229,   230,   231,     0,
       0,     0,     0,   232,   233,     0,     0,     0,     0,   385,
     386,   387,     0,     0,     0,   234,   235,   236,     0,     0,
     388,     0,   237,    20,   389,   238,   390,     0,     0,     0,
       0,   239,     0,     0,   240,     0,     0,   241,     0,   242,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,   364,     0,
     244,     0,    51,    52,     0,   245,     0,   246,     0,     0,
     247,     0,     0,     0,     0,    62,    63,    64,    65,    66,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      76,     0,     0,    79,     0,     0,     0,     0,     0,   365,
     366,   367,   368,   369,   370,   371,   372,   373,     0,     0,
       0,     0,   374,   375,   376,   377,     0,     0,     0,     0,
     378,   379,   380,     0,     0,   381,     0,   382,     0,     0,
       0,     0,     0,     0,   248,     0,     0,   383,   249,   250,
     384,     0,     0,   251,   252,   253,     0,   254,   255,   256,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
     258,     0,     0,     0,     0,     0,   259,     0,     0,     0,
       0,   345,   195,     6,     0,   261,     0,     0,   262,   196,
     197,   198,     0,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   229,   230,   231,     0,     0,
       0,     0,   232,   233,     0,     0,     0,     0,   385,   386,
     387,     0,     0,     0,   234,   235,   236,     0,     0,   388,
       0,   237,    20,   389,   238,   390,     0,     0,     0,     0,
     239,     0,     0,   240,     0,     0,   241,     0,   242,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,    51,    52,     0,   245,     0,   246,     0,     0,   247,
       0,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       0,    68,    69,    70,    71,    72,     0,     0,     0,    76,
       0,     0,    79,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,  1822,     0,     0,     0,  1823,     0,     0,     0,     0,
       0,     0,     0,   248,     0,     0,     0,   249,   250,     0,
       0,     0,   251,   252,   253,     0,   254,   255,   256,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   611,  1814,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
     613,   195,     6,     0,   307,   545,     0,   262,   196,   197,
     198,     0,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,   231,     0,     0,     0,
       0,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,     0,     0,     0,     0,
     237,    20,     0,   238,     0,     0,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,   242,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
      51,    52,     0,   245,     0,   246,     0,     0,   247,     0,
       0,     0,     0,    62,    63,    64,    65,    66,     0,     0,
      68,    69,    70,    71,    72,     0,     0,     0,    76,     0,
       0,    79,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
    1988,     0,     0,     0,  1989,     0,     0,     0,     0,     0,
       0,     0,   248,     0,     0,     0,   249,   250,     0,     0,
       0,   251,   252,   253,     0,   254,   255,   256,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   258,     0,
       0,     0,     0,     0,   259,     0,     0,     0,     0,   260,
     195,     6,     0,   261,     0,     0,   262,   196,   197,   198,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   230,   231,     0,     0,     0,     0,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   235,   236,     0,     0,     0,     0,   237,
      20,     0,   238,     0,     0,     0,     0,     0,   239,     0,
       0,   240,     0,     0,   241,     0,   242,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,    51,
      52,     0,   245,     0,   246,     0,     0,   247,     0,     0,
       0,     0,    62,    63,    64,    65,    66,     0,     0,    68,
      69,    70,    71,    72,     0,     0,     0,    76,     0,     0,
      79,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   912,     0,     0,     0,     0,     0,     0,
       0,   248,     0,     0,     0,   249,   250,     0,     0,     0,
     251,   252,   253,     0,   254,   255,   256,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,   258,     0,     0,
       0,     0,     0,   259,     0,     0,     0,     0,   345,   195,
       6,     0,   261,     0,     0,   262,   196,   197,   198,     0,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,   229,   230,   231,     0,     0,     0,     0,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,   236,     0,     0,     0,     0,   237,    20,
       0,   238,     0,     0,     0,     0,     0,   239,     0,     0,
     240,     0,     0,   241,     0,   242,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,     0,    51,    52,
       0,   245,     0,   246,     0,     0,   247,     0,     0,     0,
       0,    62,    63,    64,    65,    66,     0,     0,    68,    69,
      70,    71,    72,     0,     0,     0,    76,     0,     0,    79,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   913,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,   249,   250,     0,     0,     0,   251,
     252,   253,     0,   254,   255,   256,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,   481,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,   345,   195,     6,
       0,   540,     0,     0,   262,   196,   197,   198,     0,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,   231,     0,     0,     0,     0,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,   235,   236,     0,     0,     0,     0,   237,    20,     0,
     238,     0,     0,     0,     0,     0,   239,     0,     0,   240,
       0,     0,   241,     0,   242,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,    51,    52,     0,
     245,     0,   246,     0,     0,   247,     0,     0,     0,     0,
      62,    63,    64,    65,    66,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    76,     0,     0,    79,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   957,     0,     0,     0,     0,     0,     0,     0,   248,
       0,     0,     0,   249,   250,     0,     0,     0,   251,   252,
     253,     0,   254,   255,   256,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,   481,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,   345,   195,     6,     0,
       0,   545,     0,   262,   196,   197,   198,     0,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,     0,     0,     0,     0,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,     0,     0,     0,     0,   237,    20,     0,   238,
       0,     0,     0,     0,     0,   239,     0,     0,   240,     0,
       0,   241,     0,   242,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,    51,    52,     0,   245,
       0,   246,     0,     0,   247,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     0,     0,    68,    69,    70,    71,
      72,     0,     0,     0,    76,     0,     0,    79,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1065,     0,     0,     0,     0,     0,     0,     0,   248,     0,
       0,     0,   249,   250,     0,     0,     0,   251,   252,   253,
       0,   254,   255,   256,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   258,     0,     0,     0,     0,     0,
     259,     0,     0,     0,     0,   583,   195,     6,     0,   261,
       0,     0,   262,   196,   197,   198,     0,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,   229,
     230,   231,     0,     0,     0,     0,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
     236,     0,     0,     0,     0,   237,    20,     0,   238,     0,
       0,     0,     0,     0,   239,     0,     0,   240,     0,     0,
     241,     0,   242,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,    51,    52,     0,   245,     0,
     246,     0,     0,   247,     0,     0,     0,     0,    62,    63,
      64,    65,    66,     0,     0,    68,    69,    70,    71,    72,
       0,     0,     0,    76,     0,     0,    79,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1066,
       0,     0,     0,     0,     0,     0,     0,   248,     0,     0,
       0,   249,   250,     0,     0,     0,   251,   252,   253,     0,
     254,   255,   256,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,   258,     0,     0,     0,     0,     0,   259,
       0,     0,     0,     0,   590,   195,     6,     0,   261,     0,
       0,   262,   196,   197,   198,     0,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
     231,     0,     0,     0,     0,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
       0,     0,     0,     0,   237,    20,     0,   238,     0,     0,
       0,     0,     0,   239,     0,     0,   240,     0,     0,   241,
       0,   242,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,    51,    52,     0,   245,     0,   246,
       0,     0,   247,     0,     0,     0,     0,    62,    63,    64,
      65,    66,     0,     0,    68,    69,    70,    71,    72,     0,
       0,     0,    76,     0,     0,    79,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1067,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
     249,   250,     0,     0,     0,   251,   252,   253,     0,   254,
     255,   256,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,   481,     0,     0,     0,     0,     0,   259,     0,
       0,     0,     0,   345,   195,     6,     0,   873,     0,  1329,
     262,   196,   197,   198,     0,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   230,   231,
       0,     0,     0,     0,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,   236,     0,
       0,     0,     0,   237,    20,     0,   238,     0,     0,     0,
       0,     0,   239,     0,     0,   240,     0,     0,   241,     0,
     242,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,     0,    51,    52,     0,   245,     0,   246,     0,
       0,   247,     0,     0,     0,     0,    62,    63,    64,    65,
      66,     0,     0,    68,    69,    70,    71,    72,     0,     0,
       0,    76,     0,     0,    79,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1068,     0,     0,
       0,     0,     0,     0,     0,   248,     0,     0,     0,   249,
     250,     0,     0,     0,   251,   252,   253,     0,   254,   255,
     256,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   481,     0,     0,     0,     0,     0,   259,   195,     6,
       0,     0,   345,  1536,     0,   196,   197,   198,     0,   262,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,   231,     0,     0,     0,     0,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,   235,   236,     0,     0,     0,     0,   237,    20,     0,
     238,     0,     0,     0,     0,     0,   239,     0,     0,   240,
       0,     0,   241,     0,   242,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,    51,    52,     0,
     245,     0,   246,     0,     0,   247,     0,     0,     0,     0,
      62,    63,    64,    65,    66,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    76,     0,     0,    79,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,   248,
       0,     0,     0,   249,   250,     0,     0,     0,   251,   252,
     253,     0,   254,   255,   256,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,   481,     0,     0,     0,     0,
       0,   259,   195,     6,     0,     0,   345,     0,     0,   196,
     197,   198,     0,   262,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   229,   230,   231,     0,     0,
       0,     0,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,   235,   236,     0,     0,     0,
       0,   237,    20,     0,   238,     0,     0,     0,     0,     0,
     239,     0,     0,   240,     0,     0,   241,     0,   242,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,    51,    52,     0,   245,     0,   246,     0,     0,   247,
       0,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       0,    68,    69,    70,    71,    72,     0,     0,     0,    76,
       0,     0,    79,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1116,     0,     0,     0,     0,
       0,     0,     0,   248,     0,     0,     0,   249,   250,     0,
       0,     0,   251,   252,   253,     0,   254,   255,   256,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,   258,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
     345,   195,     6,     0,  1661,     0,     0,   262,   196,   197,
     198,     0,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,   231,     0,     0,     0,
       0,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,     0,     0,     0,     0,
     237,    20,     0,   238,     0,     0,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,   242,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
      51,    52,     0,   245,     0,   246,     0,     0,   247,     0,
       0,     0,     0,    62,    63,    64,    65,    66,     0,     0,
      68,    69,    70,    71,    72,     0,     0,     0,    76,     0,
       0,    79,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1117,     0,     0,     0,     0,     0,
       0,     0,   248,     0,     0,     0,   249,   250,     0,     0,
       0,   251,   252,   253,     0,   254,   255,   256,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   611,  1814,     0,
       0,     0,     0,     0,   259,     0,     0,     0,     0,   613,
     195,     6,     0,   307,     0,     0,   262,   196,   197,   198,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   230,   231,     0,     0,     0,     0,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   235,   236,     0,     0,     0,     0,   237,
      20,     0,   238,     0,     0,     0,     0,     0,   239,     0,
       0,   240,     0,     0,   241,     0,   242,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,    51,
      52,     0,   245,     0,   246,     0,     0,   247,     0,     0,
       0,     0,    62,    63,    64,    65,    66,     0,     0,    68,
      69,    70,    71,    72,     0,     0,     0,    76,     0,     0,
      79,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1118,     0,     0,     0,     0,     0,     0,
       0,   248,     0,     0,     0,   249,   250,     0,     0,     0,
     251,   252,   253,     0,   254,   255,   256,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,   481,     0,     0,
       0,     0,     0,   259,   195,   153,   364,     0,   345,     0,
       0,   196,   197,   198,     0,   262,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   400,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,     0,     0,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   228,   229,   230,   231,
     374,   375,   376,   377,   232,     0,     0,     0,   378,   379,
     380,     0,     0,   381,     0,   382,   234,   235,   236,     0,
       0,     0,     0,   237,    20,   383,   238,     0,   384,   195,
     153,   364,     0,     0,     0,     0,   196,   197,   198,     0,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   400,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
       0,     0,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   228,   229,   230,   231,   374,   375,   376,   377,   232,
       0,     0,     0,   378,   379,   380,     0,     0,   381,     0,
     382,   234,   235,   236,     0,     0,     0,     0,   237,    20,
     383,   238,     0,   384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   385,   386,   387,   249,
       0,     0,     0,     0,   251,   252,   253,   388,   254,   255,
     256,   389,     0,   390,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   401,     0,     0,     0,     0,     0,   259,     0,     0,
       0,     0,   345,     0,     0,     0,  1552,     0,     0,   262,
       0,     0,     0,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
     248,   385,   386,   387,   249,  1123,     0,     0,     0,   251,
     252,   253,   388,   254,   255,   256,   389,     0,   390,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,   401,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,   345,   195,   153,
     364,  1827,     0,     0,   262,   196,   197,   198,     0,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   400,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,     0,     0,
       0,  1556,   366,   367,   368,   369,   370,   371,   372,   373,
     228,   229,   230,   231,   374,   375,   376,   377,   232,     0,
       0,     0,   378,   379,   380,     0,     0,   381,     0,   382,
     234,   235,   236,     0,     0,     0,     0,   237,    20,   383,
     238,     0,   384,   195,   153,   364,     0,     0,     0,     0,
     196,   197,   198,     0,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   400,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,     0,     0,     0,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   228,   229,   230,   231,   374,
     375,   376,   377,   232,     0,     0,     0,   378,   379,   380,
       0,     0,   381,     0,   382,   234,   235,   236,     0,     0,
       0,     0,   237,    20,   383,   238,     0,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     385,   386,   387,   249,     0,     0,     0,     0,   251,   252,
     253,   388,   254,   255,   256,   389,     0,   390,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,   401,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,   345,     0,     0,     0,
    1715,     0,     0,   262,     0,     0,     0,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,   248,   385,   386,   387,   249,  1124,
       0,     0,     0,   251,   252,   253,   388,   254,   255,   256,
     389,     0,   390,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
     401,     0,     0,     0,     0,     0,   259,   195,   153,     0,
       0,   345,     0,     0,   196,   197,   198,     0,   262,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   400,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,     0,   195,   153,     0,   237,    20,   841,   238,
     196,   197,   198,     0,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   400,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,   229,   230,   231,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   236,     0,     0,
       0,     0,   237,    20,     0,   238,     0,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,   248,  1126,
       0,     0,   249,     0,     0,     0,     0,   251,   252,   253,
       0,   254,   255,   256,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   611,   612,     0,     0,     0,     0,     0,
     259,     0,     0,     0,     0,   613,     0,     0,     0,   307,
       0,     0,   262,     0,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,   248,     0,   571,     0,   249,     0,
       0,     0,     0,   251,   252,   253,  1232,   254,   255,   256,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
     401,     0,     0,     0,     0,     0,   259,   195,   153,     0,
       0,   345,     0,     0,   196,   197,   198,     0,   262,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   400,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,     0,     0,     0,     0,   237,    20,     0,   238,
     195,   153,     0,  1279,     0,     0,     0,   196,   197,   198,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   400,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   230,   231,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   235,   236,     0,     0,     0,     0,   237,
      20,     0,   238,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,   248,     0,
       0,     0,   249,     0,     0,  1253,     0,   251,   252,   253,
       0,   254,   255,   256,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   401,     0,     0,     0,     0,     0,
     259,     0,     0,     0,     0,   345,  1055,     0,     0,     0,
       0,     0,   262,     0,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,   248,     0,     0,     0,   249,  1338,     0,     0,     0,
     251,   252,   253,     0,   254,   255,   256,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,   401,     0,     0,
       0,     0,     0,   259,   195,   153,     0,  1433,   345,     0,
       0,   196,   197,   198,     0,   262,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   400,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   230,   231,
       0,     0,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,   236,     0,
       0,     0,     0,   237,    20,     0,   238,   195,   153,     0,
    1495,     0,     0,     0,   196,   197,   198,     0,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   400,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,     0,     0,     0,     0,   237,    20,     0,   238,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,   248,     0,     0,     0,   249,
       0,     0,  1427,     0,   251,   252,   253,     0,   254,   255,
     256,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   401,     0,     0,     0,     0,     0,   259,     0,     0,
       0,     0,   345,     0,     0,     0,     0,     0,     0,   262,
       0,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,   248,     0,
       0,     0,   249,  1428,     0,     0,     0,   251,   252,   253,
       0,   254,   255,   256,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   401,     0,     0,     0,     0,     0,
     259,   195,   153,     0,     0,   345,     0,     0,   196,   197,
     198,     0,   262,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     400,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,   231,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,     0,   195,   153,     0,
     237,    20,     0,   238,   196,   197,   198,     0,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   400,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,     0,     0,     0,     0,   237,    20,     0,   238,
       0,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,   248,  1470,     0,     0,   249,     0,     0,     0,
       0,   251,   252,   253,     0,   254,   255,   256,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   401,     0,
       0,     0,     0,     0,   259,     0,     0,     0,     0,   345,
    1551,     0,     0,     0,     0,     0,   262,     0,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,   248,     0,
     571,     0,   249,     0,     0,     0,     0,   251,   252,   253,
    1597,   254,   255,   256,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   401,     0,     0,     0,     0,     0,
     259,   195,   153,     0,     0,   345,  1874,     0,   196,   197,
     198,     0,   262,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     400,   217,   218,   219,   220,   221,   222,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,   231,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,     0,     0,     0,     0,
     237,    20,     0,   238,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1598,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,     0,     0,     0,     0,   732,    50,     0,     0,
      53,   733,     0,   734,   735,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,     0,     0,     0,   249,    87,    88,    89,
       0,   251,   252,   253,     0,   254,   255,   256,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   401,     0,
       0,     0,     0,     0,   259,     0,     7,     8,     0,   345,
       0,     0,     0,     0,     0,     0,   262,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,   942,     0,     0,     0,   732,    50,     0,     0,
      53,   733,     0,   734,   735,     0,   736,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    87,    88,    89,
      38,    39,    40,    41,     0,     0,    43,     0,     0,     0,
       0,     0,     0,   732,    50,     0,     0,    53,   733,     0,
     734,   735,     0,   736,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,    87,    88,    89,     0,     0,     0,
     732,    50,   989,     0,    53,   733,     0,   734,   735,     0,
     736,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    87,    88,    89,    38,    39,    40,    41,     0,     0,
      43,     0,     0,     0,     0,     0,     0,   732,    50,   991,
       0,    53,   733,     0,   734,   735,     0,   736,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,    87,    88,
      89,     0,     0,     0,   732,    50,  1186,     0,    53,   733,
       0,   734,   735,     0,   736,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    87,    88,    89,    38,    39,
      40,    41,     0,     0,    43,     0,     0,     0,     0,     0,
       0,   732,    50,  1188,     0,    53,   733,     0,   734,   735,
       0,   736,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,    87,    88,    89,     0,     0,     0,   732,    50,
    1189,     0,    53,   733,     0,   734,   735,     0,   736,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    87,
      88,    89,    38,    39,    40,    41,     0,     0,    43,     0,
       0,     0,     0,     0,     0,   732,    50,  1208,     0,    53,
     733,     0,   734,   735,     0,   736,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,    41,     0,     0,    43,    87,    88,    89,     0,
       0,     0,   732,    50,  1238,     0,    53,   733,     0,   734,
     735,     0,   736,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    87,    88,    89,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,     0,   732,
      50,  1271,     0,    53,   733,     0,   734,   735,     0,   736,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
      87,    88,    89,     0,     0,     0,   732,    50,  1425,     0,
      53,   733,     0,   734,   735,     0,   736,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    73,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,    87,    88,    89,
       0,     0,    -4,    -4,     0,     0,  1599,     0,     0,     0,
       0,     0,     0,     0,     0,  2046,     0,     0,     0,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,     0,     0,     0,     0,    -4,     0,    -4,    -4,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,  2105,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     6,     0,    -4,    -4,    -4,
       0,     0,     0,    -4,     7,     8,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,     9,    10,     0,    -4,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
       0,    -4,     0,     0,     0,    11,    12,    13,     0,     0,
       0,    14,    15,     0,    16,     0,     0,     0,     0,    17,
       0,    18,    19,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,    37,    38,    39,
      40,    41,    42,     0,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     7,     8,     0,
      82,    83,    84,     0,     0,     0,    85,     0,     0,     0,
       0,    86,    87,    88,    89,     0,     0,    90,     0,    91,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,     0,     0,
       0,     0,     0,     0,   732,    50,     0,     0,    53,   733,
       0,   734,   735,     0,   736,     0,     0,     0,  1000,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,  1001,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    87,    88,    89,    38,    39,
      40,    41,     0,     0,    43,     0,     0,     0,     0,     0,
       0,   732,    50,     0,     0,    53,   733,     0,   734,   735,
       0,   736,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,    87,    88,    89,     0,     0,     0,     0,     0,
       0,  1613,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1743,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1861,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1862,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1890,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1893,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1960,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2014,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2015,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2029,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2031,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2064,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2092,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2097,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2098,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2099,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2139,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,  1037,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,  1093,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,  1136,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,  1137,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,  1180,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,  1211,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,  1229,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,  1285,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
    1385,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,  1429,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,  1501,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,  1502,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,  1503,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,  1504,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,  1793,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,  1804,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,  1841,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,  1910,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
    1925,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,  1937,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,  1994,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,  2003,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,  2004,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,  2027,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,  2078,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,  2118,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,  2137,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,  2157,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
    2158,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,  2159,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,     0,   694,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,     0,   904,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,     0,  1903,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,   719,     0,
     720,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,   963,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,  1014,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,  1160,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,  1224,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,  1225,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
       0,     0,  1230,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   693,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,  1231,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   693,   567,   568,   569,   570,     0,     0,
       0,     0,   571,     0,     0,     0,  1321,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     693,   567,   568,   569,   570,     0,     0,     0,     0,   571,
       0,     0,     0,  1335,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   693,   567,   568,
     569,   570,     0,     0,     0,     0,   571,     0,     0,     0,
    1533,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,  1619,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   693,   567,   568,   569,   570,     0,     0,     0,     0,
     571,     0,     0,     0,  1667,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   693,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,  1853,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   693,   567,   568,   569,   570,
       0,     0,     0,     0,   571,     0,     0,     0,  1895,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   693,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,  1911,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     770,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   771,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     772,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   774,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     775,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   776,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     778,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   779,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     780,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   781,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     782,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   783,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     784,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   786,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     787,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   788,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     853,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   888,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     933,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   951,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     953,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   954,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     955,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   961,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
     962,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,   999,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1013,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1073,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1077,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1089,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1159,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1169,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1170,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1171,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1181,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1210,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1212,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1213,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1214,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1215,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1216,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1217,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1218,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1223,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1320,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1334,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1534,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1564,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1565,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1566,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1567,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1605,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1618,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1730,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1732,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1735,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1742,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1794,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1803,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1826,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1894,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  1958,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    1959,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   693,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,  2091,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   693,
     567,   568,   569,   570,     0,     0,     0,     0,   571,     0,
    2134
};

static const yytype_int16 yycheck[] =
{
       3,     3,     3,   300,  1205,   312,  1209,   149,   608,   609,
      57,   714,   101,   136,   103,  1391,  1655,    20,  1698,   722,
    1700,     4,    49,   330,   184,     5,     4,    20,     7,     4,
       4,     4,   192,     5,     4,  1875,     5,     5,     4,     6,
       4,     4,     4,     4,  1685,   131,    49,   136,     4,     7,
       4,     6,    97,    97,    91,    56,     4,     6,     6,   241,
     151,   243,   229,   230,     6,   229,   230,     6,     4,   158,
       4,   229,   230,   110,    77,   120,   120,    14,   229,   230,
       9,     4,    85,   250,     6,   176,   250,    90,   246,     0,
     397,     4,   399,   179,    94,     9,     9,    97,   101,   250,
     407,   192,   193,   242,     9,   229,   230,  1748,   247,     7,
     110,   698,   244,   229,   230,   245,   238,   239,   250,   249,
      83,     6,   282,   283,   284,   247,   250,   241,  1767,   229,
     230,   229,   230,   136,   250,   137,   100,   101,   141,   142,
     241,     8,   729,    91,   245,    97,   149,   229,   230,   242,
     250,     6,   250,   229,   230,     6,     9,   250,     6,   746,
     163,   238,   239,   323,   324,   325,   193,   754,   250,     6,
     242,    97,   244,    99,   250,   242,   179,     6,   250,     9,
     340,   184,  2022,   250,   187,   241,     9,   229,   230,   192,
     193,   194,   166,   167,   168,   169,   244,   164,   229,   230,
     229,   230,   250,     6,   229,   230,   176,   177,   250,   164,
     176,   177,   135,   136,   137,   138,     6,   244,   191,   250,
      91,   250,     7,    94,   187,   250,    97,   150,     7,   242,
     153,   244,   233,     7,  1610,   213,   241,   250,   213,   110,
     245,   244,   229,   230,  1445,   246,   247,     8,   242,   246,
     213,   213,   213,   250,   281,   258,   250,   213,   261,   262,
     243,  1900,   241,   250,   243,   245,   249,   294,   855,   262,
     248,   298,   246,   245,   277,   278,   245,   245,   281,   282,
     283,   284,   245,   245,   245,     6,   242,   241,   244,   247,
     597,   294,   599,   600,   241,   298,   245,   300,    63,    64,
     213,    66,   241,   245,     6,   241,   245,   241,   243,   616,
    1013,  1014,   241,   243,   243,  1954,   214,   215,   216,   217,
     323,   324,   325,   242,   413,   238,   239,   241,   241,   243,
     243,   250,   245,   247,   247,   241,   241,   340,   243,   242,
     238,   239,   247,   346,   229,   230,   246,   250,   655,   247,
     250,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     6,
       7,   531,     7,   240,   229,   230,   224,   225,  2058,   246,
     246,   523,   409,   410,   250,   238,   239,   694,   241,   241,
     243,   244,   229,   230,   247,   224,   225,   242,   425,   244,
     245,   404,   405,   241,     6,   243,   409,   410,   238,   239,
     246,   241,   250,   243,   250,   238,   239,   247,   241,   241,
     243,   243,   425,   245,   247,   229,   230,   241,   431,   214,
     215,   216,   217,   241,   435,   214,   215,   216,   217,   241,
     214,   215,   216,   217,    91,   241,   250,    94,   537,   452,
      97,   245,    99,   238,   239,  2094,   112,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     4,   229,   230,   481,   240,
     229,   230,   241,   229,   230,   246,   229,   230,     7,   241,
     229,   230,    91,   520,   241,    94,   247,   250,    97,   250,
      99,   250,   505,   530,   250,   532,   241,   250,  2147,   512,
     513,   250,     6,     7,   517,  1891,   519,   520,   521,   522,
     523,   663,   241,   526,   243,   241,   245,   530,   531,   532,
     533,   534,   535,   536,   242,   538,   244,   540,   303,   304,
     229,   230,   250,   536,   241,   538,   311,   312,    94,   229,
     230,    97,     8,    99,   229,   230,  1143,   242,  1145,   244,
     242,   250,    91,   566,   110,   250,    95,   131,   250,   572,
     250,  1158,   101,   102,   246,   104,   105,   242,   250,   214,
     215,   216,   217,   131,   148,   250,   241,   676,   243,   592,
     593,   714,   156,   157,   158,   124,   229,   230,   162,   163,
     148,   908,    94,   238,   239,    97,   608,   609,   156,   157,
     158,   241,   245,   614,   162,   163,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   635,   638,   639,   640,   240,     8,
     246,   229,   230,   241,   250,   243,   246,   241,    91,   247,
     250,    94,   250,   241,    97,   241,    99,   245,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   110,   671,   672,
     673,   674,   675,    97,   677,   678,   679,   680,   681,  1266,
     769,   684,   246,     6,   711,  1272,   687,   680,   735,   690,
     229,   230,   695,   229,   230,   214,   215,   216,   217,   131,
     245,   702,   241,   238,   239,   247,   245,   249,   711,   245,
     245,   131,    99,   229,   230,  1418,   148,   241,   721,   238,
     239,   234,   235,   726,   156,   157,   158,   240,   148,   245,
     162,   163,  1319,   734,   241,   736,   156,   157,   158,   742,
     743,   245,   162,   163,   245,   748,  1333,   245,   751,   752,
      97,   242,  1339,   244,   757,    94,   759,   241,    97,   250,
      99,   884,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     131,   135,   136,   242,   240,   244,   242,   141,   244,   792,
      94,   794,   231,   232,   233,   234,   235,   148,     4,   245,
       6,   240,   135,   136,  1507,   156,   157,   158,   141,   898,
      94,   162,   163,   246,   246,   246,  1519,   250,   246,   250,
     238,   239,   250,    94,   827,   241,   246,   245,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   606,   607,   246,  2047,   240,   611,   250,    97,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    97,   895,     4,
     873,   240,   246,   242,   246,     4,   250,     4,   250,  2080,
     246,   246,   246,   886,   250,   250,   250,     4,   241,   246,
    1013,  1014,   895,   250,     6,   246,   246,     4,     5,   241,
     250,   904,   242,  2106,   244,   245,   907,   241,   909,   910,
     229,   230,   231,   232,   233,   234,   235,   241,     6,   243,
     246,   240,   923,  2124,   250,   246,  1015,   241,   246,   250,
     246,   246,   250,   246,   250,   250,   241,   250,   243,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   241,   241,
     243,   243,    59,    60,    61,    62,     6,   958,   241,   246,
      67,    68,    69,   250,   246,    72,   246,    74,   250,   246,
     250,   246,   246,   250,   243,   250,   250,    84,  1005,   246,
      87,   246,   246,   250,   246,   250,   250,   246,   250,   241,
     246,   250,   246,   994,   250,   246,   250,  1024,   245,   250,
       6,   246,  1005,   246,  1301,   250,   246,   250,   246,   246,
     250,   246,   250,   250,   246,   250,  1019,   243,   250,   246,
     127,  1024,   246,   250,   246,   246,   250,   246,   250,   250,
     246,   250,   249,  1036,   250,   246,  1159,  1160,  1041,   250,
    1640,  1641,   246,   245,  1071,  1072,   250,  1074,  1075,  1076,
       6,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,   246,   246,   249,   241,   250,   250,     9,  1071,  1072,
     241,  1074,  1075,  1076,   241,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,   241,   241,  1090,   195,   196,
     197,   241,   241,   241,   245,   241,   241,   179,   179,   206,
     179,  1128,   245,   210,   120,   212,   213,   241,   241,   241,
     241,   179,     4,   241,   179,   245,   241,     6,     6,   245,
       6,   245,   245,  1150,   245,  1128,  1129,  1130,   241,   245,
     241,   238,   239,   241,   243,   241,   241,   241,   245,  1166,
     247,   241,   241,   245,   245,   243,   911,  1150,   245,   245,
     243,   243,     6,   918,     6,   245,   241,   922,   241,   243,
       6,   241,     6,  1166,  1167,  1168,   241,   241,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,  1187,  1494,   241,   245,
     240,  1498,  1219,     6,     8,     6,     8,  1320,  1321,   245,
       7,     6,   245,     6,   245,    86,  1233,  1234,  1235,   246,
     250,   250,   242,     7,     6,     6,  1219,  1514,   242,   245,
     245,   240,    64,     8,   247,     4,     7,     7,   241,     6,
    1233,  1234,  1235,   242,     6,   245,     7,     6,   246,     7,
       6,  1244,     6,   176,     4,     5,  1249,   245,   244,   246,
    1253,   246,  1341,     7,  1343,  1282,   242,     6,   245,  1262,
     245,  1264,   245,   245,  1267,     7,   247,     6,   243,   241,
       4,   245,   242,     6,     6,  1276,     6,     6,   243,  1282,
       7,     7,     7,     7,     7,     7,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     7,     7,     7,  1301,    59,
      60,    61,    62,     7,     7,  1070,  1906,    67,    68,    69,
       7,     7,    72,     7,    74,     7,  1343,     7,  1321,   245,
       6,   242,   244,  1326,    84,  1328,   250,    87,   246,  1356,
     250,   250,   242,  1360,   250,     7,   245,     7,   246,     4,
    1343,   247,   245,     6,   245,     6,     6,   247,   246,   246,
       7,     7,     7,  1356,     7,   131,   247,  1360,   242,   242,
     250,     9,   242,   250,   179,   250,   244,   127,   247,     7,
     246,   245,   249,   151,     6,     6,     6,     4,  1520,  1521,
      46,   247,    46,   241,  1507,  1412,  1413,  1414,   245,   245,
     241,   241,   247,  1420,   247,     4,   241,     7,     4,     7,
       7,  1490,   250,   242,   179,     7,     7,     7,  1435,  1412,
    1413,  1414,     6,   242,   250,  1712,     7,  1420,     7,  1446,
       7,   109,     4,   245,   241,     6,     6,  1454,     7,     7,
       7,     7,  1435,     7,     7,   195,   196,   197,     7,     7,
       6,   245,     6,  1446,     6,    97,   206,     7,     6,     6,
     210,  1454,   212,   213,  1457,     4,     4,   250,   248,   242,
     246,   250,     6,  1552,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   242,   245,   244,   245,   240,   245,   245,     6,
       6,   243,     7,     6,  1617,     6,   241,   241,   245,  1526,
       6,     6,     6,   246,     6,     6,   247,   244,     6,   124,
     250,  1514,     6,     6,     6,     6,     6,  1520,  1521,     6,
       6,     6,     6,  1526,     6,  1552,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,  1544,     6,     6,     5,   240,     6,  1636,     4,  1552,
       7,   242,     6,   242,  1557,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,  1715,     4,     6,   245,   240,   245,     6,
       6,     6,     6,   245,     6,   175,   245,   245,     6,  1678,
       6,   245,   243,     6,     6,   245,  1685,  1686,   245,   245,
     245,   245,  1629,   245,     7,  1728,   242,   250,  1915,   250,
     250,   245,   247,   250,     4,  1704,   241,   245,     6,     6,
     246,     6,     6,   241,     4,   241,  1629,     6,  1655,  1632,
    1633,     7,     6,     6,     6,     6,     6,     6,  1640,  1641,
       6,     6,    95,  1670,     5,   242,  1943,   245,     6,   245,
     245,   250,  1655,     6,     6,     6,     6,   250,  1661,     6,
       6,     4,   250,     7,   250,     6,     6,  1670,     6,     6,
     242,     6,     6,     5,  1701,   250,     6,  1680,   245,  1444,
    1683,     6,   245,     6,   245,     6,   245,  1714,   242,   245,
     245,     7,   245,     6,   246,   246,   174,  1698,  1701,  1700,
     245,  2008,     6,   242,   246,  1708,   246,     6,   246,  1712,
       7,  1714,  1715,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     6,     6,   247,     6,   240,     6,   245,     6,     6,
    1767,  2048,     6,   246,     6,  1748,   242,     6,   245,   177,
       6,  1840,     6,     6,     6,     6,   245,     6,   246,     6,
     241,     6,     6,   246,  1767,   245,   242,   246,   245,   131,
     245,   245,   245,   245,   242,  1802,  1779,  1780,     6,   246,
     246,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     245,     6,  1881,   245,     6,   245,     6,     6,     6,  1802,
       6,     6,  1332,  2060,  1386,  1570,  1562,  1876,  1838,  1625,
     449,  1814,  1355,     3,     3,     3,     3,   587,  1902,  1487,
       3,  1708,  1685,  1521,  1827,    -1,   751,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1864,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
    1877,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1864,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1900,  1877,    -1,    -1,    -1,    -1,  1882,
    1883,  1884,    -1,    -1,    -1,    -1,    -1,  1914,    -1,    -1,
     179,  1656,  1657,  1658,  1659,  1660,  1661,  1900,    -1,    -1,
    1903,    -1,    -1,    -1,  1906,   194,    -1,    -1,    -1,    -1,
      -1,  1914,    -1,    -1,    -1,  1918,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,  1954,    -1,    -1,
      -1,    -1,    -1,    -1,  2023,    -1,    -1,    -1,    -1,    -1,
    1943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1954,    -1,    -1,  1981,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,  1981,     6,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,  1993,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    87,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,  2032,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,  2050,  2051,  2052,
    2053,  2054,    -1,    -1,    -1,    -1,    -1,  2058,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2094,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2094,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,  2111,    -1,
     195,   196,   197,    -1,    -1,   404,    -1,    -1,    -1,    -1,
    2147,   206,    -1,    -1,    -1,   210,    -1,   212,   213,    -1,
    2133,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,  2147,    -1,    -1,    -1,    -1,    -1,
      -1,  2154,  2155,    -1,  1919,  1920,  1921,  1922,  1923,    -1,
     245,    -1,   164,   165,   166,  2168,   168,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,    -1,   180,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,  1980,    -1,    -1,    -1,  1984,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,    -1,
     519,    -1,   521,   522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   533,   534,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2034,
      -1,    -1,    -1,  2038,   276,   277,   278,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2054,
      -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,
     312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2101,  2102,    -1,    -1,
      -1,    -1,    -1,   345,   346,    -1,    -1,    -1,   350,   351,
     352,    -1,   354,    -1,    -1,    -1,   358,   359,   360,    -1,
      -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   662,    -1,   664,   665,   666,   667,   668,
     669,    -1,   671,   672,   673,   674,    -1,    -1,   677,   678,
     679,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,   401,
      -1,    -1,    -1,   405,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,   436,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,   454,   455,   456,   457,    67,    68,    69,    -1,
     462,    72,   751,    74,   466,    -1,    -1,    -1,    -1,    -1,
     759,    -1,    -1,    84,    -1,    -1,    87,    -1,   480,   481,
      -1,    -1,    -1,   485,    -1,    -1,    -1,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,    -1,   515,   516,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,   525,    -1,    -1,   528,   529,    -1,    -1,
      -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,   540,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
      -1,   573,   574,    -1,    -1,    -1,    -1,    -1,    -1,   581,
     582,   583,     6,    -1,   195,   196,   197,   589,   590,    -1,
     592,   593,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,
      -1,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,   611,
     612,   613,    -1,    -1,    -1,   617,   618,   619,   620,   621,
     622,   623,   624,   625,    -1,    -1,    -1,    -1,   630,    -1,
     632,    -1,   634,    -1,    -1,    -1,   638,   639,   640,   641,
      -1,   643,   644,   645,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,   670,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,   691,
      -1,   693,    -1,    -1,   696,   697,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,
      -1,    -1,    -1,    -1,    -1,   727,   728,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     742,    -1,   744,   745,    -1,    -1,   748,   749,    -1,    -1,
      -1,   753,  1041,    -1,    -1,    -1,    -1,    -1,   760,    -1,
      -1,    -1,   764,    -1,    -1,    -1,   187,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,   790,   240,
     792,    -1,   794,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,   827,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   837,    -1,    -1,    -1,    -1,
    1129,  1130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   277,   278,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   886,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   894,    -1,    -1,    -1,   898,    -1,    -1,    -1,
      -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     912,   913,    -1,    -1,    -1,    -1,   918,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,   934,    -1,    -1,   937,    -1,    -1,    -1,    -1,
      -1,    -1,   277,   278,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   957,    -1,   959,   960,    -1,
    1249,    -1,    -1,    -1,  1253,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,  1262,    -1,  1264,   978,    -1,  1267,    -1,
      -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,
      -1,    -1,    -1,    -1,    -1,    -1,  1008,  1009,  1010,  1011,
      -1,   346,    -1,    -1,  1016,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1030,  1031,
      -1,    -1,  1321,    -1,  1036,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,  1065,  1066,  1067,  1068,    -1,    -1,    -1,
     405,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,  1090,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1116,  1117,  1118,    -1,    -1,   540,
      -1,  1123,  1124,    -1,  1126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1138,  1139,     6,    -1,
      -1,    -1,    -1,    -1,  1146,  1147,   481,    -1,    -1,    -1,
      -1,  1153,    -1,  1155,  1156,    -1,    -1,    -1,    -1,    -1,
    1162,  1163,    -1,    -1,    -1,  1167,  1168,    -1,    -1,    -1,
     505,   592,   593,    -1,    -1,    -1,    -1,   512,   513,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,  1199,    -1,    -1,
     535,   240,    -1,    -1,    -1,   540,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   639,   640,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1252,    -1,    -1,    -1,    -1,  1544,    -1,   592,   593,    -1,
      -1,    -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1273,  1274,    -1,    -1,    -1,  1278,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1292,    -1,    -1,  1295,    -1,    -1,    -1,    -1,    -1,    -1,
     721,    -1,    -1,   638,   639,   640,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1322,   742,    -1,  1325,  1326,  1327,  1328,   748,    -1,    -1,
      -1,    -1,    -1,    -1,  1336,    -1,  1338,    -1,  1340,  1341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   721,    -1,    -1,    -1,
      -1,  1680,    -1,    -1,  1683,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   827,   742,    -1,    -1,
      -1,    -1,    -1,   748,    -1,    -1,    -1,  1419,    -1,    -1,
      -1,    -1,    -1,    -1,  1426,  1427,  1428,    -1,    -1,    -1,
      -1,    -1,    -1,  1435,    -1,  1437,    -1,    -1,    -1,    -1,
      -1,    -1,  1444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   873,    -1,    -1,  1457,    -1,   792,    -1,   794,
    1462,    -1,    -1,    -1,    -1,   886,    -1,    -1,  1470,  1471,
    1472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1482,    -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,
    1492,    -1,   827,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,  1518,    -1,    -1,    -1,
      -1,    -1,  1524,  1525,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   873,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,   886,    -1,    -1,    -1,  1557,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   904,
      -1,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,  1597,  1598,  1599,   240,    -1,
     242,    -1,   244,    -1,    -1,    -1,  1608,    -1,   250,    -1,
      -1,  1613,  1614,  1615,    -1,  1036,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1627,    -1,    -1,    -1,    -1,
    1632,  1633,  1634,    -1,  1636,    -1,    -1,    -1,    -1,    -1,
    1642,  1643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1661,
      -1,    -1,    -1,  1665,    -1,    -1,    -1,    -1,    -1,  1090,
      -1,    -1,    -1,    -1,    -1,    -1,  1678,    -1,    -1,  1681,
      -1,    -1,    -1,  1685,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1694,  1695,    -1,  1697,    -1,   427,    -1,    -1,
      -1,  1036,    -1,  1705,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,  1721,
      -1,    -1,    -1,    -1,  1726,  1727,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1740,    -1,
      -1,  1743,  1744,    -1,    -1,    -1,  1167,  1168,     6,    -1,
      -1,    -1,    -1,    -1,    -1,  1090,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,  1779,  1780,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1796,    -1,   526,    -1,    -1,    -1,
      -1,    -1,    -1,  1805,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1814,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1823,  1824,  1244,    -1,  1827,    -1,    -1,    -1,    -1,
      -1,    -1,  1167,  1168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2133,    -1,    -1,   577,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1861,
    1862,    -1,    -1,    -1,    -1,  2154,  2155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1880,  2168,
      -1,  1883,  1884,  1885,    -1,    -1,    -1,    -1,  1890,    -1,
      -1,  1893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1903,    -1,    -1,    -1,  1326,    -1,  1328,    -1,  1244,
      -1,    -1,    -1,    -1,    -1,    -1,  1918,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1926,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,  1951,
      -1,    -1,    -1,    -1,    -1,  1957,    -1,    -1,  1960,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,  1989,    -1,    -1,
      -1,  1326,    -1,  1328,    -1,    -1,    -1,    -1,    21,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2014,  2015,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2028,  2029,    -1,  2031,
    2032,    -1,    -1,    -1,    -1,    -1,  1457,    -1,    -1,    -1,
      -1,    -1,    -1,  2045,    -1,    -1,    -1,    -1,  2050,  2051,
    2052,  2053,  2054,    -1,    -1,    -1,    -1,    -1,  2060,    -1,
      -1,    -1,  2064,    -1,    -1,    -1,    -1,    -1,    -1,   799,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
      -1,   811,   812,   813,   814,    -1,   816,   817,   818,   819,
    2092,    -1,    -1,    -1,    -1,  2097,  2098,  2099,    -1,    -1,
     830,    -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,  2111,
     840,    -1,    -1,   136,    -1,    -1,    -1,   847,   848,    -1,
      -1,    -1,  1457,    -1,    -1,    -1,   856,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2139,  2140,  2141,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,   242,    -1,     6,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,   231,    -1,
      -1,  1632,  1633,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,    -1,  1557,    -1,    -1,    -1,   249,   250,    -1,    -1,
      -1,    -1,    -1,    -1,   964,   965,   966,    -1,    -1,    -1,
     970,   971,    -1,    -1,   974,   975,   976,   977,    -1,   979,
      -1,     3,     4,    -1,   984,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1632,  1633,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,  1661,    -1,    -1,    -1,
      82,    83,    -1,    85,  1064,    -1,    -1,    -1,    -1,  1069,
      -1,    -1,   365,   366,   367,    -1,    -1,    -1,   371,   372,
     373,   374,   375,   376,   377,    -1,   379,    -1,  1779,  1780,
     383,   384,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,    -1,    -1,   400,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,  1827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,  1779,  1780,   198,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,   213,  1883,  1884,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,  1814,
      -1,    -1,  1903,    -1,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,  1827,   245,    -1,    -1,   248,  1918,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     8,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,   548,    -1,    -1,    -1,   120,
     121,    -1,    -1,   124,   125,    -1,   127,   128,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,  1883,  1884,
      -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1903,    -1,
      -1,    -1,    -1,    -1,  1304,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,  1918,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,  2032,  1342,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2050,
    2051,  2052,  2053,  2054,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1374,  1375,  1376,  1377,  1378,    -1,
      -1,    -1,    -1,  1383,  1384,   246,    -1,  1387,    -1,  1389,
      -1,    -1,    -1,  1393,    -1,    -1,  1396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1408,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2111,    -1,    -1,    -1,    -1,    -1,    -1,  2032,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2050,  2051,  2052,  2053,  2054,
      -1,    -1,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,  1478,    -1,
    1480,    -1,    -1,    -1,  1484,    -1,  1486,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,  2111,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1520,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   851,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   885,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     3,     4,     5,    -1,   240,  1616,    -1,    10,    11,
      12,   246,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,  1717,   110,    -1,
    1720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
     122,   123,    -1,   125,    -1,   127,    -1,    -1,   130,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,    -1,    -1,    -1,   150,    -1,
      -1,   153,    -1,    -1,    -1,  1058,    -1,    -1,  1768,  1769,
      -1,  1771,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,   194,   195,   196,   197,   198,   199,     8,   250,
      -1,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
     212,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1831,  1832,    -1,    -1,    -1,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,   245,    -1,    -1,   248,    -1,  1151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,  1878,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,   122,   123,    -1,   125,
       8,   127,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,   142,   143,   144,   145,
     146,    -1,  1305,  1306,   150,    -1,    -1,   153,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,   212,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,    -1,    -1,    -1,  1391,    -1,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,  1401,   245,
      -1,    -1,   248,    -1,     3,     4,     5,    -1,     7,    -1,
    2120,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,  1556,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,   238,
     239,    -1,   241,    -1,   243,     3,     4,     5,   247,   248,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,   120,    -1,   122,   123,    -1,   125,    -1,   127,
      -1,    -1,   130,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,   142,   143,   144,   145,   146,    -1,
      -1,    -1,   150,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    84,
     198,   199,    87,    -1,    -1,   203,   204,   205,    -1,   207,
     208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,   127,   241,     3,     4,    -1,   245,    -1,     8,
     248,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,   206,    -1,    82,    83,   210,    85,   212,   213,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,   120,    -1,   122,   123,    -1,   125,    -1,   127,    -1,
      -1,   130,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,   146,    -1,    -1,
      -1,   150,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    84,   198,
     199,    87,    -1,    -1,   203,   204,   205,    -1,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,   241,     3,     4,     5,    -1,   246,    -1,   248,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,   195,
     196,   197,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
     206,    -1,    82,    83,   210,    85,   212,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
     120,    -1,   122,   123,    -1,   125,    -1,   127,    -1,    -1,
     130,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,    -1,    -1,
     150,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    84,   198,   199,
      87,    -1,    -1,   203,   204,   205,    -1,   207,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,   241,     3,     4,    -1,   245,    -1,    -1,   248,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,   195,   196,
     197,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,   206,
      -1,    82,    83,   210,    85,   212,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   122,   123,    -1,   125,    -1,   127,    -1,    -1,   130,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,   146,    -1,    -1,    -1,   150,
      -1,    -1,   153,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,   198,   199,    -1,
      -1,    -1,   203,   204,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
     241,     3,     4,    -1,   245,   246,    -1,   248,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
     122,   123,    -1,   125,    -1,   127,    -1,    -1,   130,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,    -1,    -1,    -1,   150,    -1,
      -1,   153,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,   198,   199,    -1,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,
       3,     4,    -1,   245,    -1,    -1,   248,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,
     123,    -1,   125,    -1,   127,    -1,    -1,   130,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,
     153,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,   198,   199,    -1,    -1,    -1,
     203,   204,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,     3,
       4,    -1,   245,    -1,    -1,   248,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,   123,
      -1,   125,    -1,   127,    -1,    -1,   130,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,   153,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,   198,   199,    -1,    -1,    -1,   203,
     204,   205,    -1,   207,   208,   209,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,   241,     3,     4,
      -1,   245,    -1,    -1,   248,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,   122,   123,    -1,
     125,    -1,   127,    -1,    -1,   130,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,    -1,    -1,   150,    -1,    -1,   153,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,   198,   199,    -1,    -1,    -1,   203,   204,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,   241,     3,     4,    -1,
      -1,   246,    -1,   248,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,   122,   123,    -1,   125,
      -1,   127,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,   142,   143,   144,   145,
     146,    -1,    -1,    -1,   150,    -1,    -1,   153,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,   198,   199,    -1,    -1,    -1,   203,   204,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,   241,     3,     4,    -1,   245,
      -1,    -1,   248,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,   122,   123,    -1,   125,    -1,
     127,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,   142,   143,   144,   145,   146,
      -1,    -1,    -1,   150,    -1,    -1,   153,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,   198,   199,    -1,    -1,    -1,   203,   204,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,   241,     3,     4,    -1,   245,    -1,
      -1,   248,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,   122,   123,    -1,   125,    -1,   127,
      -1,    -1,   130,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,   142,   143,   144,   145,   146,    -1,
      -1,    -1,   150,    -1,    -1,   153,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
     198,   199,    -1,    -1,    -1,   203,   204,   205,    -1,   207,
     208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,   241,     3,     4,    -1,   245,    -1,     8,
     248,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,   122,   123,    -1,   125,    -1,   127,    -1,
      -1,   130,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,   146,    -1,    -1,
      -1,   150,    -1,    -1,   153,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,   198,
     199,    -1,    -1,    -1,   203,   204,   205,    -1,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,   236,     3,     4,
      -1,    -1,   241,     8,    -1,    10,    11,    12,    -1,   248,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,   122,   123,    -1,
     125,    -1,   127,    -1,    -1,   130,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,    -1,    -1,   150,    -1,    -1,   153,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,   198,   199,    -1,    -1,    -1,   203,   204,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,   236,     3,     4,    -1,    -1,   241,    -1,    -1,    10,
      11,    12,    -1,   248,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   122,   123,    -1,   125,    -1,   127,    -1,    -1,   130,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,   146,    -1,    -1,    -1,   150,
      -1,    -1,   153,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,   198,   199,    -1,
      -1,    -1,   203,   204,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
     241,     3,     4,    -1,   245,    -1,    -1,   248,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
     122,   123,    -1,   125,    -1,   127,    -1,    -1,   130,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,    -1,    -1,    -1,   150,    -1,
      -1,   153,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,   198,   199,    -1,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,
       3,     4,    -1,   245,    -1,    -1,   248,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,
     123,    -1,   125,    -1,   127,    -1,    -1,   130,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,
     153,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,   198,   199,    -1,    -1,    -1,
     203,   204,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,   236,     3,     4,     5,    -1,   241,    -1,
      -1,    10,    11,    12,    -1,   248,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    -1,    87,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,   212,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,   245,    -1,    -1,   248,
      -1,    -1,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
     194,   195,   196,   197,   198,   250,    -1,    -1,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   212,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,   241,     3,     4,
       5,   245,    -1,    -1,   248,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    -1,    87,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,   196,   197,   198,    -1,    -1,    -1,    -1,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,   212,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
     245,    -1,    -1,   248,    -1,    -1,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,   250,
      -1,    -1,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,    -1,    -1,    -1,    -1,    -1,   236,     3,     4,    -1,
      -1,   241,    -1,    -1,    10,    11,    12,    -1,   248,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,     3,     4,    -1,    82,    83,     8,    85,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   250,
      -1,    -1,   198,    -1,    -1,    -1,    -1,   203,   204,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,   245,
      -1,    -1,   248,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,   194,    -1,   240,    -1,   198,    -1,
      -1,    -1,    -1,   203,   204,   205,   250,   207,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,    -1,    -1,    -1,    -1,    -1,   236,     3,     4,    -1,
      -1,   241,    -1,    -1,    10,    11,    12,    -1,   248,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,   194,    -1,
      -1,    -1,   198,    -1,    -1,   250,    -1,   203,   204,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,   248,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,   198,   250,    -1,    -1,    -1,
     203,   204,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,   236,     3,     4,    -1,     6,   241,    -1,
      -1,    10,    11,    12,    -1,   248,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,   194,    -1,    -1,    -1,   198,
      -1,    -1,   250,    -1,   203,   204,   205,    -1,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,   198,   250,    -1,    -1,    -1,   203,   204,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,
     236,     3,     4,    -1,    -1,   241,    -1,    -1,    10,    11,
      12,    -1,   248,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,     3,     4,    -1,
      82,    83,    -1,    85,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   250,    -1,    -1,   198,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,   248,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,   194,    -1,
     240,    -1,   198,    -1,    -1,    -1,    -1,   203,   204,   205,
     250,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,
     236,     3,     4,    -1,    -1,   241,   242,    -1,    10,    11,
      12,    -1,   248,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,
     124,   125,    -1,   127,   128,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,   198,   171,   172,   173,
      -1,   203,   204,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    13,    14,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,   246,    -1,    -1,    -1,   120,   121,    -1,    -1,
     124,   125,    -1,   127,   128,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   171,   172,   173,
     107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   121,    -1,    -1,   124,   125,    -1,
     127,   128,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   171,   172,   173,    -1,    -1,    -1,
     120,   121,   246,    -1,   124,   125,    -1,   127,   128,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   171,   172,   173,   107,   108,   109,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,   246,
      -1,   124,   125,    -1,   127,   128,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   171,   172,
     173,    -1,    -1,    -1,   120,   121,   246,    -1,   124,   125,
      -1,   127,   128,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   171,   172,   173,   107,   108,
     109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,   121,   246,    -1,   124,   125,    -1,   127,   128,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,   171,   172,   173,    -1,    -1,    -1,   120,   121,
     246,    -1,   124,   125,    -1,   127,   128,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   171,
     172,   173,   107,   108,   109,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,   246,    -1,   124,
     125,    -1,   127,   128,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   171,   172,   173,    -1,
      -1,    -1,   120,   121,   246,    -1,   124,   125,    -1,   127,
     128,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   171,   172,   173,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,   246,    -1,   124,   125,    -1,   127,   128,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     171,   172,   173,    -1,    -1,    -1,   120,   121,   246,    -1,
     124,   125,    -1,   127,   128,    -1,   130,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   147,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,   171,   172,   173,
      -1,    -1,    44,    45,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
      -1,   113,   246,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,     4,    -1,   159,   160,   161,
      -1,    -1,    -1,   165,    13,    14,    -1,    -1,   170,   171,
     172,   173,    -1,    -1,   176,    -1,   178,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    44,    45,    -1,   200,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,   213,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,   106,   107,   108,
     109,   110,   111,    -1,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    13,    14,    -1,
     159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,   178,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   211,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,   124,   125,
      -1,   127,   128,    -1,   130,    -1,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   171,   172,   173,   107,   108,
     109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,   121,    -1,    -1,   124,   125,    -1,   127,   128,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   250,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   250,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,   246,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,   246,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,   246,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,   246,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,   246,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,   246,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,   246,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
     246,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,   246,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,   246,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,   246,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,   246,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,   246,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,   246,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,   246,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
     246,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,   246,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,   246,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,   246,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,   246,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,   246,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,   246,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,   246,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
     246,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   246,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,   245,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,   245,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,   245,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,   242,    -1,
     244,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,   244,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,   244,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,   244,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,   244,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,   244,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,   244,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,   244,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,   244,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,   244,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
     244,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,   244,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,   244,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,   244,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,   244,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,   244,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,   240,    -1,   242,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,   240,    -1,
     242
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   252,   253,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    80,    81,
      83,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   106,   107,   108,
     109,   110,   111,   113,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   159,   160,   161,   165,   170,   171,   172,   173,
     176,   178,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   200,   201,   202,   211,
     213,   254,   256,   257,   277,   295,   297,   301,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   319,   321,   322,
     328,   329,   330,   331,   337,   362,   363,   245,   249,    14,
      97,   241,   241,     6,   245,     6,     6,     6,     6,   241,
       6,   243,   243,     4,   339,   363,   241,   243,   275,    91,
      94,    97,    99,   275,   241,   241,   241,     4,   241,   241,
     241,     4,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   245,   112,    97,     6,   245,    91,    94,
      97,   110,   300,    99,   241,     3,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    55,    56,
      57,    58,    63,    64,    75,    76,    77,    82,    85,    91,
      94,    97,    99,   110,   120,   125,   127,   130,   194,   198,
     199,   203,   204,   205,   207,   208,   209,   229,   230,   236,
     241,   245,   248,   297,   298,   301,   312,   319,   321,   332,
     333,   337,   339,   346,   348,   363,   241,   245,   245,    97,
      97,   120,    94,    97,    99,    91,    94,    97,    99,   297,
      94,    97,    99,   110,   298,    94,    97,   241,    94,   151,
     176,   192,   193,   245,   229,   230,   241,   245,   343,   344,
     343,   245,   245,   343,     4,    91,    95,   101,   102,   104,
     105,   124,   241,    97,    99,    97,    94,     4,    83,   187,
     245,   363,     4,     6,    91,    94,    97,    94,    97,   110,
     299,     4,     4,     4,     5,   241,   245,   346,   347,     4,
     241,   241,   241,     4,   245,   350,   363,     4,   241,   241,
     241,     6,     6,   243,     5,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    61,    62,    67,    68,
      69,    72,    74,    84,    87,   195,   196,   197,   206,   210,
     212,   354,   363,   241,     4,   354,     5,   245,     5,   245,
      32,   230,   332,   363,   243,   245,   241,   245,     6,   241,
     245,     6,   249,     7,   127,   187,   214,   215,   216,   217,
     238,   239,   241,   243,   247,   273,   274,   275,   332,   353,
     354,   363,     4,   301,   302,   303,   245,     6,   332,   353,
     354,   363,   353,   332,   353,   360,   361,   363,   279,   283,
     241,   342,     9,   354,   241,   241,   241,   241,   363,   332,
     332,   332,   241,   332,   332,   332,   241,   332,   332,   332,
     332,   332,   332,   332,   353,   332,   332,   332,   332,   347,
     241,   230,   332,   348,   349,   245,   347,   346,   353,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   241,   243,   275,   275,   275,   275,   275,   275,
     241,   275,   275,   241,   297,   275,   275,     5,   245,   245,
     120,   297,   297,   241,   275,   275,   241,   241,   241,   332,
     245,   332,   348,   332,   332,   246,   349,   339,   363,   179,
       5,   245,     8,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   240,     9,   241,   243,   247,   274,   275,   332,   349,
     349,   241,   241,   241,   346,   347,   347,   347,   296,   245,
     241,   346,   245,   245,   332,     4,   346,   245,   350,   245,
     245,   343,   343,   343,   332,   332,   229,   230,   245,   245,
     343,   229,   230,   241,   303,   343,   245,   241,   245,   241,
     241,   241,   241,   241,   241,   241,   332,   347,   347,   347,
     241,     4,   243,     6,   243,   303,     6,     6,   245,   245,
     245,   245,   347,   243,   243,   243,   332,     8,     6,     6,
     332,   332,   332,   247,   332,   245,   179,   332,   332,   332,
     332,   275,   275,   275,   241,   241,   241,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   241,   241,   275,
     241,   243,     6,     6,   245,     6,     8,   303,     6,     8,
     303,   275,   332,   231,   245,     9,   241,   243,   247,   353,
     349,   332,   303,   346,   346,   245,   354,    91,    94,    97,
      99,     7,   332,   332,     4,   176,   177,   346,     6,   242,
     244,   245,   276,     6,   245,     6,     9,   241,   243,   247,
     363,   246,   120,   125,   127,   128,   130,   295,   297,   332,
       6,   242,   250,     9,   241,   243,   247,   242,   250,   250,
     242,   250,     9,   241,   247,   244,   250,   278,   244,   278,
      86,   341,   338,   363,   250,   332,   332,   332,   332,   250,
     242,   242,   242,   332,   242,   242,   242,   332,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   246,
       7,   332,   231,   246,   250,   332,     6,     6,   242,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   348,   332,   332,   332,
     332,   332,   332,   332,   348,   348,   363,   245,   332,   332,
     353,   332,   353,   346,   353,   353,   360,   245,   332,   276,
     363,     8,   332,   332,   347,   346,   353,   353,   348,   339,
     354,   339,   349,   242,   246,   247,   275,    64,     8,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   245,   332,   348,   332,   332,   332,   332,
     332,   363,   332,   332,     4,   340,   245,   276,   242,   246,
     246,   332,   332,   332,     7,     7,   325,   325,   241,   332,
     332,     6,   349,   349,   245,   242,     6,   303,   245,   303,
     303,   250,   250,   250,   343,   343,   302,   302,   250,   332,
     246,   316,   250,   303,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   242,     7,   326,     6,     7,   332,     6,
     332,   332,   246,   349,   349,   349,   332,     6,   332,   332,
     332,   242,   246,   242,   242,   242,   176,   250,   303,   245,
       8,   242,   242,   244,   360,   353,   360,   353,   353,   353,
     353,   353,   353,   332,   353,   353,   353,   353,   248,   356,
     363,   354,   353,   353,   353,   339,   363,   349,   246,   246,
     246,   246,   332,   332,   303,   363,   340,   244,   246,   242,
     134,   151,   320,   242,   246,   250,   332,     6,   245,   245,
     245,   245,   346,   242,   244,     7,   273,   274,   247,     7,
       6,   349,     7,   217,   273,   258,   363,   332,   332,   340,
     243,   241,   120,   297,   298,   297,   245,   246,     6,   224,
     225,   255,   349,   363,   332,   332,     4,   340,     6,   349,
     332,     6,   353,   361,   363,   242,   340,     6,   363,     6,
     353,   332,   242,   243,   332,   250,   250,   250,   250,   354,
       7,     7,     7,   242,     7,     7,     7,   242,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   332,   242,
     245,   332,   348,   246,     6,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   250,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   250,   250,   250,   242,
     244,   244,   349,   250,   250,   276,   250,   276,   250,   250,
     250,   242,   332,   334,   276,   246,   246,   246,   250,   250,
     276,   276,   242,   247,   242,   247,   250,   275,   335,   246,
       7,   340,   276,   245,   246,     8,     8,   349,   247,   242,
     244,   274,   241,   243,   275,   349,     7,   245,   245,   242,
     242,   242,   332,   346,     4,   324,     6,   292,   332,   354,
     246,   242,   246,   246,   349,   247,   246,   303,   246,   246,
     343,   332,   332,   246,   246,   332,   343,   131,   131,   148,
     156,   157,   158,   162,   163,   317,   318,   343,   246,   313,
     242,   246,   242,   242,   242,   242,   242,   242,   242,     7,
     332,     6,   332,   242,   244,   244,   246,   246,   246,   246,
     244,   244,   250,     7,     7,     7,   247,   332,   246,   332,
     332,     7,   247,   276,   250,   276,   276,   242,   242,   250,
     276,   276,   250,   250,   276,   276,   276,   276,   332,   276,
       9,   355,   250,   242,   250,   276,   247,   250,   336,   244,
     246,   246,   247,   241,   243,   249,   179,     7,   151,     6,
     332,   246,   245,     6,   346,   246,   332,   332,   332,   332,
       6,     7,   273,   274,   247,   273,   274,   354,   332,     6,
       4,   245,   351,   363,   246,    46,    46,   346,     4,   166,
     167,   168,   169,   246,   261,   265,   268,   270,   271,   247,
     242,   244,   241,   332,   332,   241,   245,   241,   245,     8,
     349,   353,   242,   247,   242,   244,   241,   242,   250,   247,
     241,     7,   275,     4,   286,   287,   288,   276,   332,   332,
     332,   332,   276,   343,   346,   346,     7,   346,   346,   346,
       7,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,     6,     7,   349,   332,   332,   332,   332,   246,   332,
     332,   332,   346,   353,   353,   246,   250,   285,   332,   332,
     340,   340,   332,   332,   242,   346,   275,   332,   332,   332,
     246,   340,   274,   247,   274,   332,   332,   276,   246,   346,
     349,   349,     7,     7,     7,   131,   323,     6,   242,   250,
       7,     7,     7,   246,     4,   246,   250,   250,   250,   246,
     246,   109,     4,     6,   332,   245,     6,   241,     6,   164,
       6,   164,   246,   318,   250,   317,     7,     6,     7,     7,
       7,     7,     7,     7,     7,   346,     6,   245,     6,     6,
       6,    97,     7,     6,     6,   332,   346,   346,   346,     4,
     250,     8,     8,   242,     4,   100,   101,     4,   349,   353,
     332,   353,   248,   250,   289,   353,   353,   340,   353,   242,
     250,   340,   245,   297,   245,     6,   332,     6,   245,   346,
     246,   246,   246,   246,   246,   332,     6,     4,   176,   177,
     332,     6,     6,     6,     7,   350,   352,     6,   243,   276,
     275,   275,     6,   262,   241,   241,   245,   272,     6,   340,
     247,   353,   332,   244,   242,   332,     8,   349,   332,   349,
     246,   246,     6,     6,   255,   340,   247,   332,     6,   332,
     340,   242,   245,   332,   354,   276,    46,   245,   346,   354,
     357,   244,   250,     6,   242,   242,   242,   242,     6,     6,
     124,   294,   294,   346,     6,     6,     6,   346,   131,   179,
     293,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   246,   276,   276,   276,   276,   276,   250,   250,   250,
     242,   276,   276,   287,   276,   242,   276,   242,   275,   335,
     276,     6,   276,   250,   241,   243,   275,     4,   242,   244,
     276,     6,   246,   246,   346,   346,   346,     4,     6,   273,
     332,   346,   245,   245,     7,     6,     7,   332,   332,   332,
     245,   245,   245,   243,     6,   332,   346,   332,     6,     6,
     332,   343,   246,     5,   346,   245,   245,   245,   245,   245,
     245,   245,   346,     6,   349,   245,   332,   244,     6,     6,
     175,   332,   332,   332,     6,     6,     6,     6,     7,   276,
     250,   250,   276,   250,   332,     4,   191,   290,   291,   276,
     242,   276,   336,   354,   241,   243,   332,   245,   303,     6,
     303,   250,     6,     6,     7,   273,   274,   247,     7,     6,
     350,   246,   250,   332,   273,   245,   276,   358,   359,   360,
     358,   241,   332,   332,   345,   346,   245,   241,     4,     6,
     242,     6,   242,   246,   246,   242,   246,     6,     6,   353,
     241,     4,   242,   250,   241,   346,   354,     7,   275,   284,
     332,   348,   288,     6,     6,     6,     6,   343,     6,     6,
       6,     6,    91,   110,    95,     6,     5,   245,   332,   332,
     332,   332,   242,   335,   332,   332,   332,   276,   274,   245,
     245,     6,   293,     6,   332,   346,     4,     6,   349,   349,
     332,   332,   354,   246,   242,   246,   250,   302,   302,   332,
     332,   246,   250,   242,   246,   250,     6,     6,   345,   343,
     343,   343,   343,   343,   230,   343,     6,   246,   332,     6,
       6,   346,   246,   250,     8,   246,   242,   245,   332,   354,
     353,   332,   353,   332,   354,   357,   359,   354,   250,   242,
     250,   246,   332,   320,   320,   346,   354,   332,     6,     4,
     351,     6,   350,   244,   346,   360,     6,   276,   276,   259,
     332,   250,   250,   246,   250,   260,   332,   332,     6,     6,
       6,     6,   332,   332,   242,   280,   282,   245,   359,   246,
     250,     7,     7,   245,   245,   245,     5,   345,   276,   276,
     250,   276,   242,   250,   242,   244,   349,   349,     6,     6,
     245,   246,   246,   245,     6,     6,   245,   332,   246,   246,
     246,   244,     6,   346,     7,   245,   332,   246,   250,   250,
     250,   250,   250,   250,     6,   246,   174,   332,   332,   349,
       6,     6,   242,   276,   276,   291,   354,   246,   246,   246,
     246,     6,     6,     7,     6,   247,     6,   246,     6,     6,
     242,   250,   332,   332,   245,   346,   246,   250,   242,   242,
     250,   285,   289,   346,   276,   332,   354,   363,   349,   349,
     332,     6,   246,   332,   335,   332,   246,   246,   345,   135,
     136,   141,   327,   135,   136,   327,   349,   302,   246,   250,
       6,   246,   346,   303,   246,     6,   349,   343,   343,   343,
     343,   343,   332,   246,   246,   246,   242,     6,   245,     6,
     350,   177,   263,   332,   250,   250,   345,     6,   332,   332,
     246,   246,   281,     7,   241,   246,   246,   246,   245,   250,
     242,   250,   245,   246,   245,   343,   346,     6,   245,   343,
       6,   246,   246,   332,     6,   131,   246,   314,   245,   246,
     250,   250,   250,   250,   250,     6,     6,     6,   303,     6,
     245,   332,   332,   246,   250,   285,   354,   242,   332,   332,
     332,   349,     6,   343,     6,   343,     6,     6,   246,   332,
     317,   303,     6,   349,   349,   349,   349,   343,   349,   320,
     260,   242,   250,     6,   245,   332,   246,   250,   250,   250,
     246,   250,   250,     6,   246,   246,   315,   246,   246,   246,
     246,   250,   246,   246,   246,   266,   332,   345,   246,   332,
     332,   332,   343,   343,   317,     6,     6,     6,     6,   349,
       6,     6,     6,   245,   242,   246,     6,   246,   276,   250,
     250,   250,   246,   246,   264,   353,   269,   245,     6,   332,
     332,   332,     6,   246,   250,   245,   345,   246,   246,   246,
       6,   353,   267,   353,   246,     6,     6,   246,   250,     6,
       6,   353
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
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 271:
#line 3424 "Gmsh.y"
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

  case 272:
#line 3487 "Gmsh.y"
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

  case 273:
#line 3503 "Gmsh.y"
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

  case 274:
#line 3520 "Gmsh.y"
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

  case 275:
#line 3537 "Gmsh.y"
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

  case 276:
#line 3559 "Gmsh.y"
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

  case 277:
#line 3581 "Gmsh.y"
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

  case 278:
#line 3616 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3624 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 3632 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 281:
#line 3638 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3645 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 3652 "Gmsh.y"
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

  case 284:
#line 3672 "Gmsh.y"
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

  case 285:
#line 3698 "Gmsh.y"
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

  case 286:
#line 3710 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 287:
#line 3721 "Gmsh.y"
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

  case 288:
#line 3739 "Gmsh.y"
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

  case 289:
#line 3757 "Gmsh.y"
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

  case 290:
#line 3775 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 291:
#line 3781 "Gmsh.y"
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

  case 292:
#line 3799 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 3805 "Gmsh.y"
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

  case 294:
#line 3825 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 3831 "Gmsh.y"
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

  case 296:
#line 3849 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 3855 "Gmsh.y"
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

  case 298:
#line 3872 "Gmsh.y"
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

  case 299:
#line 3888 "Gmsh.y"
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

  case 300:
#line 3905 "Gmsh.y"
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

  case 301:
#line 3923 "Gmsh.y"
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

  case 302:
#line 3946 "Gmsh.y"
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

  case 303:
#line 3973 "Gmsh.y"
    {
    ;}
    break;

  case 304:
#line 3976 "Gmsh.y"
    {
    ;}
    break;

  case 305:
#line 3982 "Gmsh.y"
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

  case 306:
#line 3994 "Gmsh.y"
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

  case 307:
#line 4014 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 308:
#line 4018 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 309:
#line 4022 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 310:
#line 4026 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 311:
#line 4030 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 312:
#line 4034 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 313:
#line 4038 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 314:
#line 4042 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 315:
#line 4051 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 316:
#line 4063 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 317:
#line 4064 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 318:
#line 4065 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 319:
#line 4066 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 320:
#line 4067 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 321:
#line 4071 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 322:
#line 4072 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 323:
#line 4073 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 324:
#line 4074 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 325:
#line 4075 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 326:
#line 4080 "Gmsh.y"
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

  case 327:
#line 4103 "Gmsh.y"
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

  case 328:
#line 4123 "Gmsh.y"
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

  case 329:
#line 4144 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 330:
#line 4148 "Gmsh.y"
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

  case 331:
#line 4163 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 332:
#line 4167 "Gmsh.y"
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

  case 333:
#line 4183 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 334:
#line 4187 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 335:
#line 4192 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 336:
#line 4196 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 337:
#line 4202 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 338:
#line 4206 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 339:
#line 4213 "Gmsh.y"
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

  case 340:
#line 4235 "Gmsh.y"
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

  case 341:
#line 4276 "Gmsh.y"
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

  case 342:
#line 4320 "Gmsh.y"
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

  case 343:
#line 4359 "Gmsh.y"
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

  case 344:
#line 4384 "Gmsh.y"
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

  case 345:
#line 4396 "Gmsh.y"
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

  case 346:
#line 4408 "Gmsh.y"
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

  case 347:
#line 4420 "Gmsh.y"
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

  case 348:
#line 4432 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 349:
#line 4441 "Gmsh.y"
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

  case 350:
#line 4471 "Gmsh.y"
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

  case 351:
#line 4497 "Gmsh.y"
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

  case 352:
#line 4524 "Gmsh.y"
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

  case 353:
#line 4556 "Gmsh.y"
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

  case 354:
#line 4583 "Gmsh.y"
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

  case 355:
#line 4609 "Gmsh.y"
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

  case 356:
#line 4635 "Gmsh.y"
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

  case 357:
#line 4661 "Gmsh.y"
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

  case 358:
#line 4687 "Gmsh.y"
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

  case 359:
#line 4708 "Gmsh.y"
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

  case 360:
#line 4719 "Gmsh.y"
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

  case 361:
#line 4767 "Gmsh.y"
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

  case 362:
#line 4821 "Gmsh.y"
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

  case 363:
#line 4836 "Gmsh.y"
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

  case 364:
#line 4848 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 365:
#line 4859 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 366:
#line 4866 "Gmsh.y"
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

  case 367:
#line 4881 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 368:
#line 4894 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 369:
#line 4895 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 370:
#line 4896 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 371:
#line 4901 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 372:
#line 4907 "Gmsh.y"
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

  case 373:
#line 4919 "Gmsh.y"
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

  case 374:
#line 4937 "Gmsh.y"
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

  case 375:
#line 4964 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 376:
#line 4965 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 377:
#line 4966 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 378:
#line 4967 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 379:
#line 4968 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 380:
#line 4969 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4970 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4971 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 4973 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 384:
#line 4979 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 385:
#line 4980 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 386:
#line 4981 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 387:
#line 4982 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 388:
#line 4983 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 389:
#line 4984 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 390:
#line 4985 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 391:
#line 4986 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 4987 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 4988 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 4989 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 395:
#line 4990 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 396:
#line 4991 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 397:
#line 4992 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 398:
#line 4993 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 399:
#line 4994 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4995 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 401:
#line 4996 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 402:
#line 4997 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4998 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 404:
#line 4999 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 5000 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 406:
#line 5001 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 5002 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 408:
#line 5003 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 5004 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 410:
#line 5005 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 5006 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 5007 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 413:
#line 5008 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 414:
#line 5009 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 415:
#line 5010 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 416:
#line 5011 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 417:
#line 5012 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 418:
#line 5013 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 419:
#line 5014 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 420:
#line 5015 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 421:
#line 5016 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 422:
#line 5025 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 423:
#line 5026 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 424:
#line 5027 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 425:
#line 5028 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 426:
#line 5029 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 427:
#line 5030 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 428:
#line 5031 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 429:
#line 5032 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 430:
#line 5033 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 431:
#line 5034 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 432:
#line 5035 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 433:
#line 5040 "Gmsh.y"
    { init_options(); ;}
    break;

  case 434:
#line 5042 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 435:
#line 5048 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 436:
#line 5050 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 437:
#line 5055 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 438:
#line 5060 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 439:
#line 5065 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 440:
#line 5070 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 441:
#line 5074 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 442:
#line 5078 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 443:
#line 5082 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 444:
#line 5086 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 445:
#line 5090 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 446:
#line 5094 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 447:
#line 5098 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 448:
#line 5104 "Gmsh.y"
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

  case 449:
#line 5120 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 450:
#line 5125 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 451:
#line 5131 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 452:
#line 5137 "Gmsh.y"
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

  case 453:
#line 5156 "Gmsh.y"
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

  case 454:
#line 5177 "Gmsh.y"
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
#line 5210 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 456:
#line 5214 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 457:
#line 5219 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 458:
#line 5223 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 459:
#line 5227 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 460:
#line 5231 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 461:
#line 5236 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 462:
#line 5241 "Gmsh.y"
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

  case 463:
#line 5251 "Gmsh.y"
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

  case 464:
#line 5261 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 465:
#line 5266 "Gmsh.y"
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

  case 466:
#line 5277 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 467:
#line 5286 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 468:
#line 5291 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 469:
#line 5296 "Gmsh.y"
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

  case 470:
#line 5323 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 471:
#line 5325 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 472:
#line 5330 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 473:
#line 5332 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 474:
#line 5337 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 475:
#line 5344 "Gmsh.y"
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

  case 476:
#line 5360 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 477:
#line 5362 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 478:
#line 5367 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 479:
#line 5376 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 480:
#line 5378 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 481:
#line 5383 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 482:
#line 5385 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 483:
#line 5390 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 484:
#line 5394 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 485:
#line 5398 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 486:
#line 5402 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 487:
#line 5406 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 488:
#line 5413 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 489:
#line 5417 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 490:
#line 5421 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 491:
#line 5425 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 492:
#line 5432 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 493:
#line 5437 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 494:
#line 5444 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 495:
#line 5449 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 496:
#line 5453 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 497:
#line 5458 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 498:
#line 5462 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 499:
#line 5470 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 500:
#line 5481 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 501:
#line 5485 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 502:
#line 5489 "Gmsh.y"
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

  case 503:
#line 5503 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 504:
#line 5511 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 505:
#line 5519 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 506:
#line 5526 "Gmsh.y"
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

  case 507:
#line 5536 "Gmsh.y"
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

  case 508:
#line 5559 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 509:
#line 5564 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 510:
#line 5570 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 511:
#line 5575 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 512:
#line 5581 "Gmsh.y"
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

  case 513:
#line 5592 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 514:
#line 5599 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 515:
#line 5604 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 516:
#line 5609 "Gmsh.y"
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

  case 517:
#line 5619 "Gmsh.y"
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
#line 5629 "Gmsh.y"
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
#line 5639 "Gmsh.y"
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

  case 520:
#line 5651 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 521:
#line 5655 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 522:
#line 5660 "Gmsh.y"
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

  case 523:
#line 5672 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
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
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 526:
#line 5684 "Gmsh.y"
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

  case 527:
#line 5702 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 528:
#line 5710 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 529:
#line 5718 "Gmsh.y"
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

  case 530:
#line 5747 "Gmsh.y"
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

  case 531:
#line 5757 "Gmsh.y"
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

  case 532:
#line 5773 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 533:
#line 5784 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 534:
#line 5789 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 535:
#line 5793 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 536:
#line 5797 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 537:
#line 5809 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 538:
#line 5813 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 539:
#line 5825 "Gmsh.y"
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

  case 540:
#line 5842 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 541:
#line 5852 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 542:
#line 5856 "Gmsh.y"
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

  case 543:
#line 5871 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 544:
#line 5876 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 545:
#line 5883 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 546:
#line 5887 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 547:
#line 5892 "Gmsh.y"
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

  case 548:
#line 5906 "Gmsh.y"
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
#line 5922 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 550:
#line 5926 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 551:
#line 5930 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 552:
#line 5934 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 553:
#line 5938 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 554:
#line 5946 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 555:
#line 5952 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 556:
#line 5958 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 557:
#line 5964 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 558:
#line 5973 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 559:
#line 5977 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 560:
#line 5981 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 561:
#line 5989 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 562:
#line 5995 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 563:
#line 6001 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 564:
#line 6005 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 565:
#line 6013 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 566:
#line 6021 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 567:
#line 6028 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 568:
#line 6037 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 569:
#line 6041 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 570:
#line 6045 "Gmsh.y"
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

  case 571:
#line 6060 "Gmsh.y"
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

  case 572:
#line 6074 "Gmsh.y"
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

  case 573:
#line 6088 "Gmsh.y"
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

  case 574:
#line 6100 "Gmsh.y"
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

  case 575:
#line 6116 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 576:
#line 6125 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 577:
#line 6134 "Gmsh.y"
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

  case 578:
#line 6144 "Gmsh.y"
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

  case 579:
#line 6155 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 580:
#line 6163 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 581:
#line 6171 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 582:
#line 6175 "Gmsh.y"
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

  case 583:
#line 6194 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 584:
#line 6201 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 585:
#line 6207 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6214 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 6221 "Gmsh.y"
    { init_options(); ;}
    break;

  case 588:
#line 6223 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 589:
#line 6231 "Gmsh.y"
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

  case 590:
#line 6255 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 591:
#line 6257 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 592:
#line 6263 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 593:
#line 6268 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 594:
#line 6270 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 595:
#line 6275 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 596:
#line 6280 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 597:
#line 6285 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 598:
#line 6287 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 599:
#line 6291 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 600:
#line 6303 "Gmsh.y"
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

  case 601:
#line 6317 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 602:
#line 6321 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 603:
#line 6328 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 604:
#line 6336 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 605:
#line 6344 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 606:
#line 6355 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 607:
#line 6357 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 608:
#line 6360 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14051 "Gmsh.tab.cpp"
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


#line 6363 "Gmsh.y"


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

