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
     tPlane = 378,
     tRuled = 379,
     tTransfinite = 380,
     tPhysical = 381,
     tCompound = 382,
     tPeriodic = 383,
     tParent = 384,
     tUsing = 385,
     tPlugin = 386,
     tDegenerated = 387,
     tRecursive = 388,
     tRotate = 389,
     tTranslate = 390,
     tSymmetry = 391,
     tDilate = 392,
     tExtrude = 393,
     tLevelset = 394,
     tAffine = 395,
     tBooleanUnion = 396,
     tBooleanIntersection = 397,
     tBooleanDifference = 398,
     tBooleanSection = 399,
     tBooleanFragments = 400,
     tThickSolid = 401,
     tRecombine = 402,
     tSmoother = 403,
     tSplit = 404,
     tDelete = 405,
     tCoherence = 406,
     tIntersect = 407,
     tMeshAlgorithm = 408,
     tReverseMesh = 409,
     tLayers = 410,
     tScaleLast = 411,
     tHole = 412,
     tAlias = 413,
     tAliasWithOptions = 414,
     tCopyOptions = 415,
     tQuadTriAddVerts = 416,
     tQuadTriNoNewVerts = 417,
     tRecombLaterals = 418,
     tTransfQuadTri = 419,
     tText2D = 420,
     tText3D = 421,
     tInterpolationScheme = 422,
     tTime = 423,
     tCombine = 424,
     tBSpline = 425,
     tBezier = 426,
     tNurbs = 427,
     tNurbsOrder = 428,
     tNurbsKnots = 429,
     tColor = 430,
     tColorTable = 431,
     tFor = 432,
     tIn = 433,
     tEndFor = 434,
     tIf = 435,
     tElseIf = 436,
     tElse = 437,
     tEndIf = 438,
     tExit = 439,
     tAbort = 440,
     tField = 441,
     tReturn = 442,
     tCall = 443,
     tSlide = 444,
     tMacro = 445,
     tShow = 446,
     tHide = 447,
     tGetValue = 448,
     tGetStringValue = 449,
     tGetEnv = 450,
     tGetString = 451,
     tGetNumber = 452,
     tUnique = 453,
     tHomology = 454,
     tCohomology = 455,
     tBetti = 456,
     tExists = 457,
     tFileExists = 458,
     tGetForced = 459,
     tGetForcedStr = 460,
     tGMSH_MAJOR_VERSION = 461,
     tGMSH_MINOR_VERSION = 462,
     tGMSH_PATCH_VERSION = 463,
     tGmshExecutableName = 464,
     tSetPartition = 465,
     tNameToString = 466,
     tStringToName = 467,
     tAFFECTDIVIDE = 468,
     tAFFECTTIMES = 469,
     tAFFECTMINUS = 470,
     tAFFECTPLUS = 471,
     tOR = 472,
     tAND = 473,
     tNOTEQUAL = 474,
     tEQUAL = 475,
     tGREATERGREATER = 476,
     tLESSLESS = 477,
     tGREATEROREQUAL = 478,
     tLESSOREQUAL = 479,
     UNARYPREC = 480,
     tMINUSMINUS = 481,
     tPLUSPLUS = 482
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
#define tPlane 378
#define tRuled 379
#define tTransfinite 380
#define tPhysical 381
#define tCompound 382
#define tPeriodic 383
#define tParent 384
#define tUsing 385
#define tPlugin 386
#define tDegenerated 387
#define tRecursive 388
#define tRotate 389
#define tTranslate 390
#define tSymmetry 391
#define tDilate 392
#define tExtrude 393
#define tLevelset 394
#define tAffine 395
#define tBooleanUnion 396
#define tBooleanIntersection 397
#define tBooleanDifference 398
#define tBooleanSection 399
#define tBooleanFragments 400
#define tThickSolid 401
#define tRecombine 402
#define tSmoother 403
#define tSplit 404
#define tDelete 405
#define tCoherence 406
#define tIntersect 407
#define tMeshAlgorithm 408
#define tReverseMesh 409
#define tLayers 410
#define tScaleLast 411
#define tHole 412
#define tAlias 413
#define tAliasWithOptions 414
#define tCopyOptions 415
#define tQuadTriAddVerts 416
#define tQuadTriNoNewVerts 417
#define tRecombLaterals 418
#define tTransfQuadTri 419
#define tText2D 420
#define tText3D 421
#define tInterpolationScheme 422
#define tTime 423
#define tCombine 424
#define tBSpline 425
#define tBezier 426
#define tNurbs 427
#define tNurbsOrder 428
#define tNurbsKnots 429
#define tColor 430
#define tColorTable 431
#define tFor 432
#define tIn 433
#define tEndFor 434
#define tIf 435
#define tElseIf 436
#define tElse 437
#define tEndIf 438
#define tExit 439
#define tAbort 440
#define tField 441
#define tReturn 442
#define tCall 443
#define tSlide 444
#define tMacro 445
#define tShow 446
#define tHide 447
#define tGetValue 448
#define tGetStringValue 449
#define tGetEnv 450
#define tGetString 451
#define tGetNumber 452
#define tUnique 453
#define tHomology 454
#define tCohomology 455
#define tBetti 456
#define tExists 457
#define tFileExists 458
#define tGetForced 459
#define tGetForcedStr 460
#define tGMSH_MAJOR_VERSION 461
#define tGMSH_MINOR_VERSION 462
#define tGMSH_PATCH_VERSION 463
#define tGmshExecutableName 464
#define tSetPartition 465
#define tNameToString 466
#define tStringToName 467
#define tAFFECTDIVIDE 468
#define tAFFECTTIMES 469
#define tAFFECTMINUS 470
#define tAFFECTPLUS 471
#define tOR 472
#define tAND 473
#define tNOTEQUAL 474
#define tEQUAL 475
#define tGREATERGREATER 476
#define tLESSLESS 477
#define tGREATEROREQUAL 478
#define tLESSOREQUAL 479
#define UNARYPREC 480
#define tMINUSMINUS 481
#define tPLUSPLUS 482




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
#line 734 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 747 "Gmsh.tab.cpp"

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
#define YYLAST   16141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  250
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  607
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2159

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   482

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   235,     2,   247,     2,   232,   234,     2,
     240,   241,   230,   228,   249,   229,   246,   231,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     222,     2,   223,   217,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   242,     2,   243,   239,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   244,   233,   245,   248,     2,     2,     2,
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
     215,   216,   218,   219,   220,   221,   224,   225,   226,   227,
     236,   237,   238
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
    1698,  1702,  1713,  1715,  1718,  1724,  1732,  1735,  1738,  1742,
    1745,  1749,  1752,  1756,  1766,  1773,  1775,  1777,  1779,  1781,
    1783,  1784,  1787,  1791,  1795,  1800,  1810,  1815,  1830,  1831,
    1835,  1836,  1838,  1839,  1842,  1843,  1846,  1847,  1850,  1857,
    1865,  1872,  1878,  1882,  1891,  1900,  1909,  1918,  1927,  1933,
    1938,  1945,  1957,  1969,  1988,  2007,  2020,  2033,  2046,  2057,
    2062,  2067,  2072,  2077,  2082,  2085,  2089,  2096,  2098,  2100,
    2102,  2105,  2111,  2119,  2130,  2132,  2136,  2139,  2142,  2145,
    2149,  2153,  2157,  2161,  2165,  2169,  2173,  2177,  2181,  2185,
    2189,  2193,  2197,  2201,  2205,  2209,  2213,  2217,  2223,  2228,
    2233,  2238,  2243,  2248,  2253,  2258,  2263,  2268,  2273,  2280,
    2285,  2290,  2295,  2300,  2305,  2310,  2315,  2320,  2327,  2334,
    2341,  2346,  2348,  2350,  2352,  2354,  2356,  2358,  2360,  2362,
    2364,  2366,  2368,  2369,  2376,  2378,  2383,  2390,  2392,  2397,
    2402,  2407,  2414,  2420,  2428,  2437,  2448,  2453,  2458,  2465,
    2470,  2474,  2477,  2483,  2489,  2493,  2499,  2506,  2515,  2522,
    2531,  2538,  2543,  2551,  2558,  2565,  2572,  2577,  2584,  2589,
    2590,  2593,  2594,  2597,  2598,  2606,  2608,  2612,  2614,  2616,
    2619,  2620,  2624,  2626,  2629,  2632,  2636,  2640,  2652,  2662,
    2670,  2678,  2680,  2684,  2686,  2688,  2691,  2695,  2700,  2706,
    2708,  2712,  2714,  2717,  2721,  2725,  2731,  2736,  2741,  2744,
    2749,  2752,  2756,  2760,  2777,  2783,  2785,  2787,  2789,  2793,
    2799,  2807,  2812,  2817,  2822,  2829,  2836,  2845,  2854,  2859,
    2874,  2879,  2884,  2886,  2888,  2892,  2896,  2906,  2914,  2916,
    2922,  2926,  2933,  2935,  2939,  2941,  2943,  2948,  2953,  2957,
    2963,  2970,  2979,  2986,  2992,  2998,  3004,  3010,  3012,  3017,
    3019,  3021,  3023,  3025,  3030,  3037,  3042,  3049,  3055,  3063,
    3068,  3073,  3078,  3087,  3092,  3097,  3102,  3107,  3116,  3125,
    3132,  3137,  3144,  3149,  3151,  3156,  3161,  3162,  3169,  3174,
    3177,  3182,  3187,  3189,  3191,  3195,  3197,  3199,  3203,  3207,
    3211,  3217,  3225,  3231,  3237,  3246,  3248,  3250
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     251,     0,    -1,   252,    -1,     1,     6,    -1,    -1,   252,
     253,    -1,   255,    -1,   256,    -1,   276,    -1,   119,   240,
     352,   241,     6,    -1,   294,    -1,   300,    -1,   304,    -1,
     305,    -1,   306,    -1,   307,    -1,   311,    -1,   320,    -1,
     321,    -1,   327,    -1,   328,    -1,   310,    -1,   309,    -1,
     308,    -1,   303,    -1,   330,    -1,   223,    -1,   224,    -1,
      44,   240,   352,   241,     6,    -1,    45,   240,   352,   241,
       6,    -1,    44,   240,   352,   241,   254,   352,     6,    -1,
      44,   240,   352,   249,   348,   241,     6,    -1,    45,   240,
     352,   249,   348,   241,     6,    -1,    44,   240,   352,   249,
     348,   241,   254,   352,     6,    -1,   362,   352,   244,   257,
     245,     6,    -1,   158,     4,   242,   331,   243,     6,    -1,
     159,     4,   242,   331,   243,     6,    -1,   160,     4,   242,
     331,   249,   331,   243,     6,    -1,    -1,   257,   260,    -1,
     257,   264,    -1,   257,   267,    -1,   257,   269,    -1,   257,
     270,    -1,   331,    -1,   258,   249,   331,    -1,   331,    -1,
     259,   249,   331,    -1,    -1,    -1,     4,   261,   240,   258,
     241,   262,   244,   259,   245,     6,    -1,   352,    -1,   263,
     249,   352,    -1,    -1,   165,   240,   331,   249,   331,   249,
     331,   241,   265,   244,   263,   245,     6,    -1,   352,    -1,
     266,   249,   352,    -1,    -1,   166,   240,   331,   249,   331,
     249,   331,   249,   331,   241,   268,   244,   266,   245,     6,
      -1,   167,   244,   344,   245,   244,   344,   245,     6,    -1,
     167,   244,   344,   245,   244,   344,   245,   244,   344,   245,
     244,   344,   245,     6,    -1,    -1,   168,   271,   244,   259,
     245,     6,    -1,     7,    -1,   216,    -1,   215,    -1,   214,
      -1,   213,    -1,   238,    -1,   237,    -1,   240,    -1,   242,
      -1,   241,    -1,   243,    -1,    80,   242,   278,   243,     6,
      -1,    81,   242,   282,   243,     6,    -1,   336,     6,    -1,
      88,   274,   353,   249,   331,   275,     6,    -1,    90,   274,
     362,   249,   353,   275,     6,    -1,   362,   272,   345,     6,
      -1,   362,   273,     6,    -1,   362,   274,   275,   272,   345,
       6,    -1,   362,   274,   244,   348,   245,   275,   272,   345,
       6,    -1,   362,   242,   331,   243,   272,   331,     6,    -1,
     362,   242,   331,   243,   273,     6,    -1,   362,   240,   331,
     241,   272,   331,     6,    -1,   362,   240,   331,   241,   273,
       6,    -1,   362,     7,   353,     6,    -1,   362,   274,   275,
       7,    46,   274,   275,     6,    -1,   362,   274,   275,     7,
      46,   274,   357,   275,     6,    -1,   362,   274,   275,   216,
      46,   274,   357,   275,     6,    -1,   362,   246,     4,     7,
     353,     6,    -1,   362,   242,   331,   243,   246,     4,     7,
     353,     6,    -1,   362,   246,     4,   272,   331,     6,    -1,
     362,   242,   331,   243,   246,     4,   272,   331,     6,    -1,
     362,   246,     4,   273,     6,    -1,   362,   242,   331,   243,
     246,     4,   273,     6,    -1,   362,   246,   175,   246,     4,
       7,   349,     6,    -1,   362,   242,   331,   243,   246,   175,
     246,     4,     7,   349,     6,    -1,   362,   246,   176,     7,
     350,     6,    -1,   362,   242,   331,   243,   246,   176,     7,
     350,     6,    -1,   362,   186,     7,   345,     6,    -1,   186,
     242,   331,   243,     7,     4,     6,    -1,   186,   242,   331,
     243,     7,   100,     6,    -1,   186,   242,   331,   243,     7,
     101,     6,    -1,   186,   242,   331,   243,   246,     4,     7,
     331,     6,    -1,   186,   242,   331,   243,   246,     4,     7,
     353,     6,    -1,   186,   242,   331,   243,   246,     4,     7,
     244,   348,   245,     6,    -1,   186,   242,   331,   243,   246,
       4,     6,    -1,   131,   240,     4,   241,   246,     4,     7,
     331,     6,    -1,   131,   240,     4,   241,   246,     4,     7,
     353,     6,    -1,    -1,   249,    -1,    -1,   278,   277,   362,
      -1,   278,   277,   362,     7,   331,    -1,    -1,   278,   277,
     362,     7,   244,   345,   279,   284,   245,    -1,    -1,   278,
     277,   362,   274,   275,     7,   244,   345,   280,   284,   245,
      -1,   278,   277,   362,     7,   353,    -1,    -1,   278,   277,
     362,     7,   244,   353,   281,   288,   245,    -1,    -1,   282,
     277,   352,    -1,   331,     7,   353,    -1,   283,   249,   331,
       7,   353,    -1,   347,     7,   362,   240,   241,    -1,    -1,
     249,   286,    -1,    -1,   286,    -1,   287,    -1,   286,   249,
     287,    -1,     4,   345,    -1,     4,    -1,     4,   244,   283,
     245,    -1,     4,   353,    -1,     4,   356,    -1,    -1,   249,
     289,    -1,   290,    -1,   289,   249,   290,    -1,     4,   331,
      -1,     4,   353,    -1,   190,   353,    -1,     4,   358,    -1,
       4,   356,    -1,   331,    -1,   353,    -1,   353,   249,   331,
      -1,    -1,   178,    95,   244,   331,   245,    -1,   130,    91,
     244,   348,   245,    -1,   130,   110,   244,   348,   245,    -1,
      -1,   123,   342,    -1,    91,   240,   331,   241,     7,   342,
       6,    -1,    94,   240,   331,   241,     7,   345,     6,    -1,
      98,   240,   331,   241,     7,   345,     6,    -1,    92,   240,
     331,   241,     7,   345,   293,     6,    -1,    93,   240,   331,
     241,     7,   345,   293,     6,    -1,   170,   240,   331,   241,
       7,   345,     6,    -1,   171,   240,   331,   241,     7,   345,
       6,    -1,   172,   240,   331,   241,     7,   345,   174,   345,
     173,   331,     6,    -1,   109,   240,   331,   241,     7,   345,
       6,    -1,    94,     4,   240,   331,   241,     7,   345,     6,
      -1,   123,    97,   240,   331,   241,     7,   345,     6,    -1,
      97,   240,   331,   241,     7,   345,   292,     6,    -1,   124,
      97,   240,   331,   241,     7,   345,   292,     6,    -1,    13,
      14,     6,    -1,    14,    97,   331,     6,    -1,   113,    97,
     240,   331,   241,     7,     5,     5,     5,     6,    -1,    95,
     240,   331,   241,     7,   345,     6,    -1,    96,   240,   331,
     241,     7,   345,     6,    -1,   100,   240,   331,   241,     7,
     345,     6,    -1,   103,   240,   331,   241,     7,   345,     6,
      -1,   107,   240,   331,   241,     7,   345,     6,    -1,   108,
     240,   331,   241,     7,   345,     6,    -1,   101,   240,   331,
     241,     7,   345,     6,    -1,   102,   240,   331,   241,     7,
     345,     6,    -1,   121,   240,   331,   241,     7,   345,     6,
      -1,   146,   240,   331,   241,     7,   345,     6,    -1,    97,
       4,   240,   331,   241,     7,   345,     6,    -1,    99,   240,
     331,   241,     7,   345,     6,    -1,   120,   240,   331,   241,
       7,   345,     6,    -1,   124,   120,   240,   331,   241,     7,
     345,     6,    -1,   127,   297,   240,   331,   241,     7,   345,
       6,    -1,   127,   297,   240,   331,   241,     7,   345,     4,
     244,   344,   245,     6,    -1,    -1,   126,   296,   295,   240,
     291,   241,   272,   345,     6,    -1,    91,    -1,    94,    -1,
      97,    -1,    99,    -1,   110,   244,   331,   245,    -1,    94,
      -1,    97,    -1,    99,    -1,   110,   244,   331,   245,    -1,
      94,    -1,    97,    -1,   110,   244,   331,   245,    -1,    91,
      -1,    94,    -1,    97,    -1,   110,   244,   331,   245,    -1,
     135,   342,   244,   301,   245,    -1,   134,   244,   342,   249,
     342,   249,   331,   245,   244,   301,   245,    -1,   136,   342,
     244,   301,   245,    -1,   137,   244,   342,   249,   331,   245,
     244,   301,   245,    -1,   137,   244,   342,   249,   342,   245,
     244,   301,   245,    -1,     4,   244,   301,   245,    -1,   152,
      94,   244,   348,   245,    97,   244,   331,   245,    -1,   149,
      94,   240,   331,   241,   244,   348,   245,     6,    -1,   302,
      -1,   300,    -1,    -1,   302,   294,    -1,   302,   296,   244,
     348,   245,     6,    -1,   302,   126,   296,   244,   348,   245,
       6,    -1,   302,   129,   296,   244,   348,   245,     6,    -1,
     302,   296,   244,     8,   245,     6,    -1,   302,   126,   296,
     244,     8,   245,     6,    -1,   139,   123,   240,   331,   241,
       7,   345,     6,    -1,   139,    91,   240,   331,   241,     7,
     244,   344,   245,     6,    -1,   139,   123,   240,   331,   241,
       7,   244,   342,   249,   342,   249,   348,   245,     6,    -1,
     139,   123,   240,   331,   241,     7,   244,   342,   249,   342,
     249,   342,   249,   348,   245,     6,    -1,   139,    95,   240,
     331,   241,     7,   244,   342,   249,   348,   245,     6,    -1,
     139,   101,   240,   331,   241,     7,   244,   342,   249,   342,
     249,   348,   245,     6,    -1,   139,   102,   240,   331,   241,
       7,   244,   342,   249,   342,   249,   348,   245,     6,    -1,
     139,   104,   240,   331,   241,     7,   244,   342,   249,   342,
     249,   348,   245,     6,    -1,   139,   105,   240,   331,   241,
       7,   244,   342,   249,   342,   249,   348,   245,     6,    -1,
     139,     4,   240,   331,   241,     7,   345,     6,    -1,   139,
       4,   240,   331,   241,     7,     5,     6,    -1,   139,     4,
     244,   331,   245,     6,    -1,   150,   244,   302,   245,    -1,
     133,   150,   244,   302,   245,    -1,   150,   186,   242,   331,
     243,     6,    -1,   150,     4,   242,   331,   243,     6,    -1,
     150,   362,     6,    -1,   150,     4,     4,     6,    -1,   150,
      83,     6,    -1,   175,   349,   244,   302,   245,    -1,   133,
     175,   349,   244,   302,   245,    -1,   210,   331,   244,   302,
     245,    -1,   191,   244,     8,   245,    -1,   191,     5,     6,
      -1,   192,   244,     8,   245,    -1,   192,     5,     6,    -1,
     191,   244,   302,   245,    -1,   133,   191,   244,   302,   245,
      -1,   192,   244,   302,   245,    -1,   133,   192,   244,   302,
     245,    -1,   362,   353,     6,    -1,    73,   240,   359,   241,
       6,    -1,   362,   362,   242,   331,   243,   352,     6,    -1,
     362,   362,   362,   242,   331,   243,     6,    -1,   362,   331,
       6,    -1,   131,   240,     4,   241,   246,     4,     6,    -1,
     169,     4,     6,    -1,   184,     6,    -1,   185,     6,    -1,
      70,     6,    -1,    71,     6,    -1,    64,     6,    -1,    64,
     244,   331,   249,   331,   249,   331,   249,   331,   249,   331,
     249,   331,   245,     6,    -1,    65,     6,    -1,    66,     6,
      -1,    78,     6,    -1,   115,     6,    -1,   116,   244,   348,
     245,   244,   348,   245,   244,   344,   245,   244,   331,   249,
     331,   245,     6,    -1,   189,   240,   244,   348,   245,   249,
     353,   249,   353,   241,     6,    -1,   177,   240,   331,     8,
     331,   241,    -1,   177,   240,   331,     8,   331,     8,   331,
     241,    -1,   177,     4,   178,   244,   331,     8,   331,   245,
      -1,   177,     4,   178,   244,   331,     8,   331,     8,   331,
     245,    -1,   179,    -1,   190,     4,    -1,   190,   353,    -1,
     187,    -1,   188,   362,     6,    -1,   188,   353,     6,    -1,
     180,   240,   331,   241,    -1,   181,   240,   331,   241,    -1,
     182,    -1,   183,    -1,   138,   342,   244,   302,   245,    -1,
     138,   244,   342,   249,   342,   249,   331,   245,   244,   302,
     245,    -1,   138,   244,   342,   249,   342,   249,   342,   249,
     331,   245,   244,   302,   245,    -1,    -1,   138,   342,   244,
     302,   312,   316,   245,    -1,    -1,   138,   244,   342,   249,
     342,   249,   331,   245,   244,   302,   313,   316,   245,    -1,
      -1,   138,   244,   342,   249,   342,   249,   342,   249,   331,
     245,   244,   302,   314,   316,   245,    -1,    -1,   138,   244,
     302,   315,   316,   245,    -1,   138,   244,   302,   245,   130,
     109,   244,   331,   245,    -1,   120,   345,    -1,   124,   120,
     345,    -1,   122,   244,   348,   245,   244,   348,   245,   244,
     331,   245,    -1,   317,    -1,   316,   317,    -1,   155,   244,
     331,   245,     6,    -1,   155,   244,   345,   249,   345,   245,
       6,    -1,   156,     6,    -1,   147,     6,    -1,   147,   331,
       6,    -1,   161,     6,    -1,   161,   163,     6,    -1,   162,
       6,    -1,   162,   163,     6,    -1,   157,   240,   331,   241,
       7,   345,   130,   331,     6,    -1,   130,     4,   242,   331,
     243,     6,    -1,   141,    -1,   142,    -1,   143,    -1,   144,
      -1,   145,    -1,    -1,   150,     6,    -1,   133,   150,     6,
      -1,   150,   331,     6,    -1,   133,   150,   331,     6,    -1,
     318,   244,   302,   319,   245,   244,   302,   319,   245,    -1,
     106,   240,   352,   241,    -1,   318,   240,   331,   241,     7,
     244,   302,   319,   245,   244,   302,   319,   245,     6,    -1,
      -1,   130,     4,   331,    -1,    -1,     4,    -1,    -1,     7,
     345,    -1,    -1,     7,   331,    -1,    -1,   140,   345,    -1,
     111,   112,   346,     7,   331,     6,    -1,   125,    94,   346,
       7,   331,   322,     6,    -1,   125,    97,   346,   324,   323,
       6,    -1,   125,    99,   346,   324,     6,    -1,   164,   346,
       6,    -1,    89,    91,   240,   331,   249,   331,   241,     6,
      -1,    89,    94,   240,   331,   249,   331,   241,     6,    -1,
      89,    97,   240,   331,   249,   331,   241,     6,    -1,    89,
      99,   240,   331,   249,   331,   241,     6,    -1,   153,    97,
     244,   348,   245,     7,   331,     6,    -1,   147,    97,   346,
     325,     6,    -1,   147,    99,   346,     6,    -1,   148,    97,
     346,     7,   331,     6,    -1,   128,    94,   244,   348,   245,
       7,   244,   348,   245,   326,     6,    -1,   128,    97,   244,
     348,   245,     7,   244,   348,   245,   326,     6,    -1,   128,
      94,   244,   348,   245,     7,   244,   348,   245,   134,   244,
     342,   249,   342,   249,   331,   245,     6,    -1,   128,    97,
     244,   348,   245,     7,   244,   348,   245,   134,   244,   342,
     249,   342,   249,   331,   245,     6,    -1,   128,    94,   244,
     348,   245,     7,   244,   348,   245,   135,   342,     6,    -1,
     128,    97,   244,   348,   245,     7,   244,   348,   245,   135,
     342,     6,    -1,   128,    97,   331,   244,   348,   245,     7,
     331,   244,   348,   245,     6,    -1,   296,   244,   348,   245,
     178,   296,   244,   331,   245,     6,    -1,   154,   298,   346,
       6,    -1,   117,   299,   346,     6,    -1,   118,    99,   345,
       6,    -1,   132,    94,   345,     6,    -1,   127,   297,   345,
       6,    -1,   151,     6,    -1,   151,     4,     6,    -1,   151,
      91,   244,   348,   245,     6,    -1,   199,    -1,   200,    -1,
     201,    -1,   329,     6,    -1,   329,   244,   345,   245,     6,
      -1,   329,   244,   345,   249,   345,   245,     6,    -1,   329,
     240,   345,   241,   244,   345,   249,   345,   245,     6,    -1,
     332,    -1,   240,   331,   241,    -1,   229,   331,    -1,   228,
     331,    -1,   235,   331,    -1,   331,   229,   331,    -1,   331,
     228,   331,    -1,   331,   230,   331,    -1,   331,   231,   331,
      -1,   331,   233,   331,    -1,   331,   234,   331,    -1,   331,
     232,   331,    -1,   331,   239,   331,    -1,   331,   222,   331,
      -1,   331,   223,   331,    -1,   331,   227,   331,    -1,   331,
     226,   331,    -1,   331,   221,   331,    -1,   331,   220,   331,
      -1,   331,   219,   331,    -1,   331,   218,   331,    -1,   331,
     224,   331,    -1,   331,   225,   331,    -1,   331,   217,   331,
       8,   331,    -1,    16,   274,   331,   275,    -1,    17,   274,
     331,   275,    -1,    18,   274,   331,   275,    -1,    19,   274,
     331,   275,    -1,    20,   274,   331,   275,    -1,    21,   274,
     331,   275,    -1,    22,   274,   331,   275,    -1,    23,   274,
     331,   275,    -1,    24,   274,   331,   275,    -1,    26,   274,
     331,   275,    -1,    27,   274,   331,   249,   331,   275,    -1,
      28,   274,   331,   275,    -1,    29,   274,   331,   275,    -1,
      30,   274,   331,   275,    -1,    31,   274,   331,   275,    -1,
      32,   274,   331,   275,    -1,    33,   274,   331,   275,    -1,
      34,   274,   331,   275,    -1,    35,   274,   331,   275,    -1,
      36,   274,   331,   249,   331,   275,    -1,    37,   274,   331,
     249,   331,   275,    -1,    38,   274,   331,   249,   331,   275,
      -1,    25,   274,   331,   275,    -1,     3,    -1,    10,    -1,
      15,    -1,    11,    -1,    12,    -1,   206,    -1,   207,    -1,
     208,    -1,    75,    -1,    76,    -1,    77,    -1,    -1,    82,
     274,   331,   333,   284,   275,    -1,   336,    -1,   197,   274,
     352,   275,    -1,   197,   274,   352,   249,   331,   275,    -1,
     338,    -1,   362,   242,   331,   243,    -1,   362,   240,   331,
     241,    -1,   202,   240,   338,   241,    -1,   202,   240,   338,
     246,   339,   241,    -1,   204,   240,   338,   334,   241,    -1,
     204,   240,   338,   246,   339,   334,   241,    -1,   204,   240,
     338,   274,   331,   275,   334,   241,    -1,   204,   240,   338,
     246,   339,   274,   331,   275,   334,   241,    -1,   203,   240,
     353,   241,    -1,   247,   362,   274,   275,    -1,   247,   338,
     246,   339,   274,   275,    -1,    85,   274,   362,   275,    -1,
      85,   274,   275,    -1,   362,   273,    -1,   362,   242,   331,
     243,   273,    -1,   362,   240,   331,   241,   273,    -1,   362,
     246,   339,    -1,   362,     9,   362,   246,   339,    -1,   362,
     246,   339,   240,   331,   241,    -1,   362,     9,   362,   246,
     339,   240,   331,   241,    -1,   362,   246,   339,   242,   331,
     243,    -1,   362,     9,   362,   246,   339,   242,   331,   243,
      -1,   362,   242,   331,   243,   246,     4,    -1,   362,   246,
       4,   273,    -1,   362,   242,   331,   243,   246,     4,   273,
      -1,   193,   240,   352,   249,   331,   241,    -1,    56,   240,
     345,   249,   345,   241,    -1,    57,   274,   352,   249,   352,
     275,    -1,    55,   274,   352,   275,    -1,    58,   274,   352,
     249,   352,   275,    -1,    63,   240,   359,   241,    -1,    -1,
     249,   331,    -1,    -1,   249,   352,    -1,    -1,    83,   338,
     341,   337,   242,   285,   243,    -1,   362,    -1,   362,     9,
     362,    -1,     4,    -1,    86,    -1,    86,   331,    -1,    -1,
     240,   340,   241,    -1,   343,    -1,   229,   342,    -1,   228,
     342,    -1,   342,   229,   342,    -1,   342,   228,   342,    -1,
     244,   331,   249,   331,   249,   331,   249,   331,   249,   331,
     245,    -1,   244,   331,   249,   331,   249,   331,   249,   331,
     245,    -1,   244,   331,   249,   331,   249,   331,   245,    -1,
     240,   331,   249,   331,   249,   331,   241,    -1,   345,    -1,
     344,   249,   345,    -1,   331,    -1,   347,    -1,   244,   245,
      -1,   244,   348,   245,    -1,   229,   244,   348,   245,    -1,
     331,   230,   244,   348,   245,    -1,   345,    -1,   244,     8,
     245,    -1,     5,    -1,   229,   347,    -1,   331,   230,   347,
      -1,   331,     8,   331,    -1,   331,     8,   331,     8,   331,
      -1,    91,   244,   331,   245,    -1,    91,   244,     8,   245,
      -1,    91,     5,    -1,   297,   244,     8,   245,    -1,   297,
       5,    -1,   126,   296,   346,    -1,   129,   296,   345,    -1,
     296,   178,    64,   244,   331,   249,   331,   249,   331,   249,
     331,   249,   331,   249,   331,   245,    -1,    64,   296,   244,
     331,   245,    -1,   300,    -1,   311,    -1,   320,    -1,   362,
     274,   275,    -1,   362,   246,   339,   274,   275,    -1,   362,
       9,   362,   246,   339,   274,   275,    -1,    39,   242,   362,
     243,    -1,    39,   242,   347,   243,    -1,    39,   240,   347,
     241,    -1,    39,   274,   244,   348,   245,   275,    -1,   362,
     274,   244,   348,   245,   275,    -1,    40,   274,   331,   249,
     331,   249,   331,   275,    -1,    41,   274,   331,   249,   331,
     249,   331,   275,    -1,    42,   274,   352,   275,    -1,    43,
     274,   331,   249,   331,   249,   331,   249,   331,   249,   331,
     249,   331,   275,    -1,   198,   274,   347,   275,    -1,    32,
     274,   347,   275,    -1,   331,    -1,   347,    -1,   348,   249,
     331,    -1,   348,   249,   347,    -1,   244,   331,   249,   331,
     249,   331,   249,   331,   245,    -1,   244,   331,   249,   331,
     249,   331,   245,    -1,   362,    -1,     4,   246,   175,   246,
       4,    -1,   244,   351,   245,    -1,   362,   242,   331,   243,
     246,   176,    -1,   349,    -1,   351,   249,   349,    -1,   353,
      -1,   362,    -1,   362,   242,   331,   243,    -1,   362,   240,
     331,   241,    -1,   362,   246,   339,    -1,   362,     9,   362,
     246,   339,    -1,   362,   246,   339,   240,   331,   241,    -1,
     362,     9,   362,   246,   339,   240,   331,   241,    -1,   362,
     242,   331,   243,   246,     4,    -1,   126,    91,   244,   331,
     245,    -1,   126,    94,   244,   331,   245,    -1,   126,    97,
     244,   331,   245,    -1,   126,    99,   244,   331,   245,    -1,
       5,    -1,   211,   242,   362,   243,    -1,    67,    -1,   209,
      -1,    72,    -1,    74,    -1,   195,   240,   352,   241,    -1,
     194,   240,   352,   249,   352,   241,    -1,   196,   274,   352,
     275,    -1,   196,   274,   352,   249,   352,   275,    -1,   205,
     240,   338,   335,   241,    -1,   205,   240,   338,   246,   339,
     335,   241,    -1,    48,   274,   359,   275,    -1,    49,   240,
     352,   241,    -1,    50,   240,   352,   241,    -1,    51,   240,
     352,   249,   352,   249,   352,   241,    -1,    46,   274,   359,
     275,    -1,    60,   274,   352,   275,    -1,    61,   274,   352,
     275,    -1,    62,   274,   352,   275,    -1,    59,   274,   331,
     249,   352,   249,   352,   275,    -1,    54,   274,   352,   249,
     331,   249,   331,   275,    -1,    54,   274,   352,   249,   331,
     275,    -1,    47,   274,   352,   275,    -1,    47,   274,   352,
     249,   348,   275,    -1,    68,   274,   352,   275,    -1,    69,
      -1,    53,   274,   352,   275,    -1,    52,   274,   352,   275,
      -1,    -1,    87,   274,   353,   354,   288,   275,    -1,    84,
     274,   355,   275,    -1,   247,   331,    -1,   362,     9,   247,
     331,    -1,    46,   274,   358,   275,    -1,   359,    -1,   358,
      -1,   244,   359,   245,    -1,   352,    -1,   360,    -1,   359,
     249,   352,    -1,   359,   249,   360,    -1,   362,   240,   241,
      -1,   362,   246,   339,   240,   241,    -1,   362,     9,   362,
     246,   339,   240,   241,    -1,     4,   248,   244,   331,   245,
      -1,   361,   248,   244,   331,   245,    -1,   212,   242,   352,
     243,   248,   244,   331,   245,    -1,     4,    -1,   361,    -1,
     212,   242,   352,   243,    -1
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
    1647,  1684,  1724,  1740,  1756,  1788,  1804,  1823,  1839,  1889,
    1907,  1913,  1919,  1926,  1957,  1972,  1994,  2017,  2040,  2063,
    2087,  2111,  2135,  2161,  2178,  2194,  2212,  2230,  2237,  2246,
    2245,  2275,  2277,  2279,  2281,  2283,  2291,  2293,  2295,  2297,
    2305,  2307,  2309,  2317,  2319,  2321,  2323,  2333,  2349,  2365,
    2381,  2397,  2413,  2450,  2472,  2496,  2497,  2502,  2505,  2509,
    2525,  2543,  2561,  2579,  2604,  2623,  2644,  2659,  2675,  2693,
    2744,  2765,  2787,  2810,  2915,  2931,  2966,  2988,  3010,  3016,
    3031,  3059,  3071,  3080,  3087,  3099,  3118,  3122,  3127,  3131,
    3136,  3143,  3150,  3157,  3169,  3242,  3260,  3277,  3292,  3325,
    3337,  3361,  3365,  3370,  3377,  3382,  3392,  3397,  3403,  3411,
    3415,  3424,  3488,  3504,  3521,  3538,  3560,  3582,  3617,  3625,
    3633,  3639,  3646,  3653,  3673,  3699,  3711,  3722,  3740,  3758,
    3777,  3776,  3801,  3800,  3827,  3826,  3851,  3850,  3873,  3889,
    3906,  3923,  3946,  3949,  3955,  3967,  3987,  3991,  3995,  3999,
    4003,  4007,  4011,  4015,  4024,  4037,  4038,  4039,  4040,  4041,
    4045,  4046,  4047,  4048,  4049,  4052,  4076,  4095,  4118,  4121,
    4137,  4140,  4157,  4160,  4166,  4169,  4176,  4179,  4186,  4208,
    4249,  4293,  4332,  4357,  4369,  4381,  4393,  4405,  4414,  4444,
    4470,  4496,  4528,  4555,  4581,  4607,  4633,  4659,  4681,  4692,
    4740,  4794,  4809,  4821,  4832,  4839,  4854,  4868,  4869,  4870,
    4874,  4880,  4892,  4910,  4938,  4939,  4940,  4941,  4942,  4943,
    4944,  4945,  4946,  4953,  4954,  4955,  4956,  4957,  4958,  4959,
    4960,  4961,  4962,  4963,  4964,  4965,  4966,  4967,  4968,  4969,
    4970,  4971,  4972,  4973,  4974,  4975,  4976,  4977,  4978,  4979,
    4980,  4981,  4982,  4983,  4984,  4985,  4986,  4987,  4988,  4989,
    4990,  4999,  5000,  5001,  5002,  5003,  5004,  5005,  5006,  5007,
    5008,  5009,  5014,  5013,  5021,  5023,  5028,  5033,  5037,  5042,
    5047,  5051,  5055,  5059,  5063,  5067,  5071,  5077,  5093,  5098,
    5104,  5110,  5129,  5150,  5183,  5187,  5192,  5196,  5200,  5204,
    5209,  5214,  5224,  5234,  5239,  5250,  5259,  5264,  5269,  5297,
    5298,  5304,  5305,  5311,  5310,  5333,  5335,  5340,  5349,  5351,
    5357,  5358,  5363,  5367,  5371,  5375,  5379,  5386,  5390,  5394,
    5398,  5405,  5410,  5417,  5422,  5426,  5431,  5435,  5443,  5454,
    5458,  5462,  5476,  5484,  5492,  5499,  5509,  5532,  5537,  5543,
    5548,  5554,  5565,  5571,  5577,  5582,  5592,  5602,  5612,  5624,
    5628,  5633,  5645,  5649,  5653,  5657,  5675,  5683,  5691,  5720,
    5730,  5746,  5757,  5762,  5766,  5770,  5782,  5786,  5798,  5815,
    5825,  5829,  5844,  5849,  5856,  5860,  5865,  5879,  5895,  5899,
    5903,  5907,  5911,  5919,  5925,  5931,  5937,  5946,  5950,  5954,
    5962,  5968,  5974,  5978,  5986,  5994,  6001,  6010,  6014,  6018,
    6033,  6047,  6061,  6073,  6089,  6098,  6107,  6117,  6128,  6136,
    6144,  6148,  6167,  6174,  6180,  6187,  6195,  6194,  6204,  6228,
    6230,  6236,  6241,  6243,  6248,  6253,  6258,  6260,  6264,  6276,
    6290,  6294,  6301,  6309,  6317,  6328,  6330,  6333
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
  "tThruSections", "tWedge", "tFillet", "tPlane", "tRuled", "tTransfinite",
  "tPhysical", "tCompound", "tPeriodic", "tParent", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
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
     465,   466,   467,   468,   469,   470,   471,    63,   472,   473,
     474,   475,    60,    62,   476,   477,   478,   479,    43,    45,
      42,    47,    37,   124,    38,    33,   480,   481,   482,    94,
      40,    41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   250,   251,   251,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   254,   254,   255,   255,
     255,   255,   255,   255,   256,   256,   256,   256,   257,   257,
     257,   257,   257,   257,   258,   258,   259,   259,   261,   262,
     260,   263,   263,   265,   264,   266,   266,   268,   267,   269,
     269,   271,   270,   272,   272,   272,   272,   272,   273,   273,
     274,   274,   275,   275,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   277,   277,   278,   278,   278,   279,   278,   280,   278,
     278,   281,   278,   282,   282,   283,   283,   283,   284,   284,
     285,   285,   286,   286,   287,   287,   287,   287,   287,   288,
     288,   289,   289,   290,   290,   290,   290,   290,   291,   291,
     291,   292,   292,   292,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   295,
     294,   296,   296,   296,   296,   296,   297,   297,   297,   297,
     298,   298,   298,   299,   299,   299,   299,   300,   300,   300,
     300,   300,   300,   300,   300,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   305,   305,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   309,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   311,   311,   311,
     312,   311,   313,   311,   314,   311,   315,   311,   311,   311,
     311,   311,   316,   316,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   318,   318,   318,   318,   318,
     319,   319,   319,   319,   319,   320,   320,   321,   322,   322,
     323,   323,   324,   324,   325,   325,   326,   326,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   328,   328,   328,   329,   329,   329,
     330,   330,   330,   330,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   333,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   334,
     334,   335,   335,   337,   336,   338,   338,   339,   340,   340,
     341,   341,   342,   342,   342,   342,   342,   343,   343,   343,
     343,   344,   344,   345,   345,   345,   345,   345,   345,   346,
     346,   346,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   348,   348,   348,   348,   349,   349,   349,   349,
     350,   350,   351,   351,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   354,   353,   353,   355,
     355,   356,   357,   357,   358,   359,   359,   359,   359,   360,
     360,   360,   361,   361,   361,   362,   362,   362
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
       3,    10,     1,     2,     5,     7,     2,     2,     3,     2,
       3,     2,     3,     9,     6,     1,     1,     1,     1,     1,
       0,     2,     3,     3,     4,     9,     4,    14,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     6,     7,
       6,     5,     3,     8,     8,     8,     8,     8,     5,     4,
       6,    11,    11,    18,    18,    12,    12,    12,    10,     4,
       4,     4,     4,     4,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     6,     1,     4,     4,
       4,     6,     5,     7,     8,    10,     4,     4,     6,     4,
       3,     2,     5,     5,     3,     5,     6,     8,     6,     8,
       6,     4,     7,     6,     6,     6,     4,     6,     4,     0,
       2,     0,     2,     0,     7,     1,     3,     1,     1,     2,
       0,     3,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       3,     1,     2,     3,     3,     5,     4,     4,     2,     4,
       2,     3,     3,    16,     5,     1,     1,     1,     3,     5,
       7,     4,     4,     4,     6,     6,     8,     8,     4,    14,
       4,     4,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     4,     4,     3,     5,
       6,     8,     6,     5,     5,     5,     5,     1,     4,     1,
       1,     1,     1,     4,     6,     4,     6,     5,     7,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     4,     2,
       4,     4,     1,     1,     3,     1,     1,     3,     3,     3,
       5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,     0,   192,     0,     0,
     193,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,   316,   317,
     318,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,   285,   286,     0,     0,     0,   280,
       0,     0,     0,     0,     0,   367,   368,   369,     0,     0,
       5,     6,     7,     8,    10,     0,    11,    24,    12,    13,
      14,    15,    23,    22,    21,    16,     0,    17,    18,    19,
      20,     0,    25,     0,   606,     0,   217,     0,     0,     0,
       0,     0,   265,     0,   267,   268,   263,   264,     0,   269,
     113,   123,   605,   480,   475,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,   203,   204,   205,
       0,     0,     0,     0,   421,   422,   424,   425,   423,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,   430,   431,     0,     0,   191,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   426,   427,   428,     0,     0,     0,     0,
       0,     0,     0,     0,   515,   516,     0,   517,   493,   374,
     434,   437,   299,   494,   475,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,   193,   194,   189,   196,   197,
     198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   482,     0,     0,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   605,     0,     0,   217,     0,
       0,   364,     0,     0,     0,   200,   201,     0,     0,     0,
       0,     0,   501,     0,     0,   499,     0,     0,     0,     0,
       0,   605,     0,     0,   538,     0,     0,     0,     0,   261,
     262,     0,   557,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   559,     0,   583,   561,
     562,     0,     0,     0,     0,     0,     0,   560,     0,     0,
       0,     0,   278,   279,     0,   217,     0,   217,     0,     0,
       0,   475,     0,     0,     0,   217,   370,     0,     0,    76,
       0,    63,     0,     0,    67,    66,    65,    64,    69,    68,
      70,    71,     0,     0,     0,     0,     0,     0,   544,   475,
       0,   216,     0,   215,     0,   170,     0,     0,   544,   545,
       0,     0,   595,     0,   596,   545,   111,   111,     0,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     532,   533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   377,     0,   376,
     502,   378,     0,   495,     0,     0,   475,     0,   510,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,   451,     0,     0,     0,     0,     0,
       0,   300,     0,   332,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   217,     0,   217,   217,     0,   484,
     483,     0,     0,     0,     0,   217,   217,     0,     0,     0,
       0,   296,     0,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,     0,     0,     0,     0,     0,
     242,     0,     0,   240,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,   260,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
     281,     0,   247,     0,     0,   249,     0,     0,     0,   376,
       0,   217,     0,     0,     0,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    72,    73,     0,     0,
     258,    38,   254,     0,     0,     0,     0,     0,   212,     0,
       0,     0,     0,     0,   218,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,   478,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,     0,     0,     0,   195,     0,     0,     0,
       0,     0,     0,   360,   361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   432,   450,     0,     0,     0,
       0,   511,   512,     0,     0,     0,     0,     0,   469,     0,
     375,   496,     0,     0,     0,     0,   504,     0,   394,   393,
     392,   391,   387,   388,   395,   396,   390,   389,   380,   379,
       0,   381,   503,   382,   385,   383,   384,   386,   476,     0,
       0,   477,   454,     0,   518,     0,     0,     0,     0,     0,
       0,     0,   330,     0,     0,     0,     0,   363,     0,     0,
       0,     0,   362,     0,   217,     0,     0,     0,     0,     0,
     486,   485,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,   241,     0,     0,   236,     0,
       0,     0,     0,   359,     0,     0,     0,   375,   500,     0,
       0,     0,     0,     0,     0,     0,     0,   283,   284,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,     0,     0,
       0,   471,     0,     0,   246,   250,   248,   252,     0,   381,
       0,   476,   454,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,   375,
       0,    63,     0,     0,     0,     0,    79,     0,    63,    64,
       0,     0,   476,     0,     0,   454,     0,     0,     0,   189,
       0,     0,     0,   602,    28,    26,    27,     0,     0,     0,
       0,     0,   477,   548,    29,     0,     0,   255,   597,   598,
       0,   599,   548,    74,   114,    75,   124,   479,   481,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   534,   535,   206,
       9,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     420,   407,     0,   409,   410,   411,   412,   413,   531,   414,
     415,   416,     0,     0,     0,   523,   522,   521,     0,     0,
       0,   528,     0,   466,     0,     0,     0,   468,     0,   128,
     449,   507,   506,   199,     0,     0,   435,   530,   440,     0,
     446,     0,     0,     0,     0,   497,     0,     0,   447,     0,
     509,     0,     0,     0,     0,   439,   438,   461,    70,    71,
       0,     0,     0,     0,     0,     0,   375,   328,   333,   331,
       0,   341,     0,   148,   149,   199,   375,     0,     0,     0,
       0,   237,     0,   251,   253,     0,     0,     0,   207,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,   287,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,   348,     0,     0,     0,
       0,     0,     0,     0,   202,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,     0,     0,     0,   573,     0,
     580,   569,   570,   571,     0,   585,   584,     0,     0,   574,
     575,   576,   582,   589,   588,     0,   139,     0,   563,     0,
     565,     0,     0,     0,   558,     0,   245,     0,     0,     0,
       0,     0,     0,     0,   321,     0,     0,     0,   371,     0,
     603,     0,     0,     0,     0,   101,    63,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,    61,     0,    39,
      40,    41,    42,    43,     0,   439,   438,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   547,
     546,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     131,   132,     0,     0,     0,     0,     0,     0,     0,   155,
     155,     0,     0,     0,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   338,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,     0,     0,     0,     0,     0,   469,   470,     0,   442,
       0,     0,     0,   505,   397,   498,   455,   453,     0,   452,
       0,     0,   519,     0,     0,     0,     0,     0,     0,     0,
       0,   340,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,   307,     0,     0,
     306,     0,   309,     0,   311,     0,   297,   303,     0,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
     350,     0,   239,   238,   366,     0,     0,    35,    36,     0,
       0,     0,     0,   539,     0,     0,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,   472,   567,     0,   455,     0,     0,   217,   322,
       0,   323,   217,     0,     0,   553,   554,   555,   556,     0,
      86,     0,     0,     0,     0,    84,    91,    93,     0,   542,
       0,    99,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,    34,   455,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,     0,   549,
       0,     0,    32,     0,   549,   600,     0,   115,   120,     0,
       0,     0,   134,   137,   138,   474,     0,    77,     0,     0,
       0,     0,    78,   157,     0,     0,     0,     0,   158,   173,
     174,     0,     0,     0,     0,   159,   184,   175,   179,   180,
     176,   177,   178,   165,     0,     0,   408,   417,   418,   419,
     524,     0,     0,     0,   464,   465,   467,   129,   433,   463,
     436,   441,     0,     0,   469,   185,   448,     0,    70,    71,
       0,   460,   456,   458,   525,   181,     0,     0,   151,     0,
       0,   339,     0,   150,     0,     0,     0,     0,   259,     0,
       0,     0,     0,   217,   217,     0,     0,   308,   493,     0,
       0,   310,   312,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,   162,   163,     0,     0,     0,     0,   102,   103,   104,
     108,     0,   581,     0,     0,   579,     0,   590,     0,     0,
     140,   141,   587,   564,   566,     0,     0,     0,     0,     0,
       0,   320,   324,   320,     0,   372,    85,    63,     0,     0,
       0,     0,    83,     0,   540,     0,     0,     0,     0,     0,
       0,   593,   592,     0,     0,     0,     0,     0,   491,     0,
       0,   460,   256,   456,   257,     0,     0,     0,     0,     0,
     222,   219,     0,     0,   552,   550,     0,     0,   116,   121,
       0,     0,     0,   532,   533,   133,   343,   344,   345,   346,
     156,   160,   161,   166,   183,     0,     0,     0,   168,     0,
       0,     0,     0,     0,     0,   443,     0,     0,     0,     0,
     520,   462,     0,   167,     0,   186,   329,     0,     0,   187,
       0,     0,     0,     0,     0,     0,   490,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   233,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       0,   347,    37,     0,   537,     0,     0,   275,   274,     0,
       0,     0,     0,     0,     0,   143,   144,   147,   146,   145,
       0,   568,     0,   604,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    97,   543,     0,     0,     0,    88,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    46,     0,
     223,   220,   221,    33,     0,     0,   601,   128,   139,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
     526,   527,     0,   469,   444,     0,   457,   459,     0,   169,
     190,     0,   336,   336,     0,   109,   110,   217,     0,   210,
     211,   298,     0,   304,     0,     0,   217,     0,     0,     0,
       0,     0,     0,     0,     0,   214,   213,     0,     0,     0,
       0,   105,   106,   572,   578,   577,   142,     0,     0,     0,
     325,     0,    92,    94,     0,   100,     0,    82,   594,    89,
      90,    49,     0,     0,     0,     0,   492,     0,     0,   457,
     551,     0,     0,     0,   118,   591,     0,   125,     0,     0,
       0,     0,   172,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,     0,
     314,     0,     0,   292,     0,   225,     0,     0,     0,     0,
       0,     0,     0,   536,   276,     0,     0,   358,   217,   373,
       0,   541,     0,    45,     0,     0,     0,    62,    47,     0,
     117,   122,   128,     0,     0,   153,   154,   152,     0,     0,
     445,     0,     0,     0,     0,   337,   351,     0,     0,   352,
       0,   208,     0,   305,     0,   288,     0,   217,     0,     0,
       0,     0,     0,     0,   164,   107,   272,   320,    98,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
     188,     0,   355,     0,   356,   357,   487,     0,     0,   294,
     228,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,    59,     0,     0,   119,     0,     0,     0,     0,     0,
     313,   293,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   229,   230,   231,   232,     0,   226,   327,    50,
       0,    57,     0,   266,     0,   529,     0,     0,     0,   295,
       0,     0,    51,     0,     0,   271,     0,     0,     0,   227,
       0,     0,     0,     0,   513,     0,     0,    54,    52,     0,
      55,     0,   353,   354,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   110,  1037,   111,   112,  1021,  1851,  1857,
    1309,  1517,  2002,  2131,  1310,  2102,  2149,  1311,  2133,  1312,
    1313,  1521,   423,   574,   575,  1107,   113,   754,   446,  1867,
    2012,  1868,   447,  1742,  1382,  1339,  1340,  1341,  1478,  1680,
    1681,  1172,  1574,  1565,   734,   585,   262,   263,   338,   191,
     264,   432,   433,   117,   118,   119,   120,   121,   122,   123,
     124,   265,  1204,  2036,  2093,   917,  1200,  1201,   266,   998,
     267,   128,  1410,  1170,   892,   931,  1972,   129,   130,   131,
     132,   268,   269,  1129,  1144,  1263,   270,   759,   271,   882,
     758,   449,   600,   307,  1717,   345,   346,   273,   544,   353,
    1297,  1510,   442,   438,  1256,   975,  1554,  1710,  1711,   960,
     444,   134,   401
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1842
static const yytype_int16 yypact[] =
{
   11955,    28,    69, 12107, -1842, -1842,  -188,    97,    25,  -100,
     -58,    19,   214,   274,   281,   304,   -32,   311,   101,   104,
      29,    11,   555,    11,    86,   134,   150,    45,   163,   174,
      63,   183,   188,   246,   257,   306,   319,   324,   358,   361,
     400,    48,   392,   553,   673,   440,   514,   617,   498,  6334,
     501,   503,   688,   -55,   548,   461,   554,    59,   559,   632,
     -71,   546,   -14,   -14,   564,   478,   383, -1842, -1842, -1842,
   -1842, -1842,   633,   376,   785,   763,    31,    60,   772,   787,
     285,   886,   894,   897,  5382,   907,   679,   698,   699,    16,
      72, -1842,   710,   718, -1842, -1842,   953,   954,   752, -1842,
    8108,   757,  8341,    39,    47, -1842, -1842, -1842, 11071,   777,
   -1842, -1842, -1842, -1842, -1842,   724, -1842, -1842, -1842, -1842,
   -1842, -1842, -1842, -1842, -1842, -1842,  -162, -1842, -1842, -1842,
   -1842,    62, -1842,   996,   765,  5137,   300,   764,  1016, 11071,
    2235,  2235, -1842, 11071, -1842, -1842, -1842, -1842,  2235, -1842,
   -1842, -1842,   775,   784,  1017, -1842, -1842, 12275,   788,   790,
     791,   797,    29, 11071, 11071, 11071,   798, 11071, 11071, 11071,
     799, 11071, 11071, 11071, 11071, 11071, 11071, 11071,  2235, 11071,
   11071, 11071, 11071,  5382,   802, -1842,  8942, -1842, -1842, -1842,
     781,  5382,  6572,  2235, -1842, -1842, -1842, -1842, -1842,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,   254,    11,    11,    11,    11,    11,   806,    11,
      11,   818,   461, -1842, -1842, -1842,    11,    11,    50,   849,
     881,   882,   817,  6572,   942,   461,   461,   823,    11,    11,
     830,   841,   842, -1842, -1842, -1842, 11071,  6810, 11071, 11071,
    7048,    29,   906,    52, -1842, -1842,   843, -1842,  1058, -1842,
   -1842, -1842, -1842, -1842,   170, 11071,  8942,   845,   846,  7286,
    5382,  5382,  5382, -1842, -1842, -1842, -1842, -1842, -1842, -1842,
   -1842,   844,  7524,   848,  9583,  1089,  6572,   850,    16,   851,
     852,   -14,   -14,   -14, 11071, 11071,   251, -1842,   397,   -14,
    9821,   484,    89,   858,   859,   861,   862,   865,   868,   869,
   11071,  5382,  5382,  5382,   870,    24,  1105,   871, -1842,  1106,
    1108, -1842,   873,   874,   876, -1842, -1842,   880,  5382,   883,
     884,   885, -1842, 11071,  5620, -1842,  1109,  1122, 11071, 11071,
   11071,   286, 11071,   887, -1842,   951, 11071, 11071, 11071, -1842,
   -1842, 11071, -1842,    11,    11,    11,   890,   892,   900,    11,
      11,    11,    11,    11,    11,    11, -1842,    11, -1842, -1842,
   -1842,    11,    11,   901,   904,    11,   905, -1842,   908,  1128,
    1131,   902, -1842, -1842,  1141,  1140,  1143,  1144,    11, 11071,
   13761,   187,  2235,  8942, 11071, -1842, -1842,  6572,  6572, -1842,
     909, 12275,   594,  1147, -1842, -1842, -1842, -1842, -1842, -1842,
   11071, 11071,    34,  6572,  1145,   148,  1136,   911,  1150,    44,
     913, -1842,   934, 12404, 11071, -1842,  1340,  -169, -1842,    65,
    -147,  6508, -1842,  -136, -1842,   126,   314,   340,  1094, -1842,
      29,   933, 11071, 11071, 11071, 11071,   935, 14277, 14302, 14327,
   11071, 14352, 14377, 14402, 11071, 14427, 14452, 14477, 14502, 14527,
   14552, 14577,   945, 14602, 14627, 14652, 12221,  1181, 11071,  8942,
    2564, -1842,   122, 11071,  1183,  1184,   950, 11071, 11071, 11071,
   11071, 11071, 11071, 11071, 11071, 11071, 11071, 11071, 11071, 11071,
   11071, 11071, 11071,  8942, 11071, 11071, 11071, 11071, 11071, 11071,
    8942,  8942,   952, 11071, 11071,  2235, 11071,  2235,  6572,  2235,
    2235,  2235,   955, 11071,    27, -1842,  9897, 11071,  6572,  5382,
    6572,  2235,  2235,  8942,    29, 12275,    29,   956,  8942,   956,
   -1842,   956, 14677, -1842,   275,   948,   133,  1133, -1842,  1190,
   11071, 11071, 11071, 11071, 11071, 11071, 11071, 11071, 11071, 11071,
   11071, 11071, 11071, 11071,  7762, 11071, 11071, 11071, 11071, 11071,
      29, 11071, 11071,  1196, -1842,   480, 14702,   364, 11071, 11071,
   11071, -1842,  1197,  1198,  1198,   966, 11071, 11071,  1201,  8942,
    8942, 13789,   967,  1203, -1842,   968, -1842, -1842,  -141, -1842,
   -1842,  6746,  6984,   -14,   -14,   300,   300,  -122,  9821,  9821,
   11071,  4719,   -99, -1842, 11071, 11071, 11071, 11071, 11071, 11071,
   11071, 11071, 11071, 14727,  1207,  1204,  1208, 11071,  1210, 11071,
   -1842, 11071,  5189, -1842, -1842,  8942,  8942,  8942, 11071,  1211,
   11071, 11071, 11071, 14752,   973, -1842, -1842, 14777, 14802, 14827,
    1045,  7222, -1842,   977,  4297, 14852, 14877, 13872,  2235,  2235,
    2235,  2235,  2235,  2235,  2235,  2235,  2235, 11071,  2235,  2235,
    2235,  2235,    12, 12275,  2235,  2235,  2235,    29,    29, -1842,
   -1842,  8942, -1842,   979, 11099, -1842,   983, 11228, 11071,   956,
   11071, -1842,    29, 11071, 11071,  1196,   986,   465, 14902, 12287,
     981,   486, 11071,  1224,   987,   988,   989,   990,  6572, 14927,
   13899,   335,   991,  1228,  1232, -1842, -1842, -1842,  8942,    22,
   -1842, -1842, -1842,    29, 11071, 11071,  1196,   997, -1842,  1003,
     -20,   461,   554,   461, -1842,  1000, 12862, -1842,    90,  8942,
      29, 11071, 11071,  1242,  1241,  8942, 11071,  1243,  2235,    29,
   10130,  1242,  1245, -1842,    29,  1246,  2235, 11071,  1007,  1011,
   -1842, 11071,  7460,  7698,  8402,  8640, 12275,  1248,  1250,  1251,
   14952,  1253,  1254,  1255, 14977,  1256,  1257,  1259,  1260,  1261,
    1262,  1264, -1842,  1265,  1266,  1287, -1842, 11071, 15002,  8942,
    1051,  8942, 12891, -1842, -1842,  1290, 13845, 13845, 13845, 13845,
   13845, 13845, 13845, 13845, 13845, 13845, 13845,  8878, 13845, 13845,
   13845, 13845,   622,   449, 13845, 13845, 13845,  9209,  9529,  9766,
    2564,  1057,  1059,    94,  8942,  9853, 10082,   449, 10162,   449,
    1052,  1054,  1055,  -116, 11071, 15902, -1842,   449,  1060, 12920,
   12949, -1842, -1842,  1061,   -16,   449,   165,  1065,   -68,   495,
    1293, -1842,  1242,   449,  1063,  1064,  4329,  4649,  2585,   701,
     550,   550,   531,   531,   531,   531,   531,   531,   563,   563,
    8942,   211, -1842,   211,   211,   956,   956,   956,  1062, 15027,
   13926,   338,   515,  8942, -1842,  1305,  1070, 15052, 15077, 15102,
   11071,  6572,  1311,  1310,  9498, 12978, 15127, -1842,   542,   556,
    8942,  1071, -1842, 11268, -1842, 11359, 11399,   -14, 11071, 11071,
   -1842, -1842,  1076,  1077,  9821,  5556,  1193,   423,   -14, 11490,
   15152, 13007, 15177, 15202, 15227, 15252, 15277, 15302, 15327,  1318,
   11071,  1320, -1842, 11071, 15352, -1842, 13953, 13980, -1842,   561,
     562,   568, 13036, -1842, 14007, 14034, 10398, -1842, -1842,  1322,
    1323,  1324,  1081, 11071, 11530, 11071, 11071, -1842, -1842,    55,
     172,   205,   172,  1091,  1092,  1085,   449,   449,  1087, 10478,
     449,   449,   449,   449, 11071,   449,  1328, -1842,  1090,  1097,
     325,   -79,  1098,   569, -1842, -1842, -1842, -1842, 13845,   211,
   11621,  1096,   526,  1095,  1162,  1337,  1195, 10213,  1102,  1107,
    1343,  6572, 13065, -1842, 11071, 11071, 11071, 11071,  1344,   377,
      84, 12275, 11071,  1365,  1368,    17, -1842,   570,  1327,  1330,
    6572,    26,  1137, 15377, 14061,   457, 11071, 11071,  1134,  1138,
    1146,  1148,  8000, -1842, -1842, -1842, -1842,  2235,   -54,  1139,
   15402, 14088, -1842,  1149, -1842,   -36, 10707, -1842, -1842, -1842,
    1151, -1842,  1153, -1842,   105, -1842, -1842, 15902, -1842,  1373,
   13845, 11071, 11071, 11071, 11071,   449,   -14,  6572,  6572,  1377,
    6572,  6572,  6572,  1387,  6572,  6572,  6572,  6572,  6572,  6572,
    6572,  6572,  6572,  6572,  1491,  1388,  8942,  2564, -1842, -1842,
   -1842, -1842, -1842, -1842, -1842, -1842, -1842, -1842, -1842, -1842,
   -1842, -1842, 11071, -1842, -1842, -1842, -1842, -1842, -1842, -1842,
   -1842, -1842, 11071, 11071, 11071, -1842, -1842, -1842,   571, 11071,
   11071, -1842, 11071, -1842,  6572,  2235,  2235, -1842, 13094,  1152,
   -1842, -1842, -1842,  1220, 11071, 11071, -1842, -1842, -1842,  1242,
   -1842,  1242, 11071, 11071,  1158, -1842,  6572,    11, -1842, 11071,
   -1842, 11071, 11071,   579,  1242,   338,   -94, -1842, 11071, 11071,
     449,   580,  6572,  8942,  1393,  1399,  1400,  5015, -1842, -1842,
    1402, -1842,  1168, 15902,  1163, -1842,  1407,  1408,  1409,   581,
    1413, -1842, 11661, -1842, -1842,   -80, 10794, 10940, -1842, -1842,
   13123,  -130,  1309,  1418, 10446,  1179,  1419,  1187,    37,    41,
     -72, -1842,   -65, -1842,   423,  1417,  1422,  1423,  1424,  1425,
    1426,  1427,  1428,  1429,  6572, 15902, -1842,  1991,  1185,  1432,
    1433,  1434,  1345,  1436, -1842,  1435,  1438, 11071,  6572,  6572,
    6572,  1442, 11198, -1842,  4836,   944,    46,  1443, -1842,  8942,
   -1842, -1842, -1842, -1842,  2235, -1842, -1842, 11071,  2235, -1842,
   -1842, -1842, -1842, 15902, -1842,  1202,  1205,  2235, -1842,  2235,
   -1842,  1242,  2235,  1212, -1842,  1206, -1842,  1242, 11071, 11071,
    1213,   461,  1214, 10529, -1842,  2464,  1215,  6572, -1842,  1225,
   -1842, 13152, 13181, 13210, 13239, -1842, -1842, 11071,  1445,    36,
   11071,  1446,  1450,  2824, -1842,  1453,    16,  1465,  1231,   449,
      11,    11,  1472, -1842,  1239,  1240,  1237, -1842,  1479, -1842,
   -1842, -1842, -1842, -1842,  1242,   379,  1415, 11071, 14115, 15427,
   11071,  8233, 11071,  8942,  1247,   582,  1480,   162,  1242, -1842,
    1244, 11071,  1485, 11071,  1242, 10762,  4266,   449,  4562,  1252,
    1249, -1842,  1488, 15452, 15477, 15502, 15527,  1490,    21,  1378,
    1378,  6572,  1494,  1497,  1498,  6572,   -85,  1500,  1501,  1502,
    1503,  1504,  1507,  1508,  1509,  1510, -1842,  1513,   587, 13845,
   13845, 13845, 13845,   449, 11329, 11460, 11591,  1279,   449,   449,
   -1842,  1373,   449, 15552, 13845,  1280,   298, 15902, 13845, -1842,
    1516,   449, 11753, 15902, 15902, -1842,   527, -1842,  1519, -1842,
   15577, 14142, -1842,   449,  1518,   589,  6572,  6572,  6572,  1521,
    1520, -1842,   227, 11071,  6572,  1283,  1284,  1522,   853, -1842,
   11071, 11071, 11071,  1288,  1292,  1294,  1289, -1842,  2966,  6572,
   -1842, 11071, -1842,  1528, -1842,  1531, -1842, -1842,  9821,   -38,
    5858, -1842,  1295,  1296,  1298,  1300,  1301,  1302,  8466,  1541,
   -1842,  8942, -1842, -1842, -1842,  1306, 11071, -1842, -1842, 14169,
    1543,  1545,  1379, -1842, 11071, 11071, 11071, -1842,  1546,  1549,
    1570,   910,   476,  1329,  5318,  1331, 11071,    33,   449,  1336,
     449,  1332, -1842, -1842, 12275,   593, 11071,  1341, -1842, -1842,
    2990, -1842, -1842,  1338,  1580, -1842, -1842, -1842, -1842,  3116,
   -1842,   381,  1342,  1582,  3150, -1842, -1842, -1842,    16, -1842,
     613, -1842, 11071,   227,   895,  1702, -1842,  1350, 11071, 11071,
    6572,  1347, -1842,   508,  1588,  1587, 15602,  1590,  1293, 15627,
    1349,   626, 15652,   627,  1591,  1593, -1842, -1842,  2235,  1360,
    1598, 15677, -1842, 12334,  1363, -1842,  4899, 15902, -1842,  1597,
      11,  7048, -1842, -1842, -1842, -1842,  1373, -1842,  1599,  1600,
    1601,  1602, -1842, -1842,   -14,  1606,  1607,  1608, -1842, -1842,
   -1842,  1609,   -40,  1523,  1610, -1842, -1842, -1842, -1842, -1842,
   -1842, -1842, -1842, -1842,  1612,  1381, -1842, -1842, -1842, -1842,
   -1842, 11071, 11071, 11071, -1842, -1842, -1842,  1249, -1842, -1842,
   -1842, -1842, 11071,  1389,  1380, -1842, -1842, 11071, 11071, 11071,
     449,   338, -1842, -1842, -1842, -1842,  1384,  1627,   -85,  1628,
   11071, -1842,  6572, 15902,   750,  8942,  8942, 11071, -1842,  9498,
   13268, 15702,  5794,   300,   300, 11071, 11071, -1842,   131,  1386,
   15727, -1842, -1842, 13297,   -52, -1842,  1632,  1634,  6572,   -14,
     -14,   -14,   -14,   -14,  6096,  1635, -1842,   629, 11071,  3195,
    1636, -1842, -1842,  6572,  6032,   238, 15752, -1842, -1842, -1842,
   -1842,  9175, -1842,  2235, 11071, -1842,  2235, 15902,  9260, 12275,
    1394, -1842, -1842, -1842, -1842,  1403,  1397, 11071, 11071, 13326,
   11071, 12287, -1842, 12287,  6572, -1842, -1842, 12275, 11071,  1641,
    1644,    17, -1842,  1643, -1842,    16, 14196,  6572,  2235,  1648,
     449, -1842,  1401,   449, 11071, 12367, 12400,   634, -1842, 11071,
   11071,   384, -1842,  1411, -1842,  1400,  1651,  1652,  1407,  1656,
   -1842, -1842,  1657, 11071, -1842, -1842, 11071, 10838, -1842, -1842,
    1420,  1702,   636,  4218,  1658, -1842, -1842, -1842, -1842, -1842,
     708, -1842, -1842, -1842, -1842,  1430,  1431,  1437, -1842,  1661,
    6572, 13845, 13845, 12433, 13845, -1842,  1441, 12466, 15777, 14223,
   -1842, -1842, 11071, -1842,  1662, -1842, 15902,  1663,  1439, -1842,
     644,   646, 13817,  3463,  1665,  1444, -1842, -1842, 11071,  1440,
    1448, 13355, 14250,  1666,  6572,  1669,  1451, 11071, -1842, -1842,
     647,   -43,   -30,    -7,   149,   189,  8704,   202, -1842,  1671,
   13384, -1842, -1842,  1505, -1842, 11071, 11071, -1842, -1842,  8942,
    3547,  1673,  1455, 13845,   449, 15902, -1842, -1842, -1842, -1842,
      33, -1842, 12275, -1842, 13413,  1449,  1452,  1454,  1680,  3728,
   -1842,  1682,  1681, -1842, -1842,  1457,  1694,   658, -1842,  1695,
    1720,     6, 15902, 11071, 11071,  1483,  6572,   661, 15902, 15802,
   -1842, -1842, -1842, -1842, 15827, 12499, -1842,  1152,  1205,  6572,
     449, -1842, 11071, 12275,    29,  8942,  8942, 11071,  1722,   663,
   -1842, -1842, 11071,  1380, -1842, 11071, -1842, -1842, 13442, -1842,
   -1842,  6572,   599,   669,  8942, -1842, -1842,   300,  6270, -1842,
   -1842, -1842,  1725, -1842,  1487,  6572, -1842, 13471,  1728,  8942,
     -14,   -14,   -14,   -14,   -14, -1842, -1842, 11071, 13500, 13529,
     664, -1842, -1842, -1842, -1842, -1842, -1842,  1496,  1729,  1495,
   -1842,  1734, -1842, -1842,    16, -1842,  1571, -1842, -1842, -1842,
   -1842, -1842, 11071, 12532, 12565,  6572, -1842,  1752, 11071,  1515,
   -1842, 11071,  1527,  1530, -1842, -1842,  3691, -1842,  1525,   716,
     721, 13558, -1842,  1529, 12598,  1537, 12631, -1842,   726,  1535,
     -14,  6572,  1754,  1536,   -14,  1760,   728,  1538, -1842, 11071,
   -1842,  1775,  1654, 11752,  1544, -1842,   731,   253,   261,   264,
     270,   294,  3887, -1842, -1842,  1776,  1779, -1842, -1842, -1842,
    1781, -1842,  1548, 15902, 11071, 11071,   736, -1842, 15902, 12664,
   -1842, -1842,  1152, 12275,  1552, -1842, -1842, -1842, 11071, 11071,
   -1842, 11071,  1784,   -14,    95, -1842, -1842,   -14,   110, -1842,
    1788, -1842, 13587, -1842, 11071, -1842,   423, -1842,  1789,  8942,
    8942,  8942,  8942,  8704, -1842, -1842, -1842, 12287, -1842, 11071,
   15852, 12697,    30, 11071,  1551, -1842, -1842, 12730, 12763, 12796,
   -1842,   313, -1842,   316, -1842, -1842, -1842,  3922,   482, 11792,
   -1842,   738,   739,   741,   746,   353,   747,  1553,   755, -1842,
   11071, -1842,  6572, 13616, -1842, 11071, 11071, 11071,   -14,   -14,
   -1842, -1842, -1842,   423,  1791,  1793,  1794,  1795,  8942,  1796,
    1798,  1799,  1562, 15877,   758,  1801, 13645, 13845, 12829,   371,
     378,   547, -1842, -1842, -1842, -1842,   760, -1842, -1842, -1842,
    2235, -1842,  1564, -1842,  1803, -1842, 11071, 11071, 11071, -1842,
    1804,   766, -1842,  1567,  6572, -1842, 13674, 13703, 13732, -1842,
    1806,  2235,  2235,   769, -1842,  1807,  1808, -1842, -1842,   771,
   -1842,  1809, -1842, -1842,  1811,  2235, -1842, -1842, -1842
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1842, -1842, -1842, -1842,   491, -1842, -1842, -1842, -1842,  -230,
   -1842, -1842, -1842, -1842, -1842, -1842, -1842, -1842, -1842, -1842,
   -1842, -1842,  -701,  -123,  3831,  3031, -1842,  1374, -1842, -1842,
   -1842, -1842, -1842, -1842, -1841, -1842,   439,   266,   -44, -1842,
      -5, -1842,   208,   473,  1824, -1842,    -1,   -45, -1842, -1842,
      -2,  -598,  -269, -1842, -1842, -1842, -1842, -1842, -1842, -1842,
   -1842,  1827, -1842, -1842, -1842, -1842, -1199, -1191,  1828, -1678,
    1829, -1842, -1842, -1842,  1263, -1842,   -60, -1842, -1842, -1842,
   -1842,  1846, -1842, -1842, -1372,   354,  1831, -1842,     3,  -585,
   -1842, -1842,    92, -1842, -1629,   -27,  -120,  2356,   233,  -295,
     135, -1842,  1983,   -96, -1842, -1842,   159,   323, -1646,  -124,
    1093, -1842,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -553
static const yytype_int16 yytable[] =
{
     135,   116,   115,   595,   389,  1439,   393,   912,   913,  1437,
    1012,   292,   424,  1835,  1603,  1836,   152,   154,  1020,  1800,
     351,   152,   272,   153,   443,   142,  1952,  1563,   628,  1018,
    1303,   152,  1828,   152,     4,   325,  2081,  1678,   711,   428,
    1501,   611,   278,  1432,   394,  1572,   274,  1434,   152,   166,
    1468,  1755,   396,   723,   287,   525,   136,   548,  1193,   632,
     137,   451,  1236,   477,   330,   279,   331,   170,   406,     5,
    1756,   484,   738,   329,   740,  1194,   355,   278,   404,   297,
     739,   274,   405,  1195,  1196,  1197,   354,   603,   604,  1198,
    1199,  1286,  1193,  1573,   744,  1870,  1034,   390,   603,   604,
    1028,  2062,   745,   570,   298,   747,   603,   604,   907,  1194,
     992,   138,  1336,   748,   326,  1424,  2064,  1195,  1196,  1197,
     299,   300,   139,  1198,  1199,  1127,   684,   914,   687,   603,
     604,  1879,   429,   748,   431,   749,   699,   439,   439,   550,
     140,  1025,   450,   418,   419,   445,  1469,  1470,   603,   604,
     918,   332,  1398,   293,   306,   308,   294,   311,  1043,   456,
     582,   583,   584,   603,   604,   485,  1052,  1261,  1537,  1420,
    1262,  2054,   155,  1436,   156,   439,   603,   604,  1141,   570,
     274,  1142,   141,   274,  1438,   603,   604,  1327,   274,   274,
     439,  1304,  1305,  1306,  1307,   791,   692,  1797,   603,   604,
    1433,   624,   625,   626,  1435,  1332,  1909,  1645,   148,   712,
     713,  1502,  1503,   791,   302,   303,   272,   327,   639,  1910,
     144,   603,   604,  1679,   109,   716,   304,   717,   109,   109,
     305,   522,  1766,  1135,  1286,   414,   415,   416,  1019,   109,
     274,   109,  1911,   109,   529,   530,  1816,  1941,  1437,   603,
     604,   155,   581,   156,   274,  1942,   109,   274,   546,   974,
     352,  1296,  1968,   143,   545,   588,   629,  1147,   716,   593,
     717,  1308,   137,   274,  2082,   328,   274,   274,   274,   274,
     145,   418,   419,   395,   724,   167,   725,   146,  -545,   274,
     726,   397,   182,   274,   526,   354,   549,   414,   415,   416,
     417,  1237,   407,   171,   430,   741,   408,   742,  1287,  1290,
     147,   743,   356,  1035,  1036,   703,  2006,   149,   274,   274,
     274,   418,   419,   603,   604,   903,   163,   905,   906,   614,
    1289,   418,   419,   615,   571,   274,   572,  1117,   603,   604,
     573,   274,  1011,   150,   919,   155,   151,   156,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   750,   790,   742,  2077,
     569,   791,   751,   155,   164,   156,  1793,   603,   604,   335,
     700,   701,   336,   954,  1286,  1035,  1036,   312,  1697,   716,
     165,   717,   718,   598,   599,   337,   714,   833,  1912,   439,
     274,   607,   612,   168,   274,   274,  1138,   418,   419,   841,
     571,  1139,   572,   716,   169,   717,   573,   603,   604,   482,
     274,   748,   990,   172,   418,   419,   727,   693,   173,   694,
     603,   604,   735,   695,    61,    62,    63,    64,  1913,   847,
     414,   415,   416,   417,   567,   568,   716,   760,   717,    75,
     569,  1914,    78,  2104,  1239,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,   321,   313,   322,   274,   569,   314,   603,
     604,   603,   604,  1817,   315,   316,   174,   317,   318,   603,
     604,   830,   603,   604,   510,   605,   511,   175,   603,   604,
     274,   581,  2039,   842,   183,  2143,   319,   274,   823,   577,
    2040,  1965,   439,  2041,   439,   274,   439,   439,   445,  2042,
     851,   837,   603,   604,   791,   274,   274,   274,   439,   439,
     274,   154,   650,   154,   137,   274,   962,   846,   155,   848,
     156,   603,   604,  2043,   603,   604,   176,  1142,   414,   415,
     416,   417,   283,  1193,  1385,   284,  1386,   752,   285,   177,
     286,   274,  2088,   753,   178,  2089,   716,   878,   717,  1396,
    1194,    41,   418,   419,  1259,   418,   419,   977,  1195,  1196,
    1197,   603,   604,   755,  1198,  1199,   274,   274,  1013,   753,
     414,   415,   416,   417,   414,   415,   416,   417,   179,   603,
     604,   180,  2098,   431,   431,   187,   603,   604,   188,   886,
     735,   189,  1193,   791,   418,   419,   418,   419,   418,   419,
    2127,   418,   419,  -547,   190,   603,   604,  2128,  -552,  1194,
     550,   735,   274,   274,   274,  1182,   697,  1195,  1196,  1197,
     181,   606,   280,  1198,  1199,   281,   158,   282,   288,   159,
     184,   289,   160,   290,   161,   445,   439,   445,   439,   439,
     439,   439,   439,   439,   291,   439,   439,   439,   439,   976,
    1065,   439,   439,   439,   154,   982,  1481,  1193,   274,   185,
     981,  1008,  1485,   735,   186,   704,   735,  1030,   705,   991,
     716,   706,   717,   707,  1194,   910,   911,  1317,   735,  1269,
     599,  -548,  1195,  1196,  1197,   274,   302,   303,  1198,  1199,
     994,  1622,   603,   604,   791,   274,   192,   716,   304,   717,
    1022,   716,   310,   717,   883,   791,   296,  2091,   613,  1523,
    1029,  1000,  1031,  1969,  1970,  1001,   274,  1039,   193,  1971,
    1145,   275,   274,  1539,   791,   445,  1050,   276,  1720,  1544,
    1688,  1054,  -549,   439,  1778,  1158,  1779,  1159,  1157,   562,
     563,   690,   565,   566,   567,   568,  1268,  1608,  1269,  1609,
     569,   849,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,   277,   274,  1177,   274,   569,
     301,   791,  2129,   690,   565,   566,   567,   568,  1174,   295,
    1698,  1178,   569,  1973,  1974,   791,  1221,  1222,   309,  1971,
     791,   791,  1707,  1223,  1265,  1299,  1373,   791,   791,   791,
     791,   274,   898,   899,  1395,  1403,  1417,  1535,   791,   791,
     791,   791,  1585,  1687,  1616,  1688,   791,  2068,   791,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   789,   565,   566,   567,   568,   324,  1704,  1628,
    1629,   569,  1705,   716,  1168,   717,   333,   274,   939,   940,
     941,  1727,  1729,   320,  1809,   791,   791,  1437,   791,  1855,
     274,  1871,   323,  1856,   334,  1872,  1288,  1291,   274,  1892,
     339,  1893,  1908,   791,  2111,   791,  1856,   274,   340,   152,
     362,   341,   735,  1938,   735,   735,  1947,   748,  1963,  1995,
    1948,   347,  1856,   791,   983,  1292,  1670,  1671,   735,   348,
    1437,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,   603,   604,   349,   350,
     569,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     357,  1017,  1466,   735,   372,   373,   374,   375,   358,   359,
     360,  2015,   376,   377,   378,   791,  2016,   379,   403,   380,
     791,  2022,  1038,  2030,  1279,  1856,  2038,   791,  1045,   381,
     791,  2052,   382,  2094,  2095,  1856,  2096,   791,   791,   735,
     791,  2097,  2099,  1302,   361,   791,   791,   391,   274,  1185,
    2101,  1509,   409,  2122,  1948,  2130,  1191,  1856,   434,   791,
    1202,  2140,  1298,   410,  2151,  2141,  2154,   274,  1856,   402,
    2155,   412,   435,   137,   448,   483,   450,  -192,   452,   274,
     453,   454,  1397,  1399,   439,  1789,  1790,   455,   460,   464,
    1349,  1350,   478,  1352,  1353,  1354,   518,  1356,  1357,  1358,
    1359,  1360,  1361,  1362,  1363,  1364,  1365,  1118,   521,  -193,
    -194,   527,   528,   531,   274,   274,   550,   274,   274,   274,
     534,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   535,   536,   274,   547,   578,   579,   405,   586,   383,
     384,   385,   589,   592,   594,   596,   597,  1377,   616,   617,
     386,   618,   619,  1153,   387,   620,   388,   109,   621,   622,
     627,   630,   633,   631,   634,   645,  1161,   635,   636,  1390,
     637,   274,   439,   439,   638,   640,   641,   642,   646,   653,
     661,   652,   662,  1179,   679,  1404,   716,   680,   717,  1708,
     663,   674,   720,   274,   675,   677,   681,   682,   683,   685,
     678,   715,   686,   702,   708,   721,   722,   136,  1348,   274,
     274,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,   728,
     757,   735,   761,   569,   766,  1467,   782,  1449,   787,   793,
     794,   795,  1397,  1399,   852,   569,   824,   854,   855,   834,
     881,  1460,  1461,  1462,   890,   891,   894,   897,   901,   902,
     932,   274,   904,  1703,   930,   933,   935,   943,   948,  1691,
     952,   955,   999,  1693,   984,   274,   274,   274,   986,   993,
    1003,  1004,  1005,  1006,  1007,  1015,   274,  1014,  1016,  1026,
    1548,   439,  1553,  1027,  1032,   439,  1042,  1044,  1058,  1047,
    1493,  1053,  1055,  1059,   439,  1066,   439,  1067,  1068,   439,
    1070,  1071,  1072,  1074,  1075,  1325,  1076,  1077,  1078,  1079,
    1487,  1080,  1081,  1082,   274,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   354,  1083,  1086,  1090,   569,  1115,  1977,
    1146,  1124,  1116,  1125,  1126,  1131,  1140,  1149,  1154,  1150,
    1134,  1552,  1162,   439,  1163,  1169,  1171,  1180,   274,  1368,
     274,  1188,  1189,  1192,  1567,  1214,  1216,  1231,  1571,  1228,
    1229,  1230,  1242,  1243,  1244,   274,  1247,  1255,  1258,  1257,
    1271,  1264,  1267,  1270,  1272,  1273,   737,  1276,   274,  1278,
    1285,  1277,   274,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,  1294,  1295,  1300,  1320,   569,  1301,  1338,  1699,  1617,
    1618,  1619,  1321,  1314,  1351,  1328,  1322,  1624,  1686,  1331,
    1712,  1712,  1323,  1335,  1355,  1367,  1405,  1334,  -195,  1389,
    1406,  1381,  1639,   274,   274,   274,  1407,  1408,  1411,  1412,
    1844,   274,  1413,  1647,  1414,  1415,  1416,  1418,  1425,   152,
     362,  1655,  1426,  1429,  1440,  1430,   274,  1431,  1441,  1451,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,   274,  1452,  1453,
    1454,  1457,  1455,  1456,  1458,   274,  1463,  1471,   274,  1476,
    1739,  1500,  1505,  1483,  1477,  1484,  1506,  1486,  1488,  1492,
    1508,   363,   364,   365,   366,   367,   368,   369,   370,   371,
    1494,  1511,  1472,  1512,   372,   373,   374,   375,  1516,  1518,
    1519,  1520,   376,   377,   378,  1522,  1536,   379,  1771,   380,
    1540,  1542,  1534,  1718,  1557,  1555,  1562,  1366,  1556,   381,
    1568,  1564,   382,  1569,  1570,   354,  1575,  1576,  1577,  1578,
    1579,   445,   445,  1580,  1581,  1582,  1583,   274,  1584,  1738,
    1594,  1601,  1605,  1611,  1615,  1620,  1621,  1625,  1626,  1627,
    1644,  1636,  1633,  1784,  1641,   439,  1634,  1642,  1635,  1648,
    1649,   412,  1650,   274,  1651,  1652,  1653,  1656,   274,  1661,
    1658,  1662,  1667,  1663,  1531,  1668,  1533,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,  1821,  1669,  1683,  1673,   569,
    1676,  1262,  1826,  1829,  1847,  1690,  1695,  1694,  1700,  1701,
    1714,  1719,  1721,  1722,  1726,  1777,  1724,  1730,  1771,  1731,
    1733,  1838,  1734,  1737,  1740,  1746,  1747,  1748,  1749,   383,
     384,   385,  1751,  1752,  1753,  1754,  1758,  1759,  1757,   274,
     386,  1718,   274,   274,   387,  1760,   388,   109,  1772,  1142,
    1765,   431,   431,  1773,  1775,  1794,  1813,  1983,  1798,  2000,
    1799,  1808,  1812,  1830,  1831,   274,  1832,  1840,  1841,  1843,
     748,   274,   418,   419,  1848,  -550,  1750,  1860,  1861,  -546,
     274,  1524,  1862,  1863,  1869,  1874,  1878,  1837,  1889,  1890,
     439,  1896,  1903,   439,  1875,  1876,  1905,  1915,  1917,  1922,
    1846,  1877,  1884,  1891,  1657,  1899,  1932,  1935,  1897,  1934,
     735,   274,   735,  1900,  1929,  1906,  1923,  1930,  1298,  1931,
    1937,  1939,   354,  1936,   274,   445,   152,   362,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,  1940,  1945,  1962,  2047,
     569,  1980,  1981,  1718,  1985,  1997,  1927,  1996,   445,  1998,
    1999,  1801,  1802,  1803,  1804,  1805,  1807,  2001,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   274,  2007,  -551,
    2026,   372,   373,   374,   375,  2014,  2029,  1904,  2069,   376,
     377,   378,  2010,  2018,   379,  2011,   380,  1957,  2020,  2023,
    2027,  2033,  2045,  2031,  2034,  2046,   381,  2048,  2037,   382,
    2060,   274,  2049,  2056,  2065,  2070,  2084,  2112,  2100,  2113,
    2114,  2115,  2117,   274,  2118,  2119,  2120,  2123,  2134,  2135,
    2139,  2142,  2147,  2152,  2153,  2156,   274,  2157,  1538,  2078,
    1597,   756,  1745,  1566,  1953,  1926,  1774,   114,   412,  1946,
     125,   126,   127,  1975,   133,  1685,  1842,  1827,  1713,     0,
       0,  1049,  1954,     0,     0,     0,     0,   893,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,  1780,  1781,
       0,     0,     0,     0,  1718,     0,   274,     0,     0,     0,
       0,  1958,   274,   274,     0,     0,     0,     0,  1982,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,   274,     0,     0,     0,   431,   383,   384,   385,     0,
       0,     0,   274,     0,     0,     0,   274,   386,     0,     0,
       0,   387,     0,   388,   109,     0,     0,  2055,  1718,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,  2025,     0,  1708,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,   735,     0,     0,   436,     0,     0,     0,   441,
       0,     0,     0,     0,     0,     0,     0,  1450,     0,     0,
       0,     0,  1987,  1988,  1989,  1990,  1991,     0,     0,   457,
     458,   459,     0,   461,   462,   463,     0,   465,   466,   467,
     468,   469,   470,   471,     0,   473,   474,   475,   476,     0,
       0,     0,   480,     0,     0,     0,   274,   274,   274,   274,
     274,     0,     0,     0,     0,     0,   735,     0,     0,     0,
       0,     0,  1920,     0,     0,  1718,     0,     0,     0,     0,
       0,     0,  2024,     0,     0,     0,  2028,     0,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   274,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,     0,     0,     0,
       0,     0,   537,   539,   541,   542,   480,  1718,  1959,  1960,
       0,     0,     0,     0,     0,  2061,     0,   439,   427,  2063,
       0,   576,   480,   437,   440,     0,     0,  1976,     0,     0,
       0,   274,     0,     0,     0,  2075,     0,     0,   439,   439,
     591,     0,  1986,     0,     0,     0,     0,     0,     0,     0,
     601,   602,   439,     0,     0,     0,   602,     0,     0,     0,
       0,   472,     0,     0,     0,     0,   623,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
    2109,  2110,     0,     0,     0,     0,     0,     0,     0,   643,
     480,     0,     0,     0,   647,   648,   649,     0,   651,     0,
       0,     0,   654,   655,   656,     0,     0,   657,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     362,     0,     0,     0,     0,   689,     0,     0,     0,   480,
     698,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   709,   710,     0,     0,
       0,     0,  2071,  2072,  2073,  2074,  2076,     0,     0,     0,
     736,   363,   364,   365,   366,   367,   368,   369,   370,   371,
       0,     0,     0,     0,   372,   373,   374,   375,   762,   763,
     764,   765,   376,   377,   378,     0,   770,   379,     0,   380,
     774,     0,     0,     0,     0,     0,     0,     0,     0,   381,
       0,     0,   382,     0,   788,   539,     0,     0,     0,   792,
       0,  2116,     0,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,   810,   811,   812,
     814,   815,   816,   817,   818,   819,   820,   820,     0,   825,
     826,   412,   828,     0,     0,     0,     0,     0,     0,   835,
       0,     0,   839,   840,     0,     0,     0,     0,     0,   820,
       0,     0,     0,     0,   480,   696,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   856,   857,   858,   859,
     860,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     871,   873,   874,   875,   876,   877,     0,   879,   880,     0,
       0,     0,     0,     0,   887,   888,   889,     0,     0,   383,
     384,   385,   895,   896,     0,   480,   480,     0,     0,     0,
     386,     0,     0,     0,   387,     0,   388,   109,     0,     0,
       0,     0,     0,     0,   537,   689,   915,     0,     0,     0,
     920,   921,   922,   923,   924,   925,   926,   927,   928,     0,
    1491,     0,     0,   934,     0,   936,     0,   937,     0,     0,
       0,   480,   480,   480,   942,     0,   944,   945,   946,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   827,     0,
     829,     0,   831,   832,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   969,   843,   844,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,   988,     0,   989,     0,     0,   879,
     880,     0,   481,     0,     0,     0,     0,     0,  1002,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
    1023,  1024,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,  1040,  1041,     0,
       0,   480,  1046,     0,     0,     0,  1040,     0,     0,     0,
       0,     0,     0,  1057,     0,     0,     0,  1060,     0,     0,
       0,     0,     0,   540,     0,     0,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   481,  1084,     0,   871,     0,  1087,     0,     0,
       0,     0,   961,     0,   963,   964,   965,   966,   967,   968,
       0,   970,   971,   972,   973,     0,     0,   978,   979,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1128,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
     481,     0,     0,   569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,  1048,     0,     0,     0,     0,  1167,     0,     0,  1056,
    1173,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,  1186,  1187,     0,     0,     0,   481,
    1190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1215,     0,     0,  1217,
       0,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   789,   565,   566,   567,   568,  1232,
       0,  1234,  1235,   569,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
    1253,     0,     0,     0,   569,     0,     0,     0,     0,     0,
    1507,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,  1275,     0,     0,     0,     0,     0,     0,
    1281,  1282,  1283,  1284,     0,     0,     0,     0,  1293,   813,
       0,     0,     0,     0,     0,     0,   821,   822,     0,     0,
       0,     0,  1318,  1319,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   845,
       0,     0,     0,     0,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1343,  1344,  1345,
    1346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     872,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,   481,     0,  1369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1370,  1371,
    1372,     0,     0,     0,     0,  1374,  1375,     0,  1376,     0,
       0,     0,  1637,     0,     0,     0,     0,     0,     0,     0,
    1383,  1384,     0,     0,     0,     0,     0,     0,  1387,  1388,
       0,   481,   481,   481,     0,  1392,  1692,  1393,  1394,     0,
       0,     0,     0,     0,  1400,  1401,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,     0,
    1428,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1459,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,  1474,     0,   481,     0,     0,     0,     0,
       0,   481,     0,     0,     0,     0,     0,     0,  1378,  1379,
       0,     0,     0,     0,  1400,  1401,     0,     0,     0,  1490,
       0,     0,  1696,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1499,     0,     0,  1504,     0,     0,     0,
       0,     0,     0,     0,     0,   872,     0,  1088,     0,     0,
       0,     0,     0,     0,     0,     0,  1702,     0,     0,     0,
       0,     0,     0,  1526,     0,     0,  1529,   480,  1532,   480,
       0,     0,     0,     0,     0,     0,     0,  1541,     0,  1543,
     481,  1541,  1547,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,  1811,     0,     0,     0,   569,     0,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,   481,  1473,     0,   569,
       0,  1475,     0,     0,     0,     0,     0,     0,     0,   481,
    1479,     0,  1480,     0,     0,  1482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,     0,     0,  1623,
       0,     0,     0,     0,     0,     0,  1630,  1631,  1632,     0,
       0,     0,     0,     0,     0,  1638,     0,  1640,     0,     0,
       0,     0,     0,     0,  1643,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,     0,  1525,
       0,     0,  1659,     0,     0,     0,     0,     0,     0,     0,
    1664,  1665,  1666,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1689,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,  1706,     0,
       0,     0,     0,     0,  1715,  1716,     0,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,   481,   569,
       0,     0,     0,     0,     0,     0,     0,  1743,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,  1761,  1762,  1763,
       0,     0,   481,     0,     0,     0,     0,     0,  1764,     0,
       0,     0,     0,  1767,  1768,  1769,   719,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1776,     0,     0,  1895,
       0,   480,   480,  1782,     0,  1783,     0,     0,     0,     0,
       0,  1791,  1792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,  1810,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1820,     0,   481,
    1823,  1732,     0,     0,  1825,     0,     0,     0,     0,     0,
       0,     0,     0,  1768,  1769,     0,  1834,     0,     0,     0,
       0,     0,     0,     0,  1839,     0,     0,     0,     0,     0,
       0,     0,     0,  1921,     0,   836,     0,     0,     0,     0,
    1852,     0,     0,     0,     0,  1858,  1859,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1864,
       0,     0,  1865,  1864,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   884,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1888,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1898,     0,     0,     0,     0,     0,
       0,     0,     0,  1907,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,     0,  1822,     0,     0,  1824,
       0,  1918,  1919,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,   481,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,  2013,  1943,
    1944,     0,   569,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1956,     0,
       0,   480,   480,  1961,     0,     0,     0,     0,  1964,     0,
       0,  1966,     0,     0,  1933,     0,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,  1992,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  2003,     0,
       0,     0,     0,     0,  2008,     0,     0,  2009,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2032,     0,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,     0,  1103,
    1104,  1105,  1106,     0,  1108,  1109,  1110,  1111,     0,     0,
    2050,  2051,   157,     0,   162,     0,     0,     0,  1121,     0,
    1123,     0,     0,     0,  2057,  2058,     0,  2059,  1130,     0,
       0,     0,     0,     0,     0,  1136,  1137,     0,     0,     0,
    2067,     0,     0,     0,  1148,   480,   480,   480,   480,   480,
       0,     0,     0,  2044,     0,  1858,     0,     0,     0,  2083,
       0,     0,     0,     0,     0,     0,     0,  1744,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,  2103,     0,  2090,     0,
     569,  2106,  2107,  2108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,   425,   569,     0,     0,
       0,     0,  2136,  2137,  2138,     0,     0,     0,     0,     0,
       0,   481,   481,     0,     0,     0,     0,     0,     0,     0,
       0,  1238,  1240,  1241,     0,     0,     0,  1245,  1246,     0,
       0,  1249,  1250,  1251,  1252,     0,  1254,     0,     0,     0,
     481,  1260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   512,   513,   514,   515,   516,   517,     0,
     519,   520,     0,     0,     0,     0,     0,   523,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
     533,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1342,     0,     0,     0,     0,  1347,     0,     0,     0,
       0,     0,     0,  2132,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,  2148,  2150,   569,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2158,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1402,     0,     0,   658,   659,   660,     0,     0,     0,
     664,   665,   666,   667,   668,   669,   670,     0,   671,     0,
       0,     0,   672,   673,     0,     0,   676,     0,     0,     0,
       0,     0,     0,     0,     0,  1873,   550,     0,     0,   688,
       0,   481,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,     0,     0,   194,
     152,   362,     0,     0,     0,     0,   195,   196,   197,     0,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   398,   216,
     217,   218,   219,   220,   221,   956,     0,     0,     0,     0,
       0,     0,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   227,   228,   229,   230,   372,   373,   374,   375,   231,
    1513,     0,     0,   376,   377,   378,     0,  1151,   379,     0,
     380,   233,   234,   235,     0,     0,     0,     0,   236,    20,
     381,   237,     0,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1549,     0,
       0,     0,     0,     0,     0,     0,     0,   853,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,   481,   481,   481,   481,
    1586,  1587,  1588,  1589,  1590,     0,     0,     0,     0,  1595,
    1596,     0,     0,  1598,     0,  1600,     0,     0,     0,  1604,
       0,     0,  1606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1614,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   789,   565,
     566,   567,   568,     0,   481,     0,     0,   569,     0,   247,
     383,   384,   385,   248,     0,     0,     0,     0,   250,   251,
     252,   386,   253,   254,   255,   387,     0,   388,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   399,     0,     0,     0,     0,
       0,   258,     0,  1672,     0,  1675,   343,     0,     0,  1682,
    1546,  1684,     0,   261,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,  1709,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,   194,     6,   362,   569,     0,
       0,     0,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,  1550,   364,
     365,   366,   367,   368,   369,   370,   371,   227,   228,   229,
     230,   372,   373,   374,   375,   231,   232,     0,     0,   376,
     377,   378,     0,     0,   379,     0,   380,   233,   234,   235,
       0,  1770,     0,     0,   236,    20,   381,   237,     0,   382,
       0,     0,     0,   238,     0,     0,   239,  1152,     0,   240,
       0,   241,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,  1143,
       0,     0,   243,     0,    51,     0,   244,     0,   245,     0,
       0,   246,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,  1160,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,  1849,     0,     0,  1850,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   383,   384,   385,   248,
     249,     0,     0,     0,   250,   251,   252,   386,   253,   254,
     255,   387,     0,   388,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   257,  1880,  1881,     0,  1883,     0,   258,     0,     0,
       0,     0,   343,     0,     0,     0,  1551,     0,     0,   261,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,     0,   729,
      50,     0,    52,   730,  1465,   731,   732,     0,   733,     0,
       0,     0,     0,     0,  1924,  1925,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,  1337,     0,     0,   569,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1955,   194,     6,   362,     0,     0,     0,     0,   195,
     196,   197,     0,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,     0,     0,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   227,   228,   229,   230,   372,   373,
     374,   375,   231,   232,   916,     0,   376,   377,   378,     0,
       0,   379,     0,   380,   233,   234,   235,     0,  1391,     0,
       0,   236,    20,   381,   237,     0,   382,     0,     0,     0,
     238,     0,     0,   239,     0,     0,   240,     0,   241,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,    51,     0,   244,     0,   245,     0,     0,   246,     0,
       0,     0,     0,    61,    62,    63,    64,    65,     0,     0,
      67,    68,    69,    70,    71,     0,     0,     0,    75,     0,
       0,    78,     0,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   383,   384,   385,   248,   249,     0,     0,
       0,   250,   251,   252,   386,   253,   254,   255,   387,     0,
     388,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,     0,
       0,  1514,  1515,     0,   258,     0,     0,     0,  2125,   343,
     194,   152,   362,   260,   411,  1409,   261,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   398,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   227,   228,   229,   230,   372,   373,   374,   375,
     231,     0,     7,     8,   376,   377,   378,     0,     0,   379,
       0,   380,   233,   234,   235,     0,     0,  1602,     0,   236,
      20,   381,   237,     0,   382,     0,     0,  1610,     0,     0,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,     0,   412,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,     0,   729,
      50,     0,    52,   730,     0,   731,   732,     0,   733,     0,
       0,     0,     0,   413,     0,     0,     0,     0,     0,     0,
     247,   383,   384,   385,   248,    72,     0,     0,     0,   250,
     251,   252,   386,   253,   254,   255,   387,     0,   388,   109,
     414,   415,   416,   417,     0,     0,     0,     0,     0,    86,
      87,    88,     0,     0,     0,   256,   399,     0,     0,     0,
       0,     0,   258,     0,   418,   419,     0,   420,     0,   421,
       0,  1741,     0,   422,   261,   194,     6,   342,     0,     0,
       0,     0,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,     0,     0,     0,   938,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,   236,    20,     0,   237,     0,     0,
       0,     0,     0,   238,     0,     0,   239,     0,     0,   240,
       0,   241,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    51,     0,   244,     0,   245,     0,
       0,   246,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,   716,
       0,   717,     0,     0,     0,     0,     0,  1674,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,   248,
     249,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   257,     0,     0,     0,     0,     0,   258,     0,     0,
       0,     0,   343,   194,     6,     0,   344,     0,   644,   261,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,     0,     0,     0,     0,
       0,   238,     0,     0,   239,     0,     0,   240,     0,   241,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,    51,     0,   244,     0,   245,     0,     0,   246,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
       0,     0,    78,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,   947,     0,     0,
       0,     0,     0,     0,     0,   908,     0,     0,     0,     0,
       0,     0,     0,   247,     0,     0,     0,   248,   249,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   479,
       0,     0,     0,     0,     0,   258,     0,     0,     0,     0,
     343,   194,     6,  1646,     0,   543,     0,   261,   195,   196,
     197,     0,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,   230,     0,     0,     0,
       0,   231,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,     0,
     236,    20,     0,   237,     0,     0,     0,     0,     0,   238,
       0,     0,   239,     0,     0,   240,     0,   241,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
      51,     0,   244,     0,   245,     0,     0,   246,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,    67,
      68,    69,    70,    71,     0,     0,     0,    75,     0,     0,
      78,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,  1787,
       0,     0,     0,  1788,     0,     0,     0,     0,     0,     0,
       0,   247,     0,     0,     0,   248,   249,     0,     0,     0,
     250,   251,   252,     0,   253,   254,   255,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   257,     0,     0,
       0,     0,     0,   258,     0,     0,     0,     0,   343,   194,
       6,     0,   260,     0,     0,   261,   195,   196,   197,     0,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,     0,     0,     0,     0,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   234,   235,     0,     0,     0,     0,   236,    20,
       0,   237,     0,     0,     0,     0,     0,   238,     0,     0,
     239,     0,     0,   240,     0,   241,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,    51,     0,
     244,     0,   245,     0,     0,   246,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,  1814,     0,     0,
       0,  1815,     0,     0,     0,     0,     0,     0,     0,   247,
       0,     0,     0,   248,   249,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   608,  1806,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   610,   194,     6,     0,
     305,   543,     0,   261,   195,   196,   197,     0,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,   230,     0,     0,     0,     0,   231,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,     0,     0,     0,   236,    20,     0,   237,
       0,     0,     0,     0,     0,   238,     0,     0,   239,     0,
       0,   240,     0,   241,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,    51,     0,   244,     0,
     245,     0,     0,   246,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,  1978,     0,     0,     0,  1979,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,   248,   249,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   257,     0,     0,     0,     0,     0,   258,
       0,     0,     0,     0,   259,   194,     6,     0,   260,     0,
       0,   261,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,   236,    20,     0,   237,     0,     0,
       0,     0,     0,   238,     0,     0,   239,     0,     0,   240,
       0,   241,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    51,     0,   244,     0,   245,     0,
       0,   246,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   746,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,   248,
     249,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   257,     0,     0,     0,     0,     0,   258,     0,     0,
       0,     0,   343,   194,     6,     0,   260,     0,     0,   261,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,     0,     0,     0,     0,
       0,   238,     0,     0,   239,     0,     0,   240,     0,   241,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,    51,     0,   244,     0,   245,     0,     0,   246,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
       0,     0,    78,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   908,     0,     0,     0,     0,
       0,     0,     0,   247,     0,     0,     0,   248,   249,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   479,
       0,     0,     0,     0,     0,   258,     0,     0,     0,     0,
     343,   194,     6,     0,   538,     0,     0,   261,   195,   196,
     197,     0,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,   230,     0,     0,     0,
       0,   231,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,     0,
     236,    20,     0,   237,     0,     0,     0,     0,     0,   238,
       0,     0,   239,     0,     0,   240,     0,   241,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
      51,     0,   244,     0,   245,     0,     0,   246,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,    67,
      68,    69,    70,    71,     0,     0,     0,    75,     0,     0,
      78,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   909,     0,     0,     0,     0,     0,     0,
       0,   247,     0,     0,     0,   248,   249,     0,     0,     0,
     250,   251,   252,     0,   253,   254,   255,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   479,     0,     0,
       0,     0,     0,   258,     0,     0,     0,     0,   343,   194,
       6,     0,     0,   543,     0,   261,   195,   196,   197,     0,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,     0,     0,     0,     0,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   234,   235,     0,     0,     0,     0,   236,    20,
       0,   237,     0,     0,     0,     0,     0,   238,     0,     0,
     239,     0,     0,   240,     0,   241,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,    51,     0,
     244,     0,   245,     0,     0,   246,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   953,     0,     0,     0,     0,     0,     0,     0,   247,
       0,     0,     0,   248,   249,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   580,   194,     6,     0,
     260,     0,     0,   261,   195,   196,   197,     0,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,   230,     0,     0,     0,     0,   231,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,     0,     0,     0,   236,    20,     0,   237,
       0,     0,     0,     0,     0,   238,     0,     0,   239,     0,
       0,   240,     0,   241,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,    51,     0,   244,     0,
     245,     0,     0,   246,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1061,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,   248,   249,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   257,     0,     0,     0,     0,     0,   258,
       0,     0,     0,     0,   587,   194,     6,     0,   260,     0,
       0,   261,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,   236,    20,     0,   237,     0,     0,
       0,     0,     0,   238,     0,     0,   239,     0,     0,   240,
       0,   241,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    51,     0,   244,     0,   245,     0,
       0,   246,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1062,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,   248,
     249,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   479,     0,     0,     0,     0,     0,   258,     0,     0,
       0,     0,   343,   194,     6,     0,   870,     0,  1324,   261,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,     0,     0,     0,     0,
       0,   238,     0,     0,   239,     0,     0,   240,     0,   241,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
     242,     0,   152,   362,     0,     0,     0,     0,     0,     0,
     243,     0,    51,     0,   244,     0,   245,     0,     0,   246,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
       0,     0,    78,     0,   363,   364,   365,   366,   367,   368,
     369,   370,   371,     0,     0,     0,     0,   372,   373,   374,
     375,     0,     0,     0,     0,   376,   377,   378,     0,     0,
     379,     0,   380,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,   247,     0,   382,     0,   248,   249,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   479,
       0,     0,     0,     0,     0,   258,   194,     6,     0,     0,
     343,  1530,     0,   195,   196,   197,     0,   261,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,   230,     0,     0,     0,     0,   231,   232,     0,     0,
       0,     0,   383,   384,   385,     0,     0,     0,   233,   234,
     235,     0,     0,   386,     0,   236,    20,   387,   237,   388,
     109,     0,     0,     0,   238,     0,     0,   239,     0,     0,
     240,     0,   241,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,   242,     0,   392,   362,     0,     0,     0,
       0,     0,     0,   243,     0,    51,     0,   244,     0,   245,
       0,     0,   246,     0,     0,     0,     0,    61,    62,    63,
      64,    65,     0,     0,    67,    68,    69,    70,    71,     0,
       0,     0,    75,     0,     0,    78,     0,   363,   364,   365,
     366,   367,   368,   369,   370,   371,     0,     0,     0,     0,
     372,   373,   374,   375,     0,     0,     0,     0,   376,   377,
     378,     0,     0,   379,     0,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   381,   247,     0,   382,     0,
     248,   249,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   479,     0,     0,     0,     0,     0,   258,   194,
       6,     0,     0,   343,     0,     0,   195,   196,   197,     0,
     261,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,     0,     0,     0,     0,   231,
     232,     0,     0,     0,     0,   383,   384,   385,     0,     0,
       0,   233,   234,   235,     0,     0,   386,     0,   236,    20,
     387,   237,   388,     0,     0,     0,     0,   238,     0,     0,
     239,     0,     0,   240,     0,   241,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,    51,     0,
     244,     0,   245,     0,     0,   246,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1063,     0,     0,     0,     0,     0,     0,     0,   247,
       0,     0,     0,   248,   249,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   343,   194,     6,     0,
    1654,     0,     0,   261,   195,   196,   197,     0,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,   230,     0,     0,     0,     0,   231,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,     0,     0,     0,   236,    20,     0,   237,
       0,     0,     0,     0,     0,   238,     0,     0,   239,     0,
       0,   240,     0,   241,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,    51,     0,   244,     0,
     245,     0,     0,   246,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1064,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,   248,   249,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   608,  1806,     0,     0,     0,     0,     0,   258,
       0,     0,     0,     0,   610,   194,     6,     0,   305,     0,
       0,   261,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,   236,    20,     0,   237,     0,     0,
       0,     0,     0,   238,     0,     0,   239,     0,     0,   240,
       0,   241,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    51,     0,   244,     0,   245,     0,
       0,   246,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,   248,
     249,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   479,     0,     0,     0,     0,     0,   258,   194,   152,
     362,     0,   343,     0,     0,   195,   196,   197,     0,   261,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   398,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     227,   228,   229,   230,   372,   373,   374,   375,   231,     0,
       0,     0,   376,   377,   378,     0,     0,   379,     0,   380,
     233,   234,   235,     0,     0,     0,     0,   236,    20,   381,
     237,     0,   382,   194,   152,   362,     0,     0,     0,     0,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   398,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,  1550,   364,   365,   366,
     367,   368,   369,   370,   371,   227,   228,   229,   230,   372,
     373,   374,   375,   231,     0,     0,     0,   376,   377,   378,
       0,     0,   379,     0,   380,   233,   234,   235,     0,     0,
       0,     0,   236,    20,   381,   237,     0,   382,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   383,
     384,   385,   248,     0,     0,     0,     0,   250,   251,   252,
     386,   253,   254,   255,   387,     0,   388,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,   399,     0,     0,     0,     0,     0,
     258,     0,     0,     0,     0,   343,     0,     0,     0,  1819,
       0,     0,   261,     0,     0,     0,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,   247,   383,   384,   385,   248,  1112,     0,
       0,     0,   250,   251,   252,   386,   253,   254,   255,   387,
       0,   388,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   399,
       0,     0,     0,     0,     0,   258,     0,     0,     0,     0,
     343,   194,   152,   362,  1708,     0,     0,   261,   195,   196,
     197,     0,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     398,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   227,   228,   229,   230,   372,   373,   374,
     375,   231,     0,     0,     0,   376,   377,   378,     0,     0,
     379,     0,   380,   233,   234,   235,     0,     0,     0,     0,
     236,    20,   381,   237,     0,   382,   194,   152,     0,     0,
       0,     0,     0,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   398,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,   230,     0,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,     0,     0,     0,   236,    20,     0,   237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   383,   384,   385,   248,     0,     0,     0,     0,
     250,   251,   252,   386,   253,   254,   255,   387,     0,   388,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   399,     0,     0,
       0,     0,     0,   258,     0,     0,     0,     0,   343,     0,
       0,     0,     0,     0,     0,   261,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,     0,     0,   247,     0,  1113,     0,
     248,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   399,     0,     0,     0,     0,     0,   258,     0,
       0,     0,     0,   343,   194,   152,     0,   590,     0,     0,
     261,   195,   196,   197,     0,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   398,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,   230,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,     0,
     194,   152,     0,   236,    20,   838,   237,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   398,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,   230,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,     0,     0,     0,     0,   236,
      20,     0,   237,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,   247,  1114,     0,     0,   248,     0,
       0,     0,     0,   250,   251,   252,     0,   253,   254,   255,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   608,
     609,     0,     0,     0,     0,     0,   258,     0,     0,     0,
       0,   610,     0,     0,     0,   305,     0,     0,   261,     0,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
     247,     0,   569,     0,   248,     0,     0,     0,     0,   250,
     251,   252,  1119,   253,   254,   255,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   399,     0,     0,     0,
       0,     0,   258,   194,   152,     0,     0,   343,     0,     0,
     195,   196,   197,     0,   261,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   398,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,   194,   152,     0,  1274,
       0,     0,     0,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   398,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,   230,     0,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,     0,     0,     0,   236,    20,     0,   237,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   247,     0,     0,     0,   248,     0,     0,
       0,  1120,   250,   251,   252,     0,   253,   254,   255,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   399,
       0,     0,     0,     0,     0,   258,     0,     0,     0,     0,
     343,  1051,     0,     0,     0,     0,     0,   261,     0,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,   247,     0,     0,     0,
     248,  1122,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   399,     0,     0,     0,     0,     0,   258,   194,
     152,     0,  1427,   343,     0,     0,   195,   196,   197,     0,
     261,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   398,   216,
     217,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,     0,     0,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   234,   235,     0,     0,     0,     0,   236,    20,
       0,   237,   194,   152,     0,  1489,     0,     0,     0,   195,
     196,   197,     0,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   398,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,   230,     0,     0,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,     0,     0,     0,
       0,   236,    20,     0,   237,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,   247,
       0,     0,     0,   248,     0,     0,     0,  1227,   250,   251,
     252,     0,   253,   254,   255,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   399,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   343,     0,     0,     0,
       0,     0,     0,   261,     0,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,   247,     0,     0,     0,   248,  1248,     0,     0,
       0,   250,   251,   252,     0,   253,   254,   255,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   399,     0,
       0,     0,     0,     0,   258,   194,   152,     0,     0,   343,
       0,     0,   195,   196,   197,     0,   261,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   398,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,   194,   152,     0,   236,    20,     0,   237,   195,   196,
     197,     0,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     398,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,   230,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,     0,
     236,    20,     0,   237,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,   247,  1333,     0,     0,   248,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   399,     0,     0,     0,     0,     0,   258,     0,     0,
       0,     0,   343,  1545,     0,     0,     0,     0,     0,   261,
       0,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,   247,     0,   569,     0,   248,     0,     0,     0,     0,
     250,   251,   252,  1421,   253,   254,   255,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   399,     0,     0,
       0,     0,     0,   258,   194,   152,     0,     0,   343,  1866,
       0,   195,   196,   197,     0,   261,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   398,   216,   217,   218,   219,   220,   221,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,   230,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,     0,
       0,     0,     0,   236,    20,     0,   237,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1422,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,     0,   729,
      50,     0,    52,   730,     0,   731,   732,     0,   733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,   248,    86,
      87,    88,     0,   250,   251,   252,     0,   253,   254,   255,
       0,     7,     8,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     399,     0,     0,     0,     0,     0,   258,     0,     0,     0,
       0,   343,     0,     0,     0,     0,     0,     0,   261,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,     0,     0,   985,     0,     0,     0,   729,    50,
       0,    52,   730,     0,   731,   732,     0,   733,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     7,     8,    72,    38,    39,    40,    41,     0,
       0,    43,     0,     0,     0,     0,     0,     0,   729,    50,
       0,    52,   730,     0,   731,   732,     0,   733,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    72,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,    86,    87,
      88,     0,     0,     0,     0,     0,     0,  1464,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,   987,     0,     0,     0,     0,     0,   729,
      50,     0,    52,   730,     0,   731,   732,     0,   733,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     7,     8,    72,    38,    39,    40,    41,
       0,     0,    43,  1181,     0,     0,     0,     0,     0,   729,
      50,     0,    52,   730,     0,   731,   732,     0,   733,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    72,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,    86,
      87,    88,     0,     0,     0,     0,     0,     0,  1591,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,  1183,     0,     0,     0,     0,     0,
     729,    50,     0,    52,   730,     0,   731,   732,     0,   733,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     7,     8,    72,    38,    39,    40,
      41,     0,     0,    43,  1184,     0,     0,     0,     0,     0,
     729,    50,     0,    52,   730,     0,   731,   732,     0,   733,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,    72,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
      86,    87,    88,     0,     0,     0,     0,     0,     0,  1592,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,    41,     0,     0,    43,  1203,     0,     0,     0,     0,
       0,   729,    50,     0,    52,   730,     0,   731,   732,     0,
     733,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     7,     8,    72,    38,    39,
      40,    41,     0,     0,    43,  1233,     0,     0,     0,     0,
       0,   729,    50,     0,    52,   730,     0,   731,   732,     0,
     733,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    72,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,    86,    87,    88,     0,     0,     0,     0,     0,     0,
    1593,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,    41,     0,     0,    43,  1266,     0,     0,     0,
       0,     0,   729,    50,     0,    52,   730,     0,   731,   732,
       0,   733,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,    72,    38,
      39,    40,    41,     0,     0,    43,  1419,     0,     0,     0,
       0,     0,   729,    50,     0,    52,   730,     0,   731,   732,
       0,   733,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,     1,     0,     0,    -4,
       0,     0,    86,    87,    88,     0,     0,     0,    -4,    -4,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,     0,  2035,     0,    -4,
      -4,     0,  1607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,     0,    -4,    -4,  2092,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     6,     0,    -4,    -4,    -4,     0,     0,     0,    -4,
       7,     8,     0,     0,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,     9,    10,     0,    -4,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,     0,    -4,     0,     0,
       0,    11,    12,    13,     0,     0,     0,    14,    15,     0,
      16,     0,     0,     0,     0,    17,     0,    18,    19,     0,
      20,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,    37,    38,    39,    40,    41,    42,     0,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    81,    82,    83,     0,     0,
       0,    84,     0,     0,     0,     0,    85,    86,    87,    88,
     362,     0,    89,     0,    90,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       7,     8,     0,     0,     0,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,   109,
       0,   363,   364,   365,   366,   367,   368,   369,   370,   371,
       0,     0,     0,     0,   372,   373,   374,   375,     0,     0,
       0,     0,   376,   377,   378,     0,     0,   379,     0,   380,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   381,
       0,     0,   382,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,    41,     0,     0,
      43,     0,     0,     0,     0,     0,     0,   729,    50,     0,
      52,   730,     0,   731,   732,     0,   733,     7,     8,     0,
     996,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,   997,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,    86,    87,    88,
     569,     0,     0,     0,     0,     0,   786,     0,     0,   383,
     384,   385,     0,     0,     0,     0,     0,     0,     0,     0,
     386,     0,     0,     0,   387,     0,   388,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,     0,     0,
       0,     0,     0,     0,   729,    50,     0,    52,   730,     0,
     731,   732,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,    86,    87,    88,     0,     0,     0,
       0,     0,     0,  1736,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1853,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1854,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1882,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1885,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1951,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2004,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2005,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2019,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2021,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2053,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2080,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2085,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2086,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2087,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2126,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,  1033,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,     0,     0,  1089,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,  1132,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,  1133,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,  1175,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,  1206,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,  1224,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
    1280,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,  1380,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,     0,     0,  1423,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,  1495,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,     0,     0,  1496,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,  1497,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,  1498,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,  1785,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,  1796,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,  1833,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
    1901,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,  1916,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,     0,     0,  1928,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,  1967,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,     0,     0,  1984,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,  1993,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,  1994,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,  2017,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,  2066,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,  2105,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
    2124,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,  2144,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,     0,     0,  2145,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,  2146,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,     0,   691,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,     0,   900,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
       0,  1894,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,   716,     0,   717,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,   959,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,  1010,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,  1156,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,  1219,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,  1220,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,     0,     0,
    1225,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   690,   565,   566,   567,   568,     0,
       0,     0,     0,   569,     0,     0,     0,  1226,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   690,   565,   566,   567,   568,     0,     0,     0,     0,
     569,     0,     0,     0,  1316,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   690,   565,
     566,   567,   568,     0,     0,     0,     0,   569,     0,     0,
       0,  1330,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   690,   565,   566,   567,   568,
       0,     0,     0,     0,   569,     0,     0,     0,  1527,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,     0,     0,  1613,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   690,
     565,   566,   567,   568,     0,     0,     0,     0,   569,     0,
       0,     0,  1660,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   690,   565,   566,   567,
     568,     0,     0,     0,     0,   569,     0,     0,     0,  1845,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   690,   565,   566,   567,   568,     0,     0,
       0,     0,   569,     0,     0,     0,  1887,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     690,   565,   566,   567,   568,     0,     0,     0,     0,   569,
       0,     0,     0,  1902,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   767,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   768,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   769,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   771,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   772,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   773,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   775,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   776,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   777,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   778,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   779,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   780,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   781,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   783,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   784,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   785,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   850,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   885,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   929,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   947,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   949,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   950,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   951,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   957,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,   958,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,   995,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1009,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1069,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1073,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1085,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1155,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1164,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1165,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1166,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1176,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1205,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1207,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1208,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1209,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1210,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1211,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1212,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1213,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1218,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1315,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1329,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1528,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1558,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1559,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1560,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1561,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1599,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1612,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1723,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1725,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1728,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1735,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1786,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1795,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1818,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1886,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  1949,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  1950,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569,     0,  2079,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   690,   565,   566,
     567,   568,     0,     0,     0,     0,   569,     0,  2121,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   690,   565,   566,   567,   568,     0,     0,     0,
       0,   569
};

static const yytype_int16 yycheck[] =
{
       3,     3,     3,   298,   100,  1204,   102,   605,   606,  1200,
     711,    56,   135,  1691,  1386,  1693,     4,    20,   719,  1648,
       4,     4,    49,    20,   148,     6,  1867,     6,     4,     7,
       4,     4,  1678,     4,     6,     4,     6,     4,     4,   135,
       4,   310,    97,     6,     5,   130,    49,     6,     4,     4,
       4,    91,     5,     9,    55,     5,   244,     5,   130,   328,
     248,   157,     7,   183,     4,   120,     6,     4,     6,     0,
     110,   191,   241,    76,     9,   147,     4,    97,   240,   150,
     249,    84,   244,   155,   156,   157,    89,   228,   229,   161,
     162,     7,   130,   178,   241,  1741,     6,   100,   228,   229,
     120,     6,   249,     9,   175,   241,   228,   229,   249,   147,
     695,    14,     7,   249,    83,   245,     6,   155,   156,   157,
     191,   192,    97,   161,   162,   241,   395,   249,   397,   228,
     229,  1760,   135,   249,   136,     9,   405,   140,   141,     8,
     240,   726,     9,   237,   238,   148,   100,   101,   228,   229,
     249,    91,   246,    94,    62,    63,    97,    65,   743,   162,
     280,   281,   282,   228,   229,   192,   751,   246,     6,   249,
     249,  2012,   240,   245,   242,   178,   228,   229,   246,     9,
     183,   249,   240,   186,   249,   228,   229,   241,   191,   192,
     193,   165,   166,   167,   168,   249,     9,   249,   228,   229,
     163,   321,   322,   323,   163,   241,   249,   245,   240,   175,
     176,   175,   176,   249,   228,   229,   243,   186,   338,   249,
       6,   228,   229,   190,   212,   241,   240,   243,   212,   212,
     244,   232,  1604,   249,     7,   213,   214,   215,   216,   212,
     243,   212,   249,   212,   245,   246,     8,   241,  1439,   228,
     229,   240,   279,   242,   257,   249,   212,   260,   261,   247,
     244,   244,  1891,   244,   261,   292,   242,   852,   241,   296,
     243,   245,   248,   276,   244,   244,   279,   280,   281,   282,
       6,   237,   238,   244,   240,   240,   242,     6,   244,   292,
     246,   244,   244,   296,   244,   298,   244,   213,   214,   215,
     216,   246,   240,   240,     4,   240,   244,   242,  1009,  1010,
       6,   246,   240,   223,   224,   411,  1945,     6,   321,   322,
     323,   237,   238,   228,   229,   594,   240,   596,   597,   240,
     246,   237,   238,   244,   240,   338,   242,   243,   228,   229,
     246,   344,     7,   242,   613,   240,   242,   242,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   240,   245,   242,  2047,
     239,   249,   246,   240,   240,   242,   245,   228,   229,    94,
     407,   408,    97,   652,     7,   223,   224,     4,     7,   241,
     240,   243,   244,   301,   302,   110,   423,   521,   249,   402,
     403,   309,   310,   240,   407,   408,   241,   237,   238,   529,
     240,   246,   242,   241,   240,   243,   246,   228,   229,   186,
     423,   249,   691,   240,   237,   238,   429,   240,   240,   242,
     228,   229,   433,   246,   134,   135,   136,   137,   249,   535,
     213,   214,   215,   216,   233,   234,   241,   450,   243,   149,
     239,   249,   152,  2082,   249,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    97,    91,    99,   479,   239,    95,   228,
     229,   228,   229,   245,   101,   102,   240,   104,   105,   228,
     229,   518,   228,   229,   240,   244,   242,   240,   228,   229,
     503,   528,   249,   530,   112,  2134,   123,   510,   511,   276,
     249,  1883,   515,   249,   517,   518,   519,   520,   521,   249,
     245,   524,   228,   229,   249,   528,   529,   530,   531,   532,
     533,   534,   246,   536,   248,   538,   660,   534,   240,   536,
     242,   228,   229,   249,   228,   229,   240,   249,   213,   214,
     215,   216,    91,   130,  1139,    94,  1141,   243,    97,   240,
      99,   564,   249,   249,   240,   249,   241,   570,   243,  1154,
     147,   110,   237,   238,   249,   237,   238,   673,   155,   156,
     157,   228,   229,   243,   161,   162,   589,   590,   711,   249,
     213,   214,   215,   216,   213,   214,   215,   216,   240,   228,
     229,   240,   249,   605,   606,    91,   228,   229,    94,   245,
     611,    97,   130,   249,   237,   238,   237,   238,   237,   238,
     249,   237,   238,   244,   110,   228,   229,   249,   244,   147,
       8,   632,   635,   636,   637,   904,   403,   155,   156,   157,
     240,   244,    94,   161,   162,    97,    91,    99,    94,    94,
      97,    97,    97,    99,    99,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   110,   668,   669,   670,   671,   672,
     766,   674,   675,   676,   677,   678,  1261,   130,   681,     6,
     677,   708,  1267,   684,   244,    91,   687,   732,    94,   692,
     241,    97,   243,    99,   147,   603,   604,   240,   699,   242,
     608,   244,   155,   156,   157,   708,   228,   229,   161,   162,
     245,  1412,   228,   229,   249,   718,    99,   241,   240,   243,
     723,   241,   244,   243,   244,   249,    94,   245,   244,  1314,
     731,   245,   733,   134,   135,   249,   739,   740,   240,   140,
     245,   240,   745,  1328,   249,   748,   749,   244,   240,  1334,
     242,   754,   244,   756,     4,   240,     6,   242,   881,   228,
     229,   230,   231,   232,   233,   234,   240,   240,   242,   242,
     239,   538,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    97,   789,   245,   791,   239,
     244,   249,   245,   230,   231,   232,   233,   234,   894,   240,
    1501,   245,   239,   134,   135,   249,   245,   245,   244,   140,
     249,   249,  1513,   245,   245,   245,   245,   249,   249,   249,
     249,   824,   589,   590,   245,   245,   245,   245,   249,   249,
     249,   249,   245,   240,   245,   242,   249,  2036,   249,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    94,   245,     6,
       7,   239,   249,   241,   891,   243,    94,   870,   635,   636,
     637,   245,   245,   240,   245,   249,   249,  2068,   249,   245,
     883,   245,    97,   249,    97,   249,  1009,  1010,   891,   245,
       4,   245,   245,   249,  2093,   249,   249,   900,     4,     4,
       5,     4,   903,   245,   905,   906,   245,   249,   245,   245,
     249,     4,   249,   249,   681,  1011,     6,     7,   919,   240,
    2111,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   228,   229,   240,   240,
     239,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     240,   718,     8,   954,    59,    60,    61,    62,   240,     6,
       6,   245,    67,    68,    69,   249,   245,    72,   244,    74,
     249,   245,   739,   245,  1001,   249,   245,   249,   745,    84,
     249,   245,    87,   245,   245,   249,   245,   249,   249,   990,
     249,   245,   245,  1020,   242,   249,   249,   240,  1001,   907,
     245,  1296,     6,   245,   249,   245,   914,   249,   244,   249,
     918,   245,  1015,   248,   245,   249,   245,  1020,   249,   242,
     249,   126,     6,   248,   240,   244,     9,   178,   240,  1032,
     240,   240,  1155,  1156,  1037,  1633,  1634,   240,   240,   240,
    1067,  1068,   240,  1070,  1071,  1072,   240,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,   824,   240,   178,
     178,   244,   120,   240,  1067,  1068,     8,  1070,  1071,  1072,
     240,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,   240,   240,  1086,   178,   240,   240,   244,   244,   194,
     195,   196,   244,     4,   244,   244,   244,  1124,   240,   240,
     205,   240,   240,   870,   209,   240,   211,   212,   240,   240,
     240,     6,     6,   242,     6,     6,   883,   244,   244,  1146,
     244,  1124,  1125,  1126,   244,   242,   242,   242,     6,   178,
     240,   244,   240,   900,     6,  1162,   241,     6,   243,   244,
     240,   240,     6,  1146,   240,   240,   244,     6,     8,     6,
     242,     6,     8,   244,     7,   244,     6,   244,  1066,  1162,
    1163,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   245,
      86,  1182,   249,   239,   249,   241,   241,  1214,     7,     6,
       6,   241,  1315,  1316,   246,   239,   244,    64,     8,   244,
       4,  1228,  1229,  1230,     7,     7,   240,     6,   241,     6,
       6,  1214,   244,  1508,     7,     7,     6,     6,   245,  1488,
     175,   244,   241,  1492,   245,  1228,  1229,  1230,   245,   243,
       6,   244,   244,   244,   244,     7,  1239,   246,     6,   242,
    1336,  1244,  1338,   240,   244,  1248,     4,     6,   241,     6,
    1277,     6,     6,   242,  1257,     7,  1259,     7,     7,  1262,
       7,     7,     7,     7,     7,  1032,     7,     7,     7,     7,
    1271,     7,     7,     7,  1277,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,  1296,     7,   244,     6,   239,   241,  1897,
       7,   249,   243,   249,   249,   245,   241,   244,   246,   245,
     249,  1338,     7,  1316,   244,     4,     6,   246,  1321,  1086,
    1323,   245,   245,   130,  1351,     7,     6,   246,  1355,     7,
       7,     7,   241,   241,   249,  1338,   249,     9,   241,   249,
     178,   243,   246,   248,     7,   150,     6,   245,  1351,     6,
       6,   244,  1355,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     6,     4,    46,   240,   239,    46,     4,  1501,  1406,
    1407,  1408,   244,   246,     7,   246,   240,  1414,  1484,   240,
    1514,  1515,   244,   240,     7,     7,  1163,   246,   178,   241,
       7,   249,  1429,  1406,  1407,  1408,     7,     7,     6,   241,
    1705,  1414,   249,  1440,     7,     7,     7,     4,   109,     4,
       5,  1448,     4,   244,     7,     6,  1429,   240,     6,   244,
       7,     7,     7,     7,     7,     7,     7,  1440,     6,     6,
       6,     6,    97,     7,     6,  1448,     4,     4,  1451,   247,
    1546,     6,     6,   241,   249,   249,     6,   244,   244,   244,
       7,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     245,     6,  1239,   242,    59,    60,    61,    62,     6,   240,
     240,   244,    67,    68,    69,     6,     6,    72,  1611,    74,
     246,     6,   245,  1520,     6,   243,     6,     6,   249,    84,
       6,   123,    87,     6,     6,  1508,     6,     6,     6,     6,
       6,  1514,  1515,     6,     6,     6,     6,  1520,     5,  1546,
     241,   241,     6,     4,     6,     4,     6,   244,   244,     7,
    1438,   242,   244,  1629,     6,  1538,   244,     6,   244,   244,
     244,   126,   244,  1546,   244,   244,   244,     6,  1551,     6,
     244,     6,     6,   174,  1321,     6,  1323,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,  1671,     6,   241,   249,   239,
     249,   249,  1678,  1679,  1708,   244,     6,   249,   246,     7,
     240,   244,     4,     6,   245,  1622,     6,     6,  1721,     6,
     240,  1697,     4,   240,     7,     6,     6,     6,     6,   194,
     195,   196,     6,     6,     6,     6,     6,     5,    95,  1622,
     205,  1648,  1625,  1626,   209,   244,   211,   212,   244,   249,
     241,  1633,  1634,     6,     6,   249,  1663,  1906,     6,  1934,
       6,     6,     6,   249,   241,  1648,   249,     6,     4,     6,
     249,  1654,   237,   238,     6,   244,  1564,     6,     6,   244,
    1663,   246,     6,     6,   244,     7,     5,  1694,     6,     6,
    1673,     6,     6,  1676,   244,   244,     7,     6,   173,     6,
    1707,   244,   241,   244,  1451,   245,     6,     6,   244,     7,
    1691,  1694,  1693,   245,   245,   244,   241,   245,  1701,   245,
       6,     6,  1705,   246,  1707,  1708,     4,     5,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     6,   244,     6,  1998,
     239,     6,   245,  1760,     6,     6,  1832,   241,  1741,   244,
       6,  1649,  1650,  1651,  1652,  1653,  1654,   176,    46,    47,
      48,    49,    50,    51,    52,    53,    54,  1760,     6,   244,
       6,    59,    60,    61,    62,   240,     6,  1794,  2037,    67,
      68,    69,   245,   244,    72,   245,    74,  1873,   241,   244,
     244,     6,     6,   245,   130,     6,    84,     6,   244,    87,
       6,  1794,   244,   241,     6,     6,   245,     6,   245,     6,
       6,     6,     6,  1806,     6,     6,   244,     6,   244,     6,
       6,   244,     6,     6,     6,     6,  1819,     6,  1327,  2049,
    1381,   447,  1556,  1350,  1868,  1830,  1618,     3,   126,  1856,
       3,     3,     3,  1893,     3,  1481,  1701,  1678,  1515,    -1,
      -1,   748,  1869,    -1,    -1,    -1,    -1,   584,    -1,    -1,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,  1625,  1626,
      -1,    -1,    -1,    -1,  1891,    -1,  1869,    -1,    -1,    -1,
      -1,  1874,  1875,  1876,    -1,    -1,    -1,    -1,  1905,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1891,    -1,
      -1,  1894,    -1,    -1,    -1,  1897,   194,   195,   196,    -1,
      -1,    -1,  1905,    -1,    -1,    -1,  1909,   205,    -1,    -1,
      -1,   209,    -1,   211,   212,    -1,    -1,  2013,  1945,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1945,    -1,  1971,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1971,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,  1983,    -1,    -1,   139,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,  1910,  1911,  1912,  1913,  1914,    -1,    -1,   163,
     164,   165,    -1,   167,   168,   169,    -1,   171,   172,   173,
     174,   175,   176,   177,    -1,   179,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,  2039,  2040,  2041,  2042,
    2043,    -1,    -1,    -1,    -1,    -1,  2047,    -1,    -1,    -1,
      -1,    -1,  1819,    -1,    -1,  2082,    -1,    -1,    -1,    -1,
      -1,    -1,  1970,    -1,    -1,    -1,  1974,    -1,  2069,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2082,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2098,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,   260,  2134,  1875,  1876,
      -1,    -1,    -1,    -1,    -1,  2023,    -1,  2120,   135,  2027,
      -1,   275,   276,   140,   141,    -1,    -1,  1894,    -1,    -1,
      -1,  2134,    -1,    -1,    -1,  2043,    -1,    -1,  2141,  2142,
     294,    -1,  1909,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,   305,  2155,    -1,    -1,    -1,   310,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   320,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
    2088,  2089,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,
     344,    -1,    -1,    -1,   348,   349,   350,    -1,   352,    -1,
      -1,    -1,   356,   357,   358,    -1,    -1,   361,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,   399,    -1,    -1,    -1,   403,
     404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   420,   421,    -1,    -1,
      -1,    -1,  2039,  2040,  2041,  2042,  2043,    -1,    -1,    -1,
     434,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,   452,   453,
     454,   455,    67,    68,    69,    -1,   460,    72,    -1,    74,
     464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,   478,   479,    -1,    -1,    -1,   483,
      -1,  2098,    -1,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,    -1,   513,
     514,   126,   516,    -1,    -1,    -1,    -1,    -1,    -1,   523,
      -1,    -1,   526,   527,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,    -1,   538,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,    -1,   571,   572,    -1,
      -1,    -1,    -1,    -1,   578,   579,   580,    -1,    -1,   194,
     195,   196,   586,   587,    -1,   589,   590,    -1,    -1,    -1,
     205,    -1,    -1,    -1,   209,    -1,   211,   212,    -1,    -1,
      -1,    -1,    -1,    -1,   608,   609,   610,    -1,    -1,    -1,
     614,   615,   616,   617,   618,   619,   620,   621,   622,    -1,
       6,    -1,    -1,   627,    -1,   629,    -1,   631,    -1,    -1,
      -1,   635,   636,   637,   638,    -1,   640,   641,   642,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,    -1,
     517,    -1,   519,   520,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   667,   531,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   681,    -1,    -1,
      -1,    -1,    -1,    -1,   688,    -1,   690,    -1,    -1,   693,
     694,    -1,   186,    -1,    -1,    -1,    -1,    -1,   702,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   718,    -1,    -1,    -1,    -1,    -1,
     724,   725,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   739,    -1,   741,   742,    -1,
      -1,   745,   746,    -1,    -1,    -1,   750,    -1,    -1,    -1,
      -1,    -1,    -1,   757,    -1,    -1,    -1,   761,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   276,   787,    -1,   789,    -1,   791,    -1,    -1,
      -1,    -1,   659,    -1,   661,   662,   663,   664,   665,   666,
      -1,   668,   669,   670,   671,    -1,    -1,   674,   675,   676,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     834,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
     344,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   870,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   883,
      -1,   748,    -1,    -1,    -1,    -1,   890,    -1,    -1,   756,
     894,    -1,    -1,    -1,    -1,    -1,   900,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   908,   909,    -1,    -1,    -1,   403,
     914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   930,    -1,    -1,   933,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   953,
      -1,   955,   956,   239,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     974,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   997,    -1,    -1,    -1,    -1,    -1,    -1,
    1004,  1005,  1006,  1007,    -1,    -1,    -1,    -1,  1012,   503,
      -1,    -1,    -1,    -1,    -1,    -1,   510,   511,    -1,    -1,
      -1,    -1,  1026,  1027,    -1,    -1,    -1,    -1,  1032,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1061,  1062,  1063,
    1064,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1086,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   589,   590,    -1,  1102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1112,  1113,
    1114,    -1,    -1,    -1,    -1,  1119,  1120,    -1,  1122,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1134,  1135,    -1,    -1,    -1,    -1,    -1,    -1,  1142,  1143,
      -1,   635,   636,   637,    -1,  1149,     6,  1151,  1152,    -1,
      -1,    -1,    -1,    -1,  1158,  1159,    -1,    -1,    -1,  1163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1037,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   681,    -1,    -1,
    1194,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1227,   718,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1247,    -1,   739,    -1,    -1,    -1,    -1,
      -1,   745,    -1,    -1,    -1,    -1,    -1,    -1,  1125,  1126,
      -1,    -1,    -1,    -1,  1268,  1269,    -1,    -1,    -1,  1273,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1287,    -1,    -1,  1290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   789,    -1,   791,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,  1317,    -1,    -1,  1320,  1321,  1322,  1323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1331,    -1,  1333,
     824,  1335,  1336,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     6,    -1,    -1,    -1,   239,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,   870,  1244,    -1,   239,
      -1,  1248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   883,
    1257,    -1,  1259,    -1,    -1,  1262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   900,    -1,    -1,  1413,
      -1,    -1,    -1,    -1,    -1,    -1,  1420,  1421,  1422,    -1,
      -1,    -1,    -1,    -1,    -1,  1429,    -1,  1431,    -1,    -1,
      -1,    -1,    -1,    -1,  1438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1451,    -1,  1316,
      -1,    -1,  1456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1464,  1465,  1466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1486,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,  1512,    -1,
      -1,    -1,    -1,    -1,  1518,  1519,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,  1032,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,  1591,  1592,  1593,
      -1,    -1,  1086,    -1,    -1,    -1,    -1,    -1,  1602,    -1,
      -1,    -1,    -1,  1607,  1608,  1609,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1620,    -1,    -1,     6,
      -1,  1625,  1626,  1627,    -1,  1629,    -1,    -1,    -1,    -1,
      -1,  1635,  1636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1654,    -1,    -1,    -1,  1658,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1671,    -1,  1163,
    1674,  1538,    -1,    -1,  1678,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1687,  1688,    -1,  1690,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1698,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,   524,    -1,    -1,    -1,    -1,
    1714,    -1,    -1,    -1,    -1,  1719,  1720,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1733,
      -1,    -1,  1736,  1737,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   575,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1772,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1788,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1797,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1806,    -1,    -1,    -1,  1673,    -1,    -1,  1676,
      -1,  1815,  1816,    -1,    -1,  1819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1321,    -1,  1323,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     7,  1853,
    1854,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1872,    -1,
      -1,  1875,  1876,  1877,    -1,    -1,    -1,    -1,  1882,    -1,
      -1,  1885,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
    1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1909,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1917,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,  1942,    -1,
      -1,    -1,    -1,    -1,  1948,    -1,    -1,  1951,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1979,    -1,   796,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,    -1,   808,
     809,   810,   811,    -1,   813,   814,   815,   816,    -1,    -1,
    2004,  2005,    21,    -1,    23,    -1,    -1,    -1,   827,    -1,
     829,    -1,    -1,    -1,  2018,  2019,    -1,  2021,   837,    -1,
      -1,    -1,    -1,    -1,    -1,   844,   845,    -1,    -1,    -1,
    2034,    -1,    -1,    -1,   853,  2039,  2040,  2041,  2042,  2043,
      -1,    -1,    -1,     6,    -1,  2049,    -1,    -1,    -1,  2053,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1551,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,  2080,    -1,     6,    -1,
     239,  2085,  2086,  2087,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2098,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,   135,   239,    -1,    -1,
      -1,    -1,  2126,  2127,  2128,    -1,    -1,    -1,    -1,    -1,
      -1,  1625,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   960,   961,   962,    -1,    -1,    -1,   966,   967,    -1,
      -1,   970,   971,   972,   973,    -1,   975,    -1,    -1,    -1,
    1654,   980,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1060,    -1,    -1,    -1,    -1,  1065,    -1,    -1,    -1,
      -1,    -1,    -1,  2120,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,  2141,  2142,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2155,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,  1806,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1160,    -1,    -1,   363,   364,   365,    -1,    -1,    -1,
     369,   370,   371,   372,   373,   374,   375,    -1,   377,    -1,
      -1,    -1,   381,   382,    -1,    -1,   385,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     8,    -1,    -1,   398,
      -1,  1875,  1876,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1909,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    1299,    -1,    -1,    67,    68,    69,    -1,     8,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2039,  2040,  2041,  2042,  2043,
    1369,  1370,  1371,  1372,  1373,    -1,    -1,    -1,    -1,  1378,
    1379,    -1,    -1,  1382,    -1,  1384,    -1,    -1,    -1,  1388,
      -1,    -1,  1391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1403,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,  2098,    -1,    -1,   239,    -1,   193,
     194,   195,   196,   197,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,   211,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,  1472,    -1,  1474,   240,    -1,    -1,  1478,
     244,  1480,    -1,   247,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1514,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,     3,     4,     5,   239,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,  1610,    -1,    -1,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    94,     8,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   848,
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,    -1,   882,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1710,    -1,    -1,  1713,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,   197,
     198,    -1,    -1,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,   211,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,   229,  1761,  1762,    -1,  1764,    -1,   235,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,   244,    -1,    -1,   247,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,     8,   126,   127,    -1,   129,    -1,
      -1,    -1,    -1,    -1,  1823,  1824,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,  1054,    -1,    -1,   239,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1870,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   245,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,  1147,    -1,
      -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   122,    -1,   124,    -1,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
     141,   142,   143,   144,   145,    -1,    -1,    -1,   149,    -1,
      -1,   152,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,   197,   198,    -1,    -1,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,
      -1,  1300,  1301,    -1,   235,    -1,    -1,    -1,  2107,   240,
       3,     4,     5,   244,     7,   130,   247,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    13,    14,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,  1386,    -1,    82,
      83,    84,    85,    -1,    87,    -1,    -1,  1396,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,   126,   127,    -1,   129,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,   197,   146,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,    -1,   170,
     171,   172,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,
      -1,    -1,   235,    -1,   237,   238,    -1,   240,    -1,   242,
      -1,  1550,    -1,   246,   247,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,    -1,    -1,   152,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,   207,
     208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,   229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,   240,     3,     4,    -1,   244,    -1,     8,   247,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
      -1,    -1,   152,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,   241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   198,    -1,
      -1,    -1,   202,   203,   204,    -1,   206,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
     240,     3,     4,     5,    -1,   245,    -1,   247,    10,    11,
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
     122,    -1,   124,    -1,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,   141,
     142,   143,   144,   145,    -1,    -1,    -1,   149,    -1,    -1,
     152,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,
     202,   203,   204,    -1,   206,   207,   208,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,   240,     3,
       4,    -1,   244,    -1,    -1,   247,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,    -1,    -1,   152,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,   198,    -1,    -1,    -1,   202,   203,
     204,    -1,   206,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,   240,     3,     4,    -1,
     244,   245,    -1,   247,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,    -1,    -1,   152,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,
     206,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,   240,     3,     4,    -1,   244,    -1,
      -1,   247,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,    -1,    -1,   152,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,   207,
     208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,   229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,   240,     3,     4,    -1,   244,    -1,    -1,   247,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
      -1,    -1,   152,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   198,    -1,
      -1,    -1,   202,   203,   204,    -1,   206,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
     240,     3,     4,    -1,   244,    -1,    -1,   247,    10,    11,
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
     122,    -1,   124,    -1,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,   141,
     142,   143,   144,   145,    -1,    -1,    -1,   149,    -1,    -1,
     152,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,
     202,   203,   204,    -1,   206,   207,   208,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,   240,     3,
       4,    -1,    -1,   245,    -1,   247,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,    -1,    -1,   152,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,   198,    -1,    -1,    -1,   202,   203,
     204,    -1,   206,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,   240,     3,     4,    -1,
     244,    -1,    -1,   247,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,    -1,    -1,   152,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,
     206,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,   240,     3,     4,    -1,   244,    -1,
      -1,   247,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,    -1,    -1,   152,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,   207,
     208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,   229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,   240,     3,     4,    -1,   244,    -1,     8,   247,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
      -1,    -1,   152,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,   193,    -1,    87,    -1,   197,   198,    -1,
      -1,    -1,   202,   203,   204,    -1,   206,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,
      -1,    -1,    -1,    -1,    -1,   235,     3,     4,    -1,    -1,
     240,     8,    -1,    10,    11,    12,    -1,   247,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,   205,    -1,    82,    83,   209,    85,   211,
     212,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,   141,   142,   143,   144,   145,    -1,
      -1,    -1,   149,    -1,    -1,   152,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,   193,    -1,    87,    -1,
     197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,     3,
       4,    -1,    -1,   240,    -1,    -1,    10,    11,    12,    -1,
     247,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,   194,   195,   196,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,   205,    -1,    82,    83,
     209,    85,   211,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,    -1,    -1,   152,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,   198,    -1,    -1,    -1,   202,   203,
     204,    -1,   206,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,   240,     3,     4,    -1,
     244,    -1,    -1,   247,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,    -1,    -1,   152,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,
     206,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,   240,     3,     4,    -1,   244,    -1,
      -1,   247,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,    -1,    -1,   152,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,   207,
     208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,   229,    -1,    -1,    -1,    -1,    -1,   235,     3,     4,
       5,    -1,   240,    -1,    -1,    10,    11,    12,    -1,   247,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,   197,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,   211,   212,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,   244,
      -1,    -1,   247,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,   197,   249,    -1,
      -1,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,   211,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
     240,     3,     4,     5,   244,    -1,    -1,   247,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    -1,    87,     3,     4,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,   211,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,   249,    -1,
     197,    -1,    -1,    -1,    -1,   202,   203,   204,    -1,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,   240,     3,     4,    -1,   244,    -1,    -1,
     247,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
       3,     4,    -1,    82,    83,     8,    85,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   249,    -1,    -1,   197,    -1,
      -1,    -1,    -1,   202,   203,   204,    -1,   206,   207,   208,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,   244,    -1,    -1,   247,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
     193,    -1,   239,    -1,   197,    -1,    -1,    -1,    -1,   202,
     203,   204,   249,   206,   207,   208,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,
      -1,    -1,   235,     3,     4,    -1,    -1,   240,    -1,    -1,
      10,    11,    12,    -1,   247,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   193,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   249,   202,   203,   204,    -1,   206,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
     240,   241,    -1,    -1,    -1,    -1,    -1,   247,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
     197,   249,    -1,    -1,    -1,   202,   203,   204,    -1,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,     3,
       4,    -1,     6,   240,    -1,    -1,    10,    11,    12,    -1,
     247,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,   193,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   249,   202,   203,
     204,    -1,   206,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,   247,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,   197,   249,    -1,    -1,
      -1,   202,   203,   204,    -1,   206,   207,   208,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,
      -1,    -1,    -1,    -1,   235,     3,     4,    -1,    -1,   240,
      -1,    -1,    10,    11,    12,    -1,   247,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,     3,     4,    -1,    82,    83,    -1,    85,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   249,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,   206,   207,
     208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,   229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,   240,   241,    -1,    -1,    -1,    -1,    -1,   247,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,   193,    -1,   239,    -1,   197,    -1,    -1,    -1,    -1,
     202,   203,   204,   249,   206,   207,   208,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,
      -1,    -1,    -1,   235,     3,     4,    -1,    -1,   240,   241,
      -1,    10,    11,    12,    -1,   247,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,   126,   127,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   170,
     171,   172,    -1,   202,   203,   204,    -1,   206,   207,   208,
      -1,    13,    14,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,   247,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,   245,    -1,    -1,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,   129,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    13,    14,   146,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,   129,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,   146,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,   245,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,   126,   127,    -1,   129,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    13,    14,   146,   107,   108,   109,   110,
      -1,    -1,   113,   245,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,   126,   127,    -1,   129,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,   146,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   245,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    13,    14,   146,   107,   108,   109,
     110,    -1,    -1,   113,   245,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,   146,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,   113,   245,    -1,    -1,    -1,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,   126,   127,    -1,
     129,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    13,    14,   146,   107,   108,
     109,   110,    -1,    -1,   113,   245,    -1,    -1,    -1,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,   126,   127,    -1,
     129,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,   146,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   245,    -1,    -1,    -1,
      -1,    -1,   120,   121,    -1,   123,   124,    -1,   126,   127,
      -1,   129,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,   146,   107,
     108,   109,   110,    -1,    -1,   113,   245,    -1,    -1,    -1,
      -1,    -1,   120,   121,    -1,   123,   124,    -1,   126,   127,
      -1,   129,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,    13,    14,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,   245,    -1,    44,
      45,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    81,   245,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,   106,   107,   108,   109,   110,   111,    -1,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,     4,    -1,   158,   159,   160,    -1,    -1,    -1,   164,
      13,    14,    -1,    -1,   169,   170,   171,   172,    -1,    -1,
     175,    -1,   177,    -1,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    44,    45,    -1,   199,   200,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,   106,   107,   108,   109,   110,   111,    -1,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   169,   170,   171,   172,
       5,    -1,   175,    -1,   177,    -1,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      13,    14,    -1,    -1,    -1,    -1,   199,   200,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,   212,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,   126,   127,    -1,   129,    13,    14,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,    -1,    -1,    -1,   150,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,   170,   171,   172,
     239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,   194,
     195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,    -1,    -1,   209,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,   123,   124,    -1,
     126,   127,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,   245,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,   245,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,   245,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,   245,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,   245,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
     245,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,   245,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,   245,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,   245,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,   245,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,   245,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
     245,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,   245,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,   245,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,   245,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,   245,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,   245,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
     245,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,   244,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   244,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,   241,    -1,   243,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,   243,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,   243,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,   243,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,   243,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,   243,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
     243,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,   243,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,   243,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,   243,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,   243,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,   243,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,   243,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,   243,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,   243,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239,    -1,   241,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,   241,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,   239
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   251,   252,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    80,    81,
      83,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   106,   107,   108,
     109,   110,   111,   113,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   158,   159,   160,   164,   169,   170,   171,   172,   175,
     177,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   199,   200,   201,   210,   212,
     253,   255,   256,   276,   294,   296,   300,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   318,   320,   321,   327,
     328,   329,   330,   336,   361,   362,   244,   248,    14,    97,
     240,   240,     6,   244,     6,     6,     6,     6,   240,     6,
     242,   242,     4,   338,   362,   240,   242,   274,    91,    94,
      97,    99,   274,   240,   240,   240,     4,   240,   240,   240,
       4,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   244,   112,    97,     6,   244,    91,    94,    97,
     110,   299,    99,   240,     3,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    55,    56,    57,
      58,    63,    64,    75,    76,    77,    82,    85,    91,    94,
      97,    99,   110,   120,   124,   126,   129,   193,   197,   198,
     202,   203,   204,   206,   207,   208,   228,   229,   235,   240,
     244,   247,   296,   297,   300,   311,   318,   320,   331,   332,
     336,   338,   345,   347,   362,   240,   244,    97,    97,   120,
      94,    97,    99,    91,    94,    97,    99,   296,    94,    97,
      99,   110,   297,    94,    97,   240,    94,   150,   175,   191,
     192,   244,   228,   229,   240,   244,   342,   343,   342,   244,
     244,   342,     4,    91,    95,   101,   102,   104,   105,   123,
     240,    97,    99,    97,    94,     4,    83,   186,   244,   362,
       4,     6,    91,    94,    97,    94,    97,   110,   298,     4,
       4,     4,     5,   240,   244,   345,   346,     4,   240,   240,
     240,     4,   244,   349,   362,     4,   240,   240,   240,     6,
       6,   242,     5,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    59,    60,    61,    62,    67,    68,    69,    72,
      74,    84,    87,   194,   195,   196,   205,   209,   211,   353,
     362,   240,     4,   353,     5,   244,     5,   244,    32,   229,
     331,   362,   242,   244,   240,   244,     6,   240,   244,     6,
     248,     7,   126,   186,   213,   214,   215,   216,   237,   238,
     240,   242,   246,   272,   273,   274,   331,   352,   353,   362,
       4,   300,   301,   302,   244,     6,   331,   352,   353,   362,
     352,   331,   352,   359,   360,   362,   278,   282,   240,   341,
       9,   353,   240,   240,   240,   240,   362,   331,   331,   331,
     240,   331,   331,   331,   240,   331,   331,   331,   331,   331,
     331,   331,   352,   331,   331,   331,   331,   346,   240,   229,
     331,   347,   348,   244,   346,   345,   352,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     240,   242,   274,   274,   274,   274,   274,   274,   240,   274,
     274,   240,   296,   274,   274,     5,   244,   244,   120,   296,
     296,   240,   274,   274,   240,   240,   240,   331,   244,   331,
     347,   331,   331,   245,   348,   338,   362,   178,     5,   244,
       8,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   239,
       9,   240,   242,   246,   273,   274,   331,   348,   240,   240,
     240,   345,   346,   346,   346,   295,   244,   240,   345,   244,
     244,   331,     4,   345,   244,   349,   244,   244,   342,   342,
     342,   331,   331,   228,   229,   244,   244,   342,   228,   229,
     240,   302,   342,   244,   240,   244,   240,   240,   240,   240,
     240,   240,   240,   331,   346,   346,   346,   240,     4,   242,
       6,   242,   302,     6,     6,   244,   244,   244,   244,   346,
     242,   242,   242,   331,     8,     6,     6,   331,   331,   331,
     246,   331,   244,   178,   331,   331,   331,   331,   274,   274,
     274,   240,   240,   240,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   240,   240,   274,   240,   242,     6,
       6,   244,     6,     8,   302,     6,     8,   302,   274,   331,
     230,   244,     9,   240,   242,   246,   352,   348,   331,   302,
     345,   345,   244,   353,    91,    94,    97,    99,     7,   331,
     331,     4,   175,   176,   345,     6,   241,   243,   244,   275,
       6,   244,     6,     9,   240,   242,   246,   362,   245,   120,
     124,   126,   127,   129,   294,   296,   331,     6,   241,   249,
       9,   240,   242,   246,   241,   249,   249,   241,   249,     9,
     240,   246,   243,   249,   277,   243,   277,    86,   340,   337,
     362,   249,   331,   331,   331,   331,   249,   241,   241,   241,
     331,   241,   241,   241,   331,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   245,     7,   331,   230,
     245,   249,   331,     6,     6,   241,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   347,   331,   331,   331,   331,   331,   331,
     331,   347,   347,   362,   244,   331,   331,   352,   331,   352,
     345,   352,   352,   359,   244,   331,   275,   362,     8,   331,
     331,   346,   345,   352,   352,   347,   338,   353,   338,   348,
     241,   245,   246,   274,    64,     8,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     244,   331,   347,   331,   331,   331,   331,   331,   362,   331,
     331,     4,   339,   244,   275,   241,   245,   331,   331,   331,
       7,     7,   324,   324,   240,   331,   331,     6,   348,   348,
     244,   241,     6,   302,   244,   302,   302,   249,   249,   249,
     342,   342,   301,   301,   249,   331,   245,   315,   249,   302,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   241,
       7,   325,     6,     7,   331,     6,   331,   331,   245,   348,
     348,   348,   331,     6,   331,   331,   331,   241,   245,   241,
     241,   241,   175,   249,   302,   244,     8,   241,   241,   243,
     359,   352,   359,   352,   352,   352,   352,   352,   352,   331,
     352,   352,   352,   352,   247,   355,   362,   353,   352,   352,
     352,   338,   362,   348,   245,   245,   245,   245,   331,   331,
     302,   362,   339,   243,   245,   241,   133,   150,   319,   241,
     245,   249,   331,     6,   244,   244,   244,   244,   345,   241,
     243,     7,   272,   273,   246,     7,     6,   348,     7,   216,
     272,   257,   362,   331,   331,   339,   242,   240,   120,   296,
     297,   296,   244,   245,     6,   223,   224,   254,   348,   362,
     331,   331,     4,   339,     6,   348,   331,     6,   352,   360,
     362,   241,   339,     6,   362,     6,   352,   331,   241,   242,
     331,   249,   249,   249,   249,   353,     7,     7,     7,   241,
       7,     7,     7,   241,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   331,   241,   244,   331,   347,   245,
       6,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   249,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   249,   249,   249,   241,   243,   243,   348,   249,
     249,   275,   249,   275,   249,   249,   249,   241,   331,   333,
     275,   245,   245,   245,   249,   249,   275,   275,   241,   246,
     241,   246,   249,   274,   334,   245,     7,   339,   275,   244,
     245,     8,     8,   348,   246,   241,   243,   273,   240,   242,
     274,   348,     7,   244,   241,   241,   241,   331,   345,     4,
     323,     6,   291,   331,   353,   245,   241,   245,   245,   348,
     246,   245,   302,   245,   245,   342,   331,   331,   245,   245,
     331,   342,   130,   130,   147,   155,   156,   157,   161,   162,
     316,   317,   342,   245,   312,   241,   245,   241,   241,   241,
     241,   241,   241,   241,     7,   331,     6,   331,   241,   243,
     243,   245,   245,   245,   245,   243,   243,   249,     7,     7,
       7,   246,   331,   245,   331,   331,     7,   246,   275,   249,
     275,   275,   241,   241,   249,   275,   275,   249,   249,   275,
     275,   275,   275,   331,   275,     9,   354,   249,   241,   249,
     275,   246,   249,   335,   243,   245,   245,   246,   240,   242,
     248,   178,     7,   150,     6,   331,   245,   244,     6,   345,
     245,   331,   331,   331,   331,     6,     7,   272,   273,   246,
     272,   273,   353,   331,     6,     4,   244,   350,   362,   245,
      46,    46,   345,     4,   165,   166,   167,   168,   245,   260,
     264,   267,   269,   270,   246,   241,   243,   240,   331,   331,
     240,   244,   240,   244,     8,   348,   352,   241,   246,   241,
     243,   240,   241,   249,   246,   240,     7,   274,     4,   285,
     286,   287,   275,   331,   331,   331,   331,   275,   342,   345,
     345,     7,   345,   345,   345,     7,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,     6,     7,   348,   331,
     331,   331,   331,   245,   331,   331,   331,   345,   352,   352,
     245,   249,   284,   331,   331,   339,   339,   331,   331,   241,
     345,   274,   331,   331,   331,   245,   339,   273,   246,   273,
     331,   331,   275,   245,   345,   348,     7,     7,     7,   130,
     322,     6,   241,   249,     7,     7,     7,   245,     4,   245,
     249,   249,   249,   245,   245,   109,     4,     6,   331,   244,
       6,   240,     6,   163,     6,   163,   245,   317,   249,   316,
       7,     6,     7,     7,     7,     7,     7,     7,     7,   345,
       6,   244,     6,     6,     6,    97,     7,     6,     6,   331,
     345,   345,   345,     4,   249,     8,     8,   241,     4,   100,
     101,     4,   348,   352,   331,   352,   247,   249,   288,   352,
     352,   339,   352,   241,   249,   339,   244,   296,   244,     6,
     331,     6,   244,   345,   245,   245,   245,   245,   245,   331,
       6,     4,   175,   176,   331,     6,     6,     6,     7,   349,
     351,     6,   242,   275,   274,   274,     6,   261,   240,   240,
     244,   271,     6,   339,   246,   352,   331,   243,   241,   331,
       8,   348,   331,   348,   245,   245,     6,     6,   254,   339,
     246,   331,     6,   331,   339,   241,   244,   331,   353,   275,
      46,   244,   345,   353,   356,   243,   249,     6,   241,   241,
     241,   241,     6,     6,   123,   293,   293,   345,     6,     6,
       6,   345,   130,   178,   292,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   245,   275,   275,   275,   275,
     275,   249,   249,   249,   241,   275,   275,   286,   275,   241,
     275,   241,   274,   334,   275,     6,   275,   249,   240,   242,
     274,     4,   241,   243,   275,     6,   245,   345,   345,   345,
       4,     6,   272,   331,   345,   244,   244,     7,     6,     7,
     331,   331,   331,   244,   244,   244,   242,     6,   331,   345,
     331,     6,     6,   331,   342,   245,     5,   345,   244,   244,
     244,   244,   244,   244,   244,   345,     6,   348,   244,   331,
     243,     6,     6,   174,   331,   331,   331,     6,     6,     6,
       6,     7,   275,   249,   249,   275,   249,   331,     4,   190,
     289,   290,   275,   241,   275,   335,   353,   240,   242,   331,
     244,   302,     6,   302,   249,     6,     6,     7,   272,   273,
     246,     7,     6,   349,   245,   249,   331,   272,   244,   275,
     357,   358,   359,   357,   240,   331,   331,   344,   345,   244,
     240,     4,     6,   241,     6,   241,   245,   245,   241,   245,
       6,     6,   352,   240,     4,   241,   249,   240,   345,   353,
       7,   274,   283,   331,   347,   287,     6,     6,     6,     6,
     342,     6,     6,     6,     6,    91,   110,    95,     6,     5,
     244,   331,   331,   331,   331,   241,   334,   331,   331,   331,
     275,   273,   244,     6,   292,     6,   331,   345,     4,     6,
     348,   348,   331,   331,   353,   245,   241,   245,   249,   301,
     301,   331,   331,   245,   249,   241,   245,   249,     6,     6,
     344,   342,   342,   342,   342,   342,   229,   342,     6,   245,
     331,     6,     6,   345,   245,   249,     8,   245,   241,   244,
     331,   353,   352,   331,   352,   331,   353,   356,   358,   353,
     249,   241,   249,   245,   331,   319,   319,   345,   353,   331,
       6,     4,   350,     6,   349,   243,   345,   359,     6,   275,
     275,   258,   331,   249,   249,   245,   249,   259,   331,   331,
       6,     6,     6,     6,   331,   331,   241,   279,   281,   244,
     358,   245,   249,     7,     7,   244,   244,   244,     5,   344,
     275,   275,   249,   275,   241,   249,   241,   243,   331,     6,
       6,   244,   245,   245,   244,     6,     6,   244,   331,   245,
     245,   245,   243,     6,   345,     7,   244,   331,   245,   249,
     249,   249,   249,   249,   249,     6,   245,   173,   331,   331,
     348,     6,     6,   241,   275,   275,   290,   353,   245,   245,
     245,   245,     6,     6,     7,     6,   246,     6,   245,     6,
       6,   241,   249,   331,   331,   244,   345,   245,   249,   241,
     241,   249,   284,   288,   345,   275,   331,   353,   362,   348,
     348,   331,     6,   245,   331,   334,   331,   245,   344,   134,
     135,   140,   326,   134,   135,   326,   348,   301,   245,   249,
       6,   245,   345,   302,   245,     6,   348,   342,   342,   342,
     342,   342,   331,   245,   245,   245,   241,     6,   244,     6,
     349,   176,   262,   331,   249,   249,   344,     6,   331,   331,
     245,   245,   280,     7,   240,   245,   245,   245,   244,   249,
     241,   249,   245,   244,   342,   345,     6,   244,   342,     6,
     245,   245,   331,     6,   130,   245,   313,   244,   245,   249,
     249,   249,   249,   249,     6,     6,     6,   302,     6,   244,
     331,   331,   245,   249,   284,   353,   241,   331,   331,   331,
       6,   342,     6,   342,     6,     6,   245,   331,   316,   302,
       6,   348,   348,   348,   348,   342,   348,   319,   259,   241,
     249,     6,   244,   331,   245,   249,   249,   249,   249,   249,
       6,   245,   245,   314,   245,   245,   245,   245,   249,   245,
     245,   245,   265,   331,   344,   245,   331,   331,   331,   342,
     342,   316,     6,     6,     6,     6,   348,     6,     6,     6,
     244,   241,   245,     6,   245,   275,   249,   249,   249,   245,
     245,   263,   352,   268,   244,     6,   331,   331,   331,     6,
     245,   249,   244,   344,   245,   245,   245,     6,   352,   266,
     352,   245,     6,     6,   245,   249,     6,     6,   352
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
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] = std::abs(tags[i]); // all edge tags > 0 for OCC
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
#line 1824 "Gmsh.y"
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
#line 1840 "Gmsh.y"
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
#line 1890 "Gmsh.y"
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
#line 1908 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 171:
#line 1914 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 172:
#line 1920 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1927 "Gmsh.y"
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
#line 1958 "Gmsh.y"
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
#line 1973 "Gmsh.y"
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
#line 1995 "Gmsh.y"
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
#line 2018 "Gmsh.y"
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
#line 2041 "Gmsh.y"
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
#line 2064 "Gmsh.y"
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
#line 2088 "Gmsh.y"
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
#line 2112 "Gmsh.y"
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
#line 2136 "Gmsh.y"
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
#line 2162 "Gmsh.y"
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
#line 2179 "Gmsh.y"
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
#line 2195 "Gmsh.y"
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
#line 2213 "Gmsh.y"
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
#line 2231 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (8)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2239 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (12)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2246 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 190:
#line 2250 "Gmsh.y"
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
#line 2276 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 192:
#line 2278 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 193:
#line 2280 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 194:
#line 2282 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 195:
#line 2284 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 196:
#line 2292 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 197:
#line 2294 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 198:
#line 2296 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 199:
#line 2298 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 200:
#line 2306 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 201:
#line 2308 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 202:
#line 2310 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 203:
#line 2318 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2320 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2322 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2324 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 207:
#line 2334 "Gmsh.y"
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
#line 2350 "Gmsh.y"
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
#line 2366 "Gmsh.y"
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
#line 2382 "Gmsh.y"
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
#line 2398 "Gmsh.y"
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
#line 2414 "Gmsh.y"
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
#line 2451 "Gmsh.y"
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
#line 2473 "Gmsh.y"
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
#line 2496 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2497 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 217:
#line 2502 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 218:
#line 2506 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 219:
#line 2510 "Gmsh.y"
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
#line 2526 "Gmsh.y"
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
    ;}
    break;

  case 222:
#line 2562 "Gmsh.y"
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
#line 2580 "Gmsh.y"
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
#line 2605 "Gmsh.y"
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
#line 2624 "Gmsh.y"
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
#line 2646 "Gmsh.y"
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
#line 2661 "Gmsh.y"
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
#line 2676 "Gmsh.y"
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
#line 2695 "Gmsh.y"
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
#line 2746 "Gmsh.y"
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
#line 2767 "Gmsh.y"
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
#line 2789 "Gmsh.y"
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
#line 2811 "Gmsh.y"
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
#line 2916 "Gmsh.y"
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
#line 2932 "Gmsh.y"
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
#line 2967 "Gmsh.y"
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
#line 2989 "Gmsh.y"
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
#line 3011 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 239:
#line 3017 "Gmsh.y"
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
#line 3032 "Gmsh.y"
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
#line 3060 "Gmsh.y"
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
#line 3072 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 243:
#line 3081 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3088 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 245:
#line 3100 "Gmsh.y"
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
#line 3119 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 247:
#line 3123 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3128 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 249:
#line 3132 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 250:
#line 3137 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 251:
#line 3144 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3151 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3158 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3170 "Gmsh.y"
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
#line 3243 "Gmsh.y"
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
#line 3261 "Gmsh.y"
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
#line 3278 "Gmsh.y"
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
#line 3293 "Gmsh.y"
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
#line 3326 "Gmsh.y"
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
#line 3338 "Gmsh.y"
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
#line 3362 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 262:
#line 3366 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 263:
#line 3371 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 264:
#line 3378 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 265:
#line 3383 "Gmsh.y"
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
#line 3393 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 267:
#line 3398 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 268:
#line 3404 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 269:
#line 3412 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 270:
#line 3416 "Gmsh.y"
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
#line 3426 "Gmsh.y"
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
#line 3489 "Gmsh.y"
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
#line 3505 "Gmsh.y"
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
#line 3522 "Gmsh.y"
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
#line 3539 "Gmsh.y"
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
#line 3561 "Gmsh.y"
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
#line 3583 "Gmsh.y"
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
#line 3618 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3626 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 3634 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 281:
#line 3640 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3647 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 3654 "Gmsh.y"
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
#line 3674 "Gmsh.y"
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
#line 3700 "Gmsh.y"
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
#line 3712 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 287:
#line 3723 "Gmsh.y"
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
#line 3741 "Gmsh.y"
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
#line 3759 "Gmsh.y"
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
#line 3777 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 291:
#line 3783 "Gmsh.y"
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
#line 3801 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 3807 "Gmsh.y"
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
#line 3827 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 3833 "Gmsh.y"
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
#line 3851 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 3857 "Gmsh.y"
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
#line 3874 "Gmsh.y"
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
#line 3890 "Gmsh.y"
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
#line 3907 "Gmsh.y"
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
#line 3924 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radius, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    ;}
    break;

  case 302:
#line 3947 "Gmsh.y"
    {
    ;}
    break;

  case 303:
#line 3950 "Gmsh.y"
    {
    ;}
    break;

  case 304:
#line 3956 "Gmsh.y"
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

  case 305:
#line 3968 "Gmsh.y"
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

  case 306:
#line 3988 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 307:
#line 3992 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 308:
#line 3996 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 309:
#line 4000 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 310:
#line 4004 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 311:
#line 4008 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 312:
#line 4012 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 313:
#line 4016 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 314:
#line 4025 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 315:
#line 4037 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 316:
#line 4038 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 317:
#line 4039 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 318:
#line 4040 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 319:
#line 4041 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 320:
#line 4045 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 321:
#line 4046 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 322:
#line 4047 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 323:
#line 4048 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 324:
#line 4049 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 325:
#line 4054 "Gmsh.y"
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

  case 326:
#line 4077 "Gmsh.y"
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

  case 327:
#line 4097 "Gmsh.y"
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

  case 328:
#line 4118 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 329:
#line 4122 "Gmsh.y"
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

  case 330:
#line 4137 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 331:
#line 4141 "Gmsh.y"
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

  case 332:
#line 4157 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 333:
#line 4161 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 334:
#line 4166 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 335:
#line 4170 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 336:
#line 4176 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 337:
#line 4180 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 338:
#line 4187 "Gmsh.y"
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

  case 339:
#line 4209 "Gmsh.y"
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

  case 340:
#line 4250 "Gmsh.y"
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

  case 341:
#line 4294 "Gmsh.y"
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

  case 342:
#line 4333 "Gmsh.y"
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

  case 343:
#line 4358 "Gmsh.y"
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

  case 344:
#line 4370 "Gmsh.y"
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

  case 345:
#line 4382 "Gmsh.y"
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

  case 346:
#line 4394 "Gmsh.y"
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

  case 347:
#line 4406 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 348:
#line 4415 "Gmsh.y"
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

  case 349:
#line 4445 "Gmsh.y"
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

  case 350:
#line 4471 "Gmsh.y"
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

  case 351:
#line 4498 "Gmsh.y"
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

  case 352:
#line 4530 "Gmsh.y"
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

  case 353:
#line 4557 "Gmsh.y"
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

  case 354:
#line 4583 "Gmsh.y"
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

  case 355:
#line 4609 "Gmsh.y"
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

  case 356:
#line 4635 "Gmsh.y"
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

  case 357:
#line 4661 "Gmsh.y"
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

  case 358:
#line 4682 "Gmsh.y"
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

  case 359:
#line 4693 "Gmsh.y"
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

  case 360:
#line 4741 "Gmsh.y"
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

  case 361:
#line 4795 "Gmsh.y"
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

  case 362:
#line 4810 "Gmsh.y"
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

  case 363:
#line 4822 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 364:
#line 4833 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 365:
#line 4840 "Gmsh.y"
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

  case 366:
#line 4855 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 367:
#line 4868 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 368:
#line 4869 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 369:
#line 4870 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 370:
#line 4875 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 371:
#line 4881 "Gmsh.y"
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

  case 372:
#line 4893 "Gmsh.y"
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

  case 373:
#line 4911 "Gmsh.y"
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

  case 374:
#line 4938 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 375:
#line 4939 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 376:
#line 4940 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 377:
#line 4941 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 378:
#line 4942 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 379:
#line 4943 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 380:
#line 4944 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4945 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4947 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 383:
#line 4953 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 384:
#line 4954 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 385:
#line 4955 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 386:
#line 4956 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 387:
#line 4957 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 388:
#line 4958 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 389:
#line 4959 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 4960 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 391:
#line 4961 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 4962 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 4963 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 4964 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 395:
#line 4965 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 396:
#line 4966 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 397:
#line 4967 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 398:
#line 4968 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 399:
#line 4969 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4970 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 401:
#line 4971 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 402:
#line 4972 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 403:
#line 4973 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4974 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 405:
#line 4975 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4976 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 407:
#line 4977 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 4978 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 409:
#line 4979 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 4980 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 4981 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 4982 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 413:
#line 4983 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 414:
#line 4984 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 415:
#line 4985 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 416:
#line 4986 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 417:
#line 4987 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 418:
#line 4988 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 419:
#line 4989 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 420:
#line 4990 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 421:
#line 4999 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 422:
#line 5000 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 423:
#line 5001 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 424:
#line 5002 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 425:
#line 5003 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 426:
#line 5004 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 427:
#line 5005 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 428:
#line 5006 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 429:
#line 5007 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 430:
#line 5008 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 431:
#line 5009 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 432:
#line 5014 "Gmsh.y"
    { init_options(); ;}
    break;

  case 433:
#line 5016 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 434:
#line 5022 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 435:
#line 5024 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 436:
#line 5029 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 437:
#line 5034 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 438:
#line 5039 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 439:
#line 5044 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 440:
#line 5048 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 441:
#line 5052 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 442:
#line 5056 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 443:
#line 5060 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 444:
#line 5064 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 445:
#line 5068 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 446:
#line 5072 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 447:
#line 5078 "Gmsh.y"
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

  case 448:
#line 5094 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 449:
#line 5099 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 450:
#line 5105 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 451:
#line 5111 "Gmsh.y"
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

  case 452:
#line 5130 "Gmsh.y"
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

  case 453:
#line 5151 "Gmsh.y"
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
#line 5184 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 455:
#line 5188 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 456:
#line 5193 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 457:
#line 5197 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 458:
#line 5201 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 459:
#line 5205 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 460:
#line 5210 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 461:
#line 5215 "Gmsh.y"
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

  case 462:
#line 5225 "Gmsh.y"
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

  case 463:
#line 5235 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 464:
#line 5240 "Gmsh.y"
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

  case 465:
#line 5251 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 466:
#line 5260 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 467:
#line 5265 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 468:
#line 5270 "Gmsh.y"
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

  case 469:
#line 5297 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 470:
#line 5299 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 471:
#line 5304 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 472:
#line 5306 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 473:
#line 5311 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 474:
#line 5318 "Gmsh.y"
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

  case 475:
#line 5334 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 476:
#line 5336 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 477:
#line 5341 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 478:
#line 5350 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 479:
#line 5352 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 480:
#line 5357 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 481:
#line 5359 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 482:
#line 5364 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 483:
#line 5368 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 484:
#line 5372 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 485:
#line 5376 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 486:
#line 5380 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 487:
#line 5387 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 488:
#line 5391 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 489:
#line 5395 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 490:
#line 5399 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 491:
#line 5406 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 492:
#line 5411 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 493:
#line 5418 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 494:
#line 5423 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 495:
#line 5427 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 496:
#line 5432 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 497:
#line 5436 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 498:
#line 5444 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 499:
#line 5455 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 500:
#line 5459 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 501:
#line 5463 "Gmsh.y"
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

  case 502:
#line 5477 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 503:
#line 5485 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 504:
#line 5493 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 505:
#line 5500 "Gmsh.y"
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

  case 506:
#line 5510 "Gmsh.y"
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

  case 507:
#line 5533 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 508:
#line 5538 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 509:
#line 5544 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 510:
#line 5549 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 511:
#line 5555 "Gmsh.y"
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

  case 512:
#line 5566 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 513:
#line 5573 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 514:
#line 5578 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 515:
#line 5583 "Gmsh.y"
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

  case 516:
#line 5593 "Gmsh.y"
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
#line 5603 "Gmsh.y"
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
#line 5613 "Gmsh.y"
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

  case 519:
#line 5625 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 520:
#line 5629 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 521:
#line 5634 "Gmsh.y"
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

  case 522:
#line 5646 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 523:
#line 5650 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 524:
#line 5654 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 525:
#line 5658 "Gmsh.y"
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

  case 526:
#line 5676 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 527:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 528:
#line 5692 "Gmsh.y"
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

  case 529:
#line 5721 "Gmsh.y"
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

  case 530:
#line 5731 "Gmsh.y"
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

  case 531:
#line 5747 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 532:
#line 5758 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 533:
#line 5763 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 534:
#line 5767 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 535:
#line 5771 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 536:
#line 5783 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 537:
#line 5787 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 538:
#line 5799 "Gmsh.y"
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

  case 539:
#line 5816 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 540:
#line 5826 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 541:
#line 5830 "Gmsh.y"
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

  case 542:
#line 5845 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 543:
#line 5850 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 544:
#line 5857 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 545:
#line 5861 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 546:
#line 5866 "Gmsh.y"
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

  case 547:
#line 5880 "Gmsh.y"
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
#line 5896 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 549:
#line 5900 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 550:
#line 5904 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 551:
#line 5908 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 552:
#line 5912 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 553:
#line 5920 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 554:
#line 5926 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 555:
#line 5932 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 556:
#line 5938 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 557:
#line 5947 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 558:
#line 5951 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 559:
#line 5955 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 560:
#line 5963 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 561:
#line 5969 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 562:
#line 5975 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 563:
#line 5979 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 564:
#line 5987 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 565:
#line 5995 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 566:
#line 6002 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 567:
#line 6011 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 568:
#line 6015 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 569:
#line 6019 "Gmsh.y"
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

  case 570:
#line 6034 "Gmsh.y"
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

  case 571:
#line 6048 "Gmsh.y"
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

  case 572:
#line 6062 "Gmsh.y"
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

  case 573:
#line 6074 "Gmsh.y"
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

  case 574:
#line 6090 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 575:
#line 6099 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 576:
#line 6108 "Gmsh.y"
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

  case 577:
#line 6118 "Gmsh.y"
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

  case 578:
#line 6129 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 579:
#line 6137 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 580:
#line 6145 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 581:
#line 6149 "Gmsh.y"
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

  case 582:
#line 6168 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 583:
#line 6175 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 584:
#line 6181 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 585:
#line 6188 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6195 "Gmsh.y"
    { init_options(); ;}
    break;

  case 587:
#line 6197 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 588:
#line 6205 "Gmsh.y"
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

  case 589:
#line 6229 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 590:
#line 6231 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 591:
#line 6237 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 592:
#line 6242 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 593:
#line 6244 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 594:
#line 6249 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 595:
#line 6254 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 596:
#line 6259 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 597:
#line 6261 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 598:
#line 6265 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 599:
#line 6277 "Gmsh.y"
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

  case 600:
#line 6291 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 601:
#line 6295 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 602:
#line 6302 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 603:
#line 6310 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 604:
#line 6318 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 605:
#line 6329 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 606:
#line 6331 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 607:
#line 6334 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13977 "Gmsh.tab.cpp"
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


#line 6337 "Gmsh.y"


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

