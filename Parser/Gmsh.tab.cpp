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
     tGMSH_MAJOR_VERSION = 456,
     tGMSH_MINOR_VERSION = 457,
     tGMSH_PATCH_VERSION = 458,
     tGmshExecutableName = 459,
     tSetPartition = 460,
     tNameToString = 461,
     tStringToName = 462,
     tAFFECTDIVIDE = 463,
     tAFFECTTIMES = 464,
     tAFFECTMINUS = 465,
     tAFFECTPLUS = 466,
     tOR = 467,
     tAND = 468,
     tNOTEQUAL = 469,
     tEQUAL = 470,
     tGREATEROREQUAL = 471,
     tLESSOREQUAL = 472,
     UNARYPREC = 473,
     tMINUSMINUS = 474,
     tPLUSPLUS = 475
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
#define tGMSH_MAJOR_VERSION 456
#define tGMSH_MINOR_VERSION 457
#define tGMSH_PATCH_VERSION 458
#define tGmshExecutableName 459
#define tSetPartition 460
#define tNameToString 461
#define tStringToName 462
#define tAFFECTDIVIDE 463
#define tAFFECTTIMES 464
#define tAFFECTMINUS 465
#define tAFFECTPLUS 466
#define tOR 467
#define tAND 468
#define tNOTEQUAL 469
#define tEQUAL 470
#define tGREATEROREQUAL 471
#define tLESSOREQUAL 472
#define UNARYPREC 473
#define tMINUSMINUS 474
#define tPLUSPLUS 475




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

double treat_Struct_FullName_dot_tSTRING_Float(char* c1, char* c2, char* c3);
char* treat_Struct_FullName_dot_tSTRING_String(char* c1, char* c2, char* c3);

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
#line 147 "Gmsh.y"
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
#line 701 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 714 "Gmsh.tab.cpp"

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
#define YYLAST   13807

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  570
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2091

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   475

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   226,     2,   238,     2,   225,     2,     2,
     231,   232,   223,   221,   240,   222,   237,   224,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     217,     2,   218,   212,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   233,     2,   234,   230,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   235,     2,   236,   239,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   213,   214,   215,
     216,   219,   220,   227,   228,   229
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
    2180,  2184,  2188,  2192,  2196,  2200,  2204,  2210,  2215,  2220,
    2225,  2230,  2235,  2240,  2245,  2250,  2255,  2260,  2267,  2272,
    2277,  2282,  2287,  2292,  2297,  2302,  2307,  2314,  2321,  2328,
    2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,
    2353,  2355,  2356,  2363,  2365,  2370,  2377,  2379,  2384,  2389,
    2394,  2401,  2406,  2411,  2415,  2418,  2421,  2427,  2433,  2437,
    2443,  2450,  2455,  2463,  2470,  2477,  2484,  2489,  2496,  2501,
    2502,  2510,  2512,  2516,  2518,  2520,  2523,  2524,  2528,  2530,
    2533,  2536,  2540,  2544,  2556,  2566,  2574,  2582,  2584,  2588,
    2590,  2592,  2595,  2599,  2604,  2610,  2612,  2614,  2617,  2621,
    2625,  2631,  2636,  2639,  2642,  2645,  2648,  2652,  2656,  2660,
    2664,  2681,  2698,  2715,  2732,  2734,  2736,  2738,  2742,  2747,
    2752,  2757,  2764,  2771,  2780,  2789,  2794,  2809,  2814,  2819,
    2821,  2823,  2827,  2831,  2841,  2849,  2851,  2857,  2861,  2868,
    2870,  2874,  2876,  2878,  2883,  2888,  2892,  2898,  2905,  2911,
    2917,  2923,  2929,  2931,  2936,  2938,  2940,  2942,  2944,  2949,
    2956,  2961,  2968,  2973,  2978,  2983,  2992,  2997,  3002,  3007,
    3012,  3021,  3030,  3037,  3042,  3049,  3054,  3056,  3061,  3066,
    3067,  3074,  3079,  3082,  3087,  3089,  3093,  3099,  3105,  3107,
    3109
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     242,     0,    -1,   243,    -1,     1,     6,    -1,    -1,   243,
     244,    -1,   246,    -1,   247,    -1,   267,    -1,   116,   231,
     339,   232,     6,    -1,   288,    -1,   289,    -1,   293,    -1,
     294,    -1,   295,    -1,   296,    -1,   300,    -1,   309,    -1,
     310,    -1,   316,    -1,   317,    -1,   299,    -1,   298,    -1,
     297,    -1,   292,    -1,   319,    -1,   218,    -1,   218,   218,
      -1,    44,   231,   339,   232,     6,    -1,    45,   231,   339,
     232,     6,    -1,    44,   231,   339,   232,   245,   339,     6,
      -1,    44,   231,   339,   240,   335,   232,     6,    -1,    45,
     231,   339,   240,   335,   232,     6,    -1,    44,   231,   339,
     240,   335,   232,   245,   339,     6,    -1,   345,   339,   235,
     248,   236,     6,    -1,   155,     4,   233,   320,   234,     6,
      -1,   156,     4,   233,   320,   234,     6,    -1,   157,     4,
     233,   320,   240,   320,   234,     6,    -1,    -1,   248,   251,
      -1,   248,   255,    -1,   248,   258,    -1,   248,   260,    -1,
     248,   261,    -1,   320,    -1,   249,   240,   320,    -1,   320,
      -1,   250,   240,   320,    -1,    -1,    -1,     4,   252,   231,
     249,   232,   253,   235,   250,   236,     6,    -1,   339,    -1,
     254,   240,   339,    -1,    -1,   162,   231,   320,   240,   320,
     240,   320,   232,   256,   235,   254,   236,     6,    -1,   339,
      -1,   257,   240,   339,    -1,    -1,   163,   231,   320,   240,
     320,   240,   320,   240,   320,   232,   259,   235,   257,   236,
       6,    -1,   164,   235,   331,   236,   235,   331,   236,     6,
      -1,   164,   235,   331,   236,   235,   331,   236,   235,   331,
     236,   235,   331,   236,     6,    -1,    -1,   165,   262,   235,
     250,   236,     6,    -1,     7,    -1,   211,    -1,   210,    -1,
     209,    -1,   208,    -1,   229,    -1,   228,    -1,   231,    -1,
     233,    -1,   232,    -1,   234,    -1,    81,   233,   269,   234,
       6,    -1,    82,   233,   273,   234,     6,    -1,   323,     6,
      -1,    88,   265,   340,   240,   320,   266,     6,    -1,    89,
     265,   345,   240,   340,   266,     6,    -1,   345,   263,   332,
       6,    -1,   345,   264,     6,    -1,   345,   265,   266,   263,
     332,     6,    -1,   345,   265,   235,   335,   236,   266,   263,
     332,     6,    -1,   345,   233,   320,   234,   263,   320,     6,
      -1,   345,   233,   320,   234,   264,     6,    -1,   345,   231,
     320,   232,   263,   320,     6,    -1,   345,   231,   320,   232,
     264,     6,    -1,   345,     7,   340,     6,    -1,   345,   265,
     266,     7,    46,   265,   266,     6,    -1,   345,   265,   266,
       7,    46,   265,   343,   266,     6,    -1,   345,   265,   266,
     211,    46,   265,   343,   266,     6,    -1,   345,   237,     4,
       7,   340,     6,    -1,   345,   233,   320,   234,   237,     4,
       7,   340,     6,    -1,   345,   237,     4,   263,   320,     6,
      -1,   345,   233,   320,   234,   237,     4,   263,   320,     6,
      -1,   345,   237,     4,   264,     6,    -1,   345,   233,   320,
     234,   237,     4,   264,     6,    -1,   345,   237,   172,   237,
       4,     7,   336,     6,    -1,   345,   233,   320,   234,   237,
     172,   237,     4,     7,   336,     6,    -1,   345,   237,   173,
       7,   337,     6,    -1,   345,   233,   320,   234,   237,   173,
       7,   337,     6,    -1,   345,   183,     7,   320,     6,    -1,
     183,   233,   320,   234,     7,     4,     6,    -1,   183,   233,
     320,   234,   237,     4,     7,   320,     6,    -1,   183,   233,
     320,   234,   237,     4,     7,   340,     6,    -1,   183,   233,
     320,   234,   237,     4,     7,   235,   335,   236,     6,    -1,
     183,   233,   320,   234,   237,     4,     6,    -1,   128,   231,
       4,   232,   237,     4,     7,   320,     6,    -1,   128,   231,
       4,   232,   237,     4,     7,   340,     6,    -1,    -1,   240,
      -1,    -1,   269,   268,   345,    -1,   269,   268,   345,     7,
     320,    -1,    -1,   269,   268,   345,     7,   235,   332,   270,
     275,   236,    -1,    -1,   269,   268,   345,   265,   266,     7,
     235,   332,   271,   275,   236,    -1,   269,   268,   345,     7,
     340,    -1,    -1,   269,   268,   345,     7,   235,   340,   272,
     279,   236,    -1,    -1,   273,   268,   339,    -1,   320,     7,
     340,    -1,   274,   240,   320,     7,   340,    -1,   334,     7,
     345,   231,   232,    -1,    -1,   240,   277,    -1,    -1,   277,
      -1,   278,    -1,   277,   240,   278,    -1,     4,   332,    -1,
       4,    -1,     4,   235,   274,   236,    -1,     4,   340,    -1,
      -1,   240,   280,    -1,   281,    -1,   280,   240,   281,    -1,
       4,   320,    -1,     4,   340,    -1,   187,   340,    -1,     4,
     235,   343,   236,    -1,   320,    -1,   340,    -1,   340,   240,
     320,    -1,   320,    -1,   340,    -1,   340,   240,   320,    -1,
     320,    -1,   340,    -1,   340,   240,   320,    -1,   320,    -1,
     340,    -1,   340,   240,   320,    -1,    -1,   175,    94,   235,
     320,   236,    -1,    -1,   121,   329,    -1,    90,   231,   320,
     232,     7,   329,     6,    -1,    93,   231,   320,   232,     7,
     332,     6,    -1,    97,   231,   320,   232,     7,   332,     6,
      -1,    91,   231,   320,   232,     7,   332,   287,     6,    -1,
      92,   231,   320,   232,     7,   332,   287,     6,    -1,   167,
     231,   320,   232,     7,   332,     6,    -1,   168,   231,   320,
     232,     7,   332,     6,    -1,   169,   231,   320,   232,     7,
     332,   171,   332,   170,   320,     6,    -1,   125,    93,   231,
     320,   232,     7,   332,     6,    -1,   108,   231,   320,   232,
       7,   332,     6,    -1,    93,     4,   231,   320,   232,     7,
     332,     6,    -1,   121,    96,   231,   320,   232,     7,   332,
       6,    -1,    96,   231,   320,   232,     7,   332,   286,     6,
      -1,   122,    96,   231,   320,   232,     7,   332,   286,     6,
      -1,    13,    14,     6,    -1,    14,    96,   320,     6,    -1,
     111,    96,   231,   320,   232,     7,     5,     5,     5,     6,
      -1,    94,   231,   320,   232,     7,   332,     6,    -1,    95,
     231,   320,   232,     7,   332,     6,    -1,    99,   231,   320,
     232,     7,   332,     6,    -1,   102,   231,   320,   232,     7,
     332,     6,    -1,   106,   231,   320,   232,     7,   332,     6,
      -1,   107,   231,   320,   232,     7,   332,     6,    -1,   100,
     231,   320,   232,     7,   332,     6,    -1,   101,   231,   320,
     232,     7,   332,     6,    -1,   118,   231,   320,   232,     7,
     332,     6,    -1,   143,   231,   320,   232,     7,   332,     6,
      -1,   125,    96,   231,   320,   232,     7,   332,     6,    -1,
     125,    96,   231,   320,   232,     7,   332,     4,   235,   331,
     236,     6,    -1,    96,     4,   231,   320,   232,     7,   332,
       6,    -1,    98,   231,   320,   232,     7,   332,     6,    -1,
     117,   231,   320,   232,     7,   332,     6,    -1,   122,   117,
     231,   320,   232,     7,   332,     6,    -1,   125,    98,   231,
     320,   232,     7,   332,     6,    -1,   124,    90,   231,   282,
     232,   263,   332,     6,    -1,   124,    93,   231,   283,   232,
     263,   332,     6,    -1,   124,    96,   231,   284,   232,   263,
     332,     6,    -1,   124,    98,   231,   285,   232,   263,   332,
       6,    -1,   132,   329,   235,   290,   236,    -1,   131,   235,
     329,   240,   329,   240,   320,   236,   235,   290,   236,    -1,
     133,   329,   235,   290,   236,    -1,   134,   235,   329,   240,
     320,   236,   235,   290,   236,    -1,   134,   235,   329,   240,
     329,   236,   235,   290,   236,    -1,     4,   235,   290,   236,
      -1,   149,    93,   235,   335,   236,    96,   235,   320,   236,
      -1,   146,    93,   231,   320,   232,   235,   335,   236,     6,
      -1,   291,    -1,   289,    -1,    -1,   291,   288,    -1,   291,
      90,   235,   335,   236,     6,    -1,   291,    93,   235,   335,
     236,     6,    -1,   291,    96,   235,   335,   236,     6,    -1,
     291,    98,   235,   335,   236,     6,    -1,   136,   121,   231,
     320,   232,     7,   332,     6,    -1,   136,    90,   231,   320,
     232,     7,   235,   331,   236,     6,    -1,   136,   121,   231,
     320,   232,     7,   235,   329,   240,   329,   240,   335,   236,
       6,    -1,   136,   121,   231,   320,   232,     7,   235,   329,
     240,   329,   240,   329,   240,   335,   236,     6,    -1,   136,
      94,   231,   320,   232,     7,   235,   329,   240,   335,   236,
       6,    -1,   136,   100,   231,   320,   232,     7,   235,   329,
     240,   329,   240,   335,   236,     6,    -1,   136,   101,   231,
     320,   232,     7,   235,   329,   240,   329,   240,   335,   236,
       6,    -1,   136,   103,   231,   320,   232,     7,   235,   329,
     240,   329,   240,   335,   236,     6,    -1,   136,   104,   231,
     320,   232,     7,   235,   329,   240,   329,   240,   335,   236,
       6,    -1,   136,     4,   231,   320,   232,     7,   332,     6,
      -1,   136,     4,   231,   320,   232,     7,     5,     6,    -1,
     136,     4,   235,   320,   236,     6,    -1,   147,   235,   291,
     236,    -1,   130,   147,   235,   291,   236,    -1,   147,   183,
     233,   320,   234,     6,    -1,   147,     4,   233,   320,   234,
       6,    -1,   147,   345,     6,    -1,   147,     4,     4,     6,
      -1,   147,    84,     6,    -1,   172,   336,   235,   291,   236,
      -1,   130,   172,   336,   235,   291,   236,    -1,   205,   320,
     235,   291,   236,    -1,   188,     5,     6,    -1,   189,     5,
       6,    -1,   188,   235,   291,   236,    -1,   130,   188,   235,
     291,   236,    -1,   189,   235,   291,   236,    -1,   130,   189,
     235,   291,   236,    -1,   345,   340,     6,    -1,    73,   231,
     343,   232,     6,    -1,   345,   345,   233,   320,   234,   339,
       6,    -1,   345,   345,   345,   233,   320,   234,     6,    -1,
     345,   320,     6,    -1,   128,   231,     4,   232,   237,     4,
       6,    -1,   166,     4,     6,    -1,   181,     6,    -1,   182,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   235,   320,   240,   320,   240,   320,   240,   320,
     240,   320,   240,   320,   236,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    78,     6,    -1,    79,     6,    -1,   113,
       6,    -1,   114,   235,   335,   236,   235,   335,   236,   235,
     331,   236,   235,   320,   240,   320,   236,     6,    -1,   186,
     231,   235,   335,   236,   240,   340,   240,   340,   232,     6,
      -1,   174,   231,   320,     8,   320,   232,    -1,   174,   231,
     320,     8,   320,     8,   320,   232,    -1,   174,     4,   175,
     235,   320,     8,   320,   236,    -1,   174,     4,   175,   235,
     320,     8,   320,     8,   320,   236,    -1,   176,    -1,   187,
       4,    -1,   187,   340,    -1,   184,    -1,   185,   345,     6,
      -1,   185,   340,     6,    -1,   177,   231,   320,   232,    -1,
     178,   231,   320,   232,    -1,   179,    -1,   180,    -1,   135,
     329,   235,   291,   236,    -1,   135,   235,   329,   240,   329,
     240,   320,   236,   235,   291,   236,    -1,   135,   235,   329,
     240,   329,   240,   329,   240,   320,   236,   235,   291,   236,
      -1,    -1,   135,   329,   235,   291,   301,   305,   236,    -1,
      -1,   135,   235,   329,   240,   329,   240,   320,   236,   235,
     291,   302,   305,   236,    -1,    -1,   135,   235,   329,   240,
     329,   240,   329,   240,   320,   236,   235,   291,   303,   305,
     236,    -1,    -1,   135,   235,   291,   304,   305,   236,    -1,
     135,   235,   291,   236,   127,   108,   235,   320,   236,    -1,
     117,   332,    -1,   122,   117,   332,    -1,   119,   235,   335,
     236,   235,   335,   236,   235,   320,   236,    -1,   306,    -1,
     305,   306,    -1,   152,   235,   320,   236,     6,    -1,   152,
     235,   332,   240,   332,   236,     6,    -1,   153,     6,    -1,
     144,     6,    -1,   144,   320,     6,    -1,   158,     6,    -1,
     158,   160,     6,    -1,   159,     6,    -1,   159,   160,     6,
      -1,   154,   231,   320,   232,     7,   332,   127,   320,     6,
      -1,   127,     4,   233,   320,   234,     6,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,    -1,   147,
       6,    -1,   130,   147,     6,    -1,   147,   320,     6,    -1,
     130,   147,   320,     6,    -1,   307,   235,   291,   308,   236,
     235,   291,   308,   236,    -1,   105,   231,   339,   232,    -1,
     307,   231,   320,   232,     7,   235,   291,   308,   236,   235,
     291,   308,   236,     6,    -1,    -1,   127,     4,   320,    -1,
      -1,     4,    -1,    -1,     7,   332,    -1,    -1,     7,   320,
      -1,    -1,   137,   332,    -1,   109,   110,   332,     7,   320,
       6,    -1,   123,    93,   333,     7,   320,   311,     6,    -1,
     123,    96,   333,   313,   312,     6,    -1,   123,    98,   333,
     313,     6,    -1,   161,   333,     6,    -1,   150,    96,   235,
     335,   236,     7,   320,     6,    -1,   144,    96,   333,   314,
       6,    -1,   144,    98,   333,     6,    -1,   145,    96,   333,
       7,   320,     6,    -1,   126,    93,   235,   335,   236,     7,
     235,   335,   236,   315,     6,    -1,   126,    96,   235,   335,
     236,     7,   235,   335,   236,   315,     6,    -1,   126,    93,
     235,   335,   236,     7,   235,   335,   236,   131,   235,   329,
     240,   329,   240,   320,   236,     6,    -1,   126,    96,   235,
     335,   236,     7,   235,   335,   236,   131,   235,   329,   240,
     329,   240,   320,   236,     6,    -1,   126,    93,   235,   335,
     236,     7,   235,   335,   236,   132,   329,     6,    -1,   126,
      96,   235,   335,   236,     7,   235,   335,   236,   132,   329,
       6,    -1,   126,    96,   320,   235,   335,   236,     7,   320,
     235,   335,   236,     6,    -1,    90,   235,   335,   236,   175,
      96,   235,   320,   236,     6,    -1,    93,   235,   335,   236,
     175,    96,   235,   320,   236,     6,    -1,    90,   235,   335,
     236,   175,    98,   235,   320,   236,     6,    -1,    93,   235,
     335,   236,   175,    98,   235,   320,   236,     6,    -1,    96,
     235,   335,   236,   175,    98,   235,   320,   236,     6,    -1,
     151,    96,   333,     6,    -1,   151,    93,   333,     6,    -1,
     115,    90,   333,     6,    -1,   115,    93,   333,     6,    -1,
     115,    96,   333,     6,    -1,   129,    93,   332,     6,    -1,
     125,    93,   332,     6,    -1,   125,    96,   332,     6,    -1,
     125,    98,   332,     6,    -1,   148,     6,    -1,   148,     4,
       6,    -1,   148,    90,   235,   335,   236,     6,    -1,   196,
      -1,   197,    -1,   198,    -1,   318,     6,    -1,   318,   235,
     332,   236,     6,    -1,   318,   235,   332,   240,   332,   236,
       6,    -1,   318,   231,   332,   232,   235,   332,   240,   332,
     236,     6,    -1,   321,    -1,   231,   320,   232,    -1,   222,
     320,    -1,   221,   320,    -1,   226,   320,    -1,   320,   222,
     320,    -1,   320,   221,   320,    -1,   320,   223,   320,    -1,
     320,   224,   320,    -1,   320,   225,   320,    -1,   320,   230,
     320,    -1,   320,   217,   320,    -1,   320,   218,   320,    -1,
     320,   220,   320,    -1,   320,   219,   320,    -1,   320,   216,
     320,    -1,   320,   215,   320,    -1,   320,   214,   320,    -1,
     320,   213,   320,    -1,   320,   212,   320,     8,   320,    -1,
      16,   265,   320,   266,    -1,    17,   265,   320,   266,    -1,
      18,   265,   320,   266,    -1,    19,   265,   320,   266,    -1,
      20,   265,   320,   266,    -1,    21,   265,   320,   266,    -1,
      22,   265,   320,   266,    -1,    23,   265,   320,   266,    -1,
      24,   265,   320,   266,    -1,    26,   265,   320,   266,    -1,
      27,   265,   320,   240,   320,   266,    -1,    28,   265,   320,
     266,    -1,    29,   265,   320,   266,    -1,    30,   265,   320,
     266,    -1,    31,   265,   320,   266,    -1,    32,   265,   320,
     266,    -1,    33,   265,   320,   266,    -1,    34,   265,   320,
     266,    -1,    35,   265,   320,   266,    -1,    36,   265,   320,
     240,   320,   266,    -1,    37,   265,   320,   240,   320,   266,
      -1,    38,   265,   320,   240,   320,   266,    -1,    25,   265,
     320,   266,    -1,     3,    -1,    10,    -1,    15,    -1,    11,
      -1,    12,    -1,   201,    -1,   202,    -1,   203,    -1,    75,
      -1,    76,    -1,    77,    -1,    -1,    83,   265,   320,   322,
     275,   266,    -1,   323,    -1,   194,   265,   339,   266,    -1,
     194,   265,   339,   240,   320,   266,    -1,   325,    -1,   345,
     233,   320,   234,    -1,   345,   231,   320,   232,    -1,   199,
     231,   325,   232,    -1,   199,   231,   325,   237,   326,   232,
      -1,   200,   231,   340,   232,    -1,   238,   345,   265,   266,
      -1,   238,   345,     9,    -1,   238,     9,    -1,   345,   264,
      -1,   345,   233,   320,   234,   264,    -1,   345,   231,   320,
     232,   264,    -1,   345,   237,   326,    -1,   345,     9,   345,
     237,   326,    -1,   345,   233,   320,   234,   237,     4,    -1,
     345,   237,     4,   264,    -1,   345,   233,   320,   234,   237,
       4,   264,    -1,   190,   231,   339,   240,   320,   232,    -1,
      56,   231,   332,   240,   332,   232,    -1,    57,   265,   339,
     240,   339,   266,    -1,    55,   265,   339,   266,    -1,    58,
     265,   339,   240,   339,   266,    -1,    63,   231,   343,   232,
      -1,    -1,    84,   325,   328,   324,   233,   276,   234,    -1,
     345,    -1,   345,     9,   345,    -1,     4,    -1,    86,    -1,
      86,   320,    -1,    -1,   231,   327,   232,    -1,   330,    -1,
     222,   329,    -1,   221,   329,    -1,   329,   222,   329,    -1,
     329,   221,   329,    -1,   235,   320,   240,   320,   240,   320,
     240,   320,   240,   320,   236,    -1,   235,   320,   240,   320,
     240,   320,   240,   320,   236,    -1,   235,   320,   240,   320,
     240,   320,   236,    -1,   231,   320,   240,   320,   240,   320,
     232,    -1,   332,    -1,   331,   240,   332,    -1,   320,    -1,
     334,    -1,   235,   236,    -1,   235,   335,   236,    -1,   222,
     235,   335,   236,    -1,   320,   223,   235,   335,   236,    -1,
     332,    -1,     5,    -1,   222,   334,    -1,   320,   223,   334,
      -1,   320,     8,   320,    -1,   320,     8,   320,     8,   320,
      -1,    90,   235,   320,   236,    -1,    90,     5,    -1,    93,
       5,    -1,    96,     5,    -1,    98,     5,    -1,   124,    90,
     333,    -1,   124,    93,   333,    -1,   124,    96,   333,    -1,
     124,    98,   333,    -1,    90,   175,    64,   235,   320,   240,
     320,   240,   320,   240,   320,   240,   320,   240,   320,   236,
      -1,    93,   175,    64,   235,   320,   240,   320,   240,   320,
     240,   320,   240,   320,   240,   320,   236,    -1,    96,   175,
      64,   235,   320,   240,   320,   240,   320,   240,   320,   240,
     320,   240,   320,   236,    -1,    98,   175,    64,   235,   320,
     240,   320,   240,   320,   240,   320,   240,   320,   240,   320,
     236,    -1,   289,    -1,   300,    -1,   309,    -1,   345,   265,
     266,    -1,    39,   233,   345,   234,    -1,    39,   233,   334,
     234,    -1,    39,   231,   334,   232,    -1,    39,   265,   235,
     335,   236,   266,    -1,   345,   265,   235,   335,   236,   266,
      -1,    40,   265,   320,   240,   320,   240,   320,   266,    -1,
      41,   265,   320,   240,   320,   240,   320,   266,    -1,    42,
     265,   339,   266,    -1,    43,   265,   320,   240,   320,   240,
     320,   240,   320,   240,   320,   240,   320,   266,    -1,   195,
     265,   334,   266,    -1,    32,   265,   334,   266,    -1,   320,
      -1,   334,    -1,   335,   240,   320,    -1,   335,   240,   334,
      -1,   235,   320,   240,   320,   240,   320,   240,   320,   236,
      -1,   235,   320,   240,   320,   240,   320,   236,    -1,   345,
      -1,     4,   237,   172,   237,     4,    -1,   235,   338,   236,
      -1,   345,   233,   320,   234,   237,   173,    -1,   336,    -1,
     338,   240,   336,    -1,   340,    -1,   345,    -1,   345,   233,
     320,   234,    -1,   345,   231,   320,   232,    -1,   345,   237,
     326,    -1,   345,     9,   345,   237,   326,    -1,   345,   233,
     320,   234,   237,     4,    -1,   124,    90,   235,   320,   236,
      -1,   124,    93,   235,   320,   236,    -1,   124,    96,   235,
     320,   236,    -1,   124,    98,   235,   320,   236,    -1,     5,
      -1,   206,   233,   345,   234,    -1,    67,    -1,   204,    -1,
      72,    -1,    74,    -1,   192,   231,   339,   232,    -1,   191,
     231,   339,   240,   339,   232,    -1,   193,   265,   339,   266,
      -1,   193,   265,   339,   240,   339,   266,    -1,    48,   265,
     343,   266,    -1,    49,   231,   339,   232,    -1,    50,   231,
     339,   232,    -1,    51,   231,   339,   240,   339,   240,   339,
     232,    -1,    46,   265,   343,   266,    -1,    60,   265,   339,
     266,    -1,    61,   265,   339,   266,    -1,    62,   265,   339,
     266,    -1,    59,   265,   320,   240,   339,   240,   339,   266,
      -1,    54,   265,   339,   240,   320,   240,   320,   266,    -1,
      54,   265,   339,   240,   320,   266,    -1,    47,   265,   339,
     266,    -1,    47,   265,   339,   240,   335,   266,    -1,    68,
     265,   339,   266,    -1,    69,    -1,    53,   265,   339,   266,
      -1,    52,   265,   339,   266,    -1,    -1,    87,   265,   340,
     341,   279,   266,    -1,    85,   265,   342,   266,    -1,   238,
     320,    -1,   345,     9,   238,   320,    -1,   339,    -1,   343,
     240,   339,    -1,     4,   239,   235,   320,   236,    -1,   344,
     239,   235,   320,   236,    -1,     4,    -1,   344,    -1,   207,
     233,   339,   234,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   246,   246,   247,   252,   254,   258,   259,   260,   261,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   299,   303,   310,   315,
     320,   334,   347,   360,   388,   402,   415,   428,   447,   452,
     453,   454,   455,   456,   460,   462,   467,   469,   475,   579,
     474,   597,   604,   615,   614,   632,   639,   650,   649,   666,
     683,   706,   705,   719,   720,   721,   722,   723,   727,   728,
     734,   734,   735,   735,   741,   742,   743,   744,   749,   755,
     817,   832,   861,   871,   876,   884,   889,   897,   906,   911,
     923,   940,   946,   955,   973,   991,  1000,  1012,  1017,  1025,
    1045,  1068,  1079,  1087,  1109,  1132,  1170,  1191,  1203,  1217,
    1217,  1219,  1221,  1230,  1240,  1239,  1260,  1259,  1277,  1287,
    1286,  1300,  1302,  1310,  1316,  1321,  1347,  1349,  1352,  1354,
    1358,  1359,  1363,  1375,  1388,  1403,  1413,  1415,  1419,  1420,
    1425,  1433,  1442,  1450,  1468,  1472,  1479,  1487,  1491,  1498,
    1506,  1510,  1517,  1525,  1529,  1536,  1545,  1548,  1555,  1558,
    1565,  1586,  1600,  1614,  1649,  1687,  1701,  1715,  1735,  1744,
    1758,  1773,  1787,  1806,  1816,  1822,  1828,  1835,  1864,  1879,
    1899,  1920,  1941,  1962,  1984,  2006,  2027,  2050,  2059,  2080,
    2095,  2109,  2125,  2141,  2150,  2160,  2170,  2180,  2195,  2207,
    2221,  2234,  2247,  2260,  2293,  2313,  2335,  2336,  2341,  2344,
    2348,  2359,  2370,  2381,  2397,  2416,  2437,  2452,  2468,  2486,
    2537,  2558,  2580,  2603,  2708,  2724,  2759,  2770,  2781,  2787,
    2802,  2830,  2842,  2851,  2858,  2870,  2889,  2895,  2901,  2908,
    2915,  2922,  2934,  3007,  3025,  3042,  3057,  3090,  3102,  3126,
    3130,  3135,  3142,  3147,  3157,  3162,  3168,  3176,  3180,  3184,
    3193,  3257,  3273,  3290,  3307,  3329,  3351,  3386,  3394,  3402,
    3408,  3415,  3422,  3442,  3468,  3480,  3492,  3508,  3524,  3541,
    3540,  3563,  3562,  3587,  3586,  3609,  3608,  3629,  3643,  3658,
    3673,  3694,  3697,  3703,  3715,  3735,  3739,  3743,  3747,  3751,
    3755,  3759,  3763,  3772,  3785,  3786,  3787,  3788,  3789,  3793,
    3794,  3795,  3796,  3797,  3800,  3821,  3838,  3858,  3861,  3877,
    3880,  3897,  3900,  3906,  3909,  3916,  3919,  3926,  3943,  3984,
    4028,  4067,  4092,  4101,  4131,  4157,  4183,  4215,  4242,  4268,
    4294,  4320,  4346,  4368,  4374,  4380,  4386,  4392,  4398,  4424,
    4450,  4467,  4484,  4501,  4513,  4519,  4525,  4537,  4541,  4551,
    4562,  4563,  4564,  4568,  4574,  4586,  4604,  4632,  4633,  4634,
    4635,  4636,  4637,  4638,  4639,  4640,  4647,  4648,  4649,  4650,
    4651,  4652,  4653,  4654,  4655,  4656,  4657,  4658,  4659,  4660,
    4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,  4669,  4670,
    4671,  4672,  4673,  4674,  4675,  4676,  4677,  4678,  4679,  4680,
    4689,  4690,  4691,  4692,  4693,  4694,  4695,  4696,  4697,  4698,
    4699,  4704,  4703,  4711,  4713,  4718,  4724,  4744,  4762,  4780,
    4792,  4802,  4808,  4824,  4830,  4836,  4855,  4876,  4909,  4931,
    4936,  4941,  4951,  4961,  4966,  4977,  4986,  4991,  4996,  5025,
    5024,  5047,  5049,  5054,  5063,  5065,  5071,  5072,  5078,  5082,
    5086,  5090,  5094,  5101,  5105,  5109,  5113,  5120,  5125,  5132,
    5137,  5141,  5146,  5150,  5158,  5169,  5173,  5185,  5193,  5201,
    5208,  5218,  5241,  5247,  5253,  5259,  5265,  5276,  5287,  5298,
    5309,  5315,  5321,  5327,  5333,  5343,  5353,  5363,  5376,  5388,
    5392,  5396,  5400,  5418,  5426,  5434,  5463,  5473,  5489,  5500,
    5505,  5509,  5513,  5525,  5529,  5541,  5558,  5568,  5572,  5587,
    5592,  5599,  5603,  5616,  5630,  5647,  5675,  5679,  5687,  5693,
    5699,  5705,  5714,  5718,  5722,  5730,  5736,  5742,  5746,  5754,
    5762,  5769,  5777,  5792,  5806,  5820,  5832,  5848,  5857,  5866,
    5876,  5887,  5895,  5903,  5907,  5926,  5933,  5939,  5946,  5954,
    5953,  5963,  5987,  5989,  5995,  6000,  6008,  6017,  6030,  6033,
    6037
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
  "tFileExists", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tGmshExecutableName", "tSetPartition",
  "tNameToString", "tStringToName", "tAFFECTDIVIDE", "tAFFECTTIMES",
  "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL",
  "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS",
  "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'", "'#'", "'~'",
  "','", "$accept", "All", "GeoFormatItems", "GeoFormatItem", "SendToFile",
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
  "DefineStruct", "@14", "Struct_FullName", "tSTRING_Member_Float",
  "Append", "AppendOrNot", "VExpr", "VExpr_Single",
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
     465,   466,    63,   467,   468,   469,   470,    60,    62,   471,
     472,    43,    45,    42,    47,    37,    33,   473,   474,   475,
      94,    40,    41,    91,    93,   123,   125,    46,    35,   126,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   241,   242,   242,   243,   243,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   245,   245,   246,   246,
     246,   246,   246,   246,   247,   247,   247,   247,   248,   248,
     248,   248,   248,   248,   249,   249,   250,   250,   252,   253,
     251,   254,   254,   256,   255,   257,   257,   259,   258,   260,
     260,   262,   261,   263,   263,   263,   263,   263,   264,   264,
     265,   265,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   268,
     268,   269,   269,   269,   270,   269,   271,   269,   269,   272,
     269,   273,   273,   274,   274,   274,   275,   275,   276,   276,
     277,   277,   278,   278,   278,   278,   279,   279,   280,   280,
     281,   281,   281,   281,   282,   282,   282,   283,   283,   283,
     284,   284,   284,   285,   285,   285,   286,   286,   287,   287,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   289,   289,
     289,   289,   289,   289,   289,   289,   290,   290,   291,   291,
     291,   291,   291,   291,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   293,   293,   293,   293,
     293,   293,   293,   294,   294,   295,   296,   296,   296,   296,
     296,   296,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   298,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   300,   300,   300,   301,
     300,   302,   300,   303,   300,   304,   300,   300,   300,   300,
     300,   305,   305,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   307,   307,   307,   307,   307,   308,
     308,   308,   308,   308,   309,   309,   310,   311,   311,   312,
     312,   313,   313,   314,   314,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   317,
     318,   318,   318,   319,   319,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   322,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   324,
     323,   325,   325,   326,   327,   327,   328,   328,   329,   329,
     329,   329,   329,   330,   330,   330,   330,   331,   331,   332,
     332,   332,   332,   332,   332,   333,   333,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   335,
     335,   335,   335,   336,   336,   336,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   341,
     340,   340,   342,   342,   343,   343,   344,   344,   345,   345,
     345
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
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     1,     4,     6,     1,     4,     4,     4,
       6,     4,     4,     3,     2,     2,     5,     5,     3,     5,
       6,     4,     7,     6,     6,     6,     4,     6,     4,     0,
       7,     1,     3,     1,     1,     2,     0,     3,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     3,     3,     3,     3,
      16,    16,    16,    16,     1,     1,     1,     3,     4,     4,
       4,     6,     6,     8,     8,     4,    14,     4,     4,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     4,     4,     3,     5,     6,     5,     5,
       5,     5,     1,     4,     1,     1,     1,     1,     4,     6,
       4,     6,     4,     4,     4,     8,     4,     4,     4,     4,
       8,     8,     6,     4,     6,     4,     1,     4,     4,     0,
       6,     4,     2,     4,     1,     3,     5,     5,     1,     1,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   568,     0,     0,     0,
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
       0,   569,     0,   208,     0,     0,     0,     0,     0,   253,
       0,   255,   256,   251,   252,     0,   257,   258,   111,   121,
     568,   456,   451,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,     0,   410,   411,   413,
     414,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   418,   419,   420,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   415,   416,   417,     0,     0,     0,     0,     0,     0,
     494,   495,     0,   496,   469,   367,   423,   426,   288,   470,
     451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,     0,
       0,   208,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,   475,     0,     0,     0,     0,
       0,   568,     0,     0,   515,     0,     0,     0,     0,   249,
     250,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   534,     0,   556,   536,
     537,     0,     0,     0,     0,     0,   535,     0,     0,     0,
       0,   267,   268,     0,   208,     0,   208,     0,     0,     0,
     451,     0,     0,   208,   363,     0,     0,    76,     0,    63,
       0,     0,    67,    66,    65,    64,    69,    68,    70,    71,
       0,     0,     0,     0,     0,     0,   521,   451,     0,   207,
       0,   206,     0,   174,     0,     0,   521,   522,     0,     0,
     564,     0,   109,   109,     0,   449,     0,     0,     0,     0,
       0,   509,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   482,     0,     0,
     483,     0,   484,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,     0,   369,   477,
     371,     0,   471,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,   435,     0,     0,     0,
       0,     0,     0,   289,     0,   321,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,   208,   208,     0,   460,   459,     0,
       0,     0,     0,   208,   208,     0,     0,     0,     0,   285,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,     0,     0,   232,     0,
       0,   230,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,   248,     0,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   270,     0,   236,     0,
     237,     0,     0,   369,     0,   208,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    72,    73,     0,
       0,   246,    38,   242,     0,     0,     0,     0,     0,   203,
       0,     0,     0,     0,     0,     0,     0,   209,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,   454,     0,     0,   452,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,     0,     0,     0,     0,     0,     0,   350,
     351,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   421,     0,     0,     0,     0,     0,   486,   487,   488,
     489,     0,     0,     0,     0,     0,     0,   368,   472,   433,
       0,   479,     0,   385,   384,   383,   382,   378,   379,   381,
     380,   373,   372,     0,   374,   478,   375,   376,   377,   452,
       0,     0,   453,   438,     0,   497,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,   144,   145,     0,   147,
     148,     0,   150,   151,     0,   153,   154,     0,   354,     0,
     355,     0,   356,     0,     0,     0,     0,   353,     0,   208,
       0,     0,     0,     0,     0,   462,   461,     0,     0,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   334,     0,     0,
     231,     0,     0,   226,     0,     0,     0,   349,   348,     0,
       0,     0,   368,     0,     0,     0,     0,     0,     0,     0,
       0,   272,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   559,     0,     0,     0,     0,     0,   238,   240,     0,
     374,     0,   570,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     0,   368,     0,    63,
       0,     0,     0,     0,    79,     0,    63,    64,     0,     0,
     452,     0,     0,   438,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,    28,    26,     0,     0,     0,
       0,     0,   453,   525,    29,     0,     0,   243,   565,    74,
     112,    75,   122,   455,   457,   128,     0,     0,     0,     0,
     511,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   409,   396,     0,   398,   399,   400,
     401,   402,   508,   403,   404,   405,     0,     0,     0,   500,
     499,   498,     0,     0,     0,   505,     0,   446,     0,     0,
       0,   448,   126,     0,   481,     0,     0,     0,     0,     0,
     424,   507,   429,     0,   431,   473,     0,   432,     0,     0,
       0,     0,   428,   427,   441,     0,     0,     0,     0,     0,
     368,   317,   322,   320,     0,   330,     0,     0,     0,     0,
       0,     0,     0,     0,   368,   368,   368,     0,     0,     0,
       0,   227,     0,   239,   241,     0,     0,     0,   198,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,   546,     0,   553,
     542,   543,   544,     0,   558,   557,     0,     0,   547,   548,
     549,   555,   562,   561,     0,   136,     0,   538,     0,   540,
     533,     0,   235,     0,     0,   310,     0,     0,     0,   364,
       0,   567,     0,     0,     0,     0,   101,    63,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,    61,     0,
      39,    40,    41,    42,    43,     0,   428,   427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,   524,   523,     0,     0,     0,     0,   133,     0,
     129,   130,     0,     0,     0,     0,     0,   158,   158,     0,
       0,     0,     0,     0,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,   386,   474,   439,   437,     0,   436,     0,     0,
       0,     0,     0,     0,     0,     0,   329,     0,   146,     0,
     149,     0,   152,     0,   155,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
     296,     0,     0,   295,     0,   298,     0,   300,     0,   286,
     292,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,   335,     0,   229,   228,   359,     0,     0,
      35,    36,     0,     0,     0,     0,   516,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,   311,     0,   312,   208,     0,     0,
     528,   529,   530,   531,     0,    86,     0,     0,     0,     0,
      84,    91,    93,     0,   519,     0,    99,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,    34,   439,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    31,     0,   526,     0,    32,     0,     0,   113,
     118,     0,     0,   132,   135,   450,     0,    77,    78,   160,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   177,
     178,     0,     0,     0,     0,   162,   190,   179,   183,   184,
     180,   181,   182,   169,     0,     0,   397,   406,   407,   408,
     501,     0,     0,     0,   444,   445,   447,   127,   422,     0,
       0,     0,     0,   443,   425,   430,   191,   440,   502,   185,
       0,     0,   156,     0,     0,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     0,     0,     0,
       0,   208,   208,     0,     0,   297,   469,     0,     0,   299,
     301,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,     0,     0,   165,
     166,     0,     0,     0,     0,   102,   106,     0,   554,     0,
       0,   552,     0,   563,     0,     0,   137,   138,   560,   539,
     541,     0,   309,   313,   309,     0,   365,    85,    63,     0,
       0,     0,     0,    83,     0,   517,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   467,     0,   440,   244,
     245,   210,   211,   212,   213,     0,     0,     0,     0,     0,
     527,     0,   114,   119,     0,     0,   509,   510,   131,     0,
       0,   159,   163,   164,   170,     0,     0,   189,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     442,     0,   171,     0,   192,   318,   194,   195,   196,   197,
     168,     0,   187,   193,     0,     0,     0,     0,     0,     0,
     466,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   223,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,   332,    37,     0,   514,     0,
       0,   264,   263,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    97,   520,     0,     0,    88,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    46,    33,     0,
     126,   136,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,   504,     0,     0,     0,
       0,     0,     0,   173,     0,   325,   325,     0,   107,   108,
     208,     0,   201,   202,   287,     0,   293,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   204,
       0,     0,     0,     0,   103,   104,   545,   551,   550,     0,
     139,     0,     0,   314,     0,    92,    94,     0,   100,     0,
      82,    89,    90,    49,     0,     0,     0,     0,   468,     0,
       0,     0,     0,     0,   116,     0,   123,     0,   343,   345,
     344,   346,     0,   347,   176,     0,     0,     0,     0,     0,
       0,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,   303,     0,     0,   281,     0,   215,
       0,     0,     0,     0,     0,     0,     0,   513,   265,     0,
     143,     0,   208,   366,     0,   518,     0,    45,     0,     0,
       0,    62,    47,     0,   115,   120,   126,     0,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
     336,     0,     0,   337,     0,   199,     0,   294,     0,   277,
       0,   208,     0,     0,     0,     0,     0,     0,   167,   105,
     261,   309,    98,     0,     0,     0,     0,     0,     0,   124,
     125,     0,     0,     0,     0,     0,     0,   188,     0,   340,
       0,   341,   342,   463,     0,     0,   283,   218,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,    59,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   282,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
     216,   316,    50,     0,    57,     0,   254,     0,   506,     0,
       0,     0,     0,     0,     0,   284,     0,     0,    51,     0,
       0,   260,     0,     0,     0,     0,     0,     0,   217,     0,
       0,     0,     0,   490,   491,   492,   493,     0,     0,    54,
      52,     0,    55,     0,   338,   339,     0,     0,    60,    58,
      56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1007,   109,   110,   989,  1770,  1776,
    1260,  1462,  1916,  2057,  1261,  2022,  2081,  1262,  2059,  1263,
    1264,  1466,   401,   546,   547,  1071,   111,   723,   422,  1780,
    1926,  1781,   423,  1665,  1332,  1289,  1290,  1291,  1429,  1616,
    1617,   855,   858,   861,   864,  1513,  1503,   707,   250,   410,
     411,   114,   115,   116,   117,   118,   119,   120,   121,   251,
    1164,  1950,  2013,   892,  1160,  1161,   252,   966,   253,   125,
    1355,  1124,   853,   906,  1886,   126,   127,   128,   129,   254,
     255,  1092,   256,   728,   257,   843,   727,   425,   578,   290,
    1645,   325,   326,   259,   523,   333,  1248,  1455,   420,   416,
    1215,   949,   421,   131,   380
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1741
static const yytype_int16 yypact[] =
{
   10499,    72,   113, 10648, -1741, -1741,   307,   118,   -62,   -92,
     -77,    33,   157,   181,   196,   214,    56,   345,   357,    86,
     205,    97,  -168,  -168,   328,   139,   218,    22,   237,   253,
      38,   267,   284,   314,   336,   400,   410,   421,   429,   446,
     457,   361,   492,   594,   390,   128,   468,  5433,   504,   511,
     655,   -53,   404,    66,   638,   126,   521,   672,   -95,   552,
     -27,   -27,   591,   242,   375, -1741, -1741, -1741, -1741, -1741,
     553,   140,   735,   744,    16,    47,   753,   775,   583,   874,
     913,   920,  4746,   923,   707,   713,   714,    20,    52, -1741,
     724,   733, -1741, -1741,   964,   970,   756, -1741,  4850,   760,
    5079,    31,    32, -1741, -1741, -1741,  9468,   767, -1741, -1741,
   -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741,
   -1741, -1741, -1741,   339, -1741, -1741, -1741, -1741,    51, -1741,
     975,   762,  4515,   313,   768,   996,  9468,  4604,  4604, -1741,
    9468, -1741, -1741, -1741, -1741,  4604, -1741, -1741, -1741, -1741,
     780,   789,  1019, -1741, -1741,  5308,    97,  9468,  7952,  9468,
    9468,   802,  9468,  7952,  9468,  9468,   805,  9468,  7952,  9468,
    9468,  9468,  9468,  9468,  9468,  4604,  9468,  9468,  9468,  5662,
     807, -1741,  7952,  4746,  4746,  4746,  4604, -1741, -1741, -1741,
   -1741, -1741,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,    75,  -168,  -168,  -168,  -168,
    -168,   835,  -168,  -168,   836, -1741, -1741, -1741,  -168,    26,
      14,    17,    28,  5662,   951,    95,   863,  -168,  -168,   868,
     875, -1741, -1741, -1741,  9468,  5891,  9468,  9468,  6120,    37,
   -1741, -1741,   849, -1741,   945, -1741, -1741, -1741, -1741, -1741,
      94,  9468,  7952,   876,   877,  6349,  4746,  4746,  4746,   879,
     880,   881,   884,  6578,  6807,  7036,   870,  8799,  1112,  5662,
     882,    20,   883,   885,   -27,   -27,   -27,  9468,  9468,   -97,
   -1741,    -6,   -27,  8869,   235,   393,   888,   890,   893,   894,
     895,   896,   898,  9468,  4746,  4746,  4746,   899,     4,  1117,
     900, -1741,  1126,  1142, -1741,   914,   918,   919,  4746,  4746,
     939,   940,   943, -1741,  9468, -1741,  1149,  1150,  9468,  9468,
    9468,   479,  9468,   942, -1741,  1003,  9468,  9468,  9468, -1741,
   -1741,  9468, -1741,  -168,  -168,  -168,   948,   949,   950,  -168,
    -168,  -168,  -168,  -168,  -168,  -168, -1741,  -168, -1741, -1741,
   -1741,  -168,  -168,   952,   956,  -168, -1741,   955,  1176,  1183,
     958, -1741, -1741,  1184, -1741,  1188, -1741,  -168,  9468, 11986,
     131,  4604,  9468, -1741, -1741,  5662,  5662, -1741,   961,  5308,
     608,  1190, -1741, -1741, -1741, -1741, -1741, -1741,  9468,  9468,
      24,  5662,  1192,   589,   172,   966,  1193,    21,   967, -1741,
     969, 10851,  9468, -1741,   922,  -113, -1741,    74,   178,  3721,
   -1741,   188,   -50,    90,  1120, -1741,    97,   963,   968,  2312,
    7952,  2751, -1741,   423,  2478, 12380,  9468, 12401,   483, 12422,
   12443,  9468, 12464,   488, 12485, 12506, 12527, 12548, 12569, 12590,
     977, 12611, 12632, 12653,  1203,  9468,   497,  1206,  1208,  1210,
     985,  9468,  9468,  9468,  9468,  9468,  9468,  9468,  9468,  9468,
    9468,  9468,  9468,  9468,  9468,  9468,  9468,  7952,  9468,  9468,
    9468,  9468,  9468,  9468,  7952,  7952,   983,  9468,  9468,  4604,
    9468,  4604,  5662,  4604,  4604,  4604,  9468, -1741,  1155,  9468,
   -1741,  1156, -1741,  1157, -1741,  1158,  5662,  4746,  4746,  4746,
    4746,  4604,  4604,  7952,    97,  5308,   993,  7952,   993, -1741,
     993, 12674, -1741,   530, -1741,    63,  9468,  9468,  9468,  9468,
    9468,  9468,  9468,  9468,  9468,  9468,  9468,  9468,  7265,  9468,
    9468,  9468,    97,  9468,  9468,  1220, -1741,   613, 12695,   546,
    9468,  9468,  9468, -1741,  1219,  1221,  1221,  8575,  8575,  8575,
    8575,  9468,  1223,  9468,  1224,  9468,  1225,  7952,  7952, 12010,
     995,  1226, -1741,   998, -1741, -1741,  -135, -1741, -1741,  3945,
    4041,   -27,   -27,   313,   313,  -114,  8869,  8869,  9468,  3534,
    -110, -1741,  9468,  9468,  9468,  9468,  9468,  9468,  9468,  9468,
    9468, 12716,  1227,  1229,  1231,  9468,  1230,  9468, -1741,  9468,
    3694, -1741, -1741,  7952,  7952,  7952,  1233,  1234,  9468,  9468,
    9468, 12737, -1741, -1741, 12758, 12779, 12800,  1069,  4224, -1741,
    1007,  2876, 12821, 12842, 12081,  4604,  4604,  4604,  4604,  4604,
    4604,  4604,  4604,  4604,  9468,  4604,  4604,  4604,  4604,    10,
    5308,  4604,  4604,  4604,    97, -1741, -1741,  7952, -1741,  9617,
   -1741,  9671,  9468,   993,  9468, -1741,  9468,  9468,  1009, 12863,
   10787,  1013,   593,  9468,  1240,  1012,  1014,  1015,  1016,  9468,
   12884, 12104,   340,  1017,  1245,  1247, -1741, -1741, -1741,  7952,
     164, -1741, -1741, -1741,    97,  9468,  9468,  1220,  1022, -1741,
     601,    44,    50,   607,  1025,   -49,   685, -1741, 11186, -1741,
      15,  7952,    97,  9468,  9468,  1253,  1252,  7952,  9468,  1254,
    4604,  1256, -1741,    97,  1259,  4604,  9468,  1027,  1030, -1741,
    9468,  5308,  1275,  7952,  1091,  7952,  1276,  1277, 12905,  1280,
    1113,  1282,  1283, 12926,  1284,  1118,  1285,  1287,  1288,  1290,
    1291,  1292, -1741,  1293,  1294,  1296,  9468, 12947,  1071, -1741,
   -1741, -1741,  1298, 12058, 12058, 12058, 12058, 12058, 12058, 12058,
   12058, 12058, 12058, 12058,  4398, 12058, 12058, 12058, 12058,   670,
     367, 12058, 12058, 12058,  5371,  5600,  5829,  2751,  1075,  1074,
     124,  7952,  6058,  6287,   367,  6516,   367,  1070,  1073,  1092,
     221, 13577,  1080, 11211,  1116,  1124,  1130, -1741, -1741, -1741,
   -1741,  1115,  -130,   367,   -71,  1121,   603,  1354, -1741, -1741,
     367,  2951,  3257,   691,   635,   539,   539,   362,   362,   362,
     362,   549,   549,  7952,   993, -1741,   993,   993,   993,  1129,
   12968, 12127,   387, -1741,  7952, -1741,  1361,  1135, 12989, 13010,
   13031,  9468,  5662,  1367,  1366,  1141, 13577,  1134,  1143, 13577,
    1136,  1145, 13577,  1138,  1148, 13577,  1144, 13052, -1741, 13073,
   -1741, 13094, -1741,   604,   627,  7952,  1146, -1741,  9767, -1741,
    9821,  9917,   -27,  9468,  9468, -1741, -1741,  1151,  1152,  8869,
    3028,  1255,   403,   -27,  9971, 13115, 11236, 13136, 13157, 13178,
   13199, 13220, 13241, 13262,  1374,  9468,  1380, -1741,  9468, 13283,
   -1741, 12150, 12173, -1741,   628,   633,   634, -1741, -1741, 12196,
   12219,  6745, -1741,  1382,  1384,  1385,  1159,  9468, 10067,  9468,
    9468, -1741, -1741,    43,   -88,   137,   -88,  1161,  1162,  1160,
     367,   367,  1163,  6974,   367,   367,   367,   367,  9468,   367,
    1388, -1741,  1164,  1167,   389,  1168,   639, -1741, -1741, 12058,
     993, 10121, -1741,  1398,  1260,  9099,  1170,  1173,  1403,  5662,
   11261, -1741,  9468,  9468,  9468,  9468,  1056,   369,    81,  5308,
    9468,  1404,  1407,    25, -1741,   640,  1368,  1370,  5662,     5,
    1175, 13304, 12242,  1178,  9468,  7952,  7952,  7952,  7952,  9468,
    1186,  1187,  1191,  1195, -1741, -1741,  1201,  4604,   240,  1196,
   13325, 12265, -1741, -1741, -1741,   261,  7203, -1741, -1741, -1741,
      62, -1741, -1741, 13577, -1741,  1417, 12058,   367,   -27,   629,
    2751, -1741,  5662,  5662,  1416,  5662,   679,  5662,  5662,  1421,
    5662,  1326,  5662,  5662,  5662,  5662,  5662,  5662,  5662,  5662,
    5662,  1122,  1422,  7952, -1741, -1741, -1741, -1741, -1741, -1741,
   -1741, -1741, -1741, -1741, -1741, -1741,  9468, -1741, -1741, -1741,
   -1741, -1741, -1741, -1741, -1741, -1741,  9468,  9468,  9468, -1741,
   -1741, -1741,   661,  9468,  9468, -1741,  9468, -1741,  5662,  4604,
    4604, -1741,  1194,  9468, -1741,  9468,  9468,  9468,  9468,  9468,
   -1741, -1741, -1741,  1253, -1741, -1741,  5662, -1741,  9468,  9468,
     663,  1253,   387,  -167, -1741,   683,  5662,  7952,  1423,  1425,
    1428,   793, -1741, -1741,  1430, -1741,   198,  9468,   198,  9468,
     198,  9468,   198,  9468,  1431,  1433,  1434,  1435,  1436,   686,
    1440, -1741, 10217, -1741, -1741,  -104,  7432,  7661, -1741, -1741,
   11286,  -163,  1329,  1441,  9174,  1211,  1442,  1216,    49,    54,
     -78, -1741,   -99, -1741,   403,  1444,  1443,  1445,  1447,  1448,
    1451,  1452,  1453,  1454,  5662, 13577, -1741,  1476,  1228,  1458,
    1459,  1463,  1375,  1465,  1464,  1467,  9468,  5662,  5662,  5662,
    1470,  7890, -1741,  3316,   858,  1471,  1472, -1741,  7952, -1741,
   -1741, -1741, -1741,  4604, -1741, -1741,  9468,  4604, -1741, -1741,
   -1741, -1741, 13577, -1741,  1241,  1238,  4604, -1741,  4604, -1741,
   -1741,  1243, -1741,  1246,  9398, -1741,  1535,  1249,  5662, -1741,
    1250, -1741, 11311, 11336, 11361, 11386, -1741, -1741,  9468,  1481,
      34,  9468,  1482,  1484,  1671, -1741,  1485,    20,  1487,  1258,
     367,  -168,  -168,  1488, -1741,  1264,  1265,  1262, -1741,  1492,
   -1741, -1741, -1741, -1741, -1741,  1253,   303,  2175, 12288,   694,
     695,   696,   697, 13346,  9468,  9468,  9468,  9468, -1741,  1493,
      29,  1253, -1741,  1263,  1495,  9468,  8176,   367,  4007,  1269,
    1266, -1741,  1498,  1502,    76,  1274,  1278,  1389,  1389,  5662,
    1505,  1279,  1281,  1506,  1509,  5662,  1342,  1286,  1512,  1514,
    1516,  1517,  1518,  1519,  1520,  1521,  1522, -1741,  1524,   703,
   12058, 12058, 12058, 12058,   367,  8203,  8517,  8628,  1299,   367,
     367,  1417,   367,  8698,  8742,  8826,  8928, 13367, 12058,  1302,
    1529, 13577, 13577, -1741, -1741, -1741,  1526, -1741,   367,  1530,
     720,  5662,  5662,  5662,  1533,  1534, -1741,  5662, 13577,  5662,
   13577,  5662, 13577,  5662, 13577,  5662,  5662,  5662,  1304,  1307,
    1536,   394, -1741,  9468,  9468,  9468,  1323,  1324,  1328,  1338,
   -1741,  1713,  5662, -1741,  9468, -1741,  1559, -1741,  1567, -1741,
   -1741,  8869,   -38,  4975, -1741,  1339,  1340,  1341,  1344,  1345,
    1346,  7494,  1571, -1741,  7952, -1741, -1741, -1741,  1347,  9468,
   -1741, -1741, 12311,  1580,  1581,  1419, -1741,  9468,  9468,  9468,
   -1741,  1582,   664,   473,  1351,  1332,  1352,  9468,    23,   367,
    1362,   367,  5308, -1741, -1741,  1786, -1741, -1741,  1355,  1590,
   -1741, -1741, -1741, -1741,  1805, -1741,   398,  1360,  1592,  1935,
   -1741, -1741, -1741,    20, -1741,   721, -1741,  9468,   198,  3063,
    4604, -1741,  1369,  9468,  9468,  5662,  1372, -1741,  1373,  1597,
    1596,  1598,  1599,  1604,  1605,  1607,  1354, 13388, 13409, 13430,
   13451, -1741, -1741,  4604, -1741,  1610, -1741,  9003,  4286, 13577,
   -1741,  1608,  6120, -1741, -1741, -1741,  1417, -1741, -1741, -1741,
    9468,  9468,   -27,  1612,  1613,  1614, -1741,  9468,  9468, -1741,
   -1741,  1615,  1540,  1631,  9468, -1741, -1741, -1741, -1741, -1741,
   -1741, -1741, -1741, -1741,  1611,  1406, -1741, -1741, -1741, -1741,
   -1741,  9468,  9468,  9468, -1741, -1741, -1741,  1266, -1741,  9468,
    9468,  9468,  9468, -1741, -1741, -1741, -1741,   387, -1741, -1741,
    1408,  1633,  1342,  1641,  9468, -1741,  1642,  1643,  1644,  1645,
    1647,   892,  1648,  7952,  7952,  9468, -1741,  8575, 11411, 13472,
    3356,   313,   313,  9468,  9468, -1741,   120,  1363, 13493, -1741,
   -1741, 11436,   159, -1741,  1649,  1650,  5662,   -27,   -27,   -27,
     -27,   -27,  5204,  1651, -1741,   727,  9468,  2099,  1652, -1741,
   -1741,  5662,  3608,   304, 13514, -1741, -1741,  8261, -1741,  4604,
    9468, -1741,  4604, 13577,  8490,  5308,  1424, -1741, -1741, -1741,
   -1741,  1426, 10787, -1741, 10787,  5662, -1741, -1741,  5308,  9468,
    1656,  1659,    25, -1741,  1661, -1741,    20, 12334,  5662,  1662,
     -88,   -88,  9468,  9047,  9126,   729, -1741,  9468,   308, -1741,
   -1741, -1741, -1741, -1741, -1741,  1428,  1431,  1433,  1434,  1663,
   -1741,  9468, -1741, -1741,  1439,   737,  2673,  1658, -1741, 11461,
   11486,   489, -1741, -1741, -1741, 11511, 11536, -1741,  1446, -1741,
   11561,  1665,  5662, 12058, 12058,  9227,  9297,  9341,  9425,  9585,
   -1741,  9468, -1741,  1669, -1741, 13577, -1741, -1741, -1741, -1741,
   -1741,  1449, -1741, -1741,   739,   742, 12034,  2363,  1670,  1450,
   -1741, -1741,  9468,  1466,  1468, 11586, 12357,  1672,  5662,  1664,
    1473,  9468, -1741, -1741,   747,   191,   200,   203,   211,   215,
    7723,   220, -1741,  1676, 11611, -1741, -1741,  1513, -1741,  9468,
    9468, -1741, -1741,  7952,  2500,  1697,  1475, 12058,   367,  4604,
   13577, -1741, -1741,    23,  5308,  1469,  1474,  1477,  1703,  2555,
   -1741,  1705,  1710, -1741, -1741,  1480,  1712, -1741,  1714,  1715,
     301, 13577,  9468,  9468,  1489,  5662,   748, 13577, -1741,  9735,
    1194,  1238,  5662, -1741,  9468,  5308,    97,  1716,  1717,  1720,
    1722,  9468,  1723,  1724,   750, -1741, -1741,  9468,  9468,  9468,
    9468,  9468, 11636, -1741,  5662,   298,   535,  7952, -1741, -1741,
     313,  3760, -1741, -1741, -1741,  1725, -1741,  1496,  5662, -1741,
   11661,  1727,  7952,   -27,   -27,   -27,   -27,   -27, -1741, -1741,
    9468, 11686, 11711,   785, -1741, -1741, -1741, -1741, -1741,   786,
   -1741,  1503,  1501, -1741,  1731, -1741, -1741,    20, -1741,  1565,
   -1741, -1741, -1741, -1741,  9468,  9885, 10035,  5662, -1741,  1733,
    9468,  9468,  1507,  1525, -1741,  1857, -1741,  1531, -1741, -1741,
   -1741, -1741, 11736, -1741, -1741,  1510, 10185, 10302, 10336, 10765,
   10809, -1741,   791,  1528,   -27,  5662,  1758,  1538,   -27,  1760,
     812,  1532, -1741,  9468, -1741,  1763,  1653, 10271,  1541, -1741,
     813,   245,   273,   350,   354,   447,  2593, -1741, -1741,  1765,
   -1741,  1769, -1741, -1741,  1771, -1741,  1543, 13577,  9468,  9468,
     815, -1741, 13577, 10838, -1741, -1741,  1194,  5308,  1549, -1741,
    9468,  9468,  9468,  9468,  9468,  9468,  1776,   -27,    92, -1741,
   -1741,   -27,   145, -1741,  1778, -1741, 11761, -1741,  9468, -1741,
     403, -1741,  1779,  7952,  7952,  7952,  7952,  7723, -1741, -1741,
   -1741, 10787, -1741,  9468, 13535, 10867,    39,  9468,  1550, -1741,
   -1741, 10896, 10925, 10954, 10983, 11012, 11041, -1741,   452, -1741,
     460, -1741, -1741, -1741,  2651,   503, 10367, -1741,   818,   820,
     821,   823,   472,   829,  1551,   853, -1741,  9468, -1741,  5662,
   11786, -1741,  9468,  9468,  9468,  9468,  9468,  9468,   -27,   -27,
   -1741, -1741, -1741,   403,  1782,  1783,  1784,  1785,  7952,  1787,
    1788,  1790,  1562, 13556,   855,  1792, 11811, 12058, 11070, 11099,
   11128, 11157,   475,   481,   531, -1741, -1741, -1741, -1741,   856,
   -1741, -1741, -1741,  4604, -1741,  1568, -1741,  1794, -1741,  9468,
    9468,  9468,  9468,  9468,  9468, -1741,  1796,   861, -1741,  1570,
    5662, -1741, 11836, 11861, 11886, 11911, 11936, 11961, -1741,  1800,
    4604,  4604,   862, -1741, -1741, -1741, -1741,  1801,  1803, -1741,
   -1741,   864, -1741,  1804, -1741, -1741,  1806,  4604, -1741, -1741,
   -1741
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1741, -1741, -1741, -1741,   533, -1741, -1741, -1741, -1741,  -149,
   -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741,
   -1741, -1741,  -678,  -116,   597,  1970, -1741,  1393, -1741, -1741,
   -1741, -1741, -1741, -1741, -1740, -1741,   486,   322,    40, -1741,
      67, -1741, -1741, -1741, -1741,   270,   525,  1823,    -2,  -573,
    -226, -1741, -1741, -1741, -1741, -1741, -1741, -1741, -1741,  1824,
   -1741, -1741, -1741, -1741, -1132, -1157,  1825, -1607,  1826, -1741,
   -1741, -1741,  1289, -1741,    27, -1741, -1741, -1741, -1741,  1953,
   -1741, -1741,  1828, -1741,   -15,  -692, -1741, -1741,    36, -1741,
   -1573,   279,   -93,  1257,  2445,  -279,   202, -1741,   102,    45,
   -1741, -1741,  -488, -1741,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -528
static const yytype_int16 yytable[] =
{
     132,   113,   573,  1390,   980,   993,   151,   800,   606,  1254,
     887,   888,   988,  1724,   150,  1755,   402,  1756,   152,   500,
     308,  1005,   502,  1013,   331,   150,   161,  1614,   682,   150,
     694,   497,  1392,   504,   136,  1482,   373,   375,  1446,   139,
    1862,   150,   166,   264,   260,  1998,   524,   264,   161,  1153,
    1195,   313,   280,   314,   166,  1385,   335,   384,   581,   582,
    1387,   396,   397,   153,   265,   154,  1154,   589,  1000,  1286,
    1346,   312,   819,  1377,  1155,  1156,  1157,   281,     4,   260,
    1158,  1159,  1499,   712,   334,   610,   581,   582,  1237,  1153,
     457,   458,   459,   282,   283,   369,   289,   291,  1979,   294,
     309,   150,   687,   542,   688,   882,  1154,   581,   582,  1794,
    1099,   581,   582,     5,  1155,  1156,  1157,   581,   582,   710,
    1158,  1159,   581,   582,   581,   582,   889,   711,   526,   407,
     893,   409,   135,   542,   417,   417,  1373,   315,   583,   137,
     542,  1391,   417,   368,   687,   372,   688,   934,   659,   936,
     661,  1981,   720,   428,   138,   260,   269,   670,  1389,   270,
     260,  1102,   271,   141,   272,   260,  1103,  1255,  1256,  1257,
    1258,   986,   417,   554,   555,   556,   260,   406,   691,   260,
     260,   260,   260,   417,   721,   507,  1968,   142,   508,   501,
     722,   509,   503,   510,   285,   286,   683,   684,  1583,   310,
     427,   498,   143,   505,   287,  1237,  1447,  1448,   288,  1386,
    1615,   602,   603,   604,  1388,   581,   582,   107,   183,   276,
     144,   184,   277,   107,   185,   616,   617,   107,   107,   584,
     260,  1882,   107,  1006,   405,  1390,   304,   607,   305,   415,
     418,  1259,   260,   134,   107,   260,   525,  1006,   948,   396,
     397,   311,   695,   162,   696,   332,  -522,   163,   697,   260,
    1247,   499,   260,   260,   260,   260,   374,   376,   140,   167,
     260,   260,   260,   168,  1999,   162,   260,   450,   334,   996,
    1196,   167,   385,   336,  1920,   997,   386,   145,   460,   392,
     393,   394,   395,   153,   153,   154,   154,   581,   582,  1238,
    1241,   260,   260,   260,   107,   713,   484,   714,   485,   396,
     397,   715,  1740,   581,   582,   260,   260,   408,  1240,   148,
     576,   577,   396,   397,   724,   543,   258,   544,   585,   590,
     722,   545,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   878,   979,   880,   881,
     541,   146,   396,   397,  1994,   543,  1717,   544,  1081,   396,
     397,   545,   666,   147,   667,   894,   581,   582,   545,   687,
     159,   688,   392,   393,   394,   987,  1237,  1198,   417,   295,
     581,   582,   260,   260,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,   260,  1721,
    1566,  1567,   541,   928,   698,  1628,   392,   393,   394,   395,
     716,  1339,   581,   582,   807,   808,   809,   810,   717,  1344,
     719,   581,   582,   729,   581,   582,  2024,   260,   720,  1883,
    1884,  1822,   581,   582,   674,  1885,   581,   582,   149,   961,
    1823,   581,   582,  1824,    59,    60,    61,    62,  1357,   160,
    1359,  1825,  1361,  1091,  1363,  1826,   581,   582,   454,    73,
    1827,   720,    76,   285,   286,   296,   581,   582,   164,   297,
     591,   179,  1280,   287,   260,   298,   299,   293,   300,   301,
     735,   260,   790,   668,   165,  1953,   417,  2072,   417,   260,
     417,   417,   417,  1284,   581,   582,   302,   266,   169,   814,
     267,   735,   268,   260,   260,   260,   260,   260,   417,   417,
     260,   152,   258,  1954,   260,   170,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
    1153,   396,   397,  1853,   541,   260,   396,   397,  -524,   839,
    1741,  1854,   133,  -527,   553,   171,   134,  1154,   392,   393,
     394,   395,   562,   564,   566,  1155,  1156,  1157,   571,   157,
     815,  1158,  1159,   158,   260,   260,   981,   172,   396,   397,
     382,   581,   582,  1468,   383,   581,   582,   392,   393,   394,
     395,   409,   409,   536,   537,   664,   539,   540,   180,  1484,
    1955,   794,   541,   796,  1956,   798,   799,   396,   397,   687,
     181,   688,   857,   860,   863,   866,   392,   393,   394,   395,
     260,   260,   260,   811,   812,   396,   397,   885,   886,   155,
     156,   687,   577,   688,   592,   182,   396,   397,   593,  1218,
    1153,   173,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   174,   417,   417,   417,   417,   950,  1154,   417,   417,
     417,   955,   175,  1142,   260,  1155,  1156,  1157,  1153,   734,
     176,  1158,  1159,   735,   671,   672,  1887,  1888,   581,   582,
    1606,  1607,  1885,   581,   582,  1154,   318,   177,   526,   319,
     685,   581,   582,  1155,  1156,  1157,   260,  1957,   178,  1158,
    1159,   990,  2008,   581,   582,   951,   581,   582,   675,   186,
    2009,   676,   581,   582,   677,   687,   678,   688,   260,  1009,
     581,   582,  2018,   735,   260,  2053,   627,   417,   134,   740,
    1020,  2054,   417,   735,   745,  1295,  1114,  1296,   735,   403,
     260,   273,   260,   758,   274,   261,   275,   735,   935,  2011,
     937,   938,   939,   940,   941,   942,   262,   944,   945,   946,
     947,   263,   278,   952,   953,   954,   532,   533,   534,   535,
     536,   537,   664,   539,   540,   279,   818,  2055,  1629,   541,
     735,   797,   664,   539,   540,  1301,  1027,  1302,  1001,   541,
    1638,  1002,   847,  1003,   303,   553,   735,   284,   260,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   486,   487,   488,   489,   490,   491,  1985,   493,
     494,   687,  1018,   688,   689,   496,   292,  1022,  1390,   968,
     260,   306,   157,   969,   512,   513,   995,   307,   170,  1105,
    1137,   260,   998,   735,   735,   687,   316,   688,   844,   260,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,  1239,  1242,  1138,  1181,   541,  1419,   735,   735,  1182,
    1183,   317,   260,   735,   735,  1221,  1250,  1390,   320,   735,
     735,  2034,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   733,   539,   540,  1701,  1324,  1702,  1343,
     541,   735,   687,   735,   688,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,   321,  1145,  1348,
    1354,   541,  1370,   735,   322,  1151,   735,   327,   709,  1162,
    1472,  1473,  1474,  1475,   735,   735,   735,   735,   328,  1525,
     635,   636,   637,   735,   329,   330,   641,   642,   643,   644,
     645,   646,   647,   526,   648,   337,  1550,  1635,   649,   650,
     735,  1636,   653,  1733,   338,  1774,   260,   735,  1454,  1775,
     339,  1640,  1641,  1783,   662,  1805,   340,  1784,  1806,   735,
    1249,   387,   735,  1821,  1859,   260,  1875,  1775,  1860,   341,
    1775,   370,   260,   260,   260,   260,  1345,  1347,  1713,  1714,
     381,   388,   413,   412,   417,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,   134,
     424,  1909,  1910,   541,  1243,   735,   720,  1936,   426,   260,
     260,  1775,   260,   436,   260,   260,   441,   260,   455,   260,
     260,   260,   260,   260,   260,   260,   260,   260,  1944,  1952,
     260,  1966,   735,   735,  2014,  1775,  2015,  2016,   735,  2017,
     735,   735,  1236,   735,  1294,  2019,   492,   495,   506,   735,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,   383,   260,   417,   417,   541,  2021,
    1420,  2045,  2056,  1860,   511,  1775,   735,  2069,  2083,   514,
    2086,  2070,  1775,   260,  2087,   567,   515,   550,   551,  1279,
     557,   558,   559,   260,   260,   560,   570,   572,   574,   594,
     575,   595,   820,   608,   596,   597,   598,   599,  1317,   600,
     605,  1122,   611,   609,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,   612,   613,
    1345,  1347,   541,   614,   615,   622,   623,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   260,   618,   619,  1634,   541,   620,   629,   630,   638,
     639,   640,   655,   651,   260,   260,   260,   652,   654,   656,
     658,  1329,  1330,   657,   660,   260,   673,   679,   686,   693,
     417,   692,   133,   730,   417,   699,   726,  1622,   731,   752,
     756,  1624,   759,   417,   760,   417,   761,   762,   791,   802,
     804,   805,   806,   541,   842,   260,   851,   876,   852,   868,
     870,   872,   877,   879,   905,   907,   910,  1891,   908,   917,
     918,   926,   929,   962,   334,   967,   971,   972,  1230,   973,
     974,   975,   983,   984,   982,   994,   999,  1012,  1014,  1024,
    1017,  1839,  1019,  1025,   417,  1021,  1029,  1253,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,  1028,  1032,  1033,   260,   541,  1035,  1036,  1037,
    1038,  1040,  1042,  1041,  1043,  1044,   260,  1045,  1046,  1047,
    1048,  1049,   260,  1050,  1054,  1424,  1053,  1079,  1080,  1426,
    1088,  1297,  1298,  1089,  1300,  1093,  1303,  1304,  1430,  1306,
    1431,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1630,  1490,  1090,  1494,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,   260,   260,
     260,  1095,   541,  1104,   260,  1098,   260,  1764,   260,  1096,
     260,  1106,   260,   260,   260,  1097,  1111,  1328,  1116,  1470,
    1117,  1123,  1125,  1126,  1127,  1128,  1129,  1130,  1131,   260,
    1132,  1174,  1152,  1140,  1133,  1340,  1176,  1148,  1149,  1187,
     260,  1188,  1189,  1201,  1202,  1349,  1190,  1214,   260,  1217,
    1203,   260,  1220,  1206,  1216,  1223,  1227,  1224,  1228,  1229,
    1245,  1246,  1265,  -525,  1251,   432,  1252,  1274,  1275,  1278,
     432,  1288,  1276,  1299,  1307,   432,  1277,  1582,  1305,  1318,
    1351,  1690,  1352,  1281,  1331,  1353,  1356,  1378,  1365,   432,
    1366,  1367,  1368,  1369,  1371,  1379,  1382,  1384,  1383,  1394,
     334,  1393,  1395,  1402,  1396,  1397,   417,   417,  1398,  1399,
    1400,  1401,   260,  1404,  1405,  1406,  1413,  1414,  1415,  1407,
    1410,  1408,  1409,  1411,  1416,  1421,  1422,  1621,  1428,  1427,
     417,  1433,  1403,  1432,  1437,   260,  1439,  1445,  1450,   260,
    1451,  1457,  1453,  1456,  1461,  1463,  1464,  1465,  1467,  1481,
    1485,  1486,   519,  1495,  1497,   432,  1496,  1438,  1498,  1500,
    1502,  1506,  1509,  1501,  1507,  1510,  1508,  1512,  1515,   432,
    1516,  1514,  1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,
    1547,  1534,  1690,  1663,  1545,  1546,  1549,  1554,  1671,  1563,
    1555,  1436,  1564,  1565,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,  1571,  1572,
     260,   260,   541,  1573,   687,  1579,   688,  1493,  1914,   409,
     409,  1574,  1610,  1580,  1586,  1587,  1588,  1594,  1505,  1589,
    1590,  1591,  1596,   260,  1511,  1659,  1599,  1600,  1605,   260,
    1601,  1609,  1612,  1897,  1619,  1625,  1626,  1631,   260,  1632,
    1642,  1648,  1649,  1718,  1650,  1651,   417,  1647,  -526,   417,
    1652,  1653,  1708,  1654,  1660,  1664,  1681,  1287,  1672,  1673,
    1674,  1677,   260,  1725,  1726,  1727,  1728,  1729,  1731,  1249,
    1551,  1552,  1553,   334,  1678,   260,  1556,  1679,  1557,  1692,
    1558,  1682,  1559,  1691,  1560,  1561,  1562,  1694,  1696,  1697,
    1698,  1699,  1745,  1700,  1703,  1722,  1723,  1732,  1736,  1751,
    1752,  1577,  1760,  1761,  1753,  1786,  1754,  1763,  1767,  1778,
    1793,  1818,  1585,  1758,  1782,  1803,  1809,  1452,  1816,   260,
    1593,  1791,  1828,  1830,  1804,  1810,  1961,   519,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,  1812,  1835,  1813,  1842,   541,  1836,  1819,  1845,
    1843,  1746,  1847,  1844,  1748,   260,  1848,  1849,  1850,  1575,
    1851,  1852,  1868,  1869,  1857,  1986,  1870,   260,  1871,  1873,
    1874,  1894,  1895,  1899,   780,  1911,  1912,  1913,  1915,  1921,
     260,   788,   789,  1924,  1646,  1930,   417,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,  1925,  1928,  1937,  1940,   541,  1943,  1662,  1945,  1947,
     813,  1959,   260,  1941,   432,  1960,  1951,  1962,  1963,   260,
    1948,  1970,  1977,  1867,  1982,  1987,  2001,  2020,  2035,  2036,
    2037,  2038,  1623,  2040,  2041,   835,  2042,  2043,  2046,  1841,
    2061,   260,  2068,  2060,   260,  2071,  2079,  2084,   409,  2085,
    2088,  1627,  2089,  1483,  1995,   260,   725,  1537,  1668,   260,
    1840,  1863,  1693,  1504,   432,   432,   112,   122,   123,   124,
    1866,   130,     0,  1889,  1762,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,   854,     0,     0,  1459,  1460,
       0,     0,     0,     0,   260,     0,     0,     0,     0,  1901,
    1902,  1903,  1904,  1905,  1927,  1646,     0,     0,     0,     0,
     432,   432,   432,     0,     0,     0,     0,     0,     0,     0,
    1737,     0,   260,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,  1757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,     0,     0,  1766,     0,     0,
    1938,     0,     0,     0,  1942,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,  1633,     0,   541,     0,     0,   432,     0,     0,     0,
     260,   260,   260,   260,   260,     0,     0,     0,     0,     0,
       0,  1646,     0,     0,     0,     0,     0,     0,   432,     0,
       0,     0,  1969,  1978,   432,     0,     0,  1980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     835,     0,  1031,  1992,     0,     0,   260,  1817,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,   260,   541,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,     0,     0,     0,
     417,     0,     0,     0,  2032,  2033,     0,     0,   432,     0,
       0,     0,     0,     0,  1858,     0,     0,   260,     0,   379,
       0,  1864,     0,     0,     0,     0,     0,   417,   417,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,  1646,   417,   404,     0,   541,     0,   414,
     432,     0,     0,   419,     0,     0,     0,  1896,     0,     0,
       0,   432,     0,     0,     0,  1735,     0,     0,     0,     0,
     429,   431,   434,   435,     0,   437,   431,   439,   440,     0,
     442,   431,   444,   445,   446,   447,   448,   449,     0,   451,
     452,   453,   432,     0,     0,   431,  1646,     0,     0,     0,
       0,     0,     0,     0,     0,  2058,     0,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,  1939,   541,     0,     0,     0,     0,
       0,     0,  2080,  2082,     0,     0,     0,     0,     0,   150,
     342,     0,     0,     0,     0,     0,     0,     0,     0,  2090,
       0,     0,     0,     0,     0,     0,     0,   516,   518,   520,
     521,   431,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   548,   431,     0,     0,     0,     0,
       0,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     569,     0,     0,     0,   352,   353,   354,   355,     0,     0,
     579,   580,   356,   357,   358,     0,   580,   359,     0,   360,
       0,     0,   432,   432,   432,   432,   601,     0,     0,     0,
     361,     0,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   621,  1646,     0,
       0,   624,   625,   626,     0,   628,     0,     0,     0,   631,
     632,   633,     0,     0,   634,     0,     0,     0,     0,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,   663,     0,     0,     0,   669,     0,     0,     0,  1646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   680,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,   363,   364,   365,  1808,
       0,     0,     0,   690,   432,     0,     0,     0,     0,   366,
       0,   367,   107,   518,     0,     0,     0,     0,     0,   738,
       0,     0,     0,     0,   743,     0,     0,     0,     0,     0,
       0,     0,     0,   396,   397,     0,     0,     0,   757,     0,
    -523,     0,  1469,     0,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   781,   782,   783,   784,   785,   786,   787,   787,     0,
     792,   793,     0,   795,     0,     0,     0,     0,     0,   801,
       0,     0,   803,     0,     0,   432,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   787,     0,     0,     0,
     431,     0,     0,     0,     0,     0,     0,     0,     0,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   834,   836,   837,   838,     0,   840,   841,     0,     0,
       0,     0,     0,   848,   849,   850,  1834,     0,     0,     0,
     856,   859,   862,   865,   867,     0,   869,   845,   871,     0,
     431,   431,     0,     0,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,   516,
     663,   890,   541,     0,   732,   895,   896,   897,   898,   899,
     900,   901,   902,   903,     0,     0,     0,     0,   909,     0,
     911,  1846,   912,     0,     0,     0,   431,   431,   431,     0,
       0,   919,   920,   921,     0,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,     0,     0,   943,     0,  1958,
       0,     0,     0,   433,     0,     0,     0,     0,   438,     0,
     431,     0,     0,   443,     0,   959,     0,   960,     0,   840,
     841,     0,     0,     0,     0,     0,   970,   456,     0,     0,
       0,     0,   976,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   431,     0,     0,     0,     0,     0,   991,   992,
       0,     0,     0,     0,     0,     0,     0,  2010,     0,     0,
       0,   432,     0,     0,   431,     0,  1010,  1011,     0,     0,
     431,  1016,     0,     0,     0,     0,     0,     0,     0,  1023,
    1785,   526,     0,  1026,     0,     0,   834,     0,  1030,     0,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,   549,   541,  1051,
     736,     0,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,   431,  1067,  1068,  1069,  1070,  1667,
    1072,  1073,  1074,  1075,     0,     0,     0,     0,     0,   526,
       0,     0,     0,     0,  1085,     0,  1087,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,  1100,  1101,     0,   541,   431,     0,     0,     0,
    1107,     0,     0,     0,     0,     0,     0,   431,     0,     0,
       0,     0,     0,     0,  1121,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
     432,   432,     0,   541,     0,     0,     0,     0,   431,     0,
       0,     0,     0,     0,     0,     0,  1146,  1147,     0,     0,
       0,     0,  1150,     0,     0,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,  1175,     0,
       0,  1177,     0,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
    1191,   541,  1193,  1194,   930,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   733,   539,   540,     0,
       0,  1212,     0,   541,  1197,  1199,  1200,     0,     0,     0,
    1204,  1205,     0,     0,  1208,  1209,  1210,  1211,  1226,  1213,
       0,     0,     0,     0,  1219,  1232,  1233,  1234,  1235,     0,
       0,     0,     0,  1244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1268,   431,   431,
     431,   431,  1273,     0,     0,     0,     0,     0,     0,  1108,
       0,     0,   816,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   733,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,   519,     0,     0,
       0,     0,     0,     0,     0,     0,  1292,  1293,     0,     0,
     432,     0,     0,     0,     0,     0,   431,     0,     0,     0,
       0,     0,   873,   874,     0,     0,     0,     0,     0,  1320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1321,
    1322,  1323,     0,     0,     0,     0,  1325,  1326,     0,  1327,
       0,     0,     0,     0,     0,     0,  1333,     0,  1334,  1335,
    1336,  1337,  1338,     0,     0,     0,     0,     0,   914,   915,
     916,  1341,  1342,     0,   432,     0,     0,   150,   342,     0,
     431,     0,     0,     0,     0,     0,     0,     0,     0,   432,
    1358,     0,  1360,     0,  1362,     0,  1364,     0,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,   956,     0,     0,     0,   541,  1381,     0,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,   353,   354,   355,     0,     0,     0,     0,
     356,   357,   358,     0,   985,   359,     0,   360,     0,  1412,
       0,     0,     0,     0,     0,     0,     0,     0,   361,     0,
     362,   431,     0,     0,     0,     0,  1008,     0,     0,  1425,
       0,     0,  1015,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,  1435,     0,     0,
       0,   541,     0,     0,     0,     0,     0,   390,     0,     0,
       0,  1444,     0,     0,  1449,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   432,   432,   432,   432,     0,     0,     0,     0,     0,
    1458,     0,     0,     0,     0,     0,     0,  1477,  1478,  1479,
    1480,     0,     0,     0,     0,     0,  1082,     0,  1487,  1489,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,   363,   364,   365,  1491,   541,     0,
     922,     0,     0,     0,     0,  1109,     0,   366,   883,   367,
     107,     0,     0,     0,     0,   432,     0,     0,  1110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1115,
    1526,  1527,  1528,  1529,  1530,   687,     0,   688,     0,  1535,
    1536,     0,  1538,     0,     0,     0,     0,     0,  1544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1548,     0,
    1139,     0,     0,     0,  1418,     0,  1568,  1569,  1570,     0,
       0,     0,     0,     0,     0,  1576,     0,  1578,     0,     0,
       0,     0,     0,     0,  1581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   431,     0,     0,
       0,     0,  1597,     0,     0,     0,     0,     0,     0,     0,
    1602,  1603,  1604,     0,     0,     0,     0,     0,     0,     0,
    1613,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1608,     0,  1611,     0,     0,     0,  1618,
       0,  1620,     0,     0,     0,     0,     0,     0,     0,     0,
    1637,     0,     0,     0,     0,     0,  1643,  1644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1639,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1269,  1270,  1271,  1272,     0,  1666,     0,     0,     0,     0,
       0,     0,     0,  1669,  1670,     0,     0,     0,     0,     0,
    1675,  1676,     0,     0,     0,     0,     0,  1680,     0,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,  1683,  1684,  1685,   541,     0,     0,
       0,     0,  1686,  1687,  1688,  1689,     0,     0,  1319,     0,
       0,     0,     0,     0,     0,     0,     0,  1695,     0,     0,
       0,     0,     0,     0,     0,     0,   431,   431,  1706,     0,
    1707,     0,     0,     0,     0,     0,  1715,  1716,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,   431,   541,     7,     8,  1734,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1744,     0,  1350,  1747,     0,     0,     0,  1750,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,  1759,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1711,     0,     0,  1771,  1712,     0,     0,     0,
    1777,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1768,  1769,     0,     0,  1779,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   700,    25,    26,   701,    28,    29,
     702,    31,   703,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,  1423,  1802,    42,     0,     0,     0,     0,
       0,   704,    48,  1795,  1796,    50,   705,     0,    53,   706,
       0,     0,     0,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,  1820,     0,     0,    70,     0,     0,
       0,     0,     0,   518,     0,     0,     0,     0,     0,     0,
       0,     0,  1831,  1832,     0,     0,   431,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,  1837,  1838,     0,
       0,     0,     0,     0,     0,  1855,  1856,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1865,     0,     0,
       0,     0,     0,     0,  1872,     0,     0,     0,     0,     0,
    1876,  1877,  1878,  1879,  1880,     0,     0,     0,     0,     0,
     431,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     891,     0,     0,     0,     0,   431,     0,     0,     0,     0,
       0,     0,     0,  1906,   700,    25,    26,   701,    28,    29,
     702,    31,   703,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,  1917,     0,     0,
       0,   704,    48,  1922,  1923,    50,   705,     0,    53,   706,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,    70,   541,     0,
       0,     0,     0,     0,  1738,     0,  1946,     0,  1739,  1595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,  1964,  1965,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1971,  1972,  1973,  1974,  1975,  1976,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1984,     0,     0,     0,     0,   431,   431,   431,   431,
     431,     0,     0,     0,     0,     0,  1777,     0,     0,     0,
    2000,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     913,     0,     0,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
    2023,   541,     0,     0,     0,  2026,  2027,  2028,  2029,  2030,
    2031,   718,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,     0,     0,     0,  1892,  2048,     0,     0,
    1893,     0,  2062,  2063,  2064,  2065,  2066,  2067,  1704,  1705,
     187,     6,   342,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   220,   221,   222,   223,   352,   353,   354,   355,
     224,     0,     0,     0,   356,   357,   358,     0,     0,   359,
       0,   360,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   361,     0,   362,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   883,     0,     0,  1833,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   363,   364,
     365,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,   366,     0,   367,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   324,     0,
       0,     0,  1492,     0,     0,   249,     0,     0,     0,     0,
       0,     0,  1890,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,  1900,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   884,     0,     0,     0,     0,     0,     0,     0,   187,
       6,   342,     0,     0,     0,     0,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   220,   221,   222,   223,   352,   353,   354,   355,   224,
       0,     0,     0,   356,   357,   358,     0,     0,   359,     0,
     360,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   361,     0,   362,     0,     0,   229,     0,     0,   230,
       0,     0,   231,     0,   232,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,  1988,  1989,
    1990,  1991,  1993,   233,     0,    49,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,     0,     0,     0,     0,
       0,     0,     0,  2039,   927,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   363,   364,   365,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
     366,     0,   367,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   324,   187,   150,
     342,   248,   389,     0,   249,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   377,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     220,   221,   222,   223,   352,   353,   354,   355,   224,     0,
       0,     0,   356,   357,   358,     0,     0,   359,     0,   360,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     361,     0,   362,     0,     0,     0,     0,     0,   150,   342,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1066,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,   353,   354,   355,     0,     0,     0,
       0,   356,   357,   358,     0,     0,   359,     0,   360,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   361,
       0,   362,     0,     0,     0,     0,     0,     0,   391,     0,
       0,     0,     0,     0,     0,   236,   363,   364,   365,   237,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   366,
       0,   367,   107,   392,   393,   394,   395,     0,   390,     0,
       0,     0,     0,     0,     0,     0,   244,   378,     0,     0,
       0,   246,     0,   396,   397,     0,   398,     0,   399,   187,
       6,   323,   400,   249,     0,     0,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,   363,   364,   365,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,   366,   224,
     367,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,     0,     0,     0,     0,     0,   229,     0,     0,   230,
       0,     0,   231,     0,   232,     0,     0,     0,     0,     0,
       0,    37,     0,     0,   150,   342,     0,     0,     0,     0,
       0,     0,     0,   233,     0,    49,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
     353,   354,   355,     0,     0,     0,     0,   356,   357,   358,
       0,     0,   359,     0,   360,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   361,   236,   362,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   324,   187,     6,
    1584,   248,     0,     0,   249,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,   363,   364,   365,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,   366,     0,   367,   107,   228,    21,
       0,     0,     0,     0,     0,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      37,     0,     0,   371,   342,     0,     0,     0,     0,     0,
       0,     0,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,   353,
     354,   355,     0,     0,     0,     0,   356,   357,   358,     0,
       0,   359,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   361,   236,   362,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   245,     0,     0,
       0,   246,     0,     0,     0,     0,   324,   187,     6,     0,
     248,     0,     0,   249,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
     363,   364,   365,     0,     0,     0,     0,     0,     0,   225,
     226,   227,     0,   366,     0,   367,     0,   228,    21,     0,
       0,     0,     0,     0,   229,     0,     0,   230,     0,     0,
     231,     0,   232,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,   342,     0,     0,     0,     0,     0,     0,
       0,   233,     0,    49,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,   353,   354,
     355,     0,     0,     0,     0,   356,   357,   358,     0,     0,
     359,     0,   360,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,   236,   362,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,  1730,     0,     0,     0,
     246,     0,     0,     0,     0,   588,   187,     6,     0,   288,
     522,     0,   249,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,   363,
     364,   365,     0,     0,     0,     0,     0,     0,   225,   226,
     227,     0,   366,     0,   367,     0,   228,    21,     0,     0,
       0,     0,     0,   229,     0,     0,   230,     0,     0,   231,
       0,   232,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,    49,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,     0,     0,     0,   246,
       0,     0,     0,     0,   247,   187,     6,     0,   248,     0,
       0,   249,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1077,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   324,   187,     6,     0,   248,     0,     0,
     249,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,     0,     0,     0,     0,
       0,   229,     0,     0,   230,     0,     0,   231,     0,   232,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
      49,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1078,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   430,     0,     0,     0,   246,     0,     0,
       0,     0,   324,   187,     6,     0,   517,     0,     0,   249,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,     0,     0,     0,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,    49,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1083,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   430,     0,     0,     0,   246,     0,     0,     0,
       0,   324,   187,     6,     0,     0,   522,     0,   249,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,     0,     0,     0,     0,     0,   229,
       0,     0,   230,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,    49,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1084,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,   238,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,     0,     0,     0,   246,     0,     0,     0,     0,
     552,   187,     6,     0,   248,     0,     0,   249,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,     0,     0,     0,     0,     0,   229,     0,
       0,   230,     0,     0,   231,     0,   232,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,    49,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1086,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,     0,     0,     0,   246,     0,     0,     0,     0,   561,
     187,     6,     0,   248,     0,     0,   249,   188,   189,   190,
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
       0,     0,     0,    73,     0,     0,    76,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   563,   187,
       6,     0,   248,     0,     0,   249,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,     0,     0,     0,     0,     0,   229,     0,     0,   230,
       0,     0,   231,     0,   232,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,    49,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   565,   187,     6,
       0,   248,     0,     0,   249,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
       0,     0,     0,     0,     0,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   430,     0,     0,
       0,   246,     0,     0,     0,     0,   324,   187,     6,     0,
     833,     0,     0,   249,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,     0,
       0,     0,     0,     0,   229,     0,     0,   230,     0,     0,
     231,     0,   232,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,    49,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1374,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,     0,     0,     0,
     246,     0,     0,     0,     0,   324,   187,     6,     0,  1592,
       0,     0,   249,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,     0,     0,
       0,     0,     0,   229,     0,     0,   230,     0,     0,   231,
       0,   232,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,    49,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   586,  1730,     0,     0,     0,   246,
       0,     0,     0,     0,   588,   187,     6,     0,   288,     0,
       0,   249,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   430,     0,     0,     0,   246,   187,
     150,   342,     0,   324,     0,     0,   188,   189,   190,     0,
     249,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   377,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   220,   221,   222,   223,   352,   353,   354,   355,   224,
       0,     0,     0,   356,   357,   358,     0,     0,   359,     0,
     360,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   361,     0,   362,   187,   150,   342,     0,     0,     0,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   377,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   220,   221,   222,   223,
     352,   353,   354,   355,   224,     0,     0,     0,   356,   357,
     358,     0,     0,   359,     0,   360,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   361,     0,   362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   363,   364,   365,
     237,     0,     0,     0,     0,   239,   240,   241,   242,   243,
     366,     0,   367,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   378,     0,
       0,     0,   246,     0,     0,     0,     0,   324,     0,     0,
       0,  1488,     0,     0,   249,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1531,     0,     0,     0,     0,     0,     0,
       0,   236,   363,   364,   365,   237,     0,     0,     0,     0,
     239,   240,   241,   242,   243,   366,     0,   367,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   378,     0,     0,     0,   246,     0,     0,
       0,     0,   324,   187,   150,   342,  1743,     0,     0,   249,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   377,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   220,   221,   222,   223,   352,
     353,   354,   355,   224,     0,     0,     0,   356,   357,   358,
       0,     0,   359,     0,   360,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,   361,     0,   362,   187,   150,
     342,     0,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   377,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     220,   221,   222,   223,   352,   353,   354,   355,   224,     0,
       0,     0,   356,   357,   358,     0,     0,   359,     0,   360,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     361,     0,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   363,   364,   365,   237,     0,     0,     0,     0,   239,
     240,   241,   242,   243,   366,     0,   367,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   378,     0,     0,     0,   246,     0,     0,     0,
       0,   324,     0,     0,     0,  1749,     0,     0,   249,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1532,     0,     0,
       0,     0,     0,     0,     0,   236,   363,   364,   365,   237,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   366,
       0,   367,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   378,     0,     0,
       0,   246,   187,   150,     0,     0,   324,     0,     0,   188,
     189,   190,     0,   249,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   377,   209,   210,   211,   212,   213,   214,     0,     0,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,   220,   221,   222,   223,   541,     0,
       0,     0,   224,     0,     0,     0,     0,     0,  1533,     0,
       0,     0,   187,   150,   225,   226,   227,     0,     0,   188,
     189,   190,   228,    21,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   377,   209,   210,   211,   212,   213,   214,     0,     0,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,   220,   221,   222,   223,   541,     0,
       0,     0,   224,     0,     0,     0,     0,     0,  1539,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1540,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,     0,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   378,     0,     0,     0,   246,     0,     0,     0,     0,
     324,     0,     0,     0,   568,     0,     0,   249,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,   236,
       0,     0,     0,   237,     0,     0,  1541,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,     0,     0,     0,   246,     0,     0,     0,     0,
     588,     0,   187,   150,   288,  1225,     0,   249,     0,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   377,   209,   210,   211,   212,   213,   214,     0,     0,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,   220,   221,   222,   223,   541,     0,
       0,     0,   224,     0,     0,     0,     0,     0,  1542,     0,
       0,     0,     0,     0,   225,   226,   227,   187,   150,     0,
    1380,     0,   228,    21,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   377,   209,   210,   211,
     212,   213,   214,     0,     0,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,   220,
     221,   222,   223,   541,     0,     0,     0,   224,     0,     0,
       0,     0,     0,  1661,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1772,     0,   236,
       0,     0,     0,   237,     0,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   378,     0,     0,     0,   246,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,   249,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,     0,     0,   236,     0,  1773,     0,   237,     0,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   378,     0,     0,     0,
     246,   187,   150,     0,  1434,   324,     0,     0,   188,   189,
     190,     0,   249,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     377,   209,   210,   211,   212,   213,   214,     0,     0,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,   220,   221,   222,   223,   541,     0,     0,
       0,   224,     0,     0,     0,     0,     0,  1797,     0,     0,
       0,   187,   150,   225,   226,   227,     0,     0,   188,   189,
     190,   228,    21,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     377,   209,   210,   211,   212,   213,   214,     0,     0,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,   220,   221,   222,   223,   541,     0,     0,
       0,   224,     0,     0,     0,     0,     0,  1798,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1799,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,     0,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     378,     0,     0,     0,   246,     0,     0,     0,     0,   324,
       7,     8,     0,     0,     0,     0,   249,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,     0,   236,     0,
       0,     0,   237,     0,     0,  1800,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   244,
     378,     0,     0,     0,   246,     0,     0,     0,     0,   324,
       0,     0,     0,     0,     0,     0,   249,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,   700,    25,    26,   701,    28,    29,   702,    31,   703,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       7,     8,    42,     0,    84,    85,    86,     0,   704,    48,
       0,     0,    50,   705,     0,    53,   706,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,    70,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1801,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   957,     0,     0,     0,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   958,     0,     0,
      70,   700,    25,    26,   701,    28,    29,   702,    31,   703,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       7,     8,    42,     0,    84,    85,    86,     0,   704,    48,
       0,     0,    50,   705,     0,    53,   706,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,    70,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1861,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1141,     0,     0,     0,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1143,     0,     0,
      70,   700,    25,    26,   701,    28,    29,   702,    31,   703,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       7,     8,    42,     0,    84,    85,    86,     0,   704,    48,
       0,     0,    50,   705,     0,    53,   706,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,    70,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1918,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1144,     0,     0,     0,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1163,     0,     0,
      70,   700,    25,    26,   701,    28,    29,   702,    31,   703,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       7,     8,    42,     0,    84,    85,    86,     0,   704,    48,
       0,     0,    50,   705,     0,    53,   706,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,    70,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1919,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1192,     0,     0,     0,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1222,     0,     0,
      70,   700,    25,    26,   701,    28,    29,   702,    31,   703,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       7,     8,    42,     0,    84,    85,    86,     0,   704,    48,
       0,     0,    50,   705,     0,    53,   706,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,    70,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1931,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1372,     0,     0,     0,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,  1949,     0,     0,
      70,     0,    -4,    -4,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,    84,    85,    86,     0,     0,     0,
       0,     0,  1932,    -4,    -4,     0,     0,     0,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,    -4,    -4,    -4,   541,     0,     0,    -4,
      -4,     0,    -4,     0,     0,     0,  1933,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,  2012,    -4,    -4,    -4,    -4,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,     0,
      -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,     9,    10,     0,    -4,    -4,    -4,     0,     0,
       0,     0,     0,     0,    -4,     0,    -4,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    17,    18,     0,    19,
      20,     0,    21,     0,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,    37,    38,    39,    40,    41,     0,    42,
       0,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       7,     8,     0,    79,    80,    81,     0,     0,     0,    82,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
      87,     0,    88,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   106,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   700,    25,    26,
     701,    28,    29,   702,    31,   703,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   704,    48,     0,     0,    50,   705,
       0,    53,   706,     0,     0,     0,     0,   964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,   965,     0,     0,     0,     0,     0,
       0,   700,    25,    26,   701,    28,    29,   702,    31,   703,
      33,    34,    35,    36,    84,    85,    86,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   704,    48,
       0,     0,    50,   705,     0,    53,   706,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,    70,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1934,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1935,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1967,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1997,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2002,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2003,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2004,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2005,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2006,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2007,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2049,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2050,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2051,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2052,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1004,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1094,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1166,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1231,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1376,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1440,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1441,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1442,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1443,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1709,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1720,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1787,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1788,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1789,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1790,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1792,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1814,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1829,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1881,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1898,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1907,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1908,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  1929,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  1983,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  2025,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  2047,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  2073,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  2074,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  2075,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  2076,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,     0,  2077,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,  2078,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
       0,   665,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,     0,     0,   875,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,     0,     0,     0,  1807,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
     687,     0,   688,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,   933,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,     0,     0,   978,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,  1113,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,     0,     0,  1179,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,     0,     0,  1180,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,     0,     0,
    1184,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,     0,     0,  1185,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,     0,     0,  1267,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,     0,     0,  1283,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
       0,     0,  1471,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,     0,     0,  1598,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,     0,     0,  1765,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,     0,
       0,  1815,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,   737,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,   739,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,   741,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,   742,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,   744,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,   746,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,   747,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,   748,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
     749,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,   750,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,   751,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,   753,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,   754,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,   755,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,   817,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,   846,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,   904,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,   922,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
     923,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,   924,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,   925,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,   931,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,   932,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,   963,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,   977,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,  1034,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,  1039,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,  1052,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
    1112,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,  1118,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,  1119,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,  1120,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,  1134,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,  1135,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,  1136,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,  1165,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,  1167,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,  1168,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
    1169,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,  1170,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,  1171,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,  1172,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,  1173,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,  1178,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,  1266,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,  1282,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,  1476,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541,     0,  1543,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   664,   539,   540,     0,     0,     0,     0,   541,     0,
    1655,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   664,   539,   540,     0,     0,     0,     0,   541,
       0,  1656,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   664,   539,   540,     0,     0,     0,     0,
     541,     0,  1657,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   664,   539,   540,     0,     0,     0,
       0,   541,     0,  1658,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   664,   539,   540,     0,     0,
       0,     0,   541,     0,  1710,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   664,   539,   540,     0,
       0,     0,     0,   541,     0,  1719,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   664,   539,   540,
       0,     0,     0,     0,   541,     0,  1742,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   664,   539,
     540,     0,     0,     0,     0,   541,     0,  1996,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   664,
     539,   540,     0,     0,     0,     0,   541,     0,  2044,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     664,   539,   540,     0,     0,     0,     0,   541
};

static const yytype_int16 yycheck[] =
{
       3,     3,   281,  1160,   682,   697,    21,   495,     4,     4,
     583,   584,   690,  1586,     4,  1622,   132,  1624,    21,     5,
       4,     6,     5,   715,     4,     4,     4,     4,     4,     4,
       9,     5,  1164,     5,    96,     6,     5,     5,     4,     6,
    1780,     4,     4,    96,    47,     6,     9,    96,     4,   127,
       7,     4,   147,     6,     4,     6,     4,     6,   221,   222,
       6,   228,   229,   231,   117,   233,   144,   293,   117,     7,
     237,    74,     9,   236,   152,   153,   154,   172,     6,    82,
     158,   159,     6,     9,    87,   311,   221,   222,     7,   127,
     183,   184,   185,   188,   189,    98,    60,    61,     6,    63,
      84,     4,   232,     9,   234,   240,   144,   221,   222,  1682,
     240,   221,   222,     0,   152,   153,   154,   221,   222,   232,
     158,   159,   221,   222,   221,   222,   240,   240,     8,   132,
     240,   133,    14,     9,   137,   138,   240,    90,   235,   231,
       9,   240,   145,    98,   232,   100,   234,   635,   374,   637,
     376,     6,   240,   156,   231,   158,    90,   383,   236,    93,
     163,   232,    96,     6,    98,   168,   237,   162,   163,   164,
     165,     7,   175,   266,   267,   268,   179,   132,     6,   182,
     183,   184,   185,   186,   234,    90,  1926,     6,    93,   175,
     240,    96,   175,    98,   221,   222,   172,   173,   236,   183,
     155,   175,     6,   175,   231,     7,   172,   173,   235,   160,
     187,   304,   305,   306,   160,   221,   222,   207,    90,    93,
       6,    93,    96,   207,    96,   318,   319,   207,   207,   235,
     233,  1804,   207,   218,   132,  1392,    96,   233,    98,   137,
     138,   236,   245,   239,   207,   248,   249,   218,   238,   228,
     229,   235,   231,   231,   233,   235,   235,   235,   237,   262,
     235,   235,   265,   266,   267,   268,   235,   235,   235,   231,
     273,   274,   275,   235,   235,   231,   279,   175,   281,   235,
     237,   231,   231,   231,  1857,   235,   235,   231,   186,   208,
     209,   210,   211,   231,   231,   233,   233,   221,   222,   977,
     978,   304,   305,   306,   207,   231,   231,   233,   233,   228,
     229,   237,     8,   221,   222,   318,   319,     4,   237,   233,
     284,   285,   228,   229,   234,   231,    47,   233,   292,   293,
     240,   237,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   572,     7,   574,   575,
     230,     6,   228,   229,  1961,   231,   236,   233,   234,   228,
     229,   237,   231,     6,   233,   591,   221,   222,   237,   232,
     231,   234,   208,   209,   210,   211,     7,   240,   381,     4,
     221,   222,   385,   386,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   401,   240,
       6,     7,   230,   629,   407,     7,   208,   209,   210,   211,
     232,  1103,   221,   222,   507,   508,   509,   510,   240,  1111,
     232,   221,   222,   426,   221,   222,  1999,   430,   240,   131,
     132,   240,   221,   222,   389,   137,   221,   222,   233,   665,
     240,   221,   222,   240,   131,   132,   133,   134,  1126,   231,
    1128,   240,  1130,   232,  1132,   240,   221,   222,   179,   146,
     240,   240,   149,   221,   222,    90,   221,   222,   231,    94,
     235,   110,   232,   231,   477,   100,   101,   235,   103,   104,
     240,   484,   485,   381,   231,   240,   489,  2060,   491,   492,
     493,   494,   495,   232,   221,   222,   121,    93,   231,   514,
      96,   240,    98,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   233,   240,   517,   231,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     127,   228,   229,   232,   230,   538,   228,   229,   235,   542,
     236,   240,   235,   235,   265,   231,   239,   144,   208,   209,
     210,   211,   273,   274,   275,   152,   153,   154,   279,   231,
     515,   158,   159,   235,   567,   568,   682,   231,   228,   229,
     231,   221,   222,  1265,   235,   221,   222,   208,   209,   210,
     211,   583,   584,   221,   222,   223,   224,   225,    96,  1281,
     240,   489,   230,   491,   240,   493,   494,   228,   229,   232,
       6,   234,   557,   558,   559,   560,   208,   209,   210,   211,
     613,   614,   615,   511,   512,   228,   229,   581,   582,    22,
      23,   232,   586,   234,   231,   235,   228,   229,   235,   240,
     127,   231,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   231,   645,   646,   647,   648,   649,   144,   651,   652,
     653,   654,   231,   879,   657,   152,   153,   154,   127,   236,
     231,   158,   159,   240,   385,   386,   131,   132,   221,   222,
       6,     7,   137,   221,   222,   144,    93,   231,     8,    96,
     401,   221,   222,   152,   153,   154,   689,   240,   231,   158,
     159,   694,   240,   221,   222,   650,   221,   222,    90,   231,
     240,    93,   221,   222,    96,   232,    98,   234,   711,   712,
     221,   222,   240,   240,   717,   240,   237,   720,   239,   236,
     723,   240,   725,   240,   236,    96,   842,    98,   240,   132,
     733,    93,   735,   236,    96,   231,    98,   240,   636,   236,
     638,   639,   640,   641,   642,   643,   235,   645,   646,   647,
     648,    96,   231,   651,   652,   653,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    93,   236,   236,  1446,   230,
     240,   492,   223,   224,   225,    96,   731,    98,    93,   230,
    1458,    96,   236,    98,   231,   506,   240,   235,   791,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,  1950,   222,
     223,   232,   720,   234,   235,   228,   235,   725,  1985,   236,
     833,    96,   231,   240,   237,   238,   235,    93,   231,   236,
     236,   844,   235,   240,   240,   232,    93,   234,   235,   852,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   977,   978,   236,   236,   230,     8,   240,   240,   236,
     236,    96,   875,   240,   240,   236,   236,  2034,     4,   240,
     240,  2013,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,     4,   236,     6,   236,
     230,   240,   232,   240,   234,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,     4,   882,   236,
     127,   230,   236,   240,     4,   889,   240,     4,     6,   893,
     236,   236,   236,   236,   240,   240,   240,   240,   231,   236,
     343,   344,   345,   240,   231,   231,   349,   350,   351,   352,
     353,   354,   355,     8,   357,   231,   236,   236,   361,   362,
     240,   240,   365,   236,   231,   236,   969,   240,  1247,   240,
       6,  1459,  1460,   236,   377,   236,     6,   240,   236,   240,
     983,     6,   240,   236,   236,   988,   236,   240,   240,   233,
     240,   231,   995,   996,   997,   998,  1112,  1113,  1571,  1572,
     233,   239,     6,   235,  1007,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   239,
     231,   236,   236,   230,   979,   240,   240,   236,     9,  1032,
    1033,   240,  1035,   231,  1037,  1038,   231,  1040,   231,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,   236,   236,
    1053,   236,   240,   240,   236,   240,   236,   236,   240,   236,
     240,   240,     6,   240,  1028,   236,   231,   231,   117,   240,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   235,  1088,  1089,  1090,   230,   236,
     232,   236,   236,   240,   231,   240,   240,   236,   236,   231,
     236,   240,   240,  1106,   240,   235,   231,   231,   231,  1007,
     231,   231,   231,  1116,  1117,   231,     4,   235,   235,   231,
     235,   231,   525,     6,   231,   231,   231,   231,     6,   231,
     231,   852,     6,   233,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,     6,   235,
    1266,  1267,   230,   235,   235,     6,     6,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,  1174,   233,   233,  1453,   230,   233,   235,   175,   231,
     231,   231,     6,   231,  1187,  1188,  1189,   231,   233,     6,
       6,  1089,  1090,   235,     6,  1198,   235,     7,     6,     6,
    1203,   235,   235,   240,  1207,   236,    86,  1433,   240,   232,
       7,  1437,     6,  1216,     6,  1218,     6,   232,   235,    64,
      64,    64,    64,   230,     4,  1228,     7,   232,     7,     6,
       6,     6,     6,   235,     7,     6,     6,  1810,     7,     6,
       6,   172,   235,   234,  1247,   232,     6,   235,   969,   235,
     235,   235,     7,     6,   237,   233,   231,     4,     6,   232,
       6,  1749,     6,   233,  1267,     6,   175,   988,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,     7,     7,     7,  1288,   230,     7,   175,     7,
       7,     7,     7,   175,     7,     7,  1299,     7,     7,     7,
       7,     7,  1305,     7,     6,  1203,   235,   232,   234,  1207,
     240,  1032,  1033,   240,  1035,   235,  1037,  1038,  1216,  1040,
    1218,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,
    1446,  1286,   240,  1288,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,  1351,  1352,
    1353,   235,   230,   232,  1357,   240,  1359,  1636,  1361,   235,
    1363,     7,  1365,  1366,  1367,   235,   237,  1088,     7,  1267,
     235,     4,     6,   232,   240,   232,   240,   232,   240,  1382,
     232,     7,   127,   237,   240,  1106,     6,   236,   236,     7,
    1393,     7,     7,   232,   232,  1116,   237,     9,  1401,   232,
     240,  1404,   234,   240,   240,     7,   236,   147,   235,     6,
       6,     4,   237,   235,    46,   158,    46,   231,   231,   218,
     163,     4,   231,     7,    98,   168,   231,  1391,     7,     7,
       7,  1547,     7,   237,   240,     7,     6,   108,     7,   182,
       7,     7,     7,     7,     4,     4,   235,   231,     6,     6,
    1453,     7,     7,  1174,     7,     7,  1459,  1460,     7,     7,
       7,     7,  1465,   235,     6,     6,  1187,  1188,  1189,     6,
       6,    96,     7,     6,     4,     4,     4,  1432,   240,   238,
    1483,   235,     6,   240,   235,  1488,   236,     6,     6,  1492,
       6,   233,     7,     6,     6,   231,   231,   235,     6,     6,
     237,     6,   245,   234,     6,   248,   240,  1228,     6,   235,
     121,     6,     6,   235,   235,     6,   235,   175,     6,   262,
       6,   235,     6,     6,     6,     6,     6,     6,     6,     5,
       4,   232,  1648,  1488,   232,     6,     6,     4,  1502,   235,
       6,     6,   235,     7,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   235,   235,
    1563,  1564,   230,   235,   232,     6,   234,  1288,  1847,  1571,
    1572,   233,   240,     6,   235,   235,   235,     6,  1299,   235,
     235,   235,   235,  1586,  1305,  1483,     6,     6,     6,  1592,
     171,   240,   240,  1819,   232,   240,     6,   237,  1601,     7,
     231,     4,     6,   240,     6,     6,  1609,   235,   235,  1612,
       6,     6,  1567,     6,     4,     7,     5,  1020,     6,     6,
       6,     6,  1625,  1587,  1588,  1589,  1590,  1591,  1592,  1632,
    1351,  1352,  1353,  1636,    94,  1638,  1357,     6,  1359,     6,
    1361,   235,  1363,   235,  1365,  1366,  1367,     6,     6,     6,
       6,     6,  1607,     6,     6,     6,     6,     6,     6,  1614,
    1615,  1382,     6,     4,   240,     7,   240,     6,     6,     6,
       5,     7,  1393,  1628,   235,     6,     6,     6,     6,  1682,
    1401,   235,     6,   170,   235,   235,  1912,   430,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   236,     6,   236,   236,   230,   232,   235,     6,
     236,  1609,     7,   236,  1612,  1718,     6,   237,     6,     6,
       6,     6,     6,     6,   235,  1951,     6,  1730,     6,     6,
       6,     6,   236,     6,   477,   232,   235,     6,   173,     6,
    1743,   484,   485,   236,  1465,   235,  1749,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   236,   231,   235,     6,   230,     6,  1488,   236,     6,
     513,     6,  1775,   235,   517,     6,   235,     6,   235,  1782,
     127,   232,     6,  1786,     6,     6,   236,   236,     6,     6,
       6,     6,     6,     6,     6,   538,     6,   235,     6,  1754,
       6,  1804,     6,   235,  1807,   235,     6,     6,  1810,     6,
       6,     6,     6,  1280,  1963,  1818,   423,  1331,  1496,  1822,
    1753,  1781,  1552,  1298,   567,   568,     3,     3,     3,     3,
    1785,     3,    -1,  1806,  1632,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1847,   556,    -1,    -1,  1251,  1252,
      -1,    -1,    -1,    -1,  1857,    -1,    -1,    -1,    -1,  1823,
    1824,  1825,  1826,  1827,     7,  1586,    -1,    -1,    -1,    -1,
     613,   614,   615,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1601,    -1,  1885,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   657,    -1,    -1,  1638,    -1,    -1,
    1884,    -1,    -1,    -1,  1888,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,     6,    -1,   230,    -1,    -1,   689,    -1,    -1,    -1,
    1953,  1954,  1955,  1956,  1957,    -1,    -1,    -1,    -1,    -1,
      -1,  1682,    -1,    -1,    -1,    -1,    -1,    -1,   711,    -1,
      -1,    -1,  1927,  1937,   717,    -1,    -1,  1941,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     733,    -1,   735,  1957,    -1,    -1,  1999,  1718,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,  2018,   230,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
    2043,    -1,    -1,    -1,  2008,  2009,    -1,    -1,   791,    -1,
      -1,    -1,    -1,    -1,  1775,    -1,    -1,  2060,    -1,   106,
      -1,  1782,    -1,    -1,    -1,    -1,    -1,  2070,  2071,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,  1804,  2087,   132,    -1,   230,    -1,   136,
     833,    -1,    -1,   140,    -1,    -1,    -1,  1818,    -1,    -1,
      -1,   844,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
     177,   178,   875,    -1,    -1,   182,  1857,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2043,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,  1885,   230,    -1,    -1,    -1,    -1,
      -1,    -1,  2070,  2071,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2087,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,   262,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     277,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
     287,   288,    67,    68,    69,    -1,   293,    72,    -1,    74,
      -1,    -1,   995,   996,   997,   998,   303,    -1,    -1,    -1,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,  1999,    -1,
      -1,   328,   329,   330,    -1,   332,    -1,    -1,    -1,   336,
     337,   338,    -1,    -1,   341,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1053,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,   378,    -1,    -1,    -1,   382,    -1,    -1,    -1,  2060,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   412,   191,   192,   193,     6,
      -1,    -1,    -1,   403,  1117,    -1,    -1,    -1,    -1,   204,
      -1,   206,   207,   430,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   229,    -1,    -1,    -1,   455,    -1,
     235,    -1,   237,    -1,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,    -1,
     487,   488,    -1,   490,    -1,    -1,    -1,    -1,    -1,   496,
      -1,    -1,   499,    -1,    -1,  1198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   513,    -1,    -1,    -1,
     517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,    -1,   543,   544,    -1,    -1,
      -1,    -1,    -1,   550,   551,   552,     6,    -1,    -1,    -1,
     557,   558,   559,   560,   561,    -1,   563,   547,   565,    -1,
     567,   568,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   586,
     587,   588,   230,    -1,   232,   592,   593,   594,   595,   596,
     597,   598,   599,   600,    -1,    -1,    -1,    -1,   605,    -1,
     607,     6,   609,    -1,    -1,    -1,   613,   614,   615,    -1,
      -1,   618,   619,   620,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   644,    -1,     6,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,
     657,    -1,    -1,   168,    -1,   662,    -1,   664,    -1,   666,
     667,    -1,    -1,    -1,    -1,    -1,   673,   182,    -1,    -1,
      -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   689,    -1,    -1,    -1,    -1,    -1,   695,   696,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,  1404,    -1,    -1,   711,    -1,   713,   714,    -1,    -1,
     717,   718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   726,
       7,     8,    -1,   730,    -1,    -1,   733,    -1,   735,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,   262,   230,   756,
     232,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,   763,   764,   765,   766,   767,   768,   769,
     770,   771,   772,   773,   791,   775,   776,   777,   778,  1492,
     780,   781,   782,   783,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,   794,    -1,   796,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,   812,   813,    -1,   230,   833,    -1,    -1,    -1,
     820,    -1,    -1,    -1,    -1,    -1,    -1,   844,    -1,    -1,
      -1,    -1,    -1,    -1,   851,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
    1563,  1564,    -1,   230,    -1,    -1,    -1,    -1,   875,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   883,   884,    -1,    -1,
      -1,    -1,   889,    -1,    -1,    -1,    -1,    -1,    -1,  1592,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   905,    -1,
      -1,   908,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
     927,   230,   929,   930,     8,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,   948,    -1,   230,   934,   935,   936,    -1,    -1,    -1,
     940,   941,    -1,    -1,   944,   945,   946,   947,   965,   949,
      -1,    -1,    -1,    -1,   954,   972,   973,   974,   975,    -1,
      -1,    -1,    -1,   980,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,   995,   996,
     997,   998,   999,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,   517,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,  1730,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1026,  1027,    -1,    -1,
    1743,    -1,    -1,    -1,    -1,    -1,  1053,    -1,    -1,    -1,
      -1,    -1,   567,   568,    -1,    -1,    -1,    -1,    -1,  1066,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1076,
    1077,  1078,    -1,    -1,    -1,    -1,  1083,  1084,    -1,  1086,
      -1,    -1,    -1,    -1,    -1,    -1,  1093,    -1,  1095,  1096,
    1097,  1098,  1099,    -1,    -1,    -1,    -1,    -1,   613,   614,
     615,  1108,  1109,    -1,  1807,    -1,    -1,     4,     5,    -1,
    1117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1822,
    1127,    -1,  1129,    -1,  1131,    -1,  1133,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   657,    -1,    -1,    -1,   230,  1154,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,   689,    72,    -1,    74,    -1,  1186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      87,  1198,    -1,    -1,    -1,    -1,   711,    -1,    -1,  1206,
      -1,    -1,   717,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,  1224,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,
      -1,  1238,    -1,    -1,  1241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1953,  1954,  1955,  1956,  1957,    -1,    -1,    -1,    -1,    -1,
    1250,    -1,    -1,    -1,    -1,    -1,    -1,  1274,  1275,  1276,
    1277,    -1,    -1,    -1,    -1,    -1,   791,    -1,  1285,  1286,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   191,   192,   193,  1287,   230,    -1,
     232,    -1,    -1,    -1,    -1,     8,    -1,   204,   240,   206,
     207,    -1,    -1,    -1,    -1,  2018,    -1,    -1,   833,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   844,
    1320,  1321,  1322,  1323,  1324,   232,    -1,   234,    -1,  1329,
    1330,    -1,  1332,    -1,    -1,    -1,    -1,    -1,  1338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1348,    -1,
     875,    -1,    -1,    -1,     8,    -1,  1373,  1374,  1375,    -1,
      -1,    -1,    -1,    -1,    -1,  1382,    -1,  1384,    -1,    -1,
      -1,    -1,    -1,    -1,  1391,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1404,    -1,    -1,
      -1,    -1,  1409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1417,  1418,  1419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1423,    -1,  1425,    -1,    -1,    -1,  1429,
      -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1457,    -1,    -1,    -1,    -1,    -1,  1463,  1464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1459,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     995,   996,   997,   998,    -1,  1492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1500,  1501,    -1,    -1,    -1,    -1,    -1,
    1507,  1508,    -1,    -1,    -1,    -1,    -1,  1514,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,  1531,  1532,  1533,   230,    -1,    -1,
      -1,    -1,  1539,  1540,  1541,  1542,    -1,    -1,  1053,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1554,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1563,  1564,  1565,    -1,
    1567,    -1,    -1,    -1,    -1,    -1,  1573,  1574,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,  1592,   230,    13,    14,  1596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1607,    -1,  1117,  1610,    -1,    -1,    -1,  1614,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,  1629,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,  1642,   240,    -1,    -1,    -1,
    1647,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1640,  1641,    -1,    -1,  1661,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,  1198,  1691,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,  1683,  1684,   121,   122,    -1,   124,   125,
      -1,    -1,    -1,    -1,    -1,  1712,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1721,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1739,  1740,    -1,    -1,  1743,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,  1748,    -1,
      -1,    -1,    -1,    -1,    -1,  1772,  1773,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1784,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,    -1,    -1,
    1797,  1798,  1799,  1800,  1801,    -1,    -1,    -1,    -1,    -1,
    1807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,  1822,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1830,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,    -1,  1854,    -1,    -1,
      -1,   117,   118,  1860,  1861,   121,   122,    -1,   124,   125,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,   143,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,  1893,    -1,   240,  1404,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1918,  1919,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1930,  1931,  1932,  1933,  1934,  1935,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1948,    -1,    -1,    -1,    -1,  1953,  1954,  1955,  1956,
    1957,    -1,    -1,    -1,    -1,    -1,  1963,    -1,    -1,    -1,
    1967,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
    1997,   230,    -1,    -1,    -1,  2002,  2003,  2004,  2005,  2006,
    2007,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2018,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,  2027,    -1,    -1,
     240,    -1,  2049,  2050,  2051,  2052,  2053,  2054,  1563,  1564,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,  1743,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,   194,   195,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,    -1,
      -1,    -1,   235,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,  1807,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,  1822,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,  1953,  1954,
    1955,  1956,  1957,   117,    -1,   119,    -1,    -1,   122,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,    -1,    -1,   149,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2018,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
     194,   195,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,     4,
       5,   235,     7,    -1,   238,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,     4,     5,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,   226,    -1,   228,   229,    -1,   231,    -1,   233,     3,
       4,     5,   237,   238,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,   191,   192,   193,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,   204,    63,
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,    -1,    -1,   149,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,   190,    87,    -1,    -1,
     194,   195,    -1,    -1,    -1,   199,   200,   201,   202,   203,
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,     4,
       5,   235,    -1,    -1,   238,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,   204,    -1,   206,   207,    83,    84,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,   119,    -1,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,    -1,    -1,   149,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,   190,    87,    -1,    -1,   194,
     195,    -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,   231,     3,     4,    -1,
     235,    -1,    -1,   238,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,   204,    -1,   206,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,   119,    -1,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,   190,    87,    -1,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,   231,     3,     4,    -1,   235,
     236,    -1,   238,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,   204,    -1,   206,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
      -1,    -1,   149,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,    -1,
      -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,     3,     4,    -1,   235,    -1,
      -1,   238,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,   231,     3,     4,    -1,   235,    -1,    -1,
     238,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
     119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
     149,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,
     199,   200,   201,   202,   203,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,   231,     3,     4,    -1,   235,    -1,    -1,   238,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,   119,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,   199,
     200,   201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,   231,     3,     4,    -1,    -1,   236,    -1,   238,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,   119,    -1,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,   199,   200,
     201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
     231,     3,     4,    -1,   235,    -1,    -1,   238,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,
     122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,   146,    -1,    -1,   149,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,
     202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,
       3,     4,    -1,   235,    -1,    -1,   238,    10,    11,    12,
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
      -1,    -1,    -1,   146,    -1,    -1,   149,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,   202,
     203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,
       4,    -1,   235,    -1,    -1,   238,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,    -1,    -1,   149,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,   195,    -1,    -1,    -1,   199,   200,   201,   202,   203,
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,     4,
      -1,   235,    -1,    -1,   238,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,   119,    -1,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,    -1,    -1,   149,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,
     195,    -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,   231,     3,     4,    -1,
     235,    -1,    -1,   238,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,   119,    -1,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,   149,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,   231,     3,     4,    -1,   235,
      -1,    -1,   238,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
      -1,    -1,   149,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,    -1,
      -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,     3,     4,    -1,   235,    -1,
      -1,   238,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,     3,
       4,     5,    -1,   231,    -1,    -1,    10,    11,    12,    -1,
     238,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    87,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,   235,    -1,    -1,   238,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,    -1,   206,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,   231,     3,     4,     5,   235,    -1,    -1,   238,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    87,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
     200,   201,   202,   203,   204,    -1,   206,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,   235,    -1,    -1,   238,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,   204,
      -1,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,   226,     3,     4,    -1,    -1,   231,    -1,    -1,    10,
      11,    12,    -1,   238,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    55,    56,    57,    58,   230,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,     3,     4,    75,    76,    77,    -1,    -1,    10,
      11,    12,    83,    84,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    55,    56,    57,    58,   230,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,   200,
     201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,   235,    -1,    -1,   238,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,   190,
      -1,    -1,    -1,   194,    -1,    -1,   240,    -1,   199,   200,
     201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
     231,    -1,     3,     4,   235,     6,    -1,   238,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    55,    56,    57,    58,   230,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,     3,     4,    -1,
       6,    -1,    83,    84,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    55,
      56,    57,    58,   230,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,   200,
     201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   238,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,   240,    -1,   194,    -1,
      -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
     226,     3,     4,    -1,     6,   231,    -1,    -1,    10,    11,
      12,    -1,   238,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    55,    56,    57,    58,   230,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,     3,     4,    75,    76,    77,    -1,    -1,    10,    11,
      12,    83,    84,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    55,    56,    57,    58,   230,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,   200,   201,
     202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,
      13,    14,    -1,    -1,    -1,    -1,   238,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,   190,    -1,
      -1,    -1,   194,    -1,    -1,   240,    -1,   199,   200,   201,
     202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
      13,    14,   111,    -1,   167,   168,   169,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,   143,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
     143,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
      13,    14,   111,    -1,   167,   168,   169,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,   143,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
     143,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
      13,    14,   111,    -1,   167,   168,   169,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,   143,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
     143,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
      13,    14,   111,    -1,   167,   168,   169,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,   143,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
     143,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
      13,    14,   111,    -1,   167,   168,   169,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,   143,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,   236,    -1,    -1,
     143,    -1,    13,    14,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,   240,    44,    45,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    64,    65,    66,   230,    -1,    -1,    70,
      71,    -1,    73,    -1,    -1,    -1,   240,    78,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,   236,   105,   106,   107,   108,   109,    -1,
     111,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,     4,    -1,   155,   156,   157,    -1,    -1,    -1,
     161,    13,    14,    -1,    -1,   166,   167,   168,   169,    -1,
      -1,   172,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    44,    45,    -1,   196,   197,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    -1,    84,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,   105,   106,   107,   108,   109,    -1,   111,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      13,    14,    -1,   155,   156,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,    -1,    -1,
     172,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   167,   168,   169,   106,   107,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,   143,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,   236,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,   235,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,   235,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,   235,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,    -1,   234,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,   234,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   234,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,   234,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,   234,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
     234,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,   234,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,   234,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   234,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,   234,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,   234,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   234,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,   234,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   232,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   232,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,   232,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   232,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   232,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,   232,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   232,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   232,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,   232,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   232,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   232,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,   232,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   232,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   232,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,   232,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   232,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,   232,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   242,   243,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    81,
      82,    84,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   105,   106,   107,
     108,   109,   111,   113,   114,   115,   116,   117,   118,   119,
     121,   122,   123,   124,   125,   126,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   155,
     156,   157,   161,   166,   167,   168,   169,   172,   174,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   196,   197,   198,   205,   207,   244,   246,
     247,   267,   288,   289,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   307,   309,   310,   316,   317,   318,   319,
     323,   344,   345,   235,   239,    14,    96,   231,   231,     6,
     235,     6,     6,     6,     6,   231,     6,     6,   233,   233,
       4,   325,   345,   231,   233,   265,   265,   231,   235,   231,
     231,     4,   231,   235,   231,   231,     4,   231,   235,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   110,
      96,     6,   235,    90,    93,    96,   231,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    75,    76,    77,    83,    90,
      93,    96,    98,   117,   122,   124,   190,   194,   195,   199,
     200,   201,   202,   203,   221,   222,   226,   231,   235,   238,
     289,   300,   307,   309,   320,   321,   323,   325,   332,   334,
     345,   231,   235,    96,    96,   117,    93,    96,    98,    90,
      93,    96,    98,    93,    96,    98,    93,    96,   231,    93,
     147,   172,   188,   189,   235,   221,   222,   231,   235,   329,
     330,   329,   235,   235,   329,     4,    90,    94,   100,   101,
     103,   104,   121,   231,    96,    98,    96,    93,     4,    84,
     183,   235,   345,     4,     6,    90,    93,    96,    93,    96,
       4,     4,     4,     5,   231,   332,   333,     4,   231,   231,
     231,     4,   235,   336,   345,     4,   231,   231,   231,     6,
       6,   233,     5,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    59,    60,    61,    62,    67,    68,    69,    72,
      74,    85,    87,   191,   192,   193,   204,   206,   340,   345,
     231,     4,   340,     5,   235,     5,   235,    32,   222,   320,
     345,   233,   231,   235,     6,   231,   235,     6,   239,     7,
     124,   183,   208,   209,   210,   211,   228,   229,   231,   233,
     237,   263,   264,   265,   320,   339,   340,   345,     4,   289,
     290,   291,   235,     6,   320,   339,   340,   345,   339,   320,
     339,   343,   269,   273,   231,   328,     9,   340,   345,   320,
     222,   320,   334,   335,   320,   320,   231,   320,   335,   320,
     320,   231,   320,   335,   320,   320,   320,   320,   320,   320,
     339,   320,   320,   320,   332,   231,   335,   333,   333,   333,
     339,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   231,   233,   265,   265,   265,   265,
     265,   265,   231,   265,   265,   231,   265,     5,   175,   235,
       5,   175,     5,   175,     5,   175,   117,    90,    93,    96,
      98,   231,   265,   265,   231,   231,   320,   235,   320,   334,
     320,   320,   236,   335,     9,   345,     8,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   230,     9,   231,   233,   237,   264,   265,   320,   335,
     231,   231,   231,   332,   333,   333,   333,   231,   231,   231,
     231,   231,   332,   231,   332,   231,   332,   235,   235,   320,
       4,   332,   235,   336,   235,   235,   329,   329,   329,   320,
     320,   221,   222,   235,   235,   329,   221,   222,   231,   291,
     329,   235,   231,   235,   231,   231,   231,   231,   231,   231,
     231,   320,   333,   333,   333,   231,     4,   233,     6,   233,
     291,     6,     6,   235,   235,   235,   333,   333,   233,   233,
     233,   320,     6,     6,   320,   320,   320,   237,   320,   235,
     175,   320,   320,   320,   320,   265,   265,   265,   231,   231,
     231,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   231,   231,   265,   233,     6,     6,   235,     6,   291,
       6,   291,   265,   320,   223,   235,   231,   233,   339,   320,
     291,   332,   332,   235,   340,    90,    93,    96,    98,     7,
     320,   320,     4,   172,   173,   332,     6,   232,   234,   235,
     266,     6,   235,     6,     9,   231,   233,   237,   345,   236,
      90,    93,    96,    98,   117,   122,   125,   288,   320,     6,
     232,   240,     9,   231,   233,   237,   232,   240,   240,   232,
     240,   234,   240,   268,   234,   268,    86,   327,   324,   345,
     240,   240,   232,   223,   236,   240,   232,   232,   320,   232,
     236,   232,   232,   320,   232,   236,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,     7,   320,   236,     6,
       6,     6,   232,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     334,   320,   320,   320,   320,   320,   320,   320,   334,   334,
     345,   235,   320,   320,   339,   320,   339,   332,   339,   339,
     343,   320,    64,   320,    64,    64,    64,   333,   333,   333,
     333,   339,   339,   334,   325,   340,   335,   232,   236,     9,
     265,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   235,   320,   334,   320,   320,   320,   345,
     320,   320,     4,   326,   235,   266,   232,   236,   320,   320,
     320,     7,     7,   313,   313,   282,   320,   340,   283,   320,
     340,   284,   320,   340,   285,   320,   340,   320,     6,   320,
       6,   320,     6,   335,   335,   235,   232,     6,   291,   235,
     291,   291,   240,   240,   240,   329,   329,   290,   290,   240,
     320,   236,   304,   240,   291,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   232,     7,   314,     6,     7,   320,
       6,   320,   320,   236,   335,   335,   335,     6,     6,   320,
     320,   320,   232,   232,   232,   232,   172,   240,   291,   235,
       8,   232,   232,   234,   343,   339,   343,   339,   339,   339,
     339,   339,   339,   320,   339,   339,   339,   339,   238,   342,
     345,   340,   339,   339,   339,   345,   335,   236,   236,   320,
     320,   291,   234,   232,   130,   147,   308,   232,   236,   240,
     320,     6,   235,   235,   235,   235,   320,   232,   234,     7,
     263,   264,   237,     7,     6,   335,     7,   211,   263,   248,
     345,   320,   320,   326,   233,   235,   235,   235,   235,   231,
     117,    93,    96,    98,   236,     6,   218,   245,   335,   345,
     320,   320,     4,   326,     6,   335,   320,     6,   339,     6,
     345,     6,   339,   320,   232,   233,   320,   340,     7,   175,
     320,   334,     7,     7,   232,     7,   175,     7,     7,   232,
       7,   175,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   320,   232,   235,     6,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   240,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   240,   240,   240,   232,
     234,   234,   335,   240,   240,   266,   240,   266,   240,   240,
     240,   232,   322,   235,   236,   235,   235,   235,   240,   240,
     266,   266,   232,   237,   232,   236,     7,   266,     8,     8,
     335,   237,   232,   234,   264,   335,     7,   235,   232,   232,
     232,   320,   332,     4,   312,     6,   232,   240,   232,   240,
     232,   240,   232,   240,   232,   232,   232,   236,   236,   335,
     237,   236,   291,   236,   236,   329,   320,   320,   236,   236,
     320,   329,   127,   127,   144,   152,   153,   154,   158,   159,
     305,   306,   329,   236,   301,   232,   236,   232,   232,   232,
     232,   232,   232,   232,     7,   320,     6,   320,   232,   234,
     234,   236,   236,   236,   234,   234,   240,     7,     7,     7,
     237,   320,   236,   320,   320,     7,   237,   266,   240,   266,
     266,   232,   232,   240,   266,   266,   240,   240,   266,   266,
     266,   266,   320,   266,     9,   341,   240,   232,   240,   266,
     234,   236,   236,     7,   147,     6,   320,   236,   235,     6,
     332,   236,   320,   320,   320,   320,     6,     7,   263,   264,
     237,   263,   264,   340,   320,     6,     4,   235,   337,   345,
     236,    46,    46,   332,     4,   162,   163,   164,   165,   236,
     251,   255,   258,   260,   261,   237,   232,   234,   320,   335,
     335,   335,   335,   320,   231,   231,   231,   231,   218,   339,
     232,   237,   232,   234,   232,   240,     7,   265,     4,   276,
     277,   278,   266,   266,   329,    96,    98,   332,   332,     7,
     332,    96,    98,   332,   332,     7,   332,    98,   332,   332,
     332,   332,   332,   332,   332,   332,   332,     6,     7,   335,
     320,   320,   320,   320,   236,   320,   320,   320,   332,   339,
     339,   240,   275,   320,   320,   320,   320,   320,   320,   326,
     332,   320,   320,   236,   326,   264,   237,   264,   236,   332,
     335,     7,     7,     7,   127,   311,     6,   263,   320,   263,
     320,   263,   320,   263,   320,     7,     7,     7,     7,     7,
     236,     4,   236,   240,   240,   240,   236,   236,   108,     4,
       6,   320,   235,     6,   231,     6,   160,     6,   160,   236,
     306,   240,   305,     7,     6,     7,     7,     7,     7,     7,
       7,     7,   332,     6,   235,     6,     6,     6,    96,     7,
       6,     6,   320,   332,   332,   332,     4,   240,     8,     8,
     232,     4,     4,   335,   339,   320,   339,   238,   240,   279,
     339,   339,   240,   235,     6,   320,     6,   235,   332,   236,
     236,   236,   236,   236,   320,     6,     4,   172,   173,   320,
       6,     6,     6,     7,   336,   338,     6,   233,   266,   265,
     265,     6,   252,   231,   231,   235,   262,     6,   326,   237,
     339,   234,   236,   236,   236,   236,   232,   320,   320,   320,
     320,     6,     6,   245,   326,   237,     6,   320,   235,   320,
     340,   266,   235,   332,   340,   234,   240,     6,     6,     6,
     235,   235,   121,   287,   287,   332,     6,   235,   235,     6,
       6,   332,   175,   286,   235,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   236,   266,   266,   266,   266,
     266,   240,   240,   240,   232,   266,   266,   277,   266,   240,
     240,   240,   240,   232,   266,   232,     6,     4,   266,     6,
     236,   332,   332,   332,     4,     6,   332,   332,   332,   332,
     332,   332,   332,   235,   235,     7,     6,     7,   320,   320,
     320,   235,   235,   235,   233,     6,   320,   332,   320,     6,
       6,   320,   329,   236,     5,   332,   235,   235,   235,   235,
     235,   235,   235,   332,     6,   335,   235,   320,   234,     6,
       6,   171,   320,   320,   320,     6,     6,     7,   266,   240,
     240,   266,   240,   320,     4,   187,   280,   281,   266,   232,
     266,   340,   291,     6,   291,   240,     6,     6,     7,   263,
     264,   237,     7,     6,   336,   236,   240,   320,   263,   266,
     343,   343,   231,   320,   320,   331,   332,   235,     4,     6,
       6,     6,     6,     6,     6,   232,   232,   232,   232,   339,
       4,   240,   332,   340,     7,   274,   320,   334,   278,   320,
     320,   329,     6,     6,     6,   320,   320,     6,    94,     6,
     320,     5,   235,   320,   320,   320,   320,   320,   320,   320,
     264,   235,     6,   286,     6,   320,     6,     6,     6,     6,
       6,     4,     6,     6,   335,   335,   320,   320,   340,   236,
     232,   236,   240,   290,   290,   320,   320,   236,   240,   232,
     236,   240,     6,     6,   331,   329,   329,   329,   329,   329,
     222,   329,     6,   236,   320,     6,     6,   332,   236,   240,
       8,   236,   232,   235,   320,   340,   339,   320,   339,   235,
     320,   340,   340,   240,   240,   308,   308,   332,   340,   320,
       6,     4,   337,     6,   336,   234,   332,     6,   266,   266,
     249,   320,   240,   240,   236,   240,   250,   320,     6,   320,
     270,   272,   235,   236,   240,     7,     7,   236,   236,   236,
     236,   235,   236,     5,   331,   266,   266,   240,   240,   240,
     240,   240,   320,     6,   235,   236,   236,   235,     6,     6,
     235,   320,   236,   236,   236,   234,     6,   332,     7,   235,
     320,   236,   240,   240,   240,   240,   240,   240,     6,   236,
     170,   320,   320,   335,     6,     6,   232,   266,   266,   343,
     281,   340,   236,   236,   236,     6,     6,     7,     6,   237,
       6,     6,     6,   232,   240,   320,   320,   235,   332,   236,
     240,   240,   275,   279,   332,   320,   340,   345,     6,     6,
       6,     6,   320,     6,     6,   236,   320,   320,   320,   320,
     320,   236,   331,   131,   132,   137,   315,   131,   132,   315,
     335,   290,   236,   240,     6,   236,   332,   291,   236,     6,
     335,   329,   329,   329,   329,   329,   320,   236,   236,   236,
     236,   232,   235,     6,   336,   173,   253,   320,   240,   240,
     331,     6,   320,   320,   236,   236,   271,     7,   231,   236,
     235,   240,   240,   240,   240,   240,   236,   235,   329,   332,
       6,   235,   329,     6,   236,   236,   320,     6,   127,   236,
     302,   235,   236,   240,   240,   240,   240,   240,     6,     6,
       6,   291,     6,   235,   320,   320,   236,   240,   275,   340,
     232,   320,   320,   320,   320,   320,   320,     6,   329,     6,
     329,     6,     6,   236,   320,   305,   291,     6,   335,   335,
     335,   335,   329,   335,   308,   250,   232,   240,     6,   235,
     320,   236,   240,   240,   240,   240,   240,   240,   240,   240,
       6,   236,   236,   303,   236,   236,   236,   236,   240,   236,
     236,   236,   256,   320,   331,   236,   320,   320,   320,   320,
     320,   320,   329,   329,   305,     6,     6,     6,     6,   335,
       6,     6,     6,   235,   232,   236,     6,   236,   266,   240,
     240,   240,   240,   240,   240,   236,   236,   254,   339,   259,
     235,     6,   320,   320,   320,   320,   320,   320,     6,   236,
     240,   235,   331,   236,   236,   236,   236,   236,   236,     6,
     339,   257,   339,   236,     6,     6,   236,   240,     6,     6,
     339
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
#line 247 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 258 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 259 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 260 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 262 "Gmsh.y"
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
#line 280 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 281 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 282 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 283 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 284 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 285 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 286 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 287 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 288 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 289 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 290 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 291 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 292 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 293 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 294 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 295 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 300 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 304 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 311 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 316 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 321 "Gmsh.y"
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
#line 335 "Gmsh.y"
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
#line 348 "Gmsh.y"
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
#line 361 "Gmsh.y"
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
#line 389 "Gmsh.y"
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
#line 403 "Gmsh.y"
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
#line 416 "Gmsh.y"
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
#line 429 "Gmsh.y"
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
#line 447 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 461 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 463 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 468 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 470 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 475 "Gmsh.y"
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
#line 579 "Gmsh.y"
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
#line 589 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 598 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 605 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 615 "Gmsh.y"
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
#line 624 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 633 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 640 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 650 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 658 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 668 "Gmsh.y"
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
#line 687 "Gmsh.y"
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
#line 706 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 712 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 719 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 720 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 721 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 722 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 723 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 727 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 728 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 734 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 734 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 735 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 735 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 745 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 750 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 756 "Gmsh.y"
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
#line 818 "Gmsh.y"
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
#line 833 "Gmsh.y"
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
#line 862 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 872 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 877 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 885 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 890 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 898 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 907 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 912 "Gmsh.y"
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
#line 924 "Gmsh.y"
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
#line 941 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 947 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 956 "Gmsh.y"
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
#line 974 "Gmsh.y"
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
#line 992 "Gmsh.y"
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
#line 1001 "Gmsh.y"
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
#line 1013 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1018 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1026 "Gmsh.y"
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
#line 1046 "Gmsh.y"
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
#line 1069 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[(4) - (5)].d));
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[(4) - (5)].d));
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 102:
#line 1080 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1088 "Gmsh.y"
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
#line 1110 "Gmsh.y"
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
#line 1133 "Gmsh.y"
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
#line 1171 "Gmsh.y"
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
#line 1192 "Gmsh.y"
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
#line 1204 "Gmsh.y"
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
#line 1222 "Gmsh.y"
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
#line 1231 "Gmsh.y"
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
#line 1240 "Gmsh.y"
    { init_options(); ;}
    break;

  case 115:
#line 1242 "Gmsh.y"
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
#line 1260 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1262 "Gmsh.y"
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
#line 1278 "Gmsh.y"
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
#line 1287 "Gmsh.y"
    { init_options(); ;}
    break;

  case 120:
#line 1289 "Gmsh.y"
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
#line 1303 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 123:
#line 1311 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 124:
#line 1317 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 125:
#line 1322 "Gmsh.y"
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
#line 1364 "Gmsh.y"
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
#line 1376 "Gmsh.y"
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
#line 1389 "Gmsh.y"
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
#line 1404 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 140:
#line 1426 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 141:
#line 1434 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 142:
#line 1443 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 143:
#line 1451 "Gmsh.y"
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
#line 1469 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 145:
#line 1473 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 0, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 146:
#line 1480 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 147:
#line 1488 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 148:
#line 1492 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 1, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 149:
#line 1499 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 150:
#line 1507 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 151:
#line 1511 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 2, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 152:
#line 1518 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 153:
#line 1526 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 154:
#line 1530 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 3, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 155:
#line 1537 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 156:
#line 1545 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 157:
#line 1549 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 158:
#line 1555 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 159:
#line 1559 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 160:
#line 1566 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addVertex(num, x, y, z, lc);
      }
      else{
        if(!myGmshSurface)
          GModel::current()->getGEOInternals()->addVertex(num, x, y, z, lc);
        else
          GModel::current()->getGEOInternals()->addVertex(num, x, y, myGmshSurface, lc);
      }
      AddToTemporaryBoundingBox(x, y, z);
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 161:
#line 1587 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 162:
#line 1601 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Spline not available with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 163:
#line 1615 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){
          GModel::current()->getOCCInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 4 && param.size() <= 6){
          double r = param[3];
          double a1 = (param.size() == 6) ? param[4] : 0.;
          double a2 = (param.size() == 6) ? param[5] :
            (param.size() == 5) ? param[4] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addCircle
            (num, param[0], param[1], param[2], r, a1, a2);
        }
        else{
          yymsg(0, "Circle requires 3 points or 4 to 6 parameters");
        }
      }
      else{
        if(tags.size() == 3){
          GModel::current()->getGEOInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 164:
#line 1650 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){
          GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(tags.size() == 4){
          GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 or 4 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 4){
          GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 165:
#line 1688 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addBSpline(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 166:
#line 1702 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 167:
#line 1717 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), knots);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Nurbs not available yet with OpenCASCADE factory");
      }
      else{
        int order = knots.size() - tags.size() - 1;
        if(order != (int)(yyvsp[(10) - (11)].d))
          yymsg(1, "Incompatible Nurbs order: using %d", order);
        GModel::current()->getGEOInternals()->addNurbs(num, tags, knots);
      }
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 168:
#line 1736 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 169:
#line 1745 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available using OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 170:
#line 1759 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addLineLoop(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addLineLoop(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 171:
#line 1774 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 172:
#line 1788 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE face filling requires a single line loop");
        }
        else{
          GModel::current()->getOCCInternals()->addSurfaceFilling(num, wires[0]);
        }
      }
      else{
        GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(7) - (8)].i));
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1807 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(8) - (9)].i));
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 174:
#line 1817 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 175:
#line 1823 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 176:
#line 1829 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1836 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      (yyval.s).Type = 0;
      if(param.size() >= 4 && param.size() <= 7){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double a1 = (param.size() >= 5) ? param[4] : -M_PI/2;
          double a2 = (param.size() >= 6) ? param[5] : M_PI/2;
          double a3 = (param.size() >= 7) ? param[6] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addSphere
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Num = num;
    ;}
    break;

  case 178:
#line 1865 "Gmsh.y"
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
#line 1880 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6){
          GModel::current()->getOCCInternals()->addBlock
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Block requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Block only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1900 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 5 || param.size() == 6){
          double alpha = (param.size() == 6) ? param[5] : 2*M_PI;
          GModel::current()->getOCCInternals()->addTorus
            (num, param[0], param[1], param[2], param[3], param[4], alpha);
        }
        else{
          yymsg(0, "Torus requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Torus only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1921 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6 || param.size() == 7){
          double r = (param.size() == 7) ? param[6] : 0.;
          GModel::current()->getOCCInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4], param[5], r);
        }
        else{
          yymsg(0, "Rectangle requires 6 ou 7 parameters");
        }
      }
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 182:
#line 1942 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 4 || param.size() == 5){
          double ry = (param.size() == 5) ? param[4] : param[3];
          GModel::current()->getOCCInternals()->addDisk
            (num, param[0], param[1], param[2], param[3], ry);
        }
        else{
          yymsg(0, "Disk requires 4 or 5 parameters");
        }
      }
      else{
        yymsg(0, "Disk only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 183:
#line 1963 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 7 || param.size() == 8){
          double angle = (param.size() == 8) ? param[7] : 2*M_PI;
          GModel::current()->getOCCInternals()->addCylinder
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 184:
#line 1985 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 8 || param.size() == 9){
          double alpha = (param.size() == 9) ? param[8] : 2*M_PI;
          GModel::current()->getOCCInternals()->addCone
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 2007 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 7){
          GModel::current()->getOCCInternals()->addWedge
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2028 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(unsigned int i = 2; i < param.size(); i++)
            exclude.push_back(param[i]);
          GModel::current()->getOCCInternals()->addThickSolid
            (num, in, exclude, offset);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 parameters");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
    ;}
    break;

  case 187:
#line 2051 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2061 "Gmsh.y"
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
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags, bndTags);
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
#line 2081 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 190:
#line 2096 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2110 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, outDimTags, true, false);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2126 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, outDimTags, true, true);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2142 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 194:
#line 2151 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(0, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 195:
#line 2161 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(1, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2171 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(2, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 197:
#line 2181 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(3, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 198:
#line 2196 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->translate(dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        GModel::current()->getGEOInternals()->translate(dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 199:
#line 2208 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->rotate
          (dimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        GModel::current()->getGEOInternals()->rotate
          (dimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 200:
#line 2222 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("Symmetry not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 201:
#line 2235 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 202:
#line 2248 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 203:
#line 2261 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), inDimTags);
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      std::string action((yyvsp[(1) - (4)].c));
      if(action == "Duplicata"){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          GModel::current()->getOCCInternals()->copy(inDimTags, outDimTags);
        }
        else{
          GModel::current()->getGEOInternals()->copy(inDimTags, outDimTags);
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
        GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, action == "CombinedBoundary");
      }
      else{
        yymsg(0, "Unknown action on multiple shapes: %s", (yyvsp[(1) - (4)].c));
      }
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 204:
#line 2294 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE");
      }
      else{
        std::vector<int> in, out; ListOfDouble2Vector((yyvsp[(4) - (9)].l), in);
        GModel::current()->getGEOInternals()->intersectCurvesWithSurface
          (in, (int)(yyvsp[(8) - (9)].d), out);
        for(unsigned int i = 0; i < out.size(); i++){
          Shape s;
          s.Type = MSH_POINT;
          s.Num = out[i];
          List_Add((yyval.l), &s);
        }
      }
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 205:
#line 2314 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[(7) - (9)].l), vertices);
        GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[(4) - (9)].d), vertices, curves);
        for(unsigned int i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 206:
#line 2335 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 207:
#line 2336 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 208:
#line 2341 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 209:
#line 2345 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 210:
#line 2349 "Gmsh.y"
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
#line 2360 "Gmsh.y"
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
#line 2371 "Gmsh.y"
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
#line 2382 "Gmsh.y"
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
#line 2398 "Gmsh.y"
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
#line 2417 "Gmsh.y"
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
#line 2439 "Gmsh.y"
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
#line 2454 "Gmsh.y"
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
#line 2469 "Gmsh.y"
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
#line 2488 "Gmsh.y"
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
#line 2539 "Gmsh.y"
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
#line 2560 "Gmsh.y"
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
#line 2582 "Gmsh.y"
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
#line 2604 "Gmsh.y"
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
#line 2709 "Gmsh.y"
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
#line 2725 "Gmsh.y"
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
#line 2760 "Gmsh.y"
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
#line 2771 "Gmsh.y"
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
#line 2782 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 229:
#line 2788 "Gmsh.y"
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
#line 2803 "Gmsh.y"
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
#line 2831 "Gmsh.y"
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
#line 2843 "Gmsh.y"
    {
      nameSpaces.clear();
    ;}
    break;

  case 233:
#line 2852 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 234:
#line 2859 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 235:
#line 2871 "Gmsh.y"
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
#line 2890 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 237:
#line 2896 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 238:
#line 2902 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 2909 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 2916 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 241:
#line 2923 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 2935 "Gmsh.y"
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
#line 3008 "Gmsh.y"
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
#line 3026 "Gmsh.y"
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
#line 3043 "Gmsh.y"
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
#line 3058 "Gmsh.y"
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
#line 3091 "Gmsh.y"
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
#line 3103 "Gmsh.y"
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
#line 3127 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 250:
#line 3131 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 251:
#line 3136 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 252:
#line 3143 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 253:
#line 3148 "Gmsh.y"
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
#line 3158 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 255:
#line 3163 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 256:
#line 3169 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 257:
#line 3177 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 258:
#line 3181 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 259:
#line 3185 "Gmsh.y"
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
#line 3195 "Gmsh.y"
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
        yyerror("Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (16)].l)); i++){
          double d;
          List_Read((yyvsp[(6) - (16)].l), i, &d);
          gLevelset *l = gLevelset::find((int)d);
          if(l) f.push_back(l);
          else yymsg(0, "Unknown Levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yyerror("Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[(9) - (16)].l)) != (int)f.size()){
            yyerror("Number of parameters != number of levelsets");
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
#line 3258 "Gmsh.y"
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
#line 3274 "Gmsh.y"
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
#line 3291 "Gmsh.y"
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
#line 3308 "Gmsh.y"
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
#line 3330 "Gmsh.y"
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
#line 3352 "Gmsh.y"
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
#line 3387 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 268:
#line 3395 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 269:
#line 3403 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 270:
#line 3409 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 271:
#line 3416 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 272:
#line 3423 "Gmsh.y"
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
#line 3443 "Gmsh.y"
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
#line 3469 "Gmsh.y"
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
#line 3481 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 276:
#line 3493 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], outDimTags);
      }
      else{
        GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], outDimTags);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 277:
#line 3509 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), outDimTags);
      }
      else{
        GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), outDimTags);
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 278:
#line 3525 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (13)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2],
           (yyvsp[(9) - (13)].d),  outDimTags);
      }
      (yyval.l) = (yyvsp[(12) - (13)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 279:
#line 3541 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3547 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (7)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], outDimTags, &extr);
      }
      else{
        GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], outDimTags, &extr);
      }
      (yyval.l) = (yyvsp[(4) - (7)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 281:
#line 3563 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3569 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (13)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(7) - (13)].d), outDimTags,
           &extr);
      }
      else{
        GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(7) - (13)].d), outDimTags,
           &extr);
      }
      (yyval.l) = (yyvsp[(10) - (13)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 283:
#line 3587 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3593 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (15)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2],
           (yyvsp[(9) - (15)].d),  outDimTags, &extr);
      }
      (yyval.l) = (yyvsp[(12) - (15)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 285:
#line 3609 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3615 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (6)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Boundary layer extrusion not available with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->boundaryLayer
          (inDimTags, outDimTags, &extr);
      }
      (yyval.l) = (yyvsp[(3) - (6)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 287:
#line 3630 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), inDimTags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addPipe(inDimTags, (int)(yyvsp[(8) - (9)].d), outDimTags);
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE factory");
      }
      (yyval.l) = (yyvsp[(3) - (9)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 288:
#line 3644 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, outDimTags, false, false);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 289:
#line 3659 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, outDimTags, false, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 290:
#line 3674 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        std::vector<std::pair<int, int> > outDimTags;
        GModel::current()->getOCCInternals()->fillet
          (regions, edges, radius, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    ;}
    break;

  case 291:
#line 3695 "Gmsh.y"
    {
    ;}
    break;

  case 292:
#line 3698 "Gmsh.y"
    {
    ;}
    break;

  case 293:
#line 3704 "Gmsh.y"
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
#line 3716 "Gmsh.y"
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
#line 3736 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 296:
#line 3740 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 297:
#line 3744 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 298:
#line 3748 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 299:
#line 3752 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3756 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 301:
#line 3760 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3764 "Gmsh.y"
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
#line 3773 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 304:
#line 3785 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 305:
#line 3786 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 306:
#line 3787 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 307:
#line 3788 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 308:
#line 3789 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 309:
#line 3793 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 310:
#line 3794 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 311:
#line 3795 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 312:
#line 3796 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 313:
#line 3797 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 314:
#line 3802 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (9)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), object, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 315:
#line 3822 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE factory");
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 316:
#line 3840 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (14)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(11) - (14)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), object, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 317:
#line 3858 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 318:
#line 3862 "Gmsh.y"
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
#line 3877 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 320:
#line 3881 "Gmsh.y"
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
#line 3897 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 322:
#line 3901 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 323:
#line 3906 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 324:
#line 3910 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 325:
#line 3916 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 326:
#line 3920 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 327:
#line 3927 "Gmsh.y"
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
#line 3944 "Gmsh.y"
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
#line 3985 "Gmsh.y"
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
#line 4029 "Gmsh.y"
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
#line 4068 "Gmsh.y"
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
#line 4093 "Gmsh.y"
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
#line 4102 "Gmsh.y"
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
#line 4132 "Gmsh.y"
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
#line 4158 "Gmsh.y"
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
#line 4185 "Gmsh.y"
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
#line 4217 "Gmsh.y"
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
#line 4244 "Gmsh.y"
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
#line 4270 "Gmsh.y"
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
#line 4296 "Gmsh.y"
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
#line 4322 "Gmsh.y"
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
#line 4348 "Gmsh.y"
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
#line 4369 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 344:
#line 4375 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 345:
#line 4381 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 346:
#line 4387 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 347:
#line 4393 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 348:
#line 4399 "Gmsh.y"
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
#line 4425 "Gmsh.y"
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
#line 4451 "Gmsh.y"
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
#line 4468 "Gmsh.y"
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
#line 4485 "Gmsh.y"
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
#line 4502 "Gmsh.y"
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
#line 4514 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 355:
#line 4520 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 356:
#line 4526 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 357:
#line 4538 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 358:
#line 4542 "Gmsh.y"
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
#line 4552 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 360:
#line 4562 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 361:
#line 4563 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 362:
#line 4564 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 363:
#line 4569 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 364:
#line 4575 "Gmsh.y"
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
#line 4587 "Gmsh.y"
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
#line 4605 "Gmsh.y"
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
#line 4632 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 368:
#line 4633 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 369:
#line 4634 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 370:
#line 4635 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 371:
#line 4636 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 372:
#line 4637 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 373:
#line 4638 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4639 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4641 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 376:
#line 4647 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 377:
#line 4648 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 378:
#line 4649 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 379:
#line 4650 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 380:
#line 4651 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 381:
#line 4652 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 382:
#line 4653 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 383:
#line 4654 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4655 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4656 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4657 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 387:
#line 4658 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 388:
#line 4659 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 389:
#line 4660 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 390:
#line 4661 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 391:
#line 4662 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4663 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 393:
#line 4664 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 394:
#line 4665 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 395:
#line 4666 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 4667 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4668 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 398:
#line 4669 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4670 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 400:
#line 4671 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4672 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 402:
#line 4673 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 403:
#line 4674 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 404:
#line 4675 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4676 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 406:
#line 4677 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 407:
#line 4678 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 408:
#line 4679 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 409:
#line 4680 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 410:
#line 4689 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 411:
#line 4690 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 412:
#line 4691 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 413:
#line 4692 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 414:
#line 4693 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 415:
#line 4694 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 416:
#line 4695 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 417:
#line 4696 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 418:
#line 4697 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 419:
#line 4698 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 420:
#line 4699 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 421:
#line 4704 "Gmsh.y"
    { init_options(); ;}
    break;

  case 422:
#line 4706 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 423:
#line 4712 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 424:
#line 4714 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 425:
#line 4719 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 426:
#line 4725 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(1) - (1)].c2).char2)){
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (1)].c2).char2]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c2).char2);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      else{
        std::string struct_namespace((yyvsp[(1) - (1)].c2).char1? (yyvsp[(1) - (1)].c2).char1 : std::string("")),
          struct_name((yyvsp[(1) - (1)].c2).char2);
        if(nameSpaces.getTag(struct_namespace, struct_name, (yyval.d))) {
          yymsg(0, "Unknown Constant: %s", struct_name.c_str());
        }
      }
      Free((yyvsp[(1) - (1)].c2).char1); Free((yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 427:
#line 4745 "Gmsh.y"
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

  case 428:
#line 4763 "Gmsh.y"
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

  case 429:
#line 4781 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(3) - (4)].c2).char2)){
        (yyval.d) = 1;
      }
      else{
        std::string struct_namespace((yyvsp[(3) - (4)].c2).char1? (yyvsp[(3) - (4)].c2).char1 : std::string("")),
          struct_name((yyvsp[(3) - (4)].c2).char2);
        (yyval.d) = (nameSpaces.getTag(struct_namespace, struct_name, (yyval.d)))? 0 : 1;
      }
      Free((yyvsp[(3) - (4)].c2).char1); Free((yyvsp[(3) - (4)].c2).char2);
    ;}
    break;

  case 430:
#line 4793 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (6)].c2).char1? (yyvsp[(3) - (6)].c2).char1 : std::string("")),
        struct_name((yyvsp[(3) - (6)].c2).char2);
      Free((yyvsp[(3) - (6)].c2).char1); Free((yyvsp[(3) - (6)].c2).char2);
      std::string key_member((yyvsp[(5) - (6)].c));
      (yyval.d) = (nameSpaces.getMember
            (struct_namespace, struct_name, key_member, (yyval.d)))? 0 : 1;
      if (flag_tSTRING_alloc) Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 431:
#line 4803 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 432:
#line 4809 "Gmsh.y"
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

  case 433:
#line 4825 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 434:
#line 4831 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 435:
#line 4837 "Gmsh.y"
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

  case 436:
#line 4856 "Gmsh.y"
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

  case 437:
#line 4877 "Gmsh.y"
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

  case 438:
#line 4910 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
      /*
      std::string struct_namespace($1.char1? $1.char1 : std::string("")),
        struct_name($1.char2);
      std::string key_member($3);
      switch (nameSpaces.getMember
              (struct_namespace, struct_name, key_member, $$)) {
      case 0:
        break;
      case 1:
        NumberOption(GMSH_GET, $1.char2, 0, $3, $$);
        break;
      case 2:
        yymsg(0, "Unknown member '%s' of Struct %s", $3, struct_name.c_str());
        break;
      }
      Free($1.char1); Free($1.char2);
      if (flag_tSTRING_alloc) Free($3);
      */
    ;}
    break;

  case 439:
#line 4932 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 440:
#line 4937 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 441:
#line 4942 "Gmsh.y"
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

  case 442:
#line 4952 "Gmsh.y"
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

  case 443:
#line 4962 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 444:
#line 4967 "Gmsh.y"
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

  case 445:
#line 4978 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 446:
#line 4987 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 447:
#line 4992 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 448:
#line 4997 "Gmsh.y"
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[(3) - (4)].l)) % 2){
        yyerror("Number of text attributes should be even");
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

  case 449:
#line 5025 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 450:
#line 5032 "Gmsh.y"
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

  case 451:
#line 5048 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 452:
#line 5050 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 453:
#line 5055 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 454:
#line 5064 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 455:
#line 5066 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 456:
#line 5071 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 457:
#line 5073 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 458:
#line 5079 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 459:
#line 5083 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 460:
#line 5087 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 461:
#line 5091 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 462:
#line 5095 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 463:
#line 5102 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 464:
#line 5106 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 465:
#line 5110 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 466:
#line 5114 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 467:
#line 5121 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 468:
#line 5126 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 469:
#line 5133 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 470:
#line 5138 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 471:
#line 5142 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 472:
#line 5147 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 473:
#line 5151 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 474:
#line 5159 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 475:
#line 5170 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 476:
#line 5174 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 477:
#line 5186 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 478:
#line 5194 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 479:
#line 5202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 480:
#line 5209 "Gmsh.y"
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

  case 481:
#line 5219 "Gmsh.y"
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

  case 482:
#line 5242 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 483:
#line 5248 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 484:
#line 5254 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 485:
#line 5260 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 486:
#line 5266 "Gmsh.y"
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

  case 487:
#line 5277 "Gmsh.y"
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

  case 488:
#line 5288 "Gmsh.y"
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

  case 489:
#line 5299 "Gmsh.y"
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

  case 490:
#line 5311 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 491:
#line 5317 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 492:
#line 5323 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 493:
#line 5329 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 494:
#line 5334 "Gmsh.y"
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

  case 495:
#line 5344 "Gmsh.y"
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

  case 496:
#line 5354 "Gmsh.y"
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
#line 5364 "Gmsh.y"
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

  case 498:
#line 5377 "Gmsh.y"
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

  case 499:
#line 5389 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 500:
#line 5393 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 501:
#line 5397 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 502:
#line 5401 "Gmsh.y"
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

  case 503:
#line 5419 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 504:
#line 5427 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 505:
#line 5435 "Gmsh.y"
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

  case 506:
#line 5464 "Gmsh.y"
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

  case 507:
#line 5474 "Gmsh.y"
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

  case 508:
#line 5490 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 509:
#line 5501 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 510:
#line 5506 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 511:
#line 5510 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 512:
#line 5514 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 513:
#line 5526 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 514:
#line 5530 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 515:
#line 5542 "Gmsh.y"
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

  case 516:
#line 5559 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 517:
#line 5569 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 518:
#line 5573 "Gmsh.y"
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

  case 519:
#line 5588 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 520:
#line 5593 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 521:
#line 5600 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 522:
#line 5604 "Gmsh.y"
    {
      std::string val;
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (1)].c));
      else if(gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)].size() == 1)
        val = gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)][0];
      else
        yymsg(0, "Expected single valued string variable '%s'", (yyvsp[(1) - (1)].c));
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 523:
#line 5617 "Gmsh.y"
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

  case 524:
#line 5631 "Gmsh.y"
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

  case 525:
#line 5648 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
      /*
      std::string out;
      std::string struct_namespace($1.char1? $1.char1 : std::string("")),
        struct_name($1.char2);
      std::string key_member($3);
      const std::string * out = NULL;
      std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
      switch (nameSpaces.getMember
              (struct_namespace, struct_name, key_member, out)) {
      case 0:
        break;
      case 1:
        StringOption(GMSH_GET, $1, 0, $3, out_tmp);
        out = &out_tmp;
        break;
      case 2:
        yymsg(0, "Unknown member '%s' of Struct %s", $3, struct_name.c_str());
        break;
      }
      char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
      strcpy(out_c, out->c_str());
      Free($1.char1); Free($1.char2);
      if (flag_tSTRING_alloc) Free(c3);
      */
    ;}
    break;

  case 526:
#line 5676 "Gmsh.y"
    { (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 527:
#line 5680 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 528:
#line 5688 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 529:
#line 5694 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 530:
#line 5700 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 531:
#line 5706 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 532:
#line 5715 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 533:
#line 5719 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 534:
#line 5723 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 535:
#line 5731 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 536:
#line 5737 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 537:
#line 5743 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 538:
#line 5747 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 539:
#line 5755 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 540:
#line 5763 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 541:
#line 5770 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 542:
#line 5778 "Gmsh.y"
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

  case 543:
#line 5793 "Gmsh.y"
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

  case 544:
#line 5807 "Gmsh.y"
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

  case 545:
#line 5821 "Gmsh.y"
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

  case 546:
#line 5833 "Gmsh.y"
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

  case 547:
#line 5849 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 548:
#line 5858 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 549:
#line 5867 "Gmsh.y"
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

  case 550:
#line 5877 "Gmsh.y"
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

  case 551:
#line 5888 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 552:
#line 5896 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 553:
#line 5904 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 554:
#line 5908 "Gmsh.y"
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

  case 555:
#line 5927 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 556:
#line 5934 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 557:
#line 5940 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 558:
#line 5947 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 559:
#line 5954 "Gmsh.y"
    { init_options(); ;}
    break;

  case 560:
#line 5956 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 561:
#line 5964 "Gmsh.y"
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

  case 562:
#line 5988 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 563:
#line 5990 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 564:
#line 5996 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 565:
#line 6001 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 566:
#line 6009 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 567:
#line 6018 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 568:
#line 6031 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 569:
#line 6034 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 570:
#line 6038 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13047 "Gmsh.tab.cpp"
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


#line 6041 "Gmsh.y"


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

double treat_Struct_FullName_dot_tSTRING_Float(char* c1, char* c2, char* c3)
{
  double out;
  std::string struct_namespace(c1? c1 : std::string("")),
    struct_name(c2);
  /*
    std::string struct_namespace($1.char1? $1.char1 : std::string("")),
      struct_name($1.char2);
  */
  std::string key_member(c3);
  switch (nameSpaces.getMember
          (struct_namespace, struct_name, key_member, out)) {
  case 0:
    break;
  case 1:
    NumberOption(GMSH_GET, c2, 0, c3, out);
    break;
  case 2:
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}

char* treat_Struct_FullName_dot_tSTRING_String(char* c1, char* c2, char* c3)
{
  std::string struct_namespace(c1? c1 : std::string("")),
    struct_name(c2);
  /*
  std::string struct_namespace($1.char1? $1.char1 : std::string("")),
    struct_name($1.char2);
  */
  std::string key_member(c3);
  const std::string * out = NULL;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  switch (nameSpaces.getMember
          (struct_namespace, struct_name, key_member, out)) {
  case 0:
    break;
  case 1:
    StringOption(GMSH_GET, c2, 0, c3, out_tmp);
    out = &out_tmp;
    break;
  case 2:
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }

  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out_c;
}

