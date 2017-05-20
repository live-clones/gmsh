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
     tCreateTopologyNoHoles = 334,
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
     tSetString = 345,
     tPoint = 346,
     tCircle = 347,
     tEllipse = 348,
     tLine = 349,
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
     tSetFactory = 373,
     tThruSections = 374,
     tWedge = 375,
     tFillet = 376,
     tChamfer = 377,
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
     tReverse = 408,
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
#define tCreateTopologyNoHoles 334
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
#define tSetString 345
#define tPoint 346
#define tCircle 347
#define tEllipse 348
#define tLine 349
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
#define tSetFactory 373
#define tThruSections 374
#define tWedge 375
#define tFillet 376
#define tChamfer 377
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
#define tReverse 408
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

// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
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
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
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
#line 164 "Gmsh.y"
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
#line 730 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 743 "Gmsh.tab.cpp"

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
#define YYLAST   14799

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  588
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2070

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
     473,   483,   489,   497,   505,   515,   525,   537,   545,   555,
     565,   566,   568,   569,   573,   579,   580,   590,   591,   603,
     609,   610,   620,   621,   625,   629,   635,   641,   642,   645,
     646,   648,   650,   654,   657,   659,   664,   667,   670,   671,
     674,   676,   680,   683,   686,   689,   692,   695,   697,   699,
     703,   704,   710,   711,   714,   722,   730,   738,   747,   756,
     764,   772,   784,   792,   801,   810,   819,   829,   833,   838,
     849,   857,   865,   873,   881,   889,   897,   905,   913,   921,
     929,   938,   946,   954,   963,   972,   985,   986,   996,   998,
    1000,  1002,  1004,  1009,  1011,  1013,  1015,  1020,  1022,  1024,
    1029,  1031,  1033,  1035,  1040,  1046,  1058,  1064,  1074,  1084,
    1089,  1099,  1109,  1111,  1113,  1114,  1117,  1124,  1133,  1144,
    1159,  1176,  1189,  1204,  1219,  1234,  1249,  1258,  1267,  1274,
    1279,  1285,  1292,  1299,  1303,  1308,  1312,  1318,  1325,  1331,
    1335,  1339,  1344,  1350,  1355,  1361,  1365,  1371,  1379,  1387,
    1391,  1399,  1403,  1406,  1409,  1412,  1415,  1418,  1434,  1437,
    1440,  1443,  1446,  1449,  1466,  1478,  1485,  1494,  1503,  1514,
    1516,  1519,  1522,  1524,  1528,  1532,  1537,  1542,  1544,  1546,
    1552,  1564,  1578,  1579,  1587,  1588,  1602,  1603,  1619,  1620,
    1627,  1637,  1640,  1644,  1655,  1657,  1660,  1666,  1674,  1677,
    1680,  1684,  1687,  1691,  1694,  1698,  1708,  1715,  1717,  1719,
    1721,  1723,  1725,  1726,  1729,  1733,  1737,  1742,  1752,  1757,
    1772,  1773,  1777,  1778,  1780,  1781,  1784,  1785,  1788,  1789,
    1792,  1799,  1807,  1814,  1820,  1824,  1833,  1839,  1844,  1851,
    1863,  1875,  1894,  1913,  1926,  1939,  1952,  1963,  1968,  1973,
    1978,  1983,  1986,  1990,  1997,  1999,  2001,  2003,  2006,  2012,
    2020,  2031,  2033,  2037,  2040,  2043,  2046,  2050,  2054,  2058,
    2062,  2066,  2070,  2074,  2078,  2082,  2086,  2090,  2094,  2098,
    2102,  2106,  2110,  2114,  2118,  2124,  2129,  2134,  2139,  2144,
    2149,  2154,  2159,  2164,  2169,  2174,  2181,  2186,  2191,  2196,
    2201,  2206,  2211,  2216,  2221,  2228,  2235,  2242,  2247,  2249,
    2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,
    2270,  2277,  2279,  2284,  2291,  2293,  2298,  2303,  2308,  2315,
    2321,  2329,  2338,  2349,  2354,  2359,  2366,  2371,  2375,  2378,
    2384,  2390,  2394,  2400,  2407,  2416,  2423,  2432,  2439,  2444,
    2452,  2459,  2466,  2473,  2478,  2485,  2490,  2491,  2494,  2495,
    2498,  2499,  2507,  2509,  2513,  2515,  2517,  2520,  2521,  2525,
    2527,  2530,  2533,  2537,  2541,  2553,  2563,  2571,  2579,  2581,
    2585,  2587,  2589,  2592,  2596,  2601,  2607,  2609,  2611,  2614,
    2618,  2622,  2628,  2633,  2636,  2640,  2657,  2659,  2661,  2663,
    2667,  2673,  2681,  2686,  2691,  2696,  2703,  2710,  2719,  2728,
    2733,  2748,  2753,  2758,  2760,  2762,  2766,  2770,  2780,  2788,
    2790,  2796,  2800,  2807,  2809,  2813,  2815,  2817,  2822,  2827,
    2831,  2837,  2844,  2853,  2860,  2866,  2872,  2878,  2884,  2886,
    2891,  2893,  2895,  2897,  2899,  2904,  2911,  2916,  2923,  2929,
    2937,  2942,  2947,  2952,  2961,  2966,  2971,  2976,  2981,  2990,
    2999,  3006,  3011,  3018,  3023,  3025,  3030,  3035,  3036,  3043,
    3048,  3051,  3056,  3061,  3063,  3065,  3069,  3071,  3073,  3077,
    3081,  3085,  3091,  3099,  3105,  3111,  3120,  3122,  3124
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     250,     0,    -1,   251,    -1,     1,     6,    -1,    -1,   251,
     252,    -1,   254,    -1,   255,    -1,   275,    -1,   118,   239,
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
      -1,   240,    -1,   242,    -1,    81,   241,   277,   242,     6,
      -1,    82,   241,   281,   242,     6,    -1,   335,     6,    -1,
      89,   273,   352,   248,   330,   274,     6,    -1,    90,   273,
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
     349,     6,    -1,   361,   185,     7,   330,     6,    -1,   185,
     241,   330,   242,     7,     4,     6,    -1,   185,   241,   330,
     242,     7,   101,     6,    -1,   185,   241,   330,   242,   245,
       4,     7,   330,     6,    -1,   185,   241,   330,   242,   245,
       4,     7,   352,     6,    -1,   185,   241,   330,   242,   245,
       4,     7,   243,   347,   244,     6,    -1,   185,   241,   330,
     242,   245,     4,     6,    -1,   130,   239,     4,   240,   245,
       4,     7,   330,     6,    -1,   130,   239,     4,   240,   245,
       4,     7,   352,     6,    -1,    -1,   248,    -1,    -1,   277,
     276,   361,    -1,   277,   276,   361,     7,   330,    -1,    -1,
     277,   276,   361,     7,   243,   344,   278,   283,   244,    -1,
      -1,   277,   276,   361,   273,   274,     7,   243,   344,   279,
     283,   244,    -1,   277,   276,   361,     7,   352,    -1,    -1,
     277,   276,   361,     7,   243,   352,   280,   287,   244,    -1,
      -1,   281,   276,   351,    -1,   330,     7,   352,    -1,   282,
     248,   330,     7,   352,    -1,   346,     7,   361,   239,   240,
      -1,    -1,   248,   285,    -1,    -1,   285,    -1,   286,    -1,
     285,   248,   286,    -1,     4,   344,    -1,     4,    -1,     4,
     243,   282,   244,    -1,     4,   352,    -1,     4,   355,    -1,
      -1,   248,   288,    -1,   289,    -1,   288,   248,   289,    -1,
       4,   330,    -1,     4,   352,    -1,   189,   352,    -1,     4,
     357,    -1,     4,   355,    -1,   330,    -1,   352,    -1,   352,
     248,   330,    -1,    -1,   177,    95,   243,   330,   244,    -1,
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
     344,     6,    -1,   120,   239,   330,   240,     7,   344,     6,
      -1,   145,   239,   330,   240,     7,   344,     6,    -1,    97,
       4,   239,   330,   240,     7,   344,     6,    -1,    99,   239,
     330,   240,     7,   344,     6,    -1,   119,   239,   330,   240,
       7,   344,     6,    -1,   124,   119,   239,   330,   240,     7,
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
     347,   244,     6,    -1,   138,   123,   239,   330,   240,     7,
     344,     6,    -1,   138,    91,   239,   330,   240,     7,   243,
     343,   244,     6,    -1,   138,   123,   239,   330,   240,     7,
     243,   341,   248,   341,   248,   347,   244,     6,    -1,   138,
     123,   239,   330,   240,     7,   243,   341,   248,   341,   248,
     341,   248,   347,   244,     6,    -1,   138,    95,   239,   330,
     240,     7,   243,   341,   248,   347,   244,     6,    -1,   138,
     101,   239,   330,   240,     7,   243,   341,   248,   341,   248,
     347,   244,     6,    -1,   138,   102,   239,   330,   240,     7,
     243,   341,   248,   341,   248,   347,   244,     6,    -1,   138,
     104,   239,   330,   240,     7,   243,   341,   248,   341,   248,
     347,   244,     6,    -1,   138,   105,   239,   330,   240,     7,
     243,   341,   248,   341,   248,   347,   244,     6,    -1,   138,
       4,   239,   330,   240,     7,   344,     6,    -1,   138,     4,
     239,   330,   240,     7,     5,     6,    -1,   138,     4,   243,
     330,   244,     6,    -1,   149,   243,   301,   244,    -1,   132,
     149,   243,   301,   244,    -1,   149,   185,   241,   330,   242,
       6,    -1,   149,     4,   241,   330,   242,     6,    -1,   149,
     361,     6,    -1,   149,     4,     4,     6,    -1,   149,    84,
       6,    -1,   174,   348,   243,   301,   244,    -1,   132,   174,
     348,   243,   301,   244,    -1,   209,   330,   243,   301,   244,
      -1,   190,     5,     6,    -1,   191,     5,     6,    -1,   190,
     243,   301,   244,    -1,   132,   190,   243,   301,   244,    -1,
     191,   243,   301,   244,    -1,   132,   191,   243,   301,   244,
      -1,   361,   352,     6,    -1,    73,   239,   358,   240,     6,
      -1,   361,   361,   241,   330,   242,   351,     6,    -1,   361,
     361,   361,   241,   330,   242,     6,    -1,   361,   330,     6,
      -1,   130,   239,     4,   240,   245,     4,     6,    -1,   168,
       4,     6,    -1,   183,     6,    -1,   184,     6,    -1,    70,
       6,    -1,    71,     6,    -1,    64,     6,    -1,    64,   243,
     330,   248,   330,   248,   330,   248,   330,   248,   330,   248,
     330,   244,     6,    -1,    65,     6,    -1,    66,     6,    -1,
      78,     6,    -1,    79,     6,    -1,   115,     6,    -1,   116,
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
     244,   129,   109,   243,   330,   244,    -1,   119,   344,    -1,
     124,   119,   344,    -1,   121,   243,   347,   244,   243,   347,
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
     344,    -1,   111,   112,   344,     7,   330,     6,    -1,   125,
      94,   345,     7,   330,   321,     6,    -1,   125,    97,   345,
     323,   322,     6,    -1,   125,    99,   345,   323,     6,    -1,
     163,   345,     6,    -1,   152,    97,   243,   347,   244,     7,
     330,     6,    -1,   146,    97,   345,   324,     6,    -1,   146,
      99,   345,     6,    -1,   147,    97,   345,     7,   330,     6,
      -1,   128,    94,   243,   347,   244,     7,   243,   347,   244,
     325,     6,    -1,   128,    97,   243,   347,   244,     7,   243,
     347,   244,   325,     6,    -1,   128,    94,   243,   347,   244,
       7,   243,   347,   244,   133,   243,   341,   248,   341,   248,
     330,   244,     6,    -1,   128,    97,   243,   347,   244,     7,
     243,   347,   244,   133,   243,   341,   248,   341,   248,   330,
     244,     6,    -1,   128,    94,   243,   347,   244,     7,   243,
     347,   244,   134,   341,     6,    -1,   128,    97,   243,   347,
     244,     7,   243,   347,   244,   134,   341,     6,    -1,   128,
      97,   330,   243,   347,   244,     7,   330,   243,   347,   244,
       6,    -1,   295,   243,   347,   244,   177,   295,   243,   330,
     244,     6,    -1,   153,   297,   345,     6,    -1,   117,   298,
     345,     6,    -1,   131,    94,   344,     6,    -1,   127,   296,
     344,     6,    -1,   150,     6,    -1,   150,     4,     6,    -1,
     150,    91,   243,   347,   244,     6,    -1,   198,    -1,   199,
      -1,   200,    -1,   328,     6,    -1,   328,   243,   344,   244,
       6,    -1,   328,   243,   344,   248,   344,   244,     6,    -1,
     328,   239,   344,   240,   243,   344,   248,   344,   244,     6,
      -1,   331,    -1,   239,   330,   240,    -1,   228,   330,    -1,
     227,   330,    -1,   234,   330,    -1,   330,   228,   330,    -1,
     330,   227,   330,    -1,   330,   229,   330,    -1,   330,   230,
     330,    -1,   330,   232,   330,    -1,   330,   233,   330,    -1,
     330,   231,   330,    -1,   330,   238,   330,    -1,   330,   221,
     330,    -1,   330,   222,   330,    -1,   330,   226,   330,    -1,
     330,   225,   330,    -1,   330,   220,   330,    -1,   330,   219,
     330,    -1,   330,   218,   330,    -1,   330,   217,   330,    -1,
     330,   223,   330,    -1,   330,   224,   330,    -1,   330,   216,
     330,     8,   330,    -1,    16,   273,   330,   274,    -1,    17,
     273,   330,   274,    -1,    18,   273,   330,   274,    -1,    19,
     273,   330,   274,    -1,    20,   273,   330,   274,    -1,    21,
     273,   330,   274,    -1,    22,   273,   330,   274,    -1,    23,
     273,   330,   274,    -1,    24,   273,   330,   274,    -1,    26,
     273,   330,   274,    -1,    27,   273,   330,   248,   330,   274,
      -1,    28,   273,   330,   274,    -1,    29,   273,   330,   274,
      -1,    30,   273,   330,   274,    -1,    31,   273,   330,   274,
      -1,    32,   273,   330,   274,    -1,    33,   273,   330,   274,
      -1,    34,   273,   330,   274,    -1,    35,   273,   330,   274,
      -1,    36,   273,   330,   248,   330,   274,    -1,    37,   273,
     330,   248,   330,   274,    -1,    38,   273,   330,   248,   330,
     274,    -1,    25,   273,   330,   274,    -1,     3,    -1,    10,
      -1,    15,    -1,    11,    -1,    12,    -1,   205,    -1,   206,
      -1,   207,    -1,    75,    -1,    76,    -1,    77,    -1,    -1,
      83,   273,   330,   332,   283,   274,    -1,   335,    -1,   196,
     273,   351,   274,    -1,   196,   273,   351,   248,   330,   274,
      -1,   337,    -1,   361,   241,   330,   242,    -1,   361,   239,
     330,   240,    -1,   201,   239,   337,   240,    -1,   201,   239,
     337,   245,   338,   240,    -1,   203,   239,   337,   333,   240,
      -1,   203,   239,   337,   245,   338,   333,   240,    -1,   203,
     239,   337,   273,   330,   274,   333,   240,    -1,   203,   239,
     337,   245,   338,   273,   330,   274,   333,   240,    -1,   202,
     239,   352,   240,    -1,   246,   361,   273,   274,    -1,   246,
     337,   245,   338,   273,   274,    -1,    86,   273,   361,   274,
      -1,    86,   273,   274,    -1,   361,   272,    -1,   361,   241,
     330,   242,   272,    -1,   361,   239,   330,   240,   272,    -1,
     361,   245,   338,    -1,   361,     9,   361,   245,   338,    -1,
     361,   245,   338,   239,   330,   240,    -1,   361,     9,   361,
     245,   338,   239,   330,   240,    -1,   361,   245,   338,   241,
     330,   242,    -1,   361,     9,   361,   245,   338,   241,   330,
     242,    -1,   361,   241,   330,   242,   245,     4,    -1,   361,
     245,     4,   272,    -1,   361,   241,   330,   242,   245,     4,
     272,    -1,   192,   239,   351,   248,   330,   240,    -1,    56,
     239,   344,   248,   344,   240,    -1,    57,   273,   351,   248,
     351,   274,    -1,    55,   273,   351,   274,    -1,    58,   273,
     351,   248,   351,   274,    -1,    63,   239,   358,   240,    -1,
      -1,   248,   330,    -1,    -1,   248,   351,    -1,    -1,    84,
     337,   340,   336,   241,   284,   242,    -1,   361,    -1,   361,
       9,   361,    -1,     4,    -1,    87,    -1,    87,   330,    -1,
      -1,   239,   339,   240,    -1,   342,    -1,   228,   341,    -1,
     227,   341,    -1,   341,   228,   341,    -1,   341,   227,   341,
      -1,   243,   330,   248,   330,   248,   330,   248,   330,   248,
     330,   244,    -1,   243,   330,   248,   330,   248,   330,   248,
     330,   244,    -1,   243,   330,   248,   330,   248,   330,   244,
      -1,   239,   330,   248,   330,   248,   330,   240,    -1,   344,
      -1,   343,   248,   344,    -1,   330,    -1,   346,    -1,   243,
     244,    -1,   243,   347,   244,    -1,   228,   243,   347,   244,
      -1,   330,   229,   243,   347,   244,    -1,   344,    -1,     5,
      -1,   228,   346,    -1,   330,   229,   346,    -1,   330,     8,
     330,    -1,   330,     8,   330,     8,   330,    -1,    91,   243,
     330,   244,    -1,   295,     5,    -1,   126,   295,   345,    -1,
     295,   177,    64,   243,   330,   248,   330,   248,   330,   248,
     330,   248,   330,   248,   330,   244,    -1,   299,    -1,   310,
      -1,   319,    -1,   361,   273,   274,    -1,   361,   245,   338,
     273,   274,    -1,   361,     9,   361,   245,   338,   273,   274,
      -1,    39,   241,   361,   242,    -1,    39,   241,   346,   242,
      -1,    39,   239,   346,   240,    -1,    39,   273,   243,   347,
     244,   274,    -1,   361,   273,   243,   347,   244,   274,    -1,
      40,   273,   330,   248,   330,   248,   330,   274,    -1,    41,
     273,   330,   248,   330,   248,   330,   274,    -1,    42,   273,
     351,   274,    -1,    43,   273,   330,   248,   330,   248,   330,
     248,   330,   248,   330,   248,   330,   274,    -1,   197,   273,
     346,   274,    -1,    32,   273,   346,   274,    -1,   330,    -1,
     346,    -1,   347,   248,   330,    -1,   347,   248,   346,    -1,
     243,   330,   248,   330,   248,   330,   248,   330,   244,    -1,
     243,   330,   248,   330,   248,   330,   244,    -1,   361,    -1,
       4,   245,   174,   245,     4,    -1,   243,   350,   244,    -1,
     361,   241,   330,   242,   245,   175,    -1,   348,    -1,   350,
     248,   348,    -1,   352,    -1,   361,    -1,   361,   241,   330,
     242,    -1,   361,   239,   330,   240,    -1,   361,   245,   338,
      -1,   361,     9,   361,   245,   338,    -1,   361,   245,   338,
     239,   330,   240,    -1,   361,     9,   361,   245,   338,   239,
     330,   240,    -1,   361,   241,   330,   242,   245,     4,    -1,
     126,    91,   243,   330,   244,    -1,   126,    94,   243,   330,
     244,    -1,   126,    97,   243,   330,   244,    -1,   126,    99,
     243,   330,   244,    -1,     5,    -1,   210,   241,   361,   242,
      -1,    67,    -1,   208,    -1,    72,    -1,    74,    -1,   194,
     239,   351,   240,    -1,   193,   239,   351,   248,   351,   240,
      -1,   195,   273,   351,   274,    -1,   195,   273,   351,   248,
     351,   274,    -1,   204,   239,   337,   334,   240,    -1,   204,
     239,   337,   245,   338,   334,   240,    -1,    48,   273,   358,
     274,    -1,    49,   239,   351,   240,    -1,    50,   239,   351,
     240,    -1,    51,   239,   351,   248,   351,   248,   351,   240,
      -1,    46,   273,   358,   274,    -1,    60,   273,   351,   274,
      -1,    61,   273,   351,   274,    -1,    62,   273,   351,   274,
      -1,    59,   273,   330,   248,   351,   248,   351,   274,    -1,
      54,   273,   351,   248,   330,   248,   330,   274,    -1,    54,
     273,   351,   248,   330,   274,    -1,    47,   273,   351,   274,
      -1,    47,   273,   351,   248,   347,   274,    -1,    68,   273,
     351,   274,    -1,    69,    -1,    53,   273,   351,   274,    -1,
      52,   273,   351,   274,    -1,    -1,    88,   273,   352,   353,
     287,   274,    -1,    85,   273,   354,   274,    -1,   246,   330,
      -1,   361,     9,   246,   330,    -1,    46,   273,   357,   274,
      -1,   358,    -1,   357,    -1,   243,   358,   244,    -1,   351,
      -1,   359,    -1,   358,   248,   351,    -1,   358,   248,   359,
      -1,   361,   239,   240,    -1,   361,   245,   338,   239,   240,
      -1,   361,     9,   361,   245,   338,   239,   240,    -1,     4,
     247,   243,   330,   244,    -1,   360,   247,   243,   330,   244,
      -1,   211,   241,   351,   242,   247,   243,   330,   244,    -1,
       4,    -1,   360,    -1,   211,   241,   351,   242,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   266,   266,   267,   272,   274,   278,   279,   280,   281,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   319,   323,   330,   335,
     340,   354,   367,   380,   408,   422,   435,   448,   467,   472,
     473,   474,   475,   476,   480,   482,   487,   489,   495,   599,
     494,   617,   624,   635,   634,   652,   659,   670,   669,   686,
     703,   726,   725,   739,   740,   741,   742,   743,   747,   748,
     754,   754,   755,   755,   761,   762,   763,   764,   769,   775,
     837,   852,   881,   891,   896,   904,   909,   917,   926,   931,
     943,   960,   966,   975,   993,  1011,  1020,  1032,  1037,  1045,
    1065,  1088,  1099,  1107,  1114,  1136,  1159,  1197,  1218,  1230,
    1244,  1244,  1246,  1248,  1257,  1267,  1266,  1287,  1286,  1304,
    1314,  1313,  1327,  1329,  1337,  1343,  1348,  1374,  1376,  1379,
    1381,  1385,  1386,  1390,  1402,  1415,  1430,  1439,  1452,  1454,
    1458,  1459,  1464,  1472,  1481,  1489,  1503,  1521,  1525,  1532,
    1541,  1544,  1551,  1554,  1561,  1585,  1601,  1617,  1654,  1694,
    1710,  1726,  1748,  1764,  1783,  1799,  1820,  1831,  1837,  1843,
    1850,  1881,  1896,  1918,  1941,  1964,  1987,  2011,  2035,  2059,
    2085,  2102,  2118,  2136,  2154,  2184,  2214,  2213,  2243,  2245,
    2247,  2249,  2251,  2259,  2261,  2263,  2265,  2273,  2275,  2277,
    2285,  2287,  2289,  2291,  2301,  2317,  2333,  2349,  2365,  2381,
    2418,  2440,  2464,  2465,  2470,  2473,  2477,  2498,  2517,  2538,
    2553,  2569,  2587,  2638,  2659,  2681,  2704,  2809,  2825,  2860,
    2882,  2904,  2910,  2925,  2953,  2965,  2974,  2981,  2993,  3012,
    3018,  3024,  3031,  3038,  3045,  3057,  3130,  3148,  3165,  3180,
    3213,  3225,  3249,  3253,  3258,  3265,  3270,  3280,  3285,  3291,
    3299,  3303,  3307,  3316,  3380,  3396,  3413,  3430,  3452,  3474,
    3509,  3517,  3525,  3531,  3538,  3545,  3565,  3591,  3603,  3614,
    3632,  3650,  3669,  3668,  3693,  3692,  3719,  3718,  3743,  3742,
    3765,  3781,  3798,  3815,  3838,  3841,  3847,  3859,  3879,  3883,
    3887,  3891,  3895,  3899,  3903,  3907,  3916,  3929,  3930,  3931,
    3932,  3933,  3937,  3938,  3939,  3940,  3941,  3944,  3968,  3987,
    4010,  4013,  4029,  4032,  4049,  4052,  4058,  4061,  4068,  4071,
    4078,  4095,  4136,  4180,  4219,  4244,  4253,  4283,  4309,  4335,
    4367,  4394,  4420,  4446,  4472,  4498,  4520,  4531,  4579,  4628,
    4640,  4651,  4655,  4665,  4676,  4677,  4678,  4682,  4688,  4700,
    4718,  4746,  4747,  4748,  4749,  4750,  4751,  4752,  4753,  4754,
    4761,  4762,  4763,  4764,  4765,  4766,  4767,  4768,  4769,  4770,
    4771,  4772,  4773,  4774,  4775,  4776,  4777,  4778,  4779,  4780,
    4781,  4782,  4783,  4784,  4785,  4786,  4787,  4788,  4789,  4790,
    4791,  4792,  4793,  4794,  4795,  4796,  4797,  4798,  4807,  4808,
    4809,  4810,  4811,  4812,  4813,  4814,  4815,  4816,  4817,  4822,
    4821,  4829,  4831,  4836,  4841,  4845,  4850,  4855,  4859,  4863,
    4867,  4871,  4875,  4879,  4885,  4901,  4906,  4912,  4918,  4937,
    4958,  4991,  4995,  5000,  5004,  5008,  5012,  5017,  5022,  5032,
    5042,  5047,  5058,  5067,  5072,  5077,  5105,  5106,  5112,  5113,
    5119,  5118,  5141,  5143,  5148,  5157,  5159,  5165,  5166,  5171,
    5175,  5179,  5183,  5187,  5194,  5198,  5202,  5206,  5213,  5218,
    5225,  5230,  5234,  5239,  5243,  5251,  5262,  5266,  5278,  5286,
    5294,  5301,  5311,  5334,  5340,  5351,  5357,  5367,  5377,  5387,
    5399,  5403,  5408,  5420,  5424,  5428,  5432,  5450,  5458,  5466,
    5495,  5505,  5521,  5532,  5537,  5541,  5545,  5557,  5561,  5573,
    5590,  5600,  5604,  5619,  5624,  5631,  5635,  5640,  5654,  5670,
    5674,  5678,  5682,  5686,  5694,  5700,  5706,  5712,  5721,  5725,
    5729,  5737,  5743,  5749,  5753,  5761,  5769,  5776,  5785,  5789,
    5793,  5808,  5822,  5836,  5848,  5864,  5873,  5882,  5892,  5903,
    5911,  5919,  5923,  5942,  5949,  5955,  5962,  5970,  5969,  5979,
    6003,  6005,  6011,  6016,  6018,  6023,  6028,  6033,  6035,  6039,
    6051,  6065,  6069,  6076,  6084,  6092,  6103,  6105,  6108
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
  "tTotalMemory", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineStruct", "tNameStruct", "tDimNameSpace",
  "tAppend", "tDefineString", "tSetNumber", "tSetString", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tBox", "tCylinder", "tCone", "tTorus",
  "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle", "tDisk",
  "tWire", "tGeoEntity", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tUsing",
  "tPlugin", "tDegenerated", "tRecursive", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast", "tHole", "tAlias",
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
  "PhysicalId_per_dim_entity", "InSphereCenter", "CircleOptions", "Shape",
  "@9", "GeoEntity", "GeoEntity123", "GeoEntity12", "GeoEntity02",
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
     276,   276,   277,   277,   277,   278,   277,   279,   277,   277,
     280,   277,   281,   281,   282,   282,   282,   283,   283,   284,
     284,   285,   285,   286,   286,   286,   286,   286,   287,   287,
     288,   288,   289,   289,   289,   289,   289,   290,   290,   290,
     291,   291,   292,   292,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   294,   293,   295,   295,
     295,   295,   295,   296,   296,   296,   296,   297,   297,   297,
     298,   298,   298,   298,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   300,   301,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   304,   304,   305,   306,
     306,   306,   306,   306,   306,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   308,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   310,
     310,   310,   311,   310,   312,   310,   313,   310,   314,   310,
     310,   310,   310,   310,   315,   315,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   317,
     317,   317,   318,   318,   318,   318,   318,   319,   319,   320,
     321,   321,   322,   322,   323,   323,   324,   324,   325,   325,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   327,   327,   327,   328,   328,   328,   329,   329,   329,
     329,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   333,   333,   334,   334,
     336,   335,   337,   337,   338,   339,   339,   340,   340,   341,
     341,   341,   341,   341,   342,   342,   342,   342,   343,   343,
     344,   344,   344,   344,   344,   344,   345,   345,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   347,   347,   347,   347,   348,   348,   348,
     348,   349,   349,   350,   350,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   353,   352,   352,
     354,   354,   355,   356,   356,   357,   358,   358,   358,   358,
     359,   359,   359,   360,   360,   360,   361,   361,   361
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
       9,     5,     7,     7,     9,     9,    11,     7,     9,     9,
       0,     1,     0,     3,     5,     0,     9,     0,    11,     5,
       0,     9,     0,     3,     3,     5,     5,     0,     2,     0,
       1,     1,     3,     2,     1,     4,     2,     2,     0,     2,
       1,     3,     2,     2,     2,     2,     2,     1,     1,     3,
       0,     5,     0,     2,     7,     7,     7,     8,     8,     7,
       7,    11,     7,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       8,     7,     7,     8,     8,    12,     0,     9,     1,     1,
       1,     1,     4,     1,     1,     1,     4,     1,     1,     4,
       1,     1,     1,     4,     5,    11,     5,     9,     9,     4,
       9,     9,     1,     1,     0,     2,     6,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       5,     6,     6,     3,     4,     3,     5,     6,     5,     3,
       3,     4,     5,     4,     5,     3,     5,     7,     7,     3,
       7,     3,     2,     2,     2,     2,     2,    15,     2,     2,
       2,     2,     2,    16,    11,     6,     8,     8,    10,     1,
       2,     2,     1,     3,     3,     4,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       9,     2,     3,    10,     1,     2,     5,     7,     2,     2,
       3,     2,     3,     2,     3,     9,     6,     1,     1,     1,
       1,     1,     0,     2,     3,     3,     4,     9,     4,    14,
       0,     3,     0,     1,     0,     2,     0,     2,     0,     2,
       6,     7,     6,     5,     3,     8,     5,     4,     6,    11,
      11,    18,    18,    12,    12,    12,    10,     4,     4,     4,
       4,     2,     3,     6,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     1,     4,     6,     1,     4,     4,     4,     6,     5,
       7,     8,    10,     4,     4,     6,     4,     3,     2,     5,
       5,     3,     5,     6,     8,     6,     8,     6,     4,     7,
       6,     6,     6,     4,     6,     4,     0,     2,     0,     2,
       0,     7,     1,     3,     1,     1,     2,     0,     3,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     3,    16,     1,     1,     1,     3,
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
       0,     0,     0,     2,     3,     1,   586,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,     0,   189,     0,     0,
     190,     0,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,   308,   309,   310,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,   277,   278,     0,     0,     0,   272,     0,
       0,     0,     0,     0,   354,   355,   356,     0,     0,     5,
       6,     7,     8,    10,     0,    11,    24,    12,    13,    14,
      15,    23,    22,    21,    16,     0,    17,    18,    19,    20,
       0,    25,     0,   587,     0,   214,     0,     0,     0,     0,
       0,   256,     0,   258,   259,   254,   255,     0,   260,   261,
     112,   122,   586,   467,   462,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,   200,   201,   202,     0,     0,     0,   408,
     409,   411,   412,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   416,   417,   418,
       0,     0,   188,   189,   190,   191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   413,   414,   415,     0,     0,
       0,     0,     0,     0,     0,   496,   497,     0,   498,   480,
     361,   421,   424,   291,   481,   462,     0,     0,     0,     0,
       0,     0,     0,     0,   188,   186,   193,   194,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   469,     0,     0,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,     0,     0,   214,     0,     0,   351,
       0,     0,     0,   197,   198,     0,     0,     0,     0,     0,
     487,     0,   486,     0,     0,     0,     0,     0,   586,     0,
       0,   519,     0,     0,     0,     0,   252,   253,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   540,     0,   564,   542,   543,     0,     0,
       0,     0,     0,     0,   541,     0,     0,     0,     0,   270,
     271,     0,   214,     0,   214,     0,     0,     0,   462,     0,
       0,     0,   214,   357,     0,     0,    76,     0,    63,     0,
       0,    67,    66,    65,    64,    69,    68,    70,    71,     0,
       0,     0,     0,     0,     0,   525,   462,     0,   213,     0,
     212,     0,   167,     0,     0,   525,   526,     0,     0,   576,
       0,   577,   526,   110,   110,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   513,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,     0,   363,   488,   365,
       0,   482,     0,     0,   462,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,   438,     0,     0,     0,     0,     0,     0,   292,     0,
     324,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,   214,   214,     0,   471,   470,     0,     0,
       0,     0,   214,   214,     0,     0,     0,     0,   288,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,     0,     0,     0,     0,     0,   235,     0,     0,
     233,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   251,     0,     0,     0,     0,     0,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,   273,     0,   239,     0,
     240,     0,     0,   363,     0,   214,     0,     0,     0,     0,
       0,     0,     0,   312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      72,    73,     0,     0,   249,    38,   245,     0,     0,     0,
       0,     0,   209,     0,     0,     0,   215,     0,     0,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,   465,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,     0,   192,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   419,   437,     0,     0,   494,     0,     0,     0,     0,
       0,   456,     0,   362,   483,     0,     0,     0,   490,     0,
     381,   380,   379,   378,   374,   375,   382,   383,   377,   376,
     367,   366,     0,   368,   489,   369,   372,   370,   371,   373,
     463,     0,     0,   464,   441,     0,   499,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,   350,
       0,     0,     0,     0,   349,     0,   214,     0,     0,     0,
       0,     0,   473,   472,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   337,     0,     0,   234,     0,     0,
     229,     0,     0,     0,     0,   347,     0,     0,     0,   362,
       0,     0,     0,     0,     0,     0,     0,     0,   275,   276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,     0,
       0,     0,   458,     0,     0,   241,   243,     0,   368,     0,
     463,   441,   588,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   362,     0,
      63,     0,     0,     0,     0,    79,     0,    63,    64,     0,
       0,   463,     0,     0,   441,     0,     0,     0,     0,     0,
     583,    28,    26,    27,     0,     0,     0,     0,     0,   464,
     529,    29,     0,     0,   246,   578,   579,     0,   580,   529,
      74,   113,    75,   123,   466,   468,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     515,   516,   203,     9,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   407,   394,     0,   396,   397,   398,   399,
     400,   512,   401,   402,   403,     0,     0,     0,   504,   503,
     502,     0,     0,     0,   509,     0,   453,     0,     0,     0,
     455,   127,   436,   492,     0,     0,   422,   511,   427,     0,
     433,     0,     0,     0,     0,   484,     0,     0,   434,     0,
       0,     0,     0,     0,   426,   425,   448,    70,    71,     0,
       0,     0,     0,     0,     0,   362,   320,   325,   323,     0,
     333,     0,   147,   148,   196,   362,     0,     0,     0,     0,
     230,     0,   242,   244,     0,     0,     0,   204,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,   336,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,   554,     0,   561,
     550,   551,   552,     0,   566,   565,     0,     0,   555,   556,
     557,   563,   570,   569,     0,   138,     0,   544,     0,   546,
       0,     0,     0,   539,     0,   238,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,     0,   358,     0,   584,
       0,     0,     0,     0,   101,    63,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,    61,     0,    39,    40,
      41,    42,    43,     0,   426,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,   527,     0,     0,     0,
       0,     0,     0,     0,   134,     0,   130,   131,     0,     0,
       0,   152,   152,     0,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   456,   457,     0,
     429,     0,     0,     0,   491,   384,   485,   442,   440,     0,
     439,     0,     0,   500,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,   298,     0,   301,     0,   303,     0,   289,   295,     0,
       0,     0,   228,     0,     0,     0,     0,     0,     0,     0,
       0,   338,     0,   232,   231,   353,     0,     0,    35,    36,
       0,     0,     0,     0,   520,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   459,   548,     0,   442,     0,     0,   214,   314,
       0,   315,   214,     0,     0,   534,   535,   536,   537,     0,
      86,     0,     0,     0,     0,    84,    91,    93,     0,   523,
       0,    99,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,    34,   442,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    31,     0,   530,     0,     0,    32,     0,
     530,   581,     0,   114,   119,     0,     0,     0,   133,   136,
     137,   461,     0,    77,    78,   154,     0,     0,     0,     0,
     155,   170,   171,     0,     0,     0,   156,   181,   172,   176,
     177,   173,   174,   175,   162,     0,     0,   395,   404,   405,
     406,   505,     0,     0,     0,   451,   452,   454,   128,   420,
     450,   423,   428,     0,     0,   456,   182,   435,     0,    70,
      71,     0,   447,   443,   445,   506,   178,     0,     0,   150,
       0,     0,   331,     0,   149,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   214,   214,     0,     0,   300,   480,
       0,     0,   302,   304,     0,     0,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,   159,   160,     0,     0,     0,     0,   102,   103,
     107,     0,   562,     0,     0,   560,     0,   571,     0,     0,
     139,   140,   568,   545,   547,     0,     0,     0,     0,     0,
       0,   312,   316,   312,     0,   359,    85,    63,     0,     0,
       0,     0,    83,     0,   521,     0,     0,     0,     0,     0,
       0,   574,   573,     0,     0,     0,     0,     0,   478,     0,
       0,   447,   247,   443,   248,     0,     0,   216,     0,     0,
     533,   531,     0,     0,   115,   120,     0,     0,     0,   513,
     514,   132,   153,   157,   158,   163,   180,     0,   165,     0,
       0,     0,     0,     0,     0,   430,     0,     0,     0,     0,
     501,   449,     0,   164,     0,   183,   321,     0,     0,   184,
       0,     0,     0,     0,     0,     0,   477,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   226,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
       0,   335,    37,     0,   518,     0,     0,   267,   266,     0,
       0,     0,     0,     0,     0,   142,   143,   146,   145,   144,
       0,   549,     0,   585,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    97,   524,     0,     0,     0,    88,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    46,     0,
      33,     0,     0,   582,   127,   138,     0,     0,   135,     0,
       0,     0,     0,     0,     0,   507,   508,     0,   456,   431,
       0,   444,   446,     0,   166,   187,     0,   328,   328,     0,
     108,   109,   214,     0,   207,   208,   290,     0,   296,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
     211,   210,     0,     0,     0,     0,   104,   105,   553,   559,
     558,   141,     0,     0,     0,   317,     0,    92,    94,     0,
     100,     0,    82,   575,    89,    90,    49,     0,     0,     0,
       0,   479,     0,     0,   444,   532,     0,     0,     0,   117,
     572,     0,   124,     0,     0,   169,     0,     0,     0,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,     0,   306,     0,     0,   284,     0,   218,     0,
       0,     0,     0,     0,     0,     0,   517,   268,     0,     0,
     346,   214,   360,     0,   522,     0,    45,     0,     0,     0,
      62,    47,     0,   116,   121,   127,     0,     0,   151,     0,
       0,   432,     0,     0,     0,     0,   329,   339,     0,     0,
     340,     0,   205,     0,   297,     0,   280,     0,   214,     0,
       0,     0,     0,     0,     0,   161,   106,   264,   312,    98,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
       0,   185,     0,   343,     0,   344,   345,   474,     0,     0,
     286,   221,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    59,     0,     0,   118,     0,     0,     0,     0,
       0,   305,   285,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,   219,   319,
      50,     0,    57,     0,   257,     0,   510,     0,     0,     0,
     287,     0,     0,    51,     0,     0,   263,     0,     0,     0,
     220,     0,     0,     0,     0,   495,     0,     0,    54,    52,
       0,    55,     0,   341,   342,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   109,   994,   110,   111,   980,  1771,  1777,
    1258,  1457,  1915,  2042,  1259,  2013,  2060,  1260,  2044,  1261,
    1262,  1461,   410,   551,   552,  1060,   112,   726,   433,  1784,
    1925,  1785,   434,  1668,  1323,  1285,  1286,  1287,  1418,  1610,
    1611,  1121,  1505,  1497,   706,   562,   254,   280,   326,   187,
     255,   419,   420,   116,   117,   118,   119,   120,   121,   122,
     123,   256,  1153,  1947,  2004,   879,  1149,  1150,   257,   957,
     258,   127,  1351,  1119,   854,   893,  1885,   128,   129,   130,
     131,   259,   260,  1081,  1094,  1212,   261,   731,   262,   844,
     730,   436,   577,   295,  1647,   332,   333,   264,   522,   340,
    1246,  1450,   429,   425,  1205,   936,  1490,  1640,  1641,   921,
     431,   133,   388
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1754
static const yytype_int16 yypact[] =
{
    9968,    44,    66, 10119, -1754, -1754,  -200,    78,    33,  -129,
     -98,    42,   146,   156,   207,   213,    -5,   218,   235,    12,
      31,    21,   262,   262,    65,   104,   115,    56,   129,   140,
      71,   151,   166,   179,   206,   231,   244,   256,   276,   318,
     326,    95,   283,   330,   458,   340,   -10,   335,  5664,   352,
     351,   507,   -33,   487,   568,   443,   -15,   373,   582,  -117,
     397,   425,   425,   403,   447,   342, -1754, -1754, -1754, -1754,
   -1754,   427,   784,   576,   617,    32,    55,   630,   637,   -39,
     717,   723,   747,  4953,   748,   520,   526,   545,    47,    72,
   -1754,   558,   573, -1754, -1754,   787,   809,   592, -1754, 10317,
     607, 10347,    17,    19, -1754, -1754, -1754,  9681,   610, -1754,
   -1754, -1754, -1754, -1754,   611, -1754, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,  -122, -1754, -1754, -1754, -1754,
      59, -1754,   815,   661,  4714,    87,   634,   867,  9681, 10287,
   10287, -1754,  9681, -1754, -1754, -1754, -1754, 10287, -1754, -1754,
   -1754, -1754,   669,   676,   908, -1754, -1754, 10377,    21,  9681,
    9681,  9681,   682,  9681,  9681,  9681,   683,  9681,  9681,  9681,
    9681,  9681,  9681,  9681, 10287,  9681,  9681,  9681,  9681,  5901,
     687, -1754,  7797, -1754, -1754, -1754,   681,  4953, 10287, -1754,
   -1754, -1754, -1754, -1754,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   271,   262,   262,
     262,   262,   262,   688,   262,   262,   689, -1754, -1754, -1754,
     262,   262,   686, -1754, -1754, -1754,  5901,   811,   568,   692,
     262,   262,   694,   695,   696, -1754, -1754, -1754,  9681,  6138,
    9681,  9681,  6375,    21,    25, -1754, -1754,   697, -1754,  7733,
   -1754, -1754, -1754, -1754, -1754,    90,  9681,  7797,   698,   699,
    6612,  4953,  4953,  4953, -1754, -1754, -1754, -1754, -1754,   700,
    6849,   701,  4138,   937,  5901,   702,    47,   703,   704,   425,
     425,   425,  9681,  9681,   -60, -1754,   -53,   425,  8670,     1,
     141,   710,   713,   714,   715,   716,   719,   720,  9681,  4953,
    4953,  4953,   722,    10,   936,   709, -1754,   950,   956, -1754,
     721,   724,   726, -1754, -1754,   727,  4953,   725,   731,   739,
   -1754,  9681, -1754,   957,   959,  9681,  9681,  9681,   381,  9681,
     738, -1754,   805,  9681,  9681,  9681, -1754, -1754,  9681, -1754,
     262,   262,   262,   744,   745,   746,   262,   262,   262,   262,
     262,   262,   262, -1754,   262, -1754, -1754, -1754,   262,   262,
     750,   751,   262,   755, -1754,   757,  1003,  1004,   768, -1754,
   -1754,  1006, -1754,  1007, -1754,   262,  9681, 12520,   103, 10287,
    7797,  9681, -1754, -1754,  5901,  5901, -1754,   771, 10377,   341,
    1008, -1754, -1754, -1754, -1754, -1754, -1754,  9681,  9681,    24,
    5901,  1010,   620,  1684,   776,  1017,    37,   791, -1754,   793,
   10565,  9681, -1754,  2415,  -134, -1754,    60,   -44,  9637, -1754,
     113, -1754,    79,  -114,   -51,   948, -1754,    21,   790,   792,
   13036, 13061, 13086,  9681, 13111, 13136, 13161,  9681, 13186, 13211,
   13236, 13261, 13286, 13311, 13336,   799, 13361, 13386, 13411, 11650,
    1034,  9681,  7797,  8060, -1754,   299,  9681,  1036,   803,  9681,
    9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,
    9681,  9681,  9681,  9681,  9681,  7797,  9681,  9681,  9681,  9681,
    9681,  9681,  7797,  7797,   804,  9681,  9681, 10287,  9681, 10287,
    5901, 10287, 10287, 10287,  9681,    52,  9681,  5901,  4953, 10287,
   10287,  7797,    21, 10377,    21,   810,  7797,   810, -1754,   810,
   13436, -1754,   304,   806,    89, -1754,   986,  9681,  9681,  9681,
    9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,
    9681,  7086,  9681,  9681,  9681,  9681,  9681,    21,  9681,  9681,
    1048, -1754,   636, 13461,   359,  9681,  9681,  9681, -1754,  1046,
    1047,  1047,   817,  9681,  9681,  1051,  7797,  7797, 12548,   818,
    1054, -1754,   820, -1754, -1754,  -105, -1754, -1754,  9768, 10495,
     425,   425,    87,    87,  -103,  8670,  8670,  9681,  5020,  -101,
   -1754,  9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,  9681,
   13486,  1057,  1059,  1060,  9681,  1063,  9681, -1754,  9681,  5257,
   -1754, -1754,  7797,  7797,  7797,  9681,  1064,  9681,  9681,  9681,
   13511, -1754, -1754, 13536, 13561, 13586,   892, 10528, -1754,   828,
    8383, 13611, 13636, 12631, 10287, 10287, 10287, 10287, 10287, 10287,
   10287, 10287, 10287,  9681, 10287, 10287, 10287, 10287,    15, 10377,
   10287, 10287, 10287,    21,    21, -1754, -1754,  7797, -1754,  5494,
   -1754,  5731,  9681,   810,  9681, -1754,    21,  9681,  9681,  1048,
     830,   413, 13661, 10500,   833,   472,  9681,  1071,   835,   836,
     837,   838,  9681, 13686, 12658,   157,   839,  1075,  1080, -1754,
   -1754, -1754,  7797,   196, -1754, -1754, -1754,    21,  9681,  9681,
    1048,   848, -1754,   852,   -29,   443, -1754,   847, 11679, -1754,
     134,  7797,    21,  9681,  9681,  1088,  1089,  7797,  9681,  1091,
   10287,    21,  8747,  1088,  1092, -1754,    21,  1093, 10287,  9681,
     860,   861, -1754,  9681, 10377,  1096,  1097,  1098, 13711,  1099,
    1100,  1103, 13736,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
   -1754,  1112,  1113,  1114, -1754,  9681, 13761,  7797,   879,  7797,
   11708, -1754,  1117, 12604, 12604, 12604, 12604, 12604, 12604, 12604,
   12604, 12604, 12604, 12604, 10561, 12604, 12604, 12604, 12604,  1888,
     644, 12604, 12604, 12604, 10594, 10627, 10660,  8060,   884,   883,
      80,  7797, 10693, 10726,   644, 10759,   644,   878,   880,   881,
     133, 14561, -1754,   644, 11737, -1754,   888,   164,   644,  -162,
     887,   474,   513,  1124, -1754,  1088,   644,   889,  8618,  8702,
    1285,  1418,  1022,  1022,   468,   468,   468,   468,   468,   468,
     515,   515,  7797,   385, -1754,   385,   385,   810,   810,   810,
     893, 13786, 12685,   -59,   646,  7797, -1754,  1130,   896, 13811,
   13836, 13861,  9681,  5901,  1136,  1137,  8438, 11766, 13886, -1754,
     514,   516,  7797,   897, -1754,  5968, -1754,  6205,  6442,   425,
    9681,  9681, -1754, -1754,   900,   902,  8670,  9010,  1018,   460,
     425,  6679, 13911, 11795, 13936, 13961, 13986, 14011, 14036, 14061,
   14086,  1141,  9681,  1146, -1754,  9681, 14111, -1754, 12712, 12739,
   -1754,   519,   522,   524, 11824, -1754, 12766, 12793, 10792, -1754,
    1147,  1148,  1149,   912,  9681,  6916,  9681,  9681, -1754, -1754,
      26,   382,   429,   382,   913,   918,   911,   644,   644,   914,
   10825,   644,   644,   644,   644,  9681,   644,  1152, -1754,   916,
     925,   445,   191,   924,   527, -1754, -1754, 12604,   385,  7153,
     922,   649,   921,   994,  1165,  1024,  8979,   933,   935,  1173,
    5901, 11853, -1754,  9681,  9681,  9681,  9681,  2451,   162,   100,
   10377,  9681,  1174,  1177,    48, -1754,   529,  1138,  1140,  5901,
      22,   938, 14136, 12820,   386,  9681,  9681,   943,   949,  7797,
   -1754, -1754, -1754, -1754, 10287,   221,   942, 14161, 12847, -1754,
     952, -1754,   226, 10858, -1754, -1754, -1754,   944, -1754,   953,
   -1754,   108, -1754, -1754, 14561, -1754,  1189, 12604,   644,   425,
    5901,  5901,  1188,  5901,  5901,  5901,  1190,  5901,  5901,  5901,
    5901,  5901,  5901,  5901,  5901,  5901,  5901,  2795,  1192,  7797,
    8060, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,  9681, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,  9681,  9681,  9681, -1754, -1754,
   -1754,   530,  9681,  9681, -1754,  9681, -1754,  5901, 10287, 10287,
   -1754,   954, -1754, -1754,  9681,  9681, -1754, -1754, -1754,  1088,
   -1754,  1088,  9681,  9681,   960, -1754,  5901,   262, -1754,  9681,
    9681,  9681,   532,  1088,   -59,   333, -1754,  9681,  9681,   644,
     535,  5901,  7797,  1194,  1197,  1199,  1864, -1754, -1754,  1201,
   -1754,   969, 14561,   962, -1754,  1204,  1205,  1206,   538,  1210,
   -1754,  7390, -1754, -1754,   -95, 10891, 10924, -1754, -1754, 11882,
     -62,  1087,  1211,  9063,   973,  1215,   978,    38,    43,   -52,
   -1754,   -89, -1754,   460,  1217,  1216,  1218,  1219,  1221,  1222,
    1223,  1224,  1225,  5901, 14561, -1754,  2921,   990,  1228,  1230,
    1231,  1142,  1233, -1754,  1232,  1235,  9681,  5901,  5901,  5901,
    1253, 10957, -1754,  8934,  1991,    34,  1254, -1754,  7797, -1754,
   -1754, -1754, -1754, 10287, -1754, -1754,  9681, 10287, -1754, -1754,
   -1754, -1754, 14561, -1754,  1013,  1015, 10287, -1754, 10287, -1754,
    1088, 10287,  1021, -1754,  1016, -1754,  1088,  9681,  9681,  1023,
     568,  1025,  9295, -1754,  3110,  1027,  5901, -1754,  1028, -1754,
   11911, 11940, 11969, 11998, -1754, -1754,  9681,  1261,    36,  9681,
    1265,  1267,  3180, -1754,  1268,    47,  1270,  1033,   644,   262,
     262,  1273, -1754,  1041,  1043,  1040, -1754,  1279, -1754, -1754,
   -1754, -1754, -1754,  1088,   186,   851,  9681, 12874, 14186,  9681,
    9681,   541,  1280,   136,  1088, -1754,  1042,  9681,  1283,  9681,
    1088,  9372,  8029,   644,  4227,  1049,  1044, -1754,  1287,  1289,
      61,  1175,  1175,  5901,  1290,  1294,  1295,  5901,  1126,  1298,
    1299,  1300,  1301,  1302,  1303,  1307,  1308,  1309, -1754,  1311,
     543, 12604, 12604, 12604, 12604,   644, 10990, 11023, 11056,  1077,
     644,   644,  1189,   644, 14211, 12604,  1078,     6, 14561, 12604,
   -1754,  1316,   644, 11089, 14561, 14561, -1754,   650, -1754,  1322,
   -1754, 14236, 12901, -1754,   644,  1323,   546,  5901,  5901,  5901,
    1324,  1325, -1754,   202,  9681,  5901,  1090,  1094,  1327,   685,
   -1754,  9681,  9681,  9681,  1095,  1111,  1115,  1102, -1754,  3355,
    5901, -1754,  9681, -1754,  1326, -1754,  1329, -1754, -1754,  8670,
     302,  5190, -1754,  1116,  1119,  1120,  1121,  1122,  1123,  7323,
    1330, -1754,  7797, -1754, -1754, -1754,  1127,  9681, -1754, -1754,
   12928,  1333,  1334,  1157, -1754,  9681,  9681,  9681, -1754,  1335,
    1341,   733,   462,  1101,  2483,  1125,  9681,    23,   644,  1129,
     644,  1128, -1754, -1754, 10377,   653,  9681,  1131, -1754, -1754,
    3693, -1754, -1754,  1132,  1342, -1754, -1754, -1754, -1754,  3781,
   -1754,   188,  1134,  1344,  3822, -1754, -1754, -1754,    47, -1754,
     551, -1754,  9681,   202,  2852,  3613, -1754,  1118,  9681,  9681,
    5901,  1139, -1754,   464,  1351,  1365, 14261,  1366,  1124, 14286,
   14311,  1369, -1754, -1754, 10287,  1144,  1373, 14336, -1754, 11122,
    1145, -1754,  4464, 14561, -1754,  1374,   262,  6375, -1754, -1754,
   -1754, -1754,  1189, -1754, -1754, -1754,   425,  1379,  1381,  1382,
   -1754, -1754, -1754,  1384,  1296,  1386, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,  1388,  1151, -1754, -1754, -1754,
   -1754, -1754,  9681,  9681,  9681, -1754, -1754, -1754,  1044, -1754,
   -1754, -1754, -1754,  9681,  1155,  1150, -1754, -1754,  9681,  9681,
    9681,   644,   -59, -1754, -1754, -1754, -1754,  1153,  1391,  1126,
    1393,  9681, -1754,  5901, 14561,   903,  7797,  7797,  9681, -1754,
    8438, 12027, 14361,  9244,    87,    87,  9681,  9681, -1754,   301,
    1154, 14386, -1754, -1754, 12056,   -78, -1754,  1394,  1395,  5901,
     425,   425,   425,   425,   425,  5427,  1398, -1754,   552,  9681,
    3846,  1399, -1754, -1754,  5901,  9328,  1647, 14411, -1754, -1754,
   -1754,  8115, -1754, 10287,  9681, -1754, 10287, 14561,  8352, 10377,
    1158, -1754, -1754, -1754, -1754,  1167,  1160,  9681,  9681, 12085,
    9681, 10500, -1754, 10500,  5901, -1754, -1754, 10377,  9681,  1403,
    1406,    48, -1754,  1407, -1754,    47, 12955,  5901, 10287,  1408,
     644, -1754,  1164,   644,  9681, 11155, 11188,   554, -1754,  9681,
    9681,   362, -1754,  1172, -1754,  1199,  1204, -1754,  1410,  9681,
   -1754, -1754,  9681,  9604, -1754, -1754,  1176,  3613,   559,  2880,
    1413, -1754,   668, -1754, -1754, -1754, -1754,  1178, -1754,  1412,
    5901, 12604, 12604, 11221, 12604, -1754,  1183, 11254, 14436, 12982,
   -1754, -1754,  9681, -1754,  1419, -1754, 14561,  1420,  1181, -1754,
     560,   561, 12576,  4171,  1421,  1186, -1754, -1754,  9681,  1187,
    1191, 12114, 13009,  1424,  5901,  1426,  1193,  9681, -1754, -1754,
     562,   -47,   -34,   -21,   -12,   135,  7560,   137, -1754,  1428,
   12143, -1754, -1754,  1266, -1754,  9681,  9681, -1754, -1754,  7797,
    4400,  1431,  1200, 12604,   644, 14561, -1754, -1754, -1754, -1754,
      23, -1754, 10377, -1754, 12172,  1195,  1198,  1202,  1435,  4587,
   -1754,  1436,  1438, -1754, -1754,  1203,  1441,   569, -1754,  1443,
    1444,   236, 14561,  9681,  9681,  1212,  5901,   570, 14561, 14461,
   -1754, 14486, 11287, -1754,   954,  1015,  5901,   644, -1754,  9681,
   10377,    21,  9681,  1447,   572, -1754, -1754,  9681,  1150, -1754,
    9681, -1754, -1754, 12201, -1754, -1754,  5901,   549,   616,  7797,
   -1754, -1754,    87,  9553, -1754, -1754, -1754,  1450, -1754,  1214,
    5901, -1754, 12230,  1453,  7797,   425,   425,   425,   425,   425,
   -1754, -1754,  9681, 12259, 12288,   578, -1754, -1754, -1754, -1754,
   -1754, -1754,  1220,  1455,  1226, -1754,  1456, -1754, -1754,    47,
   -1754,  1288, -1754, -1754, -1754, -1754, -1754,  9681, 11320, 11353,
    5901, -1754,  1458,  9681,  1227, -1754,  9681,  1229,  1236, -1754,
   -1754,  2031, -1754,  1237, 12317, -1754,  1234, 11386,  1241, 11419,
   -1754,   579,  1239,   425,  5901,  1459,  1240,   425,  1460,   580,
    1242, -1754,  9681, -1754,  1461,  1339,  7627,  1244, -1754,   586,
     193,   223,   225,   227,   240,  4630, -1754, -1754,  1466,  1468,
   -1754, -1754, -1754,  1469, -1754,  1245, 14561,  9681,  9681,   587,
   -1754, 14561, 11452, -1754, -1754,   954, 10377,  1249, -1754,  9681,
    9681, -1754,  9681,  1479,   425,   105, -1754, -1754,   425,   123,
   -1754,  1484, -1754, 12346, -1754,  9681, -1754,   460, -1754,  1485,
    7797,  7797,  7797,  7797,  7560, -1754, -1754, -1754, 10500, -1754,
    9681, 14511, 11485,    57,  9681,  1248, -1754, -1754, 11518, 11551,
   11584, -1754,   308, -1754,   323, -1754, -1754, -1754,  4656,   331,
    9838, -1754,   588,   596,   597,   599,   332,   604,  1250,   605,
   -1754,  9681, -1754,  5901, 12375, -1754,  9681,  9681,  9681,   425,
     425, -1754, -1754, -1754,   460,  1487,  1491,  1492,  1493,  7797,
    1494,  1495,  1513,  1278, 14536,   613,  1516, 12404, 12604, 11617,
     334,   349,   412, -1754, -1754, -1754, -1754,   621, -1754, -1754,
   -1754, 10287, -1754,  1281, -1754,  1520, -1754,  9681,  9681,  9681,
   -1754,  1521,   624, -1754,  1286,  5901, -1754, 12433, 12462, 12491,
   -1754,  1522, 10287, 10287,   626, -1754,  1524,  1525, -1754, -1754,
     627, -1754,  1526, -1754, -1754,  1527, 10287, -1754, -1754, -1754
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1754, -1754, -1754, -1754,   263, -1754, -1754, -1754, -1754,  -425,
   -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754,
   -1754, -1754,  -672,  -131,  3748,  2454, -1754,  1133, -1754, -1754,
   -1754, -1754, -1754, -1754, -1753, -1754,   216,    49,  -246, -1754,
    -210, -1754,    -7,   254,  1544, -1754,    -1,   843, -1754, -1754,
      13,  -577,  -287, -1754, -1754, -1754, -1754, -1754, -1754, -1754,
   -1754,  1546, -1754, -1754, -1754, -1754, -1146, -1140,  1549, -1606,
    1552, -1754, -1754, -1754,   996, -1754,  -250, -1754, -1754, -1754,
   -1754,  1897, -1754, -1754, -1317,   138,  1557, -1754,     2,  -661,
   -1754, -1754,    99, -1754, -1567,   -28,  -153,  2083,   711,  -285,
     -70, -1754,    91,   -64, -1754, -1754,   -46,   114, -1566,  -143,
     850, -1754,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -534
static const yytype_int16 yytable[] =
{
     134,   572,   114,   411,   430,   874,   875,  1380,   951,  1378,
    1534,   588,  1720,   971,   605,  1755,   115,  1756,   154,   152,
     263,   979,   381,   153,   383,   152,  1252,  1608,   685,   609,
     525,  1867,   285,  1185,   467,   376,   313,   380,  1409,   984,
    1441,   152,  1748,   135,  1373,   265,   697,   136,   141,  1375,
       4,   338,   152,   275,  1000,   323,   152,   286,   324,   318,
     162,   319,  1009,  1992,   269,   393,     5,  1495,   269,   712,
     415,   325,   317,   287,   288,   166,   342,  1142,  1088,   281,
     265,   183,   282,  1089,   184,   341,   270,   185,   721,   547,
     987,   417,   137,   438,  1143,   659,   377,   661,   437,   547,
     186,  1787,  1144,  1145,  1146,   673,   710,  1235,  1147,  1148,
     139,  1973,   666,  1794,   711,  1282,   314,   391,   559,   560,
     561,   392,   580,   581,   580,   581,   580,   581,   724,  1975,
     138,   416,   580,   581,   725,  1410,   426,   426,   580,   581,
     991,   140,  1473,   869,   432,   876,   320,   880,   418,   580,
     581,   460,   143,  1361,  1097,   439,   601,   602,   603,  1379,
     294,   296,   144,   299,   970,   580,   581,   580,   581,  1235,
    1717,   426,  1965,   616,   580,   581,   265,   405,   406,   265,
     580,   581,  1365,   582,   265,   426,  1253,  1254,  1255,  1256,
     583,   727,  1377,   580,   581,  1627,   716,   725,   686,   687,
    1374,  1824,   526,   977,   717,  1376,   580,   581,   263,  1235,
    1442,  1443,  1609,   145,  1825,   580,   581,   315,  1686,   146,
      60,    61,    62,    63,   148,   414,   108,  1826,   580,   581,
     424,   427,   108,   265,   147,    74,  1827,   508,    77,  1881,
    1378,   149,   558,   108,   590,   155,   265,   156,   108,   265,
     524,   606,   565,   150,  1092,   523,   570,   136,   108,   108,
     382,   935,   384,   108,   265,   455,  1257,   265,   265,   265,
     265,  1186,   151,   405,   406,   316,   698,   265,   699,   468,
    -526,   265,   700,   341,   865,   142,   867,   868,   580,   581,
     339,  1245,   690,  1919,   691,   163,  1236,  1239,   394,   713,
    1993,   714,   395,   881,   159,   715,   265,   265,   265,   527,
     167,   343,   401,   402,   403,   404,   405,   406,   722,   548,
     714,   549,  1070,   265,   723,   550,   405,   406,   155,   548,
     156,   549,   580,   581,   677,   550,   405,   406,   178,   405,
     406,   915,   667,   160,   668,  1238,   300,   155,   669,   156,
     580,   581,  1988,   719,   161,   805,   992,   993,   992,   993,
     800,   720,   580,   581,   580,   581,   674,   675,   164,   401,
     402,   403,   404,  1080,   401,   402,   403,   404,   949,   165,
     591,   720,   688,  1828,   592,  1829,   426,   265,   575,   576,
     168,   265,   265,   405,   406,   179,   584,   589,   405,   406,
     401,   402,   403,   404,   690,   169,   691,   265,   401,   402,
     403,   978,  1085,   701,   401,   402,   403,   404,   170,   707,
     580,   581,   405,   406,   405,   406,  2015,   180,  1326,  -528,
    1327,  1142,   678,   301,   732,   679,  1210,   302,   680,  1211,
     681,  1950,  1337,   303,   304,   171,   305,   306,  1143,   810,
     580,   581,   580,   581,   580,   581,  1144,  1145,  1146,   265,
    1142,  1273,  1147,  1148,   181,   307,  1278,   580,   581,   759,
     172,  1951,   797,  1952,   759,  1953,  1856,  1143,  2054,   558,
     670,  1878,   265,   173,  1857,  1144,  1145,  1146,  1954,   265,
     790,  1147,  1148,   923,   426,   174,   426,   265,   426,   426,
     432,   155,   803,   156,   265,   265,   426,   426,   265,   154,
     492,   154,   493,   265,   809,   175,   811,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   580,   581,   276,   265,   546,
     277,  1142,   278,   758,   840,  1713,  1576,   759,   814,  1421,
     580,   581,   759,   279,   972,  1425,  1999,   176,  1143,   580,
     581,   580,   581,   265,   265,   177,  1144,  1145,  1146,   405,
     406,  2000,  1147,  1148,   188,  2002,   580,   581,  1339,  1131,
    2009,   271,  2038,   182,   272,   938,   273,   707,   794,  1142,
     796,   266,   798,   799,   267,   418,   418,  2039,   405,   406,
     806,   807,  1463,   848,   268,  -533,  1143,   759,   707,   265,
     265,   265,   283,  1475,  1144,  1145,  1146,   544,   545,  1480,
    1147,  1148,   690,   546,   691,  1266,   626,  1218,   136,  -529,
     720,   432,   426,   432,   426,   426,   426,   426,   426,   426,
     289,   426,   426,   426,   426,   937,   297,   426,   426,   426,
     154,   943,   290,   291,   265,   942,  2040,   953,   707,   274,
     707,   759,   233,   950,   292,   234,   308,   235,   293,   690,
    1018,   691,   707,   311,   290,   291,   284,  1188,    41,   872,
     873,  1553,  1882,  1883,   576,   690,   292,   691,  1884,   265,
     298,  1559,  1560,  1208,   981,   539,   540,   664,   542,   543,
     544,   545,   690,  1650,   691,  1618,   546,  -530,   265,   996,
     759,   312,  1106,   155,   265,   156,   959,   432,  1007,  1091,
     960,   327,  1092,  1011,   321,   426,   922,   328,   924,   925,
     926,   927,   928,   929,   322,   931,   932,   933,   934,  1600,
    1601,   939,   940,   941,   664,   542,   543,   544,   545,  1886,
    1887,   329,   334,   546,   265,  1884,   265,  1095,  1126,   335,
    1127,   759,   759,  1170,   759,   336,  1171,   759,  1172,  1628,
     759,  1214,   759,  1248,  1315,   759,  1336,   759,   759,  1344,
     759,  1637,  1358,   759,   337,  1471,   759,  1516,   265,   759,
    1547,   759,  1123,   346,   759,  1634,  1729,   344,  1775,  1635,
     759,  1979,  1776,  1788,  1807,  1808,  1823,  1789,   759,   759,
    1776,  1005,   345,  1853,  1862,   347,  1876,   720,  1863,  1013,
    1776,   396,  1908,  1933,  1941,  1117,   759,  1776,   759,   265,
    1949,  1963,  2005,   348,   759,  1776,   759,  1237,  1240,  1378,
    2006,  2007,   265,  2008,   759,   759,   378,   759,  2010,  2012,
     265,   389,   759,  1863,   390,   152,   349,  2033,  2022,   265,
     690,  1776,   691,   692,   707,  2041,   707,   707,  2051,   759,
    2062,  2065,  2052,   422,  1776,  2066,   690,   421,   691,   845,
     707,   309,  1378,   310,   690,  1107,   691,  1108,  1217,  1539,
    1218,  1540,  1617,   465,  1618,   580,   581,   350,   351,   352,
     353,   354,   355,   356,   357,   358,  1241,  1698,   397,  1699,
     359,   360,   361,   362,   707,   435,   136,   437,   363,   364,
     365,   443,   447,   366,   466,   367,   461,   500,   503,   506,
     507,   509,  1228,   512,   513,   514,   368,   555,   556,   369,
     392,   569,   607,   563,   566,   571,   573,   574,   707,   593,
     608,  1251,   594,   595,   596,   597,   610,   265,   598,   599,
    1449,   604,   611,   621,   612,   622,   617,   613,  1134,   614,
     615,  1247,   618,  1338,  1340,  1140,   265,   399,   554,  1151,
     619,   628,   629,   637,   638,   639,   265,  1709,  1710,   650,
     651,   426,  1291,  1292,   653,  1294,  1295,  1296,   654,  1298,
    1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,   655,
     656,   657,   658,   660,   676,   682,   689,   265,   265,   695,
     265,   265,   265,   696,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   135,   729,   265,   702,   733,   750,
     734,   755,   761,   762,   370,   371,   372,   791,   546,  1319,
     817,   815,   843,   852,   853,   373,   856,   859,   863,   374,
     864,   375,   108,   866,   892,   894,   913,   895,  1331,   897,
     905,   916,   952,   958,   265,   426,   426,   962,   963,   964,
     965,   966,   974,  1345,   973,  1272,   975,   405,   406,   985,
     989,   986,   999,   265,  -527,  1001,  1464,  1004,  1010,  1012,
    1015,   671,  1016,  1019,  1020,  1021,  1023,  1024,   265,   265,
    1025,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1290,  1034,
    1035,  1036,  1039,  1043,  1068,  1069,  1077,  1090,  1078,  1079,
     707,  1096,  1099,  1338,  1340,  1390,  1084,  1111,  1103,  1112,
    1118,  1621,  1129,  1120,  1137,  1623,  1138,  1141,  1163,  1401,
    1402,  1403,  1165,  1191,  1177,  1178,  1179,  1180,  1192,  1193,
     265,  1204,  1196,  1633,  1206,  1207,  1213,  1216,  1219,  1320,
    1321,  1220,  1221,  1222,   265,   265,   265,  1225,  1226,  1227,
    1243,  1244,  1269,  1263,  1249,   265,  1250,  1274,  1270,  1280,
     426,  1277,  1281,  1284,   426,  1293,  1366,  1297,  1433,  1309,
    1330,  1347,  1322,   426,  1348,   426,  1349,  1352,   426,  1353,
    1354,  1355,  1356,  1357,  1359,  1367,  1370,  1372,  1484,  1427,
    1489,  1371,  1382,   265,  1381,  1383,  1384,   812,  1385,  1386,
    1387,  1388,  1389,  1392,  1393,  1890,  1394,  1395,  1398,  1396,
    1397,  1399,   341,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,  1488,  1404,  1411,  1416,
     546,  1423,   426,  1417,  1424,  1499,  1426,  1440,  1428,  1503,
    1432,  1445,  1434,  1446,  1452,  1448,  1451,   860,   861,  1456,
    1458,   265,  1459,  1460,  1413,  1462,  1472,  1476,  1415,  1478,
     265,  1491,  1492,  1493,   265,  1494,  1500,  1419,  1496,  1420,
    1501,  1502,  1422,  1504,  1506,  1507,  1508,  1509,  1510,  1511,
    1629,  1642,  1642,  1512,  1513,  1514,  1515,  1525,  1532,  1548,
    1549,  1550,  1536,   901,   902,   903,  1542,  1555,  1551,  1546,
    1594,  1552,  1572,  1556,  1558,  1573,  1587,  1557,  1564,  1592,
    1593,  1598,  1570,  1567,   265,   265,   265,  1599,  1625,  1603,
    1764,  1631,   265,  1578,  1565,  1651,  1465,  1644,  1566,  1579,
    1616,  1586,  1580,  1581,  1582,  1583,  1584,   265,   944,  1613,
    1589,  1652,  1654,  1606,  1620,  1657,  1211,  1660,   265,  1630,
    1624,  1666,  1649,  1659,  1663,  1673,   265,  1674,  1675,   265,
    1676,  1677,  1678,  1679,  1680,  1685,  1692,  1693,  1092,  1695,
    1718,  1719,  1714,   976,  1728,  1732,  1750,  1751,  1752,  1760,
    1761,  1691,   720,  1763,  1768,  -531,  1780,  1793,  1665,  1786,
    1791,  1792,   995,  1799,  1806,  1804,  1805,  1811,  1002,  1812,
    1818,  1814,  1648,  1820,  1830,  1815,  1821,  1837,  1832,  1844,
    1838,  1847,  1845,  1849,  1850,   341,  1846,  1852,  1851,  1854,
    1855,   432,   432,  1875,  1664,  1860,  1893,   265,  1894,  1898,
    1909,  1910,  1912,  1914,  1920,  1937,  1940,  1944,  1945,  1911,
    -532,   426,  1956,  1923,  1957,  1959,  1927,  1929,  1575,   265,
    1924,  1931,  1934,  1938,   265,  1971,  1942,  1948,  1960,  1967,
    1976,  1981,  1995,  2023,  2011,  1767,  1704,  2024,  2025,  2026,
    2028,  2029,  1071,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,  2030,
    1691,  2031,  2034,   546,  2045,  1697,  2046,  2050,  2058,  2053,
    2063,  2064,  2067,  2068,  1896,  1989,  1474,  1741,  1528,  1868,
    1841,  1671,  1694,  1102,  1746,  1749,  1498,   113,   988,   124,
     265,  1648,   125,   265,   265,   126,  1110,   855,  1888,  1615,
     132,  1762,  1747,  1758,  1913,  1658,  1733,   728,     0,  1643,
    1006,     0,     0,  1128,     0,     0,   265,   418,   418,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,   265,     0,     0,     0,  1672,  1757,     0,     0,     0,
     426,     0,     0,   426,     0,     0,     0,     0,     0,  1766,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     707,   265,   707,     0,  1958,     0,     0,     0,  1247,     0,
       0,     0,   341,     0,   265,   432,     0,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,  1648,     0,     0,  1736,   546,     0,     0,     0,
       0,  1980,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,  1721,
    1722,  1723,  1724,  1725,  1727,     0,  1819,     0,  1842,     0,
     694,     0,     0,     0,  1742,     0,     0,  1744,     0,     0,
    1271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,  1872,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1861,     0,
    1310,     0,     0,     0,     0,     0,     0,     0,  1869,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,  1648,     0,
       0,     0,     0,   265,     0,     0,     0,     0,  1873,     0,
       0,     0,  1895,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,     0,
       0,   265,     0,  1346,     0,   418,     0,     0,     0,     0,
       0,     0,  1648,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1936,   265,     0,     0,
       0,     0,  1966,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,   265,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1737,     0,     0,     0,   707,   527,     0,     0,  1412,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,  1900,  1901,  1902,  1903,  1904,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   265,   265,
     265,   265,     0,     0,     0,     0,     0,   707,     0,     0,
       0,     0,     0,     0,     0,  1648,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   707,
       0,     0,  1935,     0,     0,     0,  1939,     0,     0,     0,
     265,     0,     0,  1350,     0,     0,     0,     0,     0,  1407,
       0,     0,     0,     0,   387,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1648,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   426,     0,
       0,   413,     0,  1972,     0,   423,     0,  1974,  1926,   428,
       0,     0,   265,     0,     0,     0,     0,     0,     0,   426,
     426,     0,     0,  1986,     0,     0,   440,   441,   442,     0,
     444,   445,   446,   426,   448,   449,   450,   451,   452,   453,
     454,     0,   456,   457,   458,   459,     0,     0,     0,   463,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,  2020,  2021,
       0,     0,   546,  1588,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   757,   542,   543,
     544,   545,  2043,     0,     0,     0,   546,     0,   690,     0,
     691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2059,  2061,   515,   517,   519,   520,   463,
       0,     0,     0,     0,     0,     0,     0,  2069,     0,     0,
       0,     0,     0,   553,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   568,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   578,
     579,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,   620,   546,
       0,  1408,   623,   624,   625,     0,   627,     0,     0,     0,
     630,   631,   632,     0,     0,   633,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,   464,     0,  1700,  1701,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   663,     0,     0,     0,   463,   672,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   683,   684,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   708,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,     0,     0,   464,     0,     0,     0,     0,
     738,     0,     0,     0,   742,     0,     0,     0,     0,     0,
     464,     0,     0,     0,     0,     0,     0,     0,   756,   517,
       0,     0,     0,   760,     0,     0,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   781,   782,   783,   784,   785,   786,   787,
     787,     0,   792,   793,     0,   795,     0,     0,     0,     0,
       0,   801,     0,   804,     0,     0,     0,     0,   787,     0,
       0,     0,     0,   463,     0,     0,     0,     0,     0,     0,
       0,   709,     0,     0,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   833,   835,
     836,   837,   838,   839,     0,   841,   842,     0,     0,     0,
    1835,     0,   849,   850,   851,     0,     0,  1234,     0,     0,
     857,   858,     0,   463,   463,     0,     0,     0,     0,     0,
       0,     0,     0,   464,     0,     0,     0,     0,     0,     0,
       0,     0,   515,   663,   877,     0,     0,     0,   882,   883,
     884,   885,   886,   887,   888,   889,   890,     0,     0,     0,
       0,   896,     0,   898,     0,   899,     0,     0,     0,   463,
     463,   463,   904,     0,   906,   907,   908,     0,     0,     0,
    1889,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1899,     0,     0,     0,     0,
     930,     0,     0,     0,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,     0,     0,     0,   947,
       0,   948,     0,     0,   841,   842,     0,     0,   780,     0,
       0,     0,     0,   961,     0,   788,   789,     0,     0,   967,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
       0,     0,     0,     0,   808,   982,   983,     0,     0,   464,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
     997,   998,     0,     0,   463,  1003,     0,     0,     0,   997,
       0,     0,     0,     0,   834,     0,  1014,     0,     0,     0,
    1017,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,   464,
     464,     0,  1037,   546,   833,     0,  1040,     0,     0,     0,
       0,  1982,  1983,  1984,  1985,  1987,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,   463,   546,
       0,     0,     0,     0,     0,   464,   464,   464,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
    2027,   546,     0,   690,     0,   691,     0,     0,     0,   463,
       0,  1604,     0,     0,     0,     0,     0,     0,     0,     0,
     464,     0,   463,     0,     0,     0,     0,     0,     0,  1116,
       0,     0,     0,  1122,     0,     0,     0,     0,     0,   463,
       0,     0,     0,     0,     0,     0,     0,  1135,  1136,     0,
       0,     0,     0,  1139,     0,   464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1164,
       0,     0,  1166,     0,   464,     0,     0,     0,     0,     0,
     464,  1308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1181,     0,  1183,  1184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1202,     0,     0,     0,     0,     0,     0,     0,
     834,     0,  1041,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1224,     0,     0,   152,   349,     0,     0,
    1230,  1231,  1232,  1233,     0,     0,   693,     0,  1242,     0,
       0,     0,     0,     0,   464,     0,     0,     0,     0,     0,
       0,     0,  1267,  1268,     0,     0,   463,  1790,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,   360,   361,   362,   464,     0,     0,     0,   363,
     364,   365,     0,     0,   366,     0,   367,  1391,   464,     0,
       0,     0,     0,     0,     0,     0,   463,   368,     0,     0,
     369,     0,     0,     0,     0,   464,     0,     0,     0,     0,
       0,     0,  1311,     0,     0,     0,     0,     0,     0,   802,
       0,     0,  1312,  1313,  1314,     0,     0,     0,     0,  1316,
    1317,     0,  1318,     0,     0,     0,     0,     0,   399,     0,
       0,  1324,  1325,     0,     0,     0,     0,     0,     0,  1328,
    1329,     0,     0,     0,     0,     0,  1333,  1334,  1335,     0,
       0,     0,     0,     0,  1341,  1342,   846,     0,     0,   463,
       0,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
    1369,     0,     0,     0,     0,   370,   371,   372,     0,     0,
       0,     0,     0,     0,     0,     0,   373,     0,     0,     0,
     374,     0,   375,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   464,  1400,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,     0,
       0,     0,   690,  1414,   691,  1638,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   757,
     542,   543,   544,   545,  1341,  1342,  1431,     0,   546,  1430,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1439,     0,     0,  1444,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,  1466,     0,     0,  1469,  1470,     0,     0,
       0,     0,     0,     0,  1477,     0,  1479,     0,  1477,  1483,
       0,     0,     0,     0,     0,     0,  1447,     0,     0,     0,
       0,     0,     0,     0,     0,   464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1044,  1045,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,     0,  1056,
    1057,  1058,  1059,     0,  1061,  1062,  1063,  1064,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1074,     0,
    1076,  1554,     0,     0,     0,     0,     0,  1082,  1561,  1562,
    1563,  1086,  1087,     0,     0,     0,     0,  1569,     0,  1571,
    1098,   464,     0,     0,     0,     0,  1574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
       0,     0,     0,     0,  1590,     0,     0,     0,     0,     0,
       0,     0,  1595,  1596,  1597,     0,     0,     0,     0,     0,
       0,     0,     0,  1607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1619,     0,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,  1636,
       0,     0,     0,     0,     0,  1645,  1646,     0,     0,     0,
       0,  1568,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1187,  1189,  1190,     0,     0,
       0,  1194,  1195,     0,  1669,  1198,  1199,  1200,  1201,     0,
    1203,     0,     0,     0,     0,  1209,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,  1681,
    1682,  1683,     0,     0,     0,     0,     0,     0,     0,     0,
    1684,     0,     0,     0,     0,  1687,  1688,  1689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1696,     0,
       0,     0,     0,   463,   463,  1702,     0,  1703,     0,     0,
       0,     0,     0,  1711,  1712,     0,     0,     0,     0,     0,
       0,  1288,  1289,     0,     0,   464,     0,     0,     0,     0,
       0,     0,   463,     0,     0,     0,  1730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1740,     0,
       0,  1743,     0,     0,     0,  1745,     0,     0,     0,     0,
       0,     0,     0,     0,  1688,  1689,     0,  1754,     0,     0,
       0,     0,     0,     0,     0,  1759,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1772,     0,     0,     0,     0,  1778,  1779,     0,     0,
       0,     0,     0,     0,     0,     0,  1781,     0,     0,  1782,
    1781,     0,     0,  1343,     0,     0,     0,     0,     0,     0,
    1670,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,  1803,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1813,     0,     0,     0,     0,
       0,     0,     0,     0,  1822,     0,     0,   152,   349,     0,
       0,     0,     0,   517,     0,     0,     0,     0,     0,     0,
       0,     0,  1833,  1834,     0,     0,   463,     0,     0,   464,
     464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   464,     0,
    1858,  1859,   359,   360,   361,   362,     0,     0,     0,     0,
     363,   364,   365,     0,     0,   366,  1871,   367,     0,  1874,
       0,     0,     0,     0,  1877,     0,     0,  1879,   368,  1622,
       0,   369,  1453,     0,     0,     0,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   463,     0,     0,     0,     0,     0,     0,     0,  1905,
       0,     0,     0,     0,     0,     0,     0,  1485,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1916,     0,     0,     0,     0,     0,
    1921,     0,     0,  1922,     0,  1517,  1518,  1519,  1520,  1521,
     157,   158,     0,     0,  1526,  1527,     0,  1529,     0,  1531,
       0,     0,     0,  1535,     0,     0,  1537,  1626,     0,  1943,
       0,     0,     0,     0,     0,     0,     0,     0,  1545,     0,
       0,     0,     0,     0,     0,     0,   370,   371,   372,   518,
       0,     0,     0,     0,  1961,  1962,     0,   373,     0,     0,
       0,   374,   464,   375,   108,     0,  1968,  1969,  1632,  1970,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1978,     0,     0,     0,     0,   463,   463,   463,
     463,   463,  1731,     0,     0,     0,  1638,  1778,     0,     0,
       0,  1994,     0,     0,     0,     0,  1602,     0,  1605,     0,
       0,     0,  1612,     0,  1614,     0,     0,     0,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,  2014,     0,
       0,     0,   464,  2017,  2018,  2019,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   463,   464,  1639,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,  2047,  2048,  2049,     0,     0,     0,
       0,     0,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   494,   495,   496,   497,   498,
     499,     0,   501,   502,     0,     0,     0,     0,   504,   505,
       0,     0,     0,     0,     0,     0,     0,     0,   510,   511,
       0,     0,     0,     0,     0,  1690,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   464,   464,   464,   464,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,   464,     0,  1769,     0,     0,  1770,   634,   635,
     636,     0,     0,     0,   640,   641,   642,   643,   644,   645,
     646,     0,   647,     0,     0,     0,   648,   649,     0,     0,
     652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   662,     0,  1795,  1796,     0,  1798,     0,
       0,   189,   152,     0,     0,     0,     0,     0,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     385,   211,   212,   213,   214,   215,   216,  1810,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,  1839,  1840,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,     0,     0,
       0,   230,    21,     0,   231,     0,     0,     0,     0,     0,
     189,     6,   349,     0,     0,     0,     0,   190,   191,   192,
       0,  1870,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,   816,  1486,   351,   352,   353,   354,   355,   356,
     357,   358,   222,   223,   224,   225,   359,   360,   361,   362,
     226,     0,     0,     0,   363,   364,   365,     0,     0,   366,
       0,   367,   227,   228,   229,     0,     0,     0,     0,     0,
     230,    21,   368,   231,     0,   369,     0,     0,   232,     0,
       0,   233,     0,     0,   234,     0,   235,     0,     0,     0,
     239,     0,     0,    37,   240,     0,     0,    41,     0,   242,
     243,   244,     0,   245,   246,   247,   236,     0,    50,   108,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,   248,   386,    66,    67,    68,
      69,    70,   250,     0,     0,    74,     0,   331,    77,     0,
       0,   567,     0,     0,   253,     0,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,  1836,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     370,   371,   372,   240,   241,     0,     0,     0,   242,   243,
     244,   373,   245,   246,   247,   374,     0,   375,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   331,   189,     6,   349,
    1487,     0,  2036,   253,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   222,
     223,   224,   225,   359,   360,   361,   362,   226,     0,     0,
       0,   363,   364,   365,     0,     0,   366,     0,   367,   227,
     228,   229,     0,     0,     0,     0,     0,   230,    21,   368,
     231,     0,   369,     0,     0,   232,     0,     0,   233,  1093,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,    50,     0,     0,   237,     0,
     238,     0,  1109,  1848,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,    74,     0,     0,    77,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,  1955,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   370,   371,   372,
     240,   241,  2001,     0,     0,   242,   243,   244,   373,   245,
     246,   247,   374,     0,   375,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,   331,     0,     0,     0,   252,     0,     0,
     253,     0,     0,     0,     0,     0,     0,   189,   152,   349,
       0,   398,     0,     0,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   385,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,  1283,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   222,
     223,   224,   225,   359,   360,   361,   362,   226,     0,     0,
       0,   363,   364,   365,     0,     0,   366,     0,   367,   227,
     228,   229,     0,     0,     0,     0,     0,   230,    21,   368,
     231,     0,   369,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     399,     0,     0,     0,     0,  1332,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,   239,   370,   371,   372,
     240,     0,     0,     0,     0,   242,   243,   244,   373,   245,
     246,   247,   374,     0,   375,   108,   401,   402,   403,   404,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   386,     0,     0,     0,     0,     0,   250,     0,
     405,   406,     0,   407,     0,   408,   189,     6,   330,   409,
     253,     0,     0,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,  1454,  1455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,     0,     0,     7,     8,     0,   230,    21,     0,   231,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    50,  1533,     0,   237,     0,   238,
       0,     0,     0,     0,     0,  1541,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,     0,     0,     0,     0,     0,   703,
      49,     0,     0,    51,   704,   239,    54,   705,     0,   240,
     241,     0,     0,     0,   242,   243,   244,     0,   245,   246,
     247,     0,     0,     0,   108,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,     0,     0,     0,     0,     0,   250,     0,    85,
      86,    87,   331,   189,     6,  1577,   252,     0,     0,   253,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,  1667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   878,   227,   228,   229,     0,     0,
       7,     8,     0,   230,    21,     0,   231,     0,     0,     0,
       0,   232,     0,     0,   233,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    50,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,     0,     0,
      66,    67,    68,    69,    70,     0,     0,     0,    74,     0,
       0,    77,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,    41,     0,     0,
      43,     0,     0,     0,     0,     0,   703,    49,     0,     0,
      51,   704,   239,    54,   705,     0,   240,   241,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   108,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     0,     0,     0,   250,     0,    85,    86,    87,   331,
     189,     6,     0,   252,     0,     0,   253,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   900,   227,   228,   229,     0,     0,     7,     8,     0,
     230,    21,     0,   231,     0,     0,     0,     0,   232,     0,
       0,   233,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,    50,     0,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,     0,     0,
       0,     0,     0,   703,    49,     0,     0,    51,   704,   239,
      54,   705,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   108,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   585,  1726,     0,     0,     0,     0,
       0,   250,     0,    85,    86,    87,   587,   189,     6,     0,
     293,   521,     0,   253,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   945,   227,
     228,   229,     0,     0,     7,     8,     0,   230,    21,     0,
     231,     0,     0,     0,     0,   232,     0,     0,   233,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,    50,     0,     0,   237,     0,
     238,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,    74,     0,     0,    77,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,    41,     0,     0,    43,     0,     0,     0,     0,     0,
     703,    49,     0,     0,    51,   704,   239,    54,   705,     0,
     240,   241,     0,     0,     0,   242,   243,   244,     0,   245,
     246,   247,     0,     0,     0,   108,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,     0,     0,   250,     0,
      85,    86,    87,   251,   189,     6,     0,   252,     0,     0,
     253,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   946,   227,   228,   229,     0,
       0,     7,     8,     0,   230,    21,     0,   231,     0,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,    50,     0,     0,   237,     0,   238,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,     0,     0,     0,     0,     0,   703,    49,     0,
       0,    51,   704,   239,    54,   705,     0,   240,   241,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
       0,     0,     0,     0,     0,   250,     0,    85,    86,    87,
     331,   189,     6,     0,   252,     0,     0,   253,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1130,   227,   228,   229,     0,     0,     7,     8,
       0,   230,    21,     0,   231,     0,     0,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    50,
       0,     0,   237,     0,   238,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,     0,     0,    66,    67,
      68,    69,    70,     0,     0,     0,    74,     0,     0,    77,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,    41,     0,     0,    43,     0,
       0,     0,     0,     0,   703,    49,     0,     0,    51,   704,
     239,    54,   705,     0,   240,   241,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   108,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   462,     0,     0,     0,
       0,     0,   250,     0,    85,    86,    87,   331,   189,     6,
       0,   516,     0,     0,   253,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1132,
     227,   228,   229,     0,     0,     7,     8,     0,   230,    21,
       0,   231,     0,     0,     0,     0,   232,     0,     0,   233,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,    50,     0,     0,   237,
       0,   238,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,    41,     0,     0,    43,     0,     0,     0,     0,
       0,   703,    49,     0,     0,    51,   704,   239,    54,   705,
       0,   240,   241,     0,     0,     0,   242,   243,   244,     0,
     245,   246,   247,     0,     0,     0,   108,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   462,     0,     0,     0,     0,     0,   250,
       0,    85,    86,    87,   331,   189,     6,     0,     0,   521,
       0,   253,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1133,   227,   228,   229,
       0,     0,     7,     8,     0,   230,    21,     0,   231,     0,
       0,     0,     0,   232,     0,     0,   233,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    50,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
      74,     0,     0,    77,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,   703,    49,
       0,     0,    51,   704,   239,    54,   705,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   108,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     0,     0,   250,     0,    85,    86,
      87,   557,   189,     6,     0,   252,     0,     0,   253,   190,
     191,   192,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1152,   227,   228,   229,     0,     0,     7,
       8,     0,   230,    21,     0,   231,     0,     0,     0,     0,
     232,     0,     0,   233,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
      50,     0,     0,   237,     0,   238,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,     0,     0,     0,   703,    49,     0,     0,    51,
     704,   239,    54,   705,     0,   240,   241,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     108,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,   250,     0,    85,    86,    87,   564,   189,
       6,     0,   252,     0,     0,   253,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1182,   227,   228,   229,     0,     0,     7,     8,     0,   230,
      21,     0,   231,     0,     0,     0,     0,   232,     0,     0,
     233,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,    50,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,    41,     0,     0,    43,     0,     0,     0,
       0,     0,   703,    49,     0,     0,    51,   704,   239,    54,
     705,     0,   240,   241,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   108,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   462,     0,     0,     0,     0,     0,
     250,     0,    85,    86,    87,   331,   189,     6,     0,   832,
       0,     0,   253,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1215,   227,   228,
     229,     0,     0,     7,     8,     0,   230,    21,     0,   231,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    50,     0,     0,   237,     0,   238,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,     0,     0,     0,     0,     0,   703,
      49,     0,     0,    51,   704,   239,    54,   705,     0,   240,
     241,     0,     0,     0,   242,   243,   244,     0,   245,   246,
     247,     0,     0,     0,   108,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,     0,     0,     0,     0,     0,   250,     0,    85,
      86,    87,   331,   189,     6,     0,  1585,     0,     0,   253,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1360,   227,   228,   229,     0,     0,
       7,     8,     0,   230,    21,     0,   231,     0,     0,     0,
       0,   232,     0,     0,   233,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    50,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,     0,     0,
      66,    67,    68,    69,    70,     0,     0,     0,    74,     0,
       0,    77,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,    41,     0,     0,
      43,   527,     0,     0,     0,     0,   703,    49,     0,     0,
      51,   704,   239,    54,   705,     0,   240,   241,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   108,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   585,  1726,     0,
       0,     0,     0,     0,   250,     0,    85,    86,    87,   587,
     189,     6,     0,   293,     0,     0,   253,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1946,   227,   228,   229,     0,     0,     0,     0,     0,
     230,    21,     0,   231,     0,     0,     0,     0,   232,     0,
       0,   233,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,    50,     0,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   462,     0,     0,     0,     0,
       0,   250,   189,   152,   349,     0,   331,     0,     0,   190,
     191,   192,     0,   253,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   385,   211,   212,   213,   214,   215,   216,   527,     0,
       0,     0,     0,     0,     0,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   222,   223,   224,   225,   359,   360,
     361,   362,   226,     0,     0,     0,   363,   364,   365,     0,
       0,   366,     0,   367,   227,   228,   229,     0,     0,     0,
       0,     0,   230,    21,   368,   231,     0,   369,   189,   152,
     349,     0,     0,     0,     0,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   385,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     222,   223,   224,   225,   359,   360,   361,   362,   226,     0,
       0,     0,   363,   364,   365,     0,     0,   366,     0,   367,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
     368,   231,     0,   369,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   370,   371,   372,   240,     0,     0,     0,     0,
     242,   243,   244,   373,   245,   246,   247,   374,     0,   375,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   386,     0,     0,
       0,     0,     0,   250,     0,     0,     0,     0,   331,     0,
       0,     0,  1482,     0,     0,   253,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   757,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   370,   371,
     372,   240,     0,     0,     0,     0,   242,   243,   244,   373,
     245,   246,   247,   374,     0,   375,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   386,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   331,   189,   152,   349,  1739,     0,
       0,   253,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   385,   211,   212,   213,   214,   215,
     216,   917,     0,     0,     0,     0,     0,     0,  1486,   351,
     352,   353,   354,   355,   356,   357,   358,   222,   223,   224,
     225,   359,   360,   361,   362,   226,     0,     0,     0,   363,
     364,   365,     0,     0,   366,     0,   367,   227,   228,   229,
       0,     0,     0,     0,     0,   230,    21,   368,   231,     0,
     369,   189,   152,   349,     0,     0,     0,     0,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     385,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   222,   223,   224,   225,   359,   360,   361,
     362,   226,     0,     0,     0,   363,   364,   365,     0,     0,
     366,     0,   367,   227,   228,   229,     0,     0,     0,     0,
       0,   230,    21,   368,   231,     0,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   370,   371,   372,   240,     0,
       0,     0,     0,   242,   243,   244,   373,   245,   246,   247,
     374,     0,   375,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     386,     0,     0,     0,     0,     0,   250,     0,     0,     0,
       0,   331,     0,     0,     0,  1638,     0,     0,   253,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,  1100,     0,     0,     0,
     239,   370,   371,   372,   240,     0,     0,     0,     0,   242,
     243,   244,   373,   245,   246,   247,   374,     0,   375,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   386,     0,     0,     0,
       0,     0,   250,   189,   152,     0,     0,   331,     0,     0,
     190,   191,   192,     0,   253,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   385,   211,   212,   213,   214,   215,   216,     0,
    1101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,     0,     0,
     189,   152,     0,   230,    21,     0,   231,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   385,
     211,   212,   213,   214,   215,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,     0,     0,     0,
     230,    21,     0,   231,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,   239,     0,     0,     0,   240,     0,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   585,   586,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,   587,
       0,     0,     0,   293,     0,     0,   253,     0,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,   239,
     546,     0,  1406,   240,     0,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   386,     0,     0,     0,     0,
       0,   250,   189,   152,     0,  1223,   331,  1008,     0,   190,
     191,   192,     0,   253,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   385,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,     0,     0,     0,
       0,     0,   230,    21,     0,   231,   189,   152,     0,  1368,
       0,     0,     0,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   385,   211,   212,   213,   214,
     215,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,     0,     0,     0,     0,     0,   230,    21,     0,   231,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,   239,   546,     0,     0,   240,     0,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   386,     0,     0,
       0,     0,     0,   250,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,   253,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     909,     0,     0,     0,     0,   239,     0,     0,   870,   240,
       0,     0,     0,     0,   242,   243,   244,     0,   245,   246,
     247,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   386,     0,     0,     0,     0,     0,   250,   189,   152,
       0,  1429,   331,     0,     0,   190,   191,   192,     0,   253,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   385,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,     0,     0,   189,   152,     0,   230,    21,
       0,   231,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   385,   211,   212,   213,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
       0,     0,     0,     0,     0,   230,    21,     0,   231,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,   239,  1707,     0,
       0,   240,  1708,     0,     0,     0,   242,   243,   244,     0,
     245,   246,   247,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   386,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,   253,     0,     0,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,   239,     0,   546,     0,   240,     0,
       0,     0,  1734,   242,   243,   244,  1735,   245,   246,   247,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     386,     0,     0,     0,     0,     0,   250,   189,   152,     0,
       0,   331,  1481,     0,   190,   191,   192,     0,   253,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   385,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,     0,     0,   189,   152,     0,   230,    21,     0,
     231,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   385,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,     0,     0,     0,   230,    21,     0,   231,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,   239,  1891,     0,     0,
     240,  1892,     0,     0,     0,   242,   243,   244,     0,   245,
     246,   247,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   386,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,   331,  1783,     0,     0,     0,     0,     0,
     253,     7,     8,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,   239,     0,   546,     0,   240,     0,     0,
       0,     0,   242,   243,   244,   718,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   386,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,   253,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,     0,     0,     0,     0,     0,   703,    49,     0,
       0,    51,   704,     0,    54,   705,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    71,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,    85,    86,    87,
       0,     0,    -4,    -4,     0,     0,   870,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,     0,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,  2003,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,     9,    10,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,     0,    17,    18,     0,
      19,    20,     0,    21,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,    37,    38,    39,    40,    41,
      42,     0,    43,     0,    44,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    80,    81,    82,     0,
       0,     0,    83,     0,     0,     0,     0,    84,    85,    86,
      87,   152,   349,    88,     0,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   152,   349,     0,     0,     0,     0,     0,   107,     0,
     108,     0,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,   360,   361,   362,
       0,   379,   349,     0,   363,   364,   365,     0,     0,   366,
       0,   367,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   368,     0,     0,   369,   359,   360,   361,   362,
       0,     0,   349,     0,   363,   364,   365,     0,     0,   366,
       0,   367,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   368,     0,     0,   369,   359,   360,   361,   362,
       0,     0,     0,   399,   363,   364,   365,     0,     0,   366,
       0,   367,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   368,     0,     0,   369,   359,   360,   361,   362,
       0,     0,     0,     0,   363,   364,   365,     0,     0,   366,
       0,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   368,     0,     0,   369,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     0,     0,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     0,   374,     0,   375,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     7,     8,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     0,   374,     0,   375,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     0,     0,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     0,   374,     0,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     0,     0,     0,     0,     0,     7,     8,
       0,   373,     0,     0,     0,   374,     0,   375,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,     0,     0,     0,     0,     0,   703,
      49,     0,     0,    51,   704,     0,    54,   705,     0,     0,
       0,     0,   955,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,   956,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    85,
      86,    87,    38,    39,    40,    41,     0,     0,    43,     0,
       0,     0,     0,     0,   703,    49,     0,     0,    51,   704,
       0,    54,   705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,    85,    86,    87,     0,     0,     0,
       0,     0,     0,   871,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   914,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1055,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1065,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1066,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1067,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1072,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1073,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1075,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1176,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1197,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1279,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1362,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1363,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1405,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1522,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1523,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1524,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1538,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1662,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1773,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1774,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1797,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1800,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1866,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1917,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1918,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1930,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1932,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1964,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1991,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1996,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1997,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1998,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2037,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,   754,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,   990,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1042,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1083,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1124,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  1155,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1173,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  1229,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1364,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1435,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1436,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1437,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1438,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1705,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1716,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  1753,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1816,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  1831,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1843,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1880,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1897,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1906,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1907,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1928,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1977,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  2016,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  2035,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  2055,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  2056,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  2057,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,   665,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,   862,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,  1809,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,   690,     0,   691,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,   920,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
     969,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,  1105,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,  1168,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,  1169,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,  1174,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,  1175,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,  1265,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,  1276,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,  1467,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,  1544,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
    1591,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,  1765,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,  1802,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,  1817,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   735,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   736,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   737,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   739,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   740,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   741,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   743,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   744,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   745,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   746,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   747,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   748,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   749,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   751,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   752,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   753,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   813,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   847,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   891,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   909,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   910,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   911,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   912,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   918,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   919,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   954,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   968,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1022,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1026,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1038,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1104,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1113,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1114,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1115,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1125,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1154,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1156,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1157,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1158,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1159,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1160,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1161,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1162,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1167,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1264,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1275,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1468,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1530,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1543,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1653,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1655,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1656,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1661,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1706,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1715,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1738,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1801,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1864,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1865,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1990,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  2032,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546
};

static const yytype_int16 yycheck[] =
{
       3,   286,     3,   134,   147,   582,   583,  1153,   669,  1149,
    1327,   298,  1579,   685,     4,  1621,     3,  1623,    21,     4,
      48,   693,     5,    21,     5,     4,     4,     4,     4,   316,
       5,  1784,   149,     7,   187,    99,     4,   101,     4,   700,
       4,     4,  1608,   243,     6,    48,     9,   247,     6,     6,
       6,     4,     4,    54,   715,    94,     4,   174,    97,     4,
       4,     6,   723,     6,    97,     6,     0,     6,    97,     9,
     134,   110,    75,   190,   191,     4,     4,   129,   240,    94,
      83,    91,    97,   245,    94,    88,   119,    97,     9,     9,
     119,     4,    14,   157,   146,   382,    99,   384,     9,     9,
     110,  1667,   154,   155,   156,   392,   240,     7,   160,   161,
     239,     6,     9,  1680,   248,     7,    84,   239,   271,   272,
     273,   243,   227,   228,   227,   228,   227,   228,   242,     6,
      97,   134,   227,   228,   248,   101,   139,   140,   227,   228,
       6,   239,     6,   248,   147,   248,    91,   248,   135,   227,
     228,   179,     6,   248,   815,   158,   309,   310,   311,   248,
      61,    62,     6,    64,     7,   227,   228,   227,   228,     7,
     248,   174,  1925,   326,   227,   228,   179,   236,   237,   182,
     227,   228,   244,   243,   187,   188,   164,   165,   166,   167,
     243,   242,   244,   227,   228,     7,   240,   248,   174,   175,
     162,   248,   177,     7,   248,   162,   227,   228,   236,     7,
     174,   175,   189,     6,   248,   227,   228,   185,  1535,     6,
     133,   134,   135,   136,     6,   134,   211,   248,   227,   228,
     139,   140,   211,   236,   239,   148,   248,   238,   151,  1806,
    1380,     6,   270,   211,   243,   239,   249,   241,   211,   252,
     253,   241,   280,   241,   248,   253,   284,   247,   211,   211,
     243,   246,   243,   211,   267,   174,   244,   270,   271,   272,
     273,   245,   241,   236,   237,   243,   239,   280,   241,   188,
     243,   284,   245,   286,   571,   243,   573,   574,   227,   228,
     243,   243,   240,  1860,   242,   239,   968,   969,   239,   239,
     243,   241,   243,   590,   239,   245,   309,   310,   311,     8,
     239,   239,   212,   213,   214,   215,   236,   237,   239,   239,
     241,   241,   242,   326,   245,   245,   236,   237,   239,   239,
     241,   241,   227,   228,   398,   245,   236,   237,   243,   236,
     237,   628,   239,   239,   241,   245,     4,   239,   245,   241,
     227,   228,  1958,   240,   239,   508,   222,   223,   222,   223,
     503,   248,   227,   228,   227,   228,   394,   395,   239,   212,
     213,   214,   215,   240,   212,   213,   214,   215,   665,   239,
     239,   248,   410,   248,   243,   248,   389,   390,   289,   290,
     239,   394,   395,   236,   237,   112,   297,   298,   236,   237,
     212,   213,   214,   215,   240,   239,   242,   410,   212,   213,
     214,   215,   248,   416,   212,   213,   214,   215,   239,   420,
     227,   228,   236,   237,   236,   237,  1993,    97,  1089,   243,
    1091,   129,    91,    91,   437,    94,   245,    95,    97,   248,
      99,   248,  1103,   101,   102,   239,   104,   105,   146,   513,
     227,   228,   227,   228,   227,   228,   154,   155,   156,   462,
     129,   240,   160,   161,     6,   123,   240,   227,   228,   248,
     239,   248,   500,   248,   248,   248,   240,   146,  2045,   507,
     389,  1798,   485,   239,   248,   154,   155,   156,   248,   492,
     493,   160,   161,   636,   497,   239,   499,   500,   501,   502,
     503,   239,   505,   241,   507,   508,   509,   510,   511,   512,
     239,   514,   241,   516,   512,   239,   514,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   227,   228,    94,   541,   238,
      97,   129,    99,   244,   547,   244,   244,   248,   244,  1210,
     227,   228,   248,   110,   685,  1216,   248,   239,   146,   227,
     228,   227,   228,   566,   567,   239,   154,   155,   156,   236,
     237,   248,   160,   161,   239,   244,   227,   228,   245,   866,
     248,    94,   248,   243,    97,   649,    99,   588,   497,   129,
     499,   239,   501,   502,   243,   582,   583,   248,   236,   237,
     509,   510,  1263,   244,    97,   243,   146,   248,   609,   612,
     613,   614,   239,  1274,   154,   155,   156,   232,   233,  1280,
     160,   161,   240,   238,   242,   239,   245,   241,   247,   243,
     248,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     243,   644,   645,   646,   647,   648,   243,   650,   651,   652,
     653,   654,   227,   228,   657,   653,   244,   244,   659,    91,
     661,   248,    94,   666,   239,    97,   239,    99,   243,   240,
     734,   242,   673,    97,   227,   228,    94,   248,   110,   580,
     581,  1353,   133,   134,   585,   240,   239,   242,   139,   692,
     243,     6,     7,   248,   697,   227,   228,   229,   230,   231,
     232,   233,   240,   239,   242,   241,   238,   243,   711,   712,
     248,    94,   843,   239,   717,   241,   244,   720,   721,   245,
     248,     4,   248,   726,    94,   728,   635,     4,   637,   638,
     639,   640,   641,   642,    97,   644,   645,   646,   647,     6,
       7,   650,   651,   652,   229,   230,   231,   232,   233,   133,
     134,     4,     4,   238,   757,   139,   759,   244,   244,   239,
     244,   248,   248,   244,   248,   239,   244,   248,   244,  1441,
     248,   244,   248,   244,   244,   248,   244,   248,   248,   244,
     248,  1453,   244,   248,   239,   244,   248,   244,   791,   248,
     244,   248,   856,     6,   248,   244,   244,   239,   244,   248,
     248,  1947,   248,   244,   244,   244,   244,   248,   248,   248,
     248,   720,   239,   244,   244,     6,   244,   248,   248,   728,
     248,     6,   244,   244,   244,   853,   248,   248,   248,   832,
     244,   244,   244,   241,   248,   248,   248,   968,   969,  1979,
     244,   244,   845,   244,   248,   248,   239,   248,   244,   244,
     853,   241,   248,   248,   243,     4,     5,   244,  2004,   862,
     240,   248,   242,   243,   865,   244,   867,   868,   244,   248,
     244,   244,   248,     6,   248,   248,   240,   243,   242,   243,
     881,    97,  2022,    99,   240,   239,   242,   241,   239,   239,
     241,   241,   239,   182,   241,   227,   228,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   970,     4,   247,     6,
      59,    60,    61,    62,   915,   239,   247,     9,    67,    68,
      69,   239,   239,    72,   243,    74,   239,   239,   239,   243,
     119,   239,   960,   239,   239,   239,    85,   239,   239,    88,
     243,     4,     6,   243,   243,   243,   243,   243,   949,   239,
     241,   979,   239,   239,   239,   239,     6,   960,   239,   239,
    1245,   239,     6,     6,   243,     6,   241,   243,   869,   243,
     243,   974,   241,  1104,  1105,   876,   979,   126,   267,   880,
     241,   243,   177,   239,   239,   239,   989,  1564,  1565,   239,
     239,   994,  1020,  1021,   239,  1023,  1024,  1025,   241,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,     6,
       6,   243,     6,     6,   243,     7,     6,  1020,  1021,   243,
    1023,  1024,  1025,     6,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,   243,    87,  1039,   244,   248,   240,
     248,     7,     6,   240,   193,   194,   195,   243,   238,  1077,
      64,   245,     4,     7,     7,   204,   239,     6,   240,   208,
       6,   210,   211,   243,     7,     6,   174,     7,  1096,     6,
       6,   243,   242,   240,  1077,  1078,  1079,     6,   243,   243,
     243,   243,     7,  1111,   245,   994,     6,   236,   237,   241,
     243,   239,     4,  1096,   243,     6,   245,     6,     6,     6,
     240,   390,   241,     7,     7,     7,     7,     7,  1111,  1112,
       7,     7,     7,     7,     7,     7,     7,     7,  1019,     7,
       7,     7,   243,     6,   240,   242,   248,   240,   248,   248,
    1131,     7,   243,  1264,  1265,  1163,   248,     7,   245,   243,
       4,  1428,   245,     6,   244,  1432,   244,   129,     7,  1177,
    1178,  1179,     6,   240,     7,     7,     7,   245,   240,   248,
    1163,     9,   248,  1448,   248,   240,   242,   245,   247,  1078,
    1079,   177,     7,   149,  1177,  1178,  1179,   244,   243,     6,
       6,     4,   239,   245,    46,  1188,    46,   245,   239,   245,
    1193,   239,   239,     4,  1197,     7,   109,     7,  1226,     7,
     240,     7,   248,  1206,     7,  1208,     7,     6,  1211,   240,
     248,     7,     7,     7,     4,     4,   243,   239,  1282,  1220,
    1284,     6,     6,  1226,     7,     7,     7,   516,     7,     7,
       7,     7,     7,   243,     6,  1812,     6,     6,     6,    97,
       7,     6,  1245,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,  1284,     4,     4,   246,
     238,   240,  1265,   248,   248,  1293,   243,     6,   243,  1297,
     243,     6,   244,     6,   241,     7,     6,   566,   567,     6,
     239,  1284,   239,   243,  1193,     6,     6,   245,  1197,     6,
    1293,   242,   248,     6,  1297,     6,     6,  1206,   123,  1208,
       6,     6,  1211,   177,     6,     6,     6,     6,     6,     6,
    1441,  1454,  1455,     6,     6,     6,     5,   240,   240,  1347,
    1348,  1349,     6,   612,   613,   614,     4,  1355,     4,     6,
     173,     6,     6,   243,     7,     6,     6,   243,   243,     6,
       6,     6,  1370,   241,  1347,  1348,  1349,     6,     6,   248,
    1635,     7,  1355,  1381,   243,     4,  1265,   239,   243,   243,
    1424,  1389,   243,   243,   243,   243,   243,  1370,   657,   240,
     243,     6,     6,   248,   243,     6,   248,     4,  1381,   245,
     248,     7,   243,   239,   239,     6,  1389,     6,     6,  1392,
       6,    95,     6,     5,   243,   240,   243,     6,   248,     6,
       6,     6,   248,   692,     6,     6,   248,   240,   248,     6,
       4,  1542,   248,     6,     6,   243,     6,     5,  1482,   243,
       7,   243,   711,   240,   243,     6,     6,     6,   717,   243,
       6,   244,  1460,     7,     6,   244,   243,     6,   172,   244,
     240,     6,   244,     7,     6,  1448,   244,     6,   245,     6,
       6,  1454,  1455,     6,  1482,   243,     6,  1460,   244,     6,
     240,     6,     6,   175,     6,     6,     6,     6,   129,   243,
     243,  1474,     6,   244,     6,     6,   239,   243,  1379,  1482,
     244,   240,   243,   243,  1487,     6,   244,   243,   243,   240,
       6,     6,   244,     6,   244,  1638,  1560,     6,     6,     6,
       6,     6,   791,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,     6,
    1651,   243,     6,   238,   243,  1553,     6,     6,     6,   243,
       6,     6,     6,     6,  1821,  1960,  1273,  1601,  1322,  1785,
    1750,  1492,  1549,   832,  1608,  1609,  1292,     3,   705,     3,
    1553,  1579,     3,  1556,  1557,     3,   845,   561,  1808,  1421,
       3,  1631,  1608,  1627,  1849,  1474,  1594,   434,    -1,  1455,
     720,    -1,    -1,   862,    -1,    -1,  1579,  1564,  1565,    -1,
      -1,    -1,  1585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1594,    -1,    -1,    -1,  1496,  1624,    -1,    -1,    -1,
    1603,    -1,    -1,  1606,    -1,    -1,    -1,    -1,    -1,  1637,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1621,  1624,  1623,    -1,  1911,    -1,    -1,    -1,  1631,    -1,
      -1,    -1,  1635,    -1,  1637,  1638,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,  1680,    -1,    -1,     8,   238,    -1,    -1,    -1,
      -1,  1948,    -1,    -1,  1667,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1680,    -1,  1580,
    1581,  1582,  1583,  1584,  1585,    -1,  1714,    -1,  1752,    -1,
       6,    -1,    -1,    -1,  1603,    -1,    -1,  1606,    -1,    -1,
     989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1726,    -1,    -1,  1790,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1739,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1776,    -1,
    1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1776,    -1,    -1,    -1,    -1,  1806,    -1,
      -1,    -1,    -1,  1786,    -1,    -1,    -1,    -1,  1791,    -1,
      -1,    -1,  1820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1806,    -1,    -1,  1809,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,  1824,    -1,  1112,    -1,  1812,    -1,    -1,    -1,    -1,
      -1,    -1,  1860,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1849,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1884,  1860,    -1,    -1,
      -1,    -1,  1926,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,  1884,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,  1896,     8,    -1,    -1,  1188,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,  1825,  1826,  1827,  1828,  1829,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1950,  1951,  1952,
    1953,  1954,    -1,    -1,    -1,    -1,    -1,  1958,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1993,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1980,
      -1,    -1,  1883,    -1,    -1,    -1,  1887,    -1,    -1,    -1,
    1993,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,   107,    -1,  2009,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2045,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2031,    -1,
      -1,   134,    -1,  1934,    -1,   138,    -1,  1938,     7,   142,
      -1,    -1,  2045,    -1,    -1,    -1,    -1,    -1,    -1,  2052,
    2053,    -1,    -1,  1954,    -1,    -1,   159,   160,   161,    -1,
     163,   164,   165,  2066,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,   176,   177,   178,    -1,    -1,    -1,   182,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,  1999,  2000,
      -1,    -1,   238,  1392,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,  2031,    -1,    -1,    -1,   238,    -1,   240,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2052,  2053,   248,   249,   250,   251,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2066,    -1,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,
     293,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,   331,   238,
      -1,   240,   335,   336,   337,    -1,   339,    -1,    -1,    -1,
     343,   344,   345,    -1,    -1,   348,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   182,    -1,  1556,  1557,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   386,    -1,    -1,    -1,   390,   391,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,   462,
      -1,    -1,    -1,   466,    -1,    -1,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,    -1,   495,   496,    -1,   498,    -1,    -1,    -1,    -1,
      -1,   504,    -1,   506,    -1,    -1,    -1,    -1,   511,    -1,
      -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,    -1,   548,   549,    -1,    -1,    -1,
    1739,    -1,   555,   556,   557,    -1,    -1,     6,    -1,    -1,
     563,   564,    -1,   566,   567,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,   586,   587,    -1,    -1,    -1,   591,   592,
     593,   594,   595,   596,   597,   598,   599,    -1,    -1,    -1,
      -1,   604,    -1,   606,    -1,   608,    -1,    -1,    -1,   612,
     613,   614,   615,    -1,   617,   618,   619,    -1,    -1,    -1,
    1809,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,
     643,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   657,    -1,    -1,    -1,    -1,   662,
      -1,   664,    -1,    -1,   667,   668,    -1,    -1,   485,    -1,
      -1,    -1,    -1,   676,    -1,   492,   493,    -1,    -1,   682,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   692,
      -1,    -1,    -1,    -1,   511,   698,   699,    -1,    -1,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   711,    -1,
     713,   714,    -1,    -1,   717,   718,    -1,    -1,    -1,   722,
      -1,    -1,    -1,    -1,   541,    -1,   729,    -1,    -1,    -1,
     733,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   566,
     567,    -1,   755,   238,   757,    -1,   759,    -1,    -1,    -1,
      -1,  1950,  1951,  1952,  1953,  1954,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,   791,   238,
      -1,    -1,    -1,    -1,    -1,   612,   613,   614,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
    2009,   238,    -1,   240,    -1,   242,    -1,    -1,    -1,   832,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     657,    -1,   845,    -1,    -1,    -1,    -1,    -1,    -1,   852,
      -1,    -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,   862,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   870,   871,    -1,
      -1,    -1,    -1,   876,    -1,   692,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   892,
      -1,    -1,   895,    -1,   711,    -1,    -1,    -1,    -1,    -1,
     717,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   914,    -1,   916,   917,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     757,    -1,   759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   956,    -1,    -1,     4,     5,    -1,    -1,
     963,   964,   965,   966,    -1,    -1,   412,    -1,   971,    -1,
      -1,    -1,    -1,    -1,   791,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   985,   986,    -1,    -1,   989,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,   832,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,     6,   845,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1039,    85,    -1,    -1,
      88,    -1,    -1,    -1,    -1,   862,    -1,    -1,    -1,    -1,
      -1,    -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,   505,
      -1,    -1,  1065,  1066,  1067,    -1,    -1,    -1,    -1,  1072,
    1073,    -1,  1075,    -1,    -1,    -1,    -1,    -1,   126,    -1,
      -1,  1084,  1085,    -1,    -1,    -1,    -1,    -1,    -1,  1092,
    1093,    -1,    -1,    -1,    -1,    -1,  1099,  1100,  1101,    -1,
      -1,    -1,    -1,    -1,  1107,  1108,   552,    -1,    -1,  1112,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
    1143,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
     208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   989,  1176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1188,    -1,    -1,    -1,    -1,
      -1,    -1,   240,  1196,   242,   243,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,  1217,  1218,     6,    -1,   238,  1222,
      -1,    -1,  1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1236,    -1,    -1,  1239,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,  1266,    -1,    -1,  1269,  1270,    -1,    -1,
      -1,    -1,    -1,    -1,  1277,    -1,  1279,    -1,  1281,  1282,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,   773,    -1,   775,
     776,   777,   778,    -1,   780,   781,   782,   783,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   794,    -1,
     796,  1354,    -1,    -1,    -1,    -1,    -1,   803,  1361,  1362,
    1363,   807,   808,    -1,    -1,    -1,    -1,  1370,    -1,  1372,
     816,  1188,    -1,    -1,    -1,    -1,  1379,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1392,
      -1,    -1,    -1,    -1,  1397,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1405,  1406,  1407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1426,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,  1452,
      -1,    -1,    -1,    -1,    -1,  1458,  1459,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   921,   922,   923,    -1,    -1,
      -1,   927,   928,    -1,  1487,   931,   932,   933,   934,    -1,
     936,    -1,    -1,    -1,    -1,   941,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,  1522,
    1523,  1524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1533,    -1,    -1,    -1,    -1,  1538,  1539,  1540,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1551,    -1,
      -1,    -1,    -1,  1556,  1557,  1558,    -1,  1560,    -1,    -1,
      -1,    -1,    -1,  1566,  1567,    -1,    -1,    -1,    -1,    -1,
      -1,  1017,  1018,    -1,    -1,  1392,    -1,    -1,    -1,    -1,
      -1,    -1,  1585,    -1,    -1,    -1,  1589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,    -1,
      -1,  1604,    -1,    -1,    -1,  1608,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1617,  1618,    -1,  1620,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1628,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1644,    -1,    -1,    -1,    -1,  1649,  1650,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,    -1,  1662,
    1663,    -1,    -1,  1109,    -1,    -1,    -1,    -1,    -1,    -1,
    1487,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,  1692,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1708,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1717,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1735,  1736,    -1,    -1,  1739,    -1,    -1,  1556,
    1557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,  1585,    -1,
    1773,  1774,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,  1789,    74,    -1,  1792,
      -1,    -1,    -1,    -1,  1797,    -1,    -1,  1800,    85,     6,
      -1,    88,  1248,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1832,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1857,    -1,    -1,    -1,    -1,    -1,
    1863,    -1,    -1,  1866,    -1,  1311,  1312,  1313,  1314,  1315,
      22,    23,    -1,    -1,  1320,  1321,    -1,  1323,    -1,  1325,
      -1,    -1,    -1,  1329,    -1,    -1,  1332,     6,    -1,  1892,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,  1726,
      -1,    -1,    -1,    -1,  1917,  1918,    -1,   204,    -1,    -1,
      -1,   208,  1739,   210,   211,    -1,  1929,  1930,     6,  1932,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1945,    -1,    -1,    -1,    -1,  1950,  1951,  1952,
    1953,  1954,     6,    -1,    -1,    -1,   243,  1960,    -1,    -1,
      -1,  1964,    -1,    -1,    -1,    -1,  1412,    -1,  1414,    -1,
      -1,    -1,  1418,    -1,  1420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,  1991,    -1,
      -1,    -1,  1809,  1996,  1997,  1998,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2009,  1824,  1454,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,  2037,  2038,  2039,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,   224,   225,    -1,    -1,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,
      -1,    -1,    -1,    -1,    -1,  1541,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1950,  1951,  1952,  1953,  1954,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2009,    -1,  1640,    -1,    -1,  1643,   350,   351,
     352,    -1,    -1,    -1,   356,   357,   358,   359,   360,   361,
     362,    -1,   364,    -1,    -1,    -1,   368,   369,    -1,    -1,
     372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,    -1,  1681,  1682,    -1,  1684,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,  1743,  1744,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,  1787,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,   524,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
     192,    -1,    -1,   106,   196,    -1,    -1,   110,    -1,   201,
     202,   203,    -1,   205,   206,   207,   119,    -1,   121,   211,
      -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   227,   228,   140,   141,   142,
     143,   144,   234,    -1,    -1,   148,    -1,   239,   151,    -1,
      -1,   243,    -1,    -1,   246,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,     6,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,   239,     3,     4,     5,
     243,    -1,  2018,   246,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,   811,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,
     126,    -1,   844,     6,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,   151,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,     6,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,
     196,   197,     6,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,   243,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,  1011,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    88,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,  1097,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
     236,   237,    -1,   239,    -1,   241,     3,     4,     5,   245,
     246,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,  1249,  1250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,  1327,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,  1337,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,   123,   124,   192,   126,   127,    -1,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,    -1,    -1,    -1,   211,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,   169,
     170,   171,   239,     3,     4,     5,   243,    -1,    -1,   246,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,  1486,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,
      13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,    -1,   124,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
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
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
      -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,   192,
     126,   127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,   169,   170,   171,   239,     3,     4,    -1,
     243,   244,    -1,   246,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,
      76,    77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,    -1,   123,   124,   192,   126,   127,    -1,
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
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,
      -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,    -1,   124,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,
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
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    75,    76,    77,    -1,    -1,    13,    14,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,
     192,   126,   127,    -1,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,    -1,   169,   170,   171,   239,     3,     4,
      -1,   243,    -1,    -1,   246,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      75,    76,    77,    -1,    -1,    13,    14,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,   124,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,   119,   120,    -1,    -1,   123,   124,   192,   126,   127,
      -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,   169,   170,   171,   239,     3,     4,    -1,    -1,   244,
      -1,   246,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,   123,   124,   192,   126,   127,    -1,   196,   197,
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
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,    13,
      14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    75,    76,    77,    -1,    -1,    13,    14,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,
     124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,    -1,   123,   124,   192,   126,
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
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,
      77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,   123,   124,   192,   126,   127,    -1,   196,
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
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,
      13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,    -1,   124,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
     113,     8,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
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
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
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
      -1,   234,     3,     4,     5,    -1,   239,    -1,    -1,    10,
      11,    12,    -1,   246,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    88,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,   210,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,   243,    -1,    -1,   246,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,     3,     4,     5,   243,    -1,
      -1,   246,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     8,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,
      88,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,   243,    -1,    -1,   246,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,   210,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,     3,     4,    -1,    -1,   239,    -1,    -1,
      10,    11,    12,    -1,   246,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
       3,     4,    -1,    83,    84,    -1,    86,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,   243,    -1,    -1,   246,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,   192,
     238,    -1,     8,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,     3,     4,    -1,     6,   239,   240,    -1,    10,
      11,    12,    -1,   246,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,   192,   238,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,    -1,    -1,    -1,    -1,   192,    -1,    -1,   248,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,     3,     4,
      -1,     6,   239,    -1,    -1,    10,    11,    12,    -1,   246,
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
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,   192,   244,    -1,
      -1,   196,   248,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,   192,    -1,   238,    -1,   196,    -1,
      -1,    -1,   244,   201,   202,   203,   248,   205,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,     3,     4,    -1,
      -1,   239,   240,    -1,    10,    11,    12,    -1,   246,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,     3,     4,    -1,    83,    84,    -1,
      86,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,   192,   244,    -1,    -1,
     196,   248,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
     206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,    13,    14,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,   192,    -1,   238,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,   248,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,
      -1,   123,   124,    -1,   126,   127,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   145,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,   169,   170,   171,
      -1,    -1,    44,    45,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
      -1,   113,   244,   115,   116,   117,   118,   119,   120,   121,
      -1,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,     4,    -1,   157,   158,   159,    -1,    -1,
      -1,   163,    13,    14,    -1,    -1,   168,   169,   170,   171,
      -1,    -1,   174,    -1,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    44,    45,    -1,   198,   199,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,   211,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,   106,   107,   108,   109,   110,
     111,    -1,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,     4,     5,   174,    -1,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   199,   200,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,   209,    -1,
     211,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,     4,     5,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    85,    -1,    -1,    88,    59,    60,    61,    62,
      -1,    -1,     5,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    85,    -1,    -1,    88,    59,    60,    61,    62,
      -1,    -1,    -1,   126,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    85,    -1,    -1,    88,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,   123,   124,    -1,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   169,
     170,   171,   107,   108,   109,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,   169,   170,   171,    -1,    -1,    -1,
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
      -1,    -1,    -1,   243,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,   243,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,   243,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,   240,    -1,   242,   216,   217,   218,
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
      45,    64,    65,    66,    70,    71,    73,    78,    79,    81,
      82,    84,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   106,   107,   108,
     109,   110,   111,   113,   115,   116,   117,   118,   119,   120,
     121,   123,   124,   125,   126,   127,   128,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     157,   158,   159,   163,   168,   169,   170,   171,   174,   176,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   198,   199,   200,   209,   211,   252,
     254,   255,   275,   293,   295,   299,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   317,   319,   320,   326,   327,
     328,   329,   335,   360,   361,   243,   247,    14,    97,   239,
     239,     6,   243,     6,     6,     6,     6,   239,     6,     6,
     241,   241,     4,   337,   361,   239,   241,   273,   273,   239,
     239,   239,     4,   239,   239,   239,     4,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   243,   112,
      97,     6,   243,    91,    94,    97,   110,   298,   239,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    55,    56,    57,    58,    63,    75,    76,    77,
      83,    86,    91,    94,    97,    99,   119,   124,   126,   192,
     196,   197,   201,   202,   203,   205,   206,   207,   227,   228,
     234,   239,   243,   246,   295,   299,   310,   317,   319,   330,
     331,   335,   337,   344,   346,   361,   239,   243,    97,    97,
     119,    94,    97,    99,    91,   295,    94,    97,    99,   110,
     296,    94,    97,   239,    94,   149,   174,   190,   191,   243,
     227,   228,   239,   243,   341,   342,   341,   243,   243,   341,
       4,    91,    95,   101,   102,   104,   105,   123,   239,    97,
      99,    97,    94,     4,    84,   185,   243,   361,     4,     6,
      91,    94,    97,    94,    97,   110,   297,     4,     4,     4,
       5,   239,   344,   345,     4,   239,   239,   239,     4,   243,
     348,   361,     4,   239,   239,   239,     6,     6,   241,     5,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    59,
      60,    61,    62,    67,    68,    69,    72,    74,    85,    88,
     193,   194,   195,   204,   208,   210,   352,   361,   239,     4,
     352,     5,   243,     5,   243,    32,   228,   330,   361,   241,
     243,   239,   243,     6,   239,   243,     6,   247,     7,   126,
     185,   212,   213,   214,   215,   236,   237,   239,   241,   245,
     271,   272,   273,   330,   351,   352,   361,     4,   299,   300,
     301,   243,     6,   330,   351,   352,   361,   351,   330,   351,
     358,   359,   361,   277,   281,   239,   340,     9,   352,   361,
     330,   330,   330,   239,   330,   330,   330,   239,   330,   330,
     330,   330,   330,   330,   330,   351,   330,   330,   330,   330,
     344,   239,   228,   330,   346,   347,   243,   345,   351,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   239,   241,   273,   273,   273,   273,   273,   273,
     239,   273,   273,   239,   273,   273,   243,   119,   295,   239,
     273,   273,   239,   239,   239,   330,   243,   330,   346,   330,
     330,   244,   347,   337,   361,     5,   177,     8,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   238,     9,   239,   241,
     245,   272,   273,   330,   347,   239,   239,   239,   344,   345,
     345,   345,   294,   243,   239,   344,   243,   243,   330,     4,
     344,   243,   348,   243,   243,   341,   341,   341,   330,   330,
     227,   228,   243,   243,   341,   227,   228,   239,   301,   341,
     243,   239,   243,   239,   239,   239,   239,   239,   239,   239,
     330,   345,   345,   345,   239,     4,   241,     6,   241,   301,
       6,     6,   243,   243,   243,   243,   345,   241,   241,   241,
     330,     6,     6,   330,   330,   330,   245,   330,   243,   177,
     330,   330,   330,   330,   273,   273,   273,   239,   239,   239,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     239,   239,   273,   239,   241,     6,     6,   243,     6,   301,
       6,   301,   273,   330,   229,   243,     9,   239,   241,   245,
     351,   347,   330,   301,   344,   344,   243,   352,    91,    94,
      97,    99,     7,   330,   330,     4,   174,   175,   344,     6,
     240,   242,   243,   274,     6,   243,     6,     9,   239,   241,
     245,   361,   244,   119,   124,   127,   293,   295,   330,     6,
     240,   248,     9,   239,   241,   245,   240,   248,   248,   240,
     248,     9,   239,   245,   242,   248,   276,   242,   276,    87,
     339,   336,   361,   248,   248,   240,   240,   240,   330,   240,
     240,   240,   330,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   244,     7,   330,   229,   244,   248,
     330,     6,   240,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     346,   330,   330,   330,   330,   330,   330,   330,   346,   346,
     361,   243,   330,   330,   351,   330,   351,   344,   351,   351,
     358,   330,   274,   361,   330,   345,   351,   351,   346,   337,
     352,   337,   347,   240,   244,   245,   273,    64,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   243,   330,   346,   330,   330,   330,   330,   330,
     361,   330,   330,     4,   338,   243,   274,   240,   244,   330,
     330,   330,     7,     7,   323,   323,   239,   330,   330,     6,
     347,   347,   243,   240,     6,   301,   243,   301,   301,   248,
     248,   248,   341,   341,   300,   300,   248,   330,   244,   314,
     248,   301,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   240,     7,   324,     6,     7,   330,     6,   330,   330,
     244,   347,   347,   347,   330,     6,   330,   330,   330,   240,
     240,   240,   240,   174,   248,   301,   243,     8,   240,   240,
     242,   358,   351,   358,   351,   351,   351,   351,   351,   351,
     330,   351,   351,   351,   351,   246,   354,   361,   352,   351,
     351,   351,   337,   361,   347,   244,   244,   330,   330,   301,
     361,   338,   242,   244,   240,   132,   149,   318,   240,   244,
     248,   330,     6,   243,   243,   243,   243,   330,   240,   242,
       7,   271,   272,   245,     7,     6,   347,     7,   215,   271,
     256,   361,   330,   330,   338,   241,   239,   119,   296,   243,
     244,     6,   222,   223,   253,   347,   361,   330,   330,     4,
     338,     6,   347,   330,     6,   351,   359,   361,   240,   338,
       6,   361,     6,   351,   330,   240,   241,   330,   352,     7,
       7,     7,   240,     7,     7,     7,   240,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   330,   240,   243,
     330,   346,   244,     6,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   248,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   248,   248,   248,   240,   242,
     242,   347,   248,   248,   274,   248,   274,   248,   248,   248,
     240,   332,   274,   244,   248,   248,   274,   274,   240,   245,
     240,   245,   248,   273,   333,   244,     7,   338,   274,   243,
       8,     8,   347,   245,   240,   242,   272,   239,   241,   273,
     347,     7,   243,   240,   240,   240,   330,   344,     4,   322,
       6,   290,   330,   352,   244,   240,   244,   244,   347,   245,
     244,   301,   244,   244,   341,   330,   330,   244,   244,   330,
     341,   129,   129,   146,   154,   155,   156,   160,   161,   315,
     316,   341,   244,   311,   240,   244,   240,   240,   240,   240,
     240,   240,   240,     7,   330,     6,   330,   240,   242,   242,
     244,   244,   244,   244,   242,   242,   248,     7,     7,     7,
     245,   330,   244,   330,   330,     7,   245,   274,   248,   274,
     274,   240,   240,   248,   274,   274,   248,   248,   274,   274,
     274,   274,   330,   274,     9,   353,   248,   240,   248,   274,
     245,   248,   334,   242,   244,   244,   245,   239,   241,   247,
     177,     7,   149,     6,   330,   244,   243,     6,   344,   244,
     330,   330,   330,   330,     6,     7,   271,   272,   245,   271,
     272,   352,   330,     6,     4,   243,   349,   361,   244,    46,
      46,   344,     4,   164,   165,   166,   167,   244,   259,   263,
     266,   268,   269,   245,   240,   242,   239,   330,   330,   239,
     239,   347,   351,   240,   245,   240,   242,   239,   240,   248,
     245,   239,     7,   273,     4,   284,   285,   286,   274,   274,
     341,   344,   344,     7,   344,   344,   344,     7,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,     6,     7,
     347,   330,   330,   330,   330,   244,   330,   330,   330,   344,
     351,   351,   248,   283,   330,   330,   338,   338,   330,   330,
     240,   344,   273,   330,   330,   330,   244,   338,   272,   245,
     272,   330,   330,   274,   244,   344,   347,     7,     7,     7,
     129,   321,     6,   240,   248,     7,     7,     7,   244,     4,
     244,   248,   248,   248,   244,   244,   109,     4,     6,   330,
     243,     6,   239,     6,   162,     6,   162,   244,   316,   248,
     315,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     344,     6,   243,     6,     6,     6,    97,     7,     6,     6,
     330,   344,   344,   344,     4,   248,     8,     8,   240,     4,
     101,     4,   347,   351,   330,   351,   246,   248,   287,   351,
     351,   338,   351,   240,   248,   338,   243,   295,   243,     6,
     330,     6,   243,   344,   244,   244,   244,   244,   244,   330,
       6,     4,   174,   175,   330,     6,     6,     6,     7,   348,
     350,     6,   241,   274,   273,   273,     6,   260,   239,   239,
     243,   270,     6,   338,   245,   351,   330,   242,   240,   330,
     330,   244,     6,     6,   253,   338,   245,   330,     6,   330,
     338,   240,   243,   330,   352,   274,    46,   243,   344,   352,
     355,   242,   248,     6,     6,     6,   123,   292,   292,   344,
       6,     6,     6,   344,   177,   291,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     5,   244,   274,   274,   274,
     274,   274,   248,   248,   248,   240,   274,   274,   285,   274,
     240,   274,   240,   273,   333,   274,     6,   274,   248,   239,
     241,   273,     4,   240,   242,   274,     6,   244,   344,   344,
     344,     4,     6,   271,   330,   344,   243,   243,     7,     6,
       7,   330,   330,   330,   243,   243,   243,   241,     6,   330,
     344,   330,     6,     6,   330,   341,   244,     5,   344,   243,
     243,   243,   243,   243,   243,   243,   344,     6,   347,   243,
     330,   242,     6,     6,   173,   330,   330,   330,     6,     6,
       6,     7,   274,   248,   248,   274,   248,   330,     4,   189,
     288,   289,   274,   240,   274,   334,   352,   239,   241,   330,
     243,   301,     6,   301,   248,     6,     6,     7,   271,   272,
     245,     7,     6,   348,   244,   248,   330,   271,   243,   274,
     356,   357,   358,   356,   239,   330,   330,   343,   344,   243,
     239,     4,     6,   240,     6,   240,   240,     6,   351,   239,
       4,   240,   248,   239,   344,   352,     7,   273,   282,   330,
     346,   286,   341,     6,     6,     6,     6,    95,     6,     5,
     243,   330,   330,   330,   330,   240,   333,   330,   330,   330,
     274,   272,   243,     6,   291,     6,   330,   344,     4,     6,
     347,   347,   330,   330,   352,   244,   240,   244,   248,   300,
     300,   330,   330,   244,   248,   240,   244,   248,     6,     6,
     343,   341,   341,   341,   341,   341,   228,   341,     6,   244,
     330,     6,     6,   344,   244,   248,     8,   244,   240,   243,
     330,   352,   351,   330,   351,   330,   352,   355,   357,   352,
     248,   240,   248,   244,   330,   318,   318,   344,   352,   330,
       6,     4,   349,     6,   348,   242,   344,   358,     6,   274,
     274,   257,   330,   248,   248,   244,   248,   258,   330,   330,
       6,   330,   330,   240,   278,   280,   243,   357,   244,   248,
       7,     7,   243,     5,   343,   274,   274,   248,   274,   240,
     248,   240,   242,   330,     6,     6,   243,   244,   244,   243,
       6,     6,   243,   330,   244,   244,   244,   242,     6,   344,
       7,   243,   330,   244,   248,   248,   248,   248,   248,   248,
       6,   244,   172,   330,   330,   347,     6,     6,   240,   274,
     274,   289,   352,   244,   244,   244,   244,     6,     6,     7,
       6,   245,     6,   244,     6,     6,   240,   248,   330,   330,
     243,   344,   244,   248,   240,   240,   248,   283,   287,   344,
     274,   330,   352,   361,   330,     6,   244,   330,   333,   330,
     244,   343,   133,   134,   139,   325,   133,   134,   325,   347,
     300,   244,   248,     6,   244,   344,   301,   244,     6,   347,
     341,   341,   341,   341,   341,   330,   244,   244,   244,   240,
       6,   243,     6,   348,   175,   261,   330,   248,   248,   343,
       6,   330,   330,   244,   244,   279,     7,   239,   244,   243,
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
#line 267 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 278 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 279 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 280 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 282 "Gmsh.y"
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
#line 300 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 301 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 302 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 303 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 304 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 305 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 306 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 307 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 308 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 310 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 311 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 312 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 315 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 320 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 324 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 331 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 336 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 341 "Gmsh.y"
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
#line 355 "Gmsh.y"
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
#line 368 "Gmsh.y"
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
#line 381 "Gmsh.y"
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
#line 409 "Gmsh.y"
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
#line 423 "Gmsh.y"
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
#line 436 "Gmsh.y"
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
#line 449 "Gmsh.y"
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
#line 467 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 481 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 483 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 488 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 490 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 495 "Gmsh.y"
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
#line 599 "Gmsh.y"
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
#line 609 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 618 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 625 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 635 "Gmsh.y"
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
#line 644 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 653 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 660 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 670 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 678 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 688 "Gmsh.y"
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
#line 707 "Gmsh.y"
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
#line 726 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 732 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 739 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 740 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 741 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 742 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 743 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 747 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 748 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 754 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 754 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 755 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 755 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 765 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 770 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 776 "Gmsh.y"
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
#line 838 "Gmsh.y"
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
#line 853 "Gmsh.y"
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
#line 882 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 892 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 897 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 905 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 910 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 918 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 927 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 932 "Gmsh.y"
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
#line 944 "Gmsh.y"
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
#line 961 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 967 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 976 "Gmsh.y"
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
#line 994 "Gmsh.y"
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
#line 1012 "Gmsh.y"
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
#line 1021 "Gmsh.y"
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
#line 1033 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1038 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1046 "Gmsh.y"
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
#line 1066 "Gmsh.y"
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
#line 1089 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[(4) - (5)].d));
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[(4) - (5)].d));
      else
	yymsg(0, "Unknown command '%s Field'", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 102:
#line 1100 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1108 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 104:
#line 1115 "Gmsh.y"
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

  case 105:
#line 1137 "Gmsh.y"
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

  case 106:
#line 1160 "Gmsh.y"
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

  case 107:
#line 1198 "Gmsh.y"
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

  case 108:
#line 1219 "Gmsh.y"
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

  case 109:
#line 1231 "Gmsh.y"
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

  case 113:
#line 1249 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 114:
#line 1258 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 115:
#line 1267 "Gmsh.y"
    { init_options(); ;}
    break;

  case 116:
#line 1269 "Gmsh.y"
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

  case 117:
#line 1287 "Gmsh.y"
    { init_options(); ;}
    break;

  case 118:
#line 1289 "Gmsh.y"
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

  case 119:
#line 1305 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 120:
#line 1314 "Gmsh.y"
    { init_options(); ;}
    break;

  case 121:
#line 1316 "Gmsh.y"
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

  case 123:
#line 1330 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 124:
#line 1338 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 125:
#line 1344 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 126:
#line 1349 "Gmsh.y"
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

  case 133:
#line 1391 "Gmsh.y"
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

  case 134:
#line 1403 "Gmsh.y"
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

  case 135:
#line 1416 "Gmsh.y"
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

  case 136:
#line 1431 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 137:
#line 1440 "Gmsh.y"
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

  case 142:
#line 1465 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 143:
#line 1473 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 144:
#line 1482 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 145:
#line 1490 "Gmsh.y"
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

  case 146:
#line 1504 "Gmsh.y"
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
#line 1522 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 148:
#line 1526 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 149:
#line 1533 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 150:
#line 1541 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 151:
#line 1545 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 152:
#line 1551 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 153:
#line 1555 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 154:
#line 1562 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
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

  case 155:
#line 1586 "Gmsh.y"
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

  case 156:
#line 1602 "Gmsh.y"
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

  case 157:
#line 1618 "Gmsh.y"
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

  case 158:
#line 1655 "Gmsh.y"
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

  case 159:
#line 1695 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "BSpline not yet available with OpenCASCADE geometry kernel");
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

  case 160:
#line 1711 "Gmsh.y"
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

  case 161:
#line 1728 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), knots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Nurbs not available yet with OpenCASCADE geometry kernel");
      }
      else{
        int order = knots.size() - tags.size() - 1;
        if(order != (int)(yyvsp[(10) - (11)].d))
          yymsg(1, "Incompatible Nurbs order: using %d", order);
        r = GModel::current()->getGEOInternals()->addNurbs(num, tags, knots);
      }
      if(!r) yymsg(0, "Could not add nurbs");
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 162:
#line 1749 "Gmsh.y"
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

  case 163:
#line 1765 "Gmsh.y"
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

  case 164:
#line 1784 "Gmsh.y"
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

  case 165:
#line 1800 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE face filling requires a single line loop");
        }
        else{
          r = GModel::current()->getOCCInternals()->addSurfaceFilling(num, wires[0]);
        }
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(7) - (8)].i));
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 166:
#line 1821 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(8) - (9)].i));
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 167:
#line 1832 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 168:
#line 1838 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 169:
#line 1844 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 170:
#line 1851 "Gmsh.y"
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

  case 171:
#line 1882 "Gmsh.y"
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

  case 172:
#line 1897 "Gmsh.y"
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

  case 173:
#line 1919 "Gmsh.y"
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

  case 174:
#line 1942 "Gmsh.y"
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

  case 175:
#line 1965 "Gmsh.y"
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

  case 176:
#line 1988 "Gmsh.y"
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

  case 177:
#line 2012 "Gmsh.y"
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

  case 178:
#line 2036 "Gmsh.y"
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

  case 179:
#line 2060 "Gmsh.y"
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

  case 180:
#line 2086 "Gmsh.y"
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

  case 181:
#line 2103 "Gmsh.y"
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

  case 182:
#line 2119 "Gmsh.y"
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

  case 183:
#line 2137 "Gmsh.y"
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

  case 184:
#line 2155 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      switch ((yyvsp[(2) - (8)].i)) {
      case 1:
        {
          bool r = GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
          if(!r) yymsg(0, "Could not add compound line");
        }
        (yyval.s).Type = MSH_SEGM_COMPOUND;
        break;
      case 2:
        {
          bool r = GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
          if(!r) yymsg(0, "Could not add compound surface");
        }
        (yyval.s).Type = MSH_SURF_COMPOUND;
        break;
      case 3:
        {
          bool r = GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
          if(!r) yymsg(0, "Could not add compound volume");
        }
        (yyval.s).Type = MSH_VOLUME_COMPOUND;
        break;
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 2186 "Gmsh.y"
    {
      // Particular case only for dim 2 (Surface)
      if ((yyvsp[(2) - (12)].i) == 2) {
        int num = (int)(yyvsp[(4) - (12)].d);
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (12)].l), tags);
        std::vector<int> bndTags[4];
        for(int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
          if(i < 4)
            ListOfDouble2Vector(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i), bndTags[i]);
          else
            break;
        }
        bool r = GModel::current()->getGEOInternals()->addCompoundSurface
          (num, tags, bndTags);
        if(!r) yymsg(0, "Could not add compound surface");
        List_Delete((yyvsp[(7) - (12)].l));
        Free((yyvsp[(8) - (12)].c));
        for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
          List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
        List_Delete((yyvsp[(10) - (12)].l));
        (yyval.s).Type = MSH_SURF_COMPOUND;
        (yyval.s).Num = num;
      }
      else {
        yymsg(0, "GeoEntity dim out of range [2,2]");
      }
    ;}
    break;

  case 186:
#line 2214 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 187:
#line 2218 "Gmsh.y"
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

  case 188:
#line 2244 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 189:
#line 2246 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 190:
#line 2248 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 191:
#line 2250 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 192:
#line 2252 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 193:
#line 2260 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 194:
#line 2262 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 195:
#line 2264 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 196:
#line 2266 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 197:
#line 2274 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 198:
#line 2276 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 199:
#line 2278 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 200:
#line 2286 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 201:
#line 2288 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 202:
#line 2290 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 203:
#line 2292 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 204:
#line 2302 "Gmsh.y"
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

  case 205:
#line 2318 "Gmsh.y"
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

  case 206:
#line 2334 "Gmsh.y"
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

  case 207:
#line 2350 "Gmsh.y"
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

  case 208:
#line 2366 "Gmsh.y"
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

  case 209:
#line 2382 "Gmsh.y"
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

  case 210:
#line 2419 "Gmsh.y"
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

  case 211:
#line 2441 "Gmsh.y"
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

  case 212:
#line 2464 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 213:
#line 2465 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 214:
#line 2470 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 215:
#line 2474 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 216:
#line 2478 "Gmsh.y"
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

  case 217:
#line 2499 "Gmsh.y"
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

  case 218:
#line 2518 "Gmsh.y"
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

  case 219:
#line 2540 "Gmsh.y"
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

  case 220:
#line 2555 "Gmsh.y"
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

  case 221:
#line 2570 "Gmsh.y"
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

  case 222:
#line 2589 "Gmsh.y"
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

  case 223:
#line 2640 "Gmsh.y"
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

  case 224:
#line 2661 "Gmsh.y"
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

  case 225:
#line 2683 "Gmsh.y"
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

  case 226:
#line 2705 "Gmsh.y"
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

  case 227:
#line 2810 "Gmsh.y"
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

  case 228:
#line 2826 "Gmsh.y"
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

  case 229:
#line 2861 "Gmsh.y"
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

  case 230:
#line 2883 "Gmsh.y"
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

  case 231:
#line 2905 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 232:
#line 2911 "Gmsh.y"
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

  case 233:
#line 2926 "Gmsh.y"
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
	GModel::current()->deletePhysicalGroups();
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

  case 234:
#line 2954 "Gmsh.y"
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

  case 235:
#line 2966 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 236:
#line 2975 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 237:
#line 2982 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 238:
#line 2994 "Gmsh.y"
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

  case 239:
#line 3013 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 240:
#line 3019 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 241:
#line 3025 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 242:
#line 3032 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 243:
#line 3039 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 244:
#line 3046 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 245:
#line 3058 "Gmsh.y"
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

  case 246:
#line 3131 "Gmsh.y"
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

  case 247:
#line 3149 "Gmsh.y"
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

  case 248:
#line 3166 "Gmsh.y"
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

  case 249:
#line 3181 "Gmsh.y"
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

  case 250:
#line 3214 "Gmsh.y"
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

  case 251:
#line 3226 "Gmsh.y"
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

  case 252:
#line 3250 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 253:
#line 3254 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 254:
#line 3259 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 255:
#line 3266 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 256:
#line 3271 "Gmsh.y"
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

  case 257:
#line 3281 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 258:
#line 3286 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 259:
#line 3292 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 260:
#line 3300 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 261:
#line 3304 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 262:
#line 3308 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 263:
#line 3318 "Gmsh.y"
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

  case 264:
#line 3381 "Gmsh.y"
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

  case 265:
#line 3397 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 266:
#line 3414 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 267:
#line 3431 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 268:
#line 3453 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 269:
#line 3475 "Gmsh.y"
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
	  gmshsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 270:
#line 3510 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 271:
#line 3518 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 272:
#line 3526 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 273:
#line 3532 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 274:
#line 3539 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 275:
#line 3546 "Gmsh.y"
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

  case 276:
#line 3566 "Gmsh.y"
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

  case 277:
#line 3592 "Gmsh.y"
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

  case 278:
#line 3604 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 279:
#line 3615 "Gmsh.y"
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

  case 280:
#line 3633 "Gmsh.y"
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

  case 281:
#line 3651 "Gmsh.y"
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

  case 282:
#line 3669 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 283:
#line 3675 "Gmsh.y"
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

  case 284:
#line 3693 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 285:
#line 3699 "Gmsh.y"
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

  case 286:
#line 3719 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 287:
#line 3725 "Gmsh.y"
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

  case 288:
#line 3743 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 289:
#line 3749 "Gmsh.y"
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

  case 290:
#line 3766 "Gmsh.y"
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

  case 291:
#line 3782 "Gmsh.y"
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

  case 292:
#line 3799 "Gmsh.y"
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

  case 293:
#line 3816 "Gmsh.y"
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

  case 294:
#line 3839 "Gmsh.y"
    {
    ;}
    break;

  case 295:
#line 3842 "Gmsh.y"
    {
    ;}
    break;

  case 296:
#line 3848 "Gmsh.y"
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

  case 297:
#line 3860 "Gmsh.y"
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

  case 298:
#line 3880 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 299:
#line 3884 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 300:
#line 3888 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 301:
#line 3892 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 302:
#line 3896 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 303:
#line 3900 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 304:
#line 3904 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 305:
#line 3908 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 306:
#line 3917 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 307:
#line 3929 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 308:
#line 3930 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 309:
#line 3931 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 310:
#line 3932 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 311:
#line 3933 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 312:
#line 3937 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 313:
#line 3938 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 314:
#line 3939 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 315:
#line 3940 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 316:
#line 3941 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 317:
#line 3946 "Gmsh.y"
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

  case 318:
#line 3969 "Gmsh.y"
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

  case 319:
#line 3989 "Gmsh.y"
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

  case 320:
#line 4010 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 321:
#line 4014 "Gmsh.y"
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

  case 322:
#line 4029 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 323:
#line 4033 "Gmsh.y"
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

  case 324:
#line 4049 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 325:
#line 4053 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 326:
#line 4058 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 327:
#line 4062 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 328:
#line 4068 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 329:
#line 4072 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 330:
#line 4079 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 331:
#line 4096 "Gmsh.y"
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

  case 332:
#line 4137 "Gmsh.y"
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
                  yymsg(0, "Unknown model vertex with tag %d", corners[j]);
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

  case 333:
#line 4181 "Gmsh.y"
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
                  yymsg(0, "Unknown model vertex with tag %d", corners[i]);
              }
            }
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 334:
#line 4220 "Gmsh.y"
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

  case 335:
#line 4245 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 336:
#line 4254 "Gmsh.y"
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

  case 337:
#line 4284 "Gmsh.y"
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

  case 338:
#line 4310 "Gmsh.y"
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

  case 339:
#line 4337 "Gmsh.y"
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

  case 340:
#line 4369 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
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

  case 341:
#line 4396 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
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

  case 342:
#line 4422 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
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

  case 343:
#line 4448 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
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

  case 344:
#line 4474 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
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

  case 345:
#line 4500 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
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

  case 346:
#line 4521 "Gmsh.y"
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

  case 347:
#line 4532 "Gmsh.y"
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

  case 348:
#line 4580 "Gmsh.y"
    {
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

  case 349:
#line 4629 "Gmsh.y"
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

  case 350:
#line 4641 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 351:
#line 4652 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 352:
#line 4656 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        GModel::current()->getGEOInternals()->removeAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 353:
#line 4666 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 354:
#line 4676 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 355:
#line 4677 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 356:
#line 4678 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 357:
#line 4683 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 358:
#line 4689 "Gmsh.y"
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

  case 359:
#line 4701 "Gmsh.y"
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

  case 360:
#line 4719 "Gmsh.y"
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

  case 361:
#line 4746 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 362:
#line 4747 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 363:
#line 4748 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 364:
#line 4749 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 365:
#line 4750 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 366:
#line 4751 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 367:
#line 4752 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 368:
#line 4753 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 369:
#line 4755 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 370:
#line 4761 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 371:
#line 4762 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 372:
#line 4763 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 373:
#line 4764 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 374:
#line 4765 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4766 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 376:
#line 4767 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 377:
#line 4768 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 378:
#line 4769 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 379:
#line 4770 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 380:
#line 4771 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 381:
#line 4772 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 382:
#line 4773 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 383:
#line 4774 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 384:
#line 4775 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 385:
#line 4776 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 386:
#line 4777 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 387:
#line 4778 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 388:
#line 4779 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 389:
#line 4780 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 390:
#line 4781 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 391:
#line 4782 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4783 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 393:
#line 4784 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 394:
#line 4785 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 395:
#line 4786 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 396:
#line 4787 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4788 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 398:
#line 4789 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4790 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 400:
#line 4791 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 401:
#line 4792 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 402:
#line 4793 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4794 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 404:
#line 4795 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 405:
#line 4796 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 406:
#line 4797 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 407:
#line 4798 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 408:
#line 4807 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 409:
#line 4808 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 410:
#line 4809 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 411:
#line 4810 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 412:
#line 4811 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 413:
#line 4812 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 414:
#line 4813 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 415:
#line 4814 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 416:
#line 4815 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 417:
#line 4816 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 418:
#line 4817 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 419:
#line 4822 "Gmsh.y"
    { init_options(); ;}
    break;

  case 420:
#line 4824 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 421:
#line 4830 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 422:
#line 4832 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 423:
#line 4837 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 424:
#line 4842 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 425:
#line 4847 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 426:
#line 4852 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 427:
#line 4856 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 428:
#line 4860 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 429:
#line 4864 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 430:
#line 4868 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 431:
#line 4872 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 432:
#line 4876 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 433:
#line 4880 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 434:
#line 4886 "Gmsh.y"
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

  case 435:
#line 4902 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 436:
#line 4907 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 437:
#line 4913 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 438:
#line 4919 "Gmsh.y"
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

  case 439:
#line 4938 "Gmsh.y"
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

  case 440:
#line 4959 "Gmsh.y"
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

  case 441:
#line 4992 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 442:
#line 4996 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 443:
#line 5001 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 444:
#line 5005 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 445:
#line 5009 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 446:
#line 5013 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 447:
#line 5018 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 448:
#line 5023 "Gmsh.y"
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

  case 449:
#line 5033 "Gmsh.y"
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

  case 450:
#line 5043 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 451:
#line 5048 "Gmsh.y"
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

  case 452:
#line 5059 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 453:
#line 5068 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 454:
#line 5073 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 455:
#line 5078 "Gmsh.y"
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

  case 456:
#line 5105 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 457:
#line 5107 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 458:
#line 5112 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 459:
#line 5114 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 460:
#line 5119 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 461:
#line 5126 "Gmsh.y"
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

  case 462:
#line 5142 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 463:
#line 5144 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 464:
#line 5149 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 465:
#line 5158 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 466:
#line 5160 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 467:
#line 5165 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 468:
#line 5167 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 469:
#line 5172 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 470:
#line 5176 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 471:
#line 5180 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 472:
#line 5184 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 473:
#line 5188 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 474:
#line 5195 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 475:
#line 5199 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 476:
#line 5203 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 477:
#line 5207 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 478:
#line 5214 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 479:
#line 5219 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 480:
#line 5226 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 481:
#line 5231 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 482:
#line 5235 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 483:
#line 5240 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 484:
#line 5244 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 485:
#line 5252 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 486:
#line 5263 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 487:
#line 5267 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 488:
#line 5279 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 489:
#line 5287 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 490:
#line 5295 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 491:
#line 5302 "Gmsh.y"
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

  case 492:
#line 5312 "Gmsh.y"
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
          yymsg(0, "Unknown model vertex with tag %d", tag);
        }
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    ;}
    break;

  case 493:
#line 5335 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 494:
#line 5341 "Gmsh.y"
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

  case 495:
#line 5353 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 496:
#line 5358 "Gmsh.y"
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

  case 497:
#line 5368 "Gmsh.y"
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

  case 498:
#line 5378 "Gmsh.y"
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

  case 499:
#line 5388 "Gmsh.y"
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

  case 500:
#line 5400 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 501:
#line 5404 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 502:
#line 5409 "Gmsh.y"
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

  case 503:
#line 5421 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 504:
#line 5425 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 505:
#line 5429 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 506:
#line 5433 "Gmsh.y"
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

  case 507:
#line 5451 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 508:
#line 5459 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 509:
#line 5467 "Gmsh.y"
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

  case 510:
#line 5496 "Gmsh.y"
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

  case 511:
#line 5506 "Gmsh.y"
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

  case 512:
#line 5522 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 513:
#line 5533 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 514:
#line 5538 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 515:
#line 5542 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 516:
#line 5546 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 517:
#line 5558 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 518:
#line 5562 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 519:
#line 5574 "Gmsh.y"
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

  case 520:
#line 5591 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 521:
#line 5601 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 522:
#line 5605 "Gmsh.y"
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

  case 523:
#line 5620 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 524:
#line 5625 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 525:
#line 5632 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 526:
#line 5636 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 527:
#line 5641 "Gmsh.y"
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

  case 528:
#line 5655 "Gmsh.y"
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

  case 529:
#line 5671 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 530:
#line 5675 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 531:
#line 5679 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 532:
#line 5683 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 533:
#line 5687 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 534:
#line 5695 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 535:
#line 5701 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 536:
#line 5707 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 537:
#line 5713 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 538:
#line 5722 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 539:
#line 5726 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 540:
#line 5730 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 541:
#line 5738 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 542:
#line 5744 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 543:
#line 5750 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 544:
#line 5754 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 545:
#line 5762 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 546:
#line 5770 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 547:
#line 5777 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 548:
#line 5786 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 549:
#line 5790 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 550:
#line 5794 "Gmsh.y"
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

  case 551:
#line 5809 "Gmsh.y"
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

  case 552:
#line 5823 "Gmsh.y"
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

  case 553:
#line 5837 "Gmsh.y"
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

  case 554:
#line 5849 "Gmsh.y"
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

  case 555:
#line 5865 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 556:
#line 5874 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 557:
#line 5883 "Gmsh.y"
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

  case 558:
#line 5893 "Gmsh.y"
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

  case 559:
#line 5904 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 560:
#line 5912 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 561:
#line 5920 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 562:
#line 5924 "Gmsh.y"
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

  case 563:
#line 5943 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 564:
#line 5950 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 565:
#line 5956 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 566:
#line 5963 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 567:
#line 5970 "Gmsh.y"
    { init_options(); ;}
    break;

  case 568:
#line 5972 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 569:
#line 5980 "Gmsh.y"
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

  case 570:
#line 6004 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 571:
#line 6006 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 572:
#line 6012 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 573:
#line 6017 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 574:
#line 6019 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 575:
#line 6024 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 576:
#line 6029 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 577:
#line 6034 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 578:
#line 6036 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 579:
#line 6040 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 580:
#line 6052 "Gmsh.y"
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

  case 581:
#line 6066 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 582:
#line 6070 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 583:
#line 6077 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 584:
#line 6085 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 585:
#line 6093 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 586:
#line 6104 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 587:
#line 6106 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 588:
#line 6109 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13376 "Gmsh.tab.cpp"
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


#line 6112 "Gmsh.y"


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
    Msg::Error("Could not find edge slave %d or master %d for periodic copy",
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
      yymsg(0, "Unknown model face with tag %d", tag2);
      return;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gf->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model vertex %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gf->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model edge %d", tags[i]);
      }
    }
  }
  else if(dim2 == 3){
    GRegion *gr = GModel::current()->getRegionByTag(tag2);
    if(!gr){
      yymsg(0, "Unknown model region with tag %d", tag2);
      return;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gr->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model vertex with tag %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gr->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model edge with tag %d", tags[i]);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(gf)
          gr->addEmbeddedFace(gf);
        else
          yymsg(0, "Unknown model face with tag %d", tags[i]);
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

