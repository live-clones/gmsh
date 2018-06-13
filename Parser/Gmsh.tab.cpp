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
     tUsing = 384,
     tPlugin = 385,
     tDegenerated = 386,
     tRecursive = 387,
     tRotate = 388,
     tTranslate = 389,
     tSymmetry = 390,
     tDilate = 391,
     tExtrude = 392,
     tLevelset = 393,
     tAffine = 394,
     tBooleanUnion = 395,
     tBooleanIntersection = 396,
     tBooleanDifference = 397,
     tBooleanSection = 398,
     tBooleanFragments = 399,
     tThickSolid = 400,
     tRecombine = 401,
     tSmoother = 402,
     tSplit = 403,
     tDelete = 404,
     tCoherence = 405,
     tIntersect = 406,
     tMeshAlgorithm = 407,
     tReverseMesh = 408,
     tLayers = 409,
     tScaleLast = 410,
     tHole = 411,
     tAlias = 412,
     tAliasWithOptions = 413,
     tCopyOptions = 414,
     tQuadTriAddVerts = 415,
     tQuadTriNoNewVerts = 416,
     tRecombLaterals = 417,
     tTransfQuadTri = 418,
     tText2D = 419,
     tText3D = 420,
     tInterpolationScheme = 421,
     tTime = 422,
     tCombine = 423,
     tBSpline = 424,
     tBezier = 425,
     tNurbs = 426,
     tNurbsOrder = 427,
     tNurbsKnots = 428,
     tColor = 429,
     tColorTable = 430,
     tFor = 431,
     tIn = 432,
     tEndFor = 433,
     tIf = 434,
     tElseIf = 435,
     tElse = 436,
     tEndIf = 437,
     tExit = 438,
     tAbort = 439,
     tField = 440,
     tReturn = 441,
     tCall = 442,
     tSlide = 443,
     tMacro = 444,
     tShow = 445,
     tHide = 446,
     tGetValue = 447,
     tGetStringValue = 448,
     tGetEnv = 449,
     tGetString = 450,
     tGetNumber = 451,
     tUnique = 452,
     tHomology = 453,
     tCohomology = 454,
     tBetti = 455,
     tExists = 456,
     tFileExists = 457,
     tGetForced = 458,
     tGetForcedStr = 459,
     tGMSH_MAJOR_VERSION = 460,
     tGMSH_MINOR_VERSION = 461,
     tGMSH_PATCH_VERSION = 462,
     tGmshExecutableName = 463,
     tSetPartition = 464,
     tNameToString = 465,
     tStringToName = 466,
     tAFFECTDIVIDE = 467,
     tAFFECTTIMES = 468,
     tAFFECTMINUS = 469,
     tAFFECTPLUS = 470,
     tOR = 471,
     tAND = 472,
     tNOTEQUAL = 473,
     tEQUAL = 474,
     tGREATERGREATER = 475,
     tLESSLESS = 476,
     tGREATEROREQUAL = 477,
     tLESSOREQUAL = 478,
     UNARYPREC = 479,
     tMINUSMINUS = 480,
     tPLUSPLUS = 481
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
#define tUsing 384
#define tPlugin 385
#define tDegenerated 386
#define tRecursive 387
#define tRotate 388
#define tTranslate 389
#define tSymmetry 390
#define tDilate 391
#define tExtrude 392
#define tLevelset 393
#define tAffine 394
#define tBooleanUnion 395
#define tBooleanIntersection 396
#define tBooleanDifference 397
#define tBooleanSection 398
#define tBooleanFragments 399
#define tThickSolid 400
#define tRecombine 401
#define tSmoother 402
#define tSplit 403
#define tDelete 404
#define tCoherence 405
#define tIntersect 406
#define tMeshAlgorithm 407
#define tReverseMesh 408
#define tLayers 409
#define tScaleLast 410
#define tHole 411
#define tAlias 412
#define tAliasWithOptions 413
#define tCopyOptions 414
#define tQuadTriAddVerts 415
#define tQuadTriNoNewVerts 416
#define tRecombLaterals 417
#define tTransfQuadTri 418
#define tText2D 419
#define tText3D 420
#define tInterpolationScheme 421
#define tTime 422
#define tCombine 423
#define tBSpline 424
#define tBezier 425
#define tNurbs 426
#define tNurbsOrder 427
#define tNurbsKnots 428
#define tColor 429
#define tColorTable 430
#define tFor 431
#define tIn 432
#define tEndFor 433
#define tIf 434
#define tElseIf 435
#define tElse 436
#define tEndIf 437
#define tExit 438
#define tAbort 439
#define tField 440
#define tReturn 441
#define tCall 442
#define tSlide 443
#define tMacro 444
#define tShow 445
#define tHide 446
#define tGetValue 447
#define tGetStringValue 448
#define tGetEnv 449
#define tGetString 450
#define tGetNumber 451
#define tUnique 452
#define tHomology 453
#define tCohomology 454
#define tBetti 455
#define tExists 456
#define tFileExists 457
#define tGetForced 458
#define tGetForcedStr 459
#define tGMSH_MAJOR_VERSION 460
#define tGMSH_MINOR_VERSION 461
#define tGMSH_PATCH_VERSION 462
#define tGmshExecutableName 463
#define tSetPartition 464
#define tNameToString 465
#define tStringToName 466
#define tAFFECTDIVIDE 467
#define tAFFECTTIMES 468
#define tAFFECTMINUS 469
#define tAFFECTPLUS 470
#define tOR 471
#define tAND 472
#define tNOTEQUAL 473
#define tEQUAL 474
#define tGREATERGREATER 475
#define tLESSLESS 476
#define tGREATEROREQUAL 477
#define tLESSOREQUAL 478
#define UNARYPREC 479
#define tMINUSMINUS 480
#define tPLUSPLUS 481




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
#line 165 "Gmsh.y"
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
#line 731 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 744 "Gmsh.tab.cpp"

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
#define YYLAST   15869

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  605
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   481

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   246,     2,   231,   233,     2,
     239,   240,   229,   227,   248,   228,   245,   230,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     221,     2,   222,   216,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   241,     2,   242,   238,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,   232,   244,   247,     2,     2,     2,
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
     215,   217,   218,   219,   220,   223,   224,   225,   226,   235,
     236,   237
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
    1144,  1152,  1159,  1167,  1176,  1187,  1202,  1219,  1232,  1247,
    1262,  1277,  1292,  1301,  1310,  1317,  1322,  1328,  1335,  1342,
    1346,  1351,  1355,  1361,  1368,  1374,  1379,  1383,  1388,  1392,
    1397,  1403,  1408,  1414,  1418,  1424,  1432,  1440,  1444,  1452,
    1456,  1459,  1462,  1465,  1468,  1471,  1487,  1490,  1493,  1496,
    1499,  1516,  1528,  1535,  1544,  1553,  1564,  1566,  1569,  1572,
    1574,  1578,  1582,  1587,  1592,  1594,  1596,  1602,  1614,  1628,
    1629,  1637,  1638,  1652,  1653,  1669,  1670,  1677,  1687,  1690,
    1694,  1705,  1707,  1710,  1716,  1724,  1727,  1730,  1734,  1737,
    1741,  1744,  1748,  1758,  1765,  1767,  1769,  1771,  1773,  1775,
    1776,  1779,  1783,  1787,  1792,  1802,  1807,  1822,  1823,  1827,
    1828,  1830,  1831,  1834,  1835,  1838,  1839,  1842,  1849,  1857,
    1864,  1870,  1874,  1883,  1892,  1901,  1910,  1919,  1925,  1930,
    1937,  1949,  1961,  1980,  1999,  2012,  2025,  2038,  2049,  2054,
    2059,  2064,  2069,  2074,  2077,  2081,  2088,  2090,  2092,  2094,
    2097,  2103,  2111,  2122,  2124,  2128,  2131,  2134,  2137,  2141,
    2145,  2149,  2153,  2157,  2161,  2165,  2169,  2173,  2177,  2181,
    2185,  2189,  2193,  2197,  2201,  2205,  2209,  2215,  2220,  2225,
    2230,  2235,  2240,  2245,  2250,  2255,  2260,  2265,  2272,  2277,
    2282,  2287,  2292,  2297,  2302,  2307,  2312,  2319,  2326,  2333,
    2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,  2356,
    2358,  2360,  2361,  2368,  2370,  2375,  2382,  2384,  2389,  2394,
    2399,  2406,  2412,  2420,  2429,  2440,  2445,  2450,  2457,  2462,
    2466,  2469,  2475,  2481,  2485,  2491,  2498,  2507,  2514,  2523,
    2530,  2535,  2543,  2550,  2557,  2564,  2569,  2576,  2581,  2582,
    2585,  2586,  2589,  2590,  2598,  2600,  2604,  2606,  2608,  2611,
    2612,  2616,  2618,  2621,  2624,  2628,  2632,  2644,  2654,  2662,
    2670,  2672,  2676,  2678,  2680,  2683,  2687,  2692,  2698,  2700,
    2704,  2706,  2709,  2713,  2717,  2723,  2728,  2733,  2736,  2741,
    2744,  2748,  2765,  2771,  2773,  2775,  2777,  2781,  2787,  2795,
    2800,  2805,  2810,  2817,  2824,  2833,  2842,  2847,  2862,  2867,
    2872,  2874,  2876,  2880,  2884,  2894,  2902,  2904,  2910,  2914,
    2921,  2923,  2927,  2929,  2931,  2936,  2941,  2945,  2951,  2958,
    2967,  2974,  2980,  2986,  2992,  2998,  3000,  3005,  3007,  3009,
    3011,  3013,  3018,  3025,  3030,  3037,  3043,  3051,  3056,  3061,
    3066,  3075,  3080,  3085,  3090,  3095,  3104,  3113,  3120,  3125,
    3132,  3137,  3139,  3144,  3149,  3150,  3157,  3162,  3165,  3170,
    3175,  3177,  3179,  3183,  3185,  3187,  3191,  3195,  3199,  3205,
    3213,  3219,  3225,  3234,  3236,  3238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     250,     0,    -1,   251,    -1,     1,     6,    -1,    -1,   251,
     252,    -1,   254,    -1,   255,    -1,   275,    -1,   119,   239,
     351,   240,     6,    -1,   293,    -1,   299,    -1,   303,    -1,
     304,    -1,   305,    -1,   306,    -1,   310,    -1,   319,    -1,
     320,    -1,   326,    -1,   327,    -1,   309,    -1,   308,    -1,
     307,    -1,   302,    -1,   329,    -1,   222,    -1,   223,    -1,
      44,   239,   351,   240,     6,    -1,    45,   239,   351,   240,
       6,    -1,    44,   239,   351,   240,   253,   351,     6,    -1,
      44,   239,   351,   248,   347,   240,     6,    -1,    45,   239,
     351,   248,   347,   240,     6,    -1,    44,   239,   351,   248,
     347,   240,   253,   351,     6,    -1,   361,   351,   243,   256,
     244,     6,    -1,   157,     4,   241,   330,   242,     6,    -1,
     158,     4,   241,   330,   242,     6,    -1,   159,     4,   241,
     330,   248,   330,   242,     6,    -1,    -1,   256,   259,    -1,
     256,   263,    -1,   256,   266,    -1,   256,   268,    -1,   256,
     269,    -1,   330,    -1,   257,   248,   330,    -1,   330,    -1,
     258,   248,   330,    -1,    -1,    -1,     4,   260,   239,   257,
     240,   261,   243,   258,   244,     6,    -1,   351,    -1,   262,
     248,   351,    -1,    -1,   164,   239,   330,   248,   330,   248,
     330,   240,   264,   243,   262,   244,     6,    -1,   351,    -1,
     265,   248,   351,    -1,    -1,   165,   239,   330,   248,   330,
     248,   330,   248,   330,   240,   267,   243,   265,   244,     6,
      -1,   166,   243,   343,   244,   243,   343,   244,     6,    -1,
     166,   243,   343,   244,   243,   343,   244,   243,   343,   244,
     243,   343,   244,     6,    -1,    -1,   167,   270,   243,   258,
     244,     6,    -1,     7,    -1,   215,    -1,   214,    -1,   213,
      -1,   212,    -1,   237,    -1,   236,    -1,   239,    -1,   241,
      -1,   240,    -1,   242,    -1,    80,   241,   277,   242,     6,
      -1,    81,   241,   281,   242,     6,    -1,   335,     6,    -1,
      88,   273,   352,   248,   330,   274,     6,    -1,    90,   273,
     361,   248,   352,   274,     6,    -1,   361,   271,   344,     6,
      -1,   361,   272,     6,    -1,   361,   273,   274,   271,   344,
       6,    -1,   361,   273,   243,   347,   244,   274,   271,   344,
       6,    -1,   361,   241,   330,   242,   271,   330,     6,    -1,
     361,   241,   330,   242,   272,     6,    -1,   361,   239,   330,
     240,   271,   330,     6,    -1,   361,   239,   330,   240,   272,
       6,    -1,   361,     7,   352,     6,    -1,   361,   273,   274,
       7,    46,   273,   274,     6,    -1,   361,   273,   274,     7,
      46,   273,   356,   274,     6,    -1,   361,   273,   274,   215,
      46,   273,   356,   274,     6,    -1,   361,   245,     4,     7,
     352,     6,    -1,   361,   241,   330,   242,   245,     4,     7,
     352,     6,    -1,   361,   245,     4,   271,   330,     6,    -1,
     361,   241,   330,   242,   245,     4,   271,   330,     6,    -1,
     361,   245,     4,   272,     6,    -1,   361,   241,   330,   242,
     245,     4,   272,     6,    -1,   361,   245,   174,   245,     4,
       7,   348,     6,    -1,   361,   241,   330,   242,   245,   174,
     245,     4,     7,   348,     6,    -1,   361,   245,   175,     7,
     349,     6,    -1,   361,   241,   330,   242,   245,   175,     7,
     349,     6,    -1,   361,   185,     7,   344,     6,    -1,   185,
     241,   330,   242,     7,     4,     6,    -1,   185,   241,   330,
     242,     7,   100,     6,    -1,   185,   241,   330,   242,     7,
     101,     6,    -1,   185,   241,   330,   242,   245,     4,     7,
     330,     6,    -1,   185,   241,   330,   242,   245,     4,     7,
     352,     6,    -1,   185,   241,   330,   242,   245,     4,     7,
     243,   347,   244,     6,    -1,   185,   241,   330,   242,   245,
       4,     6,    -1,   130,   239,     4,   240,   245,     4,     7,
     330,     6,    -1,   130,   239,     4,   240,   245,     4,     7,
     352,     6,    -1,    -1,   248,    -1,    -1,   277,   276,   361,
      -1,   277,   276,   361,     7,   330,    -1,    -1,   277,   276,
     361,     7,   243,   344,   278,   283,   244,    -1,    -1,   277,
     276,   361,   273,   274,     7,   243,   344,   279,   283,   244,
      -1,   277,   276,   361,     7,   352,    -1,    -1,   277,   276,
     361,     7,   243,   352,   280,   287,   244,    -1,    -1,   281,
     276,   351,    -1,   330,     7,   352,    -1,   282,   248,   330,
       7,   352,    -1,   346,     7,   361,   239,   240,    -1,    -1,
     248,   285,    -1,    -1,   285,    -1,   286,    -1,   285,   248,
     286,    -1,     4,   344,    -1,     4,    -1,     4,   243,   282,
     244,    -1,     4,   352,    -1,     4,   355,    -1,    -1,   248,
     288,    -1,   289,    -1,   288,   248,   289,    -1,     4,   330,
      -1,     4,   352,    -1,   189,   352,    -1,     4,   357,    -1,
       4,   355,    -1,   330,    -1,   352,    -1,   352,   248,   330,
      -1,    -1,   177,    95,   243,   330,   244,    -1,   129,    91,
     243,   347,   244,    -1,   129,   110,   243,   347,   244,    -1,
      -1,   123,   341,    -1,    91,   239,   330,   240,     7,   341,
       6,    -1,    94,   239,   330,   240,     7,   344,     6,    -1,
      98,   239,   330,   240,     7,   344,     6,    -1,    92,   239,
     330,   240,     7,   344,   292,     6,    -1,    93,   239,   330,
     240,     7,   344,   292,     6,    -1,   169,   239,   330,   240,
       7,   344,     6,    -1,   170,   239,   330,   240,     7,   344,
       6,    -1,   171,   239,   330,   240,     7,   344,   173,   344,
     172,   330,     6,    -1,   109,   239,   330,   240,     7,   344,
       6,    -1,    94,     4,   239,   330,   240,     7,   344,     6,
      -1,   123,    97,   239,   330,   240,     7,   344,     6,    -1,
      97,   239,   330,   240,     7,   344,   291,     6,    -1,   124,
      97,   239,   330,   240,     7,   344,   291,     6,    -1,    13,
      14,     6,    -1,    14,    97,   330,     6,    -1,   113,    97,
     239,   330,   240,     7,     5,     5,     5,     6,    -1,    95,
     239,   330,   240,     7,   344,     6,    -1,    96,   239,   330,
     240,     7,   344,     6,    -1,   100,   239,   330,   240,     7,
     344,     6,    -1,   103,   239,   330,   240,     7,   344,     6,
      -1,   107,   239,   330,   240,     7,   344,     6,    -1,   108,
     239,   330,   240,     7,   344,     6,    -1,   101,   239,   330,
     240,     7,   344,     6,    -1,   102,   239,   330,   240,     7,
     344,     6,    -1,   121,   239,   330,   240,     7,   344,     6,
      -1,   145,   239,   330,   240,     7,   344,     6,    -1,    97,
       4,   239,   330,   240,     7,   344,     6,    -1,    99,   239,
     330,   240,     7,   344,     6,    -1,   120,   239,   330,   240,
       7,   344,     6,    -1,   124,   120,   239,   330,   240,     7,
     344,     6,    -1,   127,   296,   239,   330,   240,     7,   344,
       6,    -1,   127,   296,   239,   330,   240,     7,   344,     4,
     243,   343,   244,     6,    -1,    -1,   126,   295,   294,   239,
     290,   240,   271,   344,     6,    -1,    91,    -1,    94,    -1,
      97,    -1,    99,    -1,   110,   243,   330,   244,    -1,    94,
      -1,    97,    -1,    99,    -1,   110,   243,   330,   244,    -1,
      94,    -1,    97,    -1,   110,   243,   330,   244,    -1,    91,
      -1,    94,    -1,    97,    -1,   110,   243,   330,   244,    -1,
     134,   341,   243,   300,   244,    -1,   133,   243,   341,   248,
     341,   248,   330,   244,   243,   300,   244,    -1,   135,   341,
     243,   300,   244,    -1,   136,   243,   341,   248,   330,   244,
     243,   300,   244,    -1,   136,   243,   341,   248,   341,   244,
     243,   300,   244,    -1,     4,   243,   300,   244,    -1,   151,
      94,   243,   347,   244,    97,   243,   330,   244,    -1,   148,
      94,   239,   330,   240,   243,   347,   244,     6,    -1,   301,
      -1,   299,    -1,    -1,   301,   293,    -1,   301,   295,   243,
     347,   244,     6,    -1,   301,   126,   295,   243,   347,   244,
       6,    -1,   301,   295,   243,     8,   244,     6,    -1,   301,
     126,   295,   243,     8,   244,     6,    -1,   138,   123,   239,
     330,   240,     7,   344,     6,    -1,   138,    91,   239,   330,
     240,     7,   243,   343,   244,     6,    -1,   138,   123,   239,
     330,   240,     7,   243,   341,   248,   341,   248,   347,   244,
       6,    -1,   138,   123,   239,   330,   240,     7,   243,   341,
     248,   341,   248,   341,   248,   347,   244,     6,    -1,   138,
      95,   239,   330,   240,     7,   243,   341,   248,   347,   244,
       6,    -1,   138,   101,   239,   330,   240,     7,   243,   341,
     248,   341,   248,   347,   244,     6,    -1,   138,   102,   239,
     330,   240,     7,   243,   341,   248,   341,   248,   347,   244,
       6,    -1,   138,   104,   239,   330,   240,     7,   243,   341,
     248,   341,   248,   347,   244,     6,    -1,   138,   105,   239,
     330,   240,     7,   243,   341,   248,   341,   248,   347,   244,
       6,    -1,   138,     4,   239,   330,   240,     7,   344,     6,
      -1,   138,     4,   239,   330,   240,     7,     5,     6,    -1,
     138,     4,   243,   330,   244,     6,    -1,   149,   243,   301,
     244,    -1,   132,   149,   243,   301,   244,    -1,   149,   185,
     241,   330,   242,     6,    -1,   149,     4,   241,   330,   242,
       6,    -1,   149,   361,     6,    -1,   149,     4,     4,     6,
      -1,   149,    83,     6,    -1,   174,   348,   243,   301,   244,
      -1,   132,   174,   348,   243,   301,   244,    -1,   209,   330,
     243,   301,   244,    -1,   190,   243,     8,   244,    -1,   190,
       5,     6,    -1,   191,   243,     8,   244,    -1,   191,     5,
       6,    -1,   190,   243,   301,   244,    -1,   132,   190,   243,
     301,   244,    -1,   191,   243,   301,   244,    -1,   132,   191,
     243,   301,   244,    -1,   361,   352,     6,    -1,    73,   239,
     358,   240,     6,    -1,   361,   361,   241,   330,   242,   351,
       6,    -1,   361,   361,   361,   241,   330,   242,     6,    -1,
     361,   330,     6,    -1,   130,   239,     4,   240,   245,     4,
       6,    -1,   168,     4,     6,    -1,   183,     6,    -1,   184,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   243,   330,   248,   330,   248,   330,   248,   330,
     248,   330,   248,   330,   244,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    78,     6,    -1,   115,     6,    -1,   116,
     243,   347,   244,   243,   347,   244,   243,   343,   244,   243,
     330,   248,   330,   244,     6,    -1,   188,   239,   243,   347,
     244,   248,   352,   248,   352,   240,     6,    -1,   176,   239,
     330,     8,   330,   240,    -1,   176,   239,   330,     8,   330,
       8,   330,   240,    -1,   176,     4,   177,   243,   330,     8,
     330,   244,    -1,   176,     4,   177,   243,   330,     8,   330,
       8,   330,   244,    -1,   178,    -1,   189,     4,    -1,   189,
     352,    -1,   186,    -1,   187,   361,     6,    -1,   187,   352,
       6,    -1,   179,   239,   330,   240,    -1,   180,   239,   330,
     240,    -1,   181,    -1,   182,    -1,   137,   341,   243,   301,
     244,    -1,   137,   243,   341,   248,   341,   248,   330,   244,
     243,   301,   244,    -1,   137,   243,   341,   248,   341,   248,
     341,   248,   330,   244,   243,   301,   244,    -1,    -1,   137,
     341,   243,   301,   311,   315,   244,    -1,    -1,   137,   243,
     341,   248,   341,   248,   330,   244,   243,   301,   312,   315,
     244,    -1,    -1,   137,   243,   341,   248,   341,   248,   341,
     248,   330,   244,   243,   301,   313,   315,   244,    -1,    -1,
     137,   243,   301,   314,   315,   244,    -1,   137,   243,   301,
     244,   129,   109,   243,   330,   244,    -1,   120,   344,    -1,
     124,   120,   344,    -1,   122,   243,   347,   244,   243,   347,
     244,   243,   330,   244,    -1,   316,    -1,   315,   316,    -1,
     154,   243,   330,   244,     6,    -1,   154,   243,   344,   248,
     344,   244,     6,    -1,   155,     6,    -1,   146,     6,    -1,
     146,   330,     6,    -1,   160,     6,    -1,   160,   162,     6,
      -1,   161,     6,    -1,   161,   162,     6,    -1,   156,   239,
     330,   240,     7,   344,   129,   330,     6,    -1,   129,     4,
     241,   330,   242,     6,    -1,   140,    -1,   141,    -1,   142,
      -1,   143,    -1,   144,    -1,    -1,   149,     6,    -1,   132,
     149,     6,    -1,   149,   330,     6,    -1,   132,   149,   330,
       6,    -1,   317,   243,   301,   318,   244,   243,   301,   318,
     244,    -1,   106,   239,   351,   240,    -1,   317,   239,   330,
     240,     7,   243,   301,   318,   244,   243,   301,   318,   244,
       6,    -1,    -1,   129,     4,   330,    -1,    -1,     4,    -1,
      -1,     7,   344,    -1,    -1,     7,   330,    -1,    -1,   139,
     344,    -1,   111,   112,   345,     7,   330,     6,    -1,   125,
      94,   345,     7,   330,   321,     6,    -1,   125,    97,   345,
     323,   322,     6,    -1,   125,    99,   345,   323,     6,    -1,
     163,   345,     6,    -1,    89,    91,   239,   330,   248,   330,
     240,     6,    -1,    89,    94,   239,   330,   248,   330,   240,
       6,    -1,    89,    97,   239,   330,   248,   330,   240,     6,
      -1,    89,    99,   239,   330,   248,   330,   240,     6,    -1,
     152,    97,   243,   347,   244,     7,   330,     6,    -1,   146,
      97,   345,   324,     6,    -1,   146,    99,   345,     6,    -1,
     147,    97,   345,     7,   330,     6,    -1,   128,    94,   243,
     347,   244,     7,   243,   347,   244,   325,     6,    -1,   128,
      97,   243,   347,   244,     7,   243,   347,   244,   325,     6,
      -1,   128,    94,   243,   347,   244,     7,   243,   347,   244,
     133,   243,   341,   248,   341,   248,   330,   244,     6,    -1,
     128,    97,   243,   347,   244,     7,   243,   347,   244,   133,
     243,   341,   248,   341,   248,   330,   244,     6,    -1,   128,
      94,   243,   347,   244,     7,   243,   347,   244,   134,   341,
       6,    -1,   128,    97,   243,   347,   244,     7,   243,   347,
     244,   134,   341,     6,    -1,   128,    97,   330,   243,   347,
     244,     7,   330,   243,   347,   244,     6,    -1,   295,   243,
     347,   244,   177,   295,   243,   330,   244,     6,    -1,   153,
     297,   345,     6,    -1,   117,   298,   345,     6,    -1,   118,
      99,   344,     6,    -1,   131,    94,   344,     6,    -1,   127,
     296,   344,     6,    -1,   150,     6,    -1,   150,     4,     6,
      -1,   150,    91,   243,   347,   244,     6,    -1,   198,    -1,
     199,    -1,   200,    -1,   328,     6,    -1,   328,   243,   344,
     244,     6,    -1,   328,   243,   344,   248,   344,   244,     6,
      -1,   328,   239,   344,   240,   243,   344,   248,   344,   244,
       6,    -1,   331,    -1,   239,   330,   240,    -1,   228,   330,
      -1,   227,   330,    -1,   234,   330,    -1,   330,   228,   330,
      -1,   330,   227,   330,    -1,   330,   229,   330,    -1,   330,
     230,   330,    -1,   330,   232,   330,    -1,   330,   233,   330,
      -1,   330,   231,   330,    -1,   330,   238,   330,    -1,   330,
     221,   330,    -1,   330,   222,   330,    -1,   330,   226,   330,
      -1,   330,   225,   330,    -1,   330,   220,   330,    -1,   330,
     219,   330,    -1,   330,   218,   330,    -1,   330,   217,   330,
      -1,   330,   223,   330,    -1,   330,   224,   330,    -1,   330,
     216,   330,     8,   330,    -1,    16,   273,   330,   274,    -1,
      17,   273,   330,   274,    -1,    18,   273,   330,   274,    -1,
      19,   273,   330,   274,    -1,    20,   273,   330,   274,    -1,
      21,   273,   330,   274,    -1,    22,   273,   330,   274,    -1,
      23,   273,   330,   274,    -1,    24,   273,   330,   274,    -1,
      26,   273,   330,   274,    -1,    27,   273,   330,   248,   330,
     274,    -1,    28,   273,   330,   274,    -1,    29,   273,   330,
     274,    -1,    30,   273,   330,   274,    -1,    31,   273,   330,
     274,    -1,    32,   273,   330,   274,    -1,    33,   273,   330,
     274,    -1,    34,   273,   330,   274,    -1,    35,   273,   330,
     274,    -1,    36,   273,   330,   248,   330,   274,    -1,    37,
     273,   330,   248,   330,   274,    -1,    38,   273,   330,   248,
     330,   274,    -1,    25,   273,   330,   274,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   205,    -1,
     206,    -1,   207,    -1,    75,    -1,    76,    -1,    77,    -1,
      -1,    82,   273,   330,   332,   283,   274,    -1,   335,    -1,
     196,   273,   351,   274,    -1,   196,   273,   351,   248,   330,
     274,    -1,   337,    -1,   361,   241,   330,   242,    -1,   361,
     239,   330,   240,    -1,   201,   239,   337,   240,    -1,   201,
     239,   337,   245,   338,   240,    -1,   203,   239,   337,   333,
     240,    -1,   203,   239,   337,   245,   338,   333,   240,    -1,
     203,   239,   337,   273,   330,   274,   333,   240,    -1,   203,
     239,   337,   245,   338,   273,   330,   274,   333,   240,    -1,
     202,   239,   352,   240,    -1,   246,   361,   273,   274,    -1,
     246,   337,   245,   338,   273,   274,    -1,    85,   273,   361,
     274,    -1,    85,   273,   274,    -1,   361,   272,    -1,   361,
     241,   330,   242,   272,    -1,   361,   239,   330,   240,   272,
      -1,   361,   245,   338,    -1,   361,     9,   361,   245,   338,
      -1,   361,   245,   338,   239,   330,   240,    -1,   361,     9,
     361,   245,   338,   239,   330,   240,    -1,   361,   245,   338,
     241,   330,   242,    -1,   361,     9,   361,   245,   338,   241,
     330,   242,    -1,   361,   241,   330,   242,   245,     4,    -1,
     361,   245,     4,   272,    -1,   361,   241,   330,   242,   245,
       4,   272,    -1,   192,   239,   351,   248,   330,   240,    -1,
      56,   239,   344,   248,   344,   240,    -1,    57,   273,   351,
     248,   351,   274,    -1,    55,   273,   351,   274,    -1,    58,
     273,   351,   248,   351,   274,    -1,    63,   239,   358,   240,
      -1,    -1,   248,   330,    -1,    -1,   248,   351,    -1,    -1,
      83,   337,   340,   336,   241,   284,   242,    -1,   361,    -1,
     361,     9,   361,    -1,     4,    -1,    86,    -1,    86,   330,
      -1,    -1,   239,   339,   240,    -1,   342,    -1,   228,   341,
      -1,   227,   341,    -1,   341,   228,   341,    -1,   341,   227,
     341,    -1,   243,   330,   248,   330,   248,   330,   248,   330,
     248,   330,   244,    -1,   243,   330,   248,   330,   248,   330,
     248,   330,   244,    -1,   243,   330,   248,   330,   248,   330,
     244,    -1,   239,   330,   248,   330,   248,   330,   240,    -1,
     344,    -1,   343,   248,   344,    -1,   330,    -1,   346,    -1,
     243,   244,    -1,   243,   347,   244,    -1,   228,   243,   347,
     244,    -1,   330,   229,   243,   347,   244,    -1,   344,    -1,
     243,     8,   244,    -1,     5,    -1,   228,   346,    -1,   330,
     229,   346,    -1,   330,     8,   330,    -1,   330,     8,   330,
       8,   330,    -1,    91,   243,   330,   244,    -1,    91,   243,
       8,   244,    -1,    91,     5,    -1,   296,   243,     8,   244,
      -1,   296,     5,    -1,   126,   295,   345,    -1,   295,   177,
      64,   243,   330,   248,   330,   248,   330,   248,   330,   248,
     330,   248,   330,   244,    -1,    64,   295,   243,   330,   244,
      -1,   299,    -1,   310,    -1,   319,    -1,   361,   273,   274,
      -1,   361,   245,   338,   273,   274,    -1,   361,     9,   361,
     245,   338,   273,   274,    -1,    39,   241,   361,   242,    -1,
      39,   241,   346,   242,    -1,    39,   239,   346,   240,    -1,
      39,   273,   243,   347,   244,   274,    -1,   361,   273,   243,
     347,   244,   274,    -1,    40,   273,   330,   248,   330,   248,
     330,   274,    -1,    41,   273,   330,   248,   330,   248,   330,
     274,    -1,    42,   273,   351,   274,    -1,    43,   273,   330,
     248,   330,   248,   330,   248,   330,   248,   330,   248,   330,
     274,    -1,   197,   273,   346,   274,    -1,    32,   273,   346,
     274,    -1,   330,    -1,   346,    -1,   347,   248,   330,    -1,
     347,   248,   346,    -1,   243,   330,   248,   330,   248,   330,
     248,   330,   244,    -1,   243,   330,   248,   330,   248,   330,
     244,    -1,   361,    -1,     4,   245,   174,   245,     4,    -1,
     243,   350,   244,    -1,   361,   241,   330,   242,   245,   175,
      -1,   348,    -1,   350,   248,   348,    -1,   352,    -1,   361,
      -1,   361,   241,   330,   242,    -1,   361,   239,   330,   240,
      -1,   361,   245,   338,    -1,   361,     9,   361,   245,   338,
      -1,   361,   245,   338,   239,   330,   240,    -1,   361,     9,
     361,   245,   338,   239,   330,   240,    -1,   361,   241,   330,
     242,   245,     4,    -1,   126,    91,   243,   330,   244,    -1,
     126,    94,   243,   330,   244,    -1,   126,    97,   243,   330,
     244,    -1,   126,    99,   243,   330,   244,    -1,     5,    -1,
     210,   241,   361,   242,    -1,    67,    -1,   208,    -1,    72,
      -1,    74,    -1,   194,   239,   351,   240,    -1,   193,   239,
     351,   248,   351,   240,    -1,   195,   273,   351,   274,    -1,
     195,   273,   351,   248,   351,   274,    -1,   204,   239,   337,
     334,   240,    -1,   204,   239,   337,   245,   338,   334,   240,
      -1,    48,   273,   358,   274,    -1,    49,   239,   351,   240,
      -1,    50,   239,   351,   240,    -1,    51,   239,   351,   248,
     351,   248,   351,   240,    -1,    46,   273,   358,   274,    -1,
      60,   273,   351,   274,    -1,    61,   273,   351,   274,    -1,
      62,   273,   351,   274,    -1,    59,   273,   330,   248,   351,
     248,   351,   274,    -1,    54,   273,   351,   248,   330,   248,
     330,   274,    -1,    54,   273,   351,   248,   330,   274,    -1,
      47,   273,   351,   274,    -1,    47,   273,   351,   248,   347,
     274,    -1,    68,   273,   351,   274,    -1,    69,    -1,    53,
     273,   351,   274,    -1,    52,   273,   351,   274,    -1,    -1,
      87,   273,   352,   353,   287,   274,    -1,    84,   273,   354,
     274,    -1,   246,   330,    -1,   361,     9,   246,   330,    -1,
      46,   273,   357,   274,    -1,   358,    -1,   357,    -1,   243,
     358,   244,    -1,   351,    -1,   359,    -1,   358,   248,   351,
      -1,   358,   248,   359,    -1,   361,   239,   240,    -1,   361,
     245,   338,   239,   240,    -1,   361,     9,   361,   245,   338,
     239,   240,    -1,     4,   247,   243,   330,   244,    -1,   360,
     247,   243,   330,   244,    -1,   211,   241,   351,   242,   247,
     243,   330,   244,    -1,     4,    -1,   360,    -1,   211,   241,
     351,   242,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   267,   267,   268,   273,   275,   279,   280,   281,   282,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   320,   324,   331,   336,
     341,   355,   368,   381,   409,   423,   436,   449,   468,   473,
     474,   475,   476,   477,   481,   483,   488,   490,   496,   600,
     495,   618,   625,   636,   635,   653,   660,   671,   670,   687,
     704,   727,   726,   740,   741,   742,   743,   744,   748,   749,
     755,   755,   756,   756,   762,   763,   764,   765,   770,   776,
     838,   853,   882,   892,   897,   905,   910,   918,   927,   932,
     944,   961,   967,   976,   994,  1012,  1021,  1033,  1038,  1046,
    1066,  1089,  1107,  1115,  1122,  1129,  1151,  1174,  1212,  1233,
    1245,  1259,  1259,  1261,  1263,  1272,  1282,  1281,  1302,  1301,
    1319,  1329,  1328,  1342,  1344,  1352,  1358,  1363,  1389,  1391,
    1394,  1396,  1400,  1401,  1405,  1417,  1430,  1445,  1454,  1467,
    1469,  1473,  1474,  1479,  1487,  1496,  1504,  1518,  1536,  1540,
    1547,  1556,  1559,  1565,  1569,  1581,  1584,  1591,  1614,  1630,
    1646,  1683,  1723,  1739,  1755,  1787,  1803,  1822,  1838,  1888,
    1906,  1912,  1918,  1925,  1956,  1971,  1993,  2016,  2039,  2062,
    2086,  2110,  2134,  2160,  2177,  2193,  2211,  2229,  2236,  2245,
    2244,  2274,  2276,  2278,  2280,  2282,  2290,  2292,  2294,  2296,
    2304,  2306,  2308,  2316,  2318,  2320,  2322,  2332,  2348,  2364,
    2380,  2396,  2412,  2449,  2471,  2495,  2496,  2501,  2504,  2508,
    2524,  2542,  2560,  2585,  2604,  2625,  2640,  2656,  2674,  2725,
    2746,  2768,  2791,  2896,  2912,  2947,  2969,  2991,  2997,  3012,
    3040,  3052,  3061,  3068,  3080,  3099,  3103,  3108,  3112,  3117,
    3124,  3131,  3138,  3150,  3224,  3242,  3259,  3274,  3307,  3319,
    3343,  3347,  3352,  3359,  3364,  3374,  3379,  3385,  3393,  3397,
    3406,  3470,  3486,  3503,  3520,  3542,  3564,  3599,  3607,  3615,
    3621,  3628,  3635,  3655,  3681,  3693,  3704,  3722,  3740,  3759,
    3758,  3783,  3782,  3809,  3808,  3833,  3832,  3855,  3871,  3888,
    3905,  3928,  3931,  3937,  3949,  3969,  3973,  3977,  3981,  3985,
    3989,  3993,  3997,  4006,  4019,  4020,  4021,  4022,  4023,  4027,
    4028,  4029,  4030,  4031,  4034,  4058,  4077,  4100,  4103,  4119,
    4122,  4139,  4142,  4148,  4151,  4158,  4161,  4168,  4190,  4231,
    4275,  4314,  4339,  4351,  4363,  4375,  4387,  4396,  4426,  4452,
    4478,  4510,  4537,  4563,  4589,  4615,  4641,  4663,  4674,  4722,
    4776,  4791,  4803,  4814,  4821,  4836,  4850,  4851,  4852,  4856,
    4862,  4874,  4892,  4920,  4921,  4922,  4923,  4924,  4925,  4926,
    4927,  4928,  4935,  4936,  4937,  4938,  4939,  4940,  4941,  4942,
    4943,  4944,  4945,  4946,  4947,  4948,  4949,  4950,  4951,  4952,
    4953,  4954,  4955,  4956,  4957,  4958,  4959,  4960,  4961,  4962,
    4963,  4964,  4965,  4966,  4967,  4968,  4969,  4970,  4971,  4972,
    4981,  4982,  4983,  4984,  4985,  4986,  4987,  4988,  4989,  4990,
    4991,  4996,  4995,  5003,  5005,  5010,  5015,  5019,  5024,  5029,
    5033,  5037,  5041,  5045,  5049,  5053,  5059,  5075,  5080,  5086,
    5092,  5111,  5132,  5165,  5169,  5174,  5178,  5182,  5186,  5191,
    5196,  5206,  5216,  5221,  5232,  5241,  5246,  5251,  5279,  5280,
    5286,  5287,  5293,  5292,  5315,  5317,  5322,  5331,  5333,  5339,
    5340,  5345,  5349,  5353,  5357,  5361,  5368,  5372,  5376,  5380,
    5387,  5392,  5399,  5404,  5408,  5413,  5417,  5425,  5436,  5440,
    5444,  5458,  5466,  5474,  5481,  5491,  5514,  5519,  5525,  5530,
    5536,  5547,  5553,  5558,  5568,  5578,  5588,  5600,  5604,  5609,
    5621,  5625,  5629,  5633,  5651,  5659,  5667,  5696,  5706,  5722,
    5733,  5738,  5742,  5746,  5758,  5762,  5774,  5791,  5801,  5805,
    5820,  5825,  5832,  5836,  5841,  5855,  5871,  5875,  5879,  5883,
    5887,  5895,  5901,  5907,  5913,  5922,  5926,  5930,  5938,  5944,
    5950,  5954,  5962,  5970,  5977,  5986,  5990,  5994,  6009,  6023,
    6037,  6049,  6065,  6074,  6083,  6093,  6104,  6112,  6120,  6124,
    6143,  6150,  6156,  6163,  6171,  6170,  6180,  6204,  6206,  6212,
    6217,  6219,  6224,  6229,  6234,  6236,  6240,  6252,  6266,  6270,
    6277,  6285,  6293,  6304,  6306,  6309
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
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     465,   466,   467,   468,   469,   470,    63,   471,   472,   473,
     474,    60,    62,   475,   476,   477,   478,    43,    45,    42,
      47,    37,   124,    38,    33,   479,   480,   481,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   249,   250,   250,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   253,   253,   254,   254,
     254,   254,   254,   254,   255,   255,   255,   255,   256,   256,
     256,   256,   256,   256,   257,   257,   258,   258,   260,   261,
     259,   262,   262,   264,   263,   265,   265,   267,   266,   268,
     268,   270,   269,   271,   271,   271,   271,   271,   272,   272,
     273,   273,   274,   274,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   276,   276,   277,   277,   277,   278,   277,   279,   277,
     277,   280,   277,   281,   281,   282,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   286,   286,   286,   287,
     287,   288,   288,   289,   289,   289,   289,   289,   290,   290,
     290,   291,   291,   291,   291,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   294,
     293,   295,   295,   295,   295,   295,   296,   296,   296,   296,
     297,   297,   297,   298,   298,   298,   298,   299,   299,   299,
     299,   299,   299,   299,   299,   300,   300,   301,   301,   301,
     301,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   304,   304,   305,   306,   306,   306,   306,   306,
     306,   306,   306,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   308,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   310,   310,   310,   311,
     310,   312,   310,   313,   310,   314,   310,   310,   310,   310,
     310,   315,   315,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   317,   317,   317,   317,   317,   318,
     318,   318,   318,   318,   319,   319,   320,   321,   321,   322,
     322,   323,   323,   324,   324,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   327,   327,   327,   328,   328,   328,   329,
     329,   329,   329,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   332,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   333,   333,
     334,   334,   336,   335,   337,   337,   338,   339,   339,   340,
     340,   341,   341,   341,   341,   341,   342,   342,   342,   342,
     343,   343,   344,   344,   344,   344,   344,   344,   345,   345,
     345,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     347,   347,   347,   347,   348,   348,   348,   348,   349,   349,
     350,   350,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   353,   352,   352,   354,   354,   355,
     356,   356,   357,   358,   358,   358,   358,   359,   359,   359,
     360,   360,   360,   361,   361,   361
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
       7,     6,     7,     8,    10,    14,    16,    12,    14,    14,
      14,    14,     8,     8,     6,     4,     5,     6,     6,     3,
       4,     3,     5,     6,     5,     4,     3,     4,     3,     4,
       5,     4,     5,     3,     5,     7,     7,     3,     7,     3,
       2,     2,     2,     2,     2,    15,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     9,     2,     3,
      10,     1,     2,     5,     7,     2,     2,     3,     2,     3,
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
       3,    16,     5,     1,     1,     1,     3,     5,     7,     4,
       4,     4,     6,     6,     8,     8,     4,    14,     4,     4,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     3,     5,     6,     8,
       6,     5,     5,     5,     5,     1,     4,     1,     1,     1,
       1,     4,     6,     4,     6,     5,     7,     4,     4,     4,
       8,     4,     4,     4,     4,     8,     8,     6,     4,     6,
       4,     1,     4,     4,     0,     6,     4,     2,     4,     4,
       1,     1,     3,     1,     1,     3,     3,     3,     5,     7,
       5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,     0,   192,     0,     0,
     193,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314,   315,   316,
     317,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,   284,   285,     0,     0,     0,   279,
       0,     0,     0,     0,     0,   366,   367,   368,     0,     0,
       5,     6,     7,     8,    10,     0,    11,    24,    12,    13,
      14,    15,    23,    22,    21,    16,     0,    17,    18,    19,
      20,     0,    25,     0,   604,     0,   217,     0,     0,     0,
       0,     0,   264,     0,   266,   267,   262,   263,     0,   268,
     113,   123,   603,   479,   474,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,   203,   204,   205,
       0,     0,     0,     0,   420,   421,   423,   424,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   428,   429,   430,     0,     0,   191,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   425,   426,   427,     0,     0,     0,     0,     0,
       0,     0,     0,   513,   514,     0,   515,   492,   373,   433,
     436,   298,   493,   474,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   189,   196,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   603,     0,     0,   217,     0,     0,
     363,     0,     0,     0,   200,   201,     0,     0,     0,     0,
       0,   500,     0,     0,   498,     0,     0,     0,     0,     0,
     603,     0,     0,   536,     0,     0,     0,     0,   260,   261,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   557,     0,   581,   559,   560,
       0,     0,     0,     0,     0,     0,   558,     0,     0,     0,
       0,   277,   278,     0,   217,     0,   217,     0,     0,     0,
     474,     0,     0,     0,   217,   369,     0,     0,    76,     0,
      63,     0,     0,    67,    66,    65,    64,    69,    68,    70,
      71,     0,     0,     0,     0,     0,     0,   542,   474,     0,
     216,     0,   215,     0,   170,     0,     0,   542,   543,     0,
       0,   593,     0,   594,   543,   111,   111,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   530,
     531,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,     0,   375,   501,   377,
       0,   494,     0,     0,   474,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,   450,     0,     0,     0,     0,     0,     0,   299,
       0,   331,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,     0,   217,   217,     0,   483,   482,     0,
       0,     0,     0,   217,   217,     0,     0,     0,     0,   295,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,   241,     0,
       0,   239,   364,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   341,   259,     0,     0,     0,     0,     0,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   280,     0,
     246,     0,     0,   248,     0,     0,     0,   375,     0,   217,
       0,     0,     0,     0,     0,     0,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    72,    73,     0,     0,   257,    38,
     253,     0,     0,     0,     0,     0,   212,     0,     0,     0,
       0,   218,     0,     0,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,   477,     0,     0,   475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   325,
       0,     0,     0,   195,     0,     0,     0,     0,     0,     0,
     359,   360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   431,   449,     0,     0,     0,     0,   510,     0,
       0,     0,     0,     0,   468,     0,   374,   495,     0,     0,
       0,     0,   503,     0,   393,   392,   391,   390,   386,   387,
     394,   395,   389,   388,   379,   378,     0,   380,   502,   381,
     384,   382,   383,   385,   475,     0,     0,   476,   453,     0,
     516,     0,     0,     0,     0,     0,     0,     0,   329,     0,
       0,     0,     0,   362,     0,     0,     0,     0,   361,     0,
     217,     0,     0,     0,     0,     0,   485,   484,     0,     0,
       0,     0,     0,     0,     0,   289,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,   240,     0,     0,   235,     0,     0,     0,     0,   358,
       0,     0,     0,   374,   499,     0,     0,     0,     0,     0,
       0,     0,     0,   282,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   584,     0,     0,     0,   470,     0,     0,
     245,   249,   247,   251,     0,   380,     0,   475,   453,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,   374,     0,    63,     0,     0,
       0,     0,    79,     0,    63,    64,     0,     0,   475,     0,
       0,   453,     0,     0,     0,   189,     0,     0,   600,    28,
      26,    27,     0,     0,     0,     0,     0,   476,   546,    29,
       0,     0,   254,   595,   596,     0,   597,   546,    74,   114,
      75,   124,   478,   480,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,   533,   206,     9,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   419,   406,     0,   408,   409,
     410,   411,   412,   529,   413,   414,   415,     0,     0,     0,
     521,   520,   519,     0,     0,     0,   526,     0,   465,     0,
       0,     0,   467,     0,   128,   448,   506,   505,   199,     0,
       0,   434,   528,   439,     0,   445,     0,     0,     0,     0,
     496,     0,     0,   446,     0,   508,     0,     0,     0,     0,
     438,   437,   460,    70,    71,     0,     0,     0,     0,     0,
       0,   374,   327,   332,   330,     0,   340,     0,   148,   149,
     199,   374,     0,     0,     0,     0,   236,     0,   250,   252,
       0,     0,     0,   207,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   301,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     334,   347,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,   242,     0,
       0,     0,     0,   571,     0,   578,   567,   568,   569,     0,
     583,   582,     0,     0,   572,   573,   574,   580,   587,   586,
       0,   139,     0,   561,     0,   563,     0,     0,     0,   556,
       0,   244,     0,     0,     0,     0,     0,     0,     0,   320,
       0,     0,     0,   370,     0,   601,     0,     0,     0,     0,
     101,    63,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    61,     0,    39,    40,    41,    42,    43,     0,
     438,   437,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   545,   544,     0,     0,     0,     0,     0,
       0,     0,   135,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,   155,   155,     0,     0,     0,     0,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     337,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   512,     0,     0,     0,     0,     0,
     468,   469,     0,   441,     0,     0,     0,   504,   396,   497,
     454,   452,     0,   451,     0,     0,   517,     0,     0,     0,
       0,     0,     0,     0,     0,   339,     0,     0,     0,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,   305,     0,   308,     0,   310,     0,
     296,   302,     0,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,   238,   237,   365,     0,
       0,    35,    36,     0,     0,     0,     0,   537,     0,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,   471,   565,     0,   454,
       0,     0,   217,   321,     0,   322,   217,     0,     0,   551,
     552,   553,   554,     0,    86,     0,     0,     0,     0,    84,
      91,    93,     0,   540,     0,    99,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    34,   454,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,   547,     0,     0,    32,     0,   547,   598,     0,
     115,   120,     0,     0,     0,   134,   137,   138,   473,     0,
      77,     0,     0,     0,     0,    78,   157,     0,     0,     0,
       0,   158,   173,   174,     0,     0,     0,     0,   159,   184,
     175,   179,   180,   176,   177,   178,   165,     0,     0,   407,
     416,   417,   418,   522,     0,     0,     0,   463,   464,   466,
     129,   432,   462,   435,   440,     0,     0,   468,   185,   447,
       0,    70,    71,     0,   459,   455,   457,   523,   181,     0,
       0,   151,     0,     0,   338,     0,   150,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   217,   217,     0,     0,
     307,   492,     0,     0,   309,   311,     0,     0,   290,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,   162,   163,     0,     0,     0,     0,
     102,   103,   104,   108,     0,   579,     0,     0,   577,     0,
     588,     0,     0,   140,   141,   585,   562,   564,     0,     0,
       0,     0,     0,     0,   319,   323,   319,     0,   371,    85,
      63,     0,     0,     0,     0,    83,     0,   538,     0,     0,
       0,     0,     0,     0,   591,   590,     0,     0,     0,     0,
       0,   490,     0,     0,   459,   255,   455,   256,     0,     0,
       0,     0,   221,   219,     0,     0,   550,   548,     0,     0,
     116,   121,     0,     0,     0,   530,   531,   133,   342,   343,
     344,   345,   156,   160,   161,   166,   183,     0,     0,     0,
     168,     0,     0,     0,     0,     0,     0,   442,     0,     0,
       0,     0,   518,   461,     0,   167,     0,   186,   328,     0,
       0,   187,     0,     0,     0,     0,     0,     0,   489,   488,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   232,     0,     0,     0,     0,     0,     0,     0,     0,
     223,     0,     0,   346,    37,     0,   535,     0,     0,   274,
     273,     0,     0,     0,     0,     0,     0,   143,   144,   147,
     146,   145,     0,   566,     0,   602,     0,     0,     0,     0,
       0,     0,    96,     0,     0,    97,   541,     0,     0,     0,
      88,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      46,     0,   222,   220,    33,     0,     0,   599,   128,   139,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   524,   525,     0,   468,   443,     0,   456,   458,     0,
     169,   190,     0,   335,   335,     0,   109,   110,   217,     0,
     210,   211,   297,     0,   303,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   213,     0,     0,
       0,     0,   105,   106,   570,   576,   575,   142,     0,     0,
       0,   324,     0,    92,    94,     0,   100,     0,    82,   592,
      89,    90,    49,     0,     0,     0,     0,   491,     0,     0,
     456,   549,     0,     0,     0,   118,   589,     0,   125,     0,
       0,     0,     0,   172,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,   313,     0,     0,   291,     0,   224,     0,     0,     0,
       0,     0,     0,     0,   534,   275,     0,     0,   357,   217,
     372,     0,   539,     0,    45,     0,     0,     0,    62,    47,
       0,   117,   122,   128,     0,     0,   153,   154,   152,     0,
       0,   444,     0,     0,     0,     0,   336,   350,     0,     0,
     351,     0,   208,     0,   304,     0,   287,     0,   217,     0,
       0,     0,     0,     0,     0,   164,   107,   271,   319,    98,
       0,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,   188,     0,   354,     0,   355,   356,   486,     0,     0,
     293,   227,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    59,     0,     0,   119,     0,     0,     0,     0,
       0,   312,   292,   288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,   231,     0,   225,   326,
      50,     0,    57,     0,   265,     0,   527,     0,     0,     0,
     294,     0,     0,    51,     0,     0,   270,     0,     0,     0,
     226,     0,     0,     0,     0,   511,     0,     0,    54,    52,
       0,    55,     0,   352,   353,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   110,  1032,   111,   112,  1017,  1843,  1849,
    1304,  1511,  1993,  2122,  1305,  2093,  2140,  1306,  2124,  1307,
    1308,  1515,   422,   572,   573,  1102,   113,   751,   445,  1858,
    2003,  1859,   446,  1734,  1376,  1333,  1334,  1335,  1472,  1673,
    1674,  1167,  1567,  1558,   731,   583,   261,   262,   337,   191,
     263,   431,   432,   117,   118,   119,   120,   121,   122,   123,
     124,   264,  1199,  2027,  2084,   913,  1195,  1196,   265,   994,
     266,   128,  1404,  1165,   888,   927,  1963,   129,   130,   131,
     132,   267,   268,  1124,  1139,  1258,   269,   756,   270,   878,
     755,   448,   598,   306,  1710,   344,   345,   272,   542,   352,
    1292,  1504,   441,   437,  1251,   971,  1547,  1703,  1704,   956,
     443,   134,   400
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1826
static const yytype_int16 yypact[] =
{
   11051,    58,    52, 11202, -1826, -1826,  -149,    60,   -12,  -143,
    -104,    47,   138,   173,   190,   213,    -8,   257,    63,    70,
      26,   314,   613,   314,     4,    75,    82,    30,   132,   150,
      45,   153,   175,   206,   228,   240,   254,   259,   262,   271,
     282,   105,   171,   284,   411,   231,   589,   436,   309,  6166,
     389,   315,   469,   -36,   708,   523,   514,   176,   399,   554,
     -86,   431,   -87,   -87,   454,   -14,   386, -1826, -1826, -1826,
   -1826, -1826,   412,   601,   611,   628,    24,    66,   633,   622,
     303,   732,   740,   741,  5218,   747,   513,   543,   548,    16,
      56, -1826,   631,   638, -1826, -1826,   765,   787,   600, -1826,
   11399,   665, 11451,    31,    38, -1826, -1826, -1826, 10880,   639,
   -1826, -1826, -1826, -1826, -1826,   571, -1826, -1826, -1826, -1826,
   -1826, -1826, -1826, -1826, -1826, -1826,   -44, -1826, -1826, -1826,
   -1826,    48, -1826,   834,   664,  4965,   349,   689,   909, 10880,
   11370, 11370, -1826, 10880, -1826, -1826, -1826, -1826, 11370, -1826,
   -1826, -1826,   698,   711,   947, -1826, -1826, 11565,   721,   725,
     729,   748,    26, 10880, 10880, 10880,   752, 10880, 10880, 10880,
     753, 10880, 10880, 10880, 10880, 10880, 10880, 10880, 11370, 10880,
   10880, 10880, 10880,  5218,   754, -1826,  8763, -1826, -1826, -1826,
     728,  5218,  6403, 11370, -1826, -1826, -1826, -1826, -1826,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   470,   314,   314,   314,   314,   314,   756,   314,
     314,   757,   523, -1826, -1826, -1826,   314,   314,    42,   809,
     813,   821,   758,  6403,   879,   523,   761,   314,   314,   763,
     764,   766, -1826, -1826, -1826, 10880,  6640, 10880, 10880,  6877,
      26,   827,    43, -1826, -1826,   767, -1826,  4838, -1826, -1826,
   -1826, -1826, -1826,   127, 10880,  8763,   768,   770,  7114,  5218,
    5218,  5218, -1826, -1826, -1826, -1826, -1826, -1826, -1826, -1826,
     769,  7351,   771,  4077,  1007,  6403,   772,    16,   773,   774,
     -87,   -87,   -87, 10880, 10880,     5, -1826,   391,   -87,  9634,
     419,   265,   779,   782,   783,   784,   788,   789,   791, 10880,
    5218,  5218,  5218,   798,     8,  1020,   810, -1826,  1044,  1046,
   -1826,   811,   812,   814, -1826, -1826,   815,  5218,   820,   835,
     836, -1826, 10880,  5455, -1826,  1047,  1050, 10880, 10880, 10880,
     614, 10880,   837, -1826,   902, 10880, 10880, 10880, -1826, -1826,
   10880, -1826,   314,   314,   314,   842,   843,   844,   314,   314,
     314,   314,   314,   314,   314, -1826,   314, -1826, -1826, -1826,
     314,   314,   845,   846,   314,   847, -1826,   866,  1081,  1102,
     869, -1826, -1826,  1103,  1106,  1113,  1112,   314, 10880, 13515,
     141, 11370,  8763, 10880, -1826, -1826,  6403,  6403, -1826,   878,
   11565,   632,  1115, -1826, -1826, -1826, -1826, -1826, -1826, 10880,
   10880,    33,  6403,  1117,   715,  2595,   881,  1119,   102,   884,
   -1826,   885, 10908, 10880, -1826,  2829,   -30, -1826,    57,   -10,
   10213, -1826,    10, -1826,    62,  -153,   -84,  1042, -1826,    26,
     882, 10880, 10880, 10880, 10880,   883,  4733, 14031, 14056, 10880,
   14081, 14106, 14131, 10880, 14156, 14181, 14206, 14231, 14256, 14281,
   14306,   892, 14331, 14356, 14381,  4470,  1126, 10880,  8763,  4876,
   -1826,   327, 10880,  1128,  1129,   896, 10880, 10880, 10880, 10880,
   10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880,
   10880, 10880,  8763, 10880, 10880, 10880, 10880, 10880, 10880,  8763,
    8763,   894, 10880, 10880, 11370, 10880, 11370,  6403, 11370, 11370,
   11370,   897, 10880,    40, -1826,  9710, 10880,  6403,  5218, 11370,
   11370,  8763,    26, 11565,    26,   901,  8763,   901, -1826,   901,
   14406, -1826,   368,   898,    81,  1078, -1826,  1136, 10880, 10880,
   10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880,
   10880, 10880,  7588, 10880, 10880, 10880, 10880, 10880,    26, 10880,
   10880,  1141, -1826,   719, 14431,   377, 10880, 10880, 10880, -1826,
    1140,  1142,  1142,   911, 10880, 10880,  1145,  8763,  8763, 13543,
     908,  1146, -1826,   913, -1826, -1826,  -148, -1826, -1826, 10289,
   10518,   -87,   -87,   349,   349,  -145,  9634,  9634, 10880,  3746,
     -97, -1826, 10880, 10880, 10880, 10880, 10880, 10880, 10880, 10880,
   10880, 14456,  1151,  1171,  1175, 10880,  1178, 10880, -1826, 10880,
    5522, -1826, -1826,  8763,  8763,  8763, 10880,  1179, 10880, 10880,
   10880, 14481,   942, -1826, -1826, 14506, 14531, 14556,  1014, 10604,
   -1826,   946,  5166, 14581, 14606, 13626, 11370, 11370, 11370, 11370,
   11370, 11370, 11370, 11370, 11370, 10880, 11370, 11370, 11370, 11370,
      15, 11565, 11370, 11370, 11370,    26,    26, -1826, -1826,  8763,
   -1826,   951,  5759, -1826,   952,  5996, 10880,   901, 10880, -1826,
      26, 10880, 10880,  1141,   948,   396, 14631,  1644,   958,   440,
   10880,  1193,   957,   959,   960,   961,  6403, 14656, 13653,   193,
     956,  1198,  1201, -1826, -1826, -1826,  8763,   235, -1826, -1826,
   -1826,    26, 10880, 10880,  1141,   968, -1826,   971,   -28,   523,
     514, -1826,   969, 12616, -1826,   161,  8763,    26, 10880, 10880,
    1207,  1208,  8763, 10880,  1209, 11370,    26,  9942,  1207,  1210,
   -1826,    26,  1218, 11370, 10880,   973,   978, -1826, 10880, 10750,
   11323, 11446, 11479, 11565,  1219,  1220,  1221, 14681,  1222,  1223,
    1225, 14706,  1226,  1227,  1231,  1232,  1235,  1236,  1237, -1826,
    1238,  1239,  1240, -1826, 10880, 14731,  8763,   982,  8763, 12645,
   -1826, -1826,  1242, 13599, 13599, 13599, 13599, 13599, 13599, 13599,
   13599, 13599, 13599, 13599, 11513, 13599, 13599, 13599, 13599,   873,
     495, 13599, 13599, 13599, 11560, 11593, 11626,  4876,  1010,  1011,
     115,  8763, 11659, 11692,   495, 11725,   495,  1004,  1008,  1009,
     125, 10880, 15631, -1826,   495,  1024, 12674, 12703, -1826,  1022,
     290,   495,   -72,  1015,   -79,   564,  1251, -1826,  1207,   495,
    1028,  1032,  7761,  7993,  1780,  1265,   751,   751,   463,   463,
     463,   463,   463,   463,   559,   559,  8763,    97, -1826,    97,
      97,   901,   901,   901,  1033, 14756, 13680,  -111,   538,  8763,
   -1826,  1270,  1036, 14781, 14806, 14831, 10880,  6403,  1279,  1278,
    9402, 12732, 14856, -1826,   567,   572,  8763,  1045, -1826,  6233,
   -1826,  6470,  6707,   -87, 10880, 10880, -1826, -1826,  1048,  1049,
    9634,  9580,  1160,   -38,   -87,  6944, 14881, 12761, 14906, 14931,
   14956, 14981, 15006, 15031, 15056,  1284, 10880,  1288, -1826, 10880,
   15081, -1826, 13707, 13734, -1826,   573,   575,   578, 12790, -1826,
   13761, 13788, 11758, -1826, -1826,  1289,  1291,  1292,  1057, 10880,
    7181, 10880, 10880, -1826, -1826,    44,   332,   490,   332,  1055,
    1063,  1058,   495,   495,  1059, 11791,   495,   495,   495,   495,
   10880,   495,  1296, -1826,  1061,  1071,   532,   114,  1073,   580,
   -1826, -1826, -1826, -1826, 13599,    97,  7418,  1072,   692,  1069,
    1143,  1312,  1172, 10025,  1079,  1082,  1316,  6403, 12819, -1826,
   10880, 10880, 10880, 10880,  1318,   197,   113, 11565, 10880,  1320,
    1323,    25, -1826,   583,  1282,  1285,  6403,    27,  1085, 15106,
   13815,   103, 10880, 10880,  1093,  1090,  1095,  7825, -1826, -1826,
   -1826, -1826, 11370,   145,  1091, 15131, 13842, -1826,  1096, -1826,
     178, 11824, -1826, -1826, -1826,  1092, -1826,  1099, -1826,    71,
   -1826, -1826, 15631, -1826,  1336, 13599, 10880, 10880, 10880, 10880,
     495,   -87,  6403,  6403,  1334,  6403,  6403,  6403,  1337,  6403,
    6403,  6403,  6403,  6403,  6403,  6403,  6403,  6403,  6403,  2854,
    1338,  8763,  4876, -1826, -1826, -1826, -1826, -1826, -1826, -1826,
   -1826, -1826, -1826, -1826, -1826, -1826, -1826, 10880, -1826, -1826,
   -1826, -1826, -1826, -1826, -1826, -1826, -1826, 10880, 10880, 10880,
   -1826, -1826, -1826,   585, 10880, 10880, -1826, 10880, -1826,  6403,
   11370, 11370, -1826, 12848,  1100, -1826, -1826, -1826,  1166, 10880,
   10880, -1826, -1826, -1826,  1207, -1826,  1207, 10880, 10880,  1107,
   -1826,  6403,   314, -1826, 10880, -1826, 10880, 10880,   586,  1207,
    -111,  -169, -1826, 10880, 10880,   495,   588,  6403,  8763,  1342,
    1343,  1344,  9029, -1826, -1826,  1347, -1826,  1114, 15631,  1108,
   -1826,  1348,  1350,  1351,   591,  1355, -1826,  7655, -1826, -1826,
     -85, 11857, 11890, -1826, -1826, 12877,   -41,  1252,  1356, 10257,
    1122,  1360,  1133,    36,    49,   -27, -1826,   -51, -1826,   -38,
    1361,  1367,  1368,  1369,  1371,  1372,  1373,  1374,  1375,  6403,
   15631, -1826,  2995,  1124,  1378,  1379,  1380,  1277,  1381, -1826,
    1383,  1384, 10880,  6403,  6403,  6403,  1387, 11923, -1826,  8699,
     943,    46,  1389, -1826,  8763, -1826, -1826, -1826, -1826, 11370,
   -1826, -1826, 10880, 11370, -1826, -1826, -1826, -1826, 15631, -1826,
    1148,  1139, 11370, -1826, 11370, -1826,  1207, 11370,  1155, -1826,
    1154, -1826,  1207, 10880, 10880,  1153,   523,  1167, 10340, -1826,
    3019,  1169,  6403, -1826,  1165, -1826, 12906, 12935, 12964, 12993,
   -1826, -1826, 10880,  1407,    41, 10880,  1408,  1409,  3178, -1826,
    1411,    16,  1410,  1181,   495,   314,   314,  1413, -1826,  1186,
    1187,  1184, -1826,  1422, -1826, -1826, -1826, -1826, -1826,  1207,
     442,  1213, 10880, 13869, 15156, 10880,  8057, 10880,  1185,   594,
    1424,   165,  1207, -1826,  1188, 10880,  1426, 10880,  1207, 10572,
    8995,   495,  4431,  1192,  1189, -1826,  1429, 15181, 15206, 15231,
   15256,  1430,   104,  1315,  1315,  6403,  1434,  1435,  1437,  6403,
     -90,  1439,  1440,  1441,  1442,  1445,  1446,  1447,  1448,  1449,
   -1826,  1452,   599, 13599, 13599, 13599, 13599,   495, 11956, 11989,
   12022,  1224,   495,   495, -1826,  1336,   495, 15281, 13599,  1228,
     -67, 15631, 13599, -1826,  1453,   495, 12055, 15631, 15631, -1826,
     697, -1826,  1456, -1826, 15306, 13896, -1826,   495,  1455,   602,
    6403,  6403,  6403,  1458,  1457, -1826,   247, 10880,  6403,  1229,
    1233,  1459,   421, -1826, 10880, 10880, 10880,  1234,  1257,  1258,
    1230, -1826,  3223,  6403, -1826, 10880, -1826,  1461, -1826,  1463,
   -1826, -1826,  9634,   408,  5692, -1826,  1259,  1261,  1264,  1266,
    1267,  1269,  8289,  1464, -1826,  8763, -1826, -1826, -1826,  1271,
   10880, -1826, -1826, 13923,  1468,  1469,  1305, -1826, 10880, 10880,
   10880, -1826,  1473,  1474,  1475,   448,   536,  1217,  9351,  1268,
   10880,    17,   495,  1273,   495,  1272, -1826, -1826, 11565,   724,
   10880,  1274, -1826, -1826,  3407, -1826, -1826,  1276,  1476, -1826,
   -1826, -1826, -1826,  3489, -1826,   227,  1286,  1508,  3573, -1826,
   -1826, -1826,    16, -1826,   604, -1826, 10880,   247,  1774,  2480,
   -1826,  1283, 10880, 10880,  6403,  1275, -1826,   237,  1517,  1523,
   15331,  1524,  1251, 15356,  1294,   607, 15381,  1527,  1529, -1826,
   -1826, 11370,  1300,  1536, 15406, -1826, 12088,  1303, -1826,  4701,
   15631, -1826,  1537,   314,  6877, -1826, -1826, -1826, -1826,  1336,
   -1826,  1539,  1540,  1541,  1542, -1826, -1826,   -87,  1543,  1544,
    1545, -1826, -1826, -1826,  1546,   -33,  1462,  1547, -1826, -1826,
   -1826, -1826, -1826, -1826, -1826, -1826, -1826,  1538,  1311, -1826,
   -1826, -1826, -1826, -1826, 10880, 10880, 10880, -1826, -1826, -1826,
    1189, -1826, -1826, -1826, -1826, 10880,  1319,  1308, -1826, -1826,
   10880, 10880, 10880,   495,  -111, -1826, -1826, -1826, -1826,  1317,
    1552,   -90,  1555, 10880, -1826,  6403, 15631,   963,  8763,  8763,
   10880, -1826,  9402, 13022, 15431,  9666,   349,   349, 10880, 10880,
   -1826,   371,  1314, 15456, -1826, -1826, 13051,   -43, -1826,  1557,
    1558,  6403,   -87,   -87,   -87,   -87,   -87,  5929,  1559, -1826,
     609, 10880,  3717,  1560, -1826, -1826,  6403,  9898,   537, 15481,
   -1826, -1826, -1826, -1826,  9080, -1826, 11370, 10880, -1826, 11370,
   15631,  9317, 11565,  1322, -1826, -1826, -1826, -1826,  1327,  1324,
   10880, 10880, 13080, 10880,  1644, -1826,  1644,  6403, -1826, -1826,
   11565, 10880,  1562,  1567,    25, -1826,  1568, -1826,    16, 13950,
    6403, 11370,  1569,   495, -1826,  1325,   495, 10880, 12121, 12154,
     610, -1826, 10880, 10880,   504, -1826,  1335, -1826,  1344,  1573,
    1574,  1348, -1826, -1826,  1575, 10880, -1826, -1826, 10880, 10648,
   -1826, -1826,  1339,  2480,   616,  4372,  1578, -1826, -1826, -1826,
   -1826, -1826,   355, -1826, -1826, -1826, -1826,  1345,  1346,  1349,
   -1826,  1581,  6403, 13599, 13599, 12187, 13599, -1826,  1353, 12220,
   15506, 13977, -1826, -1826, 10880, -1826,  1584, -1826, 15631,  1588,
    1354, -1826,   618,   623, 13571,  3948,  1590,  1357, -1826, -1826,
   10880,  1359,  1362, 13109, 14004,  1592,  6403,  1580,  1358, 10880,
   -1826, -1826,   624,   -26,    -7,    -4,    18,   168,  8526,   174,
   -1826,  1593, 13138, -1826, -1826,  1432, -1826, 10880, 10880, -1826,
   -1826,  8763,  4019,  1599,  1377, 13599,   495, 15631, -1826, -1826,
   -1826, -1826,    17, -1826, 11565, -1826, 13167,  1363,  1364,  1365,
    1605,  4122, -1826,  1606,  1608, -1826, -1826,  1376,  1612,   625,
   -1826,  1613,  1614,   217, 15631, 10880, 10880,  1385,  6403,   634,
   15631, 15531, -1826, -1826, -1826, 15556, 12253, -1826,  1100,  1139,
    6403,   495, -1826, 10880, 11565,    26,  8763,  8763, 10880,  1616,
     635, -1826, -1826, 10880,  1308, -1826, 10880, -1826, -1826, 13196,
   -1826, -1826,  6403,   298,   667,  8763, -1826, -1826,   349,  9974,
   -1826, -1826, -1826,  1617, -1826,  1382,  6403, -1826, 13225,  1618,
    8763,   -87,   -87,   -87,   -87,   -87, -1826, -1826, 10880, 13254,
   13283,   641, -1826, -1826, -1826, -1826, -1826, -1826,  1392,  1621,
    1390, -1826,  1628, -1826, -1826,    16, -1826,  1460, -1826, -1826,
   -1826, -1826, -1826, 10880, 12286, 12319,  6403, -1826,  1630, 10880,
    1394, -1826, 10880,  1395,  1396, -1826, -1826,  4637, -1826,  1402,
     642,   643, 13312, -1826,  1399, 12352,  1403, 12385, -1826,   644,
    1404,   -87,  6403,  1639,  1405,   -87,  1640,   651,  1406, -1826,
   10880, -1826,  1643,  1522,  8356,  1412, -1826,   652,   196,   208,
     241,   244,   275,  4145, -1826, -1826,  1646,  1648, -1826, -1826,
   -1826,  1653, -1826,  1417, 15631, 10880, 10880,   653, -1826, 15631,
   12418, -1826, -1826,  1100, 11565,  1421, -1826, -1826, -1826, 10880,
   10880, -1826, 10880,  1656,   -87,   109, -1826, -1826,   -87,   142,
   -1826,  1658, -1826, 13341, -1826, 10880, -1826,   -38, -1826,  1659,
    8763,  8763,  8763,  8763,  8526, -1826, -1826, -1826,  1644, -1826,
   10880, 15581, 12451,    50, 10880,  1423, -1826, -1826, 12484, 12517,
   12550, -1826,   291, -1826,   319, -1826, -1826, -1826,  4176,   481,
    8593, -1826,   654,   659,   661,   662,   322,   669,  1427,   670,
   -1826, 10880, -1826,  6403, 13370, -1826, 10880, 10880, 10880,   -87,
     -87, -1826, -1826, -1826,   -38,  1662,  1664,  1666,  1667,  8763,
    1668,  1670,  1671,  1436, 15606,   672,  1672, 13399, 13599, 12583,
     329,   333,   560, -1826, -1826, -1826, -1826,   679, -1826, -1826,
   -1826, 11370, -1826,  1438, -1826,  1674, -1826, 10880, 10880, 10880,
   -1826,  1676,   680, -1826,  1443,  6403, -1826, 13428, 13457, 13486,
   -1826,  1677, 11370, 11370,   681, -1826,  1679,  1681, -1826, -1826,
     682, -1826,  1682, -1826, -1826,  1683, 11370, -1826, -1826, -1826
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1826, -1826, -1826, -1826,   369, -1826, -1826, -1826, -1826,  -348,
   -1826, -1826, -1826, -1826, -1826, -1826, -1826, -1826, -1826, -1826,
   -1826, -1826,  -682,  -131,  3837,  2521, -1826,  1247, -1826, -1826,
   -1826, -1826, -1826, -1826, -1825, -1826,   321,   151,  -160, -1826,
    -121, -1826,    91,   359,  1702, -1826,    20,   -48, -1826, -1826,
       3,  -578,  -295, -1826, -1826, -1826, -1826, -1826, -1826, -1826,
   -1826,  1704, -1826, -1826, -1826, -1826, -1190, -1194,  1705, -1671,
    1706, -1826, -1826, -1826,  1130, -1826,  -174, -1826, -1826, -1826,
   -1826,  1880, -1826, -1826, -1369,   236,  1710, -1826,     2,  -683,
   -1826, -1826,   243, -1826, -1603,   -31,  -167,  2387,   -93,  -294,
      21, -1826,   280,   -95, -1826, -1826,    51,   205, -1612,  -146,
     972, -1826,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -551
static const yytype_int16 yytable[] =
{
     135,  1431,   442,   593,   423,   388,   116,   392,   291,  1433,
     988,  1596,   626,  1827,   609,  1828,   476,   154,   271,   152,
     350,  1671,   153,   115,   483,   908,   909,  1008,   324,   152,
     152,  1298,   630,  1943,   166,  1016,   393,   709,  1792,  1565,
     427,  1021,  1426,   395,   152,  1495,   273,   524,   546,   170,
    1462,  1231,     5,   142,   405,  1428,  2072,  1038,  1747,  1820,
     354,   277,   450,   296,     4,  1047,   737,   417,   418,   277,
     329,   746,   330,   328,   138,   286,  1392,  1748,  1330,   601,
     602,   273,   601,   602,   278,   139,   353,  1566,   297,   749,
     449,  1188,  1024,   481,   136,   750,   140,   389,   137,   682,
     903,   685,  1188,   910,   298,   299,   152,   325,  1189,   697,
    1556,   721,   580,   581,   582,  2053,  1190,  1191,  1192,  1189,
    1281,  1861,  1193,  1194,   568,   417,   418,  1190,  1191,  1192,
     601,   602,   428,  1193,  1194,   141,   568,   438,   438,   430,
     301,   302,   601,   602,   144,   444,  1463,  1464,  2055,  1870,
     690,   914,   303,   622,   623,   624,   304,   331,   752,   455,
     155,   484,   156,  1414,   750,  1142,  1136,  1029,  1133,  1137,
     637,  1530,   155,  1134,   156,   438,   601,   602,  2045,   145,
     273,  1137,   575,   273,   601,   602,   601,   602,   273,   273,
     438,  1299,  1300,  1301,  1302,   403,   146,  1432,  1427,   404,
    1007,   601,   602,  1418,  1281,  1789,  1672,   710,   711,   326,
     735,  1429,   271,   301,   302,  1496,  1497,  1430,   736,   147,
     601,   602,  1900,   601,   602,   303,   109,   109,  1758,   309,
     741,   148,   601,   602,  1690,   109,   109,   109,   742,  1431,
     273,  1901,  1014,   163,  1902,   601,   602,   579,   603,   627,
     744,   109,   521,   273,  1281,   137,   273,   544,   745,   351,
     586,   970,   543,   149,   591,   528,  1903,   327,  1291,   167,
     292,  1303,   273,   293,   394,   273,   273,   273,   273,  1959,
     714,   396,   715,   183,   171,   525,   547,   406,   273,  1232,
     143,   407,   273,  2073,   353,   355,   738,   899,   739,   901,
     902,   747,   740,   739,   150,   305,   307,   748,   310,   695,
     155,   151,   156,   109,   164,   701,   915,   273,   273,   273,
     155,   165,   156,  1282,  1285,   413,   414,   415,   416,   565,
     566,   601,   602,  1997,   273,   567,   601,   602,   417,   418,
     273,   722,  1312,   723,  1264,  -543,  -546,   724,   182,   417,
     418,   417,   418,   429,   569,   950,   570,  1112,  1284,  1256,
     571,   838,  1257,   417,   418,  1122,   569,  2068,   570,   601,
     602,   168,   571,   745,   830,   698,   699,   417,   418,   548,
     691,   184,   692,  1030,  1031,  1321,   693,  1030,  1031,   169,
     311,   712,   172,   788,   986,   601,   602,   334,   438,   273,
     335,   601,   602,   273,   273,   413,   414,   415,   416,   413,
     414,   415,   416,   336,   173,   426,  1904,   185,  1326,   273,
     436,   439,  1905,   601,   602,   725,   788,  1621,  1622,   417,
     418,  1960,  1961,   417,   418,   601,   602,  1962,   843,   413,
     414,   415,   416,   845,  2030,   174,   757,   413,   414,   415,
    1015,  1379,   732,  1380,  1663,  1664,  2031,  1932,   471,   413,
     414,   415,   416,   417,   418,  1933,  1390,   175,   601,   602,
    2095,   601,   602,   485,   186,   273,  1713,   312,  1681,   176,
    -547,   313,    61,    62,    63,    64,   827,   314,   315,  2032,
     316,   317,  2033,   177,   894,   895,   579,    75,   178,   273,
      78,   179,   601,   602,   612,  1956,   273,   820,   613,   318,
     180,   438,   958,   438,   273,   438,   438,   444,   601,   602,
     834,   181,  2134,  2034,   273,   273,   438,   438,   273,   154,
     714,   154,   715,   273,   842,   192,   844,  1188,  1130,  2079,
     935,   936,   937,   596,   597,  1808,   601,   602,   193,   601,
     602,   605,   610,   155,  1189,   156,   601,   602,   275,   273,
     601,   602,  1190,  1191,  1192,   874,   276,  2080,  1193,  1194,
    2089,   787,   714,  1475,   715,   788,   973,  2118,  1009,  1479,
     745,  2119,   601,   602,   273,   273,   979,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,  1177,   430,   430,   287,   567,
    1188,   288,   847,   289,   282,  1785,   788,   283,   601,   602,
     284,   882,   285,  1013,   290,   788,  1517,  1189,   274,   732,
     273,   273,   273,    41,   604,  1190,  1191,  1192,   294,  1532,
     990,  1193,  1194,  1033,   788,  1537,   601,   602,   295,  1040,
     732,   319,  1638,   444,   438,   444,   438,   438,   438,   438,
     438,   438,   611,   438,   438,   438,   438,   972,  1060,   438,
     438,   438,   154,   978,   300,  1004,   273,   977,   417,   418,
     187,   694,  1026,   188,   996,  -545,   189,   987,   997,  1188,
     560,   561,   688,   563,   564,   565,   566,   308,   320,   190,
     321,   567,   732,   273,   158,   732,  1189,   159,   322,   509,
     160,   510,   161,   273,  1190,  1191,  1192,   732,  1018,   333,
    1193,  1194,   323,   702,  1615,  2082,   703,   332,  1113,   704,
     714,   705,   715,   273,  1034,   714,   338,   715,  1234,   273,
     417,   418,   444,  1045,   339,   340,  1152,  -550,  1049,  1025,
     438,   346,   347,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,   358,   714,  1148,   715,   567,   714,  1153,   715,  1154,
    1254,  1809,   348,   273,   788,   273,  1156,   349,   688,   563,
     564,   565,   566,   359,   824,  1169,   826,   567,   828,   829,
    1964,  1965,   279,  1174,  2120,   280,  1962,   281,  1140,   839,
     840,  1172,   788,  1691,   402,   788,  1173,  1216,   273,  1217,
     788,   788,  1218,   788,  1260,  1700,   788,  1294,   788,  1367,
    1389,   788,  1397,   788,   788,  1411,   788,  2059,  1528,   788,
     408,   360,   788,  1578,   906,   907,  1609,   788,  1697,   597,
     788,  1720,  1698,  1801,  1847,   788,  1163,   788,  1848,   648,
    1862,   137,  1883,   273,  1863,  1431,   788,  1884,  1899,  1929,
     356,   788,  1848,   745,  1283,  1286,   273,   357,  1938,  1954,
     401,   548,  1939,  1848,   273,  1986,  2006,  2007,  2013,   788,
     788,   788,  1848,   273,  2102,  2021,  2029,  2043,  2085,   788,
     788,  1848,   788,  2086,   390,  2087,  2088,   788,  1431,   788,
     788,   409,  1287,  2090,  2092,   434,  2113,   788,  1939,   732,
    1848,   732,   732,  2121,  2131,  2142,  2145,   788,  2132,  1848,
    2146,  1263,   433,  1264,  1319,   732,  1601,   957,  1602,   959,
     960,   961,   962,   963,   964,   137,   966,   967,   968,   969,
     447,  1460,   974,   975,   976,   714,   449,   715,   716,   714,
     451,   715,   879,  1680,   452,  1681,  1274,  1770,   453,  1771,
     732,   482,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,  1297,  -192,   454,  1362,   567,
    -193,   459,   463,   477,   273,   517,   520,  1503,  -194,   527,
     529,   526,   532,   533,   545,   534,   732,   576,  1293,   577,
     404,   590,   584,   273,   587,   592,   594,   595,   614,  1391,
    1393,   615,   616,   617,   273,  1043,   628,   618,   619,   438,
     620,  1343,  1344,  1051,  1346,  1347,  1348,   625,  1350,  1351,
    1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,  1781,  1782,
     631,   629,   632,   643,   633,   634,   644,   635,   636,   273,
     273,   638,   273,   273,   273,  1399,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   639,   640,   273,   651,
     650,   659,   660,   661,   672,   673,   675,   677,  1371,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   786,   563,   564,   565,   566,   676,   678,   680,
    1384,   567,   679,   714,   681,   715,   273,   438,   438,   683,
     684,   700,   706,   713,   719,   720,  1398,   136,   754,   726,
     758,   763,   779,   784,   790,   791,   792,   821,   273,   567,
     831,  1466,   850,   848,   851,   877,  1180,   886,   897,   887,
     890,   893,   898,  1186,   273,   273,   900,  1197,   926,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,   928,  1443,  1391,
    1393,   567,   929,  1461,   931,   939,   944,  1684,   948,   951,
     989,  1686,  1454,  1455,  1456,   980,   982,   732,   995,   999,
    1000,  1010,  1001,  1002,  1003,  1011,   273,  1012,  1696,  1022,
    1023,  1037,  1027,  1053,  1039,  1042,  1048,   152,   361,  1054,
     273,   273,   273,  1525,  1050,  1081,  1061,  1062,  1063,  1065,
    1066,   273,  1067,  1069,  1070,  1541,   438,  1546,  1071,  1072,
     438,  1487,  1073,  1074,  1075,  1076,  1077,  1078,  1085,   438,
    1110,   438,  1119,  1111,   438,  1135,  1120,  1121,  1141,   362,
     363,   364,   365,   366,   367,   368,   369,   370,  1126,   273,
    1129,  1144,   371,   372,   373,   374,  1145,  1157,  1149,  1158,
     375,   376,   377,  1164,  1166,   378,  1481,   379,   353,  1187,
    1175,  1209,  1183,  1184,  1211,  1237,  1223,   380,  1224,  1225,
     381,  1545,  1226,  1238,  1342,  1250,  1239,  1242,   438,  1252,
    1968,  1253,  1320,   273,  1560,  1259,  1265,  1262,  1564,  1267,
    1266,  1268,  1273,  1271,  1280,  1272,  1289,  1290,  1295,   273,
    1309,  1296,  1315,  1316,  1317,  1325,  1322,  1328,  1329,   411,
    1332,  1345,   273,  -195,  1349,  1361,   273,  1383,  1375,  1400,
    1401,  1402,  1650,  1405,  1406,  1408,  1407,  1409,  1410,  1412,
    1420,  1419,  1705,  1705,  1692,  1423,  1424,  1445,  1434,  1610,
    1611,  1612,  1425,  1435,  1449,  1436,  1437,  1617,  1438,  1439,
    1440,  1441,  1442,  1679,  1446,  1447,  1448,  1471,  1450,  1451,
    1452,  1457,  1632,  1465,  1470,  1477,  1480,   273,   273,   273,
    1372,  1373,  1478,  1640,  1836,   273,   382,   383,   384,  1488,
    1482,  1648,  1486,  1494,  1499,  1500,  1505,   385,  1502,  1510,
     273,   386,  1506,   387,   109,  1512,  1513,  1514,  1516,  1527,
    1529,   273,  1535,  1533,  1548,  1550,  1555,  1549,  1557,   273,
    1561,  1562,   273,  1563,  1731,  1568,  1569,  1570,  1571,   417,
     418,  1572,  1573,  1574,  1575,  1576,  -544,  1577,  1518,  1598,
    1604,  1608,  1613,  1614,  1587,  1666,  1620,  1634,  1594,  1635,
    1649,  1629,  1618,  1763,  1654,  1655,  1619,  1626,  1656,  1660,
    1661,  1662,  1688,  1711,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,   353,
    1627,  1628,  1641,   567,  1642,   444,   444,  1643,  1730,  1644,
    1645,   273,  1646,  1676,  1651,  1694,  1669,  1683,  1712,  1467,
    1257,  1714,  1707,  1469,  1687,  1772,  1773,  1776,   438,  1715,
    1717,  1693,  1473,  1722,  1474,  1723,   273,  1476,  1719,  1725,
    1726,   273,  1729,  1751,  1732,  1738,  1739,  1740,  1741,  1743,
    1744,  1745,  1746,  1750,  1752,  1839,  1137,  1749,  1765,  1757,
    1764,  1767,  1786,  1790,  1791,  1800,  1804,  1823,  1832,  1813,
    1822,  1833,  1824,   745,  1835,  1840,  1818,  1821,  -548,  1852,
    1853,  1854,  1860,  1763,  1769,  1865,  1869,  1896,  1866,  1867,
    1880,  1519,  1868,  1875,  1881,  1830,  1887,  1882,  1894,  1906,
    1888,  1897,  1974,  1890,  1908,  1913,  1891,  1920,  1921,  1922,
    1711,  1923,   273,  1925,  1926,   273,   273,  1914,  1928,  1930,
    1931,  1927,  1953,  1971,  1976,  1805,  1972,  1988,  1936,   430,
     430,  1991,  1987,  1989,  1990,  1992,  1998,  -549,   273,  2001,
    2002,  2005,  2009,  2011,   273,  2017,  2020,  2014,  2018,  2024,
    2022,  2025,  2036,   273,  2037,  2028,  1829,     7,     8,  2039,
    2040,  2047,  2051,   438,  2056,  2061,   438,  2075,  2103,  1838,
    2104,  2091,  2105,  2106,  2108,  1637,  2109,  2110,  2114,  2111,
    2126,  2125,  2130,  2138,   273,  2143,  2133,  2144,  2147,  2148,
    1531,  1293,  2069,   753,  2038,   353,  1590,   273,   444,  1944,
    1737,  1917,  1766,  1559,   732,   114,   732,   125,   126,   127,
    1966,  1678,   889,   133,  1706,  1834,     0,  1044,  1911,     0,
       0,  1711,  1819,     0,     0,     0,     0,     0,     0,  1918,
     444,     0,     0,  2060,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,   273,
       0,    38,    39,    40,    41,  1895,     0,    43,     0,     0,
       0,     0,     0,     0,   727,    50,     0,    52,   728,  1948,
     729,   730,     0,  1950,  1951,     0,   992,     0,   152,   361,
       0,     0,     0,   273,     0,     0,     0,     0,     0,    72,
       0,     0,  1967,   993,     0,   273,     0,     0,     0,     0,
    1742,     0,     0,     0,     0,     0,     0,  1977,   273,     0,
       0,  1724,     0,    86,    87,    88,     0,  1937,     0,     0,
     362,   363,   364,   365,   366,   367,   368,   369,   370,  1945,
       0,     0,     0,   371,   372,   373,   374,     0,     0,     0,
       0,   375,   376,   377,     0,   273,   378,     0,   379,     0,
       0,  1711,     0,     0,     0,     0,     0,   273,   380,     0,
       0,   381,  1949,   273,   273,  1973,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,     0,   273,     0,     0,  1793,  1794,  1795,  1796,  1797,
    1799,   430,     0,   273,     0,     0,     0,   273,     0,     0,
     411,     0,     0,     0,     0,  1711,     0,     0,     0,  2046,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,     0,     0,     0,     0,     0,     0,     0,
       0,  2016,     0,   273,     0,     0,     0,  2062,  2063,  2064,
    2065,  2067,     0,     0,     0,     0,  1814,     0,     0,  1816,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   384,
       0,     0,     0,     0,     0,     0,     0,     0,   385,     0,
       0,     0,   386,     0,   387,   109,     0,     0,   399,     0,
       0,     0,     0,     0,   732,     0,  2107,     0,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,   714,   425,   715,  1701,   567,   435,
       0,     0,     0,   440,     0,     0,     0,   273,   273,   273,
     273,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1711,   456,   457,   458,     0,   460,   461,   462,
       0,   464,   465,   466,   467,   468,   469,   470,   732,   472,
     473,   474,   475,     0,     0,     0,   479,     0,     0,     0,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     732,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,     0,     0,     0,  1711,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,     0,     0,   438,
     438,     0,     0,     0,     0,   535,   537,   539,   540,   479,
       0,     0,     0,   438,  1978,  1979,  1980,  1981,  1982,     0,
       0,     0,     0,     0,   574,   479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   599,   600,     0,     0,     0,     0,   600,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   621,
       0,     0,     0,     0,  2015,     0,     0,     0,  2019,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,   479,     0,     0,     0,   645,   646,   647,
       0,   649,     0,     0,     0,   652,   653,   654,     0,     0,
     655,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2052,     0,     0,
       0,  2054,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2066,   687,     0,
       0,     0,   479,   696,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   707,
     708,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,  2100,  2101,     0,     0,     0,     0,     0,     0,
       0,   759,   760,   761,   762,     0,     0,     0,     0,   767,
       0,     0,     0,   771,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   785,   537,     0,
       0,     0,   789,     0,     0,     0,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   809,   811,   812,   813,   814,   815,   816,   817,
     817,  2123,   822,   823,     0,   825,     0,     0,     0,     0,
       0,     0,   832,     0,     0,   836,   837,     0,     0,     0,
       0,   817,  2139,  2141,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2149,     0,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   867,   869,   870,   871,   872,   873,     0,   875,
     876,     0,     0,     0,     0,     0,   883,   884,   885,     0,
       0,     0,     0,     0,   891,   892,     0,   479,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   361,   535,   687,   911,     0,
       0,     0,   916,   917,   918,   919,   920,   921,   922,   923,
     924,     0,     0,     0,     0,   930,     0,   932,     0,   933,
       0,     0,     0,   479,   479,   479,   938,     0,   940,   941,
     942,     0,     0,     0,     0,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,     0,     0,     0,     0,   371,
     372,   373,   374,     0,     0,   965,     0,   375,   376,   377,
       0,     0,   378,     0,   379,     0,     0,     0,     0,   479,
       0,     0,     0,     0,   380,     0,   984,   381,   985,     0,
       0,   875,   876,   480,     0,     0,     0,     0,     0,     0,
     998,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,   718,  1019,  1020,     0,     0,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,  1035,  1036,
       0,     0,   479,  1041,     0,     0,     0,  1035,     0,     0,
       0,     0,     0,     0,  1052,     0,     0,     0,  1055,     0,
       0,     0,     0,   538,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,  1079,     0,   867,     0,  1082,     0,
       0,     0,     0,   382,   383,   384,     0,     0,     0,     0,
       0,     0,     0,     0,   385,     0,     0,     0,   386,     0,
     387,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1701,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,     0,  1162,     0,     0,     0,
    1168,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,  1181,  1182,     0,     0,     0,   480,
    1185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1210,     0,     0,  1212,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,  1227,
       0,  1229,  1230,   567,     0,   734,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1360,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,  1270,     0,     0,     0,     0,     0,     0,
    1276,  1277,  1278,  1279,     0,     0,     0,     0,  1288,   810,
       0,     0,     0,     0,     0,     0,   818,   819,     0,     0,
       0,     0,  1313,  1314,     0,     0,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   841,     0,
       0,     0,     0,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1337,  1338,  1339,  1340,
       0,     0,     0,     0,     0,   717,     0,     0,     0,   868,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,   480,     0,  1363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1364,  1365,  1366,
       0,     0,     0,     0,  1368,  1369,     0,  1370,     0,     0,
       0,  1444,     0,     0,     0,     0,     0,     0,     0,  1377,
    1378,     0,     0,     0,     0,     0,     0,  1381,  1382,     0,
     480,   480,   480,     0,  1386,  1485,  1387,  1388,     0,     0,
       0,     0,     0,  1394,  1395,     0,     0,     0,   479,     0,
       0,     0,     0,     0,   833,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,   480,   567,     0,  1422,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,   880,     0,     0,     0,     0,     0,
       0,     0,  1453,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
       0,     0,  1468,   480,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1394,  1395,     0,     0,     0,  1484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1493,     0,     0,  1498,     0,     0,     0,     0,
       0,     0,     0,   868,     0,  1083,     0,     0,     0,     0,
       0,     0,     0,     0,  1501,     0,     0,     0,     0,     0,
       0,     0,  1520,     0,     0,  1523,   479,  1526,     0,     0,
       0,     0,     0,     0,     0,  1534,     0,  1536,   480,  1534,
    1540,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,  1630,
       0,     0,     0,   567,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,   480,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,     0,     0,     0,  1616,     0,     0,
       0,     0,     0,     0,  1623,  1624,  1625,     0,     0,     0,
       0,     0,     0,  1631,     0,  1633,     0,     0,     0,     0,
       0,     0,  1636,     0,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,   479,  1098,  1099,  1100,  1101,
    1652,  1103,  1104,  1105,  1106,     0,     0,     0,  1657,  1658,
    1659,     0,     0,     0,     0,  1116,     0,  1118,     0,     0,
    1670,     0,     0,     0,     0,  1125,     0,     0,     0,     0,
    1682,  1131,  1132,     0,     0,     0,     0,     0,     0,     0,
    1143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1699,     0,     0,     0,
       0,     0,  1708,  1709,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,  1685,   480,     0,   567,     0,     0,     0,
       0,     0,     0,     0,  1735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,  1753,  1754,  1755,     0,   480,     0,
       0,     0,     0,     0,     0,  1756,     0,  1233,  1235,  1236,
    1759,  1760,  1761,  1240,  1241,     0,     0,  1244,  1245,  1246,
    1247,     0,  1249,  1768,     0,  1689,     0,  1255,   479,   479,
    1774,     0,  1775,     0,     0,     0,     0,     0,  1783,  1784,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,     0,     0,
       0,  1802,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1812,   480,     0,  1815,     0,     0,
       0,  1817,     0,     0,     0,     0,     0,     0,     0,     0,
    1760,  1761,     0,  1826,     0,     0,     0,     0,     0,     0,
       0,  1831,     0,     0,     0,     0,  1336,     0,     0,  1695,
       0,  1341,     0,     0,     0,     0,     0,  1844,     0,     0,
       0,     0,  1850,  1851,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1855,     0,     0,  1856,  1855,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,  1879,   567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1889,     0,     0,     0,     0,     0,     0,     0,     0,  1898,
       0,     0,     0,     0,     0,     0,  1396,     0,   537,     0,
       0,     0,     0,     0,     0,     0,     0,  1909,  1910,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,  1803,     0,  1934,  1935,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1947,     0,     0,   479,   479,  1952,     0,
       0,     0,     0,  1955,     0,     0,  1957,     0,     0,     7,
       8,     0,     0,     0,     0,   479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,  1983,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,  1994,     0,  1507,     0,     0,     0,  1999,
       0,     0,  2000,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    2023,     0,  1542,    38,    39,    40,    41,     0,   157,    43,
     162,     0,     0,     0,     0,     0,   727,    50,     0,    52,
     728,     0,   729,   730,     0,  2041,  2042,     0,     0,     0,
       0,     0,     0,     0,  1579,  1580,  1581,  1582,  1583,  2048,
    2049,    72,  2050,  1588,  1589,     0,     0,  1591,     0,  1593,
       0,     0,     0,  1597,     0,  2058,  1599,     0,     0,     0,
     479,   479,   479,   479,   479,    86,    87,    88,  1607,     0,
    1850,     0,     0,     0,  2074,     0,     0,     0,     0,     0,
       0,  1736,     0,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,  2094,     0,     0,  1886,   567,  2097,  2098,  2099,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1665,     0,  1668,
     912,     0,     0,  1675,     0,  1677,     0,  2127,  2128,  2129,
       0,     0,     0,     0,     0,   480,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1912,     0,     0,     0,  1702,
       0,     0,     0,     0,   480,     0,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   511,
     512,   513,   514,   515,   516,     0,   518,   519,     0,     0,
       0,     0,     0,   522,   523,     0,     0,     0,     0,     0,
     194,   152,     0,     0,   530,   531,     0,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   397,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,  1762,     0,     0,     0,  1924,     0,
       0,     0,   227,   228,   229,   230,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2035,   233,   234,   235,     0,     0,     0,     0,   236,
      20,     0,   237,     0,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,  2081,     0,     0,   538,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,   656,
     657,   658,     0,     0,     0,   662,   663,   664,   665,   666,
     667,   668,     0,   669,     0,     0,     0,   670,   671,     0,
       0,   674,     0,     0,  1841,     0,     0,  1842,     0,     0,
       0,     0,     0,     0,   686,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,   480,   480,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,     0,   480,   247,  1871,  1872,     0,  1874,   249,   250,
     251,     0,   252,   253,   254,     0,     0,   480,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   398,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,   342,     0,     0,     0,
     588,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1915,  1916,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,  1864,
     548,   849,  1946,   567,     0,     0,     0,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,   480,   480,   480,
     480,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     6,   361,     0,     0,     0,
       0,   195,   196,   197,     0,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,     0,   480,  1543,   363,   364,
     365,   366,   367,   368,   369,   370,   227,   228,   229,   230,
     371,   372,   373,   374,   231,   232,     0,     0,   375,   376,
     377,     0,     0,   378,     0,   379,   233,   234,   235,     0,
       0,     0,     0,   236,    20,   380,   237,     0,   381,     0,
       0,     0,   238,     0,     0,   239,     0,     0,   240,     0,
     241,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,    51,     0,   244,     0,   245,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
       0,     0,    78,     0,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   786,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,     0,  2116,
       0,     0,     0,   246,   382,   383,   384,   247,   248,     0,
       0,     0,   249,   250,   251,   385,   252,   253,   254,   386,
       0,   387,   109,     0,  2004,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
     342,     0,     0,     0,  1544,     0,     0,   260,     0,     0,
       0,  1138,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,   194,     6,   361,     0,   567,     0,
       0,   195,   196,   197,   783,  1155,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,     0,     0,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   227,   228,   229,   230,
     371,   372,   373,   374,   231,   232,     0,     0,   375,   376,
     377,     0,     0,   378,     0,   379,   233,   234,   235,     0,
       0,     0,     0,   236,    20,   380,   237,     0,   381,     0,
       0,     0,   238,     0,     0,   239,     0,     0,   240,     0,
     241,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,    51,     0,   244,     0,   245,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,   548,     0,     0,    75,
       0,     0,    78,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,     0,     0,     0,   548,     0,  1331,     0,     0,     0,
       0,     0,     0,   246,   382,   383,   384,   247,   248,     0,
       0,     0,   249,   250,   251,   385,   252,   253,   254,   386,
       0,   387,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
     342,     0,     0,     0,   259,     0,     0,   260,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,   194,   152,
     361,   567,   410,   764,     0,   195,   196,   197,     0,  1385,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   397,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     227,   228,   229,   230,   371,   372,   373,   374,   231,     0,
       0,     0,   375,   376,   377,     0,     0,   378,     0,   379,
     233,   234,   235,     0,     0,     0,     0,   236,    20,   380,
     237,     0,   381,     0,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   411,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   786,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1508,  1509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,   246,   382,   383,
     384,   247,     0,     0,     0,     0,   249,   250,   251,   385,
     252,   253,   254,   386,   952,   387,   109,   413,   414,   415,
     416,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   398,     0,     0,     0,     0,     0,   257,
       0,   417,   418,     0,   419,     0,   420,     0,     0,     0,
     421,   260,     0,     0,     0,     0,     0,  1595,     0,     0,
       0,   194,     6,   341,     0,     0,     0,  1603,   195,   196,
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
      51,     0,   244,     0,   245,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,     0,     0,    67,    68,
      69,    70,    71,     0,     0,     0,    75,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1733,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
     246,     0,     0,     0,   247,   248,     0,     0,     0,   249,
     250,   251,     0,   252,   253,   254,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,   342,   194,     6,
       0,   343,     0,   642,   260,   195,   196,   197,     0,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,   230,     0,     0,     0,     0,   231,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   235,     0,     0,     7,     8,   236,    20,     0,
     237,     0,     0,     0,     0,     0,   238,     0,     0,   239,
       0,     0,   240,     0,   241,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,    51,     0,   244,
       0,   245,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,    41,     0,     0,    43,     0,     0,     0,     0,
       0,     0,   727,    50,     0,    52,   728,   246,   729,   730,
       0,   247,   248,     0,     0,     0,   249,   250,   251,     0,
     252,   253,   254,     0,     0,     0,   109,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   478,     0,     0,     0,     0,     0,   257,
       0,    86,    87,    88,   342,   194,     6,  1639,     0,   541,
       0,   260,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   934,   233,   234,   235,
       0,     0,     7,     8,   236,    20,     0,   237,     0,     0,
       0,     0,     0,   238,     0,     0,   239,     0,     0,   240,
       0,   241,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    51,     0,   244,     0,   245,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,    65,
       0,     0,    67,    68,    69,    70,    71,     0,     0,     0,
      75,     0,     0,    78,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,     0,   727,
      50,     0,    52,   728,   246,   729,   730,     0,   247,   248,
       0,     0,     0,   249,   250,   251,     0,   252,   253,   254,
       0,     0,     0,   109,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,     0,     0,     0,     0,     0,   257,     0,    86,    87,
      88,   342,   194,     6,     0,   259,     0,     0,   260,   195,
     196,   197,     0,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,   230,     0,     0,
       0,     0,   231,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   981,   233,   234,   235,     0,     0,     7,
       8,   236,    20,     0,   237,     0,     0,     0,     0,     0,
     238,     0,     0,   239,     0,     0,   240,     0,   241,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,    51,     0,   244,     0,   245,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,    67,
      68,    69,    70,    71,     0,     0,     0,    75,     0,     0,
      78,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,     0,     0,     0,     0,   727,    50,     0,    52,
     728,   246,   729,   730,     0,   247,   248,     0,     0,     0,
     249,   250,   251,     0,   252,   253,   254,     0,     0,     0,
     109,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   606,  1798,     0,     0,
       0,     0,     0,   257,     0,    86,    87,    88,   608,   194,
       6,     0,   304,   541,     0,   260,   195,   196,   197,     0,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,     0,     0,     0,     0,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     983,   233,   234,   235,     0,     0,     7,     8,   236,    20,
       0,   237,     0,     0,     0,     0,     0,   238,     0,     0,
     239,     0,     0,   240,     0,   241,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,    51,     0,
     244,     0,   245,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,    65,     0,     0,    67,    68,    69,    70,
      71,     0,     0,     0,    75,     0,     0,    78,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,    41,     0,     0,    43,     0,     0,     0,
       0,     0,     0,   727,    50,     0,    52,   728,   246,   729,
     730,     0,   247,   248,     0,     0,     0,   249,   250,   251,
       0,   252,   253,   254,     0,     0,     0,   109,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,     0,     0,     0,     0,     0,
     257,     0,    86,    87,    88,   258,   194,     6,     0,   259,
       0,     0,   260,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,   230,     0,     0,     0,     0,   231,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1176,   233,   234,
     235,     0,     0,     7,     8,   236,    20,     0,   237,     0,
       0,     0,     0,     0,   238,     0,     0,   239,     0,     0,
     240,     0,   241,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,    51,     0,   244,     0,   245,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,     0,     0,     0,     0,     0,     0,
     727,    50,     0,    52,   728,   246,   729,   730,     0,   247,
     248,     0,     0,     0,   249,   250,   251,     0,   252,   253,
     254,     0,     0,     0,   109,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,     0,     0,     0,     0,     0,   257,     0,    86,
      87,    88,   342,   194,     6,     0,   259,     0,     0,   260,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1178,   233,   234,   235,     0,     0,
       7,     8,   236,    20,     0,   237,     0,     0,     0,     0,
       0,   238,     0,     0,   239,     0,     0,   240,     0,   241,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,    51,     0,   244,     0,   245,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,    65,     0,     0,
      67,    68,    69,    70,    71,     0,     0,     0,    75,     0,
       0,    78,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,    41,     0,     0,
      43,     0,     0,     0,     0,     0,     0,   727,    50,     0,
      52,   728,   246,   729,   730,     0,   247,   248,     0,     0,
       0,   249,   250,   251,     0,   252,   253,   254,     0,     0,
       0,   109,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   478,     0,
       0,     0,     0,     0,   257,     0,    86,    87,    88,   342,
     194,     6,     0,   536,     0,     0,   260,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,   230,     0,     0,     0,     0,
     231,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1179,   233,   234,   235,     0,     0,     7,     8,   236,
      20,     0,   237,     0,     0,     0,     0,     0,   238,     0,
       0,   239,     0,     0,   240,     0,   241,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,    51,
       0,   244,     0,   245,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,     0,     0,
       0,     0,     0,     0,   727,    50,     0,    52,   728,   246,
     729,   730,     0,   247,   248,     0,     0,     0,   249,   250,
     251,     0,   252,   253,   254,     0,     0,     0,   109,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   478,     0,     0,     0,     0,
       0,   257,     0,    86,    87,    88,   342,   194,     6,     0,
       0,   541,     0,   260,   195,   196,   197,     0,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,   230,     0,     0,     0,     0,   231,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1198,   233,
     234,   235,     0,     0,     7,     8,   236,    20,     0,   237,
       0,     0,     0,     0,     0,   238,     0,     0,   239,     0,
       0,   240,     0,   241,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,    51,     0,   244,     0,
     245,     0,     0,     0,     0,     0,     0,    61,    62,    63,
      64,    65,     0,     0,    67,    68,    69,    70,    71,     0,
       0,     0,    75,     0,     0,    78,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,    41,     0,     0,    43,     0,     0,     0,     0,     0,
       0,   727,    50,     0,    52,   728,   246,   729,   730,     0,
     247,   248,     0,     0,     0,   249,   250,   251,     0,   252,
     253,   254,     0,     0,     0,   109,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,     0,     0,     0,     0,     0,   257,     0,
      86,    87,    88,   578,   194,     6,     0,   259,     0,     0,
     260,   195,   196,   197,     0,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,   230,
       0,     0,     0,     0,   231,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1228,   233,   234,   235,     0,
       0,     7,     8,   236,    20,     0,   237,     0,     0,     0,
       0,     0,   238,     0,     0,   239,     0,     0,   240,     0,
     241,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,    51,     0,   244,     0,   245,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
       0,     0,    78,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,     0,     0,     0,     0,     0,     0,   727,    50,
       0,    52,   728,   246,   729,   730,     0,   247,   248,     0,
       0,     0,   249,   250,   251,     0,   252,   253,   254,     0,
       0,     0,   109,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
       0,     0,     0,     0,     0,   257,     0,    86,    87,    88,
     585,   194,     6,     0,   259,     0,     0,   260,   195,   196,
     197,     0,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,   230,     0,     0,     0,
       0,   231,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1261,   233,   234,   235,     0,     0,     7,     8,
     236,    20,     0,   237,     0,     0,     0,     0,     0,   238,
       0,     0,   239,     0,     0,   240,     0,   241,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
      51,     0,   244,     0,   245,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,     0,     0,    67,    68,
      69,    70,    71,     0,     0,     0,    75,     0,     0,    78,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,    41,     0,     0,    43,  1146,
       0,     0,     0,     0,     0,   727,    50,     0,    52,   728,
     246,   729,   730,     0,   247,   248,     0,     0,     0,   249,
     250,   251,     0,   252,   253,   254,     0,     0,     0,   109,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   478,     0,     0,     0,
       0,     0,   257,     0,    86,    87,    88,   342,   194,     6,
       0,   866,     0,  1318,   260,   195,   196,   197,     0,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,   230,     0,     0,     0,     0,   231,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1413,
     233,   234,   235,     0,     0,     0,     0,   236,    20,     0,
     237,     0,     0,     0,     0,     0,   238,     0,     0,   239,
       0,     0,   240,     0,   241,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,    51,     0,   244,
       0,   245,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,     0,     0,
       0,   247,   248,     0,     0,     0,   249,   250,   251,     0,
     252,   253,   254,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   478,     0,     0,     0,     0,     0,   257,
     194,     6,     0,     0,   342,  1524,     0,   195,   196,   197,
       0,   260,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,   230,     0,     0,     0,     0,
     231,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,     0,     0,     0,     0,   236,
      20,     0,   237,     0,     0,     0,     0,     0,   238,     0,
       0,   239,     0,     0,   240,     0,   241,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,    51,
       0,   244,     0,   245,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,     0,     0,   247,   248,     0,     0,     0,   249,   250,
     251,     0,   252,   253,   254,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   478,     0,     0,     0,     0,
       0,   257,   194,     6,     0,     0,   342,     0,     0,   195,
     196,   197,     0,   260,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,   230,     0,     0,
       0,     0,   231,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,     0,     0,     7,
       8,   236,    20,     0,   237,     0,     0,     0,     0,     0,
     238,     0,     0,   239,     0,     0,   240,     0,   241,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,    51,     0,   244,     0,   245,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,    67,
      68,    69,    70,    71,     0,     0,     0,    75,     0,     0,
      78,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,     0,     0,     0,     0,   727,    50,     0,    52,
     728,   246,   729,   730,     0,   247,   248,     0,     0,     0,
     249,   250,   251,     0,   252,   253,   254,     0,     0,     0,
     109,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,     0,     0,
       0,     0,     0,   257,     0,    86,    87,    88,   342,   194,
       6,     0,  1647,     0,     0,   260,   195,   196,   197,     0,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,     0,     0,     0,     0,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2026,   233,   234,   235,     0,     0,     7,     8,   236,    20,
       0,   237,     0,     0,     0,     0,     0,   238,     0,     0,
     239,     0,     0,   240,     0,   241,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,    51,     0,
     244,     0,   245,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,    65,     0,     0,    67,    68,    69,    70,
      71,     0,     0,     0,    75,     0,     0,    78,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,    41,     0,     0,    43,  1459,     0,     0,
       0,     0,     0,   727,    50,     0,    52,   728,   246,   729,
     730,     0,   247,   248,     0,     0,     0,   249,   250,   251,
       0,   252,   253,   254,     0,     0,     0,   109,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,  1798,     0,     0,     0,     0,     0,
     257,     0,    86,    87,    88,   608,   194,     6,     0,   304,
       0,     0,   260,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,   230,     0,     0,     0,     0,   231,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2083,   233,   234,
     235,     0,     0,     0,     0,   236,    20,     0,   237,     0,
       0,     0,     0,     0,   238,     0,     0,   239,     0,     0,
     240,     0,   241,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,    51,     0,   244,     0,   245,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,   247,
     248,     0,     0,     0,   249,   250,   251,     0,   252,   253,
     254,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   478,     0,     0,     0,     0,     0,   257,   194,   152,
     361,     0,   342,     0,     0,   195,   196,   197,     0,   260,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   397,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     227,   228,   229,   230,   371,   372,   373,   374,   231,     0,
       0,     0,   375,   376,   377,     0,     0,   378,     0,   379,
     233,   234,   235,     0,     0,     0,     0,   236,    20,   380,
     237,     0,   381,   194,   152,   361,     0,     0,     0,     0,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   397,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   227,   228,   229,   230,   371,
     372,   373,   374,   231,     0,     0,     0,   375,   376,   377,
       0,     0,   378,     0,   379,   233,   234,   235,  1403,     0,
       0,     0,   236,    20,   380,   237,     0,   381,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   382,   383,
     384,   247,     0,     0,     0,     0,   249,   250,   251,   385,
     252,   253,   254,   386,     0,   387,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   398,     0,     0,     0,     0,     0,   257,
       0,     0,     0,     0,   342,     0,     0,     0,  1539,     0,
       0,   260,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,   246,   382,   383,   384,   247,     0,     0,     0,
       0,   249,   250,   251,   385,   252,   253,   254,   386,     0,
     387,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   398,     0,
       0,     0,     0,     0,   257,     0,     0,     0,     0,   342,
     194,   152,   361,  1811,     0,     0,   260,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   397,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,  1543,   363,   364,   365,   366,   367,   368,
     369,   370,   227,   228,   229,   230,   371,   372,   373,   374,
     231,     0,     0,     0,   375,   376,   377,     0,     0,   378,
       0,   379,   233,   234,   235,     0,     0,     0,     0,   236,
      20,   380,   237,     0,   381,   194,   152,   361,     0,     0,
       0,     0,   195,   196,   197,     0,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   397,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   227,   228,   229,
     230,   371,   372,   373,   374,   231,     0,     0,     0,   375,
     376,   377,     0,     0,   378,     0,   379,   233,   234,   235,
       0,     0,     0,     0,   236,    20,   380,   237,     0,   381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     382,   383,   384,   247,     0,     0,     0,     0,   249,   250,
     251,   385,   252,   253,   254,   386,     0,   387,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   398,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,   342,     0,     0,     0,
    1701,     0,     0,   260,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   714,     0,   715,   246,   382,   383,   384,   247,  1667,
       0,     0,     0,   249,   250,   251,   385,   252,   253,   254,
     386,     0,   387,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     398,     0,     0,     0,     0,     0,   257,   194,   152,     0,
       0,   342,     0,     0,   195,   196,   197,     0,   260,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   397,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,   230,     0,     0,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,   194,   152,     0,   236,    20,   835,   237,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   397,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
     943,     0,     0,     0,     0,     0,   246,     0,   904,     0,
     247,     0,     0,     0,     0,   249,   250,   251,     0,   252,
     253,   254,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   606,   607,     0,     0,     0,     0,     0,   257,     0,
       0,     0,     0,   608,     0,     0,     0,   304,     0,     0,
     260,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,   246,     0,   567,     0,   247,     0,     0,     0,
    1779,   249,   250,   251,  1780,   252,   253,   254,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   398,     0,
       0,     0,     0,     0,   257,   194,   152,     0,     0,   342,
       0,     0,   195,   196,   197,     0,   260,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   397,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,   236,    20,     0,   237,   194,   152,
       0,  1269,     0,     0,     0,   195,   196,   197,     0,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   397,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,   230,     0,     0,     0,     0,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   235,     0,     0,     0,     0,   236,    20,     0,
     237,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,   246,     0,   567,     0,   247,     0,
       0,     0,  1806,   249,   250,   251,  1807,   252,   253,   254,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     398,     0,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   342,  1046,     0,     0,     0,     0,     0,   260,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,   246,  1969,     0,
       0,   247,  1970,     0,     0,     0,   249,   250,   251,     0,
     252,   253,   254,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   398,     0,     0,     0,     0,     0,   257,
     194,   152,     0,  1421,   342,     0,     0,   195,   196,   197,
       0,   260,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   397,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,   230,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,     0,     0,     0,     0,   236,
      20,     0,   237,   194,   152,     0,  1483,     0,     0,     0,
     195,   196,   197,     0,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   397,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,   246,
       0,   567,     0,   247,     0,     0,     0,     0,   249,   250,
     251,   743,   252,   253,   254,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   398,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,   342,     0,     0,     0,
       0,     0,     0,   260,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,   246,     0,     0,     0,   247,   904,     0,     0,
       0,   249,   250,   251,     0,   252,   253,   254,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   398,     0,
       0,     0,     0,     0,   257,   194,   152,     0,     0,   342,
       0,     0,   195,   196,   197,     0,   260,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   397,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,   194,   152,     0,   236,    20,     0,   237,   195,   196,
     197,     0,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     397,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,   230,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,     0,
     236,    20,     0,   237,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,   246,     0,   905,     0,   247,     0,
       0,     0,     0,   249,   250,   251,     0,   252,   253,   254,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     398,     0,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   342,  1538,     0,     0,     0,     0,     0,   260,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
     246,     0,   567,     0,   247,     0,     0,     0,     0,   249,
     250,   251,   949,   252,   253,   254,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   398,     0,     0,     0,
       0,     0,   257,   194,   152,     0,     0,   342,  1857,     0,
     195,   196,   197,     0,   260,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   397,   216,   217,   218,   219,   220,   221,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,   230,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,   236,    20,     0,   237,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1056,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,     0,     0,     0,     0,     0,     0,   727,    50,
       0,    52,   728,     0,   729,   730,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,     1,    72,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,   246,     0,     0,     0,   247,    86,    87,    88,
       0,   249,   250,   251,     0,   252,   253,   254,     0,     0,
       0,   109,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   398,     0,
       0,     0,     0,     0,   257,    -4,    -4,    -4,     0,   342,
       0,    -4,    -4,     0,    -4,     0,   260,     0,     0,    -4,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
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
      17,     0,    18,    19,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,    37,    38,
      39,    40,    41,    42,     0,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    81,
      82,    83,     0,     0,     0,    84,     0,     0,     0,     0,
      85,    86,    87,    88,   152,   361,    89,     0,    90,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   152,   361,     0,     0,     0,     0,     0,
       0,   108,     0,   109,     0,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,     0,     0,     0,     0,   371,
     372,   373,   374,     0,     0,     0,     0,   375,   376,   377,
       0,     0,   378,     0,   379,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   380,   391,   361,   381,   371,   372,
     373,   374,     0,     0,     0,     0,   375,   376,   377,     0,
       0,   378,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   380,     0,     0,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   411,   362,   363,   364,
     365,   366,   367,   368,   369,   370,     0,     0,     0,     0,
     371,   372,   373,   374,     0,     0,     0,     0,   375,   376,
     377,     0,     0,   378,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   380,     0,     0,   381,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,   382,   383,   384,     0,     0,     0,     0,
     361,  1057,     0,     0,   385,     0,     0,     0,   386,     0,
     387,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   384,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,     0,   386,     0,   387,
     109,   362,   363,   364,   365,   366,   367,   368,   369,   370,
       0,     0,     0,     0,   371,   372,   373,   374,     0,     0,
       0,     0,   375,   376,   377,     0,     0,   378,     0,   379,
       0,     0,     0,     0,   382,   383,   384,     0,     0,   380,
       0,     0,   381,     0,     0,   385,     0,     0,     0,   386,
       0,   387,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1058,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1059,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,     0,   382,   383,
     384,  1097,     0,     0,     0,     0,     0,     0,     0,   385,
       0,     0,     0,   386,     0,   387,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1108,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1109,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1114,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1115,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1117,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1222,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1243,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1327,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1415,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1416,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1458,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1584,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1585,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1586,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1728,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1845,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1846,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1873,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1876,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1942,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1995,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1996,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2010,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2012,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2044,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2071,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2076,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2077,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2078,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2117,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
    1028,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,  1084,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,  1127,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,  1128,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,  1170,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,  1201,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,  1219,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,  1275,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,  1374,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,  1417,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
    1489,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,  1490,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,  1491,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,  1492,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,  1777,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,  1788,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,  1825,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,  1892,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,  1907,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,  1919,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
    1958,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,  1975,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,  1984,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,     0,  1985,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,  2008,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,  2057,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,  2096,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,  2115,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,  2135,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,     0,
       0,  2136,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,     0,     0,
    2137,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,     0,   689,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,     0,   896,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,     0,  1885,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,   714,
       0,   715,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,   955,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,  1006,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,  1151,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,  1214,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,  1215,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,     0,     0,  1220,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   688,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
    1221,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   688,   563,   564,   565,   566,     0,
       0,     0,     0,   567,     0,     0,     0,  1311,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   688,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,  1324,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   688,   563,
     564,   565,   566,     0,     0,     0,     0,   567,     0,     0,
       0,  1521,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,     0,     0,  1606,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   688,   563,   564,   565,   566,     0,     0,     0,
       0,   567,     0,     0,     0,  1653,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   688,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,  1837,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   688,   563,   564,   565,
     566,     0,     0,     0,     0,   567,     0,     0,     0,  1878,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   688,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,  1893,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   765,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   766,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   768,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   769,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   770,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   772,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   773,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   774,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   775,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   776,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   777,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   778,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   780,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   781,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   782,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   846,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   881,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   925,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   943,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   945,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   946,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   947,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   953,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,   954,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,   991,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1005,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1064,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1068,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1080,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1150,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1159,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1160,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1161,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1171,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1200,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1202,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1203,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1204,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1205,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1206,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1207,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1208,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1213,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1310,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1323,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1522,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1551,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1552,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1553,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1554,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1592,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1605,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1716,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1718,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1721,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1727,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1778,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1787,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1810,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1877,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  1940,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  1941,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567,
       0,  2070,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   688,   563,   564,   565,   566,
       0,     0,     0,     0,   567,     0,  2112,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     688,   563,   564,   565,   566,     0,     0,     0,     0,   567
};

static const yytype_int16 yycheck[] =
{
       3,  1195,   148,   297,   135,   100,     3,   102,    56,  1199,
     693,  1380,     4,  1684,   309,  1686,   183,    20,    49,     4,
       4,     4,    20,     3,   191,   603,   604,   709,     4,     4,
       4,     4,   327,  1858,     4,   717,     5,     4,  1641,   129,
     135,   724,     6,     5,     4,     4,    49,     5,     5,     4,
       4,     7,     0,     6,     6,     6,     6,   740,    91,  1671,
       4,    97,   157,   149,     6,   748,     9,   236,   237,    97,
       4,     9,     6,    76,    14,    55,   245,   110,     7,   227,
     228,    84,   227,   228,   120,    97,    89,   177,   174,   242,
       9,   129,   120,   186,   243,   248,   239,   100,   247,   394,
     248,   396,   129,   248,   190,   191,     4,    83,   146,   404,
       6,     9,   279,   280,   281,     6,   154,   155,   156,   146,
       7,  1733,   160,   161,     9,   236,   237,   154,   155,   156,
     227,   228,   135,   160,   161,   239,     9,   140,   141,   136,
     227,   228,   227,   228,     6,   148,   100,   101,     6,  1752,
       9,   248,   239,   320,   321,   322,   243,    91,   242,   162,
     239,   192,   241,   248,   248,   848,   245,     6,   240,   248,
     337,     6,   239,   245,   241,   178,   227,   228,  2003,     6,
     183,   248,   275,   186,   227,   228,   227,   228,   191,   192,
     193,   164,   165,   166,   167,   239,     6,   248,   162,   243,
       7,   227,   228,   244,     7,   248,   189,   174,   175,   185,
     240,   162,   243,   227,   228,   174,   175,   244,   248,     6,
     227,   228,   248,   227,   228,   239,   211,   211,  1597,   243,
     240,   239,   227,   228,     7,   211,   211,   211,   248,  1433,
     243,   248,     7,   239,   248,   227,   228,   278,   243,   241,
     240,   211,   232,   256,     7,   247,   259,   260,   248,   243,
     291,   246,   260,     6,   295,   245,   248,   243,   243,   239,
      94,   244,   275,    97,   243,   278,   279,   280,   281,  1882,
     240,   243,   242,   112,   239,   243,   243,   239,   291,   245,
     243,   243,   295,   243,   297,   239,   239,   592,   241,   594,
     595,   239,   245,   241,   241,    62,    63,   245,    65,   402,
     239,   241,   241,   211,   239,   410,   611,   320,   321,   322,
     239,   239,   241,  1005,  1006,   212,   213,   214,   215,   232,
     233,   227,   228,  1936,   337,   238,   227,   228,   236,   237,
     343,   239,   239,   241,   241,   243,   243,   245,   243,   236,
     237,   236,   237,     4,   239,   650,   241,   242,   245,   245,
     245,   528,   248,   236,   237,   240,   239,  2038,   241,   227,
     228,   239,   245,   248,   520,   406,   407,   236,   237,     8,
     239,    97,   241,   222,   223,   240,   245,   222,   223,   239,
       4,   422,   239,   248,   689,   227,   228,    94,   401,   402,
      97,   227,   228,   406,   407,   212,   213,   214,   215,   212,
     213,   214,   215,   110,   239,   135,   248,     6,   240,   422,
     140,   141,   248,   227,   228,   428,   248,     6,     7,   236,
     237,   133,   134,   236,   237,   227,   228,   139,   533,   212,
     213,   214,   215,   536,   248,   239,   449,   212,   213,   214,
     215,  1134,   432,  1136,     6,     7,   248,   240,   178,   212,
     213,   214,   215,   236,   237,   248,  1149,   239,   227,   228,
    2073,   227,   228,   193,   243,   478,   239,    91,   241,   239,
     243,    95,   133,   134,   135,   136,   517,   101,   102,   248,
     104,   105,   248,   239,   587,   588,   527,   148,   239,   502,
     151,   239,   227,   228,   239,  1874,   509,   510,   243,   123,
     239,   514,   658,   516,   517,   518,   519,   520,   227,   228,
     523,   239,  2125,   248,   527,   528,   529,   530,   531,   532,
     240,   534,   242,   536,   532,    99,   534,   129,   248,   248,
     633,   634,   635,   300,   301,     8,   227,   228,   239,   227,
     228,   308,   309,   239,   146,   241,   227,   228,   243,   562,
     227,   228,   154,   155,   156,   568,    97,   248,   160,   161,
     248,   244,   240,  1256,   242,   248,   671,   248,   709,  1262,
     248,   248,   227,   228,   587,   588,   679,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   900,   603,   604,    94,   238,
     129,    97,   244,    99,    91,   244,   248,    94,   227,   228,
      97,   244,    99,   716,   110,   248,  1309,   146,   239,   609,
     633,   634,   635,   110,   243,   154,   155,   156,   239,  1322,
     244,   160,   161,   736,   248,  1328,   227,   228,    94,   742,
     630,   239,   244,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   243,   666,   667,   668,   669,   670,   763,   672,
     673,   674,   675,   676,   243,   706,   679,   675,   236,   237,
      91,   401,   730,    94,   244,   243,    97,   690,   248,   129,
     227,   228,   229,   230,   231,   232,   233,   243,    97,   110,
      99,   238,   682,   706,    91,   685,   146,    94,    97,   239,
      97,   241,    99,   716,   154,   155,   156,   697,   721,    97,
     160,   161,    94,    91,  1406,   244,    94,    94,   821,    97,
     240,    99,   242,   736,   737,   240,     4,   242,   248,   742,
     236,   237,   745,   746,     4,     4,   877,   243,   751,   729,
     753,     4,   239,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,     6,   240,   866,   242,   238,   240,   239,   242,   241,
     248,   244,   239,   786,   248,   788,   879,   239,   229,   230,
     231,   232,   233,     6,   514,   890,   516,   238,   518,   519,
     133,   134,    94,   896,   244,    97,   139,    99,   244,   529,
     530,   244,   248,  1495,   243,   248,   244,   244,   821,   244,
     248,   248,   244,   248,   244,  1507,   248,   244,   248,   244,
     244,   248,   244,   248,   248,   244,   248,  2027,   244,   248,
       6,   241,   248,   244,   601,   602,   244,   248,   244,   606,
     248,   244,   248,   244,   244,   248,   887,   248,   248,   245,
     244,   247,   244,   866,   248,  2059,   248,   244,   244,   244,
     239,   248,   248,   248,  1005,  1006,   879,   239,   244,   244,
     241,     8,   248,   248,   887,   244,   244,   244,   244,   248,
     248,   248,   248,   896,  2084,   244,   244,   244,   244,   248,
     248,   248,   248,   244,   239,   244,   244,   248,  2102,   248,
     248,   247,  1007,   244,   244,     6,   244,   248,   248,   899,
     248,   901,   902,   244,   244,   244,   244,   248,   248,   248,
     248,   239,   243,   241,  1027,   915,   239,   657,   241,   659,
     660,   661,   662,   663,   664,   247,   666,   667,   668,   669,
     239,     8,   672,   673,   674,   240,     9,   242,   243,   240,
     239,   242,   243,   239,   239,   241,   997,     4,   239,     6,
     950,   243,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,  1016,   177,   239,  1081,   238,
     177,   239,   239,   239,   997,   239,   239,  1291,   177,   120,
     239,   243,   239,   239,   177,   239,   986,   239,  1011,   239,
     243,     4,   243,  1016,   243,   243,   243,   243,   239,  1150,
    1151,   239,   239,   239,  1027,   745,     6,   239,   239,  1032,
     239,  1062,  1063,   753,  1065,  1066,  1067,   239,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1626,  1627,
       6,   241,     6,     6,   243,   243,     6,   243,   243,  1062,
    1063,   241,  1065,  1066,  1067,  1158,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,   241,   241,  1081,   177,
     243,   239,   239,   239,   239,   239,   239,     6,  1119,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   241,     6,     6,
    1141,   238,   243,   240,     8,   242,  1119,  1120,  1121,     6,
       8,   243,     7,     6,   243,     6,  1157,   243,    86,   244,
     248,   248,   240,     7,     6,     6,   240,   243,  1141,   238,
     243,  1234,    64,   245,     8,     4,   903,     7,   240,     7,
     239,     6,     6,   910,  1157,  1158,   243,   914,     7,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,     6,  1209,  1310,
    1311,   238,     7,   240,     6,     6,   244,  1482,   174,   243,
     242,  1486,  1223,  1224,  1225,   244,   244,  1177,   240,     6,
     243,   245,   243,   243,   243,     7,  1209,     6,  1502,   241,
     239,     4,   243,   240,     6,     6,     6,     4,     5,   241,
    1223,  1224,  1225,  1316,     6,   243,     7,     7,     7,     7,
       7,  1234,     7,     7,     7,  1330,  1239,  1332,     7,     7,
    1243,  1272,     7,     7,     7,     7,     7,     7,     6,  1252,
     240,  1254,   248,   242,  1257,   240,   248,   248,     7,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   244,  1272,
     248,   243,    59,    60,    61,    62,   244,     7,   245,   243,
      67,    68,    69,     4,     6,    72,  1266,    74,  1291,   129,
     245,     7,   244,   244,     6,   240,     7,    84,     7,     7,
      87,  1332,   245,   240,  1061,     9,   248,   248,  1311,   248,
    1888,   240,  1032,  1316,  1345,   242,   247,   245,  1349,     7,
     177,   149,     6,   244,     6,   243,     6,     4,    46,  1332,
     245,    46,   239,   243,   239,   239,   245,   245,   239,   126,
       4,     7,  1345,   177,     7,     7,  1349,   240,   248,     7,
       7,     7,  1445,     6,   240,     7,   248,     7,     7,     4,
       4,   109,  1508,  1509,  1495,   243,     6,   243,     7,  1400,
    1401,  1402,   239,     6,    97,     7,     7,  1408,     7,     7,
       7,     7,     7,  1478,     6,     6,     6,   248,     7,     6,
       6,     4,  1423,     4,   246,   240,   243,  1400,  1401,  1402,
    1120,  1121,   248,  1434,  1698,  1408,   193,   194,   195,   244,
     243,  1442,   243,     6,     6,     6,     6,   204,     7,     6,
    1423,   208,   241,   210,   211,   239,   239,   243,     6,   244,
       6,  1434,     6,   245,   242,     6,     6,   248,   123,  1442,
       6,     6,  1445,     6,  1539,     6,     6,     6,     6,   236,
     237,     6,     6,     6,     6,     6,   243,     5,   245,     6,
       4,     6,     4,     6,   240,   248,     7,     6,   240,     6,
       6,   241,   243,  1604,     6,     6,   243,   243,   173,     6,
       6,     6,     6,  1514,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,  1502,
     243,   243,   243,   238,   243,  1508,  1509,   243,  1539,   243,
     243,  1514,   243,   240,   243,     7,   248,   243,   243,  1239,
     248,     4,   239,  1243,   248,  1618,  1619,  1622,  1531,     6,
       6,   245,  1252,     6,  1254,     6,  1539,  1257,   244,   239,
       4,  1544,   239,     5,     7,     6,     6,     6,     6,     6,
       6,     6,     6,     6,   243,  1701,   248,    95,     6,   240,
     243,     6,   248,     6,     6,     6,     6,   240,     6,  1664,
     248,     4,   248,   248,     6,     6,  1671,  1672,   243,     6,
       6,     6,   243,  1714,  1615,     7,     5,     7,   243,   243,
       6,  1311,   243,   240,     6,  1690,     6,   243,     6,     6,
     243,   243,  1897,   244,   172,     6,   244,   244,   244,   244,
    1641,     6,  1615,     7,     6,  1618,  1619,   240,     6,     6,
       6,   245,     6,     6,     6,  1656,   244,     6,   243,  1626,
    1627,  1925,   240,   243,     6,   175,     6,   243,  1641,   244,
     244,   239,   243,   240,  1647,     6,     6,   243,   243,     6,
     244,   129,     6,  1656,     6,   243,  1687,    13,    14,     6,
     243,   240,     6,  1666,     6,     6,  1669,   244,     6,  1700,
       6,   244,     6,     6,     6,  1432,     6,     6,     6,   243,
       6,   243,     6,     6,  1687,     6,   243,     6,     6,     6,
    1321,  1694,  2040,   446,  1989,  1698,  1375,  1700,  1701,  1859,
    1549,  1822,  1611,  1344,  1684,     3,  1686,     3,     3,     3,
    1884,  1475,   582,     3,  1509,  1694,    -1,   745,  1811,    -1,
      -1,  1752,  1671,    -1,    -1,    -1,    -1,    -1,    -1,  1824,
    1733,    -1,    -1,  2028,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,  1752,
      -1,   107,   108,   109,   110,  1786,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,   123,   124,  1864,
     126,   127,    -1,  1866,  1867,    -1,   132,    -1,     4,     5,
      -1,    -1,    -1,  1786,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,  1885,   149,    -1,  1798,    -1,    -1,    -1,    -1,
    1557,    -1,    -1,    -1,    -1,    -1,    -1,  1900,  1811,    -1,
      -1,  1531,    -1,   169,   170,   171,    -1,  1848,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,  1860,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,  1848,    72,    -1,    74,    -1,
      -1,  1882,    -1,    -1,    -1,    -1,    -1,  1860,    84,    -1,
      -1,    87,  1865,  1866,  1867,  1896,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1882,
      -1,    -1,  1885,    -1,    -1,  1642,  1643,  1644,  1645,  1646,
    1647,  1888,    -1,  1896,    -1,    -1,    -1,  1900,    -1,    -1,
     126,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,  2004,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1925,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1962,    -1,  1936,    -1,    -1,    -1,  2030,  2031,  2032,
    2033,  2034,    -1,    -1,    -1,    -1,  1666,    -1,    -1,  1669,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1962,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,    -1,   210,   211,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,  1974,    -1,  2089,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   240,   135,   242,   243,   238,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,  2030,  2031,  2032,
    2033,  2034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2073,   163,   164,   165,    -1,   167,   168,   169,
      -1,   171,   172,   173,   174,   175,   176,   177,  2038,   179,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,
    2073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2060,    -1,    -1,    -1,    -1,    -1,  2089,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2125,    -1,    -1,    -1,    -1,    -1,    -1,  2132,
    2133,    -1,    -1,    -1,    -1,   255,   256,   257,   258,   259,
      -1,    -1,    -1,  2146,  1901,  1902,  1903,  1904,  1905,    -1,
      -1,    -1,    -1,    -1,   274,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   304,    -1,    -1,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,
      -1,    -1,    -1,    -1,  1961,    -1,    -1,    -1,  1965,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   342,   343,    -1,    -1,    -1,   347,   348,   349,
      -1,   351,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,
     360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2014,    -1,    -1,
      -1,  2018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2034,   398,    -1,
      -1,    -1,   402,   403,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2079,  2080,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,   452,   453,   454,    -1,    -1,    -1,    -1,   459,
      -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,    -1,
      -1,    -1,   482,    -1,    -1,    -1,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,  2111,   512,   513,    -1,   515,    -1,    -1,    -1,    -1,
      -1,    -1,   522,    -1,    -1,   525,   526,    -1,    -1,    -1,
      -1,   531,  2132,  2133,    -1,    -1,   536,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2146,    -1,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,    -1,   569,
     570,    -1,    -1,    -1,    -1,    -1,   576,   577,   578,    -1,
      -1,    -1,    -1,    -1,   584,   585,    -1,   587,   588,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,   606,   607,   608,    -1,
      -1,    -1,   612,   613,   614,   615,   616,   617,   618,   619,
     620,    -1,    -1,    -1,    -1,   625,    -1,   627,    -1,   629,
      -1,    -1,    -1,   633,   634,   635,   636,    -1,   638,   639,
     640,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,   665,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,   679,
      -1,    -1,    -1,    -1,    84,    -1,   686,    87,   688,    -1,
      -1,   691,   692,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   716,    -1,    -1,    -1,
      -1,     6,   722,   723,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   736,    -1,   738,   739,
      -1,    -1,   742,   743,    -1,    -1,    -1,   747,    -1,    -1,
      -1,    -1,    -1,    -1,   754,    -1,    -1,    -1,   758,    -1,
      -1,    -1,    -1,   256,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,   784,    -1,   786,    -1,   788,    -1,
      -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   866,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   879,
      -1,    -1,    -1,    -1,    -1,    -1,   886,    -1,    -1,    -1,
     890,    -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   904,   905,    -1,    -1,    -1,   402,
     910,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   926,    -1,    -1,   929,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   949,
      -1,   951,   952,   238,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   993,    -1,    -1,    -1,    -1,    -1,    -1,
    1000,  1001,  1002,  1003,    -1,    -1,    -1,    -1,  1008,   502,
      -1,    -1,    -1,    -1,    -1,    -1,   509,   510,    -1,    -1,
      -1,    -1,  1022,  1023,    -1,    -1,    -1,  1027,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,
      -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1056,  1057,  1058,  1059,
      -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,   562,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   587,   588,    -1,  1097,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1107,  1108,  1109,
      -1,    -1,    -1,    -1,  1114,  1115,    -1,  1117,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1129,
    1130,    -1,    -1,    -1,    -1,    -1,    -1,  1137,  1138,    -1,
     633,   634,   635,    -1,  1144,     6,  1146,  1147,    -1,    -1,
      -1,    -1,    -1,  1153,  1154,    -1,    -1,    -1,  1158,    -1,
      -1,    -1,    -1,    -1,   523,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,   679,   238,    -1,  1189,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,   573,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1222,   716,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1242,   736,    -1,    -1,    -1,    -1,    -1,   742,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1263,  1264,    -1,    -1,    -1,  1268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1282,    -1,    -1,  1285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   786,    -1,   788,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1312,    -1,    -1,  1315,  1316,  1317,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1325,    -1,  1327,   821,  1329,
    1330,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,     6,
      -1,    -1,    -1,   238,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   866,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   879,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   896,    -1,    -1,    -1,  1407,    -1,    -1,
      -1,    -1,    -1,    -1,  1414,  1415,  1416,    -1,    -1,    -1,
      -1,    -1,    -1,  1423,    -1,  1425,    -1,    -1,    -1,    -1,
      -1,    -1,  1432,    -1,   793,   794,   795,   796,   797,   798,
     799,   800,   801,   802,   803,  1445,   805,   806,   807,   808,
    1450,   810,   811,   812,   813,    -1,    -1,    -1,  1458,  1459,
    1460,    -1,    -1,    -1,    -1,   824,    -1,   826,    -1,    -1,
    1470,    -1,    -1,    -1,    -1,   834,    -1,    -1,    -1,    -1,
    1480,   840,   841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     849,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1506,    -1,    -1,    -1,
      -1,    -1,  1512,  1513,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,     6,  1027,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1544,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,  1584,  1585,  1586,    -1,  1081,    -1,
      -1,    -1,    -1,    -1,    -1,  1595,    -1,   956,   957,   958,
    1600,  1601,  1602,   962,   963,    -1,    -1,   966,   967,   968,
     969,    -1,   971,  1613,    -1,     6,    -1,   976,  1618,  1619,
    1620,    -1,  1622,    -1,    -1,    -1,    -1,    -1,  1628,  1629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,    -1,    -1,
      -1,  1651,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1664,  1158,    -1,  1667,    -1,    -1,
      -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1680,  1681,    -1,  1683,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1691,    -1,    -1,    -1,    -1,  1055,    -1,    -1,     6,
      -1,  1060,    -1,    -1,    -1,    -1,    -1,  1707,    -1,    -1,
      -1,    -1,  1712,  1713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1725,    -1,    -1,  1728,  1729,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1234,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,  1764,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1789,
      -1,    -1,    -1,    -1,    -1,    -1,  1155,    -1,  1798,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1807,  1808,    -1,
      -1,  1811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1316,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     6,    -1,  1845,  1846,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1863,    -1,    -1,  1866,  1867,  1868,    -1,
      -1,    -1,    -1,  1873,    -1,    -1,  1876,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,  1885,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1908,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,  1933,    -1,  1294,    -1,    -1,    -1,  1939,
      -1,    -1,  1942,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1445,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
    1970,    -1,  1331,   107,   108,   109,   110,    -1,    21,   113,
      23,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,   123,
     124,    -1,   126,   127,    -1,  1995,  1996,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1363,  1364,  1365,  1366,  1367,  2009,
    2010,   145,  2012,  1372,  1373,    -1,    -1,  1376,    -1,  1378,
      -1,    -1,    -1,  1382,    -1,  2025,  1385,    -1,    -1,    -1,
    2030,  2031,  2032,  2033,  2034,   169,   170,   171,  1397,    -1,
    2040,    -1,    -1,    -1,  2044,    -1,    -1,    -1,    -1,    -1,
      -1,  1544,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,  2071,    -1,    -1,     6,   238,  2076,  2077,  2078,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2089,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1466,    -1,  1468,
     244,    -1,    -1,  1472,    -1,  1474,    -1,  2117,  2118,  2119,
      -1,    -1,    -1,    -1,    -1,  1618,  1619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,  1508,
      -1,    -1,    -1,    -1,  1647,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,   247,   248,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1603,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     6,    -1,    -1,  1798,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1811,   362,
     363,   364,    -1,    -1,    -1,   368,   369,   370,   371,   372,
     373,   374,    -1,   376,    -1,    -1,    -1,   380,   381,    -1,
      -1,   384,    -1,    -1,  1703,    -1,    -1,  1706,    -1,    -1,
      -1,    -1,    -1,    -1,   397,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,  1866,  1867,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,    -1,  1885,   196,  1753,  1754,    -1,  1756,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,  1900,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
     243,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1815,  1816,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,     7,
       8,   544,  1861,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,  2030,  2031,  2032,
    2033,  2034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,  2089,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2098,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,   210,   211,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,    -1,    -1,   246,    -1,    -1,
      -1,   844,    -1,    -1,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     3,     4,     5,    -1,   238,    -1,
      -1,    10,    11,    12,   244,   878,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,     8,    -1,    -1,   148,
      -1,    -1,   151,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,  1049,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,    -1,    -1,   246,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,     3,     4,
       5,   238,     7,   240,    -1,    10,    11,    12,    -1,  1142,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    -1,    87,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1295,  1296,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,     8,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,   236,   237,    -1,   239,    -1,   241,    -1,    -1,    -1,
     245,   246,    -1,    -1,    -1,    -1,    -1,  1380,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,  1390,    10,    11,
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
     122,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1543,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,   239,     3,     4,
      -1,   243,    -1,     8,   246,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    13,    14,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   121,    -1,   123,   124,   192,   126,   127,
      -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,   169,   170,   171,   239,     3,     4,     5,    -1,   244,
      -1,   246,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,    77,
      -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,   192,   126,   127,    -1,   196,   197,
      -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,   207,
      -1,    -1,    -1,   211,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,    -1,   169,   170,
     171,   239,     3,     4,    -1,   243,    -1,    -1,   246,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   122,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,   123,
     124,   192,   126,   127,    -1,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,
     211,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,    -1,   169,   170,   171,   239,     3,
       4,    -1,   243,   244,    -1,   246,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    75,    76,    77,    -1,    -1,    13,    14,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   121,    -1,   123,   124,   192,   126,
     127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   169,   170,   171,   239,     3,     4,    -1,   243,
      -1,    -1,   246,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,
      77,    -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,   123,   124,   192,   126,   127,    -1,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,    -1,    -1,    -1,   211,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,   169,
     170,   171,   239,     3,     4,    -1,   243,    -1,    -1,   246,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,
      13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,
     123,   124,   192,   126,   127,    -1,   196,   197,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,    -1,    -1,
      -1,   211,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,   169,   170,   171,   239,
       3,     4,    -1,   243,    -1,    -1,   246,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    75,    76,    77,    -1,    -1,    13,    14,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,
      -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,   123,   124,   192,
     126,   127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,   169,   170,   171,   239,     3,     4,    -1,
      -1,   244,    -1,   246,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,   121,    -1,   123,   124,   192,   126,   127,    -1,
     196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
     206,   207,    -1,    -1,    -1,   211,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
     169,   170,   171,   239,     3,     4,    -1,   243,    -1,    -1,
     246,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,
      -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,   122,    -1,   124,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
      -1,   123,   124,   192,   126,   127,    -1,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,   169,   170,   171,
     239,     3,     4,    -1,   243,    -1,    -1,   246,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    75,    76,    77,    -1,    -1,    13,    14,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
     122,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,     8,
      -1,    -1,    -1,    -1,    -1,   120,   121,    -1,   123,   124,
     192,   126,   127,    -1,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,    -1,   169,   170,   171,   239,     3,     4,
      -1,   243,    -1,     8,   246,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,
      -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
       3,     4,    -1,    -1,   239,     8,    -1,    10,    11,    12,
      -1,   246,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,     3,     4,    -1,    -1,   239,    -1,    -1,    10,
      11,    12,    -1,   246,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   122,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,   123,
     124,   192,   126,   127,    -1,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,
     211,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,    -1,   169,   170,   171,   239,     3,
       4,    -1,   243,    -1,    -1,   246,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    75,    76,    77,    -1,    -1,    13,    14,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,
     124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,     8,    -1,    -1,
      -1,    -1,    -1,   120,   121,    -1,   123,   124,   192,   126,
     127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   169,   170,   171,   239,     3,     4,    -1,   243,
      -1,    -1,   246,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,   122,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,     3,     4,
       5,    -1,   239,    -1,    -1,    10,    11,    12,    -1,   246,
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
      -1,    -1,    72,    -1,    74,    75,    76,    77,   129,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,   243,    -1,
      -1,   246,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,   239,
       3,     4,     5,   243,    -1,    -1,   246,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    -1,    87,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
     243,    -1,    -1,   246,    -1,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,    -1,   242,   192,   193,   194,   195,   196,   248,
      -1,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,     3,     4,    -1,
      -1,   239,    -1,    -1,    10,    11,    12,    -1,   246,    15,
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
      -1,    -1,    82,    83,    -1,    85,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,    -1,    -1,    -1,    -1,    -1,   192,    -1,   248,    -1,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
     206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,   243,    -1,    -1,
     246,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,   192,    -1,   238,    -1,   196,    -1,    -1,    -1,
     244,   201,   202,   203,   248,   205,   206,   207,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,     3,     4,    -1,    -1,   239,
      -1,    -1,    10,    11,    12,    -1,   246,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,   192,    -1,   238,    -1,   196,    -1,
      -1,    -1,   244,   201,   202,   203,   248,   205,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,   192,   244,    -1,
      -1,   196,   248,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
       3,     4,    -1,     6,   239,    -1,    -1,    10,    11,    12,
      -1,   246,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,     3,     4,    -1,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,   192,
      -1,   238,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,   248,   205,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,   246,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,   196,   248,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,     3,     4,    -1,    -1,   239,
      -1,    -1,    10,    11,    12,    -1,   246,    15,    16,    17,
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
      82,    83,    -1,    85,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,    -1,   248,    -1,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
     192,    -1,   238,    -1,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,   248,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,     3,     4,    -1,    -1,   239,   240,    -1,
      10,    11,    12,    -1,   246,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,   145,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,   196,   169,   170,   171,
      -1,   201,   202,   203,    -1,   205,   206,   207,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    64,    65,    66,    -1,   239,
      -1,    70,    71,    -1,    73,    -1,   246,    -1,    -1,    78,
      -1,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,   106,   107,   108,
     109,   110,   111,    -1,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,     4,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,    13,    14,    -1,    -1,   168,
     169,   170,   171,    -1,    -1,   174,    -1,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    44,    45,    -1,   198,
     199,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,    -1,   211,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,   106,   107,
     108,   109,   110,   111,    -1,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,     4,     5,   174,    -1,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   199,   200,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,   209,    -1,   211,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    84,     4,     5,    87,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,
       5,   248,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,   210,
     211,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,   204,    -1,    -1,    -1,   208,
      -1,   210,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,   208,    -1,   210,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   244,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   244,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   244,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,   243,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,   243,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,   243,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,   240,
      -1,   242,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   242,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
     242,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,   242,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,   242,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   250,   251,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    80,    81,
      83,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   106,   107,   108,
     109,   110,   111,   113,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   157,   158,   159,   163,   168,   169,   170,   171,   174,
     176,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   198,   199,   200,   209,   211,
     252,   254,   255,   275,   293,   295,   299,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   317,   319,   320,   326,
     327,   328,   329,   335,   360,   361,   243,   247,    14,    97,
     239,   239,     6,   243,     6,     6,     6,     6,   239,     6,
     241,   241,     4,   337,   361,   239,   241,   273,    91,    94,
      97,    99,   273,   239,   239,   239,     4,   239,   239,   239,
       4,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   243,   112,    97,     6,   243,    91,    94,    97,
     110,   298,    99,   239,     3,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    55,    56,    57,
      58,    63,    64,    75,    76,    77,    82,    85,    91,    94,
      97,    99,   110,   120,   124,   126,   192,   196,   197,   201,
     202,   203,   205,   206,   207,   227,   228,   234,   239,   243,
     246,   295,   296,   299,   310,   317,   319,   330,   331,   335,
     337,   344,   346,   361,   239,   243,    97,    97,   120,    94,
      97,    99,    91,    94,    97,    99,   295,    94,    97,    99,
     110,   296,    94,    97,   239,    94,   149,   174,   190,   191,
     243,   227,   228,   239,   243,   341,   342,   341,   243,   243,
     341,     4,    91,    95,   101,   102,   104,   105,   123,   239,
      97,    99,    97,    94,     4,    83,   185,   243,   361,     4,
       6,    91,    94,    97,    94,    97,   110,   297,     4,     4,
       4,     5,   239,   243,   344,   345,     4,   239,   239,   239,
       4,   243,   348,   361,     4,   239,   239,   239,     6,     6,
     241,     5,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    59,    60,    61,    62,    67,    68,    69,    72,    74,
      84,    87,   193,   194,   195,   204,   208,   210,   352,   361,
     239,     4,   352,     5,   243,     5,   243,    32,   228,   330,
     361,   241,   243,   239,   243,     6,   239,   243,     6,   247,
       7,   126,   185,   212,   213,   214,   215,   236,   237,   239,
     241,   245,   271,   272,   273,   330,   351,   352,   361,     4,
     299,   300,   301,   243,     6,   330,   351,   352,   361,   351,
     330,   351,   358,   359,   361,   277,   281,   239,   340,     9,
     352,   239,   239,   239,   239,   361,   330,   330,   330,   239,
     330,   330,   330,   239,   330,   330,   330,   330,   330,   330,
     330,   351,   330,   330,   330,   330,   345,   239,   228,   330,
     346,   347,   243,   345,   344,   351,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   239,
     241,   273,   273,   273,   273,   273,   273,   239,   273,   273,
     239,   295,   273,   273,     5,   243,   243,   120,   295,   239,
     273,   273,   239,   239,   239,   330,   243,   330,   346,   330,
     330,   244,   347,   337,   361,   177,     5,   243,     8,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   238,     9,   239,
     241,   245,   272,   273,   330,   347,   239,   239,   239,   344,
     345,   345,   345,   294,   243,   239,   344,   243,   243,   330,
       4,   344,   243,   348,   243,   243,   341,   341,   341,   330,
     330,   227,   228,   243,   243,   341,   227,   228,   239,   301,
     341,   243,   239,   243,   239,   239,   239,   239,   239,   239,
     239,   330,   345,   345,   345,   239,     4,   241,     6,   241,
     301,     6,     6,   243,   243,   243,   243,   345,   241,   241,
     241,   330,     8,     6,     6,   330,   330,   330,   245,   330,
     243,   177,   330,   330,   330,   330,   273,   273,   273,   239,
     239,   239,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   239,   239,   273,   239,   241,     6,     6,   243,
       6,     8,   301,     6,     8,   301,   273,   330,   229,   243,
       9,   239,   241,   245,   351,   347,   330,   301,   344,   344,
     243,   352,    91,    94,    97,    99,     7,   330,   330,     4,
     174,   175,   344,     6,   240,   242,   243,   274,     6,   243,
       6,     9,   239,   241,   245,   361,   244,   120,   124,   126,
     127,   293,   295,   330,     6,   240,   248,     9,   239,   241,
     245,   240,   248,   248,   240,   248,     9,   239,   245,   242,
     248,   276,   242,   276,    86,   339,   336,   361,   248,   330,
     330,   330,   330,   248,   240,   240,   240,   330,   240,   240,
     240,   330,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   244,     7,   330,   229,   244,   248,   330,
       6,     6,   240,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     346,   330,   330,   330,   330,   330,   330,   330,   346,   346,
     361,   243,   330,   330,   351,   330,   351,   344,   351,   351,
     358,   243,   330,   274,   361,     8,   330,   330,   345,   351,
     351,   346,   337,   352,   337,   347,   240,   244,   245,   273,
      64,     8,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   243,   330,   346,   330,
     330,   330,   330,   330,   361,   330,   330,     4,   338,   243,
     274,   240,   244,   330,   330,   330,     7,     7,   323,   323,
     239,   330,   330,     6,   347,   347,   243,   240,     6,   301,
     243,   301,   301,   248,   248,   248,   341,   341,   300,   300,
     248,   330,   244,   314,   248,   301,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   240,     7,   324,     6,     7,
     330,     6,   330,   330,   244,   347,   347,   347,   330,     6,
     330,   330,   330,   240,   244,   240,   240,   240,   174,   248,
     301,   243,     8,   240,   240,   242,   358,   351,   358,   351,
     351,   351,   351,   351,   351,   330,   351,   351,   351,   351,
     246,   354,   361,   352,   351,   351,   351,   337,   361,   347,
     244,   244,   244,   244,   330,   330,   301,   361,   338,   242,
     244,   240,   132,   149,   318,   240,   244,   248,   330,     6,
     243,   243,   243,   243,   344,   240,   242,     7,   271,   272,
     245,     7,     6,   347,     7,   215,   271,   256,   361,   330,
     330,   338,   241,   239,   120,   295,   296,   243,   244,     6,
     222,   223,   253,   347,   361,   330,   330,     4,   338,     6,
     347,   330,     6,   351,   359,   361,   240,   338,     6,   361,
       6,   351,   330,   240,   241,   330,   248,   248,   248,   248,
     352,     7,     7,     7,   240,     7,     7,     7,   240,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   330,
     240,   243,   330,   346,   244,     6,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   248,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   248,   248,   248,
     240,   242,   242,   347,   248,   248,   274,   248,   274,   248,
     248,   248,   240,   330,   332,   274,   244,   244,   244,   248,
     248,   274,   274,   240,   245,   240,   245,   248,   273,   333,
     244,     7,   338,   274,   243,   244,     8,     8,   347,   245,
     240,   242,   272,   239,   241,   273,   347,     7,   243,   240,
     240,   240,   330,   344,     4,   322,     6,   290,   330,   352,
     244,   240,   244,   244,   347,   245,   244,   301,   244,   244,
     341,   330,   330,   244,   244,   330,   341,   129,   129,   146,
     154,   155,   156,   160,   161,   315,   316,   341,   244,   311,
     240,   244,   240,   240,   240,   240,   240,   240,   240,     7,
     330,     6,   330,   240,   242,   242,   244,   244,   244,   244,
     242,   242,   248,     7,     7,     7,   245,   330,   244,   330,
     330,     7,   245,   274,   248,   274,   274,   240,   240,   248,
     274,   274,   248,   248,   274,   274,   274,   274,   330,   274,
       9,   353,   248,   240,   248,   274,   245,   248,   334,   242,
     244,   244,   245,   239,   241,   247,   177,     7,   149,     6,
     330,   244,   243,     6,   344,   244,   330,   330,   330,   330,
       6,     7,   271,   272,   245,   271,   272,   352,   330,     6,
       4,   243,   349,   361,   244,    46,    46,   344,     4,   164,
     165,   166,   167,   244,   259,   263,   266,   268,   269,   245,
     240,   242,   239,   330,   330,   239,   243,   239,     8,   347,
     351,   240,   245,   240,   242,   239,   240,   248,   245,   239,
       7,   273,     4,   284,   285,   286,   274,   330,   330,   330,
     330,   274,   341,   344,   344,     7,   344,   344,   344,     7,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
       6,     7,   347,   330,   330,   330,   330,   244,   330,   330,
     330,   344,   351,   351,   244,   248,   283,   330,   330,   338,
     338,   330,   330,   240,   344,   273,   330,   330,   330,   244,
     338,   272,   245,   272,   330,   330,   274,   244,   344,   347,
       7,     7,     7,   129,   321,     6,   240,   248,     7,     7,
       7,   244,     4,   244,   248,   248,   248,   244,   244,   109,
       4,     6,   330,   243,     6,   239,     6,   162,     6,   162,
     244,   316,   248,   315,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   344,     6,   243,     6,     6,     6,    97,
       7,     6,     6,   330,   344,   344,   344,     4,   248,     8,
       8,   240,     4,   100,   101,     4,   347,   351,   330,   351,
     246,   248,   287,   351,   351,   338,   351,   240,   248,   338,
     243,   295,   243,     6,   330,     6,   243,   344,   244,   244,
     244,   244,   244,   330,     6,     4,   174,   175,   330,     6,
       6,     6,     7,   348,   350,     6,   241,   274,   273,   273,
       6,   260,   239,   239,   243,   270,     6,   338,   245,   351,
     330,   242,   240,   330,     8,   347,   330,   244,   244,     6,
       6,   253,   338,   245,   330,     6,   330,   338,   240,   243,
     330,   352,   274,    46,   243,   344,   352,   355,   242,   248,
       6,   240,   240,   240,   240,     6,     6,   123,   292,   292,
     344,     6,     6,     6,   344,   129,   177,   291,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   244,   274,
     274,   274,   274,   274,   248,   248,   248,   240,   274,   274,
     285,   274,   240,   274,   240,   273,   333,   274,     6,   274,
     248,   239,   241,   273,     4,   240,   242,   274,     6,   244,
     344,   344,   344,     4,     6,   271,   330,   344,   243,   243,
       7,     6,     7,   330,   330,   330,   243,   243,   243,   241,
       6,   330,   344,   330,     6,     6,   330,   341,   244,     5,
     344,   243,   243,   243,   243,   243,   243,   243,   344,     6,
     347,   243,   330,   242,     6,     6,   173,   330,   330,   330,
       6,     6,     6,     6,     7,   274,   248,   248,   274,   248,
     330,     4,   189,   288,   289,   274,   240,   274,   334,   352,
     239,   241,   330,   243,   301,     6,   301,   248,     6,     6,
       7,   271,   272,   245,     7,     6,   348,   244,   248,   330,
     271,   243,   274,   356,   357,   358,   356,   239,   330,   330,
     343,   344,   243,   239,     4,     6,   240,     6,   240,   244,
     244,   240,     6,     6,   351,   239,     4,   240,   248,   239,
     344,   352,     7,   273,   282,   330,   346,   286,     6,     6,
       6,     6,   341,     6,     6,     6,     6,    91,   110,    95,
       6,     5,   243,   330,   330,   330,   330,   240,   333,   330,
     330,   330,   274,   272,   243,     6,   291,     6,   330,   344,
       4,     6,   347,   347,   330,   330,   352,   244,   240,   244,
     248,   300,   300,   330,   330,   244,   248,   240,   244,   248,
       6,     6,   343,   341,   341,   341,   341,   341,   228,   341,
       6,   244,   330,     6,     6,   344,   244,   248,     8,   244,
     240,   243,   330,   352,   351,   330,   351,   330,   352,   355,
     357,   352,   248,   240,   248,   244,   330,   318,   318,   344,
     352,   330,     6,     4,   349,     6,   348,   242,   344,   358,
       6,   274,   274,   257,   330,   248,   248,   244,   248,   258,
     330,   330,     6,     6,     6,   330,   330,   240,   278,   280,
     243,   357,   244,   248,     7,     7,   243,   243,   243,     5,
     343,   274,   274,   248,   274,   240,   248,   240,   242,   330,
       6,     6,   243,   244,   244,   243,     6,     6,   243,   330,
     244,   244,   244,   242,     6,   344,     7,   243,   330,   244,
     248,   248,   248,   248,   248,   248,     6,   244,   172,   330,
     330,   347,     6,     6,   240,   274,   274,   289,   352,   244,
     244,   244,   244,     6,     6,     7,     6,   245,     6,   244,
       6,     6,   240,   248,   330,   330,   243,   344,   244,   248,
     240,   240,   248,   283,   287,   344,   274,   330,   352,   361,
     347,   347,   330,     6,   244,   330,   333,   330,   244,   343,
     133,   134,   139,   325,   133,   134,   325,   347,   300,   244,
     248,     6,   244,   344,   301,   244,     6,   347,   341,   341,
     341,   341,   341,   330,   244,   244,   244,   240,     6,   243,
       6,   348,   175,   261,   330,   248,   248,   343,     6,   330,
     330,   244,   244,   279,     7,   239,   244,   244,   244,   243,
     248,   240,   248,   244,   243,   341,   344,     6,   243,   341,
       6,   244,   244,   330,     6,   129,   244,   312,   243,   244,
     248,   248,   248,   248,   248,     6,     6,     6,   301,     6,
     243,   330,   330,   244,   248,   283,   352,   240,   330,   330,
     330,     6,   341,     6,   341,     6,     6,   244,   330,   315,
     301,     6,   347,   347,   347,   347,   341,   347,   318,   258,
     240,   248,     6,   243,   330,   244,   248,   248,   248,   248,
     248,     6,   244,   244,   313,   244,   244,   244,   244,   248,
     244,   244,   244,   264,   330,   343,   244,   330,   330,   330,
     341,   341,   315,     6,     6,     6,     6,   347,     6,     6,
       6,   243,   240,   244,     6,   244,   274,   248,   248,   248,
     244,   244,   262,   351,   267,   243,     6,   330,   330,   330,
       6,   244,   248,   243,   343,   244,   244,   244,     6,   351,
     265,   351,   244,     6,     6,   244,   248,     6,     6,   351
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
#line 268 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 279 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 280 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 281 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 283 "Gmsh.y"
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
#line 301 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 302 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 303 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 304 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 305 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 306 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 307 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 308 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 310 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 311 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 312 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 315 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 316 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 321 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 325 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 332 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 337 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 342 "Gmsh.y"
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
#line 356 "Gmsh.y"
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
#line 369 "Gmsh.y"
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
#line 382 "Gmsh.y"
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
#line 410 "Gmsh.y"
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
#line 424 "Gmsh.y"
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
#line 437 "Gmsh.y"
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
#line 450 "Gmsh.y"
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
#line 468 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 482 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 484 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 489 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 491 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 496 "Gmsh.y"
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
#line 600 "Gmsh.y"
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
#line 610 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 619 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 626 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 636 "Gmsh.y"
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
#line 645 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 654 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 661 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 671 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 679 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 689 "Gmsh.y"
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
#line 708 "Gmsh.y"
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
#line 727 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 733 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 740 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 741 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 742 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 743 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 744 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 748 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 749 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 755 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 755 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 756 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 756 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 766 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 771 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 777 "Gmsh.y"
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
#line 839 "Gmsh.y"
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
#line 854 "Gmsh.y"
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
#line 883 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 893 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 898 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 906 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 911 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 919 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 928 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 933 "Gmsh.y"
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
#line 945 "Gmsh.y"
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
#line 962 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 968 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 977 "Gmsh.y"
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
#line 995 "Gmsh.y"
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
#line 1013 "Gmsh.y"
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
#line 1022 "Gmsh.y"
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
#line 1034 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1039 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1047 "Gmsh.y"
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
#line 1067 "Gmsh.y"
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
#line 1090 "Gmsh.y"
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
#line 1108 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1116 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 104:
#line 1123 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 105:
#line 1130 "Gmsh.y"
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
#line 1152 "Gmsh.y"
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
#line 1175 "Gmsh.y"
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
#line 1213 "Gmsh.y"
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
#line 1234 "Gmsh.y"
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
#line 1246 "Gmsh.y"
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
#line 1264 "Gmsh.y"
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
#line 1273 "Gmsh.y"
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
#line 1282 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1284 "Gmsh.y"
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
#line 1302 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1304 "Gmsh.y"
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
#line 1320 "Gmsh.y"
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
#line 1329 "Gmsh.y"
    { init_options(); ;}
    break;

  case 122:
#line 1331 "Gmsh.y"
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
#line 1345 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 125:
#line 1353 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 126:
#line 1359 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 127:
#line 1364 "Gmsh.y"
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
#line 1406 "Gmsh.y"
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
#line 1418 "Gmsh.y"
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
#line 1431 "Gmsh.y"
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
#line 1446 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 138:
#line 1455 "Gmsh.y"
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
#line 1480 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 144:
#line 1488 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 145:
#line 1497 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1505 "Gmsh.y"
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
#line 1519 "Gmsh.y"
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
#line 1537 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 149:
#line 1541 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 150:
#line 1548 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 151:
#line 1556 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 152:
#line 1560 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 153:
#line 1566 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 154:
#line 1570 "Gmsh.y"
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
#line 1581 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 156:
#line 1585 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 157:
#line 1592 "Gmsh.y"
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
#line 1615 "Gmsh.y"
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
#line 1631 "Gmsh.y"
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
#line 1647 "Gmsh.y"
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
#line 1684 "Gmsh.y"
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
#line 1724 "Gmsh.y"
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
#line 1740 "Gmsh.y"
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
#line 1757 "Gmsh.y"
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
#line 1788 "Gmsh.y"
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
#line 1804 "Gmsh.y"
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
    ;}
    break;

  case 221:
#line 2543 "Gmsh.y"
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

  case 222:
#line 2561 "Gmsh.y"
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

  case 223:
#line 2586 "Gmsh.y"
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

  case 224:
#line 2605 "Gmsh.y"
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

  case 225:
#line 2627 "Gmsh.y"
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

  case 226:
#line 2642 "Gmsh.y"
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

  case 227:
#line 2657 "Gmsh.y"
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

  case 228:
#line 2676 "Gmsh.y"
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

  case 229:
#line 2727 "Gmsh.y"
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

  case 230:
#line 2748 "Gmsh.y"
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

  case 231:
#line 2770 "Gmsh.y"
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

  case 232:
#line 2792 "Gmsh.y"
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

  case 233:
#line 2897 "Gmsh.y"
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

  case 234:
#line 2913 "Gmsh.y"
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

  case 235:
#line 2948 "Gmsh.y"
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

  case 236:
#line 2970 "Gmsh.y"
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

  case 237:
#line 2992 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 238:
#line 2998 "Gmsh.y"
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

  case 239:
#line 3013 "Gmsh.y"
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

  case 240:
#line 3041 "Gmsh.y"
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

  case 241:
#line 3053 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 242:
#line 3062 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 243:
#line 3069 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 244:
#line 3081 "Gmsh.y"
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

  case 245:
#line 3100 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 246:
#line 3104 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 247:
#line 3109 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 248:
#line 3113 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3118 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 250:
#line 3125 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 3132 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 252:
#line 3139 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 253:
#line 3151 "Gmsh.y"
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
				// CTX::instance()->geom.matchGeomAndMesh = 1;
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

  case 254:
#line 3225 "Gmsh.y"
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

  case 255:
#line 3243 "Gmsh.y"
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

  case 256:
#line 3260 "Gmsh.y"
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

  case 257:
#line 3275 "Gmsh.y"
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

  case 258:
#line 3308 "Gmsh.y"
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

  case 259:
#line 3320 "Gmsh.y"
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

  case 260:
#line 3344 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 261:
#line 3348 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 262:
#line 3353 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 263:
#line 3360 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 264:
#line 3365 "Gmsh.y"
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

  case 265:
#line 3375 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 266:
#line 3380 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 267:
#line 3386 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 268:
#line 3394 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 269:
#line 3398 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 270:
#line 3408 "Gmsh.y"
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

  case 271:
#line 3471 "Gmsh.y"
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

  case 272:
#line 3487 "Gmsh.y"
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

  case 273:
#line 3504 "Gmsh.y"
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

  case 274:
#line 3521 "Gmsh.y"
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

  case 275:
#line 3543 "Gmsh.y"
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

  case 276:
#line 3565 "Gmsh.y"
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

  case 277:
#line 3600 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 278:
#line 3608 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3616 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 280:
#line 3622 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 281:
#line 3629 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3636 "Gmsh.y"
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

  case 283:
#line 3656 "Gmsh.y"
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

  case 284:
#line 3682 "Gmsh.y"
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

  case 285:
#line 3694 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 286:
#line 3705 "Gmsh.y"
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

  case 287:
#line 3723 "Gmsh.y"
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

  case 288:
#line 3741 "Gmsh.y"
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

  case 289:
#line 3759 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3765 "Gmsh.y"
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

  case 291:
#line 3783 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3789 "Gmsh.y"
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

  case 293:
#line 3809 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3815 "Gmsh.y"
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

  case 295:
#line 3833 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3839 "Gmsh.y"
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

  case 297:
#line 3856 "Gmsh.y"
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

  case 298:
#line 3872 "Gmsh.y"
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

  case 299:
#line 3889 "Gmsh.y"
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

  case 300:
#line 3906 "Gmsh.y"
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

  case 301:
#line 3929 "Gmsh.y"
    {
    ;}
    break;

  case 302:
#line 3932 "Gmsh.y"
    {
    ;}
    break;

  case 303:
#line 3938 "Gmsh.y"
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

  case 304:
#line 3950 "Gmsh.y"
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

  case 305:
#line 3970 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 306:
#line 3974 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 307:
#line 3978 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 308:
#line 3982 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 309:
#line 3986 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 310:
#line 3990 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 311:
#line 3994 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 312:
#line 3998 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 313:
#line 4007 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 314:
#line 4019 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 315:
#line 4020 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 316:
#line 4021 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 317:
#line 4022 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 318:
#line 4023 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 319:
#line 4027 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 320:
#line 4028 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 321:
#line 4029 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 322:
#line 4030 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 323:
#line 4031 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 324:
#line 4036 "Gmsh.y"
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

  case 325:
#line 4059 "Gmsh.y"
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

  case 326:
#line 4079 "Gmsh.y"
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

  case 327:
#line 4100 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 328:
#line 4104 "Gmsh.y"
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

  case 329:
#line 4119 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 330:
#line 4123 "Gmsh.y"
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

  case 331:
#line 4139 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 332:
#line 4143 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 333:
#line 4148 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 334:
#line 4152 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 335:
#line 4158 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 336:
#line 4162 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 337:
#line 4169 "Gmsh.y"
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

  case 338:
#line 4191 "Gmsh.y"
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

  case 339:
#line 4232 "Gmsh.y"
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

  case 340:
#line 4276 "Gmsh.y"
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

  case 341:
#line 4315 "Gmsh.y"
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

  case 342:
#line 4340 "Gmsh.y"
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

  case 343:
#line 4352 "Gmsh.y"
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

  case 344:
#line 4364 "Gmsh.y"
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

  case 345:
#line 4376 "Gmsh.y"
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

  case 346:
#line 4388 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 347:
#line 4397 "Gmsh.y"
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

  case 348:
#line 4427 "Gmsh.y"
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

  case 349:
#line 4453 "Gmsh.y"
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

  case 350:
#line 4480 "Gmsh.y"
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

  case 351:
#line 4512 "Gmsh.y"
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

  case 352:
#line 4539 "Gmsh.y"
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

  case 353:
#line 4565 "Gmsh.y"
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

  case 354:
#line 4591 "Gmsh.y"
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

  case 355:
#line 4617 "Gmsh.y"
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

  case 356:
#line 4643 "Gmsh.y"
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

  case 357:
#line 4664 "Gmsh.y"
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

  case 358:
#line 4675 "Gmsh.y"
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

  case 359:
#line 4723 "Gmsh.y"
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

  case 360:
#line 4777 "Gmsh.y"
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

  case 361:
#line 4792 "Gmsh.y"
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

  case 362:
#line 4804 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 363:
#line 4815 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 364:
#line 4822 "Gmsh.y"
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

  case 365:
#line 4837 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 366:
#line 4850 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 367:
#line 4851 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 368:
#line 4852 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 369:
#line 4857 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 370:
#line 4863 "Gmsh.y"
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

  case 371:
#line 4875 "Gmsh.y"
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

  case 372:
#line 4893 "Gmsh.y"
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

  case 373:
#line 4920 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 374:
#line 4921 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 375:
#line 4922 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 376:
#line 4923 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 377:
#line 4924 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 378:
#line 4925 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 379:
#line 4926 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 380:
#line 4927 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4929 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 382:
#line 4935 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 383:
#line 4936 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 384:
#line 4937 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 385:
#line 4938 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 386:
#line 4939 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 387:
#line 4940 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 388:
#line 4941 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 4942 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 4943 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 391:
#line 4944 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 4945 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 4946 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 4947 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 395:
#line 4948 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 396:
#line 4949 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 397:
#line 4950 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 398:
#line 4951 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 399:
#line 4952 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 400:
#line 4953 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4954 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 4955 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4956 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 404:
#line 4957 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4958 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 406:
#line 4959 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 4960 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 408:
#line 4961 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 4962 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 4963 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 4964 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 4965 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 413:
#line 4966 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 414:
#line 4967 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 415:
#line 4968 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 416:
#line 4969 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 417:
#line 4970 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 418:
#line 4971 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 419:
#line 4972 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 420:
#line 4981 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 421:
#line 4982 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 422:
#line 4983 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 423:
#line 4984 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 424:
#line 4985 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 425:
#line 4986 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 426:
#line 4987 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 427:
#line 4988 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 428:
#line 4989 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 429:
#line 4990 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 430:
#line 4991 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 431:
#line 4996 "Gmsh.y"
    { init_options(); ;}
    break;

  case 432:
#line 4998 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 433:
#line 5004 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 434:
#line 5006 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 435:
#line 5011 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 436:
#line 5016 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 437:
#line 5021 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 438:
#line 5026 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 439:
#line 5030 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 440:
#line 5034 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 441:
#line 5038 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 442:
#line 5042 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 443:
#line 5046 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 444:
#line 5050 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 445:
#line 5054 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 446:
#line 5060 "Gmsh.y"
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

  case 447:
#line 5076 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 448:
#line 5081 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 449:
#line 5087 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 450:
#line 5093 "Gmsh.y"
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

  case 451:
#line 5112 "Gmsh.y"
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

  case 452:
#line 5133 "Gmsh.y"
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
#line 5166 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 454:
#line 5170 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 455:
#line 5175 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 456:
#line 5179 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 457:
#line 5183 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 458:
#line 5187 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 459:
#line 5192 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 460:
#line 5197 "Gmsh.y"
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

  case 461:
#line 5207 "Gmsh.y"
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

  case 462:
#line 5217 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 5222 "Gmsh.y"
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

  case 464:
#line 5233 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 465:
#line 5242 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 466:
#line 5247 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 467:
#line 5252 "Gmsh.y"
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

  case 468:
#line 5279 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 469:
#line 5281 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 470:
#line 5286 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 471:
#line 5288 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 472:
#line 5293 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 473:
#line 5300 "Gmsh.y"
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

  case 474:
#line 5316 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 475:
#line 5318 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 476:
#line 5323 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 477:
#line 5332 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 478:
#line 5334 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 479:
#line 5339 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 480:
#line 5341 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 481:
#line 5346 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 482:
#line 5350 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 483:
#line 5354 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 484:
#line 5358 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 485:
#line 5362 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 486:
#line 5369 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 487:
#line 5373 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 488:
#line 5377 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 489:
#line 5381 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 490:
#line 5388 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 491:
#line 5393 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 492:
#line 5400 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 493:
#line 5405 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 494:
#line 5409 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 495:
#line 5414 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 496:
#line 5418 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 497:
#line 5426 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 498:
#line 5437 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 5441 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 500:
#line 5445 "Gmsh.y"
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

  case 501:
#line 5459 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 502:
#line 5467 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 503:
#line 5475 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 504:
#line 5482 "Gmsh.y"
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

  case 505:
#line 5492 "Gmsh.y"
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

  case 506:
#line 5515 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 507:
#line 5520 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 508:
#line 5526 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 509:
#line 5531 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 510:
#line 5537 "Gmsh.y"
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

  case 511:
#line 5549 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 512:
#line 5554 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 513:
#line 5559 "Gmsh.y"
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

  case 514:
#line 5569 "Gmsh.y"
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

  case 515:
#line 5579 "Gmsh.y"
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
#line 5589 "Gmsh.y"
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

  case 517:
#line 5601 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 518:
#line 5605 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 519:
#line 5610 "Gmsh.y"
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

  case 520:
#line 5622 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 521:
#line 5626 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 522:
#line 5630 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 523:
#line 5634 "Gmsh.y"
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

  case 524:
#line 5652 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 525:
#line 5660 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 526:
#line 5668 "Gmsh.y"
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

  case 527:
#line 5697 "Gmsh.y"
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

  case 528:
#line 5707 "Gmsh.y"
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

  case 529:
#line 5723 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 530:
#line 5734 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 531:
#line 5739 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 532:
#line 5743 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 533:
#line 5747 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 534:
#line 5759 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 535:
#line 5763 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 536:
#line 5775 "Gmsh.y"
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

  case 537:
#line 5792 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 538:
#line 5802 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 539:
#line 5806 "Gmsh.y"
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

  case 540:
#line 5821 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 541:
#line 5826 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 542:
#line 5833 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 543:
#line 5837 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 544:
#line 5842 "Gmsh.y"
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

  case 545:
#line 5856 "Gmsh.y"
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

  case 546:
#line 5872 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 547:
#line 5876 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 548:
#line 5880 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 549:
#line 5884 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 550:
#line 5888 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 551:
#line 5896 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 552:
#line 5902 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 553:
#line 5908 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 554:
#line 5914 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 555:
#line 5923 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 556:
#line 5927 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 557:
#line 5931 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 558:
#line 5939 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 559:
#line 5945 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 560:
#line 5951 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 561:
#line 5955 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 562:
#line 5963 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 563:
#line 5971 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 564:
#line 5978 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 565:
#line 5987 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 566:
#line 5991 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 567:
#line 5995 "Gmsh.y"
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

  case 568:
#line 6010 "Gmsh.y"
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

  case 569:
#line 6024 "Gmsh.y"
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

  case 570:
#line 6038 "Gmsh.y"
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

  case 571:
#line 6050 "Gmsh.y"
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

  case 572:
#line 6066 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 573:
#line 6075 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 574:
#line 6084 "Gmsh.y"
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

  case 575:
#line 6094 "Gmsh.y"
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

  case 576:
#line 6105 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 577:
#line 6113 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 578:
#line 6121 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 579:
#line 6125 "Gmsh.y"
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

  case 580:
#line 6144 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 581:
#line 6151 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 582:
#line 6157 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 583:
#line 6164 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 584:
#line 6171 "Gmsh.y"
    { init_options(); ;}
    break;

  case 585:
#line 6173 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 586:
#line 6181 "Gmsh.y"
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

  case 587:
#line 6205 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 588:
#line 6207 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 589:
#line 6213 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 590:
#line 6218 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 591:
#line 6220 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 592:
#line 6225 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 593:
#line 6230 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 594:
#line 6235 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 595:
#line 6237 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 596:
#line 6241 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 597:
#line 6253 "Gmsh.y"
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

  case 598:
#line 6267 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 599:
#line 6271 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 600:
#line 6278 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 601:
#line 6286 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 602:
#line 6294 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 603:
#line 6305 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 604:
#line 6307 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 605:
#line 6310 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13885 "Gmsh.tab.cpp"
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


#line 6313 "Gmsh.y"


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

