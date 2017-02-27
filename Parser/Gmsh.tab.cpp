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
     tFloor = 287,
     tCeil = 288,
     tRound = 289,
     tFmod = 290,
     tModulo = 291,
     tHypot = 292,
     tList = 293,
     tLinSpace = 294,
     tLogSpace = 295,
     tListFromFile = 296,
     tCatenary = 297,
     tPrintf = 298,
     tError = 299,
     tStr = 300,
     tSprintf = 301,
     tStrCat = 302,
     tStrPrefix = 303,
     tStrRelative = 304,
     tStrReplace = 305,
     tAbsolutePath = 306,
     tDirName = 307,
     tStrSub = 308,
     tStrLen = 309,
     tFind = 310,
     tStrFind = 311,
     tStrCmp = 312,
     tStrChoice = 313,
     tUpperCase = 314,
     tLowerCase = 315,
     tLowerCaseIn = 316,
     tTextAttributes = 317,
     tBoundingBox = 318,
     tDraw = 319,
     tSetChanged = 320,
     tToday = 321,
     tFixRelativePath = 322,
     tCurrentDirectory = 323,
     tSyncModel = 324,
     tNewModel = 325,
     tOnelabAction = 326,
     tOnelabRun = 327,
     tCpu = 328,
     tMemory = 329,
     tTotalMemory = 330,
     tCreateTopology = 331,
     tCreateTopologyNoHoles = 332,
     tDistanceFunction = 333,
     tDefineConstant = 334,
     tUndefineConstant = 335,
     tDefineNumber = 336,
     tDefineStruct = 337,
     tNameStruct = 338,
     tAppend = 339,
     tDefineString = 340,
     tSetNumber = 341,
     tSetString = 342,
     tPoint = 343,
     tCircle = 344,
     tEllipse = 345,
     tLine = 346,
     tSphere = 347,
     tPolarSphere = 348,
     tSurface = 349,
     tSpline = 350,
     tVolume = 351,
     tBlock = 352,
     tCylinder = 353,
     tCone = 354,
     tTorus = 355,
     tEllipsoid = 356,
     tQuadric = 357,
     tShapeFromFile = 358,
     tRectangle = 359,
     tDisk = 360,
     tWire = 361,
     tCharacteristic = 362,
     tLength = 363,
     tParametric = 364,
     tElliptic = 365,
     tRefineMesh = 366,
     tAdaptMesh = 367,
     tRelocateMesh = 368,
     tSetFactory = 369,
     tThruSections = 370,
     tWedge = 371,
     tFillet = 372,
     tChamfer = 373,
     tPlane = 374,
     tRuled = 375,
     tTransfinite = 376,
     tPhysical = 377,
     tCompound = 378,
     tPeriodic = 379,
     tUsing = 380,
     tPlugin = 381,
     tDegenerated = 382,
     tRecursive = 383,
     tRotate = 384,
     tTranslate = 385,
     tSymmetry = 386,
     tDilate = 387,
     tExtrude = 388,
     tLevelset = 389,
     tAffine = 390,
     tBooleanUnion = 391,
     tBooleanIntersection = 392,
     tBooleanDifference = 393,
     tBooleanSection = 394,
     tBooleanFragments = 395,
     tThickSolid = 396,
     tRecombine = 397,
     tSmoother = 398,
     tSplit = 399,
     tDelete = 400,
     tCoherence = 401,
     tIntersect = 402,
     tMeshAlgorithm = 403,
     tReverse = 404,
     tLayers = 405,
     tScaleLast = 406,
     tHole = 407,
     tAlias = 408,
     tAliasWithOptions = 409,
     tCopyOptions = 410,
     tQuadTriAddVerts = 411,
     tQuadTriNoNewVerts = 412,
     tRecombLaterals = 413,
     tTransfQuadTri = 414,
     tText2D = 415,
     tText3D = 416,
     tInterpolationScheme = 417,
     tTime = 418,
     tCombine = 419,
     tBSpline = 420,
     tBezier = 421,
     tNurbs = 422,
     tNurbsOrder = 423,
     tNurbsKnots = 424,
     tColor = 425,
     tColorTable = 426,
     tFor = 427,
     tIn = 428,
     tEndFor = 429,
     tIf = 430,
     tElseIf = 431,
     tElse = 432,
     tEndIf = 433,
     tExit = 434,
     tAbort = 435,
     tField = 436,
     tReturn = 437,
     tCall = 438,
     tSlide = 439,
     tMacro = 440,
     tShow = 441,
     tHide = 442,
     tGetValue = 443,
     tGetStringValue = 444,
     tGetEnv = 445,
     tGetString = 446,
     tGetNumber = 447,
     tUnique = 448,
     tHomology = 449,
     tCohomology = 450,
     tBetti = 451,
     tExists = 452,
     tFileExists = 453,
     tGMSH_MAJOR_VERSION = 454,
     tGMSH_MINOR_VERSION = 455,
     tGMSH_PATCH_VERSION = 456,
     tGmshExecutableName = 457,
     tSetPartition = 458,
     tNameToString = 459,
     tStringToName = 460,
     tAFFECTDIVIDE = 461,
     tAFFECTTIMES = 462,
     tAFFECTMINUS = 463,
     tAFFECTPLUS = 464,
     tOR = 465,
     tAND = 466,
     tNOTEQUAL = 467,
     tEQUAL = 468,
     tGREATEROREQUAL = 469,
     tLESSOREQUAL = 470,
     UNARYPREC = 471,
     tMINUSMINUS = 472,
     tPLUSPLUS = 473
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
#define tFloor 287
#define tCeil 288
#define tRound 289
#define tFmod 290
#define tModulo 291
#define tHypot 292
#define tList 293
#define tLinSpace 294
#define tLogSpace 295
#define tListFromFile 296
#define tCatenary 297
#define tPrintf 298
#define tError 299
#define tStr 300
#define tSprintf 301
#define tStrCat 302
#define tStrPrefix 303
#define tStrRelative 304
#define tStrReplace 305
#define tAbsolutePath 306
#define tDirName 307
#define tStrSub 308
#define tStrLen 309
#define tFind 310
#define tStrFind 311
#define tStrCmp 312
#define tStrChoice 313
#define tUpperCase 314
#define tLowerCase 315
#define tLowerCaseIn 316
#define tTextAttributes 317
#define tBoundingBox 318
#define tDraw 319
#define tSetChanged 320
#define tToday 321
#define tFixRelativePath 322
#define tCurrentDirectory 323
#define tSyncModel 324
#define tNewModel 325
#define tOnelabAction 326
#define tOnelabRun 327
#define tCpu 328
#define tMemory 329
#define tTotalMemory 330
#define tCreateTopology 331
#define tCreateTopologyNoHoles 332
#define tDistanceFunction 333
#define tDefineConstant 334
#define tUndefineConstant 335
#define tDefineNumber 336
#define tDefineStruct 337
#define tNameStruct 338
#define tAppend 339
#define tDefineString 340
#define tSetNumber 341
#define tSetString 342
#define tPoint 343
#define tCircle 344
#define tEllipse 345
#define tLine 346
#define tSphere 347
#define tPolarSphere 348
#define tSurface 349
#define tSpline 350
#define tVolume 351
#define tBlock 352
#define tCylinder 353
#define tCone 354
#define tTorus 355
#define tEllipsoid 356
#define tQuadric 357
#define tShapeFromFile 358
#define tRectangle 359
#define tDisk 360
#define tWire 361
#define tCharacteristic 362
#define tLength 363
#define tParametric 364
#define tElliptic 365
#define tRefineMesh 366
#define tAdaptMesh 367
#define tRelocateMesh 368
#define tSetFactory 369
#define tThruSections 370
#define tWedge 371
#define tFillet 372
#define tChamfer 373
#define tPlane 374
#define tRuled 375
#define tTransfinite 376
#define tPhysical 377
#define tCompound 378
#define tPeriodic 379
#define tUsing 380
#define tPlugin 381
#define tDegenerated 382
#define tRecursive 383
#define tRotate 384
#define tTranslate 385
#define tSymmetry 386
#define tDilate 387
#define tExtrude 388
#define tLevelset 389
#define tAffine 390
#define tBooleanUnion 391
#define tBooleanIntersection 392
#define tBooleanDifference 393
#define tBooleanSection 394
#define tBooleanFragments 395
#define tThickSolid 396
#define tRecombine 397
#define tSmoother 398
#define tSplit 399
#define tDelete 400
#define tCoherence 401
#define tIntersect 402
#define tMeshAlgorithm 403
#define tReverse 404
#define tLayers 405
#define tScaleLast 406
#define tHole 407
#define tAlias 408
#define tAliasWithOptions 409
#define tCopyOptions 410
#define tQuadTriAddVerts 411
#define tQuadTriNoNewVerts 412
#define tRecombLaterals 413
#define tTransfQuadTri 414
#define tText2D 415
#define tText3D 416
#define tInterpolationScheme 417
#define tTime 418
#define tCombine 419
#define tBSpline 420
#define tBezier 421
#define tNurbs 422
#define tNurbsOrder 423
#define tNurbsKnots 424
#define tColor 425
#define tColorTable 426
#define tFor 427
#define tIn 428
#define tEndFor 429
#define tIf 430
#define tElseIf 431
#define tElse 432
#define tEndIf 433
#define tExit 434
#define tAbort 435
#define tField 436
#define tReturn 437
#define tCall 438
#define tSlide 439
#define tMacro 440
#define tShow 441
#define tHide 442
#define tGetValue 443
#define tGetStringValue 444
#define tGetEnv 445
#define tGetString 446
#define tGetNumber 447
#define tUnique 448
#define tHomology 449
#define tCohomology 450
#define tBetti 451
#define tExists 452
#define tFileExists 453
#define tGMSH_MAJOR_VERSION 454
#define tGMSH_MINOR_VERSION 455
#define tGMSH_PATCH_VERSION 456
#define tGmshExecutableName 457
#define tSetPartition 458
#define tNameToString 459
#define tStringToName 460
#define tAFFECTDIVIDE 461
#define tAFFECTTIMES 462
#define tAFFECTMINUS 463
#define tAFFECTPLUS 464
#define tOR 465
#define tAND 466
#define tNOTEQUAL 467
#define tEQUAL 468
#define tGREATEROREQUAL 469
#define tLESSOREQUAL 470
#define UNARYPREC 471
#define tMINUSMINUS 472
#define tPLUSPLUS 473




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
#include "Geo.h" // FIXME: remove once Extrusion has been refactored
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

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

// Static parser variables (accessible only in this file)
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
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static std::string factory;
static NameSpaces nameSpaces;
static std::string struct_name, struct_namespace;
static int flag_tSTRING_alloc = 0;

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
void ListOfShapes2Vectors(List_T *list, std::vector<int> v[4]);
void Vectors2ListOfShapes(std::vector<int> tags[4], List_T *list);
void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int,int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&, std::vector<double>&);
void addEmbedded(int dim, std::vector<int> tags, int dim2, int tag2);
void getAllElementaryTags(int dim, List_T *in);
void getAllPhysicalTags(int dim, List_T *in);
void getElementaryTagsForPhysicalGroups(int dim, List_T *in, List_T *out);
void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out);
void setVisibility(int dim, int visible, bool recursive);
void setVisibility(std::vector<int> tags[4], int visible, bool recursive);
void setColor(std::vector<int> tags[4], unsigned int val, bool recursive);

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
#line 136 "Gmsh.y"
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
#line 686 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 699 "Gmsh.tab.cpp"

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
#define YYLAST   13367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  556
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2074

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   473

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   224,     2,   236,     2,   223,     2,     2,
     229,   230,   221,   219,   238,   220,   235,   222,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     215,     2,   216,   210,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   231,     2,   232,   228,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   234,   237,     2,     2,     2,
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
     205,   206,   207,   208,   209,   211,   212,   213,   214,   217,
     218,   225,   226,   227
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
     312,   316,   323,   331,   338,   348,   355,   363,   370,   375,
     384,   394,   404,   411,   421,   428,   438,   444,   453,   462,
     474,   481,   491,   497,   505,   515,   525,   537,   545,   555,
     565,   566,   568,   569,   573,   579,   580,   590,   591,   603,
     604,   616,   622,   623,   633,   634,   638,   642,   648,   654,
     655,   658,   662,   668,   672,   673,   676,   680,   684,   688,
     694,   696,   698,   702,   704,   706,   710,   712,   714,   718,
     720,   722,   726,   727,   733,   734,   737,   745,   753,   761,
     770,   779,   787,   795,   807,   816,   824,   833,   842,   851,
     861,   865,   870,   881,   889,   897,   905,   913,   921,   929,
     937,   945,   953,   961,   970,   983,   992,  1000,  1008,  1017,
    1026,  1035,  1044,  1053,  1062,  1068,  1080,  1086,  1096,  1106,
    1111,  1121,  1131,  1133,  1135,  1136,  1139,  1146,  1153,  1160,
    1167,  1176,  1187,  1202,  1219,  1232,  1247,  1262,  1277,  1292,
    1301,  1310,  1317,  1322,  1329,  1336,  1340,  1345,  1351,  1358,
    1364,  1368,  1372,  1377,  1383,  1388,  1394,  1398,  1404,  1412,
    1420,  1424,  1432,  1436,  1439,  1442,  1445,  1448,  1451,  1467,
    1470,  1473,  1476,  1479,  1482,  1499,  1511,  1518,  1527,  1536,
    1547,  1549,  1552,  1555,  1557,  1561,  1565,  1570,  1575,  1577,
    1579,  1585,  1597,  1611,  1612,  1620,  1621,  1635,  1636,  1652,
    1653,  1660,  1670,  1673,  1677,  1688,  1690,  1693,  1699,  1707,
    1710,  1713,  1717,  1720,  1724,  1727,  1731,  1741,  1748,  1750,
    1752,  1754,  1756,  1758,  1759,  1762,  1766,  1776,  1781,  1796,
    1797,  1801,  1802,  1804,  1805,  1808,  1809,  1812,  1813,  1816,
    1823,  1831,  1838,  1844,  1848,  1857,  1863,  1868,  1875,  1887,
    1899,  1918,  1937,  1950,  1963,  1976,  1987,  1998,  2009,  2020,
    2031,  2036,  2041,  2046,  2051,  2056,  2061,  2066,  2071,  2076,
    2079,  2083,  2090,  2092,  2094,  2096,  2099,  2105,  2113,  2124,
    2126,  2130,  2133,  2136,  2139,  2143,  2147,  2151,  2155,  2159,
    2163,  2167,  2171,  2175,  2179,  2183,  2187,  2191,  2195,  2201,
    2206,  2211,  2216,  2221,  2226,  2231,  2236,  2241,  2246,  2251,
    2258,  2263,  2268,  2273,  2278,  2283,  2288,  2293,  2300,  2307,
    2314,  2319,  2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,
    2337,  2339,  2341,  2342,  2349,  2351,  2356,  2363,  2365,  2370,
    2375,  2380,  2385,  2390,  2393,  2399,  2405,  2409,  2415,  2422,
    2427,  2435,  2442,  2449,  2456,  2461,  2468,  2473,  2474,  2483,
    2485,  2489,  2491,  2493,  2496,  2497,  2501,  2503,  2506,  2509,
    2513,  2517,  2529,  2539,  2547,  2555,  2557,  2561,  2563,  2565,
    2568,  2572,  2577,  2583,  2585,  2587,  2590,  2594,  2598,  2604,
    2609,  2612,  2615,  2618,  2621,  2625,  2629,  2633,  2637,  2654,
    2671,  2688,  2705,  2707,  2709,  2711,  2715,  2720,  2725,  2730,
    2737,  2744,  2753,  2762,  2767,  2782,  2787,  2789,  2791,  2795,
    2799,  2809,  2817,  2819,  2825,  2829,  2836,  2838,  2842,  2844,
    2846,  2851,  2856,  2860,  2866,  2873,  2879,  2885,  2891,  2897,
    2899,  2904,  2906,  2908,  2910,  2915,  2922,  2927,  2934,  2939,
    2944,  2949,  2958,  2963,  2968,  2973,  2978,  2987,  2996,  3003,
    3008,  3015,  3020,  3022,  3027,  3032,  3033,  3040,  3045,  3048,
    3053,  3055,  3059,  3065,  3071,  3073,  3075
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     240,     0,    -1,   241,    -1,     1,     6,    -1,    -1,   241,
     242,    -1,   244,    -1,   245,    -1,   265,    -1,   114,   229,
     335,   230,     6,    -1,   284,    -1,   285,    -1,   289,    -1,
     290,    -1,   291,    -1,   292,    -1,   296,    -1,   305,    -1,
     306,    -1,   312,    -1,   313,    -1,   295,    -1,   294,    -1,
     293,    -1,   288,    -1,   315,    -1,   216,    -1,   216,   216,
      -1,    43,   229,   335,   230,     6,    -1,    44,   229,   335,
     230,     6,    -1,    43,   229,   335,   230,   243,   335,     6,
      -1,    43,   229,   335,   238,   331,   230,     6,    -1,    44,
     229,   335,   238,   331,   230,     6,    -1,    43,   229,   335,
     238,   331,   230,   243,   335,     6,    -1,   341,   335,   233,
     246,   234,     6,    -1,   153,     4,   231,   316,   232,     6,
      -1,   154,     4,   231,   316,   232,     6,    -1,   155,     4,
     231,   316,   238,   316,   232,     6,    -1,    -1,   246,   249,
      -1,   246,   253,    -1,   246,   256,    -1,   246,   258,    -1,
     246,   259,    -1,   316,    -1,   247,   238,   316,    -1,   316,
      -1,   248,   238,   316,    -1,    -1,    -1,     4,   250,   229,
     247,   230,   251,   233,   248,   234,     6,    -1,   335,    -1,
     252,   238,   335,    -1,    -1,   160,   229,   316,   238,   316,
     238,   316,   230,   254,   233,   252,   234,     6,    -1,   335,
      -1,   255,   238,   335,    -1,    -1,   161,   229,   316,   238,
     316,   238,   316,   238,   316,   230,   257,   233,   255,   234,
       6,    -1,   162,   233,   327,   234,   233,   327,   234,     6,
      -1,   162,   233,   327,   234,   233,   327,   234,   233,   327,
     234,   233,   327,   234,     6,    -1,    -1,   163,   260,   233,
     248,   234,     6,    -1,     7,    -1,   209,    -1,   208,    -1,
     207,    -1,   206,    -1,   227,    -1,   226,    -1,   229,    -1,
     231,    -1,   230,    -1,   232,    -1,    79,   231,   267,   232,
       6,    -1,    80,   231,   272,   232,     6,    -1,   319,     6,
      -1,    86,   263,   336,   238,   316,   264,     6,    -1,    87,
     263,   341,   238,   336,   264,     6,    -1,   341,   261,   328,
       6,    -1,   341,   262,     6,    -1,   341,   231,   232,   261,
     328,     6,    -1,   341,   231,   316,   232,   261,   316,     6,
      -1,   341,   231,   316,   232,   262,     6,    -1,   341,   263,
     233,   331,   234,   264,   261,   328,     6,    -1,   341,   229,
     230,   261,   328,     6,    -1,   341,   229,   316,   230,   261,
     316,     6,    -1,   341,   229,   316,   230,   262,     6,    -1,
     341,     7,   336,     6,    -1,   341,   263,   264,     7,    45,
     263,   264,     6,    -1,   341,   231,   232,     7,    45,   263,
     339,   264,     6,    -1,   341,   231,   232,   209,    45,   263,
     339,   264,     6,    -1,   341,   235,     4,     7,   336,     6,
      -1,   341,   231,   316,   232,   235,     4,     7,   336,     6,
      -1,   341,   235,     4,   261,   316,     6,    -1,   341,   231,
     316,   232,   235,     4,   261,   316,     6,    -1,   341,   235,
       4,   262,     6,    -1,   341,   231,   316,   232,   235,     4,
     262,     6,    -1,   341,   235,   170,   235,     4,     7,   332,
       6,    -1,   341,   231,   316,   232,   235,   170,   235,     4,
       7,   332,     6,    -1,   341,   235,   171,     7,   333,     6,
      -1,   341,   231,   316,   232,   235,   171,     7,   333,     6,
      -1,   341,   181,     7,   316,     6,    -1,   181,   231,   316,
     232,     7,     4,     6,    -1,   181,   231,   316,   232,   235,
       4,     7,   316,     6,    -1,   181,   231,   316,   232,   235,
       4,     7,   336,     6,    -1,   181,   231,   316,   232,   235,
       4,     7,   233,   331,   234,     6,    -1,   181,   231,   316,
     232,   235,     4,     6,    -1,   126,   229,     4,   230,   235,
       4,     7,   316,     6,    -1,   126,   229,     4,   230,   235,
       4,     7,   336,     6,    -1,    -1,   238,    -1,    -1,   267,
     266,   341,    -1,   267,   266,   341,     7,   316,    -1,    -1,
     267,   266,   341,     7,   233,   328,   268,   274,   234,    -1,
      -1,   267,   266,   341,   231,   232,     7,   233,   328,   269,
     274,   234,    -1,    -1,   267,   266,   341,   229,   230,     7,
     233,   328,   270,   274,   234,    -1,   267,   266,   341,     7,
     336,    -1,    -1,   267,   266,   341,     7,   233,   336,   271,
     276,   234,    -1,    -1,   272,   266,   335,    -1,   316,     7,
     336,    -1,   273,   238,   316,     7,   336,    -1,   330,     7,
     341,   229,   230,    -1,    -1,   274,   275,    -1,   238,     4,
     328,    -1,   238,     4,   233,   273,   234,    -1,   238,     4,
     336,    -1,    -1,   276,   277,    -1,   238,     4,   316,    -1,
     238,     4,   336,    -1,   238,   185,   336,    -1,   238,     4,
     233,   339,   234,    -1,   316,    -1,   336,    -1,   336,   238,
     316,    -1,   316,    -1,   336,    -1,   336,   238,   316,    -1,
     316,    -1,   336,    -1,   336,   238,   316,    -1,   316,    -1,
     336,    -1,   336,   238,   316,    -1,    -1,   173,    92,   233,
     316,   234,    -1,    -1,   119,   325,    -1,    88,   229,   316,
     230,     7,   325,     6,    -1,    91,   229,   316,   230,     7,
     328,     6,    -1,    95,   229,   316,   230,     7,   328,     6,
      -1,    89,   229,   316,   230,     7,   328,   283,     6,    -1,
      90,   229,   316,   230,     7,   328,   283,     6,    -1,   165,
     229,   316,   230,     7,   328,     6,    -1,   166,   229,   316,
     230,     7,   328,     6,    -1,   167,   229,   316,   230,     7,
     328,   169,   328,   168,   316,     6,    -1,   123,    91,   229,
     316,   230,     7,   328,     6,    -1,   106,   229,   316,   230,
       7,   328,     6,    -1,    91,     4,   229,   316,   230,     7,
     328,     6,    -1,   119,    94,   229,   316,   230,     7,   328,
       6,    -1,    94,   229,   316,   230,     7,   328,   282,     6,
      -1,   120,    94,   229,   316,   230,     7,   328,   282,     6,
      -1,    13,    14,     6,    -1,    14,    94,   316,     6,    -1,
     109,    94,   229,   316,   230,     7,     5,     5,     5,     6,
      -1,    92,   229,   316,   230,     7,   328,     6,    -1,    93,
     229,   316,   230,     7,   328,     6,    -1,    97,   229,   316,
     230,     7,   328,     6,    -1,   100,   229,   316,   230,     7,
     328,     6,    -1,   104,   229,   316,   230,     7,   328,     6,
      -1,   105,   229,   316,   230,     7,   328,     6,    -1,    98,
     229,   316,   230,     7,   328,     6,    -1,    99,   229,   316,
     230,     7,   328,     6,    -1,   116,   229,   316,   230,     7,
     328,     6,    -1,   141,   229,   316,   230,     7,   328,     6,
      -1,   123,    94,   229,   316,   230,     7,   328,     6,    -1,
     123,    94,   229,   316,   230,     7,   328,     4,   233,   327,
     234,     6,    -1,    94,     4,   229,   316,   230,     7,   328,
       6,    -1,    96,   229,   316,   230,     7,   328,     6,    -1,
     115,   229,   316,   230,     7,   328,     6,    -1,   120,   115,
     229,   316,   230,     7,   328,     6,    -1,   123,    96,   229,
     316,   230,     7,   328,     6,    -1,   122,    88,   229,   278,
     230,   261,   328,     6,    -1,   122,    91,   229,   279,   230,
     261,   328,     6,    -1,   122,    94,   229,   280,   230,   261,
     328,     6,    -1,   122,    96,   229,   281,   230,   261,   328,
       6,    -1,   130,   325,   233,   286,   234,    -1,   129,   233,
     325,   238,   325,   238,   316,   234,   233,   286,   234,    -1,
     131,   325,   233,   286,   234,    -1,   132,   233,   325,   238,
     316,   234,   233,   286,   234,    -1,   132,   233,   325,   238,
     325,   234,   233,   286,   234,    -1,   341,   233,   286,   234,
      -1,   147,    91,   233,   331,   234,    94,   233,   316,   234,
      -1,   144,    91,   229,   316,   230,   233,   331,   234,     6,
      -1,   287,    -1,   285,    -1,    -1,   287,   284,    -1,   287,
      88,   233,   331,   234,     6,    -1,   287,    91,   233,   331,
     234,     6,    -1,   287,    94,   233,   331,   234,     6,    -1,
     287,    96,   233,   331,   234,     6,    -1,   134,   119,   229,
     316,   230,     7,   328,     6,    -1,   134,    88,   229,   316,
     230,     7,   233,   327,   234,     6,    -1,   134,   119,   229,
     316,   230,     7,   233,   325,   238,   325,   238,   331,   234,
       6,    -1,   134,   119,   229,   316,   230,     7,   233,   325,
     238,   325,   238,   325,   238,   331,   234,     6,    -1,   134,
      92,   229,   316,   230,     7,   233,   325,   238,   331,   234,
       6,    -1,   134,    98,   229,   316,   230,     7,   233,   325,
     238,   325,   238,   331,   234,     6,    -1,   134,    99,   229,
     316,   230,     7,   233,   325,   238,   325,   238,   331,   234,
       6,    -1,   134,   101,   229,   316,   230,     7,   233,   325,
     238,   325,   238,   331,   234,     6,    -1,   134,   102,   229,
     316,   230,     7,   233,   325,   238,   325,   238,   331,   234,
       6,    -1,   134,     4,   229,   316,   230,     7,   328,     6,
      -1,   134,     4,   229,   316,   230,     7,     5,     6,    -1,
     134,     4,   233,   316,   234,     6,    -1,   145,   233,   287,
     234,    -1,   145,   181,   231,   316,   232,     6,    -1,   145,
       4,   231,   316,   232,     6,    -1,   145,   341,     6,    -1,
     145,     4,     4,     6,    -1,   170,   332,   233,   287,   234,
      -1,   128,   170,   332,   233,   287,   234,    -1,   203,   316,
     233,   287,   234,    -1,   186,     5,     6,    -1,   187,     5,
       6,    -1,   186,   233,   287,   234,    -1,   128,   186,   233,
     287,   234,    -1,   187,   233,   287,   234,    -1,   128,   187,
     233,   287,   234,    -1,   341,   336,     6,    -1,    72,   229,
     339,   230,     6,    -1,   341,   341,   231,   316,   232,   335,
       6,    -1,   341,   341,   341,   231,   316,   232,     6,    -1,
     341,   316,     6,    -1,   126,   229,     4,   230,   235,     4,
       6,    -1,   164,     4,     6,    -1,   179,     6,    -1,   180,
       6,    -1,    69,     6,    -1,    70,     6,    -1,    63,     6,
      -1,    63,   233,   316,   238,   316,   238,   316,   238,   316,
     238,   316,   238,   316,   234,     6,    -1,    64,     6,    -1,
      65,     6,    -1,    76,     6,    -1,    77,     6,    -1,   111,
       6,    -1,   112,   233,   331,   234,   233,   331,   234,   233,
     327,   234,   233,   316,   238,   316,   234,     6,    -1,   184,
     229,   233,   331,   234,   238,   336,   238,   336,   230,     6,
      -1,   172,   229,   316,     8,   316,   230,    -1,   172,   229,
     316,     8,   316,     8,   316,   230,    -1,   172,     4,   173,
     233,   316,     8,   316,   234,    -1,   172,     4,   173,   233,
     316,     8,   316,     8,   316,   234,    -1,   174,    -1,   185,
       4,    -1,   185,   336,    -1,   182,    -1,   183,   341,     6,
      -1,   183,   336,     6,    -1,   175,   229,   316,   230,    -1,
     176,   229,   316,   230,    -1,   177,    -1,   178,    -1,   133,
     325,   233,   287,   234,    -1,   133,   233,   325,   238,   325,
     238,   316,   234,   233,   287,   234,    -1,   133,   233,   325,
     238,   325,   238,   325,   238,   316,   234,   233,   287,   234,
      -1,    -1,   133,   325,   233,   287,   297,   301,   234,    -1,
      -1,   133,   233,   325,   238,   325,   238,   316,   234,   233,
     287,   298,   301,   234,    -1,    -1,   133,   233,   325,   238,
     325,   238,   325,   238,   316,   234,   233,   287,   299,   301,
     234,    -1,    -1,   133,   233,   287,   300,   301,   234,    -1,
     133,   233,   287,   234,   125,   106,   233,   316,   234,    -1,
     115,   328,    -1,   120,   115,   328,    -1,   117,   233,   331,
     234,   233,   331,   234,   233,   316,   234,    -1,   302,    -1,
     301,   302,    -1,   150,   233,   316,   234,     6,    -1,   150,
     233,   328,   238,   328,   234,     6,    -1,   151,     6,    -1,
     142,     6,    -1,   142,   316,     6,    -1,   156,     6,    -1,
     156,   158,     6,    -1,   157,     6,    -1,   157,   158,     6,
      -1,   152,   229,   316,   230,     7,   328,   125,   316,     6,
      -1,   125,     4,   231,   316,   232,     6,    -1,   136,    -1,
     137,    -1,   138,    -1,   139,    -1,   140,    -1,    -1,   145,
       6,    -1,   145,   316,     6,    -1,   303,   233,   287,   304,
     234,   233,   287,   304,   234,    -1,   103,   229,   335,   230,
      -1,   303,   229,   316,   230,     7,   233,   287,   304,   234,
     233,   287,   304,   234,     6,    -1,    -1,   125,     4,   316,
      -1,    -1,     4,    -1,    -1,     7,   328,    -1,    -1,     7,
     316,    -1,    -1,   135,   328,    -1,   107,   108,   328,     7,
     316,     6,    -1,   121,    91,   329,     7,   316,   307,     6,
      -1,   121,    94,   329,   309,   308,     6,    -1,   121,    96,
     329,   309,     6,    -1,   159,   329,     6,    -1,   148,    94,
     233,   331,   234,     7,   316,     6,    -1,   142,    94,   329,
     310,     6,    -1,   142,    96,   329,     6,    -1,   143,    94,
     329,     7,   316,     6,    -1,   124,    91,   233,   331,   234,
       7,   233,   331,   234,   311,     6,    -1,   124,    94,   233,
     331,   234,     7,   233,   331,   234,   311,     6,    -1,   124,
      91,   233,   331,   234,     7,   233,   331,   234,   129,   233,
     325,   238,   325,   238,   316,   234,     6,    -1,   124,    94,
     233,   331,   234,     7,   233,   331,   234,   129,   233,   325,
     238,   325,   238,   316,   234,     6,    -1,   124,    91,   233,
     331,   234,     7,   233,   331,   234,   130,   325,     6,    -1,
     124,    94,   233,   331,   234,     7,   233,   331,   234,   130,
     325,     6,    -1,   124,    94,   316,   233,   331,   234,     7,
     316,   233,   331,   234,     6,    -1,    88,   233,   331,   234,
     173,    94,   233,   316,   234,     6,    -1,    91,   233,   331,
     234,   173,    94,   233,   316,   234,     6,    -1,    88,   233,
     331,   234,   173,    96,   233,   316,   234,     6,    -1,    91,
     233,   331,   234,   173,    96,   233,   316,   234,     6,    -1,
      94,   233,   331,   234,   173,    96,   233,   316,   234,     6,
      -1,   149,    94,   329,     6,    -1,   149,    91,   329,     6,
      -1,   113,    88,   329,     6,    -1,   113,    91,   329,     6,
      -1,   113,    94,   329,     6,    -1,   127,    91,   328,     6,
      -1,   123,    91,   328,     6,    -1,   123,    94,   328,     6,
      -1,   123,    96,   328,     6,    -1,   146,     6,    -1,   146,
       4,     6,    -1,   146,    88,   233,   331,   234,     6,    -1,
     194,    -1,   195,    -1,   196,    -1,   314,     6,    -1,   314,
     233,   328,   234,     6,    -1,   314,   233,   328,   238,   328,
     234,     6,    -1,   314,   229,   328,   230,   233,   328,   238,
     328,   234,     6,    -1,   317,    -1,   229,   316,   230,    -1,
     220,   316,    -1,   219,   316,    -1,   224,   316,    -1,   316,
     220,   316,    -1,   316,   219,   316,    -1,   316,   221,   316,
      -1,   316,   222,   316,    -1,   316,   223,   316,    -1,   316,
     228,   316,    -1,   316,   215,   316,    -1,   316,   216,   316,
      -1,   316,   218,   316,    -1,   316,   217,   316,    -1,   316,
     214,   316,    -1,   316,   213,   316,    -1,   316,   212,   316,
      -1,   316,   211,   316,    -1,   316,   210,   316,     8,   316,
      -1,    16,   263,   316,   264,    -1,    17,   263,   316,   264,
      -1,    18,   263,   316,   264,    -1,    19,   263,   316,   264,
      -1,    20,   263,   316,   264,    -1,    21,   263,   316,   264,
      -1,    22,   263,   316,   264,    -1,    23,   263,   316,   264,
      -1,    24,   263,   316,   264,    -1,    26,   263,   316,   264,
      -1,    27,   263,   316,   238,   316,   264,    -1,    28,   263,
     316,   264,    -1,    29,   263,   316,   264,    -1,    30,   263,
     316,   264,    -1,    31,   263,   316,   264,    -1,    32,   263,
     316,   264,    -1,    33,   263,   316,   264,    -1,    34,   263,
     316,   264,    -1,    35,   263,   316,   238,   316,   264,    -1,
      36,   263,   316,   238,   316,   264,    -1,    37,   263,   316,
     238,   316,   264,    -1,    25,   263,   316,   264,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   199,
      -1,   200,    -1,   201,    -1,    73,    -1,    74,    -1,    75,
      -1,    -1,    81,   263,   316,   318,   274,   264,    -1,   319,
      -1,   192,   263,   335,   264,    -1,   192,   263,   335,   238,
     316,   264,    -1,   321,    -1,   341,   231,   316,   232,    -1,
     341,   229,   316,   230,    -1,   197,   229,   341,   230,    -1,
     198,   229,   336,   230,    -1,   236,   341,   263,   264,    -1,
     341,   262,    -1,   341,   231,   316,   232,   262,    -1,   341,
     229,   316,   230,   262,    -1,   341,   235,   322,    -1,   341,
       9,   341,   235,   322,    -1,   341,   231,   316,   232,   235,
       4,    -1,   341,   235,     4,   262,    -1,   341,   231,   316,
     232,   235,     4,   262,    -1,   188,   229,   335,   238,   316,
     230,    -1,    55,   229,   328,   238,   328,   230,    -1,    56,
     263,   335,   238,   335,   264,    -1,    54,   263,   335,   264,
      -1,    57,   263,   335,   238,   335,   264,    -1,    62,   229,
     339,   230,    -1,    -1,    82,   321,   324,   320,   231,   316,
     274,   232,    -1,   341,    -1,   341,     9,   341,    -1,     4,
      -1,    84,    -1,    84,   316,    -1,    -1,   229,   323,   230,
      -1,   326,    -1,   220,   325,    -1,   219,   325,    -1,   325,
     220,   325,    -1,   325,   219,   325,    -1,   233,   316,   238,
     316,   238,   316,   238,   316,   238,   316,   234,    -1,   233,
     316,   238,   316,   238,   316,   238,   316,   234,    -1,   233,
     316,   238,   316,   238,   316,   234,    -1,   229,   316,   238,
     316,   238,   316,   230,    -1,   328,    -1,   327,   238,   328,
      -1,   316,    -1,   330,    -1,   233,   234,    -1,   233,   331,
     234,    -1,   220,   233,   331,   234,    -1,   316,   221,   233,
     331,   234,    -1,   328,    -1,     5,    -1,   220,   330,    -1,
     316,   221,   330,    -1,   316,     8,   316,    -1,   316,     8,
     316,     8,   316,    -1,    88,   233,   316,   234,    -1,    88,
       5,    -1,    91,     5,    -1,    94,     5,    -1,    96,     5,
      -1,   122,    88,   329,    -1,   122,    91,   329,    -1,   122,
      94,   329,    -1,   122,    96,   329,    -1,    88,   173,    63,
     233,   316,   238,   316,   238,   316,   238,   316,   238,   316,
     238,   316,   234,    -1,    91,   173,    63,   233,   316,   238,
     316,   238,   316,   238,   316,   238,   316,   238,   316,   234,
      -1,    94,   173,    63,   233,   316,   238,   316,   238,   316,
     238,   316,   238,   316,   238,   316,   234,    -1,    96,   173,
      63,   233,   316,   238,   316,   238,   316,   238,   316,   238,
     316,   238,   316,   234,    -1,   285,    -1,   296,    -1,   305,
      -1,   341,   263,   264,    -1,    38,   231,   341,   232,    -1,
      38,   231,   330,   232,    -1,    38,   229,   330,   230,    -1,
      38,   263,   233,   331,   234,   264,    -1,   341,   263,   233,
     331,   234,   264,    -1,    39,   263,   316,   238,   316,   238,
     316,   264,    -1,    40,   263,   316,   238,   316,   238,   316,
     264,    -1,    41,   263,   335,   264,    -1,    42,   263,   316,
     238,   316,   238,   316,   238,   316,   238,   316,   238,   316,
     264,    -1,   193,   263,   330,   264,    -1,   316,    -1,   330,
      -1,   331,   238,   316,    -1,   331,   238,   330,    -1,   233,
     316,   238,   316,   238,   316,   238,   316,   234,    -1,   233,
     316,   238,   316,   238,   316,   234,    -1,   341,    -1,     4,
     235,   170,   235,     4,    -1,   233,   334,   234,    -1,   341,
     231,   316,   232,   235,   171,    -1,   332,    -1,   334,   238,
     332,    -1,   336,    -1,   341,    -1,   341,   231,   316,   232,
      -1,   341,   229,   316,   230,    -1,   341,   235,   322,    -1,
     341,     9,   341,   235,   322,    -1,   341,   231,   316,   232,
     235,     4,    -1,   122,    88,   233,   316,   234,    -1,   122,
      91,   233,   316,   234,    -1,   122,    94,   233,   316,   234,
      -1,   122,    96,   233,   316,   234,    -1,     5,    -1,   204,
     231,   341,   232,    -1,    66,    -1,   202,    -1,    71,    -1,
     190,   229,   335,   230,    -1,   189,   229,   335,   238,   335,
     230,    -1,   191,   263,   335,   264,    -1,   191,   263,   335,
     238,   335,   264,    -1,    47,   263,   339,   264,    -1,    48,
     229,   335,   230,    -1,    49,   229,   335,   230,    -1,    50,
     229,   335,   238,   335,   238,   335,   230,    -1,    45,   263,
     339,   264,    -1,    59,   263,   335,   264,    -1,    60,   263,
     335,   264,    -1,    61,   263,   335,   264,    -1,    58,   263,
     316,   238,   335,   238,   335,   264,    -1,    53,   263,   335,
     238,   316,   238,   316,   264,    -1,    53,   263,   335,   238,
     316,   264,    -1,    46,   263,   335,   264,    -1,    46,   263,
     335,   238,   331,   264,    -1,    67,   263,   335,   264,    -1,
      68,    -1,    52,   263,   335,   264,    -1,    51,   263,   335,
     264,    -1,    -1,    85,   263,   336,   337,   276,   264,    -1,
      83,   263,   338,   264,    -1,   236,   316,    -1,   341,     9,
     236,   316,    -1,   335,    -1,   339,   238,   335,    -1,     4,
     237,   233,   316,   234,    -1,   340,   237,   233,   316,   234,
      -1,     4,    -1,   340,    -1,   205,   231,   335,   232,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   235,   235,   236,   241,   243,   247,   248,   249,   250,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   286,   290,   297,   302,
     307,   321,   334,   347,   375,   389,   402,   415,   434,   439,
     440,   441,   442,   443,   447,   449,   454,   456,   462,   566,
     461,   584,   591,   602,   601,   619,   626,   637,   636,   653,
     670,   693,   692,   706,   707,   708,   709,   710,   714,   715,
     721,   721,   722,   722,   728,   729,   730,   731,   736,   742,
     804,   821,   850,   855,   860,   869,   898,   903,   911,   920,
     925,   937,   954,   961,   970,   989,  1008,  1018,  1030,  1036,
    1044,  1065,  1088,  1099,  1107,  1129,  1152,  1190,  1211,  1223,
    1237,  1237,  1239,  1241,  1250,  1260,  1259,  1280,  1279,  1298,
    1297,  1315,  1325,  1324,  1338,  1340,  1348,  1354,  1359,  1385,
    1386,  1390,  1401,  1416,  1426,  1427,  1432,  1440,  1449,  1457,
    1475,  1479,  1485,  1493,  1497,  1503,  1511,  1515,  1521,  1529,
    1533,  1539,  1548,  1551,  1558,  1561,  1568,  1589,  1603,  1617,
    1652,  1690,  1704,  1718,  1738,  1747,  1761,  1776,  1790,  1809,
    1819,  1825,  1831,  1838,  1867,  1882,  1902,  1923,  1944,  1965,
    1987,  2009,  2030,  2053,  2062,  2083,  2098,  2112,  2127,  2142,
    2151,  2161,  2171,  2181,  2196,  2207,  2220,  2232,  2244,  2256,
    2293,  2304,  2320,  2321,  2326,  2329,  2333,  2344,  2355,  2366,
    2382,  2401,  2422,  2437,  2453,  2471,  2522,  2543,  2565,  2588,
    2693,  2709,  2744,  2758,  2764,  2779,  2807,  2824,  2830,  2841,
    2855,  2861,  2867,  2873,  2879,  2885,  2896,  2969,  2987,  3004,
    3019,  3052,  3064,  3088,  3092,  3097,  3104,  3109,  3119,  3124,
    3130,  3138,  3142,  3146,  3155,  3219,  3235,  3252,  3269,  3291,
    3313,  3348,  3356,  3364,  3370,  3377,  3384,  3404,  3430,  3442,
    3454,  3470,  3486,  3495,  3494,  3509,  3508,  3523,  3522,  3537,
    3536,  3549,  3562,  3576,  3590,  3609,  3612,  3618,  3630,  3650,
    3654,  3658,  3662,  3666,  3670,  3674,  3678,  3687,  3700,  3701,
    3702,  3703,  3704,  3708,  3709,  3710,  3713,  3731,  3748,  3765,
    3768,  3784,  3787,  3804,  3807,  3813,  3816,  3823,  3826,  3833,
    3850,  3891,  3935,  3974,  3999,  4008,  4038,  4064,  4090,  4122,
    4149,  4175,  4201,  4227,  4253,  4275,  4281,  4287,  4293,  4299,
    4305,  4331,  4357,  4374,  4391,  4408,  4420,  4426,  4432,  4444,
    4448,  4458,  4469,  4470,  4471,  4475,  4481,  4493,  4511,  4539,
    4540,  4541,  4542,  4543,  4544,  4545,  4546,  4547,  4554,  4555,
    4556,  4557,  4558,  4559,  4560,  4561,  4562,  4563,  4564,  4565,
    4566,  4567,  4568,  4569,  4570,  4571,  4572,  4573,  4574,  4575,
    4576,  4577,  4578,  4579,  4580,  4581,  4582,  4583,  4584,  4585,
    4586,  4595,  4596,  4597,  4598,  4599,  4600,  4601,  4602,  4603,
    4604,  4605,  4610,  4609,  4617,  4619,  4624,  4630,  4654,  4672,
    4690,  4695,  4701,  4716,  4735,  4756,  4789,  4813,  4816,  4822,
    4833,  4843,  4848,  4859,  4868,  4873,  4878,  4907,  4906,  4936,
    4938,  4943,  4952,  4954,  4960,  4961,  4967,  4971,  4975,  4979,
    4983,  4990,  4994,  4998,  5002,  5009,  5014,  5021,  5026,  5030,
    5035,  5039,  5047,  5058,  5062,  5074,  5082,  5090,  5097,  5107,
    5130,  5136,  5142,  5148,  5154,  5165,  5176,  5187,  5198,  5204,
    5210,  5216,  5222,  5232,  5242,  5252,  5265,  5277,  5281,  5285,
    5289,  5307,  5315,  5323,  5352,  5362,  5381,  5386,  5390,  5394,
    5406,  5410,  5422,  5439,  5449,  5453,  5468,  5473,  5481,  5485,
    5498,  5512,  5529,  5555,  5559,  5567,  5573,  5579,  5585,  5594,
    5598,  5602,  5610,  5616,  5622,  5630,  5638,  5645,  5653,  5668,
    5682,  5696,  5708,  5724,  5733,  5742,  5752,  5763,  5771,  5779,
    5783,  5802,  5809,  5815,  5822,  5830,  5829,  5839,  5863,  5865,
    5871,  5876,  5884,  5893,  5906,  5909,  5913
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
  "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tFloor", "tCeil",
  "tRound", "tFmod", "tModulo", "tHypot", "tList", "tLinSpace",
  "tLogSpace", "tListFromFile", "tCatenary", "tPrintf", "tError", "tStr",
  "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace",
  "tAbsolutePath", "tDirName", "tStrSub", "tStrLen", "tFind", "tStrFind",
  "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tCurrentDirectory", "tSyncModel", "tNewModel",
  "tOnelabAction", "tOnelabRun", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineStruct",
  "tNameStruct", "tAppend", "tDefineString", "tSetNumber", "tSetString",
  "tPoint", "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tBlock", "tCylinder", "tCone",
  "tTorus", "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle",
  "tDisk", "tWire", "tCharacteristic", "tLength", "tParametric",
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
  "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'",
  "'#'", "'~'", "','", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "LP", "RP", "Affectation",
  "Comma", "DefineConstants", "@6", "@7", "@8", "@9", "UndefineConstants",
  "Enumeration", "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptions", "CharParameterOption", "PhysicalId0",
  "PhysicalId1", "PhysicalId2", "PhysicalId3", "InSphereCenter",
  "CircleOptions", "Shape", "Transform", "MultipleShape", "ListOfShapes",
  "LevelSet", "Delete", "Colorify", "SetPartition", "Visibility",
  "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12", "@13",
  "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "BooleanShape", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@14", "DefineStruct", "@15",
  "Struct_FullName", "tSTRING_Member_Float", "Append", "AppendOrNot",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "@16", "NameStruct_Arg", "RecursiveListOfStringExprVar", "StringIndex",
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
      63,   465,   466,   467,   468,    60,    62,   469,   470,    43,
      45,    42,    47,    37,    33,   471,   472,   473,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   239,   240,   240,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   245,   245,   245,   245,   246,   246,
     246,   246,   246,   246,   247,   247,   248,   248,   250,   251,
     249,   252,   252,   254,   253,   255,   255,   257,   256,   258,
     258,   260,   259,   261,   261,   261,   261,   261,   262,   262,
     263,   263,   264,   264,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     266,   266,   267,   267,   267,   268,   267,   269,   267,   270,
     267,   267,   271,   267,   272,   272,   273,   273,   273,   274,
     274,   275,   275,   275,   276,   276,   277,   277,   277,   277,
     278,   278,   278,   279,   279,   279,   280,   280,   280,   281,
     281,   281,   282,   282,   283,   283,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   287,   287,   287,   287,   287,   287,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   289,   289,   289,   289,   289,   290,   290,   291,
     292,   292,   292,   292,   292,   292,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     296,   296,   296,   297,   296,   298,   296,   299,   296,   300,
     296,   296,   296,   296,   296,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   303,
     303,   303,   303,   304,   304,   304,   305,   305,   306,   307,
     307,   308,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   314,   314,   314,   315,   315,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   318,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   320,   319,   321,
     321,   322,   323,   323,   324,   324,   325,   325,   325,   325,
     325,   326,   326,   326,   326,   327,   327,   328,   328,   328,
     328,   328,   328,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   331,   331,   331,   331,
     332,   332,   332,   332,   333,   333,   334,   334,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   337,   336,   336,   338,   338,
     339,   339,   340,   340,   341,   341,   341
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
       3,     6,     7,     6,     9,     6,     7,     6,     4,     8,
       9,     9,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     5,     7,     9,     9,    11,     7,     9,     9,
       0,     1,     0,     3,     5,     0,     9,     0,    11,     0,
      11,     5,     0,     9,     0,     3,     3,     5,     5,     0,
       2,     3,     5,     3,     0,     2,     3,     3,     3,     5,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     0,     5,     0,     2,     7,     7,     7,     8,
       8,     7,     7,    11,     8,     7,     8,     8,     8,     9,
       3,     4,    10,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     8,    12,     8,     7,     7,     8,     8,
       8,     8,     8,     8,     5,    11,     5,     9,     9,     4,
       9,     9,     1,     1,     0,     2,     6,     6,     6,     6,
       8,    10,    14,    16,    12,    14,    14,    14,    14,     8,
       8,     6,     4,     6,     6,     3,     4,     5,     6,     5,
       3,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,    11,     6,     8,     8,    10,
       1,     2,     2,     1,     3,     3,     4,     4,     1,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     9,     2,     3,    10,     1,     2,     5,     7,     2,
       2,     3,     2,     3,     2,     3,     9,     6,     1,     1,
       1,     1,     1,     0,     2,     3,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     6,
       7,     6,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,    10,    10,    10,    10,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     6,     1,     4,     4,
       4,     4,     4,     2,     5,     5,     3,     5,     6,     4,
       7,     6,     6,     6,     4,     6,     4,     0,     8,     1,
       3,     1,     1,     2,     0,     3,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     3,     3,     3,     3,    16,    16,
      16,    16,     1,     1,     1,     3,     4,     4,     4,     6,
       6,     8,     8,     4,    14,     4,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       4,     4,     3,     5,     6,     5,     5,     5,     5,     1,
       4,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     8,     6,     4,
       6,     4,     1,     4,     4,     0,     6,     4,     2,     4,
       1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   554,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   298,   299,   300,   301,   302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,   268,   269,     0,     0,     0,   263,     0,     0,
       0,     0,     0,   352,   353,   354,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   555,     0,     0,     0,     0,     0,     0,   247,     0,
     249,   250,   245,   246,     0,   251,   252,   112,   124,   444,
     439,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
       0,     0,     0,     0,     0,   401,   402,   404,   405,   403,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   409,   410,   411,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   406,   407,
     408,     0,     0,     0,     0,     0,     0,   482,   483,     0,
     484,   457,   359,   414,   417,   282,   458,   439,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,   204,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,     0,   204,     0,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,   464,     0,
     463,     0,     0,     0,     0,     0,   554,     0,     0,   502,
       0,     0,     0,     0,   243,   244,     0,   519,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   521,     0,   542,   523,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,   261,   262,     0,   204,     0,
     204,     0,     0,   439,     0,     0,   204,   355,     0,     0,
      76,     0,    63,     0,     0,    67,    66,    65,    64,    69,
      68,    70,    71,   204,     0,     0,     0,     0,     0,     0,
     508,   439,     0,   170,     0,     0,   508,   509,     0,     0,
     550,     0,   110,   110,     0,   437,     0,     0,     0,     0,
       0,   496,   497,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,     0,     0,   471,
       0,   472,     0,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,     0,   361,   465,   363,
       0,   459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,   423,     0,     0,     0,     0,     0,
       0,   283,     0,   313,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   204,     0,   448,   447,     0,     0,     0,     0,
     204,   204,     0,     0,     0,     0,   279,     0,   204,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,     0,     0,     0,     0,     0,   225,   350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   323,   242,
       0,     0,     0,     0,     0,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   264,     0,   230,     0,   231,     0,   361,     0,
     204,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,   202,     0,     0,     0,     0,     0,    80,    72,    73,
       0,     0,   240,    38,   236,     0,     0,     0,     0,     0,
       0,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   442,     0,
       0,   440,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   307,     0,     0,     0,     0,     0,
       0,   342,   343,   344,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,     0,     0,     0,     0,   360,   460,     0,
     467,     0,   377,   376,   375,   374,   370,   371,   373,   372,
     365,   364,     0,   366,   466,   367,   368,   369,   440,     0,
       0,   441,   426,     0,   485,     0,     0,     0,     0,     0,
       0,     0,   311,     0,     0,   140,   141,     0,   143,   144,
       0,   146,   147,     0,   149,   150,     0,   346,     0,   347,
       0,   348,     0,     0,     0,     0,   345,   204,     0,     0,
       0,     0,     0,   450,   449,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,     0,     0,   226,     0,     0,   222,
       0,     0,     0,   341,   340,     0,     0,     0,   360,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   545,     0,     0,
       0,     0,     0,   232,   234,   366,     0,   556,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    63,     0,   360,    63,    64,     0,     0,   199,    63,
       0,     0,     0,     0,    79,     0,     0,     0,   440,     0,
       0,   426,     0,   552,    28,    26,     0,     0,     0,     0,
       0,   441,   512,    29,     0,     0,   237,   551,    74,   113,
      75,   125,   443,   445,     0,     0,     0,     0,     0,   498,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   400,   388,     0,   390,   391,   392,   393,
     394,   395,   396,     0,     0,     0,   488,   487,   486,     0,
       0,     0,   493,     0,   434,     0,     0,     0,   436,   129,
       0,   469,     0,     0,     0,     0,     0,   415,   495,   420,
     421,   461,     0,   422,     0,     0,     0,     0,   419,   418,
     429,     0,     0,     0,     0,     0,   360,   309,   314,   312,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   360,   360,     0,     0,     0,     0,     0,   233,   235,
       0,     0,     0,   194,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   316,
     325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,   532,     0,   539,   528,   529,   530,     0,   544,   543,
       0,     0,   533,   534,   535,   541,   548,   547,     0,   134,
       0,   524,     0,   526,   520,     0,   229,     0,   304,     0,
       0,     0,   356,     0,   553,     0,     0,     0,     0,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    61,     0,    39,    40,    41,    42,    43,     0,
     419,   418,     0,    27,     0,     0,     0,   511,   510,     0,
       0,     0,     0,     0,   129,     0,     0,     0,     0,     0,
     154,   154,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   378,   462,   427,   425,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,   321,     0,   142,
       0,   145,     0,   148,     0,   151,     0,     0,     0,     0,
       0,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,   289,     0,   292,     0,   294,     0,   280,
     286,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,   327,     0,   224,   223,   351,     0,     0,
      35,    36,     0,     0,     0,     0,   503,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,   305,   204,     0,     0,   515,   516,   517,
     518,    85,     0,    87,     0,     0,    81,     0,     0,     0,
       0,    83,    92,    94,     0,   506,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,    34,   427,     0,     0,
       0,    30,    31,     0,   513,     0,    32,     0,     0,   114,
     121,     0,     0,     0,    77,    78,   156,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   173,   174,     0,     0,
       0,     0,   158,   186,   175,   179,   180,   176,   177,   178,
     165,     0,     0,   389,   397,   398,   399,   489,     0,     0,
       0,   432,   433,   435,     0,   413,   130,     0,     0,     0,
       0,   431,   416,   187,   428,   490,   181,     0,     0,   152,
       0,     0,   320,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,     0,     0,     0,     0,   204,   204,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   457,     0,     0,   293,   295,     0,     0,   274,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,     0,     0,   161,   162,     0,     0,     0,
       0,   103,   107,     0,   540,     0,     0,   538,     0,   549,
       0,   546,   135,   525,   527,     0,   303,   303,     0,   357,
      86,     0,     0,    63,     0,     0,     0,     0,    82,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,   455,
       0,   428,   238,   239,     0,   514,     0,   115,   122,     0,
       0,   438,     0,     0,   155,   159,   160,   166,     0,     0,
     185,     0,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   430,     0,   167,     0,   188,   310,
     190,   191,   192,   193,   164,     0,   183,   189,     0,     0,
       0,     0,     0,     0,   454,   453,     0,     0,     0,   206,
     207,   208,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   219,     0,     0,     0,     0,
       0,     0,     0,     0,   210,     0,     0,   324,    37,     0,
     501,     0,     0,   258,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,    98,   507,     0,     0,    89,     0,
      44,     0,     0,     0,     0,     0,    46,    33,     0,   129,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,   492,     0,     0,   131,   133,     0,     0,     0,
       0,     0,   169,     0,   317,   317,     0,   108,   109,   204,
       0,   197,   198,   281,     0,   287,     0,     0,   204,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   200,     0,
       0,     0,     0,   104,   105,   531,   537,   536,     0,   136,
     137,   138,     0,     0,   306,     0,    90,    91,    93,    95,
       0,   101,     0,    84,    49,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,   119,   117,   335,   337,   336,
     338,     0,   339,   172,     0,     0,     0,   496,   497,     0,
       0,     0,     0,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   452,     0,   297,     0,     0,   275,
       0,   211,     0,     0,     0,     0,     0,     0,     0,   500,
     259,     0,     0,     0,   204,   358,     0,   505,     0,    45,
       0,     0,     0,    62,    47,     0,   116,   123,   129,   129,
     153,     0,     0,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   318,   328,     0,     0,   329,     0,
     195,     0,   288,     0,   271,     0,   204,     0,     0,     0,
       0,     0,     0,   163,   106,   139,   255,   303,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,     0,     0,     0,     0,   184,     0,   332,     0,   333,
     334,   451,     0,     0,   277,   214,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    59,     0,     0,   120,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,   276,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,     0,     0,     0,     0,     0,   215,   216,
     217,   218,     0,   212,   308,    50,     0,    57,     0,   248,
       0,   494,     0,     0,     0,     0,     0,     0,   278,     0,
       0,    51,     0,     0,   254,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,     0,   478,   479,   480,   481,
       0,     0,    54,    52,     0,    55,     0,   330,   331,     0,
       0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,   986,   109,   110,   977,  1739,  1745,
    1244,  1441,  1888,  2040,  1245,  2003,  2064,  1246,  2042,  1247,
    1248,  1445,   395,   534,   535,   681,   111,   705,   412,  1749,
    1899,  1898,  1750,   413,  1846,  1304,  1506,  1408,  1592,   834,
     837,   840,   843,  1480,  1470,   877,   247,   670,   671,   114,
     115,   116,   117,   118,   119,   120,   121,   248,  1148,  1925,
    1994,   878,  1144,  1145,   249,   950,   250,   125,  1326,  1100,
     832,   892,  1858,   126,   127,   128,   129,   251,   252,  1069,
     253,   710,   254,   822,   709,   415,   565,   286,  1618,   320,
     321,   256,   512,   328,  1234,  1436,   410,   406,  1199,   935,
     411,   131,   373
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1586
static const yytype_int16 yypact[] =
{
   10099,    92,    59, 10246, -1586, -1586,  -203,   101,    16,  -101,
     -91,    39,   165,   179,   199,   244,     6,   264,   313,   103,
     132,    26,   -79,   -79,  -167,   148,   155,    20,   214,   228,
      22,   245,   261,   279,   285,   290,   293,   299,   302,   314,
     321,   475,   533,   627,   405,   681,   420,  5518,   452,   461,
     616,   -45,   320,   496,   580,   -16,   489,   628,  -114,   525,
     353,   353,   526,   356,   696, -1586, -1586, -1586, -1586, -1586,
     505,    70,   673,   692,    25,    44,   698,   679,   308,   786,
     803,   843,  4837,   851,   590,   593,   595,    31,    11, -1586,
     633,   640, -1586, -1586,   810,   864,   659, -1586,  4960,   658,
    5187,    33,    52, -1586, -1586, -1586,  9443,   677, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586,  -140, -1586, -1586, -1586, -1586,    57, -1586,
     918,   700,  3935,   720,   948,  9443,  3474,  3474, -1586,  9443,
   -1586, -1586, -1586, -1586,  3474, -1586, -1586, -1586, -1586,   740,
     963, -1586, -1586,  4021,    26,  9443,  8015,  9443,  9443,   752,
    9443,  8015,  9443,  9443,   771,  9443,  8015,  9443,  9443,  9443,
    9443,  9443,  9443,  3474,  9443,  9443,  9443,  5745,   781, -1586,
    8015,  4837,  4837,  4837,  3474, -1586, -1586, -1586, -1586, -1586,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -36,   -79,   -79,   -79,   -79,   -79,   783,   -79,
     -79,   788, -1586, -1586, -1586,   -79,    38,    34,    41,    42,
    5745,   900,   551,   798,   -79,   -79,   799,   825, -1586, -1586,
   -1586,  9443,  5972,  9443,  9443,  6199,    26, -1586, -1586,   811,
   -1586,  2610, -1586, -1586, -1586, -1586, -1586,   100,  9443,  8015,
     829,   831,  6426,  4837,  4837,  4837,   858,   859,   888,   891,
    6653,  6880,  7107,   867,  8852,  1106,  5745,    31,   890,   906,
     353,   353,   353,  9443,  9443,  -139, -1586,   249,   353,  8920,
     358,    19,   913,   921,   922,   923,   925,   927,   928,  9443,
    4837,  4837,  4837,   929,    10,   930, -1586,  1154,  1156, -1586,
     931,   932,   933,  4837,  4837,   936,   940,   941, -1586,  9443,
   -1586,  1157,  1167,  9443,  9443,  9443,   200,  9443,   942, -1586,
    1001,  9443,  9443,  9443, -1586, -1586,  9443, -1586,   -79,   -79,
     -79,   947,   949,   951,   -79,   -79,   -79,   -79,   -79,   -79,
     -79, -1586,   -79, -1586, -1586,   -79,   -79,   952,   953,   -79,
   -1586,   946,  1177,  1179,   956, -1586, -1586,  1184, -1586,  1186,
   -1586,  9443, 11546,    77,  3474,  9443, -1586, -1586,  5745,  5745,
   -1586,   960,  4021,   584,  1187, -1586, -1586, -1586, -1586, -1586,
   -1586,  9443,  9443,   319,    28,  5745,  1189,   106,   389,   965,
    1190,    49,  9443, -1586,   532,   -76, -1586,    65,   -54,  4141,
   -1586,     8,   127,   162,  1116, -1586,    26,   964,   966,  3713,
    8015,  2768, -1586,   136, 11940, 11961,  9443, 11982,   501, 12003,
   12024,  9443, 12045,   503, 12066, 12087, 12108, 12129, 12150, 12171,
     973, 12192, 12213, 12234,  1198,  9443,   523,  1200,  1201,  1203,
     980,  9443,  9443,  9443,  9443,  9443,  9443,  9443,  9443,  9443,
    9443,  9443,  9443,  9443,  9443,  9443,  9443,  9443,  9443,  9443,
    9443,  9443,  9443,  8015,  8015,   978,  9443,  9443,  3474,  9443,
    3474,  5745,  3474,  3474,  3474,  9443, -1586,  1149,  9443, -1586,
    1150, -1586,  1151, -1586,  1152,  5745,  4837,  4837,  4837,  4837,
    3474,  3474,  8015,    26,  4021,   988,  8015,   988, -1586,   988,
   12255, -1586,   558,   -79,  9443,  9443,  9443,  9443,  9443,  9443,
    9443,  9443,  9443,  9443,  9443,  9443,  7334,  9443,  9443,  9443,
      26,  9443,  9443,  1214, -1586,   383, 12276,   565,  9443,  9443,
    9443, -1586,  1212,  1213,  1213,  8630,  8630,  8630,  8630,  9443,
    1215,  9443,  1216,  9443,  1217,  8015,  8015, 11570,   994,  1219,
     993, -1586, -1586,  -103, -1586, -1586,  4311,  4538,   353,   353,
     319,   319,   -99,  8920,  8920,  9443,  2546,   -94, -1586,  9443,
    9443,  9443,  9443,  9443,  9443,  9443,  9443,  9443, 12297,  1220,
    1223,  1224,  9443,  1226,  9443,  9443,  2761, -1586, -1586,  8015,
    8015,  8015,  1227,  1228,  9443,  9443,  9443, 12318, -1586, -1586,
   12339, 12360, 12381,  1065,  4776, -1586,  1003,  2856, 12402, 12423,
   11641,  3474,  3474,  3474,  3474,  3474,  3474,  3474,  3474,  3474,
    9443,  3474,  3474,  3474,  3474,    21,  4021,  3474,  3474,  3474,
      26, -1586, -1586,  8015, -1586,  4086, -1586,  4183,   988,  9443,
   -1586,  9443,  9443,  1006, 12444,  3339,  1009,   567,  9443,  1234,
    1010,  1011,  1012,  1013,  9443,   197, 12465,   201, 11664, -1586,
    1008, 10383,  1014,   160,  1028,  1257,  1259, -1586, -1586, -1586,
    8015,  1261, -1586, -1586, -1586,    26,  9443,  9443,  1214,  1035,
    3438, -1586,    79,  8015,    26,  9443,  9443,  1266,  1267,  8015,
    9443,  1268,  3474,  1270, -1586,    26,  1271,  3474,  9443,  1048,
    1049, -1586,  9443,  4021,  1272,  8015,  1108,  8015,  1275,  1276,
   12486,  1277,  1112,  1281,  1283, 12507,  1286,  1122,  1298,  1299,
    1300,  1301,  1302,  1303, -1586,  1304,  1305,  1306,  9443, 12528,
    1081, -1586, -1586, -1586,  1310, 11618, 11618, 11618, 11618, 11618,
   11618, 11618, 11618, 11618, 11618, 11618,  5003, 11618, 11618, 11618,
   11618, 11618, 11618, 11618,  5229,  5456,  5683,  2768,  1087,  1086,
     118,  8015,  5910,  6137,   416,  6364,   416,  1084,  1088,  1090,
      90, 10242,  1091,  3475,  1099,  1104,  1105, -1586, -1586, -1586,
   -1586,  1101,  -127,   416,  1111,  1126,   572,  1351, -1586,   416,
    2951,  3072,  1627,  1245,   876,   876,   543,   543,   543,   543,
     211,   211,  8015,   988, -1586,   988,   988,   988,  1127, 12549,
   11687,    -4, -1586,  8015, -1586,  1354,  1130, 12570, 12591, 12612,
    9443,  5745,  1360,  1359,  1136, 10242,  1131,  1138, 10242,  1133,
    1142, 10242,  1135,  1144, 10242,  1137, 12633, -1586, 12654, -1586,
   12675, -1586,   574,   579,  8015,  1141, -1586, -1586,  9471,  9592,
     353,  9443,  9443, -1586, -1586,  1143,  1145,  8920,  3571,   243,
      48,    50,   585,  1153,   -39,   617,  1255, -1586,   -60,   353,
    9632, 12696,  8196, 12717, 12738, 12759, 12780, 12801, 12822, 12843,
    1376,  9443,  1378, -1586,  9443, 12864, -1586, 11710, 11733, -1586,
     587,   607,   612, -1586, -1586, 11756, 11779,  6591, -1586,  1379,
    1380,  1381,  1155,  9443,  9686,  9443,  9443, -1586, -1586,    53,
     -90,   -44,   -90,  1159,  1161,  1147,   416,   416,  1160,  6818,
     416,   416,   416,   416,  9443,   416,  1384, -1586,  1162,  1164,
     253,  1163,   614, -1586, -1586,   988,  9780, -1586,  1390,  9148,
    1165,  1168,  1396,  5745,  8506, -1586,  9443,  9443,  9443,  9443,
     663, -1586,  5745,   238,  1358,  1361,  5745,    -6, -1586,  4021,
    9443,  1398,  1404,    32, -1586,   615,  1364,    29,  1176, 12885,
   11802,  1181,  9443, -1586, -1586,  1196,  3474,   110,  1180, 12906,
   11825, -1586, -1586, -1586,   124,  7045, -1586, -1586, -1586,    76,
   -1586, -1586, 10242, -1586,  9443, 11618,   416,   353,   680,  2768,
   -1586,  5745,  5745,  1409,  5745,   706,  5745,  5745,  1413,  5745,
    1323,  5745,  5745,  5745,  5745,  5745,  5745,  5745,  5745,  5745,
     683,  1416,  8015, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586,  9443, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586,  9443,  9443,  9443, -1586, -1586, -1586,   620,
    9443,  9443, -1586,  9443, -1586,  5745,  3474,  3474, -1586, -1586,
    9443, -1586,  9443,  9443,  9443,  9443,  9443, -1586, -1586, -1586,
   -1586, -1586,  5745, -1586,  9443,  9443,   626,  1266,    -4,  -158,
   -1586,   654,  5745,  8015,  1417,  1418,  1419,  2818, -1586, -1586,
    1421, -1586,   197,  9443,   197,  9443,   197,  9443,   197,  9443,
    1422,  1423,  1425,  1427,  1428,   675,  1424,  9818, -1586, -1586,
     -89,  7272,  7499, -1586, -1586,  8879,   -37,  8015,  8015,  8015,
    8015,  9443,  1207,  1208,  1209,  1210,  1334,  1438,  9221,  1211,
    1437,  1222,    55,    61,   -38, -1586,   -83, -1586,   -60,  1442,
    1439,  1445,  1446,  1447,  1462,  1463,  1464,  1465,  5745, 10242,
   -1586,   776,  1246,  1474,  1475,  1476,  1393,  1481,  1483,  1484,
    9443,  5745,  5745,  5745,  1488,  7726, -1586,  3178,   510,  1490,
    1491, -1586,  8015, -1586, -1586, -1586, -1586,  3474, -1586, -1586,
    9443,  3474, -1586, -1586, -1586, -1586, 10242, -1586,  1260, -1586,
    3474, -1586,  3474, -1586, -1586,  1263, -1586,  1264, -1586,   820,
    1265,  5745, -1586,  1269, -1586,  9405,  9938, 10921, 10946, -1586,
    1493,  9443,  1496,   -79,   -79,  1498,    47,  9443,  1499,  1500,
     855, -1586,  1506,    31,  1508,  1284,   416,   -79, -1586,  1287,
    1289,  1288, -1586,  1514, -1586, -1586, -1586, -1586, -1586,  1266,
     307,  2534, 11848, -1586,  1516,   102,  1266, -1586,  1290,  1517,
    9443,  8237,  1294,  1297, 10242,  1520,  1524,    82,  1307,  1308,
    1414,  1414,  5745,  1525,  1309,  1311,  1526,  1528,  5745,  1370,
    1313,  1531,  1542,  1543,  1544,  1545,  1546,  1548,  1549,  1550,
   -1586,  1552,   676, 11618, 11618, 11618, 11618,   416,  7953,  8264,
    8574,  1328,   416,   416,   454,  8682,  8750,  8793,  8978, 12927,
   11618,  1554, 10242, 10242, -1586, -1586, -1586,  1557, -1586,   416,
    1556,   682,  5745,  5745,  5745,  1559,  1558, -1586,  5745, 10242,
    5745, 10242,  5745, 10242,  5745, 10242,  5745,  5745,  5745,  1333,
    1335,  1560,   549, -1586,  9443,  9443,  9443,  1336,  1337,   684,
     685,   687,   714, 12948,  9443,  9443,  9443,  9443,  1338,  1341,
   -1586,  1039,  5745, -1586,  9443, -1586,  1567, -1586,  1569, -1586,
   -1586,  8920,   359,  5064, -1586,  1343,  1344,  1345,  1346,  1347,
    1348,  7561,  1577, -1586,  8015, -1586, -1586, -1586,  1355,  9443,
   -1586, -1586, 11871,  1581,  1584,  1431, -1586,  9443,  9443,  9443,
   -1586,  1586,   559,   463,  1356,  3502,  1363,  9443,   477,  1366,
     416,  4021, -1586, -1586, -1586,  1368,  1587, -1586, -1586, -1586,
   -1586, -1586,  1132, -1586,  3474,  3474, -1586,   280,  1367,  1607,
    1412, -1586, -1586, -1586,    31, -1586,   722, -1586,  9443,   197,
     416,  1387,  9443,  9443,  5745,  1385, -1586,  1386,  1613,  1614,
    1630, -1586, -1586,  3474, -1586,  1634, -1586,  9051,  4373, 10242,
   -1586,  1632,  1637,   229, -1586, -1586, -1586,  9443,  9443,   353,
    1635,  1639,  1641, -1586,  9443,  9443, -1586, -1586,  1643,  1561,
    1644,  9443, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586,  1646,  1426, -1586, -1586, -1586, -1586, -1586,  9443,  9443,
    9443, -1586, -1586, -1586,  1648, -1586, -1586,  9443,  9443,  9443,
    9443, -1586, -1586, -1586,    -4, -1586, -1586,  1443,  1649,  1370,
    1654,  9443, -1586,  1669,  1671,  1672,  1674,  1675,   911,  1676,
    8015,  8015,  9443, -1586,  8630, 10971, 12969,  2293,   319,   319,
    1677,  1678,  1679,  1680,  1351, 12990, 13011, 13032, 13053,  9443,
    9443, -1586,   208,  1450, 13074, -1586, -1586, 10996,   -73, -1586,
    1683,  1685,  5745,   353,   353,   353,   353,   353,  5291,  1686,
   -1586,   727,  9443,  1451,  1687, -1586, -1586,  5745,  3627,   445,
   13095, -1586, -1586,  8320, -1586,  3474,  9443, -1586,  3474, 10242,
      27, -1586, -1586, -1586, -1586,  1456,  3339,  3339,  5745, -1586,
   -1586,   -90,   -90,  4021,  9443,  1689,  1650,    32, -1586,  1690,
   -1586,    31, 11894,  5745,  1691,  9443,  9094,  9176,   728, -1586,
    9443,   417, -1586, -1586,  1692, -1586,  9443, -1586, -1586,  1468,
    1469, -1586, 11021, 11046,   375, -1586, -1586, -1586, 11071, 11096,
   -1586,  1470, -1586, 11121,  1699,  5745, 11618, 11618,  9316,  4600,
    9600,  9758,  9909, 10297, -1586,  9443, -1586,  1700, -1586, 10242,
   -1586, -1586, -1586, -1586, -1586,  1472, -1586, -1586,   730,   733,
   11594,  1694,  1701,  1477, -1586, -1586,  9443,  1479,  1480, -1586,
   -1586, -1586, -1586,  1419,  1422,  1423,  1425, 11146, 11917,  1702,
    5745,  1704,  1482,  9443, -1586, -1586,   741,   -63,   -51,   -10,
     105,   141,  7788,   153, -1586,  1703, 11171, -1586, -1586,  1553,
   -1586,  9443,  9443, -1586, -1586,  8015,  1929,  1710,  1487, 11618,
     416,  8547,  4021,  4021,  1486,  1489,  1492,  1712,  1716,  1718,
    1964, -1586,  1720,  1719, -1586, -1586,  1494,  1722, -1586,   150,
   10242,  9443,  9443,  1497,  5745,   744, 10242, -1586, 10341, -1586,
   -1586,  5745,  5745,  1725,  1726,  1728,  1729,  9443,  1736,  1737,
     767, -1586, -1586,  9443,  6199, -1586, -1586,  9443,  9443,  9443,
    9443, 11196, -1586,  5745,   568,   656,  8015, -1586, -1586,   319,
    4026, -1586, -1586, -1586,  1738, -1586,  1511,  5745, -1586, 11221,
    1740,  8015,   353,   353,   353,   353,   353, -1586, -1586,  9443,
   11246, 11271,   768, -1586, -1586, -1586, -1586, -1586,  3474, 10242,
   -1586, -1586,  1521,  1519, -1586,  1741, -1586, -1586, -1586, -1586,
      31, -1586,  1579, -1586, -1586,  9443, 10370, 10399,  5745, -1586,
    1747,  9443,  9443,   769,   812, -1586, -1586, -1586, -1586, -1586,
   -1586, 11296, -1586, -1586,  1522, 10428,   813,  2234,  1749, 10457,
   10486, 10515, 10544, -1586,   815,  1527,   353,  5745,  1748,  1529,
     353,  1751,   818,  1530, -1586,  9443, -1586,  1752,  1638,  9912,
    1532, -1586,   821,   163,   177,   221,   235,   301,  1983, -1586,
   -1586,  1753,   823,  1761, -1586, -1586,  1762, -1586,  1536, 10242,
    9443,  9443,   846, -1586, 10242, 10573, -1586, -1586, -1586, -1586,
   -1586,  9443,  9443, -1586,  9443,  4021,    26,  9443,  9443,  9443,
    9443,  1765,   353,    94, -1586, -1586,   353,    96, -1586,  1766,
   -1586, 11321, -1586,  9443, -1586,   -60, -1586,  1768,  8015,  8015,
    8015,  8015,  7788, -1586, -1586, -1586, -1586,  3339, -1586,  9443,
   13116, 10602,    58,  9443,   847,   848, 10631, 10660,  2461, -1586,
    1551, 10689, 10718, 10747, 10776, -1586,   306, -1586,   310, -1586,
   -1586, -1586,  2185,   407,  9950, -1586,   871,   881,   884,   894,
     316,   895,  1541,   896, -1586,  9443, -1586,  5745, 11346, -1586,
   -1586,  9443,  9443,  4021,  1547,  9443,  9443,  9443,  9443,   353,
     353, -1586, -1586, -1586,   -60,  1772,  1775,  1779,  1780,  8015,
    1781,  1783,  1785,  1562, 13137,   897,  1786, 11371, 11618, -1586,
   -1586, 10805, 10834, 10863, 10892,   322,   342,   715, -1586, -1586,
   -1586, -1586,   902, -1586, -1586, -1586,  3474, -1586,  1563, -1586,
    1788, -1586,  9443,  9443,  9443,  9443,  9443,  9443, -1586,  1791,
     903, -1586,  1565,  5745, -1586, 11396, 11421, 11446, 11471, 11496,
   11521, -1586,  1793,  3474,  3474,   910, -1586, -1586, -1586, -1586,
    1795,  1796, -1586, -1586,   915, -1586,  1797, -1586, -1586,  1800,
    3474, -1586, -1586, -1586
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1586, -1586, -1586, -1586,   552, -1586, -1586, -1586, -1586,  -131,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,  -646,  -104,  3685,   181, -1586,  1397, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1247, -1586,    62, -1586, -1586,
   -1586, -1586, -1586,   292,   538,  1810,     0,  -562,  -269, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586,  1811, -1586, -1586,
   -1586, -1586, -1138, -1128,  1813, -1585,  1815, -1586, -1586, -1586,
    1278, -1586,    45, -1586, -1586, -1586, -1586,  1837, -1586, -1586,
    1816, -1586,  1802,  -675, -1586, -1586,   -56, -1586, -1539,   275,
    -141,  2443,  2553,  -275,   217, -1586,   205,   232, -1586, -1586,
    -478, -1586,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -515
static const yytype_int16 yytable[] =
{
     132,   961,   560,   113,   285,   287,   780,   290,   865,   866,
    1372,  1724,  1725,   981,   593,   330,  1370,  1463,   150,   962,
     576,   966,   992,  1696,   159,     6,   164,   970,   396,   304,
       6,  1721,   673,  1238,   133,   326,     6,   596,   367,   489,
     447,   448,   449,   486,   257,   138,   491,   493,   308,   261,
     309,  1427,   159,     6,   164,   261,   277,   369,   685,     5,
    1179,  1365,   155,   377,  1976,  1137,   156,  1367,   389,   390,
     262,   307,   278,   279,   694,   273,  1132,  1317,   274,   257,
     568,   569,  1138,  1261,   329,   984,   530,  1137,  1466,   375,
    1139,  1140,  1141,   376,   570,   363,  1142,  1143,     4,   645,
    1957,   647,  1959,   678,  1138,   679,  1760,   655,  1452,   530,
     135,  1076,  1139,  1140,  1141,   134,   568,   569,  1142,  1143,
     568,   569,   542,   543,   544,   568,   569,   530,   136,   401,
     568,   569,   310,   407,   407,   860,   568,   569,   137,   867,
     678,   407,   679,   920,   879,   922,   568,   569,   702,  1344,
     151,   418,   152,   257,   692,  1371,   568,   569,   257,   589,
     590,   591,   693,   257,   300,  1693,   301,   969,   568,   569,
     407,   140,   602,   603,   257,  1791,   698,   257,   257,   257,
     257,   407,   568,   569,   699,   141,   678,  1792,   679,  1239,
    1240,  1241,  1242,   473,  1182,   474,  1369,  1348,   674,   675,
     385,   386,   387,   388,   961,   142,   305,   490,   964,   568,
     569,   487,  1722,  1366,   492,   494,   514,  1428,  1429,  1368,
     389,   390,   389,   390,   563,   564,   107,   257,  1793,  1226,
     107,   107,   572,   577,  1854,   144,   107,   107,   701,   257,
     331,   594,   257,   513,  1370,   961,   702,   133,   579,   160,
     143,   165,   580,   161,   107,   166,   257,   934,   306,   257,
     257,   257,   257,  1243,   327,  1233,   368,   257,   257,   257,
     145,   488,   139,   257,   329,   389,   390,   160,   686,   165,
     687,  1128,  -509,  1129,   688,   370,   378,  1603,  1180,  1892,
     379,  1977,   858,   859,   695,   985,   696,   257,   257,   257,
     697,   568,   569,   389,   390,  1262,   651,  1263,   652,   880,
     257,   257,   533,   568,   569,   568,   569,  1221,   985,   146,
    1068,  1227,   255,     6,   568,   569,   389,   390,   702,   531,
     362,   532,   366,   393,   147,   533,   678,   399,   679,   680,
    1255,   405,   408,  1794,   389,   390,   914,   531,   717,   532,
    1058,   393,  1972,   533,  1259,   787,   788,   789,   790,   703,
     568,   569,   717,   148,   400,   704,   385,   386,   387,   388,
     716,   407,   568,   569,   717,   257,   257,   157,   440,  1795,
    1824,   946,   568,   569,   158,   417,   389,   390,  1825,   450,
     672,  1796,   257,   669,   706,   682,   568,   569,   689,   313,
     704,  1928,   314,   385,   386,   387,   388,   385,   386,   387,
     965,   263,  1315,   711,   264,  1929,   265,   257,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   649,   527,   528,   613,   529,   133,  2005,   529,
     568,   569,  1689,   162,   385,   386,   387,   388,    59,    60,
      61,    62,   444,  1712,   568,   569,  1328,   163,  1330,  1930,
    1332,  1631,  1334,    73,   389,   390,    76,  1504,   568,   569,
     257,   770,   155,  1931,   167,   407,  1127,   407,   257,   407,
     407,   407,   571,   678,  1137,   679,   385,   386,   387,   388,
     168,  1202,   257,   257,   257,   257,   257,   407,   407,   257,
     794,  1138,  1833,   257,  2055,   255,   389,   390,   169,  1139,
    1140,  1141,   863,   864,   170,  1142,  1143,   564,  1399,   171,
     568,   569,   172,   257,   107,   568,   569,   818,   173,   568,
     569,   174,  1137,   389,   390,   568,   569,   541,   691,  1932,
    -511,   568,   569,   175,  1989,   550,   552,   554,  1990,  1138,
     176,   559,   257,   257,  1999,  1533,  1534,  1139,  1140,  1141,
    2036,   568,   569,  1142,  1143,  1582,  1583,   672,   672,   971,
     669,   669,   281,   282,  1447,   281,   282,   568,   569,   653,
    2037,  1454,   283,   177,   266,   283,   284,   267,  1117,   289,
     268,   578,   269,  1559,   568,   569,   257,   257,   257,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,   678,   659,   679,   823,   529,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   178,   407,   407,
     407,   407,   936,   179,   407,   407,   407,   941,   180,   496,
     257,  1992,   497,   389,   390,   498,   678,   499,   679,   184,
    -514,  1944,  1945,   656,   657,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,  1219,
     676,   270,   660,   529,   271,   661,   272,   257,   662,  1713,
     663,   258,   978,   774,   678,   776,   679,   778,   779,  1290,
     257,   988,  1504,   678,   259,   679,   257,  1855,  1856,   407,
     291,   717,   999,  1857,   407,   791,   792,   678,  1133,   679,
     260,  1134,   257,  1135,   257,  1590,   824,  1090,   275,   276,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,   299,   722,   795,   727,   529,   717,
    1400,   717,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,   777,   740,   280,   288,
     529,   717,   524,   525,   649,   527,   528,   302,   257,   181,
     541,   529,   182,   312,  1268,   183,  1269,   836,   839,   842,
     845,  1604,  1383,   303,   292,  1859,  1860,  1963,   293,   311,
     315,  1857,   798,  1613,   294,   295,   717,   296,   297,   826,
    1274,   952,  1275,   717,  1120,   953,  1081,   316,  1113,   257,
     717,  1126,   717,  1114,   168,   298,   334,   717,  1130,   323,
     257,  1165,   324,  1146,   325,   717,  1413,   921,   257,   923,
     924,   925,   926,   927,   928,  1370,   930,   931,   932,   933,
    1137,  1166,   938,   939,   940,   717,  1167,   317,  1205,  1236,
     717,   257,   717,   717,  1297,   322,  2017,  1138,   717,  1222,
    1314,  1433,   332,  1228,   717,  1139,  1140,  1141,   937,   333,
     335,  1142,  1143,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,   364,  1319,  1370,
     336,   529,   717,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,   997,   374,  1341,
    1492,   529,  1001,   717,   717,  1665,  1517,  1666,  1540,  1541,
     717,  1542,   717,   717,   380,   717,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,   381,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1006,  1601,  1602,  1543,  2038,
     257,  1267,   717,   402,   403,  1062,  1610,  1064,  1435,   257,
    1611,  1705,  1743,   257,  1774,   717,  1744,  1775,   717,   414,
    1235,   717,   416,  1077,  1078,  1790,  1677,  1678,  1830,  1744,
    1083,   426,  1831,   407,  1316,  1318,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
     431,  1844,  1881,  1896,   529,  1744,   717,  1504,   257,   257,
     445,   257,   481,   257,   257,   495,   257,   484,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   500,   503,   257,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,   376,  1551,  1897,  1903,   529,  1911,
    1590,  1904,  1919,  1744,   504,  1927,   717,  1935,   538,   717,
     539,   702,   257,   407,   407,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,   257,
    1942,  1979,  1980,   529,  1744,  1504,  1504,   545,   546,   257,
     257,   520,   521,   522,   523,   524,   525,   649,   527,   528,
     555,  1181,  1183,  1184,   529,  1995,  1098,  1188,  1189,   717,
     558,  1192,  1193,  1194,  1195,  1996,  1197,   547,  1997,   717,
     548,  1203,   717,   561,   257,   257,   257,   257,  1998,  2000,
    2002,  2028,   717,   717,  1831,  1744,  2039,  2052,  1600,   562,
     717,  2053,   581,  1596,  2066,  1597,  1316,  1318,  1744,  2069,
     582,   583,   584,  2070,   585,   257,   586,   587,   592,  1609,
     597,   595,   598,   608,   599,   600,   601,   604,   257,   257,
     257,   605,   606,   609,   616,   615,   624,   640,   625,   257,
     626,   637,   638,   641,   407,   642,  1265,  1266,   407,   643,
     644,  1254,   646,   658,   664,   677,   684,   407,   683,   407,
     708,  1229,   712,   734,   713,   738,   741,   742,   257,   743,
     744,   771,   782,   784,   785,   786,   529,  1863,   821,   830,
     831,   847,   849,   851,   855,   856,   857,   891,  1213,   893,
     329,   894,   896,   903,   904,   912,   915,  1220,   947,   951,
     955,  1225,   968,   956,   957,   958,   959,   393,   407,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,   972,   973,   974,   982,   529,   976,   257,
     991,  1302,  1303,   993,   996,   257,   998,  1000,  1003,  1007,
    1004,  1008,  1011,  1012,  1014,  1015,  1270,  1271,  1016,  1273,
    1017,  1276,  1277,  1019,  1279,  1020,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1032,  1558,  1033,  1056,  1057,   257,
     257,   257,  1065,  1605,  1070,   257,  1066,   257,  1067,   257,
    1882,   257,  1072,   257,   257,   257,  1735,  1073,  1074,  1075,
    1301,  1079,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,  1080,  1311,  1082,   257,
     529,  1092,  1087,  1093,  1099,  1101,  1102,  1320,  1104,  1103,
     257,  1105,  1106,  1107,  1108,  1109,  1116,  1123,   257,  1124,
    1136,   257,  1131,  1158,  1160,  1187,  1171,  1172,  1173,  1185,
    1174,  1186,  1404,  1198,  1201,  1204,  1406,  1207,  1190,  1210,
    1200,  1211,  1212,  1223,  1231,  1409,  1224,  1410,  1232,  1237,
    1654,  1249,  1253,  1634,  -512,  1256,  1272,  1439,  1608,  1280,
    1278,   407,   407,  1291,  1322,  1323,  1324,  1327,  1342,  1336,
    1337,   329,  1338,  1382,  1339,  1340,  1354,  1355,  1356,  1357,
    1358,   257,  1359,  1363,  1362,  1374,  1393,  1394,  1395,  1373,
     407,  1364,  1375,  1376,  1377,   257,  1449,  1707,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,  1378,
    1379,  1380,  1381,   529,  1493,  1494,  1495,  1496,  1497,  1384,
    1385,  1386,  1387,  1502,  1503,  1505,  1415,  1388,  1389,  1390,
    1391,  1512,  1396,  1460,  1401,  1402,  1407,  1412,  1414,  1421,
    1515,  1411,  1423,  1416,  1426,  1431,  1432,  1697,  1698,  1699,
    1700,  1701,  1703,  1434,  1437,  1438,  1442,  1654,  1443,  1869,
    1446,  1444,  1451,  1456,  1461,  1455,  1464,   257,   257,  1462,
    1465,  1473,  1476,  1469,  1477,   672,   672,  1482,   669,   669,
    1467,  1468,  1474,  1479,  1475,  1886,  1481,  1472,  1483,  1484,
    1485,  1486,  1487,  1478,  1488,  1489,  1490,  1491,  1501,   257,
    1513,  1514,  1516,  1521,  1522,   257,  1530,  1532,  1531,  1538,
    1539,  1549,  1550,  1555,   257,  1556,  1562,  1563,  1564,  1565,
    1566,  1567,   407,  1570,  1584,   407,  1587,  1575,  1572,  1591,
    1576,  1594,  1581,  1599,  1585,   257,  1593,  1518,  1519,  1520,
    1577,  1588,  1606,  1523,  1235,  1524,  1598,  1525,   329,  1526,
     257,  1527,  1528,  1529,  1607,  1937,  1615,  1621,  1620,  -513,
    1622,  1614,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,  1623,  1553,  1625,  1629,
     529,  1635,   257,  1595,  1630,  1636,   257,  1637,  1561,  1640,
    1642,  1644,  1649,  1641,  1732,  1656,  1569,  1964,  1624,  1645,
    1658,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,  1660,  1655,  1661,  1662,   529,
    1663,  1664,  1667,  1679,  1680,  1681,  1682,   257,  1690,  1694,
    1628,  1695,  1704,  1708,  1723,  1731,  1734,  1738,  1747,   257,
    1777,  1751,  1752,  1757,  1759,  1773,  1772,  1778,  1785,  1797,
    1779,  1787,   257,  1781,  1782,  1788,  1804,  1805,  1816,  1619,
    1813,  1799,  1817,  1814,  1818,  1821,  1815,  1820,  1823,  1822,
    1828,  1837,  1838,  1627,  1839,  1840,  1873,  1874,  1875,  1876,
    1877,   257,  1842,  1843,  1866,  1867,  1871,  1885,   257,   257,
    1887,  1883,  1884,  1893,  1915,  1901,  1906,  1918,  1922,  1934,
    1912,   257,  1916,  1923,  1920,  1926,  1672,  1936,  1938,  1939,
     257,  1955,  1960,   257,  1965,  2001,   672,  2010,  2018,   669,
    1984,  2019,  1727,  1728,   257,  2020,  2021,  2023,   257,  2024,
    1718,  2025,  2029,  1720,  2044,  2026,  2043,  2051,  2054,  2062,
    1913,  2067,  2068,  2071,  1917,   407,  2072,  1453,  1973,  1471,
     707,  1657,  1834,   112,   122,  1717,   123,   329,   124,   130,
    1861,     0,   833,   149,  1733,   257,     0,  1761,  1762,     0,
       0,     0,     0,     0,     0,  1729,     0,  1619,     0,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,  1709,     0,   257,   529,  1956,     0,     0,     0,
    1958,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1726,     0,     0,  1970,     0,     0,     0,
       0,  1766,     0,     0,     0,     0,     0,     0,  1737,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1806,  1807,     0,  1950,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
    1619,     0,   529,     0,  1765,   257,   257,   257,   257,   257,
       0,     0,     0,  2015,  2016,  1803,     0,     0,     0,     0,
       0,     0,     0,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1810,  1811,  1812,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1786,     0,     0,     0,   398,
    1819,     0,   404,     0,   257,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1933,
       0,     0,   419,   421,   424,   425,   257,   427,   421,   429,
     430,     0,   432,   421,   434,   435,   436,   437,   438,   439,
       0,   441,   442,   443,     0,     0,     0,   421,     0,  1829,
       0,     0,     0,   407,     0,     0,  1835,  1836,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,  1619,     0,
     407,   407,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1868,     0,     0,     0,     0,   407,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   507,
     509,   510,   421,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,   421,     0,     0,     0,
       0,     0,     0,  1619,     0,     0,     0,     0,     0,     0,
       0,   557,     0,     0,     0,     0,     0,     0,     0,     0,
     566,   567,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,  1914,     0,     0,     0,   588,  1949,     0,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,   607,   529,     0,     0,
     610,   611,   612,     0,   614,     0,     0,     0,   617,   618,
     619,     0,     0,   620,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,  2031,
       0,  1991,   529,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,   648,     0,
       0,   529,   654,     0,     0,  2009,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   666,   668,
       0,  2041,     0,     0,     0,     0,     0,     0,     0,   690,
       0,  1905,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1619,     0,     0,     0,     0,   507,  2063,  2065,
       0,     0,     0,   720,     0,     0,     0,     0,   725,     0,
       0,     0,     0,     0,     0,  2073,     0,     0,     0,     0,
       0,     0,   739,     0,     0,     0,     0,     0,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   767,     0,   772,   773,     0,   775,     0,  1619,     0,
       0,     0,   781,     0,     0,   783,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   767,
       0,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   813,   815,   816,   817,     0,   819,   820,
       0,     0,     0,     0,     0,   827,   828,   829,     0,     0,
       0,     0,   835,   838,   841,   844,   846,     0,   848,     0,
     850,     0,   421,   421,     0,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
     505,   648,   868,   529,     0,     0,   881,   882,   883,   884,
     885,   886,   887,   888,   889,     0,     0,     0,     0,   895,
       0,   897,   898,     0,     0,     0,   421,   421,   421,     0,
       0,   905,   906,   907,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   715,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,   929,  1983,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     421,     0,     0,     0,     0,     0,   945,     0,   819,   820,
       0,     0,     0,     0,     0,   954,     0,     0,     0,     0,
       0,   960,     0,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,   421,     0,     0,
       0,   529,     0,   979,   980,     0,     0,  1675,     0,     0,
     421,  1676,   989,   990,     0,     0,   421,   995,     6,   337,
       0,     0,     0,     0,     0,  1002,     0,     0,     0,  1005,
       0,     0,   813,     0,  1009,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1030,     0,     0,     0,   338,
     339,   340,   341,   342,   343,   344,   345,   346,     0,     0,
       0,     0,   347,   348,   349,   350,     0,     0,     0,   422,
     351,   352,   353,     0,   422,   354,     0,     0,   421,   422,
       0,     0,     0,     0,     0,     0,     0,   355,   514,   356,
       0,     0,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   869,    25,    26,   870,    28,    29,
     871,    31,   872,    33,    34,    35,    36,     0,     0,   421,
      38,    39,    40,     0,     0,    42,   383,     0,     0,     0,
     421,   873,    48,     0,     0,    50,   874,  1097,    53,   875,
       0,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,   508,     0,    70,   422,   529,
       0,   421,     0,     0,     0,     0,     0,     0,  1121,  1122,
       0,     0,   422,     0,  1125,     0,     0,     0,     0,   423,
       0,    84,    85,    86,   428,     0,     0,     0,     0,   433,
       0,     0,     0,   357,   358,   359,     0,     0,  1159,     0,
       0,  1161,     0,   446,     0,     0,   360,     0,   361,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1175,     0,  1177,  1178,     0,     0,     0,     0,     0,     0,
     389,   390,     0,     0,     0,     0,     0,  -510,     0,  1448,
       0,  1196,     0,     0,     7,     8,   514,     0,     0,     0,
     876,     0,     0,     0,     0,     0,  1209,     0,     0,     0,
       0,     0,     0,  1215,  1216,  1217,  1218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1230,     0,     0,
       0,     0,   537,     0,     0,     0,     0,     0,     0,  1252,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,     0,     0,     0,     0,   529,     0,
       0,  1264,     0,     0,     0,     0,     0,     0,     0,   869,
      25,    26,   870,    28,    29,   871,    31,   872,    33,    34,
      35,    36,     0,   508,   916,    38,    39,    40,     0,   421,
      42,     0,     0,     0,     0,     0,   873,    48,     0,     0,
      50,   874,  1293,    53,   875,     0,     0,     0,     0,     0,
    1294,  1295,  1296,     0,     0,     0,     0,  1298,  1299,     0,
    1300,     0,    70,     0,     0,     0,     0,  1305,     0,  1306,
    1307,  1308,  1309,  1310,     0,     0,   768,   769,     0,     0,
       0,  1312,  1313,     0,     0,     0,    84,    85,    86,     0,
     421,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1329,     0,  1331,  1325,  1333,   793,  1335,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1084,
       0,     0,     0,     0,   421,   421,   421,   421,  1353,   814,
       0,     0,     0,     0,     0,  1361,     0,     0,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   715,
     527,   528,     0,     0,     0,   899,   529,     0,   422,   422,
       0,     0,     0,     0,     0,     0,     0,  1392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   421,
       0,     0,     0,     0,     0,     0,     0,  1405,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,   422,   422,   422,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1422,   796,
       0,     0,     0,     0,  1430,     0,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
    1085,     0,     0,     0,   529,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1457,  1459,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   852,   853,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
       0,     0,   422,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   900,   901,   902,     0,     0,     0,   814,     0,
    1010,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,  1535,  1536,  1537,     0,     0,  1398,     0,     0,     0,
       0,  1545,  1546,  1547,  1548,     0,   942,     0,     0,  1552,
       0,  1554,     0,     0,     0,     0,     0,     0,  1557,     0,
       0,     0,     0,     0,   422,     0,     0,     0,     0,     0,
       0,   421,     0,     0,     0,     0,  1573,     0,     0,     0,
       0,     0,     0,   975,  1578,  1579,  1580,     0,     0,     0,
       0,     0,     0,     0,  1589,     0,   987,     0,     0,     0,
       0,     0,   994,     0,     0,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,  1612,     0,     0,     0,  1616,
    1617,     0,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,   422,     0,     0,
     529,     0,     0,     0,  1632,  1633,     0,     0,     0,     0,
       0,  1638,  1639,     0,     0,     0,     0,     0,  1643,     0,
       0,     0,     0,     0,  1059,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1646,  1647,  1648,     0,     0,
       0,     0,     0,     0,  1650,  1651,  1652,  1653,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,  1659,     0,
       0,     0,     0,     0,     0,  1086,     0,   421,   421,  1670,
       0,  1671,     0,     0,     0,     0,  1091,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1687,  1688,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,   421,   529,  1115,     0,  1706,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1716,     0,     0,  1719,     0,     0,     0,   869,    25,    26,
     870,    28,    29,   871,    31,   872,    33,    34,    35,    36,
       0,  1730,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,  1740,     0,   873,    48,     0,  1746,    50,   874,
       0,    53,   875,  1748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,     0,     0,     6,   337,
      70,     0,     0,     0,   949,     0,     0,     0,     0,     0,
       0,     0,  1771,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,     0,  1780,     0,     0,     0,     0,     0,   338,
     339,   340,   341,   342,   343,   344,   345,   346,     0,     0,
    1789,     0,   347,   348,   349,   350,   422,     0,     0,   507,
     351,   352,   353,     0,     0,   354,     0,     0,  1800,  1801,
       0,     0,   421,     0,     0,     0,     0,   355,  1809,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     422,   422,   422,   422,     0,     0,     0,     0,  1826,  1827,
       0,     0,     0,     0,     0,  1292,     0,     0,     0,     0,
       0,     0,     0,     0,  1841,     0,   383,     0,     0,     0,
    1845,  1847,     0,     0,  1849,  1850,  1851,  1852,     0,     0,
       0,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,     0,     0,   421,     0,
       0,     0,     0,     0,     0,     0,  1878,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1321,     0,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,  1889,   357,   358,   359,   529,     0,  1894,  1895,
       0,     0,   983,     0,     0,     0,   360,     0,   361,   107,
    1349,  1350,  1351,  1352,     0,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,  1921,   529,     0,     0,     0,   153,   154,  1071,
       0,     0,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,  1940,  1941,     0,
     529,     0,   678,     0,   679,  1403,     0,     0,  1946,  1947,
    1586,  1948,     0,     0,  1951,  1952,  1953,  1954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1962,     0,     0,     0,     0,   421,   421,   421,   421,   421,
       0,     0,     0,     0,     0,     0,  1746,     0,     0,     0,
    1978,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,   908,     0,     0,     0,     0,     0,     0,     0,   861,
       0,     0,  2004,     0,     0,     0,     0,   397,  2007,  2008,
       0,     0,  2011,  2012,  2013,  2014,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,   421,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,     0,     0,     0,
       0,  1710,     0,     0,     0,  1711,     0,     0,     0,  2045,
    2046,  2047,  2048,  2049,  2050,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   475,   476,   477,
     478,   479,   480,     0,   482,   483,     0,     0,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,   501,
     502,     0,     0,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,  1571,   185,     6,
     337,   529,   382,   714,     0,   186,   187,   188,     0,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   422,   422,     0,     0,     0,     0,     0,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   217,
     218,   219,   220,   347,   348,   349,   350,   221,     0,     0,
       0,   351,   352,   353,     0,     0,   354,     0,   222,   223,
     224,   422,     0,     0,     0,     0,   225,    21,   355,     0,
     356,     0,     0,   621,   622,   623,   337,     0,     0,   627,
     628,   629,   630,   631,   632,   633,     0,   634,     0,     0,
     635,   636,     0,     0,   639,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   383,     0,     0,
       0,     0,     0,     0,     0,     0,   338,   339,   340,   341,
     342,   343,   344,   345,   346,     0,     0,     0,     0,   347,
     348,   349,   350,  1668,  1669,     0,     0,   351,   352,   353,
       0,     0,   354,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,   355,     0,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   384,     0,     0,     0,
       0,     0,     0,   233,   357,   358,   359,   234,     0,     0,
       0,     0,   236,   237,   238,   239,   240,   360,     0,   361,
     107,   385,   386,   387,   388,   508,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   371,     0,     0,   422,   243,
       0,   389,   390,     0,   391,     0,   392,     0,   393,     0,
     394,   246,     0,     0,   869,    25,    26,   870,    28,    29,
     871,    31,   872,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     7,     8,   799,     0,
       0,   873,    48,     0,     0,    50,   874,  1848,    53,   875,
     357,   358,   359,     0,     0,     0,     0,     0,     0,   422,
       0,     0,     0,   360,     0,   361,     0,    70,     0,     0,
       0,     0,     0,     0,   422,     0,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,    84,    85,    86,   529,     0,     0,     0,     0,     0,
    1864,     0,     0,     0,  1865,     0,     0,     0,  1802,     0,
       0,   869,    25,    26,   870,    28,    29,   871,    31,   872,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   873,    48,
       0,     0,    50,   874,     0,    53,   875,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     943,     0,     0,     0,    70,     0,     0,     0,     0,  1862,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1872,     0,     0,     0,    84,    85,
      86,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,   422,   422,   422,   422,   422,   185,     6,   337,   700,
       0,     0,     0,   186,   187,   188,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,     0,   944,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   217,   218,   219,
     220,   347,   348,   349,   350,   221,     0,     0,     0,   351,
     352,   353,   422,     0,   354,     0,   222,   223,   224,     0,
       0,     0,     0,     0,   225,    21,   355,     0,   356,     0,
       0,   226,     0,     0,   227,     0,     0,   228,     0,   229,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,  1966,  1967,  1968,  1969,  1971,     0,     0,   230,     0,
      49,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   861,
       0,     0,  2022,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   357,   358,   359,   234,   235,     0,     0,     0,
     236,   237,   238,   239,   240,   360,     0,   361,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,   242,     0,     0,     0,   243,     0,     0,
       0,     0,   319,   185,     6,   337,   245,     0,     0,   246,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     0,     0,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   217,   218,   219,   220,   347,   348,
     349,   350,   221,     0,     0,     0,   351,   352,   353,     0,
       0,   354,     0,   222,   223,   224,     0,     0,     0,     0,
       0,   225,    21,   355,     0,   356,     0,     0,   226,     0,
       0,   227,     0,     0,   228,     0,   229,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,    49,     0,     0,
     231,     0,   232,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   357,
     358,   359,   234,   235,     0,     0,     0,   236,   237,   238,
     239,   240,   360,     0,   361,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,     0,     0,     0,   243,     0,     0,     0,     0,   319,
       0,     0,     0,  1764,     0,     0,   246,     0,     0,     0,
     185,     6,   318,     0,     0,     0,     0,   186,   187,   188,
       0,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   218,   219,   220,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,  1424,  1425,
     222,   223,   224,     0,     0,     0,     0,     0,   225,    21,
       0,     0,  1440,     0,     0,   226,     0,     0,   227,     0,
       0,   228,     0,   229,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,     0,    49,     0,     0,   231,     0,   232,
       0,     0,     0,     0,     6,   337,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   913,     0,     0,     0,   347,   348,
     349,   350,     0,     0,     0,   233,   351,   352,   353,   234,
     235,   354,     0,     0,   236,   237,   238,   239,   240,     0,
       0,     0,   107,   355,     0,   356,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   242,     0,     0,
       0,   243,     0,     0,     0,     0,   319,   185,     6,  1560,
     245,     0,     0,   246,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   218,
     219,   220,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
       0,     0,     0,     0,     0,   225,    21,     0,     0,   357,
     358,   359,   226,     0,     0,   227,     0,     0,   228,     0,
     229,     0,   360,     0,   361,   107,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,    49,     0,     0,   231,     0,   232,     0,     0,     0,
       0,   365,   337,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,   338,   339,   340,   341,   342,   343,   344,   345,
     346,  1045,     0,     0,     0,   347,   348,   349,   350,     0,
       0,     0,   233,   351,   352,   353,   234,   235,   354,     0,
       0,   236,   237,   238,   239,   240,     0,     0,     0,   107,
     355,     0,   356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,   242,     0,     0,     0,   243,     0,
       0,     0,     0,   319,   185,     6,     0,   245,     0,     0,
     246,   186,   187,   188,     0,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   218,   219,   220,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,     0,     0,     0,
       0,     0,   225,    21,     0,     0,   357,   358,   359,   226,
       0,     0,   227,     0,     0,   228,     0,   229,     0,   360,
       0,   361,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,     0,    49,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1053,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,   234,   235,     0,     0,     0,   236,   237,
     238,   239,   240,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     573,  1702,     0,     0,     0,   243,     0,     0,     0,     0,
     575,   185,     6,     0,   284,   511,     0,   246,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   218,   219,   220,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,     0,     0,     0,     0,     0,   225,
      21,     0,     0,     0,     0,     0,   226,     0,     0,   227,
       0,     0,   228,     0,   229,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,     0,    49,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1054,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
     234,   235,     0,     0,     0,   236,   237,   238,   239,   240,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,     0,
       0,     0,   243,     0,     0,     0,     0,   244,   185,     6,
       0,   245,     0,     0,   246,   186,   187,   188,     0,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     218,   219,   220,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,     0,     0,     0,     0,     0,   225,    21,     0,     0,
       0,     0,     0,   226,     0,     0,   227,     0,     0,   228,
       0,   229,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,    49,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1055,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,   234,   235,     0,
       0,     0,   236,   237,   238,   239,   240,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   242,     0,     0,     0,   243,
       0,     0,     0,     0,   319,   185,     6,     0,   245,     0,
       0,   246,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   218,   219,   220,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,     0,     0,
       0,     0,     0,   225,    21,     0,     0,     0,     0,     0,
     226,     0,     0,   227,     0,     0,   228,     0,   229,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,    49,
       0,     0,   231,     0,   232,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1060,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,   234,   235,     0,     0,     0,   236,
     237,   238,   239,   240,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   420,     0,     0,     0,   243,     0,     0,     0,
       0,   319,   185,     6,     0,   506,     0,     0,   246,   186,
     187,   188,     0,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   217,   218,   219,   220,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,     0,     0,     0,     0,     0,
     225,    21,     0,     0,     0,     0,     0,   226,     0,     0,
     227,     0,     0,   228,     0,   229,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,    49,     0,     0,   231,
       0,   232,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1061,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,     0,
       0,   234,   235,     0,     0,     0,   236,   237,   238,   239,
     240,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   420,
       0,     0,     0,   243,     0,     0,     0,     0,   319,   185,
       6,     0,     0,   511,     0,   246,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,   218,   219,   220,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,     0,     0,     0,     0,     0,   225,    21,     0,
       0,     0,     0,     0,   226,     0,     0,   227,     0,     0,
     228,     0,   229,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,    49,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1063,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,     0,     0,   234,   235,
       0,     0,     0,   236,   237,   238,   239,   240,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   242,     0,     0,     0,
     243,     0,     0,     0,     0,   540,   185,     6,     0,   245,
       0,     0,   246,   186,   187,   188,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,   218,   219,
     220,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,     0,
       0,     0,     0,     0,   225,    21,     0,     0,     0,     0,
       0,   226,     0,     0,   227,     0,     0,   228,     0,   229,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,     0,
      49,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,     0,     0,   234,   235,     0,     0,     0,
     236,   237,   238,   239,   240,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,   242,     0,     0,     0,   243,     0,     0,
       0,     0,   549,   185,     6,     0,   245,     0,     0,   246,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   217,   218,   219,   220,     0,     0,
       0,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,     0,     0,     0,     0,
       0,   225,    21,     0,     0,     0,     0,     0,   226,     0,
       0,   227,     0,     0,   228,     0,   229,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,    49,     0,     0,
     231,     0,   232,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,   234,   235,     0,     0,     0,   236,   237,   238,
     239,   240,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,     0,     0,     0,   243,     0,     0,     0,     0,   551,
     185,     6,     0,   245,     0,     0,   246,   186,   187,   188,
       0,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   218,   219,   220,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,     0,     0,     0,     0,     0,   225,    21,
       0,     0,     0,     0,     0,   226,     0,     0,   227,     0,
       0,   228,     0,   229,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,     0,    49,     0,     0,   231,     0,   232,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,   234,
     235,     0,     0,     0,   236,   237,   238,   239,   240,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   242,     0,     0,
       0,   243,     0,     0,     0,     0,   553,   185,     6,     0,
     245,     0,     0,   246,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   218,
     219,   220,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
       0,     0,     0,     0,     0,   225,    21,     0,     0,     0,
       0,     0,   226,     0,     0,   227,     0,     0,   228,     0,
     229,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,    49,     0,     0,   231,     0,   232,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1345,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,   234,   235,     0,     0,
       0,   236,   237,   238,   239,   240,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,   420,     0,     0,     0,   243,     0,
       0,     0,     0,   319,   185,     6,     0,   812,     0,     0,
     246,   186,   187,   188,     0,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   218,   219,   220,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,     0,     0,     0,
       0,     0,   225,    21,     0,     0,     0,     0,     0,   226,
       0,     0,   227,     0,     0,   228,     0,   229,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,     0,    49,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1346,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,   234,   235,     0,     0,     0,   236,   237,
     238,   239,   240,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   242,     0,     0,     0,   243,     0,     0,     0,     0,
     319,   185,     6,     0,  1568,     0,     0,   246,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   218,   219,   220,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,     0,     0,     0,     0,     0,   225,
      21,     0,     0,     0,     0,     0,   226,     0,     0,   227,
       0,     0,   228,     0,   229,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,     0,    49,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
     234,   235,     0,     0,     0,   236,   237,   238,   239,   240,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   573,  1702,     0,
       0,     0,   243,     0,     0,     0,     0,   575,   185,     6,
       0,   284,     0,     0,   246,   186,   187,   188,     0,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     218,   219,   220,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,     0,     0,     0,     0,     0,   225,    21,     0,     0,
       0,     0,     0,   226,     0,     0,   227,     0,     0,   228,
       0,   229,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,    49,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1498,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,   234,   235,     0,
       0,     0,   236,   237,   238,   239,   240,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   420,     0,     0,     0,   243,
     185,     6,   337,     0,   319,     0,     0,   186,   187,   188,
       0,   246,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,     0,     0,     0,
       0,     0,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   217,   218,   219,   220,   347,   348,   349,   350,   221,
       0,     0,     0,   351,   352,   353,     0,     0,   354,     0,
     222,   223,   224,     0,     0,     0,     0,     0,   225,    21,
     355,     0,   356,   185,     6,   337,     0,     0,     0,     0,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   217,   218,   219,   220,   347,   348,
     349,   350,   221,     0,     0,     0,   351,   352,   353,     0,
       0,   354,     0,   222,   223,   224,     0,     0,     0,     0,
       0,   225,    21,   355,     0,   356,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,   233,   357,   358,   359,   234,
    1150,     0,     0,     0,   236,   237,   238,   239,   240,   360,
       0,   361,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   371,     0,     0,
       0,   243,     0,     0,     0,     0,   319,     0,     0,     0,
    1458,     0,     0,   246,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1499,     0,     0,     0,     0,     0,   233,   357,
     358,   359,   234,     0,     0,     0,     0,   236,   237,   238,
     239,   240,   360,     0,   361,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     371,     0,     0,     0,   243,     0,     0,     0,     0,   319,
     185,     6,   337,  1715,     0,     0,   246,   186,   187,   188,
       0,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,     0,     0,     0,
       0,     0,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   217,   218,   219,   220,   347,   348,   349,   350,   221,
       0,     0,     0,   351,   352,   353,     0,     0,   354,     0,
     222,   223,   224,     0,     0,     0,     0,     0,   225,    21,
     355,     0,   356,   185,     6,   337,     0,     0,     0,     0,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   217,   218,   219,   220,   347,   348,
     349,   350,   221,     0,     0,     0,   351,   352,   353,     0,
       0,   354,     0,   222,   223,   224,     0,     0,     0,     0,
       0,   225,    21,   355,     0,   356,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,   233,   357,   358,   359,   234,
    1214,     0,     0,     0,   236,   237,   238,   239,   240,   360,
       0,   361,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   371,     0,     0,
       0,   243,     0,     0,     0,     0,   319,     0,     0,     0,
    1808,     0,     0,   246,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1500,     0,     0,     0,     0,     0,   233,   357,
     358,   359,   234,     0,     0,     0,     0,   236,   237,   238,
     239,   240,   360,     0,   361,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     371,     0,     0,     0,   243,   185,     6,     0,     0,   319,
       0,     0,   186,   187,   188,     0,   246,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
       0,     0,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,   217,   218,   219,   220,
     529,     0,     0,     0,   221,     0,     0,     0,     0,     0,
    1507,     0,     0,   185,     6,   222,   223,   224,     0,     0,
     186,   187,   188,   225,    21,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,     0,     0,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,   217,   218,   219,   220,   529,     0,
       0,     0,   221,     0,     0,     0,     0,     0,  1508,     0,
       0,     0,     0,   222,   223,   224,     0,     0,     0,     0,
       0,   225,    21,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1509,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,   234,     0,     0,     0,     0,   236,
     237,   238,   239,   240,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   371,     0,     0,     0,   243,     0,     0,     0,
       0,   319,     0,     0,     0,   556,     0,     0,   246,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,   233,     0,
       0,     0,   234,  1347,     0,     0,     0,   236,   237,   238,
     239,   240,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
     574,     0,     0,     0,   243,     0,     0,     0,     0,   575,
       0,   185,     6,   284,  1208,     0,   246,     0,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,     0,     0,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,   217,   218,   219,   220,   529,     0,     0,     0,
     221,     0,     0,     0,     0,     0,  1510,     0,     0,     0,
       0,   222,   223,   224,   185,     6,     0,  1360,     0,   225,
      21,   186,   187,   188,     0,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,   217,   218,   219,   220,   529,
       0,     0,     0,   221,     0,     0,     0,     0,     0,  1626,
       0,     0,     0,     0,   222,   223,   224,     0,     0,     0,
       0,     0,   225,    21,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1741,     0,     0,     0,   233,     0,     0,     0,
     234,     0,     0,     0,     0,   236,   237,   238,   239,   240,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   371,     0,
       0,     0,   243,     0,     0,     0,     0,   319,     0,     0,
       0,     0,     0,     0,   246,     0,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,   233,
       0,     0,     0,   234,  1742,     0,     0,     0,   236,   237,
     238,   239,   240,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   371,     0,     0,     0,   243,   185,     6,     0,     0,
     319,     0,     0,   186,   187,   188,     0,   246,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,   218,   219,
     220,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,     0,
       0,     0,     0,     0,   225,    21,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1763,     0,     0,     0,     0,   869,
      25,    26,   870,    28,    29,   871,    31,   872,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   873,    48,     0,     0,
      50,   874,     0,    53,   875,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,    70,     0,     0,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,   233,     0,   529,     0,   234,    84,    85,    86,  1417,
     236,   237,   238,   239,   240,     7,     8,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,   371,     0,     0,     0,   243,     0,     0,
       0,     0,   319,     0,     0,     0,     0,     0,     0,   246,
     869,    25,    26,   870,    28,    29,   871,    31,   872,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     7,
       8,    42,     0,     0,     0,  1118,     0,   873,    48,     0,
       0,    50,   874,     0,    53,   875,     0,     0,     0,     0,
     869,    25,    26,   870,    28,    29,   871,    31,   872,    33,
      34,    35,    36,    70,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   873,    48,     0,
       0,    50,   874,     0,    53,   875,     0,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,   869,    25,    26,   870,    28,    29,
     871,    31,   872,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     7,     8,    42,     0,    84,    85,    86,
       0,   873,    48,     0,     0,    50,   874,     0,    53,   875,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,  1119,    70,   529,     0,
       0,     7,     8,     0,     0,     0,     0,     0,  1767,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1147,     0,   869,    25,
      26,   870,    28,    29,   871,    31,   872,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   873,    48,     0,     0,    50,
     874,     0,    53,   875,     0,     0,   869,    25,    26,   870,
      28,    29,   871,    31,   872,    33,    34,    35,    36,     0,
    1176,    70,    38,    39,    40,     7,     8,    42,     0,     0,
       0,     0,     0,   873,    48,     0,     0,    50,   874,     0,
      53,   875,     0,     0,     0,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     7,     8,     0,     0,     0,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,    84,    85,    86,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1768,     0,     0,     0,
     869,    25,    26,   870,    28,    29,   871,    31,   872,    33,
      34,    35,    36,     0,  1206,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   873,    48,     0,
       0,    50,   874,     0,    53,   875,     0,     0,   869,    25,
      26,   870,    28,    29,   871,    31,   872,    33,    34,    35,
      36,     0,  1343,    70,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   873,    48,     0,     0,    50,
     874,     0,    53,   875,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,    84,    85,    86,     0,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,    -4,    -4,     0,     0,  1924,  1769,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,    -4,    -4,    -4,     0,   529,     0,    -4,    -4,
       0,    -4,  1418,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,    -4,     0,     0,  1993,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       6,     0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,
       8,     0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     9,
      10,     0,     0,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,    14,    15,     0,    16,     0,
       0,     0,    17,    18,     0,    19,    20,     0,    21,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,    37,
      38,    39,    40,    41,     0,    42,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     7,     8,     0,    79,
      80,    81,     0,     0,     0,    82,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   106,
       0,   107,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,   869,    25,    26,   870,    28,    29,   871,    31,   872,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   873,    48,
       0,     0,    50,   874,     0,    53,   875,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,    70,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1770,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1832,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1890,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1891,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1902,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1907,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1908,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1909,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1910,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1943,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1975,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1981,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1982,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1985,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1986,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1987,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1988,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2032,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2033,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2034,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2035,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1419,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1420,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1673,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1692,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1753,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1754,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1755,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1756,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1758,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1783,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1798,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1853,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1870,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1879,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1880,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    1900,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  1961,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    2006,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  2030,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    2056,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  2057,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    2058,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  2059,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,     0,
    2060,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,  2061,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,     0,   650,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
       0,     0,     0,   854,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,     0,  1776,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,   678,     0,
     679,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,   919,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,   967,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,     0,     0,  1089,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
       0,     0,  1163,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,     0,     0,  1164,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,     0,     0,  1168,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,     0,
       0,  1169,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,     0,     0,  1251,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,     0,     0,  1258,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,     0,     0,
    1450,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,     0,     0,  1574,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,     0,     0,  1736,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,     0,     0,  1784,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
     718,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,   719,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,   721,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,   723,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,   724,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,   726,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,   728,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,   729,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,   730,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,   731,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
     732,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,   733,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,   735,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,   736,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,   737,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,   797,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,   825,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,   890,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,   908,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,   909,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
     910,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,   911,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,   917,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,   918,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,   948,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,   963,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,  1013,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,  1018,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,  1031,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,  1088,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
    1094,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,  1095,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,  1096,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,  1110,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,  1111,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,  1112,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,  1149,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,  1151,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,  1152,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,  1153,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
    1154,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,  1155,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,  1156,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,  1157,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,  1162,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,  1250,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,  1257,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,  1511,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   649,
     527,   528,     0,     0,     0,     0,   529,     0,  1544,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     649,   527,   528,     0,     0,     0,     0,   529,     0,  1674,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   649,   527,   528,     0,     0,     0,     0,   529,     0,
    1683,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   649,   527,   528,     0,     0,     0,     0,   529,
       0,  1684,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   649,   527,   528,     0,     0,     0,     0,
     529,     0,  1685,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   649,   527,   528,     0,     0,     0,
       0,   529,     0,  1686,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   649,   527,   528,     0,     0,
       0,     0,   529,     0,  1691,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   649,   527,   528,     0,
       0,     0,     0,   529,     0,  1714,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   649,   527,   528,
       0,     0,     0,     0,   529,     0,  1974,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   649,   527,
     528,     0,     0,     0,     0,   529,     0,  2027
};

static const yytype_int16 yycheck[] =
{
       3,     7,   277,     3,    60,    61,   484,    63,   570,   571,
    1148,  1596,  1597,   688,     4,     4,  1144,  1264,    21,   665,
     289,   667,   697,  1562,     4,     4,     4,   673,   132,     4,
       4,     4,     4,     4,   237,     4,     4,   306,     5,     5,
     181,   182,   183,     5,    47,     6,     5,     5,     4,    94,
       6,     4,     4,     4,     4,    94,   170,     5,     9,     0,
       7,     6,   229,     6,     6,   125,   233,     6,   226,   227,
     115,    74,   186,   187,     9,    91,   115,   235,    94,    82,
     219,   220,   142,     7,    87,     6,     9,   125,     6,   229,
     150,   151,   152,   233,   233,    98,   156,   157,     6,   368,
       6,   370,     6,   230,   142,   232,  1645,   376,     6,     9,
      94,   238,   150,   151,   152,    14,   219,   220,   156,   157,
     219,   220,   263,   264,   265,   219,   220,     9,   229,   132,
     219,   220,    88,   136,   137,   238,   219,   220,   229,   238,
     230,   144,   232,   621,   238,   623,   219,   220,   238,   238,
     229,   154,   231,   156,   230,   238,   219,   220,   161,   300,
     301,   302,   238,   166,    94,   238,    96,     7,   219,   220,
     173,     6,   313,   314,   177,   238,   230,   180,   181,   182,
     183,   184,   219,   220,   238,     6,   230,   238,   232,   160,
     161,   162,   163,   229,   238,   231,   234,   234,   170,   171,
     206,   207,   208,   209,     7,     6,   181,   173,     7,   219,
     220,   173,   185,   158,   173,   173,     8,   170,   171,   158,
     226,   227,   226,   227,   280,   281,   205,   230,   238,   235,
     205,   205,   288,   289,  1773,   229,   205,   205,   230,   242,
     229,   231,   245,   246,  1372,     7,   238,   237,   229,   229,
       6,   229,   233,   233,   205,   233,   259,   236,   233,   262,
     263,   264,   265,   234,   233,   233,   233,   270,   271,   272,
       6,   233,   233,   276,   277,   226,   227,   229,   229,   229,
     231,   233,   233,   233,   235,   233,   229,     7,   235,  1828,
     233,   233,   561,   562,   229,   216,   231,   300,   301,   302,
     235,   219,   220,   226,   227,   229,   229,   231,   231,   578,
     313,   314,   235,   219,   220,   219,   220,   963,   216,     6,
     230,   967,    47,     4,   219,   220,   226,   227,   238,   229,
      98,   231,   100,   233,   231,   235,   230,   132,   232,   233,
     230,   136,   137,   238,   226,   227,   615,   229,   238,   231,
     232,   233,  1937,   235,   230,   496,   497,   498,   499,   232,
     219,   220,   238,   231,   132,   238,   206,   207,   208,   209,
     234,   374,   219,   220,   238,   378,   379,   229,   173,   238,
     230,   650,   219,   220,   229,   153,   226,   227,   238,   184,
     393,   238,   395,   393,   232,     6,   219,   220,   401,    91,
     238,   238,    94,   206,   207,   208,   209,   206,   207,   208,
     209,    91,  1087,   416,    94,   238,    96,   420,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   221,   222,   223,   235,   228,   237,  1977,   228,
     219,   220,   234,   229,   206,   207,   208,   209,   129,   130,
     131,   132,   177,     8,   219,   220,  1102,   229,  1104,   238,
    1106,   232,  1108,   144,   226,   227,   147,   238,   219,   220,
     473,   474,   229,   238,   229,   478,   233,   480,   481,   482,
     483,   484,   233,   230,   125,   232,   206,   207,   208,   209,
     229,   238,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   142,  1749,   506,  2043,   230,   226,   227,   229,   150,
     151,   152,   568,   569,   229,   156,   157,   573,     8,   229,
     219,   220,   229,   526,   205,   219,   220,   530,   229,   219,
     220,   229,   125,   226,   227,   219,   220,   262,     6,   238,
     233,   219,   220,   229,   238,   270,   271,   272,   238,   142,
     229,   276,   555,   556,   238,     6,     7,   150,   151,   152,
     238,   219,   220,   156,   157,     6,     7,   570,   571,   673,
     570,   571,   219,   220,  1249,   219,   220,   219,   220,   374,
     238,  1256,   229,   108,    88,   229,   233,    91,   857,   233,
      94,   233,    96,   234,   219,   220,   599,   600,   601,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   230,   382,   232,   233,   228,   621,   622,
     623,   624,   625,   626,   627,   628,   629,    94,   631,   632,
     633,   634,   635,     6,   637,   638,   639,   640,   233,    88,
     643,   234,    91,   226,   227,    94,   230,    96,   232,   229,
     233,  1898,  1899,   378,   379,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     6,
     395,    91,    88,   228,    94,    91,    96,   680,    94,   234,
      96,   229,   685,   478,   230,   480,   232,   482,   483,     6,
     693,   694,   238,   230,   233,   232,   699,   129,   130,   702,
       4,   238,   705,   135,   707,   500,   501,   230,    91,   232,
      94,    94,   715,    96,   717,   238,   535,   821,   229,    91,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   229,   234,   504,   234,   228,   238,
     230,   238,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   481,   234,   233,   233,
     228,   238,   219,   220,   221,   222,   223,    94,   771,    88,
     495,   228,    91,    94,    94,    94,    96,   545,   546,   547,
     548,  1427,     6,    91,    88,   129,   130,  1925,    92,    91,
       4,   135,   234,  1439,    98,    99,   238,   101,   102,   234,
      94,   234,    96,   238,   860,   238,   234,     4,   234,   812,
     238,   867,   238,   234,   229,   119,     6,   238,   233,   229,
     823,   234,   229,   879,   229,   238,     6,   622,   831,   624,
     625,   626,   627,   628,   629,  1963,   631,   632,   633,   634,
     125,   234,   637,   638,   639,   238,   234,     4,   234,   234,
     238,   854,   238,   238,   234,     4,  1994,   142,   238,   963,
     234,     6,   229,   967,   238,   150,   151,   152,   636,   229,
       6,   156,   157,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   229,   234,  2017,
     231,   228,   238,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   702,   231,   234,
     234,   228,   707,   238,   238,     4,   234,     6,   234,   234,
     238,   234,   238,   238,     6,   238,   745,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   237,   757,   758,
     759,   760,   761,   762,   763,   713,  1424,  1425,   234,   234,
     953,  1007,   238,   233,     6,   774,   234,   776,  1233,   962,
     238,   234,   234,   966,   234,   238,   238,   234,   238,   229,
     973,   238,     9,   792,   793,   234,  1538,  1539,   234,   238,
     799,   229,   238,   986,  1088,  1089,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     229,   234,   234,   234,   228,   238,   238,   238,  1011,  1012,
     229,  1014,   229,  1016,  1017,   115,  1019,   229,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,   229,   229,  1032,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   233,     6,   234,   234,   228,   234,
     238,   238,   234,   238,   229,   234,   238,   234,   229,   238,
     229,   238,  1065,  1066,  1067,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,  1082,
     234,   234,   234,   228,   238,   238,   238,   229,   229,  1092,
    1093,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     233,   920,   921,   922,   228,   234,   831,   926,   927,   238,
       4,   930,   931,   932,   933,   234,   935,   229,   234,   238,
     229,   940,   238,   233,  1127,  1128,  1129,  1130,   234,   234,
     234,   234,   238,   238,   238,   238,   234,   234,     6,   233,
     238,   238,   229,  1412,   234,  1414,  1250,  1251,   238,   234,
     229,   229,   229,   238,   229,  1158,   229,   229,   229,  1434,
       6,   231,     6,     6,   233,   233,   233,   231,  1171,  1172,
    1173,   231,   231,     6,   173,   233,   229,   231,   229,  1182,
     229,   229,   229,     6,  1187,     6,  1005,  1006,  1191,   233,
       6,   986,     6,   233,     7,     6,     6,  1200,   233,  1202,
      84,   969,   238,   230,   238,     7,     6,     6,  1211,     6,
     230,   233,    63,    63,    63,    63,   228,  1779,     4,     7,
       7,     6,     6,     6,   230,     6,   233,     7,   953,     6,
    1233,     7,     6,     6,     6,   170,   233,   962,   232,   230,
       6,   966,   234,   233,   233,   233,   233,   233,  1251,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   235,     7,     6,   231,   228,     7,  1272,
       4,  1066,  1067,     6,     6,  1278,     6,     6,   230,     7,
     231,   173,     7,     7,     7,   173,  1011,  1012,     7,  1014,
       7,  1016,  1017,     7,  1019,   173,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   233,  1371,     6,   230,   232,  1322,
    1323,  1324,   238,  1427,   233,  1328,   238,  1330,   238,  1332,
    1808,  1334,   233,  1336,  1337,  1338,  1611,   233,   233,   238,
    1065,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   230,  1082,     7,  1362,
     228,     7,   235,   233,     4,     6,   230,  1092,   230,   238,
    1373,   238,   230,   238,   230,   238,   235,   234,  1381,   234,
     125,  1384,   229,     7,     6,   238,     7,     7,     7,   230,
     235,   230,  1187,     9,   230,   232,  1191,     7,   238,   234,
     238,   233,     6,    45,     6,  1200,    45,  1202,     4,    45,
    1514,   235,   216,  1469,   233,   235,     7,  1236,     6,    96,
       7,  1424,  1425,     7,     7,     7,     7,     6,     4,     7,
       7,  1434,     7,  1158,     7,     7,   229,   229,   229,   229,
     106,  1444,     4,     6,   233,     6,  1171,  1172,  1173,     7,
    1453,   229,     7,     7,     7,  1458,  1251,     6,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     7,
       7,     7,     7,   228,  1293,  1294,  1295,  1296,  1297,   233,
       6,     6,     6,  1302,  1303,  1304,  1211,    94,     7,     6,
       6,  1310,     4,  1261,     4,     4,   236,   233,   233,     6,
    1319,   238,     6,   234,     6,     6,     6,  1563,  1564,  1565,
    1566,  1567,  1568,     7,     6,   231,   229,  1621,   229,  1788,
       6,   233,     6,     6,   230,   235,     6,  1530,  1531,   232,
       6,     6,     6,   119,     6,  1538,  1539,     6,  1538,  1539,
     233,   233,   233,   173,   233,  1820,   233,  1272,     6,     6,
       6,     6,     6,  1278,     6,     6,     6,     5,   230,  1562,
       6,     4,     6,     4,     6,  1568,   233,     7,   233,   233,
     233,   233,   231,     6,  1577,     6,   233,   233,   233,   233,
     233,   233,  1585,     6,  1403,  1588,  1405,     6,   233,  1408,
       6,  1410,     6,     6,   238,  1598,   230,  1322,  1323,  1324,
     169,   238,   235,  1328,  1607,  1330,   238,  1332,  1611,  1334,
    1613,  1336,  1337,  1338,     7,  1884,   229,     4,   233,   233,
       6,  1440,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,     6,  1362,     4,     7,
     228,     6,  1645,  1411,     7,     6,  1649,     6,  1373,     6,
       6,     5,     4,    92,     4,     6,  1381,  1926,  1453,   233,
       6,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     6,   233,     6,     6,   228,
       6,     6,     6,     6,     6,     6,     6,  1690,   238,     6,
    1458,     6,     6,     6,   238,     6,     6,     6,     6,  1702,
       6,   233,   233,   233,     5,   233,     6,     6,     6,     6,
     233,     7,  1715,   234,   234,   233,     6,   230,     6,  1444,
     234,   168,     6,   234,     6,     6,   234,     7,     6,   235,
     233,     6,     6,  1458,     6,     6,  1792,  1793,  1794,  1795,
    1796,  1744,     6,     6,     6,   234,     6,     6,  1751,  1752,
     171,   230,   233,     6,     6,   233,     7,     6,     6,     6,
     233,  1764,   233,   125,   234,   233,  1534,     6,     6,   233,
    1773,     6,     6,  1776,     6,   234,  1779,   230,     6,  1779,
     229,     6,  1601,  1602,  1787,     6,     6,     6,  1791,     6,
    1585,     6,     6,  1588,     6,   233,   233,     6,   233,     6,
    1856,     6,     6,     6,  1860,  1808,     6,  1255,  1939,  1271,
     413,  1519,  1750,     3,     3,  1583,     3,  1820,     3,     3,
    1775,    -1,   544,    21,  1607,  1828,    -1,  1646,  1647,    -1,
      -1,    -1,    -1,    -1,    -1,  1603,    -1,  1562,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,  1577,    -1,  1857,   228,  1912,    -1,    -1,    -1,
    1916,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1598,    -1,    -1,  1932,    -1,    -1,    -1,
      -1,  1649,    -1,    -1,    -1,    -1,    -1,    -1,  1613,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1719,  1720,    -1,  1906,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
    1645,    -1,   228,    -1,  1649,  1928,  1929,  1930,  1931,  1932,
      -1,    -1,    -1,  1989,  1990,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1721,  1722,  1723,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1690,    -1,    -1,    -1,   132,
       6,    -1,   135,    -1,  1977,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,   155,   156,   157,   158,  1999,   160,   161,   162,
     163,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,  1744,
      -1,    -1,    -1,  2026,    -1,    -1,  1751,  1752,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2043,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1773,    -1,
    2053,  2054,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1787,    -1,    -1,    -1,    -1,  2070,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,   259,    -1,    -1,    -1,
      -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     283,   284,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,
      -1,    -1,  1857,    -1,    -1,    -1,   299,  1905,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,   319,   228,    -1,    -1,
     323,   324,   325,    -1,   327,    -1,    -1,    -1,   331,   332,
     333,    -1,    -1,   336,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,  2008,
      -1,     6,   228,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,   371,    -1,
      -1,   228,   375,    -1,    -1,  1983,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,   392,
      -1,  2026,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1977,    -1,    -1,    -1,    -1,   420,  2053,  2054,
      -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,   431,    -1,
      -1,    -1,    -1,    -1,    -1,  2070,    -1,    -1,    -1,    -1,
      -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,    -1,   476,   477,    -1,   479,    -1,  2043,    -1,
      -1,    -1,   485,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,    -1,   531,   532,
      -1,    -1,    -1,    -1,    -1,   538,   539,   540,    -1,    -1,
      -1,    -1,   545,   546,   547,   548,   549,    -1,   551,    -1,
     553,    -1,   555,   556,    -1,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     573,   574,   575,   228,    -1,    -1,   579,   580,   581,   582,
     583,   584,   585,   586,   587,    -1,    -1,    -1,    -1,   592,
      -1,   594,   595,    -1,    -1,    -1,   599,   600,   601,    -1,
      -1,   604,   605,   606,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,   630,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     643,    -1,    -1,    -1,    -1,    -1,   649,    -1,   651,   652,
      -1,    -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,
      -1,   664,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   680,    -1,    -1,
      -1,   228,    -1,   686,   687,    -1,    -1,   234,    -1,    -1,
     693,   238,   695,   696,    -1,    -1,   699,   700,     4,     5,
      -1,    -1,    -1,    -1,    -1,   708,    -1,    -1,    -1,   712,
      -1,    -1,   715,    -1,   717,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   738,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,   156,
      66,    67,    68,    -1,   161,    71,    -1,    -1,   771,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,     8,    85,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   812,
     104,   105,   106,    -1,    -1,   109,   122,    -1,    -1,    -1,
     823,   115,   116,    -1,    -1,   119,   120,   830,   122,   123,
      -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   242,    -1,   141,   245,   228,
      -1,   854,    -1,    -1,    -1,    -1,    -1,    -1,   861,   862,
      -1,    -1,   259,    -1,   867,    -1,    -1,    -1,    -1,   156,
      -1,   165,   166,   167,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   189,   190,   191,    -1,    -1,   891,    -1,
      -1,   894,    -1,   180,    -1,    -1,   202,    -1,   204,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     913,    -1,   915,   916,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   235,
      -1,   934,    -1,    -1,    13,    14,     8,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,   949,    -1,    -1,    -1,
      -1,    -1,    -1,   956,   957,   958,   959,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,   982,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,  1004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,   420,     8,   104,   105,   106,    -1,  1032,
     109,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,
     119,   120,  1045,   122,   123,    -1,    -1,    -1,    -1,    -1,
    1053,  1054,  1055,    -1,    -1,    -1,    -1,  1060,  1061,    -1,
    1063,    -1,   141,    -1,    -1,    -1,    -1,  1070,    -1,  1072,
    1073,  1074,  1075,  1076,    -1,    -1,   473,   474,    -1,    -1,
      -1,  1084,  1085,    -1,    -1,    -1,   165,   166,   167,    -1,
    1093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1103,    -1,  1105,   125,  1107,   502,  1109,    -1,    -1,   506,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,  1127,  1128,  1129,  1130,  1131,   526,
      -1,    -1,    -1,    -1,    -1,  1138,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,   234,   228,    -1,   555,   556,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1190,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   599,   600,   601,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1221,   506,
      -1,    -1,    -1,    -1,  1227,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
       8,    -1,    -1,    -1,   228,    -1,   643,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1260,  1261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,   556,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   693,    -1,    -1,    -1,
      -1,    -1,   699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   599,   600,   601,    -1,    -1,    -1,   715,    -1,
     717,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,  1344,  1345,  1346,    -1,    -1,     8,    -1,    -1,    -1,
      -1,  1354,  1355,  1356,  1357,    -1,   643,    -1,    -1,  1362,
      -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,  1371,    -1,
      -1,    -1,    -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,
      -1,  1384,    -1,    -1,    -1,    -1,  1389,    -1,    -1,    -1,
      -1,    -1,    -1,   680,  1397,  1398,  1399,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1407,    -1,   693,    -1,    -1,    -1,
      -1,    -1,   699,    -1,    -1,   812,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   823,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1438,    -1,    -1,    -1,  1442,
    1443,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   854,    -1,    -1,
     228,    -1,    -1,    -1,  1467,  1468,    -1,    -1,    -1,    -1,
      -1,  1474,  1475,    -1,    -1,    -1,    -1,    -1,  1481,    -1,
      -1,    -1,    -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1498,  1499,  1500,    -1,    -1,
      -1,    -1,    -1,    -1,  1507,  1508,  1509,  1510,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,  1521,    -1,
      -1,    -1,    -1,    -1,    -1,   812,    -1,  1530,  1531,  1532,
      -1,  1534,    -1,    -1,    -1,    -1,   823,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1549,  1550,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,  1568,   228,   854,    -1,  1572,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1583,    -1,    -1,  1586,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,  1604,    -1,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,  1615,    -1,   115,   116,    -1,  1620,   119,   120,
      -1,   122,   123,  1626,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1032,    -1,    -1,     4,     5,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,  1676,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
    1693,    -1,    58,    59,    60,    61,  1093,    -1,    -1,  1702,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,  1711,  1712,
      -1,    -1,  1715,    -1,    -1,    -1,    -1,    83,  1721,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1127,  1128,  1129,  1130,    -1,    -1,    -1,    -1,  1741,  1742,
      -1,    -1,    -1,    -1,    -1,  1032,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1757,    -1,   122,    -1,    -1,    -1,
    1763,  1764,    -1,    -1,  1767,  1768,  1769,  1770,    -1,    -1,
      -1,    -1,    -1,  1776,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1182,    -1,    -1,  1791,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1799,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1093,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,  1825,   189,   190,   191,   228,    -1,  1831,  1832,
      -1,    -1,   234,    -1,    -1,    -1,   202,    -1,   204,   205,
    1127,  1128,  1129,  1130,    -1,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,  1865,   228,    -1,    -1,    -1,    22,    23,   234,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,  1890,  1891,    -1,
     228,    -1,   230,    -1,   232,  1182,    -1,    -1,  1901,  1902,
     238,  1904,    -1,    -1,  1907,  1908,  1909,  1910,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1923,    -1,    -1,    -1,    -1,  1928,  1929,  1930,  1931,  1932,
      -1,    -1,    -1,    -1,    -1,    -1,  1939,    -1,    -1,    -1,
    1943,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,  1975,    -1,    -1,    -1,    -1,   132,  1981,  1982,
      -1,    -1,  1985,  1986,  1987,  1988,    -1,  1384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1999,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,   238,    -1,    -1,    -1,  2032,
    2033,  2034,  2035,  2036,  2037,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     235,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,  1384,     3,     4,
       5,   228,     7,   230,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,  1530,  1531,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    71,    -1,    73,    74,
      75,  1568,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      85,    -1,    -1,   338,   339,   340,     5,    -1,    -1,   344,
     345,   346,   347,   348,   349,   350,    -1,   352,    -1,    -1,
     355,   356,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,  1530,  1531,    -1,    -1,    66,    67,    68,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    83,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,   197,   198,   199,   200,   201,   202,    -1,   204,
     205,   206,   207,   208,   209,  1702,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,  1715,   224,
      -1,   226,   227,    -1,   229,    -1,   231,    -1,   233,    -1,
     235,   236,    -1,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     104,   105,   106,    -1,    -1,   109,    13,    14,   513,    -1,
      -1,   115,   116,    -1,    -1,   119,   120,  1764,   122,   123,
     189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,  1776,
      -1,    -1,    -1,   202,    -1,   204,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,   165,   166,   167,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,   238,    -1,    -1,    -1,  1715,    -1,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,   115,   116,
      -1,    -1,   119,   120,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,  1776,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,   165,   166,
     167,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,  1928,  1929,  1930,  1931,  1932,     3,     4,     5,   238,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,   234,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    66,
      67,    68,  1999,    -1,    71,    -1,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,  1928,  1929,  1930,  1931,  1932,    -1,    -1,   115,    -1,
     117,    -1,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,
     147,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,  1999,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,   198,   199,   200,   201,   202,    -1,   204,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,   229,     3,     4,     5,   233,    -1,    -1,   236,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    85,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    94,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,   117,    -1,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,   147,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,    -1,   204,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,   233,    -1,    -1,   236,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1223,  1224,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,  1237,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,   117,    -1,    -1,   120,    -1,   122,
      -1,    -1,    -1,    -1,     4,     5,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,   144,    -1,    -1,   147,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   238,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,   188,    66,    67,    68,   192,
     193,    71,    -1,    -1,   197,   198,   199,   200,   201,    -1,
      -1,    -1,   205,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,     3,     4,     5,
     233,    -1,    -1,   236,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,   189,
     190,   191,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,
      96,    -1,   202,    -1,   204,   205,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,   117,    -1,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,     4,     5,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
      -1,   147,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   238,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,   188,    66,    67,    68,   192,   193,    71,    -1,
      -1,   197,   198,   199,   200,   201,    -1,    -1,    -1,   205,
      83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,   229,     3,     4,    -1,   233,    -1,    -1,
     236,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,   189,   190,   191,    88,
      -1,    -1,    91,    -1,    -1,    94,    -1,    96,    -1,   202,
      -1,   204,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,   117,    -1,
      -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,   147,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,   198,
     199,   200,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
     229,     3,     4,    -1,   233,   234,    -1,   236,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      -1,    -1,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,   117,    -1,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,   144,    -1,    -1,   147,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,   197,   198,   199,   200,   201,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,   229,     3,     4,
      -1,   233,    -1,    -1,   236,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,   117,    -1,    -1,   120,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,   144,
      -1,    -1,   147,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,   197,   198,   199,   200,   201,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,   229,     3,     4,    -1,   233,    -1,
      -1,   236,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,   117,
      -1,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,   147,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,
     198,   199,   200,   201,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,   229,     3,     4,    -1,   233,    -1,    -1,   236,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    -1,    -1,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,   117,    -1,    -1,   120,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,    -1,   147,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,   192,   193,    -1,    -1,    -1,   197,   198,   199,   200,
     201,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,   229,     3,
       4,    -1,    -1,   234,    -1,   236,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,
      94,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,   117,    -1,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
     144,    -1,    -1,   147,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,   197,   198,   199,   200,   201,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,   229,     3,     4,    -1,   233,
      -1,    -1,   236,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
     117,    -1,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,
     147,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
     197,   198,   199,   200,   201,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,   229,     3,     4,    -1,   233,    -1,    -1,   236,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    94,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,   117,    -1,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,   147,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,   197,   198,   199,
     200,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,   229,
       3,     4,    -1,   233,    -1,    -1,   236,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,   117,    -1,    -1,   120,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,   144,    -1,    -1,   147,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,   197,   198,   199,   200,   201,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,     3,     4,    -1,
     233,    -1,    -1,   236,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,   117,    -1,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
      -1,   147,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,   197,   198,   199,   200,   201,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,   229,     3,     4,    -1,   233,    -1,    -1,
     236,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    -1,    -1,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,   117,    -1,
      -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,   147,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,   198,
     199,   200,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
     229,     3,     4,    -1,   233,    -1,    -1,   236,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      -1,    -1,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,   117,    -1,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,   144,    -1,    -1,   147,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,   197,   198,   199,   200,   201,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,   229,     3,     4,
      -1,   233,    -1,    -1,   236,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,   117,    -1,    -1,   120,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,   144,
      -1,    -1,   147,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,   197,   198,   199,   200,   201,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,   224,
       3,     4,     5,    -1,   229,    -1,    -1,    10,    11,    12,
      -1,   236,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    71,    -1,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    85,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,   188,   189,   190,   191,   192,
     234,    -1,    -1,    -1,   197,   198,   199,   200,   201,   202,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
     233,    -1,    -1,   236,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,    -1,   204,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,   229,
       3,     4,     5,   233,    -1,    -1,   236,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    71,    -1,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    85,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,   188,   189,   190,   191,   192,
     234,    -1,    -1,    -1,   197,   198,   199,   200,   201,   202,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
     233,    -1,    -1,   236,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,    -1,   204,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,   224,     3,     4,    -1,    -1,   229,
      -1,    -1,    10,    11,    12,    -1,   236,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    54,    55,    56,    57,
     228,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,     3,     4,    73,    74,    75,    -1,    -1,
      10,    11,    12,    81,    82,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    54,    55,    56,    57,   228,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
     198,   199,   200,   201,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,   233,    -1,    -1,   236,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,   188,    -1,
      -1,    -1,   192,   234,    -1,    -1,    -1,   197,   198,   199,
     200,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,   229,
      -1,     3,     4,   233,     6,    -1,   236,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    54,    55,    56,    57,   228,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    73,    74,    75,     3,     4,    -1,     6,    -1,    81,
      82,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    54,    55,    56,    57,   228,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,   198,   199,   200,   201,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   238,    -1,    -1,    -1,   197,   198,
     199,   200,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,    -1,    -1,   224,     3,     4,    -1,    -1,
     229,    -1,    -1,    10,    11,    12,    -1,   236,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,
     119,   120,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,   141,    -1,    -1,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,   188,    -1,   228,    -1,   192,   165,   166,   167,   234,
     197,   198,   199,   200,   201,    13,    14,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,   104,   105,   106,    13,
      14,   109,    -1,    -1,    -1,   234,    -1,   115,   116,    -1,
      -1,   119,   120,    -1,   122,   123,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   141,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,
      -1,   119,   120,    -1,   122,   123,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   141,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     104,   105,   106,    13,    14,   109,    -1,   165,   166,   167,
      -1,   115,   116,    -1,    -1,   119,   120,    -1,   122,   123,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,   234,   141,   228,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,   119,
     120,    -1,   122,   123,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     234,   141,   104,   105,   106,    13,    14,   109,    -1,    -1,
      -1,    -1,    -1,   115,   116,    -1,    -1,   119,   120,    -1,
     122,   123,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   165,   166,   167,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,   234,    -1,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,
      -1,   119,   120,    -1,   122,   123,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   234,   141,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,   119,
     120,    -1,   122,   123,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,   165,   166,   167,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,   234,   238,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    63,    64,    65,    -1,   228,    -1,    69,    70,
      -1,    72,   234,    -1,    -1,    76,    77,    -1,    79,    80,
      -1,    82,    -1,    -1,   234,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,   105,   106,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
       4,    -1,   153,   154,   155,    -1,    -1,    -1,   159,    13,
      14,    -1,    -1,   164,   165,   166,   167,    -1,    -1,   170,
      -1,   172,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    43,
      44,    -1,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,   205,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    -1,    72,    -1,
      -1,    -1,    76,    77,    -1,    79,    80,    -1,    82,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,   105,   106,   107,    -1,   109,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    13,    14,    -1,   153,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    -1,    -1,   170,    -1,   172,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,   205,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,   115,   116,
      -1,    -1,   119,   120,    -1,   122,   123,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,   141,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     234,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   233,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,   233,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,   233,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,    -1,
     232,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,   232,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,   232,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,   232,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,   232,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,   232,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,   232,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,   232,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,   232,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,    -1,    -1,   232,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
     232,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,   232,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,   232,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,   232,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
     230,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,   230,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
     230,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,   230,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
     230,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,   230,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
     230,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,   230,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
     230,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,   230,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
     230,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,   230,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,   230,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,   230,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   240,   241,     6,     0,     4,    13,    14,    43,
      44,    63,    64,    65,    69,    70,    72,    76,    77,    79,
      80,    82,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   103,   104,   105,
     106,   107,   109,   111,   112,   113,   114,   115,   116,   117,
     119,   120,   121,   122,   123,   124,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   153,
     154,   155,   159,   164,   165,   166,   167,   170,   172,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   194,   195,   196,   203,   205,   242,   244,
     245,   265,   284,   285,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   303,   305,   306,   312,   313,   314,   315,
     319,   340,   341,   237,    14,    94,   229,   229,     6,   233,
       6,     6,     6,     6,   229,     6,     6,   231,   231,   321,
     341,   229,   231,   263,   263,   229,   233,   229,   229,     4,
     229,   233,   229,   229,     4,   229,   233,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   108,    94,     6,
     233,    88,    91,    94,   229,     3,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    54,    55,    56,
      57,    62,    73,    74,    75,    81,    88,    91,    94,    96,
     115,   120,   122,   188,   192,   193,   197,   198,   199,   200,
     201,   219,   220,   224,   229,   233,   236,   285,   296,   303,
     305,   316,   317,   319,   321,   328,   330,   341,   229,   233,
      94,    94,   115,    91,    94,    96,    88,    91,    94,    96,
      91,    94,    96,    91,    94,   229,    91,   170,   186,   187,
     233,   219,   220,   229,   233,   325,   326,   325,   233,   233,
     325,     4,    88,    92,    98,    99,   101,   102,   119,   229,
      94,    96,    94,    91,     4,   181,   233,   341,     4,     6,
      88,    91,    94,    91,    94,     4,     4,     4,     5,   229,
     328,   329,     4,   229,   229,   229,     4,   233,   332,   341,
       4,   229,   229,   229,     6,     6,   231,     5,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    58,    59,    60,
      61,    66,    67,    68,    71,    83,    85,   189,   190,   191,
     202,   204,   336,   341,   229,     4,   336,     5,   233,     5,
     233,   220,   316,   341,   231,   229,   233,     6,   229,   233,
       6,   237,     7,   122,   181,   206,   207,   208,   209,   226,
     227,   229,   231,   233,   235,   261,   262,   263,   316,   335,
     336,   341,   233,     6,   316,   335,   336,   341,   335,   316,
     335,   339,   267,   272,   229,   324,     9,   336,   341,   316,
     220,   316,   330,   331,   316,   316,   229,   316,   331,   316,
     316,   229,   316,   331,   316,   316,   316,   316,   316,   316,
     335,   316,   316,   316,   328,   229,   331,   329,   329,   329,
     335,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   229,   231,   263,   263,   263,   263,   263,
     263,   229,   263,   263,   229,   263,     5,   173,   233,     5,
     173,     5,   173,     5,   173,   115,    88,    91,    94,    96,
     229,   263,   263,   229,   229,   316,   233,   316,   330,   316,
     316,   234,   331,   341,     8,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   228,
       9,   229,   231,   235,   262,   263,   316,   331,   229,   229,
     229,   328,   329,   329,   329,   229,   229,   229,   229,   229,
     328,   229,   328,   229,   328,   233,   233,   316,     4,   328,
     332,   233,   233,   325,   325,   325,   316,   316,   219,   220,
     233,   233,   325,   219,   220,   229,   287,   325,   233,   229,
     233,   229,   229,   229,   229,   229,   229,   229,   316,   329,
     329,   329,   229,     4,   231,   231,   287,     6,     6,   233,
     233,   233,   329,   329,   231,   231,   231,   316,     6,     6,
     316,   316,   316,   235,   316,   233,   173,   316,   316,   316,
     316,   263,   263,   263,   229,   229,   229,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   229,   229,   263,
     231,     6,     6,   233,     6,   287,     6,   287,   316,   221,
     233,   229,   231,   335,   316,   287,   328,   328,   233,   336,
      88,    91,    94,    96,     7,   230,   316,   232,   316,   285,
     286,   287,   341,     4,   170,   171,   328,     6,   230,   232,
     233,   264,     6,   233,     6,     9,   229,   231,   235,   341,
     316,     6,   230,   238,     9,   229,   231,   235,   230,   238,
     238,   230,   238,   232,   238,   266,   232,   266,    84,   323,
     320,   341,   238,   238,   230,   221,   234,   238,   230,   230,
     316,   230,   234,   230,   230,   316,   230,   234,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,     7,   316,
     234,     6,     6,     6,   230,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   330,   330,
     341,   233,   316,   316,   335,   316,   335,   328,   335,   335,
     339,   316,    63,   316,    63,    63,    63,   329,   329,   329,
     329,   335,   335,   330,   341,   336,   331,   230,   234,   263,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   233,   316,   330,   316,   316,   316,   341,   316,
     316,     4,   322,   233,   264,   230,   234,   316,   316,   316,
       7,     7,   309,   309,   278,   316,   336,   279,   316,   336,
     280,   316,   336,   281,   316,   336,   316,     6,   316,     6,
     316,     6,   331,   331,   233,   230,     6,   233,   287,   287,
     238,   238,   238,   325,   325,   286,   286,   238,   316,    88,
      91,    94,    96,   115,   120,   123,   234,   284,   300,   238,
     287,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     230,     7,   310,     6,     7,   316,     6,   316,   316,   234,
     331,   331,   331,     6,     6,   316,   316,   316,   230,   230,
     230,   230,   170,   238,   287,   233,     8,   230,   230,   232,
     339,   335,   339,   335,   335,   335,   335,   335,   335,   316,
     335,   335,   335,   335,   236,   338,   341,   336,   335,   335,
     335,   341,   331,   234,   234,   316,   287,   232,   230,   145,
     304,   230,   234,   238,   316,     6,   233,   233,   233,   233,
     316,     7,   261,   230,     7,   209,   261,   232,   234,     7,
     261,   262,   235,     7,     6,   331,     7,   246,   341,   316,
     316,   322,   231,   234,     6,   216,   243,   331,   341,   316,
     316,     4,   322,     6,   331,   316,     6,   335,     6,   341,
       6,   335,   316,   230,   231,   316,   336,     7,   173,   316,
     330,     7,     7,   230,     7,   173,     7,     7,   230,     7,
     173,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     316,   230,   233,     6,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   238,   264,   264,   264,   264,
     264,   264,   264,   238,   238,   238,   230,   232,   232,   331,
     238,   238,   264,   238,   264,   238,   238,   238,   230,   318,
     233,   234,   233,   233,   233,   238,   238,   264,   264,   230,
     230,   234,     7,   264,     8,     8,   331,   235,   230,   232,
     262,   331,     7,   233,   230,   230,   230,   316,   328,     4,
     308,     6,   230,   238,   230,   238,   230,   238,   230,   238,
     230,   230,   230,   234,   234,   331,   235,   287,   234,   234,
     325,   316,   316,   234,   234,   316,   325,   233,   233,   233,
     233,   229,   115,    91,    94,    96,   125,   125,   142,   150,
     151,   152,   156,   157,   301,   302,   325,   234,   297,   230,
     234,   230,   230,   230,   230,   230,   230,   230,     7,   316,
       6,   316,   230,   232,   232,   234,   234,   234,   232,   232,
     238,     7,     7,     7,   235,   316,   234,   316,   316,     7,
     235,   264,   238,   264,   264,   230,   230,   238,   264,   264,
     238,   238,   264,   264,   264,   264,   316,   264,     9,   337,
     238,   230,   238,   264,   232,   234,   234,     7,     6,   316,
     234,   233,     6,   328,   234,   316,   316,   316,   316,     6,
     328,   261,   262,    45,    45,   328,   235,   261,   262,   336,
     316,     6,     4,   233,   333,   341,   234,    45,     4,   160,
     161,   162,   163,   234,   249,   253,   256,   258,   259,   235,
     230,   232,   316,   216,   335,   230,   235,   230,   232,   230,
     238,     7,   229,   231,   316,   264,   264,   325,    94,    96,
     328,   328,     7,   328,    94,    96,   328,   328,     7,   328,
      96,   328,   328,   328,   328,   328,   328,   328,   328,   328,
       6,     7,   331,   316,   316,   316,   316,   234,   316,   316,
     316,   328,   335,   335,   274,   316,   316,   316,   316,   316,
     316,   328,   316,   316,   234,   322,   262,   235,   262,   234,
     328,   331,     7,     7,     7,   125,   307,     6,   261,   316,
     261,   316,   261,   316,   261,   316,     7,     7,     7,     7,
       7,   234,     4,   234,   238,   238,   238,   234,   234,   331,
     331,   331,   331,   316,   229,   229,   229,   229,   106,     4,
       6,   316,   233,     6,   229,     6,   158,     6,   158,   234,
     302,   238,   301,     7,     6,     7,     7,     7,     7,     7,
       7,     7,   328,     6,   233,     6,     6,     6,    94,     7,
       6,     6,   316,   328,   328,   328,     4,   238,     8,     8,
     230,     4,     4,   331,   335,   316,   335,   236,   276,   335,
     335,   238,   233,     6,   233,   328,   234,   234,   234,   234,
     234,     6,   316,     6,   263,   263,     6,     4,   170,   171,
     316,     6,     6,     6,     7,   332,   334,     6,   231,   264,
     263,   250,   229,   229,   233,   260,     6,   322,   235,   335,
     232,     6,     6,   243,   322,   235,     6,   316,   233,   316,
     336,   230,   232,   274,     6,     6,     6,   233,   233,   119,
     283,   283,   328,     6,   233,   233,     6,     6,   328,   173,
     282,   233,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,   234,   264,   264,   264,   264,   264,   238,   238,
     238,   230,   264,   264,   238,   264,   275,   238,   238,   238,
     238,   230,   264,     6,     4,   264,     6,   234,   328,   328,
     328,     4,     6,   328,   328,   328,   328,   328,   328,   328,
     233,   233,     7,     6,     7,   316,   316,   316,   233,   233,
     234,   234,   234,   234,   230,   316,   316,   316,   316,   233,
     231,     6,   316,   328,   316,     6,     6,   316,   325,   234,
       5,   328,   233,   233,   233,   233,   233,   233,   233,   328,
       6,   331,   233,   316,   232,     6,     6,   169,   316,   316,
     316,     6,     6,     7,   264,   238,   238,   264,   238,   316,
     238,   264,   277,   230,   264,   336,   287,   287,   238,     6,
       6,   339,   339,     7,   261,   262,   235,     7,     6,   332,
     234,   238,   316,   261,   264,   229,   316,   316,   327,   328,
     233,     4,     6,     6,   335,     4,   238,   328,   336,     7,
       7,   232,   316,   316,   325,     6,     6,     6,   316,   316,
       6,    92,     6,   316,     5,   233,   316,   316,   316,     4,
     316,   316,   316,   316,   262,   233,     6,   282,     6,   316,
       6,     6,     6,     6,     6,     4,     6,     6,   331,   331,
     316,   316,   336,   234,   230,   234,   238,   286,   286,     6,
       6,     6,     6,   230,   230,   230,   230,   316,   316,   234,
     238,   230,   234,   238,     6,     6,   327,   325,   325,   325,
     325,   325,   220,   325,     6,   234,   316,     6,     6,   328,
     234,   238,     8,   234,   230,   233,   316,   336,   335,   316,
     335,     4,   185,   238,   304,   304,   328,   264,   264,   336,
     316,     6,     4,   333,     6,   332,   232,   328,     6,   247,
     316,   238,   238,   234,   238,   248,   316,     6,   316,   268,
     271,   233,   233,   234,   234,   234,   234,   233,   234,     5,
     327,   264,   264,   238,   233,   328,   336,   238,   238,   238,
     238,   316,     6,   233,   234,   234,   233,     6,     6,   233,
     316,   234,   234,   234,   232,     6,   328,     7,   233,   316,
     234,   238,   238,   238,   238,   238,   238,     6,   234,   168,
     316,   316,   331,     6,     6,   230,   264,   264,   233,   316,
     336,   336,   336,   234,   234,   234,     6,     6,     6,     6,
       7,     6,   235,     6,   230,   238,   316,   316,   233,   328,
     234,   238,   238,   274,   276,   328,   328,     6,     6,     6,
       6,   316,     6,     6,   234,   316,   273,   316,   330,   316,
     316,   316,   316,   234,   327,   129,   130,   135,   311,   129,
     130,   311,   331,   286,   234,   238,     6,   234,   328,   287,
     234,     6,   331,   325,   325,   325,   325,   325,   316,   234,
     234,   234,   339,   230,   233,     6,   332,   171,   251,   316,
     238,   238,   327,     6,   316,   316,   234,   234,   270,   269,
     234,   233,   238,   234,   238,     7,     7,   238,   238,   238,
     238,   234,   233,   325,   328,     6,   233,   325,     6,   234,
     234,   316,     6,   125,   234,   298,   233,   234,   238,   238,
     238,   238,   238,     6,     6,   234,     6,   287,     6,   233,
     316,   316,   234,   238,   274,   274,   316,   316,   316,   336,
     341,   316,   316,   316,   316,     6,   325,     6,   325,     6,
       6,   234,   316,   301,   287,     6,   331,   331,   331,   331,
     325,   331,   304,   248,   230,   238,     6,   233,   316,   234,
     234,   238,   238,     7,   229,   238,   238,   238,   238,   238,
     238,     6,   234,   234,   299,   234,   234,   234,   234,   238,
     234,   234,   234,   254,   316,   327,   234,   316,   316,   336,
     230,   316,   316,   316,   316,   325,   325,   301,     6,     6,
       6,     6,   331,     6,     6,     6,   233,   230,   234,     6,
     234,   264,   238,   238,   238,   238,   238,   238,   234,   234,
     252,   335,   257,   233,     6,   316,   316,   316,   316,   316,
     316,     6,   234,   238,   233,   327,   234,   234,   234,   234,
     234,   234,     6,   335,   255,   335,   234,     6,     6,   234,
     238,     6,     6,   335
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
#line 236 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 247 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 248 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 249 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 251 "Gmsh.y"
    {
      factory = (yyvsp[(3) - (5)].c);
      if(factory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, GModel::current()->getGEOInternals()->getMaxTag(dim));
      }
      else if(GModel::current()->getOCCInternals()){
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getGEOInternals()->setMaxTag
            (dim, GModel::current()->getOCCInternals()->getMaxTag(dim));
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 267 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 268 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 269 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 270 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 271 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 272 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 273 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 274 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 275 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 276 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 277 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 278 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 279 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 280 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 281 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 282 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 287 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 291 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 298 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 303 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 308 "Gmsh.y"
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
#line 322 "Gmsh.y"
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
#line 335 "Gmsh.y"
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
#line 348 "Gmsh.y"
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
#line 376 "Gmsh.y"
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
#line 390 "Gmsh.y"
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
#line 403 "Gmsh.y"
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
#line 416 "Gmsh.y"
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
#line 434 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 448 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 450 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 455 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 457 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 462 "Gmsh.y"
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
#line 566 "Gmsh.y"
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
#line 576 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 585 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 592 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 602 "Gmsh.y"
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
#line 611 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 620 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 627 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 637 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 645 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 655 "Gmsh.y"
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
#line 674 "Gmsh.y"
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
#line 693 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 699 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 706 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 707 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 708 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 709 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 710 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 714 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 715 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 721 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 721 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 722 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 722 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 732 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 737 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 743 "Gmsh.y"
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
#line 805 "Gmsh.y"
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
#line 822 "Gmsh.y"
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
#line 851 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 856 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 84:
#line 861 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 85:
#line 870 "Gmsh.y"
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

  case 86:
#line 899 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 87:
#line 904 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 88:
#line 912 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 89:
#line 921 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 90:
#line 926 "Gmsh.y"
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

  case 91:
#line 938 "Gmsh.y"
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

  case 92:
#line 955 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 93:
#line 962 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 94:
#line 971 "Gmsh.y"
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

  case 95:
#line 990 "Gmsh.y"
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

  case 96:
#line 1009 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 97:
#line 1019 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 98:
#line 1031 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 99:
#line 1037 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 100:
#line 1045 "Gmsh.y"
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

  case 101:
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

  case 102:
#line 1089 "Gmsh.y"
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

  case 103:
#line 1100 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 104:
#line 1108 "Gmsh.y"
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
#line 1130 "Gmsh.y"
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
#line 1153 "Gmsh.y"
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
#line 1191 "Gmsh.y"
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
#line 1212 "Gmsh.y"
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
#line 1224 "Gmsh.y"
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
#line 1242 "Gmsh.y"
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
#line 1251 "Gmsh.y"
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
#line 1260 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 116:
#line 1262 "Gmsh.y"
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
#line 1280 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 118:
#line 1282 "Gmsh.y"
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
#line 1298 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 120:
#line 1300 "Gmsh.y"
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

  case 121:
#line 1316 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 122:
#line 1325 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 123:
#line 1327 "Gmsh.y"
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

  case 125:
#line 1341 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 126:
#line 1349 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 127:
#line 1355 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 128:
#line 1360 "Gmsh.y"
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

  case 131:
#line 1391 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
        double v;
        List_Read((yyvsp[(3) - (3)].l), i, &v);
        floatOptions[key].push_back(v);
      }
      Free((yyvsp[(2) - (3)].c));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 132:
#line 1402 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[(4) - (5)].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[(4) - (5)].l), i))->s);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 133:
#line 1417 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 136:
#line 1433 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 137:
#line 1441 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 138:
#line 1450 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 139:
#line 1458 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        char *s;
        List_Read((yyvsp[(4) - (5)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(2) - (5)].c));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 140:
#line 1476 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 141:
#line 1480 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 142:
#line 1486 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 143:
#line 1494 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 144:
#line 1498 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 145:
#line 1504 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 146:
#line 1512 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 147:
#line 1516 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 148:
#line 1522 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 149:
#line 1530 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 150:
#line 1534 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 151:
#line 1540 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 152:
#line 1548 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 153:
#line 1552 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 154:
#line 1558 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 155:
#line 1562 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 156:
#line 1569 "Gmsh.y"
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

  case 157:
#line 1590 "Gmsh.y"
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

  case 158:
#line 1604 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
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

  case 159:
#line 1618 "Gmsh.y"
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

  case 160:
#line 1653 "Gmsh.y"
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

  case 161:
#line 1691 "Gmsh.y"
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

  case 162:
#line 1705 "Gmsh.y"
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

  case 163:
#line 1720 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), knots);
      if(factory == "OpenCASCADE"){
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

  case 164:
#line 1739 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 165:
#line 1748 "Gmsh.y"
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

  case 166:
#line 1762 "Gmsh.y"
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

  case 167:
#line 1777 "Gmsh.y"
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

  case 168:
#line 1791 "Gmsh.y"
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

  case 169:
#line 1810 "Gmsh.y"
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

  case 170:
#line 1820 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 171:
#line 1826 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 172:
#line 1832 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1839 "Gmsh.y"
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

  case 174:
#line 1868 "Gmsh.y"
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
#line 1883 "Gmsh.y"
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

  case 176:
#line 1903 "Gmsh.y"
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

  case 177:
#line 1924 "Gmsh.y"
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

  case 178:
#line 1945 "Gmsh.y"
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

  case 179:
#line 1966 "Gmsh.y"
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

  case 180:
#line 1988 "Gmsh.y"
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

  case 181:
#line 2010 "Gmsh.y"
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

  case 182:
#line 2031 "Gmsh.y"
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

  case 183:
#line 2054 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 184:
#line 2064 "Gmsh.y"
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

  case 185:
#line 2084 "Gmsh.y"
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

  case 186:
#line 2099 "Gmsh.y"
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

  case 187:
#line 2113 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, out, true, false);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2128 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, out, true, true);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2143 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 190:
#line 2152 "Gmsh.y"
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

  case 191:
#line 2162 "Gmsh.y"
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

  case 192:
#line 2172 "Gmsh.y"
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

  case 193:
#line 2182 "Gmsh.y"
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

  case 194:
#line 2197 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->translate(tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        GModel::current()->getGEOInternals()->translate(tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 195:
#line 2208 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(10) - (11)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->rotate
          (tags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        GModel::current()->getGEOInternals()->rotate
          (tags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 196:
#line 2221 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      if(factory == "OpenCASCADE"){
        Msg::Error("Symmetry not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->symmetry
          (tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 197:
#line 2233 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(8) - (9)].l), tags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (tags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 198:
#line 2245 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(8) - (9)].l), tags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (tags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 199:
#line 2257 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      std::string action((yyvsp[(1) - (4)].c));
      if(action == "Duplicata"){
        // don't use per-dimension vectors here, in order to respect the input
        // ordering (points can e.g. be given after surfaces) in the output
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape s; List_Read((yyvsp[(3) - (4)].l), i, &s); int dim = s.Type / 100 - 1;
          if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
            s.Num = GModel::current()->getOCCInternals()->copy(dim, s.Num);
          }
          else{
            s.Num = GModel::current()->getGEOInternals()->copy(dim, s.Num);
          }
          List_Add((yyval.l), &s);
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
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), in);
        GModel::current()->getBoundaryTags(in, out, action == "CombinedBoundary");
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Unknown action on multiple shapes: %s", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 200:
#line 2294 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        yymsg(0, "Intersect Line not available with OpenCASCADE");
      }
      else{
        IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      }
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 201:
#line 2305 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      if(factory == "OpenCASCADE"){
        yymsg(0, "Split Line not available with OpenCASCADE");
      }
      else{
        List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
        SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
        List_Delete(tmp);
      }
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 202:
#line 2320 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 203:
#line 2321 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 204:
#line 2326 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 205:
#line 2330 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 206:
#line 2334 "Gmsh.y"
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

  case 207:
#line 2345 "Gmsh.y"
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

  case 208:
#line 2356 "Gmsh.y"
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

  case 209:
#line 2367 "Gmsh.y"
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

  case 210:
#line 2383 "Gmsh.y"
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

  case 211:
#line 2402 "Gmsh.y"
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

  case 212:
#line 2424 "Gmsh.y"
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

  case 213:
#line 2439 "Gmsh.y"
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

  case 214:
#line 2454 "Gmsh.y"
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

  case 215:
#line 2473 "Gmsh.y"
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

  case 216:
#line 2524 "Gmsh.y"
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

  case 217:
#line 2545 "Gmsh.y"
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

  case 218:
#line 2567 "Gmsh.y"
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

  case 219:
#line 2589 "Gmsh.y"
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

  case 220:
#line 2694 "Gmsh.y"
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

  case 221:
#line 2710 "Gmsh.y"
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

  case 222:
#line 2745 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
      for(int dim = 0; dim < 4; dim++){
        for(unsigned int i = 0; i < tags[dim].size(); i++){
          if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
            GModel::current()->getOCCInternals()->remove(dim, tags[dim][i]);
          }
          GModel::current()->getGEOInternals()->remove(dim, tags[dim][i]);
          GModel::current()->remove(dim, tags[dim][i]);
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 223:
#line 2759 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 224:
#line 2765 "Gmsh.y"
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

  case 225:
#line 2780 "Gmsh.y"
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

  case 226:
#line 2808 "Gmsh.y"
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

  case 227:
#line 2825 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      setColor(tags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 228:
#line 2831 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(5) - (6)].l), tags);
      setColor(tags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 229:
#line 2842 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 230:
#line 2856 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 231:
#line 2862 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 232:
#line 2868 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
      setVisibility(tags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 233:
#line 2874 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      setVisibility(tags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 234:
#line 2880 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
      setVisibility(tags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 235:
#line 2886 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      setVisibility(tags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 236:
#line 2897 "Gmsh.y"
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

  case 237:
#line 2970 "Gmsh.y"
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

  case 238:
#line 2988 "Gmsh.y"
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

  case 239:
#line 3005 "Gmsh.y"
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

  case 240:
#line 3020 "Gmsh.y"
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

  case 241:
#line 3053 "Gmsh.y"
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

  case 242:
#line 3065 "Gmsh.y"
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

  case 243:
#line 3089 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 244:
#line 3093 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 245:
#line 3098 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 246:
#line 3105 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 247:
#line 3110 "Gmsh.y"
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

  case 248:
#line 3120 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 249:
#line 3125 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 250:
#line 3131 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 251:
#line 3139 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 252:
#line 3143 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 253:
#line 3147 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 254:
#line 3157 "Gmsh.y"
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

  case 255:
#line 3220 "Gmsh.y"
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

  case 256:
#line 3236 "Gmsh.y"
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

  case 257:
#line 3253 "Gmsh.y"
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

  case 258:
#line 3270 "Gmsh.y"
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

  case 259:
#line 3292 "Gmsh.y"
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

  case 260:
#line 3314 "Gmsh.y"
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

  case 261:
#line 3349 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 262:
#line 3357 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 263:
#line 3365 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 264:
#line 3371 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 265:
#line 3378 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 266:
#line 3385 "Gmsh.y"
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

  case 267:
#line 3405 "Gmsh.y"
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

  case 268:
#line 3431 "Gmsh.y"
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

  case 269:
#line 3443 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 270:
#line 3455 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), in);
        GModel::current()->getOCCInternals()->extrude(-1, in, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        // FIXME use GEOInternals + int api -- SAME FOR ALL BELOW!
        ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
                      (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
                      NULL, (yyval.l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 271:
#line 3471 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(10) - (11)].l), in);
        GModel::current()->getOCCInternals()->revolve(-1, in, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2],
                                                      (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
                      0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
                      NULL, (yyval.l));
      }
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 272:
#line 3487 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 273:
#line 3495 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 274:
#line 3501 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 275:
#line 3509 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 276:
#line 3515 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 277:
#line 3523 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 278:
#line 3529 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 279:
#line 3537 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3543 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 281:
#line 3550 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(3) - (9)].l), in);
        GModel::current()->getOCCInternals()->addPipe(-1, in, (int)(yyvsp[(8) - (9)].d), out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 282:
#line 3563 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, false);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 283:
#line 3577 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, true);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 284:
#line 3591 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges, out[4];
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        GModel::current()->getOCCInternals()->fillet(regions, edges, radius, out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    ;}
    break;

  case 285:
#line 3610 "Gmsh.y"
    {
    ;}
    break;

  case 286:
#line 3613 "Gmsh.y"
    {
    ;}
    break;

  case 287:
#line 3619 "Gmsh.y"
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

  case 288:
#line 3631 "Gmsh.y"
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

  case 289:
#line 3651 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 290:
#line 3655 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 291:
#line 3659 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 292:
#line 3663 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 293:
#line 3667 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 294:
#line 3671 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 295:
#line 3675 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 296:
#line 3679 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 297:
#line 3688 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 298:
#line 3700 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 299:
#line 3701 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 300:
#line 3702 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 301:
#line 3703 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 302:
#line 3704 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 303:
#line 3708 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 304:
#line 3709 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 305:
#line 3710 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 306:
#line 3715 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4], out[4];
        ListOfShapes2Vectors((yyvsp[(3) - (9)].l), shape);
        ListOfShapes2Vectors((yyvsp[(7) - (9)].l), tool);
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), shape, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 307:
#line 3732 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> out[4];
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE factory");
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 308:
#line 3750 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4], out[4];
        ListOfShapes2Vectors((yyvsp[(7) - (14)].l), shape);
        ListOfShapes2Vectors((yyvsp[(11) - (14)].l), tool);
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), shape, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 309:
#line 3765 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 310:
#line 3769 "Gmsh.y"
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

  case 311:
#line 3784 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 312:
#line 3788 "Gmsh.y"
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

  case 313:
#line 3804 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 314:
#line 3808 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 315:
#line 3813 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 316:
#line 3817 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 317:
#line 3823 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 318:
#line 3827 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 319:
#line 3834 "Gmsh.y"
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

  case 320:
#line 3851 "Gmsh.y"
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

  case 321:
#line 3892 "Gmsh.y"
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
                GVertex *gv = GModel::current()->getVertexByTag(std::abs(corners[j]));
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

  case 322:
#line 3936 "Gmsh.y"
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
                GVertex *gv = GModel::current()->getVertexByTag(std::abs(corners[i]));
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

  case 323:
#line 3975 "Gmsh.y"
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

  case 324:
#line 4000 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 325:
#line 4009 "Gmsh.y"
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

  case 326:
#line 4039 "Gmsh.y"
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

  case 327:
#line 4065 "Gmsh.y"
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

  case 328:
#line 4092 "Gmsh.y"
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

  case 329:
#line 4124 "Gmsh.y"
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

  case 330:
#line 4151 "Gmsh.y"
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

  case 331:
#line 4177 "Gmsh.y"
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

  case 332:
#line 4203 "Gmsh.y"
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

  case 333:
#line 4229 "Gmsh.y"
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

  case 334:
#line 4255 "Gmsh.y"
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

  case 335:
#line 4276 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 336:
#line 4282 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 337:
#line 4288 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 338:
#line 4294 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 339:
#line 4300 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 340:
#line 4306 "Gmsh.y"
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

  case 341:
#line 4332 "Gmsh.y"
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

  case 342:
#line 4358 "Gmsh.y"
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

  case 343:
#line 4375 "Gmsh.y"
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

  case 344:
#line 4392 "Gmsh.y"
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

  case 345:
#line 4409 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
	int num = (int)fabs(dnum);
        GModel::current()->getGEOInternals()->setDegenerated(1, num);
        GEdge *ge = GModel::current()->getEdgeByTag(num);
        if(ge) ge->setTooSmall(true);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 346:
#line 4421 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 347:
#line 4427 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 348:
#line 4433 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 349:
#line 4445 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 350:
#line 4449 "Gmsh.y"
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

  case 351:
#line 4459 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 352:
#line 4469 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 353:
#line 4470 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 354:
#line 4471 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 355:
#line 4476 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 356:
#line 4482 "Gmsh.y"
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

  case 357:
#line 4494 "Gmsh.y"
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

  case 358:
#line 4512 "Gmsh.y"
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

  case 359:
#line 4539 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 360:
#line 4540 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 361:
#line 4541 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 362:
#line 4542 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 363:
#line 4543 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 364:
#line 4544 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 365:
#line 4545 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 366:
#line 4546 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 367:
#line 4548 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 368:
#line 4554 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 369:
#line 4555 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 370:
#line 4556 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 371:
#line 4557 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 372:
#line 4558 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 373:
#line 4559 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 374:
#line 4560 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 375:
#line 4561 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 376:
#line 4562 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 377:
#line 4563 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 378:
#line 4564 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 379:
#line 4565 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 380:
#line 4566 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 381:
#line 4567 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 382:
#line 4568 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 383:
#line 4569 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 384:
#line 4570 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 385:
#line 4571 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 386:
#line 4572 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 387:
#line 4573 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 388:
#line 4574 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 389:
#line 4575 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 390:
#line 4576 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 391:
#line 4577 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 392:
#line 4578 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 393:
#line 4579 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 394:
#line 4580 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 395:
#line 4581 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 396:
#line 4582 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 397:
#line 4583 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 398:
#line 4584 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 399:
#line 4585 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 400:
#line 4586 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 401:
#line 4595 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 402:
#line 4596 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 403:
#line 4597 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 404:
#line 4598 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 405:
#line 4599 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 406:
#line 4600 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 407:
#line 4601 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 408:
#line 4602 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 409:
#line 4603 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 410:
#line 4604 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 411:
#line 4605 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 412:
#line 4610 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 413:
#line 4612 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 414:
#line 4618 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 415:
#line 4620 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 416:
#line 4625 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 417:
#line 4631 "Gmsh.y"
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
        if(nameSpaces.count(struct_namespace) &&
           nameSpaces[struct_namespace].count(struct_name)) {
          (yyval.d) = (double)nameSpaces[struct_namespace][struct_name]._index;
        }
        else {
          yymsg(0, "Unknown variable: %s", struct_name.c_str());  (yyval.d) = 0.;
        }
      }
      Free((yyvsp[(1) - (1)].c2).char1); Free((yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 418:
#line 4655 "Gmsh.y"
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

  case 419:
#line 4673 "Gmsh.y"
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

  case 420:
#line 4691 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 421:
#line 4696 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 422:
#line 4702 "Gmsh.y"
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

  case 423:
#line 4717 "Gmsh.y"
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

  case 424:
#line 4736 "Gmsh.y"
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

  case 425:
#line 4757 "Gmsh.y"
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

  case 426:
#line 4790 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
      /*
      std::string struct_namespace($1.char1? $1.char1 : std::string("")),
        struct_name($1.char2);
      if (nameSpaces.count(struct_namespace) &&
          nameSpaces[struct_namespace].count(struct_name)) {
        std::string key2($3);
        if (nameSpaces[struct_namespace][struct_name]._fopt.count(key2)) {
	  $$ = nameSpaces[struct_namespace][struct_name]._fopt[key2][0];
        }
        else {
	  yymsg(0, "Unknown member '%s' of Struct %s", $3, struct_name.c_str());
          $$ = 0.;
	}
      }
      else  {
        NumberOption(GMSH_GET, $1.char2, 0, $3, $$);
      }
      Free($1.char1); Free($1.char2);
      if (flag_tSTRING_alloc) Free($3);
      */
    ;}
    break;

  case 427:
#line 4814 "Gmsh.y"
    { (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 428:
#line 4817 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 429:
#line 4823 "Gmsh.y"
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

  case 430:
#line 4834 "Gmsh.y"
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

  case 431:
#line 4844 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 4849 "Gmsh.y"
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

  case 433:
#line 4860 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 434:
#line 4869 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 435:
#line 4874 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 436:
#line 4879 "Gmsh.y"
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

  case 437:
#line 4907 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 438:
#line 4909 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (8)].c2).char1? (yyvsp[(2) - (8)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (8)].c2).char2);
      Free((yyvsp[(2) - (8)].c2).char1); Free((yyvsp[(2) - (8)].c2).char2);
      if (!(yyvsp[(3) - (8)].i))
        if (!nameSpaces[struct_namespace].count(struct_name)) {
          int index = (int)(yyvsp[(6) - (8)].d);
          if (index < 0)
            index = nameSpaces[struct_namespace].get().size()+1;
          nameSpaces[struct_namespace][struct_name] =
            Struct(index, floatOptions, charOptions);
          (yyval.d) = (double)index;
        }
        else {
          yymsg(0, "Redefinition of Struct '%s::%s'",
                struct_namespace.c_str(), struct_name.c_str());
          (yyval.d) = (yyvsp[(6) - (8)].d);
        }
      else {
        nameSpaces[struct_namespace][struct_name].
          append(floatOptions, charOptions);
        (yyval.d) = (double)nameSpaces[struct_namespace][struct_name]._index;
      }
    ;}
    break;

  case 439:
#line 4937 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 440:
#line 4939 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 441:
#line 4944 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 442:
#line 4953 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 443:
#line 4955 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 444:
#line 4960 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 445:
#line 4962 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 446:
#line 4968 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 447:
#line 4972 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 448:
#line 4976 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 449:
#line 4980 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 450:
#line 4984 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 451:
#line 4991 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 452:
#line 4995 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 453:
#line 4999 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 454:
#line 5003 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 455:
#line 5010 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 456:
#line 5015 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 457:
#line 5022 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 458:
#line 5027 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 459:
#line 5031 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 460:
#line 5036 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 461:
#line 5040 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 462:
#line 5048 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 463:
#line 5059 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 464:
#line 5063 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 465:
#line 5075 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 466:
#line 5083 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 467:
#line 5091 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 468:
#line 5098 "Gmsh.y"
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

  case 469:
#line 5108 "Gmsh.y"
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

  case 470:
#line 5131 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 471:
#line 5137 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 472:
#line 5143 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 473:
#line 5149 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 474:
#line 5155 "Gmsh.y"
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

  case 475:
#line 5166 "Gmsh.y"
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

  case 476:
#line 5177 "Gmsh.y"
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

  case 477:
#line 5188 "Gmsh.y"
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

  case 478:
#line 5200 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 479:
#line 5206 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 480:
#line 5212 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 481:
#line 5218 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 482:
#line 5223 "Gmsh.y"
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

  case 483:
#line 5233 "Gmsh.y"
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

  case 484:
#line 5243 "Gmsh.y"
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

  case 485:
#line 5253 "Gmsh.y"
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

  case 486:
#line 5266 "Gmsh.y"
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

  case 487:
#line 5278 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 488:
#line 5282 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 489:
#line 5286 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 490:
#line 5290 "Gmsh.y"
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

  case 491:
#line 5308 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 492:
#line 5316 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 493:
#line 5324 "Gmsh.y"
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

  case 494:
#line 5353 "Gmsh.y"
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

  case 495:
#line 5363 "Gmsh.y"
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

  case 496:
#line 5382 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 497:
#line 5387 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 498:
#line 5391 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 499:
#line 5395 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 500:
#line 5407 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 501:
#line 5411 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 502:
#line 5423 "Gmsh.y"
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

  case 503:
#line 5440 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 504:
#line 5450 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 505:
#line 5454 "Gmsh.y"
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

  case 506:
#line 5469 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 507:
#line 5474 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 508:
#line 5482 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 509:
#line 5486 "Gmsh.y"
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

  case 510:
#line 5499 "Gmsh.y"
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

  case 511:
#line 5513 "Gmsh.y"
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

  case 512:
#line 5530 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
      /*
      std::string out;
      std::string struct_namespace($1.char1? $1.char1 : std::string("")),
        struct_name($1.char2);
      if(nameSpaces.count(struct_namespace) &&
         nameSpaces[struct_namespace].count(struct_name)) {
        std::string key2($3);
        if(nameSpaces[struct_namespace][struct_name]._copt.count(key2)) {
	  out = nameSpaces[struct_namespace][struct_name]._copt[key2][0];
        }
        else {
	  yymsg(0, "Unknown member '%s' of Struct %s", $3, struct_name.c_str());
	}
      }
      else  {
        StringOption(GMSH_GET, $1, 0, $3, out);
      }
      $$ = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
      Free($1.char1); Free($1.char2);
      if (flag_tSTRING_alloc) Free($3);
      */
    ;}
    break;

  case 513:
#line 5556 "Gmsh.y"
    { (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 514:
#line 5560 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 515:
#line 5568 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 516:
#line 5574 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 517:
#line 5580 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 518:
#line 5586 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 519:
#line 5595 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 520:
#line 5599 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 521:
#line 5603 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 522:
#line 5611 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 523:
#line 5617 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 524:
#line 5623 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 525:
#line 5631 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 526:
#line 5639 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 527:
#line 5646 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 528:
#line 5654 "Gmsh.y"
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

  case 529:
#line 5669 "Gmsh.y"
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

  case 530:
#line 5683 "Gmsh.y"
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

  case 531:
#line 5697 "Gmsh.y"
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

  case 532:
#line 5709 "Gmsh.y"
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

  case 533:
#line 5725 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 534:
#line 5734 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 535:
#line 5743 "Gmsh.y"
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

  case 536:
#line 5753 "Gmsh.y"
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

  case 537:
#line 5764 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 538:
#line 5772 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 539:
#line 5780 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 540:
#line 5784 "Gmsh.y"
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

  case 541:
#line 5803 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 542:
#line 5810 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 543:
#line 5816 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 544:
#line 5823 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 545:
#line 5830 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 546:
#line 5832 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 547:
#line 5840 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = NULL;
      switch (nameSpaces.get_key_struct_from_index((int)(yyvsp[(3) - (4)].d), key_struct,
                                                   struct_namespace)) {
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

  case 548:
#line 5864 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 549:
#line 5866 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 550:
#line 5872 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 551:
#line 5877 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 552:
#line 5885 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 553:
#line 5894 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 554:
#line 5907 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 555:
#line 5910 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 556:
#line 5914 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 12795 "Gmsh.tab.cpp"
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


#line 5917 "Gmsh.y"


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

void ListOfShapes2Vectors(List_T *list, std::vector<int> v[4])
{
  Shape s;
  for(int i = 0; i < List_Nbr(list); i++){
    List_Read(list, i, &s);
    int dim = s.Type / 100 - 1;
    if(dim >= 0 && dim <= 3) v[dim].push_back(s.Num);
  }
}

void Vectors2ListOfShapes(std::vector<int> tags[4], List_T *list)
{
  for(int dim = 0; dim < 4; dim++){
    Shape s;
    s.Type =
      (dim == 3) ? MSH_VOLUME :
      (dim == 2) ? MSH_SURF_PLAN :
      (dim == 1) ? MSH_SEGM_LINE :
      MSH_POINT;
    for(unsigned int i = 0; i < tags[dim].size(); i++){
      s.Num = tags[dim][i];
      List_Add(list, &s);
    }
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

  GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(abs(iSource));
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

  GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(abs(iSource));
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

  GEdge *target = GModel::current()->getEdgeByTag(abs(iTarget));
  GEdge *source = GModel::current()->getEdgeByTag(abs(iSource));
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

void setVisibility(std::vector<int> tags[4], int visible, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < tags[dim].size(); i++){
      GEntity *ge = GModel::current()->getEntityByTag(dim, std::abs(tags[dim][i]));
      if(ge) ge->setVisibility(visible, recursive);
    }
  }
}

void setColor(std::vector<int> tags[4], unsigned int val, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < tags[dim].size(); i++){
      GEntity *ge = GModel::current()->getEntityByTag(dim, std::abs(tags[dim][i]));
      if(ge) ge->setColor(val, recursive);
    }
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
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxPhysicalNum + 1);
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
    return (GModel::current()->getGEOInternals()->MaxPhysicalNum + 1);
}


double treat_Struct_FullName_dot_tSTRING_Float(char* c1, char* c2, char* c3) {
  double out;
  std::string struct_namespace(c1? c1 : std::string("")),
    struct_name(c2);
  /*
  std::string struct_namespace($1.char1? $1.char1 : std::string("")),
    struct_name($1.char2);
  */
  if(nameSpaces.count(struct_namespace) &&
     nameSpaces[struct_namespace].count(struct_name)) {
    std::string key2(c3);
    if(nameSpaces[struct_namespace][struct_name]._fopt.count(key2)) {
      out = nameSpaces[struct_namespace][struct_name]._fopt[key2][0];
    }
    else {
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
      out = 0.;
    }
  }
  else  {
    NumberOption(GMSH_GET, c2, 0, c3, out);
  }
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}


char* treat_Struct_FullName_dot_tSTRING_String(char* c1, char* c2, char* c3) {
  std::string out;
  std::string struct_namespace(c1? c1 : std::string("")),
    struct_name(c2);
  /*
  std::string struct_namespace($1.char1? $1.char1 : std::string("")),
    struct_name($1.char2);
  */
  if(nameSpaces.count(struct_namespace) &&
     nameSpaces[struct_namespace].count(struct_name)) {
    std::string key2(c3);
    if(nameSpaces[struct_namespace][struct_name]._copt.count(key2)) {
      out = nameSpaces[struct_namespace][struct_name]._copt[key2][0];
    }
    else {
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    }
  }
  else  {
    StringOption(GMSH_GET, c2, 0, c3, out);
  }
  char* out_c = (char*)Malloc((out.size() + 1) * sizeof(char));
  strcpy(out_c, out.c_str());
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out_c;
}

