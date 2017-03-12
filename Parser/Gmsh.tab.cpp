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
static NameSpaces nameSpaces;
static std::string struct_name, struct_namespace;
static int flag_tSTRING_alloc = 0;

static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static int flag_Enum, member_ValMax;

void init_Options(int member_ValMax_ = 0)
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
#define YYLAST   13637

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  569
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2089

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
    1332,  1336,  1341,  1347,  1354,  1360,  1364,  1368,  1373,  1379,
    1384,  1390,  1394,  1400,  1408,  1416,  1420,  1428,  1432,  1435,
    1438,  1441,  1444,  1447,  1463,  1466,  1469,  1472,  1475,  1478,
    1495,  1507,  1514,  1523,  1532,  1543,  1545,  1548,  1551,  1553,
    1557,  1561,  1566,  1571,  1573,  1575,  1581,  1593,  1607,  1608,
    1616,  1617,  1631,  1632,  1648,  1649,  1656,  1666,  1669,  1673,
    1684,  1686,  1689,  1695,  1703,  1706,  1709,  1713,  1716,  1720,
    1723,  1727,  1737,  1744,  1746,  1748,  1750,  1752,  1754,  1755,
    1758,  1762,  1766,  1771,  1781,  1786,  1801,  1802,  1806,  1807,
    1809,  1810,  1813,  1814,  1817,  1818,  1821,  1828,  1836,  1843,
    1849,  1853,  1862,  1868,  1873,  1880,  1892,  1904,  1923,  1942,
    1955,  1968,  1981,  1992,  2003,  2014,  2025,  2036,  2041,  2046,
    2051,  2056,  2061,  2066,  2071,  2076,  2081,  2084,  2088,  2095,
    2097,  2099,  2101,  2104,  2110,  2118,  2129,  2131,  2135,  2138,
    2141,  2144,  2148,  2152,  2156,  2160,  2164,  2168,  2172,  2176,
    2180,  2184,  2188,  2192,  2196,  2200,  2206,  2211,  2216,  2221,
    2226,  2231,  2236,  2241,  2246,  2251,  2256,  2263,  2268,  2273,
    2278,  2283,  2288,  2293,  2298,  2303,  2310,  2317,  2324,  2329,
    2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,
    2351,  2352,  2359,  2361,  2366,  2373,  2375,  2380,  2385,  2390,
    2397,  2402,  2407,  2411,  2414,  2417,  2423,  2429,  2433,  2439,
    2446,  2451,  2459,  2466,  2473,  2480,  2485,  2492,  2497,  2498,
    2506,  2508,  2512,  2514,  2516,  2519,  2520,  2524,  2526,  2529,
    2532,  2536,  2540,  2552,  2562,  2570,  2578,  2580,  2584,  2586,
    2588,  2591,  2595,  2600,  2606,  2608,  2610,  2613,  2617,  2621,
    2627,  2632,  2635,  2638,  2641,  2644,  2648,  2652,  2656,  2660,
    2677,  2694,  2711,  2728,  2730,  2732,  2734,  2738,  2743,  2748,
    2753,  2760,  2767,  2776,  2785,  2790,  2805,  2810,  2815,  2817,
    2819,  2823,  2827,  2837,  2845,  2847,  2853,  2857,  2864,  2866,
    2870,  2872,  2874,  2879,  2884,  2888,  2894,  2901,  2907,  2913,
    2919,  2925,  2927,  2932,  2934,  2936,  2938,  2940,  2945,  2952,
    2957,  2964,  2969,  2974,  2979,  2988,  2993,  2998,  3003,  3008,
    3017,  3026,  3033,  3038,  3045,  3050,  3052,  3057,  3062,  3063,
    3070,  3075,  3078,  3083,  3085,  3089,  3095,  3101,  3103,  3105
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
      -1,   172,   336,   235,   291,   236,    -1,   130,   172,   336,
     235,   291,   236,    -1,   205,   320,   235,   291,   236,    -1,
     188,     5,     6,    -1,   189,     5,     6,    -1,   188,   235,
     291,   236,    -1,   130,   188,   235,   291,   236,    -1,   189,
     235,   291,   236,    -1,   130,   189,   235,   291,   236,    -1,
     345,   340,     6,    -1,    73,   231,   343,   232,     6,    -1,
     345,   345,   233,   320,   234,   339,     6,    -1,   345,   345,
     345,   233,   320,   234,     6,    -1,   345,   320,     6,    -1,
     128,   231,     4,   232,   237,     4,     6,    -1,   166,     4,
       6,    -1,   181,     6,    -1,   182,     6,    -1,    70,     6,
      -1,    71,     6,    -1,    64,     6,    -1,    64,   235,   320,
     240,   320,   240,   320,   240,   320,   240,   320,   240,   320,
     236,     6,    -1,    65,     6,    -1,    66,     6,    -1,    78,
       6,    -1,    79,     6,    -1,   113,     6,    -1,   114,   235,
     335,   236,   235,   335,   236,   235,   331,   236,   235,   320,
     240,   320,   236,     6,    -1,   186,   231,   235,   335,   236,
     240,   340,   240,   340,   232,     6,    -1,   174,   231,   320,
       8,   320,   232,    -1,   174,   231,   320,     8,   320,     8,
     320,   232,    -1,   174,     4,   175,   235,   320,     8,   320,
     236,    -1,   174,     4,   175,   235,   320,     8,   320,     8,
     320,   236,    -1,   176,    -1,   187,     4,    -1,   187,   340,
      -1,   184,    -1,   185,   345,     6,    -1,   185,   340,     6,
      -1,   177,   231,   320,   232,    -1,   178,   231,   320,   232,
      -1,   179,    -1,   180,    -1,   135,   329,   235,   291,   236,
      -1,   135,   235,   329,   240,   329,   240,   320,   236,   235,
     291,   236,    -1,   135,   235,   329,   240,   329,   240,   329,
     240,   320,   236,   235,   291,   236,    -1,    -1,   135,   329,
     235,   291,   301,   305,   236,    -1,    -1,   135,   235,   329,
     240,   329,   240,   320,   236,   235,   291,   302,   305,   236,
      -1,    -1,   135,   235,   329,   240,   329,   240,   329,   240,
     320,   236,   235,   291,   303,   305,   236,    -1,    -1,   135,
     235,   291,   304,   305,   236,    -1,   135,   235,   291,   236,
     127,   108,   235,   320,   236,    -1,   117,   332,    -1,   122,
     117,   332,    -1,   119,   235,   335,   236,   235,   335,   236,
     235,   320,   236,    -1,   306,    -1,   305,   306,    -1,   152,
     235,   320,   236,     6,    -1,   152,   235,   332,   240,   332,
     236,     6,    -1,   153,     6,    -1,   144,     6,    -1,   144,
     320,     6,    -1,   158,     6,    -1,   158,   160,     6,    -1,
     159,     6,    -1,   159,   160,     6,    -1,   154,   231,   320,
     232,     7,   332,   127,   320,     6,    -1,   127,     4,   233,
     320,   234,     6,    -1,   138,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    -1,    -1,   147,     6,    -1,   130,   147,
       6,    -1,   147,   320,     6,    -1,   130,   147,   320,     6,
      -1,   307,   235,   291,   308,   236,   235,   291,   308,   236,
      -1,   105,   231,   339,   232,    -1,   307,   231,   320,   232,
       7,   235,   291,   308,   236,   235,   291,   308,   236,     6,
      -1,    -1,   127,     4,   320,    -1,    -1,     4,    -1,    -1,
       7,   332,    -1,    -1,     7,   320,    -1,    -1,   137,   332,
      -1,   109,   110,   332,     7,   320,     6,    -1,   123,    93,
     333,     7,   320,   311,     6,    -1,   123,    96,   333,   313,
     312,     6,    -1,   123,    98,   333,   313,     6,    -1,   161,
     333,     6,    -1,   150,    96,   235,   335,   236,     7,   320,
       6,    -1,   144,    96,   333,   314,     6,    -1,   144,    98,
     333,     6,    -1,   145,    96,   333,     7,   320,     6,    -1,
     126,    93,   235,   335,   236,     7,   235,   335,   236,   315,
       6,    -1,   126,    96,   235,   335,   236,     7,   235,   335,
     236,   315,     6,    -1,   126,    93,   235,   335,   236,     7,
     235,   335,   236,   131,   235,   329,   240,   329,   240,   320,
     236,     6,    -1,   126,    96,   235,   335,   236,     7,   235,
     335,   236,   131,   235,   329,   240,   329,   240,   320,   236,
       6,    -1,   126,    93,   235,   335,   236,     7,   235,   335,
     236,   132,   329,     6,    -1,   126,    96,   235,   335,   236,
       7,   235,   335,   236,   132,   329,     6,    -1,   126,    96,
     320,   235,   335,   236,     7,   320,   235,   335,   236,     6,
      -1,    90,   235,   335,   236,   175,    96,   235,   320,   236,
       6,    -1,    93,   235,   335,   236,   175,    96,   235,   320,
     236,     6,    -1,    90,   235,   335,   236,   175,    98,   235,
     320,   236,     6,    -1,    93,   235,   335,   236,   175,    98,
     235,   320,   236,     6,    -1,    96,   235,   335,   236,   175,
      98,   235,   320,   236,     6,    -1,   151,    96,   333,     6,
      -1,   151,    93,   333,     6,    -1,   115,    90,   333,     6,
      -1,   115,    93,   333,     6,    -1,   115,    96,   333,     6,
      -1,   129,    93,   332,     6,    -1,   125,    93,   332,     6,
      -1,   125,    96,   332,     6,    -1,   125,    98,   332,     6,
      -1,   148,     6,    -1,   148,     4,     6,    -1,   148,    90,
     235,   335,   236,     6,    -1,   196,    -1,   197,    -1,   198,
      -1,   318,     6,    -1,   318,   235,   332,   236,     6,    -1,
     318,   235,   332,   240,   332,   236,     6,    -1,   318,   231,
     332,   232,   235,   332,   240,   332,   236,     6,    -1,   321,
      -1,   231,   320,   232,    -1,   222,   320,    -1,   221,   320,
      -1,   226,   320,    -1,   320,   222,   320,    -1,   320,   221,
     320,    -1,   320,   223,   320,    -1,   320,   224,   320,    -1,
     320,   225,   320,    -1,   320,   230,   320,    -1,   320,   217,
     320,    -1,   320,   218,   320,    -1,   320,   220,   320,    -1,
     320,   219,   320,    -1,   320,   216,   320,    -1,   320,   215,
     320,    -1,   320,   214,   320,    -1,   320,   213,   320,    -1,
     320,   212,   320,     8,   320,    -1,    16,   265,   320,   266,
      -1,    17,   265,   320,   266,    -1,    18,   265,   320,   266,
      -1,    19,   265,   320,   266,    -1,    20,   265,   320,   266,
      -1,    21,   265,   320,   266,    -1,    22,   265,   320,   266,
      -1,    23,   265,   320,   266,    -1,    24,   265,   320,   266,
      -1,    26,   265,   320,   266,    -1,    27,   265,   320,   240,
     320,   266,    -1,    28,   265,   320,   266,    -1,    29,   265,
     320,   266,    -1,    30,   265,   320,   266,    -1,    31,   265,
     320,   266,    -1,    32,   265,   320,   266,    -1,    33,   265,
     320,   266,    -1,    34,   265,   320,   266,    -1,    35,   265,
     320,   266,    -1,    36,   265,   320,   240,   320,   266,    -1,
      37,   265,   320,   240,   320,   266,    -1,    38,   265,   320,
     240,   320,   266,    -1,    25,   265,   320,   266,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   201,
      -1,   202,    -1,   203,    -1,    75,    -1,    76,    -1,    77,
      -1,    -1,    83,   265,   320,   322,   275,   266,    -1,   323,
      -1,   194,   265,   339,   266,    -1,   194,   265,   339,   240,
     320,   266,    -1,   325,    -1,   345,   233,   320,   234,    -1,
     345,   231,   320,   232,    -1,   199,   231,   325,   232,    -1,
     199,   231,   325,   237,   326,   232,    -1,   200,   231,   340,
     232,    -1,   238,   345,   265,   266,    -1,   238,   345,     9,
      -1,   238,     9,    -1,   345,   264,    -1,   345,   233,   320,
     234,   264,    -1,   345,   231,   320,   232,   264,    -1,   345,
     237,   326,    -1,   345,     9,   345,   237,   326,    -1,   345,
     233,   320,   234,   237,     4,    -1,   345,   237,     4,   264,
      -1,   345,   233,   320,   234,   237,     4,   264,    -1,   190,
     231,   339,   240,   320,   232,    -1,    56,   231,   332,   240,
     332,   232,    -1,    57,   265,   339,   240,   339,   266,    -1,
      55,   265,   339,   266,    -1,    58,   265,   339,   240,   339,
     266,    -1,    63,   231,   343,   232,    -1,    -1,    84,   325,
     328,   324,   233,   276,   234,    -1,   345,    -1,   345,     9,
     345,    -1,     4,    -1,    86,    -1,    86,   320,    -1,    -1,
     231,   327,   232,    -1,   330,    -1,   222,   329,    -1,   221,
     329,    -1,   329,   222,   329,    -1,   329,   221,   329,    -1,
     235,   320,   240,   320,   240,   320,   240,   320,   240,   320,
     236,    -1,   235,   320,   240,   320,   240,   320,   240,   320,
     236,    -1,   235,   320,   240,   320,   240,   320,   236,    -1,
     231,   320,   240,   320,   240,   320,   232,    -1,   332,    -1,
     331,   240,   332,    -1,   320,    -1,   334,    -1,   235,   236,
      -1,   235,   335,   236,    -1,   222,   235,   335,   236,    -1,
     320,   223,   235,   335,   236,    -1,   332,    -1,     5,    -1,
     222,   334,    -1,   320,   223,   334,    -1,   320,     8,   320,
      -1,   320,     8,   320,     8,   320,    -1,    90,   235,   320,
     236,    -1,    90,     5,    -1,    93,     5,    -1,    96,     5,
      -1,    98,     5,    -1,   124,    90,   333,    -1,   124,    93,
     333,    -1,   124,    96,   333,    -1,   124,    98,   333,    -1,
      90,   175,    64,   235,   320,   240,   320,   240,   320,   240,
     320,   240,   320,   240,   320,   236,    -1,    93,   175,    64,
     235,   320,   240,   320,   240,   320,   240,   320,   240,   320,
     240,   320,   236,    -1,    96,   175,    64,   235,   320,   240,
     320,   240,   320,   240,   320,   240,   320,   240,   320,   236,
      -1,    98,   175,    64,   235,   320,   240,   320,   240,   320,
     240,   320,   240,   320,   240,   320,   236,    -1,   289,    -1,
     300,    -1,   309,    -1,   345,   265,   266,    -1,    39,   233,
     345,   234,    -1,    39,   233,   334,   234,    -1,    39,   231,
     334,   232,    -1,    39,   265,   235,   335,   236,   266,    -1,
     345,   265,   235,   335,   236,   266,    -1,    40,   265,   320,
     240,   320,   240,   320,   266,    -1,    41,   265,   320,   240,
     320,   240,   320,   266,    -1,    42,   265,   339,   266,    -1,
      43,   265,   320,   240,   320,   240,   320,   240,   320,   240,
     320,   240,   320,   266,    -1,   195,   265,   334,   266,    -1,
      32,   265,   334,   266,    -1,   320,    -1,   334,    -1,   335,
     240,   320,    -1,   335,   240,   334,    -1,   235,   320,   240,
     320,   240,   320,   240,   320,   236,    -1,   235,   320,   240,
     320,   240,   320,   236,    -1,   345,    -1,     4,   237,   172,
     237,     4,    -1,   235,   338,   236,    -1,   345,   233,   320,
     234,   237,   173,    -1,   336,    -1,   338,   240,   336,    -1,
     340,    -1,   345,    -1,   345,   233,   320,   234,    -1,   345,
     231,   320,   232,    -1,   345,   237,   326,    -1,   345,     9,
     345,   237,   326,    -1,   345,   233,   320,   234,   237,     4,
      -1,   124,    90,   235,   320,   236,    -1,   124,    93,   235,
     320,   236,    -1,   124,    96,   235,   320,   236,    -1,   124,
      98,   235,   320,   236,    -1,     5,    -1,   206,   233,   345,
     234,    -1,    67,    -1,   204,    -1,    72,    -1,    74,    -1,
     192,   231,   339,   232,    -1,   191,   231,   339,   240,   339,
     232,    -1,   193,   265,   339,   266,    -1,   193,   265,   339,
     240,   339,   266,    -1,    48,   265,   343,   266,    -1,    49,
     231,   339,   232,    -1,    50,   231,   339,   232,    -1,    51,
     231,   339,   240,   339,   240,   339,   232,    -1,    46,   265,
     343,   266,    -1,    60,   265,   339,   266,    -1,    61,   265,
     339,   266,    -1,    62,   265,   339,   266,    -1,    59,   265,
     320,   240,   339,   240,   339,   266,    -1,    54,   265,   339,
     240,   320,   240,   320,   266,    -1,    54,   265,   339,   240,
     320,   266,    -1,    47,   265,   339,   266,    -1,    47,   265,
     339,   240,   335,   266,    -1,    68,   265,   339,   266,    -1,
      69,    -1,    53,   265,   339,   266,    -1,    52,   265,   339,
     266,    -1,    -1,    87,   265,   340,   341,   279,   266,    -1,
      85,   265,   342,   266,    -1,   238,   320,    -1,   345,     9,
     238,   320,    -1,   339,    -1,   343,   240,   339,    -1,     4,
     239,   235,   320,   236,    -1,   344,   239,   235,   320,   236,
      -1,     4,    -1,   344,    -1,   207,   233,   339,   234,    -1
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
    2802,  2830,  2847,  2854,  2866,  2885,  2891,  2897,  2904,  2911,
    2918,  2930,  3003,  3021,  3038,  3053,  3086,  3098,  3122,  3126,
    3131,  3138,  3143,  3153,  3158,  3164,  3172,  3176,  3180,  3189,
    3253,  3269,  3286,  3303,  3325,  3347,  3382,  3390,  3398,  3404,
    3411,  3418,  3438,  3464,  3476,  3488,  3504,  3520,  3537,  3536,
    3559,  3558,  3583,  3582,  3605,  3604,  3625,  3639,  3654,  3669,
    3690,  3693,  3699,  3711,  3731,  3735,  3739,  3743,  3747,  3751,
    3755,  3759,  3768,  3781,  3782,  3783,  3784,  3785,  3789,  3790,
    3791,  3792,  3793,  3796,  3817,  3834,  3854,  3857,  3873,  3876,
    3893,  3896,  3902,  3905,  3912,  3915,  3922,  3939,  3980,  4024,
    4063,  4088,  4097,  4127,  4153,  4179,  4211,  4238,  4264,  4290,
    4316,  4342,  4364,  4370,  4376,  4382,  4388,  4394,  4420,  4446,
    4463,  4480,  4497,  4509,  4515,  4521,  4533,  4537,  4547,  4558,
    4559,  4560,  4564,  4570,  4582,  4600,  4628,  4629,  4630,  4631,
    4632,  4633,  4634,  4635,  4636,  4643,  4644,  4645,  4646,  4647,
    4648,  4649,  4650,  4651,  4652,  4653,  4654,  4655,  4656,  4657,
    4658,  4659,  4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,
    4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,  4676,  4685,
    4686,  4687,  4688,  4689,  4690,  4691,  4692,  4693,  4694,  4695,
    4700,  4699,  4707,  4709,  4714,  4720,  4740,  4758,  4776,  4788,
    4798,  4804,  4820,  4826,  4832,  4851,  4872,  4905,  4927,  4932,
    4937,  4947,  4957,  4962,  4973,  4982,  4987,  4992,  5021,  5020,
    5043,  5045,  5050,  5059,  5061,  5067,  5068,  5074,  5078,  5082,
    5086,  5090,  5097,  5101,  5105,  5109,  5116,  5121,  5128,  5133,
    5137,  5142,  5146,  5154,  5165,  5169,  5181,  5189,  5197,  5204,
    5214,  5237,  5243,  5249,  5255,  5261,  5272,  5283,  5294,  5305,
    5311,  5317,  5323,  5329,  5339,  5349,  5359,  5372,  5384,  5388,
    5392,  5396,  5414,  5422,  5430,  5459,  5469,  5485,  5496,  5501,
    5505,  5509,  5521,  5525,  5537,  5554,  5564,  5568,  5583,  5588,
    5595,  5599,  5612,  5626,  5643,  5671,  5675,  5683,  5689,  5695,
    5701,  5710,  5714,  5718,  5726,  5732,  5738,  5742,  5750,  5758,
    5765,  5773,  5788,  5802,  5816,  5828,  5844,  5853,  5862,  5872,
    5883,  5891,  5899,  5903,  5922,  5929,  5935,  5942,  5950,  5949,
    5959,  5983,  5985,  5991,  5996,  6004,  6013,  6026,  6029,  6033
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
     293,   293,   294,   294,   295,   296,   296,   296,   296,   296,
     296,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   300,   300,   300,   301,   300,
     302,   300,   303,   300,   304,   300,   300,   300,   300,   300,
     305,   305,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   307,   307,   307,   307,   307,   308,   308,
     308,   308,   308,   309,   309,   310,   311,   311,   312,   312,
     313,   313,   314,   314,   315,   315,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   317,   317,   317,   318,
     318,   318,   319,   319,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   324,   323,
     325,   325,   326,   327,   327,   328,   328,   329,   329,   329,
     329,   329,   330,   330,   330,   330,   331,   331,   332,   332,
     332,   332,   332,   332,   333,   333,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   335,   335,
     335,   335,   336,   336,   336,   336,   337,   337,   338,   338,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   341,   340,
     340,   342,   342,   343,   343,   344,   344,   345,   345,   345
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
       3,     4,     5,     6,     5,     3,     3,     4,     5,     4,
       5,     3,     5,     7,     7,     3,     7,     3,     2,     2,
       2,     2,     2,    15,     2,     2,     2,     2,     2,    16,
      11,     6,     8,     8,    10,     1,     2,     2,     1,     3,
       3,     4,     4,     1,     1,     5,    11,    13,     0,     7,
       0,    13,     0,    15,     0,     6,     9,     2,     3,    10,
       1,     2,     5,     7,     2,     2,     3,     2,     3,     2,
       3,     9,     6,     1,     1,     1,     1,     1,     0,     2,
       3,     3,     4,     9,     4,    14,     0,     3,     0,     1,
       0,     2,     0,     2,     0,     2,     6,     7,     6,     5,
       3,     8,     5,     4,     6,    11,    11,    18,    18,    12,
      12,    12,    10,    10,    10,    10,    10,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     3,     6,     1,
       1,     1,     2,     5,     7,    10,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     1,     4,     6,     1,     4,     4,     4,     6,
       4,     4,     3,     2,     2,     5,     5,     3,     5,     6,
       4,     7,     6,     6,     6,     4,     6,     4,     0,     7,
       1,     3,     1,     1,     2,     0,     3,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     1,     2,     3,     3,     5,
       4,     2,     2,     2,     2,     3,     3,     3,     3,    16,
      16,    16,    16,     1,     1,     1,     3,     4,     4,     4,
       6,     6,     8,     8,     4,    14,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     5,     5,     5,
       5,     1,     4,     1,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     4,     8,     4,     4,     4,     4,     8,
       8,     6,     4,     6,     4,     1,     4,     4,     0,     6,
       4,     2,     4,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,   304,   305,   306,   307,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   273,   274,     0,     0,     0,   268,     0,     0,
       0,     0,     0,   359,   360,   361,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   568,     0,   208,     0,     0,     0,     0,     0,   252,
       0,   254,   255,   250,   251,     0,   256,   257,   111,   121,
     567,   455,   450,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,     0,   409,   410,   412,
     413,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   417,   418,   419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   414,   415,   416,     0,     0,     0,     0,     0,     0,
     493,   494,     0,   495,   468,   366,   422,   425,   287,   469,
     450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,     0,
     208,     0,     0,   356,     0,     0,     0,     0,     0,     0,
       0,     0,   475,     0,   474,     0,     0,     0,     0,     0,
     567,     0,     0,   514,     0,     0,     0,     0,   248,   249,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,   555,   535,   536,
       0,     0,     0,     0,     0,   534,     0,     0,     0,     0,
     266,   267,     0,   208,     0,   208,     0,     0,     0,   450,
       0,     0,   208,   362,     0,     0,    76,     0,    63,     0,
       0,    67,    66,    65,    64,    69,    68,    70,    71,     0,
       0,     0,     0,     0,     0,   520,   450,     0,   207,     0,
     206,     0,   174,     0,     0,   520,   521,     0,     0,   563,
       0,   109,   109,     0,   448,     0,     0,     0,     0,     0,
     508,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,     0,     0,   482,
       0,   483,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   369,     0,   368,   476,   370,
       0,   470,     0,   433,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,   434,     0,     0,     0,     0,
       0,     0,   288,     0,   320,   320,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,   208,   208,     0,   459,   458,     0,     0,
       0,     0,   208,   208,     0,     0,     0,     0,   284,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,   230,
     357,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     330,   247,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   269,     0,   235,     0,   236,     0,
       0,   368,     0,   208,     0,     0,     0,     0,   308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    72,    73,     0,     0,   245,
      38,   241,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,   453,     0,     0,   451,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,   485,   486,   487,   488,     0,
       0,     0,     0,     0,     0,   367,   471,   432,     0,   478,
       0,   384,   383,   382,   381,   377,   378,   380,   379,   372,
     371,     0,   373,   477,   374,   375,   376,   451,     0,     0,
     452,   437,     0,   496,     0,     0,     0,     0,     0,     0,
       0,   318,     0,     0,   144,   145,     0,   147,   148,     0,
     150,   151,     0,   153,   154,     0,   353,     0,   354,     0,
     355,     0,     0,     0,     0,   352,     0,   208,     0,     0,
       0,     0,     0,   461,   460,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   333,     0,     0,   231,     0,
       0,   226,     0,     0,     0,   348,   347,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,   237,   239,     0,   373,     0,
     569,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,   367,     0,    63,     0,     0,
       0,     0,    79,     0,    63,    64,     0,     0,   451,     0,
       0,   437,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   565,    28,    26,     0,     0,     0,     0,     0,
     452,   524,    29,     0,     0,   242,   564,    74,   112,    75,
     122,   454,   456,   128,     0,     0,     0,     0,   510,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   408,   395,     0,   397,   398,   399,   400,   401,
     507,   402,   403,   404,     0,     0,     0,   499,   498,   497,
       0,     0,     0,   504,     0,   445,     0,     0,     0,   447,
     126,     0,   480,     0,     0,     0,     0,     0,   423,   506,
     428,     0,   430,   472,     0,   431,     0,     0,     0,     0,
     427,   426,   440,     0,     0,     0,     0,     0,   367,   316,
     321,   319,     0,   329,     0,     0,     0,     0,     0,     0,
       0,     0,   367,   367,   367,     0,     0,     0,     0,   227,
       0,   238,   240,     0,     0,     0,   198,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,   545,     0,   552,   541,   542,
     543,     0,   557,   556,     0,     0,   546,   547,   548,   554,
     561,   560,     0,   136,     0,   537,     0,   539,   532,     0,
     234,     0,     0,   309,     0,     0,     0,   363,     0,   566,
       0,     0,     0,     0,   101,    63,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,    61,     0,    39,    40,
      41,    42,    43,     0,   427,   426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
     523,   522,     0,     0,     0,     0,   133,     0,   129,   130,
       0,     0,     0,     0,     0,   158,   158,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
     385,   473,   438,   436,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,   328,     0,   146,     0,   149,     0,
     152,     0,   155,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,   294,     0,   297,     0,   299,     0,   285,   291,     0,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,   334,     0,   229,   228,   358,     0,     0,    35,    36,
       0,     0,     0,     0,   515,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,   310,     0,   311,   208,     0,     0,   527,   528,
     529,   530,     0,    86,     0,     0,     0,     0,    84,    91,
      93,     0,   518,     0,    99,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    34,   438,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,   525,     0,    32,     0,     0,   113,   118,     0,
       0,   132,   135,   449,     0,    77,    78,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   177,   178,     0,
       0,     0,     0,   162,   190,   179,   183,   184,   180,   181,
     182,   169,     0,     0,   396,   405,   406,   407,   500,     0,
       0,     0,   443,   444,   446,   127,   421,     0,     0,     0,
       0,   442,   424,   429,   191,   439,   501,   185,     0,     0,
     156,     0,     0,   327,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,     0,     0,     0,   208,
     208,     0,     0,   296,   468,     0,     0,   298,   300,     0,
       0,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,     0,   165,   166,     0,
       0,     0,     0,   102,   106,     0,   553,     0,     0,   551,
       0,   562,     0,     0,   137,   138,   559,   538,   540,     0,
     308,   312,   308,     0,   364,    85,    63,     0,     0,     0,
       0,    83,     0,   516,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   466,     0,   439,   243,   244,   210,
     211,   212,   213,     0,     0,     0,     0,     0,   526,     0,
     114,   119,     0,     0,   508,   509,   131,     0,     0,   159,
     163,   164,   170,     0,     0,   189,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   441,     0,
     171,     0,   192,   317,   194,   195,   196,   197,   168,     0,
     187,   193,     0,     0,     0,     0,     0,     0,   465,   464,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   223,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,   331,    37,     0,   513,     0,     0,   263,
     262,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     142,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,    97,   519,     0,     0,    88,     0,     0,     0,    44,
       0,     0,     0,     0,     0,    46,    33,     0,   126,   136,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   502,   503,     0,     0,     0,     0,     0,
       0,   173,     0,   324,   324,     0,   107,   108,   208,     0,
     201,   202,   286,     0,   292,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   204,     0,     0,
       0,     0,   103,   104,   544,   550,   549,     0,   139,     0,
       0,   313,     0,    92,    94,     0,   100,     0,    82,    89,
      90,    49,     0,     0,     0,     0,   467,     0,     0,     0,
       0,     0,   116,     0,   123,     0,   342,   344,   343,   345,
       0,   346,   176,     0,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     463,     0,   302,     0,     0,   280,     0,   215,     0,     0,
       0,     0,     0,     0,     0,   512,   264,     0,   143,     0,
     208,   365,     0,   517,     0,    45,     0,     0,     0,    62,
      47,     0,   115,   120,   126,     0,     0,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,   335,     0,
       0,   336,     0,   199,     0,   293,     0,   276,     0,   208,
       0,     0,     0,     0,     0,     0,   167,   105,   260,   308,
      98,     0,     0,     0,     0,     0,     0,   124,   125,     0,
       0,     0,     0,     0,     0,   188,     0,   339,     0,   340,
     341,   462,     0,     0,   282,   218,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    59,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,   301,   281,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,   220,   221,   222,     0,   216,   315,
      50,     0,    57,     0,   253,     0,   505,     0,     0,     0,
       0,     0,     0,   283,     0,     0,    51,     0,     0,   259,
       0,     0,     0,     0,     0,     0,   217,     0,     0,     0,
       0,   489,   490,   491,   492,     0,     0,    54,    52,     0,
      55,     0,   337,   338,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1005,   109,   110,   987,  1768,  1774,
    1258,  1460,  1914,  2055,  1259,  2020,  2079,  1260,  2057,  1261,
    1262,  1464,   400,   545,   546,  1069,   111,   721,   421,  1778,
    1924,  1779,   422,  1663,  1330,  1287,  1288,  1289,  1427,  1614,
    1615,   853,   856,   859,   862,  1511,  1501,   705,   250,   409,
     410,   114,   115,   116,   117,   118,   119,   120,   121,   251,
    1162,  1948,  2011,   890,  1158,  1159,   252,   964,   253,   125,
    1353,  1122,   851,   904,  1884,   126,   127,   128,   129,   254,
     255,  1090,   256,   726,   257,   841,   725,   424,   577,   290,
    1643,   324,   325,   259,   522,   332,  1246,  1453,   419,   415,
    1213,   947,   420,   131,   379
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1748
static const yytype_int16 yypact[] =
{
   10329,    79,    93, 10478, -1748, -1748,  -121,   113,   -66,  -122,
     -90,    46,    94,   162,   195,   205,   -70,   214,   251,   -42,
       5,    11,   542,   542,   -95,    64,   132,    17,   138,   144,
      19,   180,   190,   219,   228,   231,   261,   288,   298,   357,
     370,   247,   229,   410,   145,   753,   420,  5694,   425,   361,
     450,   -47,   255,   528,   725,   -34,   434,   521,   -78,   446,
     143,   143,   486,   394,    12, -1748, -1748, -1748, -1748, -1748,
     513,   755,   630,   639,    16,    76,   656,   676,   133,   778,
     786,   787,  5007,   797,   588,   610,   619,    18,    43, -1748,
     638,   653, -1748, -1748,   830,   903,   682, -1748,  4862,   699,
    5111,    38,    51, -1748, -1748, -1748,  9658,   698, -1748, -1748,
   -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748,
   -1748, -1748, -1748,   -85, -1748, -1748, -1748, -1748,    61, -1748,
     946,   714,  4776,    73,   726,   960,  9658,  4055,  4055, -1748,
    9658, -1748, -1748, -1748, -1748,  4055, -1748, -1748, -1748, -1748,
     732,   743,   978, -1748, -1748,  3650,    11,  9658,  8213,  9658,
    9658,   767,  9658,  8213,  9658,  9658,   798,  9658,  8213,  9658,
    9658,  9658,  9658,  9658,  9658,  4055,  9658,  9658,  9658,  5923,
     837, -1748,  8213,  5007,  5007,  5007,  4055, -1748, -1748, -1748,
   -1748, -1748,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   683,   542,   542,   542,   542,
     542,   845,   542,   542,   866, -1748, -1748, -1748,   542,    49,
      27,   134,   146,  5923,   996,   629,   890,   542,   542,   899,
     921, -1748, -1748, -1748,  9658,  6152,  9658,  9658,  6381,    24,
   -1748, -1748,   774, -1748,   943, -1748, -1748, -1748, -1748, -1748,
     155,  9658,  8213,   939,   940,  6610,  5007,  5007,  5007,   941,
     944,   947,   948,  6839,  7068,  7297,   887,  4014,  1073,  5923,
     942,    18,   945,   950,   143,   143,   143,  9658,  9658,   -27,
   -1748,   451,   143,  9060,   453,   -38,   955,   956,   957,   961,
     964,   965,   966,  9658,  5007,  5007,  5007,   968,    10,   958,
   -1748,  1168,  1175, -1748,   969,   970,   971,  5007,  5007,   967,
     974,   975, -1748,  9658, -1748,  1195,  1197,  9658,  9658,  9658,
     706,  9658,   979, -1748,  1034,  9658,  9658,  9658, -1748, -1748,
    9658, -1748,   542,   542,   542,   984,   986,   987,   542,   542,
     542,   542,   542,   542,   542, -1748,   542, -1748, -1748, -1748,
     542,   542,   988,   989,   542, -1748,   977,  1215,  1218,   991,
   -1748, -1748,  1222, -1748,  1223, -1748,   542,  9658, 11795,   181,
    4055,  9658, -1748, -1748,  5923,  5923, -1748,   995,  3650,   739,
    1224, -1748, -1748, -1748, -1748, -1748, -1748,  9658,  9658,   158,
    5923,  1226,  -110,   215,   999,  1229,    54,  1001, -1748,  1002,
   10681,  9658, -1748,   544,   -44, -1748,    67,   126,  1995, -1748,
     147,  -168,  -137,  1151, -1748,    11,  1000,  1003,  2302,  8213,
    1320, -1748,    87, 12189, 12210,  9658, 12231,    88, 12252, 12273,
    9658, 12294,   149, 12315, 12336, 12357, 12378, 12399, 12420,  1007,
   12441, 12462, 12483,  1234,  9658,   177,  1238,  1239,  1241,  1016,
    9658,  9658,  9658,  9658,  9658,  9658,  9658,  9658,  9658,  9658,
    9658,  9658,  9658,  9658,  9658,  9658,  8213,  9658,  9658,  9658,
    9658,  9658,  9658,  8213,  8213,  1014,  9658,  9658,  4055,  9658,
    4055,  5923,  4055,  4055,  4055,  9658, -1748,  1186,  9658, -1748,
    1187, -1748,  1189, -1748,  1190,  5923,  5007,  5007,  5007,  5007,
    4055,  4055,  8213,    11,  3650,  1022,  8213,  1022, -1748,  1022,
   12504, -1748,   243, -1748,    66,  9658,  9658,  9658,  9658,  9658,
    9658,  9658,  9658,  9658,  9658,  9658,  9658,  7526,  9658,  9658,
    9658,    11,  9658,  9658,  1251, -1748,   499, 12525,   300,  9658,
    9658,  9658, -1748,  1249,  1253,  1253,  8836,  8836,  8836,  8836,
    9658,  1255,  9658,  1257,  9658,  1258,  8213,  8213, 11819,  1026,
    1260, -1748,  1024, -1748, -1748,  -123, -1748, -1748,  3345,  3931,
     143,   143,    73,    73,  -117,  9060,  9060,  9658,  2588,  -114,
   -1748,  9658,  9658,  9658,  9658,  9658,  9658,  9658,  9658,  9658,
   12546,  1275,  1261,  1280,  9658,  1283,  9658,  9658,  2712, -1748,
   -1748,  8213,  8213,  8213,  1285,  1286,  9658,  9658,  9658, 12567,
   -1748, -1748, 12588, 12609, 12630,  1121,  4075, -1748,  1060,  2990,
   12651, 12672, 11890,  4055,  4055,  4055,  4055,  4055,  4055,  4055,
    4055,  4055,  9658,  4055,  4055,  4055,  4055,     9,  3650,  4055,
    4055,  4055,    11, -1748, -1748,  8213, -1748,  2862, -1748,  3009,
    9658,  1022,  9658, -1748,  9658,  9658,  1063, 12693, 10617,  1066,
     387,  9658,  1293,  1067,  1069,  1070,  1071,  9658, 12714, 11913,
     191,  1064,  1301,  1305, -1748, -1748, -1748,  8213,   185, -1748,
   -1748, -1748,    11,  9658,  9658,  1251,  1096, -1748,   519,    25,
      44,   552,  1099,   -39,   775, -1748,  3538, -1748,    62,  8213,
      11,  9658,  9658,  1327,  1343,  8213,  9658,  1345,  4055,  1347,
   -1748,    11,  1349,  4055,  9658,  1125,  1130, -1748,  9658,  3650,
    1357,  8213,  1191,  8213,  1361,  1362, 12735,  1363,  1198,  1365,
    1367, 12756,  1368,  1201,  1371,  1372,  1373,  1374,  1375,  1377,
   -1748,  1378,  1379,  1380,  9658, 12777,  1154, -1748, -1748, -1748,
    1384, 11867, 11867, 11867, 11867, 11867, 11867, 11867, 11867, 11867,
   11867, 11867,  4247, 11867, 11867, 11867, 11867,   592,   712, 11867,
   11867, 11867,  4485,  4661,  5174,  1320,  1159,  1158,   139,  8213,
    5403,  5632,   712,  5861,   712,  1155,  1157,  1176,   211, 13407,
    1163,  3785,  1182,  1184,  1185, -1748, -1748, -1748, -1748,  1181,
    -179,   712,  -149,  1162,   442,  1415, -1748, -1748,   712,  3019,
    3159,   680,  1252,   702,   702,   555,   555,   555,   555,   658,
     658,  8213,  1022, -1748,  1022,  1022,  1022,  1205, 12798, 11936,
     -55, -1748,  8213, -1748,  1416,  1210, 12819, 12840, 12861,  9658,
    5923,  1420,  1419,  1194, 13407,  1207,  1217, 13407,  1212,  1221,
   13407,  1219,  1225, 13407,  1240, 12882, -1748, 12903, -1748, 12924,
   -1748,   559,   591,  8213,  1213, -1748,  3715, -1748,  9686,  9725,
     143,  9658,  9658, -1748, -1748,  1220,  1227,  9060,  1433,  1331,
     374,   143,  9849, 12945, 11045, 12966, 12987, 13008, 13029, 13050,
   13071, 13092,  1454,  9658,  1456, -1748,  9658, 13113, -1748, 11959,
   11982, -1748,   602,   649,   650, -1748, -1748, 12005, 12028,  6090,
   -1748,  1472,  1474,  1477,  1248,  9658,  9887,  9658,  9658, -1748,
   -1748,    53,   -65,   311,   -65,  1254,  1256,  1250,   712,   712,
    1267,  6319,   712,   712,   712,   712,  9658,   712,  1480, -1748,
    1268,  1278,   336,  1277,   651, -1748, -1748, 11867,  1022,  9951,
   -1748,  1505,  1366,  9135,  1281,  1284,  1508,  5923, 11070, -1748,
    9658,  9658,  9658,  9658,   842,   196,     4,  3650,  9658,  1510,
    1514,    20, -1748,   671,  1475,  1476,  5923,    22,  1287, 13134,
   12051,  1288,  9658,  8213,  8213,  8213,  8213,  9658,  1289,  1294,
    1296,  1297, -1748, -1748,  1311,  4055,   234,  1310, 13155, 12074,
   -1748, -1748, -1748,   244,  6548, -1748, -1748, -1748,    35, -1748,
   -1748, 13407, -1748,  1526, 11867,   712,   143,   938,  1320, -1748,
    5923,  5923,  1524,  5923,   992,  5923,  5923,  1541,  5923,  1451,
    5923,  5923,  5923,  5923,  5923,  5923,  5923,  5923,  5923,   923,
    1544,  8213, -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748,
   -1748, -1748, -1748, -1748,  9658, -1748, -1748, -1748, -1748, -1748,
   -1748, -1748, -1748, -1748,  9658,  9658,  9658, -1748, -1748, -1748,
     672,  9658,  9658, -1748,  9658, -1748,  5923,  4055,  4055, -1748,
    1312,  9658, -1748,  9658,  9658,  9658,  9658,  9658, -1748, -1748,
   -1748,  1327, -1748, -1748,  5923, -1748,  9658,  9658,   718,  1327,
     -55,     7, -1748,   723,  5923,  8213,  1548,  1549,  1550,   801,
   -1748, -1748,  1554, -1748,   260,  9658,   260,  9658,   260,  9658,
     260,  9658,  1555,  1556,  1557,  1559,  1564,   729,  1568, -1748,
   10047, -1748, -1748,   -91,  6777,  7006, -1748, -1748, 11095,   -84,
    1453,  1569,  9359,  1339,  1571,  1344,    29,    40,   403, -1748,
     -12, -1748,   374,  1572,  1574,  1577,  1578,  1579,  1581,  1582,
    1583,  1584,  5923, 13407, -1748,  1120,  1358,  1586,  1588,  1589,
    1482,  1590,  1593,  1594,  9658,  5923,  5923,  5923,  1597,  7235,
   -1748,  3306,   642,  1598,  1599, -1748,  8213, -1748, -1748, -1748,
   -1748,  4055, -1748, -1748,  9658,  4055, -1748, -1748, -1748, -1748,
   13407, -1748,  1370,  1369,  4055, -1748,  4055, -1748, -1748,  1381,
   -1748,  1382,  9434, -1748,  1188,  1383,  5923, -1748,  1386, -1748,
   11120, 11145, 11170, 11195, -1748, -1748,  9658,  1600,   174,  9658,
    1604,  1613,  1216, -1748,  1617,    18,  1619,  1393,   712,   542,
     542,  1626, -1748,  1404,  1406,  1425, -1748,  1633, -1748, -1748,
   -1748, -1748, -1748,  1327,   448,   888, 12097,   736,   741,   746,
     748, 13176,  9658,  9658,  9658,  9658, -1748,  1635,    75,  1327,
   -1748,  1424,  1656,  9658,  8437,   712,  4309,  1430,  1426, -1748,
    1661,  1662,    84,  1434,  1436,  1484,  1484,  5923,  1666,  1439,
    1440,  1670,  1673,  5923,  1506,  1445,  1676,  1677,  1678,  1679,
    1680,  1682,  1683,  1684,  1686, -1748,  1689,   749, 11867, 11867,
   11867, 11867,   712,  7464,  7693,  7922,  1463,   712,   712,  1526,
     712,  8151,  8464,  8778,  8889, 13197, 11867,  1464,  1691, 13407,
   13407, -1748, -1748, -1748,  1694, -1748,   712,  1693,   760,  5923,
    5923,  5923,  1696,  1695, -1748,  5923, 13407,  5923, 13407,  5923,
   13407,  5923, 13407,  5923,  5923,  5923,  1470,  1471,  1700,   384,
   -1748,  9658,  9658,  9658,  1473,  1479,  1481,  1478, -1748,  1279,
    5923, -1748,  9658, -1748,  1709, -1748,  1711, -1748, -1748,  9060,
     421,  5236, -1748,  1483,  1485,  1486,  1487,  1488,  1491,  7755,
    1713, -1748,  8213, -1748, -1748, -1748,  1492,  9658, -1748, -1748,
   12120,  1722,  1723,  1560, -1748,  9658,  9658,  9658, -1748,  1726,
     565,   560,  1493,  1056,  1494,  9658,    30,   712,  1503,   712,
    3650, -1748, -1748,  1704, -1748, -1748,  1496,  1731, -1748, -1748,
   -1748, -1748,  1784, -1748,   313,  1502,  1733,  1804, -1748, -1748,
   -1748,    18, -1748,   763, -1748,  9658,   260,  1699,  4055, -1748,
    1512,  9658,  9658,  5923,  1519, -1748,  1520,  1737,  1750,  1751,
    1758,  1763,  1766,  1768,  1415, 13218, 13239, 13260, 13281, -1748,
   -1748,  4055, -1748,  1771, -1748,  8964,  4547, 13407, -1748,  1769,
    6381, -1748, -1748, -1748,  1526, -1748, -1748, -1748,  9658,  9658,
     143,  1772,  1773,  1774, -1748,  9658,  9658, -1748, -1748,  1776,
    1697,  1777,  9658, -1748, -1748, -1748, -1748, -1748, -1748, -1748,
   -1748, -1748,  1780,  1552, -1748, -1748, -1748, -1748, -1748,  9658,
    9658,  9658, -1748, -1748, -1748,  1426, -1748,  9658,  9658,  9658,
    9658, -1748, -1748, -1748, -1748,   -55, -1748, -1748,  1553,  1783,
    1506,  1786,  9658, -1748,  1787,  1788,  1789,  1790,  1791,  1145,
    1792,  8213,  8213,  9658, -1748,  8836, 11220, 13302,  2146,    73,
      73,  9658,  9658, -1748,   120,  1561, 13323, -1748, -1748, 11245,
     220, -1748,  1794,  1797,  5923,   143,   143,   143,   143,   143,
    5465,  1798, -1748,   765,  9658,  1933,  1799, -1748, -1748,  5923,
    3698,   478, 13344, -1748, -1748,  8522, -1748,  4055,  9658, -1748,
    4055, 13407,  8751,  3650,  1566, -1748, -1748, -1748, -1748,  1575,
   10617, -1748, 10617,  5923, -1748, -1748,  3650,  9658,  1802,  1805,
      20, -1748,  1806, -1748,    18, 12143,  5923,  1808,   -65,   -65,
    9658,  9008,  9087,   768, -1748,  9658,   605, -1748, -1748, -1748,
   -1748, -1748, -1748,  1550,  1555,  1556,  1557,  1810, -1748,  9658,
   -1748, -1748,  1576,   770,  1755,  1811, -1748, 11270, 11295,   398,
   -1748, -1748, -1748, 11320, 11345, -1748,  1585, -1748, 11370,  1814,
    5923, 11867, 11867,  9188,  9263,  9307,  9386,  9531, -1748,  9658,
   -1748,  1815, -1748, 13407, -1748, -1748, -1748, -1748, -1748,  1587,
   -1748, -1748,   771,   810, 11843,  2036,  1818,  1591, -1748, -1748,
    9658,  1592,  1595, 11395, 12166,  1819,  5923,  1820,  1603,  9658,
   -1748, -1748,   811,   232,   235,   256,   295,   338,  7984,   345,
   -1748,  1823, 11420, -1748, -1748,  1660, -1748,  9658,  9658, -1748,
   -1748,  8213,  2073,  1826,  1607, 11867,   712,  4055, 13407, -1748,
   -1748,    30,  3650,  1605,  1608,  1609,  1834,  2092, -1748,  1836,
    1840, -1748, -1748,  1616,  1848, -1748,  1849,  1850,   299, 13407,
    9658,  9658,  1622,  5923,   813, 13407, -1748,  9690,  1312,  1369,
    5923, -1748,  9658,  3650,    11,  1852,  1853,  1854,  1855,  9658,
    1856,  1858,   833, -1748, -1748,  9658,  9658,  9658,  9658,  9658,
   11445, -1748,  5923,   315,   383,  8213, -1748, -1748,    73,  3749,
   -1748, -1748, -1748,  1859, -1748,  1631,  5923, -1748, 11470,  1862,
    8213,   143,   143,   143,   143,   143, -1748, -1748,  9658, 11495,
   11520,   834, -1748, -1748, -1748, -1748, -1748,   835, -1748,  1637,
    1636, -1748,  1864, -1748, -1748,    18, -1748,  1701, -1748, -1748,
   -1748, -1748,  9658,  9886, 10015,  5923, -1748,  1866,  9658,  9658,
    1639,  1640, -1748,  2546, -1748,  1642, -1748, -1748, -1748, -1748,
   11545, -1748, -1748,  1644, 10132, 10166, 10595, 10639, 10668, -1748,
     846,  1646,   143,  5923,  1871,  1647,   143,  1877,   851,  1648,
   -1748,  9658, -1748,  1879,  1759, 10101,  1652, -1748,   853,   362,
     365,   377,   382,   440,  2351, -1748, -1748,  1882, -1748,  1883,
   -1748, -1748,  1887, -1748,  1659, 13407,  9658,  9658,   860, -1748,
   13407, 10697, -1748, -1748,  1312,  3650,  1663, -1748,  9658,  9658,
    9658,  9658,  9658,  9658,  1890,   143,    86, -1748, -1748,   143,
      95, -1748,  1891, -1748, 11570, -1748,  9658, -1748,   374, -1748,
    1893,  8213,  8213,  8213,  8213,  7984, -1748, -1748, -1748, 10617,
   -1748,  9658, 13365, 10726,    59,  9658,  1664, -1748, -1748, 10755,
   10784, 10813, 10842, 10871, 10900, -1748,   445, -1748,   447, -1748,
   -1748, -1748,  2522,   501, 10197, -1748,   862,   863,   868,   869,
     483,   870,  1665,   878, -1748,  9658, -1748,  5923, 11595, -1748,
    9658,  9658,  9658,  9658,  9658,  9658,   143,   143, -1748, -1748,
   -1748,   374,  1898,  1901,  1903,  1904,  8213,  1905,  1907,  1908,
    1702, 13386,   879,  1924, 11620, 11867, 10929, 10958, 10987, 11016,
     489,   495,   644, -1748, -1748, -1748, -1748,   884, -1748, -1748,
   -1748,  4055, -1748,  1703, -1748,  1926, -1748,  9658,  9658,  9658,
    9658,  9658,  9658, -1748,  1929,   891, -1748,  1705,  5923, -1748,
   11645, 11670, 11695, 11720, 11745, 11770, -1748,  1930,  4055,  4055,
     892, -1748, -1748, -1748, -1748,  1935,  1936, -1748, -1748,   914,
   -1748,  1937, -1748, -1748,  1938,  4055, -1748, -1748, -1748
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1748, -1748, -1748, -1748,   667, -1748, -1748, -1748, -1748,   -15,
   -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748,
   -1748, -1748,  -663,  -131,  3068,  2846, -1748,  1525, -1748, -1748,
   -1748, -1748, -1748, -1748, -1747, -1748,   624,   460,   176, -1748,
     206, -1748, -1748, -1748, -1748,   406,   662,  1957,    -1,  -575,
    -219, -1748, -1748, -1748, -1748, -1748, -1748, -1748, -1748,  1959,
   -1748, -1748, -1748, -1748, -1159, -1153,  1960, -1610,  1961, -1748,
   -1748, -1748,  1411, -1748,   178, -1748, -1748, -1748, -1748,  1944,
   -1748, -1748,  1980, -1748,    -2,  -686, -1748, -1748,    26, -1748,
   -1533,   279,  -147,  2466,  -118,  -275,   354, -1748,   102,   -59,
   -1748, -1748,  -490, -1748,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -527
static const yytype_int16 yytable[] =
{
     132,   401,   113,  1390,   798,  1388,   572,   885,   886,   991,
    1753,  1235,  1754,   150,   605,   150,   295,   978,   152,   151,
     308,   161,   330,   166,   150,   986,  1252,  1011,   150,   161,
     136,  1860,   499,   523,  1612,  1383,   456,   457,   458,   367,
     432,   371,  1284,   372,   260,   437,  1385,   334,   166,   264,
     442,  1722,   139,   685,   496,   686,   374,   264,   150,   276,
    1193,  1097,   277,   692,   455,  1996,   719,   383,  1003,   280,
     265,   311,   720,   405,   588,   817,   710,   407,   998,   260,
     312,  1480,   313,  1100,   333,     4,   289,   291,  1101,   294,
    1497,   608,  1977,     5,   281,   368,   426,   722,   580,   581,
     141,  1979,   296,   720,   580,   581,   297,   580,   581,   137,
     282,   283,   298,   299,   133,   300,   301,   880,   134,   553,
     554,   555,   685,   887,   686,   687,   891,   135,   525,   406,
     580,   581,   408,   302,   416,   416,   157,   580,   581,   501,
     158,   138,   416,   932,   548,   934,   381,  1792,   541,  1371,
     382,   503,  1375,   427,   657,   260,   659,   601,   602,   603,
     260,   145,   680,   668,   541,   260,   314,   685,   142,   686,
     614,   615,   416,   395,   396,   718,   260,  1966,  1444,   260,
     260,   260,   260,   416,  1253,  1254,  1255,  1256,   708,  1384,
     541,   148,   984,   591,   580,   581,   709,   592,   977,   309,
    1386,   143,   500,  1235,    59,    60,    61,    62,   582,   580,
     581,   144,   391,   392,   393,   394,   107,  1613,   107,    73,
     146,   689,    76,   107,   497,   107,   317,   107,  1389,   318,
     260,   107,   395,   396,   404,   395,   396,  1388,   149,   414,
     417,  1238,   260,   606,  1344,   260,   524,   946,   162,   134,
     167,   310,   163,   331,   168,  1245,   162,   147,  1257,   260,
     994,   107,   260,   260,   260,   260,   153,  1235,   154,  1880,
     260,   260,   260,   373,   335,   167,   260,   449,   333,   995,
    1004,   140,   395,   396,   498,   693,   375,   694,   459,  -521,
    1194,   695,   384,  1004,  1997,   159,   385,   153,   711,   154,
     712,   260,   260,   260,   713,   580,   581,   580,   581,   502,
     575,   576,  1236,  1239,   260,   260,   580,   581,   584,   589,
    1626,   504,  1918,   732,   738,   180,   258,   733,   733,   672,
     681,   682,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,  1445,  1446,   266,  1992,
     540,   267,   876,   268,   878,   879,  1715,   179,   714,   805,
     806,   807,   808,   160,   285,   286,   715,   395,   396,   164,
     542,   892,   543,  1079,   287,   165,   544,   416,   288,   717,
     182,   260,   260,   395,   396,   743,   542,   718,   543,   733,
    1564,  1565,   544,   391,   392,   393,   985,   260,   814,   391,
     392,   393,   394,   696,   391,   392,   393,   394,   926,   395,
     396,   169,   664,   756,   665,  1337,   181,   733,   544,   395,
     396,   170,   727,  1342,   395,   396,   260,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,   580,   581,  1089,   959,   540,  1881,  1882,   871,   872,
     171,   718,  1883,   580,   581,   813,   580,   581,   453,   172,
    1719,  1355,   173,  1357,  2022,  1359,  1278,  1361,   391,   392,
     393,   394,  1820,   260,   733,  1821,  1282,   580,   581,   816,
     260,   788,   666,   733,   733,   416,  1738,   416,   260,   416,
     416,   416,   174,   912,   913,   914,  1822,   855,   858,   861,
     864,  1151,   260,   260,   260,   260,   260,   416,   416,   260,
     152,   812,   258,   260,  1885,  1886,   580,   581,  1152,   175,
    1883,   391,   392,   393,   394,  2070,  1153,  1154,  1155,   176,
    1151,  1851,  1156,  1157,   260,  1823,   845,   954,   837,  1852,
     733,   395,   396,   685,   552,   686,   263,  1152,  1151,   979,
     707,  1196,   561,   563,   565,  1153,  1154,  1155,   570,   580,
     581,  1156,  1157,   260,   260,  1152,   580,   581,   685,   983,
     686,  1604,  1605,  1153,  1154,  1155,  1216,  1466,  1824,  1156,
    1157,   408,   408,   580,   581,  1825,   580,   581,   177,   949,
     792,  1006,   794,  1482,   796,   797,   262,  1013,   580,   581,
     525,   178,  1951,   580,   581,  1952,   883,   884,   260,   260,
     260,   576,   809,   810,   279,   285,   286,  1953,   269,   580,
     581,   270,  1954,   966,   271,   287,   272,   967,  1151,   293,
     416,   416,   416,   416,   416,   416,   416,   416,   416,  1387,
     416,   416,   416,   416,   948,  1152,   416,   416,   416,   953,
    1417,   186,   260,  1153,  1154,  1155,   261,  1581,  1140,  1156,
    1157,   580,   581,   669,   670,   278,   580,   581,   580,   581,
    1025,  1080,   580,   581,   580,   581,   395,   396,  1103,   683,
    1955,   284,   733,  -523,   260,  2006,   583,  2007,   590,   988,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,   580,   581,   260,  1007,   540,  1112,
     580,   581,   260,  1108,  1739,   416,   580,   581,  1018,   506,
     416,   292,   507,  2016,  1113,   508,   306,   509,   260,  2051,
     260,   685,   307,   686,   842,  2052,   933,  2009,   935,   936,
     937,   938,   939,   940,   303,   942,   943,   944,   945,   315,
     157,   950,   951,   952,   993,  1137,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
     795,  1151,   316,   153,   540,   154,   535,   536,   662,   538,
     539,  1627,   319,   170,   552,   540,   260,   996,  1152,  1983,
     320,   321,   685,  1636,   686,  1135,  1153,  1154,  1155,   733,
     733,   326,  1156,  1157,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   731,   538,   539,   273,   327,
    1016,   274,   540,   275,   685,  1020,   686,  1136,   260,   673,
    1388,   733,   674,   395,   396,   675,   338,   676,  1179,   260,
    -526,   328,   733,   183,  1237,  1240,   184,   260,  1234,   185,
     329,   304,  2032,   305,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,   999,   336,
     260,  1000,   540,  1001,  1418,  1267,  1268,  1269,  1270,  1388,
    2053,   662,   538,   539,   337,  1180,  1181,  1219,   540,   733,
     733,   733,   150,   341,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,  1143,  1248,  1322,   339,
     540,   733,   733,  1149,   483,   340,   484,  1160,  1241,   531,
     532,   533,   534,   535,   536,   662,   538,   539,  1352,  1315,
     369,   380,   540,  1317,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   625,   685,   134,   686,   351,   352,   353,
     354,   525,   386,   387,  1341,   355,   356,   357,   733,  1346,
     358,   411,   359,   733,   260,  1368,   412,  1638,  1639,   733,
    1452,   134,  1470,   360,   423,   361,   733,  1471,  1247,  1343,
    1345,   733,  1472,   260,  1473,  1523,   733,   425,   733,   733,
     260,   260,   260,   260,  1711,  1712,  1548,  1348,   435,  1633,
     733,  1731,   416,  1634,  1772,   733,  1781,  1803,  1773,   382,
    1782,   733,   389,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,   260,   260,   440,
     260,   540,   260,   260,  1293,   260,  1294,   260,   260,   260,
     260,   260,   260,   260,   260,   260,  1804,  1819,   260,  1857,
     733,  1773,  1292,  1858,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,   454,  1873,
    1907,  1908,   540,  1773,   733,   718,   491,   569,  1421,   362,
     363,   364,  1934,   260,   416,   416,  1773,  1942,  1299,  1950,
    1300,   733,   365,   733,   366,   107,  1964,   494,  2012,  2013,
    1773,   260,   733,   733,  2014,  2015,  2017,  1277,   733,   733,
     733,   260,   260,   505,  2019,  2043,   395,   396,  1858,  1773,
    2054,   510,   566,  -522,   733,  1467,  1401,  2067,  2081,  1120,
     513,  2068,  1773,  1343,  1345,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,  1699,
    2084,  1700,   514,   540,  2085,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   260,
     549,   550,   556,   540,   609,   557,  1632,   571,   558,   559,
     573,   610,   260,   260,   260,   574,   593,   594,   595,  1327,
    1328,   607,   596,   260,  1434,   597,   598,   599,   416,   604,
     616,   620,   416,   621,   611,   612,   613,   617,   618,   628,
     652,   416,  1620,   416,   627,   636,  1622,   637,   638,   649,
     650,   653,  1450,   260,   654,  1488,   655,  1492,   656,   658,
     671,   677,   684,  1889,   690,   691,   133,   724,   697,   750,
     728,   754,   333,   729,   757,   758,  1228,   759,   760,   789,
     800,   802,   540,   803,   804,   840,   849,  1837,   874,   877,
     850,   866,   416,   868,   870,  1251,   875,   905,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,   903,   260,  1593,  1573,   540,   906,   685,   908,
     686,   915,   916,   924,   260,   927,  1608,   960,   965,   969,
     260,   980,   970,  1422,   971,   972,   973,  1424,   981,  1295,
    1296,   982,  1298,  1628,  1301,  1302,  1428,  1304,  1429,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,   525,   992,
     997,  1010,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,   260,   260,   260,  1012,
     540,  1015,   260,  1017,   260,  1019,   260,  1022,   260,  1762,
     260,   260,   260,  1023,  1026,  1326,  1027,  1468,  1030,  1031,
    1033,  1619,  1035,  1034,  1036,  1038,  1039,   260,  1040,  1041,
    1042,  1043,  1044,  1338,  1045,  1046,  1047,  1048,   260,  1051,
    1052,  1077,  1078,  1347,  1102,  1086,   260,  1087,  1091,   260,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,  1688,  1580,  1088,  1093,   540,  1094,
    1095,  1096,  1104,  1114,  1121,  1123,  1124,  1661,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,  1109,  1702,  1703,  1115,   540,  1125,   333,  1126,
    1138,  1400,  1127,  1128,   416,   416,  1146,  1130,  1150,  1129,
     260,  1172,  1174,  1147,  1411,  1412,  1413,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,   416,  1185,
    1131,  1186,   540,   260,  1187,  1188,  1199,   260,  1200,  1212,
    1201,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,  1436,  1706,  1204,  1214,   540,
    1215,  1218,  1221,  1222,  1227,  1688,  1243,  1225,  1244,  1226,
    1272,  1249,  1250,  -524,  1263,  1273,  1669,  1274,  1275,  1276,
    1286,  1297,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   731,   538,   539,  1743,  1279,  1303,  1305,
     540,  1316,  1329,  1749,  1750,  1349,  1350,  1351,   260,   260,
    1354,  1376,  1363,  1364,  1365,  1491,  1366,  1756,   408,   408,
    1912,  1367,  1369,  1377,  1380,  1382,  1503,  1381,  1406,  1391,
    1392,   260,  1509,  1657,  1393,  1394,  1395,   260,  1396,  1397,
    1398,  1399,  1403,  1402,  1404,  1405,   260,  1407,  1895,  1408,
    1409,  1414,  1419,  1420,   416,  1500,  1443,   416,  1425,  1426,
    1448,  1723,  1724,  1725,  1726,  1727,  1729,  1431,  1435,  1449,
     260,  1430,  1437,  1831,  1451,  1454,  1455,  1247,  1549,  1550,
    1551,   333,  1459,   260,  1554,  1461,  1555,  1462,  1556,  1465,
    1557,  1479,  1558,  1559,  1560,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,  1575,
    1463,  1483,  1484,   540,  1493,   920,  1494,  1495,  1496,  1498,
    1583,  1499,  1504,   881,  1505,  1506,  1507,   260,  1591,  1508,
    1512,  1510,  1513,  1514,  1515,  1516,  1517,  1888,  1518,  1519,
    1520,  1959,  1521,  1839,  1522,  1532,  1543,  1544,  1545,  1547,
    1552,  1553,  1898,   150,   341,  1561,  1562,  1563,  1569,  1744,
    1621,  1572,  1746,   260,  1570,  1577,  1571,  1578,  1584,  1592,
    1585,  1586,  1587,  1588,  1864,   260,  1589,  1594,  1597,  1598,
    1984,  1599,  1603,  1607,  1610,  1617,  1623,  1624,   260,  1629,
    1630,  1646,  1644,  1640,   416,   342,   343,   344,   345,   346,
     347,   348,   349,   350,  1645,  -525,  1647,  1648,   351,   352,
     353,   354,  1783,   525,  1649,  1660,   355,   356,   357,  1650,
     260,   358,  1651,   359,  1652,  1658,  1662,   260,  1670,  1671,
    1672,  1865,  1675,  1677,   360,  1679,   361,  1680,  1689,  1690,
    1625,  1676,  1692,  1694,  1695,  1696,  1697,  1698,  1701,   260,
    1720,  1716,   260,  1721,  1730,  1734,  1751,   408,  1758,  1759,
    1631,  1780,  1761,   260,  1765,  1752,  1776,   260,  1784,  1791,
    1789,  1801,  1802,   389,  1807,  1814,  1808,  1816,  1810,  1826,
    1828,  1811,  1833,  1986,  1987,  1988,  1989,  1991,  1817,  1834,
    1843,  1840,   333,  1845,  1841,  1842,  1846,  1899,  1900,  1901,
    1902,  1903,   260,  1847,  1848,  1849,  1850,  1855,  1866,  1867,
    1868,  1869,  1871,  1644,  1872,  1892,  1967,  1893,  1897,  1909,
    1911,  1910,  1919,  1926,  1913,  1922,  1923,  1938,  1735,  1928,
     260,  1935,  1939,  1941,  1943,  1945,  1946,  1949,  1957,  1958,
     362,   363,   364,  1960,  1961,  1968,  1975,  1980,  2037,  1985,
    1999,  2018,  1755,   365,  2033,   366,   107,  2034,  1936,  2035,
    2036,  2038,  1940,  2039,  2040,  1764,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
    2044,   685,  2059,   686,   540,  2066,  2077,  2041,  2058,  1733,
    2069,  2082,  2083,  2086,  2087,  1481,  1993,   723,   260,   260,
     260,   260,   260,  1535,  1666,  1861,  1691,  1838,  1502,  1644,
     112,  1976,   122,   123,   124,  1978,   852,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   731,   538,
     539,  1990,  1887,   130,  1760,   540,     0,     0,     0,     0,
       0,     0,     0,     0,   260,  1815,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,   260,   540,     0,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,  2030,  2031,   540,     0,     0,     0,   416,     0,
       0,     0,  1806,     0,     0,     0,     0,     0,     0,     0,
     378,     0,  1856,     0,     0,   260,     0,     0,     0,  1862,
       0,     0,     0,     0,     0,   416,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   403,     0,     0,  1832,
     413,  1644,   416,     0,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1894,     0,     0,  1844,     0,
       0,   428,   430,   433,   434,     0,   436,   430,   438,   439,
       0,   441,   430,   443,   444,   445,   446,   447,   448,     0,
     450,   451,   452,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,  1644,     0,     0,     0,     0,     0,
       0,     0,     0,  2056,     0,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,  1937,   540,     0,     0,     0,     0,     0,     0,
    2078,  2080,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2088,   515,   517,
     519,   520,   430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,   430,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,   568,     0,     0,     0,   540,     0,     0,     0,     0,
       0,   578,   579,     0,     0,   716,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,   619,     0,     0,
       0,   622,   623,   624,     0,   626,  1644,     0,     0,   629,
     630,   631,     0,     0,   632,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,   661,   540,     0,     0,   667,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1644,     0,     0,
       0,   678,   679,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   706,     0,  1956,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,   517,     0,     0,   540,     0,     0,   736,
       0,     0,  1709,     0,   741,     0,  1710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   779,   780,   781,   782,   783,   784,   785,   785,     0,
     790,   791,     0,   793,     0,     0,     0,     0,     0,   799,
       0,     0,   801,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   785,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   832,   834,   835,   836,     0,   838,   839,     0,     0,
       0,     0,     0,   846,   847,   848,     0,     0,     0,     0,
     854,   857,   860,   863,   865,     0,   867,     0,   869,     0,
     430,   430,     0,     0,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,  2008,   515,
     661,   888,   540,     0,   730,   893,   894,   895,   896,   897,
     898,   899,   900,   901,     0,     0,     0,     0,   907,     0,
     909,   910,     0,  1925,     0,   430,   430,   430,     0,     0,
     917,   918,   919,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,   941,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   430,
       0,     7,     8,     0,   957,     0,   958,     0,   838,   839,
       0,     0,     0,     0,     0,   968,     0,     0,     0,     0,
       0,   974,     0,     0,   431,     0,     0,     0,     0,   431,
       0,   430,     0,     0,   431,     0,     0,   989,   990,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   431,     0,
       0,     0,     0,   430,     0,  1008,  1009,     0,     0,   430,
    1014,     0,     0,     0,     0,     0,     0,     0,  1021,     0,
       0,     0,  1024,     0,     0,   832,     0,  1028,   698,    25,
      26,   699,    28,    29,   700,    31,   701,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,  1049,    42,
       0,     0,     0,     0,     0,   702,    48,     0,     0,    50,
     703,   518,    53,   704,   431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,   431,     0,
       0,    70,     0,   430,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,     0,    84,    85,    86,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,   430,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1119,     0,     0,     0,     0,     0,     0,
       0,     0,   698,    25,    26,   699,    28,    29,   700,    31,
     701,    33,    34,    35,    36,     0,     0,   430,    38,    39,
      40,     0,     0,    42,   889,  1144,  1145,     0,     0,   702,
      48,  1148,     0,    50,   703,     0,    53,   704,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1173,     0,     0,
    1175,     0,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1189,
       0,  1191,  1192,     0,     0,     7,     8,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
    1210,     0,     0,     0,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1224,     0,     0,
       0,     0,     0,     0,  1230,  1231,  1232,  1233,     0,     0,
       0,     0,  1242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1266,   430,   430,   430,
     430,  1271,   778,     0,     0,     0,     0,     0,   911,   786,
     787,     0,   698,    25,    26,   699,    28,    29,   700,    31,
     701,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,   811,   702,
      48,     0,   431,    50,   703,     0,    53,   704,     0,     0,
       0,     0,     0,     0,     0,   430,     0,     0,   928,     0,
       0,     0,     0,   833,     0,    70,     0,     0,  1318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1319,  1320,
    1321,     0,     7,     8,     0,  1323,  1324,  1106,  1325,    84,
      85,    86,   431,   431,     0,  1331,     0,  1332,  1333,  1334,
    1335,  1336,     0,     0,     0,     0,     0,     0,     0,     0,
    1339,  1340,     0,     0,     0,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1356,
       0,  1358,     0,  1360,     0,  1362,     0,   431,   431,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,     0,     0,     0,     0,  1379,     0,   955,   698,
      25,    26,   699,    28,    29,   700,    31,   701,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,   431,     0,     0,     0,     0,   702,    48,  1410,     0,
      50,   703,     0,    53,   704,     0,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,  1423,     0,
       0,     0,    70,   431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1433,  1107,     0,     0,
       0,     0,     0,     0,     0,   431,    84,    85,    86,     0,
    1442,   431,     0,  1447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   833,     0,  1029,
     402,     0,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,  1475,  1476,  1477,  1478,
     540,     0,     0,     0,     0,     0,     0,  1485,  1487,     0,
       0,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,   956,     0,     0,   688,   540,
       0,     0,     0,     0,     0,   431,     0,     0,     0,     0,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   485,   486,   487,   488,   489,   490,     0,
     492,   493,     0,     0,     0,     0,   495,   431,     0,     0,
       0,     0,     0,     0,     0,   511,   512,     0,   431,     0,
       0,     0,     0,     0,  1416,  1566,  1567,  1568,     0,     0,
       0,     0,     0,     0,  1574,     0,  1576,     0,     0,     0,
       0,     0,     0,  1579,     0,     0,     0,     0,     0,   431,
       0,     0,     0,     0,     0,     0,   430,     0,     0,     0,
       0,  1595,     0,     0,     0,     0,     0,     0,     0,  1600,
    1601,  1602,     0,     0,     0,     0,     0,     0,     0,  1611,
       0,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,   843,     0,     0,     0,     0,     0,     0,  1635,
       0,     0,     0,     0,     0,  1641,  1642,     0,     0,     0,
     633,   634,   635,     0,     0,     0,   639,   640,   641,   642,
     643,   644,   645,     0,   646,     0,     0,     0,   647,   648,
       0,     0,   651,     0,  1664,     0,     0,     0,     0,     0,
       0,     0,  1667,  1668,   660,     0,     0,     0,     0,  1673,
    1674,     0,     0,     0,     0,     0,  1678,     0,     0,   431,
     431,   431,   431,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1681,  1682,  1683,     0,     0,     0,     0,
       0,  1684,  1685,  1686,  1687,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1693,     0,     0,     0,
       0,     0,     0,     0,     0,   430,   430,  1704,     0,  1705,
       0,     0,     0,     0,     0,  1713,  1714,   431,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,   430,     0,   540,     0,  1732,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1742,
       0,     0,  1745,     0,     0,     0,  1748,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,  1757,     0,     0,     0,   540,     0,     0,     0,     0,
       0,   431,     0,     0,  1769,   881,     0,     0,     0,  1775,
       0,     0,   818,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1777,     0,     0,     0,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,     0,  1065,
    1066,  1067,  1068,     0,  1070,  1071,  1072,  1073,     0,     0,
       0,     0,     0,  1800,     0,     0,     0,     0,  1083,     0,
    1085,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1809,   341,  1098,  1099,     0,     0,
       0,     0,   431,  1818,  1105,     0,     0,     0,     0,     0,
       0,     0,   517,     0,     0,     0,     0,     0,     0,     0,
       0,  1829,  1830,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
     352,   353,   354,     0,  1853,  1854,     0,   355,   356,   357,
       0,     0,   358,     0,   359,     0,  1863,     0,     7,     8,
       0,     0,     0,  1870,     0,   360,     0,   361,     0,  1874,
    1875,  1876,  1877,  1878,     0,     0,     0,     0,     0,   430,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,   430,     0,     0,     0,   540,     0,
       0,     0,  1904,     0,  1002,     0,     0,     0,  1195,  1197,
    1198,     0,     0,     0,  1202,  1203,     0,     0,  1206,  1207,
    1208,  1209,     0,  1211,     0,     0,  1915,     0,  1217,     0,
       0,     0,  1920,  1921,     0,   698,    25,    26,   699,    28,
      29,   700,    31,   701,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   702,    48,     0,  1944,    50,   703,     0,    53,
     704,   362,   363,   364,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,   366,     0,    70,     0,
    1962,  1963,     0,     0,     0,     0,     0,     0,   431,     0,
    1290,  1291,  1969,  1970,  1971,  1972,  1973,  1974,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
    1982,     0,     0,     0,     0,   430,   430,   430,   430,   430,
       0,     0,     0,     0,     0,  1775,     0,     0,     0,  1998,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,  1736,     0,     0,     0,  1737,  2021,
       0,     0,     0,     0,  2024,  2025,  2026,  2027,  2028,  2029,
       0,  1139,     0,     0,     0,     0,  1665,     0,     0,     0,
     430,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,  1890,     0,     0,     0,  1891,
       0,  2060,  2061,  2062,  2063,  2064,  2065,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,   187,   150,     0,
       0,  1092,     0,     0,   188,   189,   190,   431,   431,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   376,   209,   210,   211,
     212,   213,   214,     0,     0,     0,   431,     0,     0,   150,
     341,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,  1285,     0,     0,   225,
     226,   227,     0,     0,  1456,     0,     0,   228,    21,     0,
       0,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,   352,   353,   354,     0,     0,
       0,     0,   355,   356,   357,     0,     0,   358,     0,   359,
       0,  1489,     0,     0,     0,     0,     0,     0,     0,     0,
     360,     0,   361,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,  1524,  1525,  1526,  1527,  1528,     0,
       0,   882,     0,  1533,  1534,     0,  1536,     0,     0,   389,
       0,     0,  1542,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1546,     0,   518,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,   431,   237,     0,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   377,     0,     0,     0,
     246,     0,     0,     0,     0,   323,   362,   363,   364,   567,
       0,     0,   249,     0,     0,     0,     0,     0,     0,   365,
       0,   366,   107,     0,     0,     0,     0,  1606,     0,  1609,
       0,   431,     0,  1616,     0,  1618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,  1637,     0,   540,     0,     0,     0,     0,
       0,     0,   187,     6,   341,   925,     0,  1457,  1458,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   220,   221,   222,   223,   351,   352,
     353,   354,   224,     0,     0,     0,   355,   356,   357,     0,
       0,   358,     0,   359,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   360,     0,   361,     0,     0,   229,
       0,     0,   230,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    37,     0,     0,   431,   431,   431,
     431,   431,     0,     0,     0,     0,   233,     0,    49,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,   431,     0,  1766,  1767,     0,  1064,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     362,   363,   364,   237,   238,     0,     0,     0,   239,   240,
     241,   242,   243,   365,     0,   366,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1793,  1794,     0,
     244,   245,     0,     0,     0,   246,     0,     0,     0,     0,
     323,     0,     0,     0,  1490,     0,     0,   249,     0,     0,
     187,     6,   341,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,  1835,  1836,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   220,   221,   222,   223,   351,   352,   353,   354,
     224,     0,     0,     0,   355,   356,   357,     0,     0,   358,
       0,   359,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   360,     0,   361,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1074,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   362,   363,
     364,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,   365,     0,   366,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   323,   187,
     150,   341,   248,   388,     0,   249,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   376,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   220,   221,   222,   223,   351,   352,   353,   354,   224,
       0,     0,     0,   355,   356,   357,     0,     0,   358,     0,
     359,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   360,     0,   361,     0,     0,   150,   341,     0,     0,
       0,  2046,     0,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
     389,  1075,     0,     0,     0,     0,     0,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,   352,   353,   354,     0,     0,     0,     0,   355,
     356,   357,     0,     0,   358,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   360,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   390,
       0,     0,     0,     0,     0,     0,   236,   362,   363,   364,
     237,     0,     0,     0,     0,   239,   240,   241,   242,   243,
     365,     0,   366,   107,   391,   392,   393,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   377,     0,
       0,     0,   246,     0,   395,   396,     0,   397,     0,   398,
     187,     6,   322,   399,   249,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,   362,   363,   364,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,   365,     0,   366,   107,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,   370,   341,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,   352,   353,   354,     0,     0,     0,     0,   355,   356,
     357,     0,     0,   358,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   360,   236,   361,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   323,   187,
       6,  1582,   248,     0,     0,   249,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,   362,   363,   364,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,   365,     0,   366,     0,   228,
      21,     0,     0,     0,     0,     0,   229,     0,     0,   230,
       0,     0,   231,     0,   232,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,    49,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1076,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   323,   187,     6,
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
       0,    73,     0,     0,    76,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1081,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   585,  1728,     0,     0,
       0,   246,     0,     0,     0,     0,   587,   187,     6,     0,
     288,   521,     0,   249,   188,   189,   190,     0,     0,   191,
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
      73,     0,     0,    76,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1082,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,     0,     0,     0,
     246,     0,     0,     0,     0,   247,   187,     6,     0,   248,
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
       0,     0,    76,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,     0,     0,     0,   246,
       0,     0,     0,     0,   323,   187,     6,     0,   248,     0,
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
       0,    76,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   429,     0,     0,     0,   246,     0,
       0,     0,     0,   323,   187,     6,     0,   516,     0,     0,
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
      76,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   429,     0,     0,     0,   246,     0,     0,
       0,     0,   323,   187,     6,     0,     0,   521,     0,   249,
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
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   245,     0,     0,     0,   246,     0,     0,     0,
       0,   551,   187,     6,     0,   248,     0,     0,   249,   188,
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
      68,    69,     0,     0,     0,    73,     0,     0,    76,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,   238,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,     0,     0,     0,   246,     0,     0,     0,     0,
     560,   187,     6,     0,   248,     0,     0,   249,   188,   189,
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
      69,     0,     0,     0,    73,     0,     0,    76,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1373,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,     0,     0,     0,   246,     0,     0,     0,     0,   562,
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
       0,     0,     0,    73,     0,     0,    76,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1415,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   564,   187,
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
       0,     0,    73,     0,     0,    76,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   429,     0,
       0,     0,   246,     0,     0,     0,     0,   323,   187,     6,
       0,   831,     0,     0,   249,   188,   189,   190,     0,     0,
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
       0,    73,     0,     0,    76,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1530,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   245,     0,     0,
       0,   246,     0,     0,     0,     0,   323,   187,     6,     0,
    1590,     0,     0,   249,   188,   189,   190,     0,     0,   191,
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
      73,     0,     0,    76,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1531,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   585,  1728,     0,     0,     0,
     246,     0,     0,     0,     0,   587,   187,     6,     0,   288,
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
       0,     0,    76,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   429,     0,     0,     0,   246,
     187,   150,   341,     0,   323,     0,     0,   188,   189,   190,
       0,   249,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   376,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   220,   221,   222,   223,   351,   352,   353,   354,
     224,     0,     0,     0,   355,   356,   357,     0,     0,   358,
       0,   359,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   360,     0,   361,   187,   150,   341,     0,     0,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   376,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   220,   221,   222,
     223,   351,   352,   353,   354,   224,     0,     0,     0,   355,
     356,   357,     0,     0,   358,     0,   359,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   360,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   362,   363,
     364,   237,     0,     0,     0,     0,   239,   240,   241,   242,
     243,   365,     0,   366,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   377,
       0,     0,     0,   246,     0,     0,     0,     0,   323,     0,
       0,     0,  1486,     0,     0,   249,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1538,     0,     0,     0,     0,     0,
       0,     0,   236,   362,   363,   364,   237,     0,     0,     0,
       0,   239,   240,   241,   242,   243,   365,     0,   366,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   377,     0,     0,     0,   246,     0,
       0,     0,     0,   323,   187,   150,   341,  1741,     0,     0,
     249,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   376,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   220,   221,   222,   223,
     351,   352,   353,   354,   224,     0,     0,     0,   355,   356,
     357,     0,     0,   358,     0,   359,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   360,     0,   361,   187,
     150,   341,     0,     0,     0,     0,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   376,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   220,   221,   222,   223,   351,   352,   353,   354,   224,
       0,     0,     0,   355,   356,   357,     0,     0,   358,     0,
     359,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   360,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   362,   363,   364,   237,     0,     0,     0,     0,
     239,   240,   241,   242,   243,   365,     0,   366,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   377,     0,     0,     0,   246,     0,     0,
       0,     0,   323,     0,     0,     0,  1747,     0,     0,   249,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1539,     0,
       0,     0,     0,     0,     0,     0,   236,   362,   363,   364,
     237,     0,     0,     0,     0,   239,   240,   241,   242,   243,
     365,     0,   366,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   377,     0,
       0,     0,   246,   187,   150,     0,     0,   323,     0,     0,
     188,   189,   190,     0,   249,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   376,   209,   210,   211,   212,   213,   214,     0,
       0,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,   220,   221,   222,   223,   540,
       0,     0,     0,   224,     0,     0,     0,     0,     0,  1540,
       0,     0,     0,     0,     0,   225,   226,   227,   187,   150,
       0,  1223,     0,   228,    21,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   376,   209,   210,
     211,   212,   213,   214,     0,     0,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
     220,   221,   222,   223,   540,     0,     0,     0,   224,     0,
       0,     0,     0,     0,  1659,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1770,     0,
     236,     0,     0,     0,   237,     0,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   585,   586,     0,     0,     0,   246,     0,     0,     0,
       0,   587,     0,     0,     0,   288,     0,     0,   249,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,   236,     0,  1771,     0,   237,
       0,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   377,     0,     0,
       0,   246,   187,   150,     0,  1378,   323,     0,     0,   188,
     189,   190,     0,   249,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   376,   209,   210,   211,   212,   213,   214,     0,     0,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,   220,   221,   222,   223,   540,     0,
       0,     0,   224,     0,     0,     0,     0,     0,  1795,     0,
       0,     0,     0,     0,   225,   226,   227,   187,   150,     0,
    1432,     0,   228,    21,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   376,   209,   210,   211,
     212,   213,   214,     0,     0,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,   220,
     221,   222,   223,   540,     0,     0,     0,   224,     0,     0,
       0,     0,     0,  1796,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1797,     0,   236,
       0,     0,     0,   237,     0,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   377,     0,     0,     0,   246,     0,     0,     0,     0,
     323,     0,     0,     0,     0,     0,     0,   249,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,   236,     0,  1798,     0,   237,     0,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   377,     0,     0,     0,
     246,   187,   150,     0,     0,   323,     0,     0,   188,   189,
     190,     0,   249,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     376,   209,   210,   211,   212,   213,   214,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     7,     8,
       0,   228,    21,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1799,     0,     0,     0,     0,   698,    25,    26,   699,
      28,    29,   700,    31,   701,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,   702,    48,     0,     0,    50,   703,     0,
      53,   704,     0,     0,     0,   698,    25,    26,   699,    28,
      29,   700,    31,   701,    33,    34,    35,    36,     0,    70,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   702,    48,     0,     0,    50,   703,   236,    53,
     704,     0,   237,    84,    85,    86,     0,   239,   240,   241,
     242,   243,     7,     8,     0,   107,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     377,     0,     0,     0,   246,     0,     0,     0,     0,   323,
       0,     0,    84,    85,    86,     0,   249,     0,     0,     0,
       7,     8,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,  1141,     0,     0,     0,     0,     0,     0,     0,
    1859,     0,     0,     0,     0,     0,     0,     0,     0,   698,
      25,    26,   699,    28,    29,   700,    31,   701,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,  1142,     0,     0,     7,     8,   702,    48,     0,     0,
      50,   703,     0,    53,   704,     0,     0,   698,    25,    26,
     699,    28,    29,   700,    31,   701,    33,    34,    35,    36,
       0,     0,    70,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   702,    48,     0,     0,    50,   703,
       0,    53,   704,     0,     0,     0,    84,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   698,    25,    26,   699,    28,    29,   700,    31,   701,
      33,    34,    35,    36,    84,    85,    86,    38,    39,    40,
       7,     8,    42,     0,     0,     0,     0,     0,   702,    48,
       0,     0,    50,   703,     0,    53,   704,     0,     0,     0,
       0,     0,     0,     0,     0,  1161,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     7,     8,   540,     0,    84,    85,
      86,     0,     0,  1190,     0,     0,  1916,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   698,    25,    26,
     699,    28,    29,   700,    31,   701,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   702,    48,     0,     0,    50,   703,
       0,    53,   704,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1220,     0,     0,
      70,   698,    25,    26,   699,    28,    29,   700,    31,   701,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       7,     8,    42,     0,    84,    85,    86,     0,   702,    48,
       0,     0,    50,   703,     0,    53,   704,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,    70,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1917,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1370,     0,     0,     0,   698,    25,    26,
     699,    28,    29,   700,    31,   701,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   702,    48,     0,     0,    50,   703,
       0,    53,   704,     0,     0,     0,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,  1947,     0,     0,
      70,     0,    -4,    -4,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,    84,    85,    86,     0,     0,     0,
       0,     0,  1929,    -4,    -4,     0,     0,     0,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,    -4,    -4,    -4,   540,     0,     0,    -4,
      -4,     0,    -4,     0,     0,     0,  1930,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,  2010,    -4,    -4,    -4,    -4,    -4,     0,
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
       0,     0,     0,     0,     0,     0,     0,   698,    25,    26,
     699,    28,    29,   700,    31,   701,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   702,    48,     0,     0,    50,   703,
       0,    53,   704,     0,     0,     0,     0,   962,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,   698,    25,    26,   699,    28,    29,   700,    31,   701,
      33,    34,    35,    36,    84,    85,    86,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   702,    48,
       0,     0,    50,   703,     0,    53,   704,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,    70,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1931,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1932,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1933,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1965,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1995,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2000,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2001,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2002,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2003,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2004,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2005,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2047,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2048,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2049,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2050,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1164,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1229,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1374,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1438,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1439,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1440,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1441,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1707,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1718,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1785,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1786,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1787,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1788,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1790,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1812,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1827,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1879,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1896,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1905,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1906,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  1927,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  1981,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  2023,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  2045,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  2071,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  2072,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  2073,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  2074,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,  2075,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,  2076,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
     663,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,   873,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,  1805,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,   685,
       0,   686,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,   931,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,   976,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
    1111,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,  1177,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,  1178,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,  1182,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,  1183,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,  1265,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,  1281,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,  1469,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,  1596,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,  1763,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
    1813,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,   734,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,   735,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,   737,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,   739,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,   740,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,   742,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,   744,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,   745,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,   746,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
     747,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,   748,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,   749,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,   751,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,   752,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,   753,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,   815,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,   844,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,   902,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,   920,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
     921,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,   922,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,   923,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,   929,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,   930,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,   961,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,   975,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,  1032,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,  1037,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,  1050,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
    1110,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,  1116,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,  1117,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,  1118,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,  1132,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,  1133,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,  1134,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,  1163,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,  1165,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,  1166,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
    1167,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,  1168,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,  1169,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,  1170,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,  1171,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,  1176,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,  1264,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,  1280,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,  1474,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540,     0,  1541,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   662,   538,   539,     0,     0,     0,     0,   540,     0,
    1653,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   662,   538,   539,     0,     0,     0,     0,   540,
       0,  1654,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   662,   538,   539,     0,     0,     0,     0,
     540,     0,  1655,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   662,   538,   539,     0,     0,     0,
       0,   540,     0,  1656,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   662,   538,   539,     0,     0,
       0,     0,   540,     0,  1708,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   662,   538,   539,     0,
       0,     0,     0,   540,     0,  1717,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   662,   538,   539,
       0,     0,     0,     0,   540,     0,  1740,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   662,   538,
     539,     0,     0,     0,     0,   540,     0,  1994,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   662,
     538,   539,     0,     0,     0,     0,   540,     0,  2042,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     662,   538,   539,     0,     0,     0,     0,   540
};

static const yytype_int16 yycheck[] =
{
       3,   132,     3,  1162,   494,  1158,   281,   582,   583,   695,
    1620,     7,  1622,     4,     4,     4,     4,   680,    21,    21,
       4,     4,     4,     4,     4,   688,     4,   713,     4,     4,
      96,  1778,     5,     9,     4,     6,   183,   184,   185,    98,
     158,   100,     7,     5,    47,   163,     6,     4,     4,    96,
     168,  1584,     6,   232,     5,   234,     5,    96,     4,    93,
       7,   240,    96,     9,   182,     6,   234,     6,     6,   147,
     117,    74,   240,   132,   293,     9,     9,     4,   117,    82,
       4,     6,     6,   232,    87,     6,    60,    61,   237,    63,
       6,   310,     6,     0,   172,    98,   155,   234,   221,   222,
       6,     6,    90,   240,   221,   222,    94,   221,   222,   231,
     188,   189,   100,   101,   235,   103,   104,   240,   239,   266,
     267,   268,   232,   240,   234,   235,   240,    14,     8,   132,
     221,   222,   133,   121,   137,   138,   231,   221,   222,     5,
     235,   231,   145,   633,   262,   635,   231,  1680,     9,   240,
     235,     5,   236,   156,   373,   158,   375,   304,   305,   306,
     163,   231,     4,   382,     9,   168,    90,   232,     6,   234,
     317,   318,   175,   228,   229,   240,   179,  1924,     4,   182,
     183,   184,   185,   186,   162,   163,   164,   165,   232,   160,
       9,   233,     7,   231,   221,   222,   240,   235,     7,   183,
     160,     6,   175,     7,   131,   132,   133,   134,   235,   221,
     222,     6,   208,   209,   210,   211,   207,   187,   207,   146,
       6,     6,   149,   207,   175,   207,    93,   207,   240,    96,
     233,   207,   228,   229,   132,   228,   229,  1390,   233,   137,
     138,   237,   245,   233,   237,   248,   249,   238,   231,   239,
     231,   235,   235,   235,   235,   235,   231,     6,   236,   262,
     235,   207,   265,   266,   267,   268,   231,     7,   233,  1802,
     273,   274,   275,   235,   231,   231,   279,   175,   281,   235,
     218,   235,   228,   229,   235,   231,   235,   233,   186,   235,
     237,   237,   231,   218,   235,   231,   235,   231,   231,   233,
     233,   304,   305,   306,   237,   221,   222,   221,   222,   175,
     284,   285,   975,   976,   317,   318,   221,   222,   292,   293,
       7,   175,  1855,   236,   236,    96,    47,   240,   240,   388,
     172,   173,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   172,   173,    93,  1959,
     230,    96,   571,    98,   573,   574,   236,   110,   232,   506,
     507,   508,   509,   231,   221,   222,   240,   228,   229,   231,
     231,   590,   233,   234,   231,   231,   237,   380,   235,   232,
     235,   384,   385,   228,   229,   236,   231,   240,   233,   240,
       6,     7,   237,   208,   209,   210,   211,   400,   516,   208,
     209,   210,   211,   406,   208,   209,   210,   211,   627,   228,
     229,   231,   231,   236,   233,  1101,     6,   240,   237,   228,
     229,   231,   425,  1109,   228,   229,   429,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   221,   222,   232,   663,   230,   131,   132,   566,   567,
     231,   240,   137,   221,   222,   514,   221,   222,   179,   231,
     240,  1124,   231,  1126,  1997,  1128,   232,  1130,   208,   209,
     210,   211,   240,   476,   240,   240,   232,   221,   222,   236,
     483,   484,   380,   240,   240,   488,     8,   490,   491,   492,
     493,   494,   231,   611,   612,   613,   240,   556,   557,   558,
     559,   127,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   513,   233,   516,   131,   132,   221,   222,   144,   231,
     137,   208,   209,   210,   211,  2058,   152,   153,   154,   231,
     127,   232,   158,   159,   537,   240,   236,   655,   541,   240,
     240,   228,   229,   232,   265,   234,    96,   144,   127,   680,
       6,   240,   273,   274,   275,   152,   153,   154,   279,   221,
     222,   158,   159,   566,   567,   144,   221,   222,   232,   687,
     234,     6,     7,   152,   153,   154,   240,  1263,   240,   158,
     159,   582,   583,   221,   222,   240,   221,   222,   231,   648,
     488,   709,   490,  1279,   492,   493,   235,   715,   221,   222,
       8,   231,   240,   221,   222,   240,   580,   581,   611,   612,
     613,   585,   510,   511,    93,   221,   222,   240,    90,   221,
     222,    93,   240,   236,    96,   231,    98,   240,   127,   235,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   236,
     643,   644,   645,   646,   647,   144,   649,   650,   651,   652,
       8,   231,   655,   152,   153,   154,   231,   236,   877,   158,
     159,   221,   222,   384,   385,   231,   221,   222,   221,   222,
     729,   789,   221,   222,   221,   222,   228,   229,   236,   400,
     240,   235,   240,   235,   687,   240,   235,   240,   235,   692,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   221,   222,   709,   710,   230,   840,
     221,   222,   715,   831,   236,   718,   221,   222,   721,    90,
     723,   235,    93,   240,   842,    96,    96,    98,   731,   240,
     733,   232,    93,   234,   235,   240,   634,   236,   636,   637,
     638,   639,   640,   641,   231,   643,   644,   645,   646,    93,
     231,   649,   650,   651,   235,   873,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     491,   127,    96,   231,   230,   233,   221,   222,   223,   224,
     225,  1444,     4,   231,   505,   230,   789,   235,   144,  1948,
       4,     4,   232,  1456,   234,   236,   152,   153,   154,   240,
     240,     4,   158,   159,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    93,   231,
     718,    96,   230,    98,   232,   723,   234,   236,   831,    90,
    1983,   240,    93,   228,   229,    96,     6,    98,   236,   842,
     235,   231,   240,    90,   975,   976,    93,   850,     6,    96,
     231,    96,  2011,    98,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    93,   231,
     873,    96,   230,    98,   232,   993,   994,   995,   996,  2032,
     236,   223,   224,   225,   231,   236,   236,   236,   230,   240,
     240,   240,     4,     5,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   880,   236,   236,     6,
     230,   240,   240,   887,   231,   233,   233,   891,   977,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   127,     6,
     231,   233,   230,  1051,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   237,   232,   239,   234,    59,    60,    61,
      62,     8,     6,   239,   236,    67,    68,    69,   240,   236,
      72,   235,    74,   240,   967,   236,     6,  1457,  1458,   240,
    1245,   239,   236,    85,   231,    87,   240,   236,   981,  1110,
    1111,   240,   236,   986,   236,   236,   240,     9,   240,   240,
     993,   994,   995,   996,  1569,  1570,   236,  1115,   231,   236,
     240,   236,  1005,   240,   236,   240,   236,   236,   240,   235,
     240,   240,   124,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,  1030,  1031,   231,
    1033,   230,  1035,  1036,    96,  1038,    98,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,   236,   236,  1051,   236,
     240,   240,  1026,   240,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   231,   236,
     236,   236,   230,   240,   240,   240,   231,     4,  1196,   191,
     192,   193,   236,  1086,  1087,  1088,   240,   236,    96,   236,
      98,   240,   204,   240,   206,   207,   236,   231,   236,   236,
     240,  1104,   240,   240,   236,   236,   236,  1005,   240,   240,
     240,  1114,  1115,   117,   236,   236,   228,   229,   240,   240,
     236,   231,   235,   235,   240,   237,     6,   236,   236,   850,
     231,   240,   240,  1264,  1265,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,     4,
     236,     6,   231,   230,   240,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,  1172,
     231,   231,   231,   230,     6,   231,  1451,   235,   231,   231,
     235,     6,  1185,  1186,  1187,   235,   231,   231,   231,  1087,
    1088,   233,   231,  1196,     6,   231,   231,   231,  1201,   231,
     233,     6,  1205,     6,   235,   235,   235,   233,   233,   175,
     233,  1214,  1431,  1216,   235,   231,  1435,   231,   231,   231,
     231,     6,     6,  1226,     6,  1284,   235,  1286,     6,     6,
     235,     7,     6,  1808,   235,     6,   235,    86,   236,   232,
     240,     7,  1245,   240,     6,     6,   967,     6,   232,   235,
      64,    64,   230,    64,    64,     4,     7,  1747,   232,   235,
       7,     6,  1265,     6,     6,   986,     6,     6,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,     7,  1286,  1402,     6,   230,     7,   232,     6,
     234,     6,     6,   172,  1297,   235,   240,   234,   232,     6,
    1303,   237,   235,  1201,   235,   235,   235,  1205,     7,  1030,
    1031,     6,  1033,  1444,  1035,  1036,  1214,  1038,  1216,  1040,
    1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,     8,   233,
     231,     4,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,  1349,  1350,  1351,     6,
     230,     6,  1355,     6,  1357,     6,  1359,   232,  1361,  1634,
    1363,  1364,  1365,   233,     7,  1086,   175,  1265,     7,     7,
       7,  1430,     7,   175,     7,     7,   175,  1380,     7,     7,
       7,     7,     7,  1104,     7,     7,     7,     7,  1391,   235,
       6,   232,   234,  1114,   232,   240,  1399,   240,   235,  1402,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,  1545,  1389,   240,   235,   230,   235,
     235,   240,     7,     7,     4,     6,   232,  1486,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   237,  1561,  1562,   235,   230,   240,  1451,   232,
     237,  1172,   240,   232,  1457,  1458,   236,   232,   127,   240,
    1463,     7,     6,   236,  1185,  1186,  1187,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,  1481,     7,
     240,     7,   230,  1486,     7,   237,   232,  1490,   232,     9,
     240,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,  1226,  1565,   240,   240,   230,
     232,   234,     7,   147,     6,  1646,     6,   236,     4,   235,
     231,    46,    46,   235,   237,   231,  1500,   231,   231,   218,
       4,     7,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,  1605,   237,     7,    98,
     230,     7,   240,  1612,  1613,     7,     7,     7,  1561,  1562,
       6,   108,     7,     7,     7,  1286,     7,  1626,  1569,  1570,
    1845,     7,     4,     4,   235,   231,  1297,     6,    96,     7,
       6,  1584,  1303,  1481,     7,     7,     7,  1590,     7,     7,
       7,     7,     6,   235,     6,     6,  1599,     7,  1817,     6,
       6,     4,     4,     4,  1607,   121,     6,  1610,   238,   240,
       6,  1585,  1586,  1587,  1588,  1589,  1590,   235,   235,     6,
    1623,   240,   236,  1741,     7,     6,   233,  1630,  1349,  1350,
    1351,  1634,     6,  1636,  1355,   231,  1357,   231,  1359,     6,
    1361,     6,  1363,  1364,  1365,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,  1380,
     235,   237,     6,   230,   234,   232,   240,     6,     6,   235,
    1391,   235,     6,   240,   235,   235,     6,  1680,  1399,     6,
     235,   175,     6,     6,     6,     6,     6,  1805,     6,     6,
       6,  1910,     6,  1752,     5,   232,   232,     6,     4,     6,
       4,     6,  1820,     4,     5,   235,   235,     7,   235,  1607,
       6,   233,  1610,  1716,   235,     6,   235,     6,   235,     6,
     235,   235,   235,   235,  1783,  1728,   235,   235,     6,     6,
    1949,   171,     6,   240,   240,   232,   240,     6,  1741,   237,
       7,     4,  1463,   231,  1747,    46,    47,    48,    49,    50,
      51,    52,    53,    54,   235,   235,     6,     6,    59,    60,
      61,    62,     7,     8,     6,  1486,    67,    68,    69,     6,
    1773,    72,     6,    74,     6,     4,     7,  1780,     6,     6,
       6,  1784,     6,     6,    85,     5,    87,   235,   235,     6,
       6,    94,     6,     6,     6,     6,     6,     6,     6,  1802,
       6,   240,  1805,     6,     6,     6,   240,  1808,     6,     4,
       6,   235,     6,  1816,     6,   240,     6,  1820,     7,     5,
     235,     6,   235,   124,     6,     6,   235,     7,   236,     6,
     170,   236,     6,  1951,  1952,  1953,  1954,  1955,   235,   232,
       6,   236,  1845,     7,   236,   236,     6,  1821,  1822,  1823,
    1824,  1825,  1855,   237,     6,     6,     6,   235,     6,     6,
       6,     6,     6,  1584,     6,     6,  1925,   236,     6,   232,
       6,   235,     6,   231,   173,   236,   236,     6,  1599,   235,
    1883,   235,   235,     6,   236,     6,   127,   235,     6,     6,
     191,   192,   193,     6,   235,   232,     6,     6,  2016,     6,
     236,   236,  1623,   204,     6,   206,   207,     6,  1882,     6,
       6,     6,  1886,     6,     6,  1636,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
       6,   232,     6,   234,   230,     6,     6,   235,   235,     6,
     235,     6,     6,     6,     6,  1278,  1961,   422,  1951,  1952,
    1953,  1954,  1955,  1329,  1494,  1779,  1550,  1751,  1296,  1680,
       3,  1935,     3,     3,     3,  1939,   555,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,  1955,  1804,     3,  1630,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1997,  1716,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,  2016,   230,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,  2006,  2007,   230,    -1,    -1,    -1,  2041,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,  1773,    -1,    -1,  2058,    -1,    -1,    -1,  1780,
      -1,    -1,    -1,    -1,    -1,  2068,  2069,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,     6,
     136,  1802,  2085,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1816,    -1,    -1,     6,    -1,
      -1,   157,   158,   159,   160,    -1,   162,   163,   164,   165,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,   177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2041,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,  1883,   230,    -1,    -1,    -1,    -1,    -1,    -1,
    2068,  2069,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2085,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   261,   262,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   277,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   287,   288,    -1,    -1,   240,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,   323,    -1,    -1,
      -1,   327,   328,   329,    -1,   331,  1997,    -1,    -1,   335,
     336,   337,    -1,    -1,   340,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,   377,   230,    -1,    -1,   381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2058,    -1,    -1,
      -1,   397,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   411,    -1,     6,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   429,    -1,    -1,   230,    -1,    -1,   435,
      -1,    -1,   236,    -1,   440,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,    -1,
     486,   487,    -1,   489,    -1,    -1,    -1,    -1,    -1,   495,
      -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,    -1,   542,   543,    -1,    -1,
      -1,    -1,    -1,   549,   550,   551,    -1,    -1,    -1,    -1,
     556,   557,   558,   559,   560,    -1,   562,    -1,   564,    -1,
     566,   567,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,     6,   585,
     586,   587,   230,    -1,   232,   591,   592,   593,   594,   595,
     596,   597,   598,   599,    -1,    -1,    -1,    -1,   604,    -1,
     606,   607,    -1,     7,    -1,   611,   612,   613,    -1,    -1,
     616,   617,   618,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,
      -1,    13,    14,    -1,   660,    -1,   662,    -1,   664,   665,
      -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,    -1,
      -1,   677,    -1,    -1,   158,    -1,    -1,    -1,    -1,   163,
      -1,   687,    -1,    -1,   168,    -1,    -1,   693,   694,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,   709,    -1,   711,   712,    -1,    -1,   715,
     716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   724,    -1,
      -1,    -1,   728,    -1,    -1,   731,    -1,   733,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,   107,   108,    -1,   754,   111,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,
     122,   245,   124,   125,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,   262,    -1,
      -1,   143,    -1,   789,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,   167,   168,   169,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,   831,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   842,    -1,    -1,    -1,
      -1,    -1,    -1,   849,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,   873,   106,   107,
     108,    -1,    -1,   111,   236,   881,   882,    -1,    -1,   117,
     118,   887,    -1,   121,   122,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   903,    -1,    -1,
     906,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   925,
      -1,   927,   928,    -1,    -1,    13,    14,    -1,    -1,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     946,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   963,    -1,    -1,
      -1,    -1,    -1,    -1,   970,   971,   972,   973,    -1,    -1,
      -1,    -1,   978,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   992,   993,   994,   995,
     996,   997,   476,    -1,    -1,    -1,    -1,    -1,   236,   483,
     484,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,   512,   117,
     118,    -1,   516,   121,   122,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1051,    -1,    -1,     8,    -1,
      -1,    -1,    -1,   537,    -1,   143,    -1,    -1,  1064,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,  1075,
    1076,    -1,    13,    14,    -1,  1081,  1082,     8,  1084,   167,
     168,   169,   566,   567,    -1,  1091,    -1,  1093,  1094,  1095,
    1096,  1097,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1106,  1107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,
      -1,  1127,    -1,  1129,    -1,  1131,    -1,   611,   612,   613,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,  1152,    -1,   236,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,   655,    -1,    -1,    -1,    -1,   117,   118,  1184,    -1,
     121,   122,    -1,   124,   125,    -1,    -1,    -1,    -1,    -1,
    1196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1204,    -1,
      -1,    -1,   143,   687,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1222,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   709,   167,   168,   169,    -1,
    1236,   715,    -1,  1239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   731,    -1,   733,
     132,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,  1272,  1273,  1274,  1275,
     230,    -1,    -1,    -1,    -1,    -1,    -1,  1283,  1284,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   236,    -1,    -1,   402,   230,
      -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
     222,   223,    -1,    -1,    -1,    -1,   228,   831,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,   842,    -1,
      -1,    -1,    -1,    -1,     8,  1371,  1372,  1373,    -1,    -1,
      -1,    -1,    -1,    -1,  1380,    -1,  1382,    -1,    -1,    -1,
      -1,    -1,    -1,  1389,    -1,    -1,    -1,    -1,    -1,   873,
      -1,    -1,    -1,    -1,    -1,    -1,  1402,    -1,    -1,    -1,
      -1,  1407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,
    1416,  1417,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1425,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,   546,    -1,    -1,    -1,    -1,    -1,    -1,  1455,
      -1,    -1,    -1,    -1,    -1,  1461,  1462,    -1,    -1,    -1,
     342,   343,   344,    -1,    -1,    -1,   348,   349,   350,   351,
     352,   353,   354,    -1,   356,    -1,    -1,    -1,   360,   361,
      -1,    -1,   364,    -1,  1490,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1498,  1499,   376,    -1,    -1,    -1,    -1,  1505,
    1506,    -1,    -1,    -1,    -1,    -1,  1512,    -1,    -1,   993,
     994,   995,   996,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1529,  1530,  1531,    -1,    -1,    -1,    -1,
      -1,  1537,  1538,  1539,  1540,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1552,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1561,  1562,  1563,    -1,  1565,
      -1,    -1,    -1,    -1,    -1,  1571,  1572,  1051,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,  1590,    -1,   230,    -1,  1594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1605,
      -1,    -1,  1608,    -1,    -1,    -1,  1612,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,  1627,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,  1115,    -1,    -1,  1640,   240,    -1,    -1,    -1,  1645,
      -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1659,    -1,    -1,    -1,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   771,    -1,   773,
     774,   775,   776,    -1,   778,   779,   780,   781,    -1,    -1,
      -1,    -1,    -1,  1689,    -1,    -1,    -1,    -1,   792,    -1,
     794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1710,     5,   810,   811,    -1,    -1,
      -1,    -1,  1196,  1719,   818,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1737,  1738,    -1,    -1,  1741,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,  1770,  1771,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,  1782,    -1,    13,    14,
      -1,    -1,    -1,  1789,    -1,    85,    -1,    87,    -1,  1795,
    1796,  1797,  1798,  1799,    -1,    -1,    -1,    -1,    -1,  1805,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,  1820,    -1,    -1,    -1,   230,    -1,
      -1,    -1,  1828,    -1,   236,    -1,    -1,    -1,   932,   933,
     934,    -1,    -1,    -1,   938,   939,    -1,    -1,   942,   943,
     944,   945,    -1,   947,    -1,    -1,  1852,    -1,   952,    -1,
      -1,    -1,  1858,  1859,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,  1891,   121,   122,    -1,   124,
     125,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,   206,    -1,   143,    -1,
    1916,  1917,    -1,    -1,    -1,    -1,    -1,    -1,  1402,    -1,
    1024,  1025,  1928,  1929,  1930,  1931,  1932,  1933,    -1,    -1,
      -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
    1946,    -1,    -1,    -1,    -1,  1951,  1952,  1953,  1954,  1955,
      -1,    -1,    -1,    -1,    -1,  1961,    -1,    -1,    -1,  1965,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   240,  1995,
      -1,    -1,    -1,    -1,  2000,  2001,  2002,  2003,  2004,  2005,
      -1,   236,    -1,    -1,    -1,    -1,  1490,    -1,    -1,    -1,
    2016,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   240,
      -1,  2047,  2048,  2049,  2050,  2051,  2052,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,     3,     4,    -1,
      -1,   236,    -1,    -1,    10,    11,    12,  1561,  1562,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,  1590,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1018,    -1,    -1,    75,
      76,    77,    -1,    -1,  1248,    -1,    -1,    83,    84,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      -1,  1285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,  1318,  1319,  1320,  1321,  1322,    -1,
      -1,   240,    -1,  1327,  1328,    -1,  1330,    -1,    -1,   124,
      -1,    -1,  1336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1346,    -1,  1728,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,  1741,   194,    -1,
      -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,   231,   191,   192,   193,   235,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,   206,   207,    -1,    -1,    -1,    -1,  1421,    -1,  1423,
      -1,  1805,    -1,  1427,    -1,  1429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1820,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,  1457,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,   240,    -1,  1249,  1250,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    87,    -1,    -1,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,  1951,  1952,  1953,
    1954,  1955,    -1,    -1,    -1,    -1,   117,    -1,   119,    -1,
      -1,   122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,  2016,    -1,  1638,  1639,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,   194,   195,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,    -1,   206,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1681,  1682,    -1,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,   235,    -1,    -1,   238,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,  1745,  1746,    46,    47,    48,    49,    50,    51,    52,
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
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,   194,   195,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,
       4,     5,   235,     7,    -1,   238,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    87,    -1,    -1,     4,     5,    -1,    -1,
      -1,  2025,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   240,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,   228,   229,    -1,   231,    -1,   233,
       3,     4,     5,   237,   238,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,   204,    -1,   206,   207,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,   190,    87,    -1,
      -1,   194,   195,    -1,    -1,    -1,   199,   200,   201,   202,
     203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,
       4,     5,   235,    -1,    -1,   238,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,   204,    -1,   206,    -1,    83,
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
     235,   236,    -1,   238,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   231,     3,     4,    -1,    -1,   236,    -1,   238,
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
      -1,   231,     3,     4,    -1,   235,    -1,    -1,   238,    10,
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
       3,     4,     5,    -1,   231,    -1,    -1,    10,    11,    12,
      -1,   238,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,    -1,
      -1,    -1,   235,    -1,    -1,   238,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,    -1,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,   231,     3,     4,     5,   235,    -1,    -1,
     238,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,    -1,   206,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,   231,    -1,    -1,    -1,   235,    -1,    -1,   238,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,     3,     4,    -1,    -1,   231,    -1,    -1,
      10,    11,    12,    -1,   238,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    55,    56,    57,    58,   230,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,     3,     4,
      -1,     6,    -1,    83,    84,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      55,    56,    57,    58,   230,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
     200,   201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,   235,    -1,    -1,   238,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   240,    -1,   194,
      -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,   226,     3,     4,    -1,     6,   231,    -1,    -1,    10,
      11,    12,    -1,   238,    15,    16,    17,    18,    19,    20,
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
     226,     3,     4,    -1,    -1,   231,    -1,    -1,    10,    11,
      12,    -1,   238,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    13,    14,
      -1,    83,    84,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,    -1,
     124,   125,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,   143,
      -1,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    -1,   121,   122,   190,   124,
     125,    -1,   194,   167,   168,   169,    -1,   199,   200,   201,
     202,   203,    13,    14,    -1,   207,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,
      -1,    -1,   167,   168,   169,    -1,   238,    -1,    -1,    -1,
      13,    14,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
     111,   236,    -1,    -1,    13,    14,   117,   118,    -1,    -1,
     121,   122,    -1,   124,   125,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,   143,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,   121,   122,
      -1,   124,   125,    -1,    -1,    -1,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   167,   168,   169,   106,   107,   108,
      13,    14,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,   121,   122,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    13,    14,   230,    -1,   167,   168,
     169,    -1,    -1,   236,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
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
      -1,    -1,    -1,    -1,    -1,    -1,   240,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
     235,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,   235,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,   235,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
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
     230,    -1,    -1,    -1,   234,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
     234,   212,   213,   214,   215,   216,   217,   218,   219,   220,
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
     103,   104,   121,   231,    96,    98,    96,    93,     4,   183,
     235,   345,     4,     6,    90,    93,    96,    93,    96,     4,
       4,     4,     5,   231,   332,   333,     4,   231,   231,   231,
       4,   235,   336,   345,     4,   231,   231,   231,     6,     6,
     233,     5,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    59,    60,    61,    62,    67,    68,    69,    72,    74,
      85,    87,   191,   192,   193,   204,   206,   340,   345,   231,
       4,   340,     5,   235,     5,   235,    32,   222,   320,   345,
     233,   231,   235,     6,   231,   235,     6,   239,     7,   124,
     183,   208,   209,   210,   211,   228,   229,   231,   233,   237,
     263,   264,   265,   320,   339,   340,   345,     4,   289,   290,
     291,   235,     6,   320,   339,   340,   345,   339,   320,   339,
     343,   269,   273,   231,   328,     9,   340,   345,   320,   222,
     320,   334,   335,   320,   320,   231,   320,   335,   320,   320,
     231,   320,   335,   320,   320,   320,   320,   320,   320,   339,
     320,   320,   320,   332,   231,   335,   333,   333,   333,   339,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   231,   233,   265,   265,   265,   265,   265,
     265,   231,   265,   265,   231,   265,     5,   175,   235,     5,
     175,     5,   175,     5,   175,   117,    90,    93,    96,    98,
     231,   265,   265,   231,   231,   320,   235,   320,   334,   320,
     320,   236,   335,     9,   345,     8,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     230,     9,   231,   233,   237,   264,   265,   320,   335,   231,
     231,   231,   332,   333,   333,   333,   231,   231,   231,   231,
     231,   332,   231,   332,   231,   332,   235,   235,   320,     4,
     332,   235,   336,   235,   235,   329,   329,   329,   320,   320,
     221,   222,   235,   235,   329,   221,   222,   231,   291,   329,
     235,   231,   235,   231,   231,   231,   231,   231,   231,   231,
     320,   333,   333,   333,   231,     4,   233,   233,   291,     6,
       6,   235,   235,   235,   333,   333,   233,   233,   233,   320,
       6,     6,   320,   320,   320,   237,   320,   235,   175,   320,
     320,   320,   320,   265,   265,   265,   231,   231,   231,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   231,
     231,   265,   233,     6,     6,   235,     6,   291,     6,   291,
     265,   320,   223,   235,   231,   233,   339,   320,   291,   332,
     332,   235,   340,    90,    93,    96,    98,     7,   320,   320,
       4,   172,   173,   332,     6,   232,   234,   235,   266,     6,
     235,     6,     9,   231,   233,   237,   345,   236,    90,    93,
      96,    98,   117,   122,   125,   288,   320,     6,   232,   240,
       9,   231,   233,   237,   232,   240,   240,   232,   240,   234,
     240,   268,   234,   268,    86,   327,   324,   345,   240,   240,
     232,   223,   236,   240,   232,   232,   320,   232,   236,   232,
     232,   320,   232,   236,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,     7,   320,   236,     6,     6,     6,
     232,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   334,   320,
     320,   320,   320,   320,   320,   320,   334,   334,   345,   235,
     320,   320,   339,   320,   339,   332,   339,   339,   343,   320,
      64,   320,    64,    64,    64,   333,   333,   333,   333,   339,
     339,   334,   325,   340,   335,   232,   236,     9,   265,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   235,   320,   334,   320,   320,   320,   345,   320,   320,
       4,   326,   235,   266,   232,   236,   320,   320,   320,     7,
       7,   313,   313,   282,   320,   340,   283,   320,   340,   284,
     320,   340,   285,   320,   340,   320,     6,   320,     6,   320,
       6,   335,   335,   235,   232,     6,   291,   235,   291,   291,
     240,   240,   240,   329,   329,   290,   290,   240,   320,   236,
     304,   240,   291,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   232,     7,   314,     6,     7,   320,     6,   320,
     320,   236,   335,   335,   335,     6,     6,   320,   320,   320,
     232,   232,   232,   232,   172,   240,   291,   235,     8,   232,
     232,   234,   343,   339,   343,   339,   339,   339,   339,   339,
     339,   320,   339,   339,   339,   339,   238,   342,   345,   340,
     339,   339,   339,   345,   335,   236,   236,   320,   320,   291,
     234,   232,   130,   147,   308,   232,   236,   240,   320,     6,
     235,   235,   235,   235,   320,   232,   234,     7,   263,   264,
     237,     7,     6,   335,     7,   211,   263,   248,   345,   320,
     320,   326,   233,   235,   235,   235,   235,   231,   117,    93,
      96,    98,   236,     6,   218,   245,   335,   345,   320,   320,
       4,   326,     6,   335,   320,     6,   339,     6,   345,     6,
     339,   320,   232,   233,   320,   340,     7,   175,   320,   334,
       7,     7,   232,     7,   175,     7,     7,   232,     7,   175,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   320,
     232,   235,     6,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   240,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   240,   240,   240,   232,   234,   234,
     335,   240,   240,   266,   240,   266,   240,   240,   240,   232,
     322,   235,   236,   235,   235,   235,   240,   240,   266,   266,
     232,   237,   232,   236,     7,   266,     8,     8,   335,   237,
     232,   234,   264,   335,     7,   235,   232,   232,   232,   320,
     332,     4,   312,     6,   232,   240,   232,   240,   232,   240,
     232,   240,   232,   232,   232,   236,   236,   335,   237,   236,
     291,   236,   236,   329,   320,   320,   236,   236,   320,   329,
     127,   127,   144,   152,   153,   154,   158,   159,   305,   306,
     329,   236,   301,   232,   236,   232,   232,   232,   232,   232,
     232,   232,     7,   320,     6,   320,   232,   234,   234,   236,
     236,   236,   234,   234,   240,     7,     7,     7,   237,   320,
     236,   320,   320,     7,   237,   266,   240,   266,   266,   232,
     232,   240,   266,   266,   240,   240,   266,   266,   266,   266,
     320,   266,     9,   341,   240,   232,   240,   266,   234,   236,
     236,     7,   147,     6,   320,   236,   235,     6,   332,   236,
     320,   320,   320,   320,     6,     7,   263,   264,   237,   263,
     264,   340,   320,     6,     4,   235,   337,   345,   236,    46,
      46,   332,     4,   162,   163,   164,   165,   236,   251,   255,
     258,   260,   261,   237,   232,   234,   320,   335,   335,   335,
     335,   320,   231,   231,   231,   231,   218,   339,   232,   237,
     232,   234,   232,   240,     7,   265,     4,   276,   277,   278,
     266,   266,   329,    96,    98,   332,   332,     7,   332,    96,
      98,   332,   332,     7,   332,    98,   332,   332,   332,   332,
     332,   332,   332,   332,   332,     6,     7,   335,   320,   320,
     320,   320,   236,   320,   320,   320,   332,   339,   339,   240,
     275,   320,   320,   320,   320,   320,   320,   326,   332,   320,
     320,   236,   326,   264,   237,   264,   236,   332,   335,     7,
       7,     7,   127,   311,     6,   263,   320,   263,   320,   263,
     320,   263,   320,     7,     7,     7,     7,     7,   236,     4,
     236,   240,   240,   240,   236,   236,   108,     4,     6,   320,
     235,     6,   231,     6,   160,     6,   160,   236,   306,   240,
     305,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     332,     6,   235,     6,     6,     6,    96,     7,     6,     6,
     320,   332,   332,   332,     4,   240,     8,     8,   232,     4,
       4,   335,   339,   320,   339,   238,   240,   279,   339,   339,
     240,   235,     6,   320,     6,   235,   332,   236,   236,   236,
     236,   236,   320,     6,     4,   172,   173,   320,     6,     6,
       6,     7,   336,   338,     6,   233,   266,   265,   265,     6,
     252,   231,   231,   235,   262,     6,   326,   237,   339,   234,
     236,   236,   236,   236,   232,   320,   320,   320,   320,     6,
       6,   245,   326,   237,     6,   320,   235,   320,   340,   266,
     235,   332,   340,   234,   240,     6,     6,     6,   235,   235,
     121,   287,   287,   332,     6,   235,   235,     6,     6,   332,
     175,   286,   235,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   236,   266,   266,   266,   266,   266,   240,
     240,   240,   232,   266,   266,   277,   266,   240,   240,   240,
     240,   232,   266,   232,     6,     4,   266,     6,   236,   332,
     332,   332,     4,     6,   332,   332,   332,   332,   332,   332,
     332,   235,   235,     7,     6,     7,   320,   320,   320,   235,
     235,   235,   233,     6,   320,   332,   320,     6,     6,   320,
     329,   236,     5,   332,   235,   235,   235,   235,   235,   235,
     235,   332,     6,   335,   235,   320,   234,     6,     6,   171,
     320,   320,   320,     6,     6,     7,   266,   240,   240,   266,
     240,   320,     4,   187,   280,   281,   266,   232,   266,   340,
     291,     6,   291,   240,     6,     6,     7,   263,   264,   237,
       7,     6,   336,   236,   240,   320,   263,   266,   343,   343,
     231,   320,   320,   331,   332,   235,     4,     6,     6,     6,
       6,     6,     6,   232,   232,   232,   232,   339,     4,   240,
     332,   340,     7,   274,   320,   334,   278,   320,   320,   329,
       6,     6,     6,   320,   320,     6,    94,     6,   320,     5,
     235,   320,   320,   320,   320,   320,   320,   320,   264,   235,
       6,   286,     6,   320,     6,     6,     6,     6,     6,     4,
       6,     6,   335,   335,   320,   320,   340,   236,   232,   236,
     240,   290,   290,   320,   320,   236,   240,   232,   236,   240,
       6,     6,   331,   329,   329,   329,   329,   329,   222,   329,
       6,   236,   320,     6,     6,   332,   236,   240,     8,   236,
     232,   235,   320,   340,   339,   320,   339,   235,   320,   340,
     340,   240,   240,   308,   308,   332,   340,   320,     6,     4,
     337,     6,   336,   234,   332,     6,   266,   266,   249,   320,
     240,   240,   236,   240,   250,   320,     6,   320,   270,   272,
     235,   236,   240,     7,     7,   236,   236,   236,   236,   235,
     236,     5,   331,   266,   266,   240,   240,   240,   240,   240,
     320,     6,   235,   236,   236,   235,     6,     6,   235,   320,
     236,   236,   236,   234,     6,   332,     7,   235,   320,   236,
     240,   240,   240,   240,   240,   240,     6,   236,   170,   320,
     320,   335,     6,     6,   232,   266,   266,   343,   281,   340,
     236,   236,   236,     6,     6,     7,     6,   237,     6,     6,
       6,   232,   240,   320,   320,   235,   332,   236,   240,   240,
     275,   279,   332,   320,   340,   345,     6,     6,     6,     6,
     320,     6,     6,   236,   320,   320,   320,   320,   320,   236,
     331,   131,   132,   137,   315,   131,   132,   315,   335,   290,
     236,   240,     6,   236,   332,   291,   236,     6,   335,   329,
     329,   329,   329,   329,   320,   236,   236,   236,   236,   232,
     235,     6,   336,   173,   253,   320,   240,   240,   331,     6,
     320,   320,   236,   236,   271,     7,   231,   236,   235,   240,
     240,   240,   240,   240,   236,   235,   329,   332,     6,   235,
     329,     6,   236,   236,   320,     6,   127,   236,   302,   235,
     236,   240,   240,   240,   240,   240,     6,     6,     6,   291,
       6,   235,   320,   320,   236,   240,   275,   340,   232,   320,
     320,   320,   320,   320,   320,     6,   329,     6,   329,     6,
       6,   236,   320,   305,   291,     6,   335,   335,   335,   335,
     329,   335,   308,   250,   232,   240,     6,   235,   320,   236,
     240,   240,   240,   240,   240,   240,   240,   240,     6,   236,
     236,   303,   236,   236,   236,   236,   240,   236,   236,   236,
     256,   320,   331,   236,   320,   320,   320,   320,   320,   320,
     329,   329,   305,     6,     6,     6,     6,   335,     6,     6,
       6,   235,   232,   236,     6,   236,   266,   240,   240,   240,
     240,   240,   240,   236,   236,   254,   339,   259,   235,     6,
     320,   320,   320,   320,   320,   320,     6,   236,   240,   235,
     331,   236,   236,   236,   236,   236,   236,     6,   339,   257,
     339,   236,     6,     6,   236,   240,     6,     6,   339
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
    { init_Options(); ;}
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
    { init_Options(); ;}
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
    { init_Options(); ;}
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
#line 2848 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 233:
#line 2855 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 234:
#line 2867 "Gmsh.y"
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

  case 235:
#line 2886 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 236:
#line 2892 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 237:
#line 2898 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 238:
#line 2905 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 239:
#line 2912 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 240:
#line 2919 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 241:
#line 2931 "Gmsh.y"
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

  case 242:
#line 3004 "Gmsh.y"
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

  case 243:
#line 3022 "Gmsh.y"
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

  case 244:
#line 3039 "Gmsh.y"
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

  case 245:
#line 3054 "Gmsh.y"
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

  case 246:
#line 3087 "Gmsh.y"
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

  case 247:
#line 3099 "Gmsh.y"
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

  case 248:
#line 3123 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 249:
#line 3127 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 250:
#line 3132 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 251:
#line 3139 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 252:
#line 3144 "Gmsh.y"
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

  case 253:
#line 3154 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 254:
#line 3159 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 255:
#line 3165 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 256:
#line 3173 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 257:
#line 3177 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 258:
#line 3181 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 259:
#line 3191 "Gmsh.y"
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

  case 260:
#line 3254 "Gmsh.y"
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

  case 261:
#line 3270 "Gmsh.y"
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

  case 262:
#line 3287 "Gmsh.y"
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

  case 263:
#line 3304 "Gmsh.y"
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

  case 264:
#line 3326 "Gmsh.y"
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

  case 265:
#line 3348 "Gmsh.y"
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

  case 266:
#line 3383 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 267:
#line 3391 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 268:
#line 3399 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 269:
#line 3405 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 270:
#line 3412 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 271:
#line 3419 "Gmsh.y"
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

  case 272:
#line 3439 "Gmsh.y"
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

  case 273:
#line 3465 "Gmsh.y"
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

  case 274:
#line 3477 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 275:
#line 3489 "Gmsh.y"
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

  case 276:
#line 3505 "Gmsh.y"
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

  case 277:
#line 3521 "Gmsh.y"
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

  case 278:
#line 3537 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 279:
#line 3543 "Gmsh.y"
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

  case 280:
#line 3559 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 281:
#line 3565 "Gmsh.y"
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

  case 282:
#line 3583 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 283:
#line 3589 "Gmsh.y"
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

  case 284:
#line 3605 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 285:
#line 3611 "Gmsh.y"
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

  case 286:
#line 3626 "Gmsh.y"
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

  case 287:
#line 3640 "Gmsh.y"
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

  case 288:
#line 3655 "Gmsh.y"
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

  case 289:
#line 3670 "Gmsh.y"
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

  case 290:
#line 3691 "Gmsh.y"
    {
    ;}
    break;

  case 291:
#line 3694 "Gmsh.y"
    {
    ;}
    break;

  case 292:
#line 3700 "Gmsh.y"
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

  case 293:
#line 3712 "Gmsh.y"
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

  case 294:
#line 3732 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 295:
#line 3736 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 296:
#line 3740 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 297:
#line 3744 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 298:
#line 3748 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 299:
#line 3752 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 300:
#line 3756 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 301:
#line 3760 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 302:
#line 3769 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 303:
#line 3781 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 304:
#line 3782 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 305:
#line 3783 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 306:
#line 3784 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 307:
#line 3785 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 308:
#line 3789 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 309:
#line 3790 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 310:
#line 3791 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 311:
#line 3792 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 312:
#line 3793 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 313:
#line 3798 "Gmsh.y"
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

  case 314:
#line 3818 "Gmsh.y"
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

  case 315:
#line 3836 "Gmsh.y"
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

  case 316:
#line 3854 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 317:
#line 3858 "Gmsh.y"
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

  case 318:
#line 3873 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 319:
#line 3877 "Gmsh.y"
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

  case 320:
#line 3893 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 321:
#line 3897 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 322:
#line 3902 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 323:
#line 3906 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 324:
#line 3912 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 325:
#line 3916 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 326:
#line 3923 "Gmsh.y"
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

  case 327:
#line 3940 "Gmsh.y"
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

  case 328:
#line 3981 "Gmsh.y"
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

  case 329:
#line 4025 "Gmsh.y"
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

  case 330:
#line 4064 "Gmsh.y"
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

  case 331:
#line 4089 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 332:
#line 4098 "Gmsh.y"
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

  case 333:
#line 4128 "Gmsh.y"
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

  case 334:
#line 4154 "Gmsh.y"
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

  case 335:
#line 4181 "Gmsh.y"
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

  case 336:
#line 4213 "Gmsh.y"
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

  case 337:
#line 4240 "Gmsh.y"
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

  case 338:
#line 4266 "Gmsh.y"
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

  case 339:
#line 4292 "Gmsh.y"
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

  case 340:
#line 4318 "Gmsh.y"
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

  case 341:
#line 4344 "Gmsh.y"
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

  case 342:
#line 4365 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 343:
#line 4371 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 344:
#line 4377 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 345:
#line 4383 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 346:
#line 4389 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 347:
#line 4395 "Gmsh.y"
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

  case 348:
#line 4421 "Gmsh.y"
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

  case 349:
#line 4447 "Gmsh.y"
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

  case 350:
#line 4464 "Gmsh.y"
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

  case 351:
#line 4481 "Gmsh.y"
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

  case 352:
#line 4498 "Gmsh.y"
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

  case 353:
#line 4510 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 354:
#line 4516 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 355:
#line 4522 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 356:
#line 4534 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 357:
#line 4538 "Gmsh.y"
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

  case 358:
#line 4548 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 359:
#line 4558 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 360:
#line 4559 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 361:
#line 4560 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 362:
#line 4565 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 363:
#line 4571 "Gmsh.y"
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
#line 4583 "Gmsh.y"
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
#line 4601 "Gmsh.y"
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
#line 4628 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 367:
#line 4629 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 368:
#line 4630 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 369:
#line 4631 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 370:
#line 4632 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 371:
#line 4633 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 372:
#line 4634 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 373:
#line 4635 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 374:
#line 4637 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 375:
#line 4643 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 376:
#line 4644 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 377:
#line 4645 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 378:
#line 4646 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 379:
#line 4647 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 380:
#line 4648 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 381:
#line 4649 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 382:
#line 4650 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 383:
#line 4651 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 384:
#line 4652 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4653 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 386:
#line 4654 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 387:
#line 4655 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 388:
#line 4656 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 389:
#line 4657 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 390:
#line 4658 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 391:
#line 4659 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 392:
#line 4660 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 393:
#line 4661 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 394:
#line 4662 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 395:
#line 4663 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 396:
#line 4664 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 397:
#line 4665 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 398:
#line 4666 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4667 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 400:
#line 4668 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4669 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 402:
#line 4670 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 403:
#line 4671 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 4672 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 405:
#line 4673 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 406:
#line 4674 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 407:
#line 4675 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 408:
#line 4676 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 409:
#line 4685 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 410:
#line 4686 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 411:
#line 4687 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 412:
#line 4688 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 413:
#line 4689 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 414:
#line 4690 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 415:
#line 4691 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 416:
#line 4692 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 417:
#line 4693 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 418:
#line 4694 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 419:
#line 4695 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 420:
#line 4700 "Gmsh.y"
    { init_Options(); ;}
    break;

  case 421:
#line 4702 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 422:
#line 4708 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 423:
#line 4710 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 424:
#line 4715 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 425:
#line 4721 "Gmsh.y"
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

  case 426:
#line 4741 "Gmsh.y"
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

  case 427:
#line 4759 "Gmsh.y"
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
#line 4777 "Gmsh.y"
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

  case 429:
#line 4789 "Gmsh.y"
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

  case 430:
#line 4799 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 431:
#line 4805 "Gmsh.y"
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

  case 432:
#line 4821 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 433:
#line 4827 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 434:
#line 4833 "Gmsh.y"
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

  case 435:
#line 4852 "Gmsh.y"
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

  case 436:
#line 4873 "Gmsh.y"
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
#line 4906 "Gmsh.y"
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

  case 438:
#line 4928 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 439:
#line 4933 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 440:
#line 4938 "Gmsh.y"
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

  case 441:
#line 4948 "Gmsh.y"
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

  case 442:
#line 4958 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 443:
#line 4963 "Gmsh.y"
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

  case 444:
#line 4974 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 445:
#line 4983 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 446:
#line 4988 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 447:
#line 4993 "Gmsh.y"
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

  case 448:
#line 5021 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_Options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 449:
#line 5028 "Gmsh.y"
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

  case 450:
#line 5044 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 451:
#line 5046 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 452:
#line 5051 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 453:
#line 5060 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 454:
#line 5062 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 455:
#line 5067 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 456:
#line 5069 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 457:
#line 5075 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 458:
#line 5079 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 459:
#line 5083 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 460:
#line 5087 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 461:
#line 5091 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 462:
#line 5098 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 463:
#line 5102 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 464:
#line 5106 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 465:
#line 5110 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 466:
#line 5117 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 467:
#line 5122 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 468:
#line 5129 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 469:
#line 5134 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 470:
#line 5138 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 471:
#line 5143 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 472:
#line 5147 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 473:
#line 5155 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 474:
#line 5166 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 475:
#line 5170 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 476:
#line 5182 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 477:
#line 5190 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 478:
#line 5198 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 479:
#line 5205 "Gmsh.y"
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

  case 480:
#line 5215 "Gmsh.y"
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

  case 481:
#line 5238 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 482:
#line 5244 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 483:
#line 5250 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 484:
#line 5256 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 485:
#line 5262 "Gmsh.y"
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

  case 486:
#line 5273 "Gmsh.y"
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

  case 487:
#line 5284 "Gmsh.y"
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

  case 488:
#line 5295 "Gmsh.y"
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

  case 489:
#line 5307 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 490:
#line 5313 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 491:
#line 5319 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 492:
#line 5325 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 493:
#line 5330 "Gmsh.y"
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

  case 494:
#line 5340 "Gmsh.y"
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
#line 5350 "Gmsh.y"
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
#line 5360 "Gmsh.y"
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

  case 497:
#line 5373 "Gmsh.y"
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

  case 498:
#line 5385 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
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
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 501:
#line 5397 "Gmsh.y"
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

  case 502:
#line 5415 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 503:
#line 5423 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 504:
#line 5431 "Gmsh.y"
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

  case 505:
#line 5460 "Gmsh.y"
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

  case 506:
#line 5470 "Gmsh.y"
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

  case 507:
#line 5486 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 508:
#line 5497 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 509:
#line 5502 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 510:
#line 5506 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 511:
#line 5510 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 512:
#line 5522 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 513:
#line 5526 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 514:
#line 5538 "Gmsh.y"
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

  case 515:
#line 5555 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 516:
#line 5565 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 517:
#line 5569 "Gmsh.y"
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

  case 518:
#line 5584 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 519:
#line 5589 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 520:
#line 5596 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 521:
#line 5600 "Gmsh.y"
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

  case 522:
#line 5613 "Gmsh.y"
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

  case 523:
#line 5627 "Gmsh.y"
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
#line 5644 "Gmsh.y"
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

  case 525:
#line 5672 "Gmsh.y"
    { (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 526:
#line 5676 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 527:
#line 5684 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 528:
#line 5690 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 529:
#line 5696 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 530:
#line 5702 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 531:
#line 5711 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 532:
#line 5715 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 533:
#line 5719 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 534:
#line 5727 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 535:
#line 5733 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 536:
#line 5739 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 537:
#line 5743 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 538:
#line 5751 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 539:
#line 5759 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 540:
#line 5766 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 541:
#line 5774 "Gmsh.y"
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

  case 542:
#line 5789 "Gmsh.y"
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

  case 543:
#line 5803 "Gmsh.y"
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

  case 544:
#line 5817 "Gmsh.y"
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

  case 545:
#line 5829 "Gmsh.y"
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

  case 546:
#line 5845 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 547:
#line 5854 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 548:
#line 5863 "Gmsh.y"
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

  case 549:
#line 5873 "Gmsh.y"
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

  case 550:
#line 5884 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 551:
#line 5892 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 552:
#line 5900 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 553:
#line 5904 "Gmsh.y"
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

  case 554:
#line 5923 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 555:
#line 5930 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 556:
#line 5936 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 557:
#line 5943 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 558:
#line 5950 "Gmsh.y"
    { init_Options(); ;}
    break;

  case 559:
#line 5952 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 560:
#line 5960 "Gmsh.y"
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

  case 561:
#line 5984 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 562:
#line 5986 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 563:
#line 5992 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 564:
#line 5997 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 565:
#line 6005 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 566:
#line 6014 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 567:
#line 6027 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 568:
#line 6030 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 569:
#line 6034 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 12998 "Gmsh.tab.cpp"
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


#line 6037 "Gmsh.y"


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

