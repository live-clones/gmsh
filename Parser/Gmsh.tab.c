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
     tBlock = 355,
     tCylinder = 356,
     tCone = 357,
     tTorus = 358,
     tEllipsoid = 359,
     tQuadric = 360,
     tShapeFromFile = 361,
     tRectangle = 362,
     tDisk = 363,
     tWire = 364,
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
#define tBlock 355
#define tCylinder 356
#define tCone 357
#define tTorus 358
#define tEllipsoid 359
#define tQuadric 360
#define tShapeFromFile 361
#define tRectangle 362
#define tDisk 363
#define tWire 364
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
NameSpaces nameSpaces;

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
static std::string factory;
static std::string struct_name, struct_namespace;
static int flag_tSTRING_alloc = 0;

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
int treat_Struct_FullName_dot_tSTRING_Float_getDim
  (char* c1, char* c2, char* c3);
char* treat_Struct_FullName_String
  (char* c1, char* c2, int type_var = 1, int index = 0,
   char* val_default = NULL, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = NULL, int type_treat = 0);

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
#line 159 "Gmsh.y"
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
#line 715 "Gmsh.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 728 "Gmsh.tab.c"

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
#define YYLAST   15296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  588
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2157

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
     473,   483,   489,   497,   507,   517,   529,   537,   547,   557,
     558,   560,   561,   565,   571,   572,   582,   583,   595,   601,
     602,   612,   613,   617,   621,   627,   633,   634,   637,   638,
     640,   642,   646,   649,   651,   656,   659,   660,   663,   665,
     669,   672,   675,   678,   683,   685,   687,   691,   693,   695,
     699,   701,   703,   707,   709,   711,   715,   716,   722,   723,
     726,   734,   742,   750,   759,   768,   776,   784,   796,   805,
     813,   822,   831,   840,   850,   854,   859,   870,   878,   886,
     894,   902,   910,   918,   926,   934,   942,   950,   959,   972,
     981,   989,   997,  1006,  1015,  1024,  1033,  1042,  1051,  1057,
    1069,  1075,  1085,  1095,  1100,  1110,  1120,  1122,  1124,  1125,
    1128,  1135,  1142,  1149,  1156,  1165,  1176,  1191,  1208,  1221,
    1236,  1251,  1266,  1281,  1290,  1299,  1306,  1311,  1317,  1324,
    1331,  1335,  1340,  1344,  1350,  1357,  1363,  1367,  1371,  1376,
    1382,  1387,  1393,  1397,  1403,  1411,  1419,  1423,  1431,  1435,
    1438,  1441,  1444,  1447,  1450,  1466,  1469,  1472,  1475,  1478,
    1481,  1498,  1510,  1517,  1526,  1535,  1546,  1548,  1551,  1554,
    1556,  1560,  1564,  1569,  1574,  1576,  1578,  1584,  1596,  1610,
    1611,  1619,  1620,  1634,  1635,  1651,  1652,  1659,  1669,  1672,
    1676,  1687,  1689,  1692,  1698,  1706,  1709,  1712,  1716,  1719,
    1723,  1726,  1730,  1740,  1747,  1749,  1751,  1753,  1755,  1757,
    1758,  1761,  1765,  1769,  1774,  1784,  1789,  1804,  1805,  1809,
    1810,  1812,  1813,  1816,  1817,  1820,  1821,  1824,  1831,  1839,
    1846,  1852,  1856,  1865,  1871,  1876,  1883,  1895,  1907,  1926,
    1945,  1958,  1971,  1984,  1995,  2006,  2017,  2028,  2039,  2044,
    2049,  2054,  2059,  2064,  2069,  2074,  2079,  2084,  2087,  2091,
    2098,  2100,  2102,  2104,  2107,  2113,  2121,  2132,  2134,  2138,
    2141,  2144,  2147,  2151,  2155,  2159,  2163,  2167,  2171,  2175,
    2179,  2183,  2187,  2191,  2195,  2199,  2203,  2207,  2211,  2215,
    2219,  2225,  2230,  2235,  2240,  2245,  2250,  2255,  2260,  2265,
    2270,  2275,  2282,  2287,  2292,  2297,  2302,  2307,  2312,  2317,
    2322,  2329,  2336,  2343,  2348,  2350,  2352,  2354,  2356,  2358,
    2360,  2362,  2364,  2366,  2368,  2370,  2371,  2378,  2380,  2385,
    2392,  2394,  2399,  2404,  2409,  2416,  2422,  2430,  2435,  2440,
    2447,  2452,  2456,  2459,  2465,  2471,  2475,  2481,  2488,  2497,
    2504,  2509,  2517,  2524,  2531,  2538,  2543,  2550,  2555,  2556,
    2559,  2560,  2563,  2564,  2572,  2574,  2578,  2580,  2582,  2585,
    2586,  2590,  2592,  2595,  2598,  2602,  2606,  2618,  2628,  2636,
    2644,  2646,  2650,  2652,  2654,  2657,  2661,  2666,  2672,  2674,
    2676,  2679,  2683,  2687,  2693,  2698,  2701,  2704,  2707,  2710,
    2714,  2718,  2722,  2726,  2743,  2760,  2777,  2794,  2796,  2798,
    2800,  2804,  2809,  2814,  2819,  2826,  2833,  2842,  2851,  2856,
    2871,  2876,  2881,  2883,  2885,  2889,  2893,  2903,  2911,  2913,
    2919,  2923,  2930,  2932,  2936,  2938,  2940,  2945,  2950,  2954,
    2960,  2967,  2976,  2983,  2989,  2995,  3001,  3007,  3009,  3014,
    3016,  3018,  3020,  3022,  3027,  3034,  3039,  3046,  3052,  3060,
    3065,  3070,  3075,  3084,  3089,  3094,  3099,  3104,  3113,  3122,
    3129,  3134,  3141,  3146,  3148,  3153,  3158,  3159,  3166,  3171,
    3174,  3179,  3181,  3185,  3191,  3197,  3206,  3208,  3210
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     249,     0,    -1,   250,    -1,     1,     6,    -1,    -1,   250,
     251,    -1,   253,    -1,   254,    -1,   274,    -1,   117,   238,
     348,   239,     6,    -1,   295,    -1,   296,    -1,   300,    -1,
     301,    -1,   302,    -1,   303,    -1,   307,    -1,   316,    -1,
     317,    -1,   323,    -1,   324,    -1,   306,    -1,   305,    -1,
     304,    -1,   299,    -1,   326,    -1,   221,    -1,   222,    -1,
      44,   238,   348,   239,     6,    -1,    45,   238,   348,   239,
       6,    -1,    44,   238,   348,   239,   252,   348,     6,    -1,
      44,   238,   348,   247,   344,   239,     6,    -1,    45,   238,
     348,   247,   344,   239,     6,    -1,    44,   238,   348,   247,
     344,   239,   252,   348,     6,    -1,   354,   348,   242,   255,
     243,     6,    -1,   156,     4,   240,   327,   241,     6,    -1,
     157,     4,   240,   327,   241,     6,    -1,   158,     4,   240,
     327,   247,   327,   241,     6,    -1,    -1,   255,   258,    -1,
     255,   262,    -1,   255,   265,    -1,   255,   267,    -1,   255,
     268,    -1,   327,    -1,   256,   247,   327,    -1,   327,    -1,
     257,   247,   327,    -1,    -1,    -1,     4,   259,   238,   256,
     239,   260,   242,   257,   243,     6,    -1,   348,    -1,   261,
     247,   348,    -1,    -1,   163,   238,   327,   247,   327,   247,
     327,   239,   263,   242,   261,   243,     6,    -1,   348,    -1,
     264,   247,   348,    -1,    -1,   164,   238,   327,   247,   327,
     247,   327,   247,   327,   239,   266,   242,   264,   243,     6,
      -1,   165,   242,   340,   243,   242,   340,   243,     6,    -1,
     165,   242,   340,   243,   242,   340,   243,   242,   340,   243,
     242,   340,   243,     6,    -1,    -1,   166,   269,   242,   257,
     243,     6,    -1,     7,    -1,   214,    -1,   213,    -1,   212,
      -1,   211,    -1,   236,    -1,   235,    -1,   238,    -1,   240,
      -1,   239,    -1,   241,    -1,    81,   240,   276,   241,     6,
      -1,    82,   240,   280,   241,     6,    -1,   332,     6,    -1,
      89,   272,   349,   247,   327,   273,     6,    -1,    90,   272,
     354,   247,   349,   273,     6,    -1,   354,   270,   341,     6,
      -1,   354,   271,     6,    -1,   354,   272,   273,   270,   341,
       6,    -1,   354,   272,   242,   344,   243,   273,   270,   341,
       6,    -1,   354,   240,   327,   241,   270,   327,     6,    -1,
     354,   240,   327,   241,   271,     6,    -1,   354,   238,   327,
     239,   270,   327,     6,    -1,   354,   238,   327,   239,   271,
       6,    -1,   354,     7,   349,     6,    -1,   354,   272,   273,
       7,    46,   272,   273,     6,    -1,   354,   272,   273,     7,
      46,   272,   352,   273,     6,    -1,   354,   272,   273,   214,
      46,   272,   352,   273,     6,    -1,   354,   244,     4,     7,
     349,     6,    -1,   354,   240,   327,   241,   244,     4,     7,
     349,     6,    -1,   354,   244,     4,   270,   327,     6,    -1,
     354,   240,   327,   241,   244,     4,   270,   327,     6,    -1,
     354,   244,     4,   271,     6,    -1,   354,   240,   327,   241,
     244,     4,   271,     6,    -1,   354,   244,   173,   244,     4,
       7,   345,     6,    -1,   354,   240,   327,   241,   244,   173,
     244,     4,     7,   345,     6,    -1,   354,   244,   174,     7,
     346,     6,    -1,   354,   240,   327,   241,   244,   174,     7,
     346,     6,    -1,   354,   184,     7,   327,     6,    -1,   184,
     240,   327,   241,     7,     4,     6,    -1,   184,   240,   327,
     241,   244,     4,     7,   327,     6,    -1,   184,   240,   327,
     241,   244,     4,     7,   349,     6,    -1,   184,   240,   327,
     241,   244,     4,     7,   242,   344,   243,     6,    -1,   184,
     240,   327,   241,   244,     4,     6,    -1,   129,   238,     4,
     239,   244,     4,     7,   327,     6,    -1,   129,   238,     4,
     239,   244,     4,     7,   349,     6,    -1,    -1,   247,    -1,
      -1,   276,   275,   354,    -1,   276,   275,   354,     7,   327,
      -1,    -1,   276,   275,   354,     7,   242,   341,   277,   282,
     243,    -1,    -1,   276,   275,   354,   272,   273,     7,   242,
     341,   278,   282,   243,    -1,   276,   275,   354,     7,   349,
      -1,    -1,   276,   275,   354,     7,   242,   349,   279,   286,
     243,    -1,    -1,   280,   275,   348,    -1,   327,     7,   349,
      -1,   281,   247,   327,     7,   349,    -1,   343,     7,   354,
     238,   239,    -1,    -1,   247,   284,    -1,    -1,   284,    -1,
     285,    -1,   284,   247,   285,    -1,     4,   341,    -1,     4,
      -1,     4,   242,   281,   243,    -1,     4,   349,    -1,    -1,
     247,   287,    -1,   288,    -1,   287,   247,   288,    -1,     4,
     327,    -1,     4,   349,    -1,   188,   349,    -1,     4,   242,
     352,   243,    -1,   327,    -1,   349,    -1,   349,   247,   327,
      -1,   327,    -1,   349,    -1,   349,   247,   327,    -1,   327,
      -1,   349,    -1,   349,   247,   327,    -1,   327,    -1,   349,
      -1,   349,   247,   327,    -1,    -1,   176,    95,   242,   327,
     243,    -1,    -1,   122,   338,    -1,    91,   238,   327,   239,
       7,   338,     6,    -1,    94,   238,   327,   239,     7,   341,
       6,    -1,    98,   238,   327,   239,     7,   341,     6,    -1,
      92,   238,   327,   239,     7,   341,   294,     6,    -1,    93,
     238,   327,   239,     7,   341,   294,     6,    -1,   168,   238,
     327,   239,     7,   341,     6,    -1,   169,   238,   327,   239,
       7,   341,     6,    -1,   170,   238,   327,   239,     7,   341,
     172,   341,   171,   327,     6,    -1,   126,    94,   238,   327,
     239,     7,   341,     6,    -1,   109,   238,   327,   239,     7,
     341,     6,    -1,    94,     4,   238,   327,   239,     7,   341,
       6,    -1,   122,    97,   238,   327,   239,     7,   341,     6,
      -1,    97,   238,   327,   239,     7,   341,   293,     6,    -1,
     123,    97,   238,   327,   239,     7,   341,   293,     6,    -1,
      13,    14,     6,    -1,    14,    97,   327,     6,    -1,   112,
      97,   238,   327,   239,     7,     5,     5,     5,     6,    -1,
      95,   238,   327,   239,     7,   341,     6,    -1,    96,   238,
     327,   239,     7,   341,     6,    -1,   100,   238,   327,   239,
       7,   341,     6,    -1,   103,   238,   327,   239,     7,   341,
       6,    -1,   107,   238,   327,   239,     7,   341,     6,    -1,
     108,   238,   327,   239,     7,   341,     6,    -1,   101,   238,
     327,   239,     7,   341,     6,    -1,   102,   238,   327,   239,
       7,   341,     6,    -1,   119,   238,   327,   239,     7,   341,
       6,    -1,   144,   238,   327,   239,     7,   341,     6,    -1,
     126,    97,   238,   327,   239,     7,   341,     6,    -1,   126,
      97,   238,   327,   239,     7,   341,     4,   242,   340,   243,
       6,    -1,    97,     4,   238,   327,   239,     7,   341,     6,
      -1,    99,   238,   327,   239,     7,   341,     6,    -1,   118,
     238,   327,   239,     7,   341,     6,    -1,   123,   118,   238,
     327,   239,     7,   341,     6,    -1,   126,    99,   238,   327,
     239,     7,   341,     6,    -1,   125,    91,   238,   289,   239,
     270,   341,     6,    -1,   125,    94,   238,   290,   239,   270,
     341,     6,    -1,   125,    97,   238,   291,   239,   270,   341,
       6,    -1,   125,    99,   238,   292,   239,   270,   341,     6,
      -1,   133,   338,   242,   297,   243,    -1,   132,   242,   338,
     247,   338,   247,   327,   243,   242,   297,   243,    -1,   134,
     338,   242,   297,   243,    -1,   135,   242,   338,   247,   327,
     243,   242,   297,   243,    -1,   135,   242,   338,   247,   338,
     243,   242,   297,   243,    -1,     4,   242,   297,   243,    -1,
     150,    94,   242,   344,   243,    97,   242,   327,   243,    -1,
     147,    94,   238,   327,   239,   242,   344,   243,     6,    -1,
     298,    -1,   296,    -1,    -1,   298,   295,    -1,   298,    91,
     242,   344,   243,     6,    -1,   298,    94,   242,   344,   243,
       6,    -1,   298,    97,   242,   344,   243,     6,    -1,   298,
      99,   242,   344,   243,     6,    -1,   137,   122,   238,   327,
     239,     7,   341,     6,    -1,   137,    91,   238,   327,   239,
       7,   242,   340,   243,     6,    -1,   137,   122,   238,   327,
     239,     7,   242,   338,   247,   338,   247,   344,   243,     6,
      -1,   137,   122,   238,   327,   239,     7,   242,   338,   247,
     338,   247,   338,   247,   344,   243,     6,    -1,   137,    95,
     238,   327,   239,     7,   242,   338,   247,   344,   243,     6,
      -1,   137,   101,   238,   327,   239,     7,   242,   338,   247,
     338,   247,   344,   243,     6,    -1,   137,   102,   238,   327,
     239,     7,   242,   338,   247,   338,   247,   344,   243,     6,
      -1,   137,   104,   238,   327,   239,     7,   242,   338,   247,
     338,   247,   344,   243,     6,    -1,   137,   105,   238,   327,
     239,     7,   242,   338,   247,   338,   247,   344,   243,     6,
      -1,   137,     4,   238,   327,   239,     7,   341,     6,    -1,
     137,     4,   238,   327,   239,     7,     5,     6,    -1,   137,
       4,   242,   327,   243,     6,    -1,   148,   242,   298,   243,
      -1,   131,   148,   242,   298,   243,    -1,   148,   184,   240,
     327,   241,     6,    -1,   148,     4,   240,   327,   241,     6,
      -1,   148,   354,     6,    -1,   148,     4,     4,     6,    -1,
     148,    84,     6,    -1,   173,   345,   242,   298,   243,    -1,
     131,   173,   345,   242,   298,   243,    -1,   208,   327,   242,
     298,   243,    -1,   189,     5,     6,    -1,   190,     5,     6,
      -1,   189,   242,   298,   243,    -1,   131,   189,   242,   298,
     243,    -1,   190,   242,   298,   243,    -1,   131,   190,   242,
     298,   243,    -1,   354,   349,     6,    -1,    73,   238,   352,
     239,     6,    -1,   354,   354,   240,   327,   241,   348,     6,
      -1,   354,   354,   354,   240,   327,   241,     6,    -1,   354,
     327,     6,    -1,   129,   238,     4,   239,   244,     4,     6,
      -1,   167,     4,     6,    -1,   182,     6,    -1,   183,     6,
      -1,    70,     6,    -1,    71,     6,    -1,    64,     6,    -1,
      64,   242,   327,   247,   327,   247,   327,   247,   327,   247,
     327,   247,   327,   243,     6,    -1,    65,     6,    -1,    66,
       6,    -1,    78,     6,    -1,    79,     6,    -1,   114,     6,
      -1,   115,   242,   344,   243,   242,   344,   243,   242,   340,
     243,   242,   327,   247,   327,   243,     6,    -1,   187,   238,
     242,   344,   243,   247,   349,   247,   349,   239,     6,    -1,
     175,   238,   327,     8,   327,   239,    -1,   175,   238,   327,
       8,   327,     8,   327,   239,    -1,   175,     4,   176,   242,
     327,     8,   327,   243,    -1,   175,     4,   176,   242,   327,
       8,   327,     8,   327,   243,    -1,   177,    -1,   188,     4,
      -1,   188,   349,    -1,   185,    -1,   186,   354,     6,    -1,
     186,   349,     6,    -1,   178,   238,   327,   239,    -1,   179,
     238,   327,   239,    -1,   180,    -1,   181,    -1,   136,   338,
     242,   298,   243,    -1,   136,   242,   338,   247,   338,   247,
     327,   243,   242,   298,   243,    -1,   136,   242,   338,   247,
     338,   247,   338,   247,   327,   243,   242,   298,   243,    -1,
      -1,   136,   338,   242,   298,   308,   312,   243,    -1,    -1,
     136,   242,   338,   247,   338,   247,   327,   243,   242,   298,
     309,   312,   243,    -1,    -1,   136,   242,   338,   247,   338,
     247,   338,   247,   327,   243,   242,   298,   310,   312,   243,
      -1,    -1,   136,   242,   298,   311,   312,   243,    -1,   136,
     242,   298,   243,   128,   109,   242,   327,   243,    -1,   118,
     341,    -1,   123,   118,   341,    -1,   120,   242,   344,   243,
     242,   344,   243,   242,   327,   243,    -1,   313,    -1,   312,
     313,    -1,   153,   242,   327,   243,     6,    -1,   153,   242,
     341,   247,   341,   243,     6,    -1,   154,     6,    -1,   145,
       6,    -1,   145,   327,     6,    -1,   159,     6,    -1,   159,
     161,     6,    -1,   160,     6,    -1,   160,   161,     6,    -1,
     155,   238,   327,   239,     7,   341,   128,   327,     6,    -1,
     128,     4,   240,   327,   241,     6,    -1,   139,    -1,   140,
      -1,   141,    -1,   142,    -1,   143,    -1,    -1,   148,     6,
      -1,   131,   148,     6,    -1,   148,   327,     6,    -1,   131,
     148,   327,     6,    -1,   314,   242,   298,   315,   243,   242,
     298,   315,   243,    -1,   106,   238,   348,   239,    -1,   314,
     238,   327,   239,     7,   242,   298,   315,   243,   242,   298,
     315,   243,     6,    -1,    -1,   128,     4,   327,    -1,    -1,
       4,    -1,    -1,     7,   341,    -1,    -1,     7,   327,    -1,
      -1,   138,   341,    -1,   110,   111,   341,     7,   327,     6,
      -1,   124,    94,   342,     7,   327,   318,     6,    -1,   124,
      97,   342,   320,   319,     6,    -1,   124,    99,   342,   320,
       6,    -1,   162,   342,     6,    -1,   151,    97,   242,   344,
     243,     7,   327,     6,    -1,   145,    97,   342,   321,     6,
      -1,   145,    99,   342,     6,    -1,   146,    97,   342,     7,
     327,     6,    -1,   127,    94,   242,   344,   243,     7,   242,
     344,   243,   322,     6,    -1,   127,    97,   242,   344,   243,
       7,   242,   344,   243,   322,     6,    -1,   127,    94,   242,
     344,   243,     7,   242,   344,   243,   132,   242,   338,   247,
     338,   247,   327,   243,     6,    -1,   127,    97,   242,   344,
     243,     7,   242,   344,   243,   132,   242,   338,   247,   338,
     247,   327,   243,     6,    -1,   127,    94,   242,   344,   243,
       7,   242,   344,   243,   133,   338,     6,    -1,   127,    97,
     242,   344,   243,     7,   242,   344,   243,   133,   338,     6,
      -1,   127,    97,   327,   242,   344,   243,     7,   327,   242,
     344,   243,     6,    -1,    91,   242,   344,   243,   176,    97,
     242,   327,   243,     6,    -1,    94,   242,   344,   243,   176,
      97,   242,   327,   243,     6,    -1,    91,   242,   344,   243,
     176,    99,   242,   327,   243,     6,    -1,    94,   242,   344,
     243,   176,    99,   242,   327,   243,     6,    -1,    97,   242,
     344,   243,   176,    99,   242,   327,   243,     6,    -1,   152,
      97,   342,     6,    -1,   152,    94,   342,     6,    -1,   116,
      91,   342,     6,    -1,   116,    94,   342,     6,    -1,   116,
      97,   342,     6,    -1,   130,    94,   341,     6,    -1,   126,
      94,   341,     6,    -1,   126,    97,   341,     6,    -1,   126,
      99,   341,     6,    -1,   149,     6,    -1,   149,     4,     6,
      -1,   149,    91,   242,   344,   243,     6,    -1,   197,    -1,
     198,    -1,   199,    -1,   325,     6,    -1,   325,   242,   341,
     243,     6,    -1,   325,   242,   341,   247,   341,   243,     6,
      -1,   325,   238,   341,   239,   242,   341,   247,   341,   243,
       6,    -1,   328,    -1,   238,   327,   239,    -1,   227,   327,
      -1,   226,   327,    -1,   233,   327,    -1,   327,   227,   327,
      -1,   327,   226,   327,    -1,   327,   228,   327,    -1,   327,
     229,   327,    -1,   327,   231,   327,    -1,   327,   232,   327,
      -1,   327,   230,   327,    -1,   327,   237,   327,    -1,   327,
     220,   327,    -1,   327,   221,   327,    -1,   327,   225,   327,
      -1,   327,   224,   327,    -1,   327,   219,   327,    -1,   327,
     218,   327,    -1,   327,   217,   327,    -1,   327,   216,   327,
      -1,   327,   222,   327,    -1,   327,   223,   327,    -1,   327,
     215,   327,     8,   327,    -1,    16,   272,   327,   273,    -1,
      17,   272,   327,   273,    -1,    18,   272,   327,   273,    -1,
      19,   272,   327,   273,    -1,    20,   272,   327,   273,    -1,
      21,   272,   327,   273,    -1,    22,   272,   327,   273,    -1,
      23,   272,   327,   273,    -1,    24,   272,   327,   273,    -1,
      26,   272,   327,   273,    -1,    27,   272,   327,   247,   327,
     273,    -1,    28,   272,   327,   273,    -1,    29,   272,   327,
     273,    -1,    30,   272,   327,   273,    -1,    31,   272,   327,
     273,    -1,    32,   272,   327,   273,    -1,    33,   272,   327,
     273,    -1,    34,   272,   327,   273,    -1,    35,   272,   327,
     273,    -1,    36,   272,   327,   247,   327,   273,    -1,    37,
     272,   327,   247,   327,   273,    -1,    38,   272,   327,   247,
     327,   273,    -1,    25,   272,   327,   273,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   204,    -1,
     205,    -1,   206,    -1,    75,    -1,    76,    -1,    77,    -1,
      -1,    83,   272,   327,   329,   282,   273,    -1,   332,    -1,
     195,   272,   348,   273,    -1,   195,   272,   348,   247,   327,
     273,    -1,   334,    -1,   334,   240,   327,   241,    -1,   334,
     238,   327,   239,    -1,   200,   238,   334,   239,    -1,   200,
     238,   334,   244,   335,   239,    -1,   202,   238,   334,   330,
     239,    -1,   202,   238,   334,   244,   335,   330,   239,    -1,
     201,   238,   349,   239,    -1,   245,   354,   272,   273,    -1,
     245,   334,   244,   335,   238,   239,    -1,    86,   272,   354,
     273,    -1,    86,   272,   273,    -1,   354,   271,    -1,   354,
     240,   327,   241,   271,    -1,   354,   238,   327,   239,   271,
      -1,   354,   244,   335,    -1,   354,     9,   354,   244,   335,
      -1,   354,   244,   335,   238,   327,   239,    -1,   354,     9,
     354,   244,   335,   238,   327,   239,    -1,   354,   240,   327,
     241,   244,     4,    -1,   354,   244,     4,   271,    -1,   354,
     240,   327,   241,   244,     4,   271,    -1,   191,   238,   348,
     247,   327,   239,    -1,    56,   238,   341,   247,   341,   239,
      -1,    57,   272,   348,   247,   348,   273,    -1,    55,   272,
     348,   273,    -1,    58,   272,   348,   247,   348,   273,    -1,
      63,   238,   352,   239,    -1,    -1,   247,   327,    -1,    -1,
     247,   348,    -1,    -1,    84,   334,   337,   333,   240,   283,
     241,    -1,   354,    -1,   354,     9,   354,    -1,     4,    -1,
      87,    -1,    87,   327,    -1,    -1,   238,   336,   239,    -1,
     339,    -1,   227,   338,    -1,   226,   338,    -1,   338,   227,
     338,    -1,   338,   226,   338,    -1,   242,   327,   247,   327,
     247,   327,   247,   327,   247,   327,   243,    -1,   242,   327,
     247,   327,   247,   327,   247,   327,   243,    -1,   242,   327,
     247,   327,   247,   327,   243,    -1,   238,   327,   247,   327,
     247,   327,   239,    -1,   341,    -1,   340,   247,   341,    -1,
     327,    -1,   343,    -1,   242,   243,    -1,   242,   344,   243,
      -1,   227,   242,   344,   243,    -1,   327,   228,   242,   344,
     243,    -1,   341,    -1,     5,    -1,   227,   343,    -1,   327,
     228,   343,    -1,   327,     8,   327,    -1,   327,     8,   327,
       8,   327,    -1,    91,   242,   327,   243,    -1,    91,     5,
      -1,    94,     5,    -1,    97,     5,    -1,    99,     5,    -1,
     125,    91,   342,    -1,   125,    94,   342,    -1,   125,    97,
     342,    -1,   125,    99,   342,    -1,    91,   176,    64,   242,
     327,   247,   327,   247,   327,   247,   327,   247,   327,   247,
     327,   243,    -1,    94,   176,    64,   242,   327,   247,   327,
     247,   327,   247,   327,   247,   327,   247,   327,   243,    -1,
      97,   176,    64,   242,   327,   247,   327,   247,   327,   247,
     327,   247,   327,   247,   327,   243,    -1,    99,   176,    64,
     242,   327,   247,   327,   247,   327,   247,   327,   247,   327,
     247,   327,   243,    -1,   296,    -1,   307,    -1,   316,    -1,
     354,   272,   273,    -1,    39,   240,   354,   241,    -1,    39,
     240,   343,   241,    -1,    39,   238,   343,   239,    -1,    39,
     272,   242,   344,   243,   273,    -1,   354,   272,   242,   344,
     243,   273,    -1,    40,   272,   327,   247,   327,   247,   327,
     273,    -1,    41,   272,   327,   247,   327,   247,   327,   273,
      -1,    42,   272,   348,   273,    -1,    43,   272,   327,   247,
     327,   247,   327,   247,   327,   247,   327,   247,   327,   273,
      -1,   196,   272,   343,   273,    -1,    32,   272,   343,   273,
      -1,   327,    -1,   343,    -1,   344,   247,   327,    -1,   344,
     247,   343,    -1,   242,   327,   247,   327,   247,   327,   247,
     327,   243,    -1,   242,   327,   247,   327,   247,   327,   243,
      -1,   354,    -1,     4,   244,   173,   244,     4,    -1,   242,
     347,   243,    -1,   354,   240,   327,   241,   244,   174,    -1,
     345,    -1,   347,   247,   345,    -1,   349,    -1,   354,    -1,
     354,   240,   327,   241,    -1,   354,   238,   327,   239,    -1,
     354,   244,   335,    -1,   354,     9,   354,   244,   335,    -1,
     354,   244,   335,   238,   327,   239,    -1,   354,     9,   354,
     244,   335,   238,   327,   239,    -1,   354,   240,   327,   241,
     244,     4,    -1,   125,    91,   242,   327,   243,    -1,   125,
      94,   242,   327,   243,    -1,   125,    97,   242,   327,   243,
      -1,   125,    99,   242,   327,   243,    -1,     5,    -1,   209,
     240,   354,   241,    -1,    67,    -1,   207,    -1,    72,    -1,
      74,    -1,   193,   238,   348,   239,    -1,   192,   238,   348,
     247,   348,   239,    -1,   194,   272,   348,   273,    -1,   194,
     272,   348,   247,   348,   273,    -1,   203,   238,   334,   331,
     239,    -1,   203,   238,   334,   244,   335,   331,   239,    -1,
      48,   272,   352,   273,    -1,    49,   238,   348,   239,    -1,
      50,   238,   348,   239,    -1,    51,   238,   348,   247,   348,
     247,   348,   239,    -1,    46,   272,   352,   273,    -1,    60,
     272,   348,   273,    -1,    61,   272,   348,   273,    -1,    62,
     272,   348,   273,    -1,    59,   272,   327,   247,   348,   247,
     348,   273,    -1,    54,   272,   348,   247,   327,   247,   327,
     273,    -1,    54,   272,   348,   247,   327,   273,    -1,    47,
     272,   348,   273,    -1,    47,   272,   348,   247,   344,   273,
      -1,    68,   272,   348,   273,    -1,    69,    -1,    53,   272,
     348,   273,    -1,    52,   272,   348,   273,    -1,    -1,    88,
     272,   349,   350,   286,   273,    -1,    85,   272,   351,   273,
      -1,   245,   327,    -1,   354,     9,   245,   327,    -1,   348,
      -1,   352,   247,   348,    -1,     4,   246,   242,   327,   243,
      -1,   353,   246,   242,   327,   243,    -1,   210,   240,   348,
     241,   246,   242,   327,   243,    -1,     4,    -1,   353,    -1,
     210,   240,   348,   241,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   259,   259,   260,   265,   267,   271,   272,   273,   274,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   312,   316,   323,   328,
     333,   347,   360,   373,   401,   415,   428,   441,   460,   465,
     466,   467,   468,   469,   473,   475,   480,   482,   488,   592,
     487,   610,   617,   628,   627,   645,   652,   663,   662,   679,
     696,   719,   718,   732,   733,   734,   735,   736,   740,   741,
     747,   747,   748,   748,   754,   755,   756,   757,   762,   768,
     830,   845,   874,   884,   889,   897,   902,   910,   919,   924,
     936,   953,   959,   968,   986,  1004,  1013,  1025,  1030,  1038,
    1058,  1081,  1092,  1100,  1122,  1145,  1183,  1204,  1216,  1230,
    1230,  1232,  1234,  1243,  1253,  1252,  1273,  1272,  1290,  1300,
    1299,  1313,  1315,  1323,  1329,  1334,  1360,  1362,  1365,  1367,
    1371,  1372,  1376,  1388,  1401,  1416,  1426,  1428,  1432,  1433,
    1438,  1446,  1455,  1463,  1481,  1485,  1492,  1500,  1504,  1511,
    1519,  1523,  1530,  1538,  1542,  1549,  1558,  1561,  1568,  1571,
    1578,  1602,  1618,  1634,  1671,  1711,  1727,  1743,  1765,  1775,
    1791,  1808,  1824,  1845,  1856,  1862,  1868,  1875,  1906,  1921,
    1943,  1966,  1989,  2012,  2036,  2060,  2083,  2108,  2118,  2141,
    2158,  2174,  2192,  2210,  2220,  2232,  2244,  2256,  2273,  2289,
    2305,  2320,  2337,  2354,  2389,  2411,  2435,  2436,  2441,  2444,
    2448,  2459,  2470,  2481,  2497,  2516,  2537,  2552,  2568,  2586,
    2637,  2658,  2680,  2703,  2808,  2824,  2859,  2870,  2881,  2887,
    2902,  2930,  2942,  2951,  2958,  2970,  2989,  2995,  3001,  3008,
    3015,  3022,  3034,  3107,  3125,  3142,  3157,  3190,  3202,  3226,
    3230,  3235,  3242,  3247,  3257,  3262,  3268,  3276,  3280,  3284,
    3293,  3357,  3373,  3390,  3407,  3429,  3451,  3486,  3494,  3502,
    3508,  3515,  3522,  3542,  3568,  3580,  3592,  3610,  3628,  3647,
    3646,  3671,  3670,  3697,  3696,  3721,  3720,  3743,  3759,  3776,
    3793,  3816,  3819,  3825,  3837,  3857,  3861,  3865,  3869,  3873,
    3877,  3881,  3885,  3894,  3907,  3908,  3909,  3910,  3911,  3915,
    3916,  3917,  3918,  3919,  3922,  3945,  3964,  3986,  3989,  4005,
    4008,  4025,  4028,  4034,  4037,  4044,  4047,  4054,  4071,  4112,
    4156,  4195,  4220,  4229,  4259,  4285,  4311,  4343,  4370,  4396,
    4422,  4448,  4474,  4496,  4502,  4508,  4514,  4520,  4526,  4552,
    4578,  4595,  4612,  4629,  4641,  4647,  4653,  4665,  4669,  4679,
    4690,  4691,  4692,  4696,  4702,  4714,  4732,  4760,  4761,  4762,
    4763,  4764,  4765,  4766,  4767,  4768,  4775,  4776,  4777,  4778,
    4779,  4780,  4781,  4782,  4783,  4784,  4785,  4786,  4787,  4788,
    4789,  4790,  4791,  4792,  4793,  4794,  4795,  4796,  4797,  4798,
    4799,  4800,  4801,  4802,  4803,  4804,  4805,  4806,  4807,  4808,
    4809,  4810,  4811,  4812,  4821,  4822,  4823,  4824,  4825,  4826,
    4827,  4828,  4829,  4830,  4831,  4836,  4835,  4843,  4845,  4850,
    4855,  4860,  4882,  4903,  4907,  4911,  4915,  4919,  4925,  4941,
    4946,  4952,  4958,  4977,  4998,  5031,  5035,  5040,  5044,  5049,
    5054,  5064,  5074,  5079,  5090,  5099,  5104,  5109,  5137,  5138,
    5144,  5145,  5151,  5150,  5173,  5175,  5180,  5189,  5191,  5197,
    5198,  5204,  5208,  5212,  5216,  5220,  5227,  5231,  5235,  5239,
    5246,  5251,  5258,  5263,  5267,  5272,  5276,  5284,  5295,  5299,
    5311,  5319,  5327,  5334,  5344,  5367,  5373,  5379,  5385,  5391,
    5402,  5413,  5424,  5435,  5441,  5447,  5453,  5459,  5469,  5479,
    5489,  5502,  5514,  5518,  5522,  5526,  5544,  5552,  5560,  5589,
    5599,  5615,  5626,  5631,  5635,  5639,  5651,  5655,  5667,  5684,
    5694,  5698,  5713,  5718,  5725,  5729,  5734,  5748,  5765,  5769,
    5774,  5778,  5783,  5791,  5797,  5803,  5809,  5818,  5822,  5826,
    5834,  5840,  5846,  5850,  5858,  5866,  5873,  5883,  5888,  5893,
    5908,  5922,  5936,  5948,  5964,  5973,  5982,  5992,  6003,  6011,
    6019,  6023,  6042,  6049,  6055,  6062,  6070,  6069,  6079,  6103,
    6105,  6111,  6116,  6124,  6133,  6142,  6154,  6157,  6161
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
  "tSpline", "tVolume", "tBlock", "tCylinder", "tCone", "tTorus",
  "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle", "tDisk",
  "tWire", "tCharacteristic", "tLength", "tParametric", "tElliptic",
  "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tSetFactory",
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
  "CharParameterOptions", "CharParameterOption", "PhysicalId0",
  "PhysicalId1", "PhysicalId2", "PhysicalId3", "InSphereCenter",
  "CircleOptions", "Shape", "Transform", "MultipleShape", "ListOfShapes",
  "LevelSet", "Delete", "Colorify", "SetPartition", "Visibility",
  "Command", "Slide", "Loop", "Extrude", "@9", "@10", "@11", "@12",
  "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "BooleanShape", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@13", "GetForced_Default",
  "GetForcedStr_Default", "DefineStruct", "@14", "Struct_FullName",
  "tSTRING_Member_Float", "Append", "AppendOrNot", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@15",
  "NameStruct_Arg", "RecursiveListOfStringExprVar", "StringIndex",
  "String__Index", 0
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
     274,   274,   274,   274,   274,   274,   274,   274,   274,   275,
     275,   276,   276,   276,   277,   276,   278,   276,   276,   279,
     276,   280,   280,   281,   281,   281,   282,   282,   283,   283,
     284,   284,   285,   285,   285,   285,   286,   286,   287,   287,
     288,   288,   288,   288,   289,   289,   289,   290,   290,   290,
     291,   291,   291,   292,   292,   292,   293,   293,   294,   294,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   296,   296,
     296,   296,   296,   296,   296,   296,   297,   297,   298,   298,
     298,   298,   298,   298,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   300,   300,   300,   300,
     300,   300,   300,   301,   301,   302,   303,   303,   303,   303,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   305,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   307,   307,   307,   308,
     307,   309,   307,   310,   307,   311,   307,   307,   307,   307,
     307,   312,   312,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   314,   314,   314,   314,   314,   315,
     315,   315,   315,   315,   316,   316,   317,   318,   318,   319,
     319,   320,   320,   321,   321,   322,   322,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   324,   324,   324,
     325,   325,   325,   326,   326,   326,   326,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   330,   330,
     331,   331,   333,   332,   334,   334,   335,   336,   336,   337,
     337,   338,   338,   338,   338,   338,   339,   339,   339,   339,
     340,   340,   341,   341,   341,   341,   341,   341,   342,   342,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   344,   344,   344,   344,   345,   345,   345,   345,
     346,   346,   347,   347,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   350,   349,   349,   351,
     351,   352,   352,   353,   353,   353,   354,   354,   354
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
       9,     5,     7,     9,     9,    11,     7,     9,     9,     0,
       1,     0,     3,     5,     0,     9,     0,    11,     5,     0,
       9,     0,     3,     3,     5,     5,     0,     2,     0,     1,
       1,     3,     2,     1,     4,     2,     0,     2,     1,     3,
       2,     2,     2,     4,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     0,     5,     0,     2,
       7,     7,     7,     8,     8,     7,     7,    11,     8,     7,
       8,     8,     8,     9,     3,     4,    10,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     8,    12,     8,
       7,     7,     8,     8,     8,     8,     8,     8,     5,    11,
       5,     9,     9,     4,     9,     9,     1,     1,     0,     2,
       6,     6,     6,     6,     8,    10,    14,    16,    12,    14,
      14,    14,    14,     8,     8,     6,     4,     5,     6,     6,
       3,     4,     3,     5,     6,     5,     3,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     9,     2,     3,
      10,     1,     2,     5,     7,     2,     2,     3,     2,     3,
       2,     3,     9,     6,     1,     1,     1,     1,     1,     0,
       2,     3,     3,     4,     9,     4,    14,     0,     3,     0,
       1,     0,     2,     0,     2,     0,     2,     6,     7,     6,
       5,     3,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,    10,    10,    10,    10,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     1,     4,     6,
       1,     4,     4,     4,     6,     5,     7,     4,     4,     6,
       4,     3,     2,     5,     5,     3,     5,     6,     8,     6,
       4,     7,     6,     6,     6,     4,     6,     4,     0,     2,
       0,     2,     0,     7,     1,     3,     1,     1,     2,     0,
       3,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     1,
       2,     3,     3,     5,     4,     2,     2,     2,     2,     3,
       3,     3,     3,    16,    16,    16,    16,     1,     1,     1,
       3,     4,     4,     4,     6,     6,     8,     8,     4,    14,
       4,     4,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     4,     4,     3,     5,
       6,     8,     6,     5,     5,     5,     5,     1,     4,     1,
       1,     1,     1,     4,     6,     4,     6,     5,     7,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     4,     2,
       4,     1,     3,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   586,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   305,   306,   307,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,   274,   275,     0,     0,     0,   269,     0,     0,
       0,     0,     0,   360,   361,   362,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   587,     0,   208,     0,     0,     0,     0,     0,   253,
       0,   255,   256,   251,   252,     0,   257,   258,   111,   121,
     586,   469,   464,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,     0,   414,   415,   417,
     418,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,   423,   424,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   419,   420,   421,     0,     0,     0,     0,
       0,     0,   507,   508,     0,   509,   482,   367,   427,   430,
     288,   483,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,     0,     0,   208,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,   488,     0,     0,
       0,     0,     0,   586,     0,     0,   528,     0,     0,     0,
       0,   249,   250,     0,   547,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   549,     0,
     573,   551,   552,     0,     0,     0,     0,     0,     0,   550,
       0,     0,     0,     0,   267,   268,     0,   208,     0,   208,
       0,     0,     0,   464,     0,     0,   208,   363,     0,     0,
      76,     0,    63,     0,     0,    67,    66,    65,    64,    69,
      68,    70,    71,     0,     0,     0,     0,     0,     0,   534,
     464,     0,   207,     0,   206,     0,   174,     0,     0,   534,
     535,     0,     0,   581,     0,   109,   109,     0,   462,     0,
       0,     0,     0,     0,   522,   523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,     0,     0,   496,     0,   497,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,     0,   369,   490,   371,     0,   484,     0,     0,
     464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,     0,   442,     0,     0,
       0,     0,     0,     0,   289,     0,   321,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,     0,   208,   208,     0,   473,   472,
       0,     0,     0,     0,   208,   208,     0,     0,     0,     0,
     285,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,   232,
       0,     0,   230,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   248,     0,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   270,     0,
     236,     0,   237,     0,     0,   369,     0,   208,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    72,
      73,     0,     0,   246,    38,   242,     0,     0,     0,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,   209,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,   467,     0,
       0,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,     0,     0,     0,     0,     0,
       0,   350,   351,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   425,   441,     0,     0,     0,     0,     0,
       0,   499,   500,   501,   502,     0,     0,     0,     0,     0,
     458,     0,   368,   485,     0,     0,   492,     0,   387,   386,
     385,   384,   380,   381,   388,   389,   383,   382,   373,   372,
       0,   374,   491,   375,   378,   376,   377,   379,     0,     0,
     465,     0,     0,   466,   445,     0,   510,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,   144,   145,     0,
     147,   148,     0,   150,   151,     0,   153,   154,     0,   354,
       0,   355,     0,   356,     0,     0,     0,     0,   353,     0,
     208,     0,     0,     0,     0,     0,   475,   474,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   334,     0,
       0,   231,     0,     0,   226,     0,     0,     0,   349,   348,
       0,     0,     0,   368,     0,     0,     0,     0,     0,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,     0,     0,     0,   460,     0,     0,   238,
     240,     0,   374,     0,   588,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,   368,
       0,    63,     0,     0,     0,     0,    79,     0,    63,    64,
       0,     0,   465,     0,     0,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   583,    28,    26,    27,
       0,     0,     0,     0,     0,   466,   538,    29,     0,     0,
     243,   582,    74,   112,    75,   122,   468,   470,   128,     0,
       0,     0,     0,   524,   525,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   413,   400,     0,
     402,   403,   404,   405,   406,   521,   407,   408,   409,     0,
       0,     0,   513,   512,   511,     0,     0,     0,   518,     0,
     455,     0,     0,     0,   457,   126,   440,     0,   494,     0,
       0,     0,     0,     0,   428,   520,   433,     0,   437,     0,
       0,     0,   486,     0,     0,   438,     0,     0,     0,   432,
     431,     0,     0,     0,   450,     0,     0,     0,     0,     0,
       0,   368,   317,   322,   320,     0,   330,     0,     0,     0,
       0,     0,     0,     0,     0,   368,   368,   368,     0,     0,
       0,     0,   227,     0,   239,   241,     0,     0,     0,   198,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,     0,   563,     0,
     570,   559,   560,   561,     0,   575,   574,     0,     0,   564,
     565,   566,   572,   579,   578,     0,   136,     0,   553,     0,
     555,     0,     0,     0,   548,     0,   235,     0,     0,     0,
     310,     0,     0,     0,   364,     0,   584,     0,     0,     0,
       0,   101,    63,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,    61,     0,    39,    40,    41,    42,    43,
       0,   537,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   537,   536,     0,
       0,     0,     0,     0,   133,     0,   129,   130,     0,     0,
       0,     0,     0,   158,   158,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   327,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   458,   459,   435,     0,
       0,   493,   390,   487,   446,   444,     0,   443,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,     0,   146,
       0,   149,     0,   152,     0,   155,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,     0,     0,     0,     0,
       0,   296,     0,     0,   295,     0,   298,     0,   300,     0,
     286,   292,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,   335,     0,   229,   228,   359,     0,
       0,    35,    36,     0,     0,     0,     0,   529,     0,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,   461,   557,     0,     0,   208,   311,
       0,   312,   208,     0,     0,   543,   544,   545,   546,     0,
      86,     0,     0,     0,     0,    84,    91,    93,     0,   532,
       0,    99,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,    34,   446,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
     539,     0,     0,    32,     0,     0,   113,   118,     0,     0,
     132,   135,   463,     0,    77,    78,   160,     0,     0,     0,
       0,     0,     0,   161,     0,     0,   177,   178,     0,     0,
       0,     0,   162,   190,   179,   183,   184,   180,   181,   182,
     169,     0,     0,   401,   410,   411,   412,   514,     0,     0,
       0,   453,   454,   456,   127,   426,     0,     0,     0,     0,
     452,   429,   434,     0,   191,   439,     0,   449,   447,   515,
     185,     0,     0,   156,     0,     0,   328,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,   208,   208,     0,     0,   297,   482,     0,     0,
     299,   301,     0,     0,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,     0,     0,     0,     0,
     165,   166,     0,     0,     0,     0,   102,   106,     0,   571,
       0,     0,   569,     0,   580,     0,     0,   137,   138,   577,
     554,   556,     0,     0,     0,   309,   313,   309,     0,   365,
      85,    63,     0,     0,     0,     0,    83,     0,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,   449,   244,   447,   245,   210,   211,   212,   213,
       0,     0,     0,     0,     0,     0,   542,   540,     0,   114,
     119,     0,     0,   522,   523,   131,     0,     0,   159,   163,
     164,   170,     0,     0,   189,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   436,     0,   451,
       0,   171,     0,   192,   318,   194,   195,   196,   197,   168,
       0,   187,   193,     0,     0,     0,     0,     0,     0,   479,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   223,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,   332,    37,     0,   527,     0,     0,
     264,   263,     0,     0,     0,     0,     0,     0,     0,   140,
     141,   142,     0,   558,     0,   585,     0,     0,     0,     0,
       0,    96,     0,     0,    97,   533,     0,     0,    88,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    46,     0,
      33,     0,     0,   126,   136,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   516,   517,
       0,     0,     0,     0,     0,   448,     0,   173,     0,   325,
     325,     0,   107,   108,   208,     0,   201,   202,   287,     0,
     293,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   204,     0,     0,     0,     0,   103,   104,
     562,   568,   567,     0,   139,     0,     0,   314,     0,    92,
      94,     0,   100,     0,    82,    89,    90,    49,     0,     0,
       0,     0,   481,     0,     0,   448,   541,     0,     0,     0,
     116,     0,   123,     0,   343,   345,   344,   346,     0,   347,
     176,     0,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
     303,     0,     0,   281,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   526,   265,     0,   143,     0,   208,   366,
       0,   531,     0,    45,     0,     0,     0,    62,    47,     0,
     115,   120,   126,     0,     0,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,   336,     0,     0,   337,
       0,   199,     0,   294,     0,   277,     0,   208,     0,     0,
       0,     0,     0,     0,   167,   105,   261,   309,    98,     0,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,   188,     0,   340,     0,   341,   342,   476,
       0,     0,   283,   218,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,    59,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,   302,   282,   278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   220,   221,   222,     0,   216,   316,    50,     0,
      57,     0,   254,     0,   519,     0,     0,     0,     0,     0,
       0,   284,     0,     0,    51,     0,     0,   260,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,     0,   503,
     504,   505,   506,     0,     0,    54,    52,     0,    55,     0,
     338,   339,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1030,   109,   110,  1011,  1831,  1837,
    1295,  1507,  1982,  2123,  1296,  2088,  2147,  1297,  2125,  1298,
    1299,  1511,   404,   557,   558,  1094,   111,   735,   425,  1843,
    1992,  1844,   426,  1722,  1368,  1325,  1326,  1327,  1470,  1667,
    1668,   876,   879,   882,   885,  1560,  1550,   719,   252,   413,
     414,   114,   115,   116,   117,   118,   119,   120,   121,   253,
    1195,  2016,  2079,   913,  1191,  1192,   254,   988,   255,   125,
    1396,  1155,   874,   927,  1952,   126,   127,   128,   129,   256,
     257,  1115,  1131,  1253,   258,   740,   259,   864,   739,   428,
     589,   292,  1698,   327,   328,   261,   528,   335,  1283,  1500,
     423,   419,  1246,   970,   424,   131,   383
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1836
static const yytype_int16 yypact[] =
{
   10103,    36,    56, 10253, -1836, -1836,   -76,    51,     1,  -131,
    -111,    17,   171,   182,   250,   285,   -12,   315,   330,     6,
     103,    22,  -122,  -122,    74,   129,   140,    12,   153,   181,
      20,   190,   197,   203,   208,   221,   237,   248,   322,   335,
     352,   494,   514,   621,   370,   483,   380,  5833,   397,   410,
     567,   -70,   283,   574,   683,    42,   420,   582,  -113,   443,
     -52,   -52,   474,   317,   613, -1836, -1836, -1836, -1836, -1836,
     492,   419,   655,   642,    39,    24,   647,   658,   484,   742,
     774,   792,  5125,   804,   500,   556,   569,    29,    45, -1836,
     583,   588, -1836, -1836,   814,   826,   601, -1836,  8050,   608,
   10420,    26,    27, -1836, -1836, -1836,  9933,   626, -1836, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836, -1836, -1836,   183, -1836, -1836, -1836, -1836,    64, -1836,
     883,   630,  4229,   549,   662,   910,  9933,  2847,  2847, -1836,
    9933, -1836, -1836, -1836, -1836,  2847, -1836, -1836, -1836, -1836,
     691,   706,   965, -1836, -1836, 10450,    22,  9933,  8987,  9933,
    9933,   746,  9933,  8987,  9933,  9933,   747,  9933,  8987,  9933,
    9933,  9933,  9933,  9933,  9933,  2847,  9933,  9933,  9933,  6069,
     748, -1836,  8987,  5125,  5125,  5125,  2847, -1836, -1836, -1836,
   -1836, -1836,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,   -51,  -122,  -122,  -122,  -122,
    -122,   765,  -122,  -122,   767, -1836, -1836, -1836,  -122,  -122,
      54,     2,     8,    48,  6069,   893,   634,   780,  -122,  -122,
     785,   787,   802, -1836, -1836, -1836,  9933,  6305,  9933,  9933,
    6541,    22, -1836, -1836,   807, -1836,  3972, -1836, -1836,    69,
   -1836, -1836,   176,  9933,  8987,   813,   818,  6777,  5125,  5125,
    5125,   821,   823,   833,   836,  7013,  7249,  7485,   844,  1734,
    1083,  6069,   852,    29,   853,   862,   -52,   -52,   -52,  9933,
    9933,   -94, -1836,   337,   -52,  9304,   377,   290,   858,   884,
     885,   888,   889,   890,   891,  9933,  5125,  5125,  5125,   894,
      11,  1109,   895, -1836,  1125,  1127, -1836,   892,   896,   897,
    5125,  5125,   900,   901,   902, -1836,  9933, -1836,  1130,  1131,
    9933,  9933,  9933,   255,  9933,   904, -1836,   967,  9933,  9933,
    9933, -1836, -1836,  9933, -1836,  -122,  -122,  -122,   909,   911,
     912,  -122,  -122,  -122,  -122,  -122,  -122,  -122, -1836,  -122,
   -1836, -1836, -1836,  -122,  -122,   913,   914,  -122,   915, -1836,
     908,  1148,  1149,   916, -1836, -1836,  1151, -1836,  1153, -1836,
    -122,  9933, 12920,   220,  2847,  9933, -1836, -1836,  6069,  6069,
   -1836,   918, 10450,   646,  1154, -1836, -1836, -1836, -1836, -1836,
   -1836,  9933,  9933,   289,  6069,  1156,   436,  1342,   923,  1160,
      90,   925, -1836,   927,  7788,  9933, -1836,  1632,  -117, -1836,
      91,   -88,  8464, -1836,   -83,  -201,  -158,  1081, -1836,    22,
     924,   928, 13409,  8987,  4103, -1836,   394, 13434, 13459,  9933,
   13484,   395, 13509, 13534,  9933, 13559,   427, 13584, 13609, 13634,
   13659, 13684, 13709,   933, 13734, 13759, 13784,  1167,  9933,   466,
    1170,  1171,  1172,   940,  9933,  9933,  9933,  9933,  9933,  9933,
    9933,  9933,  9933,  9933,  9933,  9933,  9933,  9933,  9933,  9933,
    8987,  9933,  9933,  9933,  9933,  9933,  9933,  8987,  8987,   938,
    9933,  9933,  2847,  9933,  2847,  6069,  2847,  2847,  2847,  9933,
      53, -1836,  1117,  9933, -1836,  1119, -1836,  1121, -1836,  1122,
    6069,  5125,  5125,  5125,  5125,  2847,  2847,  8987,    22, 10450,
      22,   951,  8987,   951, -1836,   951, 13809, -1836,   476,   945,
      82,  9933,  9933,  9933,  9933,  9933,  9933,  9933,  9933,  9933,
    9933,  9933,  9933,  9933,  9933,  7721,  9933,  9933,  9933,  9933,
    9933,  9933,  9933,    22,  9933,  9933,  1186, -1836,   771, 13834,
     536,  9933,  9933,  9933, -1836,  1184,  1185,  1185,  9218,  9218,
    9218,  9218,  9933,  1187,  9933,  1189,  9933,  1194,  8987,  8987,
   12948,   962,  1198, -1836,   963, -1836, -1836,  -172, -1836, -1836,
    9497,  9572,   -52,   -52,   549,   549,  -165,  9304,  9304,  9933,
    3876,  -146, -1836,  9933,  9933,  9933,  9933,  9933,  9933,  9933,
    9933,  9933, 13859,  1199,  1202,  1203,  9933,  1205,  9933, -1836,
    9933,  4432, -1836, -1836,  8987,  8987,  8987,  1206,  1207,  9933,
    9933,  9933, 13884, -1836, -1836, 13909, 13934, 13959,  1036,  9805,
   -1836,   972,  4157, 13984, 14009, 13031,  2847,  2847,  2847,  2847,
    2847,  2847,  2847,  2847,  2847,  9933,  2847,  2847,  2847,  2847,
      15, 10450,  2847,  2847,  2847,    22,    22, -1836, -1836,  8987,
   -1836,  5192, -1836,  5428,  9933,   951,  9933, -1836,  9933,  9933,
     977, 14034,  3544,   980,   541,  9933,  1215,   985,   986,   987,
     988,  9933, 14059, 13058,   269,   978,  1225,  1227, -1836, -1836,
   -1836,  8987,   396, -1836, -1836, -1836,    22,  9933,  9933,  1186,
     996, -1836,   557,    37,    46,   577,  1001,   -28,   737, -1836,
   11963, -1836,    31,  8987,    22,  9933,  9933,  1238,  1237,  8987,
    9933,  1239,  2847,  1244, -1836,    22,  1245,  2847,  9933,  1013,
    1014, -1836,  9933, 10450,  1246,  8987,  1080,  8987,  1252,  1254,
   14084,  1255,  1087,  1257,  1258, 14109,  1261,  1093,  1263,  1264,
    1265,  1266,  1267,  1269, -1836,  1270,  1271,  1273,  9933, 14134,
    1015, -1836, -1836, -1836,  1275, 13004, 13004, 13004, 13004, 13004,
   13004, 13004, 13004, 13004, 13004, 13004, 10324, 13004, 13004, 13004,
   13004,  1155,   461, 13004, 13004, 13004, 10357, 10445, 10478,  4103,
    1045,  1046,   152,  8987, 10511, 10544,   461, 10577,   461,  1041,
    1042,  1043,   166, 15059, -1836,   461,  1049, 11992,  1050,  1051,
    1052, -1836, -1836, -1836, -1836,  1048,  -127,   461,   -71,  1057,
     463,   606,  1290, -1836,  1238,   461,  4388,  4567,   731,  1362,
     769,   769,   460,   460,   460,   460,   460,   460,   561,   561,
    8987,   402, -1836,   402,   402,   951,   951,   951, 14159, 13085,
    1054, 14184, 13112,   164,  1062,  8987, -1836,  1295,  1061, 14209,
   14234, 14259,  9933,  6069,  1300,  1299,  1067, 15059,  1060,  1069,
   15059,  1063,  1070, 15059,  1064,  1074, 15059,  1068, 14284, -1836,
   14309, -1836, 14334, -1836,   611,   612,  8987,  1072, -1836,  5664,
   -1836,  5900,  6136,   -52,  9933,  9933, -1836, -1836,  1071,  1075,
    9304,  8129,  1191,   685,   -52,  6372, 14359, 12021, 14384, 14409,
   14434, 14459, 14484, 14509, 14534,  1310,  9933,  1314, -1836,  9933,
   14559, -1836, 13139, 13166, -1836,   617,   620,   622, -1836, -1836,
   13193, 13220, 10610, -1836,  1315,  1316,  1317,  1082,  9933,  6608,
    9933,  9933, -1836, -1836,    38,   -98,   201,   -98,  1086,  1089,
    1084,   461,   461,  1088, 10643,   461,   461,   461,   461,  9933,
     461,  1320, -1836,  1090,  1091,   249,   480,  1092,   625, -1836,
   -1836, 13004,   402,  6844,  1094,  1327,  1188,  9541,  1096,  1099,
    1336,  6069, 12050, -1836,  9933,  9933,  9933,  9933,  1772,   326,
     162, 10450,  9933,  1337,  1340,    35, -1836,   628,  1304,  1307,
    6069,    70,  1101, 14584, 13247,   635,  9933,  8987,  8987,  8987,
    8987,  9933,  1128,  1129,  1150,  1162, -1836, -1836, -1836, -1836,
    2847,   232,  1111, 14609, 13274, -1836,  1168, -1836,   259, 10676,
   -1836, -1836, -1836,    61, -1836, -1836, 15059, -1836,  1361, 13004,
     461,   -52,   736,  4103, -1836,  6069,  6069,  1386,  6069,   867,
    6069,  6069,  1391,  6069,  1308,  6069,  6069,  6069,  6069,  6069,
    6069,  6069,  6069,  6069,  1999,  1402,  8987, -1836, -1836, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,  9933,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,  9933,
    9933,  9933, -1836, -1836, -1836,   631,  9933,  9933, -1836,  9933,
   -1836,  6069,  2847,  2847, -1836,  1163, -1836,  9933, -1836,  9933,
    9933,  9933,  9933,  9933, -1836, -1836, -1836,  1238, -1836,  1238,
    9933,  1173, -1836,  6069,  1175, -1836,  9933,  9933,   636, -1836,
   -1836,  1238,   164,   -73, -1836,  9933,   638,  6069,  8987,  1407,
    1408,  1409,  2541, -1836, -1836,  1363, -1836,   417,  9933,   417,
    9933,   417,  9933,   417,  9933,  1410,  1411,  1412,  1414,  1415,
     639,  1364, -1836,  7080, -1836, -1836,  -139, 10709, 10742, -1836,
   -1836, 12079,  -134,  1318,  1419,  9625,  1183,  1420,  1190,    79,
      80,   594, -1836,  -130, -1836,   685,  1422,  1424,  1425,  1426,
    1427,  1429,  1433,  1434,  1436,  6069, 15059, -1836,  2098,  1204,
    1438,  1439,  1441,  1351,  1442,  1444,  1445,  9933,  6069,  6069,
    6069,  1449, 10775, -1836,  4831,  1250,  1450,  1451, -1836,  8987,
   -1836, -1836, -1836, -1836,  2847, -1836, -1836,  9933,  2847, -1836,
   -1836, -1836, -1836, 15059, -1836,  1211,  1210,  2847, -1836,  2847,
   -1836,  1238,  2847,  1219, -1836,  1212, -1836,  1218,  1220,  9856,
   -1836,  2142,  1221,  6069, -1836,  1240, -1836, 12108, 12137, 12166,
   12195, -1836, -1836,  9933,  1455,   353,  9933,  1478,  1479,  2424,
   -1836,  1481,    29,  1480,  1251,   461,  -122,  -122,  1484, -1836,
    1256,  1259,  1262, -1836,  1486, -1836, -1836, -1836, -1836, -1836,
    1238,   164,  1031,  9933, 13301,   641,   644,   649,   651, 14634,
    9933,  9933,  9933,  9933,  1487,   138,  1238, -1836,  1268,  9933,
    1492,  9933,  7957,   461,  4631,  1272,  1253, -1836,  1493,  1497,
      97,  1274,  1276,  1383,  1383,  6069,  1500,  1277,  1278,  1502,
    1508,  6069,  1339,  1279,  1511,  1516,  1517,  1518,  1519,  1521,
    1522,  1523,  1524, -1836,  1526,   652, 13004, 13004, 13004, 13004,
     461, 10808, 10841, 10874,  1294,   461,   461,  1361,   461, 10907,
   10940, 10973, 11006, 14659, 13004,  1296,  1287, 15059, -1836,  1531,
    1301, 15059, 15059, -1836,  1303, -1836,  1534, -1836, 14684,   461,
    1533,   654,  6069,  6069,  6069,  1538,  1539, -1836,  6069, 15059,
    6069, 15059,  6069, 15059,  6069, 15059,  6069,  6069,  6069,  1302,
    1305,  1541,   462, -1836,  9933,  9933,  9933,  1309,  1311,  1313,
    1306, -1836,  2618,  6069, -1836,  9933, -1836,  1543, -1836,  1544,
   -1836, -1836,  9304,   657,  5361, -1836,  1333,  1334,  1335,  1354,
    1355,  1358,  8193,  1550, -1836,  8987, -1836, -1836, -1836,  1359,
    9933, -1836, -1836, 13328,  1572,  1596,  1431, -1836,  9933,  9933,
    9933, -1836,  1598,   524,   385,  1360,  7841,  1366,  9933,    32,
     461,  1367,   461,  1369, -1836, -1836, 10450,  9933, -1836, -1836,
    2958, -1836, -1836,  1370,  1599, -1836, -1836, -1836, -1836,  3030,
   -1836,   334,  1365,  1603,  3069, -1836, -1836, -1836,    29, -1836,
     660, -1836,  9933,   417,  2734,  2847, -1836,  1376,  9933,  9933,
    6069,  1377, -1836,   667,  1614,  1615, 14709,  1616,  1617,  1619,
    1621,  1622,  1290, 14734, 14759, 14784, 14809, -1836, -1836,  2847,
    1382,  1627, 14834, -1836, 11039,  4889, 15059, -1836,  1628,  6541,
   -1836, -1836, -1836,  1361, -1836, -1836, -1836,  9933,  9933,   -52,
    1630,  1631,  1633, -1836,  9933,  9933, -1836, -1836,  1641,  1555,
    1645,  9933, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836,  1647,  1413, -1836, -1836, -1836, -1836, -1836,  9933,  9933,
    9933, -1836, -1836, -1836,  1253, -1836,  9933,  9933,  9933,  9933,
   -1836, -1836, -1836,  1417, -1836, -1836,  9933,   164, -1836, -1836,
   -1836,  1416,  1648,  1339,  1653,  9933, -1836,  1655,  1656,  1657,
    1658,  1659,   974,  1660,  8987,  8987,  9933, -1836,  9218, 12224,
   14859,  8687,   549,   549,  9933,  9933, -1836,   544,  1406, 14884,
   -1836, -1836, 12253,  -121, -1836,  1661,  1662,  6069,   -52,   -52,
     -52,   -52,   -52,  5597,  1663, -1836,   668,  9933,  3115,  1664,
   -1836, -1836,  6069,  8923,   704, 14909, -1836, -1836,  8429, -1836,
    2847,  9933, -1836,  2847, 15059,  8515, 10450,  1430, -1836, -1836,
   -1836, -1836,  1432,  1440, 12282,  3544, -1836,  3544,  6069, -1836,
   -1836, 10450,  9933,  1666,  1669,    35, -1836,  1668, -1836,    29,
   13355,  6069,  1670,   -98,   -98,  9933, 11072, 11105,   671, -1836,
    9933,  9933,  -184, -1836,  1437, -1836, -1836, -1836, -1836, -1836,
    1409,  1410,  1411,  1412,  1672,  9933, -1836, -1836,  9933, -1836,
   -1836,  1448,   695,  3835,  1673, -1836, 12311, 12340,   467, -1836,
   -1836, -1836, 12369, 12398, -1836,  1452, -1836, 12427,  1676,  6069,
   13004, 13004, 11138, 11171, 11204, 11237, 11270, -1836, 14934, -1836,
    9933, -1836,  1686, -1836, 15059, -1836, -1836, -1836, -1836, -1836,
    1454, -1836, -1836,   696,   724, 12976,  3150,  1694,  1459, -1836,
   -1836,  9933,  1461,  1462, 12456, 13382,  1696,  6069,  1699,  1465,
    9933, -1836, -1836,   726,  -102,   -89,   -80,   142,   157,  8751,
     168, -1836,  1702, 12485, -1836, -1836,  1540, -1836,  9933,  9933,
   -1836, -1836,  8987,  3187,  1703,  1471, 13004,   461,  2847, 15059,
   -1836, -1836,    32, -1836, 10450, -1836,  1469,  1470,  1472,  1710,
    3511, -1836,  1711,  1713, -1836, -1836,  1473,  1714, -1836,  1715,
    1716,   318, 15059,  9933,  9933,  1482,  6069,   729, 15059, 14959,
   -1836, 14984, 11303,  1163,  1210,  6069, -1836,  9933, 10450,    22,
    1717,  1720,  1721,  1722,  9933,  1723,  1724,   732, -1836, -1836,
    9933,  9933,  9933,  9933,  9933, -1836, 12514, -1836,  6069,   573,
     618,  8987, -1836, -1836,   549,  9249, -1836, -1836, -1836,  1725,
   -1836,  1489,  6069, -1836, 12543,  1728,  8987,   -52,   -52,   -52,
     -52,   -52, -1836, -1836,  9933, 12572, 12601,   734, -1836, -1836,
   -1836, -1836, -1836,   740, -1836,  1496,  1498, -1836,  1733, -1836,
   -1836,    29, -1836,  1567, -1836, -1836, -1836, -1836,  9933, 11336,
   11369,  6069, -1836,  1737,  9933,  1505, -1836,  9933,  1536,  1537,
   -1836,  3932, -1836,  1510, -1836, -1836, -1836, -1836, 12630, -1836,
   -1836,  1535, 11402, 11435, 11468, 11501, 11534, -1836,   781,  1542,
     -52,  6069,  1770,  1545,   -52,  1775,   783,  1552, -1836,  9933,
   -1836,  1776,  1674,  7316,  1546, -1836,   790,   191,   207,   210,
     218,   226,  3543, -1836, -1836,  1777, -1836,  1779, -1836, -1836,
    1790, -1836,  1556, 15059,  9933,  9933,   791, -1836, 15059, 11567,
   -1836, -1836,  1163, 10450,  1561, -1836,  9933,  9933,  9933,  9933,
    9933,  9933,  1797,   -52,   113, -1836, -1836,   -52,   122, -1836,
    1798, -1836, 12659, -1836,  9933, -1836,   685, -1836,  1800,  8987,
    8987,  8987,  8987,  8751, -1836, -1836, -1836,  3544, -1836,  9933,
   15009, 11600,    28,  9933,  1564, -1836, -1836, 11633, 11666, 11699,
   11732, 11765, 11798, -1836,   240, -1836,   276, -1836, -1836, -1836,
    3595,   669,  7552, -1836,   796,   798,   803,   829,   294,   854,
    1565,   859, -1836,  9933, -1836,  6069, 12688, -1836,  9933,  9933,
    9933,  9933,  9933,  9933,   -52,   -52, -1836, -1836, -1836,   685,
    1806,  1807,  1808,  1809,  8987,  1810,  1813,  1815,  1580, 15034,
     864,  1817, 12717, 13004, 11831, 11864, 11897, 11930,   307,   309,
     697, -1836, -1836, -1836, -1836,   870, -1836, -1836, -1836,  2847,
   -1836,  1582, -1836,  1819, -1836,  9933,  9933,  9933,  9933,  9933,
    9933, -1836,  1821,   871, -1836,  1586,  6069, -1836, 12746, 12775,
   12804, 12833, 12862, 12891, -1836,  1823,  2847,  2847,   877, -1836,
   -1836, -1836, -1836,  1824,  1825, -1836, -1836,   878, -1836,  1826,
   -1836, -1836,  1828,  2847, -1836, -1836, -1836
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1836, -1836, -1836, -1836,   520, -1836, -1836, -1836, -1836,  -193,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836, -1836,  -685,   -54,    -1,  3127, -1836,  1418, -1836, -1836,
   -1836, -1836, -1836, -1836, -1835, -1836,   470,   295,    -5, -1836,
      33, -1836, -1836, -1836, -1836,   238,   506,  1840,     7,  -591,
    -275, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,  1863,
   -1836, -1836, -1836, -1836, -1189, -1190,  1864, -1663,  1867, -1836,
   -1836, -1836,  1319, -1836,     5, -1836, -1836, -1836, -1836,  2007,
   -1836, -1836,   495,   399,  1870, -1836,     4,  -680, -1836, -1836,
       3, -1836, -1626,   291,   102,  2344,   179,  -278,   189, -1836,
     -65,   451, -1836, -1836,  -496, -1836,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -543
static const yytype_int16 yytable[] =
{
     132,  1431,   812,   908,   909,   584,  1433,   504,  1928,  1002,
     113,  1783,  1816,   506,  1817,   617,   161,  1010,   152,   150,
     600,   155,   156,   139,   166,   151,   150,   266,   315,  1015,
     316,   376,   378,   333,  2064,   282,  1665,  1027,   621,   150,
     733,   161,     4,   310,   262,  1226,   734,  1036,   267,   337,
     166,   399,   400,   508,   592,   593,     5,   150,  -542,   501,
     283,   592,   593,   291,   293,   135,   296,   408,  1322,   266,
     387,   314,   418,   421,  1289,   903,   284,   285,   405,   262,
     592,   593,   910,   736,   336,  1426,  1428,   592,   593,   734,
    1022,   429,   592,   593,   150,   372,   592,   593,   136,   706,
     724,   914,   671,  1546,   673,   592,   593,   137,  1414,  1418,
     453,   682,   699,  1857,   700,   317,   153,  1432,   154,  2045,
    1123,   463,   722,   311,   592,   593,  1780,   138,  2047,   410,
     723,   406,   592,   593,   420,   420,   278,   592,   593,   279,
     412,   699,   420,   700,  1528,  1886,   592,   593,   594,   732,
     955,   728,   957,   431,  1134,   262,   731,  2034,  1887,   729,
     262,   553,   399,   400,   732,   262,   133,  1888,  1126,  1272,
     134,  1386,   420,  1127,   287,   288,   262,   141,   505,   262,
     262,   262,   262,   420,   507,   553,   289,   487,   142,   488,
     290,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   489,   490,   491,   492,   493,   494,
    1666,   496,   497,   312,   509,   107,   145,   499,   500,   553,
     502,   262,   107,  1290,  1291,  1292,  1293,   516,   517,   107,
    1427,  1429,  1948,  1431,   262,   107,   148,   262,   530,   107,
     162,   618,  1028,  1029,   163,   529,   143,   134,   167,   140,
     969,   262,   168,   107,   262,   262,   262,   262,   377,   379,
    2065,   334,   262,   262,   262,   162,  1001,  1282,   262,  1018,
     336,   313,  1227,   338,   167,   460,   461,   462,  1019,   587,
     588,   144,   699,   694,   700,  1986,   503,   596,   601,   153,
     107,   154,   388,   262,   262,   262,   389,   551,   899,   552,
     901,   902,   157,  1294,  1273,  1276,   158,   262,   262,   680,
     153,   146,   154,   592,   593,   399,   400,   915,   707,   725,
     708,   726,  -535,  1272,   709,   727,   147,   436,   260,   592,
     593,  1681,   441,   149,   646,   647,   648,   446,   592,   593,
     652,   653,   654,   655,   656,   657,   658,  1491,   659,  1028,
    1029,   459,   660,   661,  2060,   949,   664,   159,   592,   593,
     565,   566,   567,   395,   396,   397,   398,   268,   160,   674,
     269,   420,   270,   592,   593,   262,   262,   399,   400,  1889,
     554,   164,   555,  1104,   592,   593,   556,   399,   400,   399,
     400,   262,   983,  1008,  1890,  1114,  1275,   710,   613,   614,
     615,   399,   400,   732,   554,  1891,   555,   592,   593,   165,
     556,   385,   627,   628,  1272,   386,   741,   806,   169,   808,
     262,   810,   811,   592,   593,   170,   592,   593,  2019,  2090,
     699,   171,   700,   560,   592,   593,   172,  1375,  1229,  1376,
     825,   826,   592,   593,  2020,   399,   400,  2021,   678,   173,
     679,  1384,   695,   696,   556,  2022,   592,   593,  1617,  1618,
     457,  1315,  1398,  2023,  1400,   174,  1402,   262,  1404,   747,
     395,   396,   397,   398,   262,   802,   175,  2074,   699,   420,
     700,   420,   262,   420,   420,   420,  1249,   815,  1320,   638,
    2138,   134,   592,   593,   399,   400,   747,   262,   262,   262,
     262,   262,   420,   420,   262,   152,   306,   152,   307,   262,
     592,   593,   828,  2075,   830,   260,  1492,  1493,   603,   835,
    1657,  1658,   604,   592,   593,   592,   593,   395,   396,   397,
     398,  2084,   262,   287,   288,   395,   396,   397,   398,   371,
     860,   375,   531,   411,  2119,   289,  2120,  1917,   564,   295,
     176,   399,   400,   592,   593,  1918,   573,   575,   577,   399,
     400,  1473,   582,   177,   183,   262,   262,   184,   320,   595,
     185,   321,   956,   409,   958,   959,   960,   961,   962,   963,
     178,   965,   966,   967,   968,   906,   907,   973,   974,   975,
     588,   412,   412,   592,   593,   179,   430,   395,   396,   397,
    1009,   180,   182,   821,   822,   823,   824,   297,   186,   602,
    1513,   262,   262,   262,   699,  1173,   700,   181,   395,   396,
     397,   398,   747,   548,   549,   263,  1530,   746,   752,   550,
    1003,   747,   747,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   264,   420,   420,   420,   420,   971,   280,   420,
     420,   420,   152,   977,   265,   271,   262,  1041,   272,   976,
     757,   273,  1045,   274,   747,   699,   281,   700,   701,   683,
     684,    59,    60,    61,    62,   286,   543,   544,   676,   546,
     547,   548,   549,   592,   593,   697,    73,   550,   262,    76,
     699,   831,   700,  1012,   298,  1949,  1950,  1129,   299,   770,
    1130,  1951,  1799,   747,   300,   301,   294,   302,   303,   833,
     262,  1032,  1184,   747,  1251,   511,   262,  1252,   512,   420,
     305,   513,  1043,   514,   420,   304,   309,   687,   330,  1185,
     688,   318,   262,   689,   262,   690,   322,  1186,  1187,  1188,
    1953,  1954,   308,  1189,  1190,   319,  1951,   894,   895,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   275,   323,   868,
     276,   550,   277,   747,   990,  1184,   809,  1776,   991,   676,
     546,   547,   548,   549,   331,   157,   324,  1184,   550,  1017,
     262,   564,  1185,   935,   936,   937,  1682,   332,   329,  1144,
    1186,  1187,  1188,  1184,  1185,   170,  1189,  1190,  1691,  1020,
     341,   339,  1186,  1187,  1188,  1184,   340,  2051,  1189,  1190,
    1185,  1023,   342,  1331,  1024,  1332,  1025,  1430,  1186,  1187,
    1188,   343,  1185,   686,  1189,  1190,   373,   262,   978,  1132,
    1186,  1187,  1188,   747,  1168,  1169,  1189,  1190,   747,   747,
    1212,  1431,   262,  1213,   747,  1214,   384,   747,  1255,   747,
     262,  1285,   747,  1303,  1360,   747,   391,  -538,   747,  1383,
    1007,  1389,  1411,   747,  1518,   747,   747,  1519,   747,   390,
    2100,   747,  1520,   262,  1521,  1572,   747,  1601,   747,   747,
    1634,   747,  1031,  1688,   415,  1701,  1176,  1689,  1038,  -539,
    1431,  1792,  2077,  1182,  1835,   747,   416,  1193,  1836,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,   134,  1846,  1869,
    2121,   550,  1847,   747,   427,  1274,  1277,  1800,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,  1337,  1314,  1338,  1870,   550,  1885,
     829,   747,  1923,  1836,   429,  1941,  1924,  1975,  1760,  1836,
    1761,   747,  1105,  1976,   439,   444,   458,   732,   262,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,  1284,   495,  1499,   498,   550,   262,  1693,  1694,
     699,   510,   700,   865,   262,   262,   262,   262,   515,   878,
     881,   884,   887,   518,  2002,   519,  2010,   420,  1836,  1138,
     747,  1772,  1773,  2018,  2032,   150,   344,   747,  1836,  2080,
     520,  2081,  1323,   747,  1146,   747,  2082,  1365,  1366,   386,
     747,   561,   262,   262,  1330,   262,   562,   262,   262,   568,
     262,   569,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   570,  2083,   262,   571,  1170,   747,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   578,   581,  1385,  1387,
     354,   355,   356,   357,   583,   585,   605,  2085,   358,   359,
     360,   747,  2087,   361,   586,   362,  1924,  2111,   262,   420,
     420,  1836,   972,  2122,  2135,   619,   363,   747,  2136,   364,
    2149,  2152,   606,   607,  1836,  2153,   608,   609,   610,   611,
     262,   622,   616,   623,   624,   620,   633,   634,   625,   626,
     629,   630,   631,   641,   262,   262,   640,   649,   666,   650,
     651,   662,   663,   665,   667,   668,   393,   670,   669,   672,
     685,   691,   698,   531,  1153,   704,   705,   133,   738,  1465,
     711,   742,   764,  1467,   768,   743,   771,   772,   773,   774,
     803,   816,  1471,   818,  1472,   819,   820,  1474,   550,   834,
     863,   872,   873,   889,  1050,   891,  1305,  1306,  1307,  1308,
     893,   897,   262,  1675,   898,   900,   926,  1677,   928,   947,
     929,   931,   938,   939,   950,   262,   262,   262,   984,   989,
    1687,   993,  1004,   365,   366,   367,   262,   994,   995,   996,
     997,   420,  1005,  1006,   368,   420,  1016,  1515,   369,  1021,
     370,   107,  1035,  1037,   420,  1040,   420,  1385,  1387,   420,
    1042,  1044,  1047,  1051,  1048,  1355,  1052,  1076,  1460,  1055,
     262,  1056,  1058,  1059,  1060,  1061,   399,   400,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1514,  1070,  1071,  1072,   336,
    1073,  1077,  1265,  1957,  1102,  1504,  1505,  1103,  1111,  1112,
    1113,  1117,  1119,  1120,  1121,  1122,  1128,  1133,  1141,   420,
    1145,  1288,  1147,  1148,  1154,  1156,  1157,  1158,  1159,  1161,
    1160,  1162,  1903,  1163,  1179,  1164,  1171,  1205,  1180,  1183,
    1207,   262,  1218,  1219,  1220,  1232,  1221,  1391,  1233,  1245,
    1248,  1234,   262,  1254,  1258,  1237,  1259,  1247,   262,  1262,
    1257,  1263,  1264,  1280,  1281,  1300,  1333,  1334,   703,  1336,
    1286,  1339,  1340,  1287,  1342,  1316,  1344,  1345,  1346,  1347,
    1348,  1349,  1350,  1351,  1352,  1324,  1310,  1311,  1412,  1397,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   745,   546,   547,   548,   549,  1312,   262,
     262,   262,   550,  1335,   699,   262,   700,   262,  1341,   262,
    1313,   262,  1364,   262,   262,   262,  1319,  1343,  1464,  1354,
    1367,  1825,  1378,  1380,  1392,  1393,  1394,  1406,  1407,  1408,
     262,  1409,  1410,  1420,  1379,  1423,  1424,  1419,  1425,  1434,
    1435,   262,  1436,  1437,  1438,  1633,  1439,  1683,  1390,   262,
    1440,  1441,   262,  1442,  1446,  1447,  1445,  1448,  1449,  1450,
    1451,  1452,  1278,  1457,  1462,  1463,  1468,  1469,  1475,  1476,
    1477,  1490,  1478,  1482,  1714,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,  1484,  1495,  1496,  1501,   550,  1498,  1461,
    1506,  1502,  1512,  1527,  1508,   336,  1443,  1509,  1533,  1544,
    1543,   420,   420,  1545,  1510,  1549,  1553,   262,  1556,  1454,
    1455,  1456,  1531,  1542,  1557,  1559,  1547,  1562,  1548,  1554,
    1555,  1561,  1563,  1564,  1565,  1566,   420,  1567,  1568,  1569,
    1570,  1571,   262,  1581,  1130,  1592,   262,  1594,  1597,  1600,
    1595,  1596,  1605,  1749,  1614,  1606,  1625,  1615,  1616,  1630,
    1631,  1622,  1728,  1623,  1483,  1624,  1645,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,  1637,  1638,  1639,  1650,   550,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,  1805,  1640,  1641,  1807,   550,
    1642,  1647,  1651,  1652,  1656,  1679,  1670,  1660,  1963,  1684,
    1685,   262,   262,  1663,  1695,  1540,  1252,  1678,  1702,  1700,
    1715,  1703,  1705,  1706,  1646,  1707,  1552,  1708,  1709,   412,
     412,  1716,  1558,  1980,   262,  1721,  1729,  1730,   721,  1731,
     262,  1784,  1785,  1786,  1787,  1788,  1790,  1734,  1749,   262,
    1735,  1736,  1738,  1777,  1751,  1739,  1747,   420,  1750,  1753,
     420,  1755,  1756,  1757,  1758,  1759,  1762,  1781,  1782,  1791,
    1795,  1813,  1821,  1822,  1824,   262,  1828,  1812,  1840,  -540,
    1849,  1856,  1284,  1602,  1603,  1604,   336,  1814,   262,  1607,
    1845,  1608,  1867,  1609,  1854,  1610,  1868,  1611,  1612,  1613,
    1873,  1874,  1880,  2027,  1876,  1877,  1882,  1883,  1892,  1899,
    1900,  1894,  1906,  1907,  1628,  1908,  1909,  1913,  1911,  1912,
    1914,  1915,  1916,  1934,  1921,  1636,  1935,  1936,  1937,  1939,
    1940,  1960,  1961,  1644,  1965,  1977,   262,   187,   150,  1979,
    1978,  1981,  2052,  1987,   188,   189,   190,  -541,  1994,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   380,   209,   210,   211,
     212,   213,   214,  1537,   262,  1541,  2006,  1996,  1271,  1990,
    1991,  2009,  2013,  2025,  2003,  2026,   262,  2007,  2017,   220,
     221,   222,   223,  1763,  1764,  2011,  2028,   224,  2029,   262,
    2036,  1699,  2014,  2043,  2048,   420,  2053,  2067,  2086,   225,
     226,   227,  2101,  2102,  2103,  2104,  2106,   228,    21,  2107,
     229,  2108,  2109,  2112,  2126,  2127,  1719,  2134,  2137,  2145,
    2150,  2151,  2154,   262,  2155,  1529,  2061,  1584,  1725,  1929,
    1551,  1752,   262,   112,   737,  1904,  1933,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,   262,   122,   123,   262,   550,
     124,  1593,  1672,   130,  1823,  1955,     0,     0,     0,   262,
       0,   412,     0,   262,     0,     0,   875,     0,     0,     0,
    1967,  1968,  1969,  1970,  1971,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,   237,     0,  1673,  1699,   238,
       0,     0,     0,     0,   240,   241,   242,     0,   243,   244,
     245,     0,     0,  1796,   107,     0,     0,     0,   262,     0,
       0,     0,     0,  2004,     0,     0,     0,  2008,     0,     0,
     246,   381,     0,     0,     0,     0,     0,   248,     0,  1818,
       0,     0,   326,     0,     0,     0,   579,     0,     0,   251,
       0,  1897,  1827,     0,     0,     0,  1720,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,  1353,  2044,     0,     0,   550,
    2046,     0,     0,     0,     0,     0,   262,   262,   262,   262,
     262,     0,     0,     0,     0,     0,  2058,     0,     0,     0,
    1699,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2124,     0,     0,     0,     0,     0,
    1956,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,  1966,     0,     0,  1881,  1767,
       0,  2146,  2148,     0,     0,     0,     0,  2098,  2099,     0,
       0,   262,     0,     0,     0,     0,     0,     0,  2156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1444,     0,   420,     0,     0,  1804,
       0,     0,     0,   382,     0,     0,  1810,  1811,     0,     0,
       0,     0,     0,   262,     0,     0,     0,  1922,     0,     0,
       0,     0,  1819,   420,   420,     0,  1930,     0,     0,   407,
       0,     0,     0,   417,     0,     0,     0,   422,  1481,     0,
     420,     0,     0,     0,     0,     0,     0,     0,     0,  1699,
       0,     0,     0,     0,   432,   434,   437,   438,     0,   440,
     434,   442,   443,  1962,   445,   434,   447,   448,   449,   450,
     451,   452,     0,   454,   455,   456,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,  2054,  2055,
    2056,  2057,  2059,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1699,     0,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,  2005,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,   523,   525,   526,   434,     0,     0,
       0,     0,     0,  2105,     0,  1905,     0,     0,     0,     0,
     559,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   591,     0,  1932,
       0,     0,   591,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   612,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,   632,     0,   550,     0,   635,   636,   637,
       0,   639,     0,     0,     0,   642,   643,   644,     0,     0,
     645,     0,     0,     0,     0,     0,  1699,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,   675,     0,
       0,     0,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   692,   693,
       0,     0,     0,     0,     0,     0,     0,  1699,     0,     0,
       0,     0,   720,     0,     0,     0,     0,     0,     0,     0,
    1497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     523,     0,     0,     0,  2035,     0,   750,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   769,     0,     0,     0,     0,
       0,   775,   776,   777,   778,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   793,   794,
     795,   796,   797,   798,   799,   799,     0,   804,   805,     0,
     807,     0,   435,     0,     0,     0,   813,   435,     0,     0,
     817,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   799,     0,   435,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,   836,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   851,   853,   854,   855,   856,   857,   858,   859,
       0,   861,   862,     0,     0,     0,     0,     0,   869,   870,
     871,     0,     0,     0,     0,   877,   880,   883,   886,   888,
       0,   890,     0,   892,     0,   434,   434,     0,     0,     0,
       0,   524,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   521,   675,   911,     0,   435,     0,
     916,   917,   918,   919,   920,   921,   922,   923,   924,     0,
       0,     0,     0,   930,  1626,   932,     0,   933,     0,     0,
       0,   434,   434,   434,     0,     0,   940,   941,   942,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,   964,     0,     0,     0,     0,     0,     0,  1395,
       0,     0,     0,     0,     0,     0,   434,     0,     0,     0,
       0,   981,     0,   982,     0,   861,   862,     0,     0,     0,
       0,     0,   992,     0,     0,     0,     0,     0,   998,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,  1013,  1014,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     434,     0,  1033,  1034,     0,     0,   434,  1039,   150,   344,
       0,     0,     0,     0,     0,  1046,     0,     0,     0,  1049,
       0,     0,   851,     0,  1053,     0,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,  1074,     0,   524,   550,     0,
     345,   346,   347,   348,   349,   350,   351,   352,   353,     0,
       0,     0,     0,   354,   355,   356,   357,     0,     0,     0,
       0,   358,   359,   360,     0,     0,   361,     0,   362,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,   363,
       0,     0,   364,     0,   792,     0,     0,     0,     0,     0,
       0,   800,   801,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,   150,   344,     0,     0,   550,     0,   434,     0,   393,
       0,   827,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,  1152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   852,
       0,     0,     0,   345,   346,   347,   348,   349,   350,   351,
     352,   353,     0,   434,     0,     0,   354,   355,   356,   357,
       0,  1177,  1178,     0,   358,   359,   360,  1181,     0,   361,
       0,   362,   435,   435,     0,     0,   365,   366,   367,     0,
       0,     0,   363,  1206,     0,   364,  1208,   368,     0,     0,
       0,   369,     0,   370,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1222,     0,  1224,  1225,     0,
       0,     0,     0,     0,  1676,     0,     0,     0,   435,   435,
     435,     0,   393,   699,     0,   700,  1243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1261,     0,     0,     0,     0,     0,
       0,  1267,  1268,  1269,  1270,     0,     0,     0,     0,  1279,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1304,   434,   434,   434,   434,  1309,     0,
       0,     0,     0,     0,     0,     0,  1680,     0,     0,   365,
     366,   367,     0,     0,     0,   435,     0,     0,     0,     0,
     368,     0,     0,     0,   369,     0,   370,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,   435,     0,  1686,     0,     0,     0,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,   852,
       0,  1054,     0,     0,     0,     0,  1356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1357,  1358,  1359,     0,
       0,     0,     0,  1361,  1362,     0,  1363,     0,     0,     0,
       0,  1794,     0,     0,  1369,     0,  1370,  1371,  1372,  1373,
    1374,     0,     0,     0,     0,     0,     0,  1377,     0,     0,
       0,     0,     0,  1381,  1382,     0,     0,   435,     0,     0,
       0,     0,  1388,     0,     0,   434,  1872,     0,     0,     0,
       0,     0,     0,     0,     0,  1399,     0,  1401,     0,  1403,
       0,  1405,     0,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,  1422,  1898,   435,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1453,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,     0,     0,     0,
     435,     0,     0,     0,  1466,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,  1480,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1489,     0,     0,  1494,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
    1516,     0,     0,     0,     0,     0,     0,  1523,  1524,  1525,
    1526,     0,     0,     0,     0,     0,  1532,     0,  1534,  1536,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,   435,   435,   435,   435,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
     435,  1619,  1620,  1621,   550,     0,     0,     0,     0,     0,
    1627,     0,  1629,     0,     0,     0,     0,     0,     0,  1632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   434,     0,     0,     0,     0,  1648,     0,     0,
       0,     0,     0,     0,     0,  1653,  1654,  1655,     0,     0,
       0,     0,     0,     0,     0,  1664,     0,     0,     0,     0,
       0,     0,     0,     0,  1674,     0,     0,     0,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1690,
       0,     0,     0,     0,     0,  1696,  1697,  1910,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   702,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1723,     0,     0,  2024,
       0,     0,     0,     0,  1726,  1727,     0,     7,     8,     0,
       0,  1732,  1733,     0,     0,     0,     0,     0,  1737,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1740,  1741,  1742,     0,     0,
       0,     0,     0,  1743,  1744,  1745,  1746,     0,     0,     0,
       0,  2076,     0,  1748,     0,     0,     0,     0,     0,     0,
       0,     0,  1754,     0,     0,     0,     0,     0,     0,     0,
       0,   434,   434,  1765,     0,  1766,     0,   814,     0,     0,
       0,  1774,  1775,     0,     0,   712,    25,    26,   713,    28,
      29,   714,    31,   715,    33,    34,    35,    36,     0,     0,
     434,    38,    39,    40,  1793,     0,    42,     0,     0,     0,
       0,     0,   716,    48,     0,  1803,    50,   717,  1806,    53,
     718,     0,  1809,     0,     0,   986,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   866,     0,     0,    70,  1820,
       0,     0,   987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1832,     0,     0,     0,     0,  1838,  1839,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,  1841,     0,     0,  1842,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,  1866,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,  1875,     0,
     550,     0,     0,     0,     0,     0,     0,  1884,     0,   435,
       0,     0,     0,     0,     0,     0,   523,     0,     0,     0,
       0,     0,     0,     0,     0,  1895,  1896,     0,     0,   434,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
    1919,  1920,  1848,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1931,     0,     0,     0,     0,     0,
       0,  1938,     0,     0,     0,     0,     0,  1942,  1943,  1944,
    1945,  1946,     0,     0,     0,     0,     0,     0,   434,     0,
       0,     0,     0,  1724,     0,     0,     0,     0,     0,     7,
       8,     0,     0,   434,     0,     0,     0,     0,     0,     0,
       0,  1972,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,     0,  1090,  1091,  1092,  1093,     0,  1095,
    1096,  1097,  1098,     0,     0,  1983,     0,     0,     0,     0,
       0,  1988,     0,  1108,  1989,  1110,     0,     0,     0,  1993,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1124,  1125,     0,     0,     0,   435,   435,
       0,     0,  1135,     0,     0,     0,  2012,   712,    25,    26,
     713,    28,    29,   714,    31,   715,    33,    34,    35,    36,
     531,     0,     0,    38,    39,    40,     0,   435,    42,     0,
       0,  2030,  2031,     0,   716,    48,     0,     0,    50,   717,
       0,    53,   718,  2037,  2038,  2039,  2040,  2041,  2042,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,  2050,     0,     0,     0,     0,   434,   434,   434,   434,
     434,     0,     0,     0,     0,     0,  1838,     0,     0,     0,
    2066,     0,     0,     0,    84,    85,    86,     0,     0,     0,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   745,   546,   547,   548,   549,     0,     0,
    2089,     0,   550,     0,     0,  2092,  2093,  2094,  2095,  2096,
    2097,     0,  1228,  1230,  1231,     0,     0,     0,  1235,  1236,
       0,   434,  1239,  1240,  1241,  1242,     0,  1244,     0,     0,
       0,     0,  1250,     0,     0,     0,     0,     0,     0,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,   912,
       0,     0,  2128,  2129,  2130,  2131,  2132,  2133,     0,     0,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,   951,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,  1328,  1329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,     0,   187,   150,   344,     0,   392,     0,     0,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   380,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   220,   221,   222,   223,   354,   355,
     356,   357,   224,     0,     0,     0,   358,   359,   360,     0,
       0,   361,     0,   362,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   363,   229,     0,   364,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   745,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,   435,   435,   435,   435,   435,     0,     0,
       0,     0,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,  1136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1503,   394,     0,     0,     0,     0,     0,     0,
     237,   365,   366,   367,   238,     0,     0,     0,   435,   240,
     241,   242,   368,   243,   244,   245,   369,     0,   370,   107,
     395,   396,   397,   398,     0,     7,     8,     0,     0,     0,
    1538,     0,     0,     0,     0,   246,   381,     0,     0,     0,
       0,     0,   248,     0,   399,   400,     0,   401,     0,   402,
       0,     0,     0,   403,   251,     0,     0,     0,     0,     0,
       0,     0,     0,  1573,  1574,  1575,  1576,  1577,     0,     0,
       0,     0,  1582,  1583,     0,  1585,     0,     0,     0,     0,
       0,  1591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1599,     0,     0,     0,
       0,     0,     0,   712,    25,    26,   713,    28,    29,   714,
      31,   715,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     716,    48,     0,     0,    50,   717,     0,    53,   718,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1137,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1659,     0,  1662,     0,     0,     0,  1669,     0,  1671,
      84,    85,    86,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,  1692,     0,     0,   187,     6,   344,     0,     0,     0,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   934,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   220,   221,   222,   223,
     354,   355,   356,   357,   224,     0,     0,     0,   358,   359,
     360,     0,     0,   361,     0,   362,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   363,   229,     0,   364,
       0,     0,   230,     0,     0,   231,     0,     0,   232,     0,
     233,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,    49,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1829,  1830,   237,   365,   366,   367,   238,   239,     0,     0,
       0,   240,   241,   242,   368,   243,   244,   245,   369,  1459,
     370,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,     0,
       0,     0,     0,     0,   248,     0,     0,  1858,  1859,   326,
       0,     0,     0,  1539,     0,     0,   251,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     6,   344,     0,     0,     0,     0,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,  1901,  1902,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   220,   221,   222,   223,   354,   355,
     356,   357,   224,     0,     0,     0,   358,   359,   360,     0,
       0,   361,     0,   362,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   363,   229,     0,   364,     0,     0,
     230,     0,     0,   231,     0,     0,   232,     0,   233,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,    49,
       0,     0,   235,     0,   236,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,     0,     0,     0,     0,     0,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   365,   366,   367,   238,   239,     0,     0,     0,   240,
     241,   242,   368,   243,   244,   245,   369,     0,   370,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,   326,   187,     6,
     325,   250,     0,     0,   251,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     7,     8,     0,   228,    21,
       0,   229,     0,     0,     0,     0,   230,     0,     0,   231,
    2114,     0,   232,     0,   233,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,    49,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,   712,    25,    26,   713,    28,    29,   714,
      31,   715,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     716,    48,     0,     0,    50,   717,   237,    53,   718,     0,
     238,   239,     0,     0,     0,   240,   241,   242,     0,   243,
     244,   245,     0,     0,     0,   107,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,     0,   248,     0,
      84,    85,    86,   326,   187,     6,  1635,   250,     0,     0,
     251,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   979,   225,   226,   227,     0,
       0,     7,     8,     0,   228,    21,     0,   229,     0,     0,
       0,     0,   230,     0,     0,   231,     0,     0,   232,     0,
     233,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,    49,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   712,
      25,    26,   713,    28,    29,   714,    31,   715,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   716,    48,     0,     0,
      50,   717,   237,    53,   718,     0,   238,   239,     0,     0,
       0,   240,   241,   242,     0,   243,   244,   245,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,     0,
       0,     0,     0,     0,   248,     0,    84,    85,    86,   326,
     187,     6,     0,   250,     0,     0,   251,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   980,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,   229,     0,     0,     0,     0,   230,     0,
       0,   231,     0,     0,   232,     0,   233,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,    49,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,   712,    25,    26,   713,    28,
      29,   714,    31,   715,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   716,    48,     0,     0,    50,   717,   237,    53,
     718,     0,   238,   239,     0,     0,     0,   240,   241,   242,
       0,   243,   244,   245,     0,     0,     0,   107,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   597,  1789,     0,     0,     0,     0,     0,
     248,     0,    84,    85,    86,   599,   187,     6,     0,   290,
     527,     0,   251,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1172,   225,   226,
     227,     0,     0,     7,     8,     0,   228,    21,     0,   229,
       0,     0,     0,     0,   230,     0,     0,   231,     0,     0,
     232,     0,   233,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,    49,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,   712,    25,    26,   713,    28,    29,   714,    31,   715,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   716,    48,
       0,     0,    50,   717,   237,    53,   718,     0,   238,   239,
       0,     0,     0,   240,   241,   242,     0,   243,   244,   245,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,     0,     0,   248,     0,    84,    85,
      86,   249,   187,     6,     0,   250,     0,     0,   251,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1174,   225,   226,   227,     0,     0,     7,
       8,     0,   228,    21,     0,   229,     0,     0,     0,     0,
     230,     0,     0,   231,     0,     0,   232,     0,   233,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,    49,
       0,     0,   235,     0,   236,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,   712,    25,    26,
     713,    28,    29,   714,    31,   715,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   716,    48,     0,     0,    50,   717,
     237,    53,   718,     0,   238,   239,     0,     0,     0,   240,
     241,   242,     0,   243,   244,   245,     0,     0,     0,   107,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,   248,     0,    84,    85,    86,   326,   187,     6,
       0,   250,     0,     0,   251,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1175,
     225,   226,   227,     0,     0,     7,     8,     0,   228,    21,
       0,   229,     0,     0,     0,     0,   230,     0,     0,   231,
       0,     0,   232,     0,   233,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,    49,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,   712,    25,    26,   713,    28,    29,   714,
      31,   715,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     716,    48,     0,     0,    50,   717,   237,    53,   718,     0,
     238,   239,     0,     0,     0,   240,   241,   242,     0,   243,
     244,   245,     0,     0,     0,   107,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   433,     0,     0,     0,     0,     0,   248,     0,
      84,    85,    86,   326,   187,     6,     0,   522,     0,     0,
     251,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,   225,   226,   227,     0,
       0,     7,     8,     0,   228,    21,     0,   229,     0,     0,
       0,     0,   230,     0,     0,   231,     0,     0,   232,     0,
     233,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,    49,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   712,
      25,    26,   713,    28,    29,   714,    31,   715,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   716,    48,     0,     0,
      50,   717,   237,    53,   718,     0,   238,   239,     0,     0,
       0,   240,   241,   242,     0,   243,   244,   245,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   433,     0,
       0,     0,     0,     0,   248,     0,    84,    85,    86,   326,
     187,     6,     0,     0,   527,     0,   251,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1223,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,   229,     0,     0,     0,     0,   230,     0,
       0,   231,     0,     0,   232,     0,   233,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,    49,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,   712,    25,    26,   713,    28,
      29,   714,    31,   715,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   716,    48,     0,     0,    50,   717,   237,    53,
     718,     0,   238,   239,     0,     0,     0,   240,   241,   242,
       0,   243,   244,   245,     0,     0,     0,   107,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,     0,     0,
     248,     0,    84,    85,    86,   563,   187,     6,     0,   250,
       0,     0,   251,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1256,   225,   226,
     227,     0,     0,     7,     8,     0,   228,    21,     0,   229,
       0,     0,     0,     0,   230,     0,     0,   231,     0,     0,
     232,     0,   233,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,    49,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,   712,    25,    26,   713,    28,    29,   714,    31,   715,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   716,    48,
       0,     0,    50,   717,   237,    53,   718,     0,   238,   239,
       0,     0,     0,   240,   241,   242,     0,   243,   244,   245,
       0,     0,     0,   107,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,     0,     0,   248,     0,    84,    85,
      86,   572,   187,     6,     0,   250,     0,     0,   251,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1413,   225,   226,   227,     0,     0,     7,
       8,     0,   228,    21,     0,   229,     0,     0,     0,     0,
     230,     0,     0,   231,     0,     0,   232,     0,   233,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,    49,
       0,     0,   235,     0,   236,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,   712,    25,    26,
     713,    28,    29,   714,    31,   715,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   716,    48,     0,     0,    50,   717,
     237,    53,   718,     0,   238,   239,     0,     0,     0,   240,
     241,   242,     0,   243,   244,   245,     0,     0,     0,   107,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,   248,     0,    84,    85,    86,   574,   187,     6,
       0,   250,     0,     0,   251,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2015,
     225,   226,   227,     0,     0,     7,     8,     0,   228,    21,
       0,   229,     0,     0,     0,     0,   230,     0,     0,   231,
       0,     0,   232,     0,   233,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,    49,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,   712,    25,    26,   713,    28,    29,   714,
      31,   715,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     716,    48,     0,     0,    50,   717,   237,    53,   718,     0,
     238,   239,     0,     0,     0,   240,   241,   242,     0,   243,
     244,   245,     0,     0,     0,   107,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,     0,   248,     0,
      84,    85,    86,   576,   187,     6,     0,   250,     0,     0,
     251,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2078,   225,   226,   227,     0,
       0,     7,     8,     0,   228,    21,     0,   229,     0,     0,
       0,     0,   230,     0,     0,   231,     0,     0,   232,     0,
     233,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,    49,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   712,
      25,    26,   713,    28,    29,   714,    31,   715,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   716,    48,     0,     0,
      50,   717,   237,    53,   718,     0,   238,   239,     0,     0,
       0,   240,   241,   242,     0,   243,   244,   245,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   433,     0,
       0,     0,     0,     0,   248,     0,    84,    85,    86,   326,
     187,   150,   344,   850,     0,     0,   251,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   380,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   220,   221,   222,   223,   354,   355,   356,   357,
     224,     0,     0,     0,   358,   359,   360,     0,     0,   361,
       0,   362,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   363,   229,     0,   364,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   344,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
     699,     0,   700,     0,     0,     0,     0,     0,  1661,     0,
       0,     0,     0,     0,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,     0,     0,     0,     0,   354,
     355,   356,   357,     0,     0,     0,     0,   358,   359,   360,
       0,     0,   361,     0,   362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,     0,     0,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   365,
     366,   367,   238,     0,     0,     0,     0,   240,   241,   242,
     368,   243,   244,   245,   369,     0,   370,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   381,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,   326,   187,     6,     0,  1535,
       0,     0,   251,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,   365,   366,   367,     0,     0,     0,   220,   221,
     222,   223,     0,   368,     0,     0,   224,   369,     0,   370,
     107,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,     0,   229,
       0,     0,     0,     0,   230,     0,     0,   231,     0,     0,
     232,     0,   233,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,    49,     0,     0,   235,     0,   236,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   943,     0,
       0,     0,     0,     0,     0,     0,   904,     0,     0,     0,
       0,     0,     0,     0,   237,     0,     0,     0,   238,   239,
       0,     0,     0,   240,   241,   242,     0,   243,   244,   245,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,   326,   187,   150,   344,  1643,     0,     0,   251,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   380,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   220,   221,   222,   223,   354,   355,
     356,   357,   224,     0,     0,     0,   358,   359,   360,     0,
       0,   361,     0,   362,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   363,   229,     0,   364,   187,   150,
     344,     0,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   380,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     220,   221,   222,   223,   354,   355,   356,   357,   224,     0,
       0,     0,   358,   359,   360,     0,     0,   361,     0,   362,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     363,   229,     0,   364,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   365,   366,   367,   238,     0,     0,     0,     0,   240,
     241,   242,   368,   243,   244,   245,   369,     0,   370,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   381,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,   326,     0,     0,
       0,  1802,     0,     0,   251,     0,     0,     0,     0,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,   237,   365,   366,   367,
     238,   730,     0,     0,     0,   240,   241,   242,   368,   243,
     244,   245,   369,     0,   370,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   381,     0,     0,     0,     0,     0,   248,     0,
       0,     0,     0,   326,   187,     6,     0,  1808,     0,     0,
     251,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,     0,   229,     0,     0,
       0,     0,   230,     0,     0,   231,     0,     0,   232,     0,
     233,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,    49,     0,     0,   235,     0,   236,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
    1770,     0,     0,     0,  1771,     0,     0,     0,     0,     0,
       0,     0,   237,     0,     0,     0,   238,   239,     0,     0,
       0,   240,   241,   242,     0,   243,   244,   245,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,  1789,     0,
       0,     0,     0,     0,   248,     0,     0,     0,     0,   599,
     187,     6,     0,   290,     0,     0,   251,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,   229,     0,     0,     0,     0,   230,     0,
       0,   231,     0,     0,   232,     0,   233,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,    49,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,  1797,     0,     0,     0,
    1798,     0,     0,     0,     0,     0,     0,     0,   237,     0,
       0,     0,   238,   239,     0,     0,     0,   240,   241,   242,
       0,   243,   244,   245,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   433,     0,     0,     0,     0,     0,
     248,   187,   150,   344,     0,   326,     0,     0,   188,   189,
     190,     0,   251,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     380,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   220,   221,   222,   223,   354,   355,   356,
     357,   224,     0,     0,     0,   358,   359,   360,     0,     0,
     361,     0,   362,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,   363,   229,     0,   364,   187,   150,     0,
       0,     0,     0,     0,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   380,   209,   210,   211,
     212,   213,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,     0,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     365,   366,   367,   238,     0,     0,     0,     0,   240,   241,
     242,   368,   243,   244,   245,   369,     0,   370,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   381,     0,     0,     0,     0,
       0,   248,     0,     0,     0,     0,   326,     0,     0,     0,
       0,     0,     0,   251,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,  1958,     0,     0,   237,  1959,     0,     0,   238,
       0,     0,     0,     0,   240,   241,   242,     0,   243,   244,
     245,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,   598,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,   599,     0,   187,   150,   290,  1260,     0,   251,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   380,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,     0,   229,   187,   150,
       0,  1421,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   380,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
       0,   229,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,   237,     0,   550,     0,   238,     0,     0,     0,
       0,   240,   241,   242,   904,   243,   244,   245,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   381,     0,
       0,     0,     0,     0,   248,     0,     0,     0,     0,   326,
       0,     0,     0,     0,     0,     0,   251,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,   237,     0,     0,   905,
     238,     0,     0,     0,     0,   240,   241,   242,     0,   243,
     244,   245,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   381,     0,     0,     0,     0,     0,   248,   187,
     150,     0,  1479,   326,     0,     0,   188,   189,   190,     0,
     251,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   380,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,   187,   150,     0,   228,
      21,     0,   229,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   380,   209,   210,   211,   212,
     213,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,     0,   229,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,   237,     0,     0,
       0,   238,   948,     0,     0,     0,   240,   241,   242,     0,
     243,   244,   245,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   381,     0,     0,     0,     0,     0,   248,
       0,     0,     0,     0,   326,     0,     0,     0,     0,     0,
       0,   251,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,     0,   237,     0,     0,     0,   238,     0,
       0,     0,     0,   240,   241,   242,     0,   243,   244,   245,
       0,     0,     0,   107,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     381,     0,     0,     0,     0,     0,   248,    -4,    -4,    -4,
       0,   326,     0,    -4,    -4,     0,    -4,     0,   251,     0,
       0,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,    -4,
      -4,    -4,     0,     0,     0,    -4,     7,     8,     0,     0,
      -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,     9,    10,     0,
      -4,    -4,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,     0,     0,     0,    11,    12,    13,
       0,     0,     0,    14,    15,     0,    16,     0,     0,     0,
       0,    17,    18,     0,    19,    20,     0,    21,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,    37,
      38,    39,    40,    41,     0,    42,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
      80,    81,     0,     0,     0,    82,     0,     0,     0,     0,
      83,    84,    85,    86,   374,   344,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,   344,     0,     0,     0,     0,
       0,   106,     0,   107,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,     0,     0,     0,     0,   354,
     355,   356,   357,     0,     0,     0,     0,   358,   359,   360,
       0,     0,   361,     0,   362,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   363,     0,     0,   364,   354,
     355,   356,   357,     0,     0,     0,     0,   358,   359,   360,
       0,     0,   361,     0,   362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,     0,     0,   364,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1089,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1099,     0,     0,     0,     0,     0,
       0,     0,   365,   366,   367,     0,     0,     0,     0,     0,
       0,     0,     0,   368,     0,     0,     0,   369,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   365,   366,   367,     0,     0,     0,     0,     0,
       0,     0,     0,   368,     0,     0,     0,   369,     0,   370,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1101,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1106,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1107,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1109,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1217,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1238,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1321,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1415,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1416,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1458,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1578,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1579,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1580,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1586,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1587,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1588,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1589,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1718,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1833,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1834,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1860,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1861,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1862,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1863,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1864,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1927,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1984,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1985,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1997,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1998,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1999,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2000,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2001,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2033,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2063,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2068,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2069,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2070,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2071,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2072,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2073,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2115,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2116,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2117,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2118,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,  1026,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,  1118,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,  1197,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,  1266,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,  1417,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,  1485,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
    1486,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,  1487,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,  1488,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,  1768,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,  1779,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,  1815,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,  1850,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,  1851,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,  1852,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,  1853,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
    1855,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,  1878,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,  1893,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,  1947,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,  1964,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,  1973,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,  1974,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,  1995,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,  2049,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,  2091,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
    2113,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,  2139,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,  2140,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,  2141,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,  2142,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,  2143,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,     0,     0,  2144,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,   677,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,     0,
     896,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,  1871,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   699,     0,   700,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,   954,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,  1000,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,  1140,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,  1143,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,     0,     0,
    1210,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   676,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,  1211,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   676,   546,   547,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,  1215,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   676,   546,
     547,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,  1216,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   676,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,  1302,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,  1318,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   676,
     546,   547,   548,   549,     0,     0,     0,     0,   550,     0,
       0,     0,  1517,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   676,   546,   547,   548,
     549,     0,     0,     0,     0,   550,     0,     0,     0,  1649,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   676,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,  1826,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     676,   546,   547,   548,   549,     0,     0,     0,     0,   550,
       0,     0,     0,  1879,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   744,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   748,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   749,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   751,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   753,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   754,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   756,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   758,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   759,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   760,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   761,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   762,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   763,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   765,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   766,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   767,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   832,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   867,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   925,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   943,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   944,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   945,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   946,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   952,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   953,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,   985,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,   999,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1057,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1062,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1075,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1139,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1142,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1149,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1150,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1151,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1165,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1166,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1167,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1196,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1198,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1199,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1200,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1201,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1202,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1203,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1204,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1209,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1301,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1317,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1522,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1590,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1598,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1704,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1710,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1711,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1712,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1713,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1717,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1769,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1778,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1801,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1865,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  1925,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  1926,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550,     0,  2062,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   676,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,  2110,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   676,   546,   547,
     548,   549,     0,     0,     0,     0,   550
};

static const yytype_int16 yycheck[] =
{
       3,  1191,   498,   594,   595,   283,  1195,     5,  1843,   694,
       3,  1637,  1675,     5,  1677,     4,     4,   702,    21,     4,
     295,    22,    23,     6,     4,    21,     4,    97,     4,   709,
       6,     5,     5,     4,     6,   148,     4,     6,   313,     4,
     241,     4,     6,     4,    47,     7,   247,   727,   118,     4,
       4,   235,   236,     5,   226,   227,     0,     4,   242,     5,
     173,   226,   227,    60,    61,    14,    63,   132,     7,    97,
       6,    74,   137,   138,     4,   247,   189,   190,   132,    82,
     226,   227,   247,   241,    87,     6,     6,   226,   227,   247,
     118,     9,   226,   227,     4,    98,   226,   227,    97,     9,
       9,   247,   377,     6,   379,   226,   227,   238,   247,   243,
     175,   386,   239,  1739,   241,    91,   238,   247,   240,     6,
     247,   186,   239,    84,   226,   227,   247,   238,     6,   132,
     247,   132,   226,   227,   137,   138,    94,   226,   227,    97,
     133,   239,   145,   241,     6,   247,   226,   227,   242,   247,
     646,   239,   648,   156,   834,   158,   239,  1992,   247,   247,
     163,     9,   235,   236,   247,   168,   242,   247,   239,     7,
     246,   244,   175,   244,   226,   227,   179,     6,   176,   182,
     183,   184,   185,   186,   176,     9,   238,   238,     6,   240,
     242,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     188,   222,   223,   184,   176,   210,   238,   228,   229,     9,
     176,   234,   210,   163,   164,   165,   166,   238,   239,   210,
     161,   161,  1868,  1433,   247,   210,   240,   250,   251,   210,
     238,   240,   221,   222,   242,   251,     6,   246,   238,   242,
     245,   264,   242,   210,   267,   268,   269,   270,   242,   242,
     242,   242,   275,   276,   277,   238,     7,   242,   281,   242,
     283,   242,   244,   238,   238,   183,   184,   185,   242,   286,
     287,     6,   239,     4,   241,  1921,   242,   294,   295,   238,
     210,   240,   238,   306,   307,   308,   242,   238,   583,   240,
     585,   586,   238,   243,   999,  1000,   242,   320,   321,   384,
     238,     6,   240,   226,   227,   235,   236,   602,   238,   238,
     240,   240,   242,     7,   244,   244,     6,   158,    47,   226,
     227,     7,   163,   240,   345,   346,   347,   168,   226,   227,
     351,   352,   353,   354,   355,   356,   357,     4,   359,   221,
     222,   182,   363,   364,  2027,   640,   367,   238,   226,   227,
     268,   269,   270,   211,   212,   213,   214,    94,   238,   380,
      97,   384,    99,   226,   227,   388,   389,   235,   236,   247,
     238,   238,   240,   241,   226,   227,   244,   235,   236,   235,
     236,   404,   677,     7,   247,   239,   244,   410,   306,   307,
     308,   235,   236,   247,   238,   247,   240,   226,   227,   238,
     244,   238,   320,   321,     7,   242,   429,   492,   238,   494,
     433,   496,   497,   226,   227,   238,   226,   227,   247,  2065,
     239,   238,   241,   264,   226,   227,   238,  1127,   247,  1129,
     515,   516,   226,   227,   247,   235,   236,   247,   238,   238,
     240,  1141,   173,   174,   244,   247,   226,   227,     6,     7,
     179,   239,  1157,   247,  1159,   238,  1161,   480,  1163,   247,
     211,   212,   213,   214,   487,   488,   238,   247,   239,   492,
     241,   494,   495,   496,   497,   498,   247,   500,   239,   244,
    2126,   246,   226,   227,   235,   236,   247,   510,   511,   512,
     513,   514,   515,   516,   517,   518,    97,   520,    99,   522,
     226,   227,   518,   247,   520,   234,   173,   174,   238,   530,
       6,     7,   242,   226,   227,   226,   227,   211,   212,   213,
     214,   247,   545,   226,   227,   211,   212,   213,   214,    98,
     553,   100,     8,     4,   247,   238,   247,   239,   267,   242,
     238,   235,   236,   226,   227,   247,   275,   276,   277,   235,
     236,  1251,   281,   238,    91,   578,   579,    94,    94,   242,
      97,    97,   647,   132,   649,   650,   651,   652,   653,   654,
     238,   656,   657,   658,   659,   592,   593,   662,   663,   664,
     597,   594,   595,   226,   227,   111,   155,   211,   212,   213,
     214,    97,   242,   511,   512,   513,   514,     4,   238,   242,
    1300,   624,   625,   626,   239,   900,   241,     6,   211,   212,
     213,   214,   247,   231,   232,   238,  1316,   243,   243,   237,
     694,   247,   247,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   242,   656,   657,   658,   659,   660,   238,   662,
     663,   664,   665,   666,    97,    91,   669,   732,    94,   665,
     243,    97,   737,    99,   247,   239,    94,   241,   242,   388,
     389,   132,   133,   134,   135,   242,   226,   227,   228,   229,
     230,   231,   232,   226,   227,   404,   147,   237,   701,   150,
     239,   522,   241,   706,    91,   132,   133,   244,    95,   243,
     247,   138,     8,   247,   101,   102,   242,   104,   105,   243,
     723,   724,   128,   247,   244,    91,   729,   247,    94,   732,
     238,    97,   735,    99,   737,   122,    94,    91,   238,   145,
      94,    94,   745,    97,   747,    99,     4,   153,   154,   155,
     132,   133,    97,   159,   160,    97,   138,   578,   579,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    94,     4,   243,
      97,   237,    99,   247,   243,   128,   495,   243,   247,   228,
     229,   230,   231,   232,   238,   238,     4,   128,   237,   242,
     803,   510,   145,   624,   625,   626,  1491,   238,     4,   863,
     153,   154,   155,   128,   145,   238,   159,   160,  1503,   242,
       6,   238,   153,   154,   155,   128,   238,  2016,   159,   160,
     145,    94,     6,    97,    97,    99,    99,   243,   153,   154,
     155,   240,   145,   392,   159,   160,   238,   850,   669,   243,
     153,   154,   155,   247,   243,   243,   159,   160,   247,   247,
     243,  2051,   865,   243,   247,   243,   240,   247,   243,   247,
     873,   243,   247,   238,   243,   247,   246,   242,   247,   243,
     701,   243,   243,   247,   243,   247,   247,   243,   247,     6,
    2079,   247,   243,   896,   243,   243,   247,   243,   247,   247,
     243,   247,   723,   243,   242,   238,   903,   247,   729,   242,
    2100,   243,   243,   910,   243,   247,     6,   914,   247,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   246,   243,   243,
     243,   237,   247,   247,   238,   999,  1000,   243,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    97,  1030,    99,   243,   237,   243,
     519,   247,   243,   247,     9,   243,   247,   243,     4,   247,
       6,   247,   803,   243,   238,   238,   238,   247,   991,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,  1005,   238,  1282,   238,   237,  1010,  1504,  1505,
     239,   118,   241,   242,  1017,  1018,  1019,  1020,   238,   568,
     569,   570,   571,   238,   243,   238,   243,  1030,   247,   850,
     247,  1622,  1623,   243,   243,     4,     5,   247,   247,   243,
     238,   243,  1043,   247,   865,   247,   243,  1112,  1113,   242,
     247,   238,  1055,  1056,  1051,  1058,   238,  1060,  1061,   238,
    1063,   238,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,   238,   243,  1076,   238,   896,   247,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   242,     4,  1142,  1143,
      59,    60,    61,    62,   242,   242,   238,   243,    67,    68,
      69,   247,   243,    72,   242,    74,   247,   243,  1111,  1112,
    1113,   247,   661,   243,   243,     6,    85,   247,   247,    88,
     243,   243,   238,   238,   247,   247,   238,   238,   238,   238,
    1133,     6,   238,     6,   242,   240,     6,     6,   242,   242,
     240,   240,   240,   176,  1147,  1148,   242,   238,   240,   238,
     238,   238,   238,   238,     6,     6,   125,     6,   242,     6,
     242,     7,     6,     8,   873,   242,     6,   242,    87,  1234,
     243,   247,   239,  1238,     7,   247,     6,     6,     6,   239,
     242,    64,  1247,    64,  1249,    64,    64,  1252,   237,   244,
       4,     7,     7,     6,   743,     6,  1017,  1018,  1019,  1020,
       6,   239,  1205,  1478,     6,   242,     7,  1482,     6,   173,
       7,     6,     6,     6,   242,  1218,  1219,  1220,   241,   239,
    1498,     6,   244,   192,   193,   194,  1229,   242,   242,   242,
     242,  1234,     7,     6,   203,  1238,   240,  1302,   207,   238,
     209,   210,     4,     6,  1247,     6,  1249,  1301,  1302,  1252,
       6,     6,   239,     7,   240,  1076,   176,   242,     8,     7,
    1263,     7,     7,   176,     7,     7,   235,   236,     7,   176,
       7,     7,     7,     7,     7,   244,     7,     7,     7,  1282,
       7,     6,   991,  1874,   239,  1286,  1287,   241,   247,   247,
     247,   242,   242,   242,   242,   247,   239,     7,   244,  1302,
     238,  1010,     7,   242,     4,     6,   239,   247,   239,   239,
     247,   247,  1808,   239,   243,   247,   244,     7,   243,   128,
       6,  1324,     7,     7,     7,   239,   244,  1148,   239,     9,
     239,   247,  1335,   241,     7,   247,   148,   247,  1341,   243,
     246,   242,     6,     6,     4,   244,  1055,  1056,     6,  1058,
      46,  1060,  1061,    46,  1063,   244,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,     4,   238,   238,     4,     6,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   238,  1392,
    1393,  1394,   237,     7,   239,  1398,   241,  1400,     7,  1402,
     238,  1404,  1111,  1406,  1407,  1408,   238,    99,  1229,     7,
     247,  1689,   239,   238,     7,     7,     7,     7,     7,     7,
    1423,     7,     7,     4,  1133,   242,     6,   109,   238,     7,
       6,  1434,     7,     7,     7,  1432,     7,  1491,  1147,  1442,
       7,     7,  1445,     7,     6,     6,   242,     6,    97,     7,
       6,     6,  1001,     4,     4,     4,   245,   247,   239,   247,
     242,     6,   242,   242,  1529,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   243,     6,     6,     6,   237,     7,   239,
       6,   240,     6,     6,   238,  1498,  1205,   238,     6,     6,
     247,  1504,  1505,     6,   242,   122,     6,  1510,     6,  1218,
    1219,  1220,   244,   241,     6,   176,   242,     6,   242,   242,
     242,   242,     6,     6,     6,     6,  1529,     6,     6,     6,
       6,     5,  1535,   239,   247,   239,  1539,     6,     4,     6,
     239,   238,     4,  1597,   242,     6,   240,   242,     7,     6,
       6,   242,  1549,   242,  1263,   242,     6,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   242,   242,   242,     6,   237,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,  1660,   242,   242,  1663,   237,
     242,   242,     6,   172,     6,     6,   239,   247,  1883,   244,
       7,  1614,  1615,   247,   238,  1324,   247,   247,     4,   242,
     238,     6,     6,     6,  1445,     6,  1335,     6,     6,  1622,
    1623,     4,  1341,  1911,  1637,     7,     6,     6,     6,     6,
    1643,  1638,  1639,  1640,  1641,  1642,  1643,     6,  1702,  1652,
      95,     6,     5,   247,     6,   242,   239,  1660,   242,     6,
    1663,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   239,     6,     4,     6,  1678,     6,   247,     6,   242,
       7,     5,  1685,  1392,  1393,  1394,  1689,   247,  1691,  1398,
     242,  1400,     6,  1402,   242,  1404,   242,  1406,  1407,  1408,
       6,   242,     6,  1978,   243,   243,     7,   242,     6,     6,
     239,   171,   243,   243,  1423,   243,     6,   244,     7,     6,
       6,     6,     6,     6,   242,  1434,     6,     6,     6,     6,
       6,     6,   243,  1442,     6,   239,  1739,     3,     4,     6,
     242,   174,  2017,     6,    10,    11,    12,   242,   238,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,  1322,  1777,  1324,     6,   242,     6,   243,
     243,     6,     6,     6,   242,     6,  1789,   242,   242,    55,
      56,    57,    58,  1614,  1615,   243,     6,    63,   242,  1802,
     239,  1510,   128,     6,     6,  1808,     6,   243,   243,    75,
      76,    77,     6,     6,     6,     6,     6,    83,    84,     6,
      86,     6,   242,     6,   242,     6,  1535,     6,   242,     6,
       6,     6,     6,  1836,     6,  1315,  2029,  1367,  1543,  1844,
    1334,  1603,  1845,     3,   426,  1812,  1849,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,  1868,     3,     3,  1871,   237,
       3,  1376,  1473,     3,  1685,  1870,    -1,    -1,    -1,  1882,
      -1,  1874,    -1,  1886,    -1,    -1,   567,    -1,    -1,    -1,
    1887,  1888,  1889,  1890,  1891,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1921,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    -1,  1476,  1637,   195,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,  1652,   210,    -1,    -1,    -1,  1951,    -1,
      -1,    -1,    -1,  1950,    -1,    -1,    -1,  1954,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,  1678,
      -1,    -1,   238,    -1,    -1,    -1,   242,    -1,    -1,   245,
      -1,  1802,  1691,    -1,    -1,    -1,  1535,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,     6,  2003,    -1,    -1,   237,
    2007,    -1,    -1,    -1,    -1,    -1,  2019,  2020,  2021,  2022,
    2023,    -1,    -1,    -1,    -1,    -1,  2023,    -1,    -1,    -1,
    1739,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2109,    -1,    -1,    -1,    -1,    -1,
    1871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2065,    -1,    -1,  1886,    -1,    -1,  1777,  1618,
      -1,  2136,  2137,    -1,    -1,    -1,    -1,  2074,  2075,    -1,
      -1,  2084,    -1,    -1,    -1,    -1,    -1,    -1,  2153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,  2109,    -1,    -1,  1658,
      -1,    -1,    -1,   106,    -1,    -1,  1665,  1666,    -1,    -1,
      -1,    -1,    -1,  2126,    -1,    -1,    -1,  1836,    -1,    -1,
      -1,    -1,  1681,  2136,  2137,    -1,  1845,    -1,    -1,   132,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,     6,    -1,
    2153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1868,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,  1882,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2019,  2020,
    2021,  2022,  2023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1921,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,  1951,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,    -1,  2084,    -1,  1814,    -1,    -1,    -1,    -1,
     263,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   289,   290,    -1,  1848,
      -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   305,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,   326,    -1,   237,    -1,   330,   331,   332,
      -1,   334,    -1,    -1,    -1,   338,   339,   340,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,  2065,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,    -1,
      -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,   402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2126,    -1,    -1,
      -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     433,    -1,    -1,    -1,  1993,    -1,   439,    -1,    -1,    -1,
      -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,    -1,   490,   491,    -1,
     493,    -1,   158,    -1,    -1,    -1,   499,   163,    -1,    -1,
     503,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   517,    -1,   182,    -1,    -1,   522,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
      -1,   554,   555,    -1,    -1,    -1,    -1,    -1,   561,   562,
     563,    -1,    -1,    -1,    -1,   568,   569,   570,   571,   572,
      -1,   574,    -1,   576,    -1,   578,   579,    -1,    -1,    -1,
      -1,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   597,   598,   599,    -1,   264,    -1,
     603,   604,   605,   606,   607,   608,   609,   610,   611,    -1,
      -1,    -1,    -1,   616,     6,   618,    -1,   620,    -1,    -1,
      -1,   624,   625,   626,    -1,    -1,   629,   630,   631,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,   655,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,
      -1,   674,    -1,   676,    -1,   678,   679,    -1,    -1,    -1,
      -1,    -1,   685,    -1,    -1,    -1,    -1,    -1,   691,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   701,    -1,
      -1,    -1,    -1,    -1,   707,   708,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     723,    -1,   725,   726,    -1,    -1,   729,   730,     4,     5,
      -1,    -1,    -1,    -1,    -1,   738,    -1,    -1,    -1,   742,
      -1,    -1,   745,    -1,   747,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   768,    -1,   433,   237,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
     803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,   487,   488,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,     4,     5,    -1,    -1,   237,    -1,   850,    -1,   125,
      -1,   517,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,
      -1,    -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,   872,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,   896,    -1,    -1,    59,    60,    61,    62,
      -1,   904,   905,    -1,    67,    68,    69,   910,    -1,    72,
      -1,    74,   578,   579,    -1,    -1,   192,   193,   194,    -1,
      -1,    -1,    85,   926,    -1,    88,   929,   203,    -1,    -1,
      -1,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   948,    -1,   950,   951,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   624,   625,
     626,    -1,   125,   239,    -1,   241,   969,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   987,    -1,    -1,    -1,    -1,    -1,
      -1,   994,   995,   996,   997,    -1,    -1,    -1,    -1,  1002,
      -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1016,  1017,  1018,  1019,  1020,  1021,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,   192,
     193,   194,    -1,    -1,    -1,   701,    -1,    -1,    -1,    -1,
     203,    -1,    -1,    -1,   207,    -1,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,    -1,
      -1,    -1,    -1,   729,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1076,    -1,    -1,    -1,    -1,    -1,   745,
      -1,   747,    -1,    -1,    -1,    -1,  1089,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1099,  1100,  1101,    -1,
      -1,    -1,    -1,  1106,  1107,    -1,  1109,    -1,    -1,    -1,
      -1,     6,    -1,    -1,  1117,    -1,  1119,  1120,  1121,  1122,
    1123,    -1,    -1,    -1,    -1,    -1,    -1,  1130,    -1,    -1,
      -1,    -1,    -1,  1136,  1137,    -1,    -1,   803,    -1,    -1,
      -1,    -1,  1145,    -1,    -1,  1148,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1158,    -1,  1160,    -1,  1162,
      -1,  1164,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,  1185,     6,   850,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1229,    -1,    -1,    -1,
     896,    -1,    -1,    -1,  1237,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,  1259,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1273,    -1,    -1,  1276,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
    1303,    -1,    -1,    -1,    -1,    -1,    -1,  1310,  1311,  1312,
    1313,    -1,    -1,    -1,    -1,    -1,  1319,    -1,  1321,  1322,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1017,  1018,  1019,  1020,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
    1076,  1414,  1415,  1416,   237,    -1,    -1,    -1,    -1,    -1,
    1423,    -1,  1425,    -1,    -1,    -1,    -1,    -1,    -1,  1432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1445,    -1,    -1,    -1,    -1,  1450,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1458,  1459,  1460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1477,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1502,
      -1,    -1,    -1,    -1,    -1,  1508,  1509,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1539,    -1,    -1,     6,
      -1,    -1,    -1,    -1,  1547,  1548,    -1,    13,    14,    -1,
      -1,  1554,  1555,    -1,    -1,    -1,    -1,    -1,  1561,    -1,
      -1,    -1,    -1,  1229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1578,  1579,  1580,    -1,    -1,
      -1,    -1,    -1,  1586,  1587,  1588,  1589,    -1,    -1,    -1,
      -1,     6,    -1,  1596,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1605,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1614,  1615,  1616,    -1,  1618,    -1,   500,    -1,    -1,
      -1,  1624,  1625,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
    1643,   107,   108,   109,  1647,    -1,   112,    -1,    -1,    -1,
      -1,    -1,   118,   119,    -1,  1658,   122,   123,  1661,   125,
     126,    -1,  1665,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,    -1,    -1,   144,  1682,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1695,    -1,    -1,    -1,    -1,  1700,  1701,    -1,
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1715,    -1,    -1,  1718,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,  1771,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,  1780,    -1,  1445,
      -1,    -1,    -1,    -1,    -1,    -1,  1789,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1798,  1799,    -1,    -1,  1802,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1833,  1834,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1847,    -1,    -1,    -1,    -1,    -1,
      -1,  1854,    -1,    -1,    -1,    -1,    -1,  1860,  1861,  1862,
    1863,  1864,    -1,    -1,    -1,    -1,    -1,    -1,  1871,    -1,
      -1,    -1,    -1,  1539,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,  1886,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,   775,   776,   777,   778,   779,   780,   781,   782,
     783,   784,   785,    -1,   787,   788,   789,   790,    -1,   792,
     793,   794,   795,    -1,    -1,  1918,    -1,    -1,    -1,    -1,
      -1,  1924,    -1,   806,  1927,   808,    -1,    -1,    -1,     7,
      -1,    -1,   815,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   826,   827,    -1,    -1,    -1,  1614,  1615,
      -1,    -1,   835,    -1,    -1,    -1,  1959,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       8,    -1,    -1,   107,   108,   109,    -1,  1643,   112,    -1,
      -1,  1984,  1985,    -1,   118,   119,    -1,    -1,   122,   123,
      -1,   125,   126,  1996,  1997,  1998,  1999,  2000,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,  2014,    -1,    -1,    -1,    -1,  2019,  2020,  2021,  2022,
    2023,    -1,    -1,    -1,    -1,    -1,  2029,    -1,    -1,    -1,
    2033,    -1,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
    2063,    -1,   237,    -1,    -1,  2068,  2069,  2070,  2071,  2072,
    2073,    -1,   955,   956,   957,    -1,    -1,    -1,   961,   962,
      -1,  2084,   965,   966,   967,   968,    -1,   970,    -1,    -1,
      -1,    -1,   975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,  2115,  2116,  2117,  2118,  2119,  2120,    -1,    -1,
      -1,    -1,    -1,  1789,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1802,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,     8,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,  1049,  1050,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,  1871,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1886,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    88,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2019,  2020,  2021,  2022,  2023,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1285,   184,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,  2084,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,    -1,    13,    14,    -1,    -1,    -1,
    1323,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,   235,   236,    -1,   238,    -1,   240,
      -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1356,  1357,  1358,  1359,  1360,    -1,    -1,
      -1,    -1,  1365,  1366,    -1,  1368,    -1,    -1,    -1,    -1,
      -1,  1374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1389,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
     118,   119,    -1,    -1,   122,   123,    -1,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1464,    -1,  1466,    -1,    -1,    -1,  1470,    -1,  1472,
     168,   169,   170,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,  1504,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   243,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1693,  1694,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,     8,
     209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,  1740,  1741,   238,
      -1,    -1,    -1,   242,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,  1806,  1807,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,     3,     4,
       5,   242,    -1,    -1,   245,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    13,    14,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
    2093,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
     118,   119,    -1,    -1,   122,   123,   191,   125,   126,    -1,
     195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     168,   169,   170,   238,     3,     4,     5,   242,    -1,    -1,
     245,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,
      -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
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
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,   118,   119,    -1,    -1,   122,   123,   191,   125,
     126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,
      -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,   168,   169,   170,   238,     3,     4,    -1,   242,
     243,    -1,   245,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,
      77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
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
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,
      14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,   112,    -1,
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
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      75,    76,    77,    -1,    -1,    13,    14,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
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
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,
      -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
     122,   123,   191,   125,   126,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,
       3,     4,    -1,    -1,   243,    -1,   245,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,
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
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,
      77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
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
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,
      14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,   112,    -1,
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
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      75,    76,    77,    -1,    -1,    13,    14,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
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
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,
      -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
     122,   123,   191,   125,   126,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,
       3,     4,     5,   242,    -1,    -1,   245,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
     239,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,
     193,   194,   195,    -1,    -1,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,   238,     3,     4,    -1,   242,
      -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,   192,   193,   194,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,   203,    -1,    -1,    63,   207,    -1,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,   238,     3,     4,     5,   242,    -1,    -1,   245,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
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
     191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,   242,    -1,    -1,   245,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   247,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,   238,     3,     4,    -1,   242,    -1,    -1,
     245,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,
       3,     4,    -1,   242,    -1,    -1,   245,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,
      -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,     3,     4,     5,    -1,   238,    -1,    -1,    10,    11,
      12,    -1,   245,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    88,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,   194,   195,    -1,    -1,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,   191,   247,    -1,    -1,   195,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,   238,    -1,     3,     4,   242,     6,    -1,   245,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,   191,    -1,   237,    -1,   195,    -1,    -1,    -1,
      -1,   200,   201,   202,   247,   204,   205,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,   247,
     195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,     3,
       4,    -1,     6,   238,    -1,    -1,    10,    11,    12,    -1,
     245,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,     3,     4,    -1,    83,
      84,    -1,    86,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,   195,   247,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,    64,    65,    66,
      -1,   238,    -1,    70,    71,    -1,    73,    -1,   245,    -1,
      -1,    78,    79,    -1,    81,    82,    -1,    84,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,   106,
     107,   108,   109,   110,    -1,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,     4,    -1,   156,
     157,   158,    -1,    -1,    -1,   162,    13,    14,    -1,    -1,
     167,   168,   169,   170,    -1,    -1,   173,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    44,    45,    -1,
     197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,    -1,   210,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    -1,    73,    -1,    -1,    -1,
      -1,    78,    79,    -1,    81,    82,    -1,    84,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,   106,
     107,   108,   109,   110,    -1,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,     4,     5,   173,    -1,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   198,   199,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,   208,    -1,   210,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    85,    -1,    -1,    88,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,   209,
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
      -1,    -1,   242,   215,   216,   217,   218,   219,   220,   221,
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
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,   239,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   249,   250,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    81,
      82,    84,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   106,   107,   108,
     109,   110,   112,   114,   115,   116,   117,   118,   119,   120,
     122,   123,   124,   125,   126,   127,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   156,
     157,   158,   162,   167,   168,   169,   170,   173,   175,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   197,   198,   199,   208,   210,   251,   253,
     254,   274,   295,   296,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   314,   316,   317,   323,   324,   325,   326,
     332,   353,   354,   242,   246,    14,    97,   238,   238,     6,
     242,     6,     6,     6,     6,   238,     6,     6,   240,   240,
       4,   334,   354,   238,   240,   272,   272,   238,   242,   238,
     238,     4,   238,   242,   238,   238,     4,   238,   242,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   111,
      97,     6,   242,    91,    94,    97,   238,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    75,    76,    77,    83,    86,
      91,    94,    97,    99,   118,   123,   125,   191,   195,   196,
     200,   201,   202,   204,   205,   206,   226,   227,   233,   238,
     242,   245,   296,   307,   314,   316,   327,   328,   332,   334,
     341,   343,   354,   238,   242,    97,    97,   118,    94,    97,
      99,    91,    94,    97,    99,    94,    97,    99,    94,    97,
     238,    94,   148,   173,   189,   190,   242,   226,   227,   238,
     242,   338,   339,   338,   242,   242,   338,     4,    91,    95,
     101,   102,   104,   105,   122,   238,    97,    99,    97,    94,
       4,    84,   184,   242,   354,     4,     6,    91,    94,    97,
      94,    97,     4,     4,     4,     5,   238,   341,   342,     4,
     238,   238,   238,     4,   242,   345,   354,     4,   238,   238,
     238,     6,     6,   240,     5,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    61,    62,    67,    68,
      69,    72,    74,    85,    88,   192,   193,   194,   203,   207,
     209,   349,   354,   238,     4,   349,     5,   242,     5,   242,
      32,   227,   327,   354,   240,   238,   242,     6,   238,   242,
       6,   246,     7,   125,   184,   211,   212,   213,   214,   235,
     236,   238,   240,   244,   270,   271,   272,   327,   348,   349,
     354,     4,   296,   297,   298,   242,     6,   327,   348,   349,
     354,   348,   327,   348,   352,   276,   280,   238,   337,     9,
     349,   354,   327,   227,   327,   343,   344,   327,   327,   238,
     327,   344,   327,   327,   238,   327,   344,   327,   327,   327,
     327,   327,   327,   348,   327,   327,   327,   341,   238,   344,
     342,   342,   342,   348,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   238,   240,   272,
     272,   272,   272,   272,   272,   238,   272,   272,   238,   272,
     272,     5,   176,   242,     5,   176,     5,   176,     5,   176,
     118,    91,    94,    97,    99,   238,   272,   272,   238,   238,
     238,   327,   242,   327,   343,   327,   327,   243,   344,   334,
     354,     8,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     237,   238,   240,     9,   238,   240,   244,   271,   272,   327,
     344,   238,   238,   238,   341,   342,   342,   342,   238,   238,
     238,   238,   238,   341,   238,   341,   238,   341,   242,   242,
     327,     4,   341,   242,   345,   242,   242,   338,   338,   338,
     327,   327,   226,   227,   242,   242,   338,   226,   227,   238,
     298,   338,   242,   238,   242,   238,   238,   238,   238,   238,
     238,   238,   327,   342,   342,   342,   238,     4,   240,     6,
     240,   298,     6,     6,   242,   242,   242,   342,   342,   240,
     240,   240,   327,     6,     6,   327,   327,   327,   244,   327,
     242,   176,   327,   327,   327,   327,   272,   272,   272,   238,
     238,   238,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   238,   238,   272,   238,   240,     6,     6,   242,
       6,   298,     6,   298,   272,   327,   228,   242,   238,   240,
     348,   327,   298,   341,   341,   242,   349,    91,    94,    97,
      99,     7,   327,   327,     4,   173,   174,   341,     6,   239,
     241,   242,   273,     6,   242,     6,     9,   238,   240,   244,
     354,   243,    91,    94,    97,    99,   118,   123,   126,   295,
     327,     6,   239,   247,     9,   238,   240,   244,   239,   247,
     247,   239,   247,   241,   247,   275,   241,   275,    87,   336,
     333,   354,   247,   247,   239,   228,   243,   247,   239,   239,
     327,   239,   243,   239,   239,   327,   239,   243,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,     7,   327,
     243,     6,     6,     6,   239,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   343,   327,   327,   327,   327,   327,   327,   327,
     343,   343,   354,   242,   327,   327,   348,   327,   348,   341,
     348,   348,   352,   327,   273,   354,    64,   327,    64,    64,
      64,   342,   342,   342,   342,   348,   348,   343,   334,   349,
     334,   344,   239,   243,   244,   272,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     242,   327,   343,   327,   327,   327,   327,   327,   327,   327,
     354,   327,   327,     4,   335,   242,   273,   239,   243,   327,
     327,   327,     7,     7,   320,   320,   289,   327,   349,   290,
     327,   349,   291,   327,   349,   292,   327,   349,   327,     6,
     327,     6,   327,     6,   344,   344,   242,   239,     6,   298,
     242,   298,   298,   247,   247,   247,   338,   338,   297,   297,
     247,   327,   243,   311,   247,   298,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   239,     7,   321,     6,     7,
     327,     6,   327,   327,   243,   344,   344,   344,     6,     6,
     327,   327,   327,   239,   239,   239,   239,   173,   247,   298,
     242,     8,   239,   239,   241,   352,   348,   352,   348,   348,
     348,   348,   348,   348,   327,   348,   348,   348,   348,   245,
     351,   354,   349,   348,   348,   348,   334,   354,   344,   243,
     243,   327,   327,   298,   241,   239,   131,   148,   315,   239,
     243,   247,   327,     6,   242,   242,   242,   242,   327,   239,
     241,     7,   270,   271,   244,     7,     6,   344,     7,   214,
     270,   255,   354,   327,   327,   335,   240,   242,   242,   242,
     242,   238,   118,    94,    97,    99,   243,     6,   221,   222,
     252,   344,   354,   327,   327,     4,   335,     6,   344,   327,
       6,   348,     6,   354,     6,   348,   327,   239,   240,   327,
     349,     7,   176,   327,   343,     7,     7,   239,     7,   176,
       7,     7,   239,     7,   176,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   327,   239,   242,     6,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   247,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   247,
     247,   247,   239,   241,   241,   344,   247,   247,   273,   247,
     273,   247,   247,   247,   239,   329,   273,   242,   243,   242,
     242,   242,   247,   247,   273,   273,   239,   244,   239,   244,
     247,   330,   243,     7,   335,   273,     8,     8,   344,   239,
     241,   244,   239,   241,   271,   238,   344,     7,   242,   239,
     239,   239,   327,   341,     4,   319,     6,   239,   247,   239,
     247,   239,   247,   239,   247,   239,   239,   239,   243,   243,
     344,   244,   243,   298,   243,   243,   338,   327,   327,   243,
     243,   327,   338,   128,   128,   145,   153,   154,   155,   159,
     160,   312,   313,   338,   243,   308,   239,   243,   239,   239,
     239,   239,   239,   239,   239,     7,   327,     6,   327,   239,
     241,   241,   243,   243,   243,   241,   241,   247,     7,     7,
       7,   244,   327,   243,   327,   327,     7,   244,   273,   247,
     273,   273,   239,   239,   247,   273,   273,   247,   247,   273,
     273,   273,   273,   327,   273,     9,   350,   247,   239,   247,
     273,   244,   247,   331,   241,   243,   243,   246,     7,   148,
       6,   327,   243,   242,     6,   341,   243,   327,   327,   327,
     327,     6,     7,   270,   271,   244,   270,   271,   349,   327,
       6,     4,   242,   346,   354,   243,    46,    46,   341,     4,
     163,   164,   165,   166,   243,   258,   262,   265,   267,   268,
     244,   239,   241,   238,   327,   344,   344,   344,   344,   327,
     238,   238,   238,   238,   348,   239,   244,   239,   241,   238,
     239,   247,     7,   272,     4,   283,   284,   285,   273,   273,
     338,    97,    99,   341,   341,     7,   341,    97,    99,   341,
     341,     7,   341,    99,   341,   341,   341,   341,   341,   341,
     341,   341,   341,     6,     7,   344,   327,   327,   327,   327,
     243,   327,   327,   327,   341,   348,   348,   247,   282,   327,
     327,   327,   327,   327,   327,   335,   335,   327,   239,   341,
     238,   327,   327,   243,   335,   271,   244,   271,   327,   243,
     341,   344,     7,     7,     7,   128,   318,     6,   270,   327,
     270,   327,   270,   327,   270,   327,     7,     7,     7,     7,
       7,   243,     4,   243,   247,   247,   247,   243,   243,   109,
       4,     6,   327,   242,     6,   238,     6,   161,     6,   161,
     243,   313,   247,   312,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   341,     6,   242,     6,     6,     6,    97,
       7,     6,     6,   327,   341,   341,   341,     4,   247,     8,
       8,   239,     4,     4,   344,   348,   327,   348,   245,   247,
     286,   348,   348,   335,   348,   239,   247,   242,   242,     6,
     327,     6,   242,   341,   243,   243,   243,   243,   243,   327,
       6,     4,   173,   174,   327,     6,     6,     6,     7,   345,
     347,     6,   240,   273,   272,   272,     6,   259,   238,   238,
     242,   269,     6,   335,   244,   348,   327,   241,   243,   243,
     243,   243,   239,   327,   327,   327,   327,     6,     6,   252,
     335,   244,   327,     6,   327,   242,   327,   349,   273,   242,
     341,   349,   241,   247,     6,     6,     6,   242,   242,   122,
     294,   294,   341,     6,   242,   242,     6,     6,   341,   176,
     293,   242,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,   243,   273,   273,   273,   273,   273,   247,   247,
     247,   239,   273,   273,   284,   273,   247,   247,   247,   247,
     239,   273,   239,   330,     6,   239,   238,     4,   239,   273,
       6,   243,   341,   341,   341,     4,     6,   341,   341,   341,
     341,   341,   341,   341,   242,   242,     7,     6,     7,   327,
     327,   327,   242,   242,   242,   240,     6,   327,   341,   327,
       6,     6,   327,   338,   243,     5,   341,   242,   242,   242,
     242,   242,   242,   242,   341,     6,   344,   242,   327,   241,
       6,     6,   172,   327,   327,   327,     6,     6,     7,   273,
     247,   247,   273,   247,   327,     4,   188,   287,   288,   273,
     239,   273,   331,   349,   327,   298,     6,   298,   247,     6,
       6,     7,   270,   271,   244,     7,     6,   345,   243,   247,
     327,   270,   273,   352,   352,   238,   327,   327,   340,   341,
     242,   238,     4,     6,   239,     6,     6,     6,     6,     6,
     239,   239,   239,   239,   348,   238,     4,   239,   247,   341,
     349,     7,   281,   327,   343,   285,   327,   327,   338,     6,
       6,     6,   327,   327,     6,    95,     6,   327,     5,   242,
     327,   327,   327,   327,   327,   327,   327,   239,   327,   271,
     242,     6,   293,     6,   327,     6,     6,     6,     6,     6,
       4,     6,     6,   344,   344,   327,   327,   349,   243,   239,
     243,   247,   297,   297,   327,   327,   243,   247,   239,   243,
     247,     6,     6,   340,   338,   338,   338,   338,   338,   227,
     338,     6,   243,   327,     6,     6,   341,   243,   247,     8,
     243,   239,   242,   327,   349,   348,   327,   348,   242,   327,
     349,   349,   247,   239,   247,   243,   315,   315,   341,   349,
     327,     6,     4,   346,     6,   345,   241,   341,     6,   273,
     273,   256,   327,   247,   247,   243,   247,   257,   327,   327,
       6,   327,   327,   277,   279,   242,   243,   247,     7,     7,
     243,   243,   243,   243,   242,   243,     5,   340,   273,   273,
     247,   247,   247,   247,   247,   239,   327,     6,   242,   243,
     243,   242,     6,     6,   242,   327,   243,   243,   243,   241,
       6,   341,     7,   242,   327,   243,   247,   247,   247,   247,
     247,   247,     6,   243,   171,   327,   327,   344,     6,     6,
     239,   273,   273,   352,   288,   349,   243,   243,   243,     6,
       6,     7,     6,   244,     6,     6,     6,   239,   247,   327,
     327,   242,   341,   243,   247,   239,   239,   247,   282,   286,
     341,   327,   349,   354,     6,     6,     6,     6,   327,     6,
       6,   243,   327,   327,   327,   327,   327,   243,   340,   132,
     133,   138,   322,   132,   133,   322,   344,   297,   243,   247,
       6,   243,   341,   298,   243,     6,   344,   338,   338,   338,
     338,   338,   327,   243,   243,   243,   243,   239,   242,     6,
     345,   174,   260,   327,   247,   247,   340,     6,   327,   327,
     243,   243,   278,     7,   238,   243,   242,   247,   247,   247,
     247,   247,   243,   242,   338,   341,     6,   242,   338,     6,
     243,   243,   327,     6,   128,   243,   309,   242,   243,   247,
     247,   247,   247,   247,     6,     6,     6,   298,     6,   242,
     327,   327,   243,   247,   282,   349,   239,   327,   327,   327,
     327,   327,   327,     6,   338,     6,   338,     6,     6,   243,
     327,   312,   298,     6,   344,   344,   344,   344,   338,   344,
     315,   257,   239,   247,     6,   242,   327,   243,   247,   247,
     247,   247,   247,   247,   247,   247,     6,   243,   243,   310,
     243,   243,   243,   243,   247,   243,   243,   243,   263,   327,
     340,   243,   327,   327,   327,   327,   327,   327,   338,   338,
     312,     6,     6,     6,     6,   344,     6,     6,     6,   242,
     239,   243,     6,   243,   273,   247,   247,   247,   247,   247,
     247,   243,   243,   261,   348,   266,   242,     6,   327,   327,
     327,   327,   327,   327,     6,   243,   247,   242,   340,   243,
     243,   243,   243,   243,   243,     6,   348,   264,   348,   243,
       6,     6,   243,   247,     6,     6,   348
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
#line 260 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 271 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 272 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 273 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 275 "Gmsh.y"
    {
      factory = (yyvsp[(3) - (5)].c);
      if(factory == "OpenCASCADE"){
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
#line 293 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 294 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 295 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 296 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 297 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 298 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 299 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 300 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 301 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 302 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 303 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 304 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 305 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 306 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 307 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 308 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 313 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 317 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 324 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 329 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 334 "Gmsh.y"
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
#line 348 "Gmsh.y"
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
#line 361 "Gmsh.y"
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
#line 374 "Gmsh.y"
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
#line 402 "Gmsh.y"
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
#line 416 "Gmsh.y"
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
#line 429 "Gmsh.y"
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
#line 442 "Gmsh.y"
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
#line 460 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 474 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 476 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 481 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 483 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 488 "Gmsh.y"
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
#line 592 "Gmsh.y"
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
#line 602 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 611 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 618 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 628 "Gmsh.y"
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
#line 637 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 646 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 653 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 663 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 671 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 681 "Gmsh.y"
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
#line 700 "Gmsh.y"
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
#line 719 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 725 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 732 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 733 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 734 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 735 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 736 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 740 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 741 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 747 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 747 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 748 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 748 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 758 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 763 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 769 "Gmsh.y"
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
#line 831 "Gmsh.y"
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
#line 846 "Gmsh.y"
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
#line 875 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 885 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 890 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 898 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 903 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 911 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 920 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 925 "Gmsh.y"
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
#line 937 "Gmsh.y"
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
#line 954 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 960 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 969 "Gmsh.y"
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
#line 987 "Gmsh.y"
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
#line 1005 "Gmsh.y"
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
#line 1014 "Gmsh.y"
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
#line 1026 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1031 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1039 "Gmsh.y"
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
#line 1059 "Gmsh.y"
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
#line 1082 "Gmsh.y"
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
#line 1093 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1101 "Gmsh.y"
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

  case 104:
#line 1123 "Gmsh.y"
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

  case 105:
#line 1146 "Gmsh.y"
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

  case 106:
#line 1184 "Gmsh.y"
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

  case 107:
#line 1205 "Gmsh.y"
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

  case 108:
#line 1217 "Gmsh.y"
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

  case 112:
#line 1235 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 113:
#line 1244 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 114:
#line 1253 "Gmsh.y"
    { init_options(); ;}
    break;

  case 115:
#line 1255 "Gmsh.y"
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

  case 116:
#line 1273 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1275 "Gmsh.y"
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

  case 118:
#line 1291 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 119:
#line 1300 "Gmsh.y"
    { init_options(); ;}
    break;

  case 120:
#line 1302 "Gmsh.y"
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

  case 122:
#line 1316 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 123:
#line 1324 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 124:
#line 1330 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 125:
#line 1335 "Gmsh.y"
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

  case 132:
#line 1377 "Gmsh.y"
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

  case 133:
#line 1389 "Gmsh.y"
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

  case 134:
#line 1402 "Gmsh.y"
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

  case 135:
#line 1417 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 140:
#line 1439 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 141:
#line 1447 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 142:
#line 1456 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 143:
#line 1464 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (4)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 144:
#line 1482 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 145:
#line 1486 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 0, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 146:
#line 1493 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 147:
#line 1501 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 148:
#line 1505 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 1, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 149:
#line 1512 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 150:
#line 1520 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 151:
#line 1524 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 2, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 152:
#line 1531 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 153:
#line 1539 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 154:
#line 1543 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 3, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 155:
#line 1550 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 156:
#line 1558 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 157:
#line 1562 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 158:
#line 1568 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 159:
#line 1572 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 160:
#line 1579 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 161:
#line 1603 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 162:
#line 1619 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Spline not available with OpenCASCADE factory");
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

  case 163:
#line 1635 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 164:
#line 1672 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 165:
#line 1712 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 166:
#line 1728 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 167:
#line 1745 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), knots);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Nurbs not available yet with OpenCASCADE factory");
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

  case 168:
#line 1766 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      if(!r) yymsg(0, "Could not add compound line");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 169:
#line 1776 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available using OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add wire");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 170:
#line 1792 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 171:
#line 1809 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 172:
#line 1825 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 173:
#line 1846 "Gmsh.y"
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

  case 174:
#line 1857 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 175:
#line 1863 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 176:
#line 1869 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1876 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      (yyval.s).Type = 0;
      bool r = true;
      if(param.size() >= 4 && param.size() <= 7){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double a1 = (param.size() >= 5) ? param[4] : -M_PI/2;
          double a2 = (param.size() >= 6) ? param[5] : M_PI/2;
          double a3 = (param.size() >= 7) ? param[6] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addSphere
            (num, param[0], param[1], param[2], param[3], a1, a2, a3);
        }
        else{
          yymsg(0, "Sphere only available with OpenCASCADE factory");
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

  case 178:
#line 1907 "Gmsh.y"
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

  case 179:
#line 1922 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6){
          r = GModel::current()->getOCCInternals()->addBlock
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Block requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Block only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add block");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1944 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
        yymsg(0, "Torus only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add torus");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1967 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6 || param.size() == 7){
          double r = (param.size() == 7) ? param[6] : 0.;
          r = GModel::current()->getOCCInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4], param[5], r);
        }
        else{
          yymsg(0, "Rectangle requires 6 ou 7 parameters");
        }
      }
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add rectangle");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 182:
#line 1990 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
        yymsg(0, "Disk only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add disk");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 183:
#line 2013 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
        yymsg(0, "Cylinder only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add cylinder");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 184:
#line 2037 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
        yymsg(0, "Cone only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add cone");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 2061 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 7){
          r = GModel::current()->getOCCInternals()->addWedge
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6]);
        }
        else{
          yymsg(0, "Wedge requires 7 parameters");
        }
      }
      else{
        yymsg(0, "Wedge only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add wedge");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2084 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(unsigned int i = 2; i < param.size(); i++)
            exclude.push_back(param[i]);
          r = GModel::current()->getOCCInternals()->addThickSolid
            (num, in, exclude, offset);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 parameters");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add thick solid");
      List_Delete((yyvsp[(6) - (7)].l));
    ;}
    break;

  case 187:
#line 2109 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      if(!r) yymsg(0, "Could not add compound surface");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2120 "Gmsh.y"
    {
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
    ;}
    break;

  case 189:
#line 2142 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 190:
#line 2159 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 191:
#line 2175 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (num, wires, outDimTags, true, false);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2193 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (num, wires, outDimTags, true, true);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2211 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      if(!r) yymsg(0, "Could not add compound volume");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 194:
#line 2221 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        (0, num, op, tags);
      if(!r) yymsg(0, "Could not modify physical point");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 195:
#line 2233 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        (1, num, op, tags);
      if(!r) yymsg(0, "Could not modify physical line");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2245 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        (2, num, op, tags);
      if(!r) yymsg(0, "Could not modify physical surface");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 197:
#line 2257 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        (3, num, op, tags);
      if(!r) yymsg(0, "Could not modify physical volume");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 198:
#line 2274 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 199:
#line 2290 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 200:
#line 2306 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("Symmetry not implemented yet with OpenCASCADE factory");
      }
      else{
        r = GModel::current()->getGEOInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      if(!r) yymsg(0, "Could not apply symmetry transform");
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 201:
#line 2321 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(1, "Warning Dilate OCC: Dilatation (second argument) + Translation (first argument) ");
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

  case 202:
#line 2338 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(1, "Warning Dilate OCC: Dilatation (second argument) + Translation (first argument) ");
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

  case 203:
#line 2355 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), inDimTags);
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      std::string action((yyvsp[(1) - (4)].c));
      bool r = true;
      if(action == "Duplicata"){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          r = GModel::current()->getOCCInternals()->copy(inDimTags, outDimTags);
        }
        else{
          r = GModel::current()->getGEOInternals()->copy(inDimTags, outDimTags);
        }
      }
      else if(action == "Boundary" || action == "CombinedBoundary"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        r = GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, action == "CombinedBoundary");
      }
      else{
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[(1) - (4)].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 204:
#line 2390 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 205:
#line 2412 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 206:
#line 2435 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 207:
#line 2436 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 208:
#line 2441 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 209:
#line 2445 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 210:
#line 2449 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_POINT;
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 211:
#line 2460 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_SEGM_LINE;
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 212:
#line 2471 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_SURF_PLAN; // we don't care about the actual type
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 213:
#line 2482 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_VOLUME;
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 214:
#line 2498 "Gmsh.y"
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

  case 215:
#line 2517 "Gmsh.y"
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

  case 216:
#line 2539 "Gmsh.y"
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

  case 217:
#line 2554 "Gmsh.y"
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

  case 218:
#line 2569 "Gmsh.y"
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

  case 219:
#line 2588 "Gmsh.y"
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

  case 220:
#line 2639 "Gmsh.y"
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

  case 221:
#line 2660 "Gmsh.y"
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

  case 222:
#line 2682 "Gmsh.y"
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

  case 223:
#line 2704 "Gmsh.y"
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

  case 224:
#line 2809 "Gmsh.y"
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

  case 225:
#line 2825 "Gmsh.y"
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

  case 226:
#line 2860 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->remove(dimTags);
      }
      GModel::current()->getGEOInternals()->remove(dimTags);
      GModel::current()->remove(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 227:
#line 2871 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->remove(dimTags, true);
      }
      GModel::current()->getGEOInternals()->remove(dimTags, true);
      GModel::current()->remove(dimTags, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 228:
#line 2882 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 229:
#line 2888 "Gmsh.y"
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

  case 230:
#line 2903 "Gmsh.y"
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

  case 231:
#line 2931 "Gmsh.y"
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

  case 232:
#line 2943 "Gmsh.y"
    {
      nameSpaces.clear();
    ;}
    break;

  case 233:
#line 2952 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 234:
#line 2959 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 235:
#line 2971 "Gmsh.y"
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

  case 236:
#line 2990 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 237:
#line 2996 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 238:
#line 3002 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 3009 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 3016 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 241:
#line 3023 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3035 "Gmsh.y"
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

  case 243:
#line 3108 "Gmsh.y"
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

  case 244:
#line 3126 "Gmsh.y"
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

  case 245:
#line 3143 "Gmsh.y"
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

  case 246:
#line 3158 "Gmsh.y"
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

  case 247:
#line 3191 "Gmsh.y"
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

  case 248:
#line 3203 "Gmsh.y"
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

  case 249:
#line 3227 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 250:
#line 3231 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 251:
#line 3236 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 252:
#line 3243 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 253:
#line 3248 "Gmsh.y"
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

  case 254:
#line 3258 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 255:
#line 3263 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 256:
#line 3269 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 257:
#line 3277 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 258:
#line 3281 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 259:
#line 3285 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 260:
#line 3295 "Gmsh.y"
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

  case 261:
#line 3358 "Gmsh.y"
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

  case 262:
#line 3374 "Gmsh.y"
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

  case 263:
#line 3391 "Gmsh.y"
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

  case 264:
#line 3408 "Gmsh.y"
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

  case 265:
#line 3430 "Gmsh.y"
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

  case 266:
#line 3452 "Gmsh.y"
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

  case 267:
#line 3487 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 268:
#line 3495 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 269:
#line 3503 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 270:
#line 3509 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 271:
#line 3516 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 272:
#line 3523 "Gmsh.y"
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

  case 273:
#line 3543 "Gmsh.y"
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

  case 274:
#line 3569 "Gmsh.y"
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

  case 275:
#line 3581 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 276:
#line 3593 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 277:
#line 3611 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 278:
#line 3629 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (13)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE factory");
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

  case 279:
#line 3647 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3653 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (7)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 281:
#line 3671 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3677 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (13)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 283:
#line 3697 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3703 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (15)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE factory");
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

  case 285:
#line 3721 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3727 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (6)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Boundary layer extrusion not available with OpenCASCADE factory");
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

  case 287:
#line 3744 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), inDimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPipe(inDimTags, (int)(yyvsp[(8) - (9)].d), outDimTags);
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(3) - (9)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 288:
#line 3760 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, outDimTags, false, false);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 289:
#line 3777 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, outDimTags, false, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 290:
#line 3794 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radius, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    ;}
    break;

  case 291:
#line 3817 "Gmsh.y"
    {
    ;}
    break;

  case 292:
#line 3820 "Gmsh.y"
    {
    ;}
    break;

  case 293:
#line 3826 "Gmsh.y"
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

  case 294:
#line 3838 "Gmsh.y"
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

  case 295:
#line 3858 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 296:
#line 3862 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 297:
#line 3866 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 298:
#line 3870 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 299:
#line 3874 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3878 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 301:
#line 3882 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3886 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 303:
#line 3895 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 304:
#line 3907 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 305:
#line 3908 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 306:
#line 3909 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 307:
#line 3910 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 308:
#line 3911 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 309:
#line 3915 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 310:
#line 3916 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 311:
#line 3917 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 312:
#line 3918 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 313:
#line 3919 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 314:
#line 3924 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (9)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), object, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 315:
#line 3946 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE factory");
      }
      if(!r) yymsg(0, "Could import shape");
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 316:
#line 3966 "Gmsh.y"
    {
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (14)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(11) - (14)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), object, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 317:
#line 3986 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 318:
#line 3990 "Gmsh.y"
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

  case 319:
#line 4005 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 320:
#line 4009 "Gmsh.y"
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

  case 321:
#line 4025 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 322:
#line 4029 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 323:
#line 4034 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 324:
#line 4038 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 325:
#line 4044 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 326:
#line 4048 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 327:
#line 4055 "Gmsh.y"
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

  case 328:
#line 4072 "Gmsh.y"
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

  case 329:
#line 4113 "Gmsh.y"
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

  case 330:
#line 4157 "Gmsh.y"
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

  case 331:
#line 4196 "Gmsh.y"
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

  case 332:
#line 4221 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 333:
#line 4230 "Gmsh.y"
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

  case 334:
#line 4260 "Gmsh.y"
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

  case 335:
#line 4286 "Gmsh.y"
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

  case 336:
#line 4313 "Gmsh.y"
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

  case 337:
#line 4345 "Gmsh.y"
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

  case 338:
#line 4372 "Gmsh.y"
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

  case 339:
#line 4398 "Gmsh.y"
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

  case 340:
#line 4424 "Gmsh.y"
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

  case 341:
#line 4450 "Gmsh.y"
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

  case 342:
#line 4476 "Gmsh.y"
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

  case 343:
#line 4497 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 344:
#line 4503 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 345:
#line 4509 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 346:
#line 4515 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 347:
#line 4521 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 348:
#line 4527 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setReverseMesh(2, 0);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.reverseMesh = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh(2, num);
          GFace *gf = GModel::current()->getFaceByTag(num);
          if(gf) gf->meshAttributes.reverseMesh = 1;
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 349:
#line 4553 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setReverseMesh(1, 0);
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++){
          (*it)->meshAttributes.reverseMesh = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh(1, num);
          GEdge *ge = GModel::current()->getEdgeByTag(num);
          if(ge) ge->meshAttributes.reverseMesh = 1;
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 350:
#line 4579 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::viter it = GModel::current()->firstVertex();
            it != GModel::current()->lastVertex(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GVertex *gv = GModel::current()->getVertexByTag((int)d);
          if(gv) gv->relocateMeshVertices();
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 351:
#line 4596 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GEdge *ge = GModel::current()->getEdgeByTag((int)d);
          if(ge) ge->relocateMeshVertices();
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 352:
#line 4613 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GFace *gf = GModel::current()->getFaceByTag((int)d);
          if(gf) gf->relocateMeshVertices();
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 353:
#line 4630 "Gmsh.y"
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

  case 354:
#line 4642 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 355:
#line 4648 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 356:
#line 4654 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 357:
#line 4666 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 358:
#line 4670 "Gmsh.y"
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

  case 359:
#line 4680 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 360:
#line 4690 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 361:
#line 4691 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 362:
#line 4692 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 363:
#line 4697 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 364:
#line 4703 "Gmsh.y"
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

  case 365:
#line 4715 "Gmsh.y"
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

  case 366:
#line 4733 "Gmsh.y"
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

  case 367:
#line 4760 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 368:
#line 4761 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 369:
#line 4762 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 370:
#line 4763 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 371:
#line 4764 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 372:
#line 4765 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 373:
#line 4766 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4767 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4769 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 376:
#line 4775 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 377:
#line 4776 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 378:
#line 4777 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 379:
#line 4778 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 380:
#line 4779 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4780 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4781 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 383:
#line 4782 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4783 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4784 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4785 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4786 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 388:
#line 4787 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 389:
#line 4788 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 390:
#line 4789 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 391:
#line 4790 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4791 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 393:
#line 4792 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 394:
#line 4793 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 395:
#line 4794 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 4795 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4796 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 398:
#line 4797 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4798 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4799 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4800 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 402:
#line 4801 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4802 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4803 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4804 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4805 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 407:
#line 4806 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 408:
#line 4807 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 4808 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 410:
#line 4809 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 411:
#line 4810 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 412:
#line 4811 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 413:
#line 4812 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 414:
#line 4821 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 415:
#line 4822 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 416:
#line 4823 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 417:
#line 4824 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 418:
#line 4825 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 419:
#line 4826 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 420:
#line 4827 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 421:
#line 4828 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 422:
#line 4829 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 423:
#line 4830 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 424:
#line 4831 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 425:
#line 4836 "Gmsh.y"
    { init_options(); ;}
    break;

  case 426:
#line 4838 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 427:
#line 4844 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 428:
#line 4846 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 429:
#line 4851 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 430:
#line 4856 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 431:
#line 4861 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (4)].c2).char1, (yyvsp[(1) - (4)].c2).char2, 2, (int)(yyvsp[(3) - (4)].d));
      /*
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
          $$ = 0.;
        }
        else
          $$ = s.value[index];
      }
      Free($1);
      */
    ;}
    break;

  case 432:
#line 4883 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (4)].c2).char1, (yyvsp[(1) - (4)].c2).char2, 2, (int)(yyvsp[(3) - (4)].d));
      /*
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
          $$ = 0.;
        }
        else
          $$ = s.value[index];
      }
      Free($1);
      */
    ;}
    break;

  case 433:
#line 4904 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 434:
#line 4908 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 435:
#line 4912 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 436:
#line 4916 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 437:
#line 4920 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:
#line 4926 "Gmsh.y"
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

  case 439:
#line 4942 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 440:
#line 4947 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 441:
#line 4953 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 442:
#line 4959 "Gmsh.y"
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

  case 443:
#line 4978 "Gmsh.y"
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

  case 444:
#line 4999 "Gmsh.y"
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
#line 5032 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 446:
#line 5036 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 447:
#line 5041 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 448:
#line 5045 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 449:
#line 5050 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 450:
#line 5055 "Gmsh.y"
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

  case 451:
#line 5065 "Gmsh.y"
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

  case 452:
#line 5075 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 453:
#line 5080 "Gmsh.y"
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

  case 454:
#line 5091 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 455:
#line 5100 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 456:
#line 5105 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 457:
#line 5110 "Gmsh.y"
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

  case 458:
#line 5137 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 459:
#line 5139 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 460:
#line 5144 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 461:
#line 5146 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 462:
#line 5151 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 463:
#line 5158 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (7)].c2).char1? (yyvsp[(2) - (7)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (7)].c2).char2);
      Free((yyvsp[(2) - (7)].c2).char1); Free((yyvsp[(2) - (7)].c2).char2);
      int tag_out;
      if (nameSpaces.defStruct(struct_namespace, struct_name,
                               floatOptions, charOptions,
                               tag_out, member_ValMax, (yyvsp[(3) - (7)].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    ;}
    break;

  case 464:
#line 5174 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 465:
#line 5176 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 466:
#line 5181 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 467:
#line 5190 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 468:
#line 5192 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 469:
#line 5197 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 470:
#line 5199 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 471:
#line 5205 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 472:
#line 5209 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 473:
#line 5213 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 474:
#line 5217 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 475:
#line 5221 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 476:
#line 5228 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 477:
#line 5232 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 478:
#line 5236 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 479:
#line 5240 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 480:
#line 5247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 481:
#line 5252 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 482:
#line 5259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 483:
#line 5264 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 484:
#line 5268 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 485:
#line 5273 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 486:
#line 5277 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 487:
#line 5285 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 488:
#line 5296 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 489:
#line 5300 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 490:
#line 5312 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 491:
#line 5320 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 492:
#line 5328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 493:
#line 5335 "Gmsh.y"
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

  case 494:
#line 5345 "Gmsh.y"
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

  case 495:
#line 5368 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 496:
#line 5374 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 497:
#line 5380 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 498:
#line 5386 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 499:
#line 5392 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(0, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(0, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 500:
#line 5403 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(1, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(1, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 501:
#line 5414 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(2, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(2, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 502:
#line 5425 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(3, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(3, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 503:
#line 5437 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 504:
#line 5443 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 505:
#line 5449 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 506:
#line 5455 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 507:
#line 5460 "Gmsh.y"
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
#line 5470 "Gmsh.y"
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
#line 5480 "Gmsh.y"
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
#line 5490 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
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

  case 511:
#line 5503 "Gmsh.y"
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

  case 512:
#line 5515 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 513:
#line 5519 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 514:
#line 5523 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 515:
#line 5527 "Gmsh.y"
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

  case 516:
#line 5545 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 517:
#line 5553 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 518:
#line 5561 "Gmsh.y"
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

  case 519:
#line 5590 "Gmsh.y"
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

  case 520:
#line 5600 "Gmsh.y"
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

  case 521:
#line 5616 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 522:
#line 5627 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 523:
#line 5632 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 524:
#line 5636 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 525:
#line 5640 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 526:
#line 5652 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 527:
#line 5656 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 528:
#line 5668 "Gmsh.y"
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

  case 529:
#line 5685 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 530:
#line 5695 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 531:
#line 5699 "Gmsh.y"
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

  case 532:
#line 5714 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 533:
#line 5719 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 534:
#line 5726 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 535:
#line 5730 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 536:
#line 5735 "Gmsh.y"
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

  case 537:
#line 5749 "Gmsh.y"
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
#line 5766 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 539:
#line 5770 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 540:
#line 5775 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 541:
#line 5779 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 542:
#line 5784 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 543:
#line 5792 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 544:
#line 5798 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 545:
#line 5804 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 546:
#line 5810 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 547:
#line 5819 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 548:
#line 5823 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 549:
#line 5827 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 550:
#line 5835 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 551:
#line 5841 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 552:
#line 5847 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 553:
#line 5851 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 554:
#line 5859 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 555:
#line 5867 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 556:
#line 5874 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 557:
#line 5884 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 558:
#line 5889 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 559:
#line 5894 "Gmsh.y"
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

  case 560:
#line 5909 "Gmsh.y"
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

  case 561:
#line 5923 "Gmsh.y"
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

  case 562:
#line 5937 "Gmsh.y"
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

  case 563:
#line 5949 "Gmsh.y"
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

  case 564:
#line 5965 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 565:
#line 5974 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 5983 "Gmsh.y"
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

  case 567:
#line 5993 "Gmsh.y"
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

  case 568:
#line 6004 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 569:
#line 6012 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 570:
#line 6020 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 571:
#line 6024 "Gmsh.y"
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

  case 572:
#line 6043 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 573:
#line 6050 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 574:
#line 6056 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 575:
#line 6063 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6070 "Gmsh.y"
    { init_options(); ;}
    break;

  case 577:
#line 6072 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 578:
#line 6080 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = NULL;
      switch (nameSpaces.get_key_struct_from_tag(struct_namespace,
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

  case 579:
#line 6104 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 580:
#line 6106 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 581:
#line 6112 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 582:
#line 6117 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 583:
#line 6125 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 584:
#line 6134 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 585:
#line 6143 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 586:
#line 6155 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 587:
#line 6158 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 588:
#line 6162 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13551 "Gmsh.tab.c"
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


#line 6165 "Gmsh.y"


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
      std::string s = it->first + "[] = Str(";
      for(unsigned int i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += ");";
      vec.push_back(s);
    }
  }
  if (nameSpaces.size()){
    if(help){
      vec.push_back("//");
      vec.push_back("// Structures");
      vec.push_back("//");
    }
    std::vector<std::string> strs;
    nameSpaces.sprint(strs);
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

int NEWPOINT()
{
  int tag = GModel::current()->getGEOInternals()->getMaxTag(0) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(0) + 1);
  return tag;
}

int NEWLINE()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(1) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(1) + 1);
  return tag;
}

int NEWLINELOOP()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  return tag;
}

int NEWSURFACE()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(2) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(2) + 1);
  return tag;
}

int NEWSURFACELOOP()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(-2) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  return tag;
}

int NEWVOLUME()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(3) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(3) + 1);
  return tag;
}

int NEWREG()
{
  int tag = 0;
  for(int dim = -2; dim <= 3; dim++){
    if(dim)
      tag = std::max(tag, GModel::current()->getGEOInternals()->getMaxTag(dim) + 1);
  }
  tag = std::max(tag, GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1);
  if(GModel::current()->getOCCInternals()){
    for(int dim = -2; dim <= 3; dim++){
      if(dim)
        tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(dim) + 1);
    }
  }
  return tag;
}

int NEWFIELD()
{
#if defined(HAVE_MESH)
  return (GModel::current()->getFields()->maxId() + 1);
#else
  return 0;
#endif
}

int NEWPHYSICAL()
{
  if(CTX::instance()->geom.oldNewreg)
    return NEWREG();
  else
    return (GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1);
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
        if((int)s.value.size() < index + 1){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
        }
        else
          out = s.value[0];
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
    std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
    if(nameSpaces.getTag(struct_namespace, struct_name, out)) {
      out = val_default;
      if (type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
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
  switch (nameSpaces.getMember
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
      out = (nameSpaces.getMember
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

int treat_Struct_FullName_dot_tSTRING_Float_getDim
(char* c1, char* c2, char* c3)
{
  int out;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (nameSpaces.getMember_Dim
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
  switch (nameSpaces.getMember
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

