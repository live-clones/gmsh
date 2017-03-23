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
#define YYLAST   15022

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
    2444,  2447,  2450,  2456,  2462,  2466,  2472,  2479,  2484,  2492,
    2499,  2506,  2513,  2518,  2525,  2530,  2531,  2534,  2535,  2538,
    2539,  2547,  2549,  2553,  2555,  2557,  2560,  2561,  2565,  2567,
    2570,  2573,  2577,  2581,  2593,  2603,  2611,  2619,  2621,  2625,
    2627,  2629,  2632,  2636,  2641,  2647,  2649,  2651,  2654,  2658,
    2662,  2668,  2673,  2676,  2679,  2682,  2685,  2689,  2693,  2697,
    2701,  2718,  2735,  2752,  2769,  2771,  2773,  2775,  2779,  2784,
    2789,  2794,  2801,  2808,  2817,  2826,  2831,  2846,  2851,  2856,
    2858,  2860,  2864,  2868,  2878,  2886,  2888,  2894,  2898,  2905,
    2907,  2911,  2913,  2915,  2920,  2925,  2929,  2935,  2942,  2948,
    2954,  2960,  2966,  2968,  2973,  2975,  2977,  2979,  2981,  2986,
    2993,  2998,  3005,  3011,  3019,  3024,  3029,  3034,  3043,  3048,
    3053,  3058,  3063,  3072,  3081,  3088,  3093,  3100,  3105,  3107,
    3112,  3117,  3118,  3125,  3130,  3133,  3138,  3140,  3144,  3150,
    3156,  3165,  3167,  3169
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     248,     0,    -1,   249,    -1,     1,     6,    -1,    -1,   249,
     250,    -1,   252,    -1,   253,    -1,   273,    -1,   116,   237,
     347,   238,     6,    -1,   294,    -1,   295,    -1,   299,    -1,
     300,    -1,   301,    -1,   302,    -1,   306,    -1,   315,    -1,
     316,    -1,   322,    -1,   323,    -1,   305,    -1,   304,    -1,
     303,    -1,   298,    -1,   325,    -1,   220,    -1,   221,    -1,
      44,   237,   347,   238,     6,    -1,    45,   237,   347,   238,
       6,    -1,    44,   237,   347,   238,   251,   347,     6,    -1,
      44,   237,   347,   246,   343,   238,     6,    -1,    45,   237,
     347,   246,   343,   238,     6,    -1,    44,   237,   347,   246,
     343,   238,   251,   347,     6,    -1,   353,   347,   241,   254,
     242,     6,    -1,   155,     4,   239,   326,   240,     6,    -1,
     156,     4,   239,   326,   240,     6,    -1,   157,     4,   239,
     326,   246,   326,   240,     6,    -1,    -1,   254,   257,    -1,
     254,   261,    -1,   254,   264,    -1,   254,   266,    -1,   254,
     267,    -1,   326,    -1,   255,   246,   326,    -1,   326,    -1,
     256,   246,   326,    -1,    -1,    -1,     4,   258,   237,   255,
     238,   259,   241,   256,   242,     6,    -1,   347,    -1,   260,
     246,   347,    -1,    -1,   162,   237,   326,   246,   326,   246,
     326,   238,   262,   241,   260,   242,     6,    -1,   347,    -1,
     263,   246,   347,    -1,    -1,   163,   237,   326,   246,   326,
     246,   326,   246,   326,   238,   265,   241,   263,   242,     6,
      -1,   164,   241,   339,   242,   241,   339,   242,     6,    -1,
     164,   241,   339,   242,   241,   339,   242,   241,   339,   242,
     241,   339,   242,     6,    -1,    -1,   165,   268,   241,   256,
     242,     6,    -1,     7,    -1,   213,    -1,   212,    -1,   211,
      -1,   210,    -1,   235,    -1,   234,    -1,   237,    -1,   239,
      -1,   238,    -1,   240,    -1,    81,   239,   275,   240,     6,
      -1,    82,   239,   279,   240,     6,    -1,   331,     6,    -1,
      88,   271,   348,   246,   326,   272,     6,    -1,    89,   271,
     353,   246,   348,   272,     6,    -1,   353,   269,   340,     6,
      -1,   353,   270,     6,    -1,   353,   271,   272,   269,   340,
       6,    -1,   353,   271,   241,   343,   242,   272,   269,   340,
       6,    -1,   353,   239,   326,   240,   269,   326,     6,    -1,
     353,   239,   326,   240,   270,     6,    -1,   353,   237,   326,
     238,   269,   326,     6,    -1,   353,   237,   326,   238,   270,
       6,    -1,   353,     7,   348,     6,    -1,   353,   271,   272,
       7,    46,   271,   272,     6,    -1,   353,   271,   272,     7,
      46,   271,   351,   272,     6,    -1,   353,   271,   272,   213,
      46,   271,   351,   272,     6,    -1,   353,   243,     4,     7,
     348,     6,    -1,   353,   239,   326,   240,   243,     4,     7,
     348,     6,    -1,   353,   243,     4,   269,   326,     6,    -1,
     353,   239,   326,   240,   243,     4,   269,   326,     6,    -1,
     353,   243,     4,   270,     6,    -1,   353,   239,   326,   240,
     243,     4,   270,     6,    -1,   353,   243,   172,   243,     4,
       7,   344,     6,    -1,   353,   239,   326,   240,   243,   172,
     243,     4,     7,   344,     6,    -1,   353,   243,   173,     7,
     345,     6,    -1,   353,   239,   326,   240,   243,   173,     7,
     345,     6,    -1,   353,   183,     7,   326,     6,    -1,   183,
     239,   326,   240,     7,     4,     6,    -1,   183,   239,   326,
     240,   243,     4,     7,   326,     6,    -1,   183,   239,   326,
     240,   243,     4,     7,   348,     6,    -1,   183,   239,   326,
     240,   243,     4,     7,   241,   343,   242,     6,    -1,   183,
     239,   326,   240,   243,     4,     6,    -1,   128,   237,     4,
     238,   243,     4,     7,   326,     6,    -1,   128,   237,     4,
     238,   243,     4,     7,   348,     6,    -1,    -1,   246,    -1,
      -1,   275,   274,   353,    -1,   275,   274,   353,     7,   326,
      -1,    -1,   275,   274,   353,     7,   241,   340,   276,   281,
     242,    -1,    -1,   275,   274,   353,   271,   272,     7,   241,
     340,   277,   281,   242,    -1,   275,   274,   353,     7,   348,
      -1,    -1,   275,   274,   353,     7,   241,   348,   278,   285,
     242,    -1,    -1,   279,   274,   347,    -1,   326,     7,   348,
      -1,   280,   246,   326,     7,   348,    -1,   342,     7,   353,
     237,   238,    -1,    -1,   246,   283,    -1,    -1,   283,    -1,
     284,    -1,   283,   246,   284,    -1,     4,   340,    -1,     4,
      -1,     4,   241,   280,   242,    -1,     4,   348,    -1,    -1,
     246,   286,    -1,   287,    -1,   286,   246,   287,    -1,     4,
     326,    -1,     4,   348,    -1,   187,   348,    -1,     4,   241,
     351,   242,    -1,   326,    -1,   348,    -1,   348,   246,   326,
      -1,   326,    -1,   348,    -1,   348,   246,   326,    -1,   326,
      -1,   348,    -1,   348,   246,   326,    -1,   326,    -1,   348,
      -1,   348,   246,   326,    -1,    -1,   175,    94,   241,   326,
     242,    -1,    -1,   121,   337,    -1,    90,   237,   326,   238,
       7,   337,     6,    -1,    93,   237,   326,   238,     7,   340,
       6,    -1,    97,   237,   326,   238,     7,   340,     6,    -1,
      91,   237,   326,   238,     7,   340,   293,     6,    -1,    92,
     237,   326,   238,     7,   340,   293,     6,    -1,   167,   237,
     326,   238,     7,   340,     6,    -1,   168,   237,   326,   238,
       7,   340,     6,    -1,   169,   237,   326,   238,     7,   340,
     171,   340,   170,   326,     6,    -1,   125,    93,   237,   326,
     238,     7,   340,     6,    -1,   108,   237,   326,   238,     7,
     340,     6,    -1,    93,     4,   237,   326,   238,     7,   340,
       6,    -1,   121,    96,   237,   326,   238,     7,   340,     6,
      -1,    96,   237,   326,   238,     7,   340,   292,     6,    -1,
     122,    96,   237,   326,   238,     7,   340,   292,     6,    -1,
      13,    14,     6,    -1,    14,    96,   326,     6,    -1,   111,
      96,   237,   326,   238,     7,     5,     5,     5,     6,    -1,
      94,   237,   326,   238,     7,   340,     6,    -1,    95,   237,
     326,   238,     7,   340,     6,    -1,    99,   237,   326,   238,
       7,   340,     6,    -1,   102,   237,   326,   238,     7,   340,
       6,    -1,   106,   237,   326,   238,     7,   340,     6,    -1,
     107,   237,   326,   238,     7,   340,     6,    -1,   100,   237,
     326,   238,     7,   340,     6,    -1,   101,   237,   326,   238,
       7,   340,     6,    -1,   118,   237,   326,   238,     7,   340,
       6,    -1,   143,   237,   326,   238,     7,   340,     6,    -1,
     125,    96,   237,   326,   238,     7,   340,     6,    -1,   125,
      96,   237,   326,   238,     7,   340,     4,   241,   339,   242,
       6,    -1,    96,     4,   237,   326,   238,     7,   340,     6,
      -1,    98,   237,   326,   238,     7,   340,     6,    -1,   117,
     237,   326,   238,     7,   340,     6,    -1,   122,   117,   237,
     326,   238,     7,   340,     6,    -1,   125,    98,   237,   326,
     238,     7,   340,     6,    -1,   124,    90,   237,   288,   238,
     269,   340,     6,    -1,   124,    93,   237,   289,   238,   269,
     340,     6,    -1,   124,    96,   237,   290,   238,   269,   340,
       6,    -1,   124,    98,   237,   291,   238,   269,   340,     6,
      -1,   132,   337,   241,   296,   242,    -1,   131,   241,   337,
     246,   337,   246,   326,   242,   241,   296,   242,    -1,   133,
     337,   241,   296,   242,    -1,   134,   241,   337,   246,   326,
     242,   241,   296,   242,    -1,   134,   241,   337,   246,   337,
     242,   241,   296,   242,    -1,     4,   241,   296,   242,    -1,
     149,    93,   241,   343,   242,    96,   241,   326,   242,    -1,
     146,    93,   237,   326,   238,   241,   343,   242,     6,    -1,
     297,    -1,   295,    -1,    -1,   297,   294,    -1,   297,    90,
     241,   343,   242,     6,    -1,   297,    93,   241,   343,   242,
       6,    -1,   297,    96,   241,   343,   242,     6,    -1,   297,
      98,   241,   343,   242,     6,    -1,   136,   121,   237,   326,
     238,     7,   340,     6,    -1,   136,    90,   237,   326,   238,
       7,   241,   339,   242,     6,    -1,   136,   121,   237,   326,
     238,     7,   241,   337,   246,   337,   246,   343,   242,     6,
      -1,   136,   121,   237,   326,   238,     7,   241,   337,   246,
     337,   246,   337,   246,   343,   242,     6,    -1,   136,    94,
     237,   326,   238,     7,   241,   337,   246,   343,   242,     6,
      -1,   136,   100,   237,   326,   238,     7,   241,   337,   246,
     337,   246,   343,   242,     6,    -1,   136,   101,   237,   326,
     238,     7,   241,   337,   246,   337,   246,   343,   242,     6,
      -1,   136,   103,   237,   326,   238,     7,   241,   337,   246,
     337,   246,   343,   242,     6,    -1,   136,   104,   237,   326,
     238,     7,   241,   337,   246,   337,   246,   343,   242,     6,
      -1,   136,     4,   237,   326,   238,     7,   340,     6,    -1,
     136,     4,   237,   326,   238,     7,     5,     6,    -1,   136,
       4,   241,   326,   242,     6,    -1,   147,   241,   297,   242,
      -1,   130,   147,   241,   297,   242,    -1,   147,   183,   239,
     326,   240,     6,    -1,   147,     4,   239,   326,   240,     6,
      -1,   147,   353,     6,    -1,   147,     4,     4,     6,    -1,
     147,    84,     6,    -1,   172,   344,   241,   297,   242,    -1,
     130,   172,   344,   241,   297,   242,    -1,   207,   326,   241,
     297,   242,    -1,   188,     5,     6,    -1,   189,     5,     6,
      -1,   188,   241,   297,   242,    -1,   130,   188,   241,   297,
     242,    -1,   189,   241,   297,   242,    -1,   130,   189,   241,
     297,   242,    -1,   353,   348,     6,    -1,    73,   237,   351,
     238,     6,    -1,   353,   353,   239,   326,   240,   347,     6,
      -1,   353,   353,   353,   239,   326,   240,     6,    -1,   353,
     326,     6,    -1,   128,   237,     4,   238,   243,     4,     6,
      -1,   166,     4,     6,    -1,   181,     6,    -1,   182,     6,
      -1,    70,     6,    -1,    71,     6,    -1,    64,     6,    -1,
      64,   241,   326,   246,   326,   246,   326,   246,   326,   246,
     326,   246,   326,   242,     6,    -1,    65,     6,    -1,    66,
       6,    -1,    78,     6,    -1,    79,     6,    -1,   113,     6,
      -1,   114,   241,   343,   242,   241,   343,   242,   241,   339,
     242,   241,   326,   246,   326,   242,     6,    -1,   186,   237,
     241,   343,   242,   246,   348,   246,   348,   238,     6,    -1,
     174,   237,   326,     8,   326,   238,    -1,   174,   237,   326,
       8,   326,     8,   326,   238,    -1,   174,     4,   175,   241,
     326,     8,   326,   242,    -1,   174,     4,   175,   241,   326,
       8,   326,     8,   326,   242,    -1,   176,    -1,   187,     4,
      -1,   187,   348,    -1,   184,    -1,   185,   353,     6,    -1,
     185,   348,     6,    -1,   177,   237,   326,   238,    -1,   178,
     237,   326,   238,    -1,   179,    -1,   180,    -1,   135,   337,
     241,   297,   242,    -1,   135,   241,   337,   246,   337,   246,
     326,   242,   241,   297,   242,    -1,   135,   241,   337,   246,
     337,   246,   337,   246,   326,   242,   241,   297,   242,    -1,
      -1,   135,   337,   241,   297,   307,   311,   242,    -1,    -1,
     135,   241,   337,   246,   337,   246,   326,   242,   241,   297,
     308,   311,   242,    -1,    -1,   135,   241,   337,   246,   337,
     246,   337,   246,   326,   242,   241,   297,   309,   311,   242,
      -1,    -1,   135,   241,   297,   310,   311,   242,    -1,   135,
     241,   297,   242,   127,   108,   241,   326,   242,    -1,   117,
     340,    -1,   122,   117,   340,    -1,   119,   241,   343,   242,
     241,   343,   242,   241,   326,   242,    -1,   312,    -1,   311,
     312,    -1,   152,   241,   326,   242,     6,    -1,   152,   241,
     340,   246,   340,   242,     6,    -1,   153,     6,    -1,   144,
       6,    -1,   144,   326,     6,    -1,   158,     6,    -1,   158,
     160,     6,    -1,   159,     6,    -1,   159,   160,     6,    -1,
     154,   237,   326,   238,     7,   340,   127,   326,     6,    -1,
     127,     4,   239,   326,   240,     6,    -1,   138,    -1,   139,
      -1,   140,    -1,   141,    -1,   142,    -1,    -1,   147,     6,
      -1,   130,   147,     6,    -1,   147,   326,     6,    -1,   130,
     147,   326,     6,    -1,   313,   241,   297,   314,   242,   241,
     297,   314,   242,    -1,   105,   237,   347,   238,    -1,   313,
     237,   326,   238,     7,   241,   297,   314,   242,   241,   297,
     314,   242,     6,    -1,    -1,   127,     4,   326,    -1,    -1,
       4,    -1,    -1,     7,   340,    -1,    -1,     7,   326,    -1,
      -1,   137,   340,    -1,   109,   110,   340,     7,   326,     6,
      -1,   123,    93,   341,     7,   326,   317,     6,    -1,   123,
      96,   341,   319,   318,     6,    -1,   123,    98,   341,   319,
       6,    -1,   161,   341,     6,    -1,   150,    96,   241,   343,
     242,     7,   326,     6,    -1,   144,    96,   341,   320,     6,
      -1,   144,    98,   341,     6,    -1,   145,    96,   341,     7,
     326,     6,    -1,   126,    93,   241,   343,   242,     7,   241,
     343,   242,   321,     6,    -1,   126,    96,   241,   343,   242,
       7,   241,   343,   242,   321,     6,    -1,   126,    93,   241,
     343,   242,     7,   241,   343,   242,   131,   241,   337,   246,
     337,   246,   326,   242,     6,    -1,   126,    96,   241,   343,
     242,     7,   241,   343,   242,   131,   241,   337,   246,   337,
     246,   326,   242,     6,    -1,   126,    93,   241,   343,   242,
       7,   241,   343,   242,   132,   337,     6,    -1,   126,    96,
     241,   343,   242,     7,   241,   343,   242,   132,   337,     6,
      -1,   126,    96,   326,   241,   343,   242,     7,   326,   241,
     343,   242,     6,    -1,    90,   241,   343,   242,   175,    96,
     241,   326,   242,     6,    -1,    93,   241,   343,   242,   175,
      96,   241,   326,   242,     6,    -1,    90,   241,   343,   242,
     175,    98,   241,   326,   242,     6,    -1,    93,   241,   343,
     242,   175,    98,   241,   326,   242,     6,    -1,    96,   241,
     343,   242,   175,    98,   241,   326,   242,     6,    -1,   151,
      96,   341,     6,    -1,   151,    93,   341,     6,    -1,   115,
      90,   341,     6,    -1,   115,    93,   341,     6,    -1,   115,
      96,   341,     6,    -1,   129,    93,   340,     6,    -1,   125,
      93,   340,     6,    -1,   125,    96,   340,     6,    -1,   125,
      98,   340,     6,    -1,   148,     6,    -1,   148,     4,     6,
      -1,   148,    90,   241,   343,   242,     6,    -1,   196,    -1,
     197,    -1,   198,    -1,   324,     6,    -1,   324,   241,   340,
     242,     6,    -1,   324,   241,   340,   246,   340,   242,     6,
      -1,   324,   237,   340,   238,   241,   340,   246,   340,   242,
       6,    -1,   327,    -1,   237,   326,   238,    -1,   226,   326,
      -1,   225,   326,    -1,   232,   326,    -1,   326,   226,   326,
      -1,   326,   225,   326,    -1,   326,   227,   326,    -1,   326,
     228,   326,    -1,   326,   230,   326,    -1,   326,   231,   326,
      -1,   326,   229,   326,    -1,   326,   236,   326,    -1,   326,
     219,   326,    -1,   326,   220,   326,    -1,   326,   224,   326,
      -1,   326,   223,   326,    -1,   326,   218,   326,    -1,   326,
     217,   326,    -1,   326,   216,   326,    -1,   326,   215,   326,
      -1,   326,   221,   326,    -1,   326,   222,   326,    -1,   326,
     214,   326,     8,   326,    -1,    16,   271,   326,   272,    -1,
      17,   271,   326,   272,    -1,    18,   271,   326,   272,    -1,
      19,   271,   326,   272,    -1,    20,   271,   326,   272,    -1,
      21,   271,   326,   272,    -1,    22,   271,   326,   272,    -1,
      23,   271,   326,   272,    -1,    24,   271,   326,   272,    -1,
      26,   271,   326,   272,    -1,    27,   271,   326,   246,   326,
     272,    -1,    28,   271,   326,   272,    -1,    29,   271,   326,
     272,    -1,    30,   271,   326,   272,    -1,    31,   271,   326,
     272,    -1,    32,   271,   326,   272,    -1,    33,   271,   326,
     272,    -1,    34,   271,   326,   272,    -1,    35,   271,   326,
     272,    -1,    36,   271,   326,   246,   326,   272,    -1,    37,
     271,   326,   246,   326,   272,    -1,    38,   271,   326,   246,
     326,   272,    -1,    25,   271,   326,   272,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   203,    -1,
     204,    -1,   205,    -1,    75,    -1,    76,    -1,    77,    -1,
      -1,    83,   271,   326,   328,   281,   272,    -1,   331,    -1,
     194,   271,   347,   272,    -1,   194,   271,   347,   246,   326,
     272,    -1,   333,    -1,   353,   239,   326,   240,    -1,   353,
     237,   326,   238,    -1,   199,   237,   333,   238,    -1,   199,
     237,   333,   243,   334,   238,    -1,   201,   237,   333,   329,
     238,    -1,   201,   237,   333,   243,   334,   329,   238,    -1,
     200,   237,   348,   238,    -1,   244,   353,   271,   272,    -1,
     244,   353,     9,    -1,   244,     9,    -1,   353,   270,    -1,
     353,   239,   326,   240,   270,    -1,   353,   237,   326,   238,
     270,    -1,   353,   243,   334,    -1,   353,     9,   353,   243,
     334,    -1,   353,   239,   326,   240,   243,     4,    -1,   353,
     243,     4,   270,    -1,   353,   239,   326,   240,   243,     4,
     270,    -1,   190,   237,   347,   246,   326,   238,    -1,    56,
     237,   340,   246,   340,   238,    -1,    57,   271,   347,   246,
     347,   272,    -1,    55,   271,   347,   272,    -1,    58,   271,
     347,   246,   347,   272,    -1,    63,   237,   351,   238,    -1,
      -1,   246,   326,    -1,    -1,   246,   347,    -1,    -1,    84,
     333,   336,   332,   239,   282,   240,    -1,   353,    -1,   353,
       9,   353,    -1,     4,    -1,    86,    -1,    86,   326,    -1,
      -1,   237,   335,   238,    -1,   338,    -1,   226,   337,    -1,
     225,   337,    -1,   337,   226,   337,    -1,   337,   225,   337,
      -1,   241,   326,   246,   326,   246,   326,   246,   326,   246,
     326,   242,    -1,   241,   326,   246,   326,   246,   326,   246,
     326,   242,    -1,   241,   326,   246,   326,   246,   326,   242,
      -1,   237,   326,   246,   326,   246,   326,   238,    -1,   340,
      -1,   339,   246,   340,    -1,   326,    -1,   342,    -1,   241,
     242,    -1,   241,   343,   242,    -1,   226,   241,   343,   242,
      -1,   326,   227,   241,   343,   242,    -1,   340,    -1,     5,
      -1,   226,   342,    -1,   326,   227,   342,    -1,   326,     8,
     326,    -1,   326,     8,   326,     8,   326,    -1,    90,   241,
     326,   242,    -1,    90,     5,    -1,    93,     5,    -1,    96,
       5,    -1,    98,     5,    -1,   124,    90,   341,    -1,   124,
      93,   341,    -1,   124,    96,   341,    -1,   124,    98,   341,
      -1,    90,   175,    64,   241,   326,   246,   326,   246,   326,
     246,   326,   246,   326,   246,   326,   242,    -1,    93,   175,
      64,   241,   326,   246,   326,   246,   326,   246,   326,   246,
     326,   246,   326,   242,    -1,    96,   175,    64,   241,   326,
     246,   326,   246,   326,   246,   326,   246,   326,   246,   326,
     242,    -1,    98,   175,    64,   241,   326,   246,   326,   246,
     326,   246,   326,   246,   326,   246,   326,   242,    -1,   295,
      -1,   306,    -1,   315,    -1,   353,   271,   272,    -1,    39,
     239,   353,   240,    -1,    39,   239,   342,   240,    -1,    39,
     237,   342,   238,    -1,    39,   271,   241,   343,   242,   272,
      -1,   353,   271,   241,   343,   242,   272,    -1,    40,   271,
     326,   246,   326,   246,   326,   272,    -1,    41,   271,   326,
     246,   326,   246,   326,   272,    -1,    42,   271,   347,   272,
      -1,    43,   271,   326,   246,   326,   246,   326,   246,   326,
     246,   326,   246,   326,   272,    -1,   195,   271,   342,   272,
      -1,    32,   271,   342,   272,    -1,   326,    -1,   342,    -1,
     343,   246,   326,    -1,   343,   246,   342,    -1,   241,   326,
     246,   326,   246,   326,   246,   326,   242,    -1,   241,   326,
     246,   326,   246,   326,   242,    -1,   353,    -1,     4,   243,
     172,   243,     4,    -1,   241,   346,   242,    -1,   353,   239,
     326,   240,   243,   173,    -1,   344,    -1,   346,   246,   344,
      -1,   348,    -1,   353,    -1,   353,   239,   326,   240,    -1,
     353,   237,   326,   238,    -1,   353,   243,   334,    -1,   353,
       9,   353,   243,   334,    -1,   353,   239,   326,   240,   243,
       4,    -1,   124,    90,   241,   326,   242,    -1,   124,    93,
     241,   326,   242,    -1,   124,    96,   241,   326,   242,    -1,
     124,    98,   241,   326,   242,    -1,     5,    -1,   208,   239,
     353,   240,    -1,    67,    -1,   206,    -1,    72,    -1,    74,
      -1,   192,   237,   347,   238,    -1,   191,   237,   347,   246,
     347,   238,    -1,   193,   271,   347,   272,    -1,   193,   271,
     347,   246,   347,   272,    -1,   202,   237,   333,   330,   238,
      -1,   202,   237,   333,   243,   334,   330,   238,    -1,    48,
     271,   351,   272,    -1,    49,   237,   347,   238,    -1,    50,
     237,   347,   238,    -1,    51,   237,   347,   246,   347,   246,
     347,   238,    -1,    46,   271,   351,   272,    -1,    60,   271,
     347,   272,    -1,    61,   271,   347,   272,    -1,    62,   271,
     347,   272,    -1,    59,   271,   326,   246,   347,   246,   347,
     272,    -1,    54,   271,   347,   246,   326,   246,   326,   272,
      -1,    54,   271,   347,   246,   326,   272,    -1,    47,   271,
     347,   272,    -1,    47,   271,   347,   246,   343,   272,    -1,
      68,   271,   347,   272,    -1,    69,    -1,    53,   271,   347,
     272,    -1,    52,   271,   347,   272,    -1,    -1,    87,   271,
     348,   349,   285,   272,    -1,    85,   271,   350,   272,    -1,
     244,   326,    -1,   353,     9,   244,   326,    -1,   347,    -1,
     351,   246,   347,    -1,     4,   245,   241,   326,   242,    -1,
     352,   245,   241,   326,   242,    -1,   209,   239,   347,   240,
     245,   241,   326,   242,    -1,     4,    -1,   352,    -1,   209,
     239,   347,   240,    -1
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
    2299,  2314,  2331,  2348,  2383,  2405,  2429,  2430,  2435,  2438,
    2442,  2453,  2464,  2475,  2491,  2510,  2531,  2546,  2562,  2580,
    2631,  2652,  2674,  2697,  2802,  2818,  2853,  2864,  2875,  2881,
    2896,  2924,  2936,  2945,  2952,  2964,  2983,  2989,  2995,  3002,
    3009,  3016,  3028,  3101,  3119,  3136,  3151,  3184,  3196,  3220,
    3224,  3229,  3236,  3241,  3251,  3256,  3262,  3270,  3274,  3278,
    3287,  3351,  3367,  3384,  3401,  3423,  3445,  3480,  3488,  3496,
    3502,  3509,  3516,  3536,  3562,  3574,  3586,  3604,  3622,  3641,
    3640,  3665,  3664,  3691,  3690,  3715,  3714,  3737,  3753,  3770,
    3787,  3810,  3813,  3819,  3831,  3851,  3855,  3859,  3863,  3867,
    3871,  3875,  3879,  3888,  3901,  3902,  3903,  3904,  3905,  3909,
    3910,  3911,  3912,  3913,  3916,  3939,  3958,  3980,  3983,  3999,
    4002,  4019,  4022,  4028,  4031,  4038,  4041,  4048,  4065,  4106,
    4150,  4189,  4214,  4223,  4253,  4279,  4305,  4337,  4364,  4390,
    4416,  4442,  4468,  4490,  4496,  4502,  4508,  4514,  4520,  4546,
    4572,  4589,  4606,  4623,  4635,  4641,  4647,  4659,  4663,  4673,
    4684,  4685,  4686,  4690,  4696,  4708,  4726,  4754,  4755,  4756,
    4757,  4758,  4759,  4760,  4761,  4762,  4769,  4770,  4771,  4772,
    4773,  4774,  4775,  4776,  4777,  4778,  4779,  4780,  4781,  4782,
    4783,  4784,  4785,  4786,  4787,  4788,  4789,  4790,  4791,  4792,
    4793,  4794,  4795,  4796,  4797,  4798,  4799,  4800,  4801,  4802,
    4803,  4804,  4805,  4806,  4815,  4816,  4817,  4818,  4819,  4820,
    4821,  4822,  4823,  4824,  4825,  4830,  4829,  4837,  4839,  4844,
    4849,  4853,  4871,  4889,  4893,  4897,  4901,  4905,  4911,  4927,
    4933,  4939,  4958,  4979,  5012,  5016,  5021,  5026,  5036,  5046,
    5051,  5062,  5071,  5076,  5081,  5109,  5110,  5116,  5117,  5123,
    5122,  5145,  5147,  5152,  5161,  5163,  5169,  5170,  5176,  5180,
    5184,  5188,  5192,  5199,  5203,  5207,  5211,  5218,  5223,  5230,
    5235,  5239,  5244,  5248,  5256,  5267,  5271,  5283,  5291,  5299,
    5306,  5316,  5339,  5345,  5351,  5357,  5363,  5374,  5385,  5396,
    5407,  5413,  5419,  5425,  5431,  5441,  5451,  5461,  5474,  5486,
    5490,  5494,  5498,  5516,  5524,  5532,  5561,  5571,  5587,  5598,
    5603,  5607,  5611,  5623,  5627,  5639,  5656,  5666,  5670,  5685,
    5690,  5697,  5701,  5706,  5720,  5737,  5741,  5746,  5754,  5760,
    5766,  5772,  5781,  5785,  5789,  5797,  5803,  5809,  5813,  5821,
    5829,  5836,  5846,  5851,  5856,  5871,  5885,  5899,  5911,  5927,
    5936,  5945,  5955,  5966,  5974,  5982,  5986,  6005,  6012,  6018,
    6025,  6033,  6032,  6042,  6066,  6068,  6074,  6079,  6087,  6096,
    6105,  6117,  6120,  6124
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
      26,    27,     0,     0,     0,     0,     0,   463,   535,    29,
       0,     0,   243,   577,    74,   112,    75,   122,   465,   467,
     128,     0,     0,     0,     0,   521,   522,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   413,
     400,     0,   402,   403,   404,   405,   406,   518,   407,   408,
     409,     0,     0,     0,   510,   509,   508,     0,     0,     0,
     515,     0,   452,     0,     0,     0,   454,   126,     0,   491,
       0,     0,     0,     0,     0,   428,   517,   433,     0,   437,
       0,     0,     0,   483,     0,   438,     0,     0,     0,     0,
     432,   431,   447,     0,     0,     0,     0,     0,   368,   317,
     322,   320,     0,   330,     0,     0,     0,     0,     0,     0,
       0,     0,   368,   368,   368,     0,     0,     0,     0,   227,
       0,   239,   241,     0,     0,     0,   198,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,   558,     0,   565,   554,   555,
     556,     0,   570,   569,     0,     0,   559,   560,   561,   567,
     574,   573,     0,   136,     0,   548,     0,   550,     0,     0,
       0,   543,     0,   235,     0,     0,     0,   310,     0,     0,
       0,   364,     0,   579,     0,     0,     0,     0,   101,    63,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
      61,     0,    39,    40,    41,    42,    43,     0,   432,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      -1,     2,     3,   108,  1022,   109,   110,  1003,  1804,  1810,
    1282,  1490,  1950,  2091,  1283,  2056,  2115,  1284,  2093,  1285,
    1286,  1494,   403,   553,   554,  1086,   111,   731,   424,  1814,
    1960,  1815,   425,  1696,  1353,  1310,  1311,  1312,  1453,  1645,
    1646,   868,   871,   874,   877,  1541,  1531,   715,   251,   412,
     413,   114,   115,   116,   117,   118,   119,   120,   121,   252,
    1182,  1984,  2047,   905,  1178,  1179,   253,   980,   254,   125,
    1379,  1142,   866,   919,  1920,   126,   127,   128,   129,   255,
     256,  1107,  1122,  1240,   257,   736,   258,   856,   735,   427,
     585,   291,  1676,   326,   327,   260,   526,   334,  1270,  1483,
     422,   418,  1233,   962,   423,   131,   382
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1766
static const yytype_int16 yypact[] =
{
    9906,    94,   124, 10055, -1766, -1766,   -77,    14,   -40,  -169,
     -99,    29,   155,   165,   212,   227,     4,   251,   283,    67,
      81,    22,  -156,  -156,    88,    99,   109,    12,   112,   168,
      18,   177,   205,   210,   215,   222,   267,   324,   338,   339,
     349,   362,   281,   508,   321,    16,   372,  5747,   373,   380,
     552,   -37,    30,   574,   540,   103,   398,   561,   -86,   419,
      -2,    -2,   425,   186,   434, -1766, -1766, -1766, -1766, -1766,
     443,   326,   587,   630,    10,    54,   638,   641,   202,   738,
     745,   746,  5042,   752,   473,   549,   577,    20,    50, -1766,
     592,   600, -1766, -1766,   795,   816,   591, -1766, 10250,   613,
   10280,    15,    33, -1766, -1766, -1766,  9737,   619, -1766, -1766,
   -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766,
   -1766, -1766, -1766,    96, -1766, -1766, -1766, -1766,    49, -1766,
     858,   647,  4805,   322,   652,   904,  9737, 10221, 10221, -1766,
    9737, -1766, -1766, -1766, -1766, 10221, -1766, -1766, -1766, -1766,
     683,   686,   920, -1766, -1766, 10309,    22,  9737,  8887,  9737,
    9737,   712,  9737,  8887,  9737,  9737,   726,  9737,  8887,  9737,
    9737,  9737,  9737,  9737,  9737, 10221,  9737,  9737,  9737,  5982,
     727, -1766,  8887,  5042,  5042,  5042, 10221, -1766, -1766, -1766,
   -1766, -1766,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,   454,  -156,  -156,  -156,  -156,
    -156,   729,  -156,  -156,   732, -1766, -1766, -1766,  -156,    28,
      31,    46,    52,  5982,   845,   581,   733,  -156,  -156,   734,
     735,   736, -1766, -1766, -1766,  9737,  6217,  9737,  9737,  6452,
      23, -1766, -1766,   737, -1766,  4272, -1766, -1766, -1766, -1766,
   -1766,   105,  9737,  8887,   739,   740,  6687,  5042,  5042,  5042,
     744,   747,   750,   751,  6922,  7157,  7392,   741,   742,   971,
    5982,   749,    20,   754,   755,    -2,    -2,    -2,  9737,  9737,
     -34, -1766,    89,    -2,  4070,   157,   117,   756,   760,   763,
     764,   765,   766,   773,  9737,  5042,  5042,  5042,   774,     9,
     979,   775, -1766,   983,  1009, -1766,   776,   777,   782,  5042,
    5042,   785,   786,   787, -1766,  9737, -1766,  1010,  1021,  9737,
    9737,  9737,   453,  9737,   788, -1766,   853,  9737,  9737,  9737,
   -1766, -1766,  9737, -1766,  -156,  -156,  -156,   793,   796,   797,
    -156,  -156,  -156,  -156,  -156,  -156,  -156, -1766,  -156, -1766,
   -1766, -1766,  -156,  -156,   799,   804,  -156,   805, -1766,   807,
    1026,  1037,   810, -1766, -1766,  1042, -1766,  1047, -1766,  -156,
    9737, 12849,   118, 10221,  9737, -1766, -1766,  5982,  5982, -1766,
     825, 10309,   622,  1060, -1766, -1766, -1766, -1766, -1766, -1766,
    9737,  9737,    36,  5982,  1062,   554,   868,   828,  1065,    41,
     832, -1766,   833,  9732,  9737, -1766,  1512,  -168, -1766,   108,
    -164,  8366, -1766,  -127,   -46,   -12,   988, -1766,    22,   830,
     831, 13311,  8887,  4506, -1766,   150, 13336, 13361,  9737, 13386,
     151, 13411, 13436,  9737, 13461,   235, 13486, 13511, 13536, 13561,
   13586, 13611,   840, 13636, 13661, 13686,  1072,  9737,   243,  1074,
    1097,  1116,   885,  9737,  9737,  9737,  9737,  9737,  9737,  9737,
    9737,  9737,  9737,  9737,  9737,  9737,  9737,  9737,  9737,  8887,
    9737,  9737,  9737,  9737,  9737,  9737,  8887,  8887,   883,  9737,
    9737, 10221,  9737, 10221,  5982, 10221, 10221, 10221,  9737, -1766,
    1063,  9737, -1766,  1064, -1766,  1066, -1766,  1087,  5982,  5042,
    5042,  5042,  5042, 10221, 10221,  8887,    22, 10309,    22,   890,
    8887,   890, -1766,   890, 13711, -1766,   255, -1766,    68,  9737,
    9737,  9737,  9737,  9737,  9737,  9737,  9737,  9737,  9737,  9737,
    9737,  9737,  9737,  7627,  9737,  9737,  9737,  9737,  9737,    22,
    9737,  9737,  1125, -1766,   646, 13736,   423,  9737,  9737,  9737,
   -1766,  1145,  1146,  1146,  9117,  9117,  9117,  9117,  9737,  1148,
    9737,  1151,  9737,  1152,  8887,  8887, 12877,   926,  1159, -1766,
     925, -1766, -1766,  -150, -1766, -1766,  9463,  9662,    -2,    -2,
     322,   322,  -133,  4070,  4070,  9737,  5109,   -76, -1766,  9737,
    9737,  9737,  9737,  9737,  9737,  9737,  9737,  9737, 13761,  1160,
    1162,  1163,  9737,  1166,  9737, -1766,  9737,  5344, -1766, -1766,
    8887,  8887,  8887,  1167,  1182,  9737,  9737,  9737, 13786, -1766,
   -1766, 13811, 13836, 13861,  1018, 10304, -1766,   950,  4680, 13886,
   13911, 12960, 10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221,
   10221,  9737, 10221, 10221, 10221, 10221,     8, 10309, 10221, 10221,
   10221,    22,    22, -1766, -1766,  8887, -1766,  5579, -1766,  5814,
    9737,   890,  9737, -1766,  9737,  9737,   953, 13936,  8164,   957,
     501,  9737,  1188,   955,   958,   959,   965,  9737, 13961, 12987,
     152,   954,  1191,  1201, -1766, -1766, -1766,  8887,   191, -1766,
   -1766, -1766,    22,  9737,  9737,  1125,   969, -1766,   196,    21,
      44,   507,   972,   -32,   580, -1766,  7760, -1766,    17,  8887,
      22,  9737,  9737,  1207,  1206,  8887,  9737,  1208, 10221,  1209,
   -1766,    22,  1210, 10221,  9737,   981,   978, -1766,  9737, 10309,
    1213,  8887,  1046,  8887,  1216,  1218, 13986,  1219,  1052,  1221,
    1222, 14011,  1223,  1057,  1227,  1228,  1230,  1231,  1232,  1233,
   -1766,  1234,  1235,  1236,  9737, 14036,  1003, -1766, -1766, -1766,
    1239, 12933, 12933, 12933, 12933, 12933, 12933, 12933, 12933, 12933,
   12933, 12933, 10337, 12933, 12933, 12933, 12933,  1305,   544, 12933,
   12933, 12933, 10370, 10403, 10436,  4506,  1008,  1011,    57,  8887,
   10469, 10502,   544, 10535,   544,  1004,  1006,  1007,  -105, 14786,
    1013, 11921,  1014,  1016,  1017, -1766, -1766, -1766, -1766,  1015,
     -95,   544,   -91,  1022,   223,   509,  1242, -1766, -1766,   544,
    4730,  7563,   889,  1107,   956,   956,   459,   459,   459,   459,
     459,   459,   375,   375,  8887,   478, -1766,   478,   478,   890,
     890,   890,  1019, 14061, 13014,  -193, -1766,  8887, -1766,  1252,
    1023, 14086, 14111, 14136,  9737,  5982,  1259,  1261,  1027, 14786,
    1024,  1030, 14786,  1025,  1031, 14786,  1029,  1035, 14786,  1032,
   14161, -1766, 14186, -1766, 14211, -1766,   539,   541,  8887,  1033,
   -1766,  6049, -1766,  6284,  6519,    -2,  9737,  9737, -1766, -1766,
    1038,  1039,  4070,  4754,  1155,   292,    -2,  6754, 14236, 11950,
   14261, 14286, 14311, 14336, 14361, 14386, 14411,  1272,  9737,  1277,
   -1766,  9737, 14436, -1766, 13041, 13068, -1766,   547,   562,   564,
   -1766, -1766, 13095, 13122, 10568, -1766,  1280,  1281,  1282,  1041,
    9737,  6989,  9737,  9737, -1766, -1766,    40,   224,   465,   224,
    1053,  1054,  1044,   544,   544,  1048, 10601,   544,   544,   544,
     544,  9737,   544,  1284, -1766,  1049,  1059,   481,   290,  1058,
     567, -1766, -1766, 12933,   478,  7224,  1055,  1292,  1154,  9202,
    1061,  1067,  1296,  5982, 11979, -1766,  9737,  9737,  9737,  9737,
    1715,   156,   100, 10309,  9737,  1298,  1301,    27, -1766,   569,
    1263,  1264,  5982,    25,  1068, 14461, 13149,  1071,  9737,  8887,
    8887,  8887,  8887,  9737,  1070,  1077,  1078,  1079, -1766, -1766,
   -1766, -1766, 10221,   -84,  1075, 14486, 13176, -1766, -1766, -1766,
     -80, 10634, -1766, -1766, -1766,    62, -1766, -1766, 14786, -1766,
    1315, 12933,   544,    -2,   725,  4506, -1766,  5982,  5982,  1313,
    5982,   748,  5982,  5982,  1314,  5982,  1224,  5982,  5982,  5982,
    5982,  5982,  5982,  5982,  5982,  5982,  1775,  1332,  8887, -1766,
   -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766,
   -1766,  9737, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766,
   -1766,  9737,  9737,  9737, -1766, -1766, -1766,   570,  9737,  9737,
   -1766,  9737, -1766,  5982, 10221, 10221, -1766,  1094,  9737, -1766,
    9737,  9737,  9737,  9737,  9737, -1766, -1766, -1766,  1207, -1766,
    1207,  9737,  1112, -1766,  5982, -1766,  9737,  9737,   578,  1207,
    -193,   -33, -1766,   585,  5982,  8887,  1338,  1353,  1354,  3237,
   -1766, -1766,  1356, -1766,   197,  9737,   197,  9737,   197,  9737,
     197,  9737,  1357,  1358,  1359,  1360,  1361,   586,  1365, -1766,
    7459, -1766, -1766,   -69, 10667, 10700, -1766, -1766, 12008,  -138,
    1255,  1366,  9432,  1130,  1369,  1139,    37,    56,   -22, -1766,
     -41, -1766,   292,  1370,  1373,  1374,  1376,  1378,  1382,  1383,
    1384,  1385,  5982, 14786, -1766,  2048,  1153,  1387,  1389,  1392,
    1303,  1393,  1395,  1396,  9737,  5982,  5982,  5982,  1400, 10733,
   -1766,  7737,  1641,  1401,  1402, -1766,  8887, -1766, -1766, -1766,
   -1766, 10221, -1766, -1766,  9737, 10221, -1766, -1766, -1766, -1766,
   14786, -1766,  1164,  1161, 10221, -1766, 10221, -1766,  1207, 10221,
    1171, -1766,  1165, -1766,  1169,  1172,  9507, -1766,  2371,  1174,
    5982, -1766,  1170, -1766, 12037, 12066, 12095, 12124, -1766, -1766,
    9737,  1410,    42,  9737,  1411,  1413,  2779, -1766,  1414,    20,
    1417,  1181,   544,  -156,  -156,  1420, -1766,  1190,  1192,  1189,
   -1766,  1425, -1766, -1766, -1766, -1766, -1766,  1207,   140,   829,
   13203,   593,   594,   596,   601, 14511,  9737,  9737,  9737,  9737,
    1426,    24,  1207, -1766,  1193,  1427,  9737,  7862,   544,  4335,
    1194,  1195, -1766,  1429,  1431,   102,  1197,  1198,  1319,  1319,
    5982,  1436,  1202,  1203,  1439,  1441,  5982,  1273,  1211,  1443,
    1445,  1466,  1467,  1468,  1469,  1471,  1473,  1474, -1766,  1478,
     606, 12933, 12933, 12933, 12933,   544, 10766, 10799, 10832,  1249,
     544,   544,  1315,   544, 10865, 10898, 10931, 10964, 14536, 12933,
    1250,  1243, 14786, -1766,  1485, 14786, 14786, -1766, -1766, -1766,
    1488, -1766,   544,  1487,   607,  5982,  5982,  5982,  1490,  1489,
   -1766,  5982, 14786,  5982, 14786,  5982, 14786,  5982, 14786,  5982,
    5982,  5982,  1256,  1257,  1495,   480, -1766,  9737,  9737,  9737,
    1262,  1265,  1266,  1270, -1766,  3021,  5982, -1766,  9737, -1766,
    1498, -1766,  1499, -1766, -1766,  4070,   395,  5277, -1766,  1269,
    1271,  1274,  1275,  1297,  1299,  8097,  1505, -1766,  8887, -1766,
   -1766, -1766,  1306,  9737, -1766, -1766, 13230,  1508,  1531,  1325,
   -1766,  9737,  9737,  9737, -1766,  1533,   519,   486,  1300,  3745,
    1302,  9737,    35,   544,  1304,   544,  1308, -1766, -1766, 10309,
    9737, -1766, -1766,  3051, -1766, -1766,  1309,  1543, -1766, -1766,
   -1766, -1766,  3116, -1766,   160,  1307,  1544,  3437, -1766, -1766,
   -1766,    20, -1766,   609, -1766,  9737,   197,  2701, 10221, -1766,
    1320,  9737,  9737,  5982,  1311, -1766,  1317,  1552,  1553,  1554,
    1556,  1557,  1558,  1559,  1242, 14561, 14586, 14611, 14636, -1766,
   -1766, 10221, -1766,  1562, -1766, 10997,  4570, 14786, -1766,  1560,
    6452, -1766, -1766, -1766,  1315, -1766, -1766, -1766,  9737,  9737,
      -2,  1563,  1564,  1565, -1766,  9737,  9737, -1766, -1766,  1566,
    1480,  1569,  9737, -1766, -1766, -1766, -1766, -1766, -1766, -1766,
   -1766, -1766,  1572,  1337, -1766, -1766, -1766, -1766, -1766,  9737,
    9737,  9737, -1766, -1766, -1766,  1195, -1766,  9737,  9737,  9737,
    9737, -1766, -1766, -1766,  1341, -1766,  -193, -1766, -1766,  1339,
    1575,  1273,  1576,  9737, -1766,  1577,  1578,  1579,  1580,  1581,
     933,  1582,  8887,  8887,  9737, -1766,  9117, 12153, 14661,  8823,
     322,   322,  9737,  9737, -1766,   919,  1345, 14686, -1766, -1766,
   12182,   153, -1766,  1586,  1588,  5982,    -2,    -2,    -2,    -2,
      -2,  5512,  1589, -1766,   614,  9737,  3523,  1590, -1766, -1766,
    5982,  9148,  1240, 14711, -1766, -1766,  8332, -1766, 10221,  9737,
   -1766, 10221, 14786,  8417, 10309,  1351, -1766, -1766, -1766, -1766,
    1362,  1352, 12211,  8164, -1766,  8164,  5982, -1766, -1766, 10309,
    9737,  1593,  1598,    27, -1766,  1599, -1766,    20, 13257,  5982,
    1605,   224,   224,  9737, 11030, 11063,   615, -1766,  9737,   332,
   -1766, -1766, -1766, -1766, -1766, -1766,  1354,  1357,  1358,  1359,
    1607, -1766,  9737, -1766, -1766,  1363,   617,  4022,  1608, -1766,
   12240, 12269,   325, -1766, -1766, -1766, 12298, 12327, -1766,  1375,
   -1766, 12356,  1612,  5982, 12933, 12933, 11096, 11129, 11162, 11195,
   11228, -1766, -1766,  9737, -1766,  1613, -1766, 14786, -1766, -1766,
   -1766, -1766, -1766,  1380, -1766, -1766,   625,   626, 12905,  3639,
    1616,  1388, -1766, -1766,  9737,  1381,  1386, 12385, 13284,  1619,
    5982,  1623,  1390,  9737, -1766, -1766,   627,   195,   214,   232,
     249,   254,  8652,   273, -1766,  1620, 12414, -1766, -1766,  1462,
   -1766,  9737,  9737, -1766, -1766,  8887,  3675,  1627,  1398, 12933,
     544, 10221, 14786, -1766, -1766,    35, -1766, 10309, -1766,  1397,
    1399,  1403,  1628,  3796, -1766,  1630,  1634, -1766, -1766,  1404,
    1636, -1766,  1637,  1638,   -60, 14786,  9737,  9737,  1405,  5982,
     653, 14786, -1766, 11261,  1094,  1161,  5982, -1766,  9737, 10309,
      22,  1642,  1644,  1645,  1646,  9737,  1655,  1656,   658, -1766,
   -1766,  9737,  9737,  9737,  9737,  9737, 12443, -1766,  5982,   602,
     604,  8887, -1766, -1766,   322,  9378, -1766, -1766, -1766,  1657,
   -1766,  1423,  5982, -1766, 12472,  1661,  8887,    -2,    -2,    -2,
      -2,    -2, -1766, -1766,  9737, 12501, 12530,   660, -1766, -1766,
   -1766, -1766, -1766,   663, -1766,  1430,  1432, -1766,  1666, -1766,
   -1766,    20, -1766,  1501, -1766, -1766, -1766, -1766,  9737, 11294,
   11327,  5982, -1766,  1670,  9737,  9737,  1438,  1440, -1766,  4105,
   -1766,  1450, -1766, -1766, -1766, -1766, 12559, -1766, -1766,  1437,
   11360, 11393, 11426, 11459, 11492, -1766,   665,  1447,    -2,  5982,
    1683,  1449,    -2,  1685,   666,  1451, -1766,  9737, -1766,  1686,
    1567,  7914,  1454, -1766,   671,   277,   295,   317,   319,   331,
    3943, -1766, -1766,  1690, -1766,  1691, -1766, -1766,  1692, -1766,
    1458, 14786,  9737,  9737,   673, -1766, 14786, 11525, -1766, -1766,
    1094, 10309,  1463, -1766,  9737,  9737,  9737,  9737,  9737,  9737,
    1696,    -2,   134, -1766, -1766,    -2,   163, -1766,  1697, -1766,
   12588, -1766,  9737, -1766,   292, -1766,  1698,  8887,  8887,  8887,
    8887,  8652, -1766, -1766, -1766,  8164, -1766,  9737, 14736, 11558,
      47,  9737,  1464, -1766, -1766, 11591, 11624, 11657, 11690, 11723,
   11756, -1766,   333, -1766,   366, -1766, -1766, -1766,  3993,   471,
    8719, -1766,   676,   678,   679,   684,   374,   689,  1465,   692,
   -1766,  9737, -1766,  5982, 12617, -1766,  9737,  9737,  9737,  9737,
    9737,  9737,    -2,    -2, -1766, -1766, -1766,   292,  1699,  1702,
    1703,  1706,  8887,  1707,  1708,  1709,  1475, 14761,   706,  1711,
   12646, 12933, 11789, 11822, 11855, 11888,   382,   388,   548, -1766,
   -1766, -1766, -1766,   708, -1766, -1766, -1766, 10221, -1766,  1477,
   -1766,  1714, -1766,  9737,  9737,  9737,  9737,  9737,  9737, -1766,
    1716,   713, -1766,  1482,  5982, -1766, 12675, 12704, 12733, 12762,
   12791, 12820, -1766,  1718, 10221, 10221,   714, -1766, -1766, -1766,
   -1766,  1738,  1739, -1766, -1766,   719, -1766,  1740, -1766, -1766,
    1743, 10221, -1766, -1766, -1766
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1766, -1766, -1766, -1766,   449, -1766, -1766, -1766, -1766,  -246,
   -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766,
   -1766, -1766,  -683,  -126,  1956,  2362, -1766,  1328, -1766, -1766,
   -1766, -1766, -1766, -1766, -1765, -1766,   402,   231,   -59, -1766,
     -28, -1766, -1766, -1766, -1766,   179,   439,  1758,     6,  -588,
    -260, -1766, -1766, -1766, -1766, -1766, -1766, -1766, -1766,  1759,
   -1766, -1766, -1766, -1766, -1177, -1174,  1760, -1645,  1761, -1766,
   -1766, -1766,  1204, -1766,   -75, -1766, -1766, -1766, -1766,  1957,
   -1766, -1766,   405,   312,  1766, -1766,     0,  -686, -1766, -1766,
      38, -1766, -1598,   294,   -94,  2215,  2460,  -271,   107, -1766,
     -65,   -35, -1766, -1766,  -496, -1766,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -538
static const yytype_int16 yytable[] =
{
     132,   808,   900,   901,  1414,  1416,   404,   994,  1789,   113,
    1790,   580,   150,   613,   309,  1002,   161,  1756,   152,  1007,
     375,   151,   166,  1019,   332,   161,   150,   150,   135,  1276,
    1510,   150,   527,   499,   596,   139,   502,  1028,   377,  1643,
     690,   398,   399,  1409,   261,   150,  1474,  1213,   166,  1896,
     702,   504,   617,  2032,   336,   386,   136,   506,   314,   265,
     315,   281,  1411,   370,   265,   374,   549,   407,   137,  1307,
     718,   313,   417,   420,   724,   588,   589,   828,   719,   261,
     266,   153,   725,   154,   335,  1014,   282,   588,   589,   459,
     460,   461,   588,   589,   310,   371,   895,   408,   290,   292,
       4,   295,   283,   284,  1401,  1171,   183,  1259,  1527,   184,
     452,   727,   185,   902,   549,  1828,   667,   720,   669,   728,
     429,   462,  1172,   267,     5,   678,   268,   549,   269,   409,
    1173,  1174,  1175,  1106,   419,   419,  1176,  1177,   138,   411,
    2013,   728,   419,   695,   316,   696,   947,  1117,   949,   588,
     589,  1114,  1118,   430,  1301,   261,   588,   589,  1305,   993,
     261,   141,   743,  1259,   133,   261,   743,  1659,   134,  2015,
     906,   142,   419,   561,   562,   563,   261,  1397,  1887,   261,
     261,   261,   261,   419,   588,   589,  1888,  1277,  1278,  1279,
    1280,   588,   589,   311,   729,  2002,   277,  1410,  1000,   278,
     730,   398,   399,   500,  1259,  1415,   503,   590,   691,   692,
    1370,   609,   610,   611,  1475,  1476,  1412,   107,   143,   107,
    1413,   505,  1644,   286,   287,   623,   624,   507,   732,   107,
     261,   107,   107,   144,   730,   288,   107,  1020,  1021,   289,
    1916,   145,  1414,   261,  1020,  1021,   261,   528,   614,   162,
     107,   312,   961,   163,   134,   167,   376,   146,   162,   168,
     261,   333,  1010,   261,   261,   261,   261,  1281,  1269,   501,
     140,   261,   261,   261,   378,   398,   399,   261,   703,   335,
     704,   167,  -532,  1214,   705,  1011,   387,   337,  2033,   147,
     388,   398,   399,  1954,   550,   319,   551,  1096,   320,   153,
     552,   154,   261,   261,   261,   153,   148,   154,  1260,  1263,
     394,   395,   396,   397,   588,   589,   261,   261,   676,   891,
     149,   893,   894,   583,   584,   157,   410,   588,   589,   158,
     591,   592,   597,   384,   398,   399,   159,   385,   907,   398,
     399,   259,   550,  1262,   551,   721,   160,   722,   552,   164,
    2028,   723,   398,   399,   599,   674,   682,   675,   600,   588,
     589,   552,   394,   395,   396,   397,   394,   395,   396,   397,
     394,   395,   396,   397,   398,   399,   941,   180,   588,   589,
     419,  -534,   588,   589,   261,   261,   398,   399,   588,   589,
     398,   399,   742,   748,   398,   399,   743,   743,   598,  1753,
     261,   394,   395,   396,  1001,   165,   706,   394,   395,   396,
     397,   286,   287,   975,   169,   815,   816,   817,   818,  1171,
     588,   589,   305,   288,   306,   737,   802,   294,   804,   261,
     806,   807,  1360,   157,  1361,  2058,  1172,  1009,   296,   588,
     589,  1856,   170,  1368,  1173,  1174,  1175,   171,   819,   820,
    1176,  1177,   172,    59,    60,    61,    62,   588,   589,   173,
    1857,  1381,   695,  1383,   696,  1385,  1120,  1387,    73,  1121,
     728,    76,   179,   456,   588,   589,   261,   753,  1858,   588,
     589,   743,   823,   261,   798,   766,  1595,  1596,   419,   743,
     419,   261,   419,   419,   419,  1859,  2106,   827,   588,   589,
    1860,   743,   588,   589,   174,   261,   261,   261,   261,   261,
     419,   419,   261,   152,   181,   152,   822,   261,   824,  1861,
     588,   589,  1171,  1987,   297,  1635,  1636,   259,   298,   870,
     873,   876,   879,  1238,   299,   300,  1239,   301,   302,  1172,
     261,  1988,   588,   589,   588,   589,   852,  1173,  1174,  1175,
     588,   589,  1456,  1176,  1177,   303,   588,   589,   588,   589,
     560,   175,   182,  1989,   995,  1990,   398,   399,   569,   571,
     573,   261,   261,  -537,   578,   176,   177,  1991,   948,  2042,
     950,   951,   952,   953,   954,   955,   178,   957,   958,   959,
     960,   588,   589,   965,   966,   967,   411,   411,  1171,   588,
     589,  1496,   672,   544,   545,   546,   547,   588,   589,   186,
     262,   548,  2043,   588,   589,  1172,  1512,   261,   261,   261,
    2052,   263,   964,  1173,  1174,  1175,   898,   899,  2087,  1176,
    1177,   584,  1160,   274,  2088,   279,   275,  1612,   276,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   264,   419,
     419,   419,   419,   963,   280,   419,   419,   419,   152,   969,
     285,   968,   261,  1033,   270,   860,   293,   271,  1037,   743,
     272,   509,   273,  1015,   510,  1171,  1016,   511,  1017,   512,
     304,   679,   680,   307,   541,   542,   672,   544,   545,   546,
     547,   486,  1172,   487,   261,   548,   634,   693,   134,  1004,
    1173,  1174,  1175,   695,  1042,   696,  1176,  1177,   546,   547,
     329,  1216,   683,  2045,   548,   684,   261,  1024,   685,   695,
     686,   696,   261,   308,   695,   419,   696,  1236,  1035,  1132,
     419,   317,   743,  1917,  1918,  1921,  1922,   318,   261,  1919,
     261,  1919,   321,   982,   170,   187,   150,   983,  1012,   322,
     323,  1123,   188,   189,   190,   743,   328,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   379,   209,   210,   211,   212,   213,
     214,  1155,   695,  1156,   696,   743,   330,   743,   805,  1199,
    2089,  1660,   695,   743,   696,   697,   261,   220,   221,   222,
     223,   340,   560,  1669,  1200,   224,  1201,  2019,   743,  1242,
     743,  1272,  1345,   743,   331,   743,   743,   225,   226,   227,
    1367,  1316,   341,  1317,   743,   228,    21,  1372,  1394,   338,
     342,   743,   743,   150,   343,  1500,  1501,   339,  1502,   743,
     743,   261,   743,  1503,  1322,  1414,  1323,   743,  1553,  1579,
     372,  1666,   743,   743,   261,  1667,  1765,  1808,   383,  1817,
     743,  1809,   261,  1818,   389,  1261,  1264,  1839,  1840,  1855,
    2068,   743,   743,  1809,   699,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   695,   261,   696,   857,   353,   354,
     355,   356,   390,   414,  1414,  1893,   357,   358,   359,  1894,
    1909,   360,  1943,   361,  1809,  1944,   743,  1970,  1978,   728,
     415,  1809,   743,  1986,   362,  2000,   363,   743,  2048,  1809,
    2049,  2050,   743,   426,   743,   743,  2051,   529,   134,   428,
     743,  2053,   236,  1163,  2055,   743,   237,  1733,  1894,  1734,
    1169,   239,   240,   241,  1180,   242,   243,   244,  2079,   438,
    2090,   107,  1809,   392,   743,  2103,  2117,  1300,  1265,  2104,
    1809,  2120,   508,   443,   457,  2121,   494,   245,   380,   497,
     513,   516,   517,   518,   247,   577,   557,   558,   385,   325,
     261,   564,   574,   575,   565,   615,   250,   566,   567,   618,
     579,  1671,  1672,   601,  1271,   581,   582,   602,  1482,   261,
     603,   604,   605,   606,  1369,  1371,   261,   261,   261,   261,
     607,   612,  1745,  1746,   616,   619,   629,   620,   621,   419,
     364,   365,   366,   622,   625,   626,   627,   630,   637,   636,
     645,   367,   663,   646,   647,   368,   658,   369,   107,  1350,
    1351,   659,   661,   664,   261,   261,   662,   261,   666,   261,
     261,   665,   261,   668,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   398,   399,   261,   681,   687,   694,   700,
    -533,   701,  1497,   133,   734,   707,   738,   739,   760,   764,
     767,  1315,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
     261,   419,   419,   768,   548,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,   261,   769,   770,   799,   548,   548,   810,   812,   855,
     813,   261,   261,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   814,   864,   865,   881,   548,  1448,   883,   885,  1140,
    1450,  1749,  1369,  1371,   889,   890,   892,   918,   920,  1454,
     921,  1455,   923,   930,  1457,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,   931,   261,
     939,   942,   548,   976,   985,   981,   986,   996,   997,   987,
     988,  1653,   261,   261,   261,  1655,   989,   998,  1008,  1013,
    1665,  1027,  1029,   261,  1032,  1034,  1036,  1040,   419,  1039,
    1043,  1044,   419,  1047,  1498,  1048,  1050,  1051,  1052,  1053,
    1055,   419,  1056,   419,  1057,  1058,   419,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1068,  1069,  1094,   261,  1772,  1124,
    1103,  1095,  1104,  1105,  1108,  1110,  1925,  1111,  1112,  1134,
    1119,  1113,  1129,  1141,  1135,  1144,   335,  1143,  1146,  1148,
    1145,  1147,  1518,  1150,  1522,  1149,  1158,  1252,  1151,  1192,
    1166,  1167,  1170,  1194,  1208,  1873,   419,  1205,  1206,  1207,
    1221,  1219,  1220,  1232,  1224,  1234,  1275,  1235,  1241,  1245,
    1244,  1246,  1251,  1249,  1267,  1268,   261,  1296,  1250,  1273,
    1274,  1287,  -535,   529,  1297,  1298,  1299,   261,  1302,  1309,
    1320,  1326,  1328,   261,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,  1339,
    1352,  1318,  1319,   548,  1321,  1375,  1324,  1325,  1661,  1327,
    1363,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,
    1376,  1377,  1380,  1402,  1389,  1390,  1391,  1392,  1393,  1395,
    1403,  1406,   261,   261,   261,  1407,  1408,  1417,   261,  1418,
     261,  1419,   261,  1420,   261,  1421,   261,   261,   261,  1422,
    1423,  1424,  1425,  1429,  1428,  1430,  1798,  1349,  1431,  1432,
    1433,  1434,  1435,   261,  1440,  1445,  1446,  1452,  1451,  1458,
    1460,  1459,  1467,  1461,   261,  1465,  1473,  1478,  1364,  1479,
    1485,  1481,   261,  1484,  1651,   261,  1489,  1491,  1373,  1492,
    1493,  1495,  1509,  1514,  1523,  1525,  1513,  1526,  1528,  1529,
    1530,  1524,  1534,  1535,  1536,  1537,  1690,  1538,  1540,  1543,
    1722,  1544,  1542,  1611,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,  1545,  1546,  1547,  1548,   548,  1549,   335,  1550,
    1551,  1694,  1773,  1552,   419,   419,  1426,  1562,  1573,  1121,
     261,  1575,  1576,  1578,  1583,  1584,  1630,  1592,  1593,  1437,
    1438,  1439,  1594,  1600,  1608,  1609,  1601,  1602,   419,  1603,
    1615,  1623,  1616,   261,  1628,  1617,  1618,   261,   717,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   741,   544,   545,   546,   547,  1629,  1619,  1634,
    1620,   548,  1648,   695,  1466,   696,  1638,  1625,  1641,  1657,
    1662,  1663,  1678,  1722,  1239,  1656,  1679,  1673,  -536,  1680,
    1681,  1740,  1682,  1683,  1684,  1685,  1691,  1695,  1702,  1703,
    1704,  1705,  1708,  1778,  1709,  1710,  1780,  1712,  1713,  1721,
    1723,  1724,  1726,  1728,  1729,  1730,  1731,  1732,  1735,   261,
     261,  1750,  1754,  1931,  1755,  1764,  1768,  1785,  1787,  1794,
    1786,  1777,  1795,  1521,  1816,  1797,   411,   411,  1783,  1784,
    1948,  1801,   261,  1812,  1533,  1820,  1825,  1827,   261,  1837,
    1539,  1838,  1843,  1846,  1792,  1850,  1862,   261,  1847,  1844,
    1852,  1853,  1864,  1869,  1879,   419,  1870,  1881,   419,  1876,
    1882,  1877,  1884,  1885,  1886,  1878,  1891,  1883,  1902,  1443,
    1903,  1904,  1905,   261,  1757,  1758,  1759,  1760,  1761,  1763,
    1271,  1907,  1908,  1928,   335,  1929,   261,  1933,  1945,  1580,
    1581,  1582,  1947,  1946,  1949,  1585,  1955,  1586,  1964,  1587,
    1958,  1588,  1959,  1589,  1590,  1591,  1995,  1962,  1971,  1974,
    1975,  1977,  1981,  1979,  1982,  1985,  1993,  1994,  1996,  1997,
    1606,  2004,  2011,  2016,  2021,  2069,  2035,  2054,  2070,  2071,
     261,  1614,  2072,  2074,  2075,  2076,  2077,  2080,  2094,  1622,
    2095,  1258,  2102,  2105,  2113,  2020,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,  2118,  2119,  2122,   261,   548,  2123,
    1511,  2029,  1875,   733,  1565,  1699,  1897,  1874,  1532,   261,
    1725,   112,   122,   123,   124,  1923,  1574,   867,  1650,   130,
    1796,     0,   261,     0,     0,     0,     0,     0,   419,     0,
       0,  1338,     0,     0,  1900,     0,     0,  1677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
    1693,     0,     0,   261,     0,     0,     0,  1901,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     411,     0,     0,   261,     0,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,   335,  1444,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,  1935,  1936,  1937,  1938,  1939,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1677,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,  1769,     0,  2003,     0,     0,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
    1791,   548,     0,     0,     0,     0,  1972,     0,     0,     0,
    1976,     0,     0,  1800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   156,
       0,     0,     0,     0,   261,   261,   261,   261,   261,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,  1677,     0,  2012,
       0,   548,  2092,  2014,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2026,
     261,     0,     0,     0,     0,     0,     0,     0,     0,  2114,
    2116,     0,     0,     0,  1851,     0,     0,     0,     0,   261,
       0,     0,     0,     0,  1427,     0,  2124,     0,     0,     0,
       0,     0,     0,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   419,     0,     0,     0,     0,     0,
    2066,  2067,     0,     0,     0,     0,     0,     0,   405,   406,
       0,   261,     0,   416,     0,     0,     0,   421,     0,     0,
       0,   419,   419,  1892,     0,     0,     0,     0,     0,     0,
    1898,     0,     0,     0,   431,   433,   436,   437,   419,   439,
     433,   441,   442,     0,   444,   433,   446,   447,   448,   449,
     450,   451,  1677,   453,   454,   455,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1930,     0,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   488,   489,   490,   491,   492,   493,     0,   495,   496,
       0,     0,     0,     0,   498,  1677,     0,     0,     0,     0,
       0,     0,     0,   514,   515,     0,     0,     0,     0,     0,
       0,     0,   519,   521,   523,   524,   433,     0,     0,     0,
       0,     0,     0,  1973,     0,     0,     0,     0,     0,   555,
     433,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   608,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,   628,     0,   548,     0,   631,   632,   633,     0,
     635,     0,     0,     0,   638,   639,   640,     0,     0,   641,
     642,   643,   644,     0,     0,     0,   648,   649,   650,   651,
     652,   653,   654,     0,   655,     0,     0,     0,   656,   657,
       0,     0,   660,     0,     0,     0,     0,  1677,     0,     0,
       0,     0,     0,     0,     0,   670,     0,   671,     0,     0,
       0,   677,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   688,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   716,     0,   434,     0,     0,     0,  1464,   434,     0,
       0,     0,     0,   434,     0,     0,     0,     0,  1677,   521,
       0,     0,     0,     0,     0,   746,     0,   434,     0,     0,
     751,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   765,     0,     0,     0,     0,     0,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   789,   790,   791,
     792,   793,   794,   795,   795,     0,   800,   801,     0,   803,
       0,     0,     0,     0,     0,   809,     0,     0,   811,     0,
       0,   522,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,   795,     0,     0,     0,     0,   433,   434,     0,
       0,     0,     0,     0,   829,     0,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,   842,   843,
     845,   847,   848,   849,   850,   851,     0,   853,   854,     0,
       0,     0,     0,     0,   861,   862,   863,     0,     0,     0,
       0,   869,   872,   875,   878,   880,     0,   882,     0,   884,
       0,   433,   433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     519,   671,   903,     0,     0,     0,   908,   909,   910,   911,
     912,   913,   914,   915,   916,     0,     0,     0,     0,   922,
       0,   924,     0,   925,     0,     0,     0,   433,   433,   433,
       0,     0,   932,   933,   934,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,   956,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,     0,   433,   440,     0,     0,     0,   973,   445,   974,
       0,   853,   854,     0,     0,     0,     0,     0,   984,     0,
       0,     0,   458,     0,   990,     0,     0,   522,     0,     0,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
    1005,  1006,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,     0,  1025,  1026,
       0,     0,   433,  1031,     0,     0,     0,     0,     0,     0,
       0,  1038,     0,     0,   788,  1041,     0,     0,   845,     0,
    1045,   796,   797,     0,     0,   150,   343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1066,     0,   556,     0,     0,     0,     0,     0,     0,
     821,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   433,     0,   846,     0,
     353,   354,   355,   356,     0,     0,     0,   698,   357,   358,
     359,     0,     0,   360,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1480,   362,     0,   363,   434,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
       0,  1139,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   434,   434,   434,     0,     0,
       0,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,     0,  1164,  1165,     0,     0,     0,     0,  1168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1193,     0,     0,  1195,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,     0,     0,  1209,     0,  1211,
    1212,     0,     0,   367,     0,     0,     0,   368,     0,   369,
     107,     0,   434,     0,     0,     0,   858,     0,  1230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,     0,  1248,     0,     0,   695,
     434,   696,     0,  1254,  1255,  1256,  1257,     0,     0,     0,
       0,  1266,     0,     0,     0,     0,   846,     0,  1046,     0,
       0,     0,     0,     0,     0,  1290,   433,   433,   433,   433,
    1295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     825,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1308,     0,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,   434,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,  1604,     0,     0,
       0,     0,     0,     0,   886,   887,     0,     0,  1341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1342,  1343,
    1344,     0,     0,     0,     0,  1346,  1347,  1654,  1348,   434,
       0,     0,     0,     0,     0,  1354,     0,  1355,  1356,  1357,
    1358,  1359,   434,     0,     0,     0,     0,     0,  1362,     0,
     927,   928,   929,  1365,  1366,     0,     0,     0,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1382,   434,  1384,     0,  1386,     0,  1388,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1658,     0,     0,   970,     0,     0,     0,  1405,
       0,     0,     0,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,     0,  1082,  1083,  1084,  1085,     0,
    1087,  1088,  1089,  1090,     0,     0,     0,   999,     0,     0,
       0,  1436,     0,     0,  1100,     0,  1102,     0,     0,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,  1023,
       0,  1449,  1115,  1116,     0,  1030,     0,     0,     0,     0,
       0,  1125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1472,     0,     0,
    1477,     0,     0,     0,   434,   434,   434,   434,     0,  1487,
    1488,     0,     0,     0,     0,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,  1505,  1506,  1507,  1508,   548,     0,  1097,
       0,     0,     0,  1515,  1517,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,   434,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1128,     0,     0,     0,     0,  1215,
    1217,  1218,     0,     0,     0,  1222,  1223,  1133,     0,  1226,
    1227,  1228,  1229,     0,  1231,     0,     0,     0,     0,  1237,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,  1157,     0,
     434,     0,   548,     0,  1597,  1598,  1599,     0,     0,     0,
       0,     0,     0,  1605,  1378,  1607,     0,     0,     0,     0,
       0,     0,  1610,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,     0,     0,     0,
    1626,     0,     0,     0,     0,     0,     0,     0,  1631,  1632,
    1633,     0,     0,  1313,  1314,     0,     0,     0,  1642,     0,
       0,     0,     0,     0,     0,     0,     0,  1652,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1668,  1664,     0,     0,     0,     0,  1674,  1675,
       0,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,  1291,
    1292,  1293,  1294,   548,     0,     0,     0,  1697,     0,     0,
       0,     0,     0,     0,     0,  1700,  1701,     0,     0,     0,
       0,     0,  1706,  1707,     0,     0,     0,     0,     0,  1711,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1714,  1715,  1716,     0,
       0,     0,     0,     0,  1717,  1718,  1719,  1720,  1340,  1767,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1727,     0,     0,     0,     0,     0,     0,     0,     0,   433,
     433,  1738,     0,  1739,     0,     0,     0,     0,     0,  1747,
    1748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   433,     0,
       0,     0,  1766,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1776,     0,  1374,  1779,     0,     0,     0,
    1782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1793,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1805,     0,     0,     0,  1486,  1811,     0,     0,     0,     0,
       0,     0,     0,   434,     0,  1842,     0,     0,     0,  1813,
       0,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
    1519,     0,     0,   548,     0,     0,  1447,     0,     0,     0,
    1836,  1868,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1845,     0,  1554,  1555,  1556,  1557,  1558,     0,     0,
    1854,     0,  1563,  1564,     0,  1566,     0,     0,     0,   521,
       0,  1572,     0,     0,     0,     0,     0,     0,  1865,  1866,
       0,     0,   433,     0,  1577,  1698,     0,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,  1889,  1890,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1899,     0,     0,     0,     0,
       0,     0,  1906,     0,     0,     0,     0,     0,  1910,  1911,
    1912,  1913,  1914,     0,     0,     0,     0,     0,   433,     0,
       0,     0,  1880,     0,     0,     0,     0,   434,   434,  1637,
       0,  1640,     0,   433,     0,  1647,     0,  1649,     0,     0,
       0,  1940,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1951,     0,     0,     0,  1670,
       0,  1956,  1957,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,  1980,     0,     0,     0,  1624,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,  1998,
    1999,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2005,  2006,  2007,  2008,  2009,  2010,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2018,
       0,     0,     0,     0,   433,   433,   433,   433,   433,  1992,
       0,     0,     0,     0,  1811,     0,     0,     0,  2034,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,   522,     0,     0,
       0,   548,     0,   695,     0,   696,     0,     0,  2057,     0,
     434,  1639,     0,  2060,  2061,  2062,  2063,  2064,  2065,  2044,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   433,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,  1819,
     529,     0,   548,  1802,  1803,     0,     0,     0,     0,     0,
    2096,  2097,  2098,  2099,  2100,  2101,     0,     0,     0,     0,
       0,     0,  1736,  1737,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   434,     0,   187,   150,     0,  1829,  1830,     0,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   379,   209,   210,   211,   212,   213,   214,     0,
       0,     0,  1961,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,  1871,  1872,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,     0,     0,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   434,   434,   434,   434,   434,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1867,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   741,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
     236,     0,     0,     0,   237,     0,     0,   434,     0,   239,
     240,   241,     0,   242,   243,   244,     0,     0,     0,   107,
     529,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   593,   594,     0,     0,     0,
       0,  1924,   247,     0,     0,     0,     0,   595,     0,     0,
       0,   289,     0,     0,   250,     0,  1934,     0,     0,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,   187,     6,
     343,   548,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     220,   221,   222,   223,   353,   354,   355,   356,   224,     0,
       0,     0,   357,   358,   359,     0,     0,   360,     0,   361,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     362,     0,   363,  2082,     0,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,  2022,  2023,  2024,
    2025,  2027,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,  2073,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   364,   365,   366,   237,
     238,     0,     0,     0,   239,   240,   241,   367,   242,   243,
     244,   368,     0,   369,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,   325,   187,     6,   343,  1520,     0,     0,   250,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   220,   221,   222,   223,   353,
     354,   355,   356,   224,     0,     0,     0,   357,   358,   359,
       0,     0,   360,     0,   361,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,   362,     0,   363,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   943,    49,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   741,   544,   545,   546,   547,  1126,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   364,   365,   366,   237,   238,     0,     0,     0,   239,
     240,   241,   367,   242,   243,   244,   368,     0,   369,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,   325,   187,   150,
     343,   249,   391,     0,   250,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   379,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     220,   221,   222,   223,   353,   354,   355,   356,   224,     0,
       0,     0,   357,   358,   359,     0,     0,   360,     0,   361,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     362,     0,   363,     0,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,   393,     0,
     548,     0,   935,     0,     0,   236,   364,   365,   366,   237,
     896,     0,     0,     0,   239,   240,   241,   367,   242,   243,
     244,   368,     0,   369,   107,   394,   395,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   380,     0,     0,     0,     0,     0,   247,     0,   398,
     399,     0,   400,     0,   401,   187,     6,   324,   402,   250,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
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
       0,   904,   225,   226,   227,     0,     0,     7,     8,     0,
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
       0,     0,     0,     0,     0,     0,   926,   225,   226,   227,
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
       0,   971,   225,   226,   227,     0,     0,     7,     8,     0,
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
       0,     0,     0,     0,     0,     0,   972,   225,   226,   227,
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
       0,  1159,   225,   226,   227,     0,     0,     7,     8,     0,
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
       0,  1162,   225,   226,   227,     0,     0,     7,     8,     0,
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
       0,     0,     0,     0,     0,     0,  1181,   225,   226,   227,
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
       0,  1210,   225,   226,   227,     0,     0,     7,     8,     0,
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
       0,     0,     0,     0,     0,     0,  1243,   225,   226,   227,
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
      42,  1127,     0,     0,     0,     0,   712,    48,     0,     0,
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
       0,  1396,   225,   226,   227,     0,     0,     0,     0,     0,
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
       0,     0,  1018,     0,   708,    25,    26,   709,    28,    29,
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
       0,     0,   220,   221,   222,   223,  1983,     0,     0,     0,
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
       0,     0,   548,     0,     0,     0,     0,   236,   364,   365,
     366,   237,   726,     0,     0,     0,   239,   240,   241,   367,
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
       0,  2046,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1743,     0,     0,     0,  1744,
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
       0,   361,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   362,     0,   363,   187,   150,     0,  1247,     0,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   379,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   364,   365,
     366,   237,     0,     0,     0,     0,   239,   240,   241,   367,
     242,   243,   244,   368,     0,   369,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   380,     0,     0,     0,     0,     0,   247,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,   250,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    1770,     0,   236,     0,  1771,     0,   237,     0,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   380,     0,
       0,     0,     0,     0,   247,   187,   150,     0,  1404,   325,
       0,     0,   188,   189,   190,     0,   250,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   379,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
     187,   150,     0,  1462,     0,   228,    21,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   379,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    1926,     0,   236,     0,  1927,     0,   237,     0,     0,     0,
       0,   239,   240,   241,     0,   242,   243,   244,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   380,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,   325,
       0,     0,     0,     0,     0,     0,   250,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,   236,     0,   548,
       0,   237,     0,     0,     0,     0,   239,   240,   241,   896,
     242,   243,   244,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   380,     0,     0,     0,     0,     0,   247,
     187,   150,     0,     0,   325,     7,     8,   188,   189,   190,
       0,   250,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   379,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   708,    25,    26,   709,    28,    29,   710,    31,
     711,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   712,
      48,     0,     0,    50,   713,     0,    53,   714,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,    84,
      85,    86,     0,     0,     0,     0,    -4,     1,   897,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,     0,     0,     0,     0,   239,   240,   241,     0,
     242,   243,   244,     0,     0,     0,   107,     0,     0,     0,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   380,     0,     0,     0,     0,     0,   247,
      -4,    -4,    -4,     0,   325,     0,    -4,    -4,     0,    -4,
       0,   250,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
      -4,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,
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
       0,     0,     0,    17,    18,     0,    19,    20,     0,    21,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
      37,    38,    39,    40,    41,     0,    42,     0,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      79,    80,    81,     0,     0,     0,    82,     0,     0,     0,
       0,    83,    84,    85,    86,   150,   343,    87,     0,    88,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   150,   343,     0,     0,     0,     0,
       0,     0,   106,     0,   107,     0,     0,   344,   345,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
     353,   354,   355,   356,   373,   343,     0,     0,   357,   358,
     359,     0,     0,   360,     0,   361,   344,   345,   346,   347,
     348,   349,   350,   351,   352,     0,   362,     0,   363,   353,
     354,   355,   356,     0,   343,     0,     0,   357,   358,   359,
       0,     0,   360,     0,   361,     0,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   362,     0,   363,     0,   353,
     354,   355,   356,     0,     0,   392,     0,   357,   358,   359,
       0,     0,   360,     0,   361,   344,   345,   346,   347,   348,
     349,   350,   351,   352,     0,   362,     0,   363,   353,   354,
     355,   356,     0,     0,     0,     0,   357,   358,   359,     0,
       0,   360,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,     0,     0,     0,     0,     0,
       0,     0,     0,   367,     0,     0,     0,   368,     0,   369,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,   366,     0,     0,     0,     0,     0,     0,
       0,     0,   367,     0,     0,     0,   368,     0,   369,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,   366,     0,     0,     0,     0,     0,     0,
       0,     0,   367,     0,     0,     0,   368,     0,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,     0,     0,     0,     0,     0,     0,     0,
       0,   367,     0,     0,     0,   368,     0,   369,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     940,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1081,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1091,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1092,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1093,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1099,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1204,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1225,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1306,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1398,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1399,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1441,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1559,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1560,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1561,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1567,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1568,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1569,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1570,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1692,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1806,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1807,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1831,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1832,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1833,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1834,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1835,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1895,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1952,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1953,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1965,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1966,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1967,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1968,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1969,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2001,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2031,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2036,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2037,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2038,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2039,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2040,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2041,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2083,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2084,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2085,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2086,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  1109,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  1184,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,  1253,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    1400,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  1468,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,  1469,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,  1470,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,  1471,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1741,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,  1752,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  1788,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  1821,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,  1822,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    1823,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  1824,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,  1826,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,  1848,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,  1863,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  1915,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,  1932,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  1941,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  1942,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,  1963,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
    2017,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,     0,  2059,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,  2081,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,  2107,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,     0,     0,  2108,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,  2109,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,  2110,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,  2111,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,  2112,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,     0,
     673,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,     0,   888,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,     0,  1841,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,   695,     0,   696,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
     946,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,   992,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,  1131,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,     0,
       0,  1197,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   672,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,     0,     0,  1198,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   672,   544,   545,   546,   547,     0,     0,     0,
       0,   548,     0,     0,     0,  1202,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   672,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
       0,     0,  1203,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   672,   544,   545,   546,
     547,     0,     0,     0,     0,   548,     0,     0,     0,  1289,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,     0,     0,  1304,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     672,   544,   545,   546,   547,     0,     0,     0,     0,   548,
       0,     0,     0,  1499,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   672,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,     0,     0,
    1627,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   672,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,     0,     0,  1799,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   672,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,     0,     0,  1849,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   740,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   744,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   745,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   747,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   749,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   750,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   752,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   754,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   755,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   756,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   757,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   758,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   759,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   761,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   762,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   763,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   826,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   859,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   917,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   935,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   936,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   937,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   938,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   944,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   945,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   977,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   991,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1049,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1054,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1067,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1130,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1136,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1137,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1138,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1152,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1153,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1154,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1183,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1185,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1186,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1187,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1188,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1189,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1190,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1191,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1196,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1288,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1303,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1504,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1571,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1686,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1687,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1688,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1689,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1742,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  1751,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  1774,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,  2030,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   672,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,  2078,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   672,   544,   545,   546,   547,     0,     0,
       0,     0,   548
};

static const yytype_int16 yycheck[] =
{
       3,   497,   590,   591,  1178,  1182,   132,   690,  1653,     3,
    1655,   282,     4,     4,     4,   698,     4,  1615,    21,   705,
       5,    21,     4,     6,     4,     4,     4,     4,    14,     4,
       6,     4,     9,     5,   294,     6,     5,   723,     5,     4,
       4,   234,   235,     6,    47,     4,     4,     7,     4,  1814,
       9,     5,   312,     6,     4,     6,    96,     5,     4,    96,
       6,   147,     6,    98,    96,   100,     9,   132,   237,     7,
     238,    74,   137,   138,   238,   225,   226,     9,   246,    82,
     117,   237,   246,   239,    87,   117,   172,   225,   226,   183,
     184,   185,   225,   226,    84,    98,   246,   132,    60,    61,
       6,    63,   188,   189,   242,   127,    90,     7,     6,    93,
     175,   238,    96,   246,     9,  1713,   376,     9,   378,   246,
     155,   186,   144,    93,     0,   385,    96,     9,    98,   132,
     152,   153,   154,   238,   137,   138,   158,   159,   237,   133,
       6,   246,   145,   238,    90,   240,   642,   238,   644,   225,
     226,   246,   243,   156,   238,   158,   225,   226,   238,     7,
     163,     6,   246,     7,   241,   168,   246,     7,   245,     6,
     246,     6,   175,   267,   268,   269,   179,   246,   238,   182,
     183,   184,   185,   186,   225,   226,   246,   162,   163,   164,
     165,   225,   226,   183,   240,  1960,    93,   160,     7,    96,
     246,   234,   235,   175,     7,   246,   175,   241,   172,   173,
     243,   305,   306,   307,   172,   173,   160,   209,     6,   209,
     242,   175,   187,   225,   226,   319,   320,   175,   240,   209,
     233,   209,   209,     6,   246,   237,   209,   220,   221,   241,
    1838,   237,  1416,   246,   220,   221,   249,   250,   239,   237,
     209,   241,   244,   241,   245,   237,   241,     6,   237,   241,
     263,   241,   241,   266,   267,   268,   269,   242,   241,   241,
     241,   274,   275,   276,   241,   234,   235,   280,   237,   282,
     239,   237,   241,   243,   243,   241,   237,   237,   241,     6,
     241,   234,   235,  1891,   237,    93,   239,   240,    96,   237,
     243,   239,   305,   306,   307,   237,   239,   239,   991,   992,
     210,   211,   212,   213,   225,   226,   319,   320,   383,   579,
     239,   581,   582,   285,   286,   237,     4,   225,   226,   241,
     241,   293,   294,   237,   234,   235,   237,   241,   598,   234,
     235,    47,   237,   243,   239,   237,   237,   239,   243,   237,
    1995,   243,   234,   235,   237,   237,   391,   239,   241,   225,
     226,   243,   210,   211,   212,   213,   210,   211,   212,   213,
     210,   211,   212,   213,   234,   235,   636,    96,   225,   226,
     383,   241,   225,   226,   387,   388,   234,   235,   225,   226,
     234,   235,   242,   242,   234,   235,   246,   246,   241,   246,
     403,   210,   211,   212,   213,   237,   409,   210,   211,   212,
     213,   225,   226,   673,   237,   509,   510,   511,   512,   127,
     225,   226,    96,   237,    98,   428,   491,   241,   493,   432,
     495,   496,  1118,   237,  1120,  2033,   144,   241,     4,   225,
     226,   246,   237,  1129,   152,   153,   154,   237,   513,   514,
     158,   159,   237,   131,   132,   133,   134,   225,   226,   237,
     246,  1144,   238,  1146,   240,  1148,   243,  1150,   146,   246,
     246,   149,   110,   179,   225,   226,   479,   242,   246,   225,
     226,   246,   517,   486,   487,   242,     6,     7,   491,   246,
     493,   494,   495,   496,   497,   246,  2094,   242,   225,   226,
     246,   246,   225,   226,   237,   508,   509,   510,   511,   512,
     513,   514,   515,   516,     6,   518,   516,   520,   518,   246,
     225,   226,   127,   246,    90,     6,     7,   233,    94,   564,
     565,   566,   567,   243,   100,   101,   246,   103,   104,   144,
     543,   246,   225,   226,   225,   226,   549,   152,   153,   154,
     225,   226,  1238,   158,   159,   121,   225,   226,   225,   226,
     266,   237,   241,   246,   690,   246,   234,   235,   274,   275,
     276,   574,   575,   241,   280,   237,   237,   246,   643,   246,
     645,   646,   647,   648,   649,   650,   237,   652,   653,   654,
     655,   225,   226,   658,   659,   660,   590,   591,   127,   225,
     226,  1287,   227,   228,   229,   230,   231,   225,   226,   237,
     237,   236,   246,   225,   226,   144,  1302,   620,   621,   622,
     246,   241,   657,   152,   153,   154,   588,   589,   246,   158,
     159,   593,   892,    93,   246,   237,    96,   242,    98,   642,
     643,   644,   645,   646,   647,   648,   649,   650,    96,   652,
     653,   654,   655,   656,    93,   658,   659,   660,   661,   662,
     241,   661,   665,   728,    90,   242,   241,    93,   733,   246,
      96,    90,    98,    93,    93,   127,    96,    96,    98,    98,
     237,   387,   388,    96,   225,   226,   227,   228,   229,   230,
     231,   237,   144,   239,   697,   236,   243,   403,   245,   702,
     152,   153,   154,   238,   739,   240,   158,   159,   230,   231,
     237,   246,    90,   242,   236,    93,   719,   720,    96,   238,
      98,   240,   725,    93,   238,   728,   240,   246,   731,   855,
     733,    93,   246,   131,   132,   131,   132,    96,   741,   137,
     743,   137,     4,   242,   237,     3,     4,   246,   241,     4,
       4,   242,    10,    11,    12,   246,     4,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   242,   238,   242,   240,   246,   237,   246,   494,   242,
     242,  1474,   238,   246,   240,   241,   799,    55,    56,    57,
      58,     6,   508,  1486,   242,    63,   242,  1984,   246,   242,
     246,   242,   242,   246,   237,   246,   246,    75,    76,    77,
     242,    96,     6,    98,   246,    83,    84,   242,   242,   237,
     239,   246,   246,     4,     5,   242,   242,   237,   242,   246,
     246,   844,   246,   242,    96,  2019,    98,   246,   242,   242,
     237,   242,   246,   246,   857,   246,   242,   242,   239,   242,
     246,   246,   865,   246,     6,   991,   992,   242,   242,   242,
    2047,   246,   246,   246,     6,    46,    47,    48,    49,    50,
      51,    52,    53,    54,   238,   888,   240,   241,    59,    60,
      61,    62,   245,   241,  2068,   242,    67,    68,    69,   246,
     242,    72,   242,    74,   246,   242,   246,   242,   242,   246,
       6,   246,   246,   242,    85,   242,    87,   246,   242,   246,
     242,   242,   246,   237,   246,   246,   242,     8,   245,     9,
     246,   242,   190,   895,   242,   246,   194,     4,   246,     6,
     902,   199,   200,   201,   906,   203,   204,   205,   242,   237,
     242,   209,   246,   124,   246,   242,   242,  1022,   993,   246,
     246,   242,   117,   237,   237,   246,   237,   225,   226,   237,
     237,   237,   237,   237,   232,     4,   237,   237,   241,   237,
     983,   237,   241,   241,   237,     6,   244,   237,   237,     6,
     241,  1487,  1488,   237,   997,   241,   241,   237,  1269,  1002,
     237,   237,   237,   237,  1130,  1131,  1009,  1010,  1011,  1012,
     237,   237,  1600,  1601,   239,     6,     6,   241,   241,  1022,
     191,   192,   193,   241,   239,   239,   239,     6,   175,   241,
     237,   202,     6,   237,   237,   206,   237,   208,   209,  1104,
    1105,   237,   237,     6,  1047,  1048,   239,  1050,     6,  1052,
    1053,   241,  1055,     6,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,   234,   235,  1068,   241,     7,     6,   241,
     241,     6,   243,   241,    86,   242,   246,   246,   238,     7,
       6,  1043,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
    1103,  1104,  1105,     6,   236,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,  1124,     6,   238,   241,   236,   236,    64,    64,     4,
      64,  1134,  1135,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    64,     7,     7,     6,   236,  1221,     6,     6,   865,
    1225,   242,  1288,  1289,   238,     6,   241,     7,     6,  1234,
       7,  1236,     6,     6,  1239,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     6,  1192,
     172,   241,   236,   240,     6,   238,   241,   243,     7,   241,
     241,  1461,  1205,  1206,  1207,  1465,   241,     6,   239,   237,
    1481,     4,     6,  1216,     6,     6,     6,   239,  1221,   238,
       7,   175,  1225,     7,  1289,     7,     7,   175,     7,     7,
       7,  1234,   175,  1236,     7,     7,  1239,     7,     7,     7,
       7,     7,     7,     7,   241,     6,   238,  1250,     8,     7,
     246,   240,   246,   246,   241,   241,  1844,   241,   241,     7,
     238,   246,   243,     4,   241,   238,  1269,     6,   238,   238,
     246,   246,  1307,   238,  1309,   246,   243,   983,   246,     7,
     242,   242,   127,     6,   243,  1781,  1289,     7,     7,     7,
     246,   238,   238,     9,   246,   246,  1002,   238,   240,     7,
     245,   147,     6,   242,     6,     4,  1309,   237,   241,    46,
      46,   243,   241,     8,   237,   237,   237,  1320,   243,     4,
       7,     7,    98,  1326,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,     7,
     246,  1047,  1048,   236,  1050,     7,  1052,  1053,  1474,  1055,
     238,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
       7,     7,     6,   108,     7,     7,     7,     7,     7,     4,
       4,   241,  1375,  1376,  1377,     6,   237,     7,  1381,     6,
    1383,     7,  1385,     7,  1387,     7,  1389,  1390,  1391,     7,
       7,     7,     7,     6,   241,     6,  1667,  1103,     6,    96,
       7,     6,     6,  1406,     4,     4,     4,   246,   244,   238,
     241,   246,   242,   241,  1417,   241,     6,     6,  1124,     6,
     239,     7,  1425,     6,  1459,  1428,     6,   237,  1134,   237,
     241,     6,     6,     6,   240,     6,   243,     6,   241,   241,
     121,   246,     6,   241,   241,     6,  1511,     6,   175,     6,
    1576,     6,   241,  1415,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     6,     6,     6,     6,   236,     6,  1481,     6,
       6,  1516,   242,     5,  1487,  1488,  1192,   238,   238,   246,
    1493,     6,     4,     6,     4,     6,   171,   241,   241,  1205,
    1206,  1207,     7,   241,     6,     6,   241,   241,  1511,   239,
     241,     6,   241,  1516,     6,   241,   241,  1520,     6,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,     6,   241,     6,
     241,   236,   238,   238,  1250,   240,   246,   241,   246,     6,
     243,     7,   241,  1679,   246,   246,     4,   237,   241,     6,
       6,  1596,     6,     6,     6,     6,     4,     7,  1530,     6,
       6,     6,     6,  1638,    94,     6,  1641,     5,   241,   238,
     241,     6,     6,     6,     6,     6,     6,     6,     6,  1592,
    1593,   246,     6,  1853,     6,     6,     6,   246,   246,     6,
     238,  1636,     4,  1309,   241,     6,  1600,  1601,  1643,  1644,
    1881,     6,  1615,     6,  1320,     7,   241,     5,  1621,     6,
    1326,   241,     6,   242,  1659,     6,     6,  1630,   242,   241,
       7,   241,   170,     6,     6,  1638,   238,     7,  1641,   242,
       6,   242,     6,     6,     6,   242,   241,   243,     6,     8,
       6,     6,     6,  1656,  1616,  1617,  1618,  1619,  1620,  1621,
    1663,     6,     6,     6,  1667,   242,  1669,     6,   238,  1375,
    1376,  1377,     6,   241,   173,  1381,     6,  1383,   241,  1385,
     242,  1387,   242,  1389,  1390,  1391,  1946,   237,   241,     6,
     241,     6,     6,   242,   127,   241,     6,     6,     6,   241,
    1406,   238,     6,     6,     6,     6,   242,   242,     6,     6,
    1713,  1417,     6,     6,     6,     6,   241,     6,   241,  1425,
       6,     6,     6,   241,     6,  1985,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     6,     6,     6,  1750,   236,     6,
    1301,  1997,  1787,   425,  1352,  1524,  1815,  1785,  1319,  1762,
    1581,     3,     3,     3,     3,  1840,  1361,   563,  1456,     3,
    1663,    -1,  1775,    -1,    -1,    -1,    -1,    -1,  1781,    -1,
      -1,     6,    -1,    -1,  1819,    -1,    -1,  1493,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
    1516,    -1,    -1,  1816,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1838,    -1,    -1,  1841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1852,
    1844,    -1,    -1,  1856,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,  1881,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1891,    -1,
      -1,    -1,    -1,    -1,    -1,  1857,  1858,  1859,  1860,  1861,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,
      -1,    -1,    -1,    -1,    -1,    -1,  1919,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1630,    -1,  1961,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
    1656,   236,    -1,    -1,    -1,    -1,  1918,    -1,    -1,    -1,
    1922,    -1,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,  1987,  1988,  1989,  1990,  1991,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,  1713,    -1,  1971,
      -1,   236,  2077,  1975,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1991,
    2033,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2104,
    2105,    -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,  2052,
      -1,    -1,    -1,    -1,     6,    -1,  2121,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2077,    -1,    -1,    -1,    -1,    -1,
    2042,  2043,    -1,    -1,    -1,    -1,    -1,    -1,   132,   132,
      -1,  2094,    -1,   136,    -1,    -1,    -1,   140,    -1,    -1,
      -1,  2104,  2105,  1809,    -1,    -1,    -1,    -1,    -1,    -1,
    1816,    -1,    -1,    -1,   157,   158,   159,   160,  2121,   162,
     163,   164,   165,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,  1838,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,  1852,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,   222,   223,
      -1,    -1,    -1,    -1,   228,  1891,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,  1919,    -1,    -1,    -1,    -1,    -1,   262,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,   325,    -1,   236,    -1,   329,   330,   331,    -1,
     333,    -1,    -1,    -1,   337,   338,   339,    -1,    -1,   342,
     344,   345,   346,    -1,    -1,    -1,   350,   351,   352,   353,
     354,   355,   356,    -1,   358,    -1,    -1,    -1,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,    -1,  2033,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   379,    -1,   380,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,   401,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,    -1,   158,    -1,    -1,    -1,     6,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,  2094,   432,
      -1,    -1,    -1,    -1,    -1,   438,    -1,   182,    -1,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,    -1,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,    -1,   489,   490,    -1,   492,
      -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,   501,    -1,
      -1,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   515,    -1,    -1,    -1,    -1,   520,   263,    -1,
      -1,    -1,    -1,    -1,   528,    -1,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,    -1,   550,   551,    -1,
      -1,    -1,    -1,    -1,   557,   558,   559,    -1,    -1,    -1,
      -1,   564,   565,   566,   567,   568,    -1,   570,    -1,   572,
      -1,   574,   575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     593,   594,   595,    -1,    -1,    -1,   599,   600,   601,   602,
     603,   604,   605,   606,   607,    -1,    -1,    -1,    -1,   612,
      -1,   614,    -1,   616,    -1,    -1,    -1,   620,   621,   622,
      -1,    -1,   625,   626,   627,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,   651,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   665,   163,    -1,    -1,    -1,   670,   168,   672,
      -1,   674,   675,    -1,    -1,    -1,    -1,    -1,   681,    -1,
      -1,    -1,   182,    -1,   687,    -1,    -1,   432,    -1,    -1,
      -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,    -1,    -1,
     703,   704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   719,    -1,   721,   722,
      -1,    -1,   725,   726,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   734,    -1,    -1,   479,   738,    -1,    -1,   741,    -1,
     743,   486,   487,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
     515,    -1,    -1,    -1,    -1,   520,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   799,    -1,   543,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,   405,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    85,    -1,    87,   574,
     575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   844,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   857,    -1,    -1,    -1,    -1,    -1,
      -1,   864,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   620,   621,   622,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   896,   897,    -1,    -1,    -1,    -1,   902,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,   921,    -1,
     665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,    -1,    -1,   940,    -1,   942,
     943,    -1,    -1,   202,    -1,    -1,    -1,   206,    -1,   208,
     209,    -1,   697,    -1,    -1,    -1,   554,    -1,   961,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   719,    -1,   979,    -1,    -1,   238,
     725,   240,    -1,   986,   987,   988,   989,    -1,    -1,    -1,
      -1,   994,    -1,    -1,    -1,    -1,   741,    -1,   743,    -1,
      -1,    -1,    -1,    -1,    -1,  1008,  1009,  1010,  1011,  1012,
    1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1035,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,   799,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1068,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,   574,   575,    -1,    -1,  1081,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1091,  1092,
    1093,    -1,    -1,    -1,    -1,  1098,  1099,     6,  1101,   844,
      -1,    -1,    -1,    -1,    -1,  1108,    -1,  1110,  1111,  1112,
    1113,  1114,   857,    -1,    -1,    -1,    -1,    -1,  1121,    -1,
     620,   621,   622,  1126,  1127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1145,   888,  1147,    -1,  1149,    -1,  1151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,   665,    -1,    -1,    -1,  1172,
      -1,    -1,    -1,   771,   772,   773,   774,   775,   776,   777,
     778,   779,   780,   781,    -1,   783,   784,   785,   786,    -1,
     788,   789,   790,   791,    -1,    -1,    -1,   697,    -1,    -1,
      -1,  1204,    -1,    -1,   802,    -1,   804,    -1,    -1,    -1,
      -1,    -1,    -1,  1216,    -1,    -1,    -1,    -1,    -1,   719,
      -1,  1224,   820,   821,    -1,   725,    -1,    -1,    -1,    -1,
      -1,   829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1260,    -1,    -1,
    1263,    -1,    -1,    -1,  1009,  1010,  1011,  1012,    -1,  1273,
    1274,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,  1296,  1297,  1298,  1299,   236,    -1,   799,
      -1,    -1,    -1,  1306,  1307,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,  1068,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,   947,
     948,   949,    -1,    -1,    -1,   953,   954,   857,    -1,   957,
     958,   959,   960,    -1,   962,    -1,    -1,    -1,    -1,   967,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   888,    -1,
    1135,    -1,   236,    -1,  1397,  1398,  1399,    -1,    -1,    -1,
      -1,    -1,    -1,  1406,   127,  1408,    -1,    -1,    -1,    -1,
      -1,    -1,  1415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1428,    -1,    -1,    -1,    -1,
    1433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1441,  1442,
    1443,    -1,    -1,  1041,  1042,    -1,    -1,    -1,  1451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1485,     6,    -1,    -1,    -1,    -1,  1491,  1492,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,  1009,
    1010,  1011,  1012,   236,    -1,    -1,    -1,  1520,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1528,  1529,    -1,    -1,    -1,
      -1,    -1,  1535,  1536,    -1,    -1,    -1,    -1,    -1,  1542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1559,  1560,  1561,    -1,
      -1,    -1,    -1,    -1,  1567,  1568,  1569,  1570,  1068,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1592,
    1593,  1594,    -1,  1596,    -1,    -1,    -1,    -1,    -1,  1602,
    1603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,    -1,
      -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1636,    -1,  1135,  1639,    -1,    -1,    -1,
    1643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1660,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1673,    -1,    -1,    -1,  1272,  1678,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1428,    -1,     6,    -1,    -1,    -1,  1692,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
    1308,    -1,    -1,   236,    -1,    -1,  1216,    -1,    -1,    -1,
    1723,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1744,    -1,  1341,  1342,  1343,  1344,  1345,    -1,    -1,
    1753,    -1,  1350,  1351,    -1,  1353,    -1,    -1,    -1,  1762,
      -1,  1359,    -1,    -1,    -1,    -1,    -1,    -1,  1771,  1772,
      -1,    -1,  1775,    -1,  1372,  1520,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,  1806,  1807,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1818,    -1,    -1,    -1,    -1,
      -1,    -1,  1825,    -1,    -1,    -1,    -1,    -1,  1831,  1832,
    1833,  1834,  1835,    -1,    -1,    -1,    -1,    -1,  1841,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,  1592,  1593,  1447,
      -1,  1449,    -1,  1856,    -1,  1453,    -1,  1455,    -1,    -1,
      -1,  1864,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1621,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1888,    -1,    -1,    -1,  1487,
      -1,  1894,  1895,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1927,    -1,    -1,    -1,  1428,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,  1952,
    1953,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1964,  1965,  1966,  1967,  1968,  1969,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1982,
      -1,    -1,    -1,    -1,  1987,  1988,  1989,  1990,  1991,     6,
      -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,  2001,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,  1762,    -1,    -1,
      -1,   236,    -1,   238,    -1,   240,    -1,    -1,  2031,    -1,
    1775,   246,    -1,  2036,  2037,  2038,  2039,  2040,  2041,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2052,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,     7,
       8,    -1,   236,  1671,  1672,    -1,    -1,    -1,    -1,    -1,
    2083,  2084,  2085,  2086,  2087,  2088,    -1,    -1,    -1,    -1,
      -1,    -1,  1592,  1593,    -1,    -1,  1841,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1856,    -1,     3,     4,    -1,  1714,  1715,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1779,  1780,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1987,  1988,  1989,  1990,  1991,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,  1775,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
     190,    -1,    -1,    -1,   194,    -1,    -1,  2052,    -1,   199,
     200,   201,    -1,   203,   204,   205,    -1,    -1,    -1,   209,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,
      -1,  1841,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,   241,    -1,    -1,   244,    -1,  1856,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,     3,     4,
       5,   236,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    87,  2061,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,  1987,  1988,  1989,
    1990,  1991,   117,    -1,   119,    -1,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,    -1,    -1,   149,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,  2052,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   237,     3,     4,     5,   241,    -1,    -1,   244,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    87,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,     8,   119,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     8,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,   194,   195,    -1,    -1,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,   237,     3,     4,
       5,   241,     7,    -1,   244,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    87,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,   236,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,    -1,   183,    -1,
     236,    -1,   238,    -1,    -1,   190,   191,   192,   193,   194,
     246,    -1,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,    -1,   234,
     235,    -1,   237,    -1,   239,     3,     4,     5,   243,   244,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,   236,    -1,    -1,    -1,    -1,   190,   191,   192,
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
      -1,   242,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,   246,
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
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,   208,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,   244,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   190,    -1,   246,    -1,   194,    -1,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,     3,     4,    -1,     6,   237,
      -1,    -1,    10,    11,    12,    -1,   244,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
       3,     4,    -1,     6,    -1,    83,    84,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   190,    -1,   246,    -1,   194,    -1,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,   190,    -1,   236,
      -1,   194,    -1,    -1,    -1,    -1,   199,   200,   201,   246,
     203,   204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
       3,     4,    -1,    -1,   237,    13,    14,    10,    11,    12,
      -1,   244,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,    -1,   121,   122,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,   167,
     168,   169,    -1,    -1,    -1,    -1,     0,     1,   246,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
      64,    65,    66,    -1,   237,    -1,    70,    71,    -1,    73,
      -1,   244,    -1,    -1,    78,    79,    -1,    81,    82,    -1,
      84,    -1,    -1,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,   105,   106,   107,   108,   109,    -1,   111,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,     4,
      -1,   155,   156,   157,    -1,    -1,    -1,   161,    13,    14,
      -1,    -1,   166,   167,   168,   169,    -1,    -1,   172,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,    -1,    -1,    -1,    44,
      45,    -1,   196,   197,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,   209,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    -1,    78,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,   107,   108,   109,    -1,   111,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
     155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,     4,     5,   172,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,   198,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,   209,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,     4,     5,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    85,    -1,    87,    59,
      60,    61,    62,    -1,     5,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    85,    -1,    87,    -1,    59,
      60,    61,    62,    -1,    -1,   124,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    85,    -1,    87,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,    -1,   208,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,    -1,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,    -1,   208,   214,   215,
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
     241,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,   241,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,    -1,    -1,    -1,   236,
      -1,   238,    -1,   240,   214,   215,   216,   217,   218,   219,
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
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236,    -1,   238,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,   236,    -1,   238,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,    -1,
      -1,    -1,   236
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
     220,   221,   251,   343,   353,   326,   326,     4,   334,     6,
     343,   326,     6,   347,     6,   353,     6,   347,   326,   238,
     239,   326,   348,     7,   175,   326,   342,     7,     7,   238,
       7,   175,     7,     7,   238,     7,   175,     7,     7,     7,
       7,     7,     7,     7,     7,     7,   326,   238,   241,     6,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   246,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   246,   246,   246,   238,   240,   240,   343,   246,   246,
     272,   246,   272,   246,   246,   246,   238,   328,   241,   242,
     241,   241,   241,   246,   246,   272,   272,   238,   243,   238,
     243,   246,   329,   242,     7,   272,     8,     8,   343,   243,
     238,   240,   270,   343,     7,   241,   238,   238,   238,   326,
     340,     4,   318,     6,   238,   246,   238,   246,   238,   246,
     238,   246,   238,   238,   238,   242,   242,   343,   243,   242,
     297,   242,   242,   337,   326,   326,   242,   242,   326,   337,
     127,   127,   144,   152,   153,   154,   158,   159,   311,   312,
     337,   242,   307,   238,   242,   238,   238,   238,   238,   238,
     238,   238,     7,   326,     6,   326,   238,   240,   240,   242,
     242,   242,   240,   240,   246,     7,     7,     7,   243,   326,
     242,   326,   326,     7,   243,   272,   246,   272,   272,   238,
     238,   246,   272,   272,   246,   246,   272,   272,   272,   272,
     326,   272,     9,   349,   246,   238,   246,   272,   243,   246,
     330,   240,   242,   242,   245,     7,   147,     6,   326,   242,
     241,     6,   340,   242,   326,   326,   326,   326,     6,     7,
     269,   270,   243,   269,   270,   348,   326,     6,     4,   241,
     345,   353,   242,    46,    46,   340,     4,   162,   163,   164,
     165,   242,   257,   261,   264,   266,   267,   243,   238,   240,
     326,   343,   343,   343,   343,   326,   237,   237,   237,   237,
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
#line 2332 "Gmsh.y"
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
#line 2349 "Gmsh.y"
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
#line 2384 "Gmsh.y"
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
#line 2406 "Gmsh.y"
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
#line 2429 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 207:
#line 2430 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 208:
#line 2435 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 209:
#line 2439 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 210:
#line 2443 "Gmsh.y"
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
#line 2454 "Gmsh.y"
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
#line 2465 "Gmsh.y"
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
#line 2476 "Gmsh.y"
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
#line 2492 "Gmsh.y"
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
#line 2511 "Gmsh.y"
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
#line 2533 "Gmsh.y"
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
#line 2548 "Gmsh.y"
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
#line 2563 "Gmsh.y"
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
#line 2582 "Gmsh.y"
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
#line 2633 "Gmsh.y"
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
#line 2654 "Gmsh.y"
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
#line 2676 "Gmsh.y"
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
#line 2698 "Gmsh.y"
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
#line 2803 "Gmsh.y"
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
#line 2819 "Gmsh.y"
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
#line 2854 "Gmsh.y"
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
#line 2865 "Gmsh.y"
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
#line 2876 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 229:
#line 2882 "Gmsh.y"
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
#line 2897 "Gmsh.y"
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
#line 2925 "Gmsh.y"
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
#line 2937 "Gmsh.y"
    {
      nameSpaces.clear();
    ;}
    break;

  case 233:
#line 2946 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 234:
#line 2953 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 235:
#line 2965 "Gmsh.y"
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
#line 2984 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 237:
#line 2990 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 238:
#line 2996 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 3003 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 3010 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 241:
#line 3017 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3029 "Gmsh.y"
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
#line 3102 "Gmsh.y"
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
#line 3120 "Gmsh.y"
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
#line 3137 "Gmsh.y"
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
#line 3152 "Gmsh.y"
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
#line 3185 "Gmsh.y"
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
#line 3197 "Gmsh.y"
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
#line 3221 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 250:
#line 3225 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 251:
#line 3230 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 252:
#line 3237 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 253:
#line 3242 "Gmsh.y"
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
#line 3252 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 255:
#line 3257 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 256:
#line 3263 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 257:
#line 3271 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 258:
#line 3275 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 259:
#line 3279 "Gmsh.y"
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
#line 3289 "Gmsh.y"
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
#line 3352 "Gmsh.y"
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
#line 3368 "Gmsh.y"
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
#line 3385 "Gmsh.y"
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
#line 3402 "Gmsh.y"
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
#line 3424 "Gmsh.y"
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
#line 3446 "Gmsh.y"
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
#line 3481 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 268:
#line 3489 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 269:
#line 3497 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 270:
#line 3503 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 271:
#line 3510 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 272:
#line 3517 "Gmsh.y"
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
#line 3537 "Gmsh.y"
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
#line 3563 "Gmsh.y"
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
#line 3575 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 276:
#line 3587 "Gmsh.y"
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
#line 3605 "Gmsh.y"
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
#line 3623 "Gmsh.y"
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
#line 3641 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3647 "Gmsh.y"
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
#line 3665 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3671 "Gmsh.y"
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
#line 3691 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3697 "Gmsh.y"
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
#line 3715 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3721 "Gmsh.y"
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
#line 3738 "Gmsh.y"
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
#line 3754 "Gmsh.y"
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
#line 3771 "Gmsh.y"
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
#line 3788 "Gmsh.y"
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
#line 3811 "Gmsh.y"
    {
    ;}
    break;

  case 292:
#line 3814 "Gmsh.y"
    {
    ;}
    break;

  case 293:
#line 3820 "Gmsh.y"
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
#line 3832 "Gmsh.y"
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
#line 3852 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 296:
#line 3856 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 297:
#line 3860 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 298:
#line 3864 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 299:
#line 3868 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3872 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 301:
#line 3876 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3880 "Gmsh.y"
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
#line 3889 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 304:
#line 3901 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 305:
#line 3902 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 306:
#line 3903 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 307:
#line 3904 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 308:
#line 3905 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 309:
#line 3909 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 310:
#line 3910 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 311:
#line 3911 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 312:
#line 3912 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 313:
#line 3913 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 314:
#line 3918 "Gmsh.y"
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
#line 3940 "Gmsh.y"
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
#line 3960 "Gmsh.y"
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
#line 3980 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 318:
#line 3984 "Gmsh.y"
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
#line 3999 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 320:
#line 4003 "Gmsh.y"
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
#line 4019 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 322:
#line 4023 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 323:
#line 4028 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 324:
#line 4032 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 325:
#line 4038 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 326:
#line 4042 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 327:
#line 4049 "Gmsh.y"
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
#line 4066 "Gmsh.y"
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
#line 4107 "Gmsh.y"
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
#line 4151 "Gmsh.y"
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
#line 4190 "Gmsh.y"
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
#line 4215 "Gmsh.y"
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
#line 4224 "Gmsh.y"
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
#line 4254 "Gmsh.y"
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
#line 4280 "Gmsh.y"
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
#line 4307 "Gmsh.y"
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
#line 4339 "Gmsh.y"
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
#line 4366 "Gmsh.y"
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
#line 4392 "Gmsh.y"
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
#line 4418 "Gmsh.y"
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
#line 4444 "Gmsh.y"
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
#line 4470 "Gmsh.y"
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
#line 4491 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 344:
#line 4497 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 345:
#line 4503 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 346:
#line 4509 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 347:
#line 4515 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 348:
#line 4521 "Gmsh.y"
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
#line 4547 "Gmsh.y"
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
#line 4573 "Gmsh.y"
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
#line 4590 "Gmsh.y"
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
#line 4607 "Gmsh.y"
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
#line 4624 "Gmsh.y"
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
#line 4636 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 355:
#line 4642 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 356:
#line 4648 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 357:
#line 4660 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 358:
#line 4664 "Gmsh.y"
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
#line 4674 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 360:
#line 4684 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 361:
#line 4685 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 362:
#line 4686 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 363:
#line 4691 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 364:
#line 4697 "Gmsh.y"
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
#line 4709 "Gmsh.y"
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
#line 4727 "Gmsh.y"
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
#line 4754 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 368:
#line 4755 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 369:
#line 4756 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 370:
#line 4757 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 371:
#line 4758 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 372:
#line 4759 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 373:
#line 4760 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4761 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4763 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 376:
#line 4769 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 377:
#line 4770 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 378:
#line 4771 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 379:
#line 4772 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 380:
#line 4773 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4774 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4775 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 383:
#line 4776 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4777 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4778 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4779 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4780 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 388:
#line 4781 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 389:
#line 4782 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 390:
#line 4783 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 391:
#line 4784 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4785 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 393:
#line 4786 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 394:
#line 4787 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 395:
#line 4788 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 4789 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4790 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 398:
#line 4791 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4792 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4793 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4794 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 402:
#line 4795 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4796 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4797 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4798 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4799 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 407:
#line 4800 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 408:
#line 4801 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 4802 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 410:
#line 4803 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 411:
#line 4804 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 412:
#line 4805 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 413:
#line 4806 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 414:
#line 4815 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 415:
#line 4816 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 416:
#line 4817 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 417:
#line 4818 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 418:
#line 4819 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 419:
#line 4820 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 420:
#line 4821 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 421:
#line 4822 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 422:
#line 4823 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 423:
#line 4824 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 424:
#line 4825 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 425:
#line 4830 "Gmsh.y"
    { init_options(); ;}
    break;

  case 426:
#line 4832 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 427:
#line 4838 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 428:
#line 4840 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 429:
#line 4845 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 430:
#line 4850 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 431:
#line 4854 "Gmsh.y"
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
#line 4872 "Gmsh.y"
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
#line 4890 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 0., 1);
    ;}
    break;

  case 434:
#line 4894 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0., 1);
    ;}
    break;

  case 435:
#line 4898 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 436:
#line 4902 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 437:
#line 4906 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:
#line 4912 "Gmsh.y"
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
#line 4928 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 440:
#line 4934 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 441:
#line 4940 "Gmsh.y"
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

  case 443:
#line 4980 "Gmsh.y"
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
#line 5013 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 445:
#line 5017 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 446:
#line 5022 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 447:
#line 5027 "Gmsh.y"
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
#line 5037 "Gmsh.y"
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
#line 5047 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 450:
#line 5052 "Gmsh.y"
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
#line 5063 "Gmsh.y"
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
#line 5072 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 453:
#line 5077 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 454:
#line 5082 "Gmsh.y"
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
#line 5109 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 456:
#line 5111 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 457:
#line 5116 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 458:
#line 5118 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 459:
#line 5123 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 460:
#line 5130 "Gmsh.y"
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
#line 5146 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 462:
#line 5148 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 463:
#line 5153 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 464:
#line 5162 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 465:
#line 5164 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 466:
#line 5169 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 467:
#line 5171 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 468:
#line 5177 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 469:
#line 5181 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 470:
#line 5185 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 471:
#line 5189 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 472:
#line 5193 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 473:
#line 5200 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 474:
#line 5204 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 475:
#line 5208 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 476:
#line 5212 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 477:
#line 5219 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 478:
#line 5224 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 479:
#line 5231 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 480:
#line 5236 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 481:
#line 5240 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 482:
#line 5245 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 483:
#line 5249 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 484:
#line 5257 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 485:
#line 5268 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 486:
#line 5272 "Gmsh.y"
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
#line 5284 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 488:
#line 5292 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 489:
#line 5300 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 490:
#line 5307 "Gmsh.y"
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
#line 5317 "Gmsh.y"
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
#line 5340 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 493:
#line 5346 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 494:
#line 5352 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 495:
#line 5358 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 496:
#line 5364 "Gmsh.y"
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
#line 5375 "Gmsh.y"
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
#line 5386 "Gmsh.y"
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
#line 5397 "Gmsh.y"
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
#line 5409 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 501:
#line 5415 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 502:
#line 5421 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 503:
#line 5427 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 504:
#line 5432 "Gmsh.y"
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
#line 5442 "Gmsh.y"
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
#line 5452 "Gmsh.y"
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
#line 5462 "Gmsh.y"
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
#line 5475 "Gmsh.y"
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
#line 5487 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 510:
#line 5491 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 511:
#line 5495 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 512:
#line 5499 "Gmsh.y"
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
#line 5517 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 514:
#line 5525 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 515:
#line 5533 "Gmsh.y"
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
#line 5562 "Gmsh.y"
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
#line 5572 "Gmsh.y"
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
#line 5588 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 519:
#line 5599 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 520:
#line 5604 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 521:
#line 5608 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 522:
#line 5612 "Gmsh.y"
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
#line 5624 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 524:
#line 5628 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 525:
#line 5640 "Gmsh.y"
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
#line 5657 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 527:
#line 5667 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 528:
#line 5671 "Gmsh.y"
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
#line 5686 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 530:
#line 5691 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 531:
#line 5698 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 532:
#line 5702 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 533:
#line 5707 "Gmsh.y"
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
#line 5721 "Gmsh.y"
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
#line 5738 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 536:
#line 5742 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 537:
#line 5747 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 538:
#line 5755 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 539:
#line 5761 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 540:
#line 5767 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 541:
#line 5773 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 542:
#line 5782 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 543:
#line 5786 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 544:
#line 5790 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 545:
#line 5798 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 546:
#line 5804 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 547:
#line 5810 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 548:
#line 5814 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 549:
#line 5822 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 550:
#line 5830 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 551:
#line 5837 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 552:
#line 5847 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 553:
#line 5852 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 554:
#line 5857 "Gmsh.y"
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
#line 5872 "Gmsh.y"
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
#line 5886 "Gmsh.y"
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
#line 5900 "Gmsh.y"
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
#line 5912 "Gmsh.y"
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
#line 5928 "Gmsh.y"
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
#line 5937 "Gmsh.y"
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
#line 5946 "Gmsh.y"
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
#line 5956 "Gmsh.y"
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
#line 5967 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 564:
#line 5975 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 565:
#line 5983 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 5987 "Gmsh.y"
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
#line 6006 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 568:
#line 6013 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 569:
#line 6019 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 570:
#line 6026 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 571:
#line 6033 "Gmsh.y"
    { init_options(); ;}
    break;

  case 572:
#line 6035 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 573:
#line 6043 "Gmsh.y"
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
#line 6067 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 575:
#line 6069 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 576:
#line 6075 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 577:
#line 6080 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 578:
#line 6088 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 579:
#line 6097 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 580:
#line 6106 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 581:
#line 6118 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 582:
#line 6121 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 583:
#line 6125 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13441 "Gmsh.tab.cpp"
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


#line 6128 "Gmsh.y"


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

