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
     tCpu = 329,
     tMemory = 330,
     tTotalMemory = 331,
     tCreateTopology = 332,
     tCreateTopologyNoHoles = 333,
     tDistanceFunction = 334,
     tDefineConstant = 335,
     tUndefineConstant = 336,
     tDefineNumber = 337,
     tDefineStruct = 338,
     tNameStruct = 339,
     tAppend = 340,
     tDefineString = 341,
     tSetNumber = 342,
     tSetString = 343,
     tPoint = 344,
     tCircle = 345,
     tEllipse = 346,
     tLine = 347,
     tSphere = 348,
     tPolarSphere = 349,
     tSurface = 350,
     tSpline = 351,
     tVolume = 352,
     tBlock = 353,
     tCylinder = 354,
     tCone = 355,
     tTorus = 356,
     tEllipsoid = 357,
     tQuadric = 358,
     tShapeFromFile = 359,
     tRectangle = 360,
     tDisk = 361,
     tWire = 362,
     tCharacteristic = 363,
     tLength = 364,
     tParametric = 365,
     tElliptic = 366,
     tRefineMesh = 367,
     tAdaptMesh = 368,
     tRelocateMesh = 369,
     tSetFactory = 370,
     tThruSections = 371,
     tWedge = 372,
     tFillet = 373,
     tChamfer = 374,
     tPlane = 375,
     tRuled = 376,
     tTransfinite = 377,
     tPhysical = 378,
     tCompound = 379,
     tPeriodic = 380,
     tUsing = 381,
     tPlugin = 382,
     tDegenerated = 383,
     tRecursive = 384,
     tRotate = 385,
     tTranslate = 386,
     tSymmetry = 387,
     tDilate = 388,
     tExtrude = 389,
     tLevelset = 390,
     tAffine = 391,
     tBooleanUnion = 392,
     tBooleanIntersection = 393,
     tBooleanDifference = 394,
     tBooleanSection = 395,
     tBooleanFragments = 396,
     tThickSolid = 397,
     tRecombine = 398,
     tSmoother = 399,
     tSplit = 400,
     tDelete = 401,
     tCoherence = 402,
     tIntersect = 403,
     tMeshAlgorithm = 404,
     tReverse = 405,
     tLayers = 406,
     tScaleLast = 407,
     tHole = 408,
     tAlias = 409,
     tAliasWithOptions = 410,
     tCopyOptions = 411,
     tQuadTriAddVerts = 412,
     tQuadTriNoNewVerts = 413,
     tRecombLaterals = 414,
     tTransfQuadTri = 415,
     tText2D = 416,
     tText3D = 417,
     tInterpolationScheme = 418,
     tTime = 419,
     tCombine = 420,
     tBSpline = 421,
     tBezier = 422,
     tNurbs = 423,
     tNurbsOrder = 424,
     tNurbsKnots = 425,
     tColor = 426,
     tColorTable = 427,
     tFor = 428,
     tIn = 429,
     tEndFor = 430,
     tIf = 431,
     tElseIf = 432,
     tElse = 433,
     tEndIf = 434,
     tExit = 435,
     tAbort = 436,
     tField = 437,
     tReturn = 438,
     tCall = 439,
     tSlide = 440,
     tMacro = 441,
     tShow = 442,
     tHide = 443,
     tGetValue = 444,
     tGetStringValue = 445,
     tGetEnv = 446,
     tGetString = 447,
     tGetNumber = 448,
     tUnique = 449,
     tUnique2 = 450,
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
#define tCpu 329
#define tMemory 330
#define tTotalMemory 331
#define tCreateTopology 332
#define tCreateTopologyNoHoles 333
#define tDistanceFunction 334
#define tDefineConstant 335
#define tUndefineConstant 336
#define tDefineNumber 337
#define tDefineStruct 338
#define tNameStruct 339
#define tAppend 340
#define tDefineString 341
#define tSetNumber 342
#define tSetString 343
#define tPoint 344
#define tCircle 345
#define tEllipse 346
#define tLine 347
#define tSphere 348
#define tPolarSphere 349
#define tSurface 350
#define tSpline 351
#define tVolume 352
#define tBlock 353
#define tCylinder 354
#define tCone 355
#define tTorus 356
#define tEllipsoid 357
#define tQuadric 358
#define tShapeFromFile 359
#define tRectangle 360
#define tDisk 361
#define tWire 362
#define tCharacteristic 363
#define tLength 364
#define tParametric 365
#define tElliptic 366
#define tRefineMesh 367
#define tAdaptMesh 368
#define tRelocateMesh 369
#define tSetFactory 370
#define tThruSections 371
#define tWedge 372
#define tFillet 373
#define tChamfer 374
#define tPlane 375
#define tRuled 376
#define tTransfinite 377
#define tPhysical 378
#define tCompound 379
#define tPeriodic 380
#define tUsing 381
#define tPlugin 382
#define tDegenerated 383
#define tRecursive 384
#define tRotate 385
#define tTranslate 386
#define tSymmetry 387
#define tDilate 388
#define tExtrude 389
#define tLevelset 390
#define tAffine 391
#define tBooleanUnion 392
#define tBooleanIntersection 393
#define tBooleanDifference 394
#define tBooleanSection 395
#define tBooleanFragments 396
#define tThickSolid 397
#define tRecombine 398
#define tSmoother 399
#define tSplit 400
#define tDelete 401
#define tCoherence 402
#define tIntersect 403
#define tMeshAlgorithm 404
#define tReverse 405
#define tLayers 406
#define tScaleLast 407
#define tHole 408
#define tAlias 409
#define tAliasWithOptions 410
#define tCopyOptions 411
#define tQuadTriAddVerts 412
#define tQuadTriNoNewVerts 413
#define tRecombLaterals 414
#define tTransfQuadTri 415
#define tText2D 416
#define tText3D 417
#define tInterpolationScheme 418
#define tTime 419
#define tCombine 420
#define tBSpline 421
#define tBezier 422
#define tNurbs 423
#define tNurbsOrder 424
#define tNurbsKnots 425
#define tColor 426
#define tColorTable 427
#define tFor 428
#define tIn 429
#define tEndFor 430
#define tIf 431
#define tElseIf 432
#define tElse 433
#define tEndIf 434
#define tExit 435
#define tAbort 436
#define tField 437
#define tReturn 438
#define tCall 439
#define tSlide 440
#define tMacro 441
#define tShow 442
#define tHide 443
#define tGetValue 444
#define tGetStringValue 445
#define tGetEnv 446
#define tGetString 447
#define tGetNumber 448
#define tUnique 449
#define tUnique2 450
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
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static std::string factory;
static NameSpaces nameSpaces;
static std::string struct_name, struct_namespace;
static int flag_tSTRING_alloc = 0;

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
#line 139 "Gmsh.y"
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
#line 693 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 706 "Gmsh.tab.cpp"

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
#define YYLAST   13685

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  558
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2074

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
     603,   613,   614,   618,   622,   628,   634,   635,   638,   642,
     648,   652,   653,   656,   660,   664,   668,   674,   676,   678,
     682,   684,   686,   690,   692,   694,   698,   700,   702,   706,
     707,   713,   714,   717,   725,   733,   741,   750,   759,   767,
     775,   787,   796,   804,   813,   822,   831,   841,   845,   850,
     861,   869,   877,   885,   893,   901,   909,   917,   925,   933,
     941,   950,   963,   972,   980,   988,   997,  1006,  1015,  1024,
    1033,  1042,  1048,  1060,  1066,  1076,  1086,  1091,  1101,  1111,
    1113,  1115,  1116,  1119,  1126,  1133,  1140,  1147,  1156,  1167,
    1182,  1199,  1212,  1227,  1242,  1257,  1272,  1281,  1290,  1297,
    1302,  1309,  1316,  1320,  1325,  1331,  1338,  1344,  1348,  1352,
    1357,  1363,  1368,  1374,  1378,  1384,  1392,  1400,  1404,  1412,
    1416,  1419,  1422,  1425,  1428,  1431,  1447,  1450,  1453,  1456,
    1459,  1462,  1479,  1491,  1498,  1507,  1516,  1527,  1529,  1532,
    1535,  1537,  1541,  1545,  1550,  1555,  1557,  1559,  1565,  1577,
    1591,  1592,  1600,  1601,  1615,  1616,  1632,  1633,  1640,  1650,
    1653,  1657,  1668,  1670,  1673,  1679,  1687,  1690,  1693,  1697,
    1700,  1704,  1707,  1711,  1721,  1728,  1730,  1732,  1734,  1736,
    1738,  1739,  1742,  1746,  1756,  1761,  1776,  1777,  1781,  1782,
    1784,  1785,  1788,  1789,  1792,  1793,  1796,  1803,  1811,  1818,
    1824,  1828,  1837,  1843,  1848,  1855,  1867,  1879,  1898,  1917,
    1930,  1943,  1956,  1967,  1978,  1989,  2000,  2011,  2016,  2021,
    2026,  2031,  2036,  2041,  2046,  2051,  2056,  2059,  2063,  2070,
    2072,  2074,  2076,  2079,  2085,  2093,  2104,  2106,  2110,  2113,
    2116,  2119,  2123,  2127,  2131,  2135,  2139,  2143,  2147,  2151,
    2155,  2159,  2163,  2167,  2171,  2175,  2181,  2186,  2191,  2196,
    2201,  2206,  2211,  2216,  2221,  2226,  2231,  2238,  2243,  2248,
    2253,  2258,  2263,  2268,  2273,  2278,  2285,  2292,  2299,  2304,
    2306,  2308,  2310,  2312,  2314,  2316,  2318,  2320,  2322,  2324,
    2326,  2327,  2334,  2336,  2341,  2348,  2350,  2355,  2360,  2365,
    2370,  2375,  2379,  2382,  2385,  2391,  2397,  2401,  2407,  2414,
    2419,  2427,  2434,  2441,  2448,  2453,  2460,  2465,  2466,  2475,
    2477,  2481,  2483,  2485,  2488,  2489,  2493,  2495,  2498,  2501,
    2505,  2509,  2521,  2531,  2539,  2547,  2549,  2553,  2555,  2557,
    2560,  2564,  2569,  2575,  2577,  2579,  2582,  2586,  2590,  2596,
    2601,  2604,  2607,  2610,  2613,  2617,  2621,  2625,  2629,  2646,
    2663,  2680,  2697,  2699,  2701,  2703,  2707,  2712,  2717,  2722,
    2729,  2736,  2745,  2754,  2759,  2774,  2779,  2784,  2789,  2791,
    2793,  2797,  2801,  2811,  2819,  2821,  2827,  2831,  2838,  2840,
    2844,  2846,  2848,  2853,  2858,  2862,  2868,  2875,  2881,  2887,
    2893,  2899,  2901,  2906,  2908,  2910,  2912,  2917,  2924,  2929,
    2936,  2941,  2946,  2951,  2960,  2965,  2970,  2975,  2980,  2989,
    2998,  3005,  3010,  3017,  3022,  3024,  3029,  3034,  3035,  3042,
    3047,  3050,  3055,  3057,  3061,  3067,  3073,  3075,  3077
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     242,     0,    -1,   243,    -1,     1,     6,    -1,    -1,   243,
     244,    -1,   246,    -1,   247,    -1,   267,    -1,   115,   231,
     336,   232,     6,    -1,   285,    -1,   286,    -1,   290,    -1,
     291,    -1,   292,    -1,   293,    -1,   297,    -1,   306,    -1,
     307,    -1,   313,    -1,   314,    -1,   296,    -1,   295,    -1,
     294,    -1,   289,    -1,   316,    -1,   218,    -1,   218,   218,
      -1,    44,   231,   336,   232,     6,    -1,    45,   231,   336,
     232,     6,    -1,    44,   231,   336,   232,   245,   336,     6,
      -1,    44,   231,   336,   240,   332,   232,     6,    -1,    45,
     231,   336,   240,   332,   232,     6,    -1,    44,   231,   336,
     240,   332,   232,   245,   336,     6,    -1,   342,   336,   235,
     248,   236,     6,    -1,   154,     4,   233,   317,   234,     6,
      -1,   155,     4,   233,   317,   234,     6,    -1,   156,     4,
     233,   317,   240,   317,   234,     6,    -1,    -1,   248,   251,
      -1,   248,   255,    -1,   248,   258,    -1,   248,   260,    -1,
     248,   261,    -1,   317,    -1,   249,   240,   317,    -1,   317,
      -1,   250,   240,   317,    -1,    -1,    -1,     4,   252,   231,
     249,   232,   253,   235,   250,   236,     6,    -1,   336,    -1,
     254,   240,   336,    -1,    -1,   161,   231,   317,   240,   317,
     240,   317,   232,   256,   235,   254,   236,     6,    -1,   336,
      -1,   257,   240,   336,    -1,    -1,   162,   231,   317,   240,
     317,   240,   317,   240,   317,   232,   259,   235,   257,   236,
       6,    -1,   163,   235,   328,   236,   235,   328,   236,     6,
      -1,   163,   235,   328,   236,   235,   328,   236,   235,   328,
     236,   235,   328,   236,     6,    -1,    -1,   164,   262,   235,
     250,   236,     6,    -1,     7,    -1,   211,    -1,   210,    -1,
     209,    -1,   208,    -1,   229,    -1,   228,    -1,   231,    -1,
     233,    -1,   232,    -1,   234,    -1,    80,   233,   269,   234,
       6,    -1,    81,   233,   273,   234,     6,    -1,   320,     6,
      -1,    87,   265,   337,   240,   317,   266,     6,    -1,    88,
     265,   342,   240,   337,   266,     6,    -1,   342,   263,   329,
       6,    -1,   342,   264,     6,    -1,   342,   265,   266,   263,
     329,     6,    -1,   342,   265,   235,   332,   236,   266,   263,
     329,     6,    -1,   342,   233,   317,   234,   263,   317,     6,
      -1,   342,   233,   317,   234,   264,     6,    -1,   342,   231,
     317,   232,   263,   317,     6,    -1,   342,   231,   317,   232,
     264,     6,    -1,   342,     7,   337,     6,    -1,   342,   265,
     266,     7,    46,   265,   266,     6,    -1,   342,   265,   266,
       7,    46,   265,   340,   266,     6,    -1,   342,   265,   266,
     211,    46,   265,   340,   266,     6,    -1,   342,   237,     4,
       7,   337,     6,    -1,   342,   233,   317,   234,   237,     4,
       7,   337,     6,    -1,   342,   237,     4,   263,   317,     6,
      -1,   342,   233,   317,   234,   237,     4,   263,   317,     6,
      -1,   342,   237,     4,   264,     6,    -1,   342,   233,   317,
     234,   237,     4,   264,     6,    -1,   342,   237,   171,   237,
       4,     7,   333,     6,    -1,   342,   233,   317,   234,   237,
     171,   237,     4,     7,   333,     6,    -1,   342,   237,   172,
       7,   334,     6,    -1,   342,   233,   317,   234,   237,   172,
       7,   334,     6,    -1,   342,   182,     7,   317,     6,    -1,
     182,   233,   317,   234,     7,     4,     6,    -1,   182,   233,
     317,   234,   237,     4,     7,   317,     6,    -1,   182,   233,
     317,   234,   237,     4,     7,   337,     6,    -1,   182,   233,
     317,   234,   237,     4,     7,   235,   332,   236,     6,    -1,
     182,   233,   317,   234,   237,     4,     6,    -1,   127,   231,
       4,   232,   237,     4,     7,   317,     6,    -1,   127,   231,
       4,   232,   237,     4,     7,   337,     6,    -1,    -1,   240,
      -1,    -1,   269,   268,   342,    -1,   269,   268,   342,     7,
     317,    -1,    -1,   269,   268,   342,     7,   235,   329,   270,
     275,   236,    -1,    -1,   269,   268,   342,   265,   266,     7,
     235,   329,   271,   275,   236,    -1,   269,   268,   342,     7,
     337,    -1,    -1,   269,   268,   342,     7,   235,   337,   272,
     277,   236,    -1,    -1,   273,   268,   336,    -1,   317,     7,
     337,    -1,   274,   240,   317,     7,   337,    -1,   331,     7,
     342,   231,   232,    -1,    -1,   275,   276,    -1,   240,     4,
     329,    -1,   240,     4,   235,   274,   236,    -1,   240,     4,
     337,    -1,    -1,   277,   278,    -1,   240,     4,   317,    -1,
     240,     4,   337,    -1,   240,   186,   337,    -1,   240,     4,
     235,   340,   236,    -1,   317,    -1,   337,    -1,   337,   240,
     317,    -1,   317,    -1,   337,    -1,   337,   240,   317,    -1,
     317,    -1,   337,    -1,   337,   240,   317,    -1,   317,    -1,
     337,    -1,   337,   240,   317,    -1,    -1,   174,    93,   235,
     317,   236,    -1,    -1,   120,   326,    -1,    89,   231,   317,
     232,     7,   326,     6,    -1,    92,   231,   317,   232,     7,
     329,     6,    -1,    96,   231,   317,   232,     7,   329,     6,
      -1,    90,   231,   317,   232,     7,   329,   284,     6,    -1,
      91,   231,   317,   232,     7,   329,   284,     6,    -1,   166,
     231,   317,   232,     7,   329,     6,    -1,   167,   231,   317,
     232,     7,   329,     6,    -1,   168,   231,   317,   232,     7,
     329,   170,   329,   169,   317,     6,    -1,   124,    92,   231,
     317,   232,     7,   329,     6,    -1,   107,   231,   317,   232,
       7,   329,     6,    -1,    92,     4,   231,   317,   232,     7,
     329,     6,    -1,   120,    95,   231,   317,   232,     7,   329,
       6,    -1,    95,   231,   317,   232,     7,   329,   283,     6,
      -1,   121,    95,   231,   317,   232,     7,   329,   283,     6,
      -1,    13,    14,     6,    -1,    14,    95,   317,     6,    -1,
     110,    95,   231,   317,   232,     7,     5,     5,     5,     6,
      -1,    93,   231,   317,   232,     7,   329,     6,    -1,    94,
     231,   317,   232,     7,   329,     6,    -1,    98,   231,   317,
     232,     7,   329,     6,    -1,   101,   231,   317,   232,     7,
     329,     6,    -1,   105,   231,   317,   232,     7,   329,     6,
      -1,   106,   231,   317,   232,     7,   329,     6,    -1,    99,
     231,   317,   232,     7,   329,     6,    -1,   100,   231,   317,
     232,     7,   329,     6,    -1,   117,   231,   317,   232,     7,
     329,     6,    -1,   142,   231,   317,   232,     7,   329,     6,
      -1,   124,    95,   231,   317,   232,     7,   329,     6,    -1,
     124,    95,   231,   317,   232,     7,   329,     4,   235,   328,
     236,     6,    -1,    95,     4,   231,   317,   232,     7,   329,
       6,    -1,    97,   231,   317,   232,     7,   329,     6,    -1,
     116,   231,   317,   232,     7,   329,     6,    -1,   121,   116,
     231,   317,   232,     7,   329,     6,    -1,   124,    97,   231,
     317,   232,     7,   329,     6,    -1,   123,    89,   231,   279,
     232,   263,   329,     6,    -1,   123,    92,   231,   280,   232,
     263,   329,     6,    -1,   123,    95,   231,   281,   232,   263,
     329,     6,    -1,   123,    97,   231,   282,   232,   263,   329,
       6,    -1,   131,   326,   235,   287,   236,    -1,   130,   235,
     326,   240,   326,   240,   317,   236,   235,   287,   236,    -1,
     132,   326,   235,   287,   236,    -1,   133,   235,   326,   240,
     317,   236,   235,   287,   236,    -1,   133,   235,   326,   240,
     326,   236,   235,   287,   236,    -1,     4,   235,   287,   236,
      -1,   148,    92,   235,   332,   236,    95,   235,   317,   236,
      -1,   145,    92,   231,   317,   232,   235,   332,   236,     6,
      -1,   288,    -1,   286,    -1,    -1,   288,   285,    -1,   288,
      89,   235,   332,   236,     6,    -1,   288,    92,   235,   332,
     236,     6,    -1,   288,    95,   235,   332,   236,     6,    -1,
     288,    97,   235,   332,   236,     6,    -1,   135,   120,   231,
     317,   232,     7,   329,     6,    -1,   135,    89,   231,   317,
     232,     7,   235,   328,   236,     6,    -1,   135,   120,   231,
     317,   232,     7,   235,   326,   240,   326,   240,   332,   236,
       6,    -1,   135,   120,   231,   317,   232,     7,   235,   326,
     240,   326,   240,   326,   240,   332,   236,     6,    -1,   135,
      93,   231,   317,   232,     7,   235,   326,   240,   332,   236,
       6,    -1,   135,    99,   231,   317,   232,     7,   235,   326,
     240,   326,   240,   332,   236,     6,    -1,   135,   100,   231,
     317,   232,     7,   235,   326,   240,   326,   240,   332,   236,
       6,    -1,   135,   102,   231,   317,   232,     7,   235,   326,
     240,   326,   240,   332,   236,     6,    -1,   135,   103,   231,
     317,   232,     7,   235,   326,   240,   326,   240,   332,   236,
       6,    -1,   135,     4,   231,   317,   232,     7,   329,     6,
      -1,   135,     4,   231,   317,   232,     7,     5,     6,    -1,
     135,     4,   235,   317,   236,     6,    -1,   146,   235,   288,
     236,    -1,   146,   182,   233,   317,   234,     6,    -1,   146,
       4,   233,   317,   234,     6,    -1,   146,   342,     6,    -1,
     146,     4,     4,     6,    -1,   171,   333,   235,   288,   236,
      -1,   129,   171,   333,   235,   288,   236,    -1,   205,   317,
     235,   288,   236,    -1,   187,     5,     6,    -1,   188,     5,
       6,    -1,   187,   235,   288,   236,    -1,   129,   187,   235,
     288,   236,    -1,   188,   235,   288,   236,    -1,   129,   188,
     235,   288,   236,    -1,   342,   337,     6,    -1,    73,   231,
     340,   232,     6,    -1,   342,   342,   233,   317,   234,   336,
       6,    -1,   342,   342,   342,   233,   317,   234,     6,    -1,
     342,   317,     6,    -1,   127,   231,     4,   232,   237,     4,
       6,    -1,   165,     4,     6,    -1,   180,     6,    -1,   181,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   235,   317,   240,   317,   240,   317,   240,   317,
     240,   317,   240,   317,   236,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    77,     6,    -1,    78,     6,    -1,   112,
       6,    -1,   113,   235,   332,   236,   235,   332,   236,   235,
     328,   236,   235,   317,   240,   317,   236,     6,    -1,   185,
     231,   235,   332,   236,   240,   337,   240,   337,   232,     6,
      -1,   173,   231,   317,     8,   317,   232,    -1,   173,   231,
     317,     8,   317,     8,   317,   232,    -1,   173,     4,   174,
     235,   317,     8,   317,   236,    -1,   173,     4,   174,   235,
     317,     8,   317,     8,   317,   236,    -1,   175,    -1,   186,
       4,    -1,   186,   337,    -1,   183,    -1,   184,   342,     6,
      -1,   184,   337,     6,    -1,   176,   231,   317,   232,    -1,
     177,   231,   317,   232,    -1,   178,    -1,   179,    -1,   134,
     326,   235,   288,   236,    -1,   134,   235,   326,   240,   326,
     240,   317,   236,   235,   288,   236,    -1,   134,   235,   326,
     240,   326,   240,   326,   240,   317,   236,   235,   288,   236,
      -1,    -1,   134,   326,   235,   288,   298,   302,   236,    -1,
      -1,   134,   235,   326,   240,   326,   240,   317,   236,   235,
     288,   299,   302,   236,    -1,    -1,   134,   235,   326,   240,
     326,   240,   326,   240,   317,   236,   235,   288,   300,   302,
     236,    -1,    -1,   134,   235,   288,   301,   302,   236,    -1,
     134,   235,   288,   236,   126,   107,   235,   317,   236,    -1,
     116,   329,    -1,   121,   116,   329,    -1,   118,   235,   332,
     236,   235,   332,   236,   235,   317,   236,    -1,   303,    -1,
     302,   303,    -1,   151,   235,   317,   236,     6,    -1,   151,
     235,   329,   240,   329,   236,     6,    -1,   152,     6,    -1,
     143,     6,    -1,   143,   317,     6,    -1,   157,     6,    -1,
     157,   159,     6,    -1,   158,     6,    -1,   158,   159,     6,
      -1,   153,   231,   317,   232,     7,   329,   126,   317,     6,
      -1,   126,     4,   233,   317,   234,     6,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,    -1,   146,
       6,    -1,   146,   317,     6,    -1,   304,   235,   288,   305,
     236,   235,   288,   305,   236,    -1,   104,   231,   336,   232,
      -1,   304,   231,   317,   232,     7,   235,   288,   305,   236,
     235,   288,   305,   236,     6,    -1,    -1,   126,     4,   317,
      -1,    -1,     4,    -1,    -1,     7,   329,    -1,    -1,     7,
     317,    -1,    -1,   136,   329,    -1,   108,   109,   329,     7,
     317,     6,    -1,   122,    92,   330,     7,   317,   308,     6,
      -1,   122,    95,   330,   310,   309,     6,    -1,   122,    97,
     330,   310,     6,    -1,   160,   330,     6,    -1,   149,    95,
     235,   332,   236,     7,   317,     6,    -1,   143,    95,   330,
     311,     6,    -1,   143,    97,   330,     6,    -1,   144,    95,
     330,     7,   317,     6,    -1,   125,    92,   235,   332,   236,
       7,   235,   332,   236,   312,     6,    -1,   125,    95,   235,
     332,   236,     7,   235,   332,   236,   312,     6,    -1,   125,
      92,   235,   332,   236,     7,   235,   332,   236,   130,   235,
     326,   240,   326,   240,   317,   236,     6,    -1,   125,    95,
     235,   332,   236,     7,   235,   332,   236,   130,   235,   326,
     240,   326,   240,   317,   236,     6,    -1,   125,    92,   235,
     332,   236,     7,   235,   332,   236,   131,   326,     6,    -1,
     125,    95,   235,   332,   236,     7,   235,   332,   236,   131,
     326,     6,    -1,   125,    95,   317,   235,   332,   236,     7,
     317,   235,   332,   236,     6,    -1,    89,   235,   332,   236,
     174,    95,   235,   317,   236,     6,    -1,    92,   235,   332,
     236,   174,    95,   235,   317,   236,     6,    -1,    89,   235,
     332,   236,   174,    97,   235,   317,   236,     6,    -1,    92,
     235,   332,   236,   174,    97,   235,   317,   236,     6,    -1,
      95,   235,   332,   236,   174,    97,   235,   317,   236,     6,
      -1,   150,    95,   330,     6,    -1,   150,    92,   330,     6,
      -1,   114,    89,   330,     6,    -1,   114,    92,   330,     6,
      -1,   114,    95,   330,     6,    -1,   128,    92,   329,     6,
      -1,   124,    92,   329,     6,    -1,   124,    95,   329,     6,
      -1,   124,    97,   329,     6,    -1,   147,     6,    -1,   147,
       4,     6,    -1,   147,    89,   235,   332,   236,     6,    -1,
     196,    -1,   197,    -1,   198,    -1,   315,     6,    -1,   315,
     235,   329,   236,     6,    -1,   315,   235,   329,   240,   329,
     236,     6,    -1,   315,   231,   329,   232,   235,   329,   240,
     329,   236,     6,    -1,   318,    -1,   231,   317,   232,    -1,
     222,   317,    -1,   221,   317,    -1,   226,   317,    -1,   317,
     222,   317,    -1,   317,   221,   317,    -1,   317,   223,   317,
      -1,   317,   224,   317,    -1,   317,   225,   317,    -1,   317,
     230,   317,    -1,   317,   217,   317,    -1,   317,   218,   317,
      -1,   317,   220,   317,    -1,   317,   219,   317,    -1,   317,
     216,   317,    -1,   317,   215,   317,    -1,   317,   214,   317,
      -1,   317,   213,   317,    -1,   317,   212,   317,     8,   317,
      -1,    16,   265,   317,   266,    -1,    17,   265,   317,   266,
      -1,    18,   265,   317,   266,    -1,    19,   265,   317,   266,
      -1,    20,   265,   317,   266,    -1,    21,   265,   317,   266,
      -1,    22,   265,   317,   266,    -1,    23,   265,   317,   266,
      -1,    24,   265,   317,   266,    -1,    26,   265,   317,   266,
      -1,    27,   265,   317,   240,   317,   266,    -1,    28,   265,
     317,   266,    -1,    29,   265,   317,   266,    -1,    30,   265,
     317,   266,    -1,    31,   265,   317,   266,    -1,    32,   265,
     317,   266,    -1,    33,   265,   317,   266,    -1,    34,   265,
     317,   266,    -1,    35,   265,   317,   266,    -1,    36,   265,
     317,   240,   317,   266,    -1,    37,   265,   317,   240,   317,
     266,    -1,    38,   265,   317,   240,   317,   266,    -1,    25,
     265,   317,   266,    -1,     3,    -1,    10,    -1,    15,    -1,
      11,    -1,    12,    -1,   201,    -1,   202,    -1,   203,    -1,
      74,    -1,    75,    -1,    76,    -1,    -1,    82,   265,   317,
     319,   275,   266,    -1,   320,    -1,   193,   265,   336,   266,
      -1,   193,   265,   336,   240,   317,   266,    -1,   322,    -1,
     342,   233,   317,   234,    -1,   342,   231,   317,   232,    -1,
     199,   231,   342,   232,    -1,   200,   231,   337,   232,    -1,
     238,   342,   265,   266,    -1,   238,   342,     9,    -1,   238,
       9,    -1,   342,   264,    -1,   342,   233,   317,   234,   264,
      -1,   342,   231,   317,   232,   264,    -1,   342,   237,   323,
      -1,   342,     9,   342,   237,   323,    -1,   342,   233,   317,
     234,   237,     4,    -1,   342,   237,     4,   264,    -1,   342,
     233,   317,   234,   237,     4,   264,    -1,   189,   231,   336,
     240,   317,   232,    -1,    56,   231,   329,   240,   329,   232,
      -1,    57,   265,   336,   240,   336,   266,    -1,    55,   265,
     336,   266,    -1,    58,   265,   336,   240,   336,   266,    -1,
      63,   231,   340,   232,    -1,    -1,    83,   322,   325,   321,
     233,   317,   275,   234,    -1,   342,    -1,   342,     9,   342,
      -1,     4,    -1,    85,    -1,    85,   317,    -1,    -1,   231,
     324,   232,    -1,   327,    -1,   222,   326,    -1,   221,   326,
      -1,   326,   222,   326,    -1,   326,   221,   326,    -1,   235,
     317,   240,   317,   240,   317,   240,   317,   240,   317,   236,
      -1,   235,   317,   240,   317,   240,   317,   240,   317,   236,
      -1,   235,   317,   240,   317,   240,   317,   236,    -1,   231,
     317,   240,   317,   240,   317,   232,    -1,   329,    -1,   328,
     240,   329,    -1,   317,    -1,   331,    -1,   235,   236,    -1,
     235,   332,   236,    -1,   222,   235,   332,   236,    -1,   317,
     223,   235,   332,   236,    -1,   329,    -1,     5,    -1,   222,
     331,    -1,   317,   223,   331,    -1,   317,     8,   317,    -1,
     317,     8,   317,     8,   317,    -1,    89,   235,   317,   236,
      -1,    89,     5,    -1,    92,     5,    -1,    95,     5,    -1,
      97,     5,    -1,   123,    89,   330,    -1,   123,    92,   330,
      -1,   123,    95,   330,    -1,   123,    97,   330,    -1,    89,
     174,    64,   235,   317,   240,   317,   240,   317,   240,   317,
     240,   317,   240,   317,   236,    -1,    92,   174,    64,   235,
     317,   240,   317,   240,   317,   240,   317,   240,   317,   240,
     317,   236,    -1,    95,   174,    64,   235,   317,   240,   317,
     240,   317,   240,   317,   240,   317,   240,   317,   236,    -1,
      97,   174,    64,   235,   317,   240,   317,   240,   317,   240,
     317,   240,   317,   240,   317,   236,    -1,   286,    -1,   297,
      -1,   306,    -1,   342,   265,   266,    -1,    39,   233,   342,
     234,    -1,    39,   233,   331,   234,    -1,    39,   231,   331,
     232,    -1,    39,   265,   235,   332,   236,   266,    -1,   342,
     265,   235,   332,   236,   266,    -1,    40,   265,   317,   240,
     317,   240,   317,   266,    -1,    41,   265,   317,   240,   317,
     240,   317,   266,    -1,    42,   265,   336,   266,    -1,    43,
     265,   317,   240,   317,   240,   317,   240,   317,   240,   317,
     240,   317,   266,    -1,   194,   265,   331,   266,    -1,   195,
     265,   331,   266,    -1,    32,   265,   331,   266,    -1,   317,
      -1,   331,    -1,   332,   240,   317,    -1,   332,   240,   331,
      -1,   235,   317,   240,   317,   240,   317,   240,   317,   236,
      -1,   235,   317,   240,   317,   240,   317,   236,    -1,   342,
      -1,     4,   237,   171,   237,     4,    -1,   235,   335,   236,
      -1,   342,   233,   317,   234,   237,   172,    -1,   333,    -1,
     335,   240,   333,    -1,   337,    -1,   342,    -1,   342,   233,
     317,   234,    -1,   342,   231,   317,   232,    -1,   342,   237,
     323,    -1,   342,     9,   342,   237,   323,    -1,   342,   233,
     317,   234,   237,     4,    -1,   123,    89,   235,   317,   236,
      -1,   123,    92,   235,   317,   236,    -1,   123,    95,   235,
     317,   236,    -1,   123,    97,   235,   317,   236,    -1,     5,
      -1,   206,   233,   342,   234,    -1,    67,    -1,   204,    -1,
      72,    -1,   191,   231,   336,   232,    -1,   190,   231,   336,
     240,   336,   232,    -1,   192,   265,   336,   266,    -1,   192,
     265,   336,   240,   336,   266,    -1,    48,   265,   340,   266,
      -1,    49,   231,   336,   232,    -1,    50,   231,   336,   232,
      -1,    51,   231,   336,   240,   336,   240,   336,   232,    -1,
      46,   265,   340,   266,    -1,    60,   265,   336,   266,    -1,
      61,   265,   336,   266,    -1,    62,   265,   336,   266,    -1,
      59,   265,   317,   240,   336,   240,   336,   266,    -1,    54,
     265,   336,   240,   317,   240,   317,   266,    -1,    54,   265,
     336,   240,   317,   266,    -1,    47,   265,   336,   266,    -1,
      47,   265,   336,   240,   332,   266,    -1,    68,   265,   336,
     266,    -1,    69,    -1,    53,   265,   336,   266,    -1,    52,
     265,   336,   266,    -1,    -1,    86,   265,   337,   338,   277,
     266,    -1,    84,   265,   339,   266,    -1,   238,   317,    -1,
     342,     9,   238,   317,    -1,   336,    -1,   340,   240,   336,
      -1,     4,   239,   235,   317,   236,    -1,   341,   239,   235,
     317,   236,    -1,     4,    -1,   341,    -1,   207,   233,   336,
     234,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   238,   238,   239,   244,   246,   250,   251,   252,   253,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   289,   293,   300,   305,
     310,   324,   337,   350,   378,   392,   405,   418,   437,   442,
     443,   444,   445,   446,   450,   452,   457,   459,   465,   569,
     464,   587,   594,   605,   604,   622,   629,   640,   639,   656,
     673,   696,   695,   709,   710,   711,   712,   713,   717,   718,
     724,   724,   725,   725,   731,   732,   733,   734,   739,   745,
     807,   822,   851,   861,   866,   874,   879,   887,   896,   901,
     913,   930,   936,   945,   963,   981,   990,  1002,  1007,  1015,
    1035,  1058,  1069,  1077,  1099,  1122,  1160,  1181,  1193,  1207,
    1207,  1209,  1211,  1220,  1230,  1229,  1250,  1249,  1267,  1277,
    1276,  1290,  1292,  1300,  1306,  1311,  1337,  1338,  1342,  1353,
    1368,  1378,  1379,  1384,  1392,  1401,  1409,  1427,  1431,  1438,
    1446,  1450,  1457,  1465,  1469,  1476,  1484,  1488,  1495,  1504,
    1507,  1514,  1517,  1524,  1545,  1559,  1573,  1608,  1646,  1660,
    1674,  1694,  1703,  1717,  1732,  1746,  1765,  1775,  1781,  1787,
    1794,  1823,  1838,  1858,  1879,  1900,  1921,  1943,  1965,  1986,
    2009,  2018,  2039,  2054,  2068,  2084,  2100,  2109,  2119,  2129,
    2139,  2154,  2166,  2180,  2193,  2206,  2219,  2256,  2276,  2298,
    2299,  2304,  2307,  2311,  2322,  2333,  2344,  2360,  2379,  2400,
    2415,  2431,  2449,  2500,  2521,  2543,  2566,  2671,  2687,  2722,
    2733,  2739,  2754,  2782,  2799,  2806,  2818,  2837,  2843,  2849,
    2856,  2863,  2870,  2882,  2955,  2973,  2990,  3005,  3038,  3050,
    3074,  3078,  3083,  3090,  3095,  3105,  3110,  3116,  3124,  3128,
    3132,  3141,  3205,  3221,  3238,  3255,  3277,  3299,  3334,  3342,
    3350,  3356,  3363,  3370,  3390,  3416,  3428,  3440,  3456,  3472,
    3489,  3488,  3511,  3510,  3535,  3534,  3557,  3556,  3577,  3591,
    3606,  3621,  3642,  3645,  3651,  3663,  3683,  3687,  3691,  3695,
    3699,  3703,  3707,  3711,  3720,  3733,  3734,  3735,  3736,  3737,
    3741,  3742,  3743,  3746,  3764,  3781,  3798,  3801,  3817,  3820,
    3837,  3840,  3846,  3849,  3856,  3859,  3866,  3883,  3924,  3968,
    4007,  4032,  4041,  4071,  4097,  4123,  4155,  4182,  4208,  4234,
    4260,  4286,  4308,  4314,  4320,  4326,  4332,  4338,  4364,  4390,
    4407,  4424,  4441,  4453,  4459,  4465,  4477,  4481,  4491,  4502,
    4503,  4504,  4508,  4514,  4526,  4544,  4572,  4573,  4574,  4575,
    4576,  4577,  4578,  4579,  4580,  4587,  4588,  4589,  4590,  4591,
    4592,  4593,  4594,  4595,  4596,  4597,  4598,  4599,  4600,  4601,
    4602,  4603,  4604,  4605,  4606,  4607,  4608,  4609,  4610,  4611,
    4612,  4613,  4614,  4615,  4616,  4617,  4618,  4619,  4620,  4629,
    4630,  4631,  4632,  4633,  4634,  4635,  4636,  4637,  4638,  4639,
    4644,  4643,  4651,  4653,  4658,  4664,  4688,  4706,  4724,  4729,
    4735,  4751,  4757,  4763,  4782,  4803,  4836,  4860,  4864,  4869,
    4879,  4889,  4894,  4905,  4914,  4919,  4924,  4953,  4952,  4982,
    4984,  4989,  4998,  5000,  5006,  5007,  5013,  5017,  5021,  5025,
    5029,  5036,  5040,  5044,  5048,  5055,  5060,  5067,  5072,  5076,
    5081,  5085,  5093,  5104,  5108,  5120,  5128,  5136,  5143,  5153,
    5176,  5182,  5188,  5194,  5200,  5211,  5222,  5233,  5244,  5250,
    5256,  5262,  5268,  5278,  5288,  5298,  5311,  5323,  5327,  5331,
    5335,  5353,  5361,  5369,  5398,  5408,  5424,  5442,  5453,  5458,
    5462,  5466,  5478,  5482,  5494,  5511,  5521,  5525,  5540,  5545,
    5552,  5556,  5569,  5583,  5600,  5626,  5630,  5638,  5644,  5650,
    5656,  5665,  5669,  5673,  5681,  5687,  5693,  5701,  5709,  5716,
    5724,  5739,  5753,  5767,  5779,  5795,  5804,  5813,  5823,  5834,
    5842,  5850,  5854,  5873,  5880,  5886,  5893,  5901,  5900,  5910,
    5934,  5936,  5942,  5947,  5955,  5964,  5977,  5980,  5984
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
  "tGetString", "tGetNumber", "tUnique", "tUnique2", "tHomology",
  "tCohomology", "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
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
  "Comma", "DefineConstants", "@6", "@7", "@8", "UndefineConstants",
  "Enumeration", "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptions", "CharParameterOption", "PhysicalId0",
  "PhysicalId1", "PhysicalId2", "PhysicalId3", "InSphereCenter",
  "CircleOptions", "Shape", "Transform", "MultipleShape", "ListOfShapes",
  "LevelSet", "Delete", "Colorify", "SetPartition", "Visibility",
  "Command", "Slide", "Loop", "Extrude", "@9", "@10", "@11", "@12",
  "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "BooleanShape", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@13", "DefineStruct", "@14",
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
     276,   277,   277,   278,   278,   278,   278,   279,   279,   279,
     280,   280,   280,   281,   281,   281,   282,   282,   282,   283,
     283,   284,   284,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   286,   286,   286,   286,   286,   286,   286,   286,   287,
     287,   288,   288,   288,   288,   288,   288,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   290,
     290,   290,   290,   290,   291,   291,   292,   293,   293,   293,
     293,   293,   293,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   295,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   297,   297,   297,
     298,   297,   299,   297,   300,   297,   301,   297,   297,   297,
     297,   297,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   304,   304,   304,   304,   304,
     305,   305,   305,   306,   306,   307,   308,   308,   309,   309,
     310,   310,   311,   311,   312,   312,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   314,   314,   314,   315,
     315,   315,   316,   316,   316,   316,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     319,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   321,   320,   322,
     322,   323,   324,   324,   325,   325,   326,   326,   326,   326,
     326,   327,   327,   327,   327,   328,   328,   329,   329,   329,
     329,   329,   329,   330,   330,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   332,   332,
     332,   332,   333,   333,   333,   333,   334,   334,   335,   335,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   338,   337,   337,
     339,   339,   340,   340,   341,   341,   342,   342,   342
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
       9,     0,     3,     3,     5,     5,     0,     2,     3,     5,
       3,     0,     2,     3,     3,     3,     5,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     0,
       5,     0,     2,     7,     7,     7,     8,     8,     7,     7,
      11,     8,     7,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       8,    12,     8,     7,     7,     8,     8,     8,     8,     8,
       8,     5,    11,     5,     9,     9,     4,     9,     9,     1,
       1,     0,     2,     6,     6,     6,     6,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       6,     6,     3,     4,     5,     6,     5,     3,     3,     4,
       5,     4,     5,     3,     5,     7,     7,     3,     7,     3,
       2,     2,     2,     2,     2,    15,     2,     2,     2,     2,
       2,    16,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     2,
       3,    10,     1,     2,     5,     7,     2,     2,     3,     2,
       3,     2,     3,     9,     6,     1,     1,     1,     1,     1,
       0,     2,     3,     9,     4,    14,     0,     3,     0,     1,
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
       0,     6,     1,     4,     6,     1,     4,     4,     4,     4,
       4,     3,     2,     2,     5,     5,     3,     5,     6,     4,
       7,     6,     6,     6,     4,     6,     4,     0,     8,     1,
       3,     1,     1,     2,     0,     3,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     3,     3,     3,     3,    16,    16,
      16,    16,     1,     1,     1,     3,     4,     4,     4,     6,
       6,     8,     8,     4,    14,     4,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     5,     5,     5,
       5,     1,     4,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     8,
       6,     4,     6,     4,     1,     4,     4,     0,     6,     4,
       2,     4,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   556,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   295,   296,   297,   298,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,   265,   266,     0,     0,     0,   260,     0,     0,
       0,     0,     0,   349,   350,   351,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   557,     0,   201,     0,     0,     0,     0,     0,   244,
       0,   246,   247,   242,   243,     0,   248,   249,   111,   121,
     556,   444,   439,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,     0,   399,   400,   402,
     403,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   407,   408,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,   405,   406,     0,     0,     0,     0,     0,
       0,   482,   483,     0,   484,   457,   356,   412,   415,   279,
     458,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   556,     0,
     201,     0,     0,   346,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,   463,     0,     0,     0,     0,     0,
     556,     0,     0,   504,     0,     0,     0,     0,   240,   241,
       0,   521,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   523,     0,   544,   525,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,   258,
     259,     0,   201,     0,   201,     0,     0,     0,   439,     0,
       0,   201,   352,     0,     0,    76,     0,    63,     0,     0,
      67,    66,    65,    64,    69,    68,    70,    71,     0,     0,
       0,     0,     0,     0,   510,   439,     0,   200,     0,   199,
       0,   167,     0,     0,   510,   511,     0,     0,   552,     0,
     109,   109,     0,   437,     0,     0,     0,     0,     0,   498,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,     0,     0,   471,     0,
     472,     0,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,     0,   358,   465,   360,
       0,   459,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,   423,     0,     0,     0,     0,
       0,     0,   280,     0,   310,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   201,     0,   448,   447,     0,     0,     0,
       0,   201,   201,     0,     0,     0,     0,   276,     0,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,   222,   347,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     239,     0,     0,     0,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   261,     0,   227,     0,   228,     0,     0,
     358,     0,   201,     0,     0,     0,     0,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    72,    73,     0,     0,   237,    38,
     233,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,   202,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,   442,     0,     0,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,   339,   340,   341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,     0,     0,     0,   357,   460,   421,     0,   467,
       0,   374,   373,   372,   371,   367,   368,   370,   369,   362,
     361,     0,   363,   466,   364,   365,   366,   440,     0,     0,
     441,   426,     0,   485,     0,     0,     0,     0,     0,     0,
       0,   308,     0,     0,   137,   138,     0,   140,   141,     0,
     143,   144,     0,   146,   147,     0,   343,     0,   344,     0,
     345,     0,     0,     0,     0,   342,   201,     0,     0,     0,
       0,     0,   450,   449,     0,     0,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,   223,     0,     0,
     219,     0,     0,     0,   338,   337,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   547,     0,
       0,     0,     0,     0,   229,   231,     0,   363,     0,   558,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,   357,     0,    63,     0,     0,     0,     0,
      79,     0,    63,    64,     0,     0,   440,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     554,    28,    26,     0,     0,     0,     0,     0,   441,   514,
      29,     0,     0,   234,   553,    74,   112,    75,   122,   443,
     445,     0,     0,     0,     0,     0,   500,   501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     398,   385,     0,   387,   388,   389,   390,   391,   497,   392,
     393,   394,     0,     0,     0,   488,   487,   486,     0,     0,
       0,   493,     0,   434,     0,     0,     0,   436,   126,     0,
     469,     0,     0,     0,     0,     0,   413,   495,   496,   418,
     419,   461,     0,   420,     0,     0,     0,     0,   417,   416,
     429,     0,     0,     0,     0,     0,   357,   306,   311,   309,
       0,   319,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   357,   357,     0,     0,     0,     0,     0,   230,   232,
       0,     0,     0,   191,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   224,     0,     0,
       0,     0,   534,     0,   541,   530,   531,   532,     0,   546,
     545,     0,     0,   535,   536,   537,   543,   550,   549,     0,
     131,     0,   526,     0,   528,   522,     0,   226,     0,   301,
       0,     0,     0,   353,     0,   555,     0,     0,     0,     0,
     101,    63,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    61,     0,    39,    40,    41,    42,    43,     0,
     417,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,   513,   512,     0,     0,
       0,     0,   126,     0,     0,     0,     0,     0,   151,   151,
       0,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,   375,   462,   427,   425,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,   139,     0,   142,
       0,   145,     0,   148,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,   286,     0,   289,     0,   291,     0,   277,   283,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,   221,   220,   348,     0,     0,    35,
      36,     0,     0,     0,     0,   505,     0,     0,     0,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   302,   201,     0,     0,   517,   518,   519,   520,
       0,    86,     0,     0,     0,     0,    84,    91,    93,     0,
     508,     0,    99,     0,     0,     0,     0,    81,     0,     0,
       0,     0,     0,    34,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
     515,     0,    32,     0,     0,   113,   118,     0,     0,    77,
      78,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   170,   171,     0,     0,     0,     0,   155,   183,   172,
     176,   177,   173,   174,   175,   162,     0,     0,   386,   395,
     396,   397,   489,     0,     0,     0,   432,   433,   435,     0,
     411,   127,     0,     0,     0,     0,   431,   414,   184,   428,
     490,   178,     0,     0,   149,     0,     0,   317,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,     0,   201,   201,     0,     0,   288,   457,     0,
       0,   290,   292,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,   158,   159,     0,     0,     0,     0,   102,   106,     0,
     542,     0,     0,   540,     0,   551,     0,   548,   132,   527,
     529,     0,   300,   300,     0,   354,    85,    63,     0,     0,
       0,     0,    83,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,     0,   428,   235,   236,
     203,   204,   205,   206,     0,     0,     0,     0,     0,   516,
       0,   114,   119,     0,   438,     0,     0,   152,   156,   157,
     163,     0,     0,   182,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   430,     0,   164,
       0,   185,   307,   187,   188,   189,   190,   161,     0,   180,
     186,     0,     0,     0,     0,     0,     0,   454,   453,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     216,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,   321,    37,     0,   503,     0,     0,   255,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,    97,   509,     0,
       0,    88,     0,     0,     0,    44,     0,     0,     0,     0,
       0,    46,    33,     0,   126,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,   492,     0,     0,   128,
     130,     0,     0,     0,     0,     0,   166,     0,   314,   314,
       0,   107,   108,   201,     0,   194,   195,   278,     0,   284,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   197,     0,     0,     0,     0,   103,   104,   533,
     539,   538,     0,   133,   134,   135,     0,     0,   303,     0,
      92,    94,     0,   100,     0,    82,    89,    90,    49,     0,
       0,     0,     0,   456,     0,     0,     0,     0,     0,   116,
     332,   334,   333,   335,     0,   336,   169,     0,     0,     0,
     498,   499,     0,     0,     0,     0,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   452,     0,   294,
       0,     0,   272,     0,   208,     0,     0,     0,     0,     0,
       0,     0,   502,   256,     0,     0,     0,   201,   355,     0,
     507,     0,    45,     0,     0,     0,    62,    47,     0,   115,
     120,   126,   150,     0,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   315,   325,     0,     0,
     326,     0,   192,     0,   285,     0,   268,     0,   201,     0,
       0,     0,     0,     0,     0,   160,   105,   136,   252,   300,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,   181,     0,   329,     0,
     330,   331,   451,     0,     0,   274,   211,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,    59,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   273,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,     0,     0,     0,     0,     0,     0,     0,   212,   213,
     214,   215,     0,   209,   305,    50,     0,    57,     0,   245,
       0,   494,     0,     0,     0,     0,     0,     0,   275,     0,
       0,    51,     0,     0,   251,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,   478,   479,   480,   481,
       0,     0,    54,    52,     0,    55,     0,   327,   328,     0,
       0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1003,   109,   110,   985,  1744,  1750,
    1254,  1448,  1891,  2040,  1255,  2003,  2064,  1256,  2042,  1257,
    1258,  1452,   399,   545,   546,  1067,   111,   720,   420,  1754,
    1901,  1755,   421,  1849,  1322,  1521,  1417,  1598,   853,   856,
     859,   862,  1495,  1485,   704,   251,   408,   409,   114,   115,
     116,   117,   118,   119,   120,   121,   252,  1159,  1927,  1994,
     889,  1155,  1156,   253,   962,   254,   125,  1344,  1120,   851,
     903,  1861,   126,   127,   128,   129,   255,   256,  1088,   257,
     725,   258,   841,   724,   423,   576,   290,  1624,   324,   325,
     260,   522,   332,  1242,  1441,   418,   414,  1210,   946,   419,
     131,   378
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1596
static const yytype_int16 yypact[] =
{
   10157,    36,    53, 10305, -1596, -1596,  -142,   138,    68,  -153,
     -43,    48,   160,   201,   212,   215,    90,   222,   244,    62,
     122,    28,  -122,  -122,   118,   172,   206,    27,   220,   226,
      39,   232,   237,   242,   247,   263,   298,   304,   325,   338,
     347,   334,   460,   598,   348,   127,   361,  5510,   362,   391,
     558,   -66,   436,   506,   623,   283,   407,   570,   -10,   437,
     126,   126,   443,   322,   448, -1596, -1596, -1596, -1596, -1596,
     465,   105,   617,   662,    19,    55,   677,   656,   569,   768,
     820,   828,  4823,   836,   615,   635,   654,    34,    18, -1596,
     655,   663, -1596, -1596,   806,   842,   665, -1596, 10470,   664,
    4927,    21,    46, -1596, -1596, -1596,  9471,   666, -1596, -1596,
   -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596,
   -1596, -1596, -1596,   196, -1596, -1596, -1596, -1596,    51, -1596,
     881,   697,  4576,   394,   699,   894,  9471,  4678,  4678, -1596,
    9471, -1596, -1596, -1596, -1596,  4678, -1596, -1596, -1596, -1596,
     705,   721,   944, -1596, -1596,  4229,    28,  9471,  8029,  9471,
    9471,   727,  9471,  8029,  9471,  9471,   732,  9471,  8029,  9471,
    9471,  9471,  9471,  9471,  9471,  4678,  9471,  9471,  9471,  5739,
     741, -1596,  8029,  4823,  4823,  4823,  4678, -1596, -1596, -1596,
   -1596, -1596,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,    75,  -122,  -122,  -122,  -122,
    -122,   749,  -122,  -122,   754, -1596, -1596, -1596,  -122,    16,
      22,    29,    35,  5739,   829,   563,   767,  -122,  -122,  -122,
     789,   796, -1596, -1596, -1596,  9471,  5968,  9471,  9471,  6197,
      32, -1596, -1596,   711, -1596,  3349, -1596, -1596, -1596, -1596,
   -1596,   106,  9471,  8029,   801,   803,  6426,  4823,  4823,  4823,
     819,   825,   826,   834,  6655,  6884,  7113,   752,  8874,  1073,
    5739,    34,   849,   878,   126,   126,   126,  9471,  9471,   -48,
   -1596,   -11,   126,  8943,   162,   301,   855,   876,   883,   901,
     906,   911,   914,  9471,  4823,  4823,  4823,   915,     5,   896,
   -1596,  1141,  1143, -1596,   928,   930,   934,  4823,  4823,   939,
     945,   949, -1596,  9471, -1596,  1171,  1177,  9471,  9471,  9471,
      99,  9471,   950, -1596,  1010,  9471,  9471,  9471, -1596, -1596,
    9471, -1596,  -122,  -122,  -122,   955,   956,   957,  -122,  -122,
    -122,  -122,  -122,  -122,  -122, -1596,  -122, -1596, -1596,  -122,
    -122,   958,   960,  -122, -1596,   959,  1187,  1188,   961, -1596,
   -1596,  1191, -1596,  1194, -1596,  -122,  9471, 11822,   123,  4678,
    9471, -1596, -1596,  5739,  5739, -1596,   966,  4229,   576,  1195,
   -1596, -1596, -1596, -1596, -1596, -1596,  9471,  9471,    41,  5739,
    1197,   554,   193,   969,  1199,    24,   971, -1596,   973, 10593,
    9471, -1596,   398,  -110, -1596,    57,   -99,  4344, -1596,   -78,
    -188,  -178,  1122, -1596,    28,   972,   974, 12216,  8029,  3436,
   -1596,    87, 12237, 12258,  9471, 12279,   331, 12300, 12321,  9471,
   12342,   354, 12363, 12384, 12405, 12426, 12447, 12468,   979, 12489,
   12510, 12531,  1214,  9471,   366,  1210,  1216,  1217,   988,  9471,
    9471,  9471,  9471,  9471,  9471,  9471,  9471,  9471,  9471,  9471,
    9471,  9471,  9471,  9471,  9471,  8029,  9471,  9471,  9471,  9471,
    9471,  9471,  8029,  8029,   989,  9471,  9471,  4678,  9471,  4678,
    5739,  4678,  4678,  4678,  9471, -1596,  1161,  9471, -1596,  1162,
   -1596,  1163, -1596,  1164,  5739,  4823,  4823,  4823,  4823,  4678,
    4678,  8029,  8029,    28,  4229,   999,  8029,   999, -1596,   999,
   12552, -1596,   538, -1596,    74,  9471,  9471,  9471,  9471,  9471,
    9471,  9471,  9471,  9471,  9471,  9471,  9471,  7342,  9471,  9471,
    9471,    28,  9471,  9471,  1226, -1596,   936, 12573,   539,  9471,
    9471,  9471, -1596,  1225,  1228,  1228,  8650,  8650,  8650,  8650,
    9471,  1227,  9471,  1230,  9471,  1231,  8029,  8029, 11846,  1007,
    1234,  1006, -1596, -1596,  -149, -1596, -1596,  4451,  4493,   126,
     126,   394,   394,  -141,  8943,  8943,  9471,  2825,  -136, -1596,
    9471,  9471,  9471,  9471,  9471,  9471,  9471,  9471,  9471, 12594,
    1235,  1237,  1238,  9471,  1240,  9471,  9471,  2957, -1596, -1596,
    8029,  8029,  8029,  1241,  1242,  9471,  9471,  9471, 12615, -1596,
   -1596, 12636, 12657, 12678,  1078,  4989, -1596,  1009,  3485, 12699,
   12720, 11917,  4678,  4678,  4678,  4678,  4678,  4678,  4678,  4678,
    4678,  9471,  4678,  4678,  4678,  4678,    10,  4229,  4678,  4678,
    4678,    28, -1596, -1596,  8029, -1596,  3150, -1596,  9499,  9471,
     999,  9471, -1596,  9471,  9471,  1016, 12741, 10481,  1020,   541,
    9471,  1247,  1019,  1021,  1022,  1034,  9471, 12762, 11940,   161,
    1018,  1264,  1270, -1596, -1596, -1596,  8029,   157, -1596, -1596,
   -1596,    28,  9471,  9471,  1226,  1044, -1596,   549,    44,    45,
     556,  1047,   -56,   658, -1596,  4256, -1596,    71,  8029,    28,
    9471,  9471,  1275,  1277,  8029,  9471,  1278,  4678,  1280, -1596,
      28,  1282,  4678,  9471,  1057,  1058, -1596,  9471,  4229,  1283,
    8029,  1118,  8029,  1287,  1289, 12783,  1291,  1126,  1296,  1297,
   12804,  1298,  1127,  1299,  1300,  1303,  1304,  1305,  1306, -1596,
    1309,  1311,  1314,  9471, 12825,  1074, -1596, -1596, -1596,  1327,
   11894, 11894, 11894, 11894, 11894, 11894, 11894, 11894, 11894, 11894,
   11894,  5218, 11894, 11894, 11894, 11894,   659,   188, 11894, 11894,
   11894,  5447,  5676,  5905,  3436,  1102,  1101,    91,  8029,  6134,
    6363,   188,  6592,   188,  1104,  1106,  1108,    -7, 13455,  1107,
    9995,  1115,  1121,  1123, -1596, -1596, -1596, -1596,  1119,  -164,
     188,   188,  1109,  1128,   575,  1354, -1596, -1596,   188,  3508,
    3573,   937,   873,   543,   543,   479,   479,   479,   479,   498,
     498,  8029,   999, -1596,   999,   999,   999,  1125, 12846, 11963,
     134, -1596,  8029, -1596,  1356,  1129, 12867, 12888, 12909,  9471,
    5739,  1361,  1360,  1135, 13455,  1131,  1137, 13455,  1132,  1142,
   13455,  1133,  1144, 13455,  1138, 12930, -1596, 12951, -1596, 12972,
   -1596,   578,   580,  8029,  1140, -1596, -1596,  9538,  9633,   126,
    9471,  9471, -1596, -1596,  1145,  1146,  8943,  2438,  1254,   816,
     126,  9671, 12993, 11072, 13014, 13035, 13056, 13077, 13098, 13119,
   13140,  1376,  9471,  1378, -1596,  9471, 13161, -1596, 11986, 12009,
   -1596,   581,   586,   587, -1596, -1596, 12032, 12055,  6821, -1596,
    1379,  1382,  1384,  1148,  9471,  9766,  9471,  9471, -1596, -1596,
       8,  -127,   251,  -127,  1160,  1165,  1153,   188,   188,  1154,
    7050,   188,   188,   188,   188,  9471,   188,  1386, -1596,  1156,
    1168,   280,  1167,   589, -1596, -1596, 11894,   999,  9804, -1596,
    1395,  9173,  1172,  1174,  1401,  5739, 11097, -1596,  9471,  9471,
    9471,  9471,  1209,   225,    89,  4229,  9471,  1404,  1407,    78,
   -1596,   594,  1366,  1367,  5739,    31,  1178, 13182, 12078,  1179,
    9471,  8029,  8029,  8029,  8029,  9471,  1204,  1206,  1207,  1215,
   -1596, -1596,  1200,  4678,    64,  1203, 13203, 12101, -1596, -1596,
   -1596,   159,  7279, -1596, -1596, -1596,     9, -1596, -1596, 13455,
   -1596,  9471, 11894,   188,   126,   421,  3436, -1596,  5739,  5739,
    1434,  5739,   530,  5739,  5739,  1437,  5739,  1352,  5739,  5739,
    5739,  5739,  5739,  5739,  5739,  5739,  5739,  1302,  1443,  8029,
   -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596,
   -1596, -1596,  9471, -1596, -1596, -1596, -1596, -1596, -1596, -1596,
   -1596, -1596,  9471,  9471,  9471, -1596, -1596, -1596,   595,  9471,
    9471, -1596,  9471, -1596,  5739,  4678,  4678, -1596, -1596,  9471,
   -1596,  9471,  9471,  9471,  9471,  9471, -1596, -1596, -1596, -1596,
   -1596, -1596,  5739, -1596,  9471,  9471,   597,  1275,   134,   -70,
   -1596,   605,  5739,  8029,  1444,  1445,  1446,   903, -1596, -1596,
    1448, -1596,   184,  9471,   184,  9471,   184,  9471,   184,  9471,
    1449,  1450,  1451,  1452,  1453,   629,  1457,  9899, -1596, -1596,
    -134,  7508,  7737, -1596, -1596, 11122,   -97,  1355,  1459,  9247,
    1229,  1461,  1255,    49,    61,   318, -1596,  -132, -1596,   816,
    1458,  1481,  1482,  1484,  1486,  1487,  1488,  1489,  1491,  5739,
   13455, -1596,  1618,  1253,  1493,  1494,  1495,  1408,  1497,  1496,
    1499,  9471,  5739,  5739,  5739,  1502,  7966, -1596,  3704,  1260,
    1503,  1505, -1596,  8029, -1596, -1596, -1596, -1596,  4678, -1596,
   -1596,  9471,  4678, -1596, -1596, -1596, -1596, 13455, -1596,  1272,
   -1596,  4678, -1596,  4678, -1596, -1596,  1271, -1596,  1295, -1596,
    1694,  1301,  5739, -1596,  1293, -1596, 11147, 11172, 11197, 11222,
   -1596, -1596,  9471,  1507,    43,  9471,  1527,  1528,  1796, -1596,
    1530,    34,  1529,  1307,   188,  -122,  -122,  1532, -1596,  1308,
    1310,  1313, -1596,  1538, -1596, -1596, -1596, -1596, -1596,  1275,
     330,  2492, 12124,   652,   661,   695,   701, 13224,  9471,  9471,
    9471,  9471, -1596,  1539,    92,  1275, -1596,  1312,  1540,  9471,
    8253,   188, 13455,  1544,  1545,   108,  1317,  1318,  1435,  1435,
    5739,  1548,  1322,  1323,  1553,  1556,  5739,  1389,  1329,  1560,
    1561,  1562,  1563,  1564,  1566,  1567,  1568,  1571, -1596,  1576,
     703, 11894, 11894, 11894, 11894,   188,  8280,  8593,  8703,  1351,
     188,   188,   365,  8772,  8815,  8901,  9002, 13245, 11894,  1578,
   13455, 13455, -1596, -1596, -1596,  1581, -1596,   188,  1583,   714,
    5739,  5739,  5739,  1586,  1587, -1596,  5739, 13455,  5739, 13455,
    5739, 13455,  5739, 13455,  5739,  5739,  5739,  1357,  1359,  1588,
     680, -1596,  9471,  9471,  9471,  1362,  1363,  1364,  1369, -1596,
    1914,  5739, -1596,  9471, -1596,  1590, -1596,  1594, -1596, -1596,
    8943,   523,  5052, -1596,  1368,  1370,  1371,  1374,  1380,  1381,
    7571,  1598, -1596,  8029, -1596, -1596, -1596,  1383,  9471, -1596,
   -1596, 12147,  1605,  1607,  1447, -1596,  9471,  9471,  9471, -1596,
    1613,   750,   450,  1385,  2008,  1390,  9471,   457,  1388,   188,
    4229, -1596, -1596, -1596,  1391,  1615, -1596, -1596, -1596, -1596,
    2053, -1596,   230,  1392,  1616,  2085, -1596, -1596, -1596,    34,
   -1596,   715, -1596,  9471,   184,  1213,  4678, -1596,  1402,  9471,
    9471,  5739,  1387, -1596,  1400,  1633,  1637,  1638,  1639,  1640,
    1641,  1643,  1354, 13266, 13287, 13308, 13329, -1596, -1596,  4678,
   -1596,  1635, -1596,  9076,  3982, 13455, -1596,  1644,  -103, -1596,
   -1596, -1596,  9471,  9471,   126,  1646,  1647,  1648, -1596,  9471,
    9471, -1596, -1596,  1650,  1557,  1652,  9471, -1596, -1596, -1596,
   -1596, -1596, -1596, -1596, -1596, -1596,  1655,  1426, -1596, -1596,
   -1596, -1596, -1596,  9471,  9471,  9471, -1596, -1596, -1596,  1658,
   -1596, -1596,  9471,  9471,  9471,  9471, -1596, -1596, -1596,   134,
   -1596, -1596,  1428,  1659,  1389,  1660,  9471, -1596,  1661,  1663,
    1664,  1665,  1666,   673,  1667,  8029,  8029,  9471, -1596,  8650,
   11247, 13350,  3131,   394,   394,  9471,  9471, -1596,   522,  1424,
   13371, -1596, -1596, 11272,  -119, -1596,  1668,  1669,  5739,   126,
     126,   126,   126,   126,  5281,  1671, -1596,   724,  9471,  2118,
    1672, -1596, -1596,  5739,  3651,   583, 13392, -1596, -1596,  8337,
   -1596,  4678,  9471, -1596,  4678, 13455,    20, -1596, -1596, -1596,
   -1596,  1439, 10481, 10481,  5739, -1596, -1596,  4229,  9471,  1674,
    1677,    78, -1596,  1676, -1596,    34, 12170,  5739,  1678,  -127,
    -127,  9471,  9119,  9201,   725, -1596,  9471,   428, -1596, -1596,
   -1596, -1596, -1596, -1596,  1446,  1449,  1450,  1451,  1680, -1596,
    9471, -1596, -1596,  1454, -1596, 11297, 11322,   324, -1596, -1596,
   -1596, 11347, 11372, -1596,  1455, -1596, 11397,  1682,  5739, 11894,
   11894,  9343,  4306,  9610,  9743,  9868,  9963, -1596,  9471, -1596,
    1685, -1596, 13455, -1596, -1596, -1596, -1596, -1596,  1460, -1596,
   -1596,   735,   746, 11870,  2493,  1687,  1462, -1596, -1596,  9471,
    1463,  1465, 11422, 12193,  1688,  5739,  1681,  1467,  9471, -1596,
   -1596,   756,  -104,  -102,   -94,   -71,   -65,  7800,   -51, -1596,
    1690, 11447, -1596, -1596,  1514, -1596,  9471,  9471, -1596, -1596,
    8029,  2518,  1692,  1471, 11894,   188,  8566,  4229,  4229,  1469,
    1470,  1472,  1701,  2592, -1596,  1702,  1704, -1596, -1596,  1474,
    1706, -1596,  1707,  1708,   210, 13455,  9471,  9471,  1480,  5739,
     757, 13455, -1596, 10396, -1596, -1596,  5739,  1710,  1712,  1713,
    1714,  9471,  1715,  1716,   759, -1596, -1596,  9471,  6197, -1596,
   -1596,  9471,  9471,  9471,  9471, 11472, -1596,  5739,   243,   577,
    8029, -1596, -1596,   394,  3742, -1596, -1596, -1596,  1717, -1596,
    1498,  5739, -1596, 11497,  1718,  8029,   126,   126,   126,   126,
     126, -1596, -1596,  9471, 11522, 11547,   765, -1596, -1596, -1596,
   -1596, -1596,  4678, 13455, -1596, -1596,  1500,  1501, -1596,  1723,
   -1596, -1596,    34, -1596,  1558, -1596, -1596, -1596, -1596,  9471,
   10506, 10550,  5739, -1596,  1725,  9471,  9471,   770,   771, -1596,
   -1596, -1596, -1596, -1596, 11572, -1596, -1596,  1504, 10579,   776,
    2920,  1726, 10608, 10637, 10666, 10695, -1596,   778,  1506,   126,
    5739,  1729,  1509,   126,  1732,   779,  1511, -1596,  9471, -1596,
    1734,  1619,  9937,  1513, -1596,   781,   -17,   137,   179,   227,
     234,  2611, -1596, -1596,  1736,   808,  1743, -1596, -1596,  1744,
   -1596,  1516, 13455,  9471,  9471,   809, -1596, 13455, 10724, -1596,
   -1596, -1596, -1596,  9471,  9471, -1596,  9471,  4229,    28,  9471,
    9471,  9471,  9471,  1746,   126,   110, -1596, -1596,   126,   120,
   -1596,  1748, -1596, 11597, -1596,  9471, -1596,   816, -1596,  1749,
    8029,  8029,  8029,  8029,  7800, -1596, -1596, -1596, -1596, 10481,
   -1596,  9471, 13413, 10753,    52,  9471,   811, 10782, 10811,   637,
   -1596,  1525, 10840, 10869, 10898, 10927, -1596,   260, -1596,   271,
   -1596, -1596, -1596,  2739,   573, 10032, -1596,   831,   832,   838,
     839,   275,   840,  1521,   864, -1596,  9471, -1596,  5739, 11622,
   -1596,  9471,  9471,  4229,  1526,  9471,  9471,  9471,  9471,   126,
     126, -1596, -1596, -1596,   816,  1753,  1755,  1756,  1757,  8029,
    1758,  1760,  1761,  1533, 13434,   865,  1763, 11647, 11894, -1596,
   -1596, 10956, 10985, 11014, 11043,   277,   300,   851, -1596, -1596,
   -1596, -1596,   866, -1596, -1596, -1596,  4678, -1596,  1535, -1596,
    1765, -1596,  9471,  9471,  9471,  9471,  9471,  9471, -1596,  1766,
     872, -1596,  1541,  5739, -1596, 11672, 11697, 11722, 11747, 11772,
   11797, -1596,  1767,  4678,  4678,   898, -1596, -1596, -1596, -1596,
    1769,  1772, -1596, -1596,   904, -1596,  1773, -1596, -1596,  1774,
    4678, -1596, -1596, -1596
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1596, -1596, -1596, -1596,   507, -1596, -1596, -1596, -1596,  -159,
   -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596, -1596,
   -1596, -1596,  -662,  -130,   710,  2829, -1596,  1365, -1596, -1596,
   -1596, -1596, -1596, -1596, -1277, -1596,    30, -1596, -1596, -1596,
   -1596, -1596,   249,   495,  1784,     7,  -570,  -280, -1596, -1596,
   -1596, -1596, -1596, -1596, -1596, -1596,  1786, -1596, -1596, -1596,
   -1596, -1156, -1154,  1788, -1595,  1790, -1596, -1596, -1596,  1239,
   -1596,    17, -1596, -1596, -1596, -1596,  1916, -1596, -1596,  1792,
   -1596,  1776,  -675, -1596, -1596,  1294, -1596, -1548,   286,  -120,
    2687,   182,  -275,   189, -1596,   -63,   136, -1596, -1596,  -489,
   -1596,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -517
static const yytype_int16 yytable[] =
{
     132,  1379,   400,  1381,   797,  1478,   571,  1729,  1730,   604,
     113,   884,   885,   587,   150,  1190,  1280,   976,   152,   989,
    1701,   495,   334,   308,  1726,   984,   371,   498,   150,   265,
     607,   161,   150,   691,   500,  1248,   150,  1009,   330,   265,
     502,   523,     4,   166,   261,   679,   718,  1432,   161,   166,
     266,   373,   719,     5,   139,  1374,   721,   382,  1977,   312,
     996,   313,   719,   455,   456,   457,   709,  1376,   684,   403,
     685,   311,   579,   580,   413,   416,  1095,  1001,   137,   261,
     579,   580,   150,   817,   333,   579,   580,   579,   580,   579,
     580,   879,   656,   133,   658,   367,  1231,   134,  1468,   886,
     541,   667,   579,   580,   890,   684,  1362,   685,  1380,   153,
    1764,   154,   448,   717,  1481,   541,  1958,   579,   580,   579,
     580,  1698,   707,   458,   579,   580,  1960,   579,   580,   405,
     708,  1644,   541,   713,   415,   415,  1795,  1519,  1796,  1366,
     407,   714,   415,   931,   314,   933,  1797,   553,   554,   555,
     579,   580,   135,   426,   716,   261,   579,   580,   394,   395,
     261,   281,   717,   136,   982,   261,   141,  1335,   975,  1798,
     579,   580,   415,   579,   580,  1799,   261,   282,   283,   261,
     261,   261,   261,   415,   600,   601,   602,   581,   138,  1800,
     496,  1231,  1249,  1250,  1251,  1252,   499,   613,   614,   688,
     304,   309,   305,   501,   579,   580,  1727,   142,  1375,   503,
     579,   580,   680,   681,  1433,  1434,   183,   107,   143,   184,
    1377,   144,   185,  1930,   582,  1087,   107,  1379,   146,  1857,
     261,   107,  1231,   717,   366,   107,   370,  1607,   605,   107,
     153,   107,   154,   261,   134,  1191,   261,   524,   945,   335,
     147,   497,   394,   395,   310,   692,   372,   693,   162,  -511,
     261,   694,   163,   261,   261,   261,   261,  1253,   404,   331,
     167,   261,   261,   261,   168,   162,   167,   261,   333,   992,
     993,   374,   383,   140,  1895,   107,   384,  1978,   710,  1002,
     711,   425,   877,   878,   712,   148,  1274,   390,   391,   392,
     393,   261,   261,   261,   732,   153,   482,   154,   483,   891,
    1002,  1232,  1235,  1241,   261,   261,   665,   394,   395,   394,
     395,   145,   542,   731,   543,  1077,  1234,   732,   544,   579,
     580,   579,   580,   259,   394,   395,   624,   542,   134,   543,
     431,   579,   580,   544,  1973,   436,   925,   285,   286,   157,
     441,   394,   395,   158,   663,   149,   664,   287,   579,   580,
     544,   288,   394,   395,   454,   390,   391,   392,   983,   390,
     391,   392,   393,  1858,  1859,   277,   415,  1931,   278,  1860,
     261,   261,   958,   579,   580,   804,   805,   806,   807,   394,
     395,  1278,   390,   391,   392,   393,   261,   589,   406,   732,
     579,   580,   695,   159,   706,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,  1932,
     684,   726,   685,   540,   791,   261,   793,   380,   795,   796,
    2005,   381,  1333,   390,   391,   392,   393,   160,   390,   391,
     392,   393,  1828,   179,  1148,   548,   808,   809,   579,   580,
    1829,   164,   295,   394,   395,   579,   580,   165,   394,   395,
    1346,  1149,  1348,   169,  1350,   452,  1352,  1933,   170,  1150,
    1151,  1152,   261,   171,  1934,  1153,  1154,  1837,   172,   261,
     787,   579,   580,   684,   415,   685,   415,   261,   415,   415,
     415,  1193,   579,   580,   173,  2055,   579,   580,   579,   580,
    1989,   261,   261,   261,   261,   261,   415,   415,   261,   261,
     812,  1990,   684,   261,   685,  1999,  1286,  2036,  1287,   259,
    1213,   579,   580,   671,    59,    60,    61,    62,   267,   174,
     525,   268,   590,   269,   261,   175,   591,   296,   837,    73,
    2037,   297,    76,   285,   286,   579,   580,   298,   299,   977,
     300,   301,   552,   287,  1378,   180,   176,   293,   394,   395,
     561,   563,   565,   261,   261,  -513,   570,   737,   302,   177,
     932,   732,   934,   935,   936,   937,   938,   939,   178,   941,
     942,   943,   944,   182,  1454,   949,   950,   951,   407,   407,
     742,  1717,   186,   262,   732,   270,  1137,   684,   271,   685,
    1470,   272,   755,   273,   181,  1519,   732,   261,   261,   261,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,  1946,  1292,   263,  1293,   540,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   279,   415,
     415,   415,   415,   947,  1983,   415,   415,   415,   952,  1148,
     813,   261,   505,   264,  1014,   506,   394,   395,   507,  1018,
     508,   317,   280,  -516,   318,   672,  1149,   525,   673,   668,
     669,   674,   284,   675,  1150,  1151,  1152,  1678,   292,  1679,
    1153,  1154,   684,   261,   685,   682,  1548,  1549,   986,   684,
     732,   685,   855,   858,   861,   864,   303,  1596,   814,  1148,
     535,   536,   661,   538,   539,   261,  1005,  1862,  1863,   540,
    1110,   261,   306,  1860,   415,   274,  1149,  1016,   275,   415,
     276,   661,   538,   539,  1150,  1151,  1152,   261,   540,   261,
    1153,  1154,   155,   156,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   871,   872,
     997,   316,   540,   998,   307,   999,  1588,  1589,  1694,  1565,
     531,   532,   533,   534,   535,   536,   661,   538,   539,   315,
    1608,  1964,   319,   540,   816,   845,   794,   964,   732,   732,
     157,   965,  1617,   948,   991,   261,   684,   170,   685,   686,
     552,   994,   911,   912,   913,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,  1992,
    1379,  1101,   338,   540,  1133,   732,  1134,  1176,   732,  1718,
     732,   732,  1177,  1178,   320,  1216,   732,   732,   261,   732,
    1244,  1315,   321,  1332,   732,   732,   953,   732,  2017,   261,
     326,  1337,   401,  1233,  1236,   732,   327,   261,   339,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,  1379,  1023,  1359,   328,   540,   981,   732,
     261,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   730,   538,   539,   329,   336,   385,  1458,   540,
    1004,   684,   732,   685,   337,   368,  1011,  1459,   340,   379,
     411,   732,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   484,   485,   486,   487,   488,
     489,  1460,   491,   492,   410,   732,   386,  1461,   494,  1507,
    1273,   732,  1148,   732,   134,   504,   381,   510,   511,   512,
    1532,  1614,   422,   424,   732,  1615,  1619,  1620,   434,  1149,
    1710,  1748,   261,   439,   732,  1749,  1440,  1150,  1151,  1152,
    1078,  1778,   453,  1153,  1154,   732,  1243,  1148,  1334,  1336,
     490,   261,  1779,  1690,  1691,   493,   732,   566,   261,   261,
     261,   261,  1794,  1834,  1149,  1847,  1749,  1835,   509,  1749,
     415,  1884,  1150,  1151,  1152,   732,  1899,  1900,  1153,  1154,
    1519,  1596,  1905,  1106,  1913,  1921,  1906,  1929,  1749,   732,
     513,   732,  1320,  1321,  1111,   261,   261,   514,   261,  1343,
     261,   261,   549,   261,   550,   261,   261,   261,   261,   261,
     261,   261,   261,   261,  1937,  1944,   261,  1980,   717,  1749,
     556,  1519,   632,   633,   634,  1135,   557,   558,   638,   639,
     640,   641,   642,   643,   644,   559,   645,  1995,  1996,   646,
     647,   732,   732,   650,  1997,  1998,  2000,   569,   732,   732,
     732,   261,   415,   415,   572,   659,   592,  2038,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,   261,
    2002,  2028,  2039,   540,  1835,  1749,   732,   593,  2052,   261,
     261,  1237,  2053,   573,   594,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,   606,
    1334,  1336,   595,   540,  2066,  1413,  1118,   596,  1749,  1415,
    2069,  1602,   597,  1603,  2070,   598,   603,   608,  1418,   609,
    1419,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,   610,  1613,   611,   261,   540,   684,   612,
     685,   842,   615,  1263,  1264,  1265,  1266,   619,   616,   261,
     261,   261,   617,   620,   627,   626,   635,   636,   637,   648,
     261,   649,   651,   652,   653,   415,   654,   655,  1456,   415,
     657,   670,   676,   683,   689,   690,   133,   723,   415,   696,
     415,   749,   727,  1866,   728,  1230,   756,   150,   341,   261,
     759,   753,   757,   758,   788,   799,   801,   802,   803,   540,
     840,  1310,   849,   866,   818,   850,   868,   870,   333,   874,
     875,   876,   902,   904,   926,   905,   907,   914,   915,   923,
     959,  1224,   963,   967,   968,   978,   969,   970,   415,   342,
     343,   344,   345,   346,   347,   348,   349,   350,  1408,   971,
    1247,   979,   351,   352,   353,   354,   980,   990,   995,  1008,
     355,   356,   357,  1010,  1013,   358,  1015,   261,  1017,  1020,
    1024,  1021,  1025,   261,  1028,  1339,  1029,   359,  1031,   360,
    1032,  1037,  1609,  1033,  1034,  1036,  1038,  1039,  1308,  1049,
    1040,  1041,  1042,  1043,  1288,  1289,  1044,  1291,  1045,  1294,
    1295,  1046,  1297,  1885,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1050,  1075,  1076,   388,   261,   261,   261,
    1738,  1099,  1089,   261,  1084,   261,  1085,   261,  1086,   261,
    1091,   261,   261,   261,   289,   291,  1092,   294,  1093,  1094,
    1100,  1102,  1107,  1112,  1113,  1119,  1121,  1122,   261,  1124,
    1319,  1123,  1125,  1127,  1126,  1412,  1128,  1136,  1129,   261,
    1147,  1143,  1144,  1169,  1171,  1185,  1182,   261,  1329,  1183,
     261,  1184,  1196,  1198,  1201,  1209,  1211,  1197,  1338,  1667,
    1212,  1215,  1218,   361,   362,   363,  1638,  1223,  1221,  1222,
    1239,  1240,  1245,  1246,  -514,  1259,  1476,   364,  1272,   365,
     107,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,  1268,   333,  1269,  1270,   540,
    1275,  1290,   415,   415,  1296,   684,  1271,   685,   261,  1298,
    1309,  1340,  1341,  1342,  1345,  1391,  1354,  1355,  1356,  1357,
    1358,  1360,  1367,  1368,  1371,  1382,   415,  1372,  1402,  1403,
    1404,   261,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,  1373,  1383,  1393,  1384,
     540,  1385,  1409,  1386,  1387,  1388,  1389,  1667,  1390,  1394,
    1395,  1396,  1399,  1397,  1398,  1400,  1405,  1410,  1424,  1411,
    1416,  1420,  1872,  1431,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,  1723,  1425,
    1421,  1725,   540,  1436,  1437,  1442,  1423,  1439,  1447,  1449,
    1443,  1450,   261,   261,  1453,  1467,  1472,  1889,  1451,  1471,
    1479,  1480,  1482,  1483,  1488,  1484,  1601,  1489,  1490,  1491,
     407,   407,  1492,  1494,  1496,   261,  1497,  1498,  1499,  1500,
    1501,   261,  1502,  1503,  1504,  1577,  1487,  1505,   574,   575,
     261,  1506,  1493,  1516,  1528,  1529,   583,   588,   415,  1531,
    1536,   415,  1545,  1537,  1546,  1547,  1561,  1553,  1554,  1555,
    1562,   261,  1556,  1568,  1576,  1569,  1570,  1939,  1243,  1571,
    1642,  1581,   333,  1582,   261,  1572,  1573,  1583,  1578,  1587,
    1599,  1605,  1626,  1611,  1392,  1591,  1533,  1534,  1535,  1610,
    1594,  1604,  1538,  1621,  1539,  -515,  1540,  1627,  1541,  1639,
    1542,  1543,  1544,  1628,  1629,  1630,  1631,  1632,  1965,  1633,
    1654,  1643,  1648,  1649,  1650,   261,  1653,  1559,  1655,   261,
    1657,  1658,  1662,  1668,  1695,  1669,  1671,  1673,  1567,  1674,
    1675,  1676,  1677,  1680,  1699,  1700,  1575,  1709,  1713,  1728,
    1734,  1735,  1737,  1803,  1741,  1685,  1752,  1763,  1791,  1756,
    1761,  1776,   261,  1782,  1789,  1777,  1801,  1783,  1808,  1785,
    1422,  1786,  1792,  1809,   261,  1817,  1818,  1820,  1819,  1822,
    1823,  1824,  1825,  1826,  1827,  1832,  1840,   261,  1841,  1842,
    1843,  1845,  1846,  1869,  1874,  1722,  1281,  1681,  1682,  1888,
    1890,  1896,  1886,  1908,  1870,  1917,  1887,  1625,  1920,  1903,
    1924,  1914,  1936,  1732,  1918,  1925,   261,  1922,  1928,  1938,
    1940,  1941,  1956,   261,  1961,  1966,  1984,  2001,  2010,  2018,
    1641,  2019,  2020,  2021,  2023,   261,  2024,  2025,  2026,  2029,
    2043,  2044,  2051,  2062,   261,  2067,  2054,   261,  2068,  2071,
    2072,  1469,  1974,  1670,  1486,  1838,   722,   112,   261,   122,
     407,   123,   261,   124,   852,   130,  1864,   151,  1770,     0,
    1736,     0,  1438,     0,     0,     0,     0,     0,     0,   415,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,  1625,     0,     0,   261,     0,     0,
       0,     0,  1814,  1815,  1816,     0,     0,     0,     0,  1714,
       0,     0,     0,   882,   883,     0,     0,     0,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1731,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1806,  1740,     0,  1951,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
    1557,     0,     0,     0,   540,     0,     0,   261,   261,   261,
     261,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1625,     0,     0,     0,  1769,     0,
       0,     0,     0,     0,     0,  1445,  1446,     0,     0,     0,
       0,     0,  1865,  2041,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,  1875,     0,     0,
       0,  1790,     0,     0,     0,     0,     0,     0,     0,     0,
    2063,  2065,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2073,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,   377,   415,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,  1833,     0,     0,     0,     0,
     261,     0,  1839,  1950,     0,     0,     0,     0,   402,     0,
     415,   415,   412,     0,     0,     0,   417,     0,     0,  1606,
       0,     0,     0,  1625,     0,     0,     0,   415,     0,     0,
       0,     0,     0,   427,   429,   432,   433,  1871,   435,   429,
     437,   438,     0,   440,   429,   442,   443,   444,   445,   446,
     447,  1612,   449,   450,   451,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1967,  1968,  1969,  1970,  1972,     0,  1625,  2009,
       0,     0,     0,     0,  1712,     0,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,  1916,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   515,   517,   519,   520,   429,     0,     0,     0,     0,
       0,     0,     0,  1140,     0,     0,     0,     0,   547,   429,
    1146,  2022,     0,     0,  1157,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   578,     0,     0,     0,     0,   578,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   599,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,   618,
     684,     0,   685,   621,   622,   623,     0,   625,  1592,     0,
       0,   628,   629,   630,     0,     0,   631,     0,     0,     0,
       0,     0,     0,     0,  1625,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,   660,     0,     0,     0,   666,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,   677,   678,     0,   540,     0,     0,  1285,     0,
       0,     0,     0,     0,     0,     0,   705,     0,     0,  1625,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,   517,     0,     0,     0,   540,     0,
     735,     0,     0,     0,     0,   740,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,   760,   761,   762,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   774,
     775,   776,   778,   779,   780,   781,   782,   783,   784,   784,
       0,   789,   790,     0,   792,     0,     0,     0,     0,     0,
     798,     0,     0,   800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   784,   784,     0,
       0,     0,   429,     0,     0,     0,     0,     0,     0,     0,
       0,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   830,   832,   834,   835,   836,     0,   838,   839,
       0,     0,     0,     0,     0,   846,   847,   848,     0,     0,
       0,     0,   854,   857,   860,   863,   865,     0,   867,     0,
     869,     0,   429,   429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   341,     0,  1781,
     515,   660,   887,     0,     0,     0,   892,   893,   894,   895,
     896,   897,   898,   899,   900,     0,     0,     0,     0,   906,
       0,   908,   909,     0,  1807,     0,   429,   429,   429,     0,
       0,   916,   917,   918,     0,     0,     0,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,   352,   353,   354,     0,     0,   940,     0,   355,
     356,   357,     0,     0,   358,     0,     0,     0,     0,     0,
     429,     0,     0,     0,     0,   956,   359,   957,   360,   838,
     839,     0,     0,     0,     0,     0,   966,     0,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,  1821,     0,
       0,     0,   429,     0,     0,     0,     0,     0,   987,   988,
       0,     0,     0,     0,     0,   388,     0,  1935,     0,     0,
       0,     0,     0,     0,   429,     0,  1006,  1007,     0,     0,
     429,  1012,     0,     0,     0,     0,     0,     0,     0,  1019,
       0,     0,     0,  1022,     0,     0,   832,     0,  1026,     0,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,  1047,
     919,     0,     0,     0,  1564,     0,     0,     0,   880,     0,
       0,     0,   361,   362,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,     0,   365,   107,
       0,     0,     0,     0,   429,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
     394,   395,     0,   540,     0,     0,     0,  -512,     0,  1455,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,  1991,     0,   429,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     0,  1117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1647,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,     0,     0,  1141,  1142,     0,     0,
       0,     0,  1145,     0,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,  1170,     0,
       0,  1172,   540,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     7,     8,
    1186,   540,  1188,  1189,     0,   430,     0,     0,     0,     0,
     430,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,  1207,     0,  1702,  1703,  1704,  1705,  1706,  1708,   430,
       0,     0,     0,     0,     0,     0,     0,  1220,     0,     0,
       0,     0,     0,     0,  1226,  1227,  1228,  1229,     0,     0,
       0,     0,  1238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1262,   429,   429,   429,
     429,  1267,     0,     0,   697,    25,    26,   698,    28,    29,
     699,    31,   700,    33,    34,    35,    36,  1907,   525,     0,
      38,    39,    40,   518,     0,    42,   430,  1282,     0,     0,
       0,   701,    48,     0,     0,    50,   702,     0,    53,   703,
     430,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,   429,     0,    70,     0,   540,
       7,     8,     0,     0,     0,     0,     0,     0,  1311,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1312,  1313,
    1314,    84,    85,    86,     0,  1316,  1317,     0,  1318,     0,
       0,     0,     0,     0,     0,  1323,     0,  1324,  1325,  1326,
    1327,  1328,     0,     0,     0,     0,     0,     0,     0,     0,
    1330,  1331,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1347,
       0,  1349,     0,  1351,     0,  1353,   697,    25,    26,   698,
      28,    29,   699,    31,   700,    33,    34,    35,    36,     0,
       0,   888,    38,    39,    40,  1370,     0,    42,     0,     0,
       0,     0,     0,   701,    48,     0,     0,    50,   702,     0,
      53,   703,     0,     0,     0,     0,     0,     0,     0,     0,
    1876,  1877,  1878,  1879,  1880,     0,     0,  1401,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,     0,   518,     0,  1414,     0,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,     0,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   730,   538,   539,     0,     0,  1430,     0,
     540,  1435,     0,  1915,     0,     0,     0,  1919,     0,     0,
       0,     0,   777,     7,     8,     0,     0,     0,     0,   785,
     786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1463,  1464,  1465,  1466,     0,     0,
       0,     0,     0,   910,     0,  1473,  1475,     0,   810,   811,
       0,     0,     0,   430,     0,     0,     0,     0,  1957,     0,
       0,     0,  1959,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   833,     0,     0,     0,  1971,     0,
     687,     0,     0,     0,     0,     0,     0,     0,     0,   697,
      25,    26,   698,    28,    29,   699,    31,   700,    33,    34,
      35,    36,     0,   430,   430,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   701,    48,     0,     0,
      50,   702,     0,    53,   703,     0,     0,     0,  1550,  1551,
    1552,     0,     0,  2015,  2016,     0,     0,  1558,     0,  1560,
       0,     0,    70,     0,     0,     0,  1563,   430,   430,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,  1579,     0,    84,    85,    86,     0,
       0,     0,  1584,  1585,  1586,     0,     0,     0,     0,     0,
       0,     0,  1595,     0,     0,     0,     0,     0,     0,     0,
       0,   430,     0,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,   525,     0,  1616,
       0,   540,     0,     0,     0,  1622,  1623,  1688,     0,     0,
       0,  1689,     0,   430,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   954,     0,     0,     0,
       0,     0,     0,     0,     0,   430,     0,     0,  1645,  1646,
       0,   430,     0,     0,     0,  1651,  1652,     0,     0,     0,
       0,     0,  1656,     0,     0,     0,     0,   833,     0,  1027,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1659,
    1660,  1661,     0,     0,     0,     0,     0,     0,  1663,  1664,
    1665,  1666,     0,     0,   525,     0,     0,     0,     0,     0,
       0,     0,  1672,     0,     0,     0,     0,     0,     0,     0,
       0,   429,   429,  1683,     0,  1684,     0,     0,     0,     0,
       0,  1692,  1693,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,     0,   927,  1711,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1721,     0,     0,  1724,     0,
       0,     0,     0,     0,     0,     0,  1104,     0,   430,     0,
       0,     0,     0,     0,  1733,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,  1745,     0,     0,
       0,     0,  1751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1753,     0,     0,     0,
     430,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,     0,     0,     0,     0,   540,
       0,  1105,     0,     0,  1775,     0,     0,     0,     0,  1051,
    1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
       0,  1063,  1064,  1065,  1066,  1784,  1068,  1069,  1070,  1071,
       0,     0,     0,     0,  1793,     0,     0,     0,     0,     0,
    1081,     0,  1083,   517,     0,     0,     0,     0,     0,     0,
       0,     0,  1804,  1805,     0,     0,   429,     0,  1096,  1097,
    1098,     0,  1813,     0,     0,     0,     0,  1103,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   730,
     538,   539,  1830,  1831,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1844,   430,   430,
     430,   430,     0,  1848,  1850,     0,     0,  1852,  1853,  1854,
    1855,     0,     0,     0,     0,     0,   429,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,   429,  1407,     0,     0,   540,     0,     0,     0,  1881,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,   430,     0,   540,     0,
       0,     0,     0,     0,     0,  1892,     0,     0,     0,     0,
       0,  1897,  1898,     0,     0,     0,     0,     0,     0,     0,
    1192,  1194,  1195,     0,     0,     0,  1199,  1200,     0,     0,
    1203,  1204,  1205,  1206,     0,  1208,     0,     0,     0,     0,
    1214,     0,     0,     0,  1923,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
     430,     0,     0,   540,     0,     0,     0,     0,     0,  1942,
    1943,     0,     0,     0,     0,     0,     0,     0,     0,  1947,
    1948,     0,  1949,     0,     0,  1952,  1953,  1954,  1955,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1963,     0,     0,     0,     0,   429,   429,   429,   429,
     429,  1283,  1284,     0,     0,     0,     0,  1751,     0,     0,
       0,  1979,     0,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
     430,   540,     0,     0,     0,     0,     0,  1715,     0,     0,
       0,  1716,  2004,     0,     0,     0,     0,  2007,  2008,     0,
       0,  2011,  2012,  2013,  2014,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   429,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2045,  2046,
    2047,  2048,  2049,  2050,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1867,     0,
       0,     0,  1868,     0,     0,   187,     6,   341,     0,     0,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   220,   221,   222,
     223,   351,   352,   353,   354,   224,     0,     0,     0,   355,
     356,   357,     0,     0,   358,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   359,     0,   360,     0,
       0,   229,     0,  1444,   230,     0,     0,   231,     0,   232,
     430,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
      49,     0,     0,   234,     0,   235,     0,     0,     0,     0,
    1477,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1508,  1509,  1510,  1511,  1512,     0,     0,     0,     0,  1517,
    1518,  1520,     0,     0,     0,     0,     0,  1527,     0,     0,
       0,     0,     0,     0,     0,     0,  1530,     0,     0,     0,
       0,   236,   361,   362,   363,   237,   238,   239,     0,     0,
       0,   240,   241,   242,   243,   244,   364,     0,   365,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,   246,     0,     0,     0,   247,     0,
       0,     0,     0,   323,     0,     0,     0,   249,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,   430,   341,     0,     0,     0,     0,     0,
       0,  1590,     0,  1593,     0,     0,  1597,     0,  1600,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1618,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,   352,
     353,   354,     0,     0,     0,     0,   355,   356,   357,     0,
       0,   358,     0,     0,     0,     0,     0,     0,     0,   187,
       6,   341,     0,   359,     0,   360,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   220,   221,   222,   223,   351,   352,   353,   354,   224,
       0,     0,     0,   355,   356,   357,     0,     0,   358,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     359,     0,   360,     0,   518,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,   430,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,   361,
     362,   363,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,   364,     0,   365,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,  1742,  1743,
       0,    73,     0,     0,    76,  1851,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   430,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,   430,     0,     0,     0,   540,     0,  1765,  1766,
       0,     0,  1000,     0,     0,   236,   361,   362,   363,   237,
     238,   239,     0,     0,     0,   240,   241,   242,   243,   244,
     364,     0,   365,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,   247,     0,     0,     0,     0,   323,     0,     0,
       0,  1768,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,  1810,  1811,     0,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,   187,
     150,   341,     0,   387,   715,     0,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   375,   209,
     210,   211,   212,   213,   214,     0,     0,   430,   430,   430,
     430,   430,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   220,   221,   222,   223,   351,   352,   353,   354,   224,
       0,     0,     0,   355,   356,   357,     0,     0,   358,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     359,     0,   360,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,   150,   341,     0,     0,   430,     0,     0,     0,
       0,   880,     0,     0,     0,     0,     0,     0,     0,   388,
       0,     0,     0,     0,     0,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   881,     0,     0,     0,   351,   352,   353,
     354,     0,     0,     0,     0,   355,   356,   357,     0,     0,
     358,     0,     0,     0,     0,     0,     0,     0,   389,     0,
       0,     0,   359,     0,   360,   236,   361,   362,   363,   237,
       0,     0,     0,     0,     0,   240,   241,   242,   243,   244,
     364,     0,   365,   107,   390,   391,   392,   393,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   376,     0,
       0,   388,   247,     0,   394,   395,     0,   396,     0,   397,
       0,     0,     0,   398,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     6,   322,     0,
       0,     0,     0,   188,   189,   190,     0,  2031,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,   364,     0,   365,   107,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   369,   341,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,   352,   353,   354,
       0,     0,     0,     0,   355,   356,   357,     0,     0,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   236,   360,     0,     0,   237,   238,   239,     0,
       0,     0,   240,   241,   242,   243,   244,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,     0,     0,     0,   247,
       0,     0,     0,     0,   323,   187,     6,  1566,   249,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,   361,   362,   363,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,   364,     0,   365,   228,    21,     0,     0,     0,     0,
       0,   229,     0,     0,   230,     0,     0,   231,     0,   232,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
      49,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   924,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,   239,     0,     0,
       0,   240,   241,   242,   243,   244,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,   246,     0,     0,     0,   247,     0,
       0,     0,     0,   323,   187,     6,     0,   249,     0,     0,
     250,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,     0,     0,     0,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,    49,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1062,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,   239,     0,     0,     0,
     240,   241,   242,   243,   244,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   584,  1707,     0,     0,     0,   247,     0,     0,
       0,     0,   586,   187,     6,     0,   288,   521,     0,   250,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,     0,     0,     0,     0,     0,   229,
       0,     0,   230,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,    49,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,   238,   239,     0,     0,     0,   240,
     241,   242,   243,   244,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,     0,     0,     0,   247,     0,     0,     0,
       0,   248,   187,     6,     0,   249,     0,     0,   250,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,     0,     0,     0,     0,     0,   229,     0,
       0,   230,     0,     0,   231,     0,   232,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,    49,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1073,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,   239,     0,     0,     0,   240,   241,
     242,   243,   244,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,     0,     0,     0,   247,     0,     0,     0,     0,
     323,   187,     6,     0,   249,     0,     0,   250,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1074,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,   239,     0,     0,     0,   240,   241,   242,
     243,   244,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     428,     0,     0,     0,   247,     0,     0,     0,     0,   323,
     187,     6,     0,   516,     0,     0,   250,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,     0,     0,     0,     0,     0,   229,     0,     0,   230,
       0,     0,   231,     0,   232,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,    49,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1079,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,   239,     0,     0,     0,   240,   241,   242,   243,
     244,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   428,
       0,     0,     0,   247,     0,     0,     0,     0,   323,   187,
       6,     0,     0,   521,     0,   250,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
       0,     0,     0,     0,     0,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1080,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,   237,
     238,   239,     0,     0,     0,   240,   241,   242,   243,   244,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,   247,     0,     0,     0,     0,   551,   187,     6,
       0,   249,     0,     0,   250,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,     0,
       0,     0,     0,     0,   229,     0,     0,   230,     0,     0,
     231,     0,   232,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,    49,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1082,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
     239,     0,     0,     0,   240,   241,   242,   243,   244,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   246,     0,     0,
       0,   247,     0,     0,     0,     0,   560,   187,     6,     0,
     249,     0,     0,   250,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,     0,     0,
       0,     0,     0,   229,     0,     0,   230,     0,     0,   231,
       0,   232,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,    49,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,   239,
       0,     0,     0,   240,   241,   242,   243,   244,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,     0,     0,     0,
     247,     0,     0,     0,     0,   562,   187,     6,     0,   249,
       0,     0,   250,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,   239,     0,
       0,     0,   240,   241,   242,   243,   244,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,     0,     0,     0,   247,
       0,     0,     0,     0,   564,   187,     6,     0,   249,     0,
       0,   250,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,     0,     0,     0,     0,
       0,   229,     0,     0,   230,     0,     0,   231,     0,   232,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
      49,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,   239,     0,     0,
       0,   240,   241,   242,   243,   244,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,   428,     0,     0,     0,   247,     0,
       0,     0,     0,   323,   187,     6,     0,   831,     0,     0,
     250,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,     0,     0,     0,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,    49,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,   239,     0,     0,     0,
     240,   241,   242,   243,   244,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,   247,     0,     0,
       0,     0,   323,   187,     6,     0,  1574,     0,     0,   250,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,     0,     0,     0,     0,     0,   229,
       0,     0,   230,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,    49,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,   238,   239,     0,     0,     0,   240,
     241,   242,   243,   244,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   584,  1707,     0,     0,     0,   247,     0,     0,     0,
       0,   586,   187,     6,     0,   288,     0,     0,   250,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,     0,     0,     0,     0,     0,   229,     0,
       0,   230,     0,     0,   231,     0,   232,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,    49,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,   239,     0,     0,     0,   240,   241,
     242,   243,   244,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   428,     0,     0,     0,   247,   187,   150,   341,     0,
     323,     0,     0,   188,   189,   190,     0,   250,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   375,   209,   210,   211,   212,
     213,   214,     0,     0,     0,     0,     0,     0,     0,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   220,   221,
     222,   223,   351,   352,   353,   354,   224,     0,     0,     0,
     355,   356,   357,     0,     0,   358,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   359,     0,   360,
     187,   150,   341,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   375,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   220,   221,   222,   223,   351,   352,   353,   354,
     224,     0,     0,     0,   355,   356,   357,     0,     0,   358,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   359,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   361,   362,   363,   237,     0,     0,     0,
       0,     0,   240,   241,   242,   243,   244,   364,     0,   365,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   376,     0,     0,     0,   247,
       0,     0,     0,     0,   323,     0,     0,     0,  1474,     0,
       0,   250,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1513,     0,     0,     0,     0,     0,   236,   361,   362,   363,
     237,     0,     0,     0,     0,     0,   240,   241,   242,   243,
     244,   364,     0,   365,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   376,
       0,     0,     0,   247,     0,     0,     0,     0,   323,   187,
     150,   341,  1720,     0,     0,   250,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   375,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   220,   221,   222,   223,   351,   352,   353,   354,   224,
       0,     0,     0,   355,   356,   357,     0,     0,   358,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     359,     0,   360,   187,   150,   341,     0,     0,     0,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   375,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   220,   221,   222,   223,   351,
     352,   353,   354,   224,     0,     0,     0,   355,   356,   357,
       0,     0,   358,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   359,     0,   360,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   361,   362,   363,   237,
       0,     0,     0,     0,     0,   240,   241,   242,   243,   244,
     364,     0,   365,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   376,     0,
       0,     0,   247,     0,     0,     0,     0,   323,     0,     0,
       0,  1812,     0,     0,   250,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1514,     0,     0,     0,     0,     0,   236,
     361,   362,   363,   237,     0,     0,     0,     0,     0,   240,
     241,   242,   243,   244,   364,     0,   365,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   376,     0,     0,     0,   247,   187,   150,     0,
       0,   323,     0,     0,   188,   189,   190,     0,   250,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   375,   209,   210,   211,
     212,   213,   214,     0,     0,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,   220,
     221,   222,   223,   540,     0,     0,     0,   224,     0,     0,
       0,     0,     0,  1515,     0,     0,   187,   150,   225,   226,
     227,     0,     0,   188,   189,   190,   228,    21,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   375,   209,   210,   211,   212,
     213,   214,     0,     0,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,   220,   221,
     222,   223,   540,     0,     0,     0,   224,     0,     0,     0,
       0,     0,  1522,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1523,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,     0,     0,
       0,     0,     0,   240,   241,   242,   243,   244,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   376,     0,     0,     0,
     247,     0,     0,     0,     0,   323,     0,     0,     0,   567,
       0,     0,   250,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,   236,     0,     0,     0,   237,     0,     0,     0,
       0,  1524,   240,   241,   242,   243,   244,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   584,   585,     0,     0,     0,   247,
       0,     0,     0,     0,   586,     0,   187,   150,   288,  1219,
       0,   250,     0,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   375,   209,   210,   211,   212,
     213,   214,     0,     0,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,   220,   221,
     222,   223,   540,     0,     0,     0,   224,     0,     0,     0,
       0,     0,  1525,     0,     0,     0,     0,   225,   226,   227,
     187,   150,     0,  1369,     0,   228,    21,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   375,
     209,   210,   211,   212,   213,   214,     0,     0,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,   220,   221,   222,   223,   540,     0,     0,     0,
     224,     0,     0,     0,     0,     0,  1640,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1746,
       0,     0,   236,     0,     0,     0,   237,     0,     0,     0,
       0,     0,   240,   241,   242,   243,   244,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   376,     0,     0,     0,   247,
       0,     0,     0,     0,   323,     0,     0,     0,     0,     0,
       0,   250,     0,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,   236,     0,     0,     0,
     237,  1747,     0,     0,     0,     0,   240,   241,   242,   243,
     244,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   376,
       0,     0,     0,   247,   187,   150,     0,     0,   323,     0,
       0,   188,   189,   190,     0,   250,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   375,   209,   210,   211,   212,   213,   214,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     7,     8,   228,    21,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1767,     0,     0,     0,     0,   697,    25,
      26,   698,    28,    29,   699,    31,   700,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   701,    48,     0,     0,    50,
     702,     0,    53,   703,     0,     0,     0,   697,    25,    26,
     698,    28,    29,   699,    31,   700,    33,    34,    35,    36,
       0,    70,     0,    38,    39,    40,     7,     8,    42,     0,
       0,     0,     0,     0,   701,    48,     0,     0,    50,   702,
     236,    53,   703,     0,   237,    84,    85,    86,     0,     0,
     240,   241,   242,   243,   244,     0,     0,     0,   107,     0,
      70,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,   245,   376,     0,     0,     0,   247,     0,     0,
       0,     0,   323,     0,    84,    85,    86,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   697,    25,    26,   698,    28,    29,   699,    31,
     700,    33,    34,    35,    36,   955,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   701,
      48,     0,     0,    50,   702,     0,    53,   703,     0,     0,
     697,    25,    26,   698,    28,    29,   699,    31,   700,    33,
      34,    35,    36,     0,  1138,    70,    38,    39,    40,     7,
       8,    42,     0,     0,     0,     0,     0,   701,    48,     0,
       0,    50,   702,     0,    53,   703,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     7,     8,     0,
       0,     0,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,    84,    85,    86,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1771,     0,     0,     0,     0,   697,    25,    26,   698,    28,
      29,   699,    31,   700,    33,    34,    35,    36,     0,  1139,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   701,    48,     0,     0,    50,   702,     0,    53,
     703,     0,     0,   697,    25,    26,   698,    28,    29,   699,
      31,   700,    33,    34,    35,    36,     0,  1158,    70,    38,
      39,    40,     7,     8,    42,     0,     0,     0,     0,     0,
     701,    48,     0,     0,    50,   702,     0,    53,   703,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       7,     8,     0,     0,     0,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
      84,    85,    86,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1772,     0,     0,     0,     0,   697,    25,
      26,   698,    28,    29,   699,    31,   700,    33,    34,    35,
      36,     0,  1187,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   701,    48,     0,     0,    50,
     702,     0,    53,   703,     0,     0,   697,    25,    26,   698,
      28,    29,   699,    31,   700,    33,    34,    35,    36,     0,
    1217,    70,    38,    39,    40,     7,     8,    42,     0,     0,
       0,     0,     0,   701,    48,     0,     0,    50,   702,     0,
      53,   703,     0,     0,     0,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,    84,    85,    86,     0,     0,  1773,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   697,    25,    26,   698,    28,    29,   699,    31,   700,
      33,    34,    35,    36,     0,  1361,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   701,    48,
       0,     0,    50,   702,     0,    53,   703,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,  1926,    70,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,    84,    85,
      86,    -4,    -4,  1774,     0,     0,     0,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,    -4,    -4,    -4,     0,   540,     0,    -4,    -4,     0,
      -4,  1090,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
      -4,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,     0,    -4,  1993,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,
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
      73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
      80,    81,     0,     0,     0,    82,     0,     0,     0,     0,
      83,    84,    85,    86,   150,   341,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     7,     8,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
     106,     0,   107,     0,     0,     0,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
     352,   353,   354,     0,     0,     0,     0,   355,   356,   357,
       0,     0,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,     0,   360,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     697,    25,    26,   698,    28,    29,   699,    31,   700,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   701,    48,     0,
       0,    50,   702,     0,    53,   703,     7,     8,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,    70,     0,     0,   540,   961,     0,     0,
       0,     0,     0,     0,     0,     0,  1836,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   364,     0,   365,   107,     0,     0,
       0,     0,   697,    25,    26,   698,    28,    29,   699,    31,
     700,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   701,
      48,     0,     0,    50,   702,     0,    53,   703,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,    70,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1893,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1894,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1904,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1909,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1910,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1911,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1912,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1945,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1976,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1981,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1982,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1985,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1986,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1987,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1988,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2032,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2033,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2034,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2035,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1161,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1225,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1365,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1426,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1427,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1428,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1429,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1686,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1697,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1757,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1758,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1759,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1760,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1762,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1787,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1802,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1856,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1873,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1882,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1883,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  1902,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1962,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  2006,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  2030,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  2056,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  2057,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  2058,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  2059,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,  2060,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  2061,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,     0,   662,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
       0,   873,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,     0,  1780,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,   684,     0,   685,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,   930,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,   974,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,  1109,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,     0,     0,
    1174,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,     0,     0,  1175,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,     0,     0,  1179,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,     0,     0,  1180,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
       0,     0,  1261,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,     0,     0,  1277,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,     0,     0,  1457,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,     0,
       0,  1580,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,     0,     0,  1739,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,     0,     0,  1788,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,   729,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,   733,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
     734,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,   736,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,   738,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,   739,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,   741,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,   743,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,   744,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,   745,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,   746,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,   747,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
     748,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,   750,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,   751,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,   752,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,   815,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,   844,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,   901,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,   919,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,   920,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,   921,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
     922,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,   928,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,   929,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,   960,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,   973,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,  1030,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,  1035,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,  1048,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,  1108,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,  1114,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
    1115,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,  1116,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,  1130,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,  1131,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,  1132,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,  1160,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,  1162,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,  1163,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,  1164,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,  1165,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
    1166,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,  1167,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,  1168,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,  1173,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,  1260,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,  1276,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,  1462,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540,     0,  1526,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   661,
     538,   539,     0,     0,     0,     0,   540,     0,  1634,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     661,   538,   539,     0,     0,     0,     0,   540,     0,  1635,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   661,   538,   539,     0,     0,     0,     0,   540,     0,
    1636,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   661,   538,   539,     0,     0,     0,     0,   540,
       0,  1637,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   661,   538,   539,     0,     0,     0,     0,
     540,     0,  1687,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   661,   538,   539,     0,     0,     0,
       0,   540,     0,  1696,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   661,   538,   539,     0,     0,
       0,     0,   540,     0,  1719,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   661,   538,   539,     0,
       0,     0,     0,   540,     0,  1975,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   661,   538,   539,
       0,     0,     0,     0,   540,     0,  2027,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   661,   538,
     539,     0,     0,     0,     0,   540
};

static const yytype_int16 yycheck[] =
{
       3,  1155,   132,  1159,   493,  1282,   281,  1602,  1603,     4,
       3,   581,   582,   293,     4,     7,     7,   679,    21,   694,
    1568,     5,     4,     4,     4,   687,     5,     5,     4,    95,
     310,     4,     4,     9,     5,     4,     4,   712,     4,    95,
       5,     9,     6,     4,    47,     4,   234,     4,     4,     4,
     116,     5,   240,     0,     6,     6,   234,     6,     6,     4,
     116,     6,   240,   183,   184,   185,     9,     6,   232,   132,
     234,    74,   221,   222,   137,   138,   240,     6,   231,    82,
     221,   222,     4,     9,    87,   221,   222,   221,   222,   221,
     222,   240,   372,   235,   374,    98,     7,   239,     6,   240,
       9,   381,   221,   222,   240,   232,   240,   234,   240,   231,
    1658,   233,   175,   240,     6,     9,     6,   221,   222,   221,
     222,   240,   232,   186,   221,   222,     6,   221,   222,   132,
     240,   234,     9,   232,   137,   138,   240,   240,   240,   236,
     133,   240,   145,   632,    89,   634,   240,   267,   268,   269,
     221,   222,    14,   156,   232,   158,   221,   222,   228,   229,
     163,   171,   240,    95,     7,   168,     6,   237,     7,   240,
     221,   222,   175,   221,   222,   240,   179,   187,   188,   182,
     183,   184,   185,   186,   304,   305,   306,   235,   231,   240,
     174,     7,   161,   162,   163,   164,   174,   317,   318,     6,
      95,   182,    97,   174,   221,   222,   186,     6,   159,   174,
     221,   222,   171,   172,   171,   172,    89,   207,     6,    92,
     159,     6,    95,   240,   235,   232,   207,  1381,     6,  1777,
     233,   207,     7,   240,    98,   207,   100,     7,   233,   207,
     231,   207,   233,   246,   239,   237,   249,   250,   238,   231,
       6,   235,   228,   229,   235,   231,   235,   233,   231,   235,
     263,   237,   235,   266,   267,   268,   269,   236,   132,   235,
     231,   274,   275,   276,   235,   231,   231,   280,   281,   235,
     235,   235,   231,   235,  1832,   207,   235,   235,   231,   218,
     233,   155,   572,   573,   237,   233,   232,   208,   209,   210,
     211,   304,   305,   306,   240,   231,   231,   233,   233,   589,
     218,   973,   974,   235,   317,   318,   379,   228,   229,   228,
     229,   231,   231,   236,   233,   234,   237,   240,   237,   221,
     222,   221,   222,    47,   228,   229,   237,   231,   239,   233,
     158,   221,   222,   237,  1939,   163,   626,   221,   222,   231,
     168,   228,   229,   235,   231,   233,   233,   231,   221,   222,
     237,   235,   228,   229,   182,   208,   209,   210,   211,   208,
     209,   210,   211,   130,   131,    92,   379,   240,    95,   136,
     383,   384,   662,   221,   222,   505,   506,   507,   508,   228,
     229,   232,   208,   209,   210,   211,   399,   235,     4,   240,
     221,   222,   405,   231,     6,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   240,
     232,   424,   234,   230,   487,   428,   489,   231,   491,   492,
    1978,   235,  1107,   208,   209,   210,   211,   231,   208,   209,
     210,   211,   232,   109,   126,   263,   509,   510,   221,   222,
     240,   231,     4,   228,   229,   221,   222,   231,   228,   229,
    1122,   143,  1124,   231,  1126,   179,  1128,   240,   231,   151,
     152,   153,   475,   231,   240,   157,   158,  1754,   231,   482,
     483,   221,   222,   232,   487,   234,   489,   490,   491,   492,
     493,   240,   221,   222,   231,  2043,   221,   222,   221,   222,
     240,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   240,   232,   516,   234,   240,    95,   240,    97,   233,
     240,   221,   222,   387,   130,   131,   132,   133,    92,   231,
       8,    95,   231,    97,   537,   231,   235,    89,   541,   145,
     240,    93,   148,   221,   222,   221,   222,    99,   100,   679,
     102,   103,   266,   231,   236,    95,   231,   235,   228,   229,
     274,   275,   276,   566,   567,   235,   280,   236,   120,   231,
     633,   240,   635,   636,   637,   638,   639,   640,   231,   642,
     643,   644,   645,   235,  1259,   648,   649,   650,   581,   582,
     236,     8,   231,   231,   240,    89,   876,   232,    92,   234,
    1275,    95,   236,    97,     6,   240,   240,   610,   611,   612,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,  1901,    95,   235,    97,   230,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   231,   642,
     643,   644,   645,   646,     7,   648,   649,   650,   651,   126,
     514,   654,    89,    95,   717,    92,   228,   229,    95,   722,
      97,    92,    92,   235,    95,    89,   143,     8,    92,   383,
     384,    95,   235,    97,   151,   152,   153,     4,   235,     6,
     157,   158,   232,   686,   234,   399,     6,     7,   691,   232,
     240,   234,   556,   557,   558,   559,   231,   240,   516,   126,
     221,   222,   223,   224,   225,   708,   709,   130,   131,   230,
     840,   714,    95,   136,   717,    92,   143,   720,    95,   722,
      97,   223,   224,   225,   151,   152,   153,   730,   230,   732,
     157,   158,    22,    23,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   566,   567,
      92,    95,   230,    95,    92,    97,     6,     7,   236,   236,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    92,
    1432,  1927,     4,   230,   236,   236,   490,   236,   240,   240,
     231,   240,  1444,   647,   235,   788,   232,   231,   234,   235,
     504,   235,   610,   611,   612,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   236,
    1964,   236,     6,   230,   236,   240,   236,   236,   240,   236,
     240,   240,   236,   236,     4,   236,   240,   240,   831,   240,
     236,   236,     4,   236,   240,   240,   654,   240,  1994,   842,
       4,   236,   132,   973,   974,   240,   231,   850,     6,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,  2017,   728,   236,   231,   230,   686,   240,
     873,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   231,   231,     6,   236,   230,
     708,   232,   240,   234,   231,   231,   714,   236,   233,   233,
       6,   240,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   236,   222,   223,   235,   240,   239,   236,   228,   236,
    1003,   240,   126,   240,   239,   116,   235,   237,   238,   239,
     236,   236,   231,     9,   240,   240,  1445,  1446,   231,   143,
     236,   236,   965,   231,   240,   240,  1241,   151,   152,   153,
     788,   236,   231,   157,   158,   240,   979,   126,  1108,  1109,
     231,   984,   236,  1553,  1554,   231,   240,   235,   991,   992,
     993,   994,   236,   236,   143,   236,   240,   240,   231,   240,
    1003,   236,   151,   152,   153,   240,   236,   236,   157,   158,
     240,   240,   236,   831,   236,   236,   240,   236,   240,   240,
     231,   240,  1085,  1086,   842,  1028,  1029,   231,  1031,   126,
    1033,  1034,   231,  1036,   231,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,   236,   236,  1049,   236,   240,   240,
     231,   240,   342,   343,   344,   873,   231,   231,   348,   349,
     350,   351,   352,   353,   354,   231,   356,   236,   236,   359,
     360,   240,   240,   363,   236,   236,   236,     4,   240,   240,
     240,  1084,  1085,  1086,   235,   375,   231,   236,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,  1102,
     236,   236,   236,   230,   240,   240,   240,   231,   236,  1112,
    1113,   975,   240,   235,   231,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   233,
    1260,  1261,   231,   230,   236,  1198,   850,   231,   240,  1202,
     236,  1421,   231,  1423,   240,   231,   231,     6,  1211,     6,
    1213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   235,  1439,   235,  1169,   230,   232,   235,
     234,   235,   233,   991,   992,   993,   994,     6,   233,  1182,
    1183,  1184,   233,     6,   174,   235,   231,   231,   231,   231,
    1193,   231,   233,     6,     6,  1198,   235,     6,  1261,  1202,
       6,   235,     7,     6,   235,     6,   235,    85,  1211,   236,
    1213,   232,   240,  1783,   240,     6,     6,     4,     5,  1222,
     232,     7,     6,     6,   235,    64,    64,    64,    64,   230,
       4,  1049,     7,     6,   524,     7,     6,     6,  1241,   232,
       6,   235,     7,     6,   235,     7,     6,     6,     6,   171,
     234,   965,   232,     6,   235,   237,   235,   235,  1261,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     8,   235,
     984,     7,    59,    60,    61,    62,     6,   233,   231,     4,
      67,    68,    69,     6,     6,    72,     6,  1290,     6,   232,
       7,   233,   174,  1296,     7,  1113,     7,    84,     7,    86,
     174,   174,  1432,     7,     7,     7,     7,     7,     6,   235,
       7,     7,     7,     7,  1028,  1029,     7,  1031,     7,  1033,
    1034,     7,  1036,  1812,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,     6,   232,   234,   123,  1340,  1341,  1342,
    1615,   232,   235,  1346,   240,  1348,   240,  1350,   240,  1352,
     235,  1354,  1355,  1356,    60,    61,   235,    63,   235,   240,
     232,     7,   237,     7,   235,     4,     6,   232,  1371,   232,
    1084,   240,   240,   240,   232,  1193,   232,   237,   240,  1382,
     126,   236,   236,     7,     6,   237,     7,  1390,  1102,     7,
    1393,     7,   232,   240,   240,     9,   240,   232,  1112,  1529,
     232,   234,     7,   190,   191,   192,  1469,     6,   236,   235,
       6,     4,    46,    46,   235,   237,  1280,   204,   218,   206,
     207,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   231,  1439,   231,   231,   230,
     237,     7,  1445,  1446,     7,   232,   231,   234,  1451,    97,
       7,     7,     7,     7,     6,  1169,     7,     7,     7,     7,
       7,     4,   107,     4,   235,     7,  1469,     6,  1182,  1183,
    1184,  1474,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   231,     6,   235,     7,
     230,     7,   232,     7,     7,     7,     7,  1627,     7,     6,
       6,     6,     6,    95,     7,     6,     4,     4,  1222,     4,
     238,   240,  1792,     6,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,  1591,   236,
     235,  1594,   230,     6,     6,     6,   235,     7,     6,   231,
     233,   231,  1545,  1546,     6,     6,     6,  1822,   235,   237,
       6,     6,   235,   235,     6,   120,  1420,   235,   235,     6,
    1553,  1554,     6,   174,   235,  1568,     6,     6,     6,     6,
       6,  1574,     6,     6,     6,  1393,  1290,     6,   284,   285,
    1583,     5,  1296,   232,     6,     4,   292,   293,  1591,     6,
       4,  1594,   235,     6,   235,     7,     6,   235,   235,   235,
       6,  1604,   233,   235,     6,   235,   235,  1887,  1611,   235,
    1474,     6,  1615,     6,  1617,   235,   235,   170,   235,     6,
     232,     6,   235,     7,     6,   240,  1340,  1341,  1342,   237,
     240,   240,  1346,   231,  1348,   235,  1350,     4,  1352,     4,
    1354,  1355,  1356,     6,     6,     6,     6,     6,  1928,     6,
      93,     7,     6,     6,     6,  1658,     6,  1371,     6,  1662,
       5,   235,     4,   235,   240,     6,     6,     6,  1382,     6,
       6,     6,     6,     6,     6,     6,  1390,     6,     6,   240,
       6,     4,     6,   169,     6,  1549,     6,     5,     7,   235,
     235,     6,  1695,     6,     6,   235,     6,   235,     6,   236,
       6,   236,   235,   232,  1707,   236,   236,     6,   236,     7,
       6,   237,     6,     6,     6,   235,     6,  1720,     6,     6,
       6,     6,     6,     6,     6,  1589,  1016,  1545,  1546,     6,
     172,     6,   232,     7,   236,     6,   235,  1451,     6,   235,
       6,   235,     6,  1607,   235,   126,  1749,   236,   235,     6,
       6,   235,     6,  1756,     6,     6,   231,   236,   232,     6,
    1474,     6,     6,     6,     6,  1768,     6,     6,   235,     6,
     235,     6,     6,     6,  1777,     6,   235,  1780,     6,     6,
       6,  1274,  1941,  1534,  1289,  1755,   421,     3,  1791,     3,
    1783,     3,  1795,     3,   555,     3,  1779,    21,  1662,    -1,
    1611,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1812,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1822,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1832,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,  1568,    -1,    -1,  1860,    -1,    -1,
      -1,    -1,  1726,  1727,  1728,    -1,    -1,    -1,    -1,  1583,
      -1,    -1,    -1,   579,   580,    -1,    -1,    -1,   584,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1720,  1617,    -1,  1908,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
       6,    -1,    -1,    -1,   230,    -1,    -1,  1930,  1931,  1932,
    1933,  1934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1658,    -1,    -1,    -1,  1662,    -1,
      -1,    -1,    -1,    -1,    -1,  1245,  1246,    -1,    -1,    -1,
      -1,    -1,  1780,  2026,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1978,    -1,  1795,    -1,    -1,
      -1,  1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2053,  2054,    -1,    -1,    -1,    -1,  1999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2070,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   106,  2026,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1749,    -1,    -1,    -1,    -1,
    2043,    -1,  1756,  1907,    -1,    -1,    -1,    -1,   132,    -1,
    2053,  2054,   136,    -1,    -1,    -1,   140,    -1,    -1,     6,
      -1,    -1,    -1,  1777,    -1,    -1,    -1,  2070,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,  1791,   162,   163,
     164,   165,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,     6,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1930,  1931,  1932,  1933,  1934,    -1,  1832,  1983,
      -1,    -1,    -1,    -1,     6,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,  1860,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   879,    -1,    -1,    -1,    -1,   262,   263,
     886,  1999,    -1,    -1,   890,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,    -1,    -1,    -1,    -1,   293,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,   323,
     232,    -1,   234,   327,   328,   329,    -1,   331,   240,    -1,
      -1,   335,   336,   337,    -1,    -1,   340,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1978,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,    -1,    -1,    -1,   380,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,   396,   397,    -1,   230,    -1,    -1,  1024,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,  2043,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   428,    -1,    -1,    -1,   230,    -1,
     434,    -1,    -1,    -1,    -1,   439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,
      -1,    -1,    -1,    -1,    -1,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
      -1,   485,   486,    -1,   488,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,   512,    -1,
      -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,    -1,   542,   543,
      -1,    -1,    -1,    -1,    -1,   549,   550,   551,    -1,    -1,
      -1,    -1,   556,   557,   558,   559,   560,    -1,   562,    -1,
     564,    -1,   566,   567,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,     6,
     584,   585,   586,    -1,    -1,    -1,   590,   591,   592,   593,
     594,   595,   596,   597,   598,    -1,    -1,    -1,    -1,   603,
      -1,   605,   606,    -1,     6,    -1,   610,   611,   612,    -1,
      -1,   615,   616,   617,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,   641,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
     654,    -1,    -1,    -1,    -1,   659,    84,   661,    86,   663,
     664,    -1,    -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,
      -1,    -1,   676,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,   686,    -1,    -1,    -1,    -1,    -1,   692,   693,
      -1,    -1,    -1,    -1,    -1,   123,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,   708,    -1,   710,   711,    -1,    -1,
     714,   715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,
      -1,    -1,    -1,   727,    -1,    -1,   730,    -1,   732,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,   753,
     232,    -1,    -1,    -1,  1380,    -1,    -1,    -1,   240,    -1,
      -1,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,   206,   207,
      -1,    -1,    -1,    -1,   788,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     228,   229,    -1,   230,    -1,    -1,    -1,   235,    -1,   237,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,     6,    -1,   831,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   842,    -1,
      -1,    -1,    -1,    -1,    -1,   849,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   873,
      -1,    -1,    -1,    -1,    -1,    -1,   880,   881,    -1,    -1,
      -1,    -1,   886,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   902,    -1,
      -1,   905,   230,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    13,    14,
     924,   230,   926,   927,    -1,   158,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,   945,    -1,  1569,  1570,  1571,  1572,  1573,  1574,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   961,    -1,    -1,
      -1,    -1,    -1,    -1,   968,   969,   970,   971,    -1,    -1,
      -1,    -1,   976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   990,   991,   992,   993,
     994,   995,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     7,     8,    -1,
     105,   106,   107,   246,    -1,   110,   249,  1021,    -1,    -1,
      -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,   124,
     263,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,  1049,    -1,   142,    -1,   230,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,  1062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1072,  1073,
    1074,   166,   167,   168,    -1,  1079,  1080,    -1,  1082,    -1,
      -1,    -1,    -1,    -1,    -1,  1089,    -1,  1091,  1092,  1093,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1104,  1105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1123,
      -1,  1125,    -1,  1127,    -1,  1129,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   236,   105,   106,   107,  1149,    -1,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1796,  1797,  1798,  1799,  1800,    -1,    -1,  1181,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1193,
      -1,    -1,    -1,    -1,    -1,   428,    -1,  1201,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,  1232,    -1,
     230,  1235,    -1,  1859,    -1,    -1,    -1,  1863,    -1,    -1,
      -1,    -1,   475,    13,    14,    -1,    -1,    -1,    -1,   482,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1268,  1269,  1270,  1271,    -1,    -1,
      -1,    -1,    -1,   236,    -1,  1279,  1280,    -1,   511,   512,
      -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,  1914,    -1,
      -1,    -1,  1918,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,  1934,    -1,
     401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   566,   567,   105,   106,   107,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,  1362,  1363,
    1364,    -1,    -1,  1989,  1990,    -1,    -1,  1371,    -1,  1373,
      -1,    -1,   142,    -1,    -1,    -1,  1380,   610,   611,   612,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1393,
      -1,    -1,    -1,    -1,  1398,    -1,   166,   167,   168,    -1,
      -1,    -1,  1406,  1407,  1408,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,     8,    -1,  1443,
      -1,   230,    -1,    -1,    -1,  1449,  1450,   236,    -1,    -1,
      -1,   240,    -1,   686,    -1,   546,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   708,    -1,    -1,  1482,  1483,
      -1,   714,    -1,    -1,    -1,  1489,  1490,    -1,    -1,    -1,
      -1,    -1,  1496,    -1,    -1,    -1,    -1,   730,    -1,   732,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,
    1514,  1515,    -1,    -1,    -1,    -1,    -1,    -1,  1522,  1523,
    1524,  1525,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1545,  1546,  1547,    -1,  1549,    -1,    -1,    -1,    -1,
      -1,  1555,  1556,    -1,    -1,   788,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1574,    -1,    -1,     8,  1578,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1589,    -1,    -1,  1592,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,   831,    -1,
      -1,    -1,    -1,    -1,  1608,    -1,    -1,    -1,    -1,   842,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,    -1,    -1,
      -1,    -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1640,    -1,    -1,    -1,
     873,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,     8,    -1,    -1,  1668,    -1,    -1,    -1,    -1,   760,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
      -1,   772,   773,   774,   775,  1689,   777,   778,   779,   780,
      -1,    -1,    -1,    -1,  1698,    -1,    -1,    -1,    -1,    -1,
     791,    -1,   793,  1707,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1716,  1717,    -1,    -1,  1720,    -1,   809,   810,
     811,    -1,  1726,    -1,    -1,    -1,    -1,   818,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,  1746,  1747,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1761,   991,   992,
     993,   994,    -1,  1767,  1768,    -1,    -1,  1771,  1772,  1773,
    1774,    -1,    -1,    -1,    -1,    -1,  1780,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,  1795,     8,    -1,    -1,   230,    -1,    -1,    -1,  1803,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,  1049,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,  1829,    -1,    -1,    -1,    -1,
      -1,  1835,  1836,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     931,   932,   933,    -1,    -1,    -1,   937,   938,    -1,    -1,
     941,   942,   943,   944,    -1,   946,    -1,    -1,    -1,    -1,
     951,    -1,    -1,    -1,  1868,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
    1113,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,  1893,
    1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1903,
    1904,    -1,  1906,    -1,    -1,  1909,  1910,  1911,  1912,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1925,    -1,    -1,    -1,    -1,  1930,  1931,  1932,  1933,
    1934,  1022,  1023,    -1,    -1,    -1,    -1,  1941,    -1,    -1,
      -1,  1945,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
    1193,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,   240,  1976,    -1,    -1,    -1,    -1,  1981,  1982,    -1,
      -1,  1985,  1986,  1987,  1988,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1999,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2032,  2033,
    2034,  2035,  2036,  2037,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,   240,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,    -1,
      -1,    89,    -1,  1244,    92,    -1,    -1,    95,    -1,    97,
    1393,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
    1281,    -1,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1311,  1312,  1313,  1314,  1315,    -1,    -1,    -1,    -1,  1320,
    1321,  1322,    -1,    -1,    -1,    -1,    -1,  1328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1337,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,   193,   194,   195,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,    -1,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,   235,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1545,  1546,     5,    -1,    -1,    -1,    -1,    -1,
      -1,  1412,    -1,  1414,    -1,    -1,  1417,    -1,  1419,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1445,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    84,    -1,    86,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    86,    -1,  1707,    89,    -1,    -1,    92,    -1,
      -1,    95,    -1,    97,    -1,    -1,    -1,  1720,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,   116,    -1,   118,    -1,    -1,   121,    -1,   123,
      -1,    -1,    -1,   204,    -1,   206,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,   139,   140,   141,  1619,  1620,
      -1,   145,    -1,    -1,   148,  1768,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1780,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,  1795,    -1,    -1,    -1,   230,    -1,  1659,  1660,
      -1,    -1,   236,    -1,    -1,   189,   190,   191,   192,   193,
     194,   195,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,   235,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1724,  1725,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,   240,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,  1930,  1931,  1932,
    1933,  1934,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    86,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,     4,     5,    -1,    -1,  1999,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   240,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    84,    -1,    86,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,   123,   226,    -1,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,  2008,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,   204,    -1,   206,   207,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,   148,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,   189,    86,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,     3,     4,     5,   235,    -1,
      -1,   238,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,
      -1,   204,    -1,   206,    82,    83,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
     148,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
      -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,
     199,   200,   201,   202,   203,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,   231,     3,     4,    -1,   235,   236,    -1,   238,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,   199,
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
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,   148,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,   195,    -1,    -1,    -1,   199,   200,
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
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,   148,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,   195,    -1,    -1,    -1,   199,   200,   201,
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
      -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,   118,    -1,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,   145,    -1,    -1,   148,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,   199,   200,   201,   202,
     203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,
       4,    -1,    -1,   236,    -1,   238,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,
      -1,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   118,    -1,    -1,   121,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,   148,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,   118,    -1,    -1,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
     145,    -1,    -1,   148,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,   118,    -1,    -1,   121,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,   148,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,   195,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,   148,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,    -1,   193,   194,   195,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
     148,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
      -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,   199,
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
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,   148,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,   195,    -1,    -1,    -1,   199,   200,
     201,   202,   203,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   226,     3,     4,     5,    -1,
     231,    -1,    -1,    10,    11,    12,    -1,   238,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,    -1,   199,   200,   201,   202,   203,   204,    -1,   206,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,   235,    -1,
      -1,   238,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,   199,   200,   201,   202,
     203,   204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,     3,
       4,     5,   235,    -1,    -1,   238,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    86,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,    -1,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,   235,    -1,    -1,   238,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,   199,
     200,   201,   202,   203,   204,    -1,   206,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,   226,     3,     4,    -1,
      -1,   231,    -1,    -1,    10,    11,    12,    -1,   238,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    55,
      56,    57,    58,   230,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,     3,     4,    74,    75,
      76,    -1,    -1,    10,    11,    12,    82,    83,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    55,    56,
      57,    58,   230,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,   235,
      -1,    -1,   238,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,   189,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,   240,   199,   200,   201,   202,   203,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,    -1,     3,     4,   235,     6,
      -1,   238,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    55,    56,
      57,    58,   230,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,   240,    -1,    -1,    -1,    -1,    74,    75,    76,
       3,     4,    -1,     6,    -1,    82,    83,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    55,    56,    57,    58,   230,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,   189,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,   240,    -1,    -1,    -1,    -1,   199,   200,   201,   202,
     203,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,     3,     4,    -1,    -1,   231,    -1,
      -1,    10,    11,    12,    -1,   238,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    13,    14,    82,    83,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   142,    -1,   105,   106,   107,    13,    14,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,
     189,   123,   124,    -1,   193,   166,   167,   168,    -1,    -1,
     199,   200,   201,   202,   203,    -1,    -1,    -1,   207,    -1,
     142,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,   231,    -1,   166,   167,   168,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   236,    -1,    -1,   105,   106,
     107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,   120,   121,    -1,   123,   124,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   236,   142,   105,   106,   107,    13,
      14,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   166,   167,   168,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   236,
      -1,   105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,
     124,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   236,   142,   105,
     106,   107,    13,    14,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,    -1,   123,   124,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     166,   167,   168,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   236,    -1,   105,   106,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     236,   142,   105,   106,   107,    13,    14,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   236,    -1,   105,   106,   107,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,    -1,   120,   121,    -1,   123,   124,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,   236,   142,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,   166,   167,
     168,    44,    45,   240,    -1,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,    64,    65,    66,    -1,   230,    -1,    70,    71,    -1,
      73,   236,    -1,    -1,    77,    78,    -1,    80,    81,    -1,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,   106,   107,   108,    -1,   110,   236,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,   121,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,     4,
      -1,   154,   155,   156,    -1,    -1,    -1,   160,    13,    14,
      -1,    -1,   165,   166,   167,   168,    -1,    -1,   171,    -1,
     173,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    44,
      45,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,   207,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    77,    78,    -1,    80,    81,    -1,    83,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,   106,   107,   108,    -1,   110,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,   154,
     155,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,     4,     5,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    13,    14,    -1,    -1,    -1,    -1,
      -1,   196,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,   207,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,   105,   106,   107,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
      -1,   120,   121,    -1,   123,   124,    13,    14,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   142,    -1,    -1,   230,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,   206,   207,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,   105,   106,
     107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,   120,   121,    -1,   123,   124,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,   142,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,   212,   213,   214,   215,   216,   217,   218,   219,
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
      -1,    -1,    -1,    -1,    -1,   240,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,   236,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,   235,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,   235,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,   235,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,    -1,   234,   212,
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
     230,    -1,    -1,    -1,   234,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,   212,   213,
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
     225,    -1,    -1,    -1,    -1,   230
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   242,   243,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    77,    78,    80,
      81,    83,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   104,   105,   106,
     107,   108,   110,   112,   113,   114,   115,   116,   117,   118,
     120,   121,   122,   123,   124,   125,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   154,
     155,   156,   160,   165,   166,   167,   168,   171,   173,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   196,   197,   198,   205,   207,   244,   246,
     247,   267,   285,   286,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   304,   306,   307,   313,   314,   315,   316,
     320,   341,   342,   235,   239,    14,    95,   231,   231,     6,
     235,     6,     6,     6,     6,   231,     6,     6,   233,   233,
       4,   322,   342,   231,   233,   265,   265,   231,   235,   231,
     231,     4,   231,   235,   231,   231,     4,   231,   235,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   109,
      95,     6,   235,    89,    92,    95,   231,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    74,    75,    76,    82,    89,
      92,    95,    97,   116,   121,   123,   189,   193,   194,   195,
     199,   200,   201,   202,   203,   221,   222,   226,   231,   235,
     238,   286,   297,   304,   306,   317,   318,   320,   322,   329,
     331,   342,   231,   235,    95,    95,   116,    92,    95,    97,
      89,    92,    95,    97,    92,    95,    97,    92,    95,   231,
      92,   171,   187,   188,   235,   221,   222,   231,   235,   326,
     327,   326,   235,   235,   326,     4,    89,    93,    99,   100,
     102,   103,   120,   231,    95,    97,    95,    92,     4,   182,
     235,   342,     4,     6,    89,    92,    95,    92,    95,     4,
       4,     4,     5,   231,   329,   330,     4,   231,   231,   231,
       4,   235,   333,   342,     4,   231,   231,   231,     6,     6,
     233,     5,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    59,    60,    61,    62,    67,    68,    69,    72,    84,
      86,   190,   191,   192,   204,   206,   337,   342,   231,     4,
     337,     5,   235,     5,   235,    32,   222,   317,   342,   233,
     231,   235,     6,   231,   235,     6,   239,     7,   123,   182,
     208,   209,   210,   211,   228,   229,   231,   233,   237,   263,
     264,   265,   317,   336,   337,   342,     4,   286,   287,   288,
     235,     6,   317,   336,   337,   342,   336,   317,   336,   340,
     269,   273,   231,   325,     9,   337,   342,   317,   222,   317,
     331,   332,   317,   317,   231,   317,   332,   317,   317,   231,
     317,   332,   317,   317,   317,   317,   317,   317,   336,   317,
     317,   317,   329,   231,   332,   330,   330,   330,   336,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   231,   233,   265,   265,   265,   265,   265,   265,
     231,   265,   265,   231,   265,     5,   174,   235,     5,   174,
       5,   174,     5,   174,   116,    89,    92,    95,    97,   231,
     265,   265,   265,   231,   231,   317,   235,   317,   331,   317,
     317,   236,   332,     9,   342,     8,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     230,     9,   231,   233,   237,   264,   265,   317,   332,   231,
     231,   231,   329,   330,   330,   330,   231,   231,   231,   231,
     231,   329,   231,   329,   231,   329,   235,   235,   317,     4,
     329,   333,   235,   235,   326,   326,   326,   317,   317,   221,
     222,   235,   235,   326,   221,   222,   231,   288,   326,   235,
     231,   235,   231,   231,   231,   231,   231,   231,   231,   317,
     330,   330,   330,   231,     4,   233,   233,   288,     6,     6,
     235,   235,   235,   330,   330,   233,   233,   233,   317,     6,
       6,   317,   317,   317,   237,   317,   235,   174,   317,   317,
     317,   317,   265,   265,   265,   231,   231,   231,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   231,   231,
     265,   233,     6,     6,   235,     6,   288,     6,   288,   265,
     317,   223,   235,   231,   233,   336,   317,   288,   329,   329,
     235,   337,    89,    92,    95,    97,     7,   317,   317,     4,
     171,   172,   329,     6,   232,   234,   235,   266,     6,   235,
       6,     9,   231,   233,   237,   342,   236,    89,    92,    95,
      97,   116,   121,   124,   285,   317,     6,   232,   240,     9,
     231,   233,   237,   232,   240,   240,   232,   240,   234,   240,
     268,   234,   268,    85,   324,   321,   342,   240,   240,   232,
     223,   236,   240,   232,   232,   317,   232,   236,   232,   232,
     317,   232,   236,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,     7,   317,   236,     6,     6,     6,   232,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   331,   317,   317,
     317,   317,   317,   317,   317,   331,   331,   342,   235,   317,
     317,   336,   317,   336,   329,   336,   336,   340,   317,    64,
     317,    64,    64,    64,   330,   330,   330,   330,   336,   336,
     331,   331,   342,   337,   332,   232,   236,     9,   265,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   235,   317,   331,   317,   317,   317,   342,   317,   317,
       4,   323,   235,   266,   232,   236,   317,   317,   317,     7,
       7,   310,   310,   279,   317,   337,   280,   317,   337,   281,
     317,   337,   282,   317,   337,   317,     6,   317,     6,   317,
       6,   332,   332,   235,   232,     6,   235,   288,   288,   240,
     240,   240,   326,   326,   287,   287,   240,   317,   236,   301,
     240,   288,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   232,     7,   311,     6,     7,   317,     6,   317,   317,
     236,   332,   332,   332,     6,     6,   317,   317,   317,   232,
     232,   232,   232,   171,   240,   288,   235,     8,   232,   232,
     234,   340,   336,   340,   336,   336,   336,   336,   336,   336,
     317,   336,   336,   336,   336,   238,   339,   342,   337,   336,
     336,   336,   342,   332,   236,   236,   317,   317,   288,   234,
     232,   146,   305,   232,   236,   240,   317,     6,   235,   235,
     235,   235,   317,   232,   234,     7,   263,   264,   237,     7,
       6,   332,     7,   211,   263,   248,   342,   317,   317,   323,
     233,   235,   235,   235,   235,   231,   116,    92,    95,    97,
     236,     6,   218,   245,   332,   342,   317,   317,     4,   323,
       6,   332,   317,     6,   336,     6,   342,     6,   336,   317,
     232,   233,   317,   337,     7,   174,   317,   331,     7,     7,
     232,     7,   174,     7,     7,   232,     7,   174,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   317,   232,   235,
       6,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   240,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   240,   240,   240,   232,   234,   234,   332,   240,
     240,   266,   240,   266,   240,   240,   240,   232,   319,   235,
     236,   235,   235,   235,   240,   240,   266,   266,   266,   232,
     232,   236,     7,   266,     8,     8,   332,   237,   232,   234,
     264,   332,     7,   235,   232,   232,   232,   317,   329,     4,
     309,     6,   232,   240,   232,   240,   232,   240,   232,   240,
     232,   232,   232,   236,   236,   332,   237,   288,   236,   236,
     326,   317,   317,   236,   236,   317,   326,   126,   126,   143,
     151,   152,   153,   157,   158,   302,   303,   326,   236,   298,
     232,   236,   232,   232,   232,   232,   232,   232,   232,     7,
     317,     6,   317,   232,   234,   234,   236,   236,   236,   234,
     234,   240,     7,     7,     7,   237,   317,   236,   317,   317,
       7,   237,   266,   240,   266,   266,   232,   232,   240,   266,
     266,   240,   240,   266,   266,   266,   266,   317,   266,     9,
     338,   240,   232,   240,   266,   234,   236,   236,     7,     6,
     317,   236,   235,     6,   329,   236,   317,   317,   317,   317,
       6,     7,   263,   264,   237,   263,   264,   337,   317,     6,
       4,   235,   334,   342,   236,    46,    46,   329,     4,   161,
     162,   163,   164,   236,   251,   255,   258,   260,   261,   237,
     232,   234,   317,   332,   332,   332,   332,   317,   231,   231,
     231,   231,   218,   336,   232,   237,   232,   234,   232,   240,
       7,   265,   317,   266,   266,   326,    95,    97,   329,   329,
       7,   329,    95,    97,   329,   329,     7,   329,    97,   329,
     329,   329,   329,   329,   329,   329,   329,   329,     6,     7,
     332,   317,   317,   317,   317,   236,   317,   317,   317,   329,
     336,   336,   275,   317,   317,   317,   317,   317,   317,   329,
     317,   317,   236,   323,   264,   237,   264,   236,   329,   332,
       7,     7,     7,   126,   308,     6,   263,   317,   263,   317,
     263,   317,   263,   317,     7,     7,     7,     7,     7,   236,
       4,   236,   240,   240,   240,   236,   236,   107,     4,     6,
     317,   235,     6,   231,     6,   159,     6,   159,   236,   303,
     240,   302,     7,     6,     7,     7,     7,     7,     7,     7,
       7,   329,     6,   235,     6,     6,     6,    95,     7,     6,
       6,   317,   329,   329,   329,     4,   240,     8,     8,   232,
       4,     4,   332,   336,   317,   336,   238,   277,   336,   336,
     240,   235,     6,   235,   329,   236,   236,   236,   236,   236,
     317,     6,     4,   171,   172,   317,     6,     6,     6,     7,
     333,   335,     6,   233,   266,   265,   265,     6,   252,   231,
     231,   235,   262,     6,   323,   237,   336,   234,   236,   236,
     236,   236,   232,   317,   317,   317,   317,     6,     6,   245,
     323,   237,     6,   317,   235,   317,   337,   266,   275,     6,
       6,     6,   235,   235,   120,   284,   284,   329,     6,   235,
     235,     6,     6,   329,   174,   283,   235,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   236,   266,   266,
     266,   266,   266,   240,   240,   240,   232,   266,   266,   240,
     266,   276,   240,   240,   240,   240,   232,   266,     6,     4,
     266,     6,   236,   329,   329,   329,     4,     6,   329,   329,
     329,   329,   329,   329,   329,   235,   235,     7,     6,     7,
     317,   317,   317,   235,   235,   235,   233,     6,   317,   329,
     317,     6,     6,   317,   326,   236,     5,   329,   235,   235,
     235,   235,   235,   235,   235,   329,     6,   332,   235,   317,
     234,     6,     6,   170,   317,   317,   317,     6,     6,     7,
     266,   240,   240,   266,   240,   317,   240,   266,   278,   232,
     266,   337,   288,   288,   240,     6,     6,     7,   263,   264,
     237,     7,     6,   333,   236,   240,   317,   263,   266,   340,
     340,   231,   317,   317,   328,   329,   235,     4,     6,     6,
       6,     6,     6,     6,   232,   232,   232,   232,   336,     4,
     240,   329,   337,     7,   234,   317,   317,   326,     6,     6,
       6,   317,   317,     6,    93,     6,   317,     5,   235,   317,
     317,   317,     4,   317,   317,   317,   317,   264,   235,     6,
     283,     6,   317,     6,     6,     6,     6,     6,     4,     6,
       6,   332,   332,   317,   317,   337,   236,   232,   236,   240,
     287,   287,   317,   317,   236,   240,   232,   236,   240,     6,
       6,   328,   326,   326,   326,   326,   326,   222,   326,     6,
     236,   317,     6,     6,   329,   236,   240,     8,   236,   232,
     235,   317,   337,   336,   317,   336,     4,   186,   240,   305,
     305,   329,   337,   317,     6,     4,   334,     6,   333,   234,
     329,     6,   266,   266,   249,   317,   240,   240,   236,   240,
     250,   317,     6,   317,   270,   272,   235,   236,   236,   236,
     236,   235,   236,     5,   328,   266,   266,   240,   235,   329,
     337,   240,   240,   240,   240,   317,     6,   235,   236,   236,
     235,     6,     6,   235,   317,   236,   236,   236,   234,     6,
     329,     7,   235,   317,   236,   240,   240,   240,   240,   240,
     240,     6,   236,   169,   317,   317,   332,     6,     6,   232,
     266,   266,   235,   317,   337,   337,   337,   236,   236,   236,
       6,     6,     7,     6,   237,     6,     6,     6,   232,   240,
     317,   317,   235,   329,   236,   240,   240,   275,   277,   329,
       6,     6,     6,     6,   317,     6,     6,   236,   317,   274,
     317,   331,   317,   317,   317,   317,   236,   328,   130,   131,
     136,   312,   130,   131,   312,   332,   287,   236,   240,     6,
     236,   329,   288,   236,     6,   332,   326,   326,   326,   326,
     326,   317,   236,   236,   236,   340,   232,   235,     6,   333,
     172,   253,   317,   240,   240,   328,     6,   317,   317,   236,
     236,   271,   236,   235,   240,   236,   240,     7,     7,   240,
     240,   240,   240,   236,   235,   326,   329,     6,   235,   326,
       6,   236,   236,   317,     6,   126,   236,   299,   235,   236,
     240,   240,   240,   240,   240,     6,     6,   236,     6,   288,
       6,   235,   317,   317,   236,   240,   275,   317,   317,   317,
     337,   342,   317,   317,   317,   317,     6,   326,     6,   326,
       6,     6,   236,   317,   302,   288,     6,   332,   332,   332,
     332,   326,   332,   305,   250,   232,   240,     6,   235,   317,
     236,   240,   240,     7,   231,   240,   240,   240,   240,   240,
     240,     6,   236,   236,   300,   236,   236,   236,   236,   240,
     236,   236,   236,   256,   317,   328,   236,   317,   317,   337,
     232,   317,   317,   317,   317,   326,   326,   302,     6,     6,
       6,     6,   332,     6,     6,     6,   235,   232,   236,     6,
     236,   266,   240,   240,   240,   240,   240,   240,   236,   236,
     254,   336,   259,   235,     6,   317,   317,   317,   317,   317,
     317,     6,   236,   240,   235,   328,   236,   236,   236,   236,
     236,   236,     6,   336,   257,   336,   236,     6,     6,   236,
     240,     6,     6,   336
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
#line 239 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 250 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 251 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 252 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 254 "Gmsh.y"
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
#line 270 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 271 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 272 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 273 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 274 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 275 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 276 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 277 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 278 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 279 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 280 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 281 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 282 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 283 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 284 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 285 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 290 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 294 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 301 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 306 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 311 "Gmsh.y"
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
#line 325 "Gmsh.y"
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
#line 338 "Gmsh.y"
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
#line 351 "Gmsh.y"
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
#line 379 "Gmsh.y"
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
#line 393 "Gmsh.y"
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
#line 406 "Gmsh.y"
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
#line 419 "Gmsh.y"
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
#line 437 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 451 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 453 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 458 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 460 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 465 "Gmsh.y"
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
#line 569 "Gmsh.y"
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
#line 579 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 588 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 595 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 605 "Gmsh.y"
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
#line 614 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 623 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 630 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 640 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 648 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 658 "Gmsh.y"
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
#line 677 "Gmsh.y"
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
#line 696 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 702 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 709 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 710 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 711 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 712 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 713 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 717 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 718 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 724 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 724 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 725 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 725 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 735 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 740 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 746 "Gmsh.y"
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
#line 808 "Gmsh.y"
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
#line 823 "Gmsh.y"
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
#line 852 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 862 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 867 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 875 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 880 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 888 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 897 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 902 "Gmsh.y"
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
#line 914 "Gmsh.y"
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
#line 931 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 937 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 946 "Gmsh.y"
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
#line 964 "Gmsh.y"
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
#line 982 "Gmsh.y"
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
#line 991 "Gmsh.y"
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
#line 1003 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1008 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1016 "Gmsh.y"
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
#line 1036 "Gmsh.y"
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
#line 1059 "Gmsh.y"
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
#line 1070 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1078 "Gmsh.y"
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
#line 1100 "Gmsh.y"
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
#line 1123 "Gmsh.y"
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
#line 1161 "Gmsh.y"
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
#line 1182 "Gmsh.y"
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
#line 1194 "Gmsh.y"
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
#line 1212 "Gmsh.y"
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
#line 1221 "Gmsh.y"
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
#line 1230 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 115:
#line 1232 "Gmsh.y"
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
#line 1250 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 117:
#line 1252 "Gmsh.y"
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
#line 1268 "Gmsh.y"
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
#line 1277 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 120:
#line 1279 "Gmsh.y"
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
#line 1293 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 123:
#line 1301 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 124:
#line 1307 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 125:
#line 1312 "Gmsh.y"
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

  case 128:
#line 1343 "Gmsh.y"
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

  case 129:
#line 1354 "Gmsh.y"
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

  case 130:
#line 1369 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 133:
#line 1385 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 134:
#line 1393 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 135:
#line 1402 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 136:
#line 1410 "Gmsh.y"
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

  case 137:
#line 1428 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 138:
#line 1432 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 0, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 139:
#line 1439 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 140:
#line 1447 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 141:
#line 1451 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 1, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 142:
#line 1458 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 143:
#line 1466 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 144:
#line 1470 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 2, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 145:
#line 1477 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 146:
#line 1485 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 147:
#line 1489 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 3, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 148:
#line 1496 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 149:
#line 1504 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 150:
#line 1508 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 151:
#line 1514 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 152:
#line 1518 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 153:
#line 1525 "Gmsh.y"
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

  case 154:
#line 1546 "Gmsh.y"
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

  case 155:
#line 1560 "Gmsh.y"
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

  case 156:
#line 1574 "Gmsh.y"
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

  case 157:
#line 1609 "Gmsh.y"
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

  case 158:
#line 1647 "Gmsh.y"
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

  case 159:
#line 1661 "Gmsh.y"
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

  case 160:
#line 1676 "Gmsh.y"
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

  case 161:
#line 1695 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 162:
#line 1704 "Gmsh.y"
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

  case 163:
#line 1718 "Gmsh.y"
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

  case 164:
#line 1733 "Gmsh.y"
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

  case 165:
#line 1747 "Gmsh.y"
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

  case 166:
#line 1766 "Gmsh.y"
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

  case 167:
#line 1776 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 168:
#line 1782 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 169:
#line 1788 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 170:
#line 1795 "Gmsh.y"
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

  case 171:
#line 1824 "Gmsh.y"
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
#line 1839 "Gmsh.y"
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

  case 173:
#line 1859 "Gmsh.y"
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

  case 174:
#line 1880 "Gmsh.y"
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

  case 175:
#line 1901 "Gmsh.y"
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

  case 176:
#line 1922 "Gmsh.y"
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

  case 177:
#line 1944 "Gmsh.y"
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

  case 178:
#line 1966 "Gmsh.y"
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

  case 179:
#line 1987 "Gmsh.y"
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

  case 180:
#line 2010 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 2020 "Gmsh.y"
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

  case 182:
#line 2040 "Gmsh.y"
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

  case 183:
#line 2055 "Gmsh.y"
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

  case 184:
#line 2069 "Gmsh.y"
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

  case 185:
#line 2085 "Gmsh.y"
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

  case 186:
#line 2101 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2110 "Gmsh.y"
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

  case 188:
#line 2120 "Gmsh.y"
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

  case 189:
#line 2130 "Gmsh.y"
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

  case 190:
#line 2140 "Gmsh.y"
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

  case 191:
#line 2155 "Gmsh.y"
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

  case 192:
#line 2167 "Gmsh.y"
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

  case 193:
#line 2181 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      if(factory == "OpenCASCADE"){
        Msg::Error("Symmetry not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 194:
#line 2194 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 195:
#line 2207 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 196:
#line 2220 "Gmsh.y"
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
      else if(action == "Boundary" ||
              action == "CombinedBoundary" ||
              action == "OrientedBoundary" ||
              action == "CombinedOrientedBoundary"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, action.find("Combined") != std::string::npos,
           action.find("Oriented") != std::string::npos);
      }
      else{
        yymsg(0, "Unknown action on multiple shapes: %s", (yyvsp[(1) - (4)].c));
      }
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 197:
#line 2257 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
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

  case 198:
#line 2277 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
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

  case 199:
#line 2298 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 200:
#line 2299 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 201:
#line 2304 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 202:
#line 2308 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 203:
#line 2312 "Gmsh.y"
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

  case 204:
#line 2323 "Gmsh.y"
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

  case 205:
#line 2334 "Gmsh.y"
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

  case 206:
#line 2345 "Gmsh.y"
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

  case 207:
#line 2361 "Gmsh.y"
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

  case 208:
#line 2380 "Gmsh.y"
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

  case 209:
#line 2402 "Gmsh.y"
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

  case 210:
#line 2417 "Gmsh.y"
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

  case 211:
#line 2432 "Gmsh.y"
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

  case 212:
#line 2451 "Gmsh.y"
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

  case 213:
#line 2502 "Gmsh.y"
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

  case 214:
#line 2523 "Gmsh.y"
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

  case 215:
#line 2545 "Gmsh.y"
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

  case 216:
#line 2567 "Gmsh.y"
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

  case 217:
#line 2672 "Gmsh.y"
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

  case 218:
#line 2688 "Gmsh.y"
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

  case 219:
#line 2723 "Gmsh.y"
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

  case 220:
#line 2734 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 221:
#line 2740 "Gmsh.y"
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

  case 222:
#line 2755 "Gmsh.y"
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

  case 223:
#line 2783 "Gmsh.y"
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

  case 224:
#line 2800 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 225:
#line 2807 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 226:
#line 2819 "Gmsh.y"
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

  case 227:
#line 2838 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 228:
#line 2844 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 229:
#line 2850 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 230:
#line 2857 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 231:
#line 2864 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 232:
#line 2871 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 233:
#line 2883 "Gmsh.y"
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

  case 234:
#line 2956 "Gmsh.y"
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

  case 235:
#line 2974 "Gmsh.y"
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

  case 236:
#line 2991 "Gmsh.y"
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

  case 237:
#line 3006 "Gmsh.y"
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

  case 238:
#line 3039 "Gmsh.y"
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

  case 239:
#line 3051 "Gmsh.y"
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

  case 240:
#line 3075 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 241:
#line 3079 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 242:
#line 3084 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 243:
#line 3091 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 244:
#line 3096 "Gmsh.y"
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

  case 245:
#line 3106 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 246:
#line 3111 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 247:
#line 3117 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 248:
#line 3125 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 249:
#line 3129 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 250:
#line 3133 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 251:
#line 3143 "Gmsh.y"
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

  case 252:
#line 3206 "Gmsh.y"
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

  case 253:
#line 3222 "Gmsh.y"
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

  case 254:
#line 3239 "Gmsh.y"
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

  case 255:
#line 3256 "Gmsh.y"
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

  case 256:
#line 3278 "Gmsh.y"
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

  case 257:
#line 3300 "Gmsh.y"
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

  case 258:
#line 3335 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 259:
#line 3343 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 260:
#line 3351 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 261:
#line 3357 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 262:
#line 3364 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 263:
#line 3371 "Gmsh.y"
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

  case 264:
#line 3391 "Gmsh.y"
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

  case 265:
#line 3417 "Gmsh.y"
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

  case 266:
#line 3429 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 267:
#line 3441 "Gmsh.y"
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

  case 268:
#line 3457 "Gmsh.y"
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

  case 269:
#line 3473 "Gmsh.y"
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

  case 270:
#line 3489 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 271:
#line 3495 "Gmsh.y"
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

  case 272:
#line 3511 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 273:
#line 3517 "Gmsh.y"
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

  case 274:
#line 3535 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 275:
#line 3541 "Gmsh.y"
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

  case 276:
#line 3557 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 277:
#line 3563 "Gmsh.y"
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

  case 278:
#line 3578 "Gmsh.y"
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

  case 279:
#line 3592 "Gmsh.y"
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

  case 280:
#line 3607 "Gmsh.y"
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

  case 281:
#line 3622 "Gmsh.y"
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

  case 282:
#line 3643 "Gmsh.y"
    {
    ;}
    break;

  case 283:
#line 3646 "Gmsh.y"
    {
    ;}
    break;

  case 284:
#line 3652 "Gmsh.y"
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

  case 285:
#line 3664 "Gmsh.y"
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

  case 286:
#line 3684 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 287:
#line 3688 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 288:
#line 3692 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 289:
#line 3696 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 290:
#line 3700 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 291:
#line 3704 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 292:
#line 3708 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 293:
#line 3712 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 294:
#line 3721 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 295:
#line 3733 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 296:
#line 3734 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 297:
#line 3735 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 298:
#line 3736 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 299:
#line 3737 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 300:
#line 3741 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 301:
#line 3742 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 302:
#line 3743 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 303:
#line 3748 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (9)].l), tool);
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

  case 304:
#line 3765 "Gmsh.y"
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

  case 305:
#line 3783 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (14)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(11) - (14)].l), tool);
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), object, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 306:
#line 3798 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 307:
#line 3802 "Gmsh.y"
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

  case 308:
#line 3817 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 309:
#line 3821 "Gmsh.y"
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

  case 310:
#line 3837 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 311:
#line 3841 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 312:
#line 3846 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 313:
#line 3850 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 314:
#line 3856 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 315:
#line 3860 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 316:
#line 3867 "Gmsh.y"
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

  case 317:
#line 3884 "Gmsh.y"
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

  case 318:
#line 3925 "Gmsh.y"
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

  case 319:
#line 3969 "Gmsh.y"
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

  case 320:
#line 4008 "Gmsh.y"
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

  case 321:
#line 4033 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 322:
#line 4042 "Gmsh.y"
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

  case 323:
#line 4072 "Gmsh.y"
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

  case 324:
#line 4098 "Gmsh.y"
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

  case 325:
#line 4125 "Gmsh.y"
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

  case 326:
#line 4157 "Gmsh.y"
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

  case 327:
#line 4184 "Gmsh.y"
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

  case 328:
#line 4210 "Gmsh.y"
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

  case 329:
#line 4236 "Gmsh.y"
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

  case 330:
#line 4262 "Gmsh.y"
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

  case 331:
#line 4288 "Gmsh.y"
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

  case 332:
#line 4309 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 333:
#line 4315 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 334:
#line 4321 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 335:
#line 4327 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 336:
#line 4333 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 337:
#line 4339 "Gmsh.y"
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

  case 338:
#line 4365 "Gmsh.y"
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

  case 339:
#line 4391 "Gmsh.y"
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

  case 340:
#line 4408 "Gmsh.y"
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

  case 341:
#line 4425 "Gmsh.y"
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

  case 342:
#line 4442 "Gmsh.y"
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

  case 343:
#line 4454 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 344:
#line 4460 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 345:
#line 4466 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 346:
#line 4478 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 347:
#line 4482 "Gmsh.y"
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

  case 348:
#line 4492 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 349:
#line 4502 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 350:
#line 4503 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 351:
#line 4504 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 352:
#line 4509 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 353:
#line 4515 "Gmsh.y"
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

  case 354:
#line 4527 "Gmsh.y"
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

  case 355:
#line 4545 "Gmsh.y"
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

  case 356:
#line 4572 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 357:
#line 4573 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 358:
#line 4574 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 359:
#line 4575 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 360:
#line 4576 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 361:
#line 4577 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 362:
#line 4578 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 363:
#line 4579 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 364:
#line 4581 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 365:
#line 4587 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 366:
#line 4588 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 367:
#line 4589 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 368:
#line 4590 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 369:
#line 4591 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 370:
#line 4592 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 371:
#line 4593 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 372:
#line 4594 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 373:
#line 4595 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 374:
#line 4596 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 375:
#line 4597 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 376:
#line 4598 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 377:
#line 4599 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 378:
#line 4600 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 379:
#line 4601 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 380:
#line 4602 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 381:
#line 4603 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 382:
#line 4604 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 383:
#line 4605 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 384:
#line 4606 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 385:
#line 4607 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 386:
#line 4608 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 387:
#line 4609 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 388:
#line 4610 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 389:
#line 4611 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 390:
#line 4612 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 391:
#line 4613 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 392:
#line 4614 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 393:
#line 4615 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 394:
#line 4616 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 395:
#line 4617 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 396:
#line 4618 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 397:
#line 4619 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 398:
#line 4620 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 399:
#line 4629 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 400:
#line 4630 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 401:
#line 4631 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 402:
#line 4632 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 403:
#line 4633 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 404:
#line 4634 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 405:
#line 4635 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 406:
#line 4636 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 407:
#line 4637 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 408:
#line 4638 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 409:
#line 4639 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 410:
#line 4644 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 411:
#line 4646 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 412:
#line 4652 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 413:
#line 4654 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 414:
#line 4659 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 415:
#line 4665 "Gmsh.y"
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

  case 416:
#line 4689 "Gmsh.y"
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

  case 417:
#line 4707 "Gmsh.y"
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

  case 418:
#line 4725 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 419:
#line 4730 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 420:
#line 4736 "Gmsh.y"
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

  case 421:
#line 4752 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 422:
#line 4758 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 423:
#line 4764 "Gmsh.y"
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
#line 4783 "Gmsh.y"
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
#line 4804 "Gmsh.y"
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
#line 4837 "Gmsh.y"
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
#line 4861 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 428:
#line 4865 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 429:
#line 4870 "Gmsh.y"
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
#line 4880 "Gmsh.y"
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
#line 4890 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 4895 "Gmsh.y"
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
#line 4906 "Gmsh.y"
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
#line 4915 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 435:
#line 4920 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 436:
#line 4925 "Gmsh.y"
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
#line 4953 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 438:
#line 4955 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (8)].c2).char1? (yyvsp[(2) - (8)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (8)].c2).char2);
      Free((yyvsp[(2) - (8)].c2).char1); Free((yyvsp[(2) - (8)].c2).char2);
      if (!(yyvsp[(3) - (8)].i))
        if (!nameSpaces[struct_namespace].count(struct_name)) {
          int index = (int)(yyvsp[(6) - (8)].d);
          if (index < 0)
            index = nameSpaces[struct_namespace].size()+1;
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
#line 4983 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 440:
#line 4985 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 441:
#line 4990 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 442:
#line 4999 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 443:
#line 5001 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 444:
#line 5006 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 445:
#line 5008 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 446:
#line 5014 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 447:
#line 5018 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 448:
#line 5022 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 449:
#line 5026 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 450:
#line 5030 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 451:
#line 5037 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 452:
#line 5041 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 453:
#line 5045 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 454:
#line 5049 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 455:
#line 5056 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 456:
#line 5061 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 457:
#line 5068 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 458:
#line 5073 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 459:
#line 5077 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 460:
#line 5082 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 461:
#line 5086 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 462:
#line 5094 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 463:
#line 5105 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 464:
#line 5109 "Gmsh.y"
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
#line 5121 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 466:
#line 5129 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 467:
#line 5137 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 468:
#line 5144 "Gmsh.y"
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
#line 5154 "Gmsh.y"
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
#line 5177 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 471:
#line 5183 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 472:
#line 5189 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 473:
#line 5195 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 474:
#line 5201 "Gmsh.y"
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
#line 5212 "Gmsh.y"
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
#line 5223 "Gmsh.y"
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
#line 5234 "Gmsh.y"
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
#line 5246 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 479:
#line 5252 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 480:
#line 5258 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 481:
#line 5264 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 482:
#line 5269 "Gmsh.y"
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
#line 5279 "Gmsh.y"
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
#line 5289 "Gmsh.y"
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
#line 5299 "Gmsh.y"
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
#line 5312 "Gmsh.y"
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
#line 5324 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 488:
#line 5328 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 489:
#line 5332 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 490:
#line 5336 "Gmsh.y"
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
#line 5354 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 492:
#line 5362 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 493:
#line 5370 "Gmsh.y"
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
#line 5399 "Gmsh.y"
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
#line 5409 "Gmsh.y"
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
#line 5425 "Gmsh.y"
    {
      std::set<double> c;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double d; List_Read((yyvsp[(3) - (4)].l), i, &d);
        std::set<double>::iterator it = c.find(d);
        if(it == c.end())
          c.insert(d);
        else
          c.erase(it);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      for(std::set<double>::iterator it = c.begin(); it != c.end(); it++){
        double d = *it;
        List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 497:
#line 5443 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 498:
#line 5454 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 499:
#line 5459 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 500:
#line 5463 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 501:
#line 5467 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 502:
#line 5479 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 503:
#line 5483 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 504:
#line 5495 "Gmsh.y"
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

  case 505:
#line 5512 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 506:
#line 5522 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 507:
#line 5526 "Gmsh.y"
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

  case 508:
#line 5541 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 509:
#line 5546 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 510:
#line 5553 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 511:
#line 5557 "Gmsh.y"
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

  case 512:
#line 5570 "Gmsh.y"
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

  case 513:
#line 5584 "Gmsh.y"
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

  case 514:
#line 5601 "Gmsh.y"
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

  case 515:
#line 5627 "Gmsh.y"
    { (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 516:
#line 5631 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 517:
#line 5639 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 518:
#line 5645 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 519:
#line 5651 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 520:
#line 5657 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 521:
#line 5666 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 522:
#line 5670 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 523:
#line 5674 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 524:
#line 5682 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 525:
#line 5688 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 526:
#line 5694 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 527:
#line 5702 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 528:
#line 5710 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 529:
#line 5717 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 530:
#line 5725 "Gmsh.y"
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

  case 531:
#line 5740 "Gmsh.y"
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

  case 532:
#line 5754 "Gmsh.y"
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

  case 533:
#line 5768 "Gmsh.y"
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

  case 534:
#line 5780 "Gmsh.y"
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

  case 535:
#line 5796 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 536:
#line 5805 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 537:
#line 5814 "Gmsh.y"
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

  case 538:
#line 5824 "Gmsh.y"
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

  case 539:
#line 5835 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 540:
#line 5843 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 541:
#line 5851 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 542:
#line 5855 "Gmsh.y"
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

  case 543:
#line 5874 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 544:
#line 5881 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 545:
#line 5887 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 546:
#line 5894 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 547:
#line 5901 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 548:
#line 5903 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 549:
#line 5911 "Gmsh.y"
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

  case 550:
#line 5935 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 551:
#line 5937 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 552:
#line 5943 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 553:
#line 5948 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 554:
#line 5956 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 555:
#line 5965 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 556:
#line 5978 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 557:
#line 5981 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 558:
#line 5985 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 12948 "Gmsh.tab.cpp"
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


#line 5988 "Gmsh.y"


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
      (dimTags[i].first, dimTags[i].second);
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
      (dimTags[i].first, dimTags[i].second);
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

char* treat_Struct_FullName_dot_tSTRING_String(char* c1, char* c2, char* c3)
{
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

