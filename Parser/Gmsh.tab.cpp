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
     tSetString = 344,
     tPoint = 345,
     tCircle = 346,
     tEllipse = 347,
     tCurve = 348,
     tSphere = 349,
     tPolarSphere = 350,
     tSurface = 351,
     tSpline = 352,
     tVolume = 353,
     tBox = 354,
     tCylinder = 355,
     tCone = 356,
     tTorus = 357,
     tEllipsoid = 358,
     tQuadric = 359,
     tShapeFromFile = 360,
     tRectangle = 361,
     tDisk = 362,
     tWire = 363,
     tGeoEntity = 364,
     tCharacteristic = 365,
     tLength = 366,
     tParametric = 367,
     tElliptic = 368,
     tRefineMesh = 369,
     tAdaptMesh = 370,
     tRelocateMesh = 371,
     tReorientMesh = 372,
     tSetFactory = 373,
     tThruSections = 374,
     tWedge = 375,
     tFillet = 376,
     tPlane = 377,
     tRuled = 378,
     tTransfinite = 379,
     tPhysical = 380,
     tCompound = 381,
     tPeriodic = 382,
     tUsing = 383,
     tPlugin = 384,
     tDegenerated = 385,
     tRecursive = 386,
     tRotate = 387,
     tTranslate = 388,
     tSymmetry = 389,
     tDilate = 390,
     tExtrude = 391,
     tLevelset = 392,
     tAffine = 393,
     tBooleanUnion = 394,
     tBooleanIntersection = 395,
     tBooleanDifference = 396,
     tBooleanSection = 397,
     tBooleanFragments = 398,
     tThickSolid = 399,
     tRecombine = 400,
     tSmoother = 401,
     tSplit = 402,
     tDelete = 403,
     tCoherence = 404,
     tIntersect = 405,
     tMeshAlgorithm = 406,
     tReverseMesh = 407,
     tLayers = 408,
     tScaleLast = 409,
     tHole = 410,
     tAlias = 411,
     tAliasWithOptions = 412,
     tCopyOptions = 413,
     tQuadTriAddVerts = 414,
     tQuadTriNoNewVerts = 415,
     tRecombLaterals = 416,
     tTransfQuadTri = 417,
     tText2D = 418,
     tText3D = 419,
     tInterpolationScheme = 420,
     tTime = 421,
     tCombine = 422,
     tBSpline = 423,
     tBezier = 424,
     tNurbs = 425,
     tNurbsOrder = 426,
     tNurbsKnots = 427,
     tColor = 428,
     tColorTable = 429,
     tFor = 430,
     tIn = 431,
     tEndFor = 432,
     tIf = 433,
     tElseIf = 434,
     tElse = 435,
     tEndIf = 436,
     tExit = 437,
     tAbort = 438,
     tField = 439,
     tReturn = 440,
     tCall = 441,
     tSlide = 442,
     tMacro = 443,
     tShow = 444,
     tHide = 445,
     tGetValue = 446,
     tGetStringValue = 447,
     tGetEnv = 448,
     tGetString = 449,
     tGetNumber = 450,
     tUnique = 451,
     tHomology = 452,
     tCohomology = 453,
     tBetti = 454,
     tExists = 455,
     tFileExists = 456,
     tGetForced = 457,
     tGetForcedStr = 458,
     tGMSH_MAJOR_VERSION = 459,
     tGMSH_MINOR_VERSION = 460,
     tGMSH_PATCH_VERSION = 461,
     tGmshExecutableName = 462,
     tSetPartition = 463,
     tNameToString = 464,
     tStringToName = 465,
     tAFFECTDIVIDE = 466,
     tAFFECTTIMES = 467,
     tAFFECTMINUS = 468,
     tAFFECTPLUS = 469,
     tOR = 470,
     tAND = 471,
     tNOTEQUAL = 472,
     tEQUAL = 473,
     tGREATERGREATER = 474,
     tLESSLESS = 475,
     tGREATEROREQUAL = 476,
     tLESSOREQUAL = 477,
     UNARYPREC = 478,
     tMINUSMINUS = 479,
     tPLUSPLUS = 480
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
#define tSetString 344
#define tPoint 345
#define tCircle 346
#define tEllipse 347
#define tCurve 348
#define tSphere 349
#define tPolarSphere 350
#define tSurface 351
#define tSpline 352
#define tVolume 353
#define tBox 354
#define tCylinder 355
#define tCone 356
#define tTorus 357
#define tEllipsoid 358
#define tQuadric 359
#define tShapeFromFile 360
#define tRectangle 361
#define tDisk 362
#define tWire 363
#define tGeoEntity 364
#define tCharacteristic 365
#define tLength 366
#define tParametric 367
#define tElliptic 368
#define tRefineMesh 369
#define tAdaptMesh 370
#define tRelocateMesh 371
#define tReorientMesh 372
#define tSetFactory 373
#define tThruSections 374
#define tWedge 375
#define tFillet 376
#define tPlane 377
#define tRuled 378
#define tTransfinite 379
#define tPhysical 380
#define tCompound 381
#define tPeriodic 382
#define tUsing 383
#define tPlugin 384
#define tDegenerated 385
#define tRecursive 386
#define tRotate 387
#define tTranslate 388
#define tSymmetry 389
#define tDilate 390
#define tExtrude 391
#define tLevelset 392
#define tAffine 393
#define tBooleanUnion 394
#define tBooleanIntersection 395
#define tBooleanDifference 396
#define tBooleanSection 397
#define tBooleanFragments 398
#define tThickSolid 399
#define tRecombine 400
#define tSmoother 401
#define tSplit 402
#define tDelete 403
#define tCoherence 404
#define tIntersect 405
#define tMeshAlgorithm 406
#define tReverseMesh 407
#define tLayers 408
#define tScaleLast 409
#define tHole 410
#define tAlias 411
#define tAliasWithOptions 412
#define tCopyOptions 413
#define tQuadTriAddVerts 414
#define tQuadTriNoNewVerts 415
#define tRecombLaterals 416
#define tTransfQuadTri 417
#define tText2D 418
#define tText3D 419
#define tInterpolationScheme 420
#define tTime 421
#define tCombine 422
#define tBSpline 423
#define tBezier 424
#define tNurbs 425
#define tNurbsOrder 426
#define tNurbsKnots 427
#define tColor 428
#define tColorTable 429
#define tFor 430
#define tIn 431
#define tEndFor 432
#define tIf 433
#define tElseIf 434
#define tElse 435
#define tEndIf 436
#define tExit 437
#define tAbort 438
#define tField 439
#define tReturn 440
#define tCall 441
#define tSlide 442
#define tMacro 443
#define tShow 444
#define tHide 445
#define tGetValue 446
#define tGetStringValue 447
#define tGetEnv 448
#define tGetString 449
#define tGetNumber 450
#define tUnique 451
#define tHomology 452
#define tCohomology 453
#define tBetti 454
#define tExists 455
#define tFileExists 456
#define tGetForced 457
#define tGetForcedStr 458
#define tGMSH_MAJOR_VERSION 459
#define tGMSH_MINOR_VERSION 460
#define tGMSH_PATCH_VERSION 461
#define tGmshExecutableName 462
#define tSetPartition 463
#define tNameToString 464
#define tStringToName 465
#define tAFFECTDIVIDE 466
#define tAFFECTTIMES 467
#define tAFFECTMINUS 468
#define tAFFECTPLUS 469
#define tOR 470
#define tAND 471
#define tNOTEQUAL 472
#define tEQUAL 473
#define tGREATERGREATER 474
#define tLESSLESS 475
#define tGREATEROREQUAL 476
#define tLESSOREQUAL 477
#define UNARYPREC 478
#define tMINUSMINUS 479
#define tPLUSPLUS 480




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
#line 729 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 742 "Gmsh.tab.cpp"

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
#define YYLAST   15758

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  601
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   480

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   245,     2,   230,   232,     2,
     238,   239,   228,   226,   247,   227,   244,   229,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     220,     2,   221,   215,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   240,     2,   241,   237,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   242,   231,   243,   246,     2,     2,     2,
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
     216,   217,   218,   219,   222,   223,   224,   225,   234,   235,
     236
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
    1864,  1870,  1874,  1883,  1889,  1894,  1901,  1913,  1925,  1944,
    1963,  1976,  1989,  2002,  2013,  2018,  2023,  2028,  2033,  2038,
    2041,  2045,  2052,  2054,  2056,  2058,  2061,  2067,  2075,  2086,
    2088,  2092,  2095,  2098,  2101,  2105,  2109,  2113,  2117,  2121,
    2125,  2129,  2133,  2137,  2141,  2145,  2149,  2153,  2157,  2161,
    2165,  2169,  2173,  2179,  2184,  2189,  2194,  2199,  2204,  2209,
    2214,  2219,  2224,  2229,  2236,  2241,  2246,  2251,  2256,  2261,
    2266,  2271,  2276,  2283,  2290,  2297,  2302,  2304,  2306,  2308,
    2310,  2312,  2314,  2316,  2318,  2320,  2322,  2324,  2325,  2332,
    2334,  2339,  2346,  2348,  2353,  2358,  2363,  2370,  2376,  2384,
    2393,  2404,  2409,  2414,  2421,  2426,  2430,  2433,  2439,  2445,
    2449,  2455,  2462,  2471,  2478,  2487,  2494,  2499,  2507,  2514,
    2521,  2528,  2533,  2540,  2545,  2546,  2549,  2550,  2553,  2554,
    2562,  2564,  2568,  2570,  2572,  2575,  2576,  2580,  2582,  2585,
    2588,  2592,  2596,  2608,  2618,  2626,  2634,  2636,  2640,  2642,
    2644,  2647,  2651,  2656,  2662,  2664,  2668,  2670,  2673,  2677,
    2681,  2687,  2692,  2697,  2700,  2705,  2708,  2712,  2729,  2735,
    2737,  2739,  2741,  2745,  2751,  2759,  2764,  2769,  2774,  2781,
    2788,  2797,  2806,  2811,  2826,  2831,  2836,  2838,  2840,  2844,
    2848,  2858,  2866,  2868,  2874,  2878,  2885,  2887,  2891,  2893,
    2895,  2900,  2905,  2909,  2915,  2922,  2931,  2938,  2944,  2950,
    2956,  2962,  2964,  2969,  2971,  2973,  2975,  2977,  2982,  2989,
    2994,  3001,  3007,  3015,  3020,  3025,  3030,  3039,  3044,  3049,
    3054,  3059,  3068,  3077,  3084,  3089,  3096,  3101,  3103,  3108,
    3113,  3114,  3121,  3126,  3129,  3134,  3139,  3141,  3143,  3147,
    3149,  3151,  3155,  3159,  3163,  3169,  3177,  3183,  3189,  3198,
    3200,  3202
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     249,     0,    -1,   250,    -1,     1,     6,    -1,    -1,   250,
     251,    -1,   253,    -1,   254,    -1,   274,    -1,   118,   238,
     350,   239,     6,    -1,   292,    -1,   298,    -1,   302,    -1,
     303,    -1,   304,    -1,   305,    -1,   309,    -1,   318,    -1,
     319,    -1,   325,    -1,   326,    -1,   308,    -1,   307,    -1,
     306,    -1,   301,    -1,   328,    -1,   221,    -1,   222,    -1,
      44,   238,   350,   239,     6,    -1,    45,   238,   350,   239,
       6,    -1,    44,   238,   350,   239,   252,   350,     6,    -1,
      44,   238,   350,   247,   346,   239,     6,    -1,    45,   238,
     350,   247,   346,   239,     6,    -1,    44,   238,   350,   247,
     346,   239,   252,   350,     6,    -1,   360,   350,   242,   255,
     243,     6,    -1,   156,     4,   240,   329,   241,     6,    -1,
     157,     4,   240,   329,   241,     6,    -1,   158,     4,   240,
     329,   247,   329,   241,     6,    -1,    -1,   255,   258,    -1,
     255,   262,    -1,   255,   265,    -1,   255,   267,    -1,   255,
     268,    -1,   329,    -1,   256,   247,   329,    -1,   329,    -1,
     257,   247,   329,    -1,    -1,    -1,     4,   259,   238,   256,
     239,   260,   242,   257,   243,     6,    -1,   350,    -1,   261,
     247,   350,    -1,    -1,   163,   238,   329,   247,   329,   247,
     329,   239,   263,   242,   261,   243,     6,    -1,   350,    -1,
     264,   247,   350,    -1,    -1,   164,   238,   329,   247,   329,
     247,   329,   247,   329,   239,   266,   242,   264,   243,     6,
      -1,   165,   242,   342,   243,   242,   342,   243,     6,    -1,
     165,   242,   342,   243,   242,   342,   243,   242,   342,   243,
     242,   342,   243,     6,    -1,    -1,   166,   269,   242,   257,
     243,     6,    -1,     7,    -1,   214,    -1,   213,    -1,   212,
      -1,   211,    -1,   236,    -1,   235,    -1,   238,    -1,   240,
      -1,   239,    -1,   241,    -1,    80,   240,   276,   241,     6,
      -1,    81,   240,   280,   241,     6,    -1,   334,     6,    -1,
      88,   272,   351,   247,   329,   273,     6,    -1,    89,   272,
     360,   247,   351,   273,     6,    -1,   360,   270,   343,     6,
      -1,   360,   271,     6,    -1,   360,   272,   273,   270,   343,
       6,    -1,   360,   272,   242,   346,   243,   273,   270,   343,
       6,    -1,   360,   240,   329,   241,   270,   329,     6,    -1,
     360,   240,   329,   241,   271,     6,    -1,   360,   238,   329,
     239,   270,   329,     6,    -1,   360,   238,   329,   239,   271,
       6,    -1,   360,     7,   351,     6,    -1,   360,   272,   273,
       7,    46,   272,   273,     6,    -1,   360,   272,   273,     7,
      46,   272,   355,   273,     6,    -1,   360,   272,   273,   214,
      46,   272,   355,   273,     6,    -1,   360,   244,     4,     7,
     351,     6,    -1,   360,   240,   329,   241,   244,     4,     7,
     351,     6,    -1,   360,   244,     4,   270,   329,     6,    -1,
     360,   240,   329,   241,   244,     4,   270,   329,     6,    -1,
     360,   244,     4,   271,     6,    -1,   360,   240,   329,   241,
     244,     4,   271,     6,    -1,   360,   244,   173,   244,     4,
       7,   347,     6,    -1,   360,   240,   329,   241,   244,   173,
     244,     4,     7,   347,     6,    -1,   360,   244,   174,     7,
     348,     6,    -1,   360,   240,   329,   241,   244,   174,     7,
     348,     6,    -1,   360,   184,     7,   343,     6,    -1,   184,
     240,   329,   241,     7,     4,     6,    -1,   184,   240,   329,
     241,     7,    99,     6,    -1,   184,   240,   329,   241,     7,
     100,     6,    -1,   184,   240,   329,   241,   244,     4,     7,
     329,     6,    -1,   184,   240,   329,   241,   244,     4,     7,
     351,     6,    -1,   184,   240,   329,   241,   244,     4,     7,
     242,   346,   243,     6,    -1,   184,   240,   329,   241,   244,
       4,     6,    -1,   129,   238,     4,   239,   244,     4,     7,
     329,     6,    -1,   129,   238,     4,   239,   244,     4,     7,
     351,     6,    -1,    -1,   247,    -1,    -1,   276,   275,   360,
      -1,   276,   275,   360,     7,   329,    -1,    -1,   276,   275,
     360,     7,   242,   343,   277,   282,   243,    -1,    -1,   276,
     275,   360,   272,   273,     7,   242,   343,   278,   282,   243,
      -1,   276,   275,   360,     7,   351,    -1,    -1,   276,   275,
     360,     7,   242,   351,   279,   286,   243,    -1,    -1,   280,
     275,   350,    -1,   329,     7,   351,    -1,   281,   247,   329,
       7,   351,    -1,   345,     7,   360,   238,   239,    -1,    -1,
     247,   284,    -1,    -1,   284,    -1,   285,    -1,   284,   247,
     285,    -1,     4,   343,    -1,     4,    -1,     4,   242,   281,
     243,    -1,     4,   351,    -1,     4,   354,    -1,    -1,   247,
     287,    -1,   288,    -1,   287,   247,   288,    -1,     4,   329,
      -1,     4,   351,    -1,   188,   351,    -1,     4,   356,    -1,
       4,   354,    -1,   329,    -1,   351,    -1,   351,   247,   329,
      -1,    -1,   176,    94,   242,   329,   243,    -1,   128,    90,
     242,   346,   243,    -1,   128,   109,   242,   346,   243,    -1,
      -1,   122,   340,    -1,    90,   238,   329,   239,     7,   340,
       6,    -1,    93,   238,   329,   239,     7,   343,     6,    -1,
      97,   238,   329,   239,     7,   343,     6,    -1,    91,   238,
     329,   239,     7,   343,   291,     6,    -1,    92,   238,   329,
     239,     7,   343,   291,     6,    -1,   168,   238,   329,   239,
       7,   343,     6,    -1,   169,   238,   329,   239,     7,   343,
       6,    -1,   170,   238,   329,   239,     7,   343,   172,   343,
     171,   329,     6,    -1,   108,   238,   329,   239,     7,   343,
       6,    -1,    93,     4,   238,   329,   239,     7,   343,     6,
      -1,   122,    96,   238,   329,   239,     7,   343,     6,    -1,
      96,   238,   329,   239,     7,   343,   290,     6,    -1,   123,
      96,   238,   329,   239,     7,   343,   290,     6,    -1,    13,
      14,     6,    -1,    14,    96,   329,     6,    -1,   112,    96,
     238,   329,   239,     7,     5,     5,     5,     6,    -1,    94,
     238,   329,   239,     7,   343,     6,    -1,    95,   238,   329,
     239,     7,   343,     6,    -1,    99,   238,   329,   239,     7,
     343,     6,    -1,   102,   238,   329,   239,     7,   343,     6,
      -1,   106,   238,   329,   239,     7,   343,     6,    -1,   107,
     238,   329,   239,     7,   343,     6,    -1,   100,   238,   329,
     239,     7,   343,     6,    -1,   101,   238,   329,   239,     7,
     343,     6,    -1,   120,   238,   329,   239,     7,   343,     6,
      -1,   144,   238,   329,   239,     7,   343,     6,    -1,    96,
       4,   238,   329,   239,     7,   343,     6,    -1,    98,   238,
     329,   239,     7,   343,     6,    -1,   119,   238,   329,   239,
       7,   343,     6,    -1,   123,   119,   238,   329,   239,     7,
     343,     6,    -1,   126,   295,   238,   329,   239,     7,   343,
       6,    -1,   126,   295,   238,   329,   239,     7,   343,     4,
     242,   342,   243,     6,    -1,    -1,   125,   294,   293,   238,
     289,   239,   270,   343,     6,    -1,    90,    -1,    93,    -1,
      96,    -1,    98,    -1,   109,   242,   329,   243,    -1,    93,
      -1,    96,    -1,    98,    -1,   109,   242,   329,   243,    -1,
      93,    -1,    96,    -1,   109,   242,   329,   243,    -1,    90,
      -1,    93,    -1,    96,    -1,   109,   242,   329,   243,    -1,
     133,   340,   242,   299,   243,    -1,   132,   242,   340,   247,
     340,   247,   329,   243,   242,   299,   243,    -1,   134,   340,
     242,   299,   243,    -1,   135,   242,   340,   247,   329,   243,
     242,   299,   243,    -1,   135,   242,   340,   247,   340,   243,
     242,   299,   243,    -1,     4,   242,   299,   243,    -1,   150,
      93,   242,   346,   243,    96,   242,   329,   243,    -1,   147,
      93,   238,   329,   239,   242,   346,   243,     6,    -1,   300,
      -1,   298,    -1,    -1,   300,   292,    -1,   300,   294,   242,
     346,   243,     6,    -1,   300,   125,   294,   242,   346,   243,
       6,    -1,   300,   294,   242,     8,   243,     6,    -1,   300,
     125,   294,   242,     8,   243,     6,    -1,   137,   122,   238,
     329,   239,     7,   343,     6,    -1,   137,    90,   238,   329,
     239,     7,   242,   342,   243,     6,    -1,   137,   122,   238,
     329,   239,     7,   242,   340,   247,   340,   247,   346,   243,
       6,    -1,   137,   122,   238,   329,   239,     7,   242,   340,
     247,   340,   247,   340,   247,   346,   243,     6,    -1,   137,
      94,   238,   329,   239,     7,   242,   340,   247,   346,   243,
       6,    -1,   137,   100,   238,   329,   239,     7,   242,   340,
     247,   340,   247,   346,   243,     6,    -1,   137,   101,   238,
     329,   239,     7,   242,   340,   247,   340,   247,   346,   243,
       6,    -1,   137,   103,   238,   329,   239,     7,   242,   340,
     247,   340,   247,   346,   243,     6,    -1,   137,   104,   238,
     329,   239,     7,   242,   340,   247,   340,   247,   346,   243,
       6,    -1,   137,     4,   238,   329,   239,     7,   343,     6,
      -1,   137,     4,   238,   329,   239,     7,     5,     6,    -1,
     137,     4,   242,   329,   243,     6,    -1,   148,   242,   300,
     243,    -1,   131,   148,   242,   300,   243,    -1,   148,   184,
     240,   329,   241,     6,    -1,   148,     4,   240,   329,   241,
       6,    -1,   148,   360,     6,    -1,   148,     4,     4,     6,
      -1,   148,    83,     6,    -1,   173,   347,   242,   300,   243,
      -1,   131,   173,   347,   242,   300,   243,    -1,   208,   329,
     242,   300,   243,    -1,   189,   242,     8,   243,    -1,   189,
       5,     6,    -1,   190,   242,     8,   243,    -1,   190,     5,
       6,    -1,   189,   242,   300,   243,    -1,   131,   189,   242,
     300,   243,    -1,   190,   242,   300,   243,    -1,   131,   190,
     242,   300,   243,    -1,   360,   351,     6,    -1,    73,   238,
     357,   239,     6,    -1,   360,   360,   240,   329,   241,   350,
       6,    -1,   360,   360,   360,   240,   329,   241,     6,    -1,
     360,   329,     6,    -1,   129,   238,     4,   239,   244,     4,
       6,    -1,   167,     4,     6,    -1,   182,     6,    -1,   183,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   242,   329,   247,   329,   247,   329,   247,   329,
     247,   329,   247,   329,   243,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    78,     6,    -1,   114,     6,    -1,   115,
     242,   346,   243,   242,   346,   243,   242,   342,   243,   242,
     329,   247,   329,   243,     6,    -1,   187,   238,   242,   346,
     243,   247,   351,   247,   351,   239,     6,    -1,   175,   238,
     329,     8,   329,   239,    -1,   175,   238,   329,     8,   329,
       8,   329,   239,    -1,   175,     4,   176,   242,   329,     8,
     329,   243,    -1,   175,     4,   176,   242,   329,     8,   329,
       8,   329,   243,    -1,   177,    -1,   188,     4,    -1,   188,
     351,    -1,   185,    -1,   186,   360,     6,    -1,   186,   351,
       6,    -1,   178,   238,   329,   239,    -1,   179,   238,   329,
     239,    -1,   180,    -1,   181,    -1,   136,   340,   242,   300,
     243,    -1,   136,   242,   340,   247,   340,   247,   329,   243,
     242,   300,   243,    -1,   136,   242,   340,   247,   340,   247,
     340,   247,   329,   243,   242,   300,   243,    -1,    -1,   136,
     340,   242,   300,   310,   314,   243,    -1,    -1,   136,   242,
     340,   247,   340,   247,   329,   243,   242,   300,   311,   314,
     243,    -1,    -1,   136,   242,   340,   247,   340,   247,   340,
     247,   329,   243,   242,   300,   312,   314,   243,    -1,    -1,
     136,   242,   300,   313,   314,   243,    -1,   136,   242,   300,
     243,   128,   108,   242,   329,   243,    -1,   119,   343,    -1,
     123,   119,   343,    -1,   121,   242,   346,   243,   242,   346,
     243,   242,   329,   243,    -1,   315,    -1,   314,   315,    -1,
     153,   242,   329,   243,     6,    -1,   153,   242,   343,   247,
     343,   243,     6,    -1,   154,     6,    -1,   145,     6,    -1,
     145,   329,     6,    -1,   159,     6,    -1,   159,   161,     6,
      -1,   160,     6,    -1,   160,   161,     6,    -1,   155,   238,
     329,   239,     7,   343,   128,   329,     6,    -1,   128,     4,
     240,   329,   241,     6,    -1,   139,    -1,   140,    -1,   141,
      -1,   142,    -1,   143,    -1,    -1,   148,     6,    -1,   131,
     148,     6,    -1,   148,   329,     6,    -1,   131,   148,   329,
       6,    -1,   316,   242,   300,   317,   243,   242,   300,   317,
     243,    -1,   105,   238,   350,   239,    -1,   316,   238,   329,
     239,     7,   242,   300,   317,   243,   242,   300,   317,   243,
       6,    -1,    -1,   128,     4,   329,    -1,    -1,     4,    -1,
      -1,     7,   343,    -1,    -1,     7,   329,    -1,    -1,   138,
     343,    -1,   110,   111,   344,     7,   329,     6,    -1,   124,
      93,   344,     7,   329,   320,     6,    -1,   124,    96,   344,
     322,   321,     6,    -1,   124,    98,   344,   322,     6,    -1,
     162,   344,     6,    -1,   151,    96,   242,   346,   243,     7,
     329,     6,    -1,   145,    96,   344,   323,     6,    -1,   145,
      98,   344,     6,    -1,   146,    96,   344,     7,   329,     6,
      -1,   127,    93,   242,   346,   243,     7,   242,   346,   243,
     324,     6,    -1,   127,    96,   242,   346,   243,     7,   242,
     346,   243,   324,     6,    -1,   127,    93,   242,   346,   243,
       7,   242,   346,   243,   132,   242,   340,   247,   340,   247,
     329,   243,     6,    -1,   127,    96,   242,   346,   243,     7,
     242,   346,   243,   132,   242,   340,   247,   340,   247,   329,
     243,     6,    -1,   127,    93,   242,   346,   243,     7,   242,
     346,   243,   133,   340,     6,    -1,   127,    96,   242,   346,
     243,     7,   242,   346,   243,   133,   340,     6,    -1,   127,
      96,   329,   242,   346,   243,     7,   329,   242,   346,   243,
       6,    -1,   294,   242,   346,   243,   176,   294,   242,   329,
     243,     6,    -1,   152,   296,   344,     6,    -1,   116,   297,
     344,     6,    -1,   117,    98,   343,     6,    -1,   130,    93,
     343,     6,    -1,   126,   295,   343,     6,    -1,   149,     6,
      -1,   149,     4,     6,    -1,   149,    90,   242,   346,   243,
       6,    -1,   197,    -1,   198,    -1,   199,    -1,   327,     6,
      -1,   327,   242,   343,   243,     6,    -1,   327,   242,   343,
     247,   343,   243,     6,    -1,   327,   238,   343,   239,   242,
     343,   247,   343,   243,     6,    -1,   330,    -1,   238,   329,
     239,    -1,   227,   329,    -1,   226,   329,    -1,   233,   329,
      -1,   329,   227,   329,    -1,   329,   226,   329,    -1,   329,
     228,   329,    -1,   329,   229,   329,    -1,   329,   231,   329,
      -1,   329,   232,   329,    -1,   329,   230,   329,    -1,   329,
     237,   329,    -1,   329,   220,   329,    -1,   329,   221,   329,
      -1,   329,   225,   329,    -1,   329,   224,   329,    -1,   329,
     219,   329,    -1,   329,   218,   329,    -1,   329,   217,   329,
      -1,   329,   216,   329,    -1,   329,   222,   329,    -1,   329,
     223,   329,    -1,   329,   215,   329,     8,   329,    -1,    16,
     272,   329,   273,    -1,    17,   272,   329,   273,    -1,    18,
     272,   329,   273,    -1,    19,   272,   329,   273,    -1,    20,
     272,   329,   273,    -1,    21,   272,   329,   273,    -1,    22,
     272,   329,   273,    -1,    23,   272,   329,   273,    -1,    24,
     272,   329,   273,    -1,    26,   272,   329,   273,    -1,    27,
     272,   329,   247,   329,   273,    -1,    28,   272,   329,   273,
      -1,    29,   272,   329,   273,    -1,    30,   272,   329,   273,
      -1,    31,   272,   329,   273,    -1,    32,   272,   329,   273,
      -1,    33,   272,   329,   273,    -1,    34,   272,   329,   273,
      -1,    35,   272,   329,   273,    -1,    36,   272,   329,   247,
     329,   273,    -1,    37,   272,   329,   247,   329,   273,    -1,
      38,   272,   329,   247,   329,   273,    -1,    25,   272,   329,
     273,    -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,
      12,    -1,   204,    -1,   205,    -1,   206,    -1,    75,    -1,
      76,    -1,    77,    -1,    -1,    82,   272,   329,   331,   282,
     273,    -1,   334,    -1,   195,   272,   350,   273,    -1,   195,
     272,   350,   247,   329,   273,    -1,   336,    -1,   360,   240,
     329,   241,    -1,   360,   238,   329,   239,    -1,   200,   238,
     336,   239,    -1,   200,   238,   336,   244,   337,   239,    -1,
     202,   238,   336,   332,   239,    -1,   202,   238,   336,   244,
     337,   332,   239,    -1,   202,   238,   336,   272,   329,   273,
     332,   239,    -1,   202,   238,   336,   244,   337,   272,   329,
     273,   332,   239,    -1,   201,   238,   351,   239,    -1,   245,
     360,   272,   273,    -1,   245,   336,   244,   337,   272,   273,
      -1,    85,   272,   360,   273,    -1,    85,   272,   273,    -1,
     360,   271,    -1,   360,   240,   329,   241,   271,    -1,   360,
     238,   329,   239,   271,    -1,   360,   244,   337,    -1,   360,
       9,   360,   244,   337,    -1,   360,   244,   337,   238,   329,
     239,    -1,   360,     9,   360,   244,   337,   238,   329,   239,
      -1,   360,   244,   337,   240,   329,   241,    -1,   360,     9,
     360,   244,   337,   240,   329,   241,    -1,   360,   240,   329,
     241,   244,     4,    -1,   360,   244,     4,   271,    -1,   360,
     240,   329,   241,   244,     4,   271,    -1,   191,   238,   350,
     247,   329,   239,    -1,    56,   238,   343,   247,   343,   239,
      -1,    57,   272,   350,   247,   350,   273,    -1,    55,   272,
     350,   273,    -1,    58,   272,   350,   247,   350,   273,    -1,
      63,   238,   357,   239,    -1,    -1,   247,   329,    -1,    -1,
     247,   350,    -1,    -1,    83,   336,   339,   335,   240,   283,
     241,    -1,   360,    -1,   360,     9,   360,    -1,     4,    -1,
      86,    -1,    86,   329,    -1,    -1,   238,   338,   239,    -1,
     341,    -1,   227,   340,    -1,   226,   340,    -1,   340,   227,
     340,    -1,   340,   226,   340,    -1,   242,   329,   247,   329,
     247,   329,   247,   329,   247,   329,   243,    -1,   242,   329,
     247,   329,   247,   329,   247,   329,   243,    -1,   242,   329,
     247,   329,   247,   329,   243,    -1,   238,   329,   247,   329,
     247,   329,   239,    -1,   343,    -1,   342,   247,   343,    -1,
     329,    -1,   345,    -1,   242,   243,    -1,   242,   346,   243,
      -1,   227,   242,   346,   243,    -1,   329,   228,   242,   346,
     243,    -1,   343,    -1,   242,     8,   243,    -1,     5,    -1,
     227,   345,    -1,   329,   228,   345,    -1,   329,     8,   329,
      -1,   329,     8,   329,     8,   329,    -1,    90,   242,   329,
     243,    -1,    90,   242,     8,   243,    -1,    90,     5,    -1,
     295,   242,     8,   243,    -1,   295,     5,    -1,   125,   294,
     344,    -1,   294,   176,    64,   242,   329,   247,   329,   247,
     329,   247,   329,   247,   329,   247,   329,   243,    -1,    64,
     294,   242,   329,   243,    -1,   298,    -1,   309,    -1,   318,
      -1,   360,   272,   273,    -1,   360,   244,   337,   272,   273,
      -1,   360,     9,   360,   244,   337,   272,   273,    -1,    39,
     240,   360,   241,    -1,    39,   240,   345,   241,    -1,    39,
     238,   345,   239,    -1,    39,   272,   242,   346,   243,   273,
      -1,   360,   272,   242,   346,   243,   273,    -1,    40,   272,
     329,   247,   329,   247,   329,   273,    -1,    41,   272,   329,
     247,   329,   247,   329,   273,    -1,    42,   272,   350,   273,
      -1,    43,   272,   329,   247,   329,   247,   329,   247,   329,
     247,   329,   247,   329,   273,    -1,   196,   272,   345,   273,
      -1,    32,   272,   345,   273,    -1,   329,    -1,   345,    -1,
     346,   247,   329,    -1,   346,   247,   345,    -1,   242,   329,
     247,   329,   247,   329,   247,   329,   243,    -1,   242,   329,
     247,   329,   247,   329,   243,    -1,   360,    -1,     4,   244,
     173,   244,     4,    -1,   242,   349,   243,    -1,   360,   240,
     329,   241,   244,   174,    -1,   347,    -1,   349,   247,   347,
      -1,   351,    -1,   360,    -1,   360,   240,   329,   241,    -1,
     360,   238,   329,   239,    -1,   360,   244,   337,    -1,   360,
       9,   360,   244,   337,    -1,   360,   244,   337,   238,   329,
     239,    -1,   360,     9,   360,   244,   337,   238,   329,   239,
      -1,   360,   240,   329,   241,   244,     4,    -1,   125,    90,
     242,   329,   243,    -1,   125,    93,   242,   329,   243,    -1,
     125,    96,   242,   329,   243,    -1,   125,    98,   242,   329,
     243,    -1,     5,    -1,   209,   240,   360,   241,    -1,    67,
      -1,   207,    -1,    72,    -1,    74,    -1,   193,   238,   350,
     239,    -1,   192,   238,   350,   247,   350,   239,    -1,   194,
     272,   350,   273,    -1,   194,   272,   350,   247,   350,   273,
      -1,   203,   238,   336,   333,   239,    -1,   203,   238,   336,
     244,   337,   333,   239,    -1,    48,   272,   357,   273,    -1,
      49,   238,   350,   239,    -1,    50,   238,   350,   239,    -1,
      51,   238,   350,   247,   350,   247,   350,   239,    -1,    46,
     272,   357,   273,    -1,    60,   272,   350,   273,    -1,    61,
     272,   350,   273,    -1,    62,   272,   350,   273,    -1,    59,
     272,   329,   247,   350,   247,   350,   273,    -1,    54,   272,
     350,   247,   329,   247,   329,   273,    -1,    54,   272,   350,
     247,   329,   273,    -1,    47,   272,   350,   273,    -1,    47,
     272,   350,   247,   346,   273,    -1,    68,   272,   350,   273,
      -1,    69,    -1,    53,   272,   350,   273,    -1,    52,   272,
     350,   273,    -1,    -1,    87,   272,   351,   352,   286,   273,
      -1,    84,   272,   353,   273,    -1,   245,   329,    -1,   360,
       9,   245,   329,    -1,    46,   272,   356,   273,    -1,   357,
      -1,   356,    -1,   242,   357,   243,    -1,   350,    -1,   358,
      -1,   357,   247,   350,    -1,   357,   247,   358,    -1,   360,
     238,   239,    -1,   360,   244,   337,   238,   239,    -1,   360,
       9,   360,   244,   337,   238,   239,    -1,     4,   246,   242,
     329,   243,    -1,   359,   246,   242,   329,   243,    -1,   210,
     240,   350,   241,   246,   242,   329,   243,    -1,     4,    -1,
     359,    -1,   210,   240,   350,   241,    -1
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
    3124,  3131,  3138,  3150,  3223,  3241,  3258,  3273,  3306,  3318,
    3342,  3346,  3351,  3358,  3363,  3373,  3378,  3384,  3392,  3396,
    3405,  3469,  3485,  3502,  3519,  3541,  3563,  3598,  3606,  3614,
    3620,  3627,  3634,  3654,  3680,  3692,  3703,  3721,  3739,  3758,
    3757,  3782,  3781,  3808,  3807,  3832,  3831,  3854,  3870,  3887,
    3904,  3927,  3930,  3936,  3948,  3968,  3972,  3976,  3980,  3984,
    3988,  3992,  3996,  4005,  4018,  4019,  4020,  4021,  4022,  4026,
    4027,  4028,  4029,  4030,  4033,  4057,  4076,  4099,  4102,  4118,
    4121,  4138,  4141,  4147,  4150,  4157,  4160,  4167,  4189,  4230,
    4274,  4313,  4338,  4347,  4377,  4403,  4429,  4461,  4488,  4514,
    4540,  4566,  4592,  4614,  4625,  4673,  4727,  4742,  4754,  4765,
    4772,  4787,  4801,  4802,  4803,  4807,  4813,  4825,  4843,  4871,
    4872,  4873,  4874,  4875,  4876,  4877,  4878,  4879,  4886,  4887,
    4888,  4889,  4890,  4891,  4892,  4893,  4894,  4895,  4896,  4897,
    4898,  4899,  4900,  4901,  4902,  4903,  4904,  4905,  4906,  4907,
    4908,  4909,  4910,  4911,  4912,  4913,  4914,  4915,  4916,  4917,
    4918,  4919,  4920,  4921,  4922,  4923,  4932,  4933,  4934,  4935,
    4936,  4937,  4938,  4939,  4940,  4941,  4942,  4947,  4946,  4954,
    4956,  4961,  4966,  4970,  4975,  4980,  4984,  4988,  4992,  4996,
    5000,  5004,  5010,  5026,  5031,  5037,  5043,  5062,  5083,  5116,
    5120,  5125,  5129,  5133,  5137,  5142,  5147,  5157,  5167,  5172,
    5183,  5192,  5197,  5202,  5230,  5231,  5237,  5238,  5244,  5243,
    5266,  5268,  5273,  5282,  5284,  5290,  5291,  5296,  5300,  5304,
    5308,  5312,  5319,  5323,  5327,  5331,  5338,  5343,  5350,  5355,
    5359,  5364,  5368,  5376,  5387,  5391,  5395,  5409,  5417,  5425,
    5432,  5442,  5465,  5470,  5476,  5481,  5487,  5498,  5504,  5509,
    5519,  5529,  5539,  5551,  5555,  5560,  5572,  5576,  5580,  5584,
    5602,  5610,  5618,  5647,  5657,  5673,  5684,  5689,  5693,  5697,
    5709,  5713,  5725,  5742,  5752,  5756,  5771,  5776,  5783,  5787,
    5792,  5806,  5822,  5826,  5830,  5834,  5838,  5846,  5852,  5858,
    5864,  5873,  5877,  5881,  5889,  5895,  5901,  5905,  5913,  5921,
    5928,  5937,  5941,  5945,  5960,  5974,  5988,  6000,  6016,  6025,
    6034,  6044,  6055,  6063,  6071,  6075,  6094,  6101,  6107,  6114,
    6122,  6121,  6131,  6155,  6157,  6163,  6168,  6170,  6175,  6180,
    6185,  6187,  6191,  6203,  6217,  6221,  6228,  6236,  6244,  6255,
    6257,  6260
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
  "tSetString", "tPoint", "tCircle", "tEllipse", "tCurve", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBox", "tCylinder",
  "tCone", "tTorus", "tEllipsoid", "tQuadric", "tShapeFromFile",
  "tRectangle", "tDisk", "tWire", "tGeoEntity", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tReorientMesh", "tSetFactory", "tThruSections",
  "tWedge", "tFillet", "tPlane", "tRuled", "tTransfinite", "tPhysical",
  "tCompound", "tPeriodic", "tUsing", "tPlugin", "tDegenerated",
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
     465,   466,   467,   468,   469,    63,   470,   471,   472,   473,
      60,    62,   474,   475,   476,   477,    43,    45,    42,    47,
      37,   124,    38,    33,   478,   479,   480,    94,    40,    41,
      91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   248,   249,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   252,   253,   253,
     253,   253,   253,   253,   254,   254,   254,   254,   255,   255,
     255,   255,   255,   255,   256,   256,   257,   257,   259,   260,
     258,   261,   261,   263,   262,   264,   264,   266,   265,   267,
     267,   269,   268,   270,   270,   270,   270,   270,   271,   271,
     272,   272,   273,   273,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   275,   275,   276,   276,   276,   277,   276,   278,   276,
     276,   279,   276,   280,   280,   281,   281,   281,   282,   282,
     283,   283,   284,   284,   285,   285,   285,   285,   285,   286,
     286,   287,   287,   288,   288,   288,   288,   288,   289,   289,
     289,   290,   290,   290,   290,   291,   291,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   293,
     292,   294,   294,   294,   294,   294,   295,   295,   295,   295,
     296,   296,   296,   297,   297,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   299,   299,   300,   300,   300,
     300,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   302,   302,   302,   302,   302,
     302,   302,   303,   303,   304,   305,   305,   305,   305,   305,
     305,   305,   305,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   307,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   309,   309,   309,   310,
     309,   311,   309,   312,   309,   313,   309,   309,   309,   309,
     309,   314,   314,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   316,   316,   316,   316,   316,   317,
     317,   317,   317,   317,   318,   318,   319,   320,   320,   321,
     321,   322,   322,   323,   323,   324,   324,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   326,
     326,   326,   327,   327,   327,   328,   328,   328,   328,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   331,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   332,   332,   333,   333,   335,   334,
     336,   336,   337,   338,   338,   339,   339,   340,   340,   340,
     340,   340,   341,   341,   341,   341,   342,   342,   343,   343,
     343,   343,   343,   343,   344,   344,   344,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   346,   346,   346,   346,
     347,   347,   347,   347,   348,   348,   349,   349,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     352,   351,   351,   353,   353,   354,   355,   355,   356,   357,
     357,   357,   357,   358,   358,   358,   359,   359,   359,   360,
     360,   360
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
       5,     3,     8,     5,     4,     6,    11,    11,    18,    18,
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
       5,     4,     4,     2,     4,     2,     3,    16,     5,     1,
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
       0,     0,     0,     2,     3,     1,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,     0,     0,   192,     0,     0,   193,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   315,   316,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,   284,   285,     0,     0,     0,   279,     0,
       0,     0,     0,     0,   362,   363,   364,     0,     0,     5,
       6,     7,     8,    10,     0,    11,    24,    12,    13,    14,
      15,    23,    22,    21,    16,     0,    17,    18,    19,    20,
       0,    25,     0,   600,     0,   217,     0,     0,     0,     0,
       0,   264,     0,   266,   267,   262,   263,     0,   268,   113,
     123,   599,   475,   470,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,   203,   204,   205,     0,     0,     0,     0,   416,
     417,   419,   420,   418,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   424,   425,
     426,     0,     0,   191,   196,   197,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   421,   422,   423,
       0,     0,     0,     0,     0,     0,     0,     0,   509,   510,
       0,   511,   488,   369,   429,   432,   298,   489,   470,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,   193,
     194,   189,   196,   197,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   477,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   599,
       0,     0,   217,     0,     0,   359,     0,     0,     0,   200,
     201,     0,     0,     0,     0,     0,   496,     0,     0,   494,
       0,     0,     0,     0,     0,   599,     0,     0,   532,     0,
       0,     0,     0,   260,   261,     0,   551,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     553,     0,   577,   555,   556,     0,     0,     0,     0,     0,
       0,   554,     0,     0,     0,     0,   277,   278,     0,   217,
       0,   217,     0,     0,     0,   470,     0,     0,     0,   217,
     365,     0,     0,    76,     0,    63,     0,     0,    67,    66,
      65,    64,    69,    68,    70,    71,     0,     0,     0,     0,
       0,     0,   538,   470,     0,   216,     0,   215,     0,   170,
       0,     0,   538,   539,     0,     0,   589,     0,   590,   539,
     111,   111,     0,   468,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,     0,   371,   497,
     373,     0,   490,     0,     0,   470,     0,   505,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,   446,     0,     0,     0,     0,     0,     0,
     299,     0,   331,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   217,     0,   217,   217,     0,   479,   478,
       0,     0,     0,     0,   217,   217,     0,     0,     0,     0,
     295,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,   241,
       0,     0,   239,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   341,   259,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,   280,
       0,   246,     0,     0,   248,     0,     0,     0,   371,     0,
     217,     0,     0,     0,     0,     0,     0,     0,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    72,    73,     0,     0,   257,
      38,   253,     0,     0,     0,     0,     0,   212,     0,     0,
       0,     0,   218,     0,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,   473,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,     0,     0,
     195,     0,     0,     0,     0,     0,     0,   355,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   427,
     445,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0,   464,     0,   370,   491,     0,     0,     0,     0,   499,
       0,   389,   388,   387,   386,   382,   383,   390,   391,   385,
     384,   375,   374,     0,   376,   498,   377,   380,   378,   379,
     381,   471,     0,     0,   472,   449,     0,   512,     0,     0,
       0,     0,     0,     0,     0,   329,     0,     0,     0,     0,
     358,     0,     0,     0,     0,   357,     0,   217,     0,     0,
       0,     0,     0,   481,   480,     0,     0,     0,     0,     0,
       0,     0,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   344,     0,     0,   240,     0,
       0,   235,     0,     0,     0,     0,   354,     0,     0,     0,
     370,   495,     0,     0,     0,     0,     0,     0,     0,     0,
     282,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     580,     0,     0,     0,   466,     0,     0,   245,   249,   247,
     251,     0,   376,     0,   471,   449,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,   370,     0,    63,     0,     0,     0,     0,    79,
       0,    63,    64,     0,     0,   471,     0,     0,   449,     0,
       0,     0,   189,     0,     0,   596,    28,    26,    27,     0,
       0,     0,     0,     0,   472,   542,    29,     0,     0,   254,
     591,   592,     0,   593,   542,    74,   114,    75,   124,   474,
     476,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,   529,   206,     9,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   415,   402,
       0,   404,   405,   406,   407,   408,   525,   409,   410,   411,
       0,     0,     0,   517,   516,   515,     0,     0,     0,   522,
       0,   461,     0,     0,     0,   463,     0,   128,   444,   502,
     501,   199,     0,     0,   430,   524,   435,     0,   441,     0,
       0,     0,     0,   492,     0,     0,   442,     0,   504,     0,
       0,     0,     0,   434,   433,   456,    70,    71,     0,     0,
       0,     0,     0,     0,   370,   327,   332,   330,     0,   340,
       0,   148,   149,   199,   370,     0,     0,     0,     0,   236,
       0,   250,   252,     0,     0,     0,   207,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   343,     0,     0,     0,     0,     0,
       0,     0,   202,     0,     0,     0,     0,     0,     0,     0,
       0,   242,     0,     0,     0,     0,   567,     0,   574,   563,
     564,   565,     0,   579,   578,     0,     0,   568,   569,   570,
     576,   583,   582,     0,   139,     0,   557,     0,   559,     0,
       0,     0,   552,     0,   244,     0,     0,     0,     0,     0,
       0,     0,   320,     0,     0,     0,   366,     0,   597,     0,
       0,     0,     0,   101,    63,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,    61,     0,    39,    40,    41,
      42,    43,     0,   434,   433,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   541,   540,     0,     0,
       0,     0,     0,     0,     0,   135,     0,   131,   132,     0,
       0,     0,   155,   155,     0,     0,     0,     0,     0,   151,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   337,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   508,     0,     0,     0,     0,     0,   464,
     465,     0,   437,     0,     0,     0,   500,   392,   493,   450,
     448,     0,   447,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,     0,   339,     0,     0,     0,     0,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,   305,     0,   308,     0,   310,     0,   296,
     302,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,   345,     0,   238,   237,   361,     0,     0,
      35,    36,     0,     0,     0,     0,   533,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   466,   467,   561,     0,   450,     0,
       0,   217,   321,     0,   322,   217,     0,     0,   547,   548,
     549,   550,     0,    86,     0,     0,     0,     0,    84,    91,
      93,     0,   536,     0,    99,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    34,   450,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
       0,   543,     0,     0,    32,     0,   543,   594,     0,   115,
     120,     0,     0,     0,   134,   137,   138,   469,     0,    77,
      78,   157,     0,     0,     0,     0,   158,   173,   174,     0,
       0,     0,     0,   159,   184,   175,   179,   180,   176,   177,
     178,   165,     0,     0,   403,   412,   413,   414,   518,     0,
       0,     0,   459,   460,   462,   129,   428,   458,   431,   436,
       0,     0,   464,   185,   443,     0,    70,    71,     0,   455,
     451,   453,   519,   181,     0,     0,   151,     0,     0,   338,
       0,   150,     0,     0,     0,     0,   258,     0,     0,     0,
       0,   217,   217,     0,     0,   307,   488,     0,     0,   309,
     311,     0,     0,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,     0,     0,     0,   162,
     163,     0,     0,     0,     0,   102,   103,   104,   108,     0,
     575,     0,     0,   573,     0,   584,     0,     0,   140,   141,
     581,   558,   560,     0,     0,     0,     0,     0,     0,   319,
     323,   319,     0,   367,    85,    63,     0,     0,     0,     0,
      83,     0,   534,     0,     0,     0,     0,     0,     0,   587,
     586,     0,     0,     0,     0,     0,   486,     0,     0,   455,
     255,   451,   256,     0,     0,     0,     0,   221,   219,     0,
       0,   546,   544,     0,     0,   116,   121,     0,     0,     0,
     526,   527,   133,   156,   160,   161,   166,   183,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,   514,   457,     0,   167,     0,   186,   328,
       0,     0,   187,     0,     0,     0,     0,     0,     0,   485,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   232,     0,     0,     0,     0,     0,     0,     0,
       0,   223,     0,     0,   342,    37,     0,   531,     0,     0,
     274,   273,     0,     0,     0,     0,     0,     0,   143,   144,
     147,   146,   145,     0,   562,     0,   598,     0,     0,     0,
       0,     0,     0,    96,     0,     0,    97,   537,     0,     0,
       0,    88,     0,     0,     0,    44,     0,     0,     0,     0,
       0,    46,     0,   222,   220,    33,     0,     0,   595,   128,
     139,     0,     0,   136,     0,     0,     0,     0,     0,     0,
       0,     0,   520,   521,     0,   464,   439,     0,   452,   454,
       0,   169,   190,     0,   335,   335,     0,   109,   110,   217,
       0,   210,   211,   297,     0,   303,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   213,     0,
       0,     0,     0,   105,   106,   566,   572,   571,   142,     0,
       0,     0,   324,     0,    92,    94,     0,   100,     0,    82,
     588,    89,    90,    49,     0,     0,     0,     0,   487,     0,
       0,   452,   545,     0,     0,     0,   118,   585,     0,   125,
       0,     0,     0,     0,   172,     0,     0,     0,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     483,     0,   313,     0,     0,   291,     0,   224,     0,     0,
       0,     0,     0,     0,     0,   530,   275,     0,     0,   353,
     217,   368,     0,   535,     0,    45,     0,     0,     0,    62,
      47,     0,   117,   122,   128,     0,     0,   153,   154,   152,
       0,     0,   440,     0,     0,     0,     0,   336,   346,     0,
       0,   347,     0,   208,     0,   304,     0,   287,     0,   217,
       0,     0,     0,     0,     0,     0,   164,   107,   271,   319,
      98,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,   188,     0,   350,     0,   351,   352,   482,     0,
       0,   293,   227,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    59,     0,     0,   119,     0,     0,     0,
       0,     0,   312,   292,   288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   229,   230,   231,     0,   225,
     326,    50,     0,    57,     0,   265,     0,   523,     0,     0,
       0,   294,     0,     0,    51,     0,     0,   270,     0,     0,
       0,   226,     0,     0,     0,     0,   507,     0,     0,    54,
      52,     0,    55,     0,   348,   349,     0,     0,    60,    58,
      56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   109,  1019,   110,   111,  1004,  1814,  1820,
    1287,  1490,  1964,  2093,  1288,  2064,  2111,  1289,  2095,  1290,
    1291,  1494,   417,   563,   564,  1085,   112,   742,   440,  1829,
    1974,  1830,   441,  1709,  1355,  1316,  1317,  1318,  1451,  1648,
    1649,  1150,  1542,  1533,   722,   574,   256,   257,   332,   186,
     258,   426,   427,   116,   117,   118,   119,   120,   121,   122,
     123,   259,  1182,  1998,  2055,   900,  1178,  1179,   260,   981,
     261,   127,  1383,  1148,   875,   914,  1934,   128,   129,   130,
     131,   262,   263,  1107,  1122,  1241,   264,   747,   265,   865,
     746,   443,   589,   301,  1685,   339,   340,   267,   533,   347,
    1275,  1483,   436,   432,  1234,   958,  1526,  1678,  1679,   943,
     438,   133,   395
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1789
static const yytype_int16 yypact[] =
{
   11061,    55,    73, 11211, -1789, -1789,   -22,   113,    66,  -120,
     -98,    53,   176,   239,   338,   345,   -11,   353,   124,   138,
      30,   133,   133,   159,   166,   202,    59,   214,   256,    71,
     265,   271,   276,   283,   289,   320,   326,   366,   421,   427,
     313,   463,   481,   604,   389,   -44,   586,   467,  6002,   470,
     439,   624,   -40,   433,   544,   534,   393,   490,   642,   -97,
     518,   374,   374,   529,   391,   327, -1789, -1789, -1789, -1789,
   -1789,   563,   116,   691,   714,    19,    51,   735,   748,    17,
     847,   863,   890,  4260,   896,   682,   684,   690,    22,    83,
   -1789,   696,   699, -1789, -1789,   950,   952,   728, -1789,  1709,
     739, 11378,    23,    34, -1789, -1789, -1789, 10772,   738, -1789,
   -1789, -1789, -1789, -1789,   740, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789,    -8, -1789, -1789, -1789, -1789,
      44, -1789,   960,   734,  5056,   304,   741,   978, 10772,  3549,
    3549, -1789, 10772, -1789, -1789, -1789, -1789,  3549, -1789, -1789,
   -1789,   742,   747,   980, -1789, -1789, 11407,    30, 10772, 10772,
   10772,   749, 10772, 10772, 10772,   752, 10772, 10772, 10772, 10772,
   10772, 10772, 10772,  3549, 10772, 10772, 10772, 10772,  4260,   753,
   -1789,  8588, -1789, -1789, -1789,   750,  4260,  6238,  3549, -1789,
   -1789, -1789, -1789, -1789,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   178,   133,   133,
     133,   133,   133,   755,   133,   133,   756,   544, -1789, -1789,
   -1789,   133,   133,    42,   820,   821,   822,   757,  6238,   882,
     544,   764,   133,   133,   765,   766,   767, -1789, -1789, -1789,
   10772,  6474, 10772, 10772,  6710,    30,   832,    43, -1789, -1789,
     768, -1789,  7821, -1789, -1789, -1789, -1789, -1789,   103, 10772,
    8588,   771,   776,  6946,  4260,  4260,  4260, -1789, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789,   773,  7182,   775,  9456,  1016,
    6238,   782,    22,   793,   794,   374,   374,   374, 10772, 10772,
     257, -1789,   325,   374,  9532,   447,   147,   799,   800,   801,
     802,   803,   806,   810, 10772,  4260,  4260,  4260,   838,    20,
    1053,   837, -1789,  1054,  1072, -1789,   839,   841,   843, -1789,
   -1789,   844,  4260,   840,   848,   850, -1789, 10772,  5294, -1789,
    1078,  1081, 10772, 10772, 10772,   284, 10772,   849, -1789,   916,
   10772, 10772, 10772, -1789, -1789, 10772, -1789,   133,   133,   133,
     856,   857,   858,   133,   133,   133,   133,   133,   133,   133,
   -1789,   133, -1789, -1789, -1789,   133,   133,   860,   864,   133,
     865, -1789,   866,  1098,  1099,   867, -1789, -1789,  1101,  1100,
    1104,  1103,   133, 10772, 10729,   110,  3549,  8588, 10772, -1789,
   -1789,  6238,  6238, -1789,   870, 11407,   590,  1107, -1789, -1789,
   -1789, -1789, -1789, -1789, 10772, 10772,    33,  6238,  1109,   539,
    1207,   874,  1111,    80,   876, -1789,   879, 11528, 10772, -1789,
    1323,  -156, -1789,    60,   -71, 10421, -1789,   -42, -1789,    61,
     -82,   -39,  1033, -1789,    30,   873,   878, 13996, 14021, 14046,
   10772, 14071, 14096, 14121, 10772, 14146, 14171, 14196, 14221, 14246,
   14271, 14296,   885, 14321, 14346, 14371, 12580,  1119, 10772,  8588,
    8524, -1789,   172, 10772,  1121,  1122,   891, 10772, 10772, 10772,
   10772, 10772, 10772, 10772, 10772, 10772, 10772, 10772, 10772, 10772,
   10772, 10772, 10772,  8588, 10772, 10772, 10772, 10772, 10772, 10772,
    8588,  8588,   887, 10772, 10772,  3549, 10772,  3549,  6238,  3549,
    3549,  3549,   889, 10772,    78, -1789,  9768, 10772,  6238,  4260,
    3549,  3549,  8588,    30, 11407,    30,   895,  8588,   895, -1789,
     895, 14396, -1789,   210,   892,     9,  1069, -1789,  1126, 10772,
   10772, 10772, 10772, 10772, 10772, 10772, 10772, 10772, 10772, 10772,
   10772, 10772, 10772,  7418, 10772, 10772, 10772, 10772, 10772,    30,
   10772, 10772,  1131, -1789,   620, 14421,   227, 10772, 10772, 10772,
   -1789,  1150,  1151,  1151,   922, 10772, 10772,  1156,  8588,  8588,
   13508,   925,  1162, -1789,   928, -1789, -1789,  -149, -1789, -1789,
   10643, 10863,   374,   374,   304,   304,  -122,  9532,  9532, 10772,
    5361,  -104, -1789, 10772, 10772, 10772, 10772, 10772, 10772, 10772,
   10772, 10772, 14446,  1164,  1166,  1167, 10772,  1169, 10772, -1789,
   10772,  5597, -1789, -1789,  8588,  8588,  8588, 10772,  1170, 10772,
   10772, 10772, 14471,   934, -1789, -1789, 14496, 14521, 14546,  1005,
   11458, -1789,   940,  8850, 14571, 14596, 13591,  3549,  3549,  3549,
    3549,  3549,  3549,  3549,  3549,  3549, 10772,  3549,  3549,  3549,
    3549,    12, 11407,  3549,  3549,  3549,    30,    30, -1789, -1789,
    8588, -1789,   941,  5833, -1789,   942,  6069, 10772,   895, 10772,
   -1789,    30, 10772, 10772,  1131,   945,   233, 14621, 11409,   944,
     372, 10772,  1181,   946,   948,   949,   953,  6238, 14646, 13618,
     144,   954,  1185,  1188, -1789, -1789, -1789,  8588,   189, -1789,
   -1789, -1789,    30, 10772, 10772,  1131,   956, -1789,   959,   -38,
     544,   534, -1789,   957, 12609, -1789,   155,  8588,    30, 10772,
   10772,  1196,  1195,  8588, 10772,  1200,  3549,    30,  9844,  1196,
    1203, -1789,    30,  1204,  3549, 10772,   963,   971, -1789, 10772,
   11407,  1205,  1208,  1209, 14671,  1210,  1211,  1213, 14696,  1214,
    1215,  1217,  1218,  1219,  1220,  1222, -1789,  1223,  1224,  1226,
   -1789, 10772, 14721,  8588,   993,  8588, 12638, -1789, -1789,  1232,
   13564, 13564, 13564, 13564, 13564, 13564, 13564, 13564, 13564, 13564,
   13564, 11491, 13564, 13564, 13564, 13564,   723,   452, 13564, 13564,
   13564, 11524, 11557, 11590,  8524,  1000,   999,    92,  8588, 11623,
   11656,   452, 11689,   452,   994,   995,   996,   -16, 10772, 15521,
   -1789,   452,  1001, 12667, 12696, -1789,  1002,  -133,   452,   -75,
    1007,  -176,   459,  1243, -1789,  1196,   452,  1009,  1026,  9171,
    9403,  1036,   592,   842,   842,   484,   484,   484,   484,   484,
     484,   545,   545,  8588,   350, -1789,   350,   350,   895,   895,
     895,  1028, 14746, 13645,   355,   489,  8588, -1789,  1267,  1034,
   14771, 14796, 14821, 10772,  6238,  1271,  1272,  9225, 12725, 14846,
   -1789,   479,   500,  8588,  1035, -1789,  6305, -1789,  6541,  6777,
     374, 10772, 10772, -1789, -1789,  1037,  1038,  9532, 10107,  1149,
     443,   374,  7013, 14871, 12754, 14896, 14921, 14946, 14971, 14996,
   15021, 15046,  1275, 10772,  1277, -1789, 10772, 15071, -1789, 13672,
   13699, -1789,   506,   536,   543, 12783, -1789, 13726, 13753, 11722,
   -1789, -1789,  1278,  1279,  1280,  1040, 10772,  7249, 10772, 10772,
   -1789, -1789,    18,   203,   228,   203,  1050,  1051,  1045,   452,
     452,  1046, 11755,   452,   452,   452,   452, 10772,   452,  1285,
   -1789,  1048,  1059,   430,   185,  1058,   548, -1789, -1789, -1789,
   -1789, 13564,   350,  7485,  1056,   510,  1057,  1128,  1295,  1157,
   10075,  1063,  1065,  1302,  6238, 12812, -1789, 10772, 10772, 10772,
   10772,  1303,   156,    67, 11407, 10772,  1304,  1307,    32, -1789,
     549,  1268,  1269,  6238,    25,  1073, 15096, 13780,   498, 10772,
   10772,  1075,  1074,  1080,  7654, -1789, -1789, -1789, -1789,  3549,
      -6,  1076, 15121, 13807, -1789,  1084, -1789,    11, 11788, -1789,
   -1789, -1789,  1079, -1789,  1086, -1789,   102, -1789, -1789, 15521,
   -1789,  1315, 13564,   452,   374,  6238,  6238,  1320,  6238,  6238,
    6238,  1321,  6238,  6238,  6238,  6238,  6238,  6238,  6238,  6238,
    6238,  6238,  1461,  1324,  8588,  8524, -1789, -1789, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   10772, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   10772, 10772, 10772, -1789, -1789, -1789,   550, 10772, 10772, -1789,
   10772, -1789,  6238,  3549,  3549, -1789, 12841,  1085, -1789, -1789,
   -1789,  1158, 10772, 10772, -1789, -1789, -1789,  1196, -1789,  1196,
   10772, 10772,  1094, -1789,  6238,   133, -1789, 10772, -1789, 10772,
   10772,   551,  1196,   355,   -19, -1789, 10772, 10772,   452,   556,
    6238,  8588,  1328,  1329,  1330,  4967, -1789, -1789,  1332, -1789,
    1106, 15521,  1093, -1789,  1335,  1336,  1339,   559,  1346, -1789,
    8183, -1789, -1789,   -60, 11821, 11854, -1789, -1789, 12870,  -132,
    1247,  1347, 10158,  1114,  1351,  1120,    37,    38,   -25, -1789,
     -34, -1789,   443,  1352,  1355,  1356,  1357,  1358,  1359,  1360,
    1361,  1362,  6238, 15521, -1789,  2511,  1129,  1364,  1366,  1367,
    1266,  1372, -1789,  1368,  1374, 10772,  6238,  6238,  6238,  1377,
   11887, -1789,  9487,   924,    50,  1378, -1789,  8588, -1789, -1789,
   -1789, -1789,  3549, -1789, -1789, 10772,  3549, -1789, -1789, -1789,
   -1789, 15521, -1789,  1138,  1140,  3549, -1789,  3549, -1789,  1196,
    3549,  1152, -1789,  1141, -1789,  1196, 10772, 10772,  1148,   544,
    1153, 10389, -1789,  2625,  1154,  6238, -1789,  1159, -1789, 12899,
   12928, 12957, 12986, -1789, -1789, 10772,  1386,    36, 10772,  1387,
    1391,  2739, -1789,  1393,    22,  1395,  1163,   452,   133,   133,
    1398, -1789,  1168,  1171,  1165, -1789,  1399, -1789, -1789, -1789,
   -1789, -1789,  1196,   461,  2399, 10772, 13834, 15146, 10772,  7885,
   10772,  1172,   561,  1402,   174,  1196, -1789,  1173, 10772,  1405,
   10772,  1196, 10465,  8819,   452,  4570,  1175,  1193, -1789,  1406,
    1407,   126,  1292,  1292,  6238,  1413,  1414,  1435,  6238,   -86,
    1436,  1437,  1439,  1440,  1441,  1442,  1443,  1445,  1447, -1789,
    1449,   583, 13564, 13564, 13564, 13564,   452, 11920, 11953, 11986,
    1216,   452,   452, -1789,  1315,   452, 15171, 13564,  1221,   -66,
   15521, 13564, -1789,  1450,   452, 12019, 15521, 15521, -1789,   595,
   -1789,  1453, -1789, 15196, 13861, -1789,   452,  1452,   584,  6238,
    6238,  6238,  1455,  1456, -1789,   197, 10772,  6238,  1227,  1228,
    1454,   759, -1789, 10772, 10772, 10772,  1229,  1230,  1231,  1225,
   -1789,  3654,  6238, -1789, 10772, -1789,  1457, -1789,  1458, -1789,
   -1789,  9532,    -7,  5530, -1789,  1233,  1234,  1235,  1237,  1238,
    1239,  8116,  1462, -1789,  8588, -1789, -1789, -1789,  1240, 10772,
   -1789, -1789, 13888,  1468,  1477,  1314, -1789, 10772, 10772, 10772,
   -1789,  1481,  1482,  1483,   877,   451,  1245,  9715,  1246, 10772,
      31,   452,  1255,   452,  1248, -1789, -1789, 11407,   638, 10772,
    1254, -1789, -1789,  3721, -1789, -1789,  1250,  1492, -1789, -1789,
   -1789, -1789,  3790, -1789,   170,  1256,  1494,  4025, -1789, -1789,
   -1789,    22, -1789,   589, -1789, 10772,   197,  3718,  3082, -1789,
    1261, 10772, 10772,  6238,  1260, -1789,   504,  1499,  1498, 15221,
    1500,  1243, 15246,  1262,   591, 15271,  1502,  1503, -1789, -1789,
    3549,  1273,  1506, 15296, -1789, 12052,  1274, -1789,  4813, 15521,
   -1789,  1507,   133,  6710, -1789, -1789, -1789, -1789,  1315, -1789,
   -1789, -1789,   374,  1510,  1511,  1512, -1789, -1789, -1789,  1513,
     -23,  1419,  1515, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789,  1517,  1281, -1789, -1789, -1789, -1789, -1789, 10772,
   10772, 10772, -1789, -1789, -1789,  1193, -1789, -1789, -1789, -1789,
   10772,  1286,  1283, -1789, -1789, 10772, 10772, 10772,   452,   355,
   -1789, -1789, -1789, -1789,  1282,  1520,   -86,  1521, 10772, -1789,
    6238, 15521,   893,  8588,  8588, 10772, -1789,  9225, 13015, 15321,
    9800,   304,   304, 10772, 10772, -1789,   317,  1284, 15346, -1789,
   -1789, 13044,   -32, -1789,  1522,  1526,  6238,   374,   374,   374,
     374,   374,  5766,  1527, -1789,   594, 10772,  4298,  1528, -1789,
   -1789,  6238, 10031,   687, 15371, -1789, -1789, -1789, -1789,  8904,
   -1789,  3549, 10772, -1789,  3549, 15521,  9140, 11407,  1288, -1789,
   -1789, -1789, -1789,  1297,  1309, 10772, 10772, 13073, 10772, 11409,
   -1789, 11409,  6238, -1789, -1789, 11407, 10772,  1551,  1554,    32,
   -1789,  1553, -1789,    22, 13915,  6238,  3549,  1555,   452, -1789,
    1317,   452, 10772, 12085, 12118,   596, -1789, 10772, 10772,   465,
   -1789,  1325, -1789,  1330,  1559,  1560,  1335, -1789, -1789,  1562,
   10772, -1789, -1789, 10772, 10696, -1789, -1789,  1327,  3082,   599,
    7591,  1563, -1789,   412, -1789, -1789, -1789, -1789,  1331,  1333,
    1338, -1789,  1567,  6238, 13564, 13564, 12151, 13564, -1789,  1342,
   12184, 15396, 13942, -1789, -1789, 10772, -1789,  1568, -1789, 15521,
    1571,  1340, -1789,   602,   609, 13536,  4325,  1577,  1343, -1789,
   -1789, 10772,  1341,  1345, 13102, 13969,  1580,  6238,  1585,  1353,
   10772, -1789, -1789,   610,   -26,   160,   186,   196,   198,  8352,
     208, -1789,  1587, 13131, -1789, -1789,  1423, -1789, 10772, 10772,
   -1789, -1789,  8588,  4506,  1590,  1363, 13564,   452, 15521, -1789,
   -1789, -1789, -1789,    31, -1789, 11407, -1789, 13160,  1369,  1373,
    1375,  1592,  4754, -1789,  1594,  1599, -1789, -1789,  1365,  1600,
     611, -1789,  1601,  1604,    87, 15521, 10772, 10772,  1379,  6238,
     617, 15521, 15421, -1789, -1789, -1789, 15446, 12217, -1789,  1085,
    1140,  6238,   452, -1789, 10772, 11407,    30,  8588,  8588, 10772,
    1605,   625, -1789, -1789, 10772,  1283, -1789, 10772, -1789, -1789,
   13189, -1789, -1789,  6238,   503,   585,  8588, -1789, -1789,   304,
   10336, -1789, -1789, -1789,  1609, -1789,  1380,  6238, -1789, 13218,
    1611,  8588,   374,   374,   374,   374,   374, -1789, -1789, 10772,
   13247, 13276,   626, -1789, -1789, -1789, -1789, -1789, -1789,  1381,
    1616,  1382, -1789,  1619, -1789, -1789,    22, -1789,  1459, -1789,
   -1789, -1789, -1789, -1789, 10772, 12250, 12283,  6238, -1789,  1620,
   10772,  1385, -1789, 10772,  1388,  1389, -1789, -1789,  4197, -1789,
    1392,   627,   632, 13305, -1789,  1394, 12316,  1390, 12349, -1789,
     634,  1397,   374,  6238,  1628,  1400,   374,  1631,   643,  1401,
   -1789, 10772, -1789,  1634,  1518,  8419,  1403, -1789,   646,   221,
     232,   235,   238,   266,  4929, -1789, -1789,  1637,  1641, -1789,
   -1789, -1789,  1643, -1789,  1408, 15521, 10772, 10772,   648, -1789,
   15521, 12382, -1789, -1789,  1085, 11407,  1412, -1789, -1789, -1789,
   10772, 10772, -1789, 10772,  1646,   374,   136, -1789, -1789,   374,
     139, -1789,  1647, -1789, 13334, -1789, 10772, -1789,   443, -1789,
    1648,  8588,  8588,  8588,  8588,  8352, -1789, -1789, -1789, 11409,
   -1789, 10772, 15471, 12415,    54, 10772,  1418, -1789, -1789, 12448,
   12481, 12514, -1789,   336, -1789,   339, -1789, -1789, -1789,  5004,
     318, 10929, -1789,   649,   678,   680,   686,   342,   688,  1420,
     716, -1789, 10772, -1789,  6238, 13363, -1789, 10772, 10772, 10772,
     374,   374, -1789, -1789, -1789,   443,  1649,  1650,  1651,  1656,
    8588,  1658,  1659,  1661,  1427, 15496,   718,  1665, 13392, 13564,
   12547,   379,   381,   425, -1789, -1789, -1789, -1789,   724, -1789,
   -1789, -1789,  3549, -1789,  1432, -1789,  1669, -1789, 10772, 10772,
   10772, -1789,  1688,   726, -1789,  1460,  6238, -1789, 13421, 13450,
   13479, -1789,  1689,  3549,  3549,   727, -1789,  1691,  1693, -1789,
   -1789,   732, -1789,  1694, -1789, -1789,  1695,  3549, -1789, -1789,
   -1789
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1789, -1789, -1789, -1789,   399, -1789, -1789, -1789, -1789,  -307,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789,  -686,  -127,  3843,  2752, -1789,  1265, -1789, -1789,
   -1789, -1789, -1789, -1789, -1788, -1789,   354,   181,  -119, -1789,
     -83, -1789,   129,   394,  1713, -1789,    -1,   -45, -1789, -1789,
      -2,  -589,  -292, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789,  1715, -1789, -1789, -1789, -1789, -1173, -1175,  1716, -1648,
    1718, -1789, -1789, -1789,  1139, -1789,  -130, -1789, -1789, -1789,
   -1789,  1808, -1789, -1789, -1344,   268,  1720, -1789,     0,  -560,
   -1789, -1789,   192, -1789, -1584,   -27,  -159,  2307,  2132,  -288,
      57, -1789,   104,   -68, -1789, -1789,    82,   241, -1608,  -139,
     997, -1789,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -547
static const yytype_int16 yytable[] =
{
     134,   115,   114,  1410,   584,   895,   896,   418,   437,  1412,
     286,  1798,   600,  1799,   995,  1571,   151,   153,   444,   467,
     152,   266,  1003,   319,   617,  1214,   345,   474,   388,  1281,
     621,   383,  1763,   387,   151,  1646,   151,   700,  1791,   390,
    1474,  1914,  1540,  1405,  1407,   268,   182,   515,   537,   183,
     400,   291,   184,   281,  1441,   324,   272,   325,   272,   141,
    2043,     4,   154,   161,   155,   185,   422,  1718,  1119,   728,
     737,  1120,   323,     5,  1264,   165,   292,   592,   593,   273,
     268,  1011,   151,   726,   151,   348,  1719,   349,   445,   712,
    1541,   727,   293,   294,   592,   593,   384,   673,   890,   676,
    1832,   559,   320,  1171,   592,   593,   705,   688,   706,  1313,
     329,  1397,   559,   330,  1113,   571,   572,   573,   139,   681,
    1172,  1171,   592,   593,   975,   897,   331,   137,  1173,  1174,
    1175,   423,  1531,   425,  1176,  1177,   433,   433,  1172,  1841,
     140,   326,  2024,   901,   439,  2026,  1173,  1174,  1175,  1442,
    1443,   994,  1176,  1177,   446,  1008,   613,   614,   615,   740,
     475,  1016,   138,  1264,  1116,   741,   592,   593,   732,  1117,
     433,  1025,   154,   628,   155,   268,   733,  1665,   268,  1034,
    1509,  1120,   143,   268,   268,   433,  2016,  1393,  1282,  1283,
    1284,  1285,   592,   593,   592,   593,  1001,   735,  1406,  1408,
     592,   593,   743,   321,  1264,   736,   701,   702,   741,  1475,
    1476,   266,   315,  1411,   316,  1760,   412,   413,  1409,  1647,
     135,  1871,   108,  1105,   136,  1371,   512,   147,  1729,   108,
     398,   736,   108,  1304,   399,   268,  1613,  1410,   421,   519,
     108,   775,   108,   431,   434,   144,   570,   154,   268,   155,
    1309,   268,   535,   300,   302,   534,   305,   957,   775,   577,
     618,   322,  1215,   582,   346,   389,   136,   268,  1286,  1930,
     268,   268,   268,   268,  1274,  1125,   391,   462,   408,   409,
     410,   411,   401,   268,   516,   538,   402,   268,   108,   348,
     108,   886,   476,   888,   889,   142,  2044,   162,   729,   738,
     730,   730,   412,   413,   731,   739,  1265,  1268,   424,   166,
     902,  1267,   268,   268,   268,   412,   413,   705,   713,   706,
     714,   350,  -539,  1968,   715,   539,  1903,   412,   413,   268,
     560,   306,   561,  1095,  1904,   268,   562,   692,   412,   413,
     154,   560,   155,   561,   145,   412,   413,   562,   682,   937,
     683,   146,   592,   593,   684,   408,   409,   410,   411,   148,
     825,  2039,   592,   593,   149,   592,   593,   408,   409,   410,
     411,   154,   817,   155,   689,   690,  1017,  1018,   150,   412,
     413,   408,   409,   410,   411,   603,   592,   593,   973,   604,
     703,   412,   413,   433,   268,  1017,  1018,   158,   268,   268,
     408,   409,   410,  1002,   159,   412,   413,  1872,   408,   409,
     410,   411,   592,   593,   268,   774,   500,   307,   501,   775,
     716,   308,   592,   593,   592,   593,   723,   309,   310,  1239,
     311,   312,  1240,  1873,   592,   593,    60,    61,    62,    63,
     160,   748,   705,  1874,   706,  1875,  1171,   592,   593,   313,
     736,    74,   163,   834,    77,  1876,   830,   775,   592,   593,
    2066,   592,   593,  1172,   592,   593,   268,   705,  2001,   706,
     869,  1173,  1174,  1175,   775,  1217,   977,  1176,  1177,  2002,
     775,   814,  2003,   592,   593,  2004,   287,   587,   588,   288,
     268,   570,   592,   593,   164,   596,   601,   268,   807,   594,
     685,  1927,   433,   167,   433,   268,   433,   433,   439,   168,
     945,   821,  2105,  2005,   169,   268,   268,   433,   433,   268,
     153,   170,   153,   829,   268,   831,   274,   171,   639,   275,
     136,   276,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     268,   592,   593,  1171,   558,   177,   861,  1358,   172,  1359,
    1756,  2053,   592,   593,   173,   592,   593,   595,   592,   593,
    1172,  1171,  1369,   996,   178,   268,   268,   179,  1173,  1174,
    1175,   556,   557,  2050,  1176,  1177,  2051,   558,  1172,  2060,
     412,   413,   425,   425,   960,  1160,  1173,  1174,  1175,   723,
     296,   297,  1176,  1177,   174,   592,   593,   592,   593,   811,
     180,   813,   298,   815,   816,   983,   299,   296,   297,   984,
     723,   268,   268,   268,   826,   827,  2089,   282,  2090,   298,
     283,   181,   284,   304,   277,  1931,  1932,   278,   592,   593,
     279,  1933,   280,   285,   439,   433,   439,   433,   433,   433,
     433,   433,   433,    40,   433,   433,   433,   433,   959,   175,
     433,   433,   433,   153,   965,   176,   964,   268,  2091,   705,
     991,   706,   723,   592,   593,   723,  1013,  1237,   974,  1454,
     693,   270,  1043,   694,   187,  1458,   695,   723,   696,   602,
     705,   705,   706,   706,   268,  1779,   412,   413,   775,  1590,
     412,   413,  1123,  -541,   268,   188,   775,  -546,   269,  1005,
     551,   552,   679,   554,   555,   556,   557,  1935,  1936,  1012,
     271,   558,  1155,  1933,   268,  1021,   775,  1136,   289,  1137,
     268,   539,  1496,   439,  1032,   290,  1295,  1135,  1247,  1036,
    -542,   433,  1688,  1156,  1656,  1511,  -543,   775,  1246,  1199,
    1247,  1516,   944,   775,   946,   947,   948,   949,   950,   951,
     295,   953,   954,   955,   956,  1596,  1597,   961,   962,   963,
     268,   303,   268,   679,   554,   555,   556,   557,   705,  1200,
     706,   707,   558,   775,   893,   894,  1201,   317,  1666,   588,
     775,  1243,  1277,  1346,  1368,   775,   775,   775,   775,  1376,
    1675,   314,  1390,   775,  1507,   268,   775,   318,   775,  1152,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,  2030,  1553,  1584,   327,   558,
     775,   775,  1672,  1576,  1695,  1577,  1673,  1772,   775,  1818,
    1030,   775,  1833,  1819,   328,  1854,  1834,  1146,  1038,   775,
     268,   333,  1855,  1870,  1900,  1410,   775,  1819,   736,   705,
    1909,   706,   866,   268,  1910,  1266,  1269,   334,  1925,  1957,
    1977,   268,  1819,   775,   775,  1978,  1655,  1984,  1656,   775,
     268,  1819,  2073,  1638,  1639,   723,  1992,   723,   723,  2000,
     775,  2014,  2056,   775,   335,  1819,   775,  1741,  1410,  1742,
     341,   723,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
     342,  2057,   343,  2058,   558,   775,  1270,   775,   344,  2059,
    1780,  2061,  1439,   775,   351,   775,   723,   352,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   773,   554,   555,   556,   557,   353,  1257,   354,  2063,
     558,  2084,   705,  1910,   706,  1819,   403,  2092,   355,  2102,
    2113,   775,   723,  2103,  1819,  2116,  1280,   385,   396,  2117,
     404,   268,   397,   428,   429,   442,  1482,   450,   136,   444,
     454,   468,   473,   508,   511,  1276,  -192,  -193,  -194,   517,
     268,   518,   520,   523,   524,   525,  1370,  1372,   536,   567,
     399,   268,  1752,  1753,   568,   575,   433,   578,  1322,  1323,
     581,  1325,  1326,  1327,   583,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1337,  1338,   585,   586,   605,   606,   607,
     608,   609,   268,   268,   610,   268,   268,   268,   611,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   619,
     622,   268,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,  1350,   616,   620,   623,   558,
     629,   624,  1163,   625,   634,   626,   627,   635,   630,  1169,
     631,   641,   642,  1180,   650,   651,   652,  1363,   663,   268,
     433,   433,   664,   666,   668,   669,   667,   671,   672,   670,
     674,   675,   691,  1377,   697,   704,   710,   711,   135,   745,
     749,   268,   717,  1303,   766,   750,   771,   777,   778,   808,
     779,   818,   558,   837,   838,   864,   835,   268,   268,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,   873,   874,   723,
     877,   558,   880,  1440,   884,  1422,  1370,  1372,   885,  1659,
     887,   913,   915,  1661,   916,   918,   926,   931,   935,  1433,
    1434,  1435,   938,   982,   967,   969,   976,   986,   987,   268,
     988,   989,   998,  1671,   999,   990,  1009,  1010,   997,  1014,
    1024,  1026,  1040,   268,   268,   268,  1029,  1351,  1352,  1035,
    1037,  1041,  1044,   709,   268,  1045,  1046,  1048,  1049,   433,
    1050,  1052,  1053,   433,  1054,  1055,  1056,  1057,  1466,  1058,
    1059,  1060,   433,  1061,   433,  1064,  1321,   433,  1068,  1093,
    1094,  1102,  1103,  1104,  1109,  1520,  1118,  1525,  1460,  1112,
    1124,  1127,   268,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,  1128,
    1939,   348,  1132,   558,  1140,  1147,  1141,  1170,  1149,  1158,
    1166,  1167,  1192,  1194,  1209,  1206,  1207,  1208,  1524,  1220,
    1221,   433,  1222,  1225,  1233,  1235,   268,  1535,  1236,  1242,
    1245,  1539,  1250,  1248,  1249,  1251,  1254,  1255,  1256,  1263,
    1272,  1273,   268,  1298,  1278,  1279,  1299,  1292,  1300,  1315,
    1305,   268,  1308,  1311,  1312,   268,  1446,  1324,  1328,   725,
    1448,  1340,  1354,  1362,  -195,  1379,  1380,  1381,  1384,  1452,
    1386,  1453,  1387,  1388,  1455,  1385,  1389,  1667,  1680,  1680,
    1391,  1399,  1585,  1586,  1587,  1398,  1402,  1403,  1404,  1413,
    1592,  1414,  1428,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1425,  1424,  1426,  1427,  1430,  1607,   268,   268,   268,  1429,
    1431,  1436,  1444,  1449,   268,  1807,  1615,  1450,  1457,  1654,
    1459,  1456,  1473,  1478,  1623,  1461,  1465,  1479,  1498,   268,
    1481,  1484,  1467,  1485,  1489,  1495,  1491,  1493,  1508,  1492,
     268,  1514,  1529,  1530,  1532,  1506,  1527,  1512,   268,  1536,
    1537,   268,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
    1528,  1538,  1543,  1544,   558,  1545,  1546,  1547,  1548,  1549,
    1706,  1550,  1734,  1551,  1552,  1562,  1573,  1579,  1583,  1588,
    1569,  1595,  1589,  1609,  1610,  1604,  1686,  1339,  1624,  1593,
    1594,  1601,  1602,  1603,  1629,  1616,  1617,  1618,   348,  1619,
    1620,  1621,  1626,  1630,   439,   439,  1631,  1635,  1636,  1637,
     268,  1705,  1641,  1644,  1651,  1240,  1658,  1662,  1663,  1682,
    1668,  1669,  1687,  1689,  1690,  1694,  1692,   433,  1697,  1698,
    1701,  1700,  1704,  1720,  1707,   268,  1714,  1715,  1716,  1717,
     268,  1721,  1722,  1723,  1735,  1728,  1736,  1738,  1761,  1747,
    1120,  1757,  1762,  1771,  1775,  1793,  1794,  1810,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,  1795,  1803,  1804,  1806,
     558,  1811,  1734,  1740,   736,  1823,  1824,  -544,  1825,  1831,
    1836,  1784,  1840,  1837,  1851,  1838,  1945,  1852,  1789,  1792,
    1839,  1846,  1853,  1858,  1861,  1859,  1865,   268,  1862,  1686,
     268,   268,  1867,  1877,  1879,  1868,  1884,  1801,  1894,   425,
     425,  1896,  1885,  1612,  1776,  1897,  1899,  1901,  1962,  1898,
    1902,  1924,  1891,   268,  1699,  1942,  1892,  1947,  1893,   268,
    1958,  1907,  1959,  1943,  1960,  1961,  1969,  -545,   268,  1982,
    1976,  1972,  1973,  1963,  1988,  1800,  1980,  1991,   433,  1985,
    1995,   433,  1989,  2007,  1993,  1999,  1996,  2008,  1809,  2010,
    2011,  2018,  2022,  2027,  2032,  2074,  2075,  2076,   723,   268,
     723,  2046,  2077,  2062,  2079,  2080,  1276,  2081,  2009,  2082,
     348,  2085,   268,   439,  2096,  2097,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,  2101,  2109,  1686,  2114,   558,  2115,
    2118,  2119,  2104,  1510,  2040,   439,   744,  2031,  1565,  1712,
    1888,  1915,   876,   151,   356,  1737,   113,  1534,   124,   125,
     268,   126,  1653,   132,  1713,  1937,  1805,  1889,  1790,  1681,
    1866,     0,     0,  1031,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1785,     0,     0,  1787,     0,
       0,     0,     0,     0,   268,   357,   358,   359,   360,   361,
     362,   363,   364,   365,     0,     0,   268,  1919,   366,   367,
     368,   369,     0,     0,     0,     0,   370,   371,   372,   268,
       0,   373,     0,   374,     0,     0,     0,     0,     0,     0,
       0,     0,  1908,   375,     0,     0,   376,     0,     0,     0,
       0,     0,     0,     0,  1916,     0,     0,     0,     0,  1764,
    1765,  1766,  1767,  1768,  1770,     0,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1686,     0,   268,     0,
       0,     0,     0,  1920,   268,   268,     0,     0,     0,     0,
    1944,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,   268,     0,     0,     0,   425,     0,     0,
       0,     0,     0,     0,   268,     0,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1686,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,     0,     0,     0,     0,     0,     0,
       0,   377,   378,   379,   268,     0,  1987,  2017,     0,     0,
       0,     0,   380,     0,     0,   394,   381,     0,   382,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,     0,   723,     0,   430,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   447,   448,   449,     0,
     451,   452,   453,     0,   455,   456,   457,   458,   459,   460,
     461,     0,   463,   464,   465,   466,     0,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   268,
     268,   268,   268,     0,     0,     0,     0,     0,   723,     0,
       0,     0,     0,     0,     0,     0,     0,  1686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   526,   528,
     530,   531,   470,     0,  1949,  1950,  1951,  1952,  1953,  1686,
       0,     0,     0,     0,     0,     0,     0,   565,   470,   433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,     0,     0,   580,     0,     0,     0,
     433,   433,     0,     0,     0,     0,   590,   591,     0,     0,
       0,     0,   591,     0,   433,     0,     0,     0,     0,     0,
       0,     0,   612,     0,  1986,     0,     0,     0,  1990,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   632,   470,     0,     0,     0,
     636,   637,   638,     0,   640,     0,     0,     0,   643,   644,
     645,     0,     0,   646,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2023,     0,     0,
       0,  2025,     0,     0,     0,     0,  2094,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2037,     0,     0,
       0,   678,     0,     0,     0,   470,   687,  2110,  2112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2120,   698,   699,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   724,     0,     0,     0,
       0,     0,  2071,  2072,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,   758,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   772,   528,     0,     0,
       0,   776,     0,     0,     0,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   798,   799,   800,   801,   802,   803,   804,   804,
       0,   809,   810,   472,   812,     0,     0,     0,     0,     0,
       0,   819,     0,     0,   823,   824,     0,     0,     0,     0,
     804,     0,     0,     0,     0,   470,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   854,   856,   857,   858,   859,   860,     0,   862,   863,
       0,     0,     0,     0,     0,   870,   871,   872,     0,     0,
       0,     0,     0,   878,   879,     0,   470,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   566,   151,   356,   526,   678,   898,     0,     0,
       0,   903,   904,   905,   906,   907,   908,   909,   910,   911,
       0,     0,     0,     0,   917,     0,   919,     0,   920,     0,
       0,     0,   470,   470,   470,   925,     0,   927,   928,   929,
       0,     0,     0,     0,     0,   357,   358,   359,   360,   361,
     362,   363,   364,   365,     0,     0,     0,     0,   366,   367,
     368,   369,     0,     0,   952,     0,   370,   371,   372,     0,
       0,   373,     0,   374,     0,     0,     0,     0,   470,     0,
       0,     0,     0,   375,     0,   971,   376,   972,   471,     0,
     862,   863,     0,     0,     0,     0,     0,     0,     0,   985,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,     0,  1423,     0,     0,
       0,  1006,  1007,     0,   406,     0,     0,     0,     0,   686,
       0,     0,     0,     0,     0,   470,     0,  1022,  1023,     0,
       0,   470,  1028,     0,     0,     0,  1022,     0,     0,     0,
       0,     0,     0,  1039,     0,     0,     0,  1042,   529,     0,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   471,     0,  1062,
       0,   854,     0,  1065,     0,     0,     0,     0,     0,     0,
       0,   377,   378,   379,     0,     0,     0,     0,     0,     0,
       0,     0,   380,     0,     0,     0,   381,     0,   382,   108,
       0,     0,     0,     0,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1106,     0,     0,     0,
       0,  1464,     0,     0,   412,   413,     0,     0,     0,     0,
       0,  -540,     0,  1497,     0,   471,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   832,
       0,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,     0,     0,     0,     0,     0,
       0,  1145,     0,     0,     0,  1151,     0,     0,     0,     0,
       0,   470,     0,     0,     0,     0,     0,     0,     0,  1164,
    1165,     0,     0,     0,   471,  1168,     0,     0,     0,     0,
     881,   882,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1193,     0,     0,  1195,     0,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,  1210,  1480,  1212,  1213,   558,     0,
       0,     0,     0,     0,     0,     0,   922,   923,   924,     0,
       0,     0,     0,     0,     0,  1231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1253,     0,
       0,     0,     0,     0,     0,  1259,  1260,  1261,  1262,     0,
     797,     0,   966,  1271,     0,     0,     0,   805,   806,     0,
       0,     0,     0,     0,     0,     0,     0,  1296,  1297,     0,
       0,     0,   470,     0,     0,     0,     0,     0,     0,   828,
       0,     0,     0,     0,   471,     0,     0,     0,     0,  1000,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,  1020,
     855,     0,   558,     0,     0,  1027,     0,     0,     0,     0,
       0,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   471,   471,     0,  1342,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1343,  1344,
    1345,     0,     0,     0,     0,  1347,  1348,     0,  1349,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1356,  1357,     0,     0,     0,     0,     0,     0,  1360,  1361,
       0,   471,   471,   471,     0,  1365,     0,  1366,  1367,     0,
    1096,     0,     0,     0,  1373,  1374,     0,     0,     0,   470,
       0,     0,     0,     0,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,   471,     0,     0,
    1401,     0,     0,     0,     0,  1131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1432,   471,  1157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,     0,     0,     0,     0,
       0,     0,     0,  1447,   471,     0,     0,     0,     0,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1373,  1374,     0,     0,     0,  1463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1472,     0,     0,  1477,     0,     0,     0,
     855,     0,  1066,     0,     0,     0,   151,   356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1499,     0,     0,  1502,   470,  1505,     0,
       0,     0,     0,     0,     0,   471,  1513,     0,  1515,     0,
    1513,  1519,     0,     0,     0,     0,     0,     0,   357,   358,
     359,   360,   361,   362,   363,   364,   365,     0,     0,     0,
       0,   366,   367,   368,   369,     0,  1302,     0,     0,   370,
     371,   372,     0,     0,   373,     0,   374,     0,     0,     0,
     471,     0,     0,     0,     0,     0,   375,     0,     0,   376,
       0,   708,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,     0,     0,     0,  1591,     0,  1341,     0,     0,     0,
       0,  1598,  1599,  1600,     0,     0,     0,   406,     0,     0,
    1606,     0,  1608,     0,     0,     0,     0,     0,     0,  1611,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   470,     0,     0,     0,     0,  1627,     0,     0,
       0,     0,     0,     0,     0,  1632,  1633,  1634,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1645,     0,     0,
       0,     0,     0,     0,     0,     0,   820,  1657,     0,     0,
       0,     0,     0,  1378,   377,   378,   379,     0,     0,     0,
       0,     0,     0,     0,     0,   380,     0,     0,     0,   381,
       0,   382,   108,  1674,     0,     0,     0,     0,     0,  1683,
    1684,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   867,     0,     0,     0,
       0,   471,     0,     0,  1676,     0,     0,     0,     0,     0,
       0,  1710,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1445,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1724,  1725,  1726,
       0,   471,     0,     0,     0,     0,     0,     0,  1727,     0,
       0,     0,     0,  1730,  1731,  1732,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1739,     0,     0,     0,
       0,   470,   470,  1745,     0,  1746,     0,     0,     0,     0,
       0,  1754,  1755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,  1504,     0,     0,  1773,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1783,   471,     0,
    1786,     0,     0,     0,  1788,     0,     0,     0,     0,     0,
       0,     0,     0,  1731,  1732,     0,  1797,     0,     0,     0,
       0,     0,     0,     0,  1802,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1815,     0,     0,     0,     0,  1821,  1822,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1826,     0,
       0,  1827,  1826,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   471,     0,     0,     0,     0,     0,
       0,     0,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1850,  1081,  1082,  1083,  1084,     0,  1086,
    1087,  1088,  1089,   151,   356,     0,  1625,     0,     0,  1860,
       0,     0,     0,  1099,     0,  1101,     0,     0,  1869,     0,
       0,     0,     0,  1108,     0,     0,     0,   528,     0,  1114,
    1115,     0,     0,     0,     0,     0,  1880,  1881,  1126,     0,
     470,     0,     0,     0,     0,   357,   358,   359,   360,   361,
     362,   363,   364,   365,     0,     0,   471,     0,   366,   367,
     368,   369,     0,     0,     0,     0,   370,   371,   372,     0,
       0,   373,     0,   374,  1905,  1906,     0,     0,     0,     0,
       0,     0,     0,   375,     0,     0,   376,     0,     0,     0,
       0,     0,  1918,     0,     0,   470,   470,  1923,     0,     0,
       0,     0,  1926,     0,     0,  1928,     0,     0,     0,     0,
    1605,     0,     0,     0,   470,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,     0,     0,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,  1954,     0,     0,
       0,     0,     0,     0,     0,  1216,  1218,  1219,     0,     0,
       0,  1223,  1224,     0,     0,  1227,  1228,  1229,  1230,     0,
    1232,     0,  1965,     0,     0,  1238,     0,     0,  1970,     0,
       0,  1971,   151,   356,     0,  1743,  1744,  1660,     0,     0,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   377,   378,   379,     0,     0,     0,     0,     0,  1994,
       0,     0,   380,     0,     0,     0,   381,     0,   382,   108,
       0,     0,     0,     0,   357,   358,   359,   360,   361,   362,
     363,   364,   365,     0,  2012,  2013,     0,   366,   367,   368,
     369,     0,     0,     0,     0,   370,   371,   372,  2019,  2020,
     373,  2021,   374,     0,  1319,  1320,  1664,     0,     0,     0,
       0,     0,   375,     0,  2029,   376,     0,     0,     0,   470,
     470,   470,   470,   470,     0,     0,     0,     0,     0,  1821,
       0,     0,     0,  2045,     0,     0,     0,     0,     0,     0,
    1711,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   406,     0,     0,     0,     0,     0,     0,
    2065,     0,     0,     0,     0,  2068,  2069,  2070,     0,     0,
       0,     0,     0,     0,   156,   157,     0,     0,   470,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
    1375,   558,     0,     0,     0,     0,  2098,  2099,  2100,     0,
     471,   471,     0,     0,     0,     0,     0,     0,     0,     0,
     377,   378,   379,     0,  1882,     0,     0,     0,     0,     0,
       0,   380,     0,     0,     0,   381,     0,   382,   108,   471,
       0,     0,     0,     0,     0,     0,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,   705,   558,   706,
    1676,     0,     0,     0,     0,     0,     0,     0,     0,  1921,
    1922,     0,     0,     0,     0,     0,     0,   419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1938,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1948,     0,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,  1486,
       0,  1670,     0,     0,     0,     0,     0,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     502,   503,   504,   505,   506,   507,  1521,   509,   510,     0,
       0,     0,     0,     0,   513,   514,   529,     0,     0,     0,
       0,     0,     0,     0,     0,   521,   522,     0,     0,   471,
       0,     0,     0,     0,  1554,  1555,  1556,  1557,  1558,     0,
       0,     0,     0,  1563,  1564,     0,     0,  1566,     0,  1568,
       0,     0,     0,  1572,     0,     0,  1574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1582,     0,
       0,     0,     0,  2033,  2034,  2035,  2036,  2038,     0,     0,
       0,     0,     0,     0,   471,   471,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2078,     0,     0,     0,     0,  1640,     0,  1643,
     647,   648,   649,  1650,  1975,  1652,   653,   654,   655,   656,
     657,   658,   659,     0,   660,     0,     0,     0,   661,   662,
       0,     0,   665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   677,     0,     0,     0,  1677,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,   189,     6,   336,     0,     0,     0,     0,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,  1774,     0,     0,     0,   471,   471,
     471,   471,   471,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,   227,     0,     0,     0,     0,     0,
    1733,  1857,     0,     0,     0,   228,   229,   230,     0,     0,
       0,     0,   231,    20,     0,   232,     0,     0,     0,     0,
     233,     0,     0,   234,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,     0,    36,     0,   471,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,   836,   238,
       0,    50,     0,   239,     0,   240,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,     0,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
    1812,     0,     0,  1813,   558,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,     0,     0,     0,   242,   243,     0,     0,     0,
     244,   245,   246,     0,   247,   248,   249,     0,     0,     0,
     108,     0,     0,     0,     0,     0,  1842,  1843,     0,  1845,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   337,     0,
       0,     0,   338,     0,     0,   255,     0,     0,     0,     0,
       0,     0,  1883,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,  1886,  1887,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     6,   356,     0,     0,     0,     0,
     190,   191,   192,     0,  1917,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,  1522,   358,   359,   360,
     361,   362,   363,   364,   365,   222,   223,   224,   225,   366,
     367,   368,   369,   226,   227,     0,     0,   370,   371,   372,
       0,     0,   373,     0,   374,   228,   229,   230,     0,     0,
       0,     0,   231,    20,   375,   232,     0,   376,     0,     0,
     233,     0,     0,   234,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,  1121,    36,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,    50,     0,   239,     0,   240,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,  1138,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1895,   241,   377,   378,   379,   242,   243,     0,     0,     0,
     244,   245,   246,   380,   247,   248,   249,   381,     0,   382,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   337,     0,
       0,     0,  1523,     0,     0,   255,   189,     6,   356,     0,
       0,  2087,     0,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   222,   223,
     224,   225,   366,   367,   368,   369,   226,   227,     0,  1314,
     370,   371,   372,     0,     0,   373,     0,   374,   228,   229,
     230,     0,     0,     0,     0,   231,    20,   375,   232,     0,
     376,     0,     0,   233,     0,     0,   234,     0,     0,   235,
       0,   236,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,    50,  2006,   239,     0,   240,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
      74,     0,     0,    77,     0,     0,     0,     0,  1364,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   377,   378,   379,   242,   243,
    2052,     0,     0,   244,   245,   246,   380,   247,   248,   249,
     381,     0,   382,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     251,     0,     0,     0,     0,     0,   252,     0,     0,     0,
       0,   337,     0,     0,     0,   254,     0,     0,   255,   189,
     151,   356,     0,   405,     0,     0,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   392,   211,
     212,   213,   214,   215,   216,  1382,     0,     0,     0,     0,
       0,     0,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   222,   223,   224,   225,   366,   367,   368,   369,   226,
       0,  1487,  1488,   370,   371,   372,     0,     0,   373,     0,
     374,   228,   229,   230,     0,     0,     0,     0,   231,    20,
     375,   232,     0,   376,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   406,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,  1570,     0,   558,     0,     0,     0,     0,     0,
       0,     0,  1578,     0,     0,     0,     0,     0,     0,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
     407,   558,     0,     0,     0,     0,     0,   241,   377,   378,
     379,   242,     0,     0,     0,     0,   244,   245,   246,   380,
     247,   248,   249,   381,     0,   382,   108,   408,   409,   410,
     411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   393,     0,     0,     0,     0,     0,   252,
       0,   412,   413,     0,   414,     0,   415,   189,     6,     0,
     416,   255,   633,     0,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,   227,     0,
       0,     0,     0,     0,     0,  1708,     0,     0,     0,   228,
     229,   230,     0,     0,     7,     8,   231,    20,     0,   232,
       0,     0,     0,     0,   233,     0,     0,   234,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,    50,     0,   239,     0,   240,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,     0,
     718,    49,     0,    51,   719,   241,   720,   721,     0,   242,
     243,     0,     0,     0,   244,   245,   246,     0,   247,   248,
     249,     0,     0,     0,   108,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   469,     0,     0,     0,     0,     0,   252,     0,    85,
      86,    87,   337,   189,     6,  1614,     0,   532,     0,   255,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   899,   228,   229,   230,     0,     0,
       7,     8,   231,    20,     0,   232,     0,     0,     0,     0,
     233,     0,     0,   234,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,    50,     0,   239,     0,   240,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,     0,   718,    49,     0,    51,
     719,   241,   720,   721,     0,   242,   243,     0,     0,     0,
     244,   245,   246,     0,   247,   248,   249,     0,     0,     0,
     108,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,     0,     0,   252,     0,    85,    86,    87,   337,   189,
       6,     0,   254,     0,     0,   255,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     921,   228,   229,   230,     0,     0,     7,     8,   231,    20,
       0,   232,     0,     0,     0,     0,   233,     0,     0,   234,
       0,     0,   235,     0,   236,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,    50,     0,   239,
       0,   240,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,     0,   718,    49,     0,    51,   719,   241,   720,   721,
       0,   242,   243,     0,     0,     0,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,   108,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   597,  1769,     0,     0,     0,     0,     0,   252,
       0,    85,    86,    87,   599,   189,     6,     0,   299,   532,
       0,   255,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   968,   228,   229,   230,
       0,     0,     7,     8,   231,    20,     0,   232,     0,     0,
       0,     0,   233,     0,     0,   234,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,    50,     0,   239,     0,   240,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,     0,   718,    49,
       0,    51,   719,   241,   720,   721,     0,   242,   243,     0,
       0,     0,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,   108,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,     0,     0,   252,     0,    85,    86,    87,
     253,   189,     6,     0,   254,     0,     0,   255,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,   228,   229,   230,     0,     0,     7,     8,
     231,    20,     0,   232,     0,     0,     0,     0,   233,     0,
       0,   234,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,    50,
       0,   239,     0,   240,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,     0,   718,    49,     0,    51,   719,   241,
     720,   721,     0,   242,   243,     0,     0,     0,   244,   245,
     246,     0,   247,   248,   249,     0,     0,     0,   108,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,     0,     0,     0,     0,
       0,   252,     0,    85,    86,    87,   337,   189,     6,     0,
     254,     0,     0,   255,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1159,   228,
     229,   230,     0,     0,     7,     8,   231,    20,     0,   232,
       0,     0,     0,     0,   233,     0,     0,   234,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,    50,     0,   239,     0,   240,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,     0,
     718,    49,     0,    51,   719,   241,   720,   721,     0,   242,
     243,     0,     0,     0,   244,   245,   246,     0,   247,   248,
     249,     0,     0,     0,   108,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   469,     0,     0,     0,     0,     0,   252,     0,    85,
      86,    87,   337,   189,     6,     0,   527,     0,     0,   255,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1161,   228,   229,   230,     0,     0,
       7,     8,   231,    20,     0,   232,     0,     0,     0,     0,
     233,     0,     0,   234,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,    50,     0,   239,     0,   240,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,     0,   718,    49,     0,    51,
     719,   241,   720,   721,     0,   242,   243,     0,     0,     0,
     244,   245,   246,     0,   247,   248,   249,     0,     0,     0,
     108,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   469,     0,     0,
       0,     0,     0,   252,     0,    85,    86,    87,   337,   189,
       6,     0,     0,   532,     0,   255,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1162,   228,   229,   230,     0,     0,     7,     8,   231,    20,
       0,   232,     0,     0,     0,     0,   233,     0,     0,   234,
       0,     0,   235,     0,   236,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,    50,     0,   239,
       0,   240,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,     0,   718,    49,     0,    51,   719,   241,   720,   721,
       0,   242,   243,     0,     0,     0,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,   108,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   251,     0,     0,     0,     0,     0,   252,
       0,    85,    86,    87,   569,   189,     6,     0,   254,     0,
       0,   255,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1181,   228,   229,   230,
       0,     0,     7,     8,   231,    20,     0,   232,     0,     0,
       0,     0,   233,     0,     0,   234,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,    50,     0,   239,     0,   240,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,     0,   718,    49,
       0,    51,   719,   241,   720,   721,     0,   242,   243,     0,
       0,     0,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,   108,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,     0,     0,   252,     0,    85,    86,    87,
     576,   189,     6,     0,   254,     0,     0,   255,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1211,   228,   229,   230,     0,     0,     7,     8,
     231,    20,     0,   232,     0,     0,     0,     0,   233,     0,
       0,   234,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,    50,
       0,   239,     0,   240,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,    40,     0,     0,    42,  1835,   539,
       0,     0,     0,     0,   718,    49,     0,    51,   719,   241,
     720,   721,     0,   242,   243,     0,     0,     0,   244,   245,
     246,     0,   247,   248,   249,     0,     0,     0,   108,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   469,     0,     0,     0,     0,
       0,   252,     0,    85,    86,    87,   337,   189,     6,     0,
     853,     0,  1301,   255,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1244,   228,
     229,   230,     0,     0,     0,     0,   231,    20,     0,   232,
       0,     0,     0,     0,   233,     0,     0,   234,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,    50,     0,   239,     0,   240,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,     0,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   773,
     554,   555,   556,   557,     0,     0,     0,     0,   558,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,   242,
     243,     0,     0,     0,   244,   245,   246,     0,   247,   248,
     249,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   469,     0,     0,     0,     0,     0,   252,   189,     6,
       0,     0,   337,  1503,     0,   190,   191,   192,     0,   255,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,     0,     0,     0,     0,   231,    20,     0,
     232,     0,     0,     0,     0,   233,     0,     0,   234,     0,
       0,   235,     0,   236,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,    50,     0,   239,     0,
     240,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,    74,     0,     0,    77,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,     0,     0,     0,
     242,   243,     0,     0,     0,   244,   245,   246,     0,   247,
     248,   249,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   469,     0,     0,     0,     0,     0,   252,   189,
       6,     0,     0,   337,     0,     0,   190,   191,   192,     0,
     255,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,   229,   230,     0,     0,     7,     8,   231,    20,
       0,   232,     0,     0,     0,     0,   233,     0,     0,   234,
       0,     0,   235,     0,   236,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,    50,     0,   239,
       0,   240,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,     0,   718,    49,     0,    51,   719,   241,   720,   721,
       0,   242,   243,     0,     0,     0,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,   108,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   251,     0,     0,     0,     0,     0,   252,
       0,    85,    86,    87,   337,   189,     6,     0,  1622,     0,
       0,   255,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1392,   228,   229,   230,
       0,     0,     7,     8,   231,    20,     0,   232,     0,     0,
       0,     0,   233,     0,     0,   234,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,    50,     0,   239,     0,   240,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,    40,     0,
       0,    42,   539,     0,     0,     0,     0,     0,   718,    49,
       0,    51,   719,   241,   720,   721,     0,   242,   243,     0,
       0,     0,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,   108,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597,  1769,
       0,     0,     0,     0,     0,   252,     0,    85,    86,    87,
     599,   189,     6,     0,   299,     0,     0,   255,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1997,   228,   229,   230,     0,     0,     0,     0,
     231,    20,     0,   232,     0,     0,     0,     0,   233,     0,
       0,   234,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,    50,
       0,   239,     0,   240,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   773,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
       0,     0,     0,   242,   243,     0,     0,     0,   244,   245,
     246,     0,   247,   248,   249,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   469,     0,     0,     0,     0,
       0,   252,   189,   151,   356,     0,   337,     0,     0,   190,
     191,   192,     0,   255,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   392,   211,   212,   213,   214,   215,   216,   939,     0,
       0,     0,     0,     0,     0,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   222,   223,   224,   225,   366,   367,
     368,   369,   226,     0,     0,     0,   370,   371,   372,     0,
       0,   373,     0,   374,   228,   229,   230,     0,     0,     0,
       0,   231,    20,   375,   232,     0,   376,   189,   151,   356,
       0,     0,     0,     0,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   392,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   222,
     223,   224,   225,   366,   367,   368,   369,   226,     0,     0,
       0,   370,   371,   372,     0,     0,   373,     0,   374,   228,
     229,   230,     0,     0,     0,     0,   231,    20,   375,   232,
       0,   376,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   377,   378,   379,   242,     0,     0,     0,     0,   244,
     245,   246,   380,   247,   248,   249,   381,     0,   382,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   393,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,   337,     0,     0,
       0,  1518,     0,     0,   255,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,   241,   377,   378,   379,   242,
       0,     0,     0,     0,   244,   245,   246,   380,   247,   248,
     249,   381,     0,   382,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   393,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,   337,   189,   151,   356,  1782,     0,     0,   255,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   392,   211,   212,   213,   214,   215,   216,  1129,
       0,     0,     0,     0,     0,     0,  1522,   358,   359,   360,
     361,   362,   363,   364,   365,   222,   223,   224,   225,   366,
     367,   368,   369,   226,     0,     0,     0,   370,   371,   372,
       0,     0,   373,     0,   374,   228,   229,   230,     0,     0,
       0,     0,   231,    20,   375,   232,     0,   376,   189,   151,
     356,     0,     0,     0,     0,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   392,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     222,   223,   224,   225,   366,   367,   368,   369,   226,     0,
       0,     0,   370,   371,   372,     0,     0,   373,     0,   374,
     228,   229,   230,     0,     0,     0,     0,   231,    20,   375,
     232,     0,   376,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   377,   378,   379,   242,     0,     0,     0,     0,
     244,   245,   246,   380,   247,   248,   249,   381,     0,   382,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   393,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   337,     0,
       0,     0,  1676,     0,     0,   255,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,  1130,     0,     0,     0,     0,   241,   377,   378,   379,
     242,     0,     0,     0,     0,   244,   245,   246,   380,   247,
     248,   249,   381,     0,   382,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   393,     0,     0,     0,     0,     0,   252,   189,
     151,     0,     0,   337,     0,     0,   190,   191,   192,     0,
     255,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   392,   211,
     212,   213,   214,   215,   216,  1438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,   229,   230,     0,   189,   151,     0,   231,    20,
       0,   232,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   392,   211,   212,   213,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
       0,     0,     0,     0,   231,    20,     0,   232,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,   241,     0,     0,
       0,   242,     0,     0,     0,     0,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   393,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   337,     0,     0,     0,   579,     0,
       0,   255,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,   241,   558,     0,     0,   242,     0,     0,
       0,     0,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597,   598,
       0,     0,     0,     0,     0,   252,     0,     0,     0,     0,
     599,   189,   151,     0,   299,     0,   822,   255,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     392,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,     0,   189,   151,     0,
     231,    20,     0,   232,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   392,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,     0,     0,     0,     0,   231,    20,     0,   232,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,   705,     0,   706,     0,     0,   241,
       0,     0,  1642,   242,     0,     0,     0,     0,   244,   245,
     246,     0,   247,   248,   249,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   393,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,   337,     0,     0,     0,
       0,     0,     0,   255,     0,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,   241,     0,   558,     0,   242,
       0,     0,     0,  1750,   244,   245,   246,  1751,   247,   248,
     249,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   393,     0,     0,     0,     0,     0,   252,   189,   151,
       0,  1252,   337,  1033,     0,   190,   191,   192,     0,   255,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   392,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,     0,     0,     0,     0,   231,    20,     0,
     232,   189,   151,     0,  1400,     0,     0,     0,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     392,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,     0,     0,     0,     0,
     231,    20,     0,   232,     0,     0,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,   241,     0,   558,     0,
     242,     0,     0,     0,  1777,   244,   245,   246,  1778,   247,
     248,   249,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   393,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,   337,     0,     0,     0,     0,     0,     0,
     255,     0,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,   930,     0,     0,   241,
       0,     0,     0,   242,   891,     0,     0,     0,   244,   245,
     246,     0,   247,   248,   249,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   393,     0,     0,     0,     0,
       0,   252,   189,   151,     0,  1462,   337,     0,     0,   190,
     191,   192,     0,   255,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   392,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   229,   230,     0,   189,   151,
       0,   231,    20,     0,   232,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   392,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,     0,     0,     0,     0,   231,    20,     0,
     232,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,  1940,
     241,     0,     0,  1941,   242,     0,     0,     0,     0,   244,
     245,   246,     0,   247,   248,   249,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   393,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,   337,     0,     0,
       0,     0,     0,     0,   255,     0,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,   241,     0,   558,     0,
     242,     0,     0,     0,     0,   244,   245,   246,   734,   247,
     248,   249,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   393,     0,     0,     0,     0,     0,   252,   189,
     151,     0,     0,   337,  1517,     0,   190,   191,   192,     0,
     255,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   392,   211,
     212,   213,   214,   215,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,   229,   230,     0,   189,   151,     0,   231,    20,
       0,   232,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   392,   211,   212,   213,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
       0,     0,     0,     0,   231,    20,     0,   232,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,   241,     0,     0,
     891,   242,     0,     0,     0,     0,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   393,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   337,  1828,     0,     0,     0,     0,
       0,   255,     7,     8,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,   241,     0,     0,   558,   242,     0,     0,
       0,   680,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   393,
       0,     0,     0,     0,     0,   252,     0,     0,     0,     0,
     337,     0,     0,     0,     0,     0,     0,   255,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,     0,   718,    49,
       0,    51,   719,     0,   720,   721,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    71,    -4,    -4,     0,     0,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,    85,    86,    87,
     558,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
     892,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,  2054,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
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
      32,    33,    34,    35,     0,     0,    36,    37,    38,    39,
      40,    41,     0,    42,     0,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    80,    81,    82,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
      86,    87,   386,   356,    88,     0,    89,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   356,     0,     0,     0,     0,     0,     0,   107,
       0,   108,     7,     8,   357,   358,   359,   360,   361,   362,
     363,   364,   365,     0,     0,     0,     0,   366,   367,   368,
     369,     0,     0,     0,     0,   370,   371,   372,     0,     0,
     373,     0,   374,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   375,     0,     0,   376,   366,   367,   368,   369,
       0,     0,     0,     0,   370,   371,   372,     0,     0,   373,
       0,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   375,     0,     0,   376,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,     0,   718,    49,
       0,    51,   719,     0,   720,   721,     0,     0,     0,     0,
     979,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,     0,   980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     377,   378,   379,     0,     0,     0,     0,    85,    86,    87,
       0,   380,     0,     0,     0,   381,     0,   382,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   377,
     378,   379,     0,     0,     0,     0,     0,     0,     0,     0,
     380,     0,     0,     0,   381,     0,   382,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,     0,   718,    49,     0,
      51,   719,     0,   720,   721,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,    85,    86,    87,     0,
       0,     0,     0,     0,     0,   936,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1080,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1090,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1091,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1092,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1097,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1100,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1205,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1226,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1310,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1394,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1395,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1437,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1559,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1560,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1561,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1575,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1703,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1816,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1817,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1844,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1847,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1913,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1966,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1967,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1981,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1983,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2015,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2042,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2047,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2048,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2049,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2088,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,   770,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,  1015,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,  1067,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
    1110,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,  1111,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,  1153,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,  1184,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,  1202,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,  1258,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,  1353,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,  1396,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,  1468,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,  1469,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
    1470,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,  1471,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,  1748,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,  1759,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,  1796,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,  1863,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,  1878,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,  1890,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,  1929,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,  1946,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
    1955,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,  1956,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,     0,     0,  1979,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,     0,     0,  2028,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,  2067,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,  2086,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,  2106,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,  2107,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
       0,     0,  2108,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,     0,
     883,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,     0,  1856,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,   705,     0,   706,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,   942,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,   993,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,  1134,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,  1197,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
    1198,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,     0,     0,  1203,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   679,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,     0,     0,  1204,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   679,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,     0,
       0,  1294,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   679,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,     0,     0,  1307,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   679,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,     0,     0,  1500,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
       0,     0,  1581,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   679,   554,   555,   556,
     557,     0,     0,     0,     0,   558,     0,     0,     0,  1628,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   679,   554,   555,   556,   557,     0,     0,
       0,     0,   558,     0,     0,     0,  1808,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     679,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,     0,     0,  1849,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   679,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,     0,     0,
    1864,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   751,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     752,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   753,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     755,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   756,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     757,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   759,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     760,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   761,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     762,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   763,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     764,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   765,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     767,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   768,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     769,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   833,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     868,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   912,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     930,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   932,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     933,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   934,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     940,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   941,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     978,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   992,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1047,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1051,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1063,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1133,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1142,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1143,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1144,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1154,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1183,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1185,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1186,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1187,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1188,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1189,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1190,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1191,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1196,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1293,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1306,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1501,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1567,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1580,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1691,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1693,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1696,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1702,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1749,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1758,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1781,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1848,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    1911,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  1912,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
    2041,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   679,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,  2083,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   679,
     554,   555,   556,   557,     0,     0,     0,     0,   558
};

static const yytype_int16 yycheck[] =
{
       3,     3,     3,  1178,   292,   594,   595,   134,   147,  1182,
      55,  1659,   304,  1661,   700,  1359,     4,    20,     9,   178,
      20,    48,   708,     4,     4,     7,     4,   186,     5,     4,
     322,    99,  1616,   101,     4,     4,     4,     4,  1646,     5,
       4,  1829,   128,     6,     6,    48,    90,     5,     5,    93,
       6,   148,    96,    54,     4,     4,    96,     6,    96,     6,
       6,     6,   238,     4,   240,   109,   134,    90,   244,     9,
       9,   247,    75,     0,     7,     4,   173,   226,   227,   119,
      83,   119,     4,   239,     4,    88,   109,     4,   156,     9,
     176,   247,   189,   190,   226,   227,    99,   389,   247,   391,
    1708,     9,    83,   128,   226,   227,   239,   399,   241,     7,
      93,   243,     9,    96,   247,   274,   275,   276,   238,     9,
     145,   128,   226,   227,   684,   247,   109,    14,   153,   154,
     155,   134,     6,   135,   159,   160,   139,   140,   145,  1723,
     238,    90,     6,   247,   147,     6,   153,   154,   155,    99,
     100,     7,   159,   160,   157,   715,   315,   316,   317,   241,
     187,     6,    96,     7,   239,   247,   226,   227,   239,   244,
     173,   731,   238,   332,   240,   178,   247,     7,   181,   739,
       6,   247,     6,   186,   187,   188,  1974,   247,   163,   164,
     165,   166,   226,   227,   226,   227,     7,   239,   161,   161,
     226,   227,   241,   184,     7,   247,   173,   174,   247,   173,
     174,   238,    96,   247,    98,   247,   235,   236,   243,   188,
     242,   247,   210,   239,   246,   244,   227,   238,  1572,   210,
     238,   247,   210,   239,   242,   238,   243,  1412,   134,   240,
     210,   247,   210,   139,   140,     6,   273,   238,   251,   240,
     239,   254,   255,    61,    62,   255,    64,   245,   247,   286,
     240,   242,   244,   290,   242,   242,   246,   270,   243,  1853,
     273,   274,   275,   276,   242,   835,   242,   173,   211,   212,
     213,   214,   238,   286,   242,   242,   242,   290,   210,   292,
     210,   583,   188,   585,   586,   242,   242,   238,   238,   238,
     240,   240,   235,   236,   244,   244,   992,   993,     4,   238,
     602,   244,   315,   316,   317,   235,   236,   239,   238,   241,
     240,   238,   242,  1907,   244,     8,   239,   235,   236,   332,
     238,     4,   240,   241,   247,   338,   244,   405,   235,   236,
     238,   238,   240,   240,     6,   235,   236,   244,   238,   641,
     240,     6,   226,   227,   244,   211,   212,   213,   214,     6,
     519,  2009,   226,   227,   240,   226,   227,   211,   212,   213,
     214,   238,   511,   240,   401,   402,   221,   222,   240,   235,
     236,   211,   212,   213,   214,   238,   226,   227,   680,   242,
     417,   235,   236,   396,   397,   221,   222,   238,   401,   402,
     211,   212,   213,   214,   238,   235,   236,   247,   211,   212,
     213,   214,   226,   227,   417,   243,   238,    90,   240,   247,
     423,    94,   226,   227,   226,   227,   427,   100,   101,   244,
     103,   104,   247,   247,   226,   227,   132,   133,   134,   135,
     238,   444,   239,   247,   241,   247,   128,   226,   227,   122,
     247,   147,   238,   243,   150,   247,   524,   247,   226,   227,
    2044,   226,   227,   145,   226,   227,   469,   239,   247,   241,
     243,   153,   154,   155,   247,   247,   243,   159,   160,   247,
     247,   508,   247,   226,   227,   247,    93,   295,   296,    96,
     493,   518,   226,   227,   238,   303,   304,   500,   501,   242,
     396,  1845,   505,   238,   507,   508,   509,   510,   511,   238,
     649,   514,  2096,   247,   238,   518,   519,   520,   521,   522,
     523,   238,   525,   523,   527,   525,    93,   238,   244,    96,
     246,    98,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     553,   226,   227,   128,   237,   242,   559,  1117,   238,  1119,
     243,   243,   226,   227,   238,   226,   227,   242,   226,   227,
     145,   128,  1132,   700,   111,   578,   579,    96,   153,   154,
     155,   231,   232,   247,   159,   160,   247,   237,   145,   247,
     235,   236,   594,   595,   662,   887,   153,   154,   155,   600,
     226,   227,   159,   160,   238,   226,   227,   226,   227,   505,
       6,   507,   238,   509,   510,   243,   242,   226,   227,   247,
     621,   624,   625,   626,   520,   521,   247,    93,   247,   238,
      96,   242,    98,   242,    90,   132,   133,    93,   226,   227,
      96,   138,    98,   109,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   109,   657,   658,   659,   660,   661,   238,
     663,   664,   665,   666,   667,   238,   666,   670,   243,   239,
     697,   241,   673,   226,   227,   676,   721,   247,   681,  1239,
      90,   242,   750,    93,    98,  1245,    96,   688,    98,   242,
     239,   239,   241,   241,   697,     8,   235,   236,   247,  1385,
     235,   236,   243,   242,   707,   238,   247,   242,   238,   712,
     226,   227,   228,   229,   230,   231,   232,   132,   133,   720,
      96,   237,   243,   138,   727,   728,   247,   238,   238,   240,
     733,     8,  1292,   736,   737,    93,   238,   864,   240,   742,
     242,   744,   238,   243,   240,  1305,   242,   247,   238,   243,
     240,  1311,   648,   247,   650,   651,   652,   653,   654,   655,
     242,   657,   658,   659,   660,     6,     7,   663,   664,   665,
     773,   242,   775,   228,   229,   230,   231,   232,   239,   243,
     241,   242,   237,   247,   592,   593,   243,    96,  1474,   597,
     247,   243,   243,   243,   243,   247,   247,   247,   247,   243,
    1486,   238,   243,   247,   243,   808,   247,    93,   247,   877,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,  1998,   243,   243,    93,   237,
     247,   247,   243,   238,   243,   240,   247,   243,   247,   243,
     736,   247,   243,   247,    96,   243,   247,   874,   744,   247,
     853,     4,   243,   243,   243,  2030,   247,   247,   247,   239,
     243,   241,   242,   866,   247,   992,   993,     4,   243,   243,
     243,   874,   247,   247,   247,   243,   238,   243,   240,   247,
     883,   247,  2055,     6,     7,   886,   243,   888,   889,   243,
     247,   243,   243,   247,     4,   247,   247,     4,  2073,     6,
       4,   902,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     238,   243,   238,   243,   237,   247,   994,   247,   238,   243,
     243,   243,     8,   247,   238,   247,   937,   238,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,     6,   984,     6,   243,
     237,   243,   239,   247,   241,   247,     6,   243,   240,   243,
     243,   247,   973,   247,   247,   243,  1003,   238,   240,   247,
     246,   984,   242,   242,     6,   238,  1274,   238,   246,     9,
     238,   238,   242,   238,   238,   998,   176,   176,   176,   242,
    1003,   119,   238,   238,   238,   238,  1133,  1134,   176,   238,
     242,  1014,  1601,  1602,   238,   242,  1019,   242,  1045,  1046,
       4,  1048,  1049,  1050,   242,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,   242,   242,   238,   238,   238,
     238,   238,  1045,  1046,   238,  1048,  1049,  1050,   238,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,     6,
       6,  1064,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,  1102,   238,   240,     6,   237,
     240,   242,   890,   242,     6,   242,   242,     6,   240,   897,
     240,   242,   176,   901,   238,   238,   238,  1124,   238,  1102,
    1103,  1104,   238,   238,     6,     6,   240,     6,     8,   242,
       6,     8,   242,  1140,     7,     6,   242,     6,   242,    86,
     247,  1124,   243,  1019,   239,   247,     7,     6,     6,   242,
     239,   242,   237,    64,     8,     4,   244,  1140,  1141,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,     7,     7,  1160,
     238,   237,     6,   239,   239,  1192,  1293,  1294,     6,  1461,
     242,     7,     6,  1465,     7,     6,     6,   243,   173,  1206,
    1207,  1208,   242,   239,   243,   243,   241,     6,   242,  1192,
     242,   242,     7,  1481,     6,   242,   240,   238,   244,   242,
       4,     6,   239,  1206,  1207,  1208,     6,  1103,  1104,     6,
       6,   240,     7,     6,  1217,     7,     7,     7,     7,  1222,
       7,     7,     7,  1226,     7,     7,     7,     7,  1255,     7,
       7,     7,  1235,     7,  1237,   242,  1044,  1240,     6,   239,
     241,   247,   247,   247,   243,  1313,   239,  1315,  1249,   247,
       7,   242,  1255,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   243,
    1859,  1274,   244,   237,     7,     4,   242,   128,     6,   244,
     243,   243,     7,     6,   244,     7,     7,     7,  1315,   239,
     239,  1294,   247,   247,     9,   247,  1299,  1324,   239,   241,
     244,  1328,     7,   246,   176,   148,   243,   242,     6,     6,
       6,     4,  1315,   238,    46,    46,   242,   244,   238,     4,
     244,  1324,   238,   244,   238,  1328,  1222,     7,     7,     6,
    1226,     7,   247,   239,   176,     7,     7,     7,     6,  1235,
     247,  1237,     7,     7,  1240,   239,     7,  1474,  1487,  1488,
       4,     4,  1379,  1380,  1381,   108,   242,     6,   238,     7,
    1387,     6,    96,     7,     7,     7,     7,     7,     7,     7,
       6,   242,     6,     6,     6,  1402,  1379,  1380,  1381,     7,
       6,     4,     4,   245,  1387,  1673,  1413,   247,   247,  1457,
     242,   239,     6,     6,  1421,   242,   242,     6,  1294,  1402,
       7,     6,   243,   240,     6,     6,   238,   242,     6,   238,
    1413,     6,     6,     6,   122,   243,   241,   244,  1421,     6,
       6,  1424,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     247,     6,     6,     6,   237,     6,     6,     6,     6,     6,
    1518,     6,  1579,     6,     5,   239,     6,     4,     6,     4,
     239,     7,     6,     6,     6,   240,  1493,     6,     6,   242,
     242,   242,   242,   242,     6,   242,   242,   242,  1481,   242,
     242,   242,   242,     6,  1487,  1488,   172,     6,     6,     6,
    1493,  1518,   247,   247,   239,   247,   242,   247,     6,   238,
     244,     7,   242,     4,     6,   243,     6,  1510,     6,     6,
       4,   238,   238,    94,     7,  1518,     6,     6,     6,     6,
    1523,     6,     5,   242,   242,   239,     6,     6,     6,  1597,
     247,   247,     6,     6,     6,   247,   239,  1676,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   247,     6,     4,     6,
     237,     6,  1689,  1590,   247,     6,     6,   242,     6,   242,
       7,  1639,     5,   242,     6,   242,  1868,     6,  1646,  1647,
     242,   239,   242,     6,   243,   242,     6,  1590,   243,  1616,
    1593,  1594,     7,     6,   171,   242,     6,  1665,     6,  1601,
    1602,     7,   239,  1411,  1631,     6,     6,     6,  1896,   244,
       6,     6,   243,  1616,  1510,     6,   243,     6,   243,  1622,
     239,   242,     6,   243,   242,     6,     6,   242,  1631,   239,
     238,   243,   243,   174,     6,  1662,   242,     6,  1641,   242,
       6,  1644,   242,     6,   243,   242,   128,     6,  1675,     6,
     242,   239,     6,     6,     6,     6,     6,     6,  1659,  1662,
    1661,   243,     6,   243,     6,     6,  1669,     6,  1960,   242,
    1673,     6,  1675,  1676,   242,     6,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,     6,     6,  1723,     6,   237,     6,
       6,     6,   242,  1304,  2011,  1708,   441,  1999,  1354,  1528,
    1793,  1830,   573,     4,     5,  1586,     3,  1323,     3,     3,
    1723,     3,  1454,     3,  1532,  1855,  1669,  1795,  1646,  1488,
    1757,    -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1641,    -1,    -1,  1644,    -1,
      -1,    -1,    -1,    -1,  1757,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,  1769,  1835,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,  1782,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1819,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1831,    -1,    -1,    -1,    -1,  1617,
    1618,  1619,  1620,  1621,  1622,    -1,  1819,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1853,    -1,  1831,    -1,
      -1,    -1,    -1,  1836,  1837,  1838,    -1,    -1,    -1,    -1,
    1867,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,    -1,    -1,  1856,    -1,    -1,    -1,  1859,    -1,    -1,
      -1,    -1,    -1,    -1,  1867,    -1,    -1,    -1,  1871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1907,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1896,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,   194,  1907,    -1,  1933,  1975,    -1,    -1,
      -1,    -1,   203,    -1,    -1,   107,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,  1945,    -1,   138,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
     162,   163,   164,    -1,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2001,  2002,
    2003,  2004,  2005,    -1,    -1,    -1,    -1,    -1,  2009,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2044,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2031,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2060,   250,   251,
     252,   253,   254,    -1,  1872,  1873,  1874,  1875,  1876,  2096,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,  2082,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2096,    -1,    -1,   288,    -1,    -1,    -1,
    2103,  2104,    -1,    -1,    -1,    -1,   298,   299,    -1,    -1,
      -1,    -1,   304,    -1,  2117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   314,    -1,  1932,    -1,    -1,    -1,  1936,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,
     342,   343,   344,    -1,   346,    -1,    -1,    -1,   350,   351,
     352,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1985,    -1,    -1,
      -1,  1989,    -1,    -1,    -1,    -1,  2082,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2005,    -1,    -1,
      -1,   393,    -1,    -1,    -1,   397,   398,  2103,  2104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2117,   414,   415,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,  2050,  2051,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,
      -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   468,   469,    -1,    -1,
      -1,   473,    -1,    -1,    -1,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
      -1,   503,   504,   181,   506,    -1,    -1,    -1,    -1,    -1,
      -1,   513,    -1,    -1,   516,   517,    -1,    -1,    -1,    -1,
     522,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,    -1,   560,   561,
      -1,    -1,    -1,    -1,    -1,   567,   568,   569,    -1,    -1,
      -1,    -1,    -1,   575,   576,    -1,   578,   579,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,     4,     5,   597,   598,   599,    -1,    -1,
      -1,   603,   604,   605,   606,   607,   608,   609,   610,   611,
      -1,    -1,    -1,    -1,   616,    -1,   618,    -1,   620,    -1,
      -1,    -1,   624,   625,   626,   627,    -1,   629,   630,   631,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,   656,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,   670,    -1,
      -1,    -1,    -1,    84,    -1,   677,    87,   679,   181,    -1,
     682,   683,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   691,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   707,    -1,     6,    -1,    -1,
      -1,   713,   714,    -1,   125,    -1,    -1,    -1,    -1,   397,
      -1,    -1,    -1,    -1,    -1,   727,    -1,   729,   730,    -1,
      -1,   733,   734,    -1,    -1,    -1,   738,    -1,    -1,    -1,
      -1,    -1,    -1,   745,    -1,    -1,    -1,   749,   251,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,   771,
      -1,   773,    -1,   775,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,    -1,    -1,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   808,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,    -1,
      -1,     6,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,   244,    -1,   338,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
      -1,   853,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   866,    -1,    -1,    -1,    -1,    -1,
      -1,   873,    -1,    -1,    -1,   877,    -1,    -1,    -1,    -1,
      -1,   883,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   891,
     892,    -1,    -1,    -1,   397,   897,    -1,    -1,    -1,    -1,
     578,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   913,    -1,    -1,   916,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   936,     6,   938,   939,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,   625,   626,    -1,
      -1,    -1,    -1,    -1,    -1,   957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   980,    -1,
      -1,    -1,    -1,    -1,    -1,   987,   988,   989,   990,    -1,
     493,    -1,   670,   995,    -1,    -1,    -1,   500,   501,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1009,  1010,    -1,
      -1,    -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,   522,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,   707,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   727,
     553,    -1,   237,    -1,    -1,   733,    -1,    -1,    -1,    -1,
      -1,    -1,  1064,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   578,   579,    -1,  1080,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1090,  1091,
    1092,    -1,    -1,    -1,    -1,  1097,  1098,    -1,  1100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1112,  1113,    -1,    -1,    -1,    -1,    -1,    -1,  1120,  1121,
      -1,   624,   625,   626,    -1,  1127,    -1,  1129,  1130,    -1,
     808,    -1,    -1,    -1,  1136,  1137,    -1,    -1,    -1,  1141,
      -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,   670,    -1,    -1,
    1172,    -1,    -1,    -1,    -1,   853,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   866,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1205,   707,   883,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1225,   727,    -1,    -1,    -1,    -1,    -1,
     733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1246,  1247,    -1,    -1,    -1,  1251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1265,    -1,    -1,  1268,    -1,    -1,    -1,
     773,    -1,   775,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1295,    -1,    -1,  1298,  1299,  1300,    -1,
      -1,    -1,    -1,    -1,    -1,   808,  1308,    -1,  1310,    -1,
    1312,  1313,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,  1014,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
     853,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,   419,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     883,    -1,    -1,    -1,  1386,    -1,  1064,    -1,    -1,    -1,
      -1,  1393,  1394,  1395,    -1,    -1,    -1,   125,    -1,    -1,
    1402,    -1,  1404,    -1,    -1,    -1,    -1,    -1,    -1,  1411,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1424,    -1,    -1,    -1,    -1,  1429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1437,  1438,  1439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   514,  1459,    -1,    -1,
      -1,    -1,    -1,  1141,   192,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,
      -1,   209,   210,  1485,    -1,    -1,    -1,    -1,    -1,  1491,
    1492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,
      -1,  1014,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,  1523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1559,  1560,  1561,
      -1,  1064,    -1,    -1,    -1,    -1,    -1,    -1,  1570,    -1,
      -1,    -1,    -1,  1575,  1576,  1577,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1588,    -1,    -1,    -1,
      -1,  1593,  1594,  1595,    -1,  1597,    -1,    -1,    -1,    -1,
      -1,  1603,  1604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1622,  1299,    -1,    -1,  1626,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1639,  1141,    -1,
    1642,    -1,    -1,    -1,  1646,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1655,  1656,    -1,  1658,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1666,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1682,    -1,    -1,    -1,    -1,  1687,  1688,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1700,    -1,
      -1,  1703,  1704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,  1735,   792,   793,   794,   795,    -1,   797,
     798,   799,   800,     4,     5,    -1,  1424,    -1,    -1,  1751,
      -1,    -1,    -1,   811,    -1,   813,    -1,    -1,  1760,    -1,
      -1,    -1,    -1,   821,    -1,    -1,    -1,  1769,    -1,   827,
     828,    -1,    -1,    -1,    -1,    -1,  1778,  1779,   836,    -1,
    1782,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,  1299,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,  1816,  1817,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,  1834,    -1,    -1,  1837,  1838,  1839,    -1,    -1,
      -1,    -1,  1844,    -1,    -1,  1847,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,  1871,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1879,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   943,   944,   945,    -1,    -1,
      -1,   949,   950,    -1,    -1,   953,   954,   955,   956,    -1,
     958,    -1,  1904,    -1,    -1,   963,    -1,    -1,  1910,    -1,
      -1,  1913,     4,     5,    -1,  1593,  1594,     6,    -1,    -1,
      -1,  1424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,  1941,
      -1,    -1,   203,    -1,    -1,    -1,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,  1966,  1967,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,  1980,  1981,
      72,  1983,    74,    -1,  1042,  1043,     6,    -1,    -1,    -1,
      -1,    -1,    84,    -1,  1996,    87,    -1,    -1,    -1,  2001,
    2002,  2003,  2004,  2005,    -1,    -1,    -1,    -1,    -1,  2011,
      -1,    -1,    -1,  2015,    -1,    -1,    -1,    -1,    -1,    -1,
    1523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
    2042,    -1,    -1,    -1,    -1,  2047,  2048,  2049,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    -1,  2060,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
    1138,   237,    -1,    -1,    -1,    -1,  2088,  2089,  2090,    -1,
    1593,  1594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,    -1,  1782,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,   207,    -1,   209,   210,  1622,
      -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,   239,   237,   241,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1837,
    1838,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1856,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1871,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,  1277,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,  1314,   224,   225,    -1,
      -1,    -1,    -1,    -1,   231,   232,  1769,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,  1782,
      -1,    -1,    -1,    -1,  1342,  1343,  1344,  1345,  1346,    -1,
      -1,    -1,    -1,  1351,  1352,    -1,    -1,  1355,    -1,  1357,
      -1,    -1,    -1,  1361,    -1,    -1,  1364,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,
      -1,    -1,    -1,  2001,  2002,  2003,  2004,  2005,    -1,    -1,
      -1,    -1,    -1,    -1,  1837,  1838,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2060,    -1,    -1,    -1,    -1,  1445,    -1,  1447,
     357,   358,   359,  1451,     7,  1453,   363,   364,   365,   366,
     367,   368,   369,    -1,   371,    -1,    -1,    -1,   375,   376,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,  1487,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     6,    -1,    -1,    -1,  2001,  2002,
    2003,  2004,  2005,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
    1578,     6,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,  2060,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   119,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
    1678,    -1,    -1,  1681,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,  1724,  1725,    -1,  1727,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,    -1,     6,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,  1786,  1787,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,  1832,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,   831,   105,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,   865,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,    -1,    -1,   245,     3,     4,     5,    -1,
      -1,  2069,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,  1036,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    -1,
      87,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,     6,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,    -1,  1125,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,   192,   193,   194,   195,   196,
       6,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,   242,    -1,    -1,   245,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,  1278,  1279,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    -1,    87,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,  1359,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1369,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
     184,   237,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,
     194,   195,    -1,    -1,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   235,   236,    -1,   238,    -1,   240,     3,     4,    -1,
     244,   245,     8,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,  1522,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,   122,   123,   191,   125,   126,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,
     169,   170,   238,     3,     4,     5,    -1,   243,    -1,   245,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,
      13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,   122,
     123,   191,   125,   126,    -1,   195,   196,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
     210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,     3,
       4,    -1,   242,    -1,    -1,   245,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    75,    76,    77,    -1,    -1,    13,    14,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,   122,   123,   191,   125,   126,
      -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   168,   169,   170,   238,     3,     4,    -1,   242,   243,
      -1,   245,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,
      -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,    -1,   242,    -1,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,    14,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,    -1,   122,   123,   191,
     125,   126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,   168,   169,   170,   238,     3,     4,    -1,
     242,    -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,   122,   123,   191,   125,   126,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,
     169,   170,   238,     3,     4,    -1,   242,    -1,    -1,   245,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,
      13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,   122,
     123,   191,   125,   126,    -1,   195,   196,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
     210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,     3,
       4,    -1,    -1,   243,    -1,   245,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    75,    76,    77,    -1,    -1,    13,    14,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,   122,   123,   191,   125,   126,
      -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   168,   169,   170,   238,     3,     4,    -1,   242,    -1,
      -1,   245,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,
      -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,    -1,   242,    -1,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,    14,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   106,   107,   108,   109,    -1,    -1,   112,     7,     8,
      -1,    -1,    -1,    -1,   119,   120,    -1,   122,   123,   191,
     125,   126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,   168,   169,   170,   238,     3,     4,    -1,
     242,    -1,     8,   245,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,   150,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,     3,     4,
      -1,    -1,   238,     8,    -1,    10,    11,    12,    -1,   245,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,     3,
       4,    -1,    -1,   238,    -1,    -1,    10,    11,    12,    -1,
     245,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    13,    14,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,   122,   123,   191,   125,   126,
      -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   168,   169,   170,   238,     3,     4,    -1,   242,    -1,
      -1,   245,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,
      -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,   112,     8,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,    -1,   242,    -1,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,     3,     4,     5,    -1,   238,    -1,    -1,    10,
      11,    12,    -1,   245,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    -1,    87,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,   242,    -1,    -1,   245,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,   192,   193,   194,   195,
      -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,   238,     3,     4,     5,   242,    -1,    -1,   245,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,    -1,    -1,   245,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,     8,    -1,    -1,    -1,    -1,   191,   192,   193,   194,
     195,    -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,     3,
       4,    -1,    -1,   238,    -1,    -1,    10,    11,    12,    -1,
     245,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,     3,     4,    -1,    82,    83,
      -1,    85,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,    -1,
      -1,   245,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,   191,   237,    -1,    -1,   195,    -1,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
     238,     3,     4,    -1,   242,    -1,     8,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,   239,    -1,   241,    -1,    -1,   191,
      -1,    -1,   247,   195,    -1,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,   191,    -1,   237,    -1,   195,
      -1,    -1,    -1,   243,   200,   201,   202,   247,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,     3,     4,
      -1,     6,   238,   239,    -1,    10,    11,    12,    -1,   245,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,     3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,   191,    -1,   237,    -1,
     195,    -1,    -1,    -1,   243,   200,   201,   202,   247,   204,
     205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,   239,    -1,    -1,   191,
      -1,    -1,    -1,   195,   247,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,     3,     4,    -1,     6,   238,    -1,    -1,    10,
      11,    12,    -1,   245,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,     3,     4,
      -1,    82,    83,    -1,    85,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,
     191,    -1,    -1,   247,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,   191,    -1,   237,    -1,
     195,    -1,    -1,    -1,    -1,   200,   201,   202,   247,   204,
     205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,     3,
       4,    -1,    -1,   238,   239,    -1,    10,    11,    12,    -1,
     245,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,     3,     4,    -1,    82,    83,
      -1,    85,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,
     247,   195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
      -1,   245,    13,    14,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   191,    -1,    -1,   237,   195,    -1,    -1,
      -1,   242,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    13,    14,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   168,   169,   170,
     237,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,   107,   108,
     109,   110,   243,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,     4,    -1,   156,   157,   158,
      -1,    -1,    -1,   162,    13,    14,    -1,    -1,   167,   168,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    44,    45,    -1,   197,   198,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,   210,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,   107,   108,
     109,   110,    -1,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,   156,   157,   158,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,     4,     5,   173,    -1,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,
     199,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,   210,    13,    14,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    84,    -1,    -1,    87,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,    -1,    -1,    -1,    -1,
     131,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,    -1,    -1,    -1,    -1,   168,   169,   170,
      -1,   203,    -1,    -1,    -1,   207,    -1,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,    -1,    -1,    -1,   207,    -1,   209,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,
     122,   123,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,   243,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,   243,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
     243,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,   243,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,   243,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,   243,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,   243,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,   243,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,   243,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
     243,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,   243,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,   243,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,   243,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,   243,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,   243,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,   243,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
     243,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,   243,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,   243,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,   243,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,   243,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,   243,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
     242,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,   242,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,    -1,   241,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,   241,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,   241,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,   241,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,   241,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
     241,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,   241,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,   241,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,   241,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,   241,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,   241,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,   241,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,   241,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,   241,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,   241,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
     241,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   249,   250,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    80,    81,
      83,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   105,   106,   107,   108,
     109,   110,   112,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     156,   157,   158,   162,   167,   168,   169,   170,   173,   175,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   197,   198,   199,   208,   210,   251,
     253,   254,   274,   292,   294,   298,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   316,   318,   319,   325,   326,
     327,   328,   334,   359,   360,   242,   246,    14,    96,   238,
     238,     6,   242,     6,     6,     6,     6,   238,     6,   240,
     240,     4,   336,   360,   238,   240,   272,   272,   238,   238,
     238,     4,   238,   238,   238,     4,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   242,   111,    96,
       6,   242,    90,    93,    96,   109,   297,    98,   238,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    55,    56,    57,    58,    63,    64,    75,    76,
      77,    82,    85,    90,    93,    96,    98,   109,   119,   123,
     125,   191,   195,   196,   200,   201,   202,   204,   205,   206,
     226,   227,   233,   238,   242,   245,   294,   295,   298,   309,
     316,   318,   329,   330,   334,   336,   343,   345,   360,   238,
     242,    96,    96,   119,    93,    96,    98,    90,    93,    96,
      98,   294,    93,    96,    98,   109,   295,    93,    96,   238,
      93,   148,   173,   189,   190,   242,   226,   227,   238,   242,
     340,   341,   340,   242,   242,   340,     4,    90,    94,   100,
     101,   103,   104,   122,   238,    96,    98,    96,    93,     4,
      83,   184,   242,   360,     4,     6,    90,    93,    96,    93,
      96,   109,   296,     4,     4,     4,     5,   238,   242,   343,
     344,     4,   238,   238,   238,     4,   242,   347,   360,     4,
     238,   238,   238,     6,     6,   240,     5,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    59,    60,    61,    62,
      67,    68,    69,    72,    74,    84,    87,   192,   193,   194,
     203,   207,   209,   351,   360,   238,     4,   351,     5,   242,
       5,   242,    32,   227,   329,   360,   240,   242,   238,   242,
       6,   238,   242,     6,   246,     7,   125,   184,   211,   212,
     213,   214,   235,   236,   238,   240,   244,   270,   271,   272,
     329,   350,   351,   360,     4,   298,   299,   300,   242,     6,
     329,   350,   351,   360,   350,   329,   350,   357,   358,   360,
     276,   280,   238,   339,     9,   351,   360,   329,   329,   329,
     238,   329,   329,   329,   238,   329,   329,   329,   329,   329,
     329,   329,   350,   329,   329,   329,   329,   344,   238,   227,
     329,   345,   346,   242,   344,   343,   350,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     238,   240,   272,   272,   272,   272,   272,   272,   238,   272,
     272,   238,   294,   272,   272,     5,   242,   242,   119,   294,
     238,   272,   272,   238,   238,   238,   329,   242,   329,   345,
     329,   329,   243,   346,   336,   360,   176,     5,   242,     8,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   237,     9,
     238,   240,   244,   271,   272,   329,   346,   238,   238,   238,
     343,   344,   344,   344,   293,   242,   238,   343,   242,   242,
     329,     4,   343,   242,   347,   242,   242,   340,   340,   340,
     329,   329,   226,   227,   242,   242,   340,   226,   227,   238,
     300,   340,   242,   238,   242,   238,   238,   238,   238,   238,
     238,   238,   329,   344,   344,   344,   238,     4,   240,     6,
     240,   300,     6,     6,   242,   242,   242,   242,   344,   240,
     240,   240,   329,     8,     6,     6,   329,   329,   329,   244,
     329,   242,   176,   329,   329,   329,   329,   272,   272,   272,
     238,   238,   238,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   238,   238,   272,   238,   240,     6,     6,
     242,     6,     8,   300,     6,     8,   300,   272,   329,   228,
     242,     9,   238,   240,   244,   350,   346,   329,   300,   343,
     343,   242,   351,    90,    93,    96,    98,     7,   329,   329,
       4,   173,   174,   343,     6,   239,   241,   242,   273,     6,
     242,     6,     9,   238,   240,   244,   360,   243,   119,   123,
     125,   126,   292,   294,   329,     6,   239,   247,     9,   238,
     240,   244,   239,   247,   247,   239,   247,     9,   238,   244,
     241,   247,   275,   241,   275,    86,   338,   335,   360,   247,
     247,   239,   239,   239,   329,   239,   239,   239,   329,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     243,     7,   329,   228,   243,   247,   329,     6,     6,   239,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   345,   329,   329,
     329,   329,   329,   329,   329,   345,   345,   360,   242,   329,
     329,   350,   329,   350,   343,   350,   350,   357,   242,   329,
     273,   360,     8,   329,   329,   344,   350,   350,   345,   336,
     351,   336,   346,   239,   243,   244,   272,    64,     8,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   242,   329,   345,   329,   329,   329,   329,
     329,   360,   329,   329,     4,   337,   242,   273,   239,   243,
     329,   329,   329,     7,     7,   322,   322,   238,   329,   329,
       6,   346,   346,   242,   239,     6,   300,   242,   300,   300,
     247,   247,   247,   340,   340,   299,   299,   247,   329,   243,
     313,   247,   300,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   239,     7,   323,     6,     7,   329,     6,   329,
     329,   243,   346,   346,   346,   329,     6,   329,   329,   329,
     239,   243,   239,   239,   239,   173,   247,   300,   242,     8,
     239,   239,   241,   357,   350,   357,   350,   350,   350,   350,
     350,   350,   329,   350,   350,   350,   350,   245,   353,   360,
     351,   350,   350,   350,   336,   360,   346,   243,   243,   243,
     243,   329,   329,   300,   360,   337,   241,   243,   239,   131,
     148,   317,   239,   243,   247,   329,     6,   242,   242,   242,
     242,   343,   239,   241,     7,   270,   271,   244,     7,     6,
     346,     7,   214,   270,   255,   360,   329,   329,   337,   240,
     238,   119,   294,   295,   242,   243,     6,   221,   222,   252,
     346,   360,   329,   329,     4,   337,     6,   346,   329,     6,
     350,   358,   360,   239,   337,     6,   360,     6,   350,   329,
     239,   240,   329,   351,     7,     7,     7,   239,     7,     7,
       7,   239,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   329,   239,   242,   329,   345,   243,     6,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     247,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     247,   247,   247,   239,   241,   241,   346,   247,   247,   273,
     247,   273,   247,   247,   247,   239,   329,   331,   273,   243,
     243,   243,   247,   247,   273,   273,   239,   244,   239,   244,
     247,   272,   332,   243,     7,   337,   273,   242,   243,     8,
       8,   346,   244,   239,   241,   271,   238,   240,   272,   346,
       7,   242,   239,   239,   239,   329,   343,     4,   321,     6,
     289,   329,   351,   243,   239,   243,   243,   346,   244,   243,
     300,   243,   243,   340,   329,   329,   243,   243,   329,   340,
     128,   128,   145,   153,   154,   155,   159,   160,   314,   315,
     340,   243,   310,   239,   243,   239,   239,   239,   239,   239,
     239,   239,     7,   329,     6,   329,   239,   241,   241,   243,
     243,   243,   243,   241,   241,   247,     7,     7,     7,   244,
     329,   243,   329,   329,     7,   244,   273,   247,   273,   273,
     239,   239,   247,   273,   273,   247,   247,   273,   273,   273,
     273,   329,   273,     9,   352,   247,   239,   247,   273,   244,
     247,   333,   241,   243,   243,   244,   238,   240,   246,   176,
       7,   148,     6,   329,   243,   242,     6,   343,   243,   329,
     329,   329,   329,     6,     7,   270,   271,   244,   270,   271,
     351,   329,     6,     4,   242,   348,   360,   243,    46,    46,
     343,     4,   163,   164,   165,   166,   243,   258,   262,   265,
     267,   268,   244,   239,   241,   238,   329,   329,   238,   242,
     238,     8,   346,   350,   239,   244,   239,   241,   238,   239,
     247,   244,   238,     7,   272,     4,   283,   284,   285,   273,
     273,   340,   343,   343,     7,   343,   343,   343,     7,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,     6,
       7,   346,   329,   329,   329,   329,   243,   329,   329,   329,
     343,   350,   350,   243,   247,   282,   329,   329,   337,   337,
     329,   329,   239,   343,   272,   329,   329,   329,   243,   337,
     271,   244,   271,   329,   329,   273,   243,   343,   346,     7,
       7,     7,   128,   320,     6,   239,   247,     7,     7,     7,
     243,     4,   243,   247,   247,   247,   243,   243,   108,     4,
       6,   329,   242,     6,   238,     6,   161,     6,   161,   243,
     315,   247,   314,     7,     6,     7,     7,     7,     7,     7,
       7,     7,   343,     6,   242,     6,     6,     6,    96,     7,
       6,     6,   329,   343,   343,   343,     4,   247,     8,     8,
     239,     4,    99,   100,     4,   346,   350,   329,   350,   245,
     247,   286,   350,   350,   337,   350,   239,   247,   337,   242,
     294,   242,     6,   329,     6,   242,   343,   243,   243,   243,
     243,   243,   329,     6,     4,   173,   174,   329,     6,     6,
       6,     7,   347,   349,     6,   240,   273,   272,   272,     6,
     259,   238,   238,   242,   269,     6,   337,   244,   350,   329,
     241,   239,   329,     8,   346,   329,   243,   243,     6,     6,
     252,   337,   244,   329,     6,   329,   337,   239,   242,   329,
     351,   273,    46,   242,   343,   351,   354,   241,   247,     6,
       6,     6,   122,   291,   291,   343,     6,     6,     6,   343,
     128,   176,   290,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   243,   273,   273,   273,   273,   273,   247,
     247,   247,   239,   273,   273,   284,   273,   239,   273,   239,
     272,   332,   273,     6,   273,   247,   238,   240,   272,     4,
     239,   241,   273,     6,   243,   343,   343,   343,     4,     6,
     270,   329,   343,   242,   242,     7,     6,     7,   329,   329,
     329,   242,   242,   242,   240,     6,   329,   343,   329,     6,
       6,   329,   340,   243,     5,   343,   242,   242,   242,   242,
     242,   242,   242,   343,     6,   346,   242,   329,   241,     6,
       6,   172,   329,   329,   329,     6,     6,     6,     6,     7,
     273,   247,   247,   273,   247,   329,     4,   188,   287,   288,
     273,   239,   273,   333,   351,   238,   240,   329,   242,   300,
       6,   300,   247,     6,     6,     7,   270,   271,   244,     7,
       6,   347,   243,   247,   329,   270,   242,   273,   355,   356,
     357,   355,   238,   329,   329,   342,   343,   242,   238,     4,
       6,   239,     6,   239,   243,   243,   239,     6,     6,   350,
     238,     4,   239,   247,   238,   343,   351,     7,   272,   281,
     329,   345,   285,   340,     6,     6,     6,     6,    90,   109,
      94,     6,     5,   242,   329,   329,   329,   329,   239,   332,
     329,   329,   329,   273,   271,   242,     6,   290,     6,   329,
     343,     4,     6,   346,   346,   329,   329,   351,   243,   239,
     243,   247,   299,   299,   329,   329,   243,   247,   239,   243,
     247,     6,     6,   342,   340,   340,   340,   340,   340,   227,
     340,     6,   243,   329,     6,     6,   343,   243,   247,     8,
     243,   239,   242,   329,   351,   350,   329,   350,   329,   351,
     354,   356,   351,   247,   239,   247,   243,   329,   317,   317,
     343,   351,   329,     6,     4,   348,     6,   347,   241,   343,
     357,     6,   273,   273,   256,   329,   247,   247,   243,   247,
     257,   329,   329,     6,     6,     6,   329,   329,   239,   277,
     279,   242,   356,   243,   247,     7,     7,   242,   242,   242,
       5,   342,   273,   273,   247,   273,   239,   247,   239,   241,
     329,     6,     6,   242,   243,   243,   242,     6,     6,   242,
     329,   243,   243,   243,   241,     6,   343,     7,   242,   329,
     243,   247,   247,   247,   247,   247,   247,     6,   243,   171,
     329,   329,   346,     6,     6,   239,   273,   273,   288,   351,
     243,   243,   243,   243,     6,     6,     7,     6,   244,     6,
     243,     6,     6,   239,   247,   329,   329,   242,   343,   243,
     247,   239,   239,   247,   282,   286,   343,   273,   329,   351,
     360,   346,   346,   329,     6,   243,   329,   332,   329,   243,
     342,   132,   133,   138,   324,   132,   133,   324,   346,   299,
     243,   247,     6,   243,   343,   300,   243,     6,   346,   340,
     340,   340,   340,   340,   329,   243,   243,   243,   239,     6,
     242,     6,   347,   174,   260,   329,   247,   247,   342,     6,
     329,   329,   243,   243,   278,     7,   238,   243,   243,   243,
     242,   247,   239,   247,   243,   242,   340,   343,     6,   242,
     340,     6,   243,   243,   329,     6,   128,   243,   311,   242,
     243,   247,   247,   247,   247,   247,     6,     6,     6,   300,
       6,   242,   329,   329,   243,   247,   282,   351,   239,   329,
     329,   329,     6,   340,     6,   340,     6,     6,   243,   329,
     314,   300,     6,   346,   346,   346,   346,   340,   346,   317,
     257,   239,   247,     6,   242,   329,   243,   247,   247,   247,
     247,   247,     6,   243,   243,   312,   243,   243,   243,   243,
     247,   243,   243,   243,   263,   329,   342,   243,   329,   329,
     329,   340,   340,   314,     6,     6,     6,     6,   346,     6,
       6,     6,   242,   239,   243,     6,   243,   273,   247,   247,
     247,   243,   243,   261,   350,   266,   242,     6,   329,   329,
     329,     6,   243,   247,   242,   342,   243,   243,   243,     6,
     350,   264,   350,   243,     6,     6,   243,   247,     6,     6,
     350
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
#line 3224 "Gmsh.y"
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
#line 3242 "Gmsh.y"
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
#line 3259 "Gmsh.y"
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
#line 3274 "Gmsh.y"
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
#line 3307 "Gmsh.y"
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
#line 3319 "Gmsh.y"
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
#line 3343 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 261:
#line 3347 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 262:
#line 3352 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 263:
#line 3359 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 264:
#line 3364 "Gmsh.y"
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
#line 3374 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 266:
#line 3379 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 267:
#line 3385 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 268:
#line 3393 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 269:
#line 3397 "Gmsh.y"
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
#line 3407 "Gmsh.y"
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
#line 3470 "Gmsh.y"
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
#line 3486 "Gmsh.y"
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

  case 273:
#line 3503 "Gmsh.y"
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

  case 274:
#line 3520 "Gmsh.y"
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

  case 275:
#line 3542 "Gmsh.y"
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

  case 276:
#line 3564 "Gmsh.y"
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

  case 277:
#line 3599 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 278:
#line 3607 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3615 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 280:
#line 3621 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 281:
#line 3628 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3635 "Gmsh.y"
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
#line 3655 "Gmsh.y"
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
#line 3681 "Gmsh.y"
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
#line 3693 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 286:
#line 3704 "Gmsh.y"
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
#line 3722 "Gmsh.y"
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
#line 3740 "Gmsh.y"
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
#line 3758 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3764 "Gmsh.y"
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
#line 3782 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3788 "Gmsh.y"
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
#line 3808 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3814 "Gmsh.y"
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
#line 3832 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3838 "Gmsh.y"
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
#line 3855 "Gmsh.y"
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
#line 3871 "Gmsh.y"
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
#line 3888 "Gmsh.y"
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
#line 3905 "Gmsh.y"
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
#line 3928 "Gmsh.y"
    {
    ;}
    break;

  case 302:
#line 3931 "Gmsh.y"
    {
    ;}
    break;

  case 303:
#line 3937 "Gmsh.y"
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
#line 3949 "Gmsh.y"
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
#line 3969 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 306:
#line 3973 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 307:
#line 3977 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 308:
#line 3981 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 309:
#line 3985 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 310:
#line 3989 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 311:
#line 3993 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 312:
#line 3997 "Gmsh.y"
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
#line 4006 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 314:
#line 4018 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 315:
#line 4019 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 316:
#line 4020 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 317:
#line 4021 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 318:
#line 4022 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 319:
#line 4026 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 320:
#line 4027 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 321:
#line 4028 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 322:
#line 4029 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 323:
#line 4030 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 324:
#line 4035 "Gmsh.y"
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
#line 4058 "Gmsh.y"
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
#line 4078 "Gmsh.y"
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
#line 4099 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 328:
#line 4103 "Gmsh.y"
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
#line 4118 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 330:
#line 4122 "Gmsh.y"
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
#line 4138 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 332:
#line 4142 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 333:
#line 4147 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 334:
#line 4151 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 335:
#line 4157 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 336:
#line 4161 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 337:
#line 4168 "Gmsh.y"
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
#line 4190 "Gmsh.y"
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
#line 4231 "Gmsh.y"
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
#line 4275 "Gmsh.y"
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
#line 4314 "Gmsh.y"
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
#line 4339 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 343:
#line 4348 "Gmsh.y"
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

  case 344:
#line 4378 "Gmsh.y"
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

  case 345:
#line 4404 "Gmsh.y"
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

  case 346:
#line 4431 "Gmsh.y"
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

  case 347:
#line 4463 "Gmsh.y"
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

  case 348:
#line 4490 "Gmsh.y"
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

  case 349:
#line 4516 "Gmsh.y"
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

  case 350:
#line 4542 "Gmsh.y"
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

  case 351:
#line 4568 "Gmsh.y"
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

  case 352:
#line 4594 "Gmsh.y"
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

  case 353:
#line 4615 "Gmsh.y"
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

  case 354:
#line 4626 "Gmsh.y"
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

  case 355:
#line 4674 "Gmsh.y"
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

  case 356:
#line 4728 "Gmsh.y"
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

  case 357:
#line 4743 "Gmsh.y"
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

  case 358:
#line 4755 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 359:
#line 4766 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 360:
#line 4773 "Gmsh.y"
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

  case 361:
#line 4788 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 362:
#line 4801 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 363:
#line 4802 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 364:
#line 4803 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 365:
#line 4808 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 366:
#line 4814 "Gmsh.y"
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

  case 367:
#line 4826 "Gmsh.y"
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

  case 368:
#line 4844 "Gmsh.y"
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

  case 369:
#line 4871 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 370:
#line 4872 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 371:
#line 4873 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 372:
#line 4874 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 373:
#line 4875 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 374:
#line 4876 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4877 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 376:
#line 4878 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 377:
#line 4880 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 378:
#line 4886 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 379:
#line 4887 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 380:
#line 4888 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 381:
#line 4889 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 382:
#line 4890 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 4891 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 384:
#line 4892 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4893 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4894 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4895 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 388:
#line 4896 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 4897 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 4898 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 391:
#line 4899 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 392:
#line 4900 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 393:
#line 4901 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 394:
#line 4902 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 395:
#line 4903 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 396:
#line 4904 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4905 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 398:
#line 4906 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4907 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4908 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4909 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 4910 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4911 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 404:
#line 4912 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4913 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4914 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 4915 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 4916 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 409:
#line 4917 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 410:
#line 4918 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 4919 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 412:
#line 4920 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 413:
#line 4921 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 414:
#line 4922 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 415:
#line 4923 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 416:
#line 4932 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 417:
#line 4933 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 418:
#line 4934 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 419:
#line 4935 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 420:
#line 4936 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 421:
#line 4937 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 422:
#line 4938 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 423:
#line 4939 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 424:
#line 4940 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 425:
#line 4941 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 426:
#line 4942 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 427:
#line 4947 "Gmsh.y"
    { init_options(); ;}
    break;

  case 428:
#line 4949 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 429:
#line 4955 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 430:
#line 4957 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 431:
#line 4962 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 4967 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 433:
#line 4972 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 434:
#line 4977 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 435:
#line 4981 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 436:
#line 4985 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 437:
#line 4989 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 438:
#line 4993 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 439:
#line 4997 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 440:
#line 5001 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 441:
#line 5005 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 442:
#line 5011 "Gmsh.y"
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

  case 443:
#line 5027 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 444:
#line 5032 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 445:
#line 5038 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 446:
#line 5044 "Gmsh.y"
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

  case 447:
#line 5063 "Gmsh.y"
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

  case 448:
#line 5084 "Gmsh.y"
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

  case 449:
#line 5117 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 450:
#line 5121 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 451:
#line 5126 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 452:
#line 5130 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 453:
#line 5134 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 454:
#line 5138 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 455:
#line 5143 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 456:
#line 5148 "Gmsh.y"
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

  case 457:
#line 5158 "Gmsh.y"
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

  case 458:
#line 5168 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 459:
#line 5173 "Gmsh.y"
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

  case 460:
#line 5184 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 461:
#line 5193 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5198 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 463:
#line 5203 "Gmsh.y"
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

  case 464:
#line 5230 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 465:
#line 5232 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 466:
#line 5237 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 467:
#line 5239 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 468:
#line 5244 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 469:
#line 5251 "Gmsh.y"
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

  case 470:
#line 5267 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 471:
#line 5269 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 472:
#line 5274 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 473:
#line 5283 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 474:
#line 5285 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 475:
#line 5290 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 476:
#line 5292 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 477:
#line 5297 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 478:
#line 5301 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 479:
#line 5305 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 480:
#line 5309 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 481:
#line 5313 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 482:
#line 5320 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 483:
#line 5324 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 484:
#line 5328 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 485:
#line 5332 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 486:
#line 5339 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 487:
#line 5344 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 488:
#line 5351 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 489:
#line 5356 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 490:
#line 5360 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 491:
#line 5365 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 492:
#line 5369 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 493:
#line 5377 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 494:
#line 5388 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 495:
#line 5392 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 496:
#line 5396 "Gmsh.y"
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

  case 497:
#line 5410 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 498:
#line 5418 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 499:
#line 5426 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 500:
#line 5433 "Gmsh.y"
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

  case 501:
#line 5443 "Gmsh.y"
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

  case 502:
#line 5466 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 503:
#line 5471 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 504:
#line 5477 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 505:
#line 5482 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 506:
#line 5488 "Gmsh.y"
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

  case 507:
#line 5500 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 508:
#line 5505 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 509:
#line 5510 "Gmsh.y"
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

  case 510:
#line 5520 "Gmsh.y"
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

  case 511:
#line 5530 "Gmsh.y"
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

  case 512:
#line 5540 "Gmsh.y"
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

  case 513:
#line 5552 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 514:
#line 5556 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 515:
#line 5561 "Gmsh.y"
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

  case 516:
#line 5573 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 517:
#line 5577 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 518:
#line 5581 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 519:
#line 5585 "Gmsh.y"
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

  case 520:
#line 5603 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 521:
#line 5611 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 522:
#line 5619 "Gmsh.y"
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

  case 523:
#line 5648 "Gmsh.y"
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

  case 524:
#line 5658 "Gmsh.y"
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

  case 525:
#line 5674 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 526:
#line 5685 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 527:
#line 5690 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 528:
#line 5694 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 529:
#line 5698 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 530:
#line 5710 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 531:
#line 5714 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 532:
#line 5726 "Gmsh.y"
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

  case 533:
#line 5743 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 534:
#line 5753 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 535:
#line 5757 "Gmsh.y"
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

  case 536:
#line 5772 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 537:
#line 5777 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 538:
#line 5784 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 539:
#line 5788 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 540:
#line 5793 "Gmsh.y"
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

  case 541:
#line 5807 "Gmsh.y"
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

  case 542:
#line 5823 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 543:
#line 5827 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 544:
#line 5831 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 545:
#line 5835 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 546:
#line 5839 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 547:
#line 5847 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 548:
#line 5853 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 549:
#line 5859 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 550:
#line 5865 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 551:
#line 5874 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 552:
#line 5878 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 553:
#line 5882 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 554:
#line 5890 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 555:
#line 5896 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 556:
#line 5902 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 557:
#line 5906 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 558:
#line 5914 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 559:
#line 5922 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 560:
#line 5929 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 561:
#line 5938 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 562:
#line 5942 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 563:
#line 5946 "Gmsh.y"
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

  case 564:
#line 5961 "Gmsh.y"
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

  case 565:
#line 5975 "Gmsh.y"
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

  case 566:
#line 5989 "Gmsh.y"
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

  case 567:
#line 6001 "Gmsh.y"
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

  case 568:
#line 6017 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 569:
#line 6026 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 570:
#line 6035 "Gmsh.y"
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

  case 571:
#line 6045 "Gmsh.y"
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

  case 572:
#line 6056 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 573:
#line 6064 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 574:
#line 6072 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 575:
#line 6076 "Gmsh.y"
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

  case 576:
#line 6095 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 577:
#line 6102 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 578:
#line 6108 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 579:
#line 6115 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 580:
#line 6122 "Gmsh.y"
    { init_options(); ;}
    break;

  case 581:
#line 6124 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 582:
#line 6132 "Gmsh.y"
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

  case 583:
#line 6156 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 584:
#line 6158 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 585:
#line 6164 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 586:
#line 6169 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 587:
#line 6171 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 588:
#line 6176 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 589:
#line 6181 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 590:
#line 6186 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 591:
#line 6188 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 592:
#line 6192 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 593:
#line 6204 "Gmsh.y"
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

  case 594:
#line 6218 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 595:
#line 6222 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 596:
#line 6229 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 597:
#line 6237 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 598:
#line 6245 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 599:
#line 6256 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 600:
#line 6258 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 601:
#line 6261 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13790 "Gmsh.tab.cpp"
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


#line 6264 "Gmsh.y"


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

