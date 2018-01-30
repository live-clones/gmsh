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
     tPlane = 376,
     tRuled = 377,
     tTransfinite = 378,
     tPhysical = 379,
     tCompound = 380,
     tPeriodic = 381,
     tUsing = 382,
     tPlugin = 383,
     tDegenerated = 384,
     tRecursive = 385,
     tRotate = 386,
     tTranslate = 387,
     tSymmetry = 388,
     tDilate = 389,
     tExtrude = 390,
     tLevelset = 391,
     tAffine = 392,
     tBooleanUnion = 393,
     tBooleanIntersection = 394,
     tBooleanDifference = 395,
     tBooleanSection = 396,
     tBooleanFragments = 397,
     tThickSolid = 398,
     tRecombine = 399,
     tSmoother = 400,
     tSplit = 401,
     tDelete = 402,
     tCoherence = 403,
     tIntersect = 404,
     tMeshAlgorithm = 405,
     tReverse = 406,
     tLayers = 407,
     tScaleLast = 408,
     tHole = 409,
     tAlias = 410,
     tAliasWithOptions = 411,
     tCopyOptions = 412,
     tQuadTriAddVerts = 413,
     tQuadTriNoNewVerts = 414,
     tRecombLaterals = 415,
     tTransfQuadTri = 416,
     tText2D = 417,
     tText3D = 418,
     tInterpolationScheme = 419,
     tTime = 420,
     tCombine = 421,
     tBSpline = 422,
     tBezier = 423,
     tNurbs = 424,
     tNurbsOrder = 425,
     tNurbsKnots = 426,
     tColor = 427,
     tColorTable = 428,
     tFor = 429,
     tIn = 430,
     tEndFor = 431,
     tIf = 432,
     tElseIf = 433,
     tElse = 434,
     tEndIf = 435,
     tExit = 436,
     tAbort = 437,
     tField = 438,
     tReturn = 439,
     tCall = 440,
     tSlide = 441,
     tMacro = 442,
     tShow = 443,
     tHide = 444,
     tGetValue = 445,
     tGetStringValue = 446,
     tGetEnv = 447,
     tGetString = 448,
     tGetNumber = 449,
     tUnique = 450,
     tHomology = 451,
     tCohomology = 452,
     tBetti = 453,
     tExists = 454,
     tFileExists = 455,
     tGetForced = 456,
     tGetForcedStr = 457,
     tGMSH_MAJOR_VERSION = 458,
     tGMSH_MINOR_VERSION = 459,
     tGMSH_PATCH_VERSION = 460,
     tGmshExecutableName = 461,
     tSetPartition = 462,
     tNameToString = 463,
     tStringToName = 464,
     tAFFECTDIVIDE = 465,
     tAFFECTTIMES = 466,
     tAFFECTMINUS = 467,
     tAFFECTPLUS = 468,
     tOR = 469,
     tAND = 470,
     tNOTEQUAL = 471,
     tEQUAL = 472,
     tGREATERGREATER = 473,
     tLESSLESS = 474,
     tGREATEROREQUAL = 475,
     tLESSOREQUAL = 476,
     UNARYPREC = 477,
     tMINUSMINUS = 478,
     tPLUSPLUS = 479
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
#define tPlane 376
#define tRuled 377
#define tTransfinite 378
#define tPhysical 379
#define tCompound 380
#define tPeriodic 381
#define tUsing 382
#define tPlugin 383
#define tDegenerated 384
#define tRecursive 385
#define tRotate 386
#define tTranslate 387
#define tSymmetry 388
#define tDilate 389
#define tExtrude 390
#define tLevelset 391
#define tAffine 392
#define tBooleanUnion 393
#define tBooleanIntersection 394
#define tBooleanDifference 395
#define tBooleanSection 396
#define tBooleanFragments 397
#define tThickSolid 398
#define tRecombine 399
#define tSmoother 400
#define tSplit 401
#define tDelete 402
#define tCoherence 403
#define tIntersect 404
#define tMeshAlgorithm 405
#define tReverse 406
#define tLayers 407
#define tScaleLast 408
#define tHole 409
#define tAlias 410
#define tAliasWithOptions 411
#define tCopyOptions 412
#define tQuadTriAddVerts 413
#define tQuadTriNoNewVerts 414
#define tRecombLaterals 415
#define tTransfQuadTri 416
#define tText2D 417
#define tText3D 418
#define tInterpolationScheme 419
#define tTime 420
#define tCombine 421
#define tBSpline 422
#define tBezier 423
#define tNurbs 424
#define tNurbsOrder 425
#define tNurbsKnots 426
#define tColor 427
#define tColorTable 428
#define tFor 429
#define tIn 430
#define tEndFor 431
#define tIf 432
#define tElseIf 433
#define tElse 434
#define tEndIf 435
#define tExit 436
#define tAbort 437
#define tField 438
#define tReturn 439
#define tCall 440
#define tSlide 441
#define tMacro 442
#define tShow 443
#define tHide 444
#define tGetValue 445
#define tGetStringValue 446
#define tGetEnv 447
#define tGetString 448
#define tGetNumber 449
#define tUnique 450
#define tHomology 451
#define tCohomology 452
#define tBetti 453
#define tExists 454
#define tFileExists 455
#define tGetForced 456
#define tGetForcedStr 457
#define tGMSH_MAJOR_VERSION 458
#define tGMSH_MINOR_VERSION 459
#define tGMSH_PATCH_VERSION 460
#define tGmshExecutableName 461
#define tSetPartition 462
#define tNameToString 463
#define tStringToName 464
#define tAFFECTDIVIDE 465
#define tAFFECTTIMES 466
#define tAFFECTMINUS 467
#define tAFFECTPLUS 468
#define tOR 469
#define tAND 470
#define tNOTEQUAL 471
#define tEQUAL 472
#define tGREATERGREATER 473
#define tLESSLESS 474
#define tGREATEROREQUAL 475
#define tLESSOREQUAL 476
#define UNARYPREC 477
#define tMINUSMINUS 478
#define tPLUSPLUS 479




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
#line 727 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 740 "Gmsh.tab.cpp"

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
#define YYLAST   15683

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  247
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  600
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   479

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,     2,   244,     2,   229,   231,     2,
     237,   238,   227,   225,   246,   226,   243,   228,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     219,     2,   220,   214,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   239,     2,   240,   236,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   241,   230,   242,   245,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   215,
     216,   217,   218,   221,   222,   223,   224,   233,   234,   235
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
    1963,  1976,  1989,  2002,  2013,  2018,  2023,  2028,  2033,  2036,
    2040,  2047,  2049,  2051,  2053,  2056,  2062,  2070,  2081,  2083,
    2087,  2090,  2093,  2096,  2100,  2104,  2108,  2112,  2116,  2120,
    2124,  2128,  2132,  2136,  2140,  2144,  2148,  2152,  2156,  2160,
    2164,  2168,  2174,  2179,  2184,  2189,  2194,  2199,  2204,  2209,
    2214,  2219,  2224,  2231,  2236,  2241,  2246,  2251,  2256,  2261,
    2266,  2271,  2278,  2285,  2292,  2297,  2299,  2301,  2303,  2305,
    2307,  2309,  2311,  2313,  2315,  2317,  2319,  2320,  2327,  2329,
    2334,  2341,  2343,  2348,  2353,  2358,  2365,  2371,  2379,  2388,
    2399,  2404,  2409,  2416,  2421,  2425,  2428,  2434,  2440,  2444,
    2450,  2457,  2466,  2473,  2482,  2489,  2494,  2502,  2509,  2516,
    2523,  2528,  2535,  2540,  2541,  2544,  2545,  2548,  2549,  2557,
    2559,  2563,  2565,  2567,  2570,  2571,  2575,  2577,  2580,  2583,
    2587,  2591,  2603,  2613,  2621,  2629,  2631,  2635,  2637,  2639,
    2642,  2646,  2651,  2657,  2659,  2663,  2665,  2668,  2672,  2676,
    2682,  2687,  2692,  2695,  2700,  2703,  2707,  2724,  2730,  2732,
    2734,  2736,  2740,  2746,  2754,  2759,  2764,  2769,  2776,  2783,
    2792,  2801,  2806,  2821,  2826,  2831,  2833,  2835,  2839,  2843,
    2853,  2861,  2863,  2869,  2873,  2880,  2882,  2886,  2888,  2890,
    2895,  2900,  2904,  2910,  2917,  2926,  2933,  2939,  2945,  2951,
    2957,  2959,  2964,  2966,  2968,  2970,  2972,  2977,  2984,  2989,
    2996,  3002,  3010,  3015,  3020,  3025,  3034,  3039,  3044,  3049,
    3054,  3063,  3072,  3079,  3084,  3091,  3096,  3098,  3103,  3108,
    3109,  3116,  3121,  3124,  3129,  3134,  3136,  3138,  3142,  3144,
    3146,  3150,  3154,  3158,  3164,  3172,  3178,  3184,  3193,  3195,
    3197
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     248,     0,    -1,   249,    -1,     1,     6,    -1,    -1,   249,
     250,    -1,   252,    -1,   253,    -1,   273,    -1,   117,   237,
     349,   238,     6,    -1,   291,    -1,   297,    -1,   301,    -1,
     302,    -1,   303,    -1,   304,    -1,   308,    -1,   317,    -1,
     318,    -1,   324,    -1,   325,    -1,   307,    -1,   306,    -1,
     305,    -1,   300,    -1,   327,    -1,   220,    -1,   221,    -1,
      44,   237,   349,   238,     6,    -1,    45,   237,   349,   238,
       6,    -1,    44,   237,   349,   238,   251,   349,     6,    -1,
      44,   237,   349,   246,   345,   238,     6,    -1,    45,   237,
     349,   246,   345,   238,     6,    -1,    44,   237,   349,   246,
     345,   238,   251,   349,     6,    -1,   359,   349,   241,   254,
     242,     6,    -1,   155,     4,   239,   328,   240,     6,    -1,
     156,     4,   239,   328,   240,     6,    -1,   157,     4,   239,
     328,   246,   328,   240,     6,    -1,    -1,   254,   257,    -1,
     254,   261,    -1,   254,   264,    -1,   254,   266,    -1,   254,
     267,    -1,   328,    -1,   255,   246,   328,    -1,   328,    -1,
     256,   246,   328,    -1,    -1,    -1,     4,   258,   237,   255,
     238,   259,   241,   256,   242,     6,    -1,   349,    -1,   260,
     246,   349,    -1,    -1,   162,   237,   328,   246,   328,   246,
     328,   238,   262,   241,   260,   242,     6,    -1,   349,    -1,
     263,   246,   349,    -1,    -1,   163,   237,   328,   246,   328,
     246,   328,   246,   328,   238,   265,   241,   263,   242,     6,
      -1,   164,   241,   341,   242,   241,   341,   242,     6,    -1,
     164,   241,   341,   242,   241,   341,   242,   241,   341,   242,
     241,   341,   242,     6,    -1,    -1,   165,   268,   241,   256,
     242,     6,    -1,     7,    -1,   213,    -1,   212,    -1,   211,
      -1,   210,    -1,   235,    -1,   234,    -1,   237,    -1,   239,
      -1,   238,    -1,   240,    -1,    80,   239,   275,   240,     6,
      -1,    81,   239,   279,   240,     6,    -1,   333,     6,    -1,
      88,   271,   350,   246,   328,   272,     6,    -1,    89,   271,
     359,   246,   350,   272,     6,    -1,   359,   269,   342,     6,
      -1,   359,   270,     6,    -1,   359,   271,   272,   269,   342,
       6,    -1,   359,   271,   241,   345,   242,   272,   269,   342,
       6,    -1,   359,   239,   328,   240,   269,   328,     6,    -1,
     359,   239,   328,   240,   270,     6,    -1,   359,   237,   328,
     238,   269,   328,     6,    -1,   359,   237,   328,   238,   270,
       6,    -1,   359,     7,   350,     6,    -1,   359,   271,   272,
       7,    46,   271,   272,     6,    -1,   359,   271,   272,     7,
      46,   271,   354,   272,     6,    -1,   359,   271,   272,   213,
      46,   271,   354,   272,     6,    -1,   359,   243,     4,     7,
     350,     6,    -1,   359,   239,   328,   240,   243,     4,     7,
     350,     6,    -1,   359,   243,     4,   269,   328,     6,    -1,
     359,   239,   328,   240,   243,     4,   269,   328,     6,    -1,
     359,   243,     4,   270,     6,    -1,   359,   239,   328,   240,
     243,     4,   270,     6,    -1,   359,   243,   172,   243,     4,
       7,   346,     6,    -1,   359,   239,   328,   240,   243,   172,
     243,     4,     7,   346,     6,    -1,   359,   243,   173,     7,
     347,     6,    -1,   359,   239,   328,   240,   243,   173,     7,
     347,     6,    -1,   359,   183,     7,   328,     6,    -1,   183,
     239,   328,   240,     7,     4,     6,    -1,   183,   239,   328,
     240,     7,    99,     6,    -1,   183,   239,   328,   240,     7,
     100,     6,    -1,   183,   239,   328,   240,   243,     4,     7,
     328,     6,    -1,   183,   239,   328,   240,   243,     4,     7,
     350,     6,    -1,   183,   239,   328,   240,   243,     4,     7,
     241,   345,   242,     6,    -1,   183,   239,   328,   240,   243,
       4,     6,    -1,   128,   237,     4,   238,   243,     4,     7,
     328,     6,    -1,   128,   237,     4,   238,   243,     4,     7,
     350,     6,    -1,    -1,   246,    -1,    -1,   275,   274,   359,
      -1,   275,   274,   359,     7,   328,    -1,    -1,   275,   274,
     359,     7,   241,   342,   276,   281,   242,    -1,    -1,   275,
     274,   359,   271,   272,     7,   241,   342,   277,   281,   242,
      -1,   275,   274,   359,     7,   350,    -1,    -1,   275,   274,
     359,     7,   241,   350,   278,   285,   242,    -1,    -1,   279,
     274,   349,    -1,   328,     7,   350,    -1,   280,   246,   328,
       7,   350,    -1,   344,     7,   359,   237,   238,    -1,    -1,
     246,   283,    -1,    -1,   283,    -1,   284,    -1,   283,   246,
     284,    -1,     4,   342,    -1,     4,    -1,     4,   241,   280,
     242,    -1,     4,   350,    -1,     4,   353,    -1,    -1,   246,
     286,    -1,   287,    -1,   286,   246,   287,    -1,     4,   328,
      -1,     4,   350,    -1,   187,   350,    -1,     4,   355,    -1,
       4,   353,    -1,   328,    -1,   350,    -1,   350,   246,   328,
      -1,    -1,   175,    94,   241,   328,   242,    -1,   127,    90,
     241,   345,   242,    -1,   127,   109,   241,   345,   242,    -1,
      -1,   121,   339,    -1,    90,   237,   328,   238,     7,   339,
       6,    -1,    93,   237,   328,   238,     7,   342,     6,    -1,
      97,   237,   328,   238,     7,   342,     6,    -1,    91,   237,
     328,   238,     7,   342,   290,     6,    -1,    92,   237,   328,
     238,     7,   342,   290,     6,    -1,   167,   237,   328,   238,
       7,   342,     6,    -1,   168,   237,   328,   238,     7,   342,
       6,    -1,   169,   237,   328,   238,     7,   342,   171,   342,
     170,   328,     6,    -1,   108,   237,   328,   238,     7,   342,
       6,    -1,    93,     4,   237,   328,   238,     7,   342,     6,
      -1,   121,    96,   237,   328,   238,     7,   342,     6,    -1,
      96,   237,   328,   238,     7,   342,   289,     6,    -1,   122,
      96,   237,   328,   238,     7,   342,   289,     6,    -1,    13,
      14,     6,    -1,    14,    96,   328,     6,    -1,   112,    96,
     237,   328,   238,     7,     5,     5,     5,     6,    -1,    94,
     237,   328,   238,     7,   342,     6,    -1,    95,   237,   328,
     238,     7,   342,     6,    -1,    99,   237,   328,   238,     7,
     342,     6,    -1,   102,   237,   328,   238,     7,   342,     6,
      -1,   106,   237,   328,   238,     7,   342,     6,    -1,   107,
     237,   328,   238,     7,   342,     6,    -1,   100,   237,   328,
     238,     7,   342,     6,    -1,   101,   237,   328,   238,     7,
     342,     6,    -1,   119,   237,   328,   238,     7,   342,     6,
      -1,   143,   237,   328,   238,     7,   342,     6,    -1,    96,
       4,   237,   328,   238,     7,   342,     6,    -1,    98,   237,
     328,   238,     7,   342,     6,    -1,   118,   237,   328,   238,
       7,   342,     6,    -1,   122,   118,   237,   328,   238,     7,
     342,     6,    -1,   125,   294,   237,   328,   238,     7,   342,
       6,    -1,   125,   294,   237,   328,   238,     7,   342,     4,
     241,   341,   242,     6,    -1,    -1,   124,   293,   292,   237,
     288,   238,   269,   342,     6,    -1,    90,    -1,    93,    -1,
      96,    -1,    98,    -1,   109,   241,   328,   242,    -1,    93,
      -1,    96,    -1,    98,    -1,   109,   241,   328,   242,    -1,
      93,    -1,    96,    -1,   109,   241,   328,   242,    -1,    90,
      -1,    93,    -1,    96,    -1,   109,   241,   328,   242,    -1,
     132,   339,   241,   298,   242,    -1,   131,   241,   339,   246,
     339,   246,   328,   242,   241,   298,   242,    -1,   133,   339,
     241,   298,   242,    -1,   134,   241,   339,   246,   328,   242,
     241,   298,   242,    -1,   134,   241,   339,   246,   339,   242,
     241,   298,   242,    -1,     4,   241,   298,   242,    -1,   149,
      93,   241,   345,   242,    96,   241,   328,   242,    -1,   146,
      93,   237,   328,   238,   241,   345,   242,     6,    -1,   299,
      -1,   297,    -1,    -1,   299,   291,    -1,   299,   293,   241,
     345,   242,     6,    -1,   299,   124,   293,   241,   345,   242,
       6,    -1,   299,   293,   241,     8,   242,     6,    -1,   299,
     124,   293,   241,     8,   242,     6,    -1,   136,   121,   237,
     328,   238,     7,   342,     6,    -1,   136,    90,   237,   328,
     238,     7,   241,   341,   242,     6,    -1,   136,   121,   237,
     328,   238,     7,   241,   339,   246,   339,   246,   345,   242,
       6,    -1,   136,   121,   237,   328,   238,     7,   241,   339,
     246,   339,   246,   339,   246,   345,   242,     6,    -1,   136,
      94,   237,   328,   238,     7,   241,   339,   246,   345,   242,
       6,    -1,   136,   100,   237,   328,   238,     7,   241,   339,
     246,   339,   246,   345,   242,     6,    -1,   136,   101,   237,
     328,   238,     7,   241,   339,   246,   339,   246,   345,   242,
       6,    -1,   136,   103,   237,   328,   238,     7,   241,   339,
     246,   339,   246,   345,   242,     6,    -1,   136,   104,   237,
     328,   238,     7,   241,   339,   246,   339,   246,   345,   242,
       6,    -1,   136,     4,   237,   328,   238,     7,   342,     6,
      -1,   136,     4,   237,   328,   238,     7,     5,     6,    -1,
     136,     4,   241,   328,   242,     6,    -1,   147,   241,   299,
     242,    -1,   130,   147,   241,   299,   242,    -1,   147,   183,
     239,   328,   240,     6,    -1,   147,     4,   239,   328,   240,
       6,    -1,   147,   359,     6,    -1,   147,     4,     4,     6,
      -1,   147,    83,     6,    -1,   172,   346,   241,   299,   242,
      -1,   130,   172,   346,   241,   299,   242,    -1,   207,   328,
     241,   299,   242,    -1,   188,   241,     8,   242,    -1,   188,
       5,     6,    -1,   189,   241,     8,   242,    -1,   189,     5,
       6,    -1,   188,   241,   299,   242,    -1,   130,   188,   241,
     299,   242,    -1,   189,   241,   299,   242,    -1,   130,   189,
     241,   299,   242,    -1,   359,   350,     6,    -1,    73,   237,
     356,   238,     6,    -1,   359,   359,   239,   328,   240,   349,
       6,    -1,   359,   359,   359,   239,   328,   240,     6,    -1,
     359,   328,     6,    -1,   128,   237,     4,   238,   243,     4,
       6,    -1,   166,     4,     6,    -1,   181,     6,    -1,   182,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   241,   328,   246,   328,   246,   328,   246,   328,
     246,   328,   246,   328,   242,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    78,     6,    -1,   114,     6,    -1,   115,
     241,   345,   242,   241,   345,   242,   241,   341,   242,   241,
     328,   246,   328,   242,     6,    -1,   186,   237,   241,   345,
     242,   246,   350,   246,   350,   238,     6,    -1,   174,   237,
     328,     8,   328,   238,    -1,   174,   237,   328,     8,   328,
       8,   328,   238,    -1,   174,     4,   175,   241,   328,     8,
     328,   242,    -1,   174,     4,   175,   241,   328,     8,   328,
       8,   328,   242,    -1,   176,    -1,   187,     4,    -1,   187,
     350,    -1,   184,    -1,   185,   359,     6,    -1,   185,   350,
       6,    -1,   177,   237,   328,   238,    -1,   178,   237,   328,
     238,    -1,   179,    -1,   180,    -1,   135,   339,   241,   299,
     242,    -1,   135,   241,   339,   246,   339,   246,   328,   242,
     241,   299,   242,    -1,   135,   241,   339,   246,   339,   246,
     339,   246,   328,   242,   241,   299,   242,    -1,    -1,   135,
     339,   241,   299,   309,   313,   242,    -1,    -1,   135,   241,
     339,   246,   339,   246,   328,   242,   241,   299,   310,   313,
     242,    -1,    -1,   135,   241,   339,   246,   339,   246,   339,
     246,   328,   242,   241,   299,   311,   313,   242,    -1,    -1,
     135,   241,   299,   312,   313,   242,    -1,   135,   241,   299,
     242,   127,   108,   241,   328,   242,    -1,   118,   342,    -1,
     122,   118,   342,    -1,   120,   241,   345,   242,   241,   345,
     242,   241,   328,   242,    -1,   314,    -1,   313,   314,    -1,
     152,   241,   328,   242,     6,    -1,   152,   241,   342,   246,
     342,   242,     6,    -1,   153,     6,    -1,   144,     6,    -1,
     144,   328,     6,    -1,   158,     6,    -1,   158,   160,     6,
      -1,   159,     6,    -1,   159,   160,     6,    -1,   154,   237,
     328,   238,     7,   342,   127,   328,     6,    -1,   127,     4,
     239,   328,   240,     6,    -1,   138,    -1,   139,    -1,   140,
      -1,   141,    -1,   142,    -1,    -1,   147,     6,    -1,   130,
     147,     6,    -1,   147,   328,     6,    -1,   130,   147,   328,
       6,    -1,   315,   241,   299,   316,   242,   241,   299,   316,
     242,    -1,   105,   237,   349,   238,    -1,   315,   237,   328,
     238,     7,   241,   299,   316,   242,   241,   299,   316,   242,
       6,    -1,    -1,   127,     4,   328,    -1,    -1,     4,    -1,
      -1,     7,   342,    -1,    -1,     7,   328,    -1,    -1,   137,
     342,    -1,   110,   111,   343,     7,   328,     6,    -1,   123,
      93,   343,     7,   328,   319,     6,    -1,   123,    96,   343,
     321,   320,     6,    -1,   123,    98,   343,   321,     6,    -1,
     161,   343,     6,    -1,   150,    96,   241,   345,   242,     7,
     328,     6,    -1,   144,    96,   343,   322,     6,    -1,   144,
      98,   343,     6,    -1,   145,    96,   343,     7,   328,     6,
      -1,   126,    93,   241,   345,   242,     7,   241,   345,   242,
     323,     6,    -1,   126,    96,   241,   345,   242,     7,   241,
     345,   242,   323,     6,    -1,   126,    93,   241,   345,   242,
       7,   241,   345,   242,   131,   241,   339,   246,   339,   246,
     328,   242,     6,    -1,   126,    96,   241,   345,   242,     7,
     241,   345,   242,   131,   241,   339,   246,   339,   246,   328,
     242,     6,    -1,   126,    93,   241,   345,   242,     7,   241,
     345,   242,   132,   339,     6,    -1,   126,    96,   241,   345,
     242,     7,   241,   345,   242,   132,   339,     6,    -1,   126,
      96,   328,   241,   345,   242,     7,   328,   241,   345,   242,
       6,    -1,   293,   241,   345,   242,   175,   293,   241,   328,
     242,     6,    -1,   151,   295,   343,     6,    -1,   116,   296,
     343,     6,    -1,   129,    93,   342,     6,    -1,   125,   294,
     342,     6,    -1,   148,     6,    -1,   148,     4,     6,    -1,
     148,    90,   241,   345,   242,     6,    -1,   196,    -1,   197,
      -1,   198,    -1,   326,     6,    -1,   326,   241,   342,   242,
       6,    -1,   326,   241,   342,   246,   342,   242,     6,    -1,
     326,   237,   342,   238,   241,   342,   246,   342,   242,     6,
      -1,   329,    -1,   237,   328,   238,    -1,   226,   328,    -1,
     225,   328,    -1,   232,   328,    -1,   328,   226,   328,    -1,
     328,   225,   328,    -1,   328,   227,   328,    -1,   328,   228,
     328,    -1,   328,   230,   328,    -1,   328,   231,   328,    -1,
     328,   229,   328,    -1,   328,   236,   328,    -1,   328,   219,
     328,    -1,   328,   220,   328,    -1,   328,   224,   328,    -1,
     328,   223,   328,    -1,   328,   218,   328,    -1,   328,   217,
     328,    -1,   328,   216,   328,    -1,   328,   215,   328,    -1,
     328,   221,   328,    -1,   328,   222,   328,    -1,   328,   214,
     328,     8,   328,    -1,    16,   271,   328,   272,    -1,    17,
     271,   328,   272,    -1,    18,   271,   328,   272,    -1,    19,
     271,   328,   272,    -1,    20,   271,   328,   272,    -1,    21,
     271,   328,   272,    -1,    22,   271,   328,   272,    -1,    23,
     271,   328,   272,    -1,    24,   271,   328,   272,    -1,    26,
     271,   328,   272,    -1,    27,   271,   328,   246,   328,   272,
      -1,    28,   271,   328,   272,    -1,    29,   271,   328,   272,
      -1,    30,   271,   328,   272,    -1,    31,   271,   328,   272,
      -1,    32,   271,   328,   272,    -1,    33,   271,   328,   272,
      -1,    34,   271,   328,   272,    -1,    35,   271,   328,   272,
      -1,    36,   271,   328,   246,   328,   272,    -1,    37,   271,
     328,   246,   328,   272,    -1,    38,   271,   328,   246,   328,
     272,    -1,    25,   271,   328,   272,    -1,     3,    -1,    10,
      -1,    15,    -1,    11,    -1,    12,    -1,   203,    -1,   204,
      -1,   205,    -1,    75,    -1,    76,    -1,    77,    -1,    -1,
      82,   271,   328,   330,   281,   272,    -1,   333,    -1,   194,
     271,   349,   272,    -1,   194,   271,   349,   246,   328,   272,
      -1,   335,    -1,   359,   239,   328,   240,    -1,   359,   237,
     328,   238,    -1,   199,   237,   335,   238,    -1,   199,   237,
     335,   243,   336,   238,    -1,   201,   237,   335,   331,   238,
      -1,   201,   237,   335,   243,   336,   331,   238,    -1,   201,
     237,   335,   271,   328,   272,   331,   238,    -1,   201,   237,
     335,   243,   336,   271,   328,   272,   331,   238,    -1,   200,
     237,   350,   238,    -1,   244,   359,   271,   272,    -1,   244,
     335,   243,   336,   271,   272,    -1,    85,   271,   359,   272,
      -1,    85,   271,   272,    -1,   359,   270,    -1,   359,   239,
     328,   240,   270,    -1,   359,   237,   328,   238,   270,    -1,
     359,   243,   336,    -1,   359,     9,   359,   243,   336,    -1,
     359,   243,   336,   237,   328,   238,    -1,   359,     9,   359,
     243,   336,   237,   328,   238,    -1,   359,   243,   336,   239,
     328,   240,    -1,   359,     9,   359,   243,   336,   239,   328,
     240,    -1,   359,   239,   328,   240,   243,     4,    -1,   359,
     243,     4,   270,    -1,   359,   239,   328,   240,   243,     4,
     270,    -1,   190,   237,   349,   246,   328,   238,    -1,    56,
     237,   342,   246,   342,   238,    -1,    57,   271,   349,   246,
     349,   272,    -1,    55,   271,   349,   272,    -1,    58,   271,
     349,   246,   349,   272,    -1,    63,   237,   356,   238,    -1,
      -1,   246,   328,    -1,    -1,   246,   349,    -1,    -1,    83,
     335,   338,   334,   239,   282,   240,    -1,   359,    -1,   359,
       9,   359,    -1,     4,    -1,    86,    -1,    86,   328,    -1,
      -1,   237,   337,   238,    -1,   340,    -1,   226,   339,    -1,
     225,   339,    -1,   339,   226,   339,    -1,   339,   225,   339,
      -1,   241,   328,   246,   328,   246,   328,   246,   328,   246,
     328,   242,    -1,   241,   328,   246,   328,   246,   328,   246,
     328,   242,    -1,   241,   328,   246,   328,   246,   328,   242,
      -1,   237,   328,   246,   328,   246,   328,   238,    -1,   342,
      -1,   341,   246,   342,    -1,   328,    -1,   344,    -1,   241,
     242,    -1,   241,   345,   242,    -1,   226,   241,   345,   242,
      -1,   328,   227,   241,   345,   242,    -1,   342,    -1,   241,
       8,   242,    -1,     5,    -1,   226,   344,    -1,   328,   227,
     344,    -1,   328,     8,   328,    -1,   328,     8,   328,     8,
     328,    -1,    90,   241,   328,   242,    -1,    90,   241,     8,
     242,    -1,    90,     5,    -1,   294,   241,     8,   242,    -1,
     294,     5,    -1,   124,   293,   343,    -1,   293,   175,    64,
     241,   328,   246,   328,   246,   328,   246,   328,   246,   328,
     246,   328,   242,    -1,    64,   293,   241,   328,   242,    -1,
     297,    -1,   308,    -1,   317,    -1,   359,   271,   272,    -1,
     359,   243,   336,   271,   272,    -1,   359,     9,   359,   243,
     336,   271,   272,    -1,    39,   239,   359,   240,    -1,    39,
     239,   344,   240,    -1,    39,   237,   344,   238,    -1,    39,
     271,   241,   345,   242,   272,    -1,   359,   271,   241,   345,
     242,   272,    -1,    40,   271,   328,   246,   328,   246,   328,
     272,    -1,    41,   271,   328,   246,   328,   246,   328,   272,
      -1,    42,   271,   349,   272,    -1,    43,   271,   328,   246,
     328,   246,   328,   246,   328,   246,   328,   246,   328,   272,
      -1,   195,   271,   344,   272,    -1,    32,   271,   344,   272,
      -1,   328,    -1,   344,    -1,   345,   246,   328,    -1,   345,
     246,   344,    -1,   241,   328,   246,   328,   246,   328,   246,
     328,   242,    -1,   241,   328,   246,   328,   246,   328,   242,
      -1,   359,    -1,     4,   243,   172,   243,     4,    -1,   241,
     348,   242,    -1,   359,   239,   328,   240,   243,   173,    -1,
     346,    -1,   348,   246,   346,    -1,   350,    -1,   359,    -1,
     359,   239,   328,   240,    -1,   359,   237,   328,   238,    -1,
     359,   243,   336,    -1,   359,     9,   359,   243,   336,    -1,
     359,   243,   336,   237,   328,   238,    -1,   359,     9,   359,
     243,   336,   237,   328,   238,    -1,   359,   239,   328,   240,
     243,     4,    -1,   124,    90,   241,   328,   242,    -1,   124,
      93,   241,   328,   242,    -1,   124,    96,   241,   328,   242,
      -1,   124,    98,   241,   328,   242,    -1,     5,    -1,   208,
     239,   359,   240,    -1,    67,    -1,   206,    -1,    72,    -1,
      74,    -1,   192,   237,   349,   238,    -1,   191,   237,   349,
     246,   349,   238,    -1,   193,   271,   349,   272,    -1,   193,
     271,   349,   246,   349,   272,    -1,   202,   237,   335,   332,
     238,    -1,   202,   237,   335,   243,   336,   332,   238,    -1,
      48,   271,   356,   272,    -1,    49,   237,   349,   238,    -1,
      50,   237,   349,   238,    -1,    51,   237,   349,   246,   349,
     246,   349,   238,    -1,    46,   271,   356,   272,    -1,    60,
     271,   349,   272,    -1,    61,   271,   349,   272,    -1,    62,
     271,   349,   272,    -1,    59,   271,   328,   246,   349,   246,
     349,   272,    -1,    54,   271,   349,   246,   328,   246,   328,
     272,    -1,    54,   271,   349,   246,   328,   272,    -1,    47,
     271,   349,   272,    -1,    47,   271,   349,   246,   345,   272,
      -1,    68,   271,   349,   272,    -1,    69,    -1,    53,   271,
     349,   272,    -1,    52,   271,   349,   272,    -1,    -1,    87,
     271,   350,   351,   285,   272,    -1,    84,   271,   352,   272,
      -1,   244,   328,    -1,   359,     9,   244,   328,    -1,    46,
     271,   355,   272,    -1,   356,    -1,   355,    -1,   241,   356,
     242,    -1,   349,    -1,   357,    -1,   356,   246,   349,    -1,
     356,   246,   357,    -1,   359,   237,   238,    -1,   359,   243,
     336,   237,   238,    -1,   359,     9,   359,   243,   336,   237,
     238,    -1,     4,   245,   241,   328,   242,    -1,   358,   245,
     241,   328,   242,    -1,   209,   239,   349,   240,   245,   241,
     328,   242,    -1,     4,    -1,   358,    -1,   209,   239,   349,
     240,    -1
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
    1540,  1549,  1552,  1558,  1562,  1574,  1577,  1584,  1607,  1623,
    1639,  1676,  1716,  1732,  1748,  1780,  1796,  1815,  1831,  1880,
    1897,  1903,  1909,  1916,  1947,  1962,  1984,  2007,  2030,  2053,
    2077,  2101,  2125,  2151,  2168,  2184,  2202,  2220,  2227,  2236,
    2235,  2265,  2267,  2269,  2271,  2273,  2281,  2283,  2285,  2287,
    2295,  2297,  2299,  2307,  2309,  2311,  2313,  2323,  2339,  2355,
    2371,  2387,  2403,  2440,  2462,  2486,  2487,  2492,  2495,  2499,
    2515,  2533,  2551,  2576,  2595,  2616,  2631,  2647,  2665,  2716,
    2737,  2759,  2782,  2887,  2903,  2938,  2960,  2982,  2988,  3003,
    3031,  3043,  3052,  3059,  3071,  3090,  3094,  3099,  3103,  3108,
    3115,  3122,  3129,  3141,  3214,  3232,  3249,  3264,  3297,  3309,
    3333,  3337,  3342,  3349,  3354,  3364,  3369,  3375,  3383,  3387,
    3396,  3460,  3476,  3493,  3510,  3532,  3554,  3589,  3597,  3605,
    3611,  3618,  3625,  3645,  3671,  3683,  3694,  3712,  3730,  3749,
    3748,  3773,  3772,  3799,  3798,  3823,  3822,  3845,  3861,  3878,
    3895,  3918,  3921,  3927,  3939,  3959,  3963,  3967,  3971,  3975,
    3979,  3983,  3987,  3996,  4009,  4010,  4011,  4012,  4013,  4017,
    4018,  4019,  4020,  4021,  4024,  4048,  4067,  4090,  4093,  4109,
    4112,  4129,  4132,  4138,  4141,  4148,  4151,  4158,  4180,  4221,
    4265,  4304,  4329,  4338,  4368,  4394,  4420,  4452,  4479,  4505,
    4531,  4557,  4583,  4605,  4616,  4664,  4713,  4725,  4736,  4743,
    4758,  4772,  4773,  4774,  4778,  4784,  4796,  4814,  4842,  4843,
    4844,  4845,  4846,  4847,  4848,  4849,  4850,  4857,  4858,  4859,
    4860,  4861,  4862,  4863,  4864,  4865,  4866,  4867,  4868,  4869,
    4870,  4871,  4872,  4873,  4874,  4875,  4876,  4877,  4878,  4879,
    4880,  4881,  4882,  4883,  4884,  4885,  4886,  4887,  4888,  4889,
    4890,  4891,  4892,  4893,  4894,  4903,  4904,  4905,  4906,  4907,
    4908,  4909,  4910,  4911,  4912,  4913,  4918,  4917,  4925,  4927,
    4932,  4937,  4941,  4946,  4951,  4955,  4959,  4963,  4967,  4971,
    4975,  4981,  4997,  5002,  5008,  5014,  5033,  5054,  5087,  5091,
    5096,  5100,  5104,  5108,  5113,  5118,  5128,  5138,  5143,  5154,
    5163,  5168,  5173,  5201,  5202,  5208,  5209,  5215,  5214,  5237,
    5239,  5244,  5253,  5255,  5261,  5262,  5267,  5271,  5275,  5279,
    5283,  5290,  5294,  5298,  5302,  5309,  5314,  5321,  5326,  5330,
    5335,  5339,  5347,  5358,  5362,  5366,  5380,  5388,  5396,  5403,
    5413,  5436,  5441,  5447,  5452,  5458,  5469,  5475,  5480,  5490,
    5500,  5510,  5522,  5526,  5531,  5543,  5547,  5551,  5555,  5573,
    5581,  5589,  5618,  5628,  5644,  5655,  5660,  5664,  5668,  5680,
    5684,  5696,  5713,  5723,  5727,  5742,  5747,  5754,  5758,  5763,
    5777,  5793,  5797,  5801,  5805,  5809,  5817,  5823,  5829,  5835,
    5844,  5848,  5852,  5860,  5866,  5872,  5876,  5884,  5892,  5899,
    5908,  5912,  5916,  5931,  5945,  5959,  5971,  5987,  5996,  6005,
    6015,  6026,  6034,  6042,  6046,  6065,  6072,  6078,  6085,  6093,
    6092,  6102,  6126,  6128,  6134,  6139,  6141,  6146,  6151,  6156,
    6158,  6162,  6174,  6188,  6192,  6199,  6207,  6215,  6226,  6228,
    6231
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
  "tPlane", "tRuled", "tTransfinite", "tPhysical", "tCompound",
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
     465,   466,   467,   468,    63,   469,   470,   471,   472,    60,
      62,   473,   474,   475,   476,    43,    45,    42,    47,    37,
     124,    38,    33,   477,   478,   479,    94,    40,    41,    91,
      93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   247,   248,   248,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   252,   252,
     252,   252,   252,   252,   253,   253,   253,   253,   254,   254,
     254,   254,   254,   254,   255,   255,   256,   256,   258,   259,
     257,   260,   260,   262,   261,   263,   263,   265,   264,   266,
     266,   268,   267,   269,   269,   269,   269,   269,   270,   270,
     271,   271,   272,   272,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   274,   274,   275,   275,   275,   276,   275,   277,   275,
     275,   278,   275,   279,   279,   280,   280,   280,   281,   281,
     282,   282,   283,   283,   284,   284,   284,   284,   284,   285,
     285,   286,   286,   287,   287,   287,   287,   287,   288,   288,
     288,   289,   289,   289,   289,   290,   290,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   292,
     291,   293,   293,   293,   293,   293,   294,   294,   294,   294,
     295,   295,   295,   296,   296,   296,   296,   297,   297,   297,
     297,   297,   297,   297,   297,   298,   298,   299,   299,   299,
     299,   299,   299,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   301,   301,   301,   301,   301,
     301,   301,   302,   302,   303,   304,   304,   304,   304,   304,
     304,   304,   304,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   306,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   308,   309,
     308,   310,   308,   311,   308,   312,   308,   308,   308,   308,
     308,   313,   313,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   315,   315,   315,   315,   315,   316,
     316,   316,   316,   316,   317,   317,   318,   319,   319,   320,
     320,   321,   321,   322,   322,   323,   323,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   325,   325,
     325,   326,   326,   326,   327,   327,   327,   327,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   330,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   331,   331,   332,   332,   334,   333,   335,
     335,   336,   337,   337,   338,   338,   339,   339,   339,   339,
     339,   340,   340,   340,   340,   341,   341,   342,   342,   342,
     342,   342,   342,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   345,   345,   345,   345,   346,
     346,   346,   346,   347,   347,   348,   348,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   351,
     350,   350,   352,   352,   353,   354,   354,   355,   356,   356,
     356,   356,   357,   357,   357,   358,   358,   358,   359,   359,
     359
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
      12,    12,    12,    10,     4,     4,     4,     4,     2,     3,
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
       4,     4,     2,     4,     2,     3,    16,     5,     1,     1,
       1,     3,     5,     7,     4,     4,     4,     6,     6,     8,
       8,     4,    14,     4,     4,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     4,
       4,     3,     5,     6,     8,     6,     5,     5,     5,     5,
       1,     4,     1,     1,     1,     1,     4,     6,     4,     6,
       5,     7,     4,     4,     4,     8,     4,     4,     4,     4,
       8,     8,     6,     4,     6,     4,     1,     4,     4,     0,
       6,     4,     2,     4,     4,     1,     1,     3,     1,     1,
       3,     3,     3,     5,     7,     5,     5,     8,     1,     1,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,     0,     0,   192,     0,     0,   193,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,   315,   316,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,   284,   285,     0,     0,     0,   279,     0,     0,
       0,     0,     0,   361,   362,   363,     0,     0,     5,     6,
       7,     8,    10,     0,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,     0,   599,     0,   217,     0,     0,     0,     0,     0,
     264,     0,   266,   267,   262,   263,     0,   268,   113,   123,
     598,   474,   469,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,   203,   204,   205,     0,     0,     0,   415,   416,   418,
     419,   417,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   423,   424,   425,     0,
       0,   191,   196,   197,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   420,   421,   422,     0,     0,
       0,     0,     0,     0,     0,     0,   508,   509,     0,   510,
     487,   368,   428,   431,   298,   488,   469,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   189,
     196,   197,   198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,     0,     0,
     217,     0,     0,   358,     0,     0,     0,   200,   201,     0,
       0,     0,     0,     0,   495,     0,     0,   493,     0,     0,
       0,     0,     0,   598,     0,     0,   531,     0,     0,     0,
       0,   260,   261,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   552,     0,
     576,   554,   555,     0,     0,     0,     0,     0,     0,   553,
       0,     0,     0,     0,   277,   278,     0,   217,     0,   217,
       0,     0,     0,   469,     0,     0,     0,   217,   364,     0,
       0,    76,     0,    63,     0,     0,    67,    66,    65,    64,
      69,    68,    70,    71,     0,     0,     0,     0,     0,     0,
     537,   469,     0,   216,     0,   215,     0,   170,     0,     0,
     537,   538,     0,     0,   588,     0,   589,   538,   111,   111,
       0,   467,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   525,   526,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   502,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,     0,   370,   496,   372,     0,   489,
       0,     0,   469,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
     445,     0,     0,     0,     0,     0,     0,   299,     0,   331,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,     0,   217,   217,     0,   478,   477,     0,     0,     0,
       0,   217,   217,     0,     0,     0,     0,   295,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,   241,     0,     0,   239,
     359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   341,   259,     0,     0,     0,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   280,     0,   246,     0,
       0,   248,     0,     0,     0,   370,     0,   217,     0,     0,
       0,     0,     0,     0,     0,   319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    72,    73,     0,     0,   257,    38,   253,     0,
       0,     0,     0,     0,   212,     0,     0,     0,     0,   218,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,   472,     0,     0,   470,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   325,     0,     0,     0,   195,     0,     0,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   426,   444,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,   463,     0,   369,
     490,     0,     0,     0,     0,   498,     0,   388,   387,   386,
     385,   381,   382,   389,   390,   384,   383,   374,   373,     0,
     375,   497,   376,   379,   377,   378,   380,   470,     0,     0,
     471,   448,     0,   511,     0,     0,     0,     0,     0,     0,
       0,   329,     0,     0,     0,     0,   357,     0,     0,     0,
       0,   356,     0,   217,     0,     0,     0,     0,     0,   480,
     479,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   344,     0,     0,   240,     0,     0,   235,     0,     0,
       0,     0,   354,     0,     0,     0,   369,   494,     0,     0,
       0,     0,     0,     0,     0,     0,   282,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   579,     0,     0,     0,
     465,     0,     0,   245,   249,   247,   251,     0,   375,     0,
     470,   448,   600,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   369,     0,
      63,     0,     0,     0,     0,    79,     0,    63,    64,     0,
       0,   470,     0,     0,   448,     0,     0,     0,   189,     0,
       0,   595,    28,    26,    27,     0,     0,     0,     0,     0,
     471,   541,    29,     0,     0,   254,   590,   591,     0,   592,
     541,    74,   114,    75,   124,   473,   475,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   528,   206,     9,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   414,   401,     0,   403,   404,   405,
     406,   407,   524,   408,   409,   410,     0,     0,     0,   516,
     515,   514,     0,     0,     0,   521,     0,   460,     0,     0,
       0,   462,     0,   128,   443,   501,   500,   199,     0,     0,
     429,   523,   434,     0,   440,     0,     0,     0,     0,   491,
       0,     0,   441,     0,   503,     0,     0,     0,     0,   433,
     432,   455,    70,    71,     0,     0,     0,     0,     0,     0,
     369,   327,   332,   330,     0,   340,     0,   148,   149,   199,
     369,     0,     0,     0,     0,   236,     0,   250,   252,     0,
       0,     0,   207,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     343,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,   242,     0,     0,
       0,     0,   566,     0,   573,   562,   563,   564,     0,   578,
     577,     0,     0,   567,   568,   569,   575,   582,   581,     0,
     139,     0,   556,     0,   558,     0,     0,     0,   551,     0,
     244,     0,     0,     0,     0,     0,     0,     0,   320,     0,
       0,     0,   365,     0,   596,     0,     0,     0,     0,   101,
      63,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,    61,     0,    39,    40,    41,    42,    43,     0,   433,
     432,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   540,   539,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   131,   132,     0,     0,     0,   155,   155,
       0,     0,     0,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,     0,     0,     0,     0,   463,   464,     0,   436,     0,
       0,     0,   499,   391,   492,   449,   447,     0,   446,     0,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
     339,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,   305,
       0,   308,     0,   310,     0,   296,   302,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,   345,
       0,   238,   237,   360,     0,     0,    35,    36,     0,     0,
       0,     0,   532,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     465,   466,   560,     0,   449,     0,     0,   217,   321,     0,
     322,   217,     0,     0,   546,   547,   548,   549,     0,    86,
       0,     0,     0,     0,    84,    91,    93,     0,   535,     0,
      99,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    34,   449,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,   542,     0,     0,
      32,     0,   542,   593,     0,   115,   120,     0,     0,     0,
     134,   137,   138,   468,     0,    77,    78,   157,     0,     0,
       0,     0,   158,   173,   174,     0,     0,     0,     0,   159,
     184,   175,   179,   180,   176,   177,   178,   165,     0,     0,
     402,   411,   412,   413,   517,     0,     0,     0,   458,   459,
     461,   129,   427,   457,   430,   435,     0,     0,   463,   185,
     442,     0,    70,    71,     0,   454,   450,   452,   518,   181,
       0,     0,   151,     0,     0,   338,     0,   150,     0,     0,
       0,     0,   258,     0,     0,     0,     0,   217,   217,     0,
       0,   307,   487,     0,     0,   309,   311,     0,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,     0,     0,   162,   163,     0,     0,     0,
       0,   102,   103,   104,   108,     0,   574,     0,     0,   572,
       0,   583,     0,     0,   140,   141,   580,   557,   559,     0,
       0,     0,     0,     0,     0,   319,   323,   319,     0,   366,
      85,    63,     0,     0,     0,     0,    83,     0,   533,     0,
       0,     0,     0,     0,     0,   586,   585,     0,     0,     0,
       0,     0,   485,     0,     0,   454,   255,   450,   256,     0,
       0,     0,     0,   221,   219,     0,     0,   545,   543,     0,
       0,   116,   121,     0,     0,     0,   525,   526,   133,   156,
     160,   161,   166,   183,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,   437,     0,     0,     0,     0,   513,
     456,     0,   167,     0,   186,   328,     0,     0,   187,     0,
       0,     0,     0,     0,     0,   484,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   232,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,     0,
     342,    37,     0,   530,     0,     0,   274,   273,     0,     0,
       0,     0,     0,     0,   143,   144,   147,   146,   145,     0,
     561,     0,   597,     0,     0,     0,     0,     0,     0,    96,
       0,     0,    97,   536,     0,     0,     0,    88,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    46,     0,   222,
     220,    33,     0,     0,   594,   128,   139,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   520,
       0,   463,   438,     0,   451,   453,     0,   169,   190,     0,
     335,   335,     0,   109,   110,   217,     0,   210,   211,   297,
       0,   303,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,   214,   213,     0,     0,     0,     0,   105,
     106,   565,   571,   570,   142,     0,     0,     0,   324,     0,
      92,    94,     0,   100,     0,    82,   587,    89,    90,    49,
       0,     0,     0,     0,   486,     0,     0,   451,   544,     0,
       0,     0,   118,   584,     0,   125,     0,     0,     0,     0,
     172,     0,     0,     0,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   482,     0,   313,     0,
       0,   291,     0,   224,     0,     0,     0,     0,     0,     0,
       0,   529,   275,     0,     0,   353,   217,   367,     0,   534,
       0,    45,     0,     0,     0,    62,    47,     0,   117,   122,
     128,     0,     0,   153,   154,   152,     0,     0,   439,     0,
       0,     0,     0,   336,   346,     0,     0,   347,     0,   208,
       0,   304,     0,   287,     0,   217,     0,     0,     0,     0,
       0,     0,   164,   107,   271,   319,    98,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,   188,     0,
     350,     0,   351,   352,   481,     0,     0,   293,   227,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,    59,
       0,     0,   119,     0,     0,     0,     0,     0,   312,   292,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,   231,     0,   225,   326,    50,     0,    57,
       0,   265,     0,   522,     0,     0,     0,   294,     0,     0,
      51,     0,     0,   270,     0,     0,     0,   226,     0,     0,
       0,     0,   506,     0,     0,    54,    52,     0,    55,     0,
     348,   349,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1015,   109,   110,  1000,  1810,  1816,
    1283,  1486,  1960,  2089,  1284,  2060,  2107,  1285,  2091,  1286,
    1287,  1490,   415,   560,   561,  1081,   111,   739,   438,  1825,
    1970,  1826,   439,  1705,  1351,  1312,  1313,  1314,  1447,  1644,
    1645,  1146,  1538,  1529,   719,   571,   254,   255,   330,   185,
     256,   424,   425,   115,   116,   117,   118,   119,   120,   121,
     122,   257,  1178,  1994,  2051,   896,  1174,  1175,   258,   977,
     259,   126,  1379,  1144,   871,   910,  1930,   127,   128,   129,
     130,   260,   261,  1103,  1118,  1237,   262,   744,   263,   861,
     743,   441,   586,   299,  1681,   337,   338,   265,   530,   345,
    1271,  1479,   434,   430,  1230,   954,  1522,  1674,  1675,   939,
     436,   132,   393
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1798
static const yytype_int16 yypact[] =
{
   11110,    51,    87, 11259, -1798, -1798,   112,   102,    63,   -39,
      35,    39,   187,   202,   233,   269,    56,   282,    77,    86,
      23,   -73,   -73,    65,    91,   109,    37,   138,   143,    52,
     151,   169,   174,   191,   198,   206,   221,   230,   236,   246,
     255,   398,   450,   576,   322,   581,   334,  6189,   362,   347,
     506,   -45,   502,   591,   529,    44,   375,   528,   -33,   385,
      11,    11,   392,   470,   359, -1798, -1798, -1798, -1798, -1798,
     413,   239,   560,   575,    20,    70,   595,   669,   113,   693,
     708,   728,  5249,   780,   561,   592,   605,    26,    54, -1798,
     611,   623, -1798, -1798,   779,   791,   574, -1798, 11454,   658,
   11506,     2,    41, -1798, -1798, -1798, 10941,   596, -1798, -1798,
   -1798, -1798, -1798,   593, -1798, -1798, -1798, -1798, -1798, -1798,
   -1798, -1798, -1798, -1798,   241, -1798, -1798, -1798, -1798,    25,
   -1798,   843,   668,  5000,    81,   651,   910, 10941, 11425, 11425,
   -1798, 10941, -1798, -1798, -1798, -1798, 11425, -1798, -1798, -1798,
     679,   704,   916, -1798, -1798, 11535,    23, 10941, 10941, 10941,
     710, 10941, 10941, 10941,   711, 10941, 10941, 10941, 10941, 10941,
   10941, 10941, 11425, 10941, 10941, 10941, 10941,  5249,   732, -1798,
    8764, -1798, -1798, -1798,   729,  5249, 11425, -1798, -1798, -1798,
   -1798, -1798,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   433,   -73,   -73,   -73,   -73,
     -73,   747,   -73,   -73,   749,   591, -1798, -1798, -1798,   -73,
     -73,    42,   805,   812,   813,   748,  6424,   872,   591,   755,
     -73,   -73,   756,   757,   758, -1798, -1798, -1798, 10941,  6659,
   10941, 10941,  6894,    23,   822,    45, -1798, -1798,   759, -1798,
    4477, -1798, -1798, -1798, -1798, -1798,    60, 10941,  8764,   761,
     762,  7129,  5249,  5249,  5249, -1798, -1798, -1798, -1798, -1798,
   -1798, -1798, -1798,   760,  7364,   763,  9629,   998,  6424,   764,
      26,   765,   767,    11,    11,    11, 10941, 10941,   -84, -1798,
     382,    11,  9705,   391,   372,   766,   772,   792,   793,   794,
     795,   796, 10941,  5249,  5249,  5249,   797,    15,  1010,   798,
   -1798,  1029,  1030, -1798,   799,   803,   814, -1798, -1798,   815,
    5249,   819,   820,   821, -1798, 10941,  5484, -1798,  1057,  1058,
   10941, 10941, 10941,   481, 10941,   824, -1798,   891, 10941, 10941,
   10941, -1798, -1798, 10941, -1798,   -73,   -73,   -73,   831,   832,
     851,   -73,   -73,   -73,   -73,   -73,   -73,   -73, -1798,   -73,
   -1798, -1798, -1798,   -73,   -73,   853,   854,   -73,   857, -1798,
     860,  1087,  1094,   861, -1798, -1798,  1095,  1096,  1097,  1098,
     -73, 10941,  2483,   142, 11425,  8764, 10941, -1798, -1798,  6424,
    6424, -1798,   866, 11535,   612,  1101, -1798, -1798, -1798, -1798,
   -1798, -1798, 10941, 10941,    28,  6424,  1103,   705,  1509,   869,
    1105,    95,   871, -1798,   873, 11718, 10941, -1798,  1687,  -127,
   -1798,    53,  -115,  9028, -1798,   -44, -1798,   108,  -146,    73,
    1027, -1798,    23,   868,   870, 13922, 13947, 13972, 10941, 13997,
   14022, 14047, 10941, 14072, 14097, 14122, 14147, 14172, 14197, 14222,
     897, 14247, 14272, 14297, 12506,  1129, 10941,  8764,  4876, -1798,
     309, 10941,  1132,   902, 10941, 10941, 10941, 10941, 10941, 10941,
   10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941,
    8764, 10941, 10941, 10941, 10941, 10941, 10941,  8764,  8764,   898,
   10941, 10941, 11425, 10941, 11425,  6424, 11425, 11425, 11425,   900,
   10941,    38, -1798,  9940, 10941,  6424,  5249, 11425, 11425,  8764,
      23, 11535,    23,   906,  8764,   906, -1798,   906, 14322, -1798,
     393,   903,    69,  1079, -1798,  1136, 10941, 10941, 10941, 10941,
   10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941,
    7599, 10941, 10941, 10941, 10941, 10941,    23, 10941, 10941,  1141,
   -1798,   733, 14347,   394, 10941, 10941, 10941, -1798,  1140,  1143,
    1143,   911, 10941, 10941,  1145,  8764,  8764, 13434,   914,  1147,
   -1798,   913, -1798, -1798,  -158, -1798, -1798,  9348,  9661,    11,
      11,    81,    81,  -144,  9705,  9705, 10941,  4280,  -136, -1798,
   10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941, 10941, 14372,
    1148,  1152,  1154, 10941,  1153, 10941, -1798, 10941,  5052, -1798,
   -1798,  8764,  8764,  8764, 10941,  1157, 10941, 10941, 10941, 14397,
     922, -1798, -1798, 14422, 14447, 14472,   993,  9889, -1798,   925,
    5199, 14497, 14522, 13517, 11425, 11425, 11425, 11425, 11425, 11425,
   11425, 11425, 11425, 10941, 11425, 11425, 11425, 11425,    14, 11535,
   11425, 11425, 11425,    23,    23, -1798, -1798,  8764, -1798,   926,
    5551, -1798,   928,  5786, 10941,   906, 10941, -1798,    23, 10941,
   10941,  1141,   929,   491, 14547, 11654,   936,   493, 10941,  1161,
     935,   937,   939,   940, 10941, 14572, 13544,   188,   934,  1175,
    1177, -1798, -1798, -1798,  8764,   197, -1798, -1798, -1798,    23,
   10941, 10941,  1141,   945, -1798,   949,   -32,   591,   529, -1798,
     946, 12535, -1798,   119,  8764,    23, 10941, 10941,  1184,  1186,
    8764, 10941,  1187, 11425,    23, 10016,  1184,  1188, -1798,    23,
    1189, 11425, 10941,   952,   957, -1798, 10941, 11535,  1190,  1191,
    1195, 14597,  1196,  1197,  1198, 14622,  1199,  1200,  1201,  1202,
    1204,  1205,  1206, -1798,  1207,  1209,  1210, -1798, 10941, 14647,
    8764,   977,  8764, 12564, -1798,  1217, 13490, 13490, 13490, 13490,
   13490, 13490, 13490, 13490, 13490, 13490, 13490,  9972, 13490, 13490,
   13490, 13490,   314,   537, 13490, 13490, 13490, 10202, 10278, 10508,
    4876,   987,   989,   115,  8764, 10591, 10814,   537, 11455,   537,
     981,   986,   988,    13, 10941, 15447, -1798,   537,  1007, 12593,
   12622, -1798,  1004,   -92,   537,  -166,  1015,   242,   518,  1247,
   -1798,  1184,   537,  1014,  1017,  7771,  8000,  1106,   901,  1016,
    1016,   489,   489,   489,   489,   489,   489,   543,   543,  8764,
     473, -1798,   473,   473,   906,   906,   906,  1013, 14672, 13571,
     -17,   583,  8764, -1798,  1250,  1019, 14697, 14722, 14747, 10941,
    6424,  1254,  1255,  9399, 12651, 14772, -1798,   534,   540,  8764,
    1020, -1798,  6021, -1798,  6256,  6491,    11, 10941, 10941, -1798,
   -1798,  1022,  1023,  9705,  4081,  1135,   452,    11,  6726, 14797,
   12680, 14822, 14847, 14872, 14897, 14922, 14947, 14972,  1259, 10941,
    1262, -1798, 10941, 14997, -1798, 13598, 13625, -1798,   541,   547,
     548, 12709, -1798, 13652, 13679, 11648, -1798, -1798,  1263,  1264,
    1265,  1026, 10941,  6961, 10941, 10941, -1798, -1798,    36,   -12,
     121,   -12,  1035,  1036,  1031,   537,   537,  1032, 11681,   537,
     537,   537,   537, 10941,   537,  1270, -1798,  1037,  1043,   179,
    -137,  1042,   549, -1798, -1798, -1798, -1798, 13490,   473,  7196,
    1041,   739,  1045,  1111,  1281,  1144, 10246,  1052,  1054,  1290,
    6424, 12738, -1798, 10941, 10941, 10941, 10941,  1713,   192,   131,
   11535, 10941,  1291,  1294,    32, -1798,   554,  1253,  1256,  6424,
      22,  1061, 15022, 13706,   285, 10941, 10941,  1063,  1060,  1068,
    7834, -1798, -1798, -1798, -1798, 11425,    17,  1064, 15047, 13733,
   -1798,  1069, -1798,   132, 11714, -1798, -1798, -1798,  1066, -1798,
    1073, -1798,    68, -1798, -1798, 15447, -1798,  1308, 13490,   537,
      11,  6424,  6424,  1306,  6424,  6424,  6424,  1307,  6424,  6424,
    6424,  6424,  6424,  6424,  6424,  6424,  6424,  6424,  1738,  1309,
    8764,  4876, -1798, -1798, -1798, -1798, -1798, -1798, -1798, -1798,
   -1798, -1798, -1798, -1798, -1798, -1798, 10941, -1798, -1798, -1798,
   -1798, -1798, -1798, -1798, -1798, -1798, 10941, 10941, 10941, -1798,
   -1798, -1798,   557, 10941, 10941, -1798, 10941, -1798,  6424, 11425,
   11425, -1798, 12767,  1072, -1798, -1798, -1798,  1163, 10941, 10941,
   -1798, -1798, -1798,  1184, -1798,  1184, 10941, 10941,  1077, -1798,
    6424,   -73, -1798, 10941, -1798, 10941, 10941,   562,  1184,   -17,
     -55, -1798, 10941, 10941,   537,   563,  6424,  8764,  1312,  1313,
    1332,   736, -1798, -1798,  1334, -1798,  1112, 15447,  1107, -1798,
    1336,  1344,  1347,   564,  1337, -1798,  7431, -1798, -1798,   -81,
   11747, 11780, -1798, -1798, 12796,  -113,  1248,  1351, 10329,  1116,
    1352,  1122,    29,    47,   -61, -1798,   -54, -1798,   452,  1353,
    1355,  1356,  1357,  1358,  1359,  1362,  1363,  1364,  6424, 15447,
   -1798,  1939,  1121,  1369,  1370,  1371,  1283,  1375, -1798,  1377,
    1378, 10941,  6424,  6424,  6424,  1381, 11813, -1798,  8466,  1303,
      50,  1383, -1798,  8764, -1798, -1798, -1798, -1798, 11425, -1798,
   -1798, 10941, 11425, -1798, -1798, -1798, -1798, 15447, -1798,  1146,
    1142, 11425, -1798, 11425, -1798,  1184, 11425,  1151, -1798,  1150,
   -1798,  1184, 10941, 10941,  1156,   591,  1158, 10559, -1798,  2097,
    1159,  6424, -1798,  1149, -1798, 12825, 12854, 12883, 12912, -1798,
   -1798, 10941,  1386,    48, 10941,  1387,  1395,  2511, -1798,  1396,
      26,  1398,  1166,   537,   -73,   -73,  1402, -1798,  1173,  1174,
    1172, -1798,  1409, -1798, -1798, -1798, -1798, -1798,  1184,   396,
     694, 10941, 13760, 15072, 10941,  8064, 10941,  1176,   565,  1410,
     162,  1184, -1798,  1178, 10941,  1413, 10941,  1184, 10635,  8994,
     537,  4441,  1180,  1179, -1798,  1416,  1417,   146,  1305,  1305,
    6424,  1418,  1421,  1422,  6424,   -67,  1424,  1425,  1426,  1427,
    1428,  1430,  1449,  1450,  1451, -1798,  1455,   570, 13490, 13490,
   13490, 13490,   537, 11846, 11879, 11912,  1224,   537,   537, -1798,
    1308,   537, 15097, 13490,  1225,   254, 15447, 13490, -1798,  1458,
     537, 11945, 15447, 15447, -1798,   742, -1798,  1457, -1798, 15122,
   13787, -1798,   537,  1461,   573,  6424,  6424,  6424,  1464,  1463,
   -1798,   235, 10941,  6424,  1229,  1230,  1465,   387, -1798, 10941,
   10941, 10941,  1232,  1234,  1235,  1238, -1798,  3095,  6424, -1798,
   10941, -1798,  1472, -1798,  1473, -1798, -1798,  9705,   -26,  5719,
   -1798,  1241,  1243,  1244,  1246,  1249,  1251,  8294,  1482, -1798,
    8764, -1798, -1798, -1798,  1252, 10941, -1798, -1798, 13814,  1483,
    1485,  1323, -1798, 10941, 10941, 10941, -1798,  1489,  1490,  1491,
     743,   340,  1258,  2958,  1260, 10941,    10,   537,  1261,   537,
    1266, -1798, -1798, 11535,   746, 10941,  1257, -1798, -1798,  3229,
   -1798, -1798,  1267,  1494, -1798, -1798, -1798, -1798,  3256, -1798,
     203,  1271,  1495,  3518, -1798, -1798, -1798,    26, -1798,   598,
   -1798, 10941,   235,  2918,  3221, -1798,  1268, 10941, 10941,  6424,
    1269, -1798,   426,  1497,  1503, 15147,  1529,  1247, 15172,  1296,
     599, 15197,  1530,  1534, -1798, -1798, 11425,  1310,  1538, 15222,
   -1798, 11978,  1311, -1798,  4748, 15447, -1798,  1536,   -73,  6894,
   -1798, -1798, -1798, -1798,  1308, -1798, -1798, -1798,    11,  1539,
    1540,  1543, -1798, -1798, -1798,  1545,   -29,  1459,  1546, -1798,
   -1798, -1798, -1798, -1798, -1798, -1798, -1798, -1798,  1549,  1315,
   -1798, -1798, -1798, -1798, -1798, 10941, 10941, 10941, -1798, -1798,
   -1798,  1179, -1798, -1798, -1798, -1798, 10941,  1321,  1298, -1798,
   -1798, 10941, 10941, 10941,   537,   -17, -1798, -1798, -1798, -1798,
    1319,  1555,   -67,  1557, 10941, -1798,  6424, 15447,   927,  8764,
    8764, 10941, -1798,  9399, 12941, 15247,  4684,    81,    81, 10941,
   10941, -1798,   856,  1318, 15272, -1798, -1798, 12970,   -50, -1798,
    1559,  1560,  6424,    11,    11,    11,    11,    11,  5954,  1561,
   -1798,   601, 10941,  3646,  1562, -1798, -1798,  6424,  8700,  1223,
   15297, -1798, -1798, -1798, -1798,  9079, -1798, 11425, 10941, -1798,
   11425, 15447,  9314, 11535,  1324, -1798, -1798, -1798, -1798,  1331,
    1325, 10941, 10941, 12999, 10941, 11654, -1798, 11654,  6424, -1798,
   -1798, 11535, 10941,  1566,  1569,    32, -1798,  1568, -1798,    26,
   13841,  6424, 11425,  1571,   537, -1798,  1329,   537, 10941, 12011,
   12044,   608, -1798, 10941, 10941,   451, -1798,  1338, -1798,  1332,
    1572,  1574,  1336, -1798, -1798,  1578, 10941, -1798, -1798, 10941,
   10865, -1798, -1798,  1348,  3221,   609,  4512,  1581, -1798,   533,
   -1798, -1798, -1798, -1798,  1349,  1350,  1354, -1798,  1580,  6424,
   13490, 13490, 12077, 13490, -1798,  1361, 12110, 15322, 13868, -1798,
   -1798, 10941, -1798,  1586, -1798, 15447,  1587,  1360, -1798,   616,
     619, 13462,  3674,  1588,  1365, -1798, -1798, 10941,  1366,  1368,
   13028, 13895,  1594,  6424,  1595,  1372, 10941, -1798, -1798,   624,
     -35,    -1,   195,   204,   208,  8529,   226, -1798,  1597, 13057,
   -1798, -1798,  1435, -1798, 10941, 10941, -1798, -1798,  8764,  3749,
    1601,  1373, 13490,   537, 15447, -1798, -1798, -1798, -1798,    10,
   -1798, 11535, -1798, 13086,  1374,  1376,  1379,  1606,  3823, -1798,
    1607,  1613, -1798, -1798,  1380,  1614,   626, -1798,  1616,  1619,
     186, 15447, 10941, 10941,  1385,  6424,   627, 15447, 15347, -1798,
   -1798, -1798, 15372, 12143, -1798,  1072,  1142,  6424,   537, -1798,
   10941, 11535,    23,  8764,  8764, 10941,  1622,   629, -1798, -1798,
   10941,  1298, -1798, 10941, -1798, -1798, 13115, -1798, -1798,  6424,
     597,   620,  8764, -1798, -1798,    81,  9578, -1798, -1798, -1798,
    1623, -1798,  1388,  6424, -1798, 13144,  1625,  8764,    11,    11,
      11,    11,    11, -1798, -1798, 10941, 13173, 13202,   635, -1798,
   -1798, -1798, -1798, -1798, -1798,  1394,  1627,  1397, -1798,  1629,
   -1798, -1798,    26, -1798,  1466, -1798, -1798, -1798, -1798, -1798,
   10941, 12176, 12209,  6424, -1798,  1630, 10941,  1400, -1798, 10941,
    1401,  1403, -1798, -1798,  4393, -1798,  1405,   636,   637, 13231,
   -1798,  1406, 12242,  1408, 12275, -1798,   638,  1407,    11,  6424,
    1638,  1411,    11,  1643,   647,  1412, -1798, 10941, -1798,  1644,
    1524,  7666,  1415, -1798,   652,   231,   240,   264,   272,   281,
    3946, -1798, -1798,  1647,  1651, -1798, -1798, -1798,  1652, -1798,
    1419, 15447, 10941, 10941,   655, -1798, 15447, 12308, -1798, -1798,
    1072, 11535,  1429, -1798, -1798, -1798, 10941, 10941, -1798, 10941,
    1653,    11,   161, -1798, -1798,    11,   164, -1798,  1658, -1798,
   13260, -1798, 10941, -1798,   452, -1798,  1659,  8764,  8764,  8764,
    8764,  8529, -1798, -1798, -1798, 11654, -1798, 10941, 15397, 12341,
      43, 10941,  1431, -1798, -1798, 12374, 12407, 12440, -1798,   323,
   -1798,   335, -1798, -1798, -1798,  3978,   317,  8361, -1798,   664,
     665,   666,   672,   341,   673,  1433,   680, -1798, 10941, -1798,
    6424, 13289, -1798, 10941, 10941, 10941,    11,    11, -1798, -1798,
   -1798,   452,  1665,  1666,  1670,  1671,  8764,  1672,  1673,  1674,
    1440, 15422,   681,  1677, 13318, 13490, 12473,   351,   368,   431,
   -1798, -1798, -1798, -1798,   688, -1798, -1798, -1798, 11425, -1798,
    1443, -1798,  1679, -1798, 10941, 10941, 10941, -1798,  1680,   690,
   -1798,  1446,  6424, -1798, 13347, 13376, 13405, -1798,  1683, 11425,
   11425,   696, -1798,  1684,  1686, -1798, -1798,   698, -1798,  1688,
   -1798, -1798,  1689, 11425, -1798, -1798, -1798
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1798, -1798, -1798, -1798,   397, -1798, -1798, -1798, -1798,  -311,
   -1798, -1798, -1798, -1798, -1798, -1798, -1798, -1798, -1798, -1798,
   -1798, -1798,  -668,   -68,  3893,  2881, -1798,  1272, -1798, -1798,
   -1798, -1798, -1798, -1798, -1797, -1798,   348,   175,  -126, -1798,
     -87, -1798,   122,   384,  1702, -1798,     6,   -49, -1798, -1798,
       0,  -570,  -282, -1798, -1798, -1798, -1798, -1798, -1798, -1798,
   -1798,  1704, -1798, -1798, -1798, -1798, -1177, -1170,  1705, -1645,
    1706, -1798, -1798, -1798,  1171, -1798,  -141, -1798, -1798, -1798,
   -1798,  1950, -1798, -1798, -1349,   262,  1711, -1798,     3,  -673,
   -1798, -1798,   263, -1798, -1572,   -31,  -152,  2291,  1167,  -288,
      55, -1798,   176,   -85, -1798, -1798,    75,   234, -1608,  -135,
     982, -1798,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -546
static const yytype_int16 yytable[] =
{
     133,  1408,   581,   114,  1406,   284,  1567,   386,   971,   113,
    1794,   435,  1795,   381,  1642,   385,   264,   152,   150,   614,
     597,   891,   892,   151,   317,   465,  1277,   150,  1910,   991,
     343,   398,   697,   472,  1787,  1401,   150,   999,   618,  1004,
    1759,   160,   150,  1210,   266,   140,   388,   512,   420,  2039,
     534,   270,  1470,  1403,  1437,  1021,   164,     4,   347,   279,
    1536,  1714,   725,  1030,   270,   416,  1167,   589,   590,   556,
     443,   321,  1112,   271,   322,  1309,   323,  1113,   442,   266,
    1715,   589,   590,  1168,   346,   422,  1007,     5,   886,   589,
     590,  1169,  1170,  1171,   737,   382,  1828,  1172,  1173,   150,
     738,  1167,   893,   318,   709,   670,  1235,   673,  1537,  1236,
     897,   723,   589,   590,   289,   685,   136,   734,  1168,   724,
     568,   569,   570,   729,   556,  1012,  1169,  1170,  1171,  1393,
     421,   730,  1172,  1173,   423,   431,   431,   285,  1260,   290,
     286,   589,   590,   437,   589,   590,   702,  1837,   703,  1438,
    1439,   678,  1527,   444,  1109,   291,   292,   591,  1121,   137,
     324,   610,   611,   612,   153,  1389,   154,  2020,  1505,   431,
    2022,   589,   590,  2012,   266,   589,   590,   266,   625,   410,
     411,  1405,   266,   431,  1278,  1279,  1280,  1281,  1367,  1402,
     589,   590,  1407,   142,   732,   990,  1756,  1643,   138,  1260,
     698,   699,   733,   319,   997,   264,   327,  1404,   143,   328,
    1661,  1867,    59,    60,    61,    62,  1609,   410,   411,  1725,
    1471,  1472,   329,   107,   589,   590,   702,    73,   703,   107,
      76,   509,   107,   266,   733,   107,   294,   295,  1406,   144,
     567,   107,  1260,   387,   516,  1868,   266,   107,   296,   266,
     532,  1101,   297,   574,   615,  1300,   531,   579,   953,   733,
     135,   320,   399,   772,  1282,   266,   400,   344,   266,   266,
     266,   266,   139,  1270,   161,   145,   702,  1926,   703,  1211,
     141,   266,   389,   513,  2040,   266,   535,   346,   147,   165,
     726,   348,   727,   146,   410,   411,   728,   557,   882,   558,
     884,   885,   157,   559,   107,   153,   153,   154,   154,   419,
     266,   266,   266,   740,   429,   432,   148,   898,   689,   738,
    1261,  1264,   536,   298,   300,   149,   303,   266,   158,   410,
     411,  1964,   710,   266,   711,   313,  -538,   314,   712,  1013,
    1014,   406,   407,   408,   409,   735,   159,   727,   460,   410,
     411,   736,   557,   134,   558,  1091,   933,   135,   559,   702,
    2035,   703,   473,   304,   821,   410,   411,  1213,   686,   687,
    1305,   589,   590,   813,  1263,   162,   410,   411,   772,   679,
     163,   680,  1013,  1014,   700,   681,   589,   590,   166,   589,
     590,   431,   266,  1592,  1593,   969,   266,   266,   406,   407,
     408,   409,   406,   407,   408,   409,   167,   406,   407,   408,
     998,   168,   266,   406,   407,   408,   409,   702,   713,   703,
     589,   590,   410,   411,  1899,  1233,   410,   411,   169,   589,
     590,   720,  1900,   589,   590,   170,   826,   410,   411,   745,
    1354,  1869,  1355,   171,  1167,   406,   407,   408,   409,   305,
    1870,   589,   590,   306,  1871,  1365,   589,   590,   172,   307,
     308,  1168,   309,   310,   266,   589,   590,   173,  2062,  1169,
    1170,  1171,  1872,   174,   810,  1172,  1173,  1997,   396,   153,
     311,   154,   397,   175,   567,  1115,  1998,   266,  1116,   589,
     590,   153,  1923,   154,   266,   803,   176,   589,   590,   431,
    1116,   431,   266,   431,   431,   437,   589,   590,   817,   177,
    1999,   941,   266,   266,   431,   431,   266,   152,  2000,   152,
    2101,   266,  1291,   825,  1243,   827,  -541,  2001,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   770,   551,   552,   553,   554,   178,   266,   589,   590,
     555,   771,   702,   857,   703,   772,   584,   585,  1167,  2049,
     589,   590,  1450,   180,   593,   598,   589,   590,  1454,  2046,
     682,   186,   266,   266,   956,  1168,   589,   590,   702,  1167,
     703,  2047,   179,  1169,  1170,  1171,   772,  2056,   268,  1172,
    1173,   423,   423,   589,   590,   272,  1168,  2085,   273,   267,
     274,  1156,   269,   720,  1169,  1170,  1171,   589,   590,   600,
    1172,  1173,   287,   601,  2086,  1492,   589,   590,   266,   266,
     266,   288,   280,   592,   720,   281,   293,   282,  1507,   992,
     410,   411,   599,   301,  1512,   830,   865,  -540,   283,   772,
     772,   437,   431,   437,   431,   431,   431,   431,   431,   431,
     312,   431,   431,   431,   431,   955,   315,   431,   431,   431,
     152,   961,  1039,  1684,   266,  1652,   960,  -542,   316,  1009,
     497,   181,   498,  2087,   182,   970,   720,   183,   807,   720,
     809,   275,   811,   812,   276,   410,   411,   277,   325,   278,
     184,   720,  -545,   822,   823,   294,   295,   331,   150,   354,
      40,   266,   690,   553,   554,   691,  1001,   296,   692,   555,
     693,   302,   332,  1586,   548,   549,   676,   551,   552,   553,
     554,   266,  1017,  1008,   636,   555,   135,   266,  1927,  1928,
     437,  1028,   333,   973,  1929,   979,  1032,   772,   431,   980,
     355,   356,   357,   358,   359,   360,   361,   362,   363,  1634,
    1635,  1931,  1932,   364,   365,   366,   367,  1929,   589,   590,
    1119,   368,   369,   370,   772,   326,   371,   266,   372,   266,
     676,   551,   552,   553,   554,   702,  1151,   703,   373,   555,
     772,   374,  1152,  1195,   339,   351,   772,   772,  1148,  1196,
    1197,  1239,  1131,   772,   772,   772,  1273,   352,   340,  1342,
     772,   266,  1662,   772,  1364,  1372,  1386,  1503,   772,   772,
     772,   772,  1549,   353,  1671,  1580,   772,  2026,   404,   772,
    1132,   940,  1133,   942,   943,   944,   945,   946,   947,   341,
     949,   950,   951,   952,   395,   394,   957,   958,   959,  1142,
    1668,  1691,   342,  1768,  1669,   772,   266,   772,   349,   401,
    1814,  1829,   889,   890,  1815,  1830,  1406,   585,  1850,   266,
     350,  1851,   772,  1378,   536,   772,  1866,   266,  1896,  1905,
    1815,  1921,   733,  1906,  2069,  1815,   266,  1953,  1973,  1974,
    1980,   772,   772,   772,  1815,   375,   376,   377,   720,  1988,
     720,   720,   426,   772,  1996,   383,   378,  2010,   772,  1406,
     379,  1815,   380,   107,   720,  1266,  2052,  2053,  2054,  1026,
     772,   772,   772,   402,  2055,  2057,   427,  1034,   772,   772,
    1262,  1265,  2059,  2080,   135,   442,  1906,  1815,   410,   411,
    2088,  1737,  2098,  1738,   772,  -539,  2099,  1493,  2109,   720,
    2112,   440,  1815,   702,  2113,   703,   704,   448,   452,  1253,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,  1276,   466,
     471,   702,   555,   703,   862,   720,  1242,   266,  1243,  1572,
    -192,  1573,  1478,  1651,   505,  1652,   508,  -193,  -194,   514,
     515,  1272,   517,   520,   521,   522,   266,   533,   564,   565,
     397,   572,   578,   602,   575,   580,   582,   266,   583,   603,
    1318,  1319,   431,  1321,  1322,  1323,   616,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1748,  1749,   604,
     605,   606,   607,   608,   613,   619,   620,   617,   266,   266,
     621,   266,   266,   266,   622,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   623,   624,   266,   626,   627,
     628,  1366,  1368,   631,   632,   638,   639,  1346,   647,   648,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   649,  1359,
     660,   661,   555,   665,   663,   266,   431,   431,  1752,   664,
     666,   668,   667,   671,   669,  1373,   672,   688,   694,   701,
     707,   708,   134,   742,   746,   714,   747,   266,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,   266,   266,   763,   768,   555,   774,   804,
     775,   814,   555,   833,   834,   860,   831,   869,   873,  1159,
     870,   876,   880,   881,   883,   909,  1165,  1418,   911,   914,
    1176,   912,   720,   922,   927,   931,   934,   982,   963,   972,
     965,  1429,  1430,  1431,   978,  1655,   983,   993,   984,  1657,
     985,   986,   994,   995,  1005,   266,  1006,  1010,  1020,  1667,
    1036,  1299,  1022,  1025,  1031,  1033,  1037,  1040,  1041,   266,
     266,   266,  1042,  1044,  1045,  1046,  1048,  1049,  1050,  1051,
     266,  1052,  1053,  1054,  1055,   431,  1056,  1057,  1060,   431,
    1462,  1366,  1368,  1064,  1516,  1089,  1521,  1098,   431,  1090,
     431,  1775,  1099,   431,  1100,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,   266,  1105,
    1108,  1456,   555,  1114,  1120,  1123,  1128,  1136,  1143,  1124,
    1137,  1145,  1166,  1154,  1162,  1163,  1188,   346,  1190,  1205,
    1202,  1203,  1204,  1216,  1217,  1347,  1348,  1218,  1221,  1229,
    1520,  1232,  1238,  1231,  1241,  1935,  1245,   431,  1246,  1531,
    1244,  1247,   266,  1535,  1250,  1251,  1252,  1268,  1269,  1274,
    1294,  1295,  1275,  1317,  1288,  1296,  1304,  1301,   266,  1307,
    1308,  1435,  1311,  1320,  1324,  1358,  1336,   266,  1350,  1375,
    1376,   266,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,  -195,  1377,
    1380,  1387,   555,  1383,  1581,  1582,  1583,   470,  1676,  1676,
    1381,  1384,  1588,  1382,  1385,  1395,  1394,  1398,  1399,  1400,
    1409,  1410,  1420,  1411,  1412,  1413,  1414,  1603,  1650,  1415,
    1416,  1417,   266,   266,   266,  1421,  1422,  1423,  1611,  1424,
     266,  1803,  1425,  1426,  1427,  1432,  1619,  1440,  1446,  1452,
    1445,  1463,  1469,  1474,  1442,   266,  1453,  1455,  1444,  1457,
    1461,  1475,  1663,  1477,  1480,  1481,   266,  1448,  1485,  1449,
    1487,  1488,  1451,  1489,   266,  1491,  1504,   266,  1502,  1510,
    1523,  1508,  1525,  1526,  1532,  1524,  1528,  1533,  1534,  1702,
    1539,  1540,  1541,  1542,  1543,   563,  1544,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,  1545,  1546,  1547,  1682,   555,
    1548,  1575,  1558,  1565,  1569,  1776,  1494,  1579,  1584,  1585,
    1589,  1590,  1591,  1597,   346,  1598,  1599,  1600,  1605,  1606,
     437,   437,  1612,  1701,  1613,  1614,   266,  1615,  1620,  1625,
    1616,  1626,  1617,  1622,  1627,  1631,  1632,  1633,  1654,  1647,
    1659,  1685,  1665,   431,  1637,  1678,  1640,  1730,  1743,  1686,
    1683,   266,  1236,  1658,  1664,   706,   266,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,  1688,  1693,  1806,  1690,   555,
    1694,  1436,  1697,  1703,  1116,  1710,  1711,  1696,  1700,  1712,
    1780,  1713,  1717,  1716,  1718,  1736,  1719,  1785,  1788,  1724,
    1731,  1732,   683,  1734,  1753,  1757,  1758,  1767,  1771,  1790,
    1789,  1791,  1799,  1800,  1802,   733,  1797,  1807,  1819,  -543,
    1820,  1682,  1941,   266,  1821,  1836,   266,   266,  1832,  1827,
    1833,  1834,  1847,  1848,  1854,  1835,  1772,   423,   423,  1842,
    1861,  1849,  1863,  1873,  1958,  1875,  1855,  1880,  1857,   266,
    1858,  1881,  1890,  1864,  1892,   266,  1887,  1730,  1888,  1893,
    1895,  1889,  1897,  1894,   266,  1898,  1903,  1796,  1920,  1938,
    1939,  1943,  1954,  1955,   431,  1957,  1965,   431,  1956,  1959,
    1805,  -544,  1972,  1968,  1984,  1969,  1978,  1976,  1981,  1987,
    1991,  1992,  1985,  2003,  1989,   266,  1995,  2004,  2006,  2018,
    2007,   720,  1272,   720,  2023,  2028,   346,  2014,   266,   437,
    1608,  2070,  2071,  2042,  2005,  2058,  2072,  2073,  2075,  2076,
    2077,  2078,  1695,  2081,  2092,  2093,  2097,  2100,  1682,  2105,
    2110,   828,  2111,   722,  2114,  2115,  2036,  1506,  1561,  1708,
    1911,   437,  1884,  1530,  1733,   112,  1885,   123,   124,   125,
    1933,   741,  1649,  2027,   131,  1027,   266,  1786,  1677,  1259,
    1801,     0,  1862,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,   872,   877,   878,  1335,   555,  1915,     0,     0,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,  1904,     0,     0,     0,   918,   919,
     920,  1709,     0,     0,     0,     0,  1912,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,  1781,     0,     0,  1783,     0,  1682,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,  1916,
     266,   266,  1940,     0,   962,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,     0,     0,   266,
       0,     0,     0,     0,     0,   423,     0,     0,     0,     0,
     266,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,   996,  1682,     0,     0,     0,  1760,  1761,  1762,  1763,
    1764,  1766,     0,     0,     0,     0,  2013,     0,     0,   346,
       0,  1016,     0,     0,     0,     0,     0,  1023,  1983,     0,
     266,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,   266,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,  1419,     0,   720,     0,   555,
       0,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,  1092,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   266,   266,   266,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1682,
       0,   720,     0,     0,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1135,
       0,     0,     0,   720,     0,     0,     0,   266,     0,     0,
       0,     0,     0,     0,     0,     0,  1153,     0,     0,     0,
       0,     0,     0,   266,     0,     0,   392,     0,     0,     0,
       0,  1682,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,     0,     0,
       0,     0,     0,   418,     0,     0,     0,   428,     0,   266,
       0,   433,     0,     0,     0,     0,   431,   431,     0,     0,
       0,     0,     0,  1460,     0,     0,     0,   445,   446,   447,
     431,   449,   450,   451,     0,   453,   454,   455,   456,   457,
     458,   459,     0,   461,   462,   463,   464,     0,     0,     0,
     468,  1945,  1946,  1947,  1948,  1949,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,  1298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1982,     0,     0,     0,  1986,     0,     0,   523,   525,
     527,   528,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   562,   468,     0,
       0,     0,     0,     0,     0,     0,     0,  1337,     0,     0,
       0,     0,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,     0,     0,  2019,     0,   587,   588,  2021,     0,
       0,     0,   588,     0,  2090,     0,     0,     0,     0,     0,
       0,     0,   609,     0,  2033,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2106,  2108,     0,     0,     0,
       0,     0,     0,     0,     0,   629,   468,     0,     0,  2116,
     633,   634,   635,     0,   637,     0,     0,     0,   640,   641,
     642,     0,     0,   643,  1374,     0,     0,     0,     0,  2067,
    2068,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,   675,     0,     0,     0,   468,   684,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   695,   696,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   721,     0,     0,     0,
    1441,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   751,     0,
       0,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   769,   525,     0,     0,
       0,   773,     0,     0,   776,   777,   778,   779,   780,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,   791,
     792,   794,   795,   796,   797,   798,   799,   800,   800,     0,
     805,   806,     0,   808,     0,     0,     0,     0,     0,     0,
     815,     0,  1500,   819,   820,     0,     0,     0,     0,   800,
       0,   469,     0,     0,   468,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   844,   845,   846,   847,   848,
     850,   852,   853,   854,   855,   856,     0,   858,   859,     0,
       0,     0,     0,     0,   866,   867,   868,  1476,     0,     0,
       0,     0,   874,   875,     0,   468,   468,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,     0,     0,   469,   523,   675,   894,     0,     0,     0,
     899,   900,   901,   902,   903,   904,   905,   906,   907,   469,
       0,     0,     0,   913,     0,   915,     0,   916,     0,     0,
       0,   468,   468,   468,   921,     0,   923,   924,   925,     0,
       0,     0,     0,     0,     0,     0,     0,  1621,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   948,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   468,     0,     0,
       0,     0,     0,     0,   967,     0,   968,   469,     0,   858,
     859,     0,     0,     0,     0,     0,     0,     0,   981,     0,
       0,     0,     0,     0,   987,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,     0,     0,     0,     0,     0,
    1002,  1003,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,     0,  1018,  1019,     0,     0,
     468,  1024,     0,     0,     0,  1018,   469,     0,     0,     0,
       0,     0,  1035,     0,     0,     0,  1038,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,  1058,   555,
     850,     0,  1061,     0,   677,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,   468,     0,  1739,  1740,   526,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   793,     0,     0,     0,     0,     0,     0,   801,   802,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     824,     0,   468,     0,     0,   469,     0,     0,     0,  1141,
       0,     0,     0,  1147,     0,     0,     0,     0,     0,   468,
       0,     0,     0,     0,     0,     0,     0,  1160,  1161,     0,
       0,   851,     0,  1164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1189,
       0,     0,  1191,     0,     0,     0,   469,   469,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1206,     0,  1208,  1209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1227,     0,     0,     0,     0,     0,     0,
       0,     0,   469,   469,   469,     0,     0,     0,     0,     0,
       0,     0,   150,   354,     0,     0,  1249,     0,     0,     0,
       0,     0,     0,  1255,  1256,  1257,  1258,     0,     0,     0,
       0,  1267,     0,     0,     0,  1878,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1292,  1293,     0,   469,     0,
     468,     0,     0,     0,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,   364,   365,   366,
     367,     0,     0,     0,     0,   368,   369,   370,     0,     0,
     371,     0,   372,     0,     0,   469,     0,     0,     0,     0,
    1917,  1918,   373,     0,     0,   374,     0,     0,     0,     0,
     468,     0,     0,     0,     0,   469,     0,     0,     0,  1934,
       0,   469,     0,     0,     0,     0,  1338,     0,     0,     0,
       0,     0,     0,     0,  1944,     0,  1339,  1340,  1341,     0,
       0,     0,   404,  1343,  1344,     0,  1345,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1352,  1353,
       0,   851,     0,  1062,     0,     0,  1356,  1357,     0,     0,
       0,     0,     0,  1361,     0,  1362,  1363,     0,     0,     0,
       0,     0,  1369,  1370,     0,     0,     0,   468,     0,     0,
       0,     0,     0,     0,     0,   469,     0,     0,     0,     0,
       0,  1601,     0,     0,     0,     0,     0,     0,     0,   375,
     376,   377,     0,     0,     0,     0,     0,     0,  1397,     0,
     378,     0,     0,     0,   379,     0,   380,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1428,     0,   469,     0,     0,   702,     0,   703,  1672,
       0,     0,     0,   468,  2029,  2030,  2031,  2032,  2034,     0,
     469,  1443,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,  1369,  1370,   555,     0,   702,  1459,   703,     0,
       0,     0,     0,     0,  1638,     0,     0,     0,     0,     0,
       0,  1468,     0,     0,  1473,     0,     0,     0,     0,     0,
       0,     0,     0,  2074,     0,   150,   354,     0,     0,     0,
       0,     0,     0,     0,     0,  1656,     0,     0,     0,     0,
       0,  1495,     0,     0,  1498,   468,  1501,     0,     0,     0,
       0,     0,     0,     0,  1509,     0,  1511,     0,  1509,  1515,
       0,     0,  1660,     0,     0,     0,     0,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
     364,   365,   366,   367,     0,     0,     0,     0,   368,   369,
     370,     0,     0,   371,     0,   372,     0,     0,   705,     0,
       0,   469,     0,     0,     0,   373,     0,     0,   374,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,  1587,     0,     0,     0,     0,     0,     0,  1594,
    1595,  1596,     0,     0,     0,   404,     0,     0,  1602,     0,
    1604,   469,     0,     0,     0,     0,     0,  1607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,     0,     0,     0,     0,  1623,     0,     0,     0,     0,
       0,     0,     0,  1628,  1629,  1630,     0,     0,     0,     0,
       0,     0,   816,     0,     0,  1641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1653,     0,     0,     0,     0,
       0,     0,   375,   376,   377,     0,     0,     0,     0,     0,
       0,     0,     0,   378,     0,     0,     0,   379,   469,   380,
     107,  1670,     0,     0,     0,     0,     0,  1679,  1680,     0,
       0,     0,   863,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,  1672,     0,     0,   555,     0,     0,     0,  1706,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   469,  1720,  1721,  1722,     0,     0,
       0,     0,     0,     0,     0,     0,  1723,     0,     0,     0,
       0,  1726,  1727,  1728,  1666,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1735,     0,     0,     0,     0,   468,
     468,  1741,     0,  1742,     0,     0,     0,     0,     0,  1750,
    1751,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   468,     0,
       0,     0,  1769,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1779,   469,     0,  1782,     0,
       0,     0,  1784,     0,     0,     0,     0,     0,     0,     0,
       0,  1727,  1728,     0,  1793,     0,     0,     0,     0,     0,
       0,     0,  1798,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1811,     0,
       0,     0,     0,  1817,  1818,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1822,     0,     0,  1823,
    1822,     0,  1770,     0,     0,     0,     0,  1065,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,     0,  1077,
    1078,  1079,  1080,     0,  1082,  1083,  1084,  1085,     0,     0,
    1853,  1846,     0,     0,     0,     0,     0,     0,  1095,     0,
    1097,     0,     0,     0,     0,     0,     0,  1856,  1104,     0,
       0,     0,     0,     0,  1110,  1111,  1865,     0,     0,     0,
       0,   469,     0,  1122,     0,   525,     0,     0,     0,     0,
       0,     0,     0,     0,  1876,  1877,     0,     0,   468,     0,
       0,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,  1879,     0,     0,     0,     0,
       0,     0,  1901,  1902,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1914,     0,     0,   468,   468,  1919,     0,     0,     0,     0,
    1922,     0,     0,  1924,     0,     0,     0,     0,     0,     0,
       0,     0,   468,     0,     0,     0,     0,     0,     0,     0,
    1707,     0,     0,     0,     0,     0,     0,   468,     0,     0,
    1212,  1214,  1215,     0,     0,  1950,  1219,  1220,     0,  1891,
    1223,  1224,  1225,  1226,     0,  1228,     0,     0,     0,     0,
    1234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1961,     0,     0,     0,     0,     0,  1966,     0,     0,  1967,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
     469,   469,   555,     0,     0,     0,     0,  1990,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,   469,
     555,     0,  2008,  2009,   155,   156,     0,     0,     0,  1315,
    1316,     0,     0,     0,     0,     0,  2015,  2016,     0,  2017,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2025,     0,     0,     0,     0,   468,   468,   468,
     468,   468,  2002,     0,     0,     0,     0,  1817,     0,     0,
       0,  2041,     0,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,  2048,   555,     0,     0,  2061,     0,
       0,     0,     0,  2064,  2065,  2066,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   468,     0,     0,     0,
       0,     0,     0,     0,     0,  1371,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,     0,     0,  2094,  2095,  2096,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,   526,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   499,   500,
     501,   502,   503,   504,     0,   506,   507,     0,     0,     0,
       0,     0,   510,   511,   469,   469,     0,     0,     0,     0,
       0,     0,     0,   518,   519,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1482,     0,     0,     0,   469,     0,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,  1517,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,  1550,
    1551,  1552,  1553,  1554,     0,     0,     0,     0,  1559,  1560,
       0,     0,  1562,     0,  1564,     0,     0,     0,  1568,     0,
       0,  1570,     0,     0,     0,     0,     0,     0,   644,   645,
     646,     0,     0,  1578,   650,   651,   652,   653,   654,   655,
     656,     0,   657,     0,     0,     0,   658,   659,     0,     0,
     662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   674,     0,     0,     0,     0,   469,   469,
     469,   469,   469,     7,     8,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,   926,
       0,     0,  1636,     0,  1639,     0,     0,   887,  1646,     0,
    1648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   469,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1673,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   715,    48,
    1971,    50,   716,     0,   717,   718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,   832,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     6,   354,    84,    85,    86,
       0,   188,   189,   190,     0,  1729,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   536,     0,  1518,   356,   357,
     358,   359,   360,   361,   362,   363,   220,   221,   222,   223,
     364,   365,   366,   367,   224,   225,     0,     0,   368,   369,
     370,     0,     0,   371,     0,   372,   226,   227,   228,  1831,
     536,     0,   895,   229,    20,   373,   230,     0,   374,     0,
       0,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
     235,     0,     0,     0,     0,  1808,     0,     0,  1809,   236,
       0,    49,     0,   237,     0,   238,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1838,  1839,     0,  1841,     0,     0,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,   239,   375,   376,   377,   240,   241,     0,     0,     0,
     242,   243,   244,   378,   245,   246,   247,   379,     0,   380,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1882,  1883,     0,   248,   249,     0,     0,
       0,     0,     0,   250,     0,     0,     0,     0,   335,     0,
       0,     0,  1519,     0,     0,   253,     0,     0,     0,     0,
       0,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,  1913,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
    1117,     0,     0,     0,     0,     0,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   770,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,   187,     6,   354,  1134,     0,     0,     0,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   220,   221,   222,   223,   364,   365,   366,
     367,   224,   225,     0,     0,   368,   369,   370,     0,     0,
     371,     0,   372,   226,   227,   228,     0,     0,     0,     0,
     229,    20,   373,   230,     0,   374,     0,     0,   231,     0,
       0,   232,     0,     0,   233,     0,   234,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,    49,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,   536,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,  1310,  1746,     0,     0,     0,
    1747,     0,     0,     0,     0,     0,     0,     0,   239,   375,
     376,   377,   240,   241,     0,     0,  2083,   242,   243,   244,
     378,   245,   246,   247,   379,     0,   380,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   335,     0,     0,     0,   252,
       0,     0,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   150,   354,     0,   403,     0,     0,
     188,   189,   190,     0,  1360,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   390,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   220,   221,   222,   223,   364,
     365,   366,   367,   224,     0,     7,     8,   368,   369,   370,
       0,     0,   371,     0,   372,   226,   227,   228,     0,     0,
       0,     0,   229,    20,   373,   230,     0,   374,     0,     0,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   770,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,    40,     0,     0,    42,     0,     0,  1483,  1484,     0,
     715,    48,     0,    50,   716,     0,   717,   718,     0,     0,
       0,     0,     0,   405,     0,     0,     0,     0,     0,     0,
     239,   375,   376,   377,   240,    70,     0,     0,     0,   242,
     243,   244,   378,   245,   246,   247,   379,   935,   380,   107,
     406,   407,   408,   409,     0,     0,     0,     0,     0,    84,
      85,    86,     0,     0,     0,   248,   391,     0,     0,     0,
       0,     0,   250,     0,   410,   411,     0,   412,     0,   413,
       0,     0,     0,   414,   253,     0,     0,     0,  1566,     0,
       0,     0,   187,     6,   334,     0,     0,     0,  1574,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,   917,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   227,   228,     0,     0,     0,
       0,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1704,     0,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,   239,
       0,     0,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   335,   187,     6,     0,
     336,     0,   630,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     227,   228,     0,     0,     7,     8,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   715,
      48,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     467,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   335,   187,     6,  1610,     0,   529,     0,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   964,   226,   227,   228,     0,     0,     7,
       8,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   715,    48,     0,    50,   716,   239,
     717,   718,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,   250,     0,    84,    85,    86,   335,   187,     6,     0,
     252,     0,     0,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   966,   226,
     227,   228,     0,     0,     7,     8,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   715,
      48,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
    1765,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   596,   187,     6,     0,   297,   529,     0,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1155,   226,   227,   228,     0,     0,     7,
       8,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   715,    48,     0,    50,   716,   239,
     717,   718,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,   250,     0,    84,    85,    86,   251,   187,     6,     0,
     252,     0,     0,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1157,   226,
     227,   228,     0,     0,     7,     8,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   715,
      48,     0,    50,   716,   239,   717,   718,     0,   240,   241,
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
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   715,    48,     0,    50,   716,   239,
     717,   718,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   467,     0,     0,     0,     0,
       0,   250,     0,    84,    85,    86,   335,   187,     6,     0,
     524,     0,     0,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1177,   226,
     227,   228,     0,     0,     7,     8,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   715,
      48,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     467,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   335,   187,     6,     0,     0,   529,     0,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1207,   226,   227,   228,     0,     0,     7,
       8,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   715,    48,     0,    50,   716,   239,
     717,   718,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,   250,     0,    84,    85,    86,   566,   187,     6,     0,
     252,     0,     0,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1240,   226,
     227,   228,     0,     0,     7,     8,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   715,
      48,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   573,   187,     6,     0,   252,     0,     0,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1388,   226,   227,   228,     0,     0,     7,
       8,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,    40,     0,     0,    42,  1125,
       0,     0,     0,     0,   715,    48,     0,    50,   716,   239,
     717,   718,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   467,     0,     0,     0,     0,
       0,   250,     0,    84,    85,    86,   335,   187,     6,     0,
     849,     0,  1297,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1993,   226,
     227,   228,     0,     0,     0,     0,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,  1126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     467,     0,     0,     0,     0,     0,   250,   187,     6,     0,
       0,   335,  1499,     0,   188,   189,   190,     0,   253,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     227,   228,     0,     0,     0,     0,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
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
     467,     0,     0,     0,     0,     0,   250,   187,     6,     0,
       0,   335,     0,     0,   188,   189,   190,     0,   253,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     227,   228,     0,     0,     7,     8,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
      40,     0,     0,    42,  1434,     0,     0,     0,     0,   715,
      48,     0,    50,   716,   239,   717,   718,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     0,     0,   250,     0,    84,    85,
      86,   335,   187,     6,     0,  1618,     0,     0,   253,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2050,   226,   227,   228,     0,     0,     0,
       0,   229,    20,     0,   230,     0,     0,     0,     0,   231,
       0,     0,   232,     0,     0,   233,     0,   234,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    49,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,  1765,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   596,   187,     6,     0,
     297,     0,     0,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     227,   228,     0,     0,     0,     0,   229,    20,     0,   230,
       0,     0,     0,     0,   231,     0,     0,   232,     0,     0,
     233,     0,   234,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    49,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  1773,     0,     0,     0,  1774,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     467,     0,     0,     0,     0,     0,   250,   187,   150,   354,
       0,   335,     0,     0,   188,   189,   190,     0,   253,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   390,   209,   210,   211,
     212,   213,   214,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,   239,   375,   376,   377,   240,     0,
       0,     0,     0,   242,   243,   244,   378,   245,   246,   247,
     379,     0,   380,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     391,     0,     0,     0,     0,     0,   250,     0,     0,     0,
       0,   335,     0,     0,     0,  1514,     0,     0,   253,     0,
       0,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,   239,
     375,   376,   377,   240,   731,     0,     0,     0,   242,   243,
     244,   378,   245,   246,   247,   379,     0,   380,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   335,   187,   150,   354,
    1778,     0,     0,   253,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   390,   209,   210,   211,
     212,   213,   214,     0,     0,     0,     0,     0,     0,     0,
    1518,   356,   357,   358,   359,   360,   361,   362,   363,   220,
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
       0,     0,     0,     0,   239,   375,   376,   377,   240,     0,
       0,     0,     0,   242,   243,   244,   378,   245,   246,   247,
     379,     0,   380,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     391,     0,     0,     0,     0,     0,   250,     0,     0,     0,
       0,   335,     0,     0,     0,  1672,     0,     0,   253,     0,
       0,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,   239,
     375,   376,   377,   240,   887,     0,     0,     0,   242,   243,
     244,   378,   245,   246,   247,   379,     0,   380,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,   187,   150,     0,     0,   335,     0,     0,   188,
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
     230,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,   239,
    1936,     0,     0,   240,  1937,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   335,     0,     0,     0,
     576,     0,     0,   253,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,   239,     0,   555,     0,   240,
       0,     0,     0,     0,   242,   243,   244,   888,   245,   246,
     247,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,     0,     0,     0,     0,     0,   250,     0,     0,
       0,     0,   596,   187,   150,     0,   297,     0,   818,   253,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   390,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,   227,   228,     0,   187,
     150,     0,   229,    20,     0,   230,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   390,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   227,   228,     0,     0,     0,     0,   229,    20,
       0,   230,     0,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
     239,     0,     0,     0,   240,   932,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   391,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,   253,     0,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,   239,     0,   555,     0,
     240,     0,     0,     0,     0,   242,   243,   244,  1076,   245,
     246,   247,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   391,     0,     0,     0,     0,     0,   250,   187,
     150,     0,  1248,   335,  1029,     0,   188,   189,   190,     0,
     253,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   390,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   227,   228,     0,     0,     0,     0,   229,    20,
       0,   230,   187,   150,     0,  1396,     0,     0,     0,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   390,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   227,   228,     0,     0,     0,
       0,   229,    20,     0,   230,     0,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,   239,     0,   555,     0,
     240,     0,     0,     0,     0,   242,   243,   244,  1086,   245,
     246,   247,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   391,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,   335,     0,     0,     0,     0,     0,     0,
     253,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,   239,
       0,     0,     0,   240,  1087,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,   187,   150,     0,  1458,   335,     0,     0,   188,
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
     230,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,   239,
       0,     0,     0,   240,  1088,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   391,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   335,     0,     0,     0,
       0,     0,     0,   253,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,   239,     0,   555,     0,   240,
       0,     0,     0,     0,   242,   243,   244,  1093,   245,   246,
     247,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   391,     0,     0,     0,     0,     0,   250,   187,   150,
       0,     0,   335,  1513,     0,   188,   189,   190,     0,   253,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   390,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,     0,   187,   150,     0,   229,    20,     0,
     230,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   390,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   227,   228,     0,
       0,     0,     0,   229,    20,     0,   230,     0,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,   239,     0,     0,     0,   240,
    1094,     0,     0,     0,   242,   243,   244,     0,   245,   246,
     247,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   391,     0,     0,     0,     0,     0,   250,     0,     0,
       0,     0,   335,  1824,     0,     0,     0,     0,     0,   253,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,   240,     0,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     107,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   391,     0,     0,
       0,     0,     0,   250,    -4,    -4,    -4,     0,   335,     0,
      -4,    -4,     0,    -4,     0,   253,     0,     0,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,     9,    10,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,     0,    17,     0,    18,
      19,     0,    20,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,    37,    38,    39,    40,    41,
       0,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,    80,    81,     0,     0,     0,
      82,     0,     0,     0,     0,    83,    84,    85,    86,   150,
     354,    87,     0,    88,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   150,   354,
       0,     0,     0,     0,     0,     0,   106,     0,   107,     0,
       0,   355,   356,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,   364,   365,   366,   367,     0,     0,
       0,     0,   368,   369,   370,     0,     0,   371,     0,   372,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   373,
     384,   354,   374,   364,   365,   366,   367,     0,     0,     0,
       0,   368,   369,   370,     0,     0,   371,     0,   372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   373,     0,
     354,   374,     0,     0,     0,     0,     0,     0,     0,   404,
       0,     0,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,   364,   365,   366,   367,     0,
       0,     0,     0,   368,   369,   370,     0,     0,   371,     0,
     372,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     373,     0,     0,   374,   364,   365,   366,   367,     0,     0,
       0,     0,   368,   369,   370,     0,     0,   371,     0,   372,
       0,     0,     0,     0,     0,     0,   375,   376,   377,   373,
       0,     0,   374,     0,     0,     0,     0,   378,     0,     0,
       0,   379,     0,   380,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   375,   376,   377,     0,     0,
       0,     0,     0,     0,     0,     0,   378,     0,     0,     0,
     379,     0,   380,   107,     0,     0,     0,     7,     8,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,   375,   376,   377,
       0,  1096,     0,     0,     0,     0,     0,     0,   378,     0,
       0,     0,   379,     0,   380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   375,   376,   377,     0,
       0,     7,     8,     0,     0,     0,     0,   378,     0,     0,
       0,   379,     0,   380,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   715,    48,     0,    50,   716,     0,   717,   718,
       0,     0,     0,     0,   975,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,   976,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    84,    85,    86,    37,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   715,    48,     0,    50,
     716,     0,   717,   718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,    84,    85,    86,     0,     0,
       0,     0,     0,     0,  1201,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1222,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1306,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1390,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1391,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1433,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1555,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1556,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1557,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1571,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1699,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1812,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1813,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1840,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1843,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1909,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1962,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1963,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1977,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1979,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2011,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2038,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2043,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2044,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2045,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2084,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,   767,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  1011,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,  1063,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,  1106,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,  1107,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,  1149,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  1180,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,  1198,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    1254,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  1349,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,  1392,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  1464,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,  1465,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,  1466,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,  1467,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,  1744,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  1755,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,  1792,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    1859,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  1874,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,  1886,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  1925,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,  1942,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     676,   551,   552,   553,   554,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,  1951,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,     0,  1952,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,     0,     0,  1975,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   676,   551,   552,
     553,   554,     0,     0,     0,     0,   555,     0,     0,     0,
       0,     0,  2024,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   676,   551,   552,   553,
     554,     0,     0,     0,     0,   555,     0,     0,     0,     0,
       0,  2063,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,     0,     0,
    2082,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,  2102,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   676,   551,   552,   553,   554,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,  2103,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,  2104,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,     0,   879,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
       0,     0,     0,  1852,   537,   538,   539,   540,   541,   542,
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
       0,     0,     0,   555,     0,     0,     0,  1577,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   676,   551,   552,   553,   554,     0,     0,     0,     0,
     555,     0,     0,     0,  1624,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   676,   551,
     552,   553,   554,     0,     0,     0,     0,   555,     0,     0,
       0,  1804,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   676,   551,   552,   553,   554,
       0,     0,     0,     0,   555,     0,     0,     0,  1845,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   676,   551,   552,   553,   554,     0,     0,     0,
       0,   555,     0,     0,     0,  1860,   537,   538,   539,   540,
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
       0,     0,     0,   555,     0,  1563,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1576,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1687,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1689,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1692,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1698,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1745,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1754,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1777,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1844,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  1907,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    1908,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555,     0,  2037,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   676,
     551,   552,   553,   554,     0,     0,     0,     0,   555,     0,
    2079,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   676,   551,   552,   553,   554,     0,
       0,     0,     0,   555
};

static const yytype_int16 yycheck[] =
{
       3,  1178,   290,     3,  1174,    54,  1355,     5,   681,     3,
    1655,   146,  1657,    98,     4,   100,    47,    20,     4,     4,
     302,   591,   592,    20,     4,   177,     4,     4,  1825,   697,
       4,     6,     4,   185,  1642,     6,     4,   705,   320,   712,
    1612,     4,     4,     7,    47,     6,     5,     5,   133,     6,
       5,    96,     4,     6,     4,   728,     4,     6,     4,    53,
     127,    90,     9,   736,    96,   133,   127,   225,   226,     9,
     155,    74,   238,   118,     4,     7,     6,   243,     9,    82,
     109,   225,   226,   144,    87,     4,   118,     0,   246,   225,
     226,   152,   153,   154,   240,    98,  1704,   158,   159,     4,
     246,   127,   246,    83,     9,   387,   243,   389,   175,   246,
     246,   238,   225,   226,   147,   397,    14,     9,   144,   246,
     272,   273,   274,   238,     9,     6,   152,   153,   154,   242,
     133,   246,   158,   159,   134,   138,   139,    93,     7,   172,
      96,   225,   226,   146,   225,   226,   238,  1719,   240,    99,
     100,     9,     6,   156,   246,   188,   189,   241,   831,    96,
      90,   313,   314,   315,   237,   246,   239,     6,     6,   172,
       6,   225,   226,  1970,   177,   225,   226,   180,   330,   234,
     235,   242,   185,   186,   162,   163,   164,   165,   243,   160,
     225,   226,   246,     6,   238,     7,   246,   187,   237,     7,
     172,   173,   246,   183,     7,   236,    93,   160,     6,    96,
       7,   246,   131,   132,   133,   134,   242,   234,   235,  1568,
     172,   173,   109,   209,   225,   226,   238,   146,   240,   209,
     149,   225,   209,   236,   246,   209,   225,   226,  1408,     6,
     271,   209,     7,   241,   238,   246,   249,   209,   237,   252,
     253,   238,   241,   284,   239,   238,   253,   288,   244,   246,
     245,   241,   237,   246,   242,   268,   241,   241,   271,   272,
     273,   274,   237,   241,   237,     6,   238,  1849,   240,   243,
     241,   284,   241,   241,   241,   288,   241,   290,     6,   237,
     237,   237,   239,   237,   234,   235,   243,   237,   580,   239,
     582,   583,   237,   243,   209,   237,   237,   239,   239,   133,
     313,   314,   315,   240,   138,   139,   239,   599,   403,   246,
     988,   989,     8,    60,    61,   239,    63,   330,   237,   234,
     235,  1903,   237,   336,   239,    96,   241,    98,   243,   220,
     221,   210,   211,   212,   213,   237,   237,   239,   172,   234,
     235,   243,   237,   241,   239,   240,   638,   245,   243,   238,
    2005,   240,   186,     4,   516,   234,   235,   246,   399,   400,
     238,   225,   226,   508,   243,   237,   234,   235,   246,   237,
     237,   239,   220,   221,   415,   243,   225,   226,   237,   225,
     226,   394,   395,     6,     7,   677,   399,   400,   210,   211,
     212,   213,   210,   211,   212,   213,   237,   210,   211,   212,
     213,   237,   415,   210,   211,   212,   213,   238,   421,   240,
     225,   226,   234,   235,   238,   246,   234,   235,   237,   225,
     226,   425,   246,   225,   226,   237,   521,   234,   235,   442,
    1113,   246,  1115,   237,   127,   210,   211,   212,   213,    90,
     246,   225,   226,    94,   246,  1128,   225,   226,   237,   100,
     101,   144,   103,   104,   467,   225,   226,   237,  2040,   152,
     153,   154,   246,   237,   505,   158,   159,   246,   237,   237,
     121,   239,   241,   237,   515,   243,   246,   490,   246,   225,
     226,   237,  1841,   239,   497,   498,   241,   225,   226,   502,
     246,   504,   505,   506,   507,   508,   225,   226,   511,   111,
     246,   646,   515,   516,   517,   518,   519,   520,   246,   522,
    2092,   524,   237,   520,   239,   522,   241,   246,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    96,   550,   225,   226,
     236,   242,   238,   556,   240,   246,   293,   294,   127,   242,
     225,   226,  1235,   241,   301,   302,   225,   226,  1241,   246,
     394,   237,   575,   576,   659,   144,   225,   226,   238,   127,
     240,   246,     6,   152,   153,   154,   246,   246,   241,   158,
     159,   591,   592,   225,   226,    93,   144,   246,    96,   237,
      98,   883,    96,   597,   152,   153,   154,   225,   226,   237,
     158,   159,   237,   241,   246,  1288,   225,   226,   621,   622,
     623,    93,    93,   241,   618,    96,   241,    98,  1301,   697,
     234,   235,   241,   241,  1307,   242,   242,   241,   109,   246,
     246,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     237,   654,   655,   656,   657,   658,    96,   660,   661,   662,
     663,   664,   747,   237,   667,   239,   663,   241,    93,   718,
     237,    90,   239,   242,    93,   678,   670,    96,   502,   673,
     504,    90,   506,   507,    93,   234,   235,    96,    93,    98,
     109,   685,   241,   517,   518,   225,   226,     4,     4,     5,
     109,   704,    90,   230,   231,    93,   709,   237,    96,   236,
      98,   241,     4,  1381,   225,   226,   227,   228,   229,   230,
     231,   724,   725,   717,   243,   236,   245,   730,   131,   132,
     733,   734,     4,   242,   137,   242,   739,   246,   741,   246,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     6,
       7,   131,   132,    59,    60,    61,    62,   137,   225,   226,
     242,    67,    68,    69,   246,    96,    72,   770,    74,   772,
     227,   228,   229,   230,   231,   238,   242,   240,    84,   236,
     246,    87,   242,   242,     4,     6,   246,   246,   873,   242,
     242,   242,   860,   246,   246,   246,   242,     6,   237,   242,
     246,   804,  1470,   246,   242,   242,   242,   242,   246,   246,
     246,   246,   242,   239,  1482,   242,   246,  1994,   124,   246,
     237,   645,   239,   647,   648,   649,   650,   651,   652,   237,
     654,   655,   656,   657,   241,   239,   660,   661,   662,   870,
     242,   242,   237,   242,   246,   246,   849,   246,   237,     6,
     242,   242,   589,   590,   246,   246,  2026,   594,   242,   862,
     237,   242,   246,   127,     8,   246,   242,   870,   242,   242,
     246,   242,   246,   246,  2051,   246,   879,   242,   242,   242,
     242,   246,   246,   246,   246,   191,   192,   193,   882,   242,
     884,   885,   241,   246,   242,   237,   202,   242,   246,  2069,
     206,   246,   208,   209,   898,   990,   242,   242,   242,   733,
     246,   246,   246,   245,   242,   242,     6,   741,   246,   246,
     988,   989,   242,   242,   245,     9,   246,   246,   234,   235,
     242,     4,   242,     6,   246,   241,   246,   243,   242,   933,
     242,   237,   246,   238,   246,   240,   241,   237,   237,   980,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   999,   237,
     241,   238,   236,   240,   241,   969,   237,   980,   239,   237,
     175,   239,  1270,   237,   237,   239,   237,   175,   175,   241,
     118,   994,   237,   237,   237,   237,   999,   175,   237,   237,
     241,   241,     4,   237,   241,   241,   241,  1010,   241,   237,
    1041,  1042,  1015,  1044,  1045,  1046,     6,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,  1056,  1057,  1597,  1598,   237,
     237,   237,   237,   237,   237,     6,     6,   239,  1041,  1042,
     241,  1044,  1045,  1046,   241,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,   241,   241,  1060,   239,   239,
     239,  1129,  1130,     6,     6,   241,   175,  1098,   237,   237,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   237,  1120,
     237,   237,   236,     6,   237,  1098,  1099,  1100,   242,   239,
       6,     6,   241,     6,     8,  1136,     8,   241,     7,     6,
     241,     6,   241,    86,   246,   242,   246,  1120,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,  1136,  1137,   238,     7,   236,     6,   241,
     238,   241,   236,    64,     8,     4,   243,     7,   237,   886,
       7,     6,   238,     6,   241,     7,   893,  1188,     6,     6,
     897,     7,  1156,     6,   242,   172,   241,     6,   242,   240,
     242,  1202,  1203,  1204,   238,  1457,   241,   243,   241,  1461,
     241,   241,     7,     6,   239,  1188,   237,   241,     4,  1477,
     238,  1015,     6,     6,     6,     6,   239,     7,     7,  1202,
    1203,  1204,     7,     7,     7,     7,     7,     7,     7,     7,
    1213,     7,     7,     7,     7,  1218,     7,     7,   241,  1222,
    1251,  1289,  1290,     6,  1309,   238,  1311,   246,  1231,   240,
    1233,     8,   246,  1236,   246,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,  1251,   242,
     246,  1245,   236,   238,     7,   241,   243,     7,     4,   242,
     241,     6,   127,   243,   242,   242,     7,  1270,     6,   243,
       7,     7,     7,   238,   238,  1099,  1100,   246,   246,     9,
    1311,   238,   240,   246,   243,  1855,   175,  1290,     7,  1320,
     245,   147,  1295,  1324,   242,   241,     6,     6,     4,    46,
     237,   241,    46,  1040,   243,   237,   237,   243,  1311,   243,
     237,     8,     4,     7,     7,   238,     7,  1320,   246,     7,
       7,  1324,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   175,     7,
       6,     4,   236,     7,  1375,  1376,  1377,   180,  1483,  1484,
     238,     7,  1383,   246,     7,     4,   108,   241,     6,   237,
       7,     6,   241,     7,     7,     7,     7,  1398,  1453,     7,
       7,     7,  1375,  1376,  1377,     6,     6,     6,  1409,    96,
    1383,  1669,     7,     6,     6,     4,  1417,     4,   246,   238,
     244,   242,     6,     6,  1218,  1398,   246,   241,  1222,   241,
     241,     6,  1470,     7,     6,   239,  1409,  1231,     6,  1233,
     237,   237,  1236,   241,  1417,     6,     6,  1420,   242,     6,
     240,   243,     6,     6,     6,   246,   121,     6,     6,  1514,
       6,     6,     6,     6,     6,   268,     6,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     6,     6,     6,  1489,   236,
       5,     4,   238,   238,     6,   242,  1290,     6,     4,     6,
     241,   241,     7,   241,  1477,   241,   241,   239,     6,     6,
    1483,  1484,   241,  1514,   241,   241,  1489,   241,     6,     6,
     241,     6,   241,   241,   171,     6,     6,     6,   241,   238,
       6,     4,     7,  1506,   246,   237,   246,  1575,  1593,     6,
     241,  1514,   246,   246,   243,     6,  1519,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     6,     6,  1672,   242,   236,
       6,   238,     4,     7,   246,     6,     6,   237,   237,     6,
    1635,     6,     6,    94,     5,  1586,   241,  1642,  1643,   238,
     241,     6,   395,     6,   246,     6,     6,     6,     6,   238,
     246,   246,     6,     4,     6,   246,  1661,     6,     6,   241,
       6,  1612,  1864,  1586,     6,     5,  1589,  1590,     7,   241,
     241,   241,     6,     6,     6,   241,  1627,  1597,  1598,   238,
       6,   241,     7,     6,  1892,   170,   241,     6,   242,  1612,
     242,   238,     6,   241,     7,  1618,   242,  1685,   242,     6,
       6,   242,     6,   243,  1627,     6,   241,  1658,     6,     6,
     242,     6,   238,     6,  1637,     6,     6,  1640,   241,   173,
    1671,   241,   237,   242,     6,   242,   238,   241,   241,     6,
       6,   127,   241,     6,   242,  1658,   241,     6,     6,     6,
     241,  1655,  1665,  1657,     6,     6,  1669,   238,  1671,  1672,
    1407,     6,     6,   242,  1956,   242,     6,     6,     6,     6,
       6,   241,  1506,     6,   241,     6,     6,   241,  1719,     6,
       6,   524,     6,     6,     6,     6,  2007,  1300,  1350,  1524,
    1826,  1704,  1789,  1319,  1582,     3,  1791,     3,     3,     3,
    1851,   439,  1450,  1995,     3,   733,  1719,  1642,  1484,     6,
    1665,    -1,  1753,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   570,   575,   576,     6,   236,  1831,    -1,    -1,    -1,
    1753,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1778,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1815,    -1,    -1,    -1,   621,   622,
     623,  1528,    -1,    -1,    -1,    -1,  1827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1815,  1637,    -1,    -1,  1640,    -1,  1849,    -1,
      -1,    -1,    -1,    -1,  1827,    -1,    -1,    -1,    -1,  1832,
    1833,  1834,  1863,    -1,   667,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1849,    -1,    -1,  1852,
      -1,    -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,
    1863,    -1,    -1,    -1,  1867,    -1,    -1,    -1,    -1,    -1,
      -1,   704,  1903,    -1,    -1,    -1,  1613,  1614,  1615,  1616,
    1617,  1618,    -1,    -1,    -1,    -1,  1971,    -1,    -1,  1892,
      -1,   724,    -1,    -1,    -1,    -1,    -1,   730,  1929,    -1,
    1903,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,  1929,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     6,    -1,  1941,    -1,   236,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,   804,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1997,  1998,  1999,  2000,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2040,
      -1,  2005,    -1,    -1,    -1,    -1,   849,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   862,
      -1,    -1,    -1,  2027,    -1,    -1,    -1,  2040,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   879,    -1,    -1,    -1,
      -1,    -1,    -1,  2056,    -1,    -1,   106,    -1,    -1,    -1,
      -1,  2092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2078,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   137,    -1,  2092,
      -1,   141,    -1,    -1,    -1,    -1,  2099,  2100,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,   157,   158,   159,
    2113,   161,   162,   163,    -1,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,   174,   175,   176,    -1,    -1,    -1,
     180,  1868,  1869,  1870,  1871,  1872,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,  1010,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1928,    -1,    -1,    -1,  1932,    -1,    -1,   248,   249,
     250,   251,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1981,    -1,   296,   297,  1985,    -1,
      -1,    -1,   302,    -1,  2078,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   312,    -1,  2001,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2099,  2100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,   336,    -1,    -1,  2113,
     340,   341,   342,    -1,   344,    -1,    -1,    -1,   348,   349,
     350,    -1,    -1,   353,  1137,    -1,    -1,    -1,    -1,  2046,
    2047,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,   395,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,   413,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
    1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,
      -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   466,   467,    -1,    -1,
      -1,   471,    -1,    -1,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,    -1,
     500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,
     510,    -1,  1295,   513,   514,    -1,    -1,    -1,    -1,   519,
      -1,   180,    -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,    -1,   557,   558,    -1,
      -1,    -1,    -1,    -1,   564,   565,   566,     6,    -1,    -1,
      -1,    -1,   572,   573,    -1,   575,   576,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,    -1,   252,   594,   595,   596,    -1,    -1,    -1,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   268,
      -1,    -1,    -1,   613,    -1,   615,    -1,   617,    -1,    -1,
      -1,   621,   622,   623,   624,    -1,   626,   627,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   653,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,    -1,    -1,
      -1,    -1,    -1,    -1,   674,    -1,   676,   336,    -1,   679,
     680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   688,    -1,
      -1,    -1,    -1,    -1,   694,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,
     710,   711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   724,    -1,   726,   727,    -1,    -1,
     730,   731,    -1,    -1,    -1,   735,   395,    -1,    -1,    -1,
      -1,    -1,   742,    -1,    -1,    -1,   746,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,   768,   236,
     770,    -1,   772,    -1,   241,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,   804,    -1,  1589,  1590,   467,    -1,
      -1,    -1,    -1,    -1,   814,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   849,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,    -1,   862,    -1,    -1,   524,    -1,    -1,    -1,   869,
      -1,    -1,    -1,   873,    -1,    -1,    -1,    -1,    -1,   879,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   887,   888,    -1,
      -1,   550,    -1,   893,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,
      -1,    -1,   912,    -1,    -1,    -1,   575,   576,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   932,    -1,   934,   935,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   953,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,   622,   623,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,   976,    -1,    -1,    -1,
      -1,    -1,    -1,   983,   984,   985,   986,    -1,    -1,    -1,
      -1,   991,    -1,    -1,    -1,  1778,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1005,  1006,    -1,   667,    -1,
    1010,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,   704,    -1,    -1,    -1,    -1,
    1833,  1834,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,
    1060,    -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,  1852,
      -1,   730,    -1,    -1,    -1,    -1,  1076,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1867,    -1,  1086,  1087,  1088,    -1,
      -1,    -1,   124,  1093,  1094,    -1,  1096,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1108,  1109,
      -1,   770,    -1,   772,    -1,    -1,  1116,  1117,    -1,    -1,
      -1,    -1,    -1,  1123,    -1,  1125,  1126,    -1,    -1,    -1,
      -1,    -1,  1132,  1133,    -1,    -1,    -1,  1137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   804,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,  1168,    -1,
     202,    -1,    -1,    -1,   206,    -1,   208,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     849,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1201,    -1,   862,    -1,    -1,   238,    -1,   240,   241,
      -1,    -1,    -1,  1213,  1997,  1998,  1999,  2000,  2001,    -1,
     879,  1221,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,  1242,  1243,   236,    -1,   238,  1247,   240,    -1,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,  1261,    -1,    -1,  1264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2056,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,  1291,    -1,    -1,  1294,  1295,  1296,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1304,    -1,  1306,    -1,  1308,  1309,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,   417,    -1,
      -1,  1010,    -1,    -1,    -1,    84,    -1,    -1,    87,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,  1382,    -1,    -1,    -1,    -1,    -1,    -1,  1389,
    1390,  1391,    -1,    -1,    -1,   124,    -1,    -1,  1398,    -1,
    1400,  1060,    -1,    -1,    -1,    -1,    -1,  1407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1420,    -1,    -1,    -1,    -1,  1425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1433,  1434,  1435,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,  1445,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1455,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,  1137,   208,
     209,  1481,    -1,    -1,    -1,    -1,    -1,  1487,  1488,    -1,
      -1,    -1,   561,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,   241,    -1,    -1,   236,    -1,    -1,    -1,  1519,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1213,  1555,  1556,  1557,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1566,    -1,    -1,    -1,
      -1,  1571,  1572,  1573,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1584,    -1,    -1,    -1,    -1,  1589,
    1590,  1591,    -1,  1593,    -1,    -1,    -1,    -1,    -1,  1599,
    1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1618,    -1,
      -1,    -1,  1622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1635,  1295,    -1,  1638,    -1,
      -1,    -1,  1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1651,  1652,    -1,  1654,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1678,    -1,
      -1,    -1,    -1,  1683,  1684,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,  1699,
    1700,    -1,     6,    -1,    -1,    -1,    -1,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   786,    -1,   788,
     789,   790,   791,    -1,   793,   794,   795,   796,    -1,    -1,
       6,  1731,    -1,    -1,    -1,    -1,    -1,    -1,   807,    -1,
     809,    -1,    -1,    -1,    -1,    -1,    -1,  1747,   817,    -1,
      -1,    -1,    -1,    -1,   823,   824,  1756,    -1,    -1,    -1,
      -1,  1420,    -1,   832,    -1,  1765,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1774,  1775,    -1,    -1,  1778,    -1,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,     6,    -1,    -1,    -1,    -1,
      -1,    -1,  1812,  1813,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1830,    -1,    -1,  1833,  1834,  1835,    -1,    -1,    -1,    -1,
    1840,    -1,    -1,  1843,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1519,    -1,    -1,    -1,    -1,    -1,    -1,  1867,    -1,    -1,
     939,   940,   941,    -1,    -1,  1875,   945,   946,    -1,     6,
     949,   950,   951,   952,    -1,   954,    -1,    -1,    -1,    -1,
     959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1900,    -1,    -1,    -1,    -1,    -1,  1906,    -1,    -1,  1909,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
    1589,  1590,   236,    -1,    -1,    -1,    -1,  1937,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,  1618,
     236,    -1,  1962,  1963,    21,    22,    -1,    -1,    -1,  1038,
    1039,    -1,    -1,    -1,    -1,    -1,  1976,  1977,    -1,  1979,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1992,    -1,    -1,    -1,    -1,  1997,  1998,  1999,
    2000,  2001,     6,    -1,    -1,    -1,    -1,  2007,    -1,    -1,
      -1,  2011,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,     6,   236,    -1,    -1,  2038,    -1,
      -1,    -1,    -1,  2043,  2044,  2045,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2056,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2084,  2085,  2086,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,  1765,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1778,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,   222,   223,    -1,    -1,    -1,
      -1,    -1,   229,   230,  1833,  1834,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1852,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,  1867,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1310,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,  1338,
    1339,  1340,  1341,  1342,    -1,    -1,    -1,    -1,  1347,  1348,
      -1,    -1,  1351,    -1,  1353,    -1,    -1,    -1,  1357,    -1,
      -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,   355,   356,
     357,    -1,    -1,  1372,   361,   362,   363,   364,   365,   366,
     367,    -1,   369,    -1,    -1,    -1,   373,   374,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,  1997,  1998,
    1999,  2000,  2001,    13,    14,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
      -1,    -1,  1441,    -1,  1443,    -1,    -1,   246,  1447,    -1,
    1449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2056,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1483,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,
       7,   121,   122,    -1,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,   167,   168,   169,
      -1,    10,    11,    12,    -1,  1574,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     8,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,     7,
       8,    -1,   242,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,  1674,    -1,    -1,  1677,   118,
      -1,   120,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1720,  1721,    -1,  1723,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,   190,   191,   192,   193,   194,   195,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,   208,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1782,  1783,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,   241,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,  1828,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
     827,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,     3,     4,     5,   861,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    -1,    87,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
     122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,     8,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,   146,    -1,    -1,   149,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,  1032,   242,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,   193,   194,   195,    -1,    -1,  2065,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,   208,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,   241,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,  1121,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    13,    14,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,    -1,    -1,   112,    -1,    -1,  1274,  1275,    -1,
     118,   119,    -1,   121,   122,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,   194,   143,    -1,    -1,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,     8,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,
      -1,    -1,   232,    -1,   234,   235,    -1,   237,    -1,   239,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,  1355,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,  1365,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1518,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   237,     3,     4,    -1,
     241,    -1,     8,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,   190,   124,   125,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   167,   168,
     169,   237,     3,     4,     5,    -1,   242,    -1,   244,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,   190,
     124,   125,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,   167,   168,   169,   237,     3,     4,    -1,
     241,    -1,    -1,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,   190,   124,   125,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   167,   168,
     169,   237,     3,     4,    -1,   241,   242,    -1,   244,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,   190,
     124,   125,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,   167,   168,   169,   237,     3,     4,    -1,
     241,    -1,    -1,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,   190,   124,   125,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   167,   168,
     169,   237,     3,     4,    -1,   241,    -1,    -1,   244,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,   190,
     124,   125,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,   167,   168,   169,   237,     3,     4,    -1,
     241,    -1,    -1,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,   190,   124,   125,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   167,   168,
     169,   237,     3,     4,    -1,    -1,   242,    -1,   244,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,   190,
     124,   125,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,   167,   168,   169,   237,     3,     4,    -1,
     241,    -1,    -1,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,   190,   124,   125,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   167,   168,
     169,   237,     3,     4,    -1,   241,    -1,    -1,   244,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    75,    76,    77,    -1,    -1,    13,
      14,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,   112,     8,
      -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,   190,
     124,   125,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,   167,   168,   169,   237,     3,     4,    -1,
     241,    -1,     8,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,     3,     4,    -1,
      -1,   237,     8,    -1,    10,    11,    12,    -1,   244,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,     3,     4,    -1,
      -1,   237,    -1,    -1,    10,    11,    12,    -1,   244,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    13,    14,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,   112,     8,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,   190,   124,   125,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   167,   168,
     169,   237,     3,     4,    -1,   241,    -1,    -1,   244,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   237,     3,     4,    -1,
     241,    -1,    -1,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
      -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,     3,     4,     5,
      -1,   237,    -1,    -1,    10,    11,    12,    -1,   244,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,   241,    -1,    -1,   244,    -1,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,   194,   246,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   237,     3,     4,     5,
     241,    -1,    -1,   244,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,   241,    -1,    -1,   244,    -1,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,   194,   246,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,     3,     4,    -1,    -1,   237,    -1,    -1,    10,
      11,    12,    -1,   244,    15,    16,    17,    18,    19,    20,
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
      85,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   190,
     242,    -1,    -1,   194,   246,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
     241,    -1,    -1,   244,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,   190,    -1,   236,    -1,   194,
      -1,    -1,    -1,    -1,   199,   200,   201,   246,   203,   204,
     205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   237,     3,     4,    -1,   241,    -1,     8,   244,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,     3,
       4,    -1,    82,    83,    -1,    85,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,   194,   246,    -1,    -1,    -1,   199,
     200,   201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,   190,    -1,   236,    -1,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,   246,   203,
     204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,     3,
       4,    -1,     6,   237,   238,    -1,    10,    11,    12,    -1,
     244,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,    82,    83,    -1,    85,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,   190,    -1,   236,    -1,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,   246,   203,
     204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   246,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,     3,     4,    -1,     6,   237,    -1,    -1,    10,
      11,    12,    -1,   244,    15,    16,    17,    18,    19,    20,
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
      85,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   246,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,   190,    -1,   236,    -1,   194,
      -1,    -1,    -1,    -1,   199,   200,   201,   246,   203,   204,
     205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,     3,     4,
      -1,    -1,   237,   238,    -1,    10,    11,    12,    -1,   244,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,     3,     4,    -1,    82,    83,    -1,
      85,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,
     246,    -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,
     205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,    -1,   203,   204,   205,    -1,    -1,    -1,
     209,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,    64,    65,    66,    -1,   237,    -1,
      70,    71,    -1,    73,    -1,   244,    -1,    -1,    78,    -1,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,   105,   106,   107,   108,   109,
     110,    -1,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,     4,    -1,   155,   156,   157,    -1,    -1,
      -1,   161,    13,    14,    -1,    -1,   166,   167,   168,   169,
      -1,    -1,   172,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    44,    45,    -1,   196,   197,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   209,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    -1,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,   105,   106,   107,   108,   109,   110,
      -1,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,     4,
       5,   172,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,   198,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   209,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    84,
       4,     5,    87,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
       5,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      84,    -1,    -1,    87,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,    84,
      -1,    -1,    87,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,   206,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,   192,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
     206,    -1,   208,   209,    -1,    -1,    -1,    13,    14,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,    -1,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,   206,    -1,   208,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,   118,   119,    -1,   121,   122,    -1,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   167,   168,   169,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,
     122,    -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,   242,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,   242,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,   242,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,   242,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
     242,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,   242,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,   242,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,   242,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,   242,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
     242,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,   242,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,   242,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,   242,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,   242,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
     242,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,   241,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,   241,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,    -1,
     240,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,   240,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,   240,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,   240,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   240,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,   240,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,   240,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   240,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,   240,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,   240,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
     240,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,   240,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,   240,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,   240,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   240,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,   240,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     238,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   248,   249,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    80,    81,
      83,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   105,   106,   107,   108,
     109,   110,   112,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   155,
     156,   157,   161,   166,   167,   168,   169,   172,   174,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   196,   197,   198,   207,   209,   250,   252,
     253,   273,   291,   293,   297,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   315,   317,   318,   324,   325,   326,
     327,   333,   358,   359,   241,   245,    14,    96,   237,   237,
       6,   241,     6,     6,     6,     6,   237,     6,   239,   239,
       4,   335,   359,   237,   239,   271,   271,   237,   237,   237,
       4,   237,   237,   237,     4,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   241,   111,    96,     6,
     241,    90,    93,    96,   109,   296,   237,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    64,    75,    76,    77,    82,
      85,    90,    93,    96,    98,   109,   118,   122,   124,   190,
     194,   195,   199,   200,   201,   203,   204,   205,   225,   226,
     232,   237,   241,   244,   293,   294,   297,   308,   315,   317,
     328,   329,   333,   335,   342,   344,   359,   237,   241,    96,
      96,   118,    93,    96,    98,    90,    93,    96,    98,   293,
      93,    96,    98,   109,   294,    93,    96,   237,    93,   147,
     172,   188,   189,   241,   225,   226,   237,   241,   339,   340,
     339,   241,   241,   339,     4,    90,    94,   100,   101,   103,
     104,   121,   237,    96,    98,    96,    93,     4,    83,   183,
     241,   359,     4,     6,    90,    93,    96,    93,    96,   109,
     295,     4,     4,     4,     5,   237,   241,   342,   343,     4,
     237,   237,   237,     4,   241,   346,   359,     4,   237,   237,
     237,     6,     6,   239,     5,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    61,    62,    67,    68,
      69,    72,    74,    84,    87,   191,   192,   193,   202,   206,
     208,   350,   359,   237,     4,   350,     5,   241,     5,   241,
      32,   226,   328,   359,   239,   241,   237,   241,     6,   237,
     241,     6,   245,     7,   124,   183,   210,   211,   212,   213,
     234,   235,   237,   239,   243,   269,   270,   271,   328,   349,
     350,   359,     4,   297,   298,   299,   241,     6,   328,   349,
     350,   359,   349,   328,   349,   356,   357,   359,   275,   279,
     237,   338,     9,   350,   359,   328,   328,   328,   237,   328,
     328,   328,   237,   328,   328,   328,   328,   328,   328,   328,
     349,   328,   328,   328,   328,   343,   237,   226,   328,   344,
     345,   241,   343,   349,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   237,   239,   271,
     271,   271,   271,   271,   271,   237,   271,   271,   237,   293,
     271,   271,     5,   241,   241,   118,   293,   237,   271,   271,
     237,   237,   237,   328,   241,   328,   344,   328,   328,   242,
     345,   335,   359,   175,     5,   241,     8,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   236,     9,   237,   239,   243,
     270,   271,   328,   345,   237,   237,   237,   342,   343,   343,
     343,   292,   241,   237,   342,   241,   241,   328,     4,   342,
     241,   346,   241,   241,   339,   339,   339,   328,   328,   225,
     226,   241,   241,   339,   225,   226,   237,   299,   339,   241,
     237,   241,   237,   237,   237,   237,   237,   237,   237,   328,
     343,   343,   343,   237,     4,   239,     6,   239,   299,     6,
       6,   241,   241,   241,   241,   343,   239,   239,   239,   328,
       8,     6,     6,   328,   328,   328,   243,   328,   241,   175,
     328,   328,   328,   328,   271,   271,   271,   237,   237,   237,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     237,   237,   271,   237,   239,     6,     6,   241,     6,     8,
     299,     6,     8,   299,   271,   328,   227,   241,     9,   237,
     239,   243,   349,   345,   328,   299,   342,   342,   241,   350,
      90,    93,    96,    98,     7,   328,   328,     4,   172,   173,
     342,     6,   238,   240,   241,   272,     6,   241,     6,     9,
     237,   239,   243,   359,   242,   118,   122,   124,   125,   291,
     293,   328,     6,   238,   246,     9,   237,   239,   243,   238,
     246,   246,   238,   246,     9,   237,   243,   240,   246,   274,
     240,   274,    86,   337,   334,   359,   246,   246,   238,   238,
     238,   328,   238,   238,   238,   328,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   242,     7,   328,
     227,   242,   246,   328,     6,   238,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   344,   328,   328,   328,   328,   328,   328,
     328,   344,   344,   359,   241,   328,   328,   349,   328,   349,
     342,   349,   349,   356,   241,   328,   272,   359,     8,   328,
     328,   343,   349,   349,   344,   335,   350,   335,   345,   238,
     242,   243,   271,    64,     8,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   241,
     328,   344,   328,   328,   328,   328,   328,   359,   328,   328,
       4,   336,   241,   272,   238,   242,   328,   328,   328,     7,
       7,   321,   321,   237,   328,   328,     6,   345,   345,   241,
     238,     6,   299,   241,   299,   299,   246,   246,   246,   339,
     339,   298,   298,   246,   328,   242,   312,   246,   299,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   238,     7,
     322,     6,     7,   328,     6,   328,   328,   242,   345,   345,
     345,   328,     6,   328,   328,   328,   238,   242,   238,   238,
     238,   172,   246,   299,   241,     8,   238,   238,   240,   356,
     349,   356,   349,   349,   349,   349,   349,   349,   328,   349,
     349,   349,   349,   244,   352,   359,   350,   349,   349,   349,
     335,   359,   345,   242,   242,   242,   242,   328,   328,   299,
     359,   336,   240,   242,   238,   130,   147,   316,   238,   242,
     246,   328,     6,   241,   241,   241,   241,   328,   238,   240,
       7,   269,   270,   243,     7,     6,   345,     7,   213,   269,
     254,   359,   328,   328,   336,   239,   237,   118,   293,   294,
     241,   242,     6,   220,   221,   251,   345,   359,   328,   328,
       4,   336,     6,   345,   328,     6,   349,   357,   359,   238,
     336,     6,   359,     6,   349,   328,   238,   239,   328,   350,
       7,     7,     7,   238,     7,     7,     7,   238,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   328,   238,
     241,   328,   344,   242,     6,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   246,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   246,   246,   246,   238,
     240,   240,   345,   246,   246,   272,   246,   272,   246,   246,
     246,   238,   328,   330,   272,   242,   242,   242,   246,   246,
     272,   272,   238,   243,   238,   243,   246,   271,   331,   242,
       7,   336,   272,   241,   242,     8,     8,   345,   243,   238,
     240,   270,   237,   239,   271,   345,     7,   241,   238,   238,
     238,   328,   342,     4,   320,     6,   288,   328,   350,   242,
     238,   242,   242,   345,   243,   242,   299,   242,   242,   339,
     328,   328,   242,   242,   328,   339,   127,   127,   144,   152,
     153,   154,   158,   159,   313,   314,   339,   242,   309,   238,
     242,   238,   238,   238,   238,   238,   238,   238,     7,   328,
       6,   328,   238,   240,   240,   242,   242,   242,   242,   240,
     240,   246,     7,     7,     7,   243,   328,   242,   328,   328,
       7,   243,   272,   246,   272,   272,   238,   238,   246,   272,
     272,   246,   246,   272,   272,   272,   272,   328,   272,     9,
     351,   246,   238,   246,   272,   243,   246,   332,   240,   242,
     242,   243,   237,   239,   245,   175,     7,   147,     6,   328,
     242,   241,     6,   342,   242,   328,   328,   328,   328,     6,
       7,   269,   270,   243,   269,   270,   350,   328,     6,     4,
     241,   347,   359,   242,    46,    46,   342,     4,   162,   163,
     164,   165,   242,   257,   261,   264,   266,   267,   243,   238,
     240,   237,   328,   328,   237,   241,   237,     8,   345,   349,
     238,   243,   238,   240,   237,   238,   246,   243,   237,     7,
     271,     4,   282,   283,   284,   272,   272,   339,   342,   342,
       7,   342,   342,   342,     7,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,     6,     7,   345,   328,   328,
     328,   328,   242,   328,   328,   328,   342,   349,   349,   242,
     246,   281,   328,   328,   336,   336,   328,   328,   238,   342,
     271,   328,   328,   328,   242,   336,   270,   243,   270,   328,
     328,   272,   242,   342,   345,     7,     7,     7,   127,   319,
       6,   238,   246,     7,     7,     7,   242,     4,   242,   246,
     246,   246,   242,   242,   108,     4,     6,   328,   241,     6,
     237,     6,   160,     6,   160,   242,   314,   246,   313,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   342,     6,
     241,     6,     6,     6,    96,     7,     6,     6,   328,   342,
     342,   342,     4,   246,     8,     8,   238,     4,    99,   100,
       4,   345,   349,   328,   349,   244,   246,   285,   349,   349,
     336,   349,   238,   246,   336,   241,   293,   241,     6,   328,
       6,   241,   342,   242,   242,   242,   242,   242,   328,     6,
       4,   172,   173,   328,     6,     6,     6,     7,   346,   348,
       6,   239,   272,   271,   271,     6,   258,   237,   237,   241,
     268,     6,   336,   243,   349,   328,   240,   238,   328,     8,
     345,   328,   242,   242,     6,     6,   251,   336,   243,   328,
       6,   328,   336,   238,   241,   328,   350,   272,    46,   241,
     342,   350,   353,   240,   246,     6,     6,     6,   121,   290,
     290,   342,     6,     6,     6,   342,   127,   175,   289,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     5,   242,
     272,   272,   272,   272,   272,   246,   246,   246,   238,   272,
     272,   283,   272,   238,   272,   238,   271,   331,   272,     6,
     272,   246,   237,   239,   271,     4,   238,   240,   272,     6,
     242,   342,   342,   342,     4,     6,   269,   328,   342,   241,
     241,     7,     6,     7,   328,   328,   328,   241,   241,   241,
     239,     6,   328,   342,   328,     6,     6,   328,   339,   242,
       5,   342,   241,   241,   241,   241,   241,   241,   241,   342,
       6,   345,   241,   328,   240,     6,     6,   171,   328,   328,
     328,     6,     6,     6,     6,     7,   272,   246,   246,   272,
     246,   328,     4,   187,   286,   287,   272,   238,   272,   332,
     350,   237,   239,   328,   241,   299,     6,   299,   246,     6,
       6,     7,   269,   270,   243,     7,     6,   346,   242,   246,
     328,   269,   241,   272,   354,   355,   356,   354,   237,   328,
     328,   341,   342,   241,   237,     4,     6,   238,     6,   238,
     242,   242,   238,     6,     6,   349,   237,     4,   238,   246,
     237,   342,   350,     7,   271,   280,   328,   344,   284,   339,
       6,     6,     6,     6,    90,   109,    94,     6,     5,   241,
     328,   328,   328,   328,   238,   331,   328,   328,   328,   272,
     270,   241,     6,   289,     6,   328,   342,     4,     6,   345,
     345,   328,   328,   350,   242,   238,   242,   246,   298,   298,
     328,   328,   242,   246,   238,   242,   246,     6,     6,   341,
     339,   339,   339,   339,   339,   226,   339,     6,   242,   328,
       6,     6,   342,   242,   246,     8,   242,   238,   241,   328,
     350,   349,   328,   349,   328,   350,   353,   355,   350,   246,
     238,   246,   242,   328,   316,   316,   342,   350,   328,     6,
       4,   347,     6,   346,   240,   342,   356,     6,   272,   272,
     255,   328,   246,   246,   242,   246,   256,   328,   328,     6,
       6,     6,   328,   328,   238,   276,   278,   241,   355,   242,
     246,     7,     7,   241,   241,   241,     5,   341,   272,   272,
     246,   272,   238,   246,   238,   240,   328,     6,     6,   241,
     242,   242,   241,     6,     6,   241,   328,   242,   242,   242,
     240,     6,   342,     7,   241,   328,   242,   246,   246,   246,
     246,   246,   246,     6,   242,   170,   328,   328,   345,     6,
       6,   238,   272,   272,   287,   350,   242,   242,   242,   242,
       6,     6,     7,     6,   243,     6,   242,     6,     6,   238,
     246,   328,   328,   241,   342,   242,   246,   238,   238,   246,
     281,   285,   342,   272,   328,   350,   359,   345,   345,   328,
       6,   242,   328,   331,   328,   242,   341,   131,   132,   137,
     323,   131,   132,   323,   345,   298,   242,   246,     6,   242,
     342,   299,   242,     6,   345,   339,   339,   339,   339,   339,
     328,   242,   242,   242,   238,     6,   241,     6,   346,   173,
     259,   328,   246,   246,   341,     6,   328,   328,   242,   242,
     277,     7,   237,   242,   242,   242,   241,   246,   238,   246,
     242,   241,   339,   342,     6,   241,   339,     6,   242,   242,
     328,     6,   127,   242,   310,   241,   242,   246,   246,   246,
     246,   246,     6,     6,     6,   299,     6,   241,   328,   328,
     242,   246,   281,   350,   238,   328,   328,   328,     6,   339,
       6,   339,     6,     6,   242,   328,   313,   299,     6,   345,
     345,   345,   345,   339,   345,   316,   256,   238,   246,     6,
     241,   328,   242,   246,   246,   246,   246,   246,     6,   242,
     242,   311,   242,   242,   242,   242,   246,   242,   242,   242,
     262,   328,   341,   242,   328,   328,   328,   339,   339,   313,
       6,     6,     6,     6,   345,     6,     6,     6,   241,   238,
     242,     6,   242,   272,   246,   246,   246,   242,   242,   260,
     349,   265,   241,     6,   328,   328,   328,     6,   242,   246,
     241,   341,   242,   242,   242,     6,   349,   263,   349,   242,
       6,     6,   242,   246,     6,     6,   349
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
      (yyval.l) = 0;
    ;}
    break;

  case 152:
#line 1553 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      int p = (int)(yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 153:
#line 1559 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 154:
#line 1563 "Gmsh.y"
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
#line 1574 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 156:
#line 1578 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 157:
#line 1585 "Gmsh.y"
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
#line 1608 "Gmsh.y"
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
#line 1624 "Gmsh.y"
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
#line 1640 "Gmsh.y"
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
#line 1677 "Gmsh.y"
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
#line 1717 "Gmsh.y"
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
#line 1733 "Gmsh.y"
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
#line 1750 "Gmsh.y"
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
#line 1781 "Gmsh.y"
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
#line 1797 "Gmsh.y"
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
#line 1816 "Gmsh.y"
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
#line 1832 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE face filling requires a single line loop");
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
        int sphereCenter = 0;
        if(List_Nbr((yyvsp[(7) - (8)].l)) == 1){
          double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
          sphereCenter = (int)d;
        }
        r = GModel::current()->getGEOInternals()->addSurfaceFilling
          (num, wires, sphereCenter);
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 169:
#line 1881 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      int sphereCenter = 0;
      if(List_Nbr((yyvsp[(7) - (9)].l)) == 1){
        double d; List_Read((yyvsp[(7) - (9)].l), 0, &d);
        sphereCenter = (int)d;
      }
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling
        (num, wires, sphereCenter);
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 170:
#line 1898 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 171:
#line 1904 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 172:
#line 1910 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1917 "Gmsh.y"
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
#line 1948 "Gmsh.y"
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
#line 1963 "Gmsh.y"
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
#line 1985 "Gmsh.y"
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
#line 2008 "Gmsh.y"
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
#line 2031 "Gmsh.y"
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
#line 2054 "Gmsh.y"
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
#line 2078 "Gmsh.y"
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
#line 2102 "Gmsh.y"
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
#line 2126 "Gmsh.y"
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
#line 2152 "Gmsh.y"
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
#line 2169 "Gmsh.y"
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
#line 2185 "Gmsh.y"
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
#line 2203 "Gmsh.y"
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
#line 2221 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (8)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2229 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (12)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2236 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 190:
#line 2240 "Gmsh.y"
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
#line 2266 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 192:
#line 2268 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 193:
#line 2270 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 194:
#line 2272 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 195:
#line 2274 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 196:
#line 2282 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 197:
#line 2284 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 198:
#line 2286 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 199:
#line 2288 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 200:
#line 2296 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 201:
#line 2298 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 202:
#line 2300 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 203:
#line 2308 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2310 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2312 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2314 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 207:
#line 2324 "Gmsh.y"
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
#line 2340 "Gmsh.y"
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
#line 2356 "Gmsh.y"
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
#line 2372 "Gmsh.y"
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
#line 2388 "Gmsh.y"
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
#line 2404 "Gmsh.y"
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
#line 2441 "Gmsh.y"
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
#line 2463 "Gmsh.y"
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
#line 2486 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2487 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 217:
#line 2492 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 218:
#line 2496 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 219:
#line 2500 "Gmsh.y"
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
#line 2516 "Gmsh.y"
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
#line 2534 "Gmsh.y"
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
#line 2552 "Gmsh.y"
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
#line 2577 "Gmsh.y"
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
#line 2596 "Gmsh.y"
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
#line 2618 "Gmsh.y"
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
#line 2633 "Gmsh.y"
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
#line 2648 "Gmsh.y"
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
#line 2667 "Gmsh.y"
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
#line 2718 "Gmsh.y"
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
#line 2739 "Gmsh.y"
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
#line 2761 "Gmsh.y"
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
#line 2783 "Gmsh.y"
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
#line 2888 "Gmsh.y"
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
#line 2904 "Gmsh.y"
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
#line 2939 "Gmsh.y"
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
#line 2961 "Gmsh.y"
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
#line 2983 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 238:
#line 2989 "Gmsh.y"
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
#line 3004 "Gmsh.y"
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
#line 3032 "Gmsh.y"
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
#line 3044 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 242:
#line 3053 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 243:
#line 3060 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 244:
#line 3072 "Gmsh.y"
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
#line 3091 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 246:
#line 3095 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 247:
#line 3100 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 248:
#line 3104 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3109 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 250:
#line 3116 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 3123 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 252:
#line 3130 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 253:
#line 3142 "Gmsh.y"
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
#line 3215 "Gmsh.y"
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
#line 3233 "Gmsh.y"
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
#line 3250 "Gmsh.y"
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
#line 3265 "Gmsh.y"
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
#line 3298 "Gmsh.y"
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
#line 3310 "Gmsh.y"
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
#line 3334 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 261:
#line 3338 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 262:
#line 3343 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 263:
#line 3350 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 264:
#line 3355 "Gmsh.y"
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
#line 3365 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 266:
#line 3370 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 267:
#line 3376 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 268:
#line 3384 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 269:
#line 3388 "Gmsh.y"
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
#line 3398 "Gmsh.y"
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
#line 3461 "Gmsh.y"
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
#line 3477 "Gmsh.y"
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
#line 3494 "Gmsh.y"
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
#line 3511 "Gmsh.y"
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
#line 3533 "Gmsh.y"
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
#line 3555 "Gmsh.y"
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
#line 3590 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 278:
#line 3598 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3606 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 280:
#line 3612 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 281:
#line 3619 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3626 "Gmsh.y"
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
#line 3646 "Gmsh.y"
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
#line 3672 "Gmsh.y"
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
#line 3684 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 286:
#line 3695 "Gmsh.y"
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
#line 3713 "Gmsh.y"
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
#line 3731 "Gmsh.y"
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
#line 3749 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3755 "Gmsh.y"
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
#line 3773 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3779 "Gmsh.y"
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
#line 3799 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3805 "Gmsh.y"
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
#line 3823 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3829 "Gmsh.y"
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
#line 3846 "Gmsh.y"
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
#line 3862 "Gmsh.y"
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
#line 3879 "Gmsh.y"
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
#line 3896 "Gmsh.y"
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
#line 3919 "Gmsh.y"
    {
    ;}
    break;

  case 302:
#line 3922 "Gmsh.y"
    {
    ;}
    break;

  case 303:
#line 3928 "Gmsh.y"
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
#line 3940 "Gmsh.y"
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
#line 3960 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 306:
#line 3964 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 307:
#line 3968 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 308:
#line 3972 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 309:
#line 3976 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 310:
#line 3980 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 311:
#line 3984 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 312:
#line 3988 "Gmsh.y"
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
#line 3997 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 314:
#line 4009 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 315:
#line 4010 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 316:
#line 4011 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 317:
#line 4012 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 318:
#line 4013 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 319:
#line 4017 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 320:
#line 4018 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 321:
#line 4019 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 322:
#line 4020 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 323:
#line 4021 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 324:
#line 4026 "Gmsh.y"
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
#line 4049 "Gmsh.y"
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
#line 4069 "Gmsh.y"
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
#line 4090 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 328:
#line 4094 "Gmsh.y"
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
#line 4109 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 330:
#line 4113 "Gmsh.y"
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
#line 4129 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 332:
#line 4133 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 333:
#line 4138 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 334:
#line 4142 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 335:
#line 4148 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 336:
#line 4152 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 337:
#line 4159 "Gmsh.y"
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
#line 4181 "Gmsh.y"
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
#line 4222 "Gmsh.y"
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

  case 340:
#line 4266 "Gmsh.y"
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

  case 341:
#line 4305 "Gmsh.y"
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
#line 4330 "Gmsh.y"
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
#line 4339 "Gmsh.y"
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
#line 4369 "Gmsh.y"
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
#line 4395 "Gmsh.y"
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
#line 4422 "Gmsh.y"
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
#line 4454 "Gmsh.y"
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

  case 348:
#line 4481 "Gmsh.y"
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

  case 349:
#line 4507 "Gmsh.y"
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

  case 350:
#line 4533 "Gmsh.y"
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

  case 351:
#line 4559 "Gmsh.y"
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

  case 352:
#line 4585 "Gmsh.y"
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

  case 353:
#line 4606 "Gmsh.y"
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
#line 4617 "Gmsh.y"
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
#line 4665 "Gmsh.y"
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

  case 356:
#line 4714 "Gmsh.y"
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

  case 357:
#line 4726 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 358:
#line 4737 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 359:
#line 4744 "Gmsh.y"
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

  case 360:
#line 4759 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 361:
#line 4772 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 362:
#line 4773 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 363:
#line 4774 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 364:
#line 4779 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 365:
#line 4785 "Gmsh.y"
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

  case 366:
#line 4797 "Gmsh.y"
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

  case 367:
#line 4815 "Gmsh.y"
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

  case 368:
#line 4842 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 369:
#line 4843 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 370:
#line 4844 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 371:
#line 4845 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 372:
#line 4846 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 373:
#line 4847 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4848 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4849 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 376:
#line 4851 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 377:
#line 4857 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 378:
#line 4858 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 379:
#line 4859 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 380:
#line 4860 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 381:
#line 4861 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4862 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 4863 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4864 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4865 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4866 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4867 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 388:
#line 4868 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 4869 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 390:
#line 4870 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 391:
#line 4871 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 392:
#line 4872 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 393:
#line 4873 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 394:
#line 4874 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 395:
#line 4875 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 396:
#line 4876 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 397:
#line 4877 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 398:
#line 4878 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 399:
#line 4879 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 400:
#line 4880 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 401:
#line 4881 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 402:
#line 4882 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 403:
#line 4883 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4884 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4885 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4886 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 4887 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 408:
#line 4888 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 409:
#line 4889 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 4890 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 411:
#line 4891 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 412:
#line 4892 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 413:
#line 4893 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 414:
#line 4894 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 415:
#line 4903 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 416:
#line 4904 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 417:
#line 4905 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 418:
#line 4906 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 419:
#line 4907 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 420:
#line 4908 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 421:
#line 4909 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 422:
#line 4910 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 423:
#line 4911 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 424:
#line 4912 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 425:
#line 4913 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 426:
#line 4918 "Gmsh.y"
    { init_options(); ;}
    break;

  case 427:
#line 4920 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 428:
#line 4926 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 429:
#line 4928 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 430:
#line 4933 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 431:
#line 4938 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 432:
#line 4943 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 433:
#line 4948 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 434:
#line 4952 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 435:
#line 4956 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 436:
#line 4960 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 437:
#line 4964 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 438:
#line 4968 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 439:
#line 4972 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 440:
#line 4976 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 441:
#line 4982 "Gmsh.y"
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

  case 442:
#line 4998 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 443:
#line 5003 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 444:
#line 5009 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 445:
#line 5015 "Gmsh.y"
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

  case 446:
#line 5034 "Gmsh.y"
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

  case 447:
#line 5055 "Gmsh.y"
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
#line 5088 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 449:
#line 5092 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 450:
#line 5097 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 451:
#line 5101 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 452:
#line 5105 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 453:
#line 5109 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 454:
#line 5114 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 455:
#line 5119 "Gmsh.y"
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

  case 456:
#line 5129 "Gmsh.y"
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

  case 457:
#line 5139 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 458:
#line 5144 "Gmsh.y"
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

  case 459:
#line 5155 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 460:
#line 5164 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 461:
#line 5169 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 462:
#line 5174 "Gmsh.y"
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

  case 463:
#line 5201 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 464:
#line 5203 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 465:
#line 5208 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 466:
#line 5210 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 467:
#line 5215 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 468:
#line 5222 "Gmsh.y"
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

  case 469:
#line 5238 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 470:
#line 5240 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 471:
#line 5245 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 472:
#line 5254 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 473:
#line 5256 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 474:
#line 5261 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 475:
#line 5263 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 476:
#line 5268 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 477:
#line 5272 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 478:
#line 5276 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 479:
#line 5280 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 480:
#line 5284 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 481:
#line 5291 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 482:
#line 5295 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 483:
#line 5299 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 484:
#line 5303 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 485:
#line 5310 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 486:
#line 5315 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 487:
#line 5322 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 488:
#line 5327 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 489:
#line 5331 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 490:
#line 5336 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 491:
#line 5340 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 492:
#line 5348 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 493:
#line 5359 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 494:
#line 5363 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 495:
#line 5367 "Gmsh.y"
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

  case 496:
#line 5381 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 497:
#line 5389 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 498:
#line 5397 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 499:
#line 5404 "Gmsh.y"
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

  case 500:
#line 5414 "Gmsh.y"
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

  case 501:
#line 5437 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 502:
#line 5442 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 503:
#line 5448 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 504:
#line 5453 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 505:
#line 5459 "Gmsh.y"
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

  case 506:
#line 5471 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 507:
#line 5476 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 508:
#line 5481 "Gmsh.y"
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
#line 5491 "Gmsh.y"
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
#line 5501 "Gmsh.y"
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
#line 5511 "Gmsh.y"
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

  case 512:
#line 5523 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 513:
#line 5527 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 514:
#line 5532 "Gmsh.y"
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

  case 515:
#line 5544 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 516:
#line 5548 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 517:
#line 5552 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 518:
#line 5556 "Gmsh.y"
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

  case 519:
#line 5574 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 520:
#line 5582 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 521:
#line 5590 "Gmsh.y"
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

  case 522:
#line 5619 "Gmsh.y"
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

  case 523:
#line 5629 "Gmsh.y"
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

  case 524:
#line 5645 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 525:
#line 5656 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 526:
#line 5661 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 527:
#line 5665 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 528:
#line 5669 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 529:
#line 5681 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 530:
#line 5685 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 531:
#line 5697 "Gmsh.y"
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

  case 532:
#line 5714 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 533:
#line 5724 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 534:
#line 5728 "Gmsh.y"
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

  case 535:
#line 5743 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 536:
#line 5748 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 537:
#line 5755 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 538:
#line 5759 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 539:
#line 5764 "Gmsh.y"
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

  case 540:
#line 5778 "Gmsh.y"
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
#line 5794 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 542:
#line 5798 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 543:
#line 5802 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 544:
#line 5806 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 545:
#line 5810 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 546:
#line 5818 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 547:
#line 5824 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 548:
#line 5830 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 549:
#line 5836 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 550:
#line 5845 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 551:
#line 5849 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 552:
#line 5853 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 553:
#line 5861 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 554:
#line 5867 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 555:
#line 5873 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 556:
#line 5877 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 557:
#line 5885 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 558:
#line 5893 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 559:
#line 5900 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 560:
#line 5909 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 561:
#line 5913 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 562:
#line 5917 "Gmsh.y"
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

  case 563:
#line 5932 "Gmsh.y"
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

  case 564:
#line 5946 "Gmsh.y"
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

  case 565:
#line 5960 "Gmsh.y"
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

  case 566:
#line 5972 "Gmsh.y"
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

  case 567:
#line 5988 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 568:
#line 5997 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 569:
#line 6006 "Gmsh.y"
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

  case 570:
#line 6016 "Gmsh.y"
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

  case 571:
#line 6027 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 572:
#line 6035 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 573:
#line 6043 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 574:
#line 6047 "Gmsh.y"
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

  case 575:
#line 6066 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6073 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 577:
#line 6079 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 6086 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 579:
#line 6093 "Gmsh.y"
    { init_options(); ;}
    break;

  case 580:
#line 6095 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 581:
#line 6103 "Gmsh.y"
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

  case 582:
#line 6127 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 583:
#line 6129 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 584:
#line 6135 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 585:
#line 6140 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 586:
#line 6142 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 587:
#line 6147 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 588:
#line 6152 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 589:
#line 6157 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 590:
#line 6159 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 591:
#line 6163 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 592:
#line 6175 "Gmsh.y"
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

  case 593:
#line 6189 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 594:
#line 6193 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 595:
#line 6200 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 596:
#line 6208 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 597:
#line 6216 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 598:
#line 6227 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 599:
#line 6229 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 600:
#line 6232 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13738 "Gmsh.tab.cpp"
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


#line 6235 "Gmsh.y"


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

