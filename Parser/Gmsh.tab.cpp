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
     tHomology = 450,
     tCohomology = 451,
     tBetti = 452,
     tExists = 453,
     tFileExists = 454,
     tGMSH_MAJOR_VERSION = 455,
     tGMSH_MINOR_VERSION = 456,
     tGMSH_PATCH_VERSION = 457,
     tGmshExecutableName = 458,
     tSetPartition = 459,
     tNameToString = 460,
     tStringToName = 461,
     tAFFECTDIVIDE = 462,
     tAFFECTTIMES = 463,
     tAFFECTMINUS = 464,
     tAFFECTPLUS = 465,
     tOR = 466,
     tAND = 467,
     tNOTEQUAL = 468,
     tEQUAL = 469,
     tGREATEROREQUAL = 470,
     tLESSOREQUAL = 471,
     UNARYPREC = 472,
     tMINUSMINUS = 473,
     tPLUSPLUS = 474
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
#define tHomology 450
#define tCohomology 451
#define tBetti 452
#define tExists 453
#define tFileExists 454
#define tGMSH_MAJOR_VERSION 455
#define tGMSH_MINOR_VERSION 456
#define tGMSH_PATCH_VERSION 457
#define tGmshExecutableName 458
#define tSetPartition 459
#define tNameToString 460
#define tStringToName 461
#define tAFFECTDIVIDE 462
#define tAFFECTTIMES 463
#define tAFFECTMINUS 464
#define tAFFECTPLUS 465
#define tOR 466
#define tAND 467
#define tNOTEQUAL 468
#define tEQUAL 469
#define tGREATEROREQUAL 470
#define tLESSOREQUAL 471
#define UNARYPREC 472
#define tMINUSMINUS 473
#define tPLUSPLUS 474




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
#line 699 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 712 "Gmsh.tab.cpp"

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
#define YYLAST   13781

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  568
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2088

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   474

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   225,     2,   237,     2,   224,     2,     2,
     230,   231,   222,   220,   239,   221,   236,   223,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     216,     2,   217,   211,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   232,     2,   233,   229,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   235,   238,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   212,   213,   214,   215,
     218,   219,   226,   227,   228
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
    2919,  2925,  2927,  2932,  2934,  2936,  2938,  2943,  2950,  2955,
    2962,  2967,  2972,  2977,  2986,  2991,  2996,  3001,  3006,  3015,
    3024,  3031,  3036,  3043,  3048,  3050,  3055,  3060,  3061,  3068,
    3073,  3076,  3081,  3083,  3087,  3093,  3099,  3101,  3103
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     241,     0,    -1,   242,    -1,     1,     6,    -1,    -1,   242,
     243,    -1,   245,    -1,   246,    -1,   266,    -1,   115,   230,
     338,   231,     6,    -1,   287,    -1,   288,    -1,   292,    -1,
     293,    -1,   294,    -1,   295,    -1,   299,    -1,   308,    -1,
     309,    -1,   315,    -1,   316,    -1,   298,    -1,   297,    -1,
     296,    -1,   291,    -1,   318,    -1,   217,    -1,   217,   217,
      -1,    44,   230,   338,   231,     6,    -1,    45,   230,   338,
     231,     6,    -1,    44,   230,   338,   231,   244,   338,     6,
      -1,    44,   230,   338,   239,   334,   231,     6,    -1,    45,
     230,   338,   239,   334,   231,     6,    -1,    44,   230,   338,
     239,   334,   231,   244,   338,     6,    -1,   344,   338,   234,
     247,   235,     6,    -1,   154,     4,   232,   319,   233,     6,
      -1,   155,     4,   232,   319,   233,     6,    -1,   156,     4,
     232,   319,   239,   319,   233,     6,    -1,    -1,   247,   250,
      -1,   247,   254,    -1,   247,   257,    -1,   247,   259,    -1,
     247,   260,    -1,   319,    -1,   248,   239,   319,    -1,   319,
      -1,   249,   239,   319,    -1,    -1,    -1,     4,   251,   230,
     248,   231,   252,   234,   249,   235,     6,    -1,   338,    -1,
     253,   239,   338,    -1,    -1,   161,   230,   319,   239,   319,
     239,   319,   231,   255,   234,   253,   235,     6,    -1,   338,
      -1,   256,   239,   338,    -1,    -1,   162,   230,   319,   239,
     319,   239,   319,   239,   319,   231,   258,   234,   256,   235,
       6,    -1,   163,   234,   330,   235,   234,   330,   235,     6,
      -1,   163,   234,   330,   235,   234,   330,   235,   234,   330,
     235,   234,   330,   235,     6,    -1,    -1,   164,   261,   234,
     249,   235,     6,    -1,     7,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   228,    -1,   227,    -1,   230,    -1,
     232,    -1,   231,    -1,   233,    -1,    80,   232,   268,   233,
       6,    -1,    81,   232,   272,   233,     6,    -1,   322,     6,
      -1,    87,   264,   339,   239,   319,   265,     6,    -1,    88,
     264,   344,   239,   339,   265,     6,    -1,   344,   262,   331,
       6,    -1,   344,   263,     6,    -1,   344,   264,   265,   262,
     331,     6,    -1,   344,   264,   234,   334,   235,   265,   262,
     331,     6,    -1,   344,   232,   319,   233,   262,   319,     6,
      -1,   344,   232,   319,   233,   263,     6,    -1,   344,   230,
     319,   231,   262,   319,     6,    -1,   344,   230,   319,   231,
     263,     6,    -1,   344,     7,   339,     6,    -1,   344,   264,
     265,     7,    46,   264,   265,     6,    -1,   344,   264,   265,
       7,    46,   264,   342,   265,     6,    -1,   344,   264,   265,
     210,    46,   264,   342,   265,     6,    -1,   344,   236,     4,
       7,   339,     6,    -1,   344,   232,   319,   233,   236,     4,
       7,   339,     6,    -1,   344,   236,     4,   262,   319,     6,
      -1,   344,   232,   319,   233,   236,     4,   262,   319,     6,
      -1,   344,   236,     4,   263,     6,    -1,   344,   232,   319,
     233,   236,     4,   263,     6,    -1,   344,   236,   171,   236,
       4,     7,   335,     6,    -1,   344,   232,   319,   233,   236,
     171,   236,     4,     7,   335,     6,    -1,   344,   236,   172,
       7,   336,     6,    -1,   344,   232,   319,   233,   236,   172,
       7,   336,     6,    -1,   344,   182,     7,   319,     6,    -1,
     182,   232,   319,   233,     7,     4,     6,    -1,   182,   232,
     319,   233,   236,     4,     7,   319,     6,    -1,   182,   232,
     319,   233,   236,     4,     7,   339,     6,    -1,   182,   232,
     319,   233,   236,     4,     7,   234,   334,   235,     6,    -1,
     182,   232,   319,   233,   236,     4,     6,    -1,   127,   230,
       4,   231,   236,     4,     7,   319,     6,    -1,   127,   230,
       4,   231,   236,     4,     7,   339,     6,    -1,    -1,   239,
      -1,    -1,   268,   267,   344,    -1,   268,   267,   344,     7,
     319,    -1,    -1,   268,   267,   344,     7,   234,   331,   269,
     274,   235,    -1,    -1,   268,   267,   344,   264,   265,     7,
     234,   331,   270,   274,   235,    -1,   268,   267,   344,     7,
     339,    -1,    -1,   268,   267,   344,     7,   234,   339,   271,
     278,   235,    -1,    -1,   272,   267,   338,    -1,   319,     7,
     339,    -1,   273,   239,   319,     7,   339,    -1,   333,     7,
     344,   230,   231,    -1,    -1,   239,   276,    -1,    -1,   276,
      -1,   277,    -1,   276,   239,   277,    -1,     4,   331,    -1,
       4,    -1,     4,   234,   273,   235,    -1,     4,   339,    -1,
      -1,   239,   279,    -1,   280,    -1,   279,   239,   280,    -1,
       4,   319,    -1,     4,   339,    -1,   186,   339,    -1,     4,
     234,   342,   235,    -1,   319,    -1,   339,    -1,   339,   239,
     319,    -1,   319,    -1,   339,    -1,   339,   239,   319,    -1,
     319,    -1,   339,    -1,   339,   239,   319,    -1,   319,    -1,
     339,    -1,   339,   239,   319,    -1,    -1,   174,    93,   234,
     319,   235,    -1,    -1,   120,   328,    -1,    89,   230,   319,
     231,     7,   328,     6,    -1,    92,   230,   319,   231,     7,
     331,     6,    -1,    96,   230,   319,   231,     7,   331,     6,
      -1,    90,   230,   319,   231,     7,   331,   286,     6,    -1,
      91,   230,   319,   231,     7,   331,   286,     6,    -1,   166,
     230,   319,   231,     7,   331,     6,    -1,   167,   230,   319,
     231,     7,   331,     6,    -1,   168,   230,   319,   231,     7,
     331,   170,   331,   169,   319,     6,    -1,   124,    92,   230,
     319,   231,     7,   331,     6,    -1,   107,   230,   319,   231,
       7,   331,     6,    -1,    92,     4,   230,   319,   231,     7,
     331,     6,    -1,   120,    95,   230,   319,   231,     7,   331,
       6,    -1,    95,   230,   319,   231,     7,   331,   285,     6,
      -1,   121,    95,   230,   319,   231,     7,   331,   285,     6,
      -1,    13,    14,     6,    -1,    14,    95,   319,     6,    -1,
     110,    95,   230,   319,   231,     7,     5,     5,     5,     6,
      -1,    93,   230,   319,   231,     7,   331,     6,    -1,    94,
     230,   319,   231,     7,   331,     6,    -1,    98,   230,   319,
     231,     7,   331,     6,    -1,   101,   230,   319,   231,     7,
     331,     6,    -1,   105,   230,   319,   231,     7,   331,     6,
      -1,   106,   230,   319,   231,     7,   331,     6,    -1,    99,
     230,   319,   231,     7,   331,     6,    -1,   100,   230,   319,
     231,     7,   331,     6,    -1,   117,   230,   319,   231,     7,
     331,     6,    -1,   142,   230,   319,   231,     7,   331,     6,
      -1,   124,    95,   230,   319,   231,     7,   331,     6,    -1,
     124,    95,   230,   319,   231,     7,   331,     4,   234,   330,
     235,     6,    -1,    95,     4,   230,   319,   231,     7,   331,
       6,    -1,    97,   230,   319,   231,     7,   331,     6,    -1,
     116,   230,   319,   231,     7,   331,     6,    -1,   121,   116,
     230,   319,   231,     7,   331,     6,    -1,   124,    97,   230,
     319,   231,     7,   331,     6,    -1,   123,    89,   230,   281,
     231,   262,   331,     6,    -1,   123,    92,   230,   282,   231,
     262,   331,     6,    -1,   123,    95,   230,   283,   231,   262,
     331,     6,    -1,   123,    97,   230,   284,   231,   262,   331,
       6,    -1,   131,   328,   234,   289,   235,    -1,   130,   234,
     328,   239,   328,   239,   319,   235,   234,   289,   235,    -1,
     132,   328,   234,   289,   235,    -1,   133,   234,   328,   239,
     319,   235,   234,   289,   235,    -1,   133,   234,   328,   239,
     328,   235,   234,   289,   235,    -1,     4,   234,   289,   235,
      -1,   148,    92,   234,   334,   235,    95,   234,   319,   235,
      -1,   145,    92,   230,   319,   231,   234,   334,   235,     6,
      -1,   290,    -1,   288,    -1,    -1,   290,   287,    -1,   290,
      89,   234,   334,   235,     6,    -1,   290,    92,   234,   334,
     235,     6,    -1,   290,    95,   234,   334,   235,     6,    -1,
     290,    97,   234,   334,   235,     6,    -1,   135,   120,   230,
     319,   231,     7,   331,     6,    -1,   135,    89,   230,   319,
     231,     7,   234,   330,   235,     6,    -1,   135,   120,   230,
     319,   231,     7,   234,   328,   239,   328,   239,   334,   235,
       6,    -1,   135,   120,   230,   319,   231,     7,   234,   328,
     239,   328,   239,   328,   239,   334,   235,     6,    -1,   135,
      93,   230,   319,   231,     7,   234,   328,   239,   334,   235,
       6,    -1,   135,    99,   230,   319,   231,     7,   234,   328,
     239,   328,   239,   334,   235,     6,    -1,   135,   100,   230,
     319,   231,     7,   234,   328,   239,   328,   239,   334,   235,
       6,    -1,   135,   102,   230,   319,   231,     7,   234,   328,
     239,   328,   239,   334,   235,     6,    -1,   135,   103,   230,
     319,   231,     7,   234,   328,   239,   328,   239,   334,   235,
       6,    -1,   135,     4,   230,   319,   231,     7,   331,     6,
      -1,   135,     4,   230,   319,   231,     7,     5,     6,    -1,
     135,     4,   234,   319,   235,     6,    -1,   146,   234,   290,
     235,    -1,   129,   146,   234,   290,   235,    -1,   146,   182,
     232,   319,   233,     6,    -1,   146,     4,   232,   319,   233,
       6,    -1,   146,   344,     6,    -1,   146,     4,     4,     6,
      -1,   171,   335,   234,   290,   235,    -1,   129,   171,   335,
     234,   290,   235,    -1,   204,   319,   234,   290,   235,    -1,
     187,     5,     6,    -1,   188,     5,     6,    -1,   187,   234,
     290,   235,    -1,   129,   187,   234,   290,   235,    -1,   188,
     234,   290,   235,    -1,   129,   188,   234,   290,   235,    -1,
     344,   339,     6,    -1,    73,   230,   342,   231,     6,    -1,
     344,   344,   232,   319,   233,   338,     6,    -1,   344,   344,
     344,   232,   319,   233,     6,    -1,   344,   319,     6,    -1,
     127,   230,     4,   231,   236,     4,     6,    -1,   165,     4,
       6,    -1,   180,     6,    -1,   181,     6,    -1,    70,     6,
      -1,    71,     6,    -1,    64,     6,    -1,    64,   234,   319,
     239,   319,   239,   319,   239,   319,   239,   319,   239,   319,
     235,     6,    -1,    65,     6,    -1,    66,     6,    -1,    77,
       6,    -1,    78,     6,    -1,   112,     6,    -1,   113,   234,
     334,   235,   234,   334,   235,   234,   330,   235,   234,   319,
     239,   319,   235,     6,    -1,   185,   230,   234,   334,   235,
     239,   339,   239,   339,   231,     6,    -1,   173,   230,   319,
       8,   319,   231,    -1,   173,   230,   319,     8,   319,     8,
     319,   231,    -1,   173,     4,   174,   234,   319,     8,   319,
     235,    -1,   173,     4,   174,   234,   319,     8,   319,     8,
     319,   235,    -1,   175,    -1,   186,     4,    -1,   186,   339,
      -1,   183,    -1,   184,   344,     6,    -1,   184,   339,     6,
      -1,   176,   230,   319,   231,    -1,   177,   230,   319,   231,
      -1,   178,    -1,   179,    -1,   134,   328,   234,   290,   235,
      -1,   134,   234,   328,   239,   328,   239,   319,   235,   234,
     290,   235,    -1,   134,   234,   328,   239,   328,   239,   328,
     239,   319,   235,   234,   290,   235,    -1,    -1,   134,   328,
     234,   290,   300,   304,   235,    -1,    -1,   134,   234,   328,
     239,   328,   239,   319,   235,   234,   290,   301,   304,   235,
      -1,    -1,   134,   234,   328,   239,   328,   239,   328,   239,
     319,   235,   234,   290,   302,   304,   235,    -1,    -1,   134,
     234,   290,   303,   304,   235,    -1,   134,   234,   290,   235,
     126,   107,   234,   319,   235,    -1,   116,   331,    -1,   121,
     116,   331,    -1,   118,   234,   334,   235,   234,   334,   235,
     234,   319,   235,    -1,   305,    -1,   304,   305,    -1,   151,
     234,   319,   235,     6,    -1,   151,   234,   331,   239,   331,
     235,     6,    -1,   152,     6,    -1,   143,     6,    -1,   143,
     319,     6,    -1,   157,     6,    -1,   157,   159,     6,    -1,
     158,     6,    -1,   158,   159,     6,    -1,   153,   230,   319,
     231,     7,   331,   126,   319,     6,    -1,   126,     4,   232,
     319,   233,     6,    -1,   137,    -1,   138,    -1,   139,    -1,
     140,    -1,   141,    -1,    -1,   146,     6,    -1,   129,   146,
       6,    -1,   146,   319,     6,    -1,   129,   146,   319,     6,
      -1,   306,   234,   290,   307,   235,   234,   290,   307,   235,
      -1,   104,   230,   338,   231,    -1,   306,   230,   319,   231,
       7,   234,   290,   307,   235,   234,   290,   307,   235,     6,
      -1,    -1,   126,     4,   319,    -1,    -1,     4,    -1,    -1,
       7,   331,    -1,    -1,     7,   319,    -1,    -1,   136,   331,
      -1,   108,   109,   331,     7,   319,     6,    -1,   122,    92,
     332,     7,   319,   310,     6,    -1,   122,    95,   332,   312,
     311,     6,    -1,   122,    97,   332,   312,     6,    -1,   160,
     332,     6,    -1,   149,    95,   234,   334,   235,     7,   319,
       6,    -1,   143,    95,   332,   313,     6,    -1,   143,    97,
     332,     6,    -1,   144,    95,   332,     7,   319,     6,    -1,
     125,    92,   234,   334,   235,     7,   234,   334,   235,   314,
       6,    -1,   125,    95,   234,   334,   235,     7,   234,   334,
     235,   314,     6,    -1,   125,    92,   234,   334,   235,     7,
     234,   334,   235,   130,   234,   328,   239,   328,   239,   319,
     235,     6,    -1,   125,    95,   234,   334,   235,     7,   234,
     334,   235,   130,   234,   328,   239,   328,   239,   319,   235,
       6,    -1,   125,    92,   234,   334,   235,     7,   234,   334,
     235,   131,   328,     6,    -1,   125,    95,   234,   334,   235,
       7,   234,   334,   235,   131,   328,     6,    -1,   125,    95,
     319,   234,   334,   235,     7,   319,   234,   334,   235,     6,
      -1,    89,   234,   334,   235,   174,    95,   234,   319,   235,
       6,    -1,    92,   234,   334,   235,   174,    95,   234,   319,
     235,     6,    -1,    89,   234,   334,   235,   174,    97,   234,
     319,   235,     6,    -1,    92,   234,   334,   235,   174,    97,
     234,   319,   235,     6,    -1,    95,   234,   334,   235,   174,
      97,   234,   319,   235,     6,    -1,   150,    95,   332,     6,
      -1,   150,    92,   332,     6,    -1,   114,    89,   332,     6,
      -1,   114,    92,   332,     6,    -1,   114,    95,   332,     6,
      -1,   128,    92,   331,     6,    -1,   124,    92,   331,     6,
      -1,   124,    95,   331,     6,    -1,   124,    97,   331,     6,
      -1,   147,     6,    -1,   147,     4,     6,    -1,   147,    89,
     234,   334,   235,     6,    -1,   195,    -1,   196,    -1,   197,
      -1,   317,     6,    -1,   317,   234,   331,   235,     6,    -1,
     317,   234,   331,   239,   331,   235,     6,    -1,   317,   230,
     331,   231,   234,   331,   239,   331,   235,     6,    -1,   320,
      -1,   230,   319,   231,    -1,   221,   319,    -1,   220,   319,
      -1,   225,   319,    -1,   319,   221,   319,    -1,   319,   220,
     319,    -1,   319,   222,   319,    -1,   319,   223,   319,    -1,
     319,   224,   319,    -1,   319,   229,   319,    -1,   319,   216,
     319,    -1,   319,   217,   319,    -1,   319,   219,   319,    -1,
     319,   218,   319,    -1,   319,   215,   319,    -1,   319,   214,
     319,    -1,   319,   213,   319,    -1,   319,   212,   319,    -1,
     319,   211,   319,     8,   319,    -1,    16,   264,   319,   265,
      -1,    17,   264,   319,   265,    -1,    18,   264,   319,   265,
      -1,    19,   264,   319,   265,    -1,    20,   264,   319,   265,
      -1,    21,   264,   319,   265,    -1,    22,   264,   319,   265,
      -1,    23,   264,   319,   265,    -1,    24,   264,   319,   265,
      -1,    26,   264,   319,   265,    -1,    27,   264,   319,   239,
     319,   265,    -1,    28,   264,   319,   265,    -1,    29,   264,
     319,   265,    -1,    30,   264,   319,   265,    -1,    31,   264,
     319,   265,    -1,    32,   264,   319,   265,    -1,    33,   264,
     319,   265,    -1,    34,   264,   319,   265,    -1,    35,   264,
     319,   265,    -1,    36,   264,   319,   239,   319,   265,    -1,
      37,   264,   319,   239,   319,   265,    -1,    38,   264,   319,
     239,   319,   265,    -1,    25,   264,   319,   265,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   200,
      -1,   201,    -1,   202,    -1,    74,    -1,    75,    -1,    76,
      -1,    -1,    82,   264,   319,   321,   274,   265,    -1,   322,
      -1,   193,   264,   338,   265,    -1,   193,   264,   338,   239,
     319,   265,    -1,   324,    -1,   344,   232,   319,   233,    -1,
     344,   230,   319,   231,    -1,   198,   230,   324,   231,    -1,
     198,   230,   324,   236,   325,   231,    -1,   199,   230,   339,
     231,    -1,   237,   344,   264,   265,    -1,   237,   344,     9,
      -1,   237,     9,    -1,   344,   263,    -1,   344,   232,   319,
     233,   263,    -1,   344,   230,   319,   231,   263,    -1,   344,
     236,   325,    -1,   344,     9,   344,   236,   325,    -1,   344,
     232,   319,   233,   236,     4,    -1,   344,   236,     4,   263,
      -1,   344,   232,   319,   233,   236,     4,   263,    -1,   189,
     230,   338,   239,   319,   231,    -1,    56,   230,   331,   239,
     331,   231,    -1,    57,   264,   338,   239,   338,   265,    -1,
      55,   264,   338,   265,    -1,    58,   264,   338,   239,   338,
     265,    -1,    63,   230,   342,   231,    -1,    -1,    83,   324,
     327,   323,   232,   275,   233,    -1,   344,    -1,   344,     9,
     344,    -1,     4,    -1,    85,    -1,    85,   319,    -1,    -1,
     230,   326,   231,    -1,   329,    -1,   221,   328,    -1,   220,
     328,    -1,   328,   221,   328,    -1,   328,   220,   328,    -1,
     234,   319,   239,   319,   239,   319,   239,   319,   239,   319,
     235,    -1,   234,   319,   239,   319,   239,   319,   239,   319,
     235,    -1,   234,   319,   239,   319,   239,   319,   235,    -1,
     230,   319,   239,   319,   239,   319,   231,    -1,   331,    -1,
     330,   239,   331,    -1,   319,    -1,   333,    -1,   234,   235,
      -1,   234,   334,   235,    -1,   221,   234,   334,   235,    -1,
     319,   222,   234,   334,   235,    -1,   331,    -1,     5,    -1,
     221,   333,    -1,   319,   222,   333,    -1,   319,     8,   319,
      -1,   319,     8,   319,     8,   319,    -1,    89,   234,   319,
     235,    -1,    89,     5,    -1,    92,     5,    -1,    95,     5,
      -1,    97,     5,    -1,   123,    89,   332,    -1,   123,    92,
     332,    -1,   123,    95,   332,    -1,   123,    97,   332,    -1,
      89,   174,    64,   234,   319,   239,   319,   239,   319,   239,
     319,   239,   319,   239,   319,   235,    -1,    92,   174,    64,
     234,   319,   239,   319,   239,   319,   239,   319,   239,   319,
     239,   319,   235,    -1,    95,   174,    64,   234,   319,   239,
     319,   239,   319,   239,   319,   239,   319,   239,   319,   235,
      -1,    97,   174,    64,   234,   319,   239,   319,   239,   319,
     239,   319,   239,   319,   239,   319,   235,    -1,   288,    -1,
     299,    -1,   308,    -1,   344,   264,   265,    -1,    39,   232,
     344,   233,    -1,    39,   232,   333,   233,    -1,    39,   230,
     333,   231,    -1,    39,   264,   234,   334,   235,   265,    -1,
     344,   264,   234,   334,   235,   265,    -1,    40,   264,   319,
     239,   319,   239,   319,   265,    -1,    41,   264,   319,   239,
     319,   239,   319,   265,    -1,    42,   264,   338,   265,    -1,
      43,   264,   319,   239,   319,   239,   319,   239,   319,   239,
     319,   239,   319,   265,    -1,   194,   264,   333,   265,    -1,
      32,   264,   333,   265,    -1,   319,    -1,   333,    -1,   334,
     239,   319,    -1,   334,   239,   333,    -1,   234,   319,   239,
     319,   239,   319,   239,   319,   235,    -1,   234,   319,   239,
     319,   239,   319,   235,    -1,   344,    -1,     4,   236,   171,
     236,     4,    -1,   234,   337,   235,    -1,   344,   232,   319,
     233,   236,   172,    -1,   335,    -1,   337,   239,   335,    -1,
     339,    -1,   344,    -1,   344,   232,   319,   233,    -1,   344,
     230,   319,   231,    -1,   344,   236,   325,    -1,   344,     9,
     344,   236,   325,    -1,   344,   232,   319,   233,   236,     4,
      -1,   123,    89,   234,   319,   235,    -1,   123,    92,   234,
     319,   235,    -1,   123,    95,   234,   319,   235,    -1,   123,
      97,   234,   319,   235,    -1,     5,    -1,   205,   232,   344,
     233,    -1,    67,    -1,   203,    -1,    72,    -1,   191,   230,
     338,   231,    -1,   190,   230,   338,   239,   338,   231,    -1,
     192,   264,   338,   265,    -1,   192,   264,   338,   239,   338,
     265,    -1,    48,   264,   342,   265,    -1,    49,   230,   338,
     231,    -1,    50,   230,   338,   231,    -1,    51,   230,   338,
     239,   338,   239,   338,   231,    -1,    46,   264,   342,   265,
      -1,    60,   264,   338,   265,    -1,    61,   264,   338,   265,
      -1,    62,   264,   338,   265,    -1,    59,   264,   319,   239,
     338,   239,   338,   265,    -1,    54,   264,   338,   239,   319,
     239,   319,   265,    -1,    54,   264,   338,   239,   319,   265,
      -1,    47,   264,   338,   265,    -1,    47,   264,   338,   239,
     334,   265,    -1,    68,   264,   338,   265,    -1,    69,    -1,
      53,   264,   338,   265,    -1,    52,   264,   338,   265,    -1,
      -1,    86,   264,   339,   340,   278,   265,    -1,    84,   264,
     341,   265,    -1,   237,   319,    -1,   344,     9,   237,   319,
      -1,   338,    -1,   342,   239,   338,    -1,     4,   238,   234,
     319,   235,    -1,   343,   238,   234,   319,   235,    -1,     4,
      -1,   343,    -1,   206,   232,   338,   233,    -1
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
    5701,  5710,  5714,  5718,  5726,  5732,  5738,  5746,  5754,  5761,
    5769,  5784,  5798,  5812,  5824,  5840,  5849,  5858,  5868,  5879,
    5887,  5895,  5899,  5918,  5925,  5931,  5938,  5946,  5945,  5955,
    5979,  5981,  5987,  5992,  6000,  6009,  6022,  6025,  6029
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
     465,    63,   466,   467,   468,   469,    60,    62,   470,   471,
      43,    45,    42,    47,    37,    33,   472,   473,   474,    94,
      40,    41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   240,   241,   241,   242,   242,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   244,   244,   245,   245,
     245,   245,   245,   245,   246,   246,   246,   246,   247,   247,
     247,   247,   247,   247,   248,   248,   249,   249,   251,   252,
     250,   253,   253,   255,   254,   256,   256,   258,   257,   259,
     259,   261,   260,   262,   262,   262,   262,   262,   263,   263,
     264,   264,   265,   265,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   267,
     267,   268,   268,   268,   269,   268,   270,   268,   268,   271,
     268,   272,   272,   273,   273,   273,   274,   274,   275,   275,
     276,   276,   277,   277,   277,   277,   278,   278,   279,   279,
     280,   280,   280,   280,   281,   281,   281,   282,   282,   282,
     283,   283,   283,   284,   284,   284,   285,   285,   286,   286,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   289,   290,   290,
     290,   290,   290,   290,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   292,   292,   292,   292,
     292,   292,   293,   293,   294,   295,   295,   295,   295,   295,
     295,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     297,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   299,   299,   299,   300,   299,
     301,   299,   302,   299,   303,   299,   299,   299,   299,   299,
     304,   304,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   306,   306,   306,   306,   306,   307,   307,
     307,   307,   307,   308,   308,   309,   310,   310,   311,   311,
     312,   312,   313,   313,   314,   314,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   316,   316,   316,   317,
     317,   317,   318,   318,   318,   318,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   323,   322,
     324,   324,   325,   326,   326,   327,   327,   328,   328,   328,
     328,   328,   329,   329,   329,   329,   330,   330,   331,   331,
     331,   331,   331,   331,   332,   332,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   334,   334,
     334,   334,   335,   335,   335,   335,   336,   336,   337,   337,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   340,   339,   339,
     341,   341,   342,   342,   343,   343,   344,   344,   344
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
       0,     0,     0,     2,     3,     1,   566,     0,     0,     0,
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
       0,   567,     0,   208,     0,     0,     0,     0,     0,   252,
       0,   254,   255,   250,   251,     0,   256,   257,   111,   121,
     566,   455,   450,    70,    71,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   566,     0,
     208,     0,     0,   356,     0,     0,     0,     0,     0,     0,
       0,     0,   475,     0,   474,     0,     0,     0,     0,     0,
     566,     0,     0,   514,     0,     0,     0,     0,   248,   249,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,   554,   535,     0,
       0,     0,     0,     0,   534,     0,     0,     0,     0,   266,
     267,     0,   208,     0,   208,     0,     0,     0,   450,     0,
       0,   208,   362,     0,     0,    76,     0,    63,     0,     0,
      67,    66,    65,    64,    69,    68,    70,    71,     0,     0,
       0,     0,     0,     0,   520,   450,     0,   207,     0,   206,
       0,   174,     0,     0,   520,   521,     0,     0,   562,     0,
     109,   109,     0,   448,     0,     0,     0,     0,     0,   508,
     509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,     0,   482,     0,
     483,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   369,     0,   368,   476,   370,     0,
     470,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,   434,     0,     0,     0,     0,     0,
       0,   288,     0,   320,   320,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,     0,   208,   208,     0,   459,   458,     0,     0,     0,
       0,   208,   208,     0,     0,     0,     0,   284,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,   230,   357,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   330,
     247,     0,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   269,     0,   235,     0,   236,     0,     0,
     368,     0,   208,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    72,    73,     0,     0,   245,    38,
     241,     0,     0,     0,     0,     0,   203,     0,     0,     0,
       0,     0,     0,     0,   209,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,   453,     0,     0,   451,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   349,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   420,     0,
       0,     0,     0,     0,   485,   486,   487,   488,     0,     0,
       0,     0,     0,     0,   367,   471,   432,     0,   478,     0,
     384,   383,   382,   381,   377,   378,   380,   379,   372,   371,
       0,   373,   477,   374,   375,   376,   451,     0,     0,   452,
     437,     0,   496,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,   144,   145,     0,   147,   148,     0,   150,
     151,     0,   153,   154,     0,   353,     0,   354,     0,   355,
       0,     0,     0,     0,   352,     0,   208,     0,     0,     0,
       0,     0,   461,   460,     0,     0,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,   231,     0,     0,
     226,     0,     0,     0,   348,   347,     0,     0,     0,   367,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,     0,
       0,     0,     0,     0,   237,   239,     0,   373,     0,   568,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,   367,     0,    63,     0,     0,     0,
       0,    79,     0,    63,    64,     0,     0,   451,     0,     0,
     437,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564,    28,    26,     0,     0,     0,     0,     0,   452,
     524,    29,     0,     0,   242,   563,    74,   112,    75,   122,
     454,   456,   128,     0,     0,     0,     0,   510,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   408,   395,     0,   397,   398,   399,   400,   401,   507,
     402,   403,   404,     0,     0,     0,   499,   498,   497,     0,
       0,     0,   504,     0,   445,     0,     0,     0,   447,   126,
       0,   480,     0,     0,     0,     0,     0,   423,   506,   428,
       0,   430,   472,     0,   431,     0,     0,     0,     0,   427,
     426,   440,     0,     0,     0,     0,     0,   367,   316,   321,
     319,     0,   329,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   367,   367,     0,     0,     0,     0,   227,     0,
     238,   240,     0,     0,     0,   198,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,     0,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,   332,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,   544,     0,   551,   540,   541,   542,
       0,   556,   555,     0,     0,   545,   546,   547,   553,   560,
     559,     0,   136,     0,   536,     0,   538,   532,     0,   234,
       0,     0,   309,     0,     0,     0,   363,     0,   565,     0,
       0,     0,     0,   101,    63,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,    61,     0,    39,    40,    41,
      42,    43,     0,   427,   426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,   523,
     522,     0,     0,     0,     0,   133,     0,   129,   130,     0,
       0,     0,     0,     0,   158,   158,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,   385,
     473,   438,   436,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,   328,     0,   146,     0,   149,     0,   152,
       0,   155,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
     294,     0,   297,     0,   299,     0,   285,   291,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
     334,     0,   229,   228,   358,     0,     0,    35,    36,     0,
       0,     0,     0,   515,     0,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,   310,     0,   311,   208,     0,     0,   527,   528,   529,
     530,     0,    86,     0,     0,     0,     0,    84,    91,    93,
       0,   518,     0,    99,     0,     0,     0,     0,    81,     0,
       0,     0,     0,     0,    34,   438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
       0,   525,     0,    32,     0,     0,   113,   118,     0,     0,
     132,   135,   449,     0,    77,    78,   160,     0,     0,     0,
       0,     0,     0,   161,     0,     0,   177,   178,     0,     0,
       0,     0,   162,   190,   179,   183,   184,   180,   181,   182,
     169,     0,     0,   396,   405,   406,   407,   500,     0,     0,
       0,   443,   444,   446,   127,   421,     0,     0,     0,     0,
     442,   424,   429,   191,   439,   501,   185,     0,     0,   156,
       0,     0,   327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,     0,     0,     0,     0,   208,   208,
       0,     0,   296,   468,     0,     0,   298,   300,     0,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,     0,     0,     0,     0,   165,   166,     0,     0,
       0,     0,   102,   106,     0,   552,     0,     0,   550,     0,
     561,     0,     0,   137,   138,   558,   537,   539,     0,   308,
     312,   308,     0,   364,    85,    63,     0,     0,     0,     0,
      83,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   466,     0,   439,   243,   244,   210,   211,
     212,   213,     0,     0,     0,     0,     0,   526,     0,   114,
     119,     0,     0,   508,   509,   131,     0,     0,   159,   163,
     164,   170,     0,     0,   189,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,     0,   171,
       0,   192,   317,   194,   195,   196,   197,   168,     0,   187,
     193,     0,     0,     0,     0,     0,     0,   465,   464,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
     223,     0,     0,     0,     0,     0,     0,     0,     0,   214,
       0,     0,   331,    37,     0,   513,     0,     0,   263,   262,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
      97,   519,     0,     0,    88,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    46,    33,     0,   126,   136,     0,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   502,   503,     0,     0,     0,     0,     0,     0,
     173,     0,   324,   324,     0,   107,   108,   208,     0,   201,
     202,   286,     0,   292,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   204,     0,     0,     0,
       0,   103,   104,   543,   549,   548,     0,   139,     0,     0,
     313,     0,    92,    94,     0,   100,     0,    82,    89,    90,
      49,     0,     0,     0,     0,   467,     0,     0,     0,     0,
       0,   116,     0,   123,     0,   342,   344,   343,   345,     0,
     346,   176,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
       0,   302,     0,     0,   280,     0,   215,     0,     0,     0,
       0,     0,     0,     0,   512,   264,     0,   143,     0,   208,
     365,     0,   517,     0,    45,     0,     0,     0,    62,    47,
       0,   115,   120,   126,     0,     0,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   335,     0,     0,
     336,     0,   199,     0,   293,     0,   276,     0,   208,     0,
       0,     0,     0,     0,     0,   167,   105,   260,   308,    98,
       0,     0,     0,     0,     0,     0,   124,   125,     0,     0,
       0,     0,     0,     0,   188,     0,   339,     0,   340,   341,
     462,     0,     0,   282,   218,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,    59,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,   301,   281,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   220,   221,   222,     0,   216,   315,    50,
       0,    57,     0,   253,     0,   505,     0,     0,     0,     0,
       0,     0,   283,     0,     0,    51,     0,     0,   259,     0,
       0,     0,     0,     0,     0,   217,     0,     0,     0,     0,
     489,   490,   491,   492,     0,     0,    54,    52,     0,    55,
       0,   337,   338,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1004,   109,   110,   986,  1767,  1773,
    1257,  1459,  1913,  2054,  1258,  2019,  2078,  1259,  2056,  1260,
    1261,  1463,   399,   544,   545,  1068,   111,   720,   420,  1777,
    1923,  1778,   421,  1662,  1329,  1286,  1287,  1288,  1426,  1613,
    1614,   852,   855,   858,   861,  1510,  1500,   704,   250,   408,
     409,   114,   115,   116,   117,   118,   119,   120,   121,   251,
    1161,  1947,  2010,   889,  1157,  1158,   252,   963,   253,   125,
    1352,  1121,   850,   903,  1883,   126,   127,   128,   129,   254,
     255,  1089,   256,   725,   257,   840,   724,   423,   576,   290,
    1642,   324,   325,   259,   521,   332,  1245,  1452,   418,   414,
    1212,   946,   419,   131,   378
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1750
static const yytype_int16 yypact[] =
{
   10468,    55,    91, 10616, -1750, -1750,   -98,    32,    44,   -80,
     -30,    46,   284,   291,   303,   332,    90,   347,   363,   146,
     165,    54,  -115,  -115,   285,   193,   222,    20,   262,   280,
      21,   298,   306,   324,   330,   341,   342,   348,   358,   370,
     393,   322,   466,   459,   379,   437,   408,  5437,   426,   427,
     567,   -42,   507,   506,   520,   -62,   442,   593,   -81,   476,
     208,   208,   489,   248,   361, -1750, -1750, -1750, -1750, -1750,
     529,   141,   642,   671,    19,    56,   689,   697,   498,   762,
     809,   825,  4753,   826,   611,   612,   626,    22,    18, -1750,
     652,   669, -1750, -1750,   829,   866,   676, -1750,  1698,   698,
    4857,    27,    40, -1750, -1750, -1750,  9451,   704, -1750, -1750,
   -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750,   287, -1750, -1750, -1750, -1750,    10, -1750,
     895,   691,  4523,   444,   696,   929,  9451,  4612,  4612, -1750,
    9451, -1750, -1750, -1750, -1750,  4612, -1750, -1750, -1750, -1750,
     699,   715,   945, -1750, -1750,  5085,    54,  9451,  7945,  9451,
    9451,   731,  9451,  7945,  9451,  9451,   743,  9451,  7945,  9451,
    9451,  9451,  9451,  9451,  9451,  4612,  9451,  9451,  9451,  5665,
     751, -1750,  7945,  4753,  4753,  4753,  4612, -1750, -1750, -1750,
   -1750, -1750,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,   467,  -115,  -115,  -115,  -115,
    -115,   758,  -115,  -115,   767, -1750, -1750, -1750,  -115,    34,
      42,    52,    58,  5665,   862,   568,   776,  -115,  -115,   777,
     780, -1750, -1750, -1750,  9451,  5893,  9451,  9451,  6121,    25,
   -1750, -1750,   794, -1750,  2992, -1750, -1750, -1750, -1750, -1750,
     100,  9451,  7945,   803,   815,  6349,  4753,  4753,  4753,   816,
     818,   819,   820,  6577,  6805,  7033,   821,  8787,  1048,  5665,
     822,    22,   823,   827,   208,   208,   208,  9451,  9451,   -59,
   -1750,     3,   208,  8856,   225,   394,   824,   830,   837,   838,
     839,   840,   841,  9451,  4753,  4753,  4753,   842,    11,   844,
   -1750,  1047,  1053, -1750,   845,   846,   847,  4753,  4753,   853,
     854,   855, -1750,  9451, -1750,  1067,  1068,  9451,  9451,  9451,
     490,  9451,   856, -1750,   914,  9451,  9451,  9451, -1750, -1750,
    9451, -1750,  -115,  -115,  -115,   859,   861,   863,  -115,  -115,
    -115,  -115,  -115,  -115,  -115, -1750,  -115, -1750, -1750,  -115,
    -115,   865,   867,  -115, -1750,   860,  1090,  1093,   868, -1750,
   -1750,  1095, -1750,  1098, -1750,  -115,  9451, 11961,   155,  4612,
    9451, -1750, -1750,  5665,  5665, -1750,   873,  5085,   595,  1099,
   -1750, -1750, -1750, -1750, -1750, -1750,  9451,  9451,    47,  5665,
    1102,   -82,   909,   878,  1103,   205,   879, -1750,   880, 10818,
    9451, -1750,  1277,  -167, -1750,   132,  -134,  4050, -1750,   -32,
     187,   201,  1029, -1750,    54,   877,   896, 12332,  7945,  3038,
   -1750,   463, 12353, 12374,  9451, 12395,   465, 12416, 12437,  9451,
   12458,   473, 12479, 12500, 12521, 12542, 12563, 12584,   903, 12605,
   12626, 12647,  1129,  9451,   474,  1131,  1136,  1138,   915,  9451,
    9451,  9451,  9451,  9451,  9451,  9451,  9451,  9451,  9451,  9451,
    9451,  9451,  9451,  9451,  9451,  7945,  9451,  9451,  9451,  9451,
    9451,  9451,  7945,  7945,   913,  9451,  9451,  4612,  9451,  4612,
    5665,  4612,  4612,  4612,  9451, -1750,  1086,  9451, -1750,  1105,
   -1750,  1109, -1750,  1111,  5665,  4753,  4753,  4753,  4753,  4612,
    4612,  7945,    54,  5085,   922,  7945,   922, -1750,   922, 12668,
   -1750,   481, -1750,    64,  9451,  9451,  9451,  9451,  9451,  9451,
    9451,  9451,  9451,  9451,  9451,  9451,  7261,  9451,  9451,  9451,
      54,  9451,  9451,  1162, -1750,   509, 12689,   483,  9451,  9451,
    9451, -1750,  1160,  1169,  1169,  8564,  8564,  8564,  8564,  9451,
    1171,  9451,  1172,  9451,  1173,  7945,  7945, 11985,   949,  1178,
   -1750,   951, -1750, -1750,  -151, -1750, -1750,  4233,  4408,   208,
     208,   444,   444,  -143,  8856,  8856,  9451,  3006,  -117, -1750,
    9451,  9451,  9451,  9451,  9451,  9451,  9451,  9451,  9451, 12710,
    1179,  1181,  1182,  9451,  1184,  9451,  9451,  9600, -1750, -1750,
    7945,  7945,  7945,  1185,  1190,  9451,  9451,  9451, 12731, -1750,
   -1750, 12752, 12773, 12794,  1017,  5147, -1750,   964,  3266, 12815,
   12836,  2486,  4612,  4612,  4612,  4612,  4612,  4612,  4612,  4612,
    4612,  9451,  4612,  4612,  4612,  4612,    15,  5085,  4612,  4612,
    4612,    54, -1750, -1750,  7945, -1750,  9654, -1750,  9749,  9451,
     922,  9451, -1750,  9451,  9451,   966, 12857, 10754,   969,   486,
    9451,  1196,   970,   971,   972,   974,  9451, 12878, 12056,   147,
     967,  1202,  1205, -1750, -1750, -1750,  7945,   191, -1750, -1750,
   -1750,    54,  9451,  9451,  1162,   981, -1750,   515,    39,    45,
     524,   984,   -36,   594, -1750,  3588, -1750,    50,  7945,    54,
    9451,  9451,  1211,  1210,  7945,  9451,  1212,  4612,  1213, -1750,
      54,  1214,  4612,  9451,   986,   989, -1750,  9451,  5085,  1217,
    7945,  1051,  7945,  1219,  1220, 12899,  1221,  1055,  1223,  1226,
   12920,  1227,  1062,  1231,  1232,  1233,  1235,  1236,  1238, -1750,
    1240,  1241,  1242,  9451, 12941,  1016, -1750, -1750, -1750,  1245,
   12033, 12033, 12033, 12033, 12033, 12033, 12033, 12033, 12033, 12033,
   12033,  5375, 12033, 12033, 12033, 12033,   941,   549, 12033, 12033,
   12033,  5603,  5831,  6059,  3038,  1021,  1020,    59,  7945,  6287,
    6515,   549,  6743,   549,  1015,  1018,  1023,     8,  2660,  1022,
   10307,  1025,  1030,  1031, -1750, -1750, -1750, -1750,  1024,  -123,
     549,   159,  1035,   496,  1248, -1750, -1750,   549,  3325,  3365,
    1087,   554,   644,   644,   362,   362,   362,   362,   472,   472,
    7945,   922, -1750,   922,   922,   922,  1032, 12962, 12079,   -50,
   -1750,  7945, -1750,  1260,  1036, 12983, 13004, 13025,  9451,  5665,
    1267,  1266,  1042,  2660,  1037,  1043,  2660,  1038,  1044,  2660,
    1039,  1049,  2660,  1045, 13046, -1750, 13067, -1750, 13088, -1750,
     525,   555,  7945,  1050, -1750,  9787, -1750,  9882,  9920,   208,
    9451,  9451, -1750, -1750,  1046,  1052,  8856,  3498,  1159,   -25,
     208, 10015, 13109, 11211, 13130, 13151, 13172, 13193, 13214, 13235,
   13256,  1281,  9451,  1283, -1750,  9451, 13277, -1750, 12102, 12125,
   -1750,   556,   558,   579, -1750, -1750, 12148, 12171,  6971, -1750,
    1285,  1287,  1289,  1054,  9451, 10053,  9451,  9451, -1750, -1750,
      41,   244,   311,   244,  1081,  1083,  1059,   549,   549,  1078,
    7199,   549,   549,   549,   549,  9451,   549,  1309, -1750,  1082,
    1089,   325,  1094,   580, -1750, -1750, 12033,   922, 10148, -1750,
    1315,  1186,  9085,  1107,  1096,  1337,  5665, 11236, -1750,  9451,
    9451,  9451,  9451,  1319,   286,   116,  5085,  9451,  1338,  1344,
      51, -1750,   585,  1303,  1304,  5665,    23,  1116, 13298, 12194,
    1122,  9451,  7945,  7945,  7945,  7945,  9451,  1128,  1132,  1133,
    1134, -1750, -1750,  1148,  4612,   108,  1130, 13319, 12217, -1750,
   -1750, -1750,   111,  7427, -1750, -1750, -1750,    74, -1750, -1750,
    2660, -1750,  1363, 12033,   549,   208,   655,  3038, -1750,  5665,
    5665,  1361,  5665,   760,  5665,  5665,  1362,  5665,  1273,  5665,
    5665,  5665,  5665,  5665,  5665,  5665,  5665,  5665,  1610,  1365,
    7945, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750,  9451, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750,  9451,  9451,  9451, -1750, -1750, -1750,   586,
    9451,  9451, -1750,  9451, -1750,  5665,  4612,  4612, -1750,  1135,
    9451, -1750,  9451,  9451,  9451,  9451,  9451, -1750, -1750, -1750,
    1211, -1750, -1750,  5665, -1750,  9451,  9451,   587,  1211,   -50,
    -186, -1750,   597,  5665,  7945,  1366,  1368,  1370,   801, -1750,
   -1750,  1372, -1750,   206,  9451,   206,  9451,   206,  9451,   206,
    9451,  1373,  1374,  1375,  1376,  1377,   598,  1381, -1750, 10186,
   -1750, -1750,  -109,  7655,  7883, -1750, -1750, 11261,  -121,  1279,
    1384,  9159,  1155,  1385,  1163,    29,    61,   468, -1750,   -96,
   -1750,   -25,  1383,  1386,  1387,  1389,  1392,  1393,  1394,  1395,
    1396,  5665,  2660, -1750,  1647,  1170,  1399,  1400,  1402,  1314,
    1403,  1405,  1406,  9451,  5665,  5665,  5665,  1411,  8195, -1750,
    3412,  1215,  1412,  1413, -1750,  7945, -1750, -1750, -1750, -1750,
    4612, -1750, -1750,  9451,  4612, -1750, -1750, -1750, -1750,  2660,
   -1750,  1188,  1180,  4612, -1750,  4612, -1750, -1750,  1183, -1750,
    1187,  9382, -1750,  1804,  1189,  5665, -1750,  1206, -1750, 11286,
   11311, 11336, 11361, -1750, -1750,  9451,  1434,    62,  9451,  1436,
    1437,  1946, -1750,  1438,    22,  1442,  1218,   549,  -115,  -115,
    1443, -1750,  1222,  1228,  1229, -1750,  1445, -1750, -1750, -1750,
   -1750, -1750,  1211,  -152,   143, 12240,   605,   608,   613,   614,
   13340,  9451,  9451,  9451,  9451, -1750,  1450,    88,  1211, -1750,
    1224,  1451,  9451,  8168,   549,  4020,  1234,  1225, -1750,  1455,
    1456,    87,  1237,  1239,  1298,  1298,  5665,  1460,  1247,  1249,
    1462,  1463,  5665,  1296,  1250,  1466,  1468,  1469,  1470,  1479,
    1481,  1496,  1497,  1498, -1750,  1500,   619, 12033, 12033, 12033,
   12033,   549,  8507,  8617,  8686,  1276,   549,   549,  1363,   549,
    8729,  8814,  8915,  8989, 13361, 12033,  1278,  1502,  2660,  2660,
   -1750, -1750, -1750,  1506, -1750,   549,  1507,   635,  5665,  5665,
    5665,  1508,  1509, -1750,  5665,  2660,  5665,  2660,  5665,  2660,
    5665,  2660,  5665,  5665,  5665,  1284,  1286,  1510,   402, -1750,
    9451,  9451,  9451,  1288,  1290,  1292,  1291, -1750,  1966,  5665,
   -1750,  9451, -1750,  1522, -1750,  1523, -1750, -1750,  8856,   501,
    4981, -1750,  1310,  1311,  1312,  1313,  1316,  1317,  7489,  1543,
   -1750,  7945, -1750, -1750, -1750,  1318,  9451, -1750, -1750, 12263,
    1547,  1548,  1390, -1750,  9451,  9451,  9451, -1750,  1549,   464,
     383,  1320,  2016,  1322,  9451,    36,   549,  1325,   549,  5085,
   -1750, -1750,  2057, -1750, -1750,  1323,  1557, -1750, -1750, -1750,
   -1750,  2113, -1750,   338,  1328,  1561,  2371, -1750, -1750, -1750,
      22, -1750,   636, -1750,  9451,   206,   872,  4612, -1750,  1339,
    9451,  9451,  5665,  1336, -1750,  1340,  1567,  1566,  1575,  1576,
    1577,  1578,  1579,  1248, 13382, 13403, 13424, 13445, -1750, -1750,
    4612, -1750,  1569, -1750,  9032,  4295,  2660, -1750,  1580,  6121,
   -1750, -1750, -1750,  1363, -1750, -1750, -1750,  9451,  9451,   208,
    1582,  1583,  1585, -1750,  9451,  9451, -1750, -1750,  1586,  1501,
    1587,  9451, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750,  1592,  1364, -1750, -1750, -1750, -1750, -1750,  9451,  9451,
    9451, -1750, -1750, -1750,  1225, -1750,  9451,  9451,  9451,  9451,
   -1750, -1750, -1750, -1750,   -50, -1750, -1750,  1367,  1593,  1296,
    1594,  9451, -1750,  1596,  1598,  1599,  1601,  1602,   875,  1603,
    7945,  7945,  9451, -1750,  8564, 11386, 13466,  3558,   444,   444,
    9451,  9451, -1750,   588,  1378, 13487, -1750, -1750, 11411,   -83,
   -1750,  1612,  1615,  5665,   208,   208,   208,   208,   208,  5209,
    1616, -1750,   645,  9451,  2447,  1617, -1750, -1750,  5665,  3718,
     674, 13508, -1750, -1750,  8252, -1750,  4612,  9451, -1750,  4612,
    2660,  8480,  5085,  1388, -1750, -1750, -1750, -1750,  1397, 10754,
   -1750, 10754,  5665, -1750, -1750,  5085,  9451,  1618,  1621,    51,
   -1750,  1622, -1750,    22, 12286,  5665,  1623,   244,   244,  9451,
    9112,  9212,   665, -1750,  9451,   -61, -1750, -1750, -1750, -1750,
   -1750, -1750,  1370,  1373,  1374,  1375,  1625, -1750,  9451, -1750,
   -1750,  1401,   667,  1829,  1627, -1750, 11436, 11461,   279, -1750,
   -1750, -1750, 11486, 11511, -1750,  1404, -1750, 11536,  1634,  5665,
   12033, 12033,  9281,  9324,  9409,  9568,  9727, -1750,  9451, -1750,
    1635, -1750,  2660, -1750, -1750, -1750, -1750, -1750,  1415, -1750,
   -1750,   672,   675, 12009,  2509,  1639,  1417, -1750, -1750,  9451,
    1420,  1426, 11561, 12309,  1640,  5665,  1655,  1429,  9451, -1750,
   -1750,   678,   101,   168,   173,   183,   185,  7717,   197, -1750,
    1641, 11586, -1750, -1750,  1495, -1750,  9451,  9451, -1750, -1750,
    7945,  2602,  1659,  1435, 12033,   549,  4612,  2660, -1750, -1750,
      36,  5085,  1432,  1433,  1439,  1663,  2641, -1750,  1664,  1666,
   -1750, -1750,  1441,  1669, -1750,  1672,  1673,   153,  2660,  9451,
    9451,  1446,  5665,   703,  2660, -1750,  9860,  1135,  1180,  5665,
   -1750,  9451,  5085,    54,  1675,  1676,  1677,  1679,  9451,  1680,
    1681,   708, -1750, -1750,  9451,  9451,  9451,  9451,  9451, 11611,
   -1750,  5665,   236,   519,  7945, -1750, -1750,   444,  3958, -1750,
   -1750, -1750,  1682, -1750,  1454,  5665, -1750, 11636,  1684,  7945,
     208,   208,   208,   208,   208, -1750, -1750,  9451, 11661, 11686,
     711, -1750, -1750, -1750, -1750, -1750,   713, -1750,  1464,  1457,
   -1750,  1687, -1750, -1750,    22, -1750,  1524, -1750, -1750, -1750,
   -1750,  9451,  9993, 10126,  5665, -1750,  1688,  9451,  9451,  1465,
    1471, -1750,  2564, -1750,  1440, -1750, -1750, -1750, -1750, 11711,
   -1750, -1750,  1467, 10278, 10732, 10776, 10805, 10834, -1750,   716,
    1473,   208,  5665,  1692,  1474,   208,  1693,   718,  1475, -1750,
    9451, -1750,  1699,  1588, 10281,  1477, -1750,   725,   223,   235,
     237,   246,   277,  2682, -1750, -1750,  1703, -1750,  1707, -1750,
   -1750,  1709, -1750,  1483,  2660,  9451,  9451,   727, -1750,  2660,
   10863, -1750, -1750,  1135,  5085,  1487, -1750,  9451,  9451,  9451,
    9451,  9451,  9451,  1713,   208,    92, -1750, -1750,   208,    96,
   -1750,  1714, -1750, 11736, -1750,  9451, -1750,   -25, -1750,  1715,
    7945,  7945,  7945,  7945,  7717, -1750, -1750, -1750, 10754, -1750,
    9451, 13529, 10892,    48,  9451,  1488, -1750, -1750, 10921, 10950,
   10979, 11008, 11037, 11066, -1750,   304, -1750,   310, -1750, -1750,
   -1750,  2761,   581, 10319, -1750,   732,   735,   737,   740,   314,
     745,  1490,   748, -1750,  9451, -1750,  5665, 11761, -1750,  9451,
    9451,  9451,  9451,  9451,  9451,   208,   208, -1750, -1750, -1750,
     -25,  1716,  1720,  1721,  1722,  7945,  1723,  1724,  1725,  1499,
   13550,   761,  1726, 11786, 12033, 11095, 11124, 11153, 11182,   318,
     331,   604, -1750, -1750, -1750, -1750,   763, -1750, -1750, -1750,
    4612, -1750,  1504, -1750,  1728, -1750,  9451,  9451,  9451,  9451,
    9451,  9451, -1750,  1729,   764, -1750,  1505,  5665, -1750, 11811,
   11836, 11861, 11886, 11911, 11936, -1750,  1730,  4612,  4612,   769,
   -1750, -1750, -1750, -1750,  1734,  1735, -1750, -1750,   770, -1750,
    1736, -1750, -1750,  1747,  4612, -1750, -1750, -1750
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1750, -1750, -1750, -1750,   477, -1750, -1750, -1750, -1750,  -256,
   -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750,  -676,  -124,  3633,  1981, -1750,  1334, -1750, -1750,
   -1750, -1750, -1750, -1750, -1749, -1750,   433,   269,   -15, -1750,
      14, -1750, -1750, -1750, -1750,   219,   478,  1768,    -2,  -575,
    -289, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,  1769,
   -1750, -1750, -1750, -1750, -1151, -1148,  1771, -1607,  1772, -1750,
   -1750, -1750,  1243, -1750,   -26, -1750, -1750, -1750, -1750,  1964,
   -1750, -1750,  1778, -1750,    -1,  -681, -1750, -1750,    26, -1750,
   -1566,   294,  -147,   583,  2456,  -279,   154, -1750,    31,   231,
   -1750, -1750,  -488, -1750,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -527
static const yytype_int16 yytable[] =
{
     132,   113,   571,   977,   587,   797,   884,   885,   400,  1387,
    1389,   985,  1752,   990,  1753,   604,   382,  1721,   152,   150,
     151,   607,   334,   308,   161,   166,   330,  1251,  1859,   150,
     276,  1010,   371,   277,   522,  1382,   455,   456,   457,   495,
    1611,   394,   395,   161,   260,   373,   135,   498,  1192,   166,
    1343,   679,   139,   264,  1995,   150,  1002,   500,   150,   264,
     312,     4,   313,   502,   707,   280,  1443,  1384,   540,   579,
     580,   311,   708,   816,   265,   394,   395,   579,   580,   260,
     997,  1283,  -523,   656,   333,   658,   289,   291,   879,   294,
     281,     5,   667,  1496,  1479,   367,   886,   713,  1976,   579,
     580,  1150,  1978,   579,   580,   714,   282,   283,   684,   540,
     685,   579,   580,  1791,  1374,   153,  1096,   154,  1151,   552,
     553,   554,   890,  1234,   579,   580,  1152,  1153,  1154,   405,
    1370,   407,  1155,  1156,   415,   415,   133,   579,   580,   136,
     134,   709,   415,  1388,   931,   314,   933,   150,   341,   684,
     137,   685,   686,   426,   976,   260,  1718,   600,   601,   602,
     260,   579,   580,   403,   540,   260,   394,   395,   413,   416,
     613,   614,   415,  -526,  1965,   581,   260,   394,   395,   260,
     260,   260,   260,   415,  1252,  1253,  1254,  1255,  1383,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   983,   716,
     138,   309,   351,   352,   353,   354,   448,   717,   496,   150,
     355,   356,   357,  1234,   691,   358,   499,   458,   680,   681,
    1385,   107,  1612,   579,   580,   107,   501,   359,   107,   360,
     260,   107,   503,  1444,  1445,  1879,   304,   582,   305,  1088,
     383,  1387,   260,   605,   384,   260,   523,   717,   335,   134,
     162,   167,   945,   310,   163,   168,   331,   107,  1256,   260,
     107,   372,   260,   260,   260,   260,   388,  1003,   497,   162,
     260,   260,   260,   993,   374,   167,   260,  1193,   333,   994,
     140,   875,  1996,   877,   878,  1244,   394,   395,  1917,   541,
     141,   542,  1078,  1234,   153,   543,   154,   142,  1235,  1238,
     891,   260,   260,   260,   153,  1003,   154,   579,   580,   143,
     574,   575,   579,   580,   260,   260,   579,   580,   583,   588,
     145,   579,   580,   390,   391,   392,   393,   394,   395,   366,
     541,   370,   542,   361,   362,   363,   543,   925,   144,  1277,
    1819,   258,  1281,   394,   395,  1625,   364,   732,   365,   107,
     732,  1991,  1237,   146,   390,   391,   392,   393,   804,   805,
     806,   807,   710,   404,   711,   295,  1880,  1881,   712,   147,
     394,   395,  1882,   958,   394,   395,   415,  -522,   148,  1466,
     260,   260,   394,   395,  1850,   663,   425,   664,   579,   580,
    1099,   543,  1851,   579,   580,  1100,   260,   149,   390,   391,
     392,   984,   695,   579,   580,   579,   580,  1820,  1563,  1564,
     665,   107,  1821,   390,   391,   392,   393,   579,   580,  1336,
     718,   726,  1822,   159,  1823,   260,   719,  1341,   285,   286,
    2021,   179,   394,   395,   721,   692,  1824,   693,   287,  -521,
     719,   694,   288,   579,   580,   579,   580,  1354,   406,  1356,
     296,  1358,   160,  1360,   297,   579,   580,   579,   580,   589,
     298,   299,  1950,   300,   301,   181,   579,   580,   285,   286,
    1603,  1604,   260,   452,  1951,   684,  1952,   685,   287,   260,
     787,   302,   293,   717,   415,  1953,   415,   260,   415,   415,
     415,  2069,   164,   390,   391,   392,   393,   579,   580,   579,
     580,   260,   260,   260,   260,   260,   415,   415,   260,   152,
     165,   811,   260,   394,   395,   157,  1954,   380,   791,   158,
     793,   381,   795,   796,   579,   580,   183,   258,   169,   184,
     579,   580,   185,   260,   579,   580,   170,   836,   579,   580,
     808,   809,   684,  2005,   685,   390,   391,   392,   393,  2006,
    1195,   579,   580,  2015,   171,   978,   684,  2050,   685,   551,
     172,   180,   260,   260,  1215,   394,   395,   560,   562,   564,
    2051,   173,   174,   569,    59,    60,    61,    62,   175,   407,
     407,  1465,   534,   535,   661,   537,   538,  1139,   176,    73,
     317,   539,    76,   318,  1150,   269,   524,  1481,   270,   266,
     177,   271,   267,   272,   268,   882,   883,   260,   260,   260,
     575,  1151,   273,   182,   684,   274,   685,   275,   671,  1152,
    1153,  1154,   732,   178,   590,  1155,  1156,  1150,   591,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   186,   415,
     415,   415,   415,   947,  1151,   415,   415,   415,   952,  1884,
    1885,   260,  1152,  1153,  1154,  1882,   261,   505,  1155,  1156,
     506,   262,   263,   507,   932,   508,   934,   935,   936,   937,
     938,   939,   278,   941,   942,   943,   944,   668,   669,   949,
     950,   951,  1737,   260,   672,   279,   998,   673,   987,   999,
     674,  1000,   675,   682,   661,   537,   538,   482,   731,   483,
     737,   539,   732,  1386,   732,   260,  1006,  1150,   742,   755,
     284,   260,   732,   732,   415,  1111,   815,  1017,   844,   415,
     732,   965,   732,   292,  1151,   966,   624,   260,   134,   260,
    1150,  1102,  1152,  1153,  1154,   732,  1580,   306,  1155,  1156,
     684,   430,   685,   841,   812,   157,   430,  1151,  1015,   992,
    1292,   430,  1293,  1019,   170,  1152,  1153,  1154,   995,   303,
    1134,  1155,  1156,   307,   732,   430,   319,  1626,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,  1635,
     684,   315,   685,   539,   794,   260,   854,   857,   860,   863,
    1135,  1178,   316,  1179,   732,   732,  1982,   732,   551,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   320,  1180,  1218,  2008,   539,   732,   732,
    1247,  1321,  1340,  1714,   732,   732,   732,   260,   517,   321,
     326,   430,  1345,  1367,  1387,   338,   732,   732,   260,  2052,
    1469,   327,   328,  1470,   732,   430,   260,   732,  1471,  1472,
    1236,  1239,   732,   732,  1522,  1298,   329,  1299,   732,  2031,
     530,   531,   532,   533,   534,   535,   661,   537,   538,   260,
    1547,  1632,   339,   539,   732,  1633,   150,   341,   948,  1698,
    1730,  1699,   336,  1387,   732,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,   337,
    1771,   385,  1780,   539,  1772,  1142,  1781,  1802,   340,  1738,
    1803,   732,  1148,  1818,   732,   688,  1159,  1772,   342,   343,
     344,   345,   346,   347,   348,   349,   350,  1351,   368,   386,
     410,   351,   352,   353,   354,   411,   379,   134,  1856,   355,
     356,   357,  1857,  1872,   358,   422,  1906,  1772,  1907,   524,
     732,  1933,   717,  1941,   424,  1772,   359,   732,   360,  1024,
    1949,   434,  1963,   260,   732,  1451,  1772,  2011,  1637,  1638,
    2012,   732,  2013,   439,   732,  2014,   732,  1246,   504,   732,
    2016,   453,   260,  2018,   732,  1342,  1344,  1857,   490,   260,
     260,   260,   260,  1710,  1711,   388,  2042,   493,  2053,  2066,
    1772,   415,   732,  2067,  2080,  2083,   509,   512,  1772,  2084,
     513,   517,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,   260,   260,   381,   260,
     539,   260,   260,   548,   260,  1276,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   549,   555,   260,   556,   557,
     558,  1291,   568,   608,   592,   565,   570,   572,   777,   609,
     593,   573,   361,   362,   363,   785,   786,   594,   595,   596,
     597,   598,   603,   619,   620,   364,   606,   365,   107,   610,
     611,   612,   260,   415,   415,   615,   616,   617,   627,   635,
     626,   636,   651,   637,   810,   648,   652,   649,   430,   653,
     260,   655,   654,   684,   657,   685,   676,   670,   683,   690,
     260,   260,   689,   133,   723,   696,   727,  1326,  1327,   832,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,   749,   728,   753,   756,   539,  1342,
    1344,  1619,   757,  1119,   758,  1621,   759,   788,   430,   430,
     799,   539,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   730,   537,   538,   839,   848,   260,   801,
     539,  1631,   684,   802,   685,   803,   849,   865,   867,   869,
     873,   260,   260,   260,   874,   876,   902,   904,   923,   905,
     907,   914,   260,   430,   430,   430,   915,   415,   926,   959,
     964,   415,   968,   979,   969,   970,   971,  1240,   972,   980,
     415,   981,   415,   991,   996,  1009,  1011,  1021,  1014,  1016,
    1018,  1022,   260,  1416,  1025,  1026,  1029,  1030,  1032,  1033,
    1034,  1421,  1888,  1035,  1037,  1423,  1038,   430,  1039,  1040,
    1041,   333,  1042,  1043,  1427,  1044,  1428,  1045,  1046,  1047,
    1050,  1051,  1076,  1077,  1085,  1103,  1090,  1086,  1836,  1092,
    1227,   415,  1087,  1095,  1093,  1094,  1101,  1113,  1108,   430,
    1114,  1120,  1122,  1123,  1125,  1127,  1124,  1126,  1128,  1250,
    1129,  1145,   260,   706,  1130,  1149,  1137,  1146,  1171,  1173,
    1187,   430,  1184,   260,  1185,  1467,  1186,   430,  1200,   260,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,  1198,   832,  1199,  1028,   539,  1203,  1211,  1627,
    1214,  1213,  1220,  1294,  1295,  1233,  1297,  1217,  1300,  1301,
    1225,  1303,  1221,  1305,  1306,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1224,  1226,  1242,   260,   260,   260,  1243,  1248,
    1249,   260,  1262,   260,  1761,   260,  -524,   260,  1271,   260,
     260,   260,  1272,  1273,  1274,  1275,  1278,  1285,  1296,  1302,
    1304,   430,  1315,  1348,  1328,  1349,   260,  1350,  1353,  1325,
    1362,  1363,  1364,  1365,  1366,  1368,  1375,   260,  1376,  1379,
    1390,  1380,  1391,  1381,  1392,   260,  1393,  1337,   260,  1394,
    1395,  1396,  1397,  1398,  1401,  1402,  1403,  1346,  1404,  1405,
    1406,  1407,  1408,   430,  1579,  1413,  1418,  1419,  1499,  1425,
    1687,  1430,  1429,  1434,   430,  1424,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
    1442,  1436,  1447,  1448,   539,  1450,  1417,   333,  1453,  1458,
    1454,  1464,  1460,   415,   415,   430,  1478,  1483,  1461,   260,
    1482,  1494,  1495,  1462,  1493,  1399,  1503,  1492,  1506,  1507,
    1509,  1497,  1512,  1498,  1513,  1514,  1515,   415,  1410,  1411,
    1412,  1504,   260,  1505,  1511,  1516,   260,  1517,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,  1518,  1519,  1520,  1521,   539,  1531,  1543,  1542,
    1544,  1656,  1551,  1546,  1487,  1552,  1491,  1562,  1560,  1435,
    1561,  1687,  1568,  1571,  1569,  1668,  1570,  1894,  1576,  1577,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,  1583,  1584,  1585,  1586,   539,  1591,
    1587,  1588,  1593,  1596,  1597,  1602,  1616,   260,   260,  1606,
    1598,  1609,  1622,  1623,  1628,  1911,   407,   407,  1629,  1639,
    1644,  1645,  1646,  1657,  -525,   430,   430,   430,   430,  1490,
     260,  1647,  1648,  1649,  1650,  1651,   260,  1661,  1669,  1670,
    1502,  1671,  1674,  1676,  1675,   260,  1508,  1678,  1679,  1689,
    1691,  1688,  1693,   415,  1694,  1695,   415,  1696,  1697,  1700,
    1722,  1723,  1724,  1725,  1726,  1728,  1314,  1715,  1719,   260,
    1958,  1720,  1729,  1733,  1757,  1758,  1246,  1750,  1760,  1764,
     333,  1775,   260,   430,  1783,  1779,  1751,  1743,  1788,  1790,
    1745,  1800,  1548,  1549,  1550,  1806,  1813,  1825,  1553,  1801,
    1554,  1807,  1555,  1400,  1556,  1809,  1557,  1558,  1559,  1983,
    1618,  1810,  1815,  1816,  1827,  1832,  1833,  1839,  1840,  1842,
    1925,  1844,  1845,  1574,  1841,  1847,   260,  1846,  1848,  1849,
    1854,  1865,  1866,  1867,  1582,  1868,  1870,  1871,  1891,  1892,
    1896,  1909,  1590,  1910,  1918,  1908,  1912,   430,  1937,  1940,
    1921,  1927,   150,   341,  1992,  1944,  1922,  1934,  1938,  1956,
    1942,  1948,   260,  1957,  1945,  1959,  1660,  1960,  1967,  1974,
    1979,  1984,  2032,  1998,   260,  2017,  2033,  2034,  2035,  2037,
    2038,  2039,  2043,  2040,  2058,  2065,  2076,   260,  2057,  2068,
    2081,  2082,  2085,   415,   342,   343,   344,   345,   346,   347,
     348,   349,   350,  2086,  1480,   722,  1643,   351,   352,   353,
     354,  1534,  1665,  1860,  1837,   355,   356,   357,  1690,   260,
     358,   112,   122,  1501,   123,   124,   260,  1886,   430,  1659,
    1864,   130,   359,  1759,   360,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1705,     0,   851,   260,     0,
       0,   260,     0,     0,     0,   407,     0,     0,     0,     0,
    1433,     0,   260,     0,     0,     0,   260,     0,     0,     0,
       0,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,  1742,  1782,   524,     0,   539,
       0,   333,  1748,  1749,     0,     0,  1898,  1899,  1900,  1901,
    1902,   260,     0,     0,     0,     0,  1755,     0,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,  1643,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   361,   362,
     363,     0,  1734,     0,     0,     0,     0,     0,     0,     0,
       0,   364,     0,   365,   107,     0,     0,  1935,     0,     0,
       0,  1939,     0,     0,     0,     0,  1754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1763,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   260,   260,
     260,   260,  1449,     0,     0,     0,     0,     0,     0,     0,
    1975,     0,     0,     0,  1977,     0,     0,     0,     0,     0,
       0,     0,  1572,  1643,     0,     0,     0,     0,     0,     0,
    1989,     0,  1838,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1814,
       0,     0,   260,  1863,     0,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,  2029,  2030,   539,     0,     0,     0,   415,     0,     0,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   730,   537,   538,   260,     0,     0,     0,   539,     0,
       0,     0,     0,  1620,   415,   415,  1855,     0,     0,     0,
     377,  2055,  1664,  1861,     0,     0,     0,     0,     0,     0,
       0,   415,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1643,   402,     0,  2077,  2079,
     412,     0,     0,     0,   417,     0,     0,     0,     0,  1893,
       0,     0,     0,     0,     0,  2087,     0,     0,     0,  1624,
       0,   427,   429,   432,   433,     0,   435,   429,   437,   438,
       0,   440,   429,   442,   443,   444,   445,   446,   447,     0,
     449,   450,   451,   430,   430,     0,   429,     0,  1643,     0,
       0,     0,     0,     0,     0,  1966,     0,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,   430,     0,     0,   539,  1936,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   514,   516,
     518,   519,   429,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   546,   429,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,   567,     0,     0,     0,   539,     0,   684,     0,   685,
       0,   577,   578,     0,     0,  1607,     0,   578,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   599,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,   618,     0,     0,
    1643,   621,   622,   623,     0,   625,     0,     0,     0,   628,
     629,   630,     0,     0,   631,     0,     0,     0,     0,     0,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   430,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
     660,     0,   539,     0,   666,     0,     0,     0,     0,     0,
       0,  1643,     0,     0,     0,     0,     0,     0,     0,     0,
     677,   678,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   705,     0,     0,  1630,     0,     0,
       0,     0,   687,     0,     0,     0,     0,   430,     0,     0,
       0,     0,   516,     0,     0,     0,     0,     0,   735,     0,
       0,     0,   430,   740,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   754,     0,     0,
       0,     0,     0,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     778,   779,   780,   781,   782,   783,   784,   784,     0,   789,
     790,     0,   792,  1732,     0,     0,     0,     0,   798,     0,
       0,   800,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   784,     0,     0,     0,   429,
       0,     0,     0,     0,     0,     0,     0,     0,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     831,   833,   834,   835,     0,   837,   838,     0,     0,     0,
       0,     0,   845,   846,   847,  1805,     0,     0,     0,   853,
     856,   859,   862,   864,     0,   866,   842,   868,     0,   429,
     429,     0,     0,   430,   430,   430,   430,   430,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   514,   660,
     887,     0,     0,     0,   892,   893,   894,   895,   896,   897,
     898,   899,   900,     0,     0,     0,     0,   906,     0,   908,
     909,  1924,     0,     0,   429,   429,   429,     0,     0,   916,
     917,   918,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,   430,     0,
     539,     0,     0,     0,     0,   940,     0,     0,  1831,     0,
       0,     0,     0,     0,   431,     0,     0,     0,   429,   436,
       0,     0,     0,   956,   441,   957,     0,   837,   838,     0,
       0,     0,     0,     0,   967,     0,     0,     0,   454,     0,
     973,     0,     0,     0,     0,     0,     0,  1843,     0,     0,
     429,     0,     0,     0,     0,     0,   988,   989,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,   429,     0,  1007,  1008,   539,     0,   429,  1013,
       0,     0,     0,     0,     0,     0,     0,  1020,  1955,     0,
       0,  1023,     0,     0,   831,     0,  1027,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,  1048,   547,   930,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,   429,  1064,  1065,  1066,  1067,     0,  1069,  1070,
    1071,  1072,     0,     0,     0,     0,     0,  2007,     0,     0,
       0,     0,  1082,     0,  1084,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
    1097,  1098,     0,   539,   429,     0,     0,     0,  1104,     0,
       0,     0,     0,     0,     0,   429,     0,     0,     0,     0,
       0,     0,  1118,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,   429,     0,     0,     0,
       0,     0,     0,     0,  1143,  1144,     0,     0,     0,     0,
    1147,     0,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,  1172,     0,     0,  1174,
     539,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,  1188,   539,
    1190,  1191,     0,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,  1209,
       0,   539,  1194,  1196,  1197,     0,     0,     0,  1201,  1202,
       0,     0,  1205,  1206,  1207,  1208,  1223,  1210,     0,     0,
       0,     0,  1216,  1229,  1230,  1231,  1232,     0,     0,     0,
       0,  1241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1265,   429,   429,   429,   429,
    1270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   813,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,     0,     0,     0,  1289,  1290,     0,     0,     0,     0,
       0,     0,     0,     0,   429,     0,     0,     0,     0,     7,
       8,   870,   871,     0,     0,     0,     0,  1317,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1318,  1319,  1320,
       0,     0,     0,     0,  1322,  1323,   524,  1324,     0,     0,
       0,     0,     0,     0,  1330,     0,  1331,  1332,  1333,  1334,
    1335,     0,     0,     0,     0,     0,   911,   912,   913,  1338,
    1339,     0,     0,     0,     0,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1355,     0,
    1357,     0,  1359,     0,  1361,   697,    25,    26,   698,    28,
      29,   699,    31,   700,    33,    34,    35,    36,     0,     0,
     953,    38,    39,    40,     0,  1378,    42,     0,     0,     0,
       0,     0,   701,    48,     0,     0,    50,   702,     0,    53,
     703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   982,     0,     0,     0,     0,  1409,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,  1005,     0,     0,  1422,     0,     0,
    1012,     0,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1432,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1441,
       0,     0,  1446,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,  1455,     0,
       0,     0,     0,     0,     0,  1474,  1475,  1476,  1477,     0,
       0,   888,     0,     0,  1079,     0,  1484,  1486,     0,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     730,   537,   538,     0,     0,  1488,     0,   539,     0,     0,
       0,     0,     0,     0,   927,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,  1523,  1524,
    1525,  1526,  1527,     0,     0,     0,     0,  1532,  1533,     0,
    1535,     0,     0,     0,     0,     0,  1541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1545,     0,  1136,     0,
       0,     0,     0,  1105,  1565,  1566,  1567,     0,     0,     0,
       0,     0,     0,  1573,     0,  1575,     0,     0,     0,     0,
       0,     0,  1578,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   429,     0,     0,     0,     0,
    1594,     0,     0,  1106,     0,     0,     0,     0,  1599,  1600,
    1601,     0,     0,     0,     0,     0,     0,     0,  1610,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1605,     0,  1608,     0,     0,     0,  1615,     0,  1617,
       0,     0,     0,     0,     0,     0,     0,     0,  1634,     0,
    1415,     0,     0,     0,  1640,  1641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1636,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1266,  1267,
    1268,  1269,     0,  1663,     0,     0,     0,     0,     0,     0,
       0,  1666,  1667,     0,     0,     0,     0,     0,  1672,  1673,
       0,     0,     0,     0,     0,  1677,     0,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,  1680,  1681,  1682,   539,     0,     0,     0,     0,
    1683,  1684,  1685,  1686,     0,     0,  1316,     0,     0,     0,
       0,     0,     0,     0,     0,  1692,     0,     0,     0,     0,
       0,     0,     0,     0,   429,   429,  1703,     0,  1704,     0,
       0,     0,     0,     0,  1712,  1713,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,   429,   539,     0,     0,  1731,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1741,     0,
    1347,  1744,     0,     0,     0,  1747,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
    1756,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,  1768,     0,     0,     0,     0,  1774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1765,  1766,
       0,     0,  1776,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1420,  1799,     0,     0,   155,   156,     0,     0,     0,
       0,  1792,  1793,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1808,     0,     0,     0,     0,     0,     0,
       0,     0,  1817,     0,     0,     0,     0,     0,     0,     0,
       0,   516,     0,     0,     0,     0,     0,     0,     0,     0,
    1828,  1829,     0,     0,   429,     0,     0,     0,     0,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,  1834,  1835,   539,     0,   919,
       0,     0,     0,  1852,  1853,     0,     0,   880,     0,     0,
       0,     0,     0,     0,     0,  1862,     0,     0,     0,     0,
       0,     0,  1869,     0,     0,     0,     0,     0,  1873,  1874,
    1875,  1876,  1877,     0,     0,   401,     0,     0,   429,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,   429,     0,     0,     0,   539,     0,     0,
       0,  1903,     0,  1708,     0,     0,     0,  1709,     0,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,  1914,     0,   539,     0,     0,
       0,  1919,  1920,  1001,     0,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   484,   485,
     486,   487,   488,   489,  1943,   491,   492,  1592,     0,     0,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
     510,   511,     0,     0,     0,     0,     0,     0,     0,  1961,
    1962,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1968,  1969,  1970,  1971,  1972,  1973,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1981,
       0,     0,     0,     0,   429,   429,   429,   429,   429,     0,
       0,     0,     0,     0,  1774,     0,     0,     0,  1997,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,     0,
       0,     0,     0,  1735,     0,     0,     0,  1736,  2020,     0,
       0,     0,     0,  2023,  2024,  2025,  2026,  2027,  2028,     0,
       0,     0,     0,     0,     0,   632,   633,   634,     0,   429,
       0,   638,   639,   640,   641,   642,   643,   644,     0,   645,
       0,     0,   646,   647,     0,     0,   650,     0,     0,     0,
       0,     0,     0,     0,     0,  2045,     0,     0,   659,     0,
    2059,  2060,  2061,  2062,  2063,  2064,  1701,  1702,     0,     0,
       0,     0,     0,   187,     6,   341,     0,     0,     0,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   220,   221,   222,   223,   351,
     352,   353,   354,   224,     0,     0,     0,   355,   356,   357,
       0,     0,   358,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   359,     0,   360,     0,     0,   229,
       0,     0,   230,     0,     0,   231,     0,   232,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,    49,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,   817,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,     0,
       0,     0,     0,  1889,     0,     0,  1830,  1890,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     361,   362,   363,   237,   238,     0,     0,     0,   239,   240,
     241,   242,   243,   364,     0,   365,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,     0,     0,     0,   246,     0,     0,     0,     0,
     323,     0,     0,     0,  1489,     0,     0,   249,     0,     0,
    1887,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,  1897,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   715,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     6,
     341,     0,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     220,   221,   222,   223,   351,   352,   353,   354,   224,     0,
       0,     0,   355,   356,   357,     0,     0,   358,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,   359,
       0,   360,     0,     0,   229,     0,     0,   230,     0,     0,
     231,     0,   232,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,  1985,  1986,  1987,  1988,
    1990,   233,     0,    49,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,  2036,   880,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   361,   362,   363,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,   364,     0,
     365,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,     0,     0,     0,
     246,     0,     0,     0,     0,   323,   187,   150,   341,   248,
     387,     0,   249,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   375,   209,   210,   211,   212,
     213,   214,     0,     0,     0,     0,     0,     0,     0,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   220,   221,
     222,   223,   351,   352,   353,   354,   224,     0,     0,     0,
     355,   356,   357,     0,     0,   358,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   359,     0,   360,
       0,     0,     0,     0,     0,     0,   150,   341,     0,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,     0,
       0,     0,     0,     0,     0,     0,   388,   881,     0,     0,
    1284,     0,     0,     0,     0,     0,     0,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,   352,   353,   354,     0,     0,     0,     0,   355,
     356,   357,     0,     0,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,     0,   360,     0,
       0,     0,     0,     0,     0,   389,     0,     0,     0,     0,
       0,     0,   236,   361,   362,   363,   237,     0,     0,     0,
       0,   239,   240,   241,   242,   243,   364,     0,   365,   107,
     390,   391,   392,   393,     0,   388,     0,     0,     0,     0,
       0,     0,     0,   244,   376,     0,     0,     0,   246,     0,
     394,   395,     0,   396,     0,   397,   187,     6,   322,   398,
     249,     0,     0,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,   361,   362,   363,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,   364,   224,   365,   107,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   369,   341,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,  1456,  1457,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,     0,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,   352,   353,   354,
       0,     0,     0,     0,   355,   356,   357,     0,     0,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   236,   360,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   323,   187,     6,  1581,   248,     0,     0,
     249,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,   361,   362,   363,
       0,     0,     0,     0,     0,   225,   226,   227,     0,     0,
     364,     0,   365,   228,    21,     0,     0,     0,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
     341,     0,     0,     0,     0,     0,     0,   233,     0,    49,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,   352,   353,   354,     0,     0,
       0,     0,   355,   356,   357,     0,     0,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     236,   360,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   245,     0,     0,     0,   246,     0,     0,     0,
       0,   323,   187,     6,     0,   248,     0,     0,   249,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,   361,   362,   363,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,   364,     0,
     365,   228,    21,     0,     0,     0,     0,     0,   229,     0,
       0,   230,     0,     0,   231,     0,   232,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,    49,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   924,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   584,
    1727,     0,     0,     0,   246,     0,     0,     0,     0,   586,
     187,     6,     0,   288,   520,     0,   249,   188,   189,   190,
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
       0,     0,    73,     0,     0,    76,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1063,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   247,   187,     6,
       0,   248,     0,     0,   249,   188,   189,   190,     0,     0,
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
      73,     0,     0,    76,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1073,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,     0,     0,     0,
     246,     0,     0,     0,     0,   323,   187,     6,     0,   248,
       0,     0,   249,   188,   189,   190,     0,     0,   191,   192,
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
       0,    76,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1074,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   428,     0,     0,     0,   246,     0,
       0,     0,     0,   323,   187,     6,     0,   515,     0,     0,
     249,   188,   189,   190,     0,     0,   191,   192,   193,   194,
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
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1075,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   428,     0,     0,     0,   246,     0,     0,     0,
       0,   323,   187,     6,     0,     0,   520,     0,   249,   188,
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
      69,     0,     0,     0,    73,     0,     0,    76,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1080,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,     0,     0,     0,   246,     0,     0,     0,     0,   550,
     187,     6,     0,   248,     0,     0,   249,   188,   189,   190,
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
       0,     0,    73,     0,     0,    76,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1081,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   559,   187,     6,
       0,   248,     0,     0,   249,   188,   189,   190,     0,     0,
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
      73,     0,     0,    76,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,     0,     0,     0,
     246,     0,     0,     0,     0,   561,   187,     6,     0,   248,
       0,     0,   249,   188,   189,   190,     0,     0,   191,   192,
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
       0,    76,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   563,   187,     6,     0,   248,     0,     0,
     249,   188,   189,   190,     0,     0,   191,   192,   193,   194,
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
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1204,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   428,     0,     0,     0,   246,     0,     0,     0,
       0,   323,   187,     6,     0,   830,     0,     0,   249,   188,
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
      69,     0,     0,     0,    73,     0,     0,    76,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1282,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,     0,     0,     0,   246,     0,     0,     0,     0,   323,
     187,     6,     0,  1589,     0,     0,   249,   188,   189,   190,
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
       0,     0,    73,     0,     0,    76,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1371,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   584,  1727,     0,
       0,     0,   246,     0,     0,     0,     0,   586,   187,     6,
       0,   288,     0,     0,   249,   188,   189,   190,     0,     0,
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
      73,     0,     0,    76,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1372,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   428,     0,     0,     0,
     246,   187,   150,   341,     0,   323,     0,     0,   188,   189,
     190,     0,   249,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     375,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   220,   221,   222,   223,   351,   352,   353,
     354,   224,     0,     0,     0,   355,   356,   357,     0,     0,
     358,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   359,     0,   360,   187,   150,   341,     0,     0,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   375,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   220,   221,   222,
     223,   351,   352,   353,   354,   224,     0,     0,     0,   355,
     356,   357,     0,     0,   358,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   359,     0,   360,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   361,   362,
     363,   237,     0,     0,     0,     0,   239,   240,   241,   242,
     243,   364,     0,   365,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   376,
       0,     0,     0,   246,     0,     0,     0,     0,   323,     0,
       0,     0,  1485,     0,     0,   249,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1414,     0,     0,     0,     0,     0,
       0,   236,   361,   362,   363,   237,     0,     0,     0,     0,
     239,   240,   241,   242,   243,   364,     0,   365,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   376,     0,     0,     0,   246,     0,     0,
       0,     0,   323,   187,   150,   341,  1740,     0,     0,   249,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   375,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   220,   221,   222,   223,   351,
     352,   353,   354,   224,     0,     0,     0,   355,   356,   357,
       0,     0,   358,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   359,     0,   360,   187,   150,   341,
       0,     0,     0,     0,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   375,   209,   210,   211,
     212,   213,   214,     0,     0,     0,     0,     0,     0,     0,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   220,
     221,   222,   223,   351,   352,   353,   354,   224,     0,     0,
       0,   355,   356,   357,     0,     0,   358,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,   359,     0,
     360,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     361,   362,   363,   237,     0,     0,     0,     0,   239,   240,
     241,   242,   243,   364,     0,   365,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   376,     0,     0,     0,   246,     0,     0,     0,     0,
     323,     0,     0,     0,  1746,     0,     0,   249,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1528,     0,     0,     0,
       0,     0,     0,   236,   361,   362,   363,   237,     0,     0,
       0,     0,   239,   240,   241,   242,   243,   364,     0,   365,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   376,     0,     0,     0,   246,
     187,   150,     0,     0,   323,     0,     0,   188,   189,   190,
       0,   249,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   375,
     209,   210,   211,   212,   213,   214,     0,     0,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,   220,   221,   222,   223,   539,     0,     0,     0,
     224,     0,     0,     0,     0,     0,  1529,     0,     0,   187,
     150,   225,   226,   227,     0,     0,   188,   189,   190,   228,
      21,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   375,   209,
     210,   211,   212,   213,   214,     0,     0,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,   220,   221,   222,   223,   539,     0,     0,     0,   224,
       0,     0,     0,     0,     0,  1530,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1536,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,     0,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   376,     0,
       0,     0,   246,     0,     0,     0,     0,   323,     0,     0,
       0,   566,     0,     0,   249,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,   236,     0,     0,     0,   237,
       0,     0,     0,  1537,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   584,   585,     0,     0,
       0,   246,     0,     0,     0,     0,   586,     0,   187,   150,
     288,  1222,     0,   249,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   375,   209,   210,
     211,   212,   213,   214,     0,     0,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
     220,   221,   222,   223,   539,     0,     0,     0,   224,     0,
       0,     0,     0,     0,  1538,     0,     0,     0,     0,   225,
     226,   227,   187,   150,     0,  1377,     0,   228,    21,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   375,   209,   210,   211,   212,   213,   214,     0,     0,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,   220,   221,   222,   223,   539,     0,
       0,     0,   224,     0,     0,     0,     0,     0,  1539,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1658,     0,     0,   236,     0,     0,     0,   237,     0,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   376,     0,     0,     0,
     246,     0,     0,     0,     0,   323,     0,     0,     0,     0,
       0,     0,   249,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,   236,     0,
       0,  1769,   237,     0,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     376,     0,     0,     0,   246,   187,   150,     0,  1431,   323,
       0,     0,   188,   189,   190,     0,   249,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   375,   209,   210,   211,   212,   213,
     214,     0,     0,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,   220,   221,   222,
     223,   539,     0,     0,     0,   224,     0,     0,     0,     0,
       0,  1770,     0,     0,   187,   150,   225,   226,   227,     0,
       0,   188,   189,   190,   228,    21,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   375,   209,   210,   211,   212,   213,   214,
       0,     0,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,   220,   221,   222,   223,
     539,     0,     0,     0,   224,     0,     0,     0,     0,     0,
    1794,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1795,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,     0,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   376,     0,     0,     0,   246,     0,     0,
       0,     0,   323,     7,     8,     0,     0,     0,     0,   249,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
     236,     0,     0,     0,   237,     0,     0,     0,  1796,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,   244,   376,     0,     0,     0,   246,     0,     0,     0,
       0,   323,     0,     0,     0,     0,     0,     0,   249,   697,
      25,    26,   698,    28,    29,   699,    31,   700,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   701,    48,     0,     0,
      50,   702,     0,    53,   703,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,   697,    25,    26,   698,    28,    29,   699,
      31,   700,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     7,     8,    42,     0,    84,    85,    86,     0,
     701,    48,     0,     0,    50,   702,     0,    53,   703,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,    70,   539,     0,     0,
       7,     8,     0,     0,     0,     0,     0,  1797,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   910,     0,     0,   697,    25,
      26,   698,    28,    29,   699,    31,   700,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   701,    48,     0,     0,    50,
     702,     0,    53,   703,     0,     0,   697,    25,    26,   698,
      28,    29,   699,    31,   700,    33,    34,    35,    36,   954,
       0,    70,    38,    39,    40,     7,     8,    42,     0,     0,
       0,     0,     0,   701,    48,     0,     0,    50,   702,     0,
      53,   703,     0,     0,     0,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     7,     8,     0,     0,     0,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,    84,    85,    86,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1798,     0,     0,     0,
       0,   697,    25,    26,   698,    28,    29,   699,    31,   700,
      33,    34,    35,    36,   955,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   701,    48,
       0,     0,    50,   702,     0,    53,   703,     0,     0,   697,
      25,    26,   698,    28,    29,   699,    31,   700,    33,    34,
      35,    36,  1138,     0,    70,    38,    39,    40,     7,     8,
      42,     0,     0,     0,     0,     0,   701,    48,     0,     0,
      50,   702,     0,    53,   703,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     7,     8,     0,     0,
       0,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,    84,    85,    86,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1858,
       0,     0,     0,     0,   697,    25,    26,   698,    28,    29,
     699,    31,   700,    33,    34,    35,    36,  1140,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   701,    48,     0,     0,    50,   702,     0,    53,   703,
       0,     0,   697,    25,    26,   698,    28,    29,   699,    31,
     700,    33,    34,    35,    36,  1141,     0,    70,    38,    39,
      40,     7,     8,    42,     0,     0,     0,     0,     0,   701,
      48,     0,     0,    50,   702,     0,    53,   703,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     7,
       8,     0,     0,     0,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,    84,
      85,    86,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1915,     0,     0,     0,     0,   697,    25,    26,
     698,    28,    29,   699,    31,   700,    33,    34,    35,    36,
    1160,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   701,    48,     0,     0,    50,   702,
       0,    53,   703,     0,     0,   697,    25,    26,   698,    28,
      29,   699,    31,   700,    33,    34,    35,    36,  1189,     0,
      70,    38,    39,    40,     7,     8,    42,     0,     0,     0,
       0,     0,   701,    48,     0,     0,    50,   702,     0,    53,
     703,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     7,     8,     0,     0,     0,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,    84,    85,    86,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1916,     0,     0,     0,     0,
     697,    25,    26,   698,    28,    29,   699,    31,   700,    33,
      34,    35,    36,  1219,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   701,    48,     0,
       0,    50,   702,     0,    53,   703,     0,     0,   697,    25,
      26,   698,    28,    29,   699,    31,   700,    33,    34,    35,
      36,  1369,     0,    70,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   701,    48,     0,     0,    50,
     702,     0,    53,   703,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,     0,    84,    85,    86,     0,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,     0,
       0,     0,    -4,    -4,     0,     0,  1946,  1928,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,    -4,    -4,    -4,     0,   539,     0,    -4,    -4,
       0,    -4,  1091,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,    -4,     0,     0,  2009,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       6,     0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,
       8,     0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
       9,    10,     0,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,     0,     0,     0,     0,     0,
      11,    12,    13,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,    18,     0,    19,    20,     0,    21,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
      37,    38,    39,    40,    41,     0,    42,     0,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     7,     8,     0,
      79,    80,    81,     0,     0,     0,    82,     0,     0,     0,
       0,    83,    84,    85,    86,     0,     0,    87,     0,    88,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
     106,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   697,    25,    26,   698,    28,    29,   699,
      31,   700,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     701,    48,     0,     0,    50,   702,     0,    53,   703,     0,
       0,     0,     0,   961,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
     962,     0,     0,     0,     0,     0,     0,   697,    25,    26,
     698,    28,    29,   699,    31,   700,    33,    34,    35,    36,
      84,    85,    86,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   701,    48,     0,     0,    50,   702,
       0,    53,   703,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
      70,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1929,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1930,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1931,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1932,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1964,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1994,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1999,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2000,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2001,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2002,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2003,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2004,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2046,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2047,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2048,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2049,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1163,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1228,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1373,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1437,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1438,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1439,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1440,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1706,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1717,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1784,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1785,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1786,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1787,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1789,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1811,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1826,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1878,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1895,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1904,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1905,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  1926,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  1980,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  2022,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  2044,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  2070,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  2071,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  2072,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  2073,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,  2074,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,  2075,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,     0,   662,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,     0,   872,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,     0,  1804,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,   684,     0,   685,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,   975,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,  1110,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,     0,     0,  1176,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,     0,     0,  1177,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,     0,
       0,  1181,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,     0,     0,  1182,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,     0,     0,  1264,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,     0,     0,
    1280,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,     0,     0,  1468,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,     0,     0,  1595,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,     0,     0,  1762,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
       0,     0,  1812,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,   729,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,   733,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,   734,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,   736,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,   738,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,   739,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,   741,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
     743,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,   744,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,   745,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,   746,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,   747,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,   748,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,   750,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,   751,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,   752,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,   814,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
     843,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,   901,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,   919,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,   920,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,   921,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,   922,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,   928,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,   929,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,   960,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,   974,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
    1031,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,  1036,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,  1049,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,  1109,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,  1115,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,  1116,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,  1117,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,  1131,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,  1132,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,  1133,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
    1162,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,  1164,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,  1165,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,  1166,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,  1167,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,  1168,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,  1169,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,  1170,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,  1175,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,  1263,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
    1279,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,  1473,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   661,   537,   538,     0,     0,     0,     0,
     539,     0,  1540,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   661,   537,   538,     0,     0,     0,
       0,   539,     0,  1652,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   661,   537,   538,     0,     0,
       0,     0,   539,     0,  1653,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   661,   537,   538,     0,
       0,     0,     0,   539,     0,  1654,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   661,   537,   538,
       0,     0,     0,     0,   539,     0,  1655,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   661,   537,
     538,     0,     0,     0,     0,   539,     0,  1707,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   661,
     537,   538,     0,     0,     0,     0,   539,     0,  1716,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     661,   537,   538,     0,     0,     0,     0,   539,     0,  1739,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   661,   537,   538,     0,     0,     0,     0,   539,     0,
    1993,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   661,   537,   538,     0,     0,     0,     0,   539,
       0,  2041
};

static const yytype_int16 yycheck[] =
{
       3,     3,   281,   679,   293,   493,   581,   582,   132,  1157,
    1161,   687,  1619,   694,  1621,     4,     6,  1583,    21,     4,
      21,   310,     4,     4,     4,     4,     4,     4,  1777,     4,
      92,   712,     5,    95,     9,     6,   183,   184,   185,     5,
       4,   227,   228,     4,    47,     5,    14,     5,     7,     4,
     236,     4,     6,    95,     6,     4,     6,     5,     4,    95,
       4,     6,     6,     5,   231,   146,     4,     6,     9,   220,
     221,    74,   239,     9,   116,   227,   228,   220,   221,    82,
     116,     7,   234,   372,    87,   374,    60,    61,   239,    63,
     171,     0,   381,     6,     6,    98,   239,   231,     6,   220,
     221,   126,     6,   220,   221,   239,   187,   188,   231,     9,
     233,   220,   221,  1679,   235,   230,   239,   232,   143,   266,
     267,   268,   239,     7,   220,   221,   151,   152,   153,   132,
     239,   133,   157,   158,   137,   138,   234,   220,   221,    95,
     238,     9,   145,   239,   632,    89,   634,     4,     5,   231,
     230,   233,   234,   156,     7,   158,   239,   304,   305,   306,
     163,   220,   221,   132,     9,   168,   227,   228,   137,   138,
     317,   318,   175,   234,  1923,   234,   179,   227,   228,   182,
     183,   184,   185,   186,   161,   162,   163,   164,   159,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     7,   231,
     230,   182,    59,    60,    61,    62,   175,   239,   174,     4,
      67,    68,    69,     7,     9,    72,   174,   186,   171,   172,
     159,   206,   186,   220,   221,   206,   174,    84,   206,    86,
     233,   206,   174,   171,   172,  1801,    95,   234,    97,   231,
     230,  1389,   245,   232,   234,   248,   249,   239,   230,   238,
     230,   230,   237,   234,   234,   234,   234,   206,   235,   262,
     206,   234,   265,   266,   267,   268,   123,   217,   234,   230,
     273,   274,   275,   234,   234,   230,   279,   236,   281,   234,
     234,   570,   234,   572,   573,   234,   227,   228,  1854,   230,
       6,   232,   233,     7,   230,   236,   232,     6,   974,   975,
     589,   304,   305,   306,   230,   217,   232,   220,   221,     6,
     284,   285,   220,   221,   317,   318,   220,   221,   292,   293,
     230,   220,   221,   207,   208,   209,   210,   227,   228,    98,
     230,   100,   232,   190,   191,   192,   236,   626,     6,   231,
     239,    47,   231,   227,   228,     7,   203,   239,   205,   206,
     239,  1958,   236,     6,   207,   208,   209,   210,   505,   506,
     507,   508,   230,   132,   232,     4,   130,   131,   236,     6,
     227,   228,   136,   662,   227,   228,   379,   234,   232,   236,
     383,   384,   227,   228,   231,   230,   155,   232,   220,   221,
     231,   236,   239,   220,   221,   236,   399,   232,   207,   208,
     209,   210,   405,   220,   221,   220,   221,   239,     6,     7,
     379,   206,   239,   207,   208,   209,   210,   220,   221,  1100,
     233,   424,   239,   230,   239,   428,   239,  1108,   220,   221,
    1996,   109,   227,   228,   233,   230,   239,   232,   230,   234,
     239,   236,   234,   220,   221,   220,   221,  1123,     4,  1125,
      89,  1127,   230,  1129,    93,   220,   221,   220,   221,   234,
      99,   100,   239,   102,   103,     6,   220,   221,   220,   221,
       6,     7,   475,   179,   239,   231,   239,   233,   230,   482,
     483,   120,   234,   239,   487,   239,   489,   490,   491,   492,
     493,  2057,   230,   207,   208,   209,   210,   220,   221,   220,
     221,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     230,   512,   515,   227,   228,   230,   239,   230,   487,   234,
     489,   234,   491,   492,   220,   221,    89,   233,   230,    92,
     220,   221,    95,   536,   220,   221,   230,   540,   220,   221,
     509,   510,   231,   239,   233,   207,   208,   209,   210,   239,
     239,   220,   221,   239,   230,   679,   231,   239,   233,   265,
     230,    95,   565,   566,   239,   227,   228,   273,   274,   275,
     239,   230,   230,   279,   130,   131,   132,   133,   230,   581,
     582,  1262,   220,   221,   222,   223,   224,   876,   230,   145,
      92,   229,   148,    95,   126,    89,     8,  1278,    92,    92,
     230,    95,    95,    97,    97,   579,   580,   610,   611,   612,
     584,   143,    92,   234,   231,    95,   233,    97,   387,   151,
     152,   153,   239,   230,   230,   157,   158,   126,   234,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   230,   642,
     643,   644,   645,   646,   143,   648,   649,   650,   651,   130,
     131,   654,   151,   152,   153,   136,   230,    89,   157,   158,
      92,   234,    95,    95,   633,    97,   635,   636,   637,   638,
     639,   640,   230,   642,   643,   644,   645,   383,   384,   648,
     649,   650,     8,   686,    89,    92,    92,    92,   691,    95,
      95,    97,    97,   399,   222,   223,   224,   230,   235,   232,
     235,   229,   239,   235,   239,   708,   709,   126,   235,   235,
     234,   714,   239,   239,   717,   839,   235,   720,   235,   722,
     239,   235,   239,   234,   143,   239,   236,   730,   238,   732,
     126,   235,   151,   152,   153,   239,   235,    95,   157,   158,
     231,   158,   233,   234,   513,   230,   163,   143,   717,   234,
      95,   168,    97,   722,   230,   151,   152,   153,   234,   230,
     235,   157,   158,    92,   239,   182,     4,  1443,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,  1455,
     231,    92,   233,   229,   490,   788,   555,   556,   557,   558,
     235,   235,    95,   235,   239,   239,  1947,   239,   504,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     4,   235,   235,   235,   229,   239,   239,
     235,   235,   235,   235,   239,   239,   239,   830,   245,     4,
       4,   248,   235,   235,  1982,     6,   239,   239,   841,   235,
     235,   230,   230,   235,   239,   262,   849,   239,   235,   235,
     974,   975,   239,   239,   235,    95,   230,    97,   239,  2010,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   872,
     235,   235,     6,   229,   239,   239,     4,     5,   647,     4,
     235,     6,   230,  2031,   239,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   230,
     235,     6,   235,   229,   239,   879,   239,   235,   232,   235,
     235,   239,   886,   235,   239,     6,   890,   239,    46,    47,
      48,    49,    50,    51,    52,    53,    54,   126,   230,   238,
     234,    59,    60,    61,    62,     6,   232,   238,   235,    67,
      68,    69,   239,   235,    72,   230,   235,   239,   235,     8,
     239,   235,   239,   235,     9,   239,    84,   239,    86,   728,
     235,   230,   235,   966,   239,  1244,   239,   235,  1456,  1457,
     235,   239,   235,   230,   239,   235,   239,   980,   116,   239,
     235,   230,   985,   235,   239,  1109,  1110,   239,   230,   992,
     993,   994,   995,  1568,  1569,   123,   235,   230,   235,   235,
     239,  1004,   239,   239,   235,   235,   230,   230,   239,   239,
     230,   428,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,  1029,  1030,   234,  1032,
     229,  1034,  1035,   230,  1037,  1004,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,   230,   230,  1050,   230,   230,
     230,  1025,     4,     6,   230,   234,   234,   234,   475,     6,
     230,   234,   190,   191,   192,   482,   483,   230,   230,   230,
     230,   230,   230,     6,     6,   203,   232,   205,   206,   234,
     234,   234,  1085,  1086,  1087,   232,   232,   232,   174,   230,
     234,   230,   232,   230,   511,   230,     6,   230,   515,     6,
    1103,     6,   234,   231,     6,   233,     7,   234,     6,     6,
    1113,  1114,   234,   234,    85,   235,   239,  1086,  1087,   536,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   231,   239,     7,     6,   229,  1263,
    1264,  1430,     6,   849,     6,  1434,   231,   234,   565,   566,
      64,   229,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     4,     7,  1171,    64,
     229,  1450,   231,    64,   233,    64,     7,     6,     6,     6,
     231,  1184,  1185,  1186,     6,   234,     7,     6,   171,     7,
       6,     6,  1195,   610,   611,   612,     6,  1200,   234,   233,
     231,  1204,     6,   236,   234,   234,   234,   976,   234,     7,
    1213,     6,  1215,   232,   230,     4,     6,   231,     6,     6,
       6,   232,  1225,     8,     7,   174,     7,     7,     7,   174,
       7,  1200,  1807,     7,     7,  1204,   174,   654,     7,     7,
       7,  1244,     7,     7,  1213,     7,  1215,     7,     7,     7,
     234,     6,   231,   233,   239,     7,   234,   239,  1746,   234,
     966,  1264,   239,   239,   234,   234,   231,     7,   236,   686,
     234,     4,     6,   231,   231,   231,   239,   239,   239,   985,
     231,   235,  1285,     6,   239,   126,   236,   235,     7,     6,
     236,   708,     7,  1296,     7,  1264,     7,   714,   239,  1302,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   231,   730,   231,   732,   229,   239,     9,  1443,
     231,   239,     7,  1029,  1030,     6,  1032,   233,  1034,  1035,
     234,  1037,   146,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,   235,     6,     6,  1348,  1349,  1350,     4,    46,
      46,  1354,   236,  1356,  1633,  1358,   234,  1360,   230,  1362,
    1363,  1364,   230,   230,   230,   217,   236,     4,     7,     7,
      97,   788,     7,     7,   239,     7,  1379,     7,     6,  1085,
       7,     7,     7,     7,     7,     4,   107,  1390,     4,   234,
       7,     6,     6,   230,     7,  1398,     7,  1103,  1401,     7,
       7,     7,     7,     7,   234,     6,     6,  1113,     6,    95,
       7,     6,     6,   830,  1388,     4,     4,     4,   120,   239,
    1544,   234,   239,   234,   841,   237,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       6,   235,     6,     6,   229,     7,   231,  1450,     6,     6,
     232,     6,   230,  1456,  1457,   872,     6,     6,   230,  1462,
     236,     6,     6,   234,   239,  1171,     6,   233,     6,     6,
     174,   234,     6,   234,     6,     6,     6,  1480,  1184,  1185,
    1186,   234,  1485,   234,   234,     6,  1489,     6,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,     6,     6,     6,     5,   229,   231,     6,   231,
       4,  1480,     4,     6,  1283,     6,  1285,     7,   234,  1225,
     234,  1645,   234,   232,   234,  1499,   234,  1816,     6,     6,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   234,   234,   234,   234,   229,     6,
     234,   234,   234,     6,     6,     6,   231,  1560,  1561,   239,
     170,   239,   239,     6,   236,  1844,  1568,  1569,     7,   230,
     234,     4,     6,     4,   234,   992,   993,   994,   995,  1285,
    1583,     6,     6,     6,     6,     6,  1589,     7,     6,     6,
    1296,     6,     6,     6,    93,  1598,  1302,     5,   234,     6,
       6,   234,     6,  1606,     6,     6,  1609,     6,     6,     6,
    1584,  1585,  1586,  1587,  1588,  1589,     6,   239,     6,  1622,
    1909,     6,     6,     6,     6,     4,  1629,   239,     6,     6,
    1633,     6,  1635,  1050,     7,   234,   239,  1606,   234,     5,
    1609,     6,  1348,  1349,  1350,     6,     6,     6,  1354,   234,
    1356,   234,  1358,     6,  1360,   235,  1362,  1363,  1364,  1948,
    1429,   235,     7,   234,   169,     6,   231,   235,   235,     6,
     230,     7,     6,  1379,   235,     6,  1679,   236,     6,     6,
     234,     6,     6,     6,  1390,     6,     6,     6,     6,   235,
       6,   234,  1398,     6,     6,   231,   172,  1114,     6,     6,
     235,   234,     4,     5,  1960,     6,   235,   234,   234,     6,
     235,   234,  1715,     6,   126,     6,  1485,   234,   231,     6,
       6,     6,     6,   235,  1727,   235,     6,     6,     6,     6,
       6,     6,     6,   234,     6,     6,     6,  1740,   234,   234,
       6,     6,     6,  1746,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     6,  1277,   421,  1462,    59,    60,    61,
      62,  1328,  1493,  1778,  1750,    67,    68,    69,  1549,  1772,
      72,     3,     3,  1295,     3,     3,  1779,  1803,  1195,  1485,
    1783,     3,    84,  1629,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1564,    -1,   554,  1801,    -1,
      -1,  1804,    -1,    -1,    -1,  1807,    -1,    -1,    -1,    -1,
       6,    -1,  1815,    -1,    -1,    -1,  1819,    -1,    -1,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,  1604,     7,     8,    -1,   229,
      -1,  1844,  1611,  1612,    -1,    -1,  1820,  1821,  1822,  1823,
    1824,  1854,    -1,    -1,    -1,    -1,  1625,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,  1583,    -1,  1882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,    -1,  1598,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,   205,   206,    -1,    -1,  1881,    -1,    -1,
      -1,  1885,    -1,    -1,    -1,    -1,  1622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1950,  1951,  1952,
    1953,  1954,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1934,    -1,    -1,    -1,  1938,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,  1679,    -1,    -1,    -1,    -1,    -1,    -1,
    1954,    -1,  1751,    -1,  1401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1996,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1715,
      -1,    -1,  2015,  1782,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,  2005,  2006,   229,    -1,    -1,    -1,  2040,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,  2057,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,     6,  2067,  2068,  1772,    -1,    -1,    -1,
     106,  2040,  1489,  1779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1801,   132,    -1,  2067,  2068,
     136,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,  1815,
      -1,    -1,    -1,    -1,    -1,  2084,    -1,    -1,    -1,     6,
      -1,   157,   158,   159,   160,    -1,   162,   163,   164,   165,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,   177,   178,  1560,  1561,    -1,   182,    -1,  1854,    -1,
      -1,    -1,    -1,    -1,    -1,  1924,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,  1589,    -1,    -1,   229,  1882,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   261,   262,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   277,    -1,    -1,    -1,   229,    -1,   231,    -1,   233,
      -1,   287,   288,    -1,    -1,   239,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,   323,    -1,    -1,
    1996,   327,   328,   329,    -1,   331,    -1,    -1,    -1,   335,
     336,   337,    -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,
    1727,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1740,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
     376,    -1,   229,    -1,   380,    -1,    -1,    -1,    -1,    -1,
      -1,  2057,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   410,    -1,    -1,     6,    -1,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,  1804,    -1,    -1,
      -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,   434,    -1,
      -1,    -1,  1819,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,
      -1,    -1,    -1,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,    -1,   485,
     486,    -1,   488,     6,    -1,    -1,    -1,    -1,   494,    -1,
      -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,   515,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,    -1,   541,   542,    -1,    -1,    -1,
      -1,    -1,   548,   549,   550,     6,    -1,    -1,    -1,   555,
     556,   557,   558,   559,    -1,   561,   545,   563,    -1,   565,
     566,    -1,    -1,  1950,  1951,  1952,  1953,  1954,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,   585,
     586,    -1,    -1,    -1,   590,   591,   592,   593,   594,   595,
     596,   597,   598,    -1,    -1,    -1,    -1,   603,    -1,   605,
     606,     7,    -1,    -1,   610,   611,   612,    -1,    -1,   615,
     616,   617,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,  2015,    -1,
     229,    -1,    -1,    -1,    -1,   641,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   654,   163,
      -1,    -1,    -1,   659,   168,   661,    -1,   663,   664,    -1,
      -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,   182,    -1,
     676,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
     686,    -1,    -1,    -1,    -1,    -1,   692,   693,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   708,    -1,   710,   711,   229,    -1,   714,   715,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,     6,    -1,
      -1,   727,    -1,    -1,   730,    -1,   732,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   753,   262,   233,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   788,   772,   773,   774,   775,    -1,   777,   778,
     779,   780,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,   791,    -1,   793,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     809,   810,    -1,   229,   830,    -1,    -1,    -1,   817,    -1,
      -1,    -1,    -1,    -1,    -1,   841,    -1,    -1,    -1,    -1,
      -1,    -1,   848,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,   872,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   880,   881,    -1,    -1,    -1,    -1,
     886,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   902,    -1,    -1,   905,
     229,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,   924,   229,
     926,   927,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,   945,
      -1,   229,   931,   932,   933,    -1,    -1,    -1,   937,   938,
      -1,    -1,   941,   942,   943,   944,   962,   946,    -1,    -1,
      -1,    -1,   951,   969,   970,   971,   972,    -1,    -1,    -1,
      -1,   977,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   991,   992,   993,   994,   995,
     996,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   515,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,  1023,  1024,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1050,    -1,    -1,    -1,    -1,    13,
      14,   565,   566,    -1,    -1,    -1,    -1,  1063,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1073,  1074,  1075,
      -1,    -1,    -1,    -1,  1080,  1081,     8,  1083,    -1,    -1,
      -1,    -1,    -1,    -1,  1090,    -1,  1092,  1093,  1094,  1095,
    1096,    -1,    -1,    -1,    -1,    -1,   610,   611,   612,  1105,
    1106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1124,    -1,
    1126,    -1,  1128,    -1,  1130,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     654,   105,   106,   107,    -1,  1151,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   686,    -1,    -1,    -1,    -1,  1183,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1195,
      -1,    -1,    -1,    -1,   708,    -1,    -1,  1203,    -1,    -1,
     714,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1235,
      -1,    -1,  1238,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,  1247,    -1,
      -1,    -1,    -1,    -1,    -1,  1271,  1272,  1273,  1274,    -1,
      -1,   235,    -1,    -1,   788,    -1,  1282,  1283,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,  1284,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,  1317,  1318,
    1319,  1320,  1321,    -1,    -1,    -1,    -1,  1326,  1327,    -1,
    1329,    -1,    -1,    -1,    -1,    -1,  1335,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1345,    -1,   872,    -1,
      -1,    -1,    -1,     8,  1370,  1371,  1372,    -1,    -1,    -1,
      -1,    -1,    -1,  1379,    -1,  1381,    -1,    -1,    -1,    -1,
      -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1401,    -1,    -1,    -1,    -1,
    1406,    -1,    -1,     8,    -1,    -1,    -1,    -1,  1414,  1415,
    1416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1420,    -1,  1422,    -1,    -1,    -1,  1426,    -1,  1428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1454,    -1,
       8,    -1,    -1,    -1,  1460,  1461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   992,   993,
     994,   995,    -1,  1489,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1497,  1498,    -1,    -1,    -1,    -1,    -1,  1504,  1505,
      -1,    -1,    -1,    -1,    -1,  1511,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,  1528,  1529,  1530,   229,    -1,    -1,    -1,    -1,
    1536,  1537,  1538,  1539,    -1,    -1,  1050,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1560,  1561,  1562,    -1,  1564,    -1,
      -1,    -1,    -1,    -1,  1570,  1571,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,  1589,   229,    -1,    -1,  1593,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,    -1,
    1114,  1607,    -1,    -1,    -1,  1611,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
    1626,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1639,    -1,    -1,    -1,    -1,  1644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1637,  1638,
      -1,    -1,  1658,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1195,  1688,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,  1680,  1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1709,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1727,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1736,  1737,    -1,    -1,  1740,    -1,    -1,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,  1744,  1745,   229,    -1,   231,
      -1,    -1,    -1,  1769,  1770,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1781,    -1,    -1,    -1,    -1,
      -1,    -1,  1788,    -1,    -1,    -1,    -1,    -1,  1794,  1795,
    1796,  1797,  1798,    -1,    -1,   132,    -1,    -1,  1804,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,  1819,    -1,    -1,    -1,   229,    -1,    -1,
      -1,  1827,    -1,   235,    -1,    -1,    -1,   239,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,  1851,    -1,   229,    -1,    -1,
      -1,  1857,  1858,   235,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,  1890,   222,   223,  1401,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1915,
    1916,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1927,  1928,  1929,  1930,  1931,  1932,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1945,
      -1,    -1,    -1,    -1,  1950,  1951,  1952,  1953,  1954,    -1,
      -1,    -1,    -1,    -1,  1960,    -1,    -1,    -1,  1964,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,   239,  1994,    -1,
      -1,    -1,    -1,  1999,  2000,  2001,  2002,  2003,  2004,    -1,
      -1,    -1,    -1,    -1,    -1,   342,   343,   344,    -1,  2015,
      -1,   348,   349,   350,   351,   352,   353,   354,    -1,   356,
      -1,    -1,   359,   360,    -1,    -1,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2024,    -1,    -1,   375,    -1,
    2046,  2047,  2048,  2049,  2050,  2051,  1560,  1561,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    86,    -1,    -1,    89,
      -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,   523,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,  1740,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,   198,   199,
     200,   201,   202,   203,    -1,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,   234,    -1,    -1,   237,    -1,    -1,
    1804,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,  1819,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,  1950,  1951,  1952,  1953,
    1954,   116,    -1,   118,    -1,    -1,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
     145,    -1,    -1,   148,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2015,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,   198,   199,   200,   201,   202,   203,    -1,
     205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   230,     3,     4,     5,   234,
       7,    -1,   237,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   239,    -1,    -1,
    1017,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,   199,   200,   201,   202,   203,    -1,   205,   206,
     207,   208,   209,   210,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
     227,   228,    -1,   230,    -1,   232,     3,     4,     5,   236,
     237,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,   203,    63,   205,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,  1248,  1249,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,   148,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,   189,    86,    -1,    -1,   193,   194,    -1,    -1,
      -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,     3,     4,     5,   234,    -1,    -1,
     237,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
     203,    -1,   205,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
      -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
     189,    86,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,
     199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   230,     3,     4,    -1,   234,    -1,    -1,   237,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,   203,    -1,
     205,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,    -1,    -1,    -1,   198,   199,   200,
     201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,
       3,     4,    -1,   234,   235,    -1,   237,    10,    11,    12,
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
      -1,    -1,   145,    -1,    -1,   148,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,   194,    -1,    -1,    -1,   198,   199,   200,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,
      -1,   234,    -1,    -1,   237,    10,    11,    12,    -1,    -1,
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
     145,    -1,    -1,   148,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,
      -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   230,     3,     4,    -1,   234,
      -1,    -1,   237,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,   148,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,    -1,   193,   194,    -1,    -1,
      -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,     3,     4,    -1,   234,    -1,    -1,
     237,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,
     199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   230,     3,     4,    -1,    -1,   235,    -1,   237,    10,
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
     141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,    -1,    -1,    -1,   198,   199,   200,
     201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,
       3,     4,    -1,   234,    -1,    -1,   237,    10,    11,    12,
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
      -1,    -1,   145,    -1,    -1,   148,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,   194,    -1,    -1,    -1,   198,   199,   200,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,
      -1,   234,    -1,    -1,   237,    10,    11,    12,    -1,    -1,
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
     145,    -1,    -1,   148,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,
      -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   230,     3,     4,    -1,   234,
      -1,    -1,   237,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,   148,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,    -1,   193,   194,    -1,    -1,
      -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,     3,     4,    -1,   234,    -1,    -1,
     237,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,
     199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   230,     3,     4,    -1,   234,    -1,    -1,   237,    10,
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
     141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,    -1,    -1,    -1,   198,   199,   200,
     201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,
       3,     4,    -1,   234,    -1,    -1,   237,    10,    11,    12,
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
      -1,    -1,   145,    -1,    -1,   148,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,   194,    -1,    -1,    -1,   198,   199,   200,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,
      -1,   234,    -1,    -1,   237,    10,    11,    12,    -1,    -1,
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
     145,    -1,    -1,   148,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,
      -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,     3,     4,     5,    -1,   230,    -1,    -1,    10,    11,
      12,    -1,   237,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,    86,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,   199,   200,   201,
     202,   203,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,   234,    -1,    -1,   237,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,   199,   200,   201,   202,   203,    -1,   205,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   230,     3,     4,     5,   234,    -1,    -1,   237,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    86,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,   199,
     200,   201,   202,   203,    -1,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,   234,    -1,    -1,   237,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,   199,   200,   201,   202,   203,    -1,   205,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,
       3,     4,    -1,    -1,   230,    -1,    -1,    10,    11,    12,
      -1,   237,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    55,    56,    57,    58,   229,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,     3,
       4,    74,    75,    76,    -1,    -1,    10,    11,    12,    82,
      83,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    55,    56,    57,    58,   229,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,   198,   199,   200,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,   234,    -1,    -1,   237,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   189,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   239,   198,   199,   200,   201,   202,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,    -1,     3,     4,
     234,     6,    -1,   237,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      55,    56,    57,    58,   229,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    74,
      75,    76,     3,     4,    -1,     6,    -1,    82,    83,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    55,    56,    57,    58,   229,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,   189,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,   239,   193,    -1,    -1,    -1,    -1,   198,   199,   200,
     201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,   225,     3,     4,    -1,     6,   230,
      -1,    -1,    10,    11,    12,    -1,   237,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    55,    56,    57,
      58,   229,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,     3,     4,    74,    75,    76,    -1,
      -1,    10,    11,    12,    82,    83,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    55,    56,    57,    58,
     229,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
     198,   199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   230,    13,    14,    -1,    -1,    -1,    -1,   237,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     189,    -1,    -1,    -1,   193,    -1,    -1,    -1,   239,   198,
     199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,   237,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,   105,
     106,   107,    13,    14,   110,    -1,   166,   167,   168,    -1,
     116,   117,    -1,    -1,   120,   121,    -1,   123,   124,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,   142,   229,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   235,
      -1,   142,   105,   106,   107,    13,    14,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   166,   167,   168,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   235,    -1,    -1,   105,   106,   107,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,    -1,   120,   121,    -1,   123,   124,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   235,    -1,   142,   105,   106,   107,    13,    14,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   166,   167,   168,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   235,    -1,    -1,
     105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,   124,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   235,    -1,   142,   105,   106,
     107,    13,    14,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,   120,   121,    -1,   123,   124,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   166,
     167,   168,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     235,    -1,    -1,   105,   106,   107,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,
      -1,   123,   124,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   235,    -1,
     142,   105,   106,   107,    13,    14,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,
     124,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   166,   167,   168,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   235,    -1,    -1,   105,   106,   107,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   235,    -1,   142,   105,   106,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,   166,   167,   168,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,   235,   239,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    64,    65,    66,    -1,   229,    -1,    70,    71,
      -1,    73,   235,    -1,    -1,    77,    78,    -1,    80,    81,
      -1,    83,    -1,    -1,   235,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,   106,   107,   108,    -1,   110,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,   121,
     122,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
       4,    -1,   154,   155,   156,    -1,    -1,    -1,   160,    13,
      14,    -1,    -1,   165,   166,   167,   168,    -1,    -1,   171,
      -1,   173,    -1,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      44,    45,    -1,   195,   196,   197,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,
      -1,    -1,    -1,    77,    78,    -1,    80,    81,    -1,    83,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,   106,   107,   108,    -1,   110,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,   120,   121,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    13,    14,    -1,
     154,   155,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,   171,    -1,   173,
      -1,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,    -1,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     166,   167,   168,   105,   106,   107,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,
      -1,   123,   124,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
     142,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,   235,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,   234,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,   234,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,   234,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,    -1,   233,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,   233,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,   233,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,   233,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,   233,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,   233,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,   233,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,   233,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
     233,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,   233,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,   233,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,   233,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,   233,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,   231
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   241,   242,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    77,    78,    80,
      81,    83,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   104,   105,   106,
     107,   108,   110,   112,   113,   114,   115,   116,   117,   118,
     120,   121,   122,   123,   124,   125,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   154,
     155,   156,   160,   165,   166,   167,   168,   171,   173,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   195,   196,   197,   204,   206,   243,   245,
     246,   266,   287,   288,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   306,   308,   309,   315,   316,   317,   318,
     322,   343,   344,   234,   238,    14,    95,   230,   230,     6,
     234,     6,     6,     6,     6,   230,     6,     6,   232,   232,
       4,   324,   344,   230,   232,   264,   264,   230,   234,   230,
     230,     4,   230,   234,   230,   230,     4,   230,   234,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   109,
      95,     6,   234,    89,    92,    95,   230,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    74,    75,    76,    82,    89,
      92,    95,    97,   116,   121,   123,   189,   193,   194,   198,
     199,   200,   201,   202,   220,   221,   225,   230,   234,   237,
     288,   299,   306,   308,   319,   320,   322,   324,   331,   333,
     344,   230,   234,    95,    95,   116,    92,    95,    97,    89,
      92,    95,    97,    92,    95,    97,    92,    95,   230,    92,
     146,   171,   187,   188,   234,   220,   221,   230,   234,   328,
     329,   328,   234,   234,   328,     4,    89,    93,    99,   100,
     102,   103,   120,   230,    95,    97,    95,    92,     4,   182,
     234,   344,     4,     6,    89,    92,    95,    92,    95,     4,
       4,     4,     5,   230,   331,   332,     4,   230,   230,   230,
       4,   234,   335,   344,     4,   230,   230,   230,     6,     6,
     232,     5,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    59,    60,    61,    62,    67,    68,    69,    72,    84,
      86,   190,   191,   192,   203,   205,   339,   344,   230,     4,
     339,     5,   234,     5,   234,    32,   221,   319,   344,   232,
     230,   234,     6,   230,   234,     6,   238,     7,   123,   182,
     207,   208,   209,   210,   227,   228,   230,   232,   236,   262,
     263,   264,   319,   338,   339,   344,     4,   288,   289,   290,
     234,     6,   319,   338,   339,   344,   338,   319,   338,   342,
     268,   272,   230,   327,     9,   339,   344,   319,   221,   319,
     333,   334,   319,   319,   230,   319,   334,   319,   319,   230,
     319,   334,   319,   319,   319,   319,   319,   319,   338,   319,
     319,   319,   331,   230,   334,   332,   332,   332,   338,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   230,   232,   264,   264,   264,   264,   264,   264,
     230,   264,   264,   230,   264,     5,   174,   234,     5,   174,
       5,   174,     5,   174,   116,    89,    92,    95,    97,   230,
     264,   264,   230,   230,   319,   234,   319,   333,   319,   319,
     235,   334,     9,   344,     8,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   229,
       9,   230,   232,   236,   263,   264,   319,   334,   230,   230,
     230,   331,   332,   332,   332,   230,   230,   230,   230,   230,
     331,   230,   331,   230,   331,   234,   234,   319,     4,   331,
     234,   335,   234,   234,   328,   328,   328,   319,   319,   220,
     221,   234,   234,   328,   220,   221,   230,   290,   328,   234,
     230,   234,   230,   230,   230,   230,   230,   230,   230,   319,
     332,   332,   332,   230,     4,   232,   232,   290,     6,     6,
     234,   234,   234,   332,   332,   232,   232,   232,   319,     6,
       6,   319,   319,   319,   236,   319,   234,   174,   319,   319,
     319,   319,   264,   264,   264,   230,   230,   230,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   230,   230,
     264,   232,     6,     6,   234,     6,   290,     6,   290,   264,
     319,   222,   234,   230,   232,   338,   319,   290,   331,   331,
     234,   339,    89,    92,    95,    97,     7,   319,   319,     4,
     171,   172,   331,     6,   231,   233,   234,   265,     6,   234,
       6,     9,   230,   232,   236,   344,   235,    89,    92,    95,
      97,   116,   121,   124,   287,   319,     6,   231,   239,     9,
     230,   232,   236,   231,   239,   239,   231,   239,   233,   239,
     267,   233,   267,    85,   326,   323,   344,   239,   239,   231,
     222,   235,   239,   231,   231,   319,   231,   235,   231,   231,
     319,   231,   235,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,     7,   319,   235,     6,     6,     6,   231,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   333,   319,   319,
     319,   319,   319,   319,   319,   333,   333,   344,   234,   319,
     319,   338,   319,   338,   331,   338,   338,   342,   319,    64,
     319,    64,    64,    64,   332,   332,   332,   332,   338,   338,
     333,   324,   339,   334,   231,   235,     9,   264,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     234,   319,   333,   319,   319,   319,   344,   319,   319,     4,
     325,   234,   265,   231,   235,   319,   319,   319,     7,     7,
     312,   312,   281,   319,   339,   282,   319,   339,   283,   319,
     339,   284,   319,   339,   319,     6,   319,     6,   319,     6,
     334,   334,   234,   231,     6,   290,   234,   290,   290,   239,
     239,   239,   328,   328,   289,   289,   239,   319,   235,   303,
     239,   290,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   231,     7,   313,     6,     7,   319,     6,   319,   319,
     235,   334,   334,   334,     6,     6,   319,   319,   319,   231,
     231,   231,   231,   171,   239,   290,   234,     8,   231,   231,
     233,   342,   338,   342,   338,   338,   338,   338,   338,   338,
     319,   338,   338,   338,   338,   237,   341,   344,   339,   338,
     338,   338,   344,   334,   235,   235,   319,   319,   290,   233,
     231,   129,   146,   307,   231,   235,   239,   319,     6,   234,
     234,   234,   234,   319,   231,   233,     7,   262,   263,   236,
       7,     6,   334,     7,   210,   262,   247,   344,   319,   319,
     325,   232,   234,   234,   234,   234,   230,   116,    92,    95,
      97,   235,     6,   217,   244,   334,   344,   319,   319,     4,
     325,     6,   334,   319,     6,   338,     6,   344,     6,   338,
     319,   231,   232,   319,   339,     7,   174,   319,   333,     7,
       7,   231,     7,   174,     7,     7,   231,     7,   174,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   319,   231,
     234,     6,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   239,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   239,   239,   239,   231,   233,   233,   334,
     239,   239,   265,   239,   265,   239,   239,   239,   231,   321,
     234,   235,   234,   234,   234,   239,   239,   265,   265,   231,
     236,   231,   235,     7,   265,     8,     8,   334,   236,   231,
     233,   263,   334,     7,   234,   231,   231,   231,   319,   331,
       4,   311,     6,   231,   239,   231,   239,   231,   239,   231,
     239,   231,   231,   231,   235,   235,   334,   236,   235,   290,
     235,   235,   328,   319,   319,   235,   235,   319,   328,   126,
     126,   143,   151,   152,   153,   157,   158,   304,   305,   328,
     235,   300,   231,   235,   231,   231,   231,   231,   231,   231,
     231,     7,   319,     6,   319,   231,   233,   233,   235,   235,
     235,   233,   233,   239,     7,     7,     7,   236,   319,   235,
     319,   319,     7,   236,   265,   239,   265,   265,   231,   231,
     239,   265,   265,   239,   239,   265,   265,   265,   265,   319,
     265,     9,   340,   239,   231,   239,   265,   233,   235,   235,
       7,   146,     6,   319,   235,   234,     6,   331,   235,   319,
     319,   319,   319,     6,     7,   262,   263,   236,   262,   263,
     339,   319,     6,     4,   234,   336,   344,   235,    46,    46,
     331,     4,   161,   162,   163,   164,   235,   250,   254,   257,
     259,   260,   236,   231,   233,   319,   334,   334,   334,   334,
     319,   230,   230,   230,   230,   217,   338,   231,   236,   231,
     233,   231,   239,     7,   264,     4,   275,   276,   277,   265,
     265,   328,    95,    97,   331,   331,     7,   331,    95,    97,
     331,   331,     7,   331,    97,   331,   331,   331,   331,   331,
     331,   331,   331,   331,     6,     7,   334,   319,   319,   319,
     319,   235,   319,   319,   319,   331,   338,   338,   239,   274,
     319,   319,   319,   319,   319,   319,   325,   331,   319,   319,
     235,   325,   263,   236,   263,   235,   331,   334,     7,     7,
       7,   126,   310,     6,   262,   319,   262,   319,   262,   319,
     262,   319,     7,     7,     7,     7,     7,   235,     4,   235,
     239,   239,   239,   235,   235,   107,     4,     6,   319,   234,
       6,   230,     6,   159,     6,   159,   235,   305,   239,   304,
       7,     6,     7,     7,     7,     7,     7,     7,     7,   331,
       6,   234,     6,     6,     6,    95,     7,     6,     6,   319,
     331,   331,   331,     4,   239,     8,     8,   231,     4,     4,
     334,   338,   319,   338,   237,   239,   278,   338,   338,   239,
     234,     6,   319,     6,   234,   331,   235,   235,   235,   235,
     235,   319,     6,     4,   171,   172,   319,     6,     6,     6,
       7,   335,   337,     6,   232,   265,   264,   264,     6,   251,
     230,   230,   234,   261,     6,   325,   236,   338,   233,   235,
     235,   235,   235,   231,   319,   319,   319,   319,     6,     6,
     244,   325,   236,     6,   319,   234,   319,   339,   265,   234,
     331,   339,   233,   239,     6,     6,     6,   234,   234,   120,
     286,   286,   331,     6,   234,   234,     6,     6,   331,   174,
     285,   234,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,   235,   265,   265,   265,   265,   265,   239,   239,
     239,   231,   265,   265,   276,   265,   239,   239,   239,   239,
     231,   265,   231,     6,     4,   265,     6,   235,   331,   331,
     331,     4,     6,   331,   331,   331,   331,   331,   331,   331,
     234,   234,     7,     6,     7,   319,   319,   319,   234,   234,
     234,   232,     6,   319,   331,   319,     6,     6,   319,   328,
     235,     5,   331,   234,   234,   234,   234,   234,   234,   234,
     331,     6,   334,   234,   319,   233,     6,     6,   170,   319,
     319,   319,     6,     6,     7,   265,   239,   239,   265,   239,
     319,     4,   186,   279,   280,   265,   231,   265,   339,   290,
       6,   290,   239,     6,     6,     7,   262,   263,   236,     7,
       6,   335,   235,   239,   319,   262,   265,   342,   342,   230,
     319,   319,   330,   331,   234,     4,     6,     6,     6,     6,
       6,     6,   231,   231,   231,   231,   338,     4,   239,   331,
     339,     7,   273,   319,   333,   277,   319,   319,   328,     6,
       6,     6,   319,   319,     6,    93,     6,   319,     5,   234,
     319,   319,   319,   319,   319,   319,   319,   263,   234,     6,
     285,     6,   319,     6,     6,     6,     6,     6,     4,     6,
       6,   334,   334,   319,   319,   339,   235,   231,   235,   239,
     289,   289,   319,   319,   235,   239,   231,   235,   239,     6,
       6,   330,   328,   328,   328,   328,   328,   221,   328,     6,
     235,   319,     6,     6,   331,   235,   239,     8,   235,   231,
     234,   319,   339,   338,   319,   338,   234,   319,   339,   339,
     239,   239,   307,   307,   331,   339,   319,     6,     4,   336,
       6,   335,   233,   331,     6,   265,   265,   248,   319,   239,
     239,   235,   239,   249,   319,     6,   319,   269,   271,   234,
     235,   239,     7,     7,   235,   235,   235,   235,   234,   235,
       5,   330,   265,   265,   239,   239,   239,   239,   239,   319,
       6,   234,   235,   235,   234,     6,     6,   234,   319,   235,
     235,   235,   233,     6,   331,     7,   234,   319,   235,   239,
     239,   239,   239,   239,   239,     6,   235,   169,   319,   319,
     334,     6,     6,   231,   265,   265,   342,   280,   339,   235,
     235,   235,     6,     6,     7,     6,   236,     6,     6,     6,
     231,   239,   319,   319,   234,   331,   235,   239,   239,   274,
     278,   331,   319,   339,   344,     6,     6,     6,     6,   319,
       6,     6,   235,   319,   319,   319,   319,   319,   235,   330,
     130,   131,   136,   314,   130,   131,   314,   334,   289,   235,
     239,     6,   235,   331,   290,   235,     6,   334,   328,   328,
     328,   328,   328,   319,   235,   235,   235,   235,   231,   234,
       6,   335,   172,   252,   319,   239,   239,   330,     6,   319,
     319,   235,   235,   270,     7,   230,   235,   234,   239,   239,
     239,   239,   239,   235,   234,   328,   331,     6,   234,   328,
       6,   235,   235,   319,     6,   126,   235,   301,   234,   235,
     239,   239,   239,   239,   239,     6,     6,     6,   290,     6,
     234,   319,   319,   235,   239,   274,   339,   231,   319,   319,
     319,   319,   319,   319,     6,   328,     6,   328,     6,     6,
     235,   319,   304,   290,     6,   334,   334,   334,   334,   328,
     334,   307,   249,   231,   239,     6,   234,   319,   235,   239,
     239,   239,   239,   239,   239,   239,   239,     6,   235,   235,
     302,   235,   235,   235,   235,   239,   235,   235,   235,   255,
     319,   330,   235,   319,   319,   319,   319,   319,   319,   328,
     328,   304,     6,     6,     6,     6,   334,     6,     6,     6,
     234,   231,   235,     6,   235,   265,   239,   239,   239,   239,
     239,   239,   235,   235,   253,   338,   258,   234,     6,   319,
     319,   319,   319,   319,   319,     6,   235,   239,   234,   330,
     235,   235,   235,   235,   235,   235,     6,   338,   256,   338,
     235,     6,     6,   235,   239,     6,     6,   338
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
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 537:
#line 5747 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 538:
#line 5755 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 539:
#line 5762 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 540:
#line 5770 "Gmsh.y"
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

  case 541:
#line 5785 "Gmsh.y"
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

  case 542:
#line 5799 "Gmsh.y"
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

  case 543:
#line 5813 "Gmsh.y"
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

  case 544:
#line 5825 "Gmsh.y"
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

  case 545:
#line 5841 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 546:
#line 5850 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 547:
#line 5859 "Gmsh.y"
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

  case 548:
#line 5869 "Gmsh.y"
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

  case 549:
#line 5880 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 550:
#line 5888 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 551:
#line 5896 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 552:
#line 5900 "Gmsh.y"
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

  case 553:
#line 5919 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 554:
#line 5926 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 555:
#line 5932 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 556:
#line 5939 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 557:
#line 5946 "Gmsh.y"
    { init_Options(); ;}
    break;

  case 558:
#line 5948 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 559:
#line 5956 "Gmsh.y"
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

  case 560:
#line 5980 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 561:
#line 5982 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 562:
#line 5988 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 563:
#line 5993 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 564:
#line 6001 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 565:
#line 6010 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 566:
#line 6023 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 567:
#line 6026 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 568:
#line 6030 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13017 "Gmsh.tab.cpp"
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


#line 6033 "Gmsh.y"


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

