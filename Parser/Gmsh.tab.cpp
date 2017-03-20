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
     tBlock = 354,
     tCylinder = 355,
     tCone = 356,
     tTorus = 357,
     tEllipsoid = 358,
     tQuadric = 359,
     tShapeFromFile = 360,
     tRectangle = 361,
     tDisk = 362,
     tWire = 363,
     tCharacteristic = 364,
     tLength = 365,
     tParametric = 366,
     tElliptic = 367,
     tRefineMesh = 368,
     tAdaptMesh = 369,
     tRelocateMesh = 370,
     tSetFactory = 371,
     tThruSections = 372,
     tWedge = 373,
     tFillet = 374,
     tChamfer = 375,
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
#define tCreateTopologyNoHoles 334
#define tDistanceFunction 335
#define tDefineConstant 336
#define tUndefineConstant 337
#define tDefineNumber 338
#define tDefineStruct 339
#define tNameStruct 340
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
#define tBlock 354
#define tCylinder 355
#define tCone 356
#define tTorus 357
#define tEllipsoid 358
#define tQuadric 359
#define tShapeFromFile 360
#define tRectangle 361
#define tDisk 362
#define tWire 363
#define tCharacteristic 364
#define tLength 365
#define tParametric 366
#define tElliptic 367
#define tRefineMesh 368
#define tAdaptMesh 369
#define tRelocateMesh 370
#define tSetFactory 371
#define tThruSections 372
#define tWedge 373
#define tFillet 374
#define tChamfer 375
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
  (char* c1, char* c2, double val_default = 0., int type_treat = 0);
double treat_Struct_FullName_dot_tSTRING_Float
  (char* c1, char* c2, char* c3, double val_default = 0., int type_treat = 0);
char* treat_Struct_FullName_String
  (char* c1, char* c2, char* val_default = NULL, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, char* val_default = NULL, int type_treat = 0);

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
#line 153 "Gmsh.y"
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
#line 715 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 728 "Gmsh.tab.cpp"

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
#define YYLAST   15066

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  247
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  583
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2125

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
      44,    46,    48,    50,    52,    54,    56,    58,    61,    67,
      73,    81,    89,    97,   107,   114,   121,   128,   137,   138,
     141,   144,   147,   150,   153,   155,   159,   161,   165,   166,
     167,   178,   180,   184,   185,   199,   201,   205,   206,   222,
     231,   246,   247,   254,   256,   258,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   282,   288,   291,   299,   307,
     312,   316,   323,   333,   341,   348,   356,   363,   368,   377,
     387,   397,   404,   414,   421,   431,   437,   446,   455,   467,
     474,   484,   490,   498,   508,   518,   530,   538,   548,   558,
     559,   561,   562,   566,   572,   573,   583,   584,   596,   602,
     603,   613,   614,   618,   622,   628,   634,   635,   638,   639,
     641,   643,   647,   650,   652,   657,   660,   661,   664,   666,
     670,   673,   676,   679,   684,   686,   688,   692,   694,   696,
     700,   702,   704,   708,   710,   712,   716,   717,   723,   724,
     727,   735,   743,   751,   760,   769,   777,   785,   797,   806,
     814,   823,   832,   841,   851,   855,   860,   871,   879,   887,
     895,   903,   911,   919,   927,   935,   943,   951,   960,   973,
     982,   990,   998,  1007,  1016,  1025,  1034,  1043,  1052,  1058,
    1070,  1076,  1086,  1096,  1101,  1111,  1121,  1123,  1125,  1126,
    1129,  1136,  1143,  1150,  1157,  1166,  1177,  1192,  1209,  1222,
    1237,  1252,  1267,  1282,  1291,  1300,  1307,  1312,  1318,  1325,
    1332,  1336,  1341,  1345,  1351,  1358,  1364,  1368,  1372,  1377,
    1383,  1388,  1394,  1398,  1404,  1412,  1420,  1424,  1432,  1436,
    1439,  1442,  1445,  1448,  1451,  1467,  1470,  1473,  1476,  1479,
    1482,  1499,  1511,  1518,  1527,  1536,  1547,  1549,  1552,  1555,
    1557,  1561,  1565,  1570,  1575,  1577,  1579,  1585,  1597,  1611,
    1612,  1620,  1621,  1635,  1636,  1652,  1653,  1660,  1670,  1673,
    1677,  1688,  1690,  1693,  1699,  1707,  1710,  1713,  1717,  1720,
    1724,  1727,  1731,  1741,  1748,  1750,  1752,  1754,  1756,  1758,
    1759,  1762,  1766,  1770,  1775,  1785,  1790,  1805,  1806,  1810,
    1811,  1813,  1814,  1817,  1818,  1821,  1822,  1825,  1832,  1840,
    1847,  1853,  1857,  1866,  1872,  1877,  1884,  1896,  1908,  1927,
    1946,  1959,  1972,  1985,  1996,  2007,  2018,  2029,  2040,  2045,
    2050,  2055,  2060,  2065,  2070,  2075,  2080,  2085,  2088,  2092,
    2099,  2101,  2103,  2105,  2108,  2114,  2122,  2133,  2135,  2139,
    2142,  2145,  2148,  2152,  2156,  2160,  2164,  2168,  2172,  2176,
    2180,  2184,  2188,  2192,  2196,  2200,  2204,  2208,  2212,  2216,
    2220,  2226,  2231,  2236,  2241,  2246,  2251,  2256,  2261,  2266,
    2271,  2276,  2283,  2288,  2293,  2298,  2303,  2308,  2313,  2318,
    2323,  2330,  2337,  2344,  2349,  2351,  2353,  2355,  2357,  2359,
    2361,  2363,  2365,  2367,  2369,  2371,  2372,  2379,  2381,  2386,
    2393,  2395,  2400,  2405,  2410,  2417,  2423,  2431,  2436,  2441,
    2445,  2448,  2451,  2457,  2463,  2467,  2473,  2480,  2485,  2493,
    2500,  2507,  2514,  2519,  2526,  2531,  2532,  2535,  2536,  2539,
    2540,  2548,  2550,  2554,  2556,  2558,  2561,  2562,  2566,  2568,
    2571,  2574,  2578,  2582,  2594,  2604,  2612,  2620,  2622,  2626,
    2628,  2630,  2633,  2637,  2642,  2648,  2650,  2652,  2655,  2659,
    2663,  2669,  2674,  2677,  2680,  2683,  2686,  2690,  2694,  2698,
    2702,  2719,  2736,  2753,  2770,  2772,  2774,  2776,  2780,  2785,
    2790,  2795,  2802,  2809,  2818,  2827,  2832,  2847,  2852,  2857,
    2859,  2861,  2865,  2869,  2879,  2887,  2889,  2895,  2899,  2906,
    2908,  2912,  2914,  2916,  2921,  2926,  2930,  2936,  2943,  2949,
    2955,  2961,  2967,  2969,  2974,  2976,  2978,  2980,  2982,  2987,
    2994,  2999,  3006,  3012,  3020,  3025,  3030,  3035,  3044,  3049,
    3054,  3059,  3064,  3073,  3082,  3089,  3094,  3101,  3106,  3108,
    3113,  3118,  3119,  3126,  3131,  3134,  3139,  3141,  3145,  3151,
    3157,  3166,  3168,  3170
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     248,     0,    -1,   249,    -1,     1,     6,    -1,    -1,   249,
     250,    -1,   252,    -1,   253,    -1,   273,    -1,   116,   237,
     347,   238,     6,    -1,   294,    -1,   295,    -1,   299,    -1,
     300,    -1,   301,    -1,   302,    -1,   306,    -1,   315,    -1,
     316,    -1,   322,    -1,   323,    -1,   305,    -1,   304,    -1,
     303,    -1,   298,    -1,   325,    -1,   220,    -1,   220,   220,
      -1,    44,   237,   347,   238,     6,    -1,    45,   237,   347,
     238,     6,    -1,    44,   237,   347,   238,   251,   347,     6,
      -1,    44,   237,   347,   246,   343,   238,     6,    -1,    45,
     237,   347,   246,   343,   238,     6,    -1,    44,   237,   347,
     246,   343,   238,   251,   347,     6,    -1,   353,   347,   241,
     254,   242,     6,    -1,   155,     4,   239,   326,   240,     6,
      -1,   156,     4,   239,   326,   240,     6,    -1,   157,     4,
     239,   326,   246,   326,   240,     6,    -1,    -1,   254,   257,
      -1,   254,   261,    -1,   254,   264,    -1,   254,   266,    -1,
     254,   267,    -1,   326,    -1,   255,   246,   326,    -1,   326,
      -1,   256,   246,   326,    -1,    -1,    -1,     4,   258,   237,
     255,   238,   259,   241,   256,   242,     6,    -1,   347,    -1,
     260,   246,   347,    -1,    -1,   162,   237,   326,   246,   326,
     246,   326,   238,   262,   241,   260,   242,     6,    -1,   347,
      -1,   263,   246,   347,    -1,    -1,   163,   237,   326,   246,
     326,   246,   326,   246,   326,   238,   265,   241,   263,   242,
       6,    -1,   164,   241,   339,   242,   241,   339,   242,     6,
      -1,   164,   241,   339,   242,   241,   339,   242,   241,   339,
     242,   241,   339,   242,     6,    -1,    -1,   165,   268,   241,
     256,   242,     6,    -1,     7,    -1,   213,    -1,   212,    -1,
     211,    -1,   210,    -1,   235,    -1,   234,    -1,   237,    -1,
     239,    -1,   238,    -1,   240,    -1,    81,   239,   275,   240,
       6,    -1,    82,   239,   279,   240,     6,    -1,   331,     6,
      -1,    88,   271,   348,   246,   326,   272,     6,    -1,    89,
     271,   353,   246,   348,   272,     6,    -1,   353,   269,   340,
       6,    -1,   353,   270,     6,    -1,   353,   271,   272,   269,
     340,     6,    -1,   353,   271,   241,   343,   242,   272,   269,
     340,     6,    -1,   353,   239,   326,   240,   269,   326,     6,
      -1,   353,   239,   326,   240,   270,     6,    -1,   353,   237,
     326,   238,   269,   326,     6,    -1,   353,   237,   326,   238,
     270,     6,    -1,   353,     7,   348,     6,    -1,   353,   271,
     272,     7,    46,   271,   272,     6,    -1,   353,   271,   272,
       7,    46,   271,   351,   272,     6,    -1,   353,   271,   272,
     213,    46,   271,   351,   272,     6,    -1,   353,   243,     4,
       7,   348,     6,    -1,   353,   239,   326,   240,   243,     4,
       7,   348,     6,    -1,   353,   243,     4,   269,   326,     6,
      -1,   353,   239,   326,   240,   243,     4,   269,   326,     6,
      -1,   353,   243,     4,   270,     6,    -1,   353,   239,   326,
     240,   243,     4,   270,     6,    -1,   353,   243,   172,   243,
       4,     7,   344,     6,    -1,   353,   239,   326,   240,   243,
     172,   243,     4,     7,   344,     6,    -1,   353,   243,   173,
       7,   345,     6,    -1,   353,   239,   326,   240,   243,   173,
       7,   345,     6,    -1,   353,   183,     7,   326,     6,    -1,
     183,   239,   326,   240,     7,     4,     6,    -1,   183,   239,
     326,   240,   243,     4,     7,   326,     6,    -1,   183,   239,
     326,   240,   243,     4,     7,   348,     6,    -1,   183,   239,
     326,   240,   243,     4,     7,   241,   343,   242,     6,    -1,
     183,   239,   326,   240,   243,     4,     6,    -1,   128,   237,
       4,   238,   243,     4,     7,   326,     6,    -1,   128,   237,
       4,   238,   243,     4,     7,   348,     6,    -1,    -1,   246,
      -1,    -1,   275,   274,   353,    -1,   275,   274,   353,     7,
     326,    -1,    -1,   275,   274,   353,     7,   241,   340,   276,
     281,   242,    -1,    -1,   275,   274,   353,   271,   272,     7,
     241,   340,   277,   281,   242,    -1,   275,   274,   353,     7,
     348,    -1,    -1,   275,   274,   353,     7,   241,   348,   278,
     285,   242,    -1,    -1,   279,   274,   347,    -1,   326,     7,
     348,    -1,   280,   246,   326,     7,   348,    -1,   342,     7,
     353,   237,   238,    -1,    -1,   246,   283,    -1,    -1,   283,
      -1,   284,    -1,   283,   246,   284,    -1,     4,   340,    -1,
       4,    -1,     4,   241,   280,   242,    -1,     4,   348,    -1,
      -1,   246,   286,    -1,   287,    -1,   286,   246,   287,    -1,
       4,   326,    -1,     4,   348,    -1,   187,   348,    -1,     4,
     241,   351,   242,    -1,   326,    -1,   348,    -1,   348,   246,
     326,    -1,   326,    -1,   348,    -1,   348,   246,   326,    -1,
     326,    -1,   348,    -1,   348,   246,   326,    -1,   326,    -1,
     348,    -1,   348,   246,   326,    -1,    -1,   175,    94,   241,
     326,   242,    -1,    -1,   121,   337,    -1,    90,   237,   326,
     238,     7,   337,     6,    -1,    93,   237,   326,   238,     7,
     340,     6,    -1,    97,   237,   326,   238,     7,   340,     6,
      -1,    91,   237,   326,   238,     7,   340,   293,     6,    -1,
      92,   237,   326,   238,     7,   340,   293,     6,    -1,   167,
     237,   326,   238,     7,   340,     6,    -1,   168,   237,   326,
     238,     7,   340,     6,    -1,   169,   237,   326,   238,     7,
     340,   171,   340,   170,   326,     6,    -1,   125,    93,   237,
     326,   238,     7,   340,     6,    -1,   108,   237,   326,   238,
       7,   340,     6,    -1,    93,     4,   237,   326,   238,     7,
     340,     6,    -1,   121,    96,   237,   326,   238,     7,   340,
       6,    -1,    96,   237,   326,   238,     7,   340,   292,     6,
      -1,   122,    96,   237,   326,   238,     7,   340,   292,     6,
      -1,    13,    14,     6,    -1,    14,    96,   326,     6,    -1,
     111,    96,   237,   326,   238,     7,     5,     5,     5,     6,
      -1,    94,   237,   326,   238,     7,   340,     6,    -1,    95,
     237,   326,   238,     7,   340,     6,    -1,    99,   237,   326,
     238,     7,   340,     6,    -1,   102,   237,   326,   238,     7,
     340,     6,    -1,   106,   237,   326,   238,     7,   340,     6,
      -1,   107,   237,   326,   238,     7,   340,     6,    -1,   100,
     237,   326,   238,     7,   340,     6,    -1,   101,   237,   326,
     238,     7,   340,     6,    -1,   118,   237,   326,   238,     7,
     340,     6,    -1,   143,   237,   326,   238,     7,   340,     6,
      -1,   125,    96,   237,   326,   238,     7,   340,     6,    -1,
     125,    96,   237,   326,   238,     7,   340,     4,   241,   339,
     242,     6,    -1,    96,     4,   237,   326,   238,     7,   340,
       6,    -1,    98,   237,   326,   238,     7,   340,     6,    -1,
     117,   237,   326,   238,     7,   340,     6,    -1,   122,   117,
     237,   326,   238,     7,   340,     6,    -1,   125,    98,   237,
     326,   238,     7,   340,     6,    -1,   124,    90,   237,   288,
     238,   269,   340,     6,    -1,   124,    93,   237,   289,   238,
     269,   340,     6,    -1,   124,    96,   237,   290,   238,   269,
     340,     6,    -1,   124,    98,   237,   291,   238,   269,   340,
       6,    -1,   132,   337,   241,   296,   242,    -1,   131,   241,
     337,   246,   337,   246,   326,   242,   241,   296,   242,    -1,
     133,   337,   241,   296,   242,    -1,   134,   241,   337,   246,
     326,   242,   241,   296,   242,    -1,   134,   241,   337,   246,
     337,   242,   241,   296,   242,    -1,     4,   241,   296,   242,
      -1,   149,    93,   241,   343,   242,    96,   241,   326,   242,
      -1,   146,    93,   237,   326,   238,   241,   343,   242,     6,
      -1,   297,    -1,   295,    -1,    -1,   297,   294,    -1,   297,
      90,   241,   343,   242,     6,    -1,   297,    93,   241,   343,
     242,     6,    -1,   297,    96,   241,   343,   242,     6,    -1,
     297,    98,   241,   343,   242,     6,    -1,   136,   121,   237,
     326,   238,     7,   340,     6,    -1,   136,    90,   237,   326,
     238,     7,   241,   339,   242,     6,    -1,   136,   121,   237,
     326,   238,     7,   241,   337,   246,   337,   246,   343,   242,
       6,    -1,   136,   121,   237,   326,   238,     7,   241,   337,
     246,   337,   246,   337,   246,   343,   242,     6,    -1,   136,
      94,   237,   326,   238,     7,   241,   337,   246,   343,   242,
       6,    -1,   136,   100,   237,   326,   238,     7,   241,   337,
     246,   337,   246,   343,   242,     6,    -1,   136,   101,   237,
     326,   238,     7,   241,   337,   246,   337,   246,   343,   242,
       6,    -1,   136,   103,   237,   326,   238,     7,   241,   337,
     246,   337,   246,   343,   242,     6,    -1,   136,   104,   237,
     326,   238,     7,   241,   337,   246,   337,   246,   343,   242,
       6,    -1,   136,     4,   237,   326,   238,     7,   340,     6,
      -1,   136,     4,   237,   326,   238,     7,     5,     6,    -1,
     136,     4,   241,   326,   242,     6,    -1,   147,   241,   297,
     242,    -1,   130,   147,   241,   297,   242,    -1,   147,   183,
     239,   326,   240,     6,    -1,   147,     4,   239,   326,   240,
       6,    -1,   147,   353,     6,    -1,   147,     4,     4,     6,
      -1,   147,    84,     6,    -1,   172,   344,   241,   297,   242,
      -1,   130,   172,   344,   241,   297,   242,    -1,   207,   326,
     241,   297,   242,    -1,   188,     5,     6,    -1,   189,     5,
       6,    -1,   188,   241,   297,   242,    -1,   130,   188,   241,
     297,   242,    -1,   189,   241,   297,   242,    -1,   130,   189,
     241,   297,   242,    -1,   353,   348,     6,    -1,    73,   237,
     351,   238,     6,    -1,   353,   353,   239,   326,   240,   347,
       6,    -1,   353,   353,   353,   239,   326,   240,     6,    -1,
     353,   326,     6,    -1,   128,   237,     4,   238,   243,     4,
       6,    -1,   166,     4,     6,    -1,   181,     6,    -1,   182,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   241,   326,   246,   326,   246,   326,   246,   326,
     246,   326,   246,   326,   242,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    78,     6,    -1,    79,     6,    -1,   113,
       6,    -1,   114,   241,   343,   242,   241,   343,   242,   241,
     339,   242,   241,   326,   246,   326,   242,     6,    -1,   186,
     237,   241,   343,   242,   246,   348,   246,   348,   238,     6,
      -1,   174,   237,   326,     8,   326,   238,    -1,   174,   237,
     326,     8,   326,     8,   326,   238,    -1,   174,     4,   175,
     241,   326,     8,   326,   242,    -1,   174,     4,   175,   241,
     326,     8,   326,     8,   326,   242,    -1,   176,    -1,   187,
       4,    -1,   187,   348,    -1,   184,    -1,   185,   353,     6,
      -1,   185,   348,     6,    -1,   177,   237,   326,   238,    -1,
     178,   237,   326,   238,    -1,   179,    -1,   180,    -1,   135,
     337,   241,   297,   242,    -1,   135,   241,   337,   246,   337,
     246,   326,   242,   241,   297,   242,    -1,   135,   241,   337,
     246,   337,   246,   337,   246,   326,   242,   241,   297,   242,
      -1,    -1,   135,   337,   241,   297,   307,   311,   242,    -1,
      -1,   135,   241,   337,   246,   337,   246,   326,   242,   241,
     297,   308,   311,   242,    -1,    -1,   135,   241,   337,   246,
     337,   246,   337,   246,   326,   242,   241,   297,   309,   311,
     242,    -1,    -1,   135,   241,   297,   310,   311,   242,    -1,
     135,   241,   297,   242,   127,   108,   241,   326,   242,    -1,
     117,   340,    -1,   122,   117,   340,    -1,   119,   241,   343,
     242,   241,   343,   242,   241,   326,   242,    -1,   312,    -1,
     311,   312,    -1,   152,   241,   326,   242,     6,    -1,   152,
     241,   340,   246,   340,   242,     6,    -1,   153,     6,    -1,
     144,     6,    -1,   144,   326,     6,    -1,   158,     6,    -1,
     158,   160,     6,    -1,   159,     6,    -1,   159,   160,     6,
      -1,   154,   237,   326,   238,     7,   340,   127,   326,     6,
      -1,   127,     4,   239,   326,   240,     6,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,    -1,   147,
       6,    -1,   130,   147,     6,    -1,   147,   326,     6,    -1,
     130,   147,   326,     6,    -1,   313,   241,   297,   314,   242,
     241,   297,   314,   242,    -1,   105,   237,   347,   238,    -1,
     313,   237,   326,   238,     7,   241,   297,   314,   242,   241,
     297,   314,   242,     6,    -1,    -1,   127,     4,   326,    -1,
      -1,     4,    -1,    -1,     7,   340,    -1,    -1,     7,   326,
      -1,    -1,   137,   340,    -1,   109,   110,   340,     7,   326,
       6,    -1,   123,    93,   341,     7,   326,   317,     6,    -1,
     123,    96,   341,   319,   318,     6,    -1,   123,    98,   341,
     319,     6,    -1,   161,   341,     6,    -1,   150,    96,   241,
     343,   242,     7,   326,     6,    -1,   144,    96,   341,   320,
       6,    -1,   144,    98,   341,     6,    -1,   145,    96,   341,
       7,   326,     6,    -1,   126,    93,   241,   343,   242,     7,
     241,   343,   242,   321,     6,    -1,   126,    96,   241,   343,
     242,     7,   241,   343,   242,   321,     6,    -1,   126,    93,
     241,   343,   242,     7,   241,   343,   242,   131,   241,   337,
     246,   337,   246,   326,   242,     6,    -1,   126,    96,   241,
     343,   242,     7,   241,   343,   242,   131,   241,   337,   246,
     337,   246,   326,   242,     6,    -1,   126,    93,   241,   343,
     242,     7,   241,   343,   242,   132,   337,     6,    -1,   126,
      96,   241,   343,   242,     7,   241,   343,   242,   132,   337,
       6,    -1,   126,    96,   326,   241,   343,   242,     7,   326,
     241,   343,   242,     6,    -1,    90,   241,   343,   242,   175,
      96,   241,   326,   242,     6,    -1,    93,   241,   343,   242,
     175,    96,   241,   326,   242,     6,    -1,    90,   241,   343,
     242,   175,    98,   241,   326,   242,     6,    -1,    93,   241,
     343,   242,   175,    98,   241,   326,   242,     6,    -1,    96,
     241,   343,   242,   175,    98,   241,   326,   242,     6,    -1,
     151,    96,   341,     6,    -1,   151,    93,   341,     6,    -1,
     115,    90,   341,     6,    -1,   115,    93,   341,     6,    -1,
     115,    96,   341,     6,    -1,   129,    93,   340,     6,    -1,
     125,    93,   340,     6,    -1,   125,    96,   340,     6,    -1,
     125,    98,   340,     6,    -1,   148,     6,    -1,   148,     4,
       6,    -1,   148,    90,   241,   343,   242,     6,    -1,   196,
      -1,   197,    -1,   198,    -1,   324,     6,    -1,   324,   241,
     340,   242,     6,    -1,   324,   241,   340,   246,   340,   242,
       6,    -1,   324,   237,   340,   238,   241,   340,   246,   340,
     242,     6,    -1,   327,    -1,   237,   326,   238,    -1,   226,
     326,    -1,   225,   326,    -1,   232,   326,    -1,   326,   226,
     326,    -1,   326,   225,   326,    -1,   326,   227,   326,    -1,
     326,   228,   326,    -1,   326,   230,   326,    -1,   326,   231,
     326,    -1,   326,   229,   326,    -1,   326,   236,   326,    -1,
     326,   219,   326,    -1,   326,   220,   326,    -1,   326,   224,
     326,    -1,   326,   223,   326,    -1,   326,   218,   326,    -1,
     326,   217,   326,    -1,   326,   216,   326,    -1,   326,   215,
     326,    -1,   326,   221,   326,    -1,   326,   222,   326,    -1,
     326,   214,   326,     8,   326,    -1,    16,   271,   326,   272,
      -1,    17,   271,   326,   272,    -1,    18,   271,   326,   272,
      -1,    19,   271,   326,   272,    -1,    20,   271,   326,   272,
      -1,    21,   271,   326,   272,    -1,    22,   271,   326,   272,
      -1,    23,   271,   326,   272,    -1,    24,   271,   326,   272,
      -1,    26,   271,   326,   272,    -1,    27,   271,   326,   246,
     326,   272,    -1,    28,   271,   326,   272,    -1,    29,   271,
     326,   272,    -1,    30,   271,   326,   272,    -1,    31,   271,
     326,   272,    -1,    32,   271,   326,   272,    -1,    33,   271,
     326,   272,    -1,    34,   271,   326,   272,    -1,    35,   271,
     326,   272,    -1,    36,   271,   326,   246,   326,   272,    -1,
      37,   271,   326,   246,   326,   272,    -1,    38,   271,   326,
     246,   326,   272,    -1,    25,   271,   326,   272,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   203,
      -1,   204,    -1,   205,    -1,    75,    -1,    76,    -1,    77,
      -1,    -1,    83,   271,   326,   328,   281,   272,    -1,   331,
      -1,   194,   271,   347,   272,    -1,   194,   271,   347,   246,
     326,   272,    -1,   333,    -1,   353,   239,   326,   240,    -1,
     353,   237,   326,   238,    -1,   199,   237,   333,   238,    -1,
     199,   237,   333,   243,   334,   238,    -1,   201,   237,   333,
     329,   238,    -1,   201,   237,   333,   243,   334,   329,   238,
      -1,   200,   237,   348,   238,    -1,   244,   353,   271,   272,
      -1,   244,   353,     9,    -1,   244,     9,    -1,   353,   270,
      -1,   353,   239,   326,   240,   270,    -1,   353,   237,   326,
     238,   270,    -1,   353,   243,   334,    -1,   353,     9,   353,
     243,   334,    -1,   353,   239,   326,   240,   243,     4,    -1,
     353,   243,     4,   270,    -1,   353,   239,   326,   240,   243,
       4,   270,    -1,   190,   237,   347,   246,   326,   238,    -1,
      56,   237,   340,   246,   340,   238,    -1,    57,   271,   347,
     246,   347,   272,    -1,    55,   271,   347,   272,    -1,    58,
     271,   347,   246,   347,   272,    -1,    63,   237,   351,   238,
      -1,    -1,   246,   326,    -1,    -1,   246,   347,    -1,    -1,
      84,   333,   336,   332,   239,   282,   240,    -1,   353,    -1,
     353,     9,   353,    -1,     4,    -1,    86,    -1,    86,   326,
      -1,    -1,   237,   335,   238,    -1,   338,    -1,   226,   337,
      -1,   225,   337,    -1,   337,   226,   337,    -1,   337,   225,
     337,    -1,   241,   326,   246,   326,   246,   326,   246,   326,
     246,   326,   242,    -1,   241,   326,   246,   326,   246,   326,
     246,   326,   242,    -1,   241,   326,   246,   326,   246,   326,
     242,    -1,   237,   326,   246,   326,   246,   326,   238,    -1,
     340,    -1,   339,   246,   340,    -1,   326,    -1,   342,    -1,
     241,   242,    -1,   241,   343,   242,    -1,   226,   241,   343,
     242,    -1,   326,   227,   241,   343,   242,    -1,   340,    -1,
       5,    -1,   226,   342,    -1,   326,   227,   342,    -1,   326,
       8,   326,    -1,   326,     8,   326,     8,   326,    -1,    90,
     241,   326,   242,    -1,    90,     5,    -1,    93,     5,    -1,
      96,     5,    -1,    98,     5,    -1,   124,    90,   341,    -1,
     124,    93,   341,    -1,   124,    96,   341,    -1,   124,    98,
     341,    -1,    90,   175,    64,   241,   326,   246,   326,   246,
     326,   246,   326,   246,   326,   246,   326,   242,    -1,    93,
     175,    64,   241,   326,   246,   326,   246,   326,   246,   326,
     246,   326,   246,   326,   242,    -1,    96,   175,    64,   241,
     326,   246,   326,   246,   326,   246,   326,   246,   326,   246,
     326,   242,    -1,    98,   175,    64,   241,   326,   246,   326,
     246,   326,   246,   326,   246,   326,   246,   326,   242,    -1,
     295,    -1,   306,    -1,   315,    -1,   353,   271,   272,    -1,
      39,   239,   353,   240,    -1,    39,   239,   342,   240,    -1,
      39,   237,   342,   238,    -1,    39,   271,   241,   343,   242,
     272,    -1,   353,   271,   241,   343,   242,   272,    -1,    40,
     271,   326,   246,   326,   246,   326,   272,    -1,    41,   271,
     326,   246,   326,   246,   326,   272,    -1,    42,   271,   347,
     272,    -1,    43,   271,   326,   246,   326,   246,   326,   246,
     326,   246,   326,   246,   326,   272,    -1,   195,   271,   342,
     272,    -1,    32,   271,   342,   272,    -1,   326,    -1,   342,
      -1,   343,   246,   326,    -1,   343,   246,   342,    -1,   241,
     326,   246,   326,   246,   326,   246,   326,   242,    -1,   241,
     326,   246,   326,   246,   326,   242,    -1,   353,    -1,     4,
     243,   172,   243,     4,    -1,   241,   346,   242,    -1,   353,
     239,   326,   240,   243,   173,    -1,   344,    -1,   346,   246,
     344,    -1,   348,    -1,   353,    -1,   353,   239,   326,   240,
      -1,   353,   237,   326,   238,    -1,   353,   243,   334,    -1,
     353,     9,   353,   243,   334,    -1,   353,   239,   326,   240,
     243,     4,    -1,   124,    90,   241,   326,   242,    -1,   124,
      93,   241,   326,   242,    -1,   124,    96,   241,   326,   242,
      -1,   124,    98,   241,   326,   242,    -1,     5,    -1,   208,
     239,   353,   240,    -1,    67,    -1,   206,    -1,    72,    -1,
      74,    -1,   192,   237,   347,   238,    -1,   191,   237,   347,
     246,   347,   238,    -1,   193,   271,   347,   272,    -1,   193,
     271,   347,   246,   347,   272,    -1,   202,   237,   333,   330,
     238,    -1,   202,   237,   333,   243,   334,   330,   238,    -1,
      48,   271,   351,   272,    -1,    49,   237,   347,   238,    -1,
      50,   237,   347,   238,    -1,    51,   237,   347,   246,   347,
     246,   347,   238,    -1,    46,   271,   351,   272,    -1,    60,
     271,   347,   272,    -1,    61,   271,   347,   272,    -1,    62,
     271,   347,   272,    -1,    59,   271,   326,   246,   347,   246,
     347,   272,    -1,    54,   271,   347,   246,   326,   246,   326,
     272,    -1,    54,   271,   347,   246,   326,   272,    -1,    47,
     271,   347,   272,    -1,    47,   271,   347,   246,   343,   272,
      -1,    68,   271,   347,   272,    -1,    69,    -1,    53,   271,
     347,   272,    -1,    52,   271,   347,   272,    -1,    -1,    87,
     271,   348,   349,   285,   272,    -1,    85,   271,   350,   272,
      -1,   244,   326,    -1,   353,     9,   244,   326,    -1,   347,
      -1,   351,   246,   347,    -1,     4,   245,   241,   326,   242,
      -1,   352,   245,   241,   326,   242,    -1,   209,   239,   347,
     240,   245,   241,   326,   242,    -1,     4,    -1,   352,    -1,
     209,   239,   347,   240,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   253,   253,   254,   259,   261,   265,   266,   267,   268,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   306,   310,   317,   322,
     327,   341,   354,   367,   395,   409,   422,   435,   454,   459,
     460,   461,   462,   463,   467,   469,   474,   476,   482,   586,
     481,   604,   611,   622,   621,   639,   646,   657,   656,   673,
     690,   713,   712,   726,   727,   728,   729,   730,   734,   735,
     741,   741,   742,   742,   748,   749,   750,   751,   756,   762,
     824,   839,   868,   878,   883,   891,   896,   904,   913,   918,
     930,   947,   953,   962,   980,   998,  1007,  1019,  1024,  1032,
    1052,  1075,  1086,  1094,  1116,  1139,  1177,  1198,  1210,  1224,
    1224,  1226,  1228,  1237,  1247,  1246,  1267,  1266,  1284,  1294,
    1293,  1307,  1309,  1317,  1323,  1328,  1354,  1356,  1359,  1361,
    1365,  1366,  1370,  1382,  1395,  1410,  1420,  1422,  1426,  1427,
    1432,  1440,  1449,  1457,  1475,  1479,  1486,  1494,  1498,  1505,
    1513,  1517,  1524,  1532,  1536,  1543,  1552,  1555,  1562,  1565,
    1572,  1596,  1612,  1628,  1665,  1705,  1721,  1737,  1759,  1769,
    1785,  1802,  1818,  1839,  1850,  1856,  1862,  1869,  1900,  1915,
    1937,  1960,  1983,  2006,  2030,  2054,  2077,  2102,  2112,  2135,
    2152,  2168,  2186,  2204,  2214,  2226,  2238,  2250,  2267,  2283,
    2299,  2314,  2329,  2344,  2379,  2401,  2425,  2426,  2431,  2434,
    2438,  2449,  2460,  2471,  2487,  2506,  2527,  2542,  2558,  2576,
    2627,  2648,  2670,  2693,  2798,  2814,  2849,  2860,  2871,  2877,
    2892,  2920,  2932,  2941,  2948,  2960,  2979,  2985,  2991,  2998,
    3005,  3012,  3024,  3097,  3115,  3132,  3147,  3180,  3192,  3216,
    3220,  3225,  3232,  3237,  3247,  3252,  3258,  3266,  3270,  3274,
    3283,  3347,  3363,  3380,  3397,  3419,  3441,  3476,  3484,  3492,
    3498,  3505,  3512,  3532,  3558,  3570,  3582,  3600,  3618,  3637,
    3636,  3661,  3660,  3687,  3686,  3711,  3710,  3733,  3749,  3766,
    3783,  3806,  3809,  3815,  3827,  3847,  3851,  3855,  3859,  3863,
    3867,  3871,  3875,  3884,  3897,  3898,  3899,  3900,  3901,  3905,
    3906,  3907,  3908,  3909,  3912,  3935,  3954,  3976,  3979,  3995,
    3998,  4015,  4018,  4024,  4027,  4034,  4037,  4044,  4061,  4102,
    4146,  4185,  4210,  4219,  4249,  4275,  4301,  4333,  4360,  4386,
    4412,  4438,  4464,  4486,  4492,  4498,  4504,  4510,  4516,  4542,
    4568,  4585,  4602,  4619,  4631,  4637,  4643,  4655,  4659,  4669,
    4680,  4681,  4682,  4686,  4692,  4704,  4722,  4750,  4751,  4752,
    4753,  4754,  4755,  4756,  4757,  4758,  4765,  4766,  4767,  4768,
    4769,  4770,  4771,  4772,  4773,  4774,  4775,  4776,  4777,  4778,
    4779,  4780,  4781,  4782,  4783,  4784,  4785,  4786,  4787,  4788,
    4789,  4790,  4791,  4792,  4793,  4794,  4795,  4796,  4797,  4798,
    4799,  4800,  4801,  4802,  4811,  4812,  4813,  4814,  4815,  4816,
    4817,  4818,  4819,  4820,  4821,  4826,  4825,  4833,  4835,  4840,
    4845,  4849,  4867,  4885,  4889,  4893,  4897,  4901,  4907,  4923,
    4929,  4935,  4954,  4975,  5008,  5012,  5017,  5022,  5032,  5042,
    5047,  5058,  5067,  5072,  5077,  5105,  5106,  5112,  5113,  5119,
    5118,  5141,  5143,  5148,  5157,  5159,  5165,  5166,  5172,  5176,
    5180,  5184,  5188,  5195,  5199,  5203,  5207,  5214,  5219,  5226,
    5231,  5235,  5240,  5244,  5252,  5263,  5267,  5279,  5287,  5295,
    5302,  5312,  5335,  5341,  5347,  5353,  5359,  5370,  5381,  5392,
    5403,  5409,  5415,  5421,  5427,  5437,  5447,  5457,  5470,  5482,
    5486,  5490,  5494,  5512,  5520,  5528,  5557,  5567,  5583,  5594,
    5599,  5603,  5607,  5619,  5623,  5635,  5652,  5662,  5666,  5681,
    5686,  5693,  5697,  5702,  5716,  5733,  5737,  5742,  5750,  5756,
    5762,  5768,  5777,  5781,  5785,  5793,  5799,  5805,  5809,  5817,
    5825,  5832,  5842,  5847,  5852,  5867,  5881,  5895,  5907,  5923,
    5932,  5941,  5951,  5962,  5970,  5978,  5982,  6001,  6008,  6014,
    6021,  6029,  6028,  6038,  6062,  6064,  6070,  6075,  6083,  6092,
    6101,  6113,  6116,  6120
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
  "tDefineNumber", "tDefineStruct", "tNameStruct", "tAppend",
  "tDefineString", "tSetNumber", "tSetString", "tPoint", "tCircle",
  "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline",
  "tVolume", "tBlock", "tCylinder", "tCone", "tTorus", "tEllipsoid",
  "tQuadric", "tShapeFromFile", "tRectangle", "tDisk", "tWire",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tSetFactory", "tThruSections", "tWedge",
  "tFillet", "tChamfer", "tPlane", "tRuled", "tTransfinite", "tPhysical",
  "tCompound", "tPeriodic", "tUsing", "tPlugin", "tDegenerated",
  "tRecursive", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanDifference", "tBooleanSection",
  "tBooleanFragments", "tThickSolid", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse",
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
  "CharParameterOption", "PhysicalId0", "PhysicalId1", "PhysicalId2",
  "PhysicalId3", "InSphereCenter", "CircleOptions", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "SetPartition", "Visibility", "Command", "Slide", "Loop", "Extrude",
  "@9", "@10", "@11", "@12", "ExtrudeParameters", "ExtrudeParameter",
  "BooleanOperator", "BooleanOption", "Boolean", "BooleanShape",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "PeriodicTransform", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "@13",
  "GetForced_Default", "GetForcedStr_Default", "DefineStruct", "@14",
  "Struct_FullName", "tSTRING_Member_Float", "Append", "AppendOrNot",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "@15", "NameStruct_Arg", "RecursiveListOfStringExprVar", "StringIndex",
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
     273,   273,   273,   273,   273,   273,   273,   273,   273,   274,
     274,   275,   275,   275,   276,   275,   277,   275,   275,   278,
     275,   279,   279,   280,   280,   280,   281,   281,   282,   282,
     283,   283,   284,   284,   284,   284,   285,   285,   286,   286,
     287,   287,   287,   287,   288,   288,   288,   289,   289,   289,
     290,   290,   290,   291,   291,   291,   292,   292,   293,   293,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   295,   295,
     295,   295,   295,   295,   295,   295,   296,   296,   297,   297,
     297,   297,   297,   297,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   299,   299,   299,   299,
     299,   299,   299,   300,   300,   301,   302,   302,   302,   302,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   304,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   306,   306,   307,
     306,   308,   306,   309,   306,   310,   306,   306,   306,   306,
     306,   311,   311,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   313,   313,   313,   313,   313,   314,
     314,   314,   314,   314,   315,   315,   316,   317,   317,   318,
     318,   319,   319,   320,   320,   321,   321,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   323,   323,   323,
     324,   324,   324,   325,   325,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   328,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   329,   329,   330,   330,   332,
     331,   333,   333,   334,   335,   335,   336,   336,   337,   337,
     337,   337,   337,   338,   338,   338,   338,   339,   339,   340,
     340,   340,   340,   340,   340,   341,   341,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   343,
     343,   343,   343,   344,   344,   344,   344,   345,   345,   346,
     346,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   349,   348,   348,   350,   350,   351,   351,   352,   352,
     352,   353,   353,   353
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     5,
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
       1,     4,     4,     4,     6,     5,     7,     4,     4,     3,
       2,     2,     5,     5,     3,     5,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     0,     2,     0,     2,     0,
       7,     1,     3,     1,     1,     2,     0,     3,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     3,     3,     3,     3,
      16,    16,    16,    16,     1,     1,     1,     3,     4,     4,
       4,     6,     6,     8,     8,     4,    14,     4,     4,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     4,     4,     3,     5,     6,     5,     5,
       5,     5,     1,     4,     1,     1,     1,     1,     4,     6,
       4,     6,     5,     7,     4,     4,     4,     8,     4,     4,
       4,     4,     8,     8,     6,     4,     6,     4,     1,     4,
       4,     0,     6,     4,     2,     4,     1,     3,     5,     5,
       8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   581,     0,     0,     0,
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
       0,   582,     0,   208,     0,     0,     0,     0,     0,   253,
       0,   255,   256,   251,   252,     0,   257,   258,   111,   121,
     581,   466,   461,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,     0,   414,   415,   417,
     418,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,   423,   424,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,   504,   505,     0,   506,   479,   367,   427,   430,   288,
     480,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,     0,     0,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   581,
       0,     0,   208,     0,     0,   357,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,   485,     0,     0,     0,
       0,     0,   581,     0,     0,   525,     0,     0,     0,     0,
     249,   250,     0,   542,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   544,     0,   568,
     546,   547,     0,     0,     0,     0,     0,     0,   545,     0,
       0,     0,     0,   267,   268,     0,   208,     0,   208,     0,
       0,     0,   461,     0,     0,   208,   363,     0,     0,    76,
       0,    63,     0,     0,    67,    66,    65,    64,    69,    68,
      70,    71,     0,     0,     0,     0,     0,     0,   531,   461,
       0,   207,     0,   206,     0,   174,     0,     0,   531,   532,
       0,     0,   576,     0,   109,   109,     0,   459,     0,     0,
       0,     0,     0,   519,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   492,
       0,     0,   493,     0,   494,     0,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
       0,   369,   487,   371,     0,   481,     0,   440,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,   441,     0,     0,     0,     0,     0,     0,
     289,     0,   321,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,   208,   208,     0,   470,   469,     0,     0,     0,     0,
     208,   208,     0,     0,     0,     0,   285,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,     0,   232,     0,     0,   230,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   331,
     248,     0,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   270,     0,   236,     0,   237,     0,
       0,   369,     0,   208,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    72,    73,     0,     0,   246,
      38,   242,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,   464,     0,     0,   462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,     0,     0,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   461,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   425,
       0,     0,     0,     0,     0,   496,   497,   498,   499,     0,
       0,     0,     0,     0,   455,     0,   368,   482,   439,     0,
     489,     0,   387,   386,   385,   384,   380,   381,   388,   389,
     383,   382,   373,   372,     0,   374,   488,   375,   378,   376,
     377,   379,   462,     0,     0,   463,   444,     0,   507,     0,
       0,     0,     0,     0,     0,     0,   319,     0,     0,   144,
     145,     0,   147,   148,     0,   150,   151,     0,   153,   154,
       0,   354,     0,   355,     0,   356,     0,     0,     0,     0,
     353,     0,   208,     0,     0,     0,     0,     0,   472,   471,
       0,     0,     0,     0,     0,     0,     0,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     334,     0,     0,   231,     0,     0,   226,     0,     0,     0,
     349,   348,     0,     0,     0,   368,     0,     0,     0,     0,
       0,     0,     0,     0,   272,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   571,     0,     0,     0,   457,     0,
       0,   238,   240,     0,   374,     0,   583,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,   368,     0,    63,     0,     0,     0,     0,    79,     0,
      63,    64,     0,     0,   462,     0,     0,   444,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   578,    28,
      26,     0,     0,     0,     0,     0,   463,   535,    29,     0,
       0,   243,   577,    74,   112,    75,   122,   465,   467,   128,
       0,     0,     0,     0,   521,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   413,   400,
       0,   402,   403,   404,   405,   406,   518,   407,   408,   409,
       0,     0,     0,   510,   509,   508,     0,     0,     0,   515,
       0,   452,     0,     0,     0,   454,   126,     0,   491,     0,
       0,     0,     0,     0,   428,   517,   433,     0,   437,     0,
       0,     0,   483,     0,   438,     0,     0,     0,     0,   432,
     431,   447,     0,     0,     0,     0,     0,   368,   317,   322,
     320,     0,   330,     0,     0,     0,     0,     0,     0,     0,
       0,   368,   368,   368,     0,     0,     0,     0,   227,     0,
     239,   241,     0,     0,     0,   198,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,   558,     0,   565,   554,   555,   556,
       0,   570,   569,     0,     0,   559,   560,   561,   567,   574,
     573,     0,   136,     0,   548,     0,   550,     0,     0,     0,
     543,     0,   235,     0,     0,     0,   310,     0,     0,     0,
     364,     0,   579,     0,     0,     0,     0,   101,    63,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,    61,
       0,    39,    40,    41,    42,    43,     0,   432,   431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,   534,   533,     0,     0,     0,     0,   133,
       0,   129,   130,     0,     0,     0,     0,     0,   158,   158,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   455,   456,   435,     0,   490,   390,   484,   445,   443,
       0,   442,     0,     0,     0,     0,     0,     0,     0,     0,
     329,     0,   146,     0,   149,     0,   152,     0,   155,     0,
       0,     0,     0,     0,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,   295,     0,   298,
       0,   300,     0,   286,   292,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,   229,
     228,   359,     0,     0,    35,    36,     0,     0,     0,     0,
     526,     0,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,   458,   552,     0,
       0,   208,   311,     0,   312,   208,     0,     0,   538,   539,
     540,   541,     0,    86,     0,     0,     0,     0,    84,    91,
      93,     0,   529,     0,    99,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    34,   445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,   536,     0,    32,     0,     0,   113,   118,     0,
       0,   132,   135,   460,     0,    77,    78,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   177,   178,     0,
       0,     0,     0,   162,   190,   179,   183,   184,   180,   181,
     182,   169,     0,     0,   401,   410,   411,   412,   511,     0,
       0,     0,   450,   451,   453,   127,   426,     0,     0,     0,
       0,   449,   429,   434,     0,   191,   446,   512,   185,     0,
       0,   156,     0,     0,   328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,     0,
     208,   208,     0,     0,   297,   479,     0,     0,   299,   301,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,   102,   106,     0,   566,     0,     0,
     564,     0,   575,     0,     0,   137,   138,   572,   549,   551,
       0,     0,     0,   309,   313,   309,     0,   365,    85,    63,
       0,     0,     0,     0,    83,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,     0,   446,
     244,   245,   210,   211,   212,   213,     0,     0,     0,     0,
       0,   537,     0,   114,   119,     0,     0,   519,   520,   131,
       0,     0,   159,   163,   164,   170,     0,     0,   189,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   436,   448,     0,   171,     0,   192,   318,   194,   195,
     196,   197,   168,     0,   187,   193,     0,     0,     0,     0,
       0,     0,   476,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   224,   223,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,     0,   332,    37,     0,
     524,     0,     0,   264,   263,     0,     0,     0,     0,     0,
       0,     0,   140,   141,   142,     0,   553,     0,   580,     0,
       0,     0,     0,     0,    96,     0,     0,    97,   530,     0,
       0,    88,     0,     0,     0,    44,     0,     0,     0,     0,
       0,    46,    33,     0,   126,   136,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
     514,     0,     0,     0,     0,     0,     0,   173,     0,   325,
     325,     0,   107,   108,   208,     0,   201,   202,   287,     0,
     293,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   204,     0,     0,     0,     0,   103,   104,
     557,   563,   562,     0,   139,     0,     0,   314,     0,    92,
      94,     0,   100,     0,    82,    89,    90,    49,     0,     0,
       0,     0,   478,     0,     0,     0,     0,     0,   116,     0,
     123,     0,   343,   345,   344,   346,     0,   347,   176,     0,
       0,     0,     0,     0,     0,   290,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,   303,     0,
       0,   281,     0,   215,     0,     0,     0,     0,     0,     0,
       0,   523,   265,     0,   143,     0,   208,   366,     0,   528,
       0,    45,     0,     0,     0,    62,    47,     0,   115,   120,
     126,     0,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   336,     0,     0,   337,     0,   199,
       0,   294,     0,   277,     0,   208,     0,     0,     0,     0,
       0,     0,   167,   105,   261,   309,    98,     0,     0,     0,
       0,     0,     0,   124,   125,     0,     0,     0,     0,     0,
       0,   188,     0,   340,     0,   341,   342,   473,     0,     0,
     283,   218,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    59,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,   302,   282,   278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     220,   221,   222,     0,   216,   316,    50,     0,    57,     0,
     254,     0,   516,     0,     0,     0,     0,     0,     0,   284,
       0,     0,    51,     0,     0,   260,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,   500,   501,   502,
     503,     0,     0,    54,    52,     0,    55,     0,   338,   339,
       0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1021,   109,   110,  1003,  1804,  1810,
    1281,  1490,  1950,  2091,  1282,  2056,  2115,  1283,  2093,  1284,
    1285,  1494,   403,   553,   554,  1085,   111,   731,   424,  1814,
    1960,  1815,   425,  1696,  1353,  1310,  1311,  1312,  1453,  1645,
    1646,   868,   871,   874,   877,  1541,  1531,   715,   251,   412,
     413,   114,   115,   116,   117,   118,   119,   120,   121,   252,
    1181,  1984,  2047,   905,  1177,  1178,   253,   980,   254,   125,
    1379,  1141,   866,   919,  1920,   126,   127,   128,   129,   255,
     256,  1106,  1121,  1239,   257,   736,   258,   856,   735,   427,
     585,   291,  1676,   326,   327,   260,   526,   334,  1269,  1483,
     422,   418,  1232,   962,   423,   131,   382
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1756
static const yytype_int16 yypact[] =
{
    9975,    30,    74, 10124, -1756, -1756,   -32,    10,    15,   -93,
     -87,    20,   156,   171,   180,   187,    12,   218,   250,   101,
     110,    31,     2,     2,   -26,   164,   204,    37,   209,   235,
      39,   277,   282,   289,   321,   331,   340,   345,   411,   417,
     447,   258,   290,   402,   194,   593,   471,  5747,   476,   482,
     636,   -30,   106,   536,   504,    75,   505,   680,   -82,   546,
     -68,   -68,   563,   -18,   377, -1756, -1756, -1756, -1756, -1756,
     582,   224,   725,   735,    29,    66,   740,   762,   326,   865,
     885,   907,  5042,   908,   676,   677,   679,    28,    54, -1756,
     681,   682, -1756, -1756,   909,   911,   686, -1756, 10319,   684,
   10349,    34,    41, -1756, -1756, -1756,  9806,   687, -1756, -1756,
   -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756,
   -1756, -1756, -1756,    97, -1756, -1756, -1756, -1756,    46, -1756,
     914,   685,  4786,   306,   688,   921,  9806, 10290, 10290, -1756,
    9806, -1756, -1756, -1756, -1756, 10290, -1756, -1756, -1756, -1756,
     689,   691,   922, -1756, -1756, 10378,    31,  9806,  8887,  9806,
    9806,   695,  9806,  8887,  9806,  9806,   698,  9806,  8887,  9806,
    9806,  9806,  9806,  9806,  9806, 10290,  9806,  9806,  9806,  5982,
     699, -1756,  8887,  5042,  5042,  5042, 10290, -1756, -1756, -1756,
   -1756, -1756,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    62,     2,     2,     2,     2,
       2,   701,     2,     2,   704, -1756, -1756, -1756,     2,     3,
      42,    51,    57,  5982,   825,   540,   706,     2,     2,   707,
     708,   709, -1756, -1756, -1756,  9806,  6217,  9806,  9806,  6452,
      25, -1756, -1756,   723, -1756,  4498, -1756, -1756, -1756, -1756,
   -1756,    96,  9806,  8887,   710,   711,  6687,  5042,  5042,  5042,
     730,   733,   734,   736,  6922,  7157,  7392,   728,  2658,   971,
    5982,   737,    28,   738,   741,   -68,   -68,   -68,  9806,  9806,
     179, -1756,   234,   -68,  9195,   260,   121,   739,   744,   746,
     747,   748,   749,   750,  9806,  5042,  5042,  5042,   751,     9,
     983,   756, -1756,   984,   990, -1756,   757,   759,   760,  5042,
    5042,   758,   763,   764, -1756,  9806, -1756,   998,   999,  9806,
    9806,  9806,   392,  9806,   769, -1756,   802,  9806,  9806,  9806,
   -1756, -1756,  9806, -1756,     2,     2,     2,   774,   775,   778,
       2,     2,     2,     2,     2,     2,     2, -1756,     2, -1756,
   -1756, -1756,     2,     2,   780,   782,     2,   785, -1756,   803,
    1035,  1044,   811, -1756, -1756,  1056, -1756,  1059, -1756,     2,
    9806, 12893,   116, 10290,  9806, -1756, -1756,  5982,  5982, -1756,
     826, 10378,   573,  1061, -1756, -1756, -1756, -1756, -1756, -1756,
    9806,  9806,    63,  5982,  1060,   548,   862,   828,  1065,    16,
     831, -1756,   833,  8719,  9806, -1756,  1676,   -92, -1756,    68,
     -79,  9066, -1756,   198,  -177,  -122,   987, -1756,    31,   848,
     849, 13355,  8887,  4661, -1756,    79, 13380, 13405,  9806, 13430,
     150, 13455, 13480,  9806, 13505,   297, 13530, 13555, 13580, 13605,
   13630, 13655,   858, 13680, 13705, 13730,  1095,  9806,   303,  1115,
    1116,  1117,   887,  9806,  9806,  9806,  9806,  9806,  9806,  9806,
    9806,  9806,  9806,  9806,  9806,  9806,  9806,  9806,  9806,  8887,
    9806,  9806,  9806,  9806,  9806,  9806,  8887,  8887,   886,  9806,
    9806, 10290,  9806, 10290,  5982, 10290, 10290, 10290,  9806, -1756,
    1062,  9806, -1756,  1064, -1756,  1068, -1756,  1069,  5982,  5042,
    5042,  5042,  5042, 10290, 10290,  8887,    31, 10378,    31,   893,
    8887,   893, -1756,   893, 13755, -1756,   327, -1756,    69,  9806,
    9806,  9806,  9806,  9806,  9806,  9806,  9806,  9806,  9806,  9806,
    9806,  9806,  9806,  7627,  9806,  9806,  9806,  9806,  9806,    31,
    9806,  9806,  1130, -1756,   663, 13780,   341,  9806,  9806,  9806,
   -1756,  1128,  1129,  1129,  9117,  9117,  9117,  9117,  9806,  1131,
    9806,  1132,  9806,  1133,  8887,  8887, 12921,   902,  1135, -1756,
     901, -1756, -1756,  -165, -1756, -1756,  9677, 10373,   -68,   -68,
     306,   306,  -150,  9195,  9195,  9806,  4296,  -132, -1756,  9806,
    9806,  9806,  9806,  9806,  9806,  9806,  9806,  9806, 13805,  1136,
    1138,  1147,  9806,  1149,  9806, -1756,  9806,  5109, -1756, -1756,
    8887,  8887,  8887,  1150,  1151,  9806,  9806,  9806, 13830, -1756,
   -1756, 13855, 13880, 13905,   991, 10406, -1756,   923,  4697, 13930,
   13955, 13004, 10290, 10290, 10290, 10290, 10290, 10290, 10290, 10290,
   10290,  9806, 10290, 10290, 10290, 10290,    18, 10378, 10290, 10290,
   10290,    31,    31, -1756, -1756,  8887, -1756,  5344, -1756,  5579,
    9806,   893,  9806, -1756,  9806,  9806,   929, 13980,  8164,   924,
     366,  9806,  1164,   931,   933,   934,   935,  9806, 14005, 13031,
     159,   937,  1170,  1175, -1756, -1756, -1756,  8887,   154, -1756,
   -1756, -1756,    31,  9806,  9806,  1130,   943, -1756,   374,    44,
      47,   379,   946,   -13,   599, -1756,  2429, -1756,    22,  8887,
      31,  9806,  9806,  1181,  1183,  8887,  9806,  1184, 10290,  1185,
   -1756,    31,  1186, 10290,  9806,   949,   954, -1756,  9806, 10378,
    1187,  8887,  1020,  8887,  1189,  1190, 14030,  1192,  1025,  1198,
    1199, 14055,  1200,  1033,  1202,  1204,  1206,  1207,  1208,  1209,
   -1756,  1211,  1212,  1213,  9806, 14080,   981, -1756, -1756, -1756,
    1218, 12977, 12977, 12977, 12977, 12977, 12977, 12977, 12977, 12977,
   12977, 12977, 10439, 12977, 12977, 12977, 12977,  1721,   427, 12977,
   12977, 12977, 10472, 10505, 10538,  4661,   988,   985,    89,  8887,
   10571, 10604,   427, 10637,   427,   992,   993,   994,   212, 14830,
     986,  3826,   995,   996,  1000, -1756, -1756, -1756, -1756,   997,
    -158,   427,  -146,  1004,   475,   418,  1222, -1756, -1756,   427,
    4722,  7563,  1338,   888,   732,   732,   449,   449,   449,   449,
     449,   449,   334,   334,  8887,   323, -1756,   323,   323,   893,
     893,   893,  1001, 14105, 13058,   262, -1756,  8887, -1756,  1224,
    1006, 14130, 14155, 14180,  9806,  5982,  1229,  1228,  1007, 14830,
    1002,  1011, 14830,  1005,  1012, 14830,  1008,  1014, 14830,  1009,
   14205, -1756, 14230, -1756, 14255, -1756,   456,   458,  8887,  1010,
   -1756,  5814, -1756,  6049,  6284,   -68,  9806,  9806, -1756, -1756,
    1016,  1017,  9195,  8823,  1134,   398,   -68,  6519, 14280,  7760,
   14305, 14330, 14355, 14380, 14405, 14430, 14455,  1249,  9806,  1254,
   -1756,  9806, 14480, -1756, 13085, 13112, -1756,   463,   468,   473,
   -1756, -1756, 13139, 13166, 10670, -1756,  1255,  1256,  1260,  1026,
    9806,  6754,  9806,  9806, -1756, -1756,    24,   -24,   149,   -24,
    1030,  1034,  1027,   427,   427,  1029, 10703,   427,   427,   427,
     427,  9806,   427,  1262, -1756,  1031,  1038,   291,   488,  1039,
     478, -1756, -1756, 12977,   323,  6989,  1037,  1271,  1137,  9431,
    1045,  1047,  1283,  5982, 12023, -1756,  9806,  9806,  9806,  9806,
    1905,   163,    84, 10378,  9806,  1287,  1290,    49, -1756,   487,
    1250,  1251,  5982,    26,  1052, 14505, 13193,  1057,  9806,  8887,
    8887,  8887,  8887,  9806,  1063,  1066,  1067,  1072, -1756, -1756,
    1079, 10290,   227,  1070, 14530, 13220, -1756, -1756, -1756,   249,
   10736, -1756, -1756, -1756,    61, -1756, -1756, 14830, -1756,  1307,
   12977,   427,   -68,   652,  4661, -1756,  5982,  5982,  1308,  5982,
     678,  5982,  5982,  1309,  5982,  1216,  5982,  5982,  5982,  5982,
    5982,  5982,  5982,  5982,  5982,  2041,  1311,  8887, -1756, -1756,
   -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756,
    9806, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756,
    9806,  9806,  9806, -1756, -1756, -1756,   495,  9806,  9806, -1756,
    9806, -1756,  5982, 10290, 10290, -1756,  1073,  9806, -1756,  9806,
    9806,  9806,  9806,  9806, -1756, -1756, -1756,  1181, -1756,  1181,
    9806,  1082, -1756,  5982, -1756,  9806,  9806,   501,  1181,   262,
    -102, -1756,   503,  5982,  8887,  1314,  1315,  1317,  2909, -1756,
   -1756,  1319, -1756,   203,  9806,   203,  9806,   203,  9806,   203,
    9806,  1320,  1321,  1322,  1323,  1324,   509,  1328, -1756,  7224,
   -1756, -1756,  -116, 10769, 10802, -1756, -1756, 12052,  -140,  1225,
    1330,  9506,  1085,  1329,  1101,    36,    43,   440, -1756,  -110,
   -1756,   398,  1333,  1335,  1336,  1337,  1341,  1343,  1346,  1348,
    1359,  5982, 14830, -1756,  2313,  1104,  1361,  1362,  1363,  1240,
    1364,  1369,  1370,  9806,  5982,  5982,  5982,  1366, 10835, -1756,
    7737,   809,  1373,  1375, -1756,  8887, -1756, -1756, -1756, -1756,
   10290, -1756, -1756,  9806, 10290, -1756, -1756, -1756, -1756, 14830,
   -1756,  1098,  1139, 10290, -1756, 10290, -1756,  1181, 10290,  1143,
   -1756,  1145, -1756,  1142,  1148,  9736, -1756,  2550,  1152,  5982,
   -1756,  1153, -1756, 12081, 12110, 12139, 12168, -1756, -1756,  9806,
    1386,   188,  9806,  1388,  1390,  2607, -1756,  1391,    28,  1393,
    1161,   427,     2,     2,  1398, -1756,  1168,  1169,  1166, -1756,
    1402, -1756, -1756, -1756, -1756, -1756,  1181,   183,   731, 13247,
     518,   520,   521,   523, 14555,  9806,  9806,  9806,  9806, -1756,
    1403,    32,  1181, -1756,  1174,  1405,  9806,  7862,   427,  4055,
    1173,  1172, -1756,  1413,  1414,    67,  1180,  1188,  1303,  1303,
    5982,  1420,  1191,  1214,  1421,  1422,  5982,  1277,  1217,  1424,
    1425,  1447,  1448,  1451,  1453,  1454,  1455,  1457, -1756,  1459,
     526, 12977, 12977, 12977, 12977,   427, 10868, 10901, 10934,  1230,
     427,   427,  1307,   427, 10967, 11000, 11033, 11066, 14580, 12977,
    1231,  1226, 14830, -1756,  1460, 14830, 14830, -1756, -1756, -1756,
    1466, -1756,   427,  1465,   529,  5982,  5982,  5982,  1472,  1471,
   -1756,  5982, 14830,  5982, 14830,  5982, 14830,  5982, 14830,  5982,
    5982,  5982,  1238,  1239,  1474,   881, -1756,  9806,  9806,  9806,
    1241,  1242,  1245,  1248, -1756,  2955,  5982, -1756,  9806, -1756,
    1482, -1756,  1483, -1756, -1756,  9195,   451,  5277, -1756,  1252,
    1253,  1257,  1258,  1259,  1261,  8097,  1486, -1756,  8887, -1756,
   -1756, -1756,  1266,  9806, -1756, -1756, 13274,  1489,  1490,  1326,
   -1756,  9806,  9806,  9806, -1756,  1495,   900,   292,  1263,  8366,
    1264,  9806,    33,   427,  1265,   427,  1268, -1756, -1756, 10378,
    9806, -1756, -1756,  2996, -1756, -1756,  1269,  1505, -1756, -1756,
   -1756, -1756,  3146, -1756,   199,  1273,  1529,  3379, -1756, -1756,
   -1756,    28, -1756,   555, -1756,  9806,   203,  1099, 10290, -1756,
    1275,  9806,  9806,  5982,  1296, -1756,  1297,  1535,  1536,  1537,
    1538,  1539,  1541,  1542,  1222, 14605, 14630, 14655, 14680, -1756,
   -1756, 10290, -1756,  1546, -1756, 11099,  4551, 14830, -1756,  1534,
    6452, -1756, -1756, -1756,  1307, -1756, -1756, -1756,  9806,  9806,
     -68,  1545,  1565,  1566, -1756,  9806,  9806, -1756, -1756,  1567,
    1458,  1569,  9806, -1756, -1756, -1756, -1756, -1756, -1756, -1756,
   -1756, -1756,  1571,  1339, -1756, -1756, -1756, -1756, -1756,  9806,
    9806,  9806, -1756, -1756, -1756,  1172, -1756,  9806,  9806,  9806,
    9806, -1756, -1756, -1756,  1340, -1756,   262, -1756, -1756,  1344,
    1573,  1277,  1575,  9806, -1756,  1576,  1578,  1580,  1581,  1582,
     808,  1585,  8887,  8887,  9806, -1756,  9117, 12197, 14705,  9151,
     306,   306,  9806,  9806, -1756,  1220,  1331, 14730, -1756, -1756,
   12226,  -106, -1756,  1586,  1588,  5982,   -68,   -68,   -68,   -68,
     -68,  5512,  1589, -1756,   560,  9806,  3409,  1590, -1756, -1756,
    5982,  9377,  1304, 14755, -1756, -1756,  8332, -1756, 10290,  9806,
   -1756, 10290, 14830,  8417, 10378,  1351, -1756, -1756, -1756, -1756,
    1365,  1356, 12255,  8164, -1756,  8164,  5982, -1756, -1756, 10378,
    9806,  1599,  1602,    49, -1756,  1601, -1756,    28, 13301,  5982,
    1604,   -24,   -24,  9806, 11132, 11165,   567, -1756,  9806,   390,
   -1756, -1756, -1756, -1756, -1756, -1756,  1317,  1320,  1321,  1322,
    1605, -1756,  9806, -1756, -1756,  1367,   569,  4269,  1606, -1756,
   12284, 12313,   683, -1756, -1756, -1756, 12342, 12371, -1756,  1374,
   -1756, 12400,  1609,  5982, 12977, 12977, 11198, 11231, 11264, 11297,
   11330, -1756, -1756,  9806, -1756,  1611, -1756, 14830, -1756, -1756,
   -1756, -1756, -1756,  1378, -1756, -1756,   592,   597, 12949,  3465,
    1615,  1381, -1756, -1756,  9806,  1382,  1383, 12429, 13328,  1617,
    5982,  1621,  1389,  9806, -1756, -1756,   598,  -103,   -98,   -62,
     -51,   -28,  8652,   -25, -1756,  1623, 12458, -1756, -1756,  1461,
   -1756,  9806,  9806, -1756, -1756,  8887,  3613,  1626,  1395, 12977,
     427, 10290, 14830, -1756, -1756,    33, -1756, 10378, -1756,  1392,
    1394,  1397,  1631,  3691, -1756,  1633,  1635, -1756, -1756,  1399,
    1637, -1756,  1638,  1639,   298, 14830,  9806,  9806,  1406,  5982,
     603, 14830, -1756, 11363,  1073,  1139,  5982, -1756,  9806, 10378,
      31,  1640,  1642,  1643,  1644,  9806,  1645,  1646,   604, -1756,
   -1756,  9806,  9806,  9806,  9806,  9806, 12487, -1756,  5982,   454,
     575,  8887, -1756, -1756,   306,  9462, -1756, -1756, -1756,  1648,
   -1756,  1416,  5982, -1756, 12516,  1649,  8887,   -68,   -68,   -68,
     -68,   -68, -1756, -1756,  9806, 12545, 12574,   605, -1756, -1756,
   -1756, -1756, -1756,   610, -1756,  1418,  1426, -1756,  1653, -1756,
   -1756,    28, -1756,  1488, -1756, -1756, -1756, -1756,  9806, 11396,
   11429,  5982, -1756,  1657,  9806,  9806,  1423,  1427, -1756,  4293,
   -1756,  1431, -1756, -1756, -1756, -1756, 12603, -1756, -1756,  1429,
   11462, 11495, 11528, 11561, 11594, -1756,   611,  1430,   -68,  5982,
    1666,  1432,   -68,  1668,   617,  1436, -1756,  9806, -1756,  1673,
    1553,  7459,  1443, -1756,   618,   131,   153,   157,   201,   205,
    3782, -1756, -1756,  1680, -1756,  1686, -1756, -1756,  1687, -1756,
    1456, 14830,  9806,  9806,   619, -1756, 14830, 11627, -1756, -1756,
    1073, 10378,  1462, -1756,  9806,  9806,  9806,  9806,  9806,  9806,
    1688,   -68,   111, -1756, -1756,   -68,   120, -1756,  1689, -1756,
   12632, -1756,  9806, -1756,   398, -1756,  1690,  8887,  8887,  8887,
    8887,  8652, -1756, -1756, -1756,  8164, -1756,  9806, 14780, 11660,
      48,  9806,  1463, -1756, -1756, 11693, 11726, 11759, 11792, 11825,
   11858, -1756,   217, -1756,   223, -1756, -1756, -1756,  4008,   469,
    7914, -1756,   624,   625,   630,   632,   274,   633,  1467,   635,
   -1756,  9806, -1756,  5982, 12661, -1756,  9806,  9806,  9806,  9806,
    9806,  9806,   -68,   -68, -1756, -1756, -1756,   398,  1693,  1695,
    1696,  1697,  8887,  1698,  1701,  1702,  1470, 14805,   638,  1706,
   12690, 12977, 11891, 11924, 11957, 11990,   302,   309,   600, -1756,
   -1756, -1756, -1756,   644, -1756, -1756, -1756, 10290, -1756,  1473,
   -1756,  1707, -1756,  9806,  9806,  9806,  9806,  9806,  9806, -1756,
    1709,   653, -1756,  1475,  5982, -1756, 12719, 12748, 12777, 12806,
   12835, 12864, -1756,  1712, 10290, 10290,   654, -1756, -1756, -1756,
   -1756,  1713,  1714, -1756, -1756,   656, -1756,  1715, -1756, -1756,
    1716, 10290, -1756, -1756, -1756
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1756, -1756, -1756, -1756,   423, -1756, -1756, -1756, -1756,  -271,
   -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756,
   -1756, -1756,  -679,  -109,  2722,  2995, -1756,  1302, -1756, -1756,
   -1756, -1756, -1756, -1756, -1755, -1756,   376,   206,   -84, -1756,
     -53, -1756, -1756, -1756, -1756,   152,   415,  1732,    -2,  -587,
    -191, -1756, -1756, -1756, -1756, -1756, -1756, -1756, -1756,  1733,
   -1756, -1756, -1756, -1756, -1174, -1171,  1734, -1641,  1736, -1756,
   -1756, -1756,  1177, -1756,   -99, -1756, -1756, -1756, -1756,  1899,
   -1756, -1756,   381,   287,  1742, -1756,     0,  -696, -1756, -1756,
     168, -1756, -1605,   300,  -168,  2544,  -118,  -277,    83, -1756,
     177,   -43, -1756, -1756,  -495, -1756,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -538
static const yytype_int16 yytable[] =
{
     132,   113,   808,   900,   901,   580,  1414,  1416,   499,  1007,
    1756,   994,  1789,   613,  1790,   459,   460,   461,   152,  1002,
     150,   151,   150,   404,   135,   702,   139,  1027,  1019,   150,
    1275,  1212,   332,   309,   527,   150,     4,  1643,  1510,   375,
     435,   161,  1409,   166,   261,   440,   377,   502,   161,  1411,
     445,   166,   386,   150,  2032,   370,   504,   374,   336,  1896,
     588,   589,   506,   729,   458,   281,   265,   690,  1307,   730,
     314,   313,   315,  1527,     5,   588,   589,   720,   828,   261,
     695,   895,   696,   265,   335,   588,   589,   266,  1113,   408,
     282,  1258,  1116,   588,   589,   371,   902,  1117,   549,   561,
     562,   563,  1401,   596,  1014,   549,   283,   284,  1828,   588,
     589,   136,   429,   310,   906,   588,   589,  2013,   732,   588,
     589,   617,   588,   589,   730,   549,  2015,   588,   589,   409,
    1397,   411,   398,   399,   419,   419,  1415,   609,   610,   611,
    1753,  1370,   419,  1856,   137,   556,   718,   947,  1857,   949,
     138,   623,   624,   430,   719,   261,   316,   286,   287,   724,
     261,  1000,   141,   588,   589,   261,   993,   725,   277,   288,
    1258,   278,   419,   289,   588,   589,   261,   142,   500,   261,
     261,   261,   261,   419,  1858,   667,   143,   669,  1276,  1277,
    1278,  1279,  1474,   144,   678,  1859,  1410,   588,   589,   267,
     588,   589,   268,  1412,   269,  2002,  1659,   286,   287,   133,
    1258,   157,   311,   134,   695,   158,   696,   503,  1860,   288,
    1644,  1861,   728,   294,   146,   107,   505,   107,   290,   292,
     261,   295,   507,  1916,   107,   691,   692,   107,   107,   153,
     107,   154,  1020,   261,   501,  1414,   261,   528,   614,   145,
     398,   399,  1020,   703,   134,   704,   147,  -532,   107,   705,
     261,   140,   961,   261,   261,   261,   261,  1213,  1280,   333,
     312,   261,   261,   261,   162,   376,   167,   261,   163,   335,
     168,   162,   378,   387,   167,  1010,  1954,   388,  1011,  2033,
    1268,   337,   588,   589,   394,   395,   396,   397,   153,   486,
     154,   487,   261,   261,   261,   721,   153,   722,   154,   407,
     410,   723,  1259,  1262,   417,   420,   261,   261,   398,   399,
     305,   742,   306,   398,   399,   743,   550,  1261,   551,  1095,
     398,   399,   552,   550,   384,   551,   588,   589,   385,   552,
     148,   815,   816,   817,   818,   588,   589,   259,   682,   149,
     398,   399,   452,   674,  2028,   675,   588,   589,   599,   552,
    1475,  1476,   600,   462,   394,   395,   396,  1001,   179,   394,
     395,   396,   397,   394,   395,   396,   397,  1987,   588,   589,
     419,   296,   588,   589,   261,   261,   180,   695,   891,   696,
     893,   894,   748,   398,   399,  1215,   743,   398,   399,  1988,
     261,   159,   825,  1989,   588,   589,   706,   907,   181,   394,
     395,   396,   397,   394,   395,   396,   397,   398,   399,   319,
     590,  1360,   320,  1361,  -534,   737,   588,   589,  2058,   261,
     588,   589,  1368,   398,   399,   182,   727,    59,    60,    61,
      62,   160,   588,   589,   728,   941,   164,  1990,   588,   589,
    1105,  1991,    73,   583,   584,    76,   886,   887,   728,   588,
     589,   592,   597,  2042,  1381,  1301,  1383,   297,  1385,  2043,
    1387,   298,   165,   743,   823,   591,   261,   299,   300,   456,
     301,   302,   975,   261,   798,   588,   589,  1305,   419,  2106,
     419,   261,   419,   419,   419,   743,   398,   399,   303,   588,
     589,   598,   927,   928,   929,   261,   261,   261,   261,   261,
     419,   419,   261,   152,   169,   152,   822,   261,   824,   170,
    2052,   870,   873,   876,   879,  1170,   171,   588,   589,   695,
     695,   696,   696,   259,   588,   589,  1887,  1235,   743,   753,
     261,  1456,  1171,   743,  1888,   766,   852,   970,  2087,   743,
    1172,  1173,  1174,   546,   547,  2088,  1175,  1176,   172,   548,
     676,   672,   544,   545,   546,   547,   560,  1170,   173,   827,
     548,   261,   261,   743,   569,   571,   573,   174,  1170,   999,
     578,   995,   175,   860,  1171,  1917,  1918,   743,   411,   411,
    1496,  1919,  1172,  1173,  1174,  1171,  1170,   274,  1175,  1176,
     275,  1022,   276,  1172,  1173,  1174,  1512,  1029,   982,  1175,
    1176,   157,   983,  1171,   964,  1009,   170,   261,   261,   261,
    1012,  1172,  1173,  1174,   398,   399,   270,  1175,  1176,   271,
     509,  -537,   272,   510,   273,   634,   511,   134,   512,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   176,   419,
     419,   419,   419,   963,   177,   419,   419,   419,   152,   969,
    1122,   968,   261,   683,   743,   695,   684,   696,   802,   685,
     804,   686,   806,   807,   541,   542,   672,   544,   545,   546,
     547,  1096,  1413,   183,   178,   548,   184,   679,   680,   185,
     819,   820,  1015,  1612,   261,  1016,  1041,  1017,  1154,  1004,
    1155,  1159,   743,   693,   743,  1198,  1921,  1922,   186,   743,
    1199,  2045,  1919,   262,   743,  1200,   261,  1023,  1119,   743,
    1241,  1120,   261,   263,   743,   419,  1127,  1170,  1034,  1271,
     419,  1237,   264,   743,  1238,   150,   343,  1345,   261,  1132,
     261,   743,   279,  1367,  1171,  1372,  1131,   743,  1316,   743,
    1317,  1394,  1172,  1173,  1174,   743,   898,   899,  1175,  1176,
    1500,   584,  1501,  1502,   743,  1503,   743,   743,  1553,   743,
    1156,  1579,   743,   280,  1322,   743,  1323,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   695,   285,   696,   697,
     353,   354,   355,   356,   805,  1660,   261,  1666,   357,   358,
     359,  1667,  1765,   360,   293,   361,   743,  1669,   560,  1808,
    2019,  1817,  1733,  1809,  1734,  1818,   362,  1443,   363,   304,
     948,   307,   950,   951,   952,   953,   954,   955,   308,   957,
     958,   959,   960,   317,  1839,   965,   966,   967,   743,  1840,
    1855,   261,  2089,   743,  1809,  1893,  1909,  1943,  1414,  1894,
    1809,   743,  1944,  1970,   261,   392,   728,  1809,   318,  1978,
    1986,  2000,   261,   743,   743,  1809,  2048,  2049,   699,   321,
     743,   743,  2050,  2068,  2051,  2053,   743,  2055,   743,   743,
    2079,  1894,  1260,  1263,  1809,   261,  2090,  1595,  1596,   322,
     743,  1290,  1291,  1292,  1293,  2103,  2117,  1414,  2120,  2104,
    1809,   695,  2121,   696,   857,  1032,  1635,  1636,   588,   589,
    1036,   323,   328,   329,   330,   340,   331,   341,   338,   339,
     389,   372,   364,   365,   366,   342,   383,   415,   426,   414,
     390,   428,   438,   367,   134,   443,   457,   368,   494,   369,
     107,   497,   508,   513,   516,   517,   518,   557,   558,  1340,
    1264,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,   385,   398,   399,   564,   548,   574,
     565,   566,  -533,   567,  1497,   577,   601,   637,   579,   581,
     261,   602,   582,   603,   604,   605,   606,   607,   612,   615,
     618,  1482,  1671,  1672,  1270,   616,   619,   625,   620,   261,
     621,   622,   626,   627,   629,   630,   261,   261,   261,   261,
     636,   645,   646,  1745,  1746,   647,  1374,   658,   419,   659,
    1369,  1371,   661,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,   663,   662,   261,   261,   548,   261,  1444,   261,   261,
     664,   261,   665,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   666,  1162,   261,   668,   694,   681,   687,   700,
    1168,   701,   133,   734,  1179,   707,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,   738,   739,   760,  1447,   548,   261,
     419,   419,   764,   150,   343,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
     261,   767,   768,   769,   548,   770,   810,   799,   812,   548,
     261,   261,   813,   814,   855,   864,   865,   881,   883,   885,
     889,   890,   892,   918,   920,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   921,   923,   930,   931,   353,   354,
     355,   356,   981,   939,   942,  1139,   357,   358,   359,   976,
     985,   360,   986,   361,   987,   988,   989,   997,  1369,  1371,
     996,   998,  1008,  1013,   362,  1026,   363,  1038,   261,  1028,
    1031,  1033,  1035,  1039,  1042,  1043,  1046,  1047,  1300,  1049,
    1050,   261,   261,   261,  1665,  1051,  1052,  1054,  1055,  1056,
    1315,  1057,   261,  1058,  1059,  1060,  1061,   419,  1062,  1063,
    1064,   419,  1067,   392,  1068,  1094,  1093,  1107,   529,  1123,
     419,  1133,   419,  1140,  1142,   419,  1109,  1110,  1102,  1103,
    1104,  1111,  1118,  1112,  1128,  1143,   261,  1134,  1144,  1145,
    1147,  1146,  1149,  1157,  1148,  1150,  1191,  1925,  1165,  1166,
    1193,  1169,  1204,  1205,  1518,   335,  1522,  1206,  1218,  1207,
    1653,  1231,  1219,  1220,  1655,  1223,  1234,  1233,  1244,  1240,
    1350,  1351,  1243,  1251,  1245,   419,  1873,  1248,  1249,  1250,
     364,   365,   366,  1266,  1267,  1286,  1272,  1273,  -535,  1299,
    1295,   367,  1274,  1296,  1297,   368,   261,   369,   107,  1298,
    1624,  1309,  1772,  1302,  1328,  1320,  1326,   261,  1339,  1352,
    1363,  1375,  1376,   261,  1377,  1380,  1406,  1389,  1390,  1391,
    1392,  1393,  1395,  1402,  1403,  1407,  1432,   695,  1408,   696,
    1417,  1418,  1451,  1419,  1420,  1428,  1318,  1319,  1421,  1321,
    1422,  1324,  1325,  1423,  1327,  1424,  1329,  1330,  1331,  1332,
    1333,  1334,  1335,  1336,  1337,  1661,  1425,  1429,  1430,  1431,
    1440,  1433,   261,   261,   261,  1434,  1435,  1445,   261,  1446,
     261,  1458,   261,  1460,   261,  1452,   261,   261,   261,  1461,
    1798,  1459,  1473,  1465,  1478,  1467,  1479,  1448,  1481,  1484,
    1485,  1450,  1349,   261,  1489,  1491,  1492,  1493,  1495,  1509,
    1454,  1514,  1455,  1523,   261,  1457,  1651,  1513,  1524,  1525,
    1526,  1528,   261,  1364,  1530,   261,  1534,  1537,  1538,  1529,
    1543,  1544,  1535,  1373,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,  1540,  1545,  1546,  1536,   548,  1547,  1542,  1548,
    1549,  1550,  1749,  1551,  1552,  1498,  1575,  1722,  1562,  1573,
    1576,  1578,  1120,  1694,  1736,  1737,  1583,  1584,   335,  1592,
    1593,  1594,  1600,  1601,   419,   419,  1602,  1603,  1608,  1609,
     261,  1426,  1623,  1615,  1616,  1628,  1629,  1630,  1617,  1618,
    1619,  1634,  1620,  1648,  1437,  1438,  1439,  1625,   419,  1638,
    1641,  1657,  1673,   261,  1238,  1656,  1662,   261,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,  1663,  1678,  -536,  1679,
     548,  1695,  1680,  1681,  1682,  1683,  1773,  1684,  1685,  1466,
    1691,  1703,  1709,  1740,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
    1722,  1704,  1705,  1708,   548,  1710,  1712,  1750,  1721,  1724,
    1713,  1726,  1728,  1611,  1729,  1723,  1730,  1731,  1732,   261,
     261,  1735,  1754,  1777,  1755,  1764,  1768,  1785,   411,   411,
    1783,  1784,  1787,  1786,  1948,  1794,  1795,  1797,  1816,  1521,
    1801,  1812,   261,  1820,  1827,  1825,  1792,  1837,   261,  1838,
    1533,  1843,  1844,  1850,  1846,  1847,  1539,   261,  1852,  1862,
    1853,  1864,  1869,  1870,  1876,   419,  1877,  1879,   419,  1878,
    1881,  1882,  1883,  1884,  1885,  1886,  1902,  1891,  1903,  1904,
    1905,  1907,  1908,   261,  1928,  1933,  1945,  1867,  1929,  1947,
    1270,  1949,  1931,  1955,   335,  1958,   261,  1946,  1962,  1959,
    1964,  1971,  1974,  1975,  1977,  1580,  1581,  1582,  1979,  1981,
    1982,  1585,   717,  1586,  1985,  1587,  1993,  1588,  1690,  1589,
    1590,  1591,  1994,  1996,  2011,  2016,  2021,  1997,  1702,  2069,
    2004,  2070,  2071,  2072,  2074,  2035,  1606,  2075,  2076,  2054,
     261,  2077,  2080,  2095,  2094,  2102,  2105,  1614,  2113,  2118,
    2119,  2122,  2123,  1924,  1511,  1622,  2029,   733,  1565,   529,
    1699,  1897,  1874,  1725,  1532,   112,   122,   123,  1934,   124,
     867,  1923,  1574,  1650,  1875,   130,  1796,   261,     0,     0,
       0,     0,     0,     0,     0,  1995,     0,     0,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,  1900,     0,   419,     0,
       0,     0,     0,     0,  1757,  1758,  1759,  1760,  1761,  1763,
       0,     0,     0,  1677,  2020,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,   261,     0,  1778,  1693,  1901,  1780,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,   261,     0,
       0,     0,   411,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,   261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2022,
    2023,  2024,  2025,  2027,     0,     0,     0,     0,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,  1257,   548,     0,     0,  1677,   261,     0,  2003,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1769,     0,     0,     0,  2073,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   741,   544,
     545,   546,   547,     0,     0,     0,  1791,   548,     0,   695,
       0,   696,     0,     0,     0,     0,     0,     0,     0,  1800,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   261,   261,   261,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   381,     0,     0,     0,     0,
       0,     0,     0,  1677,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1935,  1936,  1937,  1938,  1939,
     261,   406,     0,     0,     0,   416,     0,     0,     0,   421,
       0,     0,     0,     0,     0,     0,     0,  1338,     0,   261,
    1851,     0,     0,     0,     0,     0,   431,   433,   436,   437,
       0,   439,   433,   441,   442,     0,   444,   433,   446,   447,
     448,   449,   450,   451,   419,   453,   454,   455,     0,     0,
       0,   433,     0,     0,     0,     0,  1972,     0,     0,     0,
    1976,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   419,   419,     0,     0,     0,     0,     0,     0,  1892,
       0,     0,     0,     0,     0,     0,  1898,     0,   419,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,  1677,  2012,
       0,   548,     0,  2014,   519,   521,   523,   524,   433,     0,
       0,     0,  1930,     0,     0,     0,     0,     0,     0,  2026,
       0,   555,   433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,     0,
       0,  1677,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,     0,     0,     0,     0,     0,     0,
    2066,  2067,     0,     0,     0,     0,     0,     0,     0,  1973,
       0,     0,     0,     0,   628,     0,     0,     0,   631,   632,
     633,     0,   635,     0,     0,     0,   638,   639,   640,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2092,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   671,
       0,  2114,  2116,   677,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2124,   688,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   716,     0,     0,     0,     0,     0,  1427,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   521,     0,  1677,     0,     0,     0,   746,     0,     0,
       0,     0,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   765,     0,     0,     0,
       0,     0,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   789,
     790,   791,   792,   793,   794,   795,   795,     0,   800,   801,
       0,   803,     0,     0,  1677,     0,     0,   809,     0,     0,
     811,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   795,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,     0,     0,   830,   831,
     832,   833,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   845,   847,   848,   849,   850,   851,     0,   853,
     854,     0,     0,     0,     0,     0,   861,   862,   863,     0,
       0,     0,     0,   869,   872,   875,   878,   880,     0,   882,
       0,   884,     0,   433,   433,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   519,   671,   903,     0,     0,     0,   908,   909,
     910,   911,   912,   913,   914,   915,   916,     0,     0,     0,
       0,   922,     0,   924,     0,   925,     0,     0,     0,   433,
     433,   433,     0,     0,   932,   933,   934,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
     956,     0,     0,     0,     0,     0,  1464,     0,     0,     0,
       0,     0,     0,     0,   433,     0,     0,     0,     0,   973,
       0,   974,     0,   853,   854,     0,     0,     0,     0,     0,
     984,     0,     0,     0,     0,     0,   990,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,  1005,  1006,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1480,     0,     0,     0,     0,   433,     0,
    1024,  1025,     0,     0,   433,  1030,     0,     0,     0,     0,
       0,     0,     0,  1037,     0,     0,     0,  1040,     0,     0,
     845,     0,  1044,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,   187,   150,  1065,     0,   548,     0,     0,   188,   189,
     190,  1018,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     379,   209,   210,   211,   212,   213,   214,     0,   433,     0,
       0,     0,   434,     0,     0,     0,     0,   434,     0,     0,
       0,     0,   434,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,   433,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,  1138,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,   433,     0,     0,
     522,     0,     0,   434,     0,  1163,  1164,     0,     0,     0,
       0,  1167,     0,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1192,     0,     0,
    1194,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,  1208,
       0,  1210,  1211,   548,     0,     0,     0,     0,   236,     0,
       0,     0,   237,     0,   405,     0,     0,   239,   240,   241,
    1229,   242,   243,   244,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1247,     0,
       0,     0,     0,   245,   380,  1253,  1254,  1255,  1256,     0,
     247,     0,     0,  1265,     0,   325,     0,     0,     0,   575,
       0,     0,   250,     0,     0,     0,     0,  1289,   433,   433,
     433,   433,  1294,     0,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   488,   489,   490,
     491,   492,   493,     0,   495,   496,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,   514,
     515,  1604,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   522,     0,     0,  1341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1342,
    1343,  1344,     0,     0,     0,     0,  1346,  1347,     0,  1348,
       0,     0,  1654,     0,     0,     0,  1354,     0,  1355,  1356,
    1357,  1358,  1359,     0,     0,     0,     0,     0,     0,  1362,
       0,     0,     0,   788,  1365,  1366,     0,     0,     0,     0,
     796,   797,     0,   433,     0,     0,  1378,     0,     0,     0,
       0,     0,     0,  1382,     0,  1384,     0,  1386,     0,  1388,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   821,
       0,     0,     0,     0,   434,     0,   642,   643,   644,     0,
    1405,     0,   648,   649,   650,   651,   652,   653,   654,     0,
     655,     0,     0,     0,   656,   657,     0,   846,   660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670,  1436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   433,     0,     0,     0,   434,   434,
       0,     0,  1449,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,  1463,   548,     0,     0,     0,     0,
       0,     0,  1658,     0,     0,     0,     0,     0,  1472,     0,
       0,  1477,     0,     0,   434,   434,   434,     0,     0,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,  1505,  1506,  1507,  1508,     0,     0,
       0,     0,     0,     0,     0,  1515,  1517,     0,     0,   434,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,     0,     0,
     829,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   846,     0,  1045,     0,     0,
       0,     0,     0,     0,     0,     0,  1597,  1598,  1599,     0,
       0,     0,     0,     0,     0,  1605,     0,  1607,     0,     0,
       0,     0,     0,     0,  1610,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   433,     0,     0,
       0,     0,  1626,     0,     0,     0,     0,     0,     0,     0,
    1631,  1632,  1633,   434,     0,     0,     0,     0,     0,     0,
    1642,     0,     0,     0,     0,     0,     0,     0,     0,  1652,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1668,  1664,     0,     0,   434,     0,
    1674,  1675,     0,     0,     0,     0,     0,     0,     0,     0,
     698,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1767,     0,     0,     0,  1697,
       0,     0,     0,     0,     0,     0,     0,  1700,  1701,     0,
       0,     0,   434,     0,  1706,  1707,     0,     0,     0,     0,
       0,  1711,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1714,  1715,
    1716,     0,     0,     0,     0,     0,  1717,  1718,  1719,  1720,
       0,  1842,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1727,     0,     0,     0,     0,     0,     0,     0,
       0,   433,   433,  1738,     0,  1739,     0,     0,     0,     0,
       0,  1747,  1748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     433,     0,     0,     0,  1766,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1776,     0,     0,  1779,     0,
       0,     0,  1782,     0,     0,     0,     0,     0,     0,   858,
       0,     0,     0,   434,   434,   434,   434,     0,     0,  1793,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1805,     0,     0,     0,     0,  1811,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1813,     0,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,   434,     0,     0,     0,   548,     0,     0,     0,  1868,
       0,     0,  1836,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,  1845,     0,   548,     0,     0,     0,     0,
       0,     0,  1854,     0,     0,     0,     0,     0,     0,     0,
       0,   521,     0,     0,     0,     0,     0,     0,     0,     0,
    1865,  1866,     0,     0,   433,     0,     0,     0,   434,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,  1880,     0,     0,
       0,   548,     0,     0,     0,  1889,  1890,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1899,     0,     0,
       0,     0,     0,     0,  1906,     0,     0,     0,     0,     0,
    1910,  1911,  1912,  1913,  1914,     0,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,  1308,     0,     0,   434,
       0,     0,     0,  1940,     0,     0,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,     0,  1081,  1082,
    1083,  1084,     0,  1086,  1087,  1088,  1089,  1951,  1992,     0,
       0,     0,     0,  1956,  1957,     0,     0,  1099,     0,  1101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,  1115,     0,     0,     0,
       0,     0,     0,     0,  1124,     0,  1980,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,  1998,  1999,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2005,  2006,  2007,  2008,  2009,  2010,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2018,     0,     0,     0,     0,   433,   433,   433,   433,
     433,     0,     0,     0,     0,     0,  1811,     0,     0,     0,
    2034,     0,     0,     0,     0,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
    2057,     0,     0,     0,     0,  2060,  2061,  2062,  2063,  2064,
    2065,     0,  1214,  1216,  1217,     0,     0,     0,  1221,  1222,
       0,   433,  1225,  1226,  1227,  1228,     0,  1230,     0,     0,
       0,     0,  1236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2096,  2097,  2098,  2099,  2100,  2101,     0,     0,
       0,     0,     0,     0,  1487,  1488,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,  2044,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1313,  1314,     0,     0,     0,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,   187,     6,
     343,     0,   548,     0,  1698,   188,   189,   190,  1108,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     220,   221,   222,   223,   353,   354,   355,   356,   224,     0,
       0,     0,   357,   358,   359,     0,     0,   360,     0,   361,
     225,   226,   227,     0,     0,     0,   434,   434,   228,    21,
     362,     0,   363,     0,     0,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,   236,   364,   365,   366,   237,
     238,     0,     0,     0,   239,   240,   241,   367,   242,   243,
     244,   368,     0,   369,   107,     0,  1486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1819,   529,     0,     0,
     245,   246,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,   325,     0,     0,     0,  1520,     0,     0,   250,
    1961,     0,     0,  1519,     0,     0,   522,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1554,  1555,  1556,  1557,
    1558,     0,     0,     0,     0,  1563,  1564,     0,  1566,     0,
       0,     0,     0,     0,  1572,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   434,   708,    25,    26,   709,
      28,    29,   710,    31,   711,    33,    34,    35,    36,     0,
     434,     0,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,   712,    48,     0,     0,    50,   713,     0,
      53,   714,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,  1637,     0,  1640,     0,     0,     0,  1647,     0,
    1649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1670,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   741,   544,   545,   546,
     547,     0,     0,     0,     0,   548,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,   434,   434,   434,   434,   434,     0,     0,   904,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     6,   343,     0,     0,     0,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,   434,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   220,   221,   222,   223,
     353,   354,   355,   356,   224,     0,     0,     0,   357,   358,
     359,     0,     0,   360,     0,   361,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   362,     0,   363,     0,
       0,   229,     0,     0,   230,     0,     0,   231,     0,   232,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1802,  1803,   233,   529,
      49,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,     0,     0,     0,     0,   943,     0,     0,     0,  1829,
    1830,     0,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
    1125,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,   236,   364,   365,   366,   237,   238,     0,     0,     0,
     239,   240,   241,   367,   242,   243,   244,   368,     0,   369,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1871,  1872,   245,   246,     0,     0,
       0,     0,     0,   247,     0,     0,     0,     0,   325,   187,
     150,   343,   249,   391,     0,   250,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   379,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   220,   221,   222,   223,   353,   354,   355,   356,   224,
       0,     0,     0,   357,   358,   359,     0,     0,   360,     0,
     361,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   362,     0,   363,     0,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   741,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     392,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,   236,   364,   365,   366,
     237,     0,     0,     0,     0,   239,   240,   241,   367,   242,
     243,   244,   368,     0,   369,   107,   394,   395,   396,   397,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   380,     0,     0,     0,     0,     0,   247,     0,
     398,   399,     0,   400,     0,   401,     0,     0,     0,   402,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     6,   324,     0,     0,
       0,     0,   188,   189,   190,     0,  2082,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   325,
     187,     6,  1613,   249,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   926,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,   236,    53,   714,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,     0,     0,   247,
       0,    84,    85,    86,   325,   187,     6,     0,   249,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   971,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   593,  1762,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   595,
     187,     6,     0,   289,   525,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   972,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,   236,    53,   714,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,     0,     0,   247,
       0,    84,    85,    86,   248,   187,     6,     0,   249,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1158,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   325,
     187,     6,     0,   249,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1160,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,   236,    53,   714,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   432,     0,     0,     0,     0,     0,   247,
       0,    84,    85,    86,   325,   187,     6,     0,   520,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1161,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   432,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   325,
     187,     6,     0,     0,   525,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1180,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,   236,    53,   714,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,     0,     0,   247,
       0,    84,    85,    86,   559,   187,     6,     0,   249,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1209,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   568,
     187,     6,     0,   249,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1242,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,   236,    53,   714,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,     0,     0,   247,
       0,    84,    85,    86,   570,   187,     6,     0,   249,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1396,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,  1126,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   572,
     187,     6,     0,   249,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1983,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,  1442,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   432,     0,     0,     0,     0,     0,   247,
       0,     0,     0,     0,   325,   187,   150,   343,   844,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   379,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   220,   221,   222,
     223,   353,   354,   355,   356,   224,     0,     7,     8,   357,
     358,   359,     0,     0,   360,     0,   361,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   362,     0,   363,
       0,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  1183,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,     0,    53,   714,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   364,   365,   366,   237,    70,     0,     0,
       0,   239,   240,   241,   367,   242,   243,   244,   368,     0,
     369,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,   245,   380,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,   325,
     187,     6,     0,  1516,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,  2046,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     7,     8,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   708,    25,    26,   709,    28,    29,
     710,    31,   711,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   712,    48,     0,     0,    50,   713,   236,    53,   714,
       0,   237,   238,     0,   978,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,    70,     0,     0,
       0,   979,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,     0,     0,   247,
       0,    84,    85,    86,   325,   187,   150,   343,  1621,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   379,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   220,   221,   222,
     223,   353,   354,   355,   356,   224,     0,     0,     0,   357,
     358,   359,     0,     0,   360,     0,   361,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   362,     0,   363,
     187,   150,   343,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   379,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   220,   221,   222,   223,   353,   354,   355,   356,
     224,     0,     0,     0,   357,   358,   359,     0,     0,   360,
       0,   361,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   362,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   364,   365,   366,   237,     0,     0,     0,
       0,   239,   240,   241,   367,   242,   243,   244,   368,     0,
     369,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   380,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,   325,
       0,     0,     0,  1775,     0,     0,   250,     0,     0,     0,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   695,     0,   696,   236,   364,   365,
     366,   237,  1639,     0,     0,     0,   239,   240,   241,   367,
     242,   243,   244,   368,     0,   369,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   380,     0,     0,     0,     0,     0,   247,
       0,     0,     0,     0,   325,   187,     6,     0,  1781,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,   708,
      25,    26,   709,    28,    29,   710,    31,   711,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   712,    48,     0,     0,
      50,   713,   236,    53,   714,     0,   237,   238,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   593,  1762,     0,
       0,     0,     0,     0,   247,     0,    84,    85,    86,   595,
     187,     6,     0,   289,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,   935,     0,     0,     0,     0,     0,     0,     0,   896,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   432,     0,     0,     0,     0,     0,   247,
     187,   150,   343,     0,   325,     0,     0,   188,   189,   190,
       0,   250,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   379,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   220,   221,   222,   223,   353,   354,   355,   356,
     224,     0,     0,     0,   357,   358,   359,     0,     0,   360,
       0,   361,   225,   226,   227,     0,     0,     0,   187,   150,
     228,    21,   362,     0,   363,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   379,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,   236,   364,   365,
     366,   237,   726,     0,     0,     0,   239,   240,   241,   367,
     242,   243,   244,   368,     0,   369,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   380,     0,     0,     0,     0,     0,   247,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,   250,     0,     0,     0,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,   236,     0,   548,     0,   237,
       0,     0,     0,  1743,   239,   240,   241,  1744,   242,   243,
     244,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,   594,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,   595,     0,   187,   150,   289,  1246,     0,   250,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   379,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,   187,
     150,     0,  1404,     0,   228,    21,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   379,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  1770,
       0,   236,     0,  1771,     0,   237,     0,     0,     0,     0,
     239,   240,   241,     0,   242,   243,   244,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   380,     0,     0,
       0,     0,     0,   247,     0,     0,     0,     0,   325,     0,
       0,     0,     0,     0,     0,   250,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,   236,     0,   548,     0,
     237,     0,     0,     0,  1926,   239,   240,   241,  1927,   242,
     243,   244,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   380,     0,     0,     0,     0,     0,   247,   187,
     150,     0,  1462,   325,     0,     0,   188,   189,   190,     0,
     250,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   379,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
     150,   225,   226,   227,     0,     0,   188,   189,   190,   228,
      21,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   379,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   896,     0,     0,   236,     0,     0,     0,
     237,     0,     0,     0,     0,   239,   240,   241,     0,   242,
     243,   244,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   380,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,   325,     0,    -4,     1,     0,     0,    -4,
     250,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,     0,     0,     0,     0,   239,   240,   241,     0,   242,
     243,   244,     0,     0,     0,   107,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   380,     0,     0,     0,     0,     0,   247,    -4,
      -4,    -4,     0,   325,     0,    -4,    -4,     0,    -4,     0,
     250,     0,     0,    -4,    -4,     0,    -4,    -4,     0,    -4,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,    10,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,     0,     0,     0,    11,    12,
      13,     0,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    17,    18,     0,    19,    20,     0,    21,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,    37,
      38,    39,    40,    41,     0,    42,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
      80,    81,     0,     0,     0,    82,     0,     0,     0,     0,
      83,    84,    85,    86,   150,   343,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   150,   343,     0,     0,     0,     0,     0,
       0,   106,     0,   107,     0,     0,   344,   345,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,   353,
     354,   355,   356,   373,   343,     0,     0,   357,   358,   359,
       0,     0,   360,     0,   361,   344,   345,   346,   347,   348,
     349,   350,   351,   352,     0,   362,     0,   363,   353,   354,
     355,   356,     0,   343,     0,     0,   357,   358,   359,     0,
       0,   360,     0,   361,     0,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   362,     0,   363,     0,   353,   354,
     355,   356,     0,     0,   392,     0,   357,   358,   359,     0,
       0,   360,     0,   361,   344,   345,   346,   347,   348,   349,
     350,   351,   352,     0,   362,     0,   363,   353,   354,   355,
     356,     0,     0,     0,     0,   357,   358,   359,     0,     0,
     360,     0,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,     0,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,   366,     0,     0,     0,     0,     0,     0,
       0,     0,   367,     0,     0,     0,   368,     0,   369,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,     0,     0,     0,     0,     0,     0,     0,
       0,   367,     0,     0,     0,   368,     0,   369,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,     0,     0,     0,     0,     0,     0,     0,
       0,   367,     0,     0,     0,   368,     0,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     365,   366,     0,     0,     0,     0,     0,     0,     0,     0,
     367,     0,     0,     0,   368,     0,   369,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   897,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   940,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1080,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1090,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1091,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1092,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1097,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1100,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1203,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1224,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1306,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1398,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1399,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1441,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1559,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1560,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1561,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1567,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1568,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1569,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1570,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1692,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1806,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1807,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1831,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1832,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1833,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1834,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1835,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1895,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1952,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1953,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1965,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1966,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1967,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1968,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1969,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2001,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2031,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2036,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2037,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2038,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2039,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2040,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2041,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2083,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2084,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2085,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2086,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1252,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,  1400,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  1468,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  1469,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,  1470,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    1471,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  1741,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,  1752,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,  1788,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,  1821,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1822,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,  1823,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  1824,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  1826,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,  1848,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    1863,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  1915,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,  1932,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,  1941,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,  1942,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1963,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,  2017,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  2059,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  2081,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,  2107,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    2108,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  2109,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,  2110,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,  2111,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,  2112,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,   673,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,   888,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
    1841,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,   695,     0,   696,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,   946,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,   992,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,  1130,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,  1196,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,  1197,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,  1201,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,  1202,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,  1288,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
    1304,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,  1499,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,  1627,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,  1799,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,  1849,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   740,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   744,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   745,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   747,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   749,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   750,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   752,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   754,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   755,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   756,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   757,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   758,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   759,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   761,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   762,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   763,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   826,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   859,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   917,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   935,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   936,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   937,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   938,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   944,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   945,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   977,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,   991,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1048,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1053,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1066,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1129,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1135,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1136,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1137,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1151,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1152,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1153,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1182,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1184,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1185,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1186,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1187,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1188,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1189,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1190,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1195,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1287,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1303,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1504,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1571,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1686,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1687,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1688,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1689,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1742,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  1751,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  1774,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,  2030,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,  2078,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548
};

static const yytype_int16 yycheck[] =
{
       3,     3,   497,   590,   591,   282,  1177,  1181,     5,   705,
    1615,   690,  1653,     4,  1655,   183,   184,   185,    21,   698,
       4,    21,     4,   132,    14,     9,     6,   723,     6,     4,
       4,     7,     4,     4,     9,     4,     6,     4,     6,     5,
     158,     4,     6,     4,    47,   163,     5,     5,     4,     6,
     168,     4,     6,     4,     6,    98,     5,   100,     4,  1814,
     225,   226,     5,   240,   182,   147,    96,     4,     7,   246,
       4,    74,     6,     6,     0,   225,   226,     9,     9,    82,
     238,   246,   240,    96,    87,   225,   226,   117,   246,   132,
     172,     7,   238,   225,   226,    98,   246,   243,     9,   267,
     268,   269,   242,   294,   117,     9,   188,   189,  1713,   225,
     226,    96,   155,    84,   246,   225,   226,     6,   240,   225,
     226,   312,   225,   226,   246,     9,     6,   225,   226,   132,
     246,   133,   234,   235,   137,   138,   246,   305,   306,   307,
     246,   243,   145,   246,   237,   263,   238,   642,   246,   644,
     237,   319,   320,   156,   246,   158,    90,   225,   226,   238,
     163,     7,     6,   225,   226,   168,     7,   246,    93,   237,
       7,    96,   175,   241,   225,   226,   179,     6,   175,   182,
     183,   184,   185,   186,   246,   376,     6,   378,   162,   163,
     164,   165,     4,     6,   385,   246,   160,   225,   226,    93,
     225,   226,    96,   160,    98,  1960,     7,   225,   226,   241,
       7,   237,   183,   245,   238,   241,   240,   175,   246,   237,
     187,   246,   246,   241,     6,   209,   175,   209,    60,    61,
     233,    63,   175,  1838,   209,   172,   173,   209,   209,   237,
     209,   239,   220,   246,   241,  1416,   249,   250,   239,   237,
     234,   235,   220,   237,   245,   239,     6,   241,   209,   243,
     263,   241,   244,   266,   267,   268,   269,   243,   242,   241,
     241,   274,   275,   276,   237,   241,   237,   280,   241,   282,
     241,   237,   241,   237,   237,   241,  1891,   241,   241,   241,
     241,   237,   225,   226,   210,   211,   212,   213,   237,   237,
     239,   239,   305,   306,   307,   237,   237,   239,   239,   132,
       4,   243,   991,   992,   137,   138,   319,   320,   234,   235,
      96,   242,    98,   234,   235,   246,   237,   243,   239,   240,
     234,   235,   243,   237,   237,   239,   225,   226,   241,   243,
     239,   509,   510,   511,   512,   225,   226,    47,   391,   239,
     234,   235,   175,   237,  1995,   239,   225,   226,   237,   243,
     172,   173,   241,   186,   210,   211,   212,   213,   110,   210,
     211,   212,   213,   210,   211,   212,   213,   246,   225,   226,
     383,     4,   225,   226,   387,   388,    96,   238,   579,   240,
     581,   582,   242,   234,   235,   246,   246,   234,   235,   246,
     403,   237,   520,   246,   225,   226,   409,   598,     6,   210,
     211,   212,   213,   210,   211,   212,   213,   234,   235,    93,
     241,  1117,    96,  1119,   241,   428,   225,   226,  2033,   432,
     225,   226,  1128,   234,   235,   241,   238,   131,   132,   133,
     134,   237,   225,   226,   246,   636,   237,   246,   225,   226,
     238,   246,   146,   285,   286,   149,   574,   575,   246,   225,
     226,   293,   294,   246,  1143,   238,  1145,    90,  1147,   246,
    1149,    94,   237,   246,   517,   241,   479,   100,   101,   179,
     103,   104,   673,   486,   487,   225,   226,   238,   491,  2094,
     493,   494,   495,   496,   497,   246,   234,   235,   121,   225,
     226,   241,   620,   621,   622,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   237,   518,   516,   520,   518,   237,
     246,   564,   565,   566,   567,   127,   237,   225,   226,   238,
     238,   240,   240,   233,   225,   226,   238,   246,   246,   242,
     543,  1237,   144,   246,   246,   242,   549,   665,   246,   246,
     152,   153,   154,   230,   231,   246,   158,   159,   237,   236,
     383,   227,   228,   229,   230,   231,   266,   127,   237,   242,
     236,   574,   575,   246,   274,   275,   276,   237,   127,   697,
     280,   690,   237,   242,   144,   131,   132,   246,   590,   591,
    1286,   137,   152,   153,   154,   144,   127,    93,   158,   159,
      96,   719,    98,   152,   153,   154,  1302,   725,   242,   158,
     159,   237,   246,   144,   657,   241,   237,   620,   621,   622,
     241,   152,   153,   154,   234,   235,    90,   158,   159,    93,
      90,   241,    96,    93,    98,   243,    96,   245,    98,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   237,   652,
     653,   654,   655,   656,   237,   658,   659,   660,   661,   662,
     242,   661,   665,    90,   246,   238,    93,   240,   491,    96,
     493,    98,   495,   496,   225,   226,   227,   228,   229,   230,
     231,   799,   242,    90,   237,   236,    93,   387,   388,    96,
     513,   514,    93,   242,   697,    96,   739,    98,   242,   702,
     242,   892,   246,   403,   246,   242,   131,   132,   237,   246,
     242,   242,   137,   237,   246,   242,   719,   720,   243,   246,
     242,   246,   725,   241,   246,   728,   844,   127,   731,   242,
     733,   243,    96,   246,   246,     4,     5,   242,   741,   857,
     743,   246,   237,   242,   144,   242,   855,   246,    96,   246,
      98,   242,   152,   153,   154,   246,   588,   589,   158,   159,
     242,   593,   242,   242,   246,   242,   246,   246,   242,   246,
     888,   242,   246,    93,    96,   246,    98,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   238,   241,   240,   241,
      59,    60,    61,    62,   494,  1474,   799,   242,    67,    68,
      69,   246,   242,    72,   241,    74,   246,  1486,   508,   242,
    1984,   242,     4,   246,     6,   246,    85,     8,    87,   237,
     643,    96,   645,   646,   647,   648,   649,   650,    93,   652,
     653,   654,   655,    93,   242,   658,   659,   660,   246,   242,
     242,   844,   242,   246,   246,   242,   242,   242,  2019,   246,
     246,   246,   242,   242,   857,   124,   246,   246,    96,   242,
     242,   242,   865,   246,   246,   246,   242,   242,     6,     4,
     246,   246,   242,  2047,   242,   242,   246,   242,   246,   246,
     242,   246,   991,   992,   246,   888,   242,     6,     7,     4,
     246,  1009,  1010,  1011,  1012,   242,   242,  2068,   242,   246,
     246,   238,   246,   240,   241,   728,     6,     7,   225,   226,
     733,     4,     4,   237,   237,     6,   237,     6,   237,   237,
       6,   237,   191,   192,   193,   239,   239,     6,   237,   241,
     245,     9,   237,   202,   245,   237,   237,   206,   237,   208,
     209,   237,   117,   237,   237,   237,   237,   237,   237,  1067,
     993,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   241,   234,   235,   237,   236,   241,
     237,   237,   241,   237,   243,     4,   237,   175,   241,   241,
     983,   237,   241,   237,   237,   237,   237,   237,   237,     6,
       6,  1268,  1487,  1488,   997,   239,     6,   239,   241,  1002,
     241,   241,   239,   239,     6,     6,  1009,  1010,  1011,  1012,
     241,   237,   237,  1600,  1601,   237,  1134,   237,  1021,   237,
    1129,  1130,   237,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,     6,   239,  1046,  1047,   236,  1049,   238,  1051,  1052,
       6,  1054,   241,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,     6,   895,  1067,     6,     6,   241,     7,   241,
     902,     6,   241,    86,   906,   242,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   246,   246,   238,  1215,   236,  1102,
    1103,  1104,     7,     4,     5,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
    1123,     6,     6,     6,   236,   238,    64,   241,    64,   236,
    1133,  1134,    64,    64,     4,     7,     7,     6,     6,     6,
     238,     6,   241,     7,     6,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     7,     6,     6,     6,    59,    60,
      61,    62,   238,   172,   241,   865,    67,    68,    69,   240,
       6,    72,   241,    74,   241,   241,   241,     7,  1287,  1288,
     243,     6,   239,   237,    85,     4,    87,   238,  1191,     6,
       6,     6,     6,   239,     7,   175,     7,     7,  1021,     7,
     175,  1204,  1205,  1206,  1481,     7,     7,     7,   175,     7,
    1042,     7,  1215,     7,     7,     7,     7,  1220,     7,     7,
       7,  1224,   241,   124,     6,   240,   238,   241,     8,     7,
    1233,     7,  1235,     4,     6,  1238,   241,   241,   246,   246,
     246,   241,   238,   246,   243,   238,  1249,   241,   246,   238,
     238,   246,   238,   243,   246,   246,     7,  1844,   242,   242,
       6,   127,     7,     7,  1307,  1268,  1309,     7,   238,   243,
    1461,     9,   238,   246,  1465,   246,   238,   246,     7,   240,
    1103,  1104,   245,   983,   147,  1288,  1781,   242,   241,     6,
     191,   192,   193,     6,     4,   243,    46,    46,   241,   220,
     237,   202,  1002,   237,   237,   206,  1309,   208,   209,   237,
    1428,     4,     8,   243,    98,     7,     7,  1320,     7,   246,
     238,     7,     7,  1326,     7,     6,   241,     7,     7,     7,
       7,     7,     4,   108,     4,     6,    96,   238,   237,   240,
       7,     6,   244,     7,     7,   241,  1046,  1047,     7,  1049,
       7,  1051,  1052,     7,  1054,     7,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1474,     7,     6,     6,     6,
       4,     7,  1375,  1376,  1377,     6,     6,     4,  1381,     4,
    1383,   238,  1385,   241,  1387,   246,  1389,  1390,  1391,   241,
    1667,   246,     6,   241,     6,   242,     6,  1220,     7,     6,
     239,  1224,  1102,  1406,     6,   237,   237,   241,     6,     6,
    1233,     6,  1235,   240,  1417,  1238,  1459,   243,   246,     6,
       6,   241,  1425,  1123,   121,  1428,     6,     6,     6,   241,
       6,     6,   241,  1133,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   175,     6,     6,   241,   236,     6,   241,     6,
       6,     6,   242,     6,     5,  1288,     6,  1576,   238,   238,
       4,     6,   246,  1516,  1592,  1593,     4,     6,  1481,   241,
     241,     7,   241,   241,  1487,  1488,   241,   239,     6,     6,
    1493,  1191,     6,   241,   241,     6,     6,   171,   241,   241,
     241,     6,   241,   238,  1204,  1205,  1206,   241,  1511,   246,
     246,     6,   237,  1516,   246,   246,   243,  1520,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     7,   241,   241,     4,
     236,     7,     6,     6,     6,     6,   242,     6,     6,  1249,
       4,     6,    94,  1596,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
    1679,     6,     6,     6,   236,     6,     5,   246,   238,     6,
     241,     6,     6,  1415,     6,   241,     6,     6,     6,  1592,
    1593,     6,     6,  1636,     6,     6,     6,   246,  1600,  1601,
    1643,  1644,   246,   238,  1881,     6,     4,     6,   241,  1309,
       6,     6,  1615,     7,     5,   241,  1659,     6,  1621,   241,
    1320,     6,   241,     6,   242,   242,  1326,  1630,     7,     6,
     241,   170,     6,   238,   242,  1638,   242,     6,  1641,   242,
       7,     6,   243,     6,     6,     6,     6,   241,     6,     6,
       6,     6,     6,  1656,     6,     6,   238,  1775,   242,     6,
    1663,   173,  1853,     6,  1667,   242,  1669,   241,   237,   242,
     241,   241,     6,   241,     6,  1375,  1376,  1377,   242,     6,
     127,  1381,     6,  1383,   241,  1385,     6,  1387,  1511,  1389,
    1390,  1391,     6,     6,     6,     6,     6,   241,  1530,     6,
     238,     6,     6,     6,     6,   242,  1406,     6,     6,   242,
    1713,   241,     6,     6,   241,     6,   241,  1417,     6,     6,
       6,     6,     6,  1841,  1301,  1425,  1997,   425,  1352,     8,
    1524,  1815,  1785,  1581,  1319,     3,     3,     3,  1856,     3,
     563,  1840,  1361,  1456,  1787,     3,  1663,  1750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1946,    -1,    -1,    -1,  1762,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1775,    -1,    -1,    -1,  1819,    -1,  1781,    -1,
      -1,    -1,    -1,    -1,  1616,  1617,  1618,  1619,  1620,  1621,
      -1,    -1,    -1,  1493,  1985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
      -1,    -1,    -1,  1816,    -1,  1638,  1516,  1820,  1641,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1838,    -1,    -1,  1841,    -1,
      -1,    -1,  1844,    -1,    -1,    -1,    -1,    -1,    -1,  1852,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1987,
    1988,  1989,  1990,  1991,    -1,    -1,    -1,    -1,  1881,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1891,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,     6,   236,    -1,    -1,  1615,  1919,    -1,  1961,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1630,    -1,    -1,    -1,  2052,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,  1656,   236,    -1,   238,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1987,  1988,  1989,  1990,  1991,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1857,  1858,  1859,  1860,  1861,
    2033,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,  2052,
    1750,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
      -1,   162,   163,   164,   165,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,  2077,   176,   177,   178,    -1,    -1,
      -1,   182,    -1,    -1,    -1,    -1,  1918,    -1,    -1,    -1,
    1922,  2094,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2104,  2105,    -1,    -1,    -1,    -1,    -1,    -1,  1809,
      -1,    -1,    -1,    -1,    -1,    -1,  1816,    -1,  2121,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,  1838,  1971,
      -1,   236,    -1,  1975,   245,   246,   247,   248,   249,    -1,
      -1,    -1,  1852,    -1,    -1,    -1,    -1,    -1,    -1,  1991,
      -1,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,    -1,
      -1,  1891,    -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,
    2042,  2043,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1919,
      -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,   329,   330,
     331,    -1,   333,    -1,    -1,    -1,   337,   338,   339,    -1,
      -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2077,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   380,
      -1,  2104,  2105,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2121,   400,
     401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   432,    -1,  2033,    -1,    -1,    -1,   438,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,
      -1,    -1,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,    -1,   489,   490,
      -1,   492,    -1,    -1,  2094,    -1,    -1,   498,    -1,    -1,
     501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,   520,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,    -1,   550,
     551,    -1,    -1,    -1,    -1,    -1,   557,   558,   559,    -1,
      -1,    -1,    -1,   564,   565,   566,   567,   568,    -1,   570,
      -1,   572,    -1,   574,   575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   593,   594,   595,    -1,    -1,    -1,   599,   600,
     601,   602,   603,   604,   605,   606,   607,    -1,    -1,    -1,
      -1,   612,    -1,   614,    -1,   616,    -1,    -1,    -1,   620,
     621,   622,    -1,    -1,   625,   626,   627,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
     651,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,    -1,   670,
      -1,   672,    -1,   674,   675,    -1,    -1,    -1,    -1,    -1,
     681,    -1,    -1,    -1,    -1,    -1,   687,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,
      -1,    -1,   703,   704,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,   719,    -1,
     721,   722,    -1,    -1,   725,   726,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   734,    -1,    -1,    -1,   738,    -1,    -1,
     741,    -1,   743,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,     3,     4,   764,    -1,   236,    -1,    -1,    10,    11,
      12,   242,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,   799,    -1,
      -1,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,   168,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,   844,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   857,    -1,    -1,    -1,
      -1,    -1,    -1,   864,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,   888,    -1,    -1,
     246,    -1,    -1,   249,    -1,   896,   897,    -1,    -1,    -1,
      -1,   902,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,
     921,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   940,
      -1,   942,   943,   236,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,   194,    -1,   132,    -1,    -1,   199,   200,   201,
     961,   203,   204,   205,    -1,    -1,    -1,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,    -1,
      -1,    -1,    -1,   225,   226,   986,   987,   988,   989,    -1,
     232,    -1,    -1,   994,    -1,   237,    -1,    -1,    -1,   241,
      -1,    -1,   244,    -1,    -1,    -1,    -1,  1008,  1009,  1010,
    1011,  1012,  1013,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,     6,    -1,    -1,    -1,    -1,  1067,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,  1080,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1090,
    1091,  1092,    -1,    -1,    -1,    -1,  1097,  1098,    -1,  1100,
      -1,    -1,     6,    -1,    -1,    -1,  1107,    -1,  1109,  1110,
    1111,  1112,  1113,    -1,    -1,    -1,    -1,    -1,    -1,  1120,
      -1,    -1,    -1,   479,  1125,  1126,    -1,    -1,    -1,    -1,
     486,   487,    -1,  1134,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,  1144,    -1,  1146,    -1,  1148,    -1,  1150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,
      -1,    -1,    -1,    -1,   520,    -1,   344,   345,   346,    -1,
    1171,    -1,   350,   351,   352,   353,   354,   355,   356,    -1,
     358,    -1,    -1,    -1,   362,   363,    -1,   543,   366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   379,  1203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1215,    -1,    -1,    -1,   574,   575,
      -1,    -1,  1223,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,  1245,   236,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,  1259,    -1,
      -1,  1262,    -1,    -1,   620,   621,   622,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,  1295,  1296,  1297,  1298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1306,  1307,    -1,    -1,   665,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   697,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   719,    -1,    -1,    -1,    -1,    -1,   725,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   741,    -1,   743,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1397,  1398,  1399,    -1,
      -1,    -1,    -1,    -1,    -1,  1406,    -1,  1408,    -1,    -1,
      -1,    -1,    -1,    -1,  1415,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1428,    -1,    -1,
      -1,    -1,  1433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1441,  1442,  1443,   799,    -1,    -1,    -1,    -1,    -1,    -1,
    1451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1460,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,  1485,     6,    -1,    -1,   844,    -1,
    1491,  1492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     405,   857,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,  1520,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1528,  1529,    -1,
      -1,    -1,   888,    -1,  1535,  1536,    -1,    -1,    -1,    -1,
      -1,  1542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1559,  1560,
    1561,    -1,    -1,    -1,    -1,    -1,  1567,  1568,  1569,  1570,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1592,  1593,  1594,    -1,  1596,    -1,    -1,    -1,    -1,
      -1,  1602,  1603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1621,    -1,    -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1636,    -1,    -1,  1639,    -1,
      -1,    -1,  1643,    -1,    -1,    -1,    -1,    -1,    -1,   554,
      -1,    -1,    -1,  1009,  1010,  1011,  1012,    -1,    -1,  1660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1673,    -1,    -1,    -1,    -1,  1678,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1692,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,  1067,    -1,    -1,    -1,   236,    -1,    -1,    -1,     6,
      -1,    -1,  1723,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,  1744,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,  1753,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1771,  1772,    -1,    -1,  1775,    -1,    -1,    -1,  1134,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,     6,    -1,    -1,
      -1,   236,    -1,    -1,    -1,  1806,  1807,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1818,    -1,    -1,
      -1,    -1,    -1,    -1,  1825,    -1,    -1,    -1,    -1,    -1,
    1831,  1832,  1833,  1834,  1835,    -1,    -1,    -1,    -1,    -1,
    1841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1856,  1034,    -1,    -1,  1215,
      -1,    -1,    -1,  1864,    -1,    -1,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   781,    -1,   783,   784,
     785,   786,    -1,   788,   789,   790,   791,  1888,     6,    -1,
      -1,    -1,    -1,  1894,  1895,    -1,    -1,   802,    -1,   804,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   820,   821,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   829,    -1,  1927,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,  1952,  1953,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1964,  1965,  1966,  1967,  1968,  1969,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1982,    -1,    -1,    -1,    -1,  1987,  1988,  1989,  1990,
    1991,    -1,    -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,
    2001,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
    2031,    -1,    -1,    -1,    -1,  2036,  2037,  2038,  2039,  2040,
    2041,    -1,   947,   948,   949,    -1,    -1,    -1,   953,   954,
      -1,  2052,   957,   958,   959,   960,    -1,   962,    -1,    -1,
      -1,    -1,   967,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2083,  2084,  2085,  2086,  2087,  2088,    -1,    -1,
      -1,    -1,    -1,    -1,  1272,  1273,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     6,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1040,  1041,    -1,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     3,     4,
       5,    -1,   236,    -1,  1520,    10,    11,    12,   242,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,  1592,  1593,    83,    84,
      85,    -1,    87,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,  1621,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,   119,    -1,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,   190,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,   208,   209,    -1,  1271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,   241,    -1,    -1,   244,
       7,    -1,    -1,  1308,    -1,    -1,  1762,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1775,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1341,  1342,  1343,  1344,
    1345,    -1,    -1,    -1,    -1,  1350,  1351,    -1,  1353,    -1,
      -1,    -1,    -1,    -1,  1359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1841,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
    1856,    -1,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,    -1,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,  1447,    -1,  1449,    -1,    -1,    -1,  1453,    -1,
    1455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1487,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,     8,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,  1987,  1988,  1989,  1990,  1991,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,  2052,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1671,  1672,   117,     8,
     119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
     149,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,  1714,
    1715,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       8,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,   194,   195,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,   208,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1779,  1780,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   237,     3,
       4,     5,   241,     7,    -1,   244,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    87,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,
     234,   235,    -1,   237,    -1,   239,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,  2061,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,     5,   241,    -1,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,   190,   124,   125,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   167,   168,   169,   237,     3,     4,    -1,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,    -1,   241,   242,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,   190,   124,   125,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   167,   168,   169,   237,     3,     4,    -1,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,    -1,   241,    -1,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,   190,   124,   125,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   167,   168,   169,   237,     3,     4,    -1,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,    -1,    -1,   242,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,   190,   124,   125,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   167,   168,   169,   237,     3,     4,    -1,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,    -1,   241,    -1,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,   190,   124,   125,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   167,   168,   169,   237,     3,     4,    -1,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,     8,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,    -1,   241,    -1,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,     8,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,   237,     3,     4,     5,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    13,    14,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,    -1,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,   194,   143,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
     208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   237,
       3,     4,    -1,   241,    -1,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,   242,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,   190,   124,   125,
      -1,   194,   195,    -1,   130,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   167,   168,   169,   237,     3,     4,     5,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
     208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,   241,    -1,    -1,   244,    -1,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,    -1,   240,   190,   191,   192,
     193,   194,   246,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,   208,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,   237,     3,     4,    -1,   241,    -1,
      -1,   244,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,   190,   124,   125,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   167,   168,   169,   237,
       3,     4,    -1,   241,    -1,    -1,   244,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
       3,     4,     5,    -1,   237,    -1,    -1,    10,    11,    12,
      -1,   244,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,     3,     4,
      83,    84,    85,    -1,    87,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,   194,   246,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,   208,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,   190,    -1,   236,    -1,   194,
      -1,    -1,    -1,   242,   199,   200,   201,   246,   203,   204,
     205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   237,    -1,     3,     4,   241,     6,    -1,   244,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,     3,
       4,    -1,     6,    -1,    83,    84,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,   242,
      -1,   190,    -1,   246,    -1,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,    -1,   203,   204,   205,    -1,    -1,    -1,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,   190,    -1,   236,    -1,
     194,    -1,    -1,    -1,   242,   199,   200,   201,   246,   203,
     204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,     3,
       4,    -1,     6,   237,    -1,    -1,    10,    11,    12,    -1,
     244,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    75,    76,    77,    -1,    -1,    10,    11,    12,    83,
      84,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,    -1,   203,
     204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,   237,    -1,     0,     1,    -1,    -1,     4,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,    -1,   203,
     204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,    64,
      65,    66,    -1,   237,    -1,    70,    71,    -1,    73,    -1,
     244,    -1,    -1,    78,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,   107,   108,   109,    -1,   111,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,     4,    -1,
     155,   156,   157,    -1,    -1,    -1,   161,    13,    14,    -1,
      -1,   166,   167,   168,   169,    -1,    -1,   172,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    -1,    -1,    -1,    44,    45,
      -1,   196,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,   209,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,    -1,
      -1,    -1,    78,    79,    -1,    81,    82,    -1,    84,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,   105,
     106,   107,   108,   109,    -1,   111,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
     136,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,     4,     5,   172,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,   209,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,     4,     5,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    85,    -1,    87,    59,    60,
      61,    62,    -1,     5,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    85,    -1,    87,    -1,    59,    60,
      61,    62,    -1,    -1,   124,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    85,    -1,    87,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,    -1,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,    -1,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,    -1,   206,    -1,   208,   214,   215,   216,
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
     236,    -1,    -1,    -1,    -1,    -1,   242,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,   241,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,   241,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
     241,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,   238,    -1,   240,   214,   215,
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
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,   238,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   248,   249,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    81,
      82,    84,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   105,   106,   107,
     108,   109,   111,   113,   114,   115,   116,   117,   118,   119,
     121,   122,   123,   124,   125,   126,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   155,
     156,   157,   161,   166,   167,   168,   169,   172,   174,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   196,   197,   198,   207,   209,   250,   252,
     253,   273,   294,   295,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   313,   315,   316,   322,   323,   324,   325,
     331,   352,   353,   241,   245,    14,    96,   237,   237,     6,
     241,     6,     6,     6,     6,   237,     6,     6,   239,   239,
       4,   333,   353,   237,   239,   271,   271,   237,   241,   237,
     237,     4,   237,   241,   237,   237,     4,   237,   241,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   110,
      96,     6,   241,    90,    93,    96,   237,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    75,    76,    77,    83,    90,
      93,    96,    98,   117,   122,   124,   190,   194,   195,   199,
     200,   201,   203,   204,   205,   225,   226,   232,   237,   241,
     244,   295,   306,   313,   315,   326,   327,   331,   333,   340,
     342,   353,   237,   241,    96,    96,   117,    93,    96,    98,
      90,    93,    96,    98,    93,    96,    98,    93,    96,   237,
      93,   147,   172,   188,   189,   241,   225,   226,   237,   241,
     337,   338,   337,   241,   241,   337,     4,    90,    94,   100,
     101,   103,   104,   121,   237,    96,    98,    96,    93,     4,
      84,   183,   241,   353,     4,     6,    90,    93,    96,    93,
      96,     4,     4,     4,     5,   237,   340,   341,     4,   237,
     237,   237,     4,   241,   344,   353,     4,   237,   237,   237,
       6,     6,   239,     5,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    59,    60,    61,    62,    67,    68,    69,
      72,    74,    85,    87,   191,   192,   193,   202,   206,   208,
     348,   353,   237,     4,   348,     5,   241,     5,   241,    32,
     226,   326,   353,   239,   237,   241,     6,   237,   241,     6,
     245,     7,   124,   183,   210,   211,   212,   213,   234,   235,
     237,   239,   243,   269,   270,   271,   326,   347,   348,   353,
       4,   295,   296,   297,   241,     6,   326,   347,   348,   353,
     347,   326,   347,   351,   275,   279,   237,   336,     9,   348,
     353,   326,   226,   326,   342,   343,   326,   326,   237,   326,
     343,   326,   326,   237,   326,   343,   326,   326,   326,   326,
     326,   326,   347,   326,   326,   326,   340,   237,   343,   341,
     341,   341,   347,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   237,   239,   271,   271,
     271,   271,   271,   271,   237,   271,   271,   237,   271,     5,
     175,   241,     5,   175,     5,   175,     5,   175,   117,    90,
      93,    96,    98,   237,   271,   271,   237,   237,   237,   326,
     241,   326,   342,   326,   326,   242,   343,     9,   353,     8,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   236,     9,
     237,   239,   243,   270,   271,   326,   343,   237,   237,   237,
     340,   341,   341,   341,   237,   237,   237,   237,   237,   340,
     237,   340,   237,   340,   241,   241,   326,     4,   340,   241,
     344,   241,   241,   337,   337,   337,   326,   326,   225,   226,
     241,   241,   337,   225,   226,   237,   297,   337,   241,   237,
     241,   237,   237,   237,   237,   237,   237,   237,   326,   341,
     341,   341,   237,     4,   239,     6,   239,   297,     6,     6,
     241,   241,   241,   341,   341,   239,   239,   239,   326,     6,
       6,   326,   326,   326,   243,   326,   241,   175,   326,   326,
     326,   326,   271,   271,   271,   237,   237,   237,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   237,   237,
     271,   237,   239,     6,     6,   241,     6,   297,     6,   297,
     271,   326,   227,   241,   237,   239,   347,   326,   297,   340,
     340,   241,   348,    90,    93,    96,    98,     7,   326,   326,
       4,   172,   173,   340,     6,   238,   240,   241,   272,     6,
     241,     6,     9,   237,   239,   243,   353,   242,    90,    93,
      96,    98,   117,   122,   125,   294,   326,     6,   238,   246,
       9,   237,   239,   243,   238,   246,   246,   238,   246,   240,
     246,   274,   240,   274,    86,   335,   332,   353,   246,   246,
     238,   227,   242,   246,   238,   238,   326,   238,   242,   238,
     238,   326,   238,   242,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,     7,   326,   242,     6,     6,     6,
     238,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   342,   326,
     326,   326,   326,   326,   326,   326,   342,   342,   353,   241,
     326,   326,   347,   326,   347,   340,   347,   347,   351,   326,
      64,   326,    64,    64,    64,   341,   341,   341,   341,   347,
     347,   342,   333,   348,   333,   343,   238,   242,     9,   271,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   241,   326,   342,   326,   326,   326,
     326,   326,   353,   326,   326,     4,   334,   241,   272,   238,
     242,   326,   326,   326,     7,     7,   319,   319,   288,   326,
     348,   289,   326,   348,   290,   326,   348,   291,   326,   348,
     326,     6,   326,     6,   326,     6,   343,   343,   241,   238,
       6,   297,   241,   297,   297,   246,   246,   246,   337,   337,
     296,   296,   246,   326,   242,   310,   246,   297,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   238,     7,   320,
       6,     7,   326,     6,   326,   326,   242,   343,   343,   343,
       6,     6,   326,   326,   326,   238,   238,   238,   238,   172,
     246,   297,   241,     8,   238,   238,   240,   351,   347,   351,
     347,   347,   347,   347,   347,   347,   326,   347,   347,   347,
     347,   244,   350,   353,   348,   347,   347,   347,   333,   353,
     343,   242,   242,   326,   326,   297,   240,   238,   130,   147,
     314,   238,   242,   246,   326,     6,   241,   241,   241,   241,
     326,   238,   240,     7,   269,   270,   243,     7,     6,   343,
       7,   213,   269,   254,   353,   326,   326,   334,   239,   241,
     241,   241,   241,   237,   117,    93,    96,    98,   242,     6,
     220,   251,   343,   353,   326,   326,     4,   334,     6,   343,
     326,     6,   347,     6,   353,     6,   347,   326,   238,   239,
     326,   348,     7,   175,   326,   342,     7,     7,   238,     7,
     175,     7,     7,   238,     7,   175,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   326,   238,   241,     6,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     246,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     246,   246,   246,   238,   240,   240,   343,   246,   246,   272,
     246,   272,   246,   246,   246,   238,   328,   241,   242,   241,
     241,   241,   246,   246,   272,   272,   238,   243,   238,   243,
     246,   329,   242,     7,   272,     8,     8,   343,   243,   238,
     240,   270,   343,     7,   241,   238,   238,   238,   326,   340,
       4,   318,     6,   238,   246,   238,   246,   238,   246,   238,
     246,   238,   238,   238,   242,   242,   343,   243,   242,   297,
     242,   242,   337,   326,   326,   242,   242,   326,   337,   127,
     127,   144,   152,   153,   154,   158,   159,   311,   312,   337,
     242,   307,   238,   242,   238,   238,   238,   238,   238,   238,
     238,     7,   326,     6,   326,   238,   240,   240,   242,   242,
     242,   240,   240,   246,     7,     7,     7,   243,   326,   242,
     326,   326,     7,   243,   272,   246,   272,   272,   238,   238,
     246,   272,   272,   246,   246,   272,   272,   272,   272,   326,
     272,     9,   349,   246,   238,   246,   272,   243,   246,   330,
     240,   242,   242,   245,     7,   147,     6,   326,   242,   241,
       6,   340,   242,   326,   326,   326,   326,     6,     7,   269,
     270,   243,   269,   270,   348,   326,     6,     4,   241,   345,
     353,   242,    46,    46,   340,     4,   162,   163,   164,   165,
     242,   257,   261,   264,   266,   267,   243,   238,   240,   326,
     343,   343,   343,   343,   326,   237,   237,   237,   237,   220,
     347,   238,   243,   238,   240,   238,   246,     7,   271,     4,
     282,   283,   284,   272,   272,   337,    96,    98,   340,   340,
       7,   340,    96,    98,   340,   340,     7,   340,    98,   340,
     340,   340,   340,   340,   340,   340,   340,   340,     6,     7,
     343,   326,   326,   326,   326,   242,   326,   326,   326,   340,
     347,   347,   246,   281,   326,   326,   326,   326,   326,   326,
     334,   334,   326,   238,   340,   326,   326,   242,   334,   270,
     243,   270,   242,   340,   343,     7,     7,     7,   127,   317,
       6,   269,   326,   269,   326,   269,   326,   269,   326,     7,
       7,     7,     7,     7,   242,     4,   242,   246,   246,   246,
     242,   242,   108,     4,     6,   326,   241,     6,   237,     6,
     160,     6,   160,   242,   312,   246,   311,     7,     6,     7,
       7,     7,     7,     7,     7,     7,   340,     6,   241,     6,
       6,     6,    96,     7,     6,     6,   326,   340,   340,   340,
       4,   246,     8,     8,   238,     4,     4,   343,   347,   326,
     347,   244,   246,   285,   347,   347,   334,   347,   238,   246,
     241,   241,     6,   326,     6,   241,   340,   242,   242,   242,
     242,   242,   326,     6,     4,   172,   173,   326,     6,     6,
       6,     7,   344,   346,     6,   239,   272,   271,   271,     6,
     258,   237,   237,   241,   268,     6,   334,   243,   347,   240,
     242,   242,   242,   242,   238,   326,   326,   326,   326,     6,
       6,   251,   334,   243,     6,   326,   241,   326,   348,   272,
     241,   340,   348,   240,   246,     6,     6,     6,   241,   241,
     121,   293,   293,   340,     6,   241,   241,     6,     6,   340,
     175,   292,   241,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   242,   272,   272,   272,   272,   272,   246,
     246,   246,   238,   272,   272,   283,   272,   246,   246,   246,
     246,   238,   272,   238,   329,     6,     4,   272,     6,   242,
     340,   340,   340,     4,     6,   340,   340,   340,   340,   340,
     340,   340,   241,   241,     7,     6,     7,   326,   326,   326,
     241,   241,   241,   239,     6,   326,   340,   326,     6,     6,
     326,   337,   242,     5,   340,   241,   241,   241,   241,   241,
     241,   241,   340,     6,   343,   241,   326,   240,     6,     6,
     171,   326,   326,   326,     6,     6,     7,   272,   246,   246,
     272,   246,   326,     4,   187,   286,   287,   272,   238,   272,
     330,   348,   326,   297,     6,   297,   246,     6,     6,     7,
     269,   270,   243,     7,     6,   344,   242,   246,   326,   269,
     272,   351,   351,   237,   326,   326,   339,   340,   241,     4,
       6,     6,     6,     6,     6,     6,   238,   238,   238,   238,
     347,     4,   246,   340,   348,     7,   280,   326,   342,   284,
     326,   326,   337,     6,     6,     6,   326,   326,     6,    94,
       6,   326,     5,   241,   326,   326,   326,   326,   326,   326,
     326,   238,   270,   241,     6,   292,     6,   326,     6,     6,
       6,     6,     6,     4,     6,     6,   343,   343,   326,   326,
     348,   242,   238,   242,   246,   296,   296,   326,   326,   242,
     246,   238,   242,   246,     6,     6,   339,   337,   337,   337,
     337,   337,   226,   337,     6,   242,   326,     6,     6,   340,
     242,   246,     8,   242,   238,   241,   326,   348,   347,   326,
     347,   241,   326,   348,   348,   246,   238,   246,   242,   314,
     314,   340,   348,   326,     6,     4,   345,     6,   344,   240,
     340,     6,   272,   272,   255,   326,   246,   246,   242,   246,
     256,   326,     6,   326,   276,   278,   241,   242,   246,     7,
       7,   242,   242,   242,   242,   241,   242,     5,   339,   272,
     272,   246,   246,   246,   246,   246,   326,     6,   241,   242,
     242,   241,     6,     6,   241,   326,   242,   242,   242,   240,
       6,   340,     7,   241,   326,   242,   246,   246,   246,   246,
     246,   246,     6,   242,   170,   326,   326,   343,     6,     6,
     238,   272,   272,   351,   287,   348,   242,   242,   242,     6,
       6,     7,     6,   243,     6,     6,     6,   238,   246,   326,
     326,   241,   340,   242,   246,   246,   281,   285,   340,   326,
     348,   353,     6,     6,     6,     6,   326,     6,     6,   242,
     326,   326,   326,   326,   326,   242,   339,   131,   132,   137,
     321,   131,   132,   321,   343,   296,   242,   246,     6,   242,
     340,   297,   242,     6,   343,   337,   337,   337,   337,   337,
     326,   242,   242,   242,   242,   238,   241,     6,   344,   173,
     259,   326,   246,   246,   339,     6,   326,   326,   242,   242,
     277,     7,   237,   242,   241,   246,   246,   246,   246,   246,
     242,   241,   337,   340,     6,   241,   337,     6,   242,   242,
     326,     6,   127,   242,   308,   241,   242,   246,   246,   246,
     246,   246,     6,     6,     6,   297,     6,   241,   326,   326,
     242,   246,   281,   348,   238,   326,   326,   326,   326,   326,
     326,     6,   337,     6,   337,     6,     6,   242,   326,   311,
     297,     6,   343,   343,   343,   343,   337,   343,   314,   256,
     238,   246,     6,   241,   326,   242,   246,   246,   246,   246,
     246,   246,   246,   246,     6,   242,   242,   309,   242,   242,
     242,   242,   246,   242,   242,   242,   262,   326,   339,   242,
     326,   326,   326,   326,   326,   326,   337,   337,   311,     6,
       6,     6,     6,   343,     6,     6,     6,   241,   238,   242,
       6,   242,   272,   246,   246,   246,   246,   246,   246,   242,
     242,   260,   347,   265,   241,     6,   326,   326,   326,   326,
     326,   326,     6,   242,   246,   241,   339,   242,   242,   242,
     242,   242,   242,     6,   347,   263,   347,   242,     6,     6,
     242,   246,     6,     6,   347
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
#line 254 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 265 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 266 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 267 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 269 "Gmsh.y"
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
#line 287 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 288 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 289 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 290 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 291 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 292 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 293 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 294 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 295 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 296 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 297 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 298 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 299 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 300 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 301 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 302 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 307 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 311 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 318 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 323 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 328 "Gmsh.y"
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
#line 342 "Gmsh.y"
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
#line 355 "Gmsh.y"
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
#line 368 "Gmsh.y"
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
#line 396 "Gmsh.y"
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
#line 410 "Gmsh.y"
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
#line 423 "Gmsh.y"
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
#line 436 "Gmsh.y"
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
#line 454 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 468 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 470 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 475 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 477 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 482 "Gmsh.y"
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
#line 586 "Gmsh.y"
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
#line 596 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 605 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 612 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 622 "Gmsh.y"
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
#line 631 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 640 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 647 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 657 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 665 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 675 "Gmsh.y"
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
#line 694 "Gmsh.y"
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
#line 713 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 719 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 726 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 727 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 728 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 729 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 730 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 734 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 735 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 741 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 741 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 742 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 742 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 752 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 757 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 763 "Gmsh.y"
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
#line 825 "Gmsh.y"
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
#line 840 "Gmsh.y"
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
#line 869 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 879 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 884 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 892 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 897 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 905 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 914 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 919 "Gmsh.y"
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
#line 931 "Gmsh.y"
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
#line 948 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 954 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 963 "Gmsh.y"
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
#line 981 "Gmsh.y"
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
#line 999 "Gmsh.y"
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
#line 1008 "Gmsh.y"
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
#line 1020 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1025 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1033 "Gmsh.y"
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
#line 1053 "Gmsh.y"
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
#line 1076 "Gmsh.y"
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
#line 1087 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1095 "Gmsh.y"
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
#line 1117 "Gmsh.y"
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
#line 1140 "Gmsh.y"
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
#line 1178 "Gmsh.y"
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
#line 1199 "Gmsh.y"
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
#line 1211 "Gmsh.y"
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
#line 1229 "Gmsh.y"
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
#line 1238 "Gmsh.y"
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
#line 1247 "Gmsh.y"
    { init_options(); ;}
    break;

  case 115:
#line 1249 "Gmsh.y"
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
#line 1267 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1269 "Gmsh.y"
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
#line 1285 "Gmsh.y"
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
#line 1294 "Gmsh.y"
    { init_options(); ;}
    break;

  case 120:
#line 1296 "Gmsh.y"
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
#line 1310 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 123:
#line 1318 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 124:
#line 1324 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 125:
#line 1329 "Gmsh.y"
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
#line 1371 "Gmsh.y"
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
#line 1383 "Gmsh.y"
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
#line 1396 "Gmsh.y"
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
#line 1411 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 140:
#line 1433 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 141:
#line 1441 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 142:
#line 1450 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 143:
#line 1458 "Gmsh.y"
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
#line 1476 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 145:
#line 1480 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 0, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 146:
#line 1487 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 147:
#line 1495 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 148:
#line 1499 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 1, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 149:
#line 1506 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 150:
#line 1514 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 151:
#line 1518 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 2, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 152:
#line 1525 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 153:
#line 1533 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 154:
#line 1537 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 3, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 155:
#line 1544 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 156:
#line 1552 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 157:
#line 1556 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 158:
#line 1562 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 159:
#line 1566 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 160:
#line 1573 "Gmsh.y"
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
#line 1597 "Gmsh.y"
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
#line 1613 "Gmsh.y"
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
#line 1629 "Gmsh.y"
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
#line 1666 "Gmsh.y"
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
#line 1706 "Gmsh.y"
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
#line 1722 "Gmsh.y"
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
#line 1739 "Gmsh.y"
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
#line 1760 "Gmsh.y"
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
#line 1770 "Gmsh.y"
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
#line 1786 "Gmsh.y"
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
#line 1803 "Gmsh.y"
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
#line 1819 "Gmsh.y"
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
#line 1840 "Gmsh.y"
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
#line 1851 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 175:
#line 1857 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 176:
#line 1863 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1870 "Gmsh.y"
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
#line 1901 "Gmsh.y"
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
#line 1916 "Gmsh.y"
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
#line 1938 "Gmsh.y"
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
#line 1961 "Gmsh.y"
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
#line 1984 "Gmsh.y"
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
#line 2007 "Gmsh.y"
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
#line 2031 "Gmsh.y"
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
#line 2055 "Gmsh.y"
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
#line 2078 "Gmsh.y"
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
#line 2103 "Gmsh.y"
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
#line 2114 "Gmsh.y"
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
#line 2136 "Gmsh.y"
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
#line 2153 "Gmsh.y"
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
#line 2169 "Gmsh.y"
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
#line 2187 "Gmsh.y"
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
#line 2205 "Gmsh.y"
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
#line 2215 "Gmsh.y"
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
#line 2227 "Gmsh.y"
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
#line 2239 "Gmsh.y"
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
#line 2251 "Gmsh.y"
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
#line 2268 "Gmsh.y"
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
#line 2284 "Gmsh.y"
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
#line 2300 "Gmsh.y"
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
#line 2315 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
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
#line 2330 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
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
#line 2345 "Gmsh.y"
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
#line 2380 "Gmsh.y"
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
#line 2402 "Gmsh.y"
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
#line 2425 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 207:
#line 2426 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 208:
#line 2431 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 209:
#line 2435 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 210:
#line 2439 "Gmsh.y"
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
#line 2450 "Gmsh.y"
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
#line 2461 "Gmsh.y"
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
#line 2472 "Gmsh.y"
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
#line 2488 "Gmsh.y"
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
#line 2507 "Gmsh.y"
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
#line 2529 "Gmsh.y"
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
#line 2544 "Gmsh.y"
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
#line 2559 "Gmsh.y"
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
#line 2578 "Gmsh.y"
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
#line 2629 "Gmsh.y"
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
#line 2650 "Gmsh.y"
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
#line 2672 "Gmsh.y"
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
#line 2694 "Gmsh.y"
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
#line 2799 "Gmsh.y"
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
#line 2815 "Gmsh.y"
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
#line 2850 "Gmsh.y"
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
#line 2861 "Gmsh.y"
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
#line 2872 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 229:
#line 2878 "Gmsh.y"
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
#line 2893 "Gmsh.y"
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
#line 2921 "Gmsh.y"
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
#line 2933 "Gmsh.y"
    {
      nameSpaces.clear();
    ;}
    break;

  case 233:
#line 2942 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 234:
#line 2949 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 235:
#line 2961 "Gmsh.y"
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
#line 2980 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 237:
#line 2986 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 238:
#line 2992 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 2999 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 3006 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 241:
#line 3013 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3025 "Gmsh.y"
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
#line 3098 "Gmsh.y"
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
#line 3116 "Gmsh.y"
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
#line 3133 "Gmsh.y"
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
#line 3148 "Gmsh.y"
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
#line 3181 "Gmsh.y"
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
#line 3193 "Gmsh.y"
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
#line 3217 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 250:
#line 3221 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 251:
#line 3226 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 252:
#line 3233 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 253:
#line 3238 "Gmsh.y"
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
#line 3248 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 255:
#line 3253 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 256:
#line 3259 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 257:
#line 3267 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 258:
#line 3271 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 259:
#line 3275 "Gmsh.y"
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
#line 3285 "Gmsh.y"
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
#line 3348 "Gmsh.y"
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
#line 3364 "Gmsh.y"
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
#line 3381 "Gmsh.y"
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
#line 3398 "Gmsh.y"
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
#line 3420 "Gmsh.y"
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
#line 3442 "Gmsh.y"
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
#line 3477 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 268:
#line 3485 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 269:
#line 3493 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 270:
#line 3499 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 271:
#line 3506 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 272:
#line 3513 "Gmsh.y"
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
#line 3533 "Gmsh.y"
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
#line 3559 "Gmsh.y"
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
#line 3571 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 276:
#line 3583 "Gmsh.y"
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
#line 3601 "Gmsh.y"
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
#line 3619 "Gmsh.y"
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
#line 3637 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3643 "Gmsh.y"
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
#line 3661 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3667 "Gmsh.y"
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
#line 3687 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3693 "Gmsh.y"
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
#line 3711 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3717 "Gmsh.y"
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
#line 3734 "Gmsh.y"
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
#line 3750 "Gmsh.y"
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
#line 3767 "Gmsh.y"
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
#line 3784 "Gmsh.y"
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
#line 3807 "Gmsh.y"
    {
    ;}
    break;

  case 292:
#line 3810 "Gmsh.y"
    {
    ;}
    break;

  case 293:
#line 3816 "Gmsh.y"
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
#line 3828 "Gmsh.y"
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
#line 3848 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 296:
#line 3852 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 297:
#line 3856 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 298:
#line 3860 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 299:
#line 3864 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3868 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 301:
#line 3872 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3876 "Gmsh.y"
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
#line 3885 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 304:
#line 3897 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 305:
#line 3898 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 306:
#line 3899 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 307:
#line 3900 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 308:
#line 3901 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 309:
#line 3905 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 310:
#line 3906 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 311:
#line 3907 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 312:
#line 3908 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 313:
#line 3909 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 314:
#line 3914 "Gmsh.y"
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
#line 3936 "Gmsh.y"
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
#line 3956 "Gmsh.y"
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
#line 3976 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 318:
#line 3980 "Gmsh.y"
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
#line 3995 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 320:
#line 3999 "Gmsh.y"
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
#line 4015 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 322:
#line 4019 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 323:
#line 4024 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 324:
#line 4028 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 325:
#line 4034 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 326:
#line 4038 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 327:
#line 4045 "Gmsh.y"
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
#line 4062 "Gmsh.y"
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
#line 4103 "Gmsh.y"
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
#line 4147 "Gmsh.y"
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
#line 4186 "Gmsh.y"
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
#line 4211 "Gmsh.y"
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
#line 4220 "Gmsh.y"
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
#line 4250 "Gmsh.y"
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
#line 4276 "Gmsh.y"
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
#line 4303 "Gmsh.y"
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
#line 4335 "Gmsh.y"
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
#line 4362 "Gmsh.y"
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
#line 4388 "Gmsh.y"
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
#line 4414 "Gmsh.y"
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
#line 4440 "Gmsh.y"
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
#line 4466 "Gmsh.y"
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
#line 4487 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 344:
#line 4493 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 345:
#line 4499 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 346:
#line 4505 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 347:
#line 4511 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 348:
#line 4517 "Gmsh.y"
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
#line 4543 "Gmsh.y"
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
#line 4569 "Gmsh.y"
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
#line 4586 "Gmsh.y"
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
#line 4603 "Gmsh.y"
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
#line 4620 "Gmsh.y"
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
#line 4632 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 355:
#line 4638 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 356:
#line 4644 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 357:
#line 4656 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 358:
#line 4660 "Gmsh.y"
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
#line 4670 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 360:
#line 4680 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 361:
#line 4681 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 362:
#line 4682 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 363:
#line 4687 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 364:
#line 4693 "Gmsh.y"
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
#line 4705 "Gmsh.y"
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
#line 4723 "Gmsh.y"
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
#line 4750 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 368:
#line 4751 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 369:
#line 4752 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 370:
#line 4753 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 371:
#line 4754 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 372:
#line 4755 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 373:
#line 4756 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4757 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4759 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 376:
#line 4765 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 377:
#line 4766 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 378:
#line 4767 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 379:
#line 4768 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 380:
#line 4769 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4770 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4771 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 383:
#line 4772 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4773 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4774 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4775 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4776 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 388:
#line 4777 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 389:
#line 4778 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 390:
#line 4779 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 391:
#line 4780 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4781 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 393:
#line 4782 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 394:
#line 4783 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 395:
#line 4784 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 4785 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4786 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 398:
#line 4787 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4788 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4789 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4790 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 402:
#line 4791 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4792 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4793 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4794 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4795 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 407:
#line 4796 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 408:
#line 4797 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 4798 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 410:
#line 4799 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 411:
#line 4800 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 412:
#line 4801 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 413:
#line 4802 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 414:
#line 4811 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 415:
#line 4812 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 416:
#line 4813 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 417:
#line 4814 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 418:
#line 4815 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 419:
#line 4816 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 420:
#line 4817 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 421:
#line 4818 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 422:
#line 4819 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 423:
#line 4820 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 424:
#line 4821 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 425:
#line 4826 "Gmsh.y"
    { init_options(); ;}
    break;

  case 426:
#line 4828 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 427:
#line 4834 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 428:
#line 4836 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 429:
#line 4841 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 430:
#line 4846 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 431:
#line 4850 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 432:
#line 4868 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 433:
#line 4886 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 0., 1);
    ;}
    break;

  case 434:
#line 4890 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0., 1);
    ;}
    break;

  case 435:
#line 4894 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 436:
#line 4898 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 437:
#line 4902 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:
#line 4908 "Gmsh.y"
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
#line 4924 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 440:
#line 4930 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 441:
#line 4936 "Gmsh.y"
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

  case 442:
#line 4955 "Gmsh.y"
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

  case 443:
#line 4976 "Gmsh.y"
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
#line 5009 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 445:
#line 5013 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 446:
#line 5018 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 447:
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

  case 448:
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

  case 449:
#line 5043 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 450:
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

  case 451:
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

  case 452:
#line 5068 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 453:
#line 5073 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 454:
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

  case 455:
#line 5105 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 456:
#line 5107 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 457:
#line 5112 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 458:
#line 5114 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 459:
#line 5119 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 460:
#line 5126 "Gmsh.y"
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

  case 461:
#line 5142 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 462:
#line 5144 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 463:
#line 5149 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 464:
#line 5158 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 465:
#line 5160 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 466:
#line 5165 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 467:
#line 5167 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 468:
#line 5173 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 469:
#line 5177 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 470:
#line 5181 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 471:
#line 5185 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 472:
#line 5189 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 473:
#line 5196 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 474:
#line 5200 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 475:
#line 5204 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 476:
#line 5208 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 477:
#line 5215 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 478:
#line 5220 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 479:
#line 5227 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 480:
#line 5232 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 481:
#line 5236 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 482:
#line 5241 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 483:
#line 5245 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 484:
#line 5253 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 485:
#line 5264 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 486:
#line 5268 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 487:
#line 5280 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 488:
#line 5288 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 489:
#line 5296 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 490:
#line 5303 "Gmsh.y"
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

  case 491:
#line 5313 "Gmsh.y"
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

  case 492:
#line 5336 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 493:
#line 5342 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 494:
#line 5348 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 495:
#line 5354 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 496:
#line 5360 "Gmsh.y"
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

  case 497:
#line 5371 "Gmsh.y"
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

  case 498:
#line 5382 "Gmsh.y"
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

  case 499:
#line 5393 "Gmsh.y"
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

  case 500:
#line 5405 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 501:
#line 5411 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 502:
#line 5417 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 503:
#line 5423 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 504:
#line 5428 "Gmsh.y"
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

  case 505:
#line 5438 "Gmsh.y"
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

  case 506:
#line 5448 "Gmsh.y"
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
#line 5458 "Gmsh.y"
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

  case 508:
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

  case 509:
#line 5483 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 510:
#line 5487 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 511:
#line 5491 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 512:
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

  case 513:
#line 5513 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 514:
#line 5521 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 515:
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

  case 516:
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

  case 517:
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

  case 518:
#line 5584 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 519:
#line 5595 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 520:
#line 5600 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 521:
#line 5604 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 522:
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

  case 523:
#line 5620 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 524:
#line 5624 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 525:
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

  case 526:
#line 5653 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 527:
#line 5663 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 528:
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

  case 529:
#line 5682 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 530:
#line 5687 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 531:
#line 5694 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 532:
#line 5698 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 533:
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

  case 534:
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

  case 535:
#line 5734 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 536:
#line 5738 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 537:
#line 5743 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 538:
#line 5751 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 539:
#line 5757 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 540:
#line 5763 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 541:
#line 5769 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 542:
#line 5778 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 543:
#line 5782 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 544:
#line 5786 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 545:
#line 5794 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 546:
#line 5800 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 547:
#line 5806 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 548:
#line 5810 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 549:
#line 5818 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 550:
#line 5826 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 551:
#line 5833 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 552:
#line 5843 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 553:
#line 5848 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 554:
#line 5853 "Gmsh.y"
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

  case 555:
#line 5868 "Gmsh.y"
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

  case 556:
#line 5882 "Gmsh.y"
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

  case 557:
#line 5896 "Gmsh.y"
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

  case 558:
#line 5908 "Gmsh.y"
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

  case 559:
#line 5924 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 560:
#line 5933 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 561:
#line 5942 "Gmsh.y"
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

  case 562:
#line 5952 "Gmsh.y"
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

  case 563:
#line 5963 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 564:
#line 5971 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 565:
#line 5979 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 5983 "Gmsh.y"
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

  case 567:
#line 6002 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 568:
#line 6009 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 569:
#line 6015 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 570:
#line 6022 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 571:
#line 6029 "Gmsh.y"
    { init_options(); ;}
    break;

  case 572:
#line 6031 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 573:
#line 6039 "Gmsh.y"
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

  case 574:
#line 6063 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 575:
#line 6065 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 576:
#line 6071 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 577:
#line 6076 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 578:
#line 6084 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 579:
#line 6093 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 580:
#line 6102 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 581:
#line 6114 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 582:
#line 6117 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 583:
#line 6121 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13445 "Gmsh.tab.cpp"
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


#line 6124 "Gmsh.y"


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
(char* c1, char* c2, double val_default, int type_treat)
{
  double out;
  if(!c1 && gmsh_yysymbols.count(c2)){
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    else { // Get (0) or GetForced (2)
      gmsh_yysymbol &s(gmsh_yysymbols[c2]);
      if(s.value.empty()){
        out = val_default;
        if (type_treat == 0) yymsg(0, "Uninitialized variable '%s'", c2);
      }
      else
        out = s.value[0];
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
(char* c1, char* c2, char* c3, double val_default, int type_treat)
{
  double out;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (nameSpaces.getMember
          (struct_namespace, struct_name, key_member, out)) {
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
  }
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}

char * treat_Struct_FullName_String
(char* c1, char* c2, char * val_default, int type_treat)
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
(char* c1, char* c2, char* c3, char * val_default, int type_treat)
{
  std::string string_default(val_default? val_default : std::string(""));
  const std::string * out = NULL;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (nameSpaces.getMember
          (struct_namespace, struct_name, key_member, out)) {
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
  }
  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out_c;
}

