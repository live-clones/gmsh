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
     tLine = 348,
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
     tSetFactory = 372,
     tThruSections = 373,
     tWedge = 374,
     tFillet = 375,
     tChamfer = 376,
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
     tReverse = 407,
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
#define tLine 348
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
#define tSetFactory 372
#define tThruSections 373
#define tWedge 374
#define tFillet 375
#define tChamfer 376
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
#define tReverse 407
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
#define YYLAST   15603

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  598
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2108

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
     707,   711,   712,   718,   719,   722,   730,   738,   746,   755,
     764,   772,   780,   792,   800,   809,   818,   827,   837,   841,
     846,   857,   865,   873,   881,   889,   897,   905,   913,   921,
     929,   937,   946,   954,   962,   971,   980,   993,   994,  1004,
    1006,  1008,  1010,  1012,  1017,  1019,  1021,  1023,  1028,  1030,
    1032,  1037,  1039,  1041,  1043,  1048,  1054,  1066,  1072,  1082,
    1092,  1097,  1107,  1117,  1119,  1121,  1122,  1125,  1132,  1140,
    1147,  1155,  1164,  1175,  1190,  1207,  1220,  1235,  1250,  1265,
    1280,  1289,  1298,  1305,  1310,  1316,  1323,  1330,  1334,  1339,
    1343,  1349,  1356,  1362,  1367,  1371,  1376,  1380,  1385,  1391,
    1396,  1402,  1406,  1412,  1420,  1428,  1432,  1440,  1444,  1447,
    1450,  1453,  1456,  1459,  1475,  1478,  1481,  1484,  1487,  1504,
    1516,  1523,  1532,  1541,  1552,  1554,  1557,  1560,  1562,  1566,
    1570,  1575,  1580,  1582,  1584,  1590,  1602,  1616,  1617,  1625,
    1626,  1640,  1641,  1657,  1658,  1665,  1675,  1678,  1682,  1693,
    1695,  1698,  1704,  1712,  1715,  1718,  1722,  1725,  1729,  1732,
    1736,  1746,  1753,  1755,  1757,  1759,  1761,  1763,  1764,  1767,
    1771,  1775,  1780,  1790,  1795,  1810,  1811,  1815,  1816,  1818,
    1819,  1822,  1823,  1826,  1827,  1830,  1837,  1845,  1852,  1858,
    1862,  1871,  1877,  1882,  1889,  1901,  1913,  1932,  1951,  1964,
    1977,  1990,  2001,  2006,  2011,  2016,  2021,  2024,  2028,  2035,
    2037,  2039,  2041,  2044,  2050,  2058,  2069,  2071,  2075,  2078,
    2081,  2084,  2088,  2092,  2096,  2100,  2104,  2108,  2112,  2116,
    2120,  2124,  2128,  2132,  2136,  2140,  2144,  2148,  2152,  2156,
    2162,  2167,  2172,  2177,  2182,  2187,  2192,  2197,  2202,  2207,
    2212,  2219,  2224,  2229,  2234,  2239,  2244,  2249,  2254,  2259,
    2266,  2273,  2280,  2285,  2287,  2289,  2291,  2293,  2295,  2297,
    2299,  2301,  2303,  2305,  2307,  2308,  2315,  2317,  2322,  2329,
    2331,  2336,  2341,  2346,  2353,  2359,  2367,  2376,  2387,  2392,
    2397,  2404,  2409,  2413,  2416,  2422,  2428,  2432,  2438,  2445,
    2454,  2461,  2470,  2477,  2482,  2490,  2497,  2504,  2511,  2516,
    2523,  2528,  2529,  2532,  2533,  2536,  2537,  2545,  2547,  2551,
    2553,  2555,  2558,  2559,  2563,  2565,  2568,  2571,  2575,  2579,
    2591,  2601,  2609,  2617,  2619,  2623,  2625,  2627,  2630,  2634,
    2639,  2645,  2647,  2651,  2653,  2656,  2660,  2664,  2670,  2675,
    2680,  2683,  2688,  2691,  2695,  2712,  2718,  2720,  2722,  2724,
    2728,  2734,  2742,  2747,  2752,  2757,  2764,  2771,  2780,  2789,
    2794,  2809,  2814,  2819,  2821,  2823,  2827,  2831,  2841,  2849,
    2851,  2857,  2861,  2868,  2870,  2874,  2876,  2878,  2883,  2888,
    2892,  2898,  2905,  2914,  2921,  2927,  2933,  2939,  2945,  2947,
    2952,  2954,  2956,  2958,  2960,  2965,  2972,  2977,  2984,  2990,
    2998,  3003,  3008,  3013,  3022,  3027,  3032,  3037,  3042,  3051,
    3060,  3067,  3072,  3079,  3084,  3086,  3091,  3096,  3097,  3104,
    3109,  3112,  3117,  3122,  3124,  3126,  3130,  3132,  3134,  3138,
    3142,  3146,  3152,  3160,  3166,  3172,  3181,  3183,  3185
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     249,     0,    -1,   250,    -1,     1,     6,    -1,    -1,   250,
     251,    -1,   253,    -1,   254,    -1,   274,    -1,   117,   238,
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
     348,     6,    -1,   360,   184,     7,   329,     6,    -1,   184,
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
      -1,    -1,   176,    94,   242,   329,   243,    -1,    -1,   122,
     340,    -1,    90,   238,   329,   239,     7,   340,     6,    -1,
      93,   238,   329,   239,     7,   343,     6,    -1,    97,   238,
     329,   239,     7,   343,     6,    -1,    91,   238,   329,   239,
       7,   343,   291,     6,    -1,    92,   238,   329,   239,     7,
     343,   291,     6,    -1,   168,   238,   329,   239,     7,   343,
       6,    -1,   169,   238,   329,   239,     7,   343,     6,    -1,
     170,   238,   329,   239,     7,   343,   172,   343,   171,   329,
       6,    -1,   108,   238,   329,   239,     7,   343,     6,    -1,
      93,     4,   238,   329,   239,     7,   343,     6,    -1,   122,
      96,   238,   329,   239,     7,   343,     6,    -1,    96,   238,
     329,   239,     7,   343,   290,     6,    -1,   123,    96,   238,
     329,   239,     7,   343,   290,     6,    -1,    13,    14,     6,
      -1,    14,    96,   329,     6,    -1,   112,    96,   238,   329,
     239,     7,     5,     5,     5,     6,    -1,    94,   238,   329,
     239,     7,   343,     6,    -1,    95,   238,   329,   239,     7,
     343,     6,    -1,    99,   238,   329,   239,     7,   343,     6,
      -1,   102,   238,   329,   239,     7,   343,     6,    -1,   106,
     238,   329,   239,     7,   343,     6,    -1,   107,   238,   329,
     239,     7,   343,     6,    -1,   100,   238,   329,   239,     7,
     343,     6,    -1,   101,   238,   329,   239,     7,   343,     6,
      -1,   119,   238,   329,   239,     7,   343,     6,    -1,   144,
     238,   329,   239,     7,   343,     6,    -1,    96,     4,   238,
     329,   239,     7,   343,     6,    -1,    98,   238,   329,   239,
       7,   343,     6,    -1,   118,   238,   329,   239,     7,   343,
       6,    -1,   123,   118,   238,   329,   239,     7,   343,     6,
      -1,   126,   295,   238,   329,   239,     7,   343,     6,    -1,
     126,   295,   238,   329,   239,     7,   343,     4,   242,   342,
     243,     6,    -1,    -1,   125,   294,   293,   238,   289,   239,
     270,   343,     6,    -1,    90,    -1,    93,    -1,    96,    -1,
      98,    -1,   109,   242,   329,   243,    -1,    93,    -1,    96,
      -1,    98,    -1,   109,   242,   329,   243,    -1,    93,    -1,
      96,    -1,   109,   242,   329,   243,    -1,    90,    -1,    93,
      -1,    96,    -1,   109,   242,   329,   243,    -1,   133,   340,
     242,   299,   243,    -1,   132,   242,   340,   247,   340,   247,
     329,   243,   242,   299,   243,    -1,   134,   340,   242,   299,
     243,    -1,   135,   242,   340,   247,   329,   243,   242,   299,
     243,    -1,   135,   242,   340,   247,   340,   243,   242,   299,
     243,    -1,     4,   242,   299,   243,    -1,   150,    93,   242,
     346,   243,    96,   242,   329,   243,    -1,   147,    93,   238,
     329,   239,   242,   346,   243,     6,    -1,   300,    -1,   298,
      -1,    -1,   300,   292,    -1,   300,   294,   242,   346,   243,
       6,    -1,   300,   125,   294,   242,   346,   243,     6,    -1,
     300,   294,   242,     8,   243,     6,    -1,   300,   125,   294,
     242,     8,   243,     6,    -1,   137,   122,   238,   329,   239,
       7,   343,     6,    -1,   137,    90,   238,   329,   239,     7,
     242,   342,   243,     6,    -1,   137,   122,   238,   329,   239,
       7,   242,   340,   247,   340,   247,   346,   243,     6,    -1,
     137,   122,   238,   329,   239,     7,   242,   340,   247,   340,
     247,   340,   247,   346,   243,     6,    -1,   137,    94,   238,
     329,   239,     7,   242,   340,   247,   346,   243,     6,    -1,
     137,   100,   238,   329,   239,     7,   242,   340,   247,   340,
     247,   346,   243,     6,    -1,   137,   101,   238,   329,   239,
       7,   242,   340,   247,   340,   247,   346,   243,     6,    -1,
     137,   103,   238,   329,   239,     7,   242,   340,   247,   340,
     247,   346,   243,     6,    -1,   137,   104,   238,   329,   239,
       7,   242,   340,   247,   340,   247,   346,   243,     6,    -1,
     137,     4,   238,   329,   239,     7,   343,     6,    -1,   137,
       4,   238,   329,   239,     7,     5,     6,    -1,   137,     4,
     242,   329,   243,     6,    -1,   148,   242,   300,   243,    -1,
     131,   148,   242,   300,   243,    -1,   148,   184,   240,   329,
     241,     6,    -1,   148,     4,   240,   329,   241,     6,    -1,
     148,   360,     6,    -1,   148,     4,     4,     6,    -1,   148,
      83,     6,    -1,   173,   347,   242,   300,   243,    -1,   131,
     173,   347,   242,   300,   243,    -1,   208,   329,   242,   300,
     243,    -1,   189,   242,     8,   243,    -1,   189,     5,     6,
      -1,   190,   242,     8,   243,    -1,   190,     5,     6,    -1,
     189,   242,   300,   243,    -1,   131,   189,   242,   300,   243,
      -1,   190,   242,   300,   243,    -1,   131,   190,   242,   300,
     243,    -1,   360,   351,     6,    -1,    73,   238,   357,   239,
       6,    -1,   360,   360,   240,   329,   241,   350,     6,    -1,
     360,   360,   360,   240,   329,   241,     6,    -1,   360,   329,
       6,    -1,   129,   238,     4,   239,   244,     4,     6,    -1,
     167,     4,     6,    -1,   182,     6,    -1,   183,     6,    -1,
      70,     6,    -1,    71,     6,    -1,    64,     6,    -1,    64,
     242,   329,   247,   329,   247,   329,   247,   329,   247,   329,
     247,   329,   243,     6,    -1,    65,     6,    -1,    66,     6,
      -1,    78,     6,    -1,   114,     6,    -1,   115,   242,   346,
     243,   242,   346,   243,   242,   342,   243,   242,   329,   247,
     329,   243,     6,    -1,   187,   238,   242,   346,   243,   247,
     351,   247,   351,   239,     6,    -1,   175,   238,   329,     8,
     329,   239,    -1,   175,   238,   329,     8,   329,     8,   329,
     239,    -1,   175,     4,   176,   242,   329,     8,   329,   243,
      -1,   175,     4,   176,   242,   329,     8,   329,     8,   329,
     243,    -1,   177,    -1,   188,     4,    -1,   188,   351,    -1,
     185,    -1,   186,   360,     6,    -1,   186,   351,     6,    -1,
     178,   238,   329,   239,    -1,   179,   238,   329,   239,    -1,
     180,    -1,   181,    -1,   136,   340,   242,   300,   243,    -1,
     136,   242,   340,   247,   340,   247,   329,   243,   242,   300,
     243,    -1,   136,   242,   340,   247,   340,   247,   340,   247,
     329,   243,   242,   300,   243,    -1,    -1,   136,   340,   242,
     300,   310,   314,   243,    -1,    -1,   136,   242,   340,   247,
     340,   247,   329,   243,   242,   300,   311,   314,   243,    -1,
      -1,   136,   242,   340,   247,   340,   247,   340,   247,   329,
     243,   242,   300,   312,   314,   243,    -1,    -1,   136,   242,
     300,   313,   314,   243,    -1,   136,   242,   300,   243,   128,
     108,   242,   329,   243,    -1,   118,   343,    -1,   123,   118,
     343,    -1,   120,   242,   346,   243,   242,   346,   243,   242,
     329,   243,    -1,   315,    -1,   314,   315,    -1,   153,   242,
     329,   243,     6,    -1,   153,   242,   343,   247,   343,   243,
       6,    -1,   154,     6,    -1,   145,     6,    -1,   145,   329,
       6,    -1,   159,     6,    -1,   159,   161,     6,    -1,   160,
       6,    -1,   160,   161,     6,    -1,   155,   238,   329,   239,
       7,   343,   128,   329,     6,    -1,   128,     4,   240,   329,
     241,     6,    -1,   139,    -1,   140,    -1,   141,    -1,   142,
      -1,   143,    -1,    -1,   148,     6,    -1,   131,   148,     6,
      -1,   148,   329,     6,    -1,   131,   148,   329,     6,    -1,
     316,   242,   300,   317,   243,   242,   300,   317,   243,    -1,
     105,   238,   350,   239,    -1,   316,   238,   329,   239,     7,
     242,   300,   317,   243,   242,   300,   317,   243,     6,    -1,
      -1,   128,     4,   329,    -1,    -1,     4,    -1,    -1,     7,
     343,    -1,    -1,     7,   329,    -1,    -1,   138,   343,    -1,
     110,   111,   344,     7,   329,     6,    -1,   124,    93,   344,
       7,   329,   320,     6,    -1,   124,    96,   344,   322,   321,
       6,    -1,   124,    98,   344,   322,     6,    -1,   162,   344,
       6,    -1,   151,    96,   242,   346,   243,     7,   329,     6,
      -1,   145,    96,   344,   323,     6,    -1,   145,    98,   344,
       6,    -1,   146,    96,   344,     7,   329,     6,    -1,   127,
      93,   242,   346,   243,     7,   242,   346,   243,   324,     6,
      -1,   127,    96,   242,   346,   243,     7,   242,   346,   243,
     324,     6,    -1,   127,    93,   242,   346,   243,     7,   242,
     346,   243,   132,   242,   340,   247,   340,   247,   329,   243,
       6,    -1,   127,    96,   242,   346,   243,     7,   242,   346,
     243,   132,   242,   340,   247,   340,   247,   329,   243,     6,
      -1,   127,    93,   242,   346,   243,     7,   242,   346,   243,
     133,   340,     6,    -1,   127,    96,   242,   346,   243,     7,
     242,   346,   243,   133,   340,     6,    -1,   127,    96,   329,
     242,   346,   243,     7,   329,   242,   346,   243,     6,    -1,
     294,   242,   346,   243,   176,   294,   242,   329,   243,     6,
      -1,   152,   296,   344,     6,    -1,   116,   297,   344,     6,
      -1,   130,    93,   343,     6,    -1,   126,   295,   343,     6,
      -1,   149,     6,    -1,   149,     4,     6,    -1,   149,    90,
     242,   346,   243,     6,    -1,   197,    -1,   198,    -1,   199,
      -1,   327,     6,    -1,   327,   242,   343,   243,     6,    -1,
     327,   242,   343,   247,   343,   243,     6,    -1,   327,   238,
     343,   239,   242,   343,   247,   343,   243,     6,    -1,   330,
      -1,   238,   329,   239,    -1,   227,   329,    -1,   226,   329,
      -1,   233,   329,    -1,   329,   227,   329,    -1,   329,   226,
     329,    -1,   329,   228,   329,    -1,   329,   229,   329,    -1,
     329,   231,   329,    -1,   329,   232,   329,    -1,   329,   230,
     329,    -1,   329,   237,   329,    -1,   329,   220,   329,    -1,
     329,   221,   329,    -1,   329,   225,   329,    -1,   329,   224,
     329,    -1,   329,   219,   329,    -1,   329,   218,   329,    -1,
     329,   217,   329,    -1,   329,   216,   329,    -1,   329,   222,
     329,    -1,   329,   223,   329,    -1,   329,   215,   329,     8,
     329,    -1,    16,   272,   329,   273,    -1,    17,   272,   329,
     273,    -1,    18,   272,   329,   273,    -1,    19,   272,   329,
     273,    -1,    20,   272,   329,   273,    -1,    21,   272,   329,
     273,    -1,    22,   272,   329,   273,    -1,    23,   272,   329,
     273,    -1,    24,   272,   329,   273,    -1,    26,   272,   329,
     273,    -1,    27,   272,   329,   247,   329,   273,    -1,    28,
     272,   329,   273,    -1,    29,   272,   329,   273,    -1,    30,
     272,   329,   273,    -1,    31,   272,   329,   273,    -1,    32,
     272,   329,   273,    -1,    33,   272,   329,   273,    -1,    34,
     272,   329,   273,    -1,    35,   272,   329,   273,    -1,    36,
     272,   329,   247,   329,   273,    -1,    37,   272,   329,   247,
     329,   273,    -1,    38,   272,   329,   247,   329,   273,    -1,
      25,   272,   329,   273,    -1,     3,    -1,    10,    -1,    15,
      -1,    11,    -1,    12,    -1,   204,    -1,   205,    -1,   206,
      -1,    75,    -1,    76,    -1,    77,    -1,    -1,    82,   272,
     329,   331,   282,   273,    -1,   334,    -1,   195,   272,   350,
     273,    -1,   195,   272,   350,   247,   329,   273,    -1,   336,
      -1,   360,   240,   329,   241,    -1,   360,   238,   329,   239,
      -1,   200,   238,   336,   239,    -1,   200,   238,   336,   244,
     337,   239,    -1,   202,   238,   336,   332,   239,    -1,   202,
     238,   336,   244,   337,   332,   239,    -1,   202,   238,   336,
     272,   329,   273,   332,   239,    -1,   202,   238,   336,   244,
     337,   272,   329,   273,   332,   239,    -1,   201,   238,   351,
     239,    -1,   245,   360,   272,   273,    -1,   245,   336,   244,
     337,   272,   273,    -1,    85,   272,   360,   273,    -1,    85,
     272,   273,    -1,   360,   271,    -1,   360,   240,   329,   241,
     271,    -1,   360,   238,   329,   239,   271,    -1,   360,   244,
     337,    -1,   360,     9,   360,   244,   337,    -1,   360,   244,
     337,   238,   329,   239,    -1,   360,     9,   360,   244,   337,
     238,   329,   239,    -1,   360,   244,   337,   240,   329,   241,
      -1,   360,     9,   360,   244,   337,   240,   329,   241,    -1,
     360,   240,   329,   241,   244,     4,    -1,   360,   244,     4,
     271,    -1,   360,   240,   329,   241,   244,     4,   271,    -1,
     191,   238,   350,   247,   329,   239,    -1,    56,   238,   343,
     247,   343,   239,    -1,    57,   272,   350,   247,   350,   273,
      -1,    55,   272,   350,   273,    -1,    58,   272,   350,   247,
     350,   273,    -1,    63,   238,   357,   239,    -1,    -1,   247,
     329,    -1,    -1,   247,   350,    -1,    -1,    83,   336,   339,
     335,   240,   283,   241,    -1,   360,    -1,   360,     9,   360,
      -1,     4,    -1,    86,    -1,    86,   329,    -1,    -1,   238,
     338,   239,    -1,   341,    -1,   227,   340,    -1,   226,   340,
      -1,   340,   227,   340,    -1,   340,   226,   340,    -1,   242,
     329,   247,   329,   247,   329,   247,   329,   247,   329,   243,
      -1,   242,   329,   247,   329,   247,   329,   247,   329,   243,
      -1,   242,   329,   247,   329,   247,   329,   243,    -1,   238,
     329,   247,   329,   247,   329,   239,    -1,   343,    -1,   342,
     247,   343,    -1,   329,    -1,   345,    -1,   242,   243,    -1,
     242,   346,   243,    -1,   227,   242,   346,   243,    -1,   329,
     228,   242,   346,   243,    -1,   343,    -1,   242,     8,   243,
      -1,     5,    -1,   227,   345,    -1,   329,   228,   345,    -1,
     329,     8,   329,    -1,   329,     8,   329,     8,   329,    -1,
      90,   242,   329,   243,    -1,    90,   242,     8,   243,    -1,
      90,     5,    -1,   295,   242,     8,   243,    -1,   295,     5,
      -1,   125,   294,   344,    -1,   294,   176,    64,   242,   329,
     247,   329,   247,   329,   247,   329,   247,   329,   247,   329,
     243,    -1,    64,   294,   242,   329,   243,    -1,   298,    -1,
     309,    -1,   318,    -1,   360,   272,   273,    -1,   360,   244,
     337,   272,   273,    -1,   360,     9,   360,   244,   337,   272,
     273,    -1,    39,   240,   360,   241,    -1,    39,   240,   345,
     241,    -1,    39,   238,   345,   239,    -1,    39,   272,   242,
     346,   243,   273,    -1,   360,   272,   242,   346,   243,   273,
      -1,    40,   272,   329,   247,   329,   247,   329,   273,    -1,
      41,   272,   329,   247,   329,   247,   329,   273,    -1,    42,
     272,   350,   273,    -1,    43,   272,   329,   247,   329,   247,
     329,   247,   329,   247,   329,   247,   329,   273,    -1,   196,
     272,   345,   273,    -1,    32,   272,   345,   273,    -1,   329,
      -1,   345,    -1,   346,   247,   329,    -1,   346,   247,   345,
      -1,   242,   329,   247,   329,   247,   329,   247,   329,   243,
      -1,   242,   329,   247,   329,   247,   329,   243,    -1,   360,
      -1,     4,   244,   173,   244,     4,    -1,   242,   349,   243,
      -1,   360,   240,   329,   241,   244,   174,    -1,   347,    -1,
     349,   247,   347,    -1,   351,    -1,   360,    -1,   360,   240,
     329,   241,    -1,   360,   238,   329,   239,    -1,   360,   244,
     337,    -1,   360,     9,   360,   244,   337,    -1,   360,   244,
     337,   238,   329,   239,    -1,   360,     9,   360,   244,   337,
     238,   329,   239,    -1,   360,   240,   329,   241,   244,     4,
      -1,   125,    90,   242,   329,   243,    -1,   125,    93,   242,
     329,   243,    -1,   125,    96,   242,   329,   243,    -1,   125,
      98,   242,   329,   243,    -1,     5,    -1,   209,   240,   360,
     241,    -1,    67,    -1,   207,    -1,    72,    -1,    74,    -1,
     193,   238,   350,   239,    -1,   192,   238,   350,   247,   350,
     239,    -1,   194,   272,   350,   273,    -1,   194,   272,   350,
     247,   350,   273,    -1,   203,   238,   336,   333,   239,    -1,
     203,   238,   336,   244,   337,   333,   239,    -1,    48,   272,
     357,   273,    -1,    49,   238,   350,   239,    -1,    50,   238,
     350,   239,    -1,    51,   238,   350,   247,   350,   247,   350,
     239,    -1,    46,   272,   357,   273,    -1,    60,   272,   350,
     273,    -1,    61,   272,   350,   273,    -1,    62,   272,   350,
     273,    -1,    59,   272,   329,   247,   350,   247,   350,   273,
      -1,    54,   272,   350,   247,   329,   247,   329,   273,    -1,
      54,   272,   350,   247,   329,   273,    -1,    47,   272,   350,
     273,    -1,    47,   272,   350,   247,   346,   273,    -1,    68,
     272,   350,   273,    -1,    69,    -1,    53,   272,   350,   273,
      -1,    52,   272,   350,   273,    -1,    -1,    87,   272,   351,
     352,   286,   273,    -1,    84,   272,   353,   273,    -1,   245,
     329,    -1,   360,     9,   245,   329,    -1,    46,   272,   356,
     273,    -1,   357,    -1,   356,    -1,   242,   357,   243,    -1,
     350,    -1,   358,    -1,   357,   247,   350,    -1,   357,   247,
     358,    -1,   360,   238,   239,    -1,   360,   244,   337,   238,
     239,    -1,   360,     9,   360,   244,   337,   238,   239,    -1,
       4,   246,   242,   329,   243,    -1,   359,   246,   242,   329,
     243,    -1,   210,   240,   350,   241,   246,   242,   329,   243,
      -1,     4,    -1,   359,    -1,   210,   240,   350,   241,    -1
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
    1066,  1089,  1100,  1108,  1115,  1122,  1144,  1167,  1205,  1226,
    1238,  1252,  1252,  1254,  1256,  1265,  1275,  1274,  1295,  1294,
    1312,  1322,  1321,  1335,  1337,  1345,  1351,  1356,  1382,  1384,
    1387,  1389,  1393,  1394,  1398,  1410,  1423,  1438,  1447,  1460,
    1462,  1466,  1467,  1472,  1480,  1489,  1497,  1511,  1529,  1533,
    1540,  1549,  1552,  1559,  1562,  1569,  1592,  1608,  1624,  1661,
    1701,  1717,  1733,  1755,  1771,  1790,  1806,  1827,  1838,  1844,
    1850,  1857,  1888,  1903,  1925,  1948,  1971,  1994,  2018,  2042,
    2066,  2092,  2109,  2125,  2143,  2161,  2167,  2175,  2174,  2204,
    2206,  2208,  2210,  2212,  2220,  2222,  2224,  2226,  2234,  2236,
    2238,  2246,  2248,  2250,  2252,  2262,  2278,  2294,  2310,  2326,
    2342,  2379,  2401,  2425,  2426,  2431,  2434,  2438,  2454,  2472,
    2490,  2515,  2534,  2555,  2570,  2586,  2604,  2655,  2676,  2698,
    2721,  2826,  2842,  2877,  2899,  2921,  2927,  2942,  2970,  2982,
    2991,  2998,  3010,  3029,  3033,  3038,  3042,  3047,  3054,  3061,
    3068,  3080,  3153,  3171,  3188,  3203,  3236,  3248,  3272,  3276,
    3281,  3288,  3293,  3303,  3308,  3314,  3322,  3326,  3335,  3399,
    3415,  3432,  3449,  3471,  3493,  3528,  3536,  3544,  3550,  3557,
    3564,  3584,  3610,  3622,  3633,  3651,  3669,  3688,  3687,  3712,
    3711,  3738,  3737,  3762,  3761,  3784,  3800,  3817,  3834,  3857,
    3860,  3866,  3878,  3898,  3902,  3906,  3910,  3914,  3918,  3922,
    3926,  3935,  3948,  3949,  3950,  3951,  3952,  3956,  3957,  3958,
    3959,  3960,  3963,  3987,  4006,  4029,  4032,  4048,  4051,  4068,
    4071,  4077,  4080,  4087,  4090,  4097,  4119,  4160,  4204,  4243,
    4268,  4277,  4307,  4333,  4359,  4391,  4418,  4444,  4470,  4496,
    4522,  4544,  4555,  4603,  4652,  4664,  4675,  4682,  4697,  4711,
    4712,  4713,  4717,  4723,  4735,  4753,  4781,  4782,  4783,  4784,
    4785,  4786,  4787,  4788,  4789,  4796,  4797,  4798,  4799,  4800,
    4801,  4802,  4803,  4804,  4805,  4806,  4807,  4808,  4809,  4810,
    4811,  4812,  4813,  4814,  4815,  4816,  4817,  4818,  4819,  4820,
    4821,  4822,  4823,  4824,  4825,  4826,  4827,  4828,  4829,  4830,
    4831,  4832,  4833,  4842,  4843,  4844,  4845,  4846,  4847,  4848,
    4849,  4850,  4851,  4852,  4857,  4856,  4864,  4866,  4871,  4876,
    4880,  4885,  4890,  4894,  4898,  4902,  4906,  4910,  4914,  4920,
    4936,  4941,  4947,  4953,  4972,  4993,  5026,  5030,  5035,  5039,
    5043,  5047,  5052,  5057,  5067,  5077,  5082,  5093,  5102,  5107,
    5112,  5140,  5141,  5147,  5148,  5154,  5153,  5176,  5178,  5183,
    5192,  5194,  5200,  5201,  5206,  5210,  5214,  5218,  5222,  5229,
    5233,  5237,  5241,  5248,  5253,  5260,  5265,  5269,  5274,  5278,
    5286,  5297,  5301,  5305,  5319,  5327,  5335,  5342,  5352,  5375,
    5380,  5386,  5391,  5397,  5408,  5414,  5419,  5429,  5439,  5449,
    5461,  5465,  5470,  5482,  5486,  5490,  5494,  5512,  5520,  5528,
    5557,  5567,  5583,  5594,  5599,  5603,  5607,  5619,  5623,  5635,
    5652,  5662,  5666,  5681,  5686,  5693,  5697,  5702,  5716,  5732,
    5736,  5740,  5744,  5748,  5756,  5762,  5768,  5774,  5783,  5787,
    5791,  5799,  5805,  5811,  5815,  5823,  5831,  5838,  5847,  5851,
    5855,  5870,  5884,  5898,  5910,  5926,  5935,  5944,  5954,  5965,
    5973,  5981,  5985,  6004,  6011,  6017,  6024,  6032,  6031,  6041,
    6065,  6067,  6073,  6078,  6080,  6085,  6090,  6095,  6097,  6101,
    6113,  6127,  6131,  6138,  6146,  6154,  6165,  6167,  6170
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
  "tSetString", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBox", "tCylinder",
  "tCone", "tTorus", "tEllipsoid", "tQuadric", "tShapeFromFile",
  "tRectangle", "tDisk", "tWire", "tGeoEntity", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tSetFactory", "tThruSections", "tWedge", "tFillet",
  "tChamfer", "tPlane", "tRuled", "tTransfinite", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRecursive",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tAffine", "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
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
     289,   290,   290,   291,   291,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   293,   292,   294,
     294,   294,   294,   294,   295,   295,   295,   295,   296,   296,
     296,   297,   297,   297,   297,   298,   298,   298,   298,   298,
     298,   298,   298,   299,   299,   300,   300,   300,   300,   300,
     300,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     303,   303,   304,   305,   305,   305,   305,   305,   305,   305,
     305,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   307,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   309,   309,   309,   310,   309,   311,
     309,   312,   309,   313,   309,   309,   309,   309,   309,   314,
     314,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   316,   316,   316,   316,   316,   317,   317,   317,
     317,   317,   318,   318,   319,   320,   320,   321,   321,   322,
     322,   323,   323,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   326,   326,   326,   327,
     327,   327,   328,   328,   328,   328,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   331,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   332,   332,   333,   333,   335,   334,   336,   336,   337,
     338,   338,   339,   339,   340,   340,   340,   340,   340,   341,
     341,   341,   341,   342,   342,   343,   343,   343,   343,   343,
     343,   344,   344,   344,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   346,   346,   346,   346,   347,   347,   347,
     347,   348,   348,   349,   349,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   352,   351,   351,
     353,   353,   354,   355,   355,   356,   357,   357,   357,   357,
     358,   358,   358,   359,   359,   359,   360,   360,   360
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
       3,     0,     5,     0,     2,     7,     7,     7,     8,     8,
       7,     7,    11,     7,     8,     8,     8,     9,     3,     4,
      10,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     8,     7,     7,     8,     8,    12,     0,     9,     1,
       1,     1,     1,     4,     1,     1,     1,     4,     1,     1,
       4,     1,     1,     1,     4,     5,    11,     5,     9,     9,
       4,     9,     9,     1,     1,     0,     2,     6,     7,     6,
       7,     8,    10,    14,    16,    12,    14,    14,    14,    14,
       8,     8,     6,     4,     5,     6,     6,     3,     4,     3,
       5,     6,     5,     4,     3,     4,     3,     4,     5,     4,
       5,     3,     5,     7,     7,     3,     7,     3,     2,     2,
       2,     2,     2,    15,     2,     2,     2,     2,    16,    11,
       6,     8,     8,    10,     1,     2,     2,     1,     3,     3,
       4,     4,     1,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     0,     6,     9,     2,     3,    10,     1,
       2,     5,     7,     2,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       3,     4,     9,     4,    14,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     6,     7,     6,     5,     3,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,     4,     4,     4,     4,     2,     3,     6,     1,
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
       2,     4,     2,     3,    16,     5,     1,     1,     1,     3,
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
       0,     0,     0,     2,     3,     1,   596,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,   190,     0,     0,   191,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   274,
       0,     0,   282,   283,     0,     0,     0,   277,     0,     0,
       0,     0,     0,   359,   360,   361,     0,     0,     5,     6,
       7,     8,    10,     0,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,     0,   597,     0,   215,     0,     0,     0,     0,     0,
     262,     0,   264,   265,   260,   261,     0,   266,   113,   123,
     596,   472,   467,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,   201,   202,   203,     0,     0,     0,   413,   414,   416,
     417,   415,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   421,   422,   423,     0,
       0,   189,   194,   195,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   418,   419,   420,     0,     0,
       0,     0,     0,     0,     0,     0,   506,   507,     0,   508,
     485,   366,   426,   429,   296,   486,   467,     0,     0,     0,
       0,     0,     0,     0,     0,   189,   190,   191,   192,   187,
     194,   195,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596,     0,     0,
     215,     0,     0,   356,     0,     0,     0,   198,   199,     0,
       0,     0,     0,     0,   493,     0,     0,   491,     0,     0,
       0,     0,     0,   596,     0,     0,   529,     0,     0,     0,
       0,   258,   259,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   550,     0,
     574,   552,   553,     0,     0,     0,     0,     0,     0,   551,
       0,     0,     0,     0,   275,   276,     0,   215,     0,   215,
       0,     0,     0,   467,     0,     0,     0,   215,   362,     0,
       0,    76,     0,    63,     0,     0,    67,    66,    65,    64,
      69,    68,    70,    71,     0,     0,     0,     0,     0,     0,
     535,   467,     0,   214,     0,   213,     0,   168,     0,     0,
     535,   536,     0,     0,   586,     0,   587,   536,   111,   111,
       0,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   369,     0,   368,   494,   370,     0,   487,
       0,     0,   467,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
     443,     0,     0,     0,     0,     0,     0,   297,     0,   329,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,   215,   215,     0,   476,   475,     0,     0,     0,
       0,   215,   215,     0,     0,     0,     0,   293,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   239,     0,     0,   237,
     357,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   339,   257,     0,     0,     0,     0,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,   278,     0,   244,     0,
       0,   246,     0,     0,     0,   368,     0,   215,     0,     0,
       0,     0,     0,     0,     0,   317,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    72,    73,     0,     0,   255,    38,   251,     0,
       0,     0,     0,     0,   210,     0,     0,     0,     0,   216,
       0,     0,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,   470,     0,     0,   468,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,   193,     0,     0,
       0,     0,     0,     0,   353,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   467,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   424,   442,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,   461,     0,   367,
     488,     0,     0,     0,     0,   496,     0,   386,   385,   384,
     383,   379,   380,   387,   388,   382,   381,   372,   371,     0,
     373,   495,   374,   377,   375,   376,   378,   468,     0,     0,
     469,   446,     0,   509,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,     0,     0,   355,     0,     0,     0,
       0,   354,     0,   215,     0,     0,     0,     0,     0,   478,
     477,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   342,     0,     0,   238,     0,     0,   233,     0,     0,
       0,     0,   352,     0,     0,     0,   367,   492,     0,     0,
       0,     0,     0,     0,     0,     0,   280,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   577,     0,     0,     0,
     463,     0,     0,   243,   247,   245,   249,     0,   373,     0,
     468,   446,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   367,     0,
      63,     0,     0,     0,     0,    79,     0,    63,    64,     0,
       0,   468,     0,     0,   446,     0,     0,     0,   187,     0,
       0,   593,    28,    26,    27,     0,     0,     0,     0,     0,
     469,   539,    29,     0,     0,   252,   588,   589,     0,   590,
     539,    74,   114,    75,   124,   471,   473,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   525,   526,   204,     9,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   412,   399,     0,   401,   402,   403,
     404,   405,   522,   406,   407,   408,     0,     0,     0,   514,
     513,   512,     0,     0,     0,   519,     0,   458,     0,     0,
       0,   460,     0,   128,   441,   499,   498,   197,     0,     0,
     427,   521,   432,     0,   438,     0,     0,     0,     0,   489,
       0,     0,   439,     0,   501,     0,     0,     0,     0,   431,
     430,   453,    70,    71,     0,     0,     0,     0,     0,     0,
     367,   325,   330,   328,     0,   338,     0,   148,   149,   197,
     367,     0,     0,     0,     0,   234,     0,   248,   250,     0,
       0,     0,   205,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
     341,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,   564,     0,   571,   560,   561,   562,     0,   576,
     575,     0,     0,   565,   566,   567,   573,   580,   579,     0,
     139,     0,   554,     0,   556,     0,     0,     0,   549,     0,
     242,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,     0,   363,     0,   594,     0,     0,     0,     0,   101,
      63,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,    61,     0,    39,    40,    41,    42,    43,     0,   431,
     430,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   538,   537,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   131,   132,     0,     0,     0,   153,   153,
       0,     0,     0,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,   461,   462,     0,   434,     0,
       0,     0,   497,   389,   490,   447,   445,     0,   444,     0,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
     337,     0,     0,     0,     0,     0,     0,     0,   241,     0,
       0,     0,     0,     0,     0,     0,   304,     0,     0,   303,
       0,   306,     0,   308,     0,   294,   300,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,   343,
       0,   236,   235,   358,     0,     0,    35,    36,     0,     0,
       0,     0,   530,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     463,   464,   558,     0,   447,     0,     0,   215,   319,     0,
     320,   215,     0,     0,   544,   545,   546,   547,     0,    86,
       0,     0,     0,     0,    84,    91,    93,     0,   533,     0,
      99,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    34,   447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,   540,     0,     0,
      32,     0,   540,   591,     0,   115,   120,     0,     0,     0,
     134,   137,   138,   466,     0,    77,    78,   155,     0,     0,
       0,     0,   156,   171,   172,     0,     0,     0,   157,   182,
     173,   177,   178,   174,   175,   176,   163,     0,     0,   400,
     409,   410,   411,   515,     0,     0,     0,   456,   457,   459,
     129,   425,   455,   428,   433,     0,     0,   461,   183,   440,
       0,    70,    71,     0,   452,   448,   450,   516,   179,     0,
       0,   151,     0,     0,   336,     0,   150,     0,     0,     0,
       0,   256,     0,     0,     0,     0,   215,   215,     0,     0,
     305,   485,     0,     0,   307,   309,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
     102,   103,   104,   108,     0,   572,     0,     0,   570,     0,
     581,     0,     0,   140,   141,   578,   555,   557,     0,     0,
       0,     0,     0,     0,   317,   321,   317,     0,   364,    85,
      63,     0,     0,     0,     0,    83,     0,   531,     0,     0,
       0,     0,     0,     0,   584,   583,     0,     0,     0,     0,
       0,   483,     0,     0,   452,   253,   448,   254,     0,     0,
       0,     0,   219,   217,     0,     0,   543,   541,     0,     0,
     116,   121,     0,     0,     0,   523,   524,   133,   154,   158,
     159,   164,   181,     0,   166,     0,     0,     0,     0,     0,
       0,   435,     0,     0,     0,     0,   511,   454,     0,   165,
       0,   184,   326,     0,     0,   185,     0,     0,     0,     0,
       0,     0,   482,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   230,     0,     0,     0,     0,
       0,     0,     0,     0,   221,     0,     0,   340,    37,     0,
     528,     0,     0,   272,   271,     0,     0,     0,     0,     0,
       0,   143,   144,   147,   146,   145,     0,   559,     0,   595,
       0,     0,     0,     0,     0,     0,    96,     0,     0,    97,
     534,     0,     0,     0,    88,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    46,     0,   220,   218,    33,     0,
       0,   592,   128,   139,     0,     0,   136,     0,     0,     0,
       0,     0,     0,   517,   518,     0,   461,   436,     0,   449,
     451,     0,   167,   188,     0,   333,   333,     0,   109,   110,
     215,     0,   208,   209,   295,     0,   301,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,   212,   211,
       0,     0,     0,     0,   105,   106,   563,   569,   568,   142,
       0,     0,     0,   322,     0,    92,    94,     0,   100,     0,
      82,   585,    89,    90,    49,     0,     0,     0,     0,   484,
       0,     0,   449,   542,     0,     0,     0,   118,   582,     0,
     125,     0,     0,   170,     0,     0,     0,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,   311,     0,     0,   289,     0,   222,     0,     0,     0,
       0,     0,     0,     0,   527,   273,     0,     0,   351,   215,
     365,     0,   532,     0,    45,     0,     0,     0,    62,    47,
       0,   117,   122,   128,     0,     0,   152,     0,     0,   437,
       0,     0,     0,     0,   334,   344,     0,     0,   345,     0,
     206,     0,   302,     0,   285,     0,   215,     0,     0,     0,
       0,     0,     0,   162,   107,   269,   317,    98,     0,     0,
       0,     0,     0,     0,   126,   127,     0,     0,     0,   186,
       0,   348,     0,   349,   350,   479,     0,     0,   291,   225,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
      59,     0,     0,   119,     0,     0,     0,     0,     0,   310,
     290,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   227,   228,   229,     0,   223,   324,    50,     0,
      57,     0,   263,     0,   520,     0,     0,     0,   292,     0,
       0,    51,     0,     0,   268,     0,     0,     0,   224,     0,
       0,     0,     0,   504,     0,     0,    54,    52,     0,    55,
       0,   346,   347,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1015,   109,   110,  1000,  1807,  1813,
    1283,  1486,  1953,  2080,  1284,  2051,  2098,  1285,  2082,  1286,
    1287,  1490,   415,   560,   561,  1081,   111,   739,   438,  1822,
    1963,  1823,   439,  1704,  1351,  1312,  1313,  1314,  1447,  1643,
    1644,  1146,  1537,  1529,   719,   571,   254,   255,   330,   185,
     256,   424,   425,   115,   116,   117,   118,   119,   120,   121,
     122,   257,  1178,  1985,  2042,   896,  1174,  1175,   258,   977,
     259,   126,  1379,  1144,   871,   910,  1923,   127,   128,   129,
     130,   260,   261,  1103,  1118,  1237,   262,   744,   263,   861,
     743,   441,   586,   299,  1680,   337,   338,   265,   530,   345,
    1271,  1479,   434,   430,  1230,   954,  1522,  1673,  1674,   939,
     436,   132,   393
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1769
static const yytype_int16 yypact[] =
{
   10775,    39,    83, 10925, -1769, -1769,    74,   118,   -40,  -173,
     -59,    22,    96,   178,   202,   232,    20,   286,    90,   113,
      46,  -166,  -166,    59,   127,   136,    45,   175,   218,    53,
     240,   245,   251,   292,   298,   303,   310,   332,   391,   399,
     224,   487,   554,   684,   438,   503,   460,  6147,   476,   484,
     623,   -30,   639,   576,     7,   632,   516,   706,   -75,   523,
     451,   451,   558,   470,   103, -1769, -1769, -1769, -1769, -1769,
     571,   411,   709,   722,    25,    58,   749,   752,    17,   858,
     859,   868,  5203,   889,   662,   663,   695,    31,    65, -1769,
     696,   702, -1769, -1769,   912,   935,   724, -1769, 11121,   733,
   11173,     9,    33, -1769, -1769, -1769, 10605,   732, -1769, -1769,
   -1769, -1769, -1769,   731, -1769, -1769, -1769, -1769, -1769, -1769,
   -1769, -1769, -1769, -1769,     1, -1769, -1769, -1769, -1769,    34,
   -1769,   968,   730,  4010,   325,   736,   973, 10605, 11092, 11092,
   -1769, 10605, -1769, -1769, -1769, -1769, 11092, -1769, -1769, -1769,
     734,   744,   974, -1769, -1769, 11286,    46, 10605, 10605, 10605,
     746, 10605, 10605, 10605,   747, 10605, 10605, 10605, 10605, 10605,
   10605, 10605, 11092, 10605, 10605, 10605, 10605,  5203,   748, -1769,
    8733, -1769, -1769, -1769,   745,  5203, 11092, -1769, -1769, -1769,
   -1769, -1769,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,   160,  -166,  -166,  -166,  -166,
    -166,   750,  -166,  -166,   751,   576, -1769, -1769, -1769,  -166,
    -166,    47,   814,   816,   817,   753,  6383,   879,   576,   756,
    -166,  -166,   762,   764,   765, -1769, -1769, -1769, 10605,  6619,
   10605, 10605,  6855,    46,   828,    48, -1769, -1769,   763, -1769,
    4877, -1769, -1769, -1769, -1769, -1769,   142, 10605,  8733,   768,
     778,  7091,  5203,  5203,  5203, -1769, -1769, -1769, -1769, -1769,
   -1769, -1769, -1769,   785,  7327,   786,  4248,  1025,  6383,   788,
      31,   789,   791,   451,   451,   451, 10605, 10605,   163, -1769,
     211,   451,  4337,   319,   329,   796,   797,   798,   799,   802,
     806,   818, 10605,  5203,  5203,  5203,   820,    14,  1049,   819,
   -1769,  1054,  1055, -1769,   821,   822,   823, -1769, -1769,   824,
    5203,   831,   832,   833, -1769, 10605,  5439, -1769,  1056,  1069,
   10605, 10605, 10605,   274, 10605,   834, -1769,   902, 10605, 10605,
   10605, -1769, -1769, 10605, -1769,  -166,  -166,  -166,   842,   843,
     844,  -166,  -166,  -166,  -166,  -166,  -166,  -166, -1769,  -166,
   -1769, -1769, -1769,  -166,  -166,   846,   849,  -166,   850, -1769,
     851,  1086,  1087,   852, -1769, -1769,  1092,  1091,  1094,  1093,
    -166, 10605, 13325,   166, 11092,  8733, 10605, -1769, -1769,  6383,
    6383, -1769,   860, 11286,   540,  1096, -1769, -1769, -1769, -1769,
   -1769, -1769, 10605, 10605,    56,  6383,  1098,   645,   360,   864,
    1102,    42,   867, -1769,   870, 11407, 10605, -1769,  1732,   -92,
   -1769,    88,   -71, 10254, -1769,   -45, -1769,   114,   -95,   222,
    1024, -1769,    46,   869,   874, 13841, 13866, 13891, 10605, 13916,
   13941, 13966, 10605, 13991, 14016, 14041, 14066, 14091, 14116, 14141,
     875, 14166, 14191, 14216,  4973,  1108, 10605,  8733,  7735, -1769,
     198, 10605,  1116,   884, 10605, 10605, 10605, 10605, 10605, 10605,
   10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605,
    8733, 10605, 10605, 10605, 10605, 10605, 10605,  8733,  8733,   882,
   10605, 10605, 11092, 10605, 11092,  6383, 11092, 11092, 11092,   883,
   10605,    78, -1769,  9601, 10605,  6383,  5203, 11092, 11092,  8733,
      46, 11286,    46,   890,  8733,   890, -1769,   890, 14241, -1769,
     392,   885,    69,  1064, -1769,  1123, 10605, 10605, 10605, 10605,
   10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605,
    7563, 10605, 10605, 10605, 10605, 10605,    46, 10605, 10605,  1128,
   -1769,   728, 14266,   420, 10605, 10605, 10605, -1769,  1129,  1130,
    1130,   897, 10605, 10605,  1132,  8733,  8733, 13353,   921,  1157,
   -1769,   922, -1769, -1769,  -146, -1769, -1769, 10476, 11046,   451,
     451,   325,   325,  -141,  4337,  4337, 10605,  1370,  -135, -1769,
   10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605, 10605, 14291,
    1158,  1160,  1161, 10605,  1163, 10605, -1769, 10605,  5270, -1769,
   -1769,  8733,  8733,  8733, 10605,  1164, 10605, 10605, 10605, 14316,
     931, -1769, -1769, 14341, 14366, 14391,   994, 11227, -1769,   933,
    7966, 14416, 14441, 13436, 11092, 11092, 11092, 11092, 11092, 11092,
   11092, 11092, 11092, 10605, 11092, 11092, 11092, 11092,    16, 11286,
   11092, 11092, 11092,    46,    46, -1769, -1769,  8733, -1769,   934,
    5506, -1769,   937,  5742, 10605,   890, 10605, -1769,    46, 10605,
   10605,  1128,   940,   456, 14466, 11293,   939,   462, 10605,  1170,
     947,   948,   949,   951, 10605, 14491, 13463,   208,   952,  1185,
    1188, -1769, -1769, -1769,  8733,   203, -1769, -1769, -1769,    46,
   10605, 10605,  1128,   955, -1769,   964,   -28,   576,     7, -1769,
     961, 12426, -1769,    26,  8733,    46, 10605, 10605,  1200,  1199,
    8733, 10605,  1201, 11092,    46,  9677,  1200,  1202, -1769,    46,
    1203, 11092, 10605,   967,   971, -1769, 10605, 11286,  1205,  1206,
    1207, 14516,  1209,  1210,  1211, 14541,  1214,  1215,  1216,  1218,
    1220,  1222,  1224, -1769,  1225,  1227,  1228, -1769, 10605, 14566,
    8733,   995,  8733, 12455, -1769,  1230, 13409, 13409, 13409, 13409,
   13409, 13409, 13409, 13409, 13409, 13409, 13409, 11337, 13409, 13409,
   13409, 13409,  1505,   365, 13409, 13409, 13409, 11370, 11403, 11436,
    7735,  1000,   999,   135,  8733, 11469, 11502,   365, 11535,   365,
     996,   997,   998,   120, 10605, 15366, -1769,   365,  1003, 12484,
   12513, -1769,  1002,   -49,   365,   -80,  1008,   473,   550,  1234,
   -1769,  1200,   365,  1010,  1007,  8433,  8669,  1341,  1786,   519,
     519,   531,   531,   531,   531,   531,   531,   379,   379,  8733,
     -10, -1769,   -10,   -10,   890,   890,   890,  1009, 14591, 13490,
     -19,   430,  8733, -1769,  1235,  1012, 14616, 14641, 14666, 10605,
    6383,  1251,  1250,  9370, 12542, 14691, -1769,   559,   564,  8733,
    1013, -1769,  5978, -1769,  6214,  6450,   451, 10605, 10605, -1769,
   -1769,  1015,  1016,  4337,  9940,  1133,   528,   451,  6686, 14716,
   12571, 14741, 14766, 14791, 14816, 14841, 14866, 14891,  1253, 10605,
    1257, -1769, 10605, 14916, -1769, 13517, 13544, -1769,   567,   573,
     574, 12600, -1769, 13571, 13598, 11568, -1769, -1769,  1258,  1259,
    1261,  1020, 10605,  6922, 10605, 10605, -1769, -1769,    51,   116,
     445,   116,  1030,  1031,  1027,   365,   365,  1028, 11601,   365,
     365,   365,   365, 10605,   365,  1262, -1769,  1029,  1033,   463,
     547,  1036,   581, -1769, -1769, -1769, -1769, 13409,   -10,  7158,
    1034,   515,  1035,  1103,  1275,  1135,  9908,  1041,  1043,  1280,
    6383, 12629, -1769, 10605, 10605, 10605, 10605,  1887,   212,    87,
   11286, 10605,  1284,  1287,    32, -1769,   582,  1248,  1249,  6383,
      23,  1052, 14941, 13625,   143, 10605, 10605,  1059,  1057,  1060,
    7799, -1769, -1769, -1769, -1769, 11092,   156,  1058, 14966, 13652,
   -1769,  1062, -1769,   226, 11634, -1769, -1769, -1769,  1061, -1769,
    1063, -1769,    68, -1769, -1769, 15366, -1769,  1299, 13409,   365,
     451,  6383,  6383,  1297,  6383,  6383,  6383,  1300,  6383,  6383,
    6383,  6383,  6383,  6383,  6383,  6383,  6383,  6383,  2027,  1302,
    8733,  7735, -1769, -1769, -1769, -1769, -1769, -1769, -1769, -1769,
   -1769, -1769, -1769, -1769, -1769, -1769, 10605, -1769, -1769, -1769,
   -1769, -1769, -1769, -1769, -1769, -1769, 10605, 10605, 10605, -1769,
   -1769, -1769,   583, 10605, 10605, -1769, 10605, -1769,  6383, 11092,
   11092, -1769, 12658,  1065, -1769, -1769, -1769,  1134, 10605, 10605,
   -1769, -1769, -1769,  1200, -1769,  1200, 10605, 10605,  1067, -1769,
    6383,  -166, -1769, 10605, -1769, 10605, 10605,   588,  1200,   -19,
     -94, -1769, 10605, 10605,   365,   589,  6383,  8733,  1304,  1306,
    1307,  9320, -1769, -1769,  1309, -1769,  1077, 15366,  1071, -1769,
    1312,  1313,  1315,   590,  1319, -1769,  7394, -1769, -1769,  -109,
   11667, 11700, -1769, -1769, 12687,  -150,  1241,  1320,  9991,  1084,
    1327,  1100,    24,    35,   326, -1769,  -102, -1769,   528,  1336,
    1344,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  6383, 15366,
   -1769,  2587,  1109,  1354,  1355,  1356,  1267,  1357, -1769,  1360,
    1363, 10605,  6383,  6383,  6383,  1366, 11733, -1769,  8995,  1707,
      57,  1367, -1769,  8733, -1769, -1769, -1769, -1769, 11092, -1769,
   -1769, 10605, 11092, -1769, -1769, -1769, -1769, 15366, -1769,  1131,
    1138, 11092, -1769, 11092, -1769,  1200, 11092,  1136, -1769,  1140,
   -1769,  1200, 10605, 10605,  1139,   576,  1146, 10222, -1769,  2704,
    1147,  6383, -1769,  1148, -1769, 12716, 12745, 12774, 12803, -1769,
   -1769, 10605,  1371,    63, 10605,  1376,  1384,  2847, -1769,  1385,
      31,  1387,  1154,   365,  -166,  -166,  1390, -1769,  1159,  1162,
    1156, -1769,  1393, -1769, -1769, -1769, -1769, -1769,  1200,   -70,
     876, 10605, 13679, 14991, 10605,  8030, 10605,  1165,   591,  1395,
      41,  1200, -1769,  1166, 10605,  1396, 10605,  1200, 10298,  8964,
     365,  4656,  1168,  1169, -1769,  1397,  1398,    98,  1283,  1283,
    6383,  1401,  1405,  1406,  6383,  1239,  1412,  1413,  1414,  1416,
    1417,  1418,  1419,  1420,  1421, -1769,  1423,   597, 13409, 13409,
   13409, 13409,   365, 11766, 11799, 11832,  1191,   365,   365, -1769,
    1299,   365, 15016, 13409,  1192,  -151, 15366, 13409, -1769,  1426,
     365, 11865, 15366, 15366, -1769,   526, -1769,  1429, -1769, 15041,
   13706, -1769,   365,  1428,   598,  6383,  6383,  6383,  1431,  1430,
   -1769,   221, 10605,  6383,  1195,  1196,  1432,   548, -1769, 10605,
   10605, 10605,  1198,  1204,  1208,  1212, -1769,  3130,  6383, -1769,
   10605, -1769,  1436, -1769,  1438, -1769, -1769,  4337,   378,  5675,
   -1769,  1213,  1217,  1231,  1233,  1242,  1243,  8261,  1439, -1769,
    8733, -1769, -1769, -1769,  1245, 10605, -1769, -1769, 13733,  1441,
    1442,  1277, -1769, 10605, 10605, 10605, -1769,  1445,  1447,  1448,
     607,   477,  1244,  9548,  1247, 10605,    30,   365,  1260,   365,
    1254, -1769, -1769, 11286,   615, 10605,  1255, -1769, -1769,  3198,
   -1769, -1769,  1263,  1450, -1769, -1769, -1769, -1769,  3374, -1769,
     216,  1246,  1491,  3544, -1769, -1769, -1769,    31, -1769,   600,
   -1769, 10605,   221,  1630,  2476, -1769,  1219, 10605, 10605,  6383,
    1264, -1769,   169,  1496,  1498, 15066,  1499,  1234, 15091,  1265,
     613, 15116,  1503,  1506, -1769, -1769, 11092,  1279,  1511, 15141,
   -1769, 11898,  1281, -1769,  4941, 15366, -1769,  1495,  -166,  6855,
   -1769, -1769, -1769, -1769,  1299, -1769, -1769, -1769,   451,  1512,
    1514,  1515, -1769, -1769, -1769,  1516,  1433,  1518, -1769, -1769,
   -1769, -1769, -1769, -1769, -1769, -1769, -1769,  1520,  1286, -1769,
   -1769, -1769, -1769, -1769, 10605, 10605, 10605, -1769, -1769, -1769,
    1169, -1769, -1769, -1769, -1769, 10605,  1290,  1285, -1769, -1769,
   10605, 10605, 10605,   365,   -19, -1769, -1769, -1769, -1769,  1288,
    1525,  1239,  1527, 10605, -1769,  6383, 15366,   950,  8733,  8733,
   10605, -1769,  9370, 12832, 15166,  9633,   325,   325, 10605, 10605,
   -1769,   119,  1289, 15191, -1769, -1769, 12861,   -98, -1769,  1528,
    1531,  6383,   451,   451,   451,   451,   451,  5911,  1535, -1769,
     618, 10605,  3578,  1536, -1769, -1769,  6383,  9864,   555, 15216,
   -1769, -1769, -1769, -1769,  9049, -1769, 11092, 10605, -1769, 11092,
   15366,  9285, 11286,  1296, -1769, -1769, -1769, -1769,  1305,  1298,
   10605, 10605, 12890, 10605, 11293, -1769, 11293,  6383, -1769, -1769,
   11286, 10605,  1540,  1522,    32, -1769,  1541, -1769,    31, 13760,
    6383, 11092,  1542,   365, -1769,  1303,   365, 10605, 11931, 11964,
     621, -1769, 10605, 10605,   323, -1769,  1310, -1769,  1307,  1545,
    1549,  1312, -1769, -1769,  1568, 10605, -1769, -1769, 10605, 10529,
   -1769, -1769,  1334,  2476,   627,  4693,  1570, -1769,   507, -1769,
   -1769, -1769, -1769,  1337, -1769,  1578,  6383, 13409, 13409, 11997,
   13409, -1769,  1345, 12030, 15241, 13787, -1769, -1769, 10605, -1769,
    1581, -1769, 15366,  1582,  1359, -1769,   628,   630, 13381,  3604,
    1583,  1361, -1769, -1769, 10605,  1353,  1362, 12919, 13814,  1584,
    6383,  1585,  1364, 10605, -1769, -1769,   635,   -93,   -87,   -56,
     -46,   -27,  8497,   -15, -1769,  1587, 12948, -1769, -1769,  1440,
   -1769, 10605, 10605, -1769, -1769,  8733,  3677,  1588,  1358, 13409,
     365, 15366, -1769, -1769, -1769, -1769,    30, -1769, 11286, -1769,
   12977,  1369,  1372,  1373,  1596,  3955, -1769,  1597,  1601, -1769,
   -1769,  1365,  1604,   636, -1769,  1611,  1612,   253, 15366, 10605,
   10605,  1377,  6383,   642, 15366, 15266, -1769, -1769, -1769, 15291,
   12063, -1769,  1065,  1138,  6383,   365, -1769, 10605, 11286,    46,
   10605,  1614,   649, -1769, -1769, 10605,  1285, -1769, 10605, -1769,
   -1769, 13006, -1769, -1769,  6383,   562,   657,  8733, -1769, -1769,
     325, 10169, -1769, -1769, -1769,  1615, -1769,  1379,  6383, -1769,
   13035,  1618,  8733,   451,   451,   451,   451,   451, -1769, -1769,
   10605, 13064, 13093,   651, -1769, -1769, -1769, -1769, -1769, -1769,
    1386,  1621,  1388, -1769,  1622, -1769, -1769,    31, -1769,  1455,
   -1769, -1769, -1769, -1769, -1769, 10605, 12096, 12129,  6383, -1769,
    1625, 10605,  1399, -1769, 10605,  1389,  1394, -1769, -1769,   924,
   -1769,  1400, 13122, -1769,  1402, 12162,  1403, 12195, -1769,   656,
    1404,   451,  6383,  1637,  1407,   451,  1639,   659,  1408, -1769,
   10605, -1769,  1641,  1463,  7630,  1410, -1769,   664,   -13,   223,
     235,   241,   250,  4396, -1769, -1769,  1644,  1647, -1769, -1769,
   -1769,  1649, -1769,  1415, 15366, 10605, 10605,   665, -1769, 15366,
   12228, -1769, -1769,  1065, 11286,  1424, -1769, 10605, 10605, -1769,
   10605,  1650,   451,   161, -1769, -1769,   451,   167, -1769,  1652,
   -1769, 13151, -1769, 10605, -1769,   528, -1769,  1653,  8733,  8733,
    8733,  8733,  8497, -1769, -1769, -1769, 11293, -1769, 10605, 15316,
   12261,    37, 10605,  1427, -1769, -1769, 12294, 12327, 12360, -1769,
     264, -1769,   302, -1769, -1769, -1769,  4592,   397,  8328, -1769,
     666,   667,   672,   673,   313,   674,  1443,   699, -1769, 10605,
   -1769,  6383, 13180, -1769, 10605, 10605, 10605,   451,   451, -1769,
   -1769, -1769,   528,  1658,  1660,  1663,  1666,  8733,  1667,  1668,
    1669,  1446, 15341,   704,  1681, 13209, 13409, 12393,   317,   375,
     472, -1769, -1769, -1769, -1769,   710, -1769, -1769, -1769, 11092,
   -1769,  1451, -1769,  1688, -1769, 10605, 10605, 10605, -1769,  1690,
     712, -1769,  1459,  6383, -1769, 13238, 13267, 13296, -1769,  1699,
   11092, 11092,   718, -1769,  1700,  1701, -1769, -1769,   719, -1769,
    1703, -1769, -1769,  1704, 11092, -1769, -1769, -1769
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1769, -1769, -1769, -1769,   412, -1769, -1769, -1769, -1769,  -287,
   -1769, -1769, -1769, -1769, -1769, -1769, -1769, -1769, -1769, -1769,
   -1769, -1769,  -674,  -131,  3022,  3161, -1769,  1301, -1769, -1769,
   -1769, -1769, -1769, -1769, -1768, -1769,   366,   194,   -84, -1769,
     -41, -1769,   168,   422,  1745, -1769,     6,   -47, -1769, -1769,
       3,  -588,  -278, -1769, -1769, -1769, -1769, -1769, -1769, -1769,
   -1769,  1747, -1769, -1769, -1769, -1769, -1173, -1163,  1748, -1635,
    1749, -1769, -1769, -1769,  1183, -1769,   -90, -1769, -1769, -1769,
   -1769,  1888, -1769, -1769, -1343,   304,  1754, -1769,     2,  -673,
   -1769, -1769,   233, -1769, -1585,   -31,  -152,  2394,   228,  -289,
      94, -1769,   680,   -85, -1769, -1769,   121,   276, -1604,  -136,
    1032, -1769,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -544
static const yytype_int16 yytable[] =
{
     133,   581,   416,   891,   892,  1408,   114,   284,   971,   113,
     435,  1406,  1566,   381,   386,   385,   264,   152,   614,  1791,
     150,  1792,   151,   991,   597,   465,  1756,  1277,   140,   317,
    1401,   999,  1012,   472,  1641,   343,   150,  1784,   388,  1004,
     398,  1403,   618,  2030,   266,     4,   150,  1505,   420,   160,
     150,   709,   512,   534,  1905,  1021,   137,   164,  1210,   279,
     697,  1437,   322,  1030,   323,   138,   270,  1470,   270,   347,
     443,   321,   153,   289,   154,  1309,   589,   590,   442,   266,
     589,   590,   150,     5,   346,   589,   590,   153,   271,   154,
    1007,   589,   590,  1393,  1260,   382,  1116,   725,   290,  1825,
     280,   886,   142,   281,  1527,   282,   893,   304,   318,   670,
     327,   673,   897,   328,   291,   292,   283,   589,   590,   685,
     568,   569,   570,   734,   589,   590,   329,   536,   589,   590,
     421,  1832,   136,   589,   590,   431,   431,   423,  1389,   589,
     590,   410,   411,   437,   556,  1407,   737,   723,   324,  1753,
    1367,   556,   738,   444,  1862,   724,  1438,  1439,  1121,  1112,
    1863,   610,   611,   612,  1113,   410,   411,  2011,   729,   431,
     589,   590,  -538,  2013,   266,   678,   730,   266,   625,   139,
     589,   590,   266,   431,   143,  1402,  1278,  1279,  1280,  1281,
     702,  1864,   703,   305,   732,  2003,  1404,   306,  1109,   589,
     590,  1865,   733,   307,   308,   264,   309,   310,   144,   319,
     997,   589,   590,   589,   590,   990,   410,   411,  1642,  1260,
    1866,   553,   554,  1660,  1722,   311,   107,   555,  1260,   698,
     699,   509,  1867,   266,  1988,   107,  1471,  1472,   145,   396,
     567,   107,   107,   397,   516,  1406,   266,  1013,  1014,   266,
     532,   387,   107,   574,   615,   531,   107,   579,   146,  1919,
     135,   953,  1013,  1014,   141,   266,  1282,   320,   266,   266,
     266,   266,   399,   344,  1270,   389,   400,   410,   411,  2031,
     710,   266,   711,   161,  -536,   266,   712,   346,   107,   513,
     535,   165,   147,   298,   300,  1211,   303,   157,   406,   407,
     408,   409,   882,   348,   884,   885,   153,   153,   154,   154,
     266,   266,   266,  1957,  1261,  1264,   134,   702,   689,   703,
     135,   898,   410,   411,   589,   590,   726,   266,   727,   422,
     148,  1263,   728,   266,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   735,   149,   727,   702,   555,   703,   736,  1101,
     933,  2026,  1749,   733,   821,   158,   706,   733,   686,   687,
     410,   411,   813,   557,   159,   558,  1091,   410,   411,   559,
     557,  1291,   558,  1243,   700,  -539,   559,   589,   590,   589,
     590,   431,   266,   589,   590,  1300,   266,   266,   497,   969,
     498,   410,   411,   772,   679,   591,   680,  1683,   470,  1651,
     681,  -540,   266,   162,   406,   407,   408,   998,   713,   406,
     407,   408,   409,   406,   407,   408,   409,   406,   407,   408,
     409,   720,   406,   407,   408,   409,   826,   589,   590,   745,
    1354,   771,  1355,   410,   411,   772,  2053,   410,   411,   589,
     590,   410,   411,   592,  1167,  1365,   163,    59,    60,    61,
      62,   589,   590,   740,   266,  1305,   176,   589,   590,   738,
    1989,  1168,    73,   772,   810,    76,   589,   590,   166,  1169,
    1170,  1171,  1990,   167,   567,  1172,  1173,   266,  1991,   168,
     589,   590,  1894,  1916,   266,   803,   563,  1992,  2092,   431,
    1895,   431,   266,   431,   431,   437,  1167,   313,   817,   314,
     941,  2037,   266,   266,   431,   431,   266,   152,   636,   152,
     135,   266,   825,  1168,   827,  1167,   584,   585,   589,   590,
     169,  1169,  1170,  1171,   593,   598,   170,  1172,  1173,   589,
     590,   171,  1168,   589,   590,   589,   590,   266,   172,  2038,
    1169,  1170,  1171,   857,  1591,  1592,  1172,  1173,   410,   411,
    2047,   599,  1450,  1772,  2076,  -543,   992,   600,  1454,  1405,
     173,   601,   266,   266,   956,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,   181,   423,   423,   182,   555,   177,   183,
    1167,   589,   590,   720,   702,  1156,   703,   676,   551,   552,
     553,   554,   184,  1633,  1634,  1492,   555,  1168,   266,   266,
     266,  1608,  2077,   683,   720,  1169,  1170,  1171,  1507,   174,
     690,  1172,  1173,   691,  1512,   830,   692,   175,   693,   772,
    2040,   437,   431,   437,   431,   431,   431,   431,   431,   431,
     178,   431,   431,   431,   431,   955,  1167,   431,   431,   431,
     152,   961,  1039,   865,   266,   960,   275,   772,  1132,   276,
    1133,  1009,   277,  1168,   278,   970,   720,   294,   295,   720,
     180,  1169,  1170,  1171,   702,    40,   703,  1172,  1173,   296,
     179,   720,  1213,   297,  1920,  1921,   294,   295,   186,   973,
    1922,   266,   702,   772,   703,   979,  1001,  1585,   296,   980,
    1233,   153,   302,   154,   267,  2078,   702,  1115,   703,   269,
    1116,   266,  1017,  1008,   772,   285,   268,   266,   286,  1131,
     437,  1028,   272,   589,   590,   273,  1032,   274,   431,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,   828,  1242,   287,  1243,   555,   548,   549,   676,
     551,   552,   553,   554,  1571,   293,  1572,   266,   555,   266,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,  1148,  1924,
    1925,  1235,   555,  1119,  1236,  1922,  1661,   772,  1773,   288,
     301,   266,  1151,   877,   878,   315,   772,  1152,  1670,   312,
    1195,   772,  2017,   419,   772,   316,  1196,  1197,   429,   432,
     772,   772,   889,   890,  1239,  1273,  1342,   585,   772,   772,
     772,  1364,  1372,  1386,  1503,   772,   772,   772,   772,  1142,
    1548,  1579,   325,  1667,   772,   772,   266,  1668,   326,   918,
     919,   920,   460,  1650,  1406,  1651,  1690,  1262,  1265,   266,
     772,  1765,   331,   332,  1811,   772,   473,   266,  1812,  2060,
    1826,  1845,   333,  1846,  1827,   772,   266,   772,  1861,  1891,
     150,   354,  1812,   733,   702,  1900,   703,   704,   720,  1901,
     720,   720,  1914,   339,  1946,   962,  1812,  1406,   772,  1971,
     340,   341,  1979,  1812,   720,  1266,   772,  1987,  2001,  2043,
    2044,   772,  1812,   772,   772,  2045,  2046,  2048,   351,   772,
     772,   772,   355,   356,   357,   358,   359,   360,   361,   362,
     363,  1964,   996,   342,   349,   364,   365,   366,   367,   720,
     350,   352,  2050,   368,   369,   370,  1901,  2071,   371,  1253,
     372,  1812,  1016,  2079,  1734,  2089,  1735,   772,  1023,  2090,
     373,  2100,  2103,   374,   353,  1812,  2104,   702,  1276,   703,
     862,   383,   394,   395,   401,   720,   402,   266,   426,   427,
     135,  1478,   440,   442,   448,   452,   466,   471,   505,   508,
    -190,  1272,  -191,  -192,   517,   514,   266,   515,  1366,  1368,
     520,   404,   521,   522,   533,   397,   564,   266,  1745,  1746,
    1318,  1319,   431,  1321,  1322,  1323,   565,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,   572,   575,   578,
     580,   582,  1092,   583,   602,   603,   604,   605,   266,   266,
     606,   266,   266,   266,   607,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   616,   608,   266,   613,   617,
     619,   620,   631,   621,   622,   623,   624,  1346,   375,   376,
     377,   626,   627,   628,   682,   632,   638,  1127,   639,   378,
     647,   648,   649,   379,   660,   380,   107,   661,   663,  1359,
    1135,   664,   665,   666,   667,   266,   431,   431,   668,   669,
     671,   672,   688,   694,   701,  1373,   707,  1153,   708,   134,
     742,   410,   411,   714,   763,   768,   746,   266,  -537,  1159,
    1493,   747,   774,   775,   804,   814,  1165,   555,   833,   831,
    1176,   834,   860,   266,   266,   873,   869,   870,   876,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,  1418,  1366,  1368,
     880,   555,   720,   881,   883,   909,   911,   931,   912,   914,
     922,  1429,  1430,  1431,   927,   934,   982,   963,   978,  1654,
     965,   972,   807,  1656,   809,   266,   811,   812,  1666,   983,
     984,   985,   994,   986,   995,  1005,   993,   822,   823,   266,
     266,   266,  1006,  1010,  1020,  1022,  1036,  1025,  1031,  1033,
     266,  1037,  1040,  1041,  1042,   431,  1044,  1045,  1046,   431,
    1462,  1048,  1049,  1050,  1516,  1051,  1521,  1052,   431,  1053,
     431,  1054,  1055,   431,  1056,  1057,  1064,  1060,  1298,  1089,
    1090,  1120,  1136,  1098,  1099,  1100,  1105,  1114,   266,  1108,
    1124,  1456,  1123,  1128,  1137,  1143,  1145,  1154,  1162,  1163,
    1188,  1166,  1928,  1190,  1205,  1202,  1203,   346,  1204,  1216,
    1217,  1229,  1232,  1317,  1218,  1221,  1231,  1238,  1241,  1245,
    1520,  1244,  1246,  1247,  1250,  1251,  1252,   431,  1337,  1531,
    1268,  1269,   266,  1535,  1274,  1275,  1288,  1294,  1296,  1295,
    1304,  1308,  1301,  1311,  1320,  1307,  1358,  1324,   266,  1336,
    -193,  1375,  1350,  1376,  1377,  1380,  1381,   266,  1382,  1383,
    1384,   266,  1385,  1387,  1395,   940,  1398,   942,   943,   944,
     945,   946,   947,  1399,   949,   950,   951,   952,  1400,  1662,
     957,   958,   959,  1409,  1580,  1581,  1582,  1675,  1675,  1394,
    1410,  1420,  1587,  1411,  1412,  1413,  1414,  1415,  1416,  1417,
    1421,  1422,  1423,  1424,  1425,  1374,  1426,  1602,  1649,  1427,
    1432,  1440,   266,   266,   266,  1452,  1445,  1469,  1610,  1800,
     266,  1455,  1474,     7,     8,  1446,  1618,  1453,  1457,  1461,
    1475,  1463,  1477,  1480,  1481,   266,  1485,  1487,  1489,  1491,
    1488,  1504,  1510,  1525,  1526,  1528,   266,  1532,  1502,  1523,
    1508,  1533,  1534,  1026,   266,  1536,  1524,   266,  1538,  1539,
    1540,  1034,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1701,
    1557,  1564,  1568,  1574,  1578,  1583,  1584,  1588,  1589,  1590,
    1596,  1441,  1604,  1727,  1605,  1619,  1597,  1624,  1625,  1626,
    1598,  1630,  1599,  1631,  1632,  1611,  1658,  1677,  1681,  1612,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,  1613,   346,  1614,    37,    38,    39,    40,
     437,   437,    42,  1700,  1615,  1616,   266,  1621,   715,    48,
    1663,  1636,    50,   716,  1639,   717,   718,  1653,  1664,  1646,
    1684,  1236,  1702,   431,  1685,  1687,  1682,  1740,  1689,  1692,
    1657,   266,  1693,   536,    70,  1696,   266,  1695,  1709,  1699,
    1710,  1711,  1712,  1500,  1714,  1715,  1797,  1713,  1716,  1721,
    1728,  1729,  1116,  1731,  1754,  1803,  1750,  1755,    84,    85,
      86,  1764,  1768,  1786,  1787,  1788,  1796,  1799,  1804,  1777,
     733,  1816,  -541,  1727,  1733,  1817,  1782,  1785,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,  1818,  1794,  1824,  1829,   555,  1830,
    1681,  1934,   266,  1831,  1837,   266,   266,  1842,  1843,  1849,
    1856,  1983,  1858,  1868,  1875,  1769,  1852,  1876,  1951,   423,
     423,  1844,  1885,  1850,  1887,  1853,  1859,  1888,   266,  1889,
    1890,  1870,  1882,   895,   266,  1883,  1884,  1892,  1893,  1898,
    1913,  1931,  1932,   266,  1936,  1947,  1793,  1948,  1950,  1952,
    1949,  1958,  1961,   431,   150,   354,   431,  1962,  1965,  1802,
    1607,  -542,  1969,  1975,  1967,  1978,  1972,  1982,  1620,  1976,
    1994,  1980,  1986,  1995,   266,  1997,  2009,  1998,  2014,  2019,
     720,  1272,   720,  2005,  2061,   346,  2062,   266,   437,  2063,
    2033,  1996,  2064,  2066,  2067,  2068,   355,   356,   357,   358,
     359,   360,   361,   362,   363,  1681,  2049,  2072,  2069,   364,
     365,   366,   367,  2083,  2084,  1299,  2088,   368,   369,   370,
     437,  2091,   371,  1880,   372,  2096,  2101,  2102,  2018,  2105,
    2106,  2027,  1506,   266,   373,  1435,  1560,   374,  1707,  1857,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   770,   551,   552,   553,   554,   722,  1906,
     741,  1530,   555,  1910,   702,  1879,   703,   266,   112,  1730,
     123,   124,   125,   872,  1648,   404,  1926,   131,  1798,   266,
    1676,  1708,  1783,     0,     0,  1027,     0,     0,     0,     0,
       0,     0,   266,     0,     0,     0,     0,     0,     0,  1347,
    1348,  1899,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1907,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,     0,  1681,     0,     0,  1736,  1737,     0,     0,
       0,   266,   375,   376,   377,     0,  1911,  1933,     0,     0,
       0,     0,     0,   378,     0,     0,     0,   379,     0,   380,
     107,   266,     0,     0,   266,  1757,  1758,  1759,  1760,  1761,
    1763,     0,     0,   423,     0,   266,     0,     0,     0,   266,
       0,     0,     0,     0,     0,     0,     0,  1681,     0,   702,
       0,   703,  1671,     0,     0,     0,     0,     0,     0,  2004,
       0,     0,     0,     0,   346,     0,     0,     0,     0,     0,
       0,  1974,     0,  1259,     0,   266,     0,     0,  1442,     0,
       0,     0,  1444,     0,     0,     0,     0,     0,     0,     0,
       0,  1448,     0,  1449,     0,     0,  1451,     0,     0,   266,
       0,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
     720,     0,     0,     0,   555,     0,  1436,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
    1494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   266,   266,   266,   266,
       0,     0,     0,     0,   392,     0,     0,     0,     0,     0,
    1681,     0,   720,  1873,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,   418,     0,   555,   720,   428,     0,     0,   266,   433,
       0,     0,     0,  1335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   445,   446,   447,     0,   449,
     450,   451,  1681,   453,   454,   455,   456,   457,   458,   459,
       0,   461,   462,   463,   464,     0,   431,     0,   468,     0,
       0,     0,     0,     0,     0,  1927,     0,     0,     0,     0,
     266,     0,     0,     0,     0,     0,     0,   431,   431,     0,
    1937,     0,     0,     0,     0,     0,  1938,  1939,  1940,  1941,
    1942,   431,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,   525,   527,   528,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1973,   562,   468,     0,  1977,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,  1694,     0,     0,     0,
     588,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     609,     0,     0,     0,     0,  2010,     0,     0,     0,  2012,
       0,     0,     0,     0,     0,     0,  2020,  2021,  2022,  2023,
    2025,     0,     0,   629,   468,  2024,     0,     0,   633,   634,
     635,     0,   637,     0,     0,     0,   640,   641,   642,     0,
       0,   643,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    2058,  2059,     0,     0,     0,  2065,     0,     0,     0,   675,
       0,     0,     0,   468,   684,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     695,   696,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   721,     0,  1778,     0,     0,  1780,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   769,   525,     0,     0,     0,   773,
       0,     0,   776,   777,   778,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   794,
     795,   796,   797,   798,   799,   800,   800,     0,   805,   806,
       0,   808,     0,     0,     0,     0,     0,     0,   815,     0,
       0,   819,   820,     0,     0,     0,     0,   800,     0,     0,
       0,     0,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   846,   847,   848,   850,   852,
     853,   854,   855,   856,     0,   858,   859,     0,     0,     0,
       0,     0,   866,   867,   868,     0,     0,     0,     0,     0,
     874,   875,     0,   468,   468,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   354,   523,   675,   894,     0,     0,     0,   899,   900,
     901,   902,   903,   904,   905,   906,   907,     0,     0,     0,
       0,   913,     0,   915,     0,   916,     0,     0,     0,   468,
     468,   468,   921,     0,   923,   924,   925,     0,     0,     0,
       0,     0,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,   364,   365,   366,   367,     0,
       0,   948,     0,   368,   369,   370,     0,     0,   371,     0,
     372,     0,     0,     0,     0,   468,     0,     0,     0,     0,
     373,     0,   967,   374,   968,     0,     0,   858,   859,     0,
       0,     0,     0,     0,   469,     0,   981,     0,     0,     0,
       0,     0,   987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,  1419,     0,     0,     0,     0,  1002,  1003,
       0,   404,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,     0,  1018,  1019,     0,     0,   468,  1024,
       0,     0,     0,  1018,     0,     0,     0,     0,     0,     0,
    1035,     0,     0,     0,  1038,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1058,     0,   850,     0,
    1061,     0,   469,     0,     0,     0,     0,     0,   375,   376,
     377,     0,     0,     0,     0,     0,     0,     0,     0,   378,
       0,     0,     0,   379,     0,   380,   107,     0,     0,     0,
       0,     0,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,     0,     0,     0,     0,     0,     0,     0,
    1460,     0,     0,     0,     0,     0,     0,     0,  1671,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,     0,     0,     0,     0,     0,     0,   468,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2081,
     468,     0,     0,     0,     0,     0,     0,  1141,     0,     0,
       0,  1147,     0,     0,     0,     0,     0,   468,     0,     0,
    2097,  2099,     0,     0,     0,  1160,  1161,     0,     0,     0,
       0,  1164,     0,     0,  2107,     0,     0,     0,     0,   469,
       0,     0,     0,     0,     0,     0,     0,  1189,     0,     0,
    1191,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
    1206,     0,  1208,  1209,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1476,     0,     0,     0,     0,     0,     0,
       0,   526,     0,     0,  1249,     0,     0,     0,     0,     0,
       0,  1255,  1256,  1257,  1258,     0,     0,     0,     0,  1267,
       0,     0,     0,     0,   793,     0,     0,     0,     0,     0,
       0,   801,   802,  1292,  1293,     0,     0,     0,   468,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   824,     0,     0,     0,     0,   469,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,   851,     0,     0,     0,   468,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1338,     0,     0,     0,     0,   469,
     469,     0,     0,     0,  1339,  1340,  1341,     0,     0,     0,
       0,  1343,  1344,     0,  1345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1352,  1353,     0,     0,
       0,     0,     0,     0,  1356,  1357,     0,     0,     0,     0,
       0,  1361,     0,  1362,  1363,   469,   469,   469,     0,     0,
    1369,  1370,     0,     0,     0,   468,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1397,     0,     0,     0,
       0,   469,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,  1428,
       0,     0,     0,     0,     0,     0,     0,     0,   469,     0,
       0,   468,     0,     0,     0,     0,     0,     0,     0,  1443,
       0,     0,     0,     0,     0,     0,     0,     0,   469,     0,
       0,     0,     0,     0,   469,     0,     0,     0,     0,     0,
    1369,  1370,     0,     0,     0,  1459,  1600,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1468,
       0,     0,  1473,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,   851,     0,  1062,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1495,
       0,     0,  1498,   468,  1501,     0,     0,     0,     0,     0,
       0,     0,  1509,     0,  1511,     0,  1509,  1515,   469,     0,
       0,     0,     0,     0,  1655,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   499,   500,   501,
     502,   503,   504,   469,   506,   507,     0,     0,     0,     0,
       0,   510,   511,     0,     0,     0,   469,     0,     0,     0,
       0,     0,   518,   519,     0,     0,     0,     0,     0,     0,
    1586,     0,     0,   469,     0,     0,     0,  1593,  1594,  1595,
       0,     0,     0,     0,     0,     0,  1601,     0,  1603,     0,
       0,     0,     0,     0,     0,  1606,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   468,     0,
       0,     0,     0,  1622,     0,     0,     0,     0,     0,     0,
       0,  1627,  1628,  1629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1652,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,  1669,
       0,     0,     0,     0,     0,  1678,  1679,   644,   645,   646,
    1659,     0,     0,   650,   651,   652,   653,   654,   655,   656,
       0,   657,     0,     0,     0,   658,   659,     0,     0,   662,
       0,     0,     0,     0,   469,     0,     0,  1705,     0,     0,
       0,     0,   674,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,  1717,  1718,  1719,     0,     0,     0,     0,     0,
       0,     0,     0,  1720,   469,     0,     0,     0,  1723,  1724,
    1725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1732,     0,     0,     0,     0,   468,   468,  1738,     0,
    1739,     0,     0,     0,     0,     0,  1747,  1748,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,     0,     0,     0,  1766,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1776,     0,     0,  1779,     0,     0,     0,  1781,
       0,   469,     0,     0,     0,     0,     0,     0,  1724,  1725,
       0,  1790,     0,     0,     0,     0,     0,     0,     0,  1795,
    1665,     0,     0,     0,   832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1808,     0,     0,     0,     0,
    1814,  1815,     0,     0,     0,     0,     0,     0,   705,     0,
       0,     0,     0,  1819,  1767,     0,  1820,  1819,     0,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,   469,     0,     0,
    1848,   555,     0,     0,     0,     0,  1841,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1851,     0,     0,     0,     0,     0,     0,     0,
       0,  1860,     0,     0,     0,     0,     0,     0,     0,     0,
     525,     0,     0,     0,     0,     0,     0,     0,     0,  1871,
    1872,     0,     0,   468,     0,     0,     0,     0,     0,     0,
       0,     0,   816,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1874,     0,     0,     0,     0,     0,   469,
       0,     0,     0,     0,     0,     0,     0,  1896,  1897,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1909,     0,     0,  1912,     0,
       0,     0,   863,  1915,     0,     0,  1917,     0,     0,     0,
       0,     0,     0,     0,     0,   468,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,     0,     0,     0,     0,     0,     0,     0,  1943,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,  1954,     0,     0,     0,     0,     0,  1959,
       0,     0,  1960,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,   469,   555,     0,     0,  1981,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,  1999,  2000,     0,     0,     0,     0,  1117,
       0,     0,     0,     0,     0,  2006,  2007,     0,  2008,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2016,     0,     0,     0,     0,   468,   468,   468,   468,
     468,     0,     0,  1134,     0,     0,  1814,     0,     0,     0,
    2032,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,  1706,   555,     0,     0,  2052,     0,     0,
       0,     0,  2055,  2056,  2057,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,     0,  1065,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,     0,  1077,
    1078,  1079,  1080,     0,  1082,  1083,  1084,  1085,     0,     0,
       0,  1886,     0,  2085,  2086,  2087,     0,     0,  1095,     0,
    1097,     0,     0,     0,     0,     0,     0,     0,  1104,     0,
       0,     0,   469,   469,  1110,  1111,     0,     0,     0,     0,
       0,     0,     0,  1122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,     0,   187,   150,   354,     0,   403,     0,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   390,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,  1310,     0,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   220,   221,   222,   223,   364,
     365,   366,   367,   224,     0,     0,     0,   368,   369,   370,
       0,     0,   371,     0,   372,   226,   227,   228,     0,     0,
       0,     0,   229,    20,   373,   230,     0,   374,     0,     0,
    1212,  1214,  1215,     0,     0,     0,  1219,  1220,     0,     0,
    1223,  1224,  1225,  1226,     0,  1228,     0,     0,     0,     0,
    1234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   404,     0,     0,     0,     0,
       0,     0,     0,  1360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,   405,     0,     0,     0,     0,  1315,
    1316,   239,   375,   376,   377,   240,     0,     0,     0,     0,
     242,   243,   244,   378,   245,   246,   247,   379,     0,   380,
     107,   406,   407,   408,   409,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   391,     0,     0,
       0,   469,     0,   250,     0,   410,   411,     0,   412,     0,
     413,   187,   150,     0,   414,   253,   469,     0,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     390,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,  1371,  1483,  1484,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,   228,     0,     0,     0,     0,
     229,    20,     0,   230,     0,     0,     0,     0,     0,     0,
     187,   150,     0,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   390,
     209,   210,   211,   212,   213,   214,     0,  1565,     0,     0,
       0,     0,   469,   469,   469,   469,   469,  1573,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,  1993,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   227,   228,     0,     0,     0,     0,   229,
      20,     0,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1482,     0,     0,     0,     0,   239,
       0,   469,     0,   240,     0,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1517,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   335,     0,     0,     0,
     576,     0,     0,   253,     0,     0,     0,     0,     0,  1549,
    1550,  1551,  1552,  1553,     0,     0,     0,     0,  1558,  1559,
       0,     0,  1561,     0,  1563,     0,     0,     0,  1567,     0,
       0,  1569,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,   240,  1577,     0,     0,     0,   242,   243,   244,
    1703,   245,   246,   247,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   596,     0,     0,     0,   297,
       0,     0,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2039,     0,
       0,     0,  1635,     0,  1638,     0,     0,     0,  1645,     0,
    1647,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1672,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       6,   354,     0,     0,     0,     0,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
    1828,   536,  1518,   356,   357,   358,   359,   360,   361,   362,
     363,   220,   221,   222,   223,   364,   365,   366,   367,   224,
     225,     0,     0,   368,   369,   370,     0,     0,   371,     0,
     372,   226,   227,   228,  1726,     0,     0,     0,   229,    20,
     373,   230,     0,   374,     0,     0,   231,     0,     0,   232,
       0,     0,   233,     0,   234,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,    49,     0,     0,   237,
       0,   238,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,  1805,     0,     0,  1806,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   375,   376,
     377,   240,   241,     0,     0,     0,   242,   243,   244,   378,
     245,   246,   247,   379,     0,   380,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1833,  1834,
       0,  1836,   248,   249,     0,   536,     0,     0,     0,   250,
       0,     0,     0,     0,   335,     0,     0,     0,  1519,     0,
       0,   253,     0,     0,     0,     0,     0,     0,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   770,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1877,  1878,     0,     0,   187,     6,   354,     0,     0,     0,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,  1908,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   220,   221,   222,   223,
     364,   365,   366,   367,   224,   225,     0,     0,   368,   369,
     370,     0,     0,   371,     0,   372,   226,   227,   228,     0,
       0,     0,     0,   229,    20,   373,   230,     0,   374,     0,
       0,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    49,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   375,   376,   377,   240,   241,     0,     0,
       0,   242,   243,   244,   378,   245,   246,   247,   379,     0,
     380,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,   335,
       0,     0,     0,   252,     0,     0,   253,     0,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,   187,     6,   334,     0,
     555,     0,     0,   188,   189,   190,   767,  2074,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     7,     8,   229,    20,     0,   230,     0,
       0,     0,     0,   231,     0,     0,   232,     0,     0,   233,
       0,   234,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    49,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   715,    48,
       0,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   335,   187,     6,     0,   336,     0,   630,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   917,   226,   227,   228,     0,     0,     7,
       8,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,     0,   237,     0,   238,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   715,    48,     0,     0,    50,   716,
     239,   717,   718,     0,   240,   241,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   107,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   467,     0,     0,     0,
       0,     0,   250,     0,    84,    85,    86,   335,   187,     6,
    1609,     0,   529,     0,   253,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   964,
     226,   227,   228,     0,     0,     7,     8,   229,    20,     0,
     230,     0,     0,     0,     0,   231,     0,     0,   232,     0,
       0,   233,     0,   234,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,    49,     0,     0,   237,     0,
     238,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     715,    48,     0,     0,    50,   716,   239,   717,   718,     0,
     240,   241,     0,     0,     0,   242,   243,   244,     0,   245,
     246,   247,     0,     0,     0,   107,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,     0,     0,   250,     0,
      84,    85,    86,   335,   187,     6,     0,   252,     0,     0,
     253,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   966,   226,   227,   228,     0,
       0,     7,     8,   229,    20,     0,   230,     0,     0,     0,
       0,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    49,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   715,    48,     0,     0,
      50,   716,   239,   717,   718,     0,   240,   241,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,  1762,     0,
       0,     0,     0,     0,   250,     0,    84,    85,    86,   596,
     187,     6,     0,   297,   529,     0,   253,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1155,   226,   227,   228,     0,     0,     7,     8,   229,
      20,     0,   230,     0,     0,     0,     0,   231,     0,     0,
     232,     0,     0,   233,     0,   234,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,    49,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   715,    48,     0,     0,    50,   716,   239,   717,
     718,     0,   240,   241,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   107,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,     0,     0,     0,
     250,     0,    84,    85,    86,   251,   187,     6,     0,   252,
       0,     0,   253,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1157,   226,   227,
     228,     0,     0,     7,     8,   229,    20,     0,   230,     0,
       0,     0,     0,   231,     0,     0,   232,     0,     0,   233,
       0,   234,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    49,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   715,    48,
       0,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   335,   187,     6,     0,   252,     0,     0,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1158,   226,   227,   228,     0,     0,     7,
       8,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,     0,   237,     0,   238,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   715,    48,     0,     0,    50,   716,
     239,   717,   718,     0,   240,   241,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   107,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   467,     0,     0,     0,
       0,     0,   250,     0,    84,    85,    86,   335,   187,     6,
       0,   524,     0,     0,   253,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1177,
     226,   227,   228,     0,     0,     7,     8,   229,    20,     0,
     230,     0,     0,     0,     0,   231,     0,     0,   232,     0,
       0,   233,     0,   234,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,    49,     0,     0,   237,     0,
     238,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     715,    48,     0,     0,    50,   716,   239,   717,   718,     0,
     240,   241,     0,     0,     0,   242,   243,   244,     0,   245,
     246,   247,     0,     0,     0,   107,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   467,     0,     0,     0,     0,     0,   250,     0,
      84,    85,    86,   335,   187,     6,     0,     0,   529,     0,
     253,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1207,   226,   227,   228,     0,
       0,     7,     8,   229,    20,     0,   230,     0,     0,     0,
       0,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    49,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   715,    48,     0,     0,
      50,   716,   239,   717,   718,     0,   240,   241,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     0,     0,     0,   250,     0,    84,    85,    86,   566,
     187,     6,     0,   252,     0,     0,   253,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1240,   226,   227,   228,     0,     0,     7,     8,   229,
      20,     0,   230,     0,     0,     0,     0,   231,     0,     0,
     232,     0,     0,   233,     0,   234,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,    49,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   715,    48,     0,     0,    50,   716,   239,   717,
     718,     0,   240,   241,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   107,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,     0,     0,     0,
     250,     0,    84,    85,    86,   573,   187,     6,     0,   252,
       0,     0,   253,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1388,   226,   227,
     228,     0,     0,     7,     8,   229,    20,     0,   230,     0,
       0,     0,     0,   231,     0,     0,   232,     0,     0,   233,
       0,   234,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    49,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,    40,
       0,     0,    42,   536,     0,     0,     0,     0,   715,    48,
       0,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     467,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   335,   187,     6,     0,   849,     0,  1297,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1984,   226,   227,   228,     0,     0,     0,
       0,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,     0,   237,     0,   238,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   770,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,   935,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,     0,     0,     0,   240,   241,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   467,     0,     0,     0,
       0,     0,   250,   187,     6,     0,     0,   335,  1499,     0,
     188,   189,   190,     0,   253,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,   227,   228,     0,     0,
       0,     0,   229,    20,     0,   230,     0,     0,     0,     0,
     231,     0,     0,   232,     0,     0,   233,     0,   234,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
      49,     0,     0,   237,     0,   238,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,   240,   241,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   467,     0,     0,
       0,     0,     0,   250,   187,     6,     0,     0,   335,     0,
       0,   188,   189,   190,     0,   253,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   227,   228,     0,
       0,     7,     8,   229,    20,     0,   230,     0,     0,     0,
       0,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    49,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,    40,     0,     0,
      42,  1125,     0,     0,     0,     0,   715,    48,     0,     0,
      50,   716,   239,   717,   718,     0,   240,   241,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     0,     0,     0,   250,     0,    84,    85,    86,   335,
     187,     6,     0,  1617,     0,     0,   253,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2041,   226,   227,   228,     0,     0,     0,     0,   229,
      20,     0,   230,     0,     0,     0,     0,   231,     0,     0,
     232,     0,     0,   233,     0,   234,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,    49,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,  1126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,   240,   241,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,  1762,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   596,   187,     6,     0,   297,
       0,     0,   253,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,   229,    20,     0,   230,     0,
       0,     0,     0,   231,     0,     0,   232,     0,     0,   233,
       0,   234,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    49,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     467,     0,     0,     0,     0,     0,   250,   187,   150,   354,
       0,   335,     0,     0,   188,   189,   190,     0,   253,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   390,   209,   210,   211,
     212,   213,   214,  1434,     0,     0,     0,     0,     0,     0,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   220,
     221,   222,   223,   364,   365,   366,   367,   224,     0,     0,
       0,   368,   369,   370,     0,     0,   371,     0,   372,   226,
     227,   228,     0,     0,     0,     0,   229,    20,   373,   230,
       0,   374,   187,   150,   354,     0,     0,     0,     0,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   390,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   220,   221,   222,   223,   364,   365,
     366,   367,   224,     0,     0,     0,   368,   369,   370,     0,
       0,   371,     0,   372,   226,   227,   228,     0,     0,     0,
       0,   229,    20,   373,   230,     0,   374,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   375,   376,   377,   240,
       0,     0,     0,     0,   242,   243,   244,   378,   245,   246,
     247,   379,     0,   380,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   391,     0,     0,     0,     0,     0,   250,     0,     0,
       0,     0,   335,     0,     0,     0,  1514,     0,     0,   253,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
     239,   375,   376,   377,   240,     0,     0,     0,     0,   242,
     243,   244,   378,   245,   246,   247,   379,     0,   380,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   391,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   335,   187,   150,
     354,  1775,     0,     0,   253,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   390,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,  1518,   356,   357,   358,   359,   360,   361,   362,   363,
     220,   221,   222,   223,   364,   365,   366,   367,   224,     0,
       0,     0,   368,   369,   370,     0,     0,   371,     0,   372,
     226,   227,   228,     0,     0,     0,     0,   229,    20,   373,
     230,     0,   374,   187,   150,   354,     0,     0,     0,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   390,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   220,   221,   222,   223,   364,
     365,   366,   367,   224,     0,     0,     0,   368,   369,   370,
       0,     0,   371,     0,   372,   226,   227,   228,  1378,     0,
       0,     0,   229,    20,   373,   230,     0,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   375,   376,   377,
     240,     0,     0,     0,     0,   242,   243,   244,   378,   245,
     246,   247,   379,     0,   380,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   391,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,   335,     0,     0,     0,  1671,     0,     0,
     253,     0,     0,     0,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,   239,   375,   376,   377,   240,     0,     0,     0,     0,
     242,   243,   244,   378,   245,   246,   247,   379,     0,   380,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   391,     0,     0,
       0,     0,     0,   250,   187,   150,     0,     0,   335,   818,
       0,   188,   189,   190,     0,   253,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   390,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   227,   228,     0,
     187,   150,     0,   229,    20,     0,   230,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   390,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   227,   228,     0,     0,     0,     0,   229,
      20,     0,   230,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,   702,     0,   703,
       0,     0,   239,     0,     0,  1637,   240,     0,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   391,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,   335,
       0,     0,     0,     0,     0,     0,   253,     0,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,   239,     0,
     555,     0,   240,     0,     0,     0,  1743,   242,   243,   244,
    1744,   245,   246,   247,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   391,     0,     0,     0,     0,     0,
     250,   187,   150,     0,  1248,   335,  1029,     0,   188,   189,
     190,     0,   253,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     390,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,   228,     0,     0,     0,     0,
     229,    20,     0,   230,   187,   150,     0,  1396,     0,     0,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   390,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   227,   228,     0,
       0,     0,     0,   229,    20,     0,   230,     0,     0,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,   239,
       0,   555,     0,   240,     0,     0,     0,  1770,   242,   243,
     244,  1771,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   335,     0,     0,     0,
       0,     0,     0,   253,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,   926,
       0,     0,   239,     0,     0,     0,   240,   887,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   391,     0,
       0,     0,     0,     0,   250,   187,   150,     0,  1458,   335,
       0,     0,   188,   189,   190,     0,   253,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   390,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   227,   228,
       0,   187,   150,     0,   229,    20,     0,   230,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     390,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,   228,     0,     0,     0,     0,
     229,    20,     0,   230,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  1929,   239,     0,     0,  1930,   240,     0,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   391,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     335,     0,     0,     0,     0,     0,     0,   253,     0,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,   239,
       0,   555,     0,   240,     0,     0,     0,     0,   242,   243,
     244,   731,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,   187,   150,     0,     0,   335,  1513,     0,   188,
     189,   190,     0,   253,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   390,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   227,   228,     0,   187,   150,
       0,   229,    20,     0,   230,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   390,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,     0,     0,     0,     0,   229,    20,     0,
     230,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
     239,     0,     0,   887,   240,     0,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   391,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   335,  1821,     0,
       0,     0,     0,     0,   253,    -4,     1,     0,     0,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,   239,     0,     0,     0,
     240,     0,     0,     0,     0,   242,   243,   244,     0,   245,
     246,   247,     0,     0,     0,   107,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   391,     0,     0,     0,     0,     0,   250,    -4,
      -4,    -4,     0,   335,     0,    -4,    -4,     0,    -4,     0,
     253,     0,     0,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,
      10,     0,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,     0,     0,     0,    11,
      12,    13,     0,     0,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    17,     0,    18,    19,     0,    20,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,    37,    38,    39,    40,    41,     0,    42,     0,    43,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    79,    80,    81,     0,     0,     0,    82,     0,     0,
       0,     0,    83,    84,    85,    86,   150,   354,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   150,   354,     0,     0,     0,
       0,     0,     0,   106,     0,   107,     0,     0,   355,   356,
     357,   358,   359,   360,   361,   362,   363,     0,     0,     0,
       0,   364,   365,   366,   367,     0,     0,     0,     0,   368,
     369,   370,     0,     0,   371,     0,   372,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   373,   384,   354,   374,
     364,   365,   366,   367,     0,     0,     0,     0,   368,   369,
     370,     0,     0,   371,     0,   372,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   373,     0,     0,   374,     0,
       0,     0,     0,     0,     0,     0,     0,   404,     0,   355,
     356,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,   364,   365,   366,   367,     0,     0,     0,     0,
     368,   369,   370,     0,     0,   371,     0,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   373,     0,     0,
     374,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,   375,   376,   377,     0,     0,     0,
       0,   354,     0,   888,     0,   378,     0,     0,     0,   379,
       0,   380,   107,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,   378,     0,     0,     0,   379,     0,
     380,   107,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,   364,   365,   366,   367,     0,
       0,     0,     0,   368,   369,   370,     0,     0,   371,     0,
     372,     0,     0,     0,     0,   375,   376,   377,     0,     0,
     373,     0,     0,   374,     0,     0,   378,     0,     0,     0,
     379,     0,   380,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   715,    48,     0,     0,    50,   716,     0,   717,   718,
       7,     8,     0,     0,   975,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,   976,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,    84,    85,    86,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   932,     0,     0,     0,   375,   376,
     377,     0,     0,     0,     0,     0,     0,     0,     0,   378,
       0,     0,     0,   379,     0,   380,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   715,    48,     0,     0,    50,
     716,     0,   717,   718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,    84,    85,    86,     0,     0,
       0,     0,     0,     0,  1076,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1086,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1087,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1088,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1093,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1094,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1096,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1201,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1222,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1306,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1390,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1391,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1433,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1554,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1555,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1556,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1570,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1698,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1809,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1810,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1835,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1838,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1904,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1955,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1956,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1968,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1970,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2002,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2029,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2034,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2035,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2036,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2075,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  1011,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,  1063,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  1106,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,  1107,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,  1149,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,  1180,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,  1198,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  1254,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,  1349,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    1392,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  1464,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,  1465,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  1466,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,  1467,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,  1741,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,  1752,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,  1789,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  1854,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,  1869,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    1881,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  1918,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,  1935,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  1944,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,  1945,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,  1966,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,  2015,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,  2054,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  2073,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,  2093,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    2094,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  2095,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,   677,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,   879,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,  1847,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,   702,     0,
     703,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,   938,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,   989,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,  1130,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,  1193,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,  1194,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,  1199,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,  1200,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,  1290,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,  1303,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
    1496,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,  1576,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,  1623,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,  1801,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,  1840,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,  1855,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     748,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   749,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     750,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   752,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     753,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   754,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     756,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   757,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     758,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   759,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     760,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   761,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     762,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   764,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     765,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   766,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     829,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   864,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     908,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   926,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     928,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   929,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     930,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   936,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     937,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,   974,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
     988,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1043,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1047,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1059,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1129,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1138,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1139,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1140,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1150,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1179,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1181,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1182,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1183,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1184,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1185,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1186,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1187,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1192,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1289,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1302,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1497,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1562,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1575,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1686,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1688,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1691,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1697,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1742,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1751,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1774,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1839,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1902,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1903,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  2028,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    2070,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555
};

static const yytype_int16 yycheck[] =
{
       3,   290,   133,   591,   592,  1178,     3,    54,   681,     3,
     146,  1174,  1355,    98,     5,   100,    47,    20,     4,  1654,
       4,  1656,    20,   697,   302,   177,  1611,     4,     6,     4,
       6,   705,     6,   185,     4,     4,     4,  1641,     5,   712,
       6,     6,   320,     6,    47,     6,     4,     6,   133,     4,
       4,     9,     5,     5,  1822,   728,    96,     4,     7,    53,
       4,     4,     4,   736,     6,   238,    96,     4,    96,     4,
     155,    74,   238,   148,   240,     7,   226,   227,     9,    82,
     226,   227,     4,     0,    87,   226,   227,   238,   118,   240,
     118,   226,   227,   243,     7,    98,   247,     9,   173,  1703,
      93,   247,     6,    96,     6,    98,   247,     4,    83,   387,
      93,   389,   247,    96,   189,   190,   109,   226,   227,   397,
     272,   273,   274,     9,   226,   227,   109,     8,   226,   227,
     133,  1716,    14,   226,   227,   138,   139,   134,   247,   226,
     227,   235,   236,   146,     9,   247,   241,   239,    90,   247,
     244,     9,   247,   156,   247,   247,    99,   100,   831,   239,
     247,   313,   314,   315,   244,   235,   236,     6,   239,   172,
     226,   227,   242,     6,   177,     9,   247,   180,   330,   238,
     226,   227,   185,   186,     6,   161,   163,   164,   165,   166,
     239,   247,   241,    90,   239,  1963,   161,    94,   247,   226,
     227,   247,   247,   100,   101,   236,   103,   104,     6,   184,
       7,   226,   227,   226,   227,     7,   235,   236,   188,     7,
     247,   231,   232,     7,  1567,   122,   210,   237,     7,   173,
     174,   225,   247,   236,   247,   210,   173,   174,     6,   238,
     271,   210,   210,   242,   238,  1408,   249,   221,   222,   252,
     253,   242,   210,   284,   240,   253,   210,   288,   238,  1844,
     246,   245,   221,   222,   242,   268,   243,   242,   271,   272,
     273,   274,   238,   242,   242,   242,   242,   235,   236,   242,
     238,   284,   240,   238,   242,   288,   244,   290,   210,   242,
     242,   238,     6,    60,    61,   244,    63,   238,   211,   212,
     213,   214,   580,   238,   582,   583,   238,   238,   240,   240,
     313,   314,   315,  1898,   988,   989,   242,   239,   403,   241,
     246,   599,   235,   236,   226,   227,   238,   330,   240,     4,
     240,   244,   244,   336,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   238,   240,   240,   239,   237,   241,   244,   239,
     638,  1996,   243,   247,   516,   238,     6,   247,   399,   400,
     235,   236,   508,   238,   238,   240,   241,   235,   236,   244,
     238,   238,   240,   240,   415,   242,   244,   226,   227,   226,
     227,   394,   395,   226,   227,   239,   399,   400,   238,   677,
     240,   235,   236,   247,   238,   242,   240,   238,   180,   240,
     244,   242,   415,   238,   211,   212,   213,   214,   421,   211,
     212,   213,   214,   211,   212,   213,   214,   211,   212,   213,
     214,   425,   211,   212,   213,   214,   521,   226,   227,   442,
    1113,   243,  1115,   235,   236,   247,  2031,   235,   236,   226,
     227,   235,   236,   242,   128,  1128,   238,   132,   133,   134,
     135,   226,   227,   241,   467,   239,   242,   226,   227,   247,
     247,   145,   147,   247,   505,   150,   226,   227,   238,   153,
     154,   155,   247,   238,   515,   159,   160,   490,   247,   238,
     226,   227,   239,  1836,   497,   498,   268,   247,  2083,   502,
     247,   504,   505,   506,   507,   508,   128,    96,   511,    98,
     646,   247,   515,   516,   517,   518,   519,   520,   244,   522,
     246,   524,   520,   145,   522,   128,   293,   294,   226,   227,
     238,   153,   154,   155,   301,   302,   238,   159,   160,   226,
     227,   238,   145,   226,   227,   226,   227,   550,   238,   247,
     153,   154,   155,   556,     6,     7,   159,   160,   235,   236,
     247,   242,  1235,     8,   247,   242,   697,   238,  1241,   243,
     238,   242,   575,   576,   659,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    90,   591,   592,    93,   237,   111,    96,
     128,   226,   227,   597,   239,   883,   241,   228,   229,   230,
     231,   232,   109,     6,     7,  1288,   237,   145,   621,   622,
     623,   243,   247,   395,   618,   153,   154,   155,  1301,   238,
      90,   159,   160,    93,  1307,   243,    96,   238,    98,   247,
     243,   644,   645,   646,   647,   648,   649,   650,   651,   652,
      96,   654,   655,   656,   657,   658,   128,   660,   661,   662,
     663,   664,   747,   243,   667,   663,    90,   247,   238,    93,
     240,   718,    96,   145,    98,   678,   670,   226,   227,   673,
     242,   153,   154,   155,   239,   109,   241,   159,   160,   238,
       6,   685,   247,   242,   132,   133,   226,   227,   238,   243,
     138,   704,   239,   247,   241,   243,   709,  1381,   238,   247,
     247,   238,   242,   240,   238,   243,   239,   244,   241,    96,
     247,   724,   725,   717,   247,    93,   242,   730,    96,   860,
     733,   734,    93,   226,   227,    96,   739,    98,   741,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   524,   238,   238,   240,   237,   226,   227,   228,
     229,   230,   231,   232,   238,   242,   240,   770,   237,   772,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   873,   132,
     133,   244,   237,   243,   247,   138,  1470,   247,   243,    93,
     242,   804,   243,   575,   576,    96,   247,   243,  1482,   238,
     243,   247,  1985,   133,   247,    93,   243,   243,   138,   139,
     247,   247,   589,   590,   243,   243,   243,   594,   247,   247,
     247,   243,   243,   243,   243,   247,   247,   247,   247,   870,
     243,   243,    93,   243,   247,   247,   849,   247,    96,   621,
     622,   623,   172,   238,  2017,   240,   243,   988,   989,   862,
     247,   243,     4,     4,   243,   247,   186,   870,   247,  2042,
     243,   243,     4,   243,   247,   247,   879,   247,   243,   243,
       4,     5,   247,   247,   239,   243,   241,   242,   882,   247,
     884,   885,   243,     4,   243,   667,   247,  2060,   247,   243,
     238,   238,   243,   247,   898,   990,   247,   243,   243,   243,
     243,   247,   247,   247,   247,   243,   243,   243,     6,   247,
     247,   247,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     7,   704,   238,   238,    59,    60,    61,    62,   933,
     238,     6,   243,    67,    68,    69,   247,   243,    72,   980,
      74,   247,   724,   243,     4,   243,     6,   247,   730,   247,
      84,   243,   243,    87,   240,   247,   247,   239,   999,   241,
     242,   238,   240,   242,     6,   969,   246,   980,   242,     6,
     246,  1270,   238,     9,   238,   238,   238,   242,   238,   238,
     176,   994,   176,   176,   238,   242,   999,   118,  1129,  1130,
     238,   125,   238,   238,   176,   242,   238,  1010,  1596,  1597,
    1041,  1042,  1015,  1044,  1045,  1046,   238,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,  1056,  1057,   242,   242,     4,
     242,   242,   804,   242,   238,   238,   238,   238,  1041,  1042,
     238,  1044,  1045,  1046,   238,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,     6,   238,  1060,   238,   240,
       6,     6,     6,   242,   242,   242,   242,  1098,   192,   193,
     194,   240,   240,   240,   394,     6,   242,   849,   176,   203,
     238,   238,   238,   207,   238,   209,   210,   238,   238,  1120,
     862,   240,     6,     6,   242,  1098,  1099,  1100,     6,     8,
       6,     8,   242,     7,     6,  1136,   242,   879,     6,   242,
      86,   235,   236,   243,   239,     7,   247,  1120,   242,   886,
     244,   247,     6,   239,   242,   242,   893,   237,    64,   244,
     897,     8,     4,  1136,  1137,   238,     7,     7,     6,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,  1188,  1289,  1290,
     239,   237,  1156,     6,   242,     7,     6,   173,     7,     6,
       6,  1202,  1203,  1204,   243,   242,     6,   243,   239,  1457,
     243,   241,   502,  1461,   504,  1188,   506,   507,  1477,   242,
     242,   242,     7,   242,     6,   240,   244,   517,   518,  1202,
    1203,  1204,   238,   242,     4,     6,   239,     6,     6,     6,
    1213,   240,     7,     7,     7,  1218,     7,     7,     7,  1222,
    1251,     7,     7,     7,  1309,     7,  1311,     7,  1231,     7,
    1233,     7,     7,  1236,     7,     7,     6,   242,  1010,   239,
     241,     7,     7,   247,   247,   247,   243,   239,  1251,   247,
     243,  1245,   242,   244,   242,     4,     6,   244,   243,   243,
       7,   128,  1850,     6,   244,     7,     7,  1270,     7,   239,
     239,     9,   239,  1040,   247,   247,   247,   241,   244,   176,
    1311,   246,     7,   148,   243,   242,     6,  1290,  1060,  1320,
       6,     4,  1295,  1324,    46,    46,   244,   238,   238,   242,
     238,   238,   244,     4,     7,   244,   239,     7,  1311,     7,
     176,     7,   247,     7,     7,     6,   239,  1320,   247,     7,
       7,  1324,     7,     4,     4,   645,   242,   647,   648,   649,
     650,   651,   652,     6,   654,   655,   656,   657,   238,  1470,
     660,   661,   662,     7,  1375,  1376,  1377,  1483,  1484,   108,
       6,   242,  1383,     7,     7,     7,     7,     7,     7,     7,
       6,     6,     6,    96,     7,  1137,     6,  1398,  1453,     6,
       4,     4,  1375,  1376,  1377,   239,   245,     6,  1409,  1668,
    1383,   242,     6,    13,    14,   247,  1417,   247,   242,   242,
       6,   243,     7,     6,   240,  1398,     6,   238,   242,     6,
     238,     6,     6,     6,     6,   122,  1409,     6,   243,   241,
     244,     6,     6,   733,  1417,   176,   247,  1420,     6,     6,
       6,   741,     6,     6,     6,     6,     6,     6,     5,  1514,
     239,   239,     6,     4,     6,     4,     6,   242,   242,     7,
     242,  1213,     6,  1574,     6,     6,   242,     6,     6,   172,
     242,     6,   240,     6,     6,   242,     6,   238,  1489,   242,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   242,  1477,   242,   106,   107,   108,   109,
    1483,  1484,   112,  1514,   242,   242,  1489,   242,   118,   119,
     244,   247,   122,   123,   247,   125,   126,   242,     7,   239,
       4,   247,     7,  1506,     6,     6,   242,  1592,   243,     6,
     247,  1514,     6,     8,   144,     4,  1519,   238,     6,   238,
       6,     6,     6,  1295,     6,     5,     4,    94,   242,   239,
     242,     6,   247,     6,     6,  1671,   247,     6,   168,   169,
     170,     6,     6,   247,   239,   247,     6,     6,     6,  1634,
     247,     6,   242,  1684,  1585,     6,  1641,  1642,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,     6,  1660,   242,     7,   237,   242,
    1611,  1859,  1585,     5,   239,  1588,  1589,     6,     6,     6,
       6,   128,     7,     6,     6,  1626,   243,   239,  1887,  1596,
    1597,   242,     6,   242,     7,   243,   242,     6,  1611,   244,
       6,   171,   243,   243,  1617,   243,   243,     6,     6,   242,
       6,     6,   243,  1626,     6,   239,  1657,     6,     6,   174,
     242,     6,   243,  1636,     4,     5,  1639,   243,   238,  1670,
    1407,   242,   239,     6,   242,     6,   242,     6,  1420,   242,
       6,   243,   242,     6,  1657,     6,     6,   242,     6,     6,
    1654,  1664,  1656,   239,     6,  1668,     6,  1670,  1671,     6,
     243,  1949,     6,     6,     6,     6,    46,    47,    48,    49,
      50,    51,    52,    53,    54,  1716,   243,     6,   242,    59,
      60,    61,    62,   242,     6,  1015,     6,    67,    68,    69,
    1703,   242,    72,  1788,    74,     6,     6,     6,  1986,     6,
       6,  1998,  1300,  1716,    84,     8,  1350,    87,  1524,  1750,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,     6,  1823,
     439,  1319,   237,  1828,   239,  1786,   241,  1750,     3,  1581,
       3,     3,     3,   570,  1450,   125,  1846,     3,  1664,  1762,
    1484,  1528,  1641,    -1,    -1,   733,    -1,    -1,    -1,    -1,
      -1,    -1,  1775,    -1,    -1,    -1,    -1,    -1,    -1,  1099,
    1100,  1812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1812,
      -1,    -1,    -1,  1844,    -1,    -1,  1588,  1589,    -1,    -1,
      -1,  1824,   192,   193,   194,    -1,  1829,  1858,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,   209,
     210,  1844,    -1,    -1,  1847,  1612,  1613,  1614,  1615,  1616,
    1617,    -1,    -1,  1850,    -1,  1858,    -1,    -1,    -1,  1862,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1898,    -1,   239,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,  1964,
      -1,    -1,    -1,    -1,  1887,    -1,    -1,    -1,    -1,    -1,
      -1,  1922,    -1,     6,    -1,  1898,    -1,    -1,  1218,    -1,
      -1,    -1,  1222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1231,    -1,  1233,    -1,    -1,  1236,    -1,    -1,  1922,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
    1934,    -1,    -1,    -1,   237,    -1,   239,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
    1290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1988,  1989,  1990,  1991,  1992,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
    2031,    -1,  1996,  1775,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,   133,    -1,   237,  2018,   137,    -1,    -1,  2031,   141,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2047,   157,   158,   159,    -1,   161,
     162,   163,  2083,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,   174,   175,   176,    -1,  2069,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,  1847,    -1,    -1,    -1,    -1,
    2083,    -1,    -1,    -1,    -1,    -1,    -1,  2090,  2091,    -1,
    1862,    -1,    -1,    -1,    -1,    -1,  1863,  1864,  1865,  1866,
    1867,  2104,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,   251,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1921,   267,   268,    -1,  1925,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   296,   297,  1506,    -1,    -1,    -1,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,    -1,    -1,    -1,    -1,  1972,    -1,    -1,    -1,  1976,
      -1,    -1,    -1,    -1,    -1,    -1,  1988,  1989,  1990,  1991,
    1992,    -1,    -1,   335,   336,  1992,    -1,    -1,   340,   341,
     342,    -1,   344,    -1,    -1,    -1,   348,   349,   350,    -1,
      -1,   353,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
    2037,  2038,    -1,    -1,    -1,  2047,    -1,    -1,    -1,   391,
      -1,    -1,    -1,   395,   396,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     412,   413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,    -1,  1636,    -1,    -1,  1639,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,
     452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   466,   467,    -1,    -1,    -1,   471,
      -1,    -1,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,    -1,   500,   501,
      -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,   513,   514,    -1,    -1,    -1,    -1,   519,    -1,    -1,
      -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,    -1,   557,   558,    -1,    -1,    -1,
      -1,    -1,   564,   565,   566,    -1,    -1,    -1,    -1,    -1,
     572,   573,    -1,   575,   576,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,   594,   595,   596,    -1,    -1,    -1,   600,   601,
     602,   603,   604,   605,   606,   607,   608,    -1,    -1,    -1,
      -1,   613,    -1,   615,    -1,   617,    -1,    -1,    -1,   621,
     622,   623,   624,    -1,   626,   627,   628,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,   653,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,   667,    -1,    -1,    -1,    -1,
      84,    -1,   674,    87,   676,    -1,    -1,   679,   680,    -1,
      -1,    -1,    -1,    -1,   180,    -1,   688,    -1,    -1,    -1,
      -1,    -1,   694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   704,     6,    -1,    -1,    -1,    -1,   710,   711,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   724,    -1,   726,   727,    -1,    -1,   730,   731,
      -1,    -1,    -1,   735,    -1,    -1,    -1,    -1,    -1,    -1,
     742,    -1,    -1,    -1,   746,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,   770,    -1,
     772,    -1,   268,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   814,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,    -1,    -1,    -1,    -1,    -1,    -1,   849,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2069,
     862,    -1,    -1,    -1,    -1,    -1,    -1,   869,    -1,    -1,
      -1,   873,    -1,    -1,    -1,    -1,    -1,   879,    -1,    -1,
    2090,  2091,    -1,    -1,    -1,   887,   888,    -1,    -1,    -1,
      -1,   893,    -1,    -1,  2104,    -1,    -1,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,    -1,    -1,
     912,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     932,    -1,   934,   935,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   953,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   467,    -1,    -1,   976,    -1,    -1,    -1,    -1,    -1,
      -1,   983,   984,   985,   986,    -1,    -1,    -1,    -1,   991,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,  1005,  1006,    -1,    -1,    -1,  1010,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   519,    -1,    -1,    -1,    -1,   524,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,   550,    -1,    -1,    -1,  1060,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1076,    -1,    -1,    -1,    -1,   575,
     576,    -1,    -1,    -1,  1086,  1087,  1088,    -1,    -1,    -1,
      -1,  1093,  1094,    -1,  1096,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1108,  1109,    -1,    -1,
      -1,    -1,    -1,    -1,  1116,  1117,    -1,    -1,    -1,    -1,
      -1,  1123,    -1,  1125,  1126,   621,   622,   623,    -1,    -1,
    1132,  1133,    -1,    -1,    -1,  1137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,
      -1,   667,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,  1201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   704,    -1,
      -1,  1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   724,    -1,
      -1,    -1,    -1,    -1,   730,    -1,    -1,    -1,    -1,    -1,
    1242,  1243,    -1,    -1,    -1,  1247,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,
      -1,    -1,  1264,    -1,    -1,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   770,    -1,   772,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,
      -1,    -1,  1294,  1295,  1296,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1304,    -1,  1306,    -1,  1308,  1309,   804,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   849,   222,   223,    -1,    -1,    -1,    -1,
      -1,   229,   230,    -1,    -1,    -1,   862,    -1,    -1,    -1,
      -1,    -1,   240,   241,    -1,    -1,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,   879,    -1,    -1,    -1,  1389,  1390,  1391,
      -1,    -1,    -1,    -1,    -1,    -1,  1398,    -1,  1400,    -1,
      -1,    -1,    -1,    -1,    -1,  1407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1420,    -1,
      -1,    -1,    -1,  1425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1433,  1434,  1435,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1445,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1455,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,  1481,
      -1,    -1,    -1,    -1,    -1,  1487,  1488,   355,   356,   357,
       6,    -1,    -1,   361,   362,   363,   364,   365,   366,   367,
      -1,   369,    -1,    -1,    -1,   373,   374,    -1,    -1,   377,
      -1,    -1,    -1,    -1,  1010,    -1,    -1,  1519,    -1,    -1,
      -1,    -1,   390,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,  1554,  1555,  1556,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1565,  1060,    -1,    -1,    -1,  1570,  1571,
    1572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1583,    -1,    -1,    -1,    -1,  1588,  1589,  1590,    -1,
    1592,    -1,    -1,    -1,    -1,    -1,  1598,  1599,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1617,    -1,    -1,    -1,  1621,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1634,    -1,    -1,  1637,    -1,    -1,    -1,  1641,
      -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,  1650,  1651,
      -1,  1653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1661,
       6,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1677,    -1,    -1,    -1,    -1,
    1682,  1683,    -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,
      -1,    -1,    -1,  1695,     6,    -1,  1698,  1699,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,  1213,    -1,    -1,
       6,   237,    -1,    -1,    -1,    -1,  1728,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1753,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1771,
    1772,    -1,    -1,  1775,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,  1295,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1809,  1810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1827,    -1,    -1,  1830,    -1,
      -1,    -1,   561,  1835,    -1,    -1,  1838,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1847,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1862,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1870,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,  1895,    -1,    -1,    -1,    -1,    -1,  1901,
      -1,    -1,  1904,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,  1420,   237,    -1,    -1,  1930,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,  1955,  1956,    -1,    -1,    -1,    -1,   827,
      -1,    -1,    -1,    -1,    -1,  1967,  1968,    -1,  1970,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1983,    -1,    -1,    -1,    -1,  1988,  1989,  1990,  1991,
    1992,    -1,    -1,   861,    -1,    -1,  1998,    -1,    -1,    -1,
    2002,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,  1519,   237,    -1,    -1,  2029,    -1,    -1,
      -1,    -1,  2034,  2035,  2036,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2047,    -1,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   786,    -1,   788,
     789,   790,   791,    -1,   793,   794,   795,   796,    -1,    -1,
      -1,     6,    -1,  2075,  2076,  2077,    -1,    -1,   807,    -1,
     809,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   817,    -1,
      -1,    -1,  1588,  1589,   823,   824,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1617,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,  1032,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,
     939,   940,   941,    -1,    -1,    -1,   945,   946,    -1,    -1,
     949,   950,   951,   952,    -1,   954,    -1,    -1,    -1,    -1,
     959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1775,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,   184,    -1,    -1,    -1,    -1,  1038,
    1039,   191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,  1847,    -1,   233,    -1,   235,   236,    -1,   238,    -1,
     240,     3,     4,    -1,   244,   245,  1862,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1134,  1274,  1275,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,  1355,    -1,    -1,
      -1,    -1,  1988,  1989,  1990,  1991,  1992,  1365,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,    -1,   191,
      -1,  2047,    -1,   195,    -1,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1310,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
     242,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,  1338,
    1339,  1340,  1341,  1342,    -1,    -1,    -1,    -1,  1347,  1348,
      -1,    -1,  1351,    -1,  1353,    -1,    -1,    -1,  1357,    -1,
      -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,   195,  1372,    -1,    -1,    -1,   200,   201,   202,
    1518,   204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,  1441,    -1,  1443,    -1,    -1,    -1,  1447,    -1,
    1449,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       7,     8,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,  1573,    -1,    -1,    -1,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,  1673,    -1,    -1,  1676,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,  1718,
      -1,  1720,   226,   227,    -1,     8,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1779,  1780,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,  1825,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
     209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   242,    -1,    -1,   245,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,     3,     4,     5,    -1,
     237,    -1,    -1,    10,    11,    12,   243,  2056,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,   122,   123,   191,   125,   126,    -1,   195,   196,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,
     170,   238,     3,     4,    -1,   242,    -1,     8,   245,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   118,   119,    -1,    -1,   122,   123,
     191,   125,   126,    -1,   195,   196,    -1,    -1,    -1,   200,
     201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,   168,   169,   170,   238,     3,     4,
       5,    -1,   243,    -1,   245,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      75,    76,    77,    -1,    -1,    13,    14,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
     118,   119,    -1,    -1,   122,   123,   191,   125,   126,    -1,
     195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     168,   169,   170,   238,     3,     4,    -1,   242,    -1,    -1,
     245,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,
      -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
     122,   123,   191,   125,   126,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,
       3,     4,    -1,   242,   243,    -1,   245,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    75,    76,    77,    -1,    -1,    13,    14,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,   118,   119,    -1,    -1,   122,   123,   191,   125,
     126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,
      -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,   168,   169,   170,   238,     3,     4,    -1,   242,
      -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,
      77,    -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,   122,   123,   191,   125,   126,    -1,   195,   196,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,
     170,   238,     3,     4,    -1,   242,    -1,    -1,   245,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   118,   119,    -1,    -1,   122,   123,
     191,   125,   126,    -1,   195,   196,    -1,    -1,    -1,   200,
     201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,   168,   169,   170,   238,     3,     4,
      -1,   242,    -1,    -1,   245,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      75,    76,    77,    -1,    -1,    13,    14,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
     118,   119,    -1,    -1,   122,   123,   191,   125,   126,    -1,
     195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     168,   169,   170,   238,     3,     4,    -1,    -1,   243,    -1,
     245,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,
      -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
     122,   123,   191,   125,   126,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,
       3,     4,    -1,   242,    -1,    -1,   245,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    75,    76,    77,    -1,    -1,    13,    14,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,   118,   119,    -1,    -1,   122,   123,   191,   125,
     126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,
      -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,   168,   169,   170,   238,     3,     4,    -1,   242,
      -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,
      77,    -1,    -1,    13,    14,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    -1,   112,     8,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,   122,   123,   191,   125,   126,    -1,   195,   196,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,
     170,   238,     3,     4,    -1,   242,    -1,     8,   245,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
     201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,     3,     4,    -1,    -1,   238,     8,    -1,
      10,    11,    12,    -1,   245,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,     3,     4,    -1,    -1,   238,    -1,
      -1,    10,    11,    12,    -1,   245,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    13,    14,    82,    83,    -1,    85,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,
     112,     8,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
     122,   123,   191,   125,   126,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,
       3,     4,    -1,   242,    -1,    -1,   245,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,
      -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,   238,     3,     4,    -1,   242,
      -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,     3,     4,     5,
      -1,   238,    -1,    -1,    10,    11,    12,    -1,   245,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      -1,    87,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,   192,   193,   194,   195,
      -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,   242,    -1,    -1,   245,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,     3,     4,
       5,   242,    -1,    -1,   245,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    72,    -1,    74,    75,    76,    77,   128,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,   194,
     195,    -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,   242,    -1,    -1,
     245,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,     3,     4,    -1,    -1,   238,     8,
      -1,    10,    11,    12,    -1,   245,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
       3,     4,    -1,    82,    83,    -1,    85,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,   241,
      -1,    -1,   191,    -1,    -1,   247,   195,    -1,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,   191,    -1,
     237,    -1,   195,    -1,    -1,    -1,   243,   200,   201,   202,
     247,   204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,     3,     4,    -1,     6,   238,   239,    -1,    10,    11,
      12,    -1,   245,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,     3,     4,    -1,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   191,
      -1,   237,    -1,   195,    -1,    -1,    -1,   243,   200,   201,
     202,   247,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,
      -1,    -1,   191,    -1,    -1,    -1,   195,   247,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,     3,     4,    -1,     6,   238,
      -1,    -1,    10,    11,    12,    -1,   245,    15,    16,    17,
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
      82,    83,    -1,    85,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,   191,    -1,    -1,   247,   195,    -1,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   191,
      -1,   237,    -1,   195,    -1,    -1,    -1,    -1,   200,   201,
     202,   247,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,     3,     4,    -1,    -1,   238,   239,    -1,    10,
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
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,   247,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,   239,    -1,
      -1,    -1,    -1,    -1,   245,     0,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    64,
      65,    66,    -1,   238,    -1,    70,    71,    -1,    73,    -1,
     245,    -1,    -1,    78,    -1,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,   107,   108,   109,   110,    -1,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,     4,
      -1,   156,   157,   158,    -1,    -1,    -1,   162,    13,    14,
      -1,    -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    44,
      45,    -1,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,   210,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,   107,   108,   109,   110,    -1,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,   156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,     4,     5,   173,    -1,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   198,   199,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,   210,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    84,     4,     5,    87,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      87,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,   192,   193,   194,    -1,    -1,    -1,
      -1,     5,    -1,   247,    -1,   203,    -1,    -1,    -1,   207,
      -1,   209,   210,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,   192,   193,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,
     209,   210,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,   192,   193,   194,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,   203,    -1,    -1,    -1,
     207,    -1,   209,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,   118,   119,    -1,    -1,   122,   123,    -1,   125,   126,
      13,    14,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,   148,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   168,   169,   170,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,   209,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,   122,
     123,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,   168,   169,   170,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   215,   216,   217,   218,   219,   220,   221,   222,   223,
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
      -1,   243,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
     243,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   243,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,   242,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,   242,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,
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
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237
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
     122,   123,   124,   125,   126,   127,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   156,
     157,   158,   162,   167,   168,   169,   170,   173,   175,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   197,   198,   199,   208,   210,   251,   253,
     254,   274,   292,   294,   298,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   316,   318,   319,   325,   326,   327,
     328,   334,   359,   360,   242,   246,    14,    96,   238,   238,
       6,   242,     6,     6,     6,     6,   238,     6,   240,   240,
       4,   336,   360,   238,   240,   272,   272,   238,   238,   238,
       4,   238,   238,   238,     4,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   242,   111,    96,     6,
     242,    90,    93,    96,   109,   297,   238,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    64,    75,    76,    77,    82,
      85,    90,    93,    96,    98,   109,   118,   123,   125,   191,
     195,   196,   200,   201,   202,   204,   205,   206,   226,   227,
     233,   238,   242,   245,   294,   295,   298,   309,   316,   318,
     329,   330,   334,   336,   343,   345,   360,   238,   242,    96,
      96,   118,    93,    96,    98,    90,    93,    96,    98,   294,
      93,    96,    98,   109,   295,    93,    96,   238,    93,   148,
     173,   189,   190,   242,   226,   227,   238,   242,   340,   341,
     340,   242,   242,   340,     4,    90,    94,   100,   101,   103,
     104,   122,   238,    96,    98,    96,    93,     4,    83,   184,
     242,   360,     4,     6,    90,    93,    96,    93,    96,   109,
     296,     4,     4,     4,     5,   238,   242,   343,   344,     4,
     238,   238,   238,     4,   242,   347,   360,     4,   238,   238,
     238,     6,     6,   240,     5,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    61,    62,    67,    68,
      69,    72,    74,    84,    87,   192,   193,   194,   203,   207,
     209,   351,   360,   238,     4,   351,     5,   242,     5,   242,
      32,   227,   329,   360,   240,   242,   238,   242,     6,   238,
     242,     6,   246,     7,   125,   184,   211,   212,   213,   214,
     235,   236,   238,   240,   244,   270,   271,   272,   329,   350,
     351,   360,     4,   298,   299,   300,   242,     6,   329,   350,
     351,   360,   350,   329,   350,   357,   358,   360,   276,   280,
     238,   339,     9,   351,   360,   329,   329,   329,   238,   329,
     329,   329,   238,   329,   329,   329,   329,   329,   329,   329,
     350,   329,   329,   329,   329,   344,   238,   227,   329,   345,
     346,   242,   344,   350,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   238,   240,   272,
     272,   272,   272,   272,   272,   238,   272,   272,   238,   294,
     272,   272,     5,   242,   242,   118,   294,   238,   272,   272,
     238,   238,   238,   329,   242,   329,   345,   329,   329,   243,
     346,   336,   360,   176,     5,   242,     8,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   237,     9,   238,   240,   244,
     271,   272,   329,   346,   238,   238,   238,   343,   344,   344,
     344,   293,   242,   238,   343,   242,   242,   329,     4,   343,
     242,   347,   242,   242,   340,   340,   340,   329,   329,   226,
     227,   242,   242,   340,   226,   227,   238,   300,   340,   242,
     238,   242,   238,   238,   238,   238,   238,   238,   238,   329,
     344,   344,   344,   238,     4,   240,     6,   240,   300,     6,
       6,   242,   242,   242,   242,   344,   240,   240,   240,   329,
       8,     6,     6,   329,   329,   329,   244,   329,   242,   176,
     329,   329,   329,   329,   272,   272,   272,   238,   238,   238,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     238,   238,   272,   238,   240,     6,     6,   242,     6,     8,
     300,     6,     8,   300,   272,   329,   228,   242,     9,   238,
     240,   244,   350,   346,   329,   300,   343,   343,   242,   351,
      90,    93,    96,    98,     7,   329,   329,     4,   173,   174,
     343,     6,   239,   241,   242,   273,     6,   242,     6,     9,
     238,   240,   244,   360,   243,   118,   123,   125,   126,   292,
     294,   329,     6,   239,   247,     9,   238,   240,   244,   239,
     247,   247,   239,   247,     9,   238,   244,   241,   247,   275,
     241,   275,    86,   338,   335,   360,   247,   247,   239,   239,
     239,   329,   239,   239,   239,   329,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   243,     7,   329,
     228,   243,   247,   329,     6,   239,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   345,   329,   329,   329,   329,   329,   329,
     329,   345,   345,   360,   242,   329,   329,   350,   329,   350,
     343,   350,   350,   357,   242,   329,   273,   360,     8,   329,
     329,   344,   350,   350,   345,   336,   351,   336,   346,   239,
     243,   244,   272,    64,     8,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   242,
     329,   345,   329,   329,   329,   329,   329,   360,   329,   329,
       4,   337,   242,   273,   239,   243,   329,   329,   329,     7,
       7,   322,   322,   238,   329,   329,     6,   346,   346,   242,
     239,     6,   300,   242,   300,   300,   247,   247,   247,   340,
     340,   299,   299,   247,   329,   243,   313,   247,   300,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   239,     7,
     323,     6,     7,   329,     6,   329,   329,   243,   346,   346,
     346,   329,     6,   329,   329,   329,   239,   243,   239,   239,
     239,   173,   247,   300,   242,     8,   239,   239,   241,   357,
     350,   357,   350,   350,   350,   350,   350,   350,   329,   350,
     350,   350,   350,   245,   353,   360,   351,   350,   350,   350,
     336,   360,   346,   243,   243,   243,   243,   329,   329,   300,
     360,   337,   241,   243,   239,   131,   148,   317,   239,   243,
     247,   329,     6,   242,   242,   242,   242,   329,   239,   241,
       7,   270,   271,   244,     7,     6,   346,     7,   214,   270,
     255,   360,   329,   329,   337,   240,   238,   118,   294,   295,
     242,   243,     6,   221,   222,   252,   346,   360,   329,   329,
       4,   337,     6,   346,   329,     6,   350,   358,   360,   239,
     337,     6,   360,     6,   350,   329,   239,   240,   329,   351,
       7,     7,     7,   239,     7,     7,     7,   239,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   329,   239,
     242,   329,   345,   243,     6,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   247,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   247,   247,   247,   239,
     241,   241,   346,   247,   247,   273,   247,   273,   247,   247,
     247,   239,   329,   331,   273,   243,   243,   243,   247,   247,
     273,   273,   239,   244,   239,   244,   247,   272,   332,   243,
       7,   337,   273,   242,   243,     8,     8,   346,   244,   239,
     241,   271,   238,   240,   272,   346,     7,   242,   239,   239,
     239,   329,   343,     4,   321,     6,   289,   329,   351,   243,
     239,   243,   243,   346,   244,   243,   300,   243,   243,   340,
     329,   329,   243,   243,   329,   340,   128,   128,   145,   153,
     154,   155,   159,   160,   314,   315,   340,   243,   310,   239,
     243,   239,   239,   239,   239,   239,   239,   239,     7,   329,
       6,   329,   239,   241,   241,   243,   243,   243,   243,   241,
     241,   247,     7,     7,     7,   244,   329,   243,   329,   329,
       7,   244,   273,   247,   273,   273,   239,   239,   247,   273,
     273,   247,   247,   273,   273,   273,   273,   329,   273,     9,
     352,   247,   239,   247,   273,   244,   247,   333,   241,   243,
     243,   244,   238,   240,   246,   176,     7,   148,     6,   329,
     243,   242,     6,   343,   243,   329,   329,   329,   329,     6,
       7,   270,   271,   244,   270,   271,   351,   329,     6,     4,
     242,   348,   360,   243,    46,    46,   343,     4,   163,   164,
     165,   166,   243,   258,   262,   265,   267,   268,   244,   239,
     241,   238,   329,   329,   238,   242,   238,     8,   346,   350,
     239,   244,   239,   241,   238,   239,   247,   244,   238,     7,
     272,     4,   283,   284,   285,   273,   273,   340,   343,   343,
       7,   343,   343,   343,     7,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,     6,     7,   346,   329,   329,
     329,   329,   243,   329,   329,   329,   343,   350,   350,   243,
     247,   282,   329,   329,   337,   337,   329,   329,   239,   343,
     272,   329,   329,   329,   243,   337,   271,   244,   271,   329,
     329,   273,   243,   343,   346,     7,     7,     7,   128,   320,
       6,   239,   247,     7,     7,     7,   243,     4,   243,   247,
     247,   247,   243,   243,   108,     4,     6,   329,   242,     6,
     238,     6,   161,     6,   161,   243,   315,   247,   314,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   343,     6,
     242,     6,     6,     6,    96,     7,     6,     6,   329,   343,
     343,   343,     4,   247,     8,     8,   239,     4,    99,   100,
       4,   346,   350,   329,   350,   245,   247,   286,   350,   350,
     337,   350,   239,   247,   337,   242,   294,   242,     6,   329,
       6,   242,   343,   243,   243,   243,   243,   243,   329,     6,
       4,   173,   174,   329,     6,     6,     6,     7,   347,   349,
       6,   240,   273,   272,   272,     6,   259,   238,   238,   242,
     269,     6,   337,   244,   350,   329,   241,   239,   329,     8,
     346,   329,   243,   243,     6,     6,   252,   337,   244,   329,
       6,   329,   337,   239,   242,   329,   351,   273,    46,   242,
     343,   351,   354,   241,   247,     6,     6,     6,   122,   291,
     291,   343,     6,     6,     6,   343,   176,   290,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   243,   273,
     273,   273,   273,   273,   247,   247,   247,   239,   273,   273,
     284,   273,   239,   273,   239,   272,   332,   273,     6,   273,
     247,   238,   240,   272,     4,   239,   241,   273,     6,   243,
     343,   343,   343,     4,     6,   270,   329,   343,   242,   242,
       7,     6,     7,   329,   329,   329,   242,   242,   242,   240,
       6,   329,   343,   329,     6,     6,   329,   340,   243,     5,
     343,   242,   242,   242,   242,   242,   242,   242,   343,     6,
     346,   242,   329,   241,     6,     6,   172,   329,   329,   329,
       6,     6,     6,     6,     7,   273,   247,   247,   273,   247,
     329,     4,   188,   287,   288,   273,   239,   273,   333,   351,
     238,   240,   329,   242,   300,     6,   300,   247,     6,     6,
       7,   270,   271,   244,     7,     6,   347,   243,   247,   329,
     270,   242,   273,   355,   356,   357,   355,   238,   329,   329,
     342,   343,   242,   238,     4,     6,   239,     6,   239,   243,
     243,   239,     6,     6,   350,   238,     4,   239,   247,   238,
     343,   351,     7,   272,   281,   329,   345,   285,   340,     6,
       6,     6,     6,    94,     6,     5,   242,   329,   329,   329,
     329,   239,   332,   329,   329,   329,   273,   271,   242,     6,
     290,     6,   329,   343,     4,     6,   346,   346,   329,   329,
     351,   243,   239,   243,   247,   299,   299,   329,   329,   243,
     247,   239,   243,   247,     6,     6,   342,   340,   340,   340,
     340,   340,   227,   340,     6,   243,   329,     6,     6,   343,
     243,   247,     8,   243,   239,   242,   329,   351,   350,   329,
     350,   329,   351,   354,   356,   351,   247,   239,   247,   243,
     329,   317,   317,   343,   351,   329,     6,     4,   348,     6,
     347,   241,   343,   357,     6,   273,   273,   256,   329,   247,
     247,   243,   247,   257,   329,   329,     6,     6,     6,   329,
     329,   239,   277,   279,   242,   356,   243,   247,     7,     7,
     242,     5,   342,   273,   273,   247,   273,   239,   247,   239,
     241,   329,     6,     6,   242,   243,   243,   242,     6,     6,
     242,   329,   243,   243,   243,   241,     6,   343,     7,   242,
     329,   243,   247,   247,   247,   247,   247,   247,     6,   243,
     171,   329,   329,   346,     6,     6,   239,   273,   273,   288,
     351,   243,   243,   243,   243,     6,     6,     7,     6,   244,
       6,   243,     6,     6,   239,   247,   329,   329,   242,   343,
     243,   247,   239,   239,   247,   282,   286,   343,   273,   329,
     351,   360,   329,     6,   243,   329,   332,   329,   243,   342,
     132,   133,   138,   324,   132,   133,   324,   346,   299,   243,
     247,     6,   243,   343,   300,   243,     6,   346,   340,   340,
     340,   340,   340,   329,   243,   243,   243,   239,     6,   242,
       6,   347,   174,   260,   329,   247,   247,   342,     6,   329,
     329,   243,   243,   278,     7,   238,   243,   242,   247,   239,
     247,   243,   242,   340,   343,     6,   242,   340,     6,   243,
     243,   329,     6,   128,   243,   311,   242,   243,   247,   247,
     247,   247,   247,     6,     6,     6,   300,     6,   242,   329,
     329,   243,   247,   282,   351,   239,   329,   329,   329,     6,
     340,     6,   340,     6,     6,   243,   329,   314,   300,     6,
     346,   346,   346,   346,   340,   346,   317,   257,   239,   247,
       6,   242,   329,   243,   247,   247,   247,   247,   247,     6,
     243,   243,   312,   243,   243,   243,   243,   247,   243,   243,
     243,   263,   329,   342,   243,   329,   329,   329,   340,   340,
     314,     6,     6,     6,     6,   346,     6,     6,     6,   242,
     239,   243,     6,   243,   273,   247,   247,   247,   243,   243,
     261,   350,   266,   242,     6,   329,   329,   329,     6,   243,
     247,   242,   342,   243,   243,   243,     6,   350,   264,   350,
     243,     6,     6,   243,   247,     6,     6,   350
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
#line 1101 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1109 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 104:
#line 1116 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 105:
#line 1123 "Gmsh.y"
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
#line 1145 "Gmsh.y"
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
#line 1168 "Gmsh.y"
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
#line 1206 "Gmsh.y"
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
#line 1227 "Gmsh.y"
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
#line 1239 "Gmsh.y"
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
#line 1257 "Gmsh.y"
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
#line 1266 "Gmsh.y"
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
#line 1275 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1277 "Gmsh.y"
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
#line 1295 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1297 "Gmsh.y"
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
#line 1313 "Gmsh.y"
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
#line 1322 "Gmsh.y"
    { init_options(); ;}
    break;

  case 122:
#line 1324 "Gmsh.y"
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
#line 1338 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 125:
#line 1346 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 126:
#line 1352 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 127:
#line 1357 "Gmsh.y"
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
#line 1399 "Gmsh.y"
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
#line 1411 "Gmsh.y"
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
#line 1424 "Gmsh.y"
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
#line 1439 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 138:
#line 1448 "Gmsh.y"
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
#line 1473 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 144:
#line 1481 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 145:
#line 1490 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1498 "Gmsh.y"
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
#line 1512 "Gmsh.y"
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
#line 1530 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 149:
#line 1534 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 150:
#line 1541 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 151:
#line 1549 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 152:
#line 1553 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 153:
#line 1559 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 154:
#line 1563 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 155:
#line 1570 "Gmsh.y"
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

  case 156:
#line 1593 "Gmsh.y"
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

  case 157:
#line 1609 "Gmsh.y"
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

  case 158:
#line 1625 "Gmsh.y"
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

  case 159:
#line 1662 "Gmsh.y"
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

  case 160:
#line 1702 "Gmsh.y"
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

  case 161:
#line 1718 "Gmsh.y"
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

  case 162:
#line 1735 "Gmsh.y"
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

  case 163:
#line 1756 "Gmsh.y"
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

  case 164:
#line 1772 "Gmsh.y"
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

  case 165:
#line 1791 "Gmsh.y"
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

  case 166:
#line 1807 "Gmsh.y"
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

  case 167:
#line 1828 "Gmsh.y"
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

  case 168:
#line 1839 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 169:
#line 1845 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 170:
#line 1851 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 171:
#line 1858 "Gmsh.y"
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

  case 172:
#line 1889 "Gmsh.y"
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

  case 173:
#line 1904 "Gmsh.y"
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

  case 174:
#line 1926 "Gmsh.y"
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

  case 175:
#line 1949 "Gmsh.y"
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

  case 176:
#line 1972 "Gmsh.y"
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

  case 177:
#line 1995 "Gmsh.y"
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

  case 178:
#line 2019 "Gmsh.y"
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

  case 179:
#line 2043 "Gmsh.y"
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

  case 180:
#line 2067 "Gmsh.y"
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

  case 181:
#line 2093 "Gmsh.y"
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

  case 182:
#line 2110 "Gmsh.y"
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

  case 183:
#line 2126 "Gmsh.y"
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

  case 184:
#line 2144 "Gmsh.y"
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

  case 185:
#line 2162 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints instead");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2169 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints instead");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 2175 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 188:
#line 2179 "Gmsh.y"
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

  case 189:
#line 2205 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 190:
#line 2207 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 191:
#line 2209 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 192:
#line 2211 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 193:
#line 2213 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 194:
#line 2221 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 195:
#line 2223 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 196:
#line 2225 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 197:
#line 2227 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 198:
#line 2235 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 199:
#line 2237 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 200:
#line 2239 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 201:
#line 2247 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 202:
#line 2249 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 203:
#line 2251 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 204:
#line 2253 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 205:
#line 2263 "Gmsh.y"
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

  case 206:
#line 2279 "Gmsh.y"
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

  case 207:
#line 2295 "Gmsh.y"
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

  case 208:
#line 2311 "Gmsh.y"
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

  case 209:
#line 2327 "Gmsh.y"
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

  case 210:
#line 2343 "Gmsh.y"
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

  case 211:
#line 2380 "Gmsh.y"
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

  case 212:
#line 2402 "Gmsh.y"
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

  case 213:
#line 2425 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 214:
#line 2426 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 215:
#line 2431 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 216:
#line 2435 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 217:
#line 2439 "Gmsh.y"
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

  case 218:
#line 2455 "Gmsh.y"
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

  case 219:
#line 2473 "Gmsh.y"
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

  case 220:
#line 2491 "Gmsh.y"
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

  case 221:
#line 2516 "Gmsh.y"
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

  case 222:
#line 2535 "Gmsh.y"
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

  case 223:
#line 2557 "Gmsh.y"
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

  case 224:
#line 2572 "Gmsh.y"
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

  case 225:
#line 2587 "Gmsh.y"
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

  case 226:
#line 2606 "Gmsh.y"
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

  case 227:
#line 2657 "Gmsh.y"
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

  case 228:
#line 2678 "Gmsh.y"
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

  case 229:
#line 2700 "Gmsh.y"
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

  case 230:
#line 2722 "Gmsh.y"
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

  case 231:
#line 2827 "Gmsh.y"
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

  case 232:
#line 2843 "Gmsh.y"
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

  case 233:
#line 2878 "Gmsh.y"
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

  case 234:
#line 2900 "Gmsh.y"
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

  case 235:
#line 2922 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 236:
#line 2928 "Gmsh.y"
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

  case 237:
#line 2943 "Gmsh.y"
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

  case 238:
#line 2971 "Gmsh.y"
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

  case 239:
#line 2983 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 240:
#line 2992 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 241:
#line 2999 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 242:
#line 3011 "Gmsh.y"
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

  case 243:
#line 3030 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 244:
#line 3034 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 245:
#line 3039 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 246:
#line 3043 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 247:
#line 3048 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 248:
#line 3055 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 249:
#line 3062 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 250:
#line 3069 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 3081 "Gmsh.y"
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

  case 252:
#line 3154 "Gmsh.y"
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

  case 253:
#line 3172 "Gmsh.y"
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

  case 254:
#line 3189 "Gmsh.y"
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

  case 255:
#line 3204 "Gmsh.y"
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

  case 256:
#line 3237 "Gmsh.y"
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

  case 257:
#line 3249 "Gmsh.y"
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

  case 258:
#line 3273 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 259:
#line 3277 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 260:
#line 3282 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 261:
#line 3289 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 262:
#line 3294 "Gmsh.y"
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

  case 263:
#line 3304 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 264:
#line 3309 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 265:
#line 3315 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 266:
#line 3323 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 267:
#line 3327 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 268:
#line 3337 "Gmsh.y"
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

  case 269:
#line 3400 "Gmsh.y"
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

  case 270:
#line 3416 "Gmsh.y"
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

  case 271:
#line 3433 "Gmsh.y"
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

  case 272:
#line 3450 "Gmsh.y"
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

  case 273:
#line 3472 "Gmsh.y"
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

  case 274:
#line 3494 "Gmsh.y"
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

  case 275:
#line 3529 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 276:
#line 3537 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 277:
#line 3545 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 278:
#line 3551 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 279:
#line 3558 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 280:
#line 3565 "Gmsh.y"
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

  case 281:
#line 3585 "Gmsh.y"
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

  case 282:
#line 3611 "Gmsh.y"
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

  case 283:
#line 3623 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 284:
#line 3634 "Gmsh.y"
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

  case 285:
#line 3652 "Gmsh.y"
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

  case 286:
#line 3670 "Gmsh.y"
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

  case 287:
#line 3688 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 288:
#line 3694 "Gmsh.y"
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

  case 289:
#line 3712 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3718 "Gmsh.y"
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

  case 291:
#line 3738 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3744 "Gmsh.y"
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

  case 293:
#line 3762 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3768 "Gmsh.y"
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

  case 295:
#line 3785 "Gmsh.y"
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

  case 296:
#line 3801 "Gmsh.y"
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

  case 297:
#line 3818 "Gmsh.y"
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

  case 298:
#line 3835 "Gmsh.y"
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

  case 299:
#line 3858 "Gmsh.y"
    {
    ;}
    break;

  case 300:
#line 3861 "Gmsh.y"
    {
    ;}
    break;

  case 301:
#line 3867 "Gmsh.y"
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

  case 302:
#line 3879 "Gmsh.y"
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

  case 303:
#line 3899 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 304:
#line 3903 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 305:
#line 3907 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 306:
#line 3911 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 307:
#line 3915 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 308:
#line 3919 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 309:
#line 3923 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 310:
#line 3927 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 311:
#line 3936 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 312:
#line 3948 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 313:
#line 3949 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 314:
#line 3950 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 315:
#line 3951 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 316:
#line 3952 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 317:
#line 3956 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 318:
#line 3957 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 319:
#line 3958 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 320:
#line 3959 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 321:
#line 3960 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 322:
#line 3965 "Gmsh.y"
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

  case 323:
#line 3988 "Gmsh.y"
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

  case 324:
#line 4008 "Gmsh.y"
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

  case 325:
#line 4029 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 326:
#line 4033 "Gmsh.y"
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

  case 327:
#line 4048 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 328:
#line 4052 "Gmsh.y"
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

  case 329:
#line 4068 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 330:
#line 4072 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 331:
#line 4077 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 332:
#line 4081 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 333:
#line 4087 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 334:
#line 4091 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 335:
#line 4098 "Gmsh.y"
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

  case 336:
#line 4120 "Gmsh.y"
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

  case 337:
#line 4161 "Gmsh.y"
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

  case 338:
#line 4205 "Gmsh.y"
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

  case 339:
#line 4244 "Gmsh.y"
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

  case 340:
#line 4269 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 341:
#line 4278 "Gmsh.y"
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

  case 342:
#line 4308 "Gmsh.y"
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

  case 343:
#line 4334 "Gmsh.y"
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

  case 344:
#line 4361 "Gmsh.y"
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

  case 345:
#line 4393 "Gmsh.y"
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

  case 346:
#line 4420 "Gmsh.y"
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

  case 347:
#line 4446 "Gmsh.y"
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

  case 348:
#line 4472 "Gmsh.y"
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

  case 349:
#line 4498 "Gmsh.y"
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

  case 350:
#line 4524 "Gmsh.y"
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

  case 351:
#line 4545 "Gmsh.y"
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

  case 352:
#line 4556 "Gmsh.y"
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

  case 353:
#line 4604 "Gmsh.y"
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

  case 354:
#line 4653 "Gmsh.y"
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

  case 355:
#line 4665 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 356:
#line 4676 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 357:
#line 4683 "Gmsh.y"
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

  case 358:
#line 4698 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 359:
#line 4711 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 360:
#line 4712 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 361:
#line 4713 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 362:
#line 4718 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 363:
#line 4724 "Gmsh.y"
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

  case 364:
#line 4736 "Gmsh.y"
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

  case 365:
#line 4754 "Gmsh.y"
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

  case 366:
#line 4781 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 367:
#line 4782 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 368:
#line 4783 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 369:
#line 4784 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 370:
#line 4785 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 371:
#line 4786 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 372:
#line 4787 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 373:
#line 4788 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4790 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 375:
#line 4796 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 376:
#line 4797 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 377:
#line 4798 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 378:
#line 4799 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 379:
#line 4800 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 380:
#line 4801 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4802 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 382:
#line 4803 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 383:
#line 4804 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4805 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4806 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4807 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4808 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 388:
#line 4809 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 389:
#line 4810 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 390:
#line 4811 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 391:
#line 4812 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4813 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 393:
#line 4814 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 394:
#line 4815 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 395:
#line 4816 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 396:
#line 4817 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 397:
#line 4818 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 398:
#line 4819 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 399:
#line 4820 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 400:
#line 4821 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 401:
#line 4822 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 402:
#line 4823 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4824 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4825 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4826 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 406:
#line 4827 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 407:
#line 4828 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 4829 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 409:
#line 4830 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 410:
#line 4831 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 411:
#line 4832 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 412:
#line 4833 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 413:
#line 4842 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 414:
#line 4843 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 415:
#line 4844 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 416:
#line 4845 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 417:
#line 4846 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 418:
#line 4847 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 419:
#line 4848 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 420:
#line 4849 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 421:
#line 4850 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 422:
#line 4851 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 423:
#line 4852 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 424:
#line 4857 "Gmsh.y"
    { init_options(); ;}
    break;

  case 425:
#line 4859 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 426:
#line 4865 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 427:
#line 4867 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 428:
#line 4872 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 429:
#line 4877 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 430:
#line 4882 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 431:
#line 4887 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 432:
#line 4891 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 433:
#line 4895 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 434:
#line 4899 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 435:
#line 4903 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 436:
#line 4907 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 437:
#line 4911 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 438:
#line 4915 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 439:
#line 4921 "Gmsh.y"
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

  case 440:
#line 4937 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 441:
#line 4942 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 442:
#line 4948 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 443:
#line 4954 "Gmsh.y"
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

  case 444:
#line 4973 "Gmsh.y"
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

  case 445:
#line 4994 "Gmsh.y"
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

  case 446:
#line 5027 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 447:
#line 5031 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 448:
#line 5036 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 449:
#line 5040 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 450:
#line 5044 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 451:
#line 5048 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 452:
#line 5053 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 453:
#line 5058 "Gmsh.y"
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

  case 454:
#line 5068 "Gmsh.y"
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

  case 455:
#line 5078 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 456:
#line 5083 "Gmsh.y"
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

  case 457:
#line 5094 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 458:
#line 5103 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 459:
#line 5108 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 460:
#line 5113 "Gmsh.y"
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

  case 461:
#line 5140 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 462:
#line 5142 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 463:
#line 5147 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 464:
#line 5149 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 465:
#line 5154 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 466:
#line 5161 "Gmsh.y"
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

  case 467:
#line 5177 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 468:
#line 5179 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 469:
#line 5184 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 470:
#line 5193 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 471:
#line 5195 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 472:
#line 5200 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 473:
#line 5202 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 474:
#line 5207 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 475:
#line 5211 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 476:
#line 5215 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 477:
#line 5219 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 478:
#line 5223 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 479:
#line 5230 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 480:
#line 5234 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 481:
#line 5238 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 482:
#line 5242 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 483:
#line 5249 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 484:
#line 5254 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 485:
#line 5261 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 486:
#line 5266 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 487:
#line 5270 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 488:
#line 5275 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 489:
#line 5279 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 490:
#line 5287 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 491:
#line 5298 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 492:
#line 5302 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 493:
#line 5306 "Gmsh.y"
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

  case 494:
#line 5320 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 495:
#line 5328 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 496:
#line 5336 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 497:
#line 5343 "Gmsh.y"
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

  case 498:
#line 5353 "Gmsh.y"
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

  case 499:
#line 5376 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 500:
#line 5381 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 501:
#line 5387 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 502:
#line 5392 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 503:
#line 5398 "Gmsh.y"
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

  case 504:
#line 5410 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 505:
#line 5415 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 506:
#line 5420 "Gmsh.y"
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

  case 507:
#line 5430 "Gmsh.y"
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

  case 508:
#line 5440 "Gmsh.y"
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

  case 509:
#line 5450 "Gmsh.y"
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

  case 510:
#line 5462 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 511:
#line 5466 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 512:
#line 5471 "Gmsh.y"
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

  case 513:
#line 5483 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 514:
#line 5487 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 515:
#line 5491 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 516:
#line 5495 "Gmsh.y"
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

  case 517:
#line 5513 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 518:
#line 5521 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 519:
#line 5529 "Gmsh.y"
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

  case 520:
#line 5558 "Gmsh.y"
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

  case 521:
#line 5568 "Gmsh.y"
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

  case 522:
#line 5584 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 523:
#line 5595 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 524:
#line 5600 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 525:
#line 5604 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 526:
#line 5608 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 527:
#line 5620 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 528:
#line 5624 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 529:
#line 5636 "Gmsh.y"
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

  case 530:
#line 5653 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 531:
#line 5663 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 532:
#line 5667 "Gmsh.y"
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

  case 533:
#line 5682 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 534:
#line 5687 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 535:
#line 5694 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 536:
#line 5698 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 537:
#line 5703 "Gmsh.y"
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

  case 538:
#line 5717 "Gmsh.y"
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

  case 539:
#line 5733 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 540:
#line 5737 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 541:
#line 5741 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 542:
#line 5745 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 543:
#line 5749 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 544:
#line 5757 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 545:
#line 5763 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 546:
#line 5769 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 547:
#line 5775 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 548:
#line 5784 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 549:
#line 5788 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 550:
#line 5792 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 551:
#line 5800 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 552:
#line 5806 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 553:
#line 5812 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 554:
#line 5816 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 555:
#line 5824 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 556:
#line 5832 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 557:
#line 5839 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 558:
#line 5848 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 559:
#line 5852 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 560:
#line 5856 "Gmsh.y"
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

  case 561:
#line 5871 "Gmsh.y"
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

  case 562:
#line 5885 "Gmsh.y"
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

  case 563:
#line 5899 "Gmsh.y"
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

  case 564:
#line 5911 "Gmsh.y"
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

  case 565:
#line 5927 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 5936 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 567:
#line 5945 "Gmsh.y"
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

  case 568:
#line 5955 "Gmsh.y"
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

  case 569:
#line 5966 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 570:
#line 5974 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 571:
#line 5982 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 572:
#line 5986 "Gmsh.y"
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

  case 573:
#line 6005 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 574:
#line 6012 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 575:
#line 6018 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6025 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 577:
#line 6032 "Gmsh.y"
    { init_options(); ;}
    break;

  case 578:
#line 6034 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 579:
#line 6042 "Gmsh.y"
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

  case 580:
#line 6066 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 581:
#line 6068 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 582:
#line 6074 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 583:
#line 6079 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 584:
#line 6081 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 585:
#line 6086 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 586:
#line 6091 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 587:
#line 6096 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 588:
#line 6098 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 589:
#line 6102 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 590:
#line 6114 "Gmsh.y"
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

  case 591:
#line 6128 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 592:
#line 6132 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 593:
#line 6139 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 594:
#line 6147 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 595:
#line 6155 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 596:
#line 6166 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 597:
#line 6168 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 598:
#line 6171 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13649 "Gmsh.tab.cpp"
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


#line 6174 "Gmsh.y"


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

