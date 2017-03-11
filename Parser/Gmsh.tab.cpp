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
#define YYLAST   13504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  565
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2079

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
    1237,  1252,  1267,  1282,  1291,  1300,  1307,  1312,  1319,  1326,
    1330,  1335,  1341,  1348,  1354,  1358,  1362,  1367,  1373,  1378,
    1384,  1388,  1394,  1402,  1410,  1414,  1422,  1426,  1429,  1432,
    1435,  1438,  1441,  1457,  1460,  1463,  1466,  1469,  1472,  1489,
    1501,  1508,  1517,  1526,  1537,  1539,  1542,  1545,  1547,  1551,
    1555,  1560,  1565,  1567,  1569,  1575,  1587,  1601,  1602,  1610,
    1611,  1625,  1626,  1642,  1643,  1650,  1660,  1663,  1667,  1678,
    1680,  1683,  1689,  1697,  1700,  1703,  1707,  1710,  1714,  1717,
    1721,  1731,  1738,  1740,  1742,  1744,  1746,  1748,  1749,  1752,
    1756,  1766,  1771,  1786,  1787,  1791,  1792,  1794,  1795,  1798,
    1799,  1802,  1803,  1806,  1813,  1821,  1828,  1834,  1838,  1847,
    1853,  1858,  1865,  1877,  1889,  1908,  1927,  1940,  1953,  1966,
    1977,  1988,  1999,  2010,  2021,  2026,  2031,  2036,  2041,  2046,
    2051,  2056,  2061,  2066,  2069,  2073,  2080,  2082,  2084,  2086,
    2089,  2095,  2103,  2114,  2116,  2120,  2123,  2126,  2129,  2133,
    2137,  2141,  2145,  2149,  2153,  2157,  2161,  2165,  2169,  2173,
    2177,  2181,  2185,  2191,  2196,  2201,  2206,  2211,  2216,  2221,
    2226,  2231,  2236,  2241,  2248,  2253,  2258,  2263,  2268,  2273,
    2278,  2283,  2288,  2295,  2302,  2309,  2314,  2316,  2318,  2320,
    2322,  2324,  2326,  2328,  2330,  2332,  2334,  2336,  2337,  2344,
    2346,  2351,  2358,  2360,  2365,  2370,  2375,  2382,  2387,  2392,
    2396,  2399,  2402,  2408,  2414,  2418,  2424,  2431,  2436,  2444,
    2451,  2458,  2465,  2470,  2477,  2482,  2483,  2491,  2493,  2497,
    2499,  2501,  2504,  2505,  2509,  2511,  2514,  2517,  2521,  2525,
    2537,  2547,  2555,  2563,  2565,  2569,  2571,  2573,  2576,  2580,
    2585,  2591,  2593,  2595,  2598,  2602,  2606,  2612,  2617,  2620,
    2623,  2626,  2629,  2633,  2637,  2641,  2645,  2662,  2679,  2696,
    2713,  2715,  2717,  2719,  2723,  2728,  2733,  2738,  2745,  2752,
    2761,  2770,  2775,  2790,  2795,  2800,  2802,  2804,  2808,  2812,
    2822,  2830,  2832,  2838,  2842,  2849,  2851,  2855,  2857,  2859,
    2864,  2869,  2873,  2879,  2886,  2892,  2898,  2904,  2910,  2912,
    2917,  2919,  2921,  2923,  2928,  2935,  2940,  2947,  2952,  2957,
    2962,  2971,  2976,  2981,  2986,  2991,  3000,  3009,  3016,  3021,
    3028,  3033,  3035,  3040,  3045,  3046,  3053,  3058,  3061,  3066,
    3068,  3072,  3078,  3084,  3086,  3088
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
     235,    -1,   146,   182,   232,   319,   233,     6,    -1,   146,
       4,   232,   319,   233,     6,    -1,   146,   344,     6,    -1,
     146,     4,     4,     6,    -1,   171,   335,   234,   290,   235,
      -1,   129,   171,   335,   234,   290,   235,    -1,   204,   319,
     234,   290,   235,    -1,   187,     5,     6,    -1,   188,     5,
       6,    -1,   187,   234,   290,   235,    -1,   129,   187,   234,
     290,   235,    -1,   188,   234,   290,   235,    -1,   129,   188,
     234,   290,   235,    -1,   344,   339,     6,    -1,    73,   230,
     342,   231,     6,    -1,   344,   344,   232,   319,   233,   338,
       6,    -1,   344,   344,   344,   232,   319,   233,     6,    -1,
     344,   319,     6,    -1,   127,   230,     4,   231,   236,     4,
       6,    -1,   165,     4,     6,    -1,   180,     6,    -1,   181,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   234,   319,   239,   319,   239,   319,   239,   319,
     239,   319,   239,   319,   235,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    77,     6,    -1,    78,     6,    -1,   112,
       6,    -1,   113,   234,   334,   235,   234,   334,   235,   234,
     330,   235,   234,   319,   239,   319,   235,     6,    -1,   185,
     230,   234,   334,   235,   239,   339,   239,   339,   231,     6,
      -1,   173,   230,   319,     8,   319,   231,    -1,   173,   230,
     319,     8,   319,     8,   319,   231,    -1,   173,     4,   174,
     234,   319,     8,   319,   235,    -1,   173,     4,   174,   234,
     319,     8,   319,     8,   319,   235,    -1,   175,    -1,   186,
       4,    -1,   186,   339,    -1,   183,    -1,   184,   344,     6,
      -1,   184,   339,     6,    -1,   176,   230,   319,   231,    -1,
     177,   230,   319,   231,    -1,   178,    -1,   179,    -1,   134,
     328,   234,   290,   235,    -1,   134,   234,   328,   239,   328,
     239,   319,   235,   234,   290,   235,    -1,   134,   234,   328,
     239,   328,   239,   328,   239,   319,   235,   234,   290,   235,
      -1,    -1,   134,   328,   234,   290,   300,   304,   235,    -1,
      -1,   134,   234,   328,   239,   328,   239,   319,   235,   234,
     290,   301,   304,   235,    -1,    -1,   134,   234,   328,   239,
     328,   239,   328,   239,   319,   235,   234,   290,   302,   304,
     235,    -1,    -1,   134,   234,   290,   303,   304,   235,    -1,
     134,   234,   290,   235,   126,   107,   234,   319,   235,    -1,
     116,   331,    -1,   121,   116,   331,    -1,   118,   234,   334,
     235,   234,   334,   235,   234,   319,   235,    -1,   305,    -1,
     304,   305,    -1,   151,   234,   319,   235,     6,    -1,   151,
     234,   331,   239,   331,   235,     6,    -1,   152,     6,    -1,
     143,     6,    -1,   143,   319,     6,    -1,   157,     6,    -1,
     157,   159,     6,    -1,   158,     6,    -1,   158,   159,     6,
      -1,   153,   230,   319,   231,     7,   331,   126,   319,     6,
      -1,   126,     4,   232,   319,   233,     6,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,    -1,   146,
       6,    -1,   146,   319,     6,    -1,   306,   234,   290,   307,
     235,   234,   290,   307,   235,    -1,   104,   230,   338,   231,
      -1,   306,   230,   319,   231,     7,   234,   290,   307,   235,
     234,   290,   307,   235,     6,    -1,    -1,   126,     4,   319,
      -1,    -1,     4,    -1,    -1,     7,   331,    -1,    -1,     7,
     319,    -1,    -1,   136,   331,    -1,   108,   109,   331,     7,
     319,     6,    -1,   122,    92,   332,     7,   319,   310,     6,
      -1,   122,    95,   332,   312,   311,     6,    -1,   122,    97,
     332,   312,     6,    -1,   160,   332,     6,    -1,   149,    95,
     234,   334,   235,     7,   319,     6,    -1,   143,    95,   332,
     313,     6,    -1,   143,    97,   332,     6,    -1,   144,    95,
     332,     7,   319,     6,    -1,   125,    92,   234,   334,   235,
       7,   234,   334,   235,   314,     6,    -1,   125,    95,   234,
     334,   235,     7,   234,   334,   235,   314,     6,    -1,   125,
      92,   234,   334,   235,     7,   234,   334,   235,   130,   234,
     328,   239,   328,   239,   319,   235,     6,    -1,   125,    95,
     234,   334,   235,     7,   234,   334,   235,   130,   234,   328,
     239,   328,   239,   319,   235,     6,    -1,   125,    92,   234,
     334,   235,     7,   234,   334,   235,   131,   328,     6,    -1,
     125,    95,   234,   334,   235,     7,   234,   334,   235,   131,
     328,     6,    -1,   125,    95,   319,   234,   334,   235,     7,
     319,   234,   334,   235,     6,    -1,    89,   234,   334,   235,
     174,    95,   234,   319,   235,     6,    -1,    92,   234,   334,
     235,   174,    95,   234,   319,   235,     6,    -1,    89,   234,
     334,   235,   174,    97,   234,   319,   235,     6,    -1,    92,
     234,   334,   235,   174,    97,   234,   319,   235,     6,    -1,
      95,   234,   334,   235,   174,    97,   234,   319,   235,     6,
      -1,   150,    95,   332,     6,    -1,   150,    92,   332,     6,
      -1,   114,    89,   332,     6,    -1,   114,    92,   332,     6,
      -1,   114,    95,   332,     6,    -1,   128,    92,   331,     6,
      -1,   124,    92,   331,     6,    -1,   124,    95,   331,     6,
      -1,   124,    97,   331,     6,    -1,   147,     6,    -1,   147,
       4,     6,    -1,   147,    89,   234,   334,   235,     6,    -1,
     195,    -1,   196,    -1,   197,    -1,   317,     6,    -1,   317,
     234,   331,   235,     6,    -1,   317,   234,   331,   239,   331,
     235,     6,    -1,   317,   230,   331,   231,   234,   331,   239,
     331,   235,     6,    -1,   320,    -1,   230,   319,   231,    -1,
     221,   319,    -1,   220,   319,    -1,   225,   319,    -1,   319,
     221,   319,    -1,   319,   220,   319,    -1,   319,   222,   319,
      -1,   319,   223,   319,    -1,   319,   224,   319,    -1,   319,
     229,   319,    -1,   319,   216,   319,    -1,   319,   217,   319,
      -1,   319,   219,   319,    -1,   319,   218,   319,    -1,   319,
     215,   319,    -1,   319,   214,   319,    -1,   319,   213,   319,
      -1,   319,   212,   319,    -1,   319,   211,   319,     8,   319,
      -1,    16,   264,   319,   265,    -1,    17,   264,   319,   265,
      -1,    18,   264,   319,   265,    -1,    19,   264,   319,   265,
      -1,    20,   264,   319,   265,    -1,    21,   264,   319,   265,
      -1,    22,   264,   319,   265,    -1,    23,   264,   319,   265,
      -1,    24,   264,   319,   265,    -1,    26,   264,   319,   265,
      -1,    27,   264,   319,   239,   319,   265,    -1,    28,   264,
     319,   265,    -1,    29,   264,   319,   265,    -1,    30,   264,
     319,   265,    -1,    31,   264,   319,   265,    -1,    32,   264,
     319,   265,    -1,    33,   264,   319,   265,    -1,    34,   264,
     319,   265,    -1,    35,   264,   319,   265,    -1,    36,   264,
     319,   239,   319,   265,    -1,    37,   264,   319,   239,   319,
     265,    -1,    38,   264,   319,   239,   319,   265,    -1,    25,
     264,   319,   265,    -1,     3,    -1,    10,    -1,    15,    -1,
      11,    -1,    12,    -1,   200,    -1,   201,    -1,   202,    -1,
      74,    -1,    75,    -1,    76,    -1,    -1,    82,   264,   319,
     321,   274,   265,    -1,   322,    -1,   193,   264,   338,   265,
      -1,   193,   264,   338,   239,   319,   265,    -1,   324,    -1,
     344,   232,   319,   233,    -1,   344,   230,   319,   231,    -1,
     198,   230,   324,   231,    -1,   198,   230,   324,   236,   325,
     231,    -1,   199,   230,   339,   231,    -1,   237,   344,   264,
     265,    -1,   237,   344,     9,    -1,   237,     9,    -1,   344,
     263,    -1,   344,   232,   319,   233,   263,    -1,   344,   230,
     319,   231,   263,    -1,   344,   236,   325,    -1,   344,     9,
     344,   236,   325,    -1,   344,   232,   319,   233,   236,     4,
      -1,   344,   236,     4,   263,    -1,   344,   232,   319,   233,
     236,     4,   263,    -1,   189,   230,   338,   239,   319,   231,
      -1,    56,   230,   331,   239,   331,   231,    -1,    57,   264,
     338,   239,   338,   265,    -1,    55,   264,   338,   265,    -1,
      58,   264,   338,   239,   338,   265,    -1,    63,   230,   342,
     231,    -1,    -1,    83,   324,   327,   323,   232,   275,   233,
      -1,   344,    -1,   344,     9,   344,    -1,     4,    -1,    85,
      -1,    85,   319,    -1,    -1,   230,   326,   231,    -1,   329,
      -1,   221,   328,    -1,   220,   328,    -1,   328,   221,   328,
      -1,   328,   220,   328,    -1,   234,   319,   239,   319,   239,
     319,   239,   319,   239,   319,   235,    -1,   234,   319,   239,
     319,   239,   319,   239,   319,   235,    -1,   234,   319,   239,
     319,   239,   319,   235,    -1,   230,   319,   239,   319,   239,
     319,   231,    -1,   331,    -1,   330,   239,   331,    -1,   319,
      -1,   333,    -1,   234,   235,    -1,   234,   334,   235,    -1,
     221,   234,   334,   235,    -1,   319,   222,   234,   334,   235,
      -1,   331,    -1,     5,    -1,   221,   333,    -1,   319,   222,
     333,    -1,   319,     8,   319,    -1,   319,     8,   319,     8,
     319,    -1,    89,   234,   319,   235,    -1,    89,     5,    -1,
      92,     5,    -1,    95,     5,    -1,    97,     5,    -1,   123,
      89,   332,    -1,   123,    92,   332,    -1,   123,    95,   332,
      -1,   123,    97,   332,    -1,    89,   174,    64,   234,   319,
     239,   319,   239,   319,   239,   319,   239,   319,   239,   319,
     235,    -1,    92,   174,    64,   234,   319,   239,   319,   239,
     319,   239,   319,   239,   319,   239,   319,   235,    -1,    95,
     174,    64,   234,   319,   239,   319,   239,   319,   239,   319,
     239,   319,   239,   319,   235,    -1,    97,   174,    64,   234,
     319,   239,   319,   239,   319,   239,   319,   239,   319,   239,
     319,   235,    -1,   288,    -1,   299,    -1,   308,    -1,   344,
     264,   265,    -1,    39,   232,   344,   233,    -1,    39,   232,
     333,   233,    -1,    39,   230,   333,   231,    -1,    39,   264,
     234,   334,   235,   265,    -1,   344,   264,   234,   334,   235,
     265,    -1,    40,   264,   319,   239,   319,   239,   319,   265,
      -1,    41,   264,   319,   239,   319,   239,   319,   265,    -1,
      42,   264,   338,   265,    -1,    43,   264,   319,   239,   319,
     239,   319,   239,   319,   239,   319,   239,   319,   265,    -1,
     194,   264,   333,   265,    -1,    32,   264,   333,   265,    -1,
     319,    -1,   333,    -1,   334,   239,   319,    -1,   334,   239,
     333,    -1,   234,   319,   239,   319,   239,   319,   239,   319,
     235,    -1,   234,   319,   239,   319,   239,   319,   235,    -1,
     344,    -1,     4,   236,   171,   236,     4,    -1,   234,   337,
     235,    -1,   344,   232,   319,   233,   236,   172,    -1,   335,
      -1,   337,   239,   335,    -1,   339,    -1,   344,    -1,   344,
     232,   319,   233,    -1,   344,   230,   319,   231,    -1,   344,
     236,   325,    -1,   344,     9,   344,   236,   325,    -1,   344,
     232,   319,   233,   236,     4,    -1,   123,    89,   234,   319,
     235,    -1,   123,    92,   234,   319,   235,    -1,   123,    95,
     234,   319,   235,    -1,   123,    97,   234,   319,   235,    -1,
       5,    -1,   205,   232,   344,   233,    -1,    67,    -1,   203,
      -1,    72,    -1,   191,   230,   338,   231,    -1,   190,   230,
     338,   239,   338,   231,    -1,   192,   264,   338,   265,    -1,
     192,   264,   338,   239,   338,   265,    -1,    48,   264,   342,
     265,    -1,    49,   230,   338,   231,    -1,    50,   230,   338,
     231,    -1,    51,   230,   338,   239,   338,   239,   338,   231,
      -1,    46,   264,   342,   265,    -1,    60,   264,   338,   265,
      -1,    61,   264,   338,   265,    -1,    62,   264,   338,   265,
      -1,    59,   264,   319,   239,   338,   239,   338,   265,    -1,
      54,   264,   338,   239,   319,   239,   319,   265,    -1,    54,
     264,   338,   239,   319,   265,    -1,    47,   264,   338,   265,
      -1,    47,   264,   338,   239,   334,   265,    -1,    68,   264,
     338,   265,    -1,    69,    -1,    53,   264,   338,   265,    -1,
      52,   264,   338,   265,    -1,    -1,    86,   264,   339,   340,
     278,   265,    -1,    84,   264,   341,   265,    -1,   237,   319,
      -1,   344,     9,   237,   319,    -1,   338,    -1,   342,   239,
     338,    -1,     4,   238,   234,   319,   235,    -1,   343,   238,
     234,   319,   235,    -1,     4,    -1,   343,    -1,   206,   232,
     338,   233,    -1
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
    2537,  2558,  2580,  2603,  2708,  2724,  2759,  2770,  2776,  2791,
    2819,  2836,  2843,  2855,  2874,  2880,  2886,  2893,  2900,  2907,
    2919,  2992,  3010,  3027,  3042,  3075,  3087,  3111,  3115,  3120,
    3127,  3132,  3142,  3147,  3153,  3161,  3165,  3169,  3178,  3242,
    3258,  3275,  3292,  3314,  3336,  3371,  3379,  3387,  3393,  3400,
    3407,  3427,  3453,  3465,  3477,  3493,  3509,  3526,  3525,  3548,
    3547,  3572,  3571,  3594,  3593,  3614,  3628,  3643,  3658,  3679,
    3682,  3688,  3700,  3720,  3724,  3728,  3732,  3736,  3740,  3744,
    3748,  3757,  3770,  3771,  3772,  3773,  3774,  3778,  3779,  3780,
    3783,  3801,  3818,  3835,  3838,  3854,  3857,  3874,  3877,  3883,
    3886,  3893,  3896,  3903,  3920,  3961,  4005,  4044,  4069,  4078,
    4108,  4134,  4160,  4192,  4219,  4245,  4271,  4297,  4323,  4345,
    4351,  4357,  4363,  4369,  4375,  4401,  4427,  4444,  4461,  4478,
    4490,  4496,  4502,  4514,  4518,  4528,  4539,  4540,  4541,  4545,
    4551,  4563,  4581,  4609,  4610,  4611,  4612,  4613,  4614,  4615,
    4616,  4617,  4624,  4625,  4626,  4627,  4628,  4629,  4630,  4631,
    4632,  4633,  4634,  4635,  4636,  4637,  4638,  4639,  4640,  4641,
    4642,  4643,  4644,  4645,  4646,  4647,  4648,  4649,  4650,  4651,
    4652,  4653,  4654,  4655,  4656,  4657,  4666,  4667,  4668,  4669,
    4670,  4671,  4672,  4673,  4674,  4675,  4676,  4681,  4680,  4688,
    4690,  4695,  4701,  4721,  4739,  4757,  4769,  4779,  4785,  4801,
    4807,  4813,  4832,  4853,  4886,  4908,  4913,  4918,  4928,  4938,
    4943,  4954,  4963,  4968,  4973,  5002,  5001,  5024,  5026,  5031,
    5040,  5042,  5048,  5049,  5055,  5059,  5063,  5067,  5071,  5078,
    5082,  5086,  5090,  5097,  5102,  5109,  5114,  5118,  5123,  5127,
    5135,  5146,  5150,  5162,  5170,  5178,  5185,  5195,  5218,  5224,
    5230,  5236,  5242,  5253,  5264,  5275,  5286,  5292,  5298,  5304,
    5310,  5320,  5330,  5340,  5353,  5365,  5369,  5373,  5377,  5395,
    5403,  5411,  5440,  5450,  5466,  5477,  5482,  5486,  5490,  5502,
    5506,  5518,  5535,  5545,  5549,  5564,  5569,  5576,  5580,  5593,
    5607,  5624,  5652,  5656,  5664,  5670,  5676,  5682,  5691,  5695,
    5699,  5707,  5713,  5719,  5727,  5735,  5742,  5750,  5765,  5779,
    5793,  5805,  5821,  5830,  5839,  5849,  5860,  5868,  5876,  5880,
    5899,  5906,  5912,  5919,  5927,  5926,  5936,  5960,  5962,  5968,
    5973,  5981,  5990,  6003,  6006,  6010
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
     292,   293,   293,   294,   295,   295,   295,   295,   295,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   297,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   299,   299,   299,   300,   299,   301,
     299,   302,   299,   303,   299,   299,   299,   299,   299,   304,
     304,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   306,   306,   306,   306,   306,   307,   307,   307,
     308,   308,   309,   310,   310,   311,   311,   312,   312,   313,
     313,   314,   314,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   316,   316,   316,   317,   317,   317,   318,
     318,   318,   318,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   321,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   323,   322,   324,   324,   325,
     326,   326,   327,   327,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   330,   330,   331,   331,   331,   331,   331,
     331,   332,   332,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   334,   334,   334,   334,   335,
     335,   335,   335,   336,   336,   337,   337,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   340,   339,   339,   341,   341,   342,
     342,   343,   343,   344,   344,   344
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
      14,    14,    14,     8,     8,     6,     4,     6,     6,     3,
       4,     5,     6,     5,     3,     3,     4,     5,     4,     5,
       3,     5,     7,     7,     3,     7,     3,     2,     2,     2,
       2,     2,    15,     2,     2,     2,     2,     2,    16,    11,
       6,     8,     8,    10,     1,     2,     2,     1,     3,     3,
       4,     4,     1,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     0,     6,     9,     2,     3,    10,     1,
       2,     5,     7,     2,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     6,     7,     6,     5,     3,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     3,     6,     1,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     4,     4,     3,
       2,     2,     5,     5,     3,     5,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     0,     7,     1,     3,     1,
       1,     2,     0,     3,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     3,     3,     3,     3,    16,    16,    16,    16,
       1,     1,     1,     3,     4,     4,     4,     6,     6,     8,
       8,     4,    14,     4,     4,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     4,
       4,     3,     5,     6,     5,     5,     5,     5,     1,     4,
       1,     1,     1,     4,     6,     4,     6,     4,     4,     4,
       8,     4,     4,     4,     4,     8,     8,     6,     4,     6,
       4,     1,     4,     4,     0,     6,     4,     2,     4,     1,
       3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   563,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,   303,   304,   305,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,   272,   273,     0,     0,     0,   267,     0,     0,
       0,     0,     0,   356,   357,   358,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   564,     0,   208,     0,     0,     0,     0,     0,   251,
       0,   253,   254,   249,   250,     0,   255,   256,   111,   121,
     563,   452,   447,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,   406,   407,   409,
     410,   408,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   414,   415,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   411,   412,   413,     0,     0,     0,     0,     0,     0,
     490,   491,     0,   492,   465,   363,   419,   422,   286,   466,
     447,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   563,     0,   208,
       0,     0,   353,     0,     0,     0,     0,     0,     0,     0,
       0,   472,     0,   471,     0,     0,     0,     0,     0,   563,
       0,     0,   511,     0,     0,     0,     0,   247,   248,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   530,     0,   551,   532,     0,     0,
       0,     0,     0,   531,     0,     0,     0,     0,   265,   266,
       0,   208,     0,   208,     0,     0,     0,   447,     0,     0,
     208,   359,     0,     0,    76,     0,    63,     0,     0,    67,
      66,    65,    64,    69,    68,    70,    71,     0,     0,     0,
       0,     0,     0,   517,   447,     0,   207,     0,   206,     0,
     174,     0,     0,   517,   518,     0,     0,   559,     0,   109,
     109,     0,   445,     0,     0,     0,     0,     0,   505,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,     0,     0,   479,     0,   480,
       0,   481,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   366,     0,   365,   473,   367,     0,   467,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,   431,     0,     0,     0,     0,     0,     0,
     287,     0,   317,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,   208,     0,   456,   455,     0,     0,     0,     0,   208,
     208,     0,     0,     0,     0,   283,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   319,     0,
       0,     0,     0,     0,     0,     0,   229,   354,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,   246,     0,
       0,     0,     0,     0,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,   268,     0,   234,     0,   235,     0,     0,   365,     0,
     208,     0,     0,     0,     0,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    72,    73,     0,     0,   244,    38,   240,     0,
       0,     0,     0,     0,   203,     0,     0,     0,     0,     0,
       0,     0,   209,     0,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,   450,     0,     0,   448,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   311,     0,     0,
       0,     0,     0,     0,   346,   347,   348,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,   482,   483,   484,   485,     0,     0,     0,     0,
       0,     0,   364,   468,   429,     0,   475,     0,   381,   380,
     379,   378,   374,   375,   377,   376,   369,   368,     0,   370,
     474,   371,   372,   373,   448,     0,     0,   449,   434,     0,
     493,     0,     0,     0,     0,     0,     0,     0,   315,     0,
       0,   144,   145,     0,   147,   148,     0,   150,   151,     0,
     153,   154,     0,   350,     0,   351,     0,   352,     0,     0,
       0,     0,   349,   208,     0,     0,     0,     0,     0,   458,
     457,     0,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   330,     0,     0,   230,     0,     0,   226,     0,     0,
       0,   345,   344,     0,     0,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,     0,     0,     0,     0,
       0,   236,   238,     0,   370,     0,   565,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
     364,     0,    63,     0,     0,     0,     0,    79,     0,    63,
      64,     0,     0,   448,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   561,    28,    26,
       0,     0,     0,     0,     0,   449,   521,    29,     0,     0,
     241,   560,    74,   112,    75,   122,   451,   453,   128,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   405,   392,     0,
     394,   395,   396,   397,   398,   504,   399,   400,   401,     0,
       0,     0,   496,   495,   494,     0,     0,     0,   501,     0,
     442,     0,     0,     0,   444,   126,     0,   477,     0,     0,
       0,     0,     0,   420,   503,   425,     0,   427,   469,     0,
     428,     0,     0,     0,     0,   424,   423,   437,     0,     0,
       0,     0,     0,   364,   313,   318,   316,     0,   326,     0,
       0,     0,     0,     0,     0,     0,     0,   364,   364,   364,
       0,     0,     0,     0,     0,   237,   239,     0,     0,     0,
     198,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   289,     0,   274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,     0,     0,   541,
       0,   548,   537,   538,   539,     0,   553,   552,     0,     0,
     542,   543,   544,   550,   557,   556,     0,   136,     0,   533,
       0,   535,   529,     0,   233,     0,   308,     0,     0,     0,
     360,     0,   562,     0,     0,     0,     0,   101,    63,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,    61,
       0,    39,    40,    41,    42,    43,     0,   424,   423,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,   520,   519,     0,     0,     0,     0,   133,
       0,   129,   130,     0,     0,     0,     0,     0,   158,   158,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   476,   382,   470,   435,   433,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,   325,     0,   146,
       0,   149,     0,   152,     0,   155,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,   293,     0,   296,     0,   298,     0,
     284,   290,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,   331,     0,   228,   227,   355,     0,
       0,    35,    36,     0,     0,     0,     0,   512,     0,     0,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,   309,   208,     0,     0,   524,
     525,   526,   527,     0,    86,     0,     0,     0,     0,    84,
      91,    93,     0,   515,     0,    99,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    34,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    31,     0,   522,     0,    32,     0,     0,   113,   118,
       0,     0,   132,   135,   446,     0,    77,    78,   160,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   177,   178,
       0,     0,     0,     0,   162,   190,   179,   183,   184,   180,
     181,   182,   169,     0,     0,   393,   402,   403,   404,   497,
       0,     0,     0,   440,   441,   443,   127,   418,     0,     0,
       0,     0,   439,   421,   426,   191,   436,   498,   185,     0,
       0,   156,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,     0,     0,     0,
     208,   208,     0,     0,   295,   465,     0,     0,   297,   299,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,   102,   106,     0,   549,     0,     0,
     547,     0,   558,     0,     0,   137,   138,   555,   534,   536,
       0,   307,   307,     0,   361,    85,    63,     0,     0,     0,
       0,    83,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,   436,   242,   243,   210,
     211,   212,   213,     0,     0,     0,     0,     0,   523,     0,
     114,   119,     0,     0,   505,   506,   131,     0,     0,   159,
     163,   164,   170,     0,     0,   189,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   438,     0,
     171,     0,   192,   314,   194,   195,   196,   197,   168,     0,
     187,   193,     0,     0,     0,     0,     0,     0,   462,   461,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   223,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,   328,    37,     0,   510,     0,     0,   262,
     261,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     142,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,    97,   516,     0,     0,    88,     0,     0,     0,    44,
       0,     0,     0,     0,     0,    46,    33,     0,   126,   136,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,   500,     0,     0,     0,     0,     0,
       0,   173,     0,   321,   321,     0,   107,   108,   208,     0,
     201,   202,   285,     0,   291,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   204,     0,     0,
       0,     0,   103,   104,   540,   546,   545,     0,   139,     0,
       0,   310,     0,    92,    94,     0,   100,     0,    82,    89,
      90,    49,     0,     0,     0,     0,   464,     0,     0,     0,
       0,     0,   116,     0,   123,     0,   339,   341,   340,   342,
       0,   343,   176,     0,     0,     0,     0,     0,     0,   288,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,     0,   301,     0,     0,   279,     0,   215,     0,     0,
       0,     0,     0,     0,     0,   509,   263,     0,   143,     0,
     208,   362,     0,   514,     0,    45,     0,     0,     0,    62,
      47,     0,   115,   120,   126,     0,     0,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,   332,     0,
       0,   333,     0,   199,     0,   292,     0,   275,     0,   208,
       0,     0,     0,     0,     0,     0,   167,   105,   259,   307,
      98,     0,     0,     0,     0,     0,     0,   124,   125,     0,
       0,     0,     0,     0,     0,   188,     0,   336,     0,   337,
     338,   459,     0,     0,   281,   218,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    59,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,   300,   280,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,   220,   221,   222,     0,   216,   312,
      50,     0,    57,     0,   252,     0,   502,     0,     0,     0,
       0,     0,     0,   282,     0,     0,    51,     0,     0,   258,
       0,     0,     0,     0,     0,     0,   217,     0,     0,     0,
       0,   486,   487,   488,   489,     0,     0,    54,    52,     0,
      55,     0,   334,   335,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1000,   109,   110,   982,  1758,  1764,
    1251,  1451,  1904,  2045,  1252,  2010,  2069,  1253,  2047,  1254,
    1255,  1455,   398,   543,   544,  1064,   111,   718,   419,  1768,
    1914,  1769,   420,  1653,  1323,  1280,  1281,  1282,  1420,  1605,
    1606,   850,   853,   856,   859,  1502,  1492,   702,   250,   407,
     408,   114,   115,   116,   117,   118,   119,   120,   121,   251,
    1156,  1938,  2001,   886,  1152,  1153,   252,   959,   253,   125,
    1346,  1117,   848,   900,  1874,   126,   127,   128,   129,   254,
     255,  1085,   256,   723,   257,   838,   722,   422,   574,   289,
    1633,   323,   324,   259,   520,   331,  1239,  1444,   417,   413,
    1207,   943,   418,   131,   377
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1708
static const yytype_int16 yypact[] =
{
   10133,    91,    78, 10281, -1708, -1708,   -32,   103,    93,   -97,
     -94,    27,   206,   220,   227,   243,    68,   262,   317,    84,
      94,    25,  -122,  -122,    60,   127,   143,    22,   159,   172,
      39,   242,   313,   336,   346,   379,   385,   394,   406,   412,
     443,   352,   327,   518,   428,   344,   458,  5745,   459,   466,
     395,   -36,   636,   521,   683,    66,   490,   622,    40,   495,
     335,   335,   496,   434,   717, -1708, -1708, -1708, -1708, -1708,
     513,   100,   649,   653,    10,    77,   654,   656,   450,   748,
     755,   762,  5061,   764,   546,   559,   575,    16,     8, -1708,
     582,   585, -1708, -1708,   771,   826,   581, -1708,  4496,   591,
    5165,    32,    33, -1708, -1708, -1708,  9690,   614, -1708, -1708,
   -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708,
   -1708, -1708, -1708,    98, -1708, -1708, -1708, -1708,    58, -1708,
     843,   626,  4831,   389,   632,   870,  9690,  4920,  4920, -1708,
    9690, -1708, -1708, -1708, -1708,  4920, -1708, -1708, -1708, -1708,
     660,   675,   903, -1708, -1708,  3488,    25,  9690,  8253,  9690,
    9690,   690,  9690,  8253,  9690,  9690,   691,  9690,  8253,  9690,
    9690,  9690,  9690,  9690,  9690,  4920,  9690,  9690,  9690,  5973,
     698, -1708,  8253,  5061,  5061,  5061,  4920, -1708, -1708, -1708,
   -1708, -1708,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,   -83,  -122,  -122,  -122,  -122,
    -122,   710,  -122,  -122,   726, -1708, -1708, -1708,  -122,    20,
      30,    31,    34,  5973,   817,   588,   727,  -122,  -122,   739,
     752, -1708, -1708, -1708,  9690,  6201,  9690,  9690,  6429,    49,
   -1708, -1708,   715, -1708,  2571, -1708, -1708, -1708, -1708, -1708,
       7,  9690,  8253,   753,   754,  6657,  5061,  5061,  5061,   770,
     772,   785,   786,  6885,  7113,  7341,   737,  9095,   985,  5973,
      16,   758,   767,   335,   335,   335,  9690,  9690,   248, -1708,
     289,   335,  9164,   310,   111,   791,   794,   796,   799,   801,
     811,   821,  9690,  5061,  5061,  5061,   822,     9,   839, -1708,
    1068,  1078, -1708,   851,   855,   856,  5061,  5061,   859,   860,
     861, -1708,  9690, -1708,  1088,  1089,  9690,  9690,  9690,   202,
    9690,   874, -1708,   935,  9690,  9690,  9690, -1708, -1708,  9690,
   -1708,  -122,  -122,  -122,   884,   885,   886,  -122,  -122,  -122,
    -122,  -122,  -122,  -122, -1708,  -122, -1708, -1708,  -122,  -122,
     887,   891,  -122, -1708,   890,  1118,  1119,   894, -1708, -1708,
    1123, -1708,  1124, -1708,  -122,  9690, 11682,   160,  4920,  9690,
   -1708, -1708,  5973,  5973, -1708,   899,  3488,   621,  1127, -1708,
   -1708, -1708, -1708, -1708, -1708,  9690,  9690,    48,  5973,  1132,
     441,   192,   905,  1134,    51,   907, -1708,   908, 10419,  9690,
   -1708,  1268,   155, -1708,    67,   235,  4124, -1708,   236,  -151,
     -18,  1057, -1708,    25,   909,   911,  3841,  8253,  2603, -1708,
      72, 12076, 12097,  9690, 12118,   325, 12139, 12160,  9690, 12181,
     455, 12202, 12223, 12244, 12265, 12286, 12307,   913, 12328, 12349,
   12370,  1139,  9690,   484,  1159,  1160,  1162,   939,  9690,  9690,
    9690,  9690,  9690,  9690,  9690,  9690,  9690,  9690,  9690,  9690,
    9690,  9690,  9690,  9690,  8253,  9690,  9690,  9690,  9690,  9690,
    9690,  8253,  8253,   937,  9690,  9690,  4920,  9690,  4920,  5973,
    4920,  4920,  4920,  9690, -1708,  1105,  9690, -1708,  1108, -1708,
    1109, -1708,  1111,  5973,  5061,  5061,  5061,  5061,  4920,  4920,
    8253,    25,  3488,   950,  8253,   950, -1708,   950, 12391, -1708,
     519, -1708,    76,  9690,  9690,  9690,  9690,  9690,  9690,  9690,
    9690,  9690,  9690,  9690,  9690,  7569,  9690,  9690,  9690,    25,
    9690,  9690,  1176, -1708,   474, 12412,   532,  9690,  9690,  9690,
   -1708,  1174,  1175,  1175,  8872,  8872,  8872,  8872,  9690,  1177,
    9690,  1178,  9690,  1179,  8253,  8253, 11706,   955,  1182,   956,
   -1708, -1708,  -130, -1708, -1708,  4526,  4716,   335,   335,   389,
     389,  -128,  9164,  9164,  9690,  2630,  -118, -1708,  9690,  9690,
    9690,  9690,  9690,  9690,  9690,  9690,  9690, 12433,  1184,  1183,
    1186,  9690,  1188,  9690,  9690,  2860, -1708, -1708,  8253,  8253,
    8253,  1191,  1192,  9690,  9690,  9690, 12454, -1708, -1708, 12475,
   12496, 12517,  1028,  5227, -1708,   966,  2870, 12538, 12559, 11777,
    4920,  4920,  4920,  4920,  4920,  4920,  4920,  4920,  4920,  9690,
    4920,  4920,  4920,  4920,    11,  3488,  4920,  4920,  4920,    25,
   -1708, -1708,  8253, -1708,  3049, -1708,  3165,  9690,   950,  9690,
   -1708,  9690,  9690,   968, 12580,  3984,   971,   547,  9690,  1197,
     970,   972,   975,   976,  9690, 12601, 11800,   222,   977,  1204,
    1206, -1708, -1708, -1708,  8253,   331, -1708, -1708, -1708,    25,
    9690,  9690,  1176,   982, -1708,   554,    50,    52,   593,   987,
     -22,   712, -1708,  2711, -1708,    36,  8253,    25,  9690,  9690,
    1211,  1212,  8253,  9690,  1213,  4920,  1214, -1708,    25,  1215,
    4920,  9690,   991,   992, -1708,  9690,  3488,  1216,  8253,  1052,
    8253,  1218,  1220, 12622,  1222,  1056,  1224,  1225, 12643,  1226,
    1060,  1229,  1230,  1231,  1232,  1233,  1237, -1708,  1238,  1240,
    1241,  9690, 12664,  1016, -1708, -1708, -1708,  1246, 11754, 11754,
   11754, 11754, 11754, 11754, 11754, 11754, 11754, 11754, 11754,  5455,
   11754, 11754, 11754, 11754,  1200,   366, 11754, 11754, 11754,  5683,
    5911,  6139,  2603,  1027,  1026,    97,  8253,  6367,  6595,   366,
    6823,   366,  1021,  1022,  1023,   294, 10277,  1029,  3514,  1030,
    1032,  1033, -1708, -1708, -1708, -1708,  1031,   145,   366,   -99,
    1037,   583,  1262, -1708, -1708,   366,  3144,  3175,  1503,   938,
     666,   666,   541,   541,   541,   541,   397,   397,  8253,   950,
   -1708,   950,   950,   950,  1035, 12685, 11823,  -160, -1708,  8253,
   -1708,  1265,  1039, 12706, 12727, 12748,  9690,  5973,  1271,  1273,
    1046, 10277,  1041,  1050, 10277,  1044,  1054, 10277,  1047,  1058,
   10277,  1049, 12769, -1708, 12790, -1708, 12811, -1708,   589,   594,
    8253,  1055, -1708, -1708,  3883,  4319,   335,  9690,  9690, -1708,
   -1708,  1059,  1061,  9164,  2625,  1164,   -27,   335,  4417, 12832,
    9972, 12853, 12874, 12895, 12916, 12937, 12958, 12979,  1285,  9690,
    1289, -1708,  9690, 13000, -1708, 11846, 11869, -1708,   595,   596,
     603, -1708, -1708, 11892, 11915,  7051, -1708,  1290,  1291,  1292,
    1064,  9690,  9718,  9690,  9690, -1708, -1708,    38,   357,   417,
     357,  1070,  1071,  1066,   366,   366,  1067,  7279,   366,   366,
     366,   366,  9690,   366,  1294, -1708,  1069,  1076,   432,  1080,
     606, -1708, -1708, 11754,   950,  9757, -1708,  1304,  9393,  1081,
    1084,  1322,  5973, 10957, -1708,  9690,  9690,  9690,  9690,  1432,
     384,   112,  3488,  9690,  1323,  1326,    17, -1708,   608,  1286,
    1287,  5973,    23,  1095, 13021, 11938,  1100,  9690,  8253,  8253,
    8253,  8253,  9690,  1106,  1107,  1112,  1113, -1708, -1708,  1121,
    4920,   383,  1099, 13042, 11961, -1708, -1708, -1708,   445,  7507,
   -1708, -1708, -1708,    59, -1708, -1708, 10277, -1708,  1340, 11754,
     366,   335,   359,  2603, -1708,  5973,  5973,  1341,  5973,   528,
    5973,  5973,  1343,  5973,  1255,  5973,  5973,  5973,  5973,  5973,
    5973,  5973,  5973,  5973,  1535,  1349,  8253, -1708, -1708, -1708,
   -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708,  9690,
   -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708,  9690,
    9690,  9690, -1708, -1708, -1708,   630,  9690,  9690, -1708,  9690,
   -1708,  5973,  4920,  4920, -1708,  1120,  9690, -1708,  9690,  9690,
    9690,  9690,  9690, -1708, -1708, -1708,  1211, -1708, -1708,  5973,
   -1708,  9690,  9690,   642,  1211,  -160,   237, -1708,   657,  5973,
    8253,  1350,  1351,  1353,   846, -1708, -1708,  1355, -1708,   343,
    9690,   343,  9690,   343,  9690,   343,  9690,  1356,  1357,  1359,
    1360,  1361,   662,  1358,  9880, -1708, -1708,   -82,  7735,  7963,
   -1708, -1708, 10982,  -158,  1264,  1365,  9467,  1138,  1367,  1144,
      42,    44,   544, -1708,   -80, -1708,   -27,  1368,  1370,  1371,
    1372,  1373,  1375,  1377,  1378,  1379,  5973, 10277, -1708,  1561,
    1143,  1381,  1382,  1384,  1296,  1387,  1390,  1391,  9690,  5973,
    5973,  5973,  1394,  8191, -1708,  3223,   639,  1395,  1396, -1708,
    8253, -1708, -1708, -1708, -1708,  4920, -1708, -1708,  9690,  4920,
   -1708, -1708, -1708, -1708, 10277, -1708,  1165,  1167,  4920, -1708,
    4920, -1708, -1708,  1168, -1708,  1169, -1708,  1633,  1170,  5973,
   -1708,  1166, -1708, 11007, 11032, 11057, 11082, -1708, -1708,  9690,
    1404,    53,  9690,  1419,  1420,  1700, -1708,  1421,    16,  1424,
    1195,   366,  -122,  -122,  1426, -1708,  1207,  1210,  1208, -1708,
    1428, -1708, -1708, -1708, -1708, -1708,  1211,  -127,   688, 11984,
     664,   669,   671,   672, 13063,  9690,  9690,  9690,  9690, -1708,
    1435,    43,  1211, -1708,  1217,  1437,  9690,  8476,   366,  4168,
    1219,  1205, -1708,  1441,  1442,   114,  1221,  1223,  1334,  1334,
    5973,  1450,  1227,  1228,  1452,  1453,  5973,  1293,  1234,  1454,
    1460,  1464,  1465,  1466,  1467,  1471,  1487,  1488, -1708,  1490,
     679, 11754, 11754, 11754, 11754,   366,  8503,  8815,  8925,  1267,
     366,   366,  1340,   366,  8994,  9037,  9122,  9223, 13084, 11754,
    1269,  1493, 10277, 10277, -1708, -1708, -1708,  1492, -1708,   366,
    1495,   684,  5973,  5973,  5973,  1498,  1500, -1708,  5973, 10277,
    5973, 10277,  5973, 10277,  5973, 10277,  5973,  5973,  5973,  1270,
    1274,  1502,   340, -1708,  9690,  9690,  9690,  1276,  1277,  1278,
    1275, -1708,  1901,  5973, -1708,  9690, -1708,  1507, -1708,  1508,
   -1708, -1708,  9164,   774,  5289, -1708,  1281,  1282,  1284,  1288,
    1295,  1297,  7797,  1513, -1708,  8253, -1708, -1708, -1708,  1299,
    9690, -1708, -1708, 12007,  1514,  1515,  1354, -1708,  9690,  9690,
    9690, -1708,  1517,   508,   493,  1298,  2130,  1300,  9690,    24,
     366,  1303,   366,  3488, -1708, -1708, -1708,  1301,  1519, -1708,
   -1708, -1708, -1708,  1920, -1708,   451,  1306,  1520,  1981, -1708,
   -1708, -1708,    16, -1708,   695, -1708,  9690,   343,  1051,  4920,
   -1708,  1313,  9690,  9690,  5973,  1302, -1708,  1310,  1522,  1524,
    1539,  1540,  1541,  1542,  1545,  1262, 13105, 13126, 13147, 13168,
   -1708, -1708,  4920, -1708,  1548, -1708,  9297,  4588, 10277, -1708,
    1546,  6429, -1708, -1708, -1708,  1340, -1708, -1708, -1708,  9690,
    9690,   335,  1549,  1550,  1552, -1708,  9690,  9690, -1708, -1708,
    1553,  1461,  1554,  9690, -1708, -1708, -1708, -1708, -1708, -1708,
   -1708, -1708, -1708,  1556,  1328, -1708, -1708, -1708, -1708, -1708,
    9690,  9690,  9690, -1708, -1708, -1708,  1205, -1708,  9690,  9690,
    9690,  9690, -1708, -1708, -1708, -1708,  -160, -1708, -1708,  1330,
    1559,  1293,  1560,  9690, -1708,  1563,  1564,  1565,  1567,  1571,
     647,  1573,  8253,  8253,  9690, -1708,  8872, 11107, 13189,  3453,
     389,   389,  9690,  9690, -1708,   148,  1344, 13210, -1708, -1708,
   11132,   -77, -1708,  1578,  1579,  5973,   335,   335,   335,   335,
     335,  5517,  1580, -1708,   700,  9690,  2021,  1583, -1708, -1708,
    5973,  3797,   579, 13231, -1708, -1708,  8560, -1708,  4920,  9690,
   -1708,  4920, 10277,  8788,  3488,  1352, -1708, -1708, -1708, -1708,
    1362,  3984,  3984,  5973, -1708, -1708,  3488,  9690,  1584,  1588,
      17, -1708,  1587, -1708,    16, 12030,  5973,  1590,   357,   357,
    9690,  9340,  9420,   703, -1708,  9690,   320, -1708, -1708, -1708,
   -1708, -1708, -1708,  1353,  1356,  1357,  1359,  1591, -1708,  9690,
   -1708, -1708,  1366,   706,  1468,  1592, -1708, 11157, 11182,   361,
   -1708, -1708, -1708, 11207, 11232, -1708,  1374, -1708, 11257,  1589,
    5973, 11754, 11754,  9563,  9722,  9850,  9943, 10333, -1708,  9690,
   -1708,  1603, -1708, 10277, -1708, -1708, -1708, -1708, -1708,  1385,
   -1708, -1708,   708,   711, 11730,  2061,  1605,  1386, -1708, -1708,
    9690,  1380,  1383, 11282, 12053,  1606,  5973,  1609,  1388,  9690,
   -1708, -1708,   713,   -50,   -46,   -43,   -30,   -21,  8025,    -7,
   -1708,  1607, 11307, -1708, -1708,  1455, -1708,  9690,  9690, -1708,
   -1708,  8253,  2098,  1623,  1399, 11754,   366,  4920, 10277, -1708,
   -1708,    24,  3488,  1398,  1400,  1402,  1625,  2285, -1708,  1651,
    1653, -1708, -1708,  1427,  1654, -1708,  1656,  1659,   460, 10277,
    9690,  9690,  1436,  5973,   716, 10277, -1708, 10377,  1120,  1167,
    5973, -1708,  9690,  3488,    25,  1660,  1663,  1665,  1666,  9690,
    1667,  1668,   719, -1708, -1708,  9690,  9690,  9690,  9690,  9690,
   11332, -1708,  5973,    37,   382,  8253, -1708, -1708,   389,  4253,
   -1708, -1708, -1708,  1669, -1708,  1459,  5973, -1708, 11357,  1671,
    8253,   335,   335,   335,   335,   335, -1708, -1708,  9690, 11382,
   11407,   731, -1708, -1708, -1708, -1708, -1708,   741, -1708,  1469,
    1462, -1708,  1689, -1708, -1708,    16, -1708,  1526, -1708, -1708,
   -1708, -1708,  9690, 10406, 10435,  5973, -1708,  1693,  9690,  9690,
    1470,  1472, -1708,  2410, -1708,  1474, -1708, -1708, -1708, -1708,
   11432, -1708, -1708,  1475, 10464, 10493, 10522, 10551, 10580, -1708,
     742,  1476,   335,  5973,  1695,  1477,   335,  1696,   759,  1473,
   -1708,  9690, -1708,  1706,  1604,  9918,  1479, -1708,   760,   135,
     161,   178,   198,   221,  2334, -1708, -1708,  1723, -1708,  1725,
   -1708, -1708,  1727, -1708,  1501, 10277,  9690,  9690,   768, -1708,
   10277, 10609, -1708, -1708,  1120,  3488,  1505, -1708,  9690,  9690,
    9690,  9690,  9690,  9690,  1731,   335,   116, -1708, -1708,   335,
     122, -1708,  1733, -1708, 11457, -1708,  9690, -1708,   -27, -1708,
    1734,  8253,  8253,  8253,  8253,  8025, -1708, -1708, -1708,  3984,
   -1708,  9690, 13252, 10638,    41,  9690,  1506, -1708, -1708, 10667,
   10696, 10725, 10754, 10783, 10812, -1708,   223, -1708,   231, -1708,
   -1708, -1708,  2489,   810, 10007, -1708,   773,   778,   779,   807,
     256,   809,  1509,   814, -1708,  9690, -1708,  5973, 11482, -1708,
    9690,  9690,  9690,  9690,  9690,  9690,   335,   335, -1708, -1708,
   -1708,   -27,  1736,  1737,  1756,  1757,  8253,  1759,  1760,  1762,
    1536, 13273,   815,  1763, 11507, 11754, 10841, 10870, 10899, 10928,
     260,   277,   853, -1708, -1708, -1708, -1708,   837, -1708, -1708,
   -1708,  4920, -1708,  1557, -1708,  1780, -1708,  9690,  9690,  9690,
    9690,  9690,  9690, -1708,  1781,   842, -1708,  1562,  5973, -1708,
   11532, 11557, 11582, 11607, 11632, 11657, -1708,  1782,  4920,  4920,
     847, -1708, -1708, -1708, -1708,  1787,  1788, -1708, -1708,   848,
   -1708,  1789, -1708, -1708,  1791,  4920, -1708, -1708, -1708
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1708, -1708, -1708, -1708,   527, -1708, -1708, -1708, -1708,  -152,
   -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708,
   -1708, -1708,  -666,  -131,  3589,  2825, -1708,  1389, -1708, -1708,
   -1708, -1708, -1708, -1708, -1707, -1708,   478,   316,    35, -1708,
      61, -1708, -1708, -1708, -1708,   264,   517,  1805,    21,  -570,
    -275, -1708, -1708, -1708, -1708, -1708, -1708, -1708, -1708,  1807,
   -1708, -1708, -1708, -1708, -1153, -1147,  1808, -1605,  1809, -1708,
   -1708, -1708,  1260, -1708,    28, -1708, -1708, -1708, -1708,  1929,
   -1708, -1708,  1811, -1708,   -17,  -670, -1708, -1708,    26, -1708,
   -1552,   284,  -153,  2515,  -117,  -278,   195, -1708,   -63,   -28,
   -1708, -1708,  -484, -1708,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -524
static const yytype_int16 yytable[] =
{
     132,   399,   569,  1383,   151,  1381,  1743,  1744,   795,   881,
     882,   973,   333,   602,   307,   150,   539,   585,   152,   981,
     329,   150,   986,  1712,   113,   494,   161,  1245,  1603,   150,
     454,   455,   456,   139,   605,   497,   499,   370,   372,   501,
    1006,   430,   998,   166,   260,  1187,   435,  1986,  1376,  1471,
    1378,   440,   677,   150,   161,   150,   166,  1435,   521,   264,
     689,  1850,   577,   578,   381,   453,  1277,   393,   394,   402,
     365,   310,   369,   264,   412,   415,   707,  1368,     5,   260,
     265,   311,   716,   312,   332,   814,   288,   290,   717,   293,
     577,   578,   577,   578,   993,   366,   654,     4,   656,  1145,
     393,   394,   577,   578,   403,   665,   539,  -520,   153,   876,
     154,   883,   447,   551,   552,   553,  1146,   135,  1782,  1228,
    1488,   887,  1967,   457,  1147,  1148,  1149,   424,  1969,   404,
    1150,  1151,  1095,   137,   414,   414,   138,  1096,   577,   578,
     577,   578,   414,   577,   578,   546,   928,   481,   930,   482,
     598,   599,   600,   425,   406,   260,   523,  1364,   276,  1382,
     260,   277,  1709,   611,   612,   260,   313,  1871,  1872,   539,
     577,   578,   414,  1873,   577,   578,   260,   577,   578,   260,
     260,   260,   260,   414,  1246,  1247,  1248,  1249,   136,  1810,
     577,   578,   308,  1811,   495,   303,  1812,   304,   686,   577,
     578,  1377,   133,  1379,   498,   500,   134,  1956,   502,  1813,
    1604,   280,   141,   577,   578,   719,   107,   107,  1814,   678,
     679,   717,   107,   107,  1436,  1437,   142,   281,   282,   972,
     260,   107,  1815,   143,   393,   394,  1381,   540,   334,   541,
    1870,   603,   260,   542,   309,   260,   522,   134,   942,   144,
     330,  1238,   162,   999,   496,   107,   163,   107,  1250,   260,
     999,   140,   260,   260,   260,   260,   371,   373,   146,   167,
     260,   260,   260,   168,  1188,  1987,   260,   332,   393,   394,
     162,   690,   167,   691,   989,  -518,   990,   692,   382,   153,
     157,   154,   383,  1908,   158,   874,   875,   708,   145,   709,
     260,   260,   260,   710,  1229,  1232,   153,   729,   154,   572,
     573,   730,   888,   260,   260,   663,   148,   581,   586,   389,
     390,   391,   392,   147,   393,   394,   149,   540,   379,   541,
    1074,   258,   380,   542,   577,   578,   577,   578,   979,   393,
     394,   588,   577,   578,  1982,   589,  1555,  1556,  1231,   922,
    1228,   802,   803,   804,   805,   577,   578,   159,   669,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   160,  1941,   414,   682,   538,   683,   260,
     260,   577,   578,  1705,  1092,   955,   705,   393,   394,   164,
     661,  1228,   662,   405,   706,   260,   542,   811,   577,   578,
    1942,   693,   165,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,  1943,   577,   578,
     724,   538,   180,   789,   260,   791,  1330,   793,   794,   389,
     390,   391,   392,   183,  1335,  2012,   184,  1944,   622,   185,
     134,   577,   578,   577,   578,   806,   807,   868,   869,   393,
     394,   577,   578,  1348,  1286,  1350,  1287,  1352,  1616,  1354,
    1945,   179,  1996,   451,   393,   394,   711,   714,   577,   578,
    1997,   260,   169,  1337,   712,   715,   577,   578,   260,   785,
     577,   578,   579,   414,   810,   414,   260,   414,   414,   414,
     263,   908,   909,   910,   809,  2006,  2060,   577,   578,  2041,
     260,   260,   260,   260,   260,   414,   414,   260,   152,   577,
     578,   260,  1875,  1876,  1595,  1596,  2042,   258,  1873,    59,
      60,    61,    62,   580,   181,  1084,   852,   855,   858,   861,
     577,   578,   260,   715,    73,   950,   834,    76,   389,   390,
     391,   980,   316,   170,   587,   317,   974,   393,   394,   550,
     389,   390,   391,   392,  -523,   284,   285,   559,   561,   563,
     735,   260,   260,   568,   730,   286,   171,   978,   929,   287,
     931,   932,   933,   934,   935,   936,   172,   938,   939,   940,
     941,   577,   578,   946,   947,   948,  1457,  1728,   682,  1001,
     683,   389,   390,   391,   392,  1008,   715,   682,  1134,   683,
     406,   406,  1473,   879,   880,   260,   260,   260,   573,   173,
     269,   393,   394,   270,  1271,   174,   271,   945,   272,   659,
     536,   537,   730,  1292,   175,  1293,   538,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   176,   414,   414,   414,
     414,   944,   177,   414,   414,   414,   949,  1410,   682,   260,
     683,  1689,  1011,  1690,   284,   285,  1190,  1015,   389,   390,
     391,   392,   182,   682,   286,   683,   666,   667,   292,  1075,
    1145,  1210,   682,   178,   683,   684,  1275,   504,   393,   394,
     505,   260,   680,   506,   730,   507,   983,  1146,   186,   261,
     740,  1841,   150,   340,   730,  1147,  1148,  1149,  1020,  1842,
     262,  1150,  1151,   260,  1002,   682,  1107,   683,   839,   260,
     670,  1103,   414,   671,   279,  1013,   672,   414,   673,   753,
     278,   294,  1108,   730,   682,   260,   683,   260,   266,   283,
     291,   267,   730,   268,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   302,   305,   306,   314,   350,   351,   352,
     353,   315,   318,  1132,   813,   354,   355,   356,   730,   319,
     357,   533,   534,   659,   536,   537,   320,   842,   325,  1617,
     538,   730,   358,   792,   359,   273,   326,   337,   274,  1380,
     275,  1626,   961,   260,   157,  1973,   962,   550,   988,   327,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,   994,   328,   295,   995,   538,   996,
     296,   387,   335,   339,  1729,   336,   297,   298,  1098,   299,
     300,   367,   730,   170,  1130,   260,  1381,   991,   730,  1131,
    1173,  1174,   338,   730,   730,   730,   260,   301,  1175,  1230,
    1233,  1213,   730,  1241,   260,   730,   378,   730,  2022,   384,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,   385,  1315,   409,   260,   538,   730,
    1411,  1260,  1261,  1262,  1263,  1381,   410,  1334,   360,   361,
     362,   730,   529,   530,   531,   532,   533,   534,   659,   536,
     537,   363,  1339,   364,   107,   538,   730,  1361,   134,  1461,
    1145,   730,  1137,   730,  1462,   421,  1463,  1464,   730,  1143,
     730,   730,   423,  1154,  1514,   393,   394,  1146,   730,  1539,
     433,   438,  -519,   730,  1458,  1147,  1148,  1149,   452,  1310,
    1623,  1150,  1151,   503,  1624,  1721,  1145,  1270,  1762,   730,
     489,  1771,  1763,  1793,  1234,  1772,  1794,   730,  1809,   380,
     730,  1847,  1763,  1146,  1863,  1848,   492,   508,  1763,   260,
    1443,  1147,  1148,  1149,  1628,  1629,  1897,  1150,  1151,   511,
     730,   564,  1345,  1240,  1336,  1338,  1898,  1924,   260,  1145,
     715,  1763,   512,   547,   548,   260,   260,   260,   260,   567,
    1701,  1702,   570,  1341,  1932,  1940,  1146,   414,   730,   730,
     554,   571,   555,  1954,  1147,  1148,  1149,  1763,  2002,  1572,
    1150,  1151,   730,  2003,  2004,   556,   557,   730,   730,  1320,
    1321,   590,   260,   260,   591,   260,   592,   260,   260,   593,
     260,   594,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   595,  2005,   260,  2007,  1999,   730,  1285,   730,  2009,
    2033,   596,   601,  1848,  1763,   150,   340,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,   604,  2044,  1414,   606,   538,   730,  2057,   260,   414,
     414,  2058,  2071,  2074,   607,   608,  1763,  2075,  2043,   609,
     610,   613,   614,   615,   617,   618,   260,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   260,   260,   624,   625,
     350,   351,   352,   353,   633,   634,   635,   646,   354,   355,
     356,   647,   649,   357,   650,   651,  1336,  1338,   652,   653,
     655,  1115,  1415,   668,   674,   358,  1417,   359,   681,   687,
     688,   133,   721,   694,   747,  1421,   751,  1422,   725,  1611,
     726,  1612,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,   260,  1622,   754,   755,   538,   756,   797,
     757,   786,   799,   800,   387,   801,   260,   260,   260,   538,
     837,   846,   847,   863,   865,   867,   871,   260,   872,   901,
     873,   899,   414,   902,   904,  1459,   414,   911,   912,   920,
     923,   956,   960,   964,   965,   414,   966,   414,   523,   967,
     968,   976,   977,   975,   987,  1005,   260,   992,  1007,  1010,
    1012,  1014,  1017,  1021,  1018,  1025,  1022,  1026,  1879,  1028,
    1029,  1030,  1031,  1033,  1034,   332,  1035,  1036,  1037,  1038,
    1039,   360,   361,   362,  1040,  1041,  1221,  1042,  1043,  1479,
    1046,  1483,  1047,  1827,   363,   414,   364,   107,  1072,  1073,
    1081,  1082,  1083,  1086,  1088,  1244,  1089,  1090,  1097,  1099,
    1091,  1104,  1109,  1110,   704,  1116,   260,  1119,  1584,  1118,
    1120,  1121,   682,  1122,   683,  1123,  1124,   260,  1126,  1125,
    1144,  1133,  1166,   260,  1140,  1168,  1141,  1179,  1180,  1181,
    1182,  1193,  1194,  1206,  1618,  1195,  1198,  1209,  1208,  1288,
    1289,  1215,  1291,  1212,  1294,  1295,  1218,  1297,  1219,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1220,  1236,
    1237,  1256,  1242,  1243,  -521,  1272,  1265,  1266,  1269,   260,
     260,   260,  1267,  1268,  1279,   260,  1752,   260,  1290,   260,
    1296,   260,  1298,   260,   260,   260,  1309,  1342,  1343,  1322,
    1344,  1347,  1362,  1356,  1357,  1319,  1358,  1359,  1360,  1370,
     260,  1369,  1373,  1374,  1375,  1384,  1385,  1395,  1386,  1387,
    1388,   260,  1389,  1331,  1390,  1391,  1392,  1396,  1397,   260,
    1398,  1399,   260,  1340,  1400,  1610,  1401,  1402,  1407,  1412,
    1413,  1428,  1418,  1424,  1426,  1678,  1419,  1423,  1571,  1647,
    1434,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   728,   536,   537,  1439,  1440,  1446,  1442,   538,
    1445,   682,  1450,   683,  1456,  1692,  1693,  1452,  1227,   332,
    1453,  1470,  1454,  1475,  1485,   414,   414,  1486,  1487,  1651,
    1393,   260,  1484,  1474,  1491,  1489,  1495,  1490,  1498,  1499,
    1504,  1496,  1497,  1404,  1405,  1406,  1505,  1501,  1503,   414,
    1506,  1507,  1508,  1509,   260,  1773,   523,  1510,   260,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,  1511,  1512,  1513,  1536,   538,  1523,  1535,
    1534,  1538,  1543,  1427,  1552,  1678,  1544,  1563,  1553,  1554,
    1560,  1561,  1562,  1568,  1569,  1575,  1576,  1659,  1577,  1583,
    1588,  1589,  1578,  1594,  1590,  1614,  1636,  1620,  1696,  1579,
    1637,  1580,  1885,  1585,  1608,  1734,  1635,  1598,  1736,  1601,
    1613,  1308,  1619,  1630,  -522,  1638,  1639,  1640,  1641,   260,
     260,  1642,  1648,  1652,  1666,  1660,  1661,  1902,  1662,  1665,
    1667,  1669,  1670,  1482,  1679,  1680,  1682,  1394,  1733,  1684,
    1685,  1686,   260,  1687,  1494,  1739,  1740,  1688,   260,  1691,
    1500,   406,   406,  1706,  1710,  1711,  1720,   260,  1746,  1724,
    1748,  1741,  1749,  1751,  1781,   414,  1755,  1766,   414,  1774,
    1770,  1742,  1713,  1714,  1715,  1716,  1717,  1719,  1779,  1791,
     260,  1797,  1804,  1816,  1821,  1800,  1806,  1240,  1801,  1792,
    1798,   332,  1807,   260,  1818,  1949,  1540,  1541,  1542,  1823,
    1824,  1833,  1545,  1830,  1546,  1831,  1547,  1832,  1548,  1425,
    1549,  1550,  1551,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,  1566,  1835,  1836,
    1838,   538,  1839,  1837,  1974,  1840,  1856,   260,  1574,  1857,
    1845,  1858,  1859,  1861,  1862,  1882,  1582,  1887,  1878,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     728,   536,   537,  1888,  1883,  1901,  1900,   538,  1903,  1909,
    1899,  1928,  1931,   260,  1916,  1912,  1441,  1913,  1933,  1918,
    1925,  1929,  1935,  1939,  1829,   260,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,   260,  1947,
    1936,  1948,   538,  1950,   414,  1951,  1958,  1965,  1634,  1970,
    1975,  1989,  2023,  2024,  2008,  1854,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
     260,  1650,  2025,  2026,   538,  2028,  2029,   260,  2030,  2034,
    2031,  1855,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,  2049,  2056,  2067,   260,
     538,  2048,   260,  2072,  2073,  2076,  2059,  2077,  1472,  1983,
    1526,  1656,  1828,   260,  1851,  1681,  1493,   260,   112,   720,
     122,   123,   124,   849,   130,  1750,     0,     0,     0,   406,
       0,     0,  1877,     0,  1976,  1977,  1978,  1979,  1981,     0,
       0,     0,   332,     0,     0,     0,     0,  1889,  1890,  1891,
    1892,  1893,   260,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,  1634,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
     260,     0,     0,     0,  1725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1957,     0,  2027,
       0,     0,     0,     0,     0,     0,     0,  1745,  1926,     0,
       0,     0,  1930,     0,     0,     0,     0,  1564,     0,     0,
    1754,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,  1615,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   260,
     260,   260,   260,     0,     0,     0,     0,     0,     0,     0,
       0,  1966,     0,     0,  1634,  1968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2046,     0,
       0,  1980,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,     0,  1621,     0,     0,
    1805,     0,     0,     0,     0,  2068,  2070,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,  2078,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2020,  2021,     0,     0,     0,  1723,   414,     0,
       0,     0,     0,     0,     0,   376,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,  1846,     0,     0,
       0,     0,     0,     0,  1852,   414,   414,     0,     0,     0,
       0,   401,     0,     0,     0,   411,     0,  1796,     0,   416,
       0,     0,   414,     0,     0,     0,  1634,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   426,   428,   431,   432,
    1884,   434,   428,   436,   437,     0,   439,   428,   441,   442,
     443,   444,   445,   446,  1822,   448,   449,   450,     0,     0,
       0,   428,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,  1634,
     538,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,  1927,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   513,   515,   517,   518,   428,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     545,   428,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,   566,     0,     0,     0,
     538,     0,     0,     0,     0,   575,   576,     0,     0,     0,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   597,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,   616,     0,     0,     0,   619,   620,   621,     0,   623,
       0,     0,     0,   626,   627,   628,     0,     0,   629,     0,
       0,  1634,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,  1834,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   658,     0,     0,     0,   664,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,   675,   676,     0,   538,     0,     0,
       0,     0,  1634,     0,     0,     0,     0,     0,   703,     0,
    1946,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,   515,     0,     0,   538,
       0,   682,   733,   683,     0,     0,     0,   738,     0,  1599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   752,     0,     0,     0,     0,     0,   758,   759,   760,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
     771,   772,   773,   774,   776,   777,   778,   779,   780,   781,
     782,   782,     0,   787,   788,     0,   790,  1915,     0,     0,
       0,     0,   796,     0,     0,   798,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   782,
       0,     0,     0,   428,     0,     0,     0,     0,     0,     0,
       0,     0,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   829,   831,   832,   833,     0,   835,
     836,     0,     0,     0,     0,     0,   843,   844,   845,     0,
       0,     0,     0,   851,   854,   857,   860,   862,     0,   864,
       0,   866,     0,   428,   428,  1998,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,   513,   658,   884,   538,     0,     0,   889,   890,   891,
     892,   893,   894,   895,   896,   897,     0,     0,     0,     0,
     903,     0,   905,   906,     0,     0,     0,   428,   428,   428,
       0,     0,   913,   914,   915,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,   937,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
       0,   428,     0,     0,     0,     0,   953,     0,   954,     0,
     835,   836,     0,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,   969,     0,     0,     0,     0,     0,     0,
       0,   523,     0,   428,     0,     0,     0,     0,     0,   984,
     985,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,   428,     0,  1003,  1004,   538,
       0,   428,  1009,     7,     8,     0,     0,     0,     0,     0,
    1016,     0,     0,     0,  1019,     0,     0,   829,     0,  1023,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,     0,     0,     0,     0,   429,     0,
    1044,     0,     0,   429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,   428,     0,     0,   538,   695,
      25,    26,   696,    28,    29,   697,    31,   698,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   699,    48,     0,     0,
      50,   700,     0,    53,   701,     0,     0,   428,     0,     0,
     516,     0,     0,   429,     0,     0,     0,     0,   428,     0,
       0,     0,    70,     0,     0,  1114,     0,   429,     0,     0,
       0,     0,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,    84,    85,    86,   428,
     538,     0,     0,     0,     0,     0,  1138,  1139,     0,     0,
       0,     0,  1142,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   728,   536,   537,  1167,     0,
       0,  1169,   538,     0,     0,     0,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
    1183,     0,  1185,  1186,   538,     0,   916,     0,     0,     0,
       0,     0,     0,     0,   877,   885,     0,     0,     0,     0,
       0,  1204,     0,     7,     8,     0,     0,     0,   924,     0,
       0,     0,     0,     0,     0,     0,     0,  1217,     0,     0,
       0,     0,     0,     0,  1223,  1224,  1225,  1226,     0,     0,
       0,     0,  1235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1259,   428,   428,   428,
     428,  1264,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   516,     0,     0,     0,   997,     0,     0,   695,
      25,    26,   696,    28,    29,   697,    31,   698,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,   428,   699,    48,     0,     0,
      50,   700,     0,    53,   701,     0,     0,     0,  1311,   775,
       0,     0,     0,     0,     0,     0,   783,   784,  1312,  1313,
    1314,     0,    70,     0,     0,  1316,  1317,     0,  1318,     0,
       0,     0,     0,     0,     0,  1324,     0,  1325,  1326,  1327,
    1328,  1329,     0,     0,     0,   808,    84,    85,    86,   429,
    1332,  1333,     0,     0,     0,     0,     0,     0,     0,   428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1349,
     830,  1351,     0,  1353,     0,  1355,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1372,     0,     0,     0,   429,
     429,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,   907,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,  1403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
       0,     0,     0,   429,   429,   429,     0,  1416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   695,    25,
      26,   696,    28,    29,   697,    31,   698,    33,    34,    35,
      36,     0,  1101,     0,    38,    39,    40,     0,  1433,    42,
       0,  1438,     0,     0,     0,   699,    48,   429,     0,    50,
     700,     0,    53,   701,     0,     0,     0,     0,     7,     8,
       0,     0,     0,  1102,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,  1466,  1467,  1468,  1469,     0,   429,
       0,     0,     0,     0,     0,  1476,  1478,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,     0,     0,
       0,   429,     0,     0,     0,   685,     0,   429,     0,     0,
       0,  1409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   830,     0,  1024,     0,     0,     0,     0,
       0,     0,     0,     0,   695,    25,    26,   696,    28,    29,
     697,    31,   698,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   699,    48,     0,   951,    50,   700,     0,    53,   701,
       0,     0,     0,  1557,  1558,  1559,     0,     0,     0,     0,
       0,   429,  1565,     0,  1567,     0,     0,    70,     0,     0,
       0,  1570,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,     0,     0,     0,     0,  1586,
       0,    84,    85,    86,     0,     0,     0,  1591,  1592,  1593,
       0,     0,     0,   429,     0,     0,     0,  1602,     0,     0,
       0,     0,     0,     0,   429,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,   840,
       0,     0,     0,   538,     0,  1625,     0,     0,     0,     0,
       0,  1631,  1632,     0,     0,   429,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
     952,     0,     0,     0,   538,     0,     0,     0,     0,     0,
    1654,     0,     0,     0,     0,     0,     0,     0,  1657,  1658,
       0,     0,     0,     0,     0,  1663,  1664,     0,     0,     0,
       0,     0,  1668,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,  1671,
    1672,  1673,   538,     0,     0,     0,     0,  1674,  1675,  1676,
    1677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1683,     0,     0,     0,     0,     0,     0,     0,
       0,   428,   428,  1694,     0,  1695,     0,     0,     0,     0,
       0,  1703,  1704,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,   429,   429,   429,     0,     0,     0,
     428,     0,     0,     0,  1722,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1732,     0,     0,  1735,     0,
       0,     0,  1738,     0,   341,   342,   343,   344,   345,   346,
     347,   348,   349,     0,     0,     0,  1747,   350,   351,   352,
     353,     0,     0,     0,     0,   354,   355,   356,     0,  1759,
     357,   429,     0,     0,  1765,     0,     0,     0,     0,     0,
       0,     0,   358,     0,   359,     0,     0,     0,  1767,     0,
       0,     0,     0,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,     0,  1060,  1061,  1062,  1063,     0,
    1065,  1066,  1067,  1068,     0,     0,     0,     0,  1790,     0,
       0,   155,   156,     0,  1078,     0,  1080,     0,     0,     0,
       0,     0,     0,     0,     0,   429,     0,     0,     0,  1799,
       0,     0,  1093,  1094,     0,     0,     0,     0,  1808,     0,
    1100,     0,     0,     0,     0,     0,     0,   515,     0,     0,
       0,     0,     0,     0,     0,     0,  1819,  1820,     0,     0,
     428,     0,     0,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,   360,   361,
     362,     0,   538,     0,     0,     0,     0,     0,  1699,  1843,
    1844,   363,  1700,   364,     0,     0,     0,     0,     0,     0,
       0,  1853,     0,     0,     0,   429,     0,     0,  1860,     0,
       0,     0,     0,     0,  1864,  1865,  1866,  1867,  1868,     0,
       0,   400,     0,     0,   428,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,   428,
       0,     0,     0,   538,     0,     0,     0,  1894,     0,  1087,
       0,     0,     0,  1189,  1191,  1192,     0,     0,     0,  1196,
    1197,     0,     0,  1200,  1201,  1202,  1203,     0,  1205,     0,
       0,  1905,     0,  1211,     0,     0,     0,  1910,  1911,     0,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   483,   484,   485,   486,   487,   488,
    1934,   490,   491,     0,     0,     0,     0,   493,     0,     0,
       0,     0,     0,     0,     0,     0,   509,   510,     0,     0,
       0,     0,     0,     0,     0,  1952,  1953,     0,     0,     0,
       0,     0,     0,     0,  1283,  1284,     0,  1959,  1960,  1961,
    1962,  1963,  1964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1972,     0,     0,     0,     0,
     428,   428,   428,   428,   428,     0,     0,     0,     0,     0,
    1765,     0,     0,     0,  1988,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,     0,     0,  2011,     0,     0,     0,     0,  2014,
    2015,  2016,  2017,  2018,  2019,     0,     0,     0,     0,     0,
     630,   631,   632,     0,     0,   428,   636,   637,   638,   639,
     640,   641,   642,     0,   643,     0,     0,   644,   645,     0,
       0,   648,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   657,     0,     0,  2050,  2051,  2052,  2053,
    2054,  2055,   695,    25,    26,   696,    28,    29,   697,    31,
     698,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,  1655,     7,     8,   699,
      48,     0,     0,    50,   700,     0,    53,   701,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,    70,   538,     0,     0,     0,
       0,     0,  1726,     0,     0,     0,  1727,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,  1447,   429,   429,     0,
     538,     0,   727,   695,    25,    26,   696,    28,    29,   697,
      31,   698,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,   429,     0,     0,     0,
     699,    48,     0,  1480,    50,   700,     0,    53,   701,     0,
       0,   815,     0,     0,     0,     0,     0,     0,  1135,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
     958,     0,     0,     0,     0,     0,  1515,  1516,  1517,  1518,
    1519,     0,     0,     0,     0,  1524,  1525,     0,  1527,     0,
      84,    85,    86,     0,  1533,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1537,     0,     0,     0,     0,     0,
       0,   187,     6,   340,     0,     0,     0,     0,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   220,   221,   222,   223,   350,   351,   352,
     353,   224,     0,   516,     0,   354,   355,   356,     0,  1597,
     357,  1600,   225,   226,   227,  1607,   429,  1609,     0,     0,
     228,    21,   358,     0,   359,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,  1627,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
     429,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,   429,     0,     0,     0,     0,
       0,     0,     7,     8,     0,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,   236,   360,   361,
     362,   237,   238,   713,     0,     0,   239,   240,   241,   242,
     243,   363,     0,   364,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   322,     0,
       0,     0,  1481,     0,     0,   249,     0,     0,   695,    25,
      26,   696,    28,    29,   697,    31,   698,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       7,     8,     0,     0,     0,   699,    48,     0,     0,    50,
     700,     0,    53,   701,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1756,  1757,     0,   429,   429,   429,   429,
     429,    70,     0,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,    84,    85,    86,  1880,     0,
       0,     0,  1881,     0,     0,     0,  1783,  1784,     0,     0,
     150,   340,     0,     0,     0,     0,   695,    25,    26,   696,
      28,    29,   697,    31,   698,    33,    34,    35,    36,     0,
       0,   429,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,   699,    48,     0,     0,    50,   700,     0,
      53,   701,   341,   342,   343,   344,   345,   346,   347,   348,
     349,     0,     0,     0,  1136,   350,   351,   352,   353,    70,
    1825,  1826,     0,   354,   355,   356,     0,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,   359,    84,    85,    86,     0,     0,     0,     0,
       0,   187,     6,   340,     0,     0,     0,     0,   188,   189,
     190,     0,  1278,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   220,   221,   222,   223,   350,   351,   352,
     353,   224,  1155,     0,     0,   354,   355,   356,     0,     0,
     357,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   358,     0,   359,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,   360,   361,   362,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,   363,
       0,   364,   107,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   877,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   360,   361,
     362,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,   363,     0,   364,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   322,     0,
       0,     0,   248,     0,     0,   249,     0,     0,     0,     0,
       0,  1448,  1449,     0,   187,   150,   340,     0,   386,     0,
    2036,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   374,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   220,   221,   222,   223,
     350,   351,   352,   353,   224,     0,     0,     0,   354,   355,
     356,     0,     0,   357,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,   358,     0,   359,     0,     0,
       0,     0,     0,     0,   150,   340,     0,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,   387,   878,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   341,   342,   343,   344,
     345,   346,   347,   348,   349,     0,     0,     0,     0,   350,
     351,   352,   353,     0,     0,     0,     0,   354,   355,   356,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   358,     0,   359,     0,     0,     0,
       0,     0,     0,   388,     0,     0,     0,     0,     0,     0,
     236,   360,   361,   362,   237,     0,     0,     0,     0,   239,
     240,   241,   242,   243,   363,     0,   364,   107,   389,   390,
     391,   392,     0,   387,     0,     0,     0,     0,     0,     0,
       0,   244,   375,     0,     0,     0,   246,     0,   393,   394,
       0,   395,     0,   396,   187,     6,   321,   397,   249,     0,
       0,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
     360,   361,   362,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,   363,   224,   364,   107,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,     0,     0,     0,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,   232,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,   368,
     340,     0,     0,     0,     0,     0,     0,   233,     0,    49,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,   341,   342,   343,   344,   345,   346,   347,   348,   349,
       0,     0,     0,     0,   350,   351,   352,   353,     0,     0,
       0,     0,   354,   355,   356,     0,     0,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   358,
     236,   359,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   245,     0,     0,     0,   246,     0,     0,     0,
       0,   322,   187,     6,  1573,   248,     0,     0,   249,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,   360,   361,   362,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,   363,     0,
     364,   228,    21,     0,     0,     0,     0,     0,   229,     0,
       0,   230,     0,     0,   231,     0,   232,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,    49,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   921,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,     0,     0,     0,   246,     0,     0,     0,     0,   322,
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
       0,     0,    73,     0,     0,    76,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1059,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   582,  1718,     0,
       0,     0,   246,     0,     0,     0,     0,   584,   187,     6,
       0,   287,   519,     0,   249,   188,   189,   190,     0,     0,
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
      73,     0,     0,    76,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1069,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,     0,     0,     0,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1070,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   322,   187,     6,     0,   248,     0,     0,
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
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1071,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   427,     0,     0,     0,   246,     0,     0,     0,
       0,   322,   187,     6,     0,   514,     0,     0,   249,   188,
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
      69,     0,     0,     0,    73,     0,     0,    76,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1076,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     427,     0,     0,     0,   246,     0,     0,     0,     0,   322,
     187,     6,     0,     0,   519,     0,   249,   188,   189,   190,
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
       0,     0,    73,     0,     0,    76,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1077,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   549,   187,     6,
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
      73,     0,     0,    76,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1079,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,     0,     0,     0,
     246,     0,     0,     0,     0,   558,   187,     6,     0,   248,
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
       0,    76,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   560,   187,     6,     0,   248,     0,     0,
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
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   237,   238,     0,     0,     0,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   245,     0,     0,     0,   246,     0,     0,     0,
       0,   562,   187,     6,     0,   248,     0,     0,   249,   188,
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
      69,     0,     0,     0,    73,     0,     0,    76,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1276,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   237,   238,     0,     0,     0,   239,   240,   241,
     242,   243,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     427,     0,     0,     0,   246,     0,     0,     0,     0,   322,
     187,     6,     0,   828,     0,     0,   249,   188,   189,   190,
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
       0,     0,    73,     0,     0,    76,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
     237,   238,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,     0,
       0,     0,   246,     0,     0,     0,     0,   322,   187,     6,
       0,  1581,     0,     0,   249,   188,   189,   190,     0,     0,
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
      73,     0,     0,    76,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1366,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,   238,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   582,  1718,     0,     0,     0,
     246,     0,     0,     0,     0,   584,   187,     6,     0,   287,
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
       0,    76,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1408,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   427,     0,     0,     0,   246,   187,
     150,   340,     0,   322,     0,     0,   188,   189,   190,     0,
     249,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   374,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   220,   221,   222,   223,   350,   351,   352,   353,   224,
       0,     0,     0,   354,   355,   356,     0,     0,   357,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     358,     0,   359,   187,   150,   340,     0,     0,     0,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   374,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   220,   221,   222,   223,   350,
     351,   352,   353,   224,     0,     0,     0,   354,   355,   356,
       0,     0,   357,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   358,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   360,   361,   362,   237,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   363,
       0,   364,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   375,     0,     0,
       0,   246,     0,     0,     0,     0,   322,     0,     0,     0,
    1477,     0,     0,   249,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1520,     0,     0,     0,     0,     0,     0,   236,
     360,   361,   362,   237,     0,     0,     0,     0,   239,   240,
     241,   242,   243,   363,     0,   364,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   375,     0,     0,     0,   246,     0,     0,     0,     0,
     322,   187,   150,   340,  1731,     0,     0,   249,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     374,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   220,   221,   222,   223,   350,   351,   352,
     353,   224,     0,     0,     0,   354,   355,   356,     0,     0,
     357,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,   358,     0,   359,   187,   150,   340,     0,     0,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   374,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   220,   221,   222,
     223,   350,   351,   352,   353,   224,     0,     0,     0,   354,
     355,   356,     0,     0,   357,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   358,     0,   359,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   360,   361,
     362,   237,     0,     0,     0,     0,   239,   240,   241,   242,
     243,   363,     0,   364,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   375,
       0,     0,     0,   246,     0,     0,     0,     0,   322,     0,
       0,     0,  1737,     0,     0,   249,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1521,     0,     0,     0,     0,     0,
       0,   236,   360,   361,   362,   237,     0,     0,     0,     0,
     239,   240,   241,   242,   243,   363,     0,   364,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   375,     0,     0,     0,   246,   187,   150,
       0,     0,   322,     0,     0,   188,   189,   190,     0,   249,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   374,   209,   210,
     211,   212,   213,   214,     0,     0,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
     220,   221,   222,   223,   538,     0,     0,     0,   224,     0,
       0,     0,     0,     0,  1522,     0,     0,   187,   150,   225,
     226,   227,     0,     0,   188,   189,   190,   228,    21,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   374,   209,   210,   211,
     212,   213,   214,     0,     0,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,   220,
     221,   222,   223,   538,     0,     0,     0,   224,     0,     0,
       0,     0,     0,  1528,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1529,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   237,     0,
       0,     0,     0,   239,   240,   241,   242,   243,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   375,     0,     0,     0,
     246,     0,     0,     0,     0,   322,     0,     0,     0,   565,
       0,     0,   249,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,   236,     0,     0,     0,   237,     0,     0,
       0,  1530,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   582,   583,     0,     0,     0,   246,
       0,     0,     0,     0,   584,     0,   187,   150,   287,  1216,
       0,   249,     0,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   374,   209,   210,   211,   212,
     213,   214,     0,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,   220,   221,
     222,   223,   538,     0,     0,     0,   224,     0,     0,     0,
       0,     0,  1531,     0,     0,     0,     0,   225,   226,   227,
     187,   150,     0,  1371,     0,   228,    21,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   374,
     209,   210,   211,   212,   213,   214,     0,     0,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,   220,   221,   222,   223,   538,     0,     0,     0,
     224,     0,     0,     0,     0,     0,  1649,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1760,
       0,     0,   236,     0,     0,     0,   237,     0,     0,     0,
       0,   239,   240,   241,   242,   243,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   375,     0,     0,     0,   246,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
     249,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,   236,     0,     0,  1761,
     237,     0,     0,     0,     0,   239,   240,   241,   242,   243,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   375,     0,
       0,     0,   246,   187,   150,     0,     0,   322,     0,     0,
     188,   189,   190,     0,   249,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   374,   209,   210,   211,   212,   213,   214,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       7,     8,   228,    21,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1785,     0,     0,     0,     0,   695,    25,    26,
     696,    28,    29,   697,    31,   698,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   699,    48,     0,     0,    50,   700,
       0,    53,   701,     0,     0,     0,   695,    25,    26,   696,
      28,    29,   697,    31,   698,    33,    34,    35,    36,     0,
      70,     0,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,   699,    48,     0,     0,    50,   700,   236,
      53,   701,     0,   237,    84,    85,    86,     0,   239,   240,
     241,   242,   243,     7,     8,     0,   107,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   375,     0,     0,     0,   246,     0,     0,     0,     0,
     322,     0,     0,    84,    85,    86,     0,   249,     0,     0,
       0,     7,     8,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1184,     0,     0,     0,     0,     0,     0,
       0,  1786,     0,     0,     0,     0,     0,     0,     0,   695,
      25,    26,   696,    28,    29,   697,    31,   698,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,  1214,     0,     0,     0,   699,    48,     0,     0,
      50,   700,     0,    53,   701,     0,     0,   695,    25,    26,
     696,    28,    29,   697,    31,   698,    33,    34,    35,    36,
       7,     8,    70,    38,    39,    40,     0,     0,    42,     0,
       0,     0,     0,     0,   699,    48,     0,     0,    50,   700,
       0,    53,   701,     0,     0,     0,    84,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,    84,    85,    86,     0,     0,  1787,
       0,     0,     0,     0,     0,     0,   695,    25,    26,   696,
      28,    29,   697,    31,   698,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,  1363,     0,    42,     0,     0,
       0,     0,     0,   699,    48,     0,     0,    50,   700,     0,
      53,   701,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,    70,
       0,     0,     0,  1937,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,    84,    85,    86,     0,    -4,    -4,     0,
       0,     0,  1788,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,    -4,    -4,    -4,
       0,   538,     0,    -4,    -4,     0,    -4,  1158,     0,     0,
      -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,  2000,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     6,     0,    -4,    -4,    -4,
       0,     0,     0,    -4,     7,     8,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,     9,    10,     0,    -4,    -4,
      -4,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,     0,     0,    11,    12,    13,     0,     0,
       0,    14,    15,     0,    16,     0,     0,     0,    17,    18,
       0,    19,    20,     0,    21,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,    37,    38,    39,    40,    41,
       0,    42,     0,    43,    44,    45,    46,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     7,     8,     0,    79,    80,    81,     0,     0,
       0,    82,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,    87,     0,    88,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   106,     0,   107,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   695,    25,
      26,   696,    28,    29,   697,    31,   698,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   699,    48,     0,     0,    50,
     700,     0,    53,   701,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,    70,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1789,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1849,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1906,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1907,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1919,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1920,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1921,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1922,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1923,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1955,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1985,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1990,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1991,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1992,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1993,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1994,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1995,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2037,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2038,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2039,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2040,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1222,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1367,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1429,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1430,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1431,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1432,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1697,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1708,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1775,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1776,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1777,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1778,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1780,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1802,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1817,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1869,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1886,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1895,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1896,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  1917,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  1971,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  2013,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  2035,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  2061,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  2062,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  2063,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  2064,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,  2065,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,  2066,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,   660,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
     870,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,  1795,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,   682,     0,   683,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
     927,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,   971,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,  1106,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,  1171,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,  1172,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,  1176,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,  1177,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,  1258,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,  1274,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,  1460,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
    1587,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,  1753,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,  1803,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,   731,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   732,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   734,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     736,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,   737,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   739,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,   741,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,   742,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,   743,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,   744,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,   745,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   746,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   748,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     749,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,   750,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   812,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,   841,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,   898,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,   916,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,   917,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,   918,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   919,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   925,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     926,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,   957,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   970,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1027,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1032,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,  1045,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,  1105,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,  1111,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,  1112,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1113,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1127,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1128,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  1129,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1157,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1159,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,  1160,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,  1161,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,  1162,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,  1163,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1164,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1165,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1170,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  1257,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1273,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1465,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,  1532,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,  1643,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,  1644,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,  1645,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1646,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1698,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1707,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  1730,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1984,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  2032
};

static const yytype_int16 yycheck[] =
{
       3,   132,   280,  1156,    21,  1152,  1611,  1612,   492,   579,
     580,   677,     4,     4,     4,     4,     9,   292,    21,   685,
       4,     4,   692,  1575,     3,     5,     4,     4,     4,     4,
     183,   184,   185,     6,   309,     5,     5,     5,     5,     5,
     710,   158,     6,     4,    47,     7,   163,     6,     6,     6,
       6,   168,     4,     4,     4,     4,     4,     4,     9,    95,
       9,  1768,   220,   221,     6,   182,     7,   227,   228,   132,
      98,    74,   100,    95,   137,   138,     9,   235,     0,    82,
     116,     4,   233,     6,    87,     9,    60,    61,   239,    63,
     220,   221,   220,   221,   116,    98,   371,     6,   373,   126,
     227,   228,   220,   221,   132,   380,     9,   234,   230,   239,
     232,   239,   175,   266,   267,   268,   143,    14,  1670,     7,
       6,   239,     6,   186,   151,   152,   153,   155,     6,   132,
     157,   158,   231,   230,   137,   138,   230,   236,   220,   221,
     220,   221,   145,   220,   221,   262,   630,   230,   632,   232,
     303,   304,   305,   156,   133,   158,     8,   239,    92,   239,
     163,    95,   239,   316,   317,   168,    89,   130,   131,     9,
     220,   221,   175,   136,   220,   221,   179,   220,   221,   182,
     183,   184,   185,   186,   161,   162,   163,   164,    95,   239,
     220,   221,   182,   239,   174,    95,   239,    97,     6,   220,
     221,   159,   234,   159,   174,   174,   238,  1914,   174,   239,
     186,   171,     6,   220,   221,   233,   206,   206,   239,   171,
     172,   239,   206,   206,   171,   172,     6,   187,   188,     7,
     233,   206,   239,     6,   227,   228,  1383,   230,   230,   232,
    1792,   232,   245,   236,   234,   248,   249,   238,   237,     6,
     234,   234,   230,   217,   234,   206,   234,   206,   235,   262,
     217,   234,   265,   266,   267,   268,   234,   234,     6,   230,
     273,   274,   275,   234,   236,   234,   279,   280,   227,   228,
     230,   230,   230,   232,   234,   234,   234,   236,   230,   230,
     230,   232,   234,  1845,   234,   570,   571,   230,   230,   232,
     303,   304,   305,   236,   970,   971,   230,   235,   232,   283,
     284,   239,   587,   316,   317,   378,   232,   291,   292,   207,
     208,   209,   210,     6,   227,   228,   232,   230,   230,   232,
     233,    47,   234,   236,   220,   221,   220,   221,     7,   227,
     228,   230,   220,   221,  1949,   234,     6,     7,   236,   624,
       7,   504,   505,   506,   507,   220,   221,   230,   386,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   230,   239,   378,   231,   229,   233,   382,
     383,   220,   221,   235,   239,   660,   231,   227,   228,   230,
     230,     7,   232,     4,   239,   398,   236,   514,   220,   221,
     239,   404,   230,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   239,   220,   221,
     423,   229,    95,   486,   427,   488,  1096,   490,   491,   207,
     208,   209,   210,    89,  1104,  1987,    92,   239,   236,    95,
     238,   220,   221,   220,   221,   508,   509,   564,   565,   227,
     228,   220,   221,  1119,    95,  1121,    97,  1123,     7,  1125,
     239,   109,   239,   179,   227,   228,   231,   231,   220,   221,
     239,   474,   230,   236,   239,   239,   220,   221,   481,   482,
     220,   221,   234,   486,   512,   488,   489,   490,   491,   492,
      95,   608,   609,   610,   511,   239,  2048,   220,   221,   239,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   220,
     221,   514,   130,   131,     6,     7,   239,   233,   136,   130,
     131,   132,   133,   234,     6,   231,   554,   555,   556,   557,
     220,   221,   535,   239,   145,   652,   539,   148,   207,   208,
     209,   210,    92,   230,   234,    95,   677,   227,   228,   265,
     207,   208,   209,   210,   234,   220,   221,   273,   274,   275,
     235,   564,   565,   279,   239,   230,   230,   684,   631,   234,
     633,   634,   635,   636,   637,   638,   230,   640,   641,   642,
     643,   220,   221,   646,   647,   648,  1256,     8,   231,   706,
     233,   207,   208,   209,   210,   712,   239,   231,   873,   233,
     579,   580,  1272,   577,   578,   608,   609,   610,   582,   230,
      89,   227,   228,    92,   231,   230,    95,   645,    97,   222,
     223,   224,   239,    95,   230,    97,   229,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   230,   640,   641,   642,
     643,   644,   230,   646,   647,   648,   649,     8,   231,   652,
     233,     4,   715,     6,   220,   221,   239,   720,   207,   208,
     209,   210,   234,   231,   230,   233,   382,   383,   234,   786,
     126,   239,   231,   230,   233,   234,   231,    89,   227,   228,
      92,   684,   398,    95,   239,    97,   689,   143,   230,   230,
     235,   231,     4,     5,   239,   151,   152,   153,   726,   239,
     234,   157,   158,   706,   707,   231,   837,   233,   234,   712,
      89,   828,   715,    92,    92,   718,    95,   720,    97,   235,
     230,     4,   839,   239,   231,   728,   233,   730,    92,   234,
     234,    95,   239,    97,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   230,    95,    92,    92,    59,    60,    61,
      62,    95,     4,   870,   235,    67,    68,    69,   239,     4,
      72,   220,   221,   222,   223,   224,     4,   235,     4,  1435,
     229,   239,    84,   489,    86,    92,   230,     6,    95,   235,
      97,  1447,   235,   786,   230,  1938,   239,   503,   234,   230,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    92,   230,    89,    95,   229,    97,
      93,   123,   230,   232,   235,   230,    99,   100,   235,   102,
     103,   230,   239,   230,   235,   828,  1973,   234,   239,   235,
     235,   235,     6,   239,   239,   239,   839,   120,   235,   970,
     971,   235,   239,   235,   847,   239,   232,   239,  2001,     6,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   238,   235,   234,   870,   229,   239,
     231,   988,   989,   990,   991,  2022,     6,   235,   190,   191,
     192,   239,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   203,   235,   205,   206,   229,   239,   235,   238,   235,
     126,   239,   876,   239,   235,   230,   235,   235,   239,   883,
     239,   239,     9,   887,   235,   227,   228,   143,   239,   235,
     230,   230,   234,   239,   236,   151,   152,   153,   230,  1046,
     235,   157,   158,   116,   239,   235,   126,  1000,   235,   239,
     230,   235,   239,   235,   972,   239,   235,   239,   235,   234,
     239,   235,   239,   143,   235,   239,   230,   230,   239,   962,
    1238,   151,   152,   153,  1448,  1449,   235,   157,   158,   230,
     239,   234,   126,   976,  1105,  1106,   235,   235,   981,   126,
     239,   239,   230,   230,   230,   988,   989,   990,   991,     4,
    1560,  1561,   234,  1110,   235,   235,   143,  1000,   239,   239,
     230,   234,   230,   235,   151,   152,   153,   239,   235,   235,
     157,   158,   239,   235,   235,   230,   230,   239,   239,  1082,
    1083,   230,  1025,  1026,   230,  1028,   230,  1030,  1031,   230,
    1033,   230,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,
    1043,   230,   235,  1046,   235,   235,   239,  1021,   239,   235,
     235,   230,   230,   239,   239,     4,     5,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   232,   235,  1190,     6,   229,   239,   235,  1081,  1082,
    1083,   239,   235,   235,     6,   234,   239,   239,   235,   234,
     234,   232,   232,   232,     6,     6,  1099,    46,    47,    48,
      49,    50,    51,    52,    53,    54,  1109,  1110,   234,   174,
      59,    60,    61,    62,   230,   230,   230,   230,    67,    68,
      69,   230,   232,    72,     6,     6,  1257,  1258,   234,     6,
       6,   847,  1195,   234,     7,    84,  1199,    86,     6,   234,
       6,   234,    85,   235,   231,  1208,     7,  1210,   239,  1424,
     239,  1426,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,  1166,  1442,     6,     6,   229,     6,    64,
     231,   234,    64,    64,   123,    64,  1179,  1180,  1181,   229,
       4,     7,     7,     6,     6,     6,   231,  1190,     6,     6,
     234,     7,  1195,     7,     6,  1258,  1199,     6,     6,   171,
     234,   233,   231,     6,   234,  1208,   234,  1210,     8,   234,
     234,     7,     6,   236,   232,     4,  1219,   230,     6,     6,
       6,     6,   231,     7,   232,     7,   174,     7,  1798,     7,
     174,     7,     7,     7,   174,  1238,     7,     7,     7,     7,
       7,   190,   191,   192,     7,     7,   962,     7,     7,  1277,
     234,  1279,     6,  1737,   203,  1258,   205,   206,   231,   233,
     239,   239,   239,   234,   234,   981,   234,   234,   231,     7,
     239,   236,     7,   234,     6,     4,  1279,   231,  1395,     6,
     239,   231,   231,   239,   233,   231,   239,  1290,   239,   231,
     126,   236,     7,  1296,   235,     6,   235,     7,     7,     7,
     236,   231,   231,     9,  1435,   239,   239,   231,   239,  1025,
    1026,     7,  1028,   233,  1030,  1031,   235,  1033,   234,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,     6,     6,
       4,   236,    46,    46,   234,   236,   230,   230,   217,  1342,
    1343,  1344,   230,   230,     4,  1348,  1624,  1350,     7,  1352,
       7,  1354,    97,  1356,  1357,  1358,     7,     7,     7,   239,
       7,     6,     4,     7,     7,  1081,     7,     7,     7,     4,
    1373,   107,   234,     6,   230,     7,     6,   234,     7,     7,
       7,  1384,     7,  1099,     7,     7,     7,     6,     6,  1392,
       6,    95,  1395,  1109,     7,  1423,     6,     6,     4,     4,
       4,   235,   237,   234,   234,  1536,   239,   239,  1382,  1472,
       6,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,     6,     6,   232,     7,   229,
       6,   231,     6,   233,     6,  1552,  1553,   230,     6,  1442,
     230,     6,   234,     6,   239,  1448,  1449,     6,     6,  1477,
    1166,  1454,   233,   236,   120,   234,     6,   234,     6,     6,
       6,   234,   234,  1179,  1180,  1181,     6,   174,   234,  1472,
       6,     6,     6,     6,  1477,     7,     8,     6,  1481,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     6,     6,     5,     4,   229,   231,     6,
     231,     6,     4,  1219,   234,  1636,     6,   232,   234,     7,
     234,   234,   234,     6,     6,   234,   234,  1491,   234,     6,
       6,     6,   234,     6,   170,     6,     4,     7,  1556,   234,
       6,   234,  1807,   234,   231,  1598,   234,   239,  1601,   239,
     239,     6,   236,   230,   234,     6,     6,     6,     6,  1552,
    1553,     6,     4,     7,    93,     6,     6,  1835,     6,     6,
       6,     5,   234,  1279,   234,     6,     6,     6,  1596,     6,
       6,     6,  1575,     6,  1290,  1603,  1604,     6,  1581,     6,
    1296,  1560,  1561,   239,     6,     6,     6,  1590,  1616,     6,
       6,   239,     4,     6,     5,  1598,     6,     6,  1601,     7,
     234,   239,  1576,  1577,  1578,  1579,  1580,  1581,   234,     6,
    1613,     6,     6,     6,  1731,   235,     7,  1620,   235,   234,
     234,  1624,   234,  1626,   169,  1900,  1342,  1343,  1344,     6,
     231,     6,  1348,   235,  1350,   235,  1352,   235,  1354,     6,
    1356,  1357,  1358,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,  1373,     7,     6,
       6,   229,     6,   236,  1939,     6,     6,  1670,  1384,     6,
     234,     6,     6,     6,     6,     6,  1392,     6,  1795,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,  1810,   235,     6,   234,   229,   172,     6,
     231,     6,     6,  1706,   230,   235,     6,   235,   235,   234,
     234,   234,     6,   234,  1742,  1718,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,  1731,     6,
     126,     6,   229,     6,  1737,   234,   231,     6,  1454,     6,
       6,   235,     6,     6,   235,  1773,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
    1763,  1477,     6,     6,   229,     6,     6,  1770,     6,     6,
     234,  1774,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     6,     6,     6,  1792,
     229,   234,  1795,     6,     6,     6,   234,     6,  1271,  1951,
    1322,  1485,  1741,  1806,  1769,  1541,  1289,  1810,     3,   420,
       3,     3,     3,   553,     3,  1620,    -1,    -1,    -1,  1798,
      -1,    -1,  1794,    -1,  1941,  1942,  1943,  1944,  1945,    -1,
      -1,    -1,  1835,    -1,    -1,    -1,    -1,  1811,  1812,  1813,
    1814,  1815,  1845,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,  1575,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1873,    -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1915,    -1,  2006,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1613,  1872,    -1,
      -1,    -1,  1876,    -1,    -1,    -1,    -1,     6,    -1,    -1,
    1626,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,     6,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1941,  1942,
    1943,  1944,  1945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1925,    -1,    -1,  1670,  1929,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2031,    -1,
      -1,  1945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1987,    -1,    -1,     6,    -1,    -1,
    1706,    -1,    -1,    -1,    -1,  2058,  2059,    -1,    -1,    -1,
      -1,    -1,    -1,  2006,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1996,  1997,    -1,    -1,    -1,     6,  2031,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2048,    -1,  1763,    -1,    -1,
      -1,    -1,    -1,    -1,  1770,  2058,  2059,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,   136,    -1,     6,    -1,   140,
      -1,    -1,  2075,    -1,    -1,    -1,  1792,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
    1806,   162,   163,   164,   165,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,     6,   176,   177,   178,    -1,    -1,
      -1,   182,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,  1845,
     229,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1873,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     261,   262,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   277,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,    -1,
      -1,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   302,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,   322,    -1,    -1,    -1,   326,   327,   328,    -1,   330,
      -1,    -1,    -1,   334,   335,   336,    -1,    -1,   339,    -1,
      -1,  1987,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,   379,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   395,   396,    -1,   229,    -1,    -1,
      -1,    -1,  2048,    -1,    -1,    -1,    -1,    -1,   409,    -1,
       6,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   427,    -1,    -1,   229,
      -1,   231,   433,   233,    -1,    -1,    -1,   438,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   452,    -1,    -1,    -1,    -1,    -1,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,    -1,   484,   485,    -1,   487,     7,    -1,    -1,
      -1,    -1,   493,    -1,    -1,   496,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   510,
      -1,    -1,    -1,   514,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,    -1,   540,
     541,    -1,    -1,    -1,    -1,    -1,   547,   548,   549,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,   558,    -1,   560,
      -1,   562,    -1,   564,   565,     6,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,   582,   583,   584,   229,    -1,    -1,   588,   589,   590,
     591,   592,   593,   594,   595,   596,    -1,    -1,    -1,    -1,
     601,    -1,   603,   604,    -1,    -1,    -1,   608,   609,   610,
      -1,    -1,   613,   614,   615,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,   639,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,   652,    -1,    -1,    -1,    -1,   657,    -1,   659,    -1,
     661,   662,    -1,    -1,    -1,    -1,    -1,   668,    -1,    -1,
      -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,   684,    -1,    -1,    -1,    -1,    -1,   690,
     691,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   706,    -1,   708,   709,   229,
      -1,   712,   713,    13,    14,    -1,    -1,    -1,    -1,    -1,
     721,    -1,    -1,    -1,   725,    -1,    -1,   728,    -1,   730,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,
     751,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   786,    -1,    -1,   229,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,    -1,   828,    -1,    -1,
     245,    -1,    -1,   248,    -1,    -1,    -1,    -1,   839,    -1,
      -1,    -1,   142,    -1,    -1,   846,    -1,   262,    -1,    -1,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   166,   167,   168,   870,
     229,    -1,    -1,    -1,    -1,    -1,   877,   878,    -1,    -1,
      -1,    -1,   883,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   899,    -1,
      -1,   902,   229,    -1,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     921,    -1,   923,   924,   229,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   235,    -1,    -1,    -1,    -1,
      -1,   942,    -1,    13,    14,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   958,    -1,    -1,
      -1,    -1,    -1,    -1,   965,   966,   967,   968,    -1,    -1,
      -1,    -1,   973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   987,   988,   989,   990,
     991,   992,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   427,    -1,    -1,    -1,   235,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
     110,    -1,    -1,    -1,    -1,  1046,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,  1059,   474,
      -1,    -1,    -1,    -1,    -1,    -1,   481,   482,  1069,  1070,
    1071,    -1,   142,    -1,    -1,  1076,  1077,    -1,  1079,    -1,
      -1,    -1,    -1,    -1,    -1,  1086,    -1,  1088,  1089,  1090,
    1091,  1092,    -1,    -1,    -1,   510,   166,   167,   168,   514,
    1101,  1102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1120,
     535,  1122,    -1,  1124,    -1,  1126,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1146,    -1,    -1,    -1,   564,
     565,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   235,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1190,
      -1,    -1,    -1,   608,   609,   610,    -1,  1198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,     8,    -1,   105,   106,   107,    -1,  1229,   110,
      -1,  1232,    -1,    -1,    -1,   116,   117,   652,    -1,   120,
     121,    -1,   123,   124,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,  1265,  1266,  1267,  1268,    -1,   684,
      -1,    -1,    -1,    -1,    -1,  1276,  1277,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,   706,    -1,    -1,    -1,   400,    -1,   712,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   728,    -1,   730,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
     105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,   235,   120,   121,    -1,   123,   124,
      -1,    -1,    -1,  1364,  1365,  1366,    -1,    -1,    -1,    -1,
      -1,   786,  1373,    -1,  1375,    -1,    -1,   142,    -1,    -1,
      -1,  1382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1395,    -1,    -1,    -1,    -1,  1400,
      -1,   166,   167,   168,    -1,    -1,    -1,  1408,  1409,  1410,
      -1,    -1,    -1,   828,    -1,    -1,    -1,  1418,    -1,    -1,
      -1,    -1,    -1,    -1,   839,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   544,
      -1,    -1,    -1,   229,    -1,  1446,    -1,    -1,    -1,    -1,
      -1,  1452,  1453,    -1,    -1,   870,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     235,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
    1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1489,  1490,
      -1,    -1,    -1,    -1,    -1,  1496,  1497,    -1,    -1,    -1,
      -1,    -1,  1503,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,  1520,
    1521,  1522,   229,    -1,    -1,    -1,    -1,  1528,  1529,  1530,
    1531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1552,  1553,  1554,    -1,  1556,    -1,    -1,    -1,    -1,
      -1,  1562,  1563,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   988,   989,   990,   991,    -1,    -1,    -1,
    1581,    -1,    -1,    -1,  1585,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1596,    -1,    -1,  1599,    -1,
      -1,    -1,  1603,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,  1617,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,  1630,
      72,  1046,    -1,    -1,  1635,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,  1649,    -1,
      -1,    -1,    -1,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   768,    -1,   770,   771,   772,   773,    -1,
     775,   776,   777,   778,    -1,    -1,    -1,    -1,  1679,    -1,
      -1,    22,    23,    -1,   789,    -1,   791,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1110,    -1,    -1,    -1,  1700,
      -1,    -1,   807,   808,    -1,    -1,    -1,    -1,  1709,    -1,
     815,    -1,    -1,    -1,    -1,    -1,    -1,  1718,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1727,  1728,    -1,    -1,
    1731,    -1,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   190,   191,
     192,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,  1760,
    1761,   203,   239,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1772,    -1,    -1,    -1,  1190,    -1,    -1,  1779,    -1,
      -1,    -1,    -1,    -1,  1785,  1786,  1787,  1788,  1789,    -1,
      -1,   132,    -1,    -1,  1795,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,  1810,
      -1,    -1,    -1,   229,    -1,    -1,    -1,  1818,    -1,   235,
      -1,    -1,    -1,   928,   929,   930,    -1,    -1,    -1,   934,
     935,    -1,    -1,   938,   939,   940,   941,    -1,   943,    -1,
      -1,  1842,    -1,   948,    -1,    -1,    -1,  1848,  1849,    -1,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
    1881,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1906,  1907,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1019,  1020,    -1,  1918,  1919,  1920,
    1921,  1922,  1923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,    -1,
    1941,  1942,  1943,  1944,  1945,    -1,    -1,    -1,    -1,    -1,
    1951,    -1,    -1,    -1,  1955,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1395,    -1,    -1,    -1,  1985,    -1,    -1,    -1,    -1,  1990,
    1991,  1992,  1993,  1994,  1995,    -1,    -1,    -1,    -1,    -1,
     341,   342,   343,    -1,    -1,  2006,   347,   348,   349,   350,
     351,   352,   353,    -1,   355,    -1,    -1,   358,   359,    -1,
      -1,   362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,    -1,    -1,  2037,  2038,  2039,  2040,
    2041,  2042,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,   105,   106,
     107,    -1,    -1,   110,    -1,    -1,  1481,    13,    14,   116,
     117,    -1,    -1,   120,   121,    -1,   123,   124,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,   142,   229,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,  1241,  1552,  1553,    -1,
     229,    -1,   231,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,    -1,  1581,    -1,    -1,    -1,
     116,   117,    -1,  1278,   120,   121,    -1,   123,   124,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,  1311,  1312,  1313,  1314,
    1315,    -1,    -1,    -1,    -1,  1320,  1321,    -1,  1323,    -1,
     166,   167,   168,    -1,  1329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,  1718,    -1,    67,    68,    69,    -1,  1414,
      72,  1416,    74,    75,    76,  1420,  1731,  1422,    -1,    -1,
      82,    83,    84,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,  1448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,   139,   140,   141,
    1795,    -1,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1810,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,   189,   190,   191,
     192,   193,   194,   239,    -1,    -1,   198,   199,   200,   201,
     202,   203,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,   234,    -1,    -1,   237,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
      13,    14,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1628,  1629,    -1,  1941,  1942,  1943,  1944,
    1945,   142,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,   166,   167,   168,   235,    -1,
      -1,    -1,   239,    -1,    -1,    -1,  1671,  1672,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,  2006,   105,   106,   107,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,
     123,   124,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,   235,    59,    60,    61,    62,   142,
    1735,  1736,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,  1013,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   235,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    95,    -1,    97,   190,   191,   192,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,   205,   206,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,   148,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,   198,   199,   200,   201,
     202,   203,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,   234,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,  1242,  1243,    -1,     3,     4,     5,    -1,     7,    -1,
    2015,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
     199,   200,   201,   202,   203,    -1,   205,   206,   207,   208,
     209,   210,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,    -1,    -1,    -1,   225,    -1,   227,   228,
      -1,   230,    -1,   232,     3,     4,     5,   236,   237,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,   203,    63,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,     4,
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
      -1,   230,     3,     4,     5,   234,    -1,    -1,   237,    10,
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
      -1,   234,   235,    -1,   237,    10,    11,    12,    -1,    -1,
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
       3,     4,    -1,    -1,   235,    -1,   237,    10,    11,    12,
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
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,     3,
       4,     5,    -1,   230,    -1,    -1,    10,    11,    12,    -1,
     237,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,    -1,    -1,    -1,   198,   199,   200,   201,   202,   203,
      -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
     234,    -1,    -1,   237,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,   199,
     200,   201,   202,   203,    -1,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,     3,     4,     5,   234,    -1,    -1,   237,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
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
      -1,    -1,   220,   221,    -1,    -1,    -1,   225,     3,     4,
      -1,    -1,   230,    -1,    -1,    10,    11,    12,    -1,   237,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      55,    56,    57,    58,   229,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,     3,     4,    74,
      75,    76,    -1,    -1,    10,    11,    12,    82,    83,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    55,
      56,    57,    58,   229,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    83,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   234,
      -1,    -1,   237,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   189,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   239,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   230,    -1,     3,     4,   234,     6,
      -1,   237,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    55,    56,
      57,    58,   229,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    74,    75,    76,
       3,     4,    -1,     6,    -1,    82,    83,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    55,    56,    57,    58,   229,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,   189,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,   239,
     193,    -1,    -1,    -1,    -1,   198,   199,   200,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,     3,     4,    -1,    -1,   230,    -1,    -1,
      10,    11,    12,    -1,   237,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      13,    14,    82,    83,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,
      -1,   123,   124,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     142,    -1,   105,   106,   107,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,   189,
     123,   124,    -1,   193,   166,   167,   168,    -1,   198,   199,
     200,   201,   202,    13,    14,    -1,   206,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,   166,   167,   168,    -1,   237,    -1,    -1,
      -1,    13,    14,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
     110,    -1,   235,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      13,    14,   142,   105,   106,   107,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,
      -1,   123,   124,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,   105,   106,   107,   235,    -1,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,   142,
      -1,    -1,    -1,   235,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,   166,   167,   168,    -1,    44,    45,    -1,
      -1,    -1,   239,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    64,    65,    66,
      -1,   229,    -1,    70,    71,    -1,    73,   235,    -1,    -1,
      77,    78,    -1,    80,    81,    -1,    83,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,   106,
     107,   108,   235,   110,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,     4,    -1,   154,   155,   156,
      -1,    -1,    -1,   160,    13,    14,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,   171,    -1,   173,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    44,    45,    -1,   195,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    77,    78,
      -1,    80,    81,    -1,    83,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,   106,   107,   108,
      -1,   110,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,   121,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    13,    14,    -1,   154,   155,   156,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      -1,    -1,   171,    -1,   173,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,   206,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,   124,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,   142,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   211,   212,
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
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,   234,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
     234,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,   234,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,   231,    -1,   233,   211,   212,
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
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,   231,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   231
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
     171,   187,   188,   234,   220,   221,   230,   234,   328,   329,
     328,   234,   234,   328,     4,    89,    93,    99,   100,   102,
     103,   120,   230,    95,    97,    95,    92,     4,   182,   234,
     344,     4,     6,    89,    92,    95,    92,    95,     4,     4,
       4,     5,   230,   331,   332,     4,   230,   230,   230,     4,
     234,   335,   344,     4,   230,   230,   230,     6,     6,   232,
       5,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      59,    60,    61,    62,    67,    68,    69,    72,    84,    86,
     190,   191,   192,   203,   205,   339,   344,   230,     4,   339,
       5,   234,     5,   234,    32,   221,   319,   344,   232,   230,
     234,     6,   230,   234,     6,   238,     7,   123,   182,   207,
     208,   209,   210,   227,   228,   230,   232,   236,   262,   263,
     264,   319,   338,   339,   344,     4,   288,   289,   290,   234,
       6,   319,   338,   339,   344,   338,   319,   338,   342,   268,
     272,   230,   327,     9,   339,   344,   319,   221,   319,   333,
     334,   319,   319,   230,   319,   334,   319,   319,   230,   319,
     334,   319,   319,   319,   319,   319,   319,   338,   319,   319,
     319,   331,   230,   334,   332,   332,   332,   338,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   230,   232,   264,   264,   264,   264,   264,   264,   230,
     264,   264,   230,   264,     5,   174,   234,     5,   174,     5,
     174,     5,   174,   116,    89,    92,    95,    97,   230,   264,
     264,   230,   230,   319,   234,   319,   333,   319,   319,   235,
     334,     9,   344,     8,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   229,     9,
     230,   232,   236,   263,   264,   319,   334,   230,   230,   230,
     331,   332,   332,   332,   230,   230,   230,   230,   230,   331,
     230,   331,   230,   331,   234,   234,   319,     4,   331,   335,
     234,   234,   328,   328,   328,   319,   319,   220,   221,   234,
     234,   328,   220,   221,   230,   290,   328,   234,   230,   234,
     230,   230,   230,   230,   230,   230,   230,   319,   332,   332,
     332,   230,     4,   232,   232,   290,     6,     6,   234,   234,
     234,   332,   332,   232,   232,   232,   319,     6,     6,   319,
     319,   319,   236,   319,   234,   174,   319,   319,   319,   319,
     264,   264,   264,   230,   230,   230,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   230,   230,   264,   232,
       6,     6,   234,     6,   290,     6,   290,   264,   319,   222,
     234,   230,   232,   338,   319,   290,   331,   331,   234,   339,
      89,    92,    95,    97,     7,   319,   319,     4,   171,   172,
     331,     6,   231,   233,   234,   265,     6,   234,     6,     9,
     230,   232,   236,   344,   235,    89,    92,    95,    97,   116,
     121,   124,   287,   319,     6,   231,   239,     9,   230,   232,
     236,   231,   239,   239,   231,   239,   233,   239,   267,   233,
     267,    85,   326,   323,   344,   239,   239,   231,   222,   235,
     239,   231,   231,   319,   231,   235,   231,   231,   319,   231,
     235,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,     7,   319,   235,     6,     6,     6,   231,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   333,   319,   319,   319,   319,
     319,   319,   319,   333,   333,   344,   234,   319,   319,   338,
     319,   338,   331,   338,   338,   342,   319,    64,   319,    64,
      64,    64,   332,   332,   332,   332,   338,   338,   333,   324,
     339,   334,   231,   235,     9,   264,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   234,   319,
     333,   319,   319,   319,   344,   319,   319,     4,   325,   234,
     265,   231,   235,   319,   319,   319,     7,     7,   312,   312,
     281,   319,   339,   282,   319,   339,   283,   319,   339,   284,
     319,   339,   319,     6,   319,     6,   319,     6,   334,   334,
     234,   231,     6,   234,   290,   290,   239,   239,   239,   328,
     328,   289,   289,   239,   319,   235,   303,   239,   290,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   231,     7,
     313,     6,     7,   319,     6,   319,   319,   235,   334,   334,
     334,     6,     6,   319,   319,   319,   231,   231,   231,   231,
     171,   239,   290,   234,     8,   231,   231,   233,   342,   338,
     342,   338,   338,   338,   338,   338,   338,   319,   338,   338,
     338,   338,   237,   341,   344,   339,   338,   338,   338,   344,
     334,   235,   235,   319,   319,   290,   233,   231,   146,   307,
     231,   235,   239,   319,     6,   234,   234,   234,   234,   319,
     231,   233,     7,   262,   263,   236,     7,     6,   334,     7,
     210,   262,   247,   344,   319,   319,   325,   232,   234,   234,
     234,   234,   230,   116,    92,    95,    97,   235,     6,   217,
     244,   334,   344,   319,   319,     4,   325,     6,   334,   319,
       6,   338,     6,   344,     6,   338,   319,   231,   232,   319,
     339,     7,   174,   319,   333,     7,     7,   231,     7,   174,
       7,     7,   231,     7,   174,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   319,   231,   234,     6,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   239,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   239,
     239,   239,   231,   233,   233,   334,   239,   239,   265,   239,
     265,   239,   239,   239,   231,   321,   234,   235,   234,   234,
     234,   239,   239,   265,   265,   231,   236,   231,   235,     7,
     265,     8,     8,   334,   236,   231,   233,   263,   334,     7,
     234,   231,   231,   231,   319,   331,     4,   311,     6,   231,
     239,   231,   239,   231,   239,   231,   239,   231,   231,   231,
     235,   235,   334,   236,   290,   235,   235,   328,   319,   319,
     235,   235,   319,   328,   126,   126,   143,   151,   152,   153,
     157,   158,   304,   305,   328,   235,   300,   231,   235,   231,
     231,   231,   231,   231,   231,   231,     7,   319,     6,   319,
     231,   233,   233,   235,   235,   235,   233,   233,   239,     7,
       7,     7,   236,   319,   235,   319,   319,     7,   236,   265,
     239,   265,   265,   231,   231,   239,   265,   265,   239,   239,
     265,   265,   265,   265,   319,   265,     9,   340,   239,   231,
     239,   265,   233,   235,   235,     7,     6,   319,   235,   234,
       6,   331,   235,   319,   319,   319,   319,     6,     7,   262,
     263,   236,   262,   263,   339,   319,     6,     4,   234,   336,
     344,   235,    46,    46,   331,     4,   161,   162,   163,   164,
     235,   250,   254,   257,   259,   260,   236,   231,   233,   319,
     334,   334,   334,   334,   319,   230,   230,   230,   230,   217,
     338,   231,   236,   231,   233,   231,   239,     7,   264,     4,
     275,   276,   277,   265,   265,   328,    95,    97,   331,   331,
       7,   331,    95,    97,   331,   331,     7,   331,    97,   331,
     331,   331,   331,   331,   331,   331,   331,   331,     6,     7,
     334,   319,   319,   319,   319,   235,   319,   319,   319,   331,
     338,   338,   239,   274,   319,   319,   319,   319,   319,   319,
     325,   331,   319,   319,   235,   325,   263,   236,   263,   235,
     331,   334,     7,     7,     7,   126,   310,     6,   262,   319,
     262,   319,   262,   319,   262,   319,     7,     7,     7,     7,
       7,   235,     4,   235,   239,   239,   239,   235,   235,   107,
       4,     6,   319,   234,     6,   230,     6,   159,     6,   159,
     235,   305,   239,   304,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   331,     6,   234,     6,     6,     6,    95,
       7,     6,     6,   319,   331,   331,   331,     4,   239,     8,
       8,   231,     4,     4,   334,   338,   319,   338,   237,   239,
     278,   338,   338,   239,   234,     6,   234,   331,   235,   235,
     235,   235,   235,   319,     6,     4,   171,   172,   319,     6,
       6,     6,     7,   335,   337,     6,   232,   265,   264,   264,
       6,   251,   230,   230,   234,   261,     6,   325,   236,   338,
     233,   235,   235,   235,   235,   231,   319,   319,   319,   319,
       6,     6,   244,   325,   236,     6,   319,   234,   319,   339,
     265,   234,   331,   339,   233,   239,     6,     6,     6,   234,
     234,   120,   286,   286,   331,     6,   234,   234,     6,     6,
     331,   174,   285,   234,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     5,   235,   265,   265,   265,   265,   265,
     239,   239,   239,   231,   265,   265,   276,   265,   239,   239,
     239,   239,   231,   265,   231,     6,     4,   265,     6,   235,
     331,   331,   331,     4,     6,   331,   331,   331,   331,   331,
     331,   331,   234,   234,     7,     6,     7,   319,   319,   319,
     234,   234,   234,   232,     6,   319,   331,   319,     6,     6,
     319,   328,   235,     5,   331,   234,   234,   234,   234,   234,
     234,   234,   331,     6,   334,   234,   319,   233,     6,     6,
     170,   319,   319,   319,     6,     6,     7,   265,   239,   239,
     265,   239,   319,     4,   186,   279,   280,   265,   231,   265,
     339,   290,   290,   239,     6,     6,     7,   262,   263,   236,
       7,     6,   335,   235,   239,   319,   262,   265,   342,   342,
     230,   319,   319,   330,   331,   234,     4,     6,     6,     6,
       6,     6,     6,   231,   231,   231,   231,   338,     4,   239,
     331,   339,     7,   273,   319,   333,   277,   319,   319,   328,
       6,     6,     6,   319,   319,     6,    93,     6,   319,     5,
     234,   319,   319,   319,   319,   319,   319,   319,   263,   234,
       6,   285,     6,   319,     6,     6,     6,     6,     6,     4,
       6,     6,   334,   334,   319,   319,   339,   235,   231,   235,
     239,   289,   289,   319,   319,   235,   239,   231,   235,   239,
       6,     6,   330,   328,   328,   328,   328,   328,   221,   328,
       6,   235,   319,     6,     6,   331,   235,   239,     8,   235,
     231,   234,   319,   339,   338,   319,   338,   234,   319,   339,
     339,   239,   239,   307,   307,   331,   339,   319,     6,     4,
     336,     6,   335,   233,   331,     6,   265,   265,   248,   319,
     239,   239,   235,   239,   249,   319,     6,   319,   269,   271,
     234,   235,   239,     7,     7,   235,   235,   235,   235,   234,
     235,     5,   330,   265,   265,   239,   239,   239,   239,   239,
     319,     6,   234,   235,   235,   234,     6,     6,   234,   319,
     235,   235,   235,   233,     6,   331,     7,   234,   319,   235,
     239,   239,   239,   239,   239,   239,     6,   235,   169,   319,
     319,   334,     6,     6,   231,   265,   265,   342,   280,   339,
     235,   235,   235,     6,     6,     7,     6,   236,     6,     6,
       6,   231,   239,   319,   319,   234,   331,   235,   239,   239,
     274,   278,   331,   319,   339,   344,     6,     6,     6,     6,
     319,     6,     6,   235,   319,   319,   319,   319,   319,   235,
     330,   130,   131,   136,   314,   130,   131,   314,   334,   289,
     235,   239,     6,   235,   331,   290,   235,     6,   334,   328,
     328,   328,   328,   328,   319,   235,   235,   235,   235,   231,
     234,     6,   335,   172,   252,   319,   239,   239,   330,     6,
     319,   319,   235,   235,   270,     7,   230,   235,   234,   239,
     239,   239,   239,   239,   235,   234,   328,   331,     6,   234,
     328,     6,   235,   235,   319,     6,   126,   235,   301,   234,
     235,   239,   239,   239,   239,   239,     6,     6,     6,   290,
       6,   234,   319,   319,   235,   239,   274,   339,   231,   319,
     319,   319,   319,   319,   319,     6,   328,     6,   328,     6,
       6,   235,   319,   304,   290,     6,   334,   334,   334,   334,
     328,   334,   307,   249,   231,   239,     6,   234,   319,   235,
     239,   239,   239,   239,   239,   239,   239,   239,     6,   235,
     235,   302,   235,   235,   235,   235,   239,   235,   235,   235,
     255,   319,   330,   235,   319,   319,   319,   319,   319,   319,
     328,   328,   304,     6,     6,     6,     6,   334,     6,     6,
       6,   234,   231,   235,     6,   235,   265,   239,   239,   239,
     239,   239,   239,   235,   235,   253,   338,   258,   234,     6,
     319,   319,   319,   319,   319,   319,     6,   235,   239,   234,
     330,   235,   235,   235,   235,   235,   235,     6,   338,   256,
     338,   235,     6,     6,   235,   239,     6,     6,   338
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
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 228:
#line 2777 "Gmsh.y"
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

  case 229:
#line 2792 "Gmsh.y"
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

  case 230:
#line 2820 "Gmsh.y"
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

  case 231:
#line 2837 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 232:
#line 2844 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 233:
#line 2856 "Gmsh.y"
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

  case 234:
#line 2875 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 235:
#line 2881 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 236:
#line 2887 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 237:
#line 2894 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 238:
#line 2901 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 2908 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 2920 "Gmsh.y"
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

  case 241:
#line 2993 "Gmsh.y"
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

  case 242:
#line 3011 "Gmsh.y"
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

  case 243:
#line 3028 "Gmsh.y"
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

  case 244:
#line 3043 "Gmsh.y"
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

  case 245:
#line 3076 "Gmsh.y"
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

  case 246:
#line 3088 "Gmsh.y"
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

  case 247:
#line 3112 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 248:
#line 3116 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 249:
#line 3121 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 250:
#line 3128 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 251:
#line 3133 "Gmsh.y"
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

  case 252:
#line 3143 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 253:
#line 3148 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 254:
#line 3154 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 255:
#line 3162 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 256:
#line 3166 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 257:
#line 3170 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 258:
#line 3180 "Gmsh.y"
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

  case 259:
#line 3243 "Gmsh.y"
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

  case 260:
#line 3259 "Gmsh.y"
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

  case 261:
#line 3276 "Gmsh.y"
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

  case 262:
#line 3293 "Gmsh.y"
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

  case 263:
#line 3315 "Gmsh.y"
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

  case 264:
#line 3337 "Gmsh.y"
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

  case 265:
#line 3372 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 266:
#line 3380 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 267:
#line 3388 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 268:
#line 3394 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 269:
#line 3401 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 270:
#line 3408 "Gmsh.y"
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

  case 271:
#line 3428 "Gmsh.y"
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

  case 272:
#line 3454 "Gmsh.y"
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

  case 273:
#line 3466 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 274:
#line 3478 "Gmsh.y"
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

  case 275:
#line 3494 "Gmsh.y"
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

  case 276:
#line 3510 "Gmsh.y"
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

  case 277:
#line 3526 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 278:
#line 3532 "Gmsh.y"
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

  case 279:
#line 3548 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3554 "Gmsh.y"
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

  case 281:
#line 3572 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3578 "Gmsh.y"
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

  case 283:
#line 3594 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3600 "Gmsh.y"
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

  case 285:
#line 3615 "Gmsh.y"
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

  case 286:
#line 3629 "Gmsh.y"
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

  case 287:
#line 3644 "Gmsh.y"
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

  case 288:
#line 3659 "Gmsh.y"
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

  case 289:
#line 3680 "Gmsh.y"
    {
    ;}
    break;

  case 290:
#line 3683 "Gmsh.y"
    {
    ;}
    break;

  case 291:
#line 3689 "Gmsh.y"
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

  case 292:
#line 3701 "Gmsh.y"
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

  case 293:
#line 3721 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 294:
#line 3725 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 295:
#line 3729 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 296:
#line 3733 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 297:
#line 3737 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 298:
#line 3741 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 299:
#line 3745 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3749 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 301:
#line 3758 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 302:
#line 3770 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 303:
#line 3771 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 304:
#line 3772 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 305:
#line 3773 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 306:
#line 3774 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 307:
#line 3778 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 308:
#line 3779 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 309:
#line 3780 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 310:
#line 3785 "Gmsh.y"
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

  case 311:
#line 3802 "Gmsh.y"
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

  case 312:
#line 3820 "Gmsh.y"
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

  case 313:
#line 3835 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 314:
#line 3839 "Gmsh.y"
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

  case 315:
#line 3854 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 316:
#line 3858 "Gmsh.y"
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

  case 317:
#line 3874 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 318:
#line 3878 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 319:
#line 3883 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 320:
#line 3887 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 321:
#line 3893 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 322:
#line 3897 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 323:
#line 3904 "Gmsh.y"
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

  case 324:
#line 3921 "Gmsh.y"
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

  case 325:
#line 3962 "Gmsh.y"
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

  case 326:
#line 4006 "Gmsh.y"
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

  case 327:
#line 4045 "Gmsh.y"
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

  case 328:
#line 4070 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 329:
#line 4079 "Gmsh.y"
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

  case 330:
#line 4109 "Gmsh.y"
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

  case 331:
#line 4135 "Gmsh.y"
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

  case 332:
#line 4162 "Gmsh.y"
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

  case 333:
#line 4194 "Gmsh.y"
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

  case 334:
#line 4221 "Gmsh.y"
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

  case 335:
#line 4247 "Gmsh.y"
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

  case 336:
#line 4273 "Gmsh.y"
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

  case 337:
#line 4299 "Gmsh.y"
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

  case 338:
#line 4325 "Gmsh.y"
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

  case 339:
#line 4346 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 340:
#line 4352 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 341:
#line 4358 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 342:
#line 4364 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 343:
#line 4370 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 344:
#line 4376 "Gmsh.y"
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

  case 345:
#line 4402 "Gmsh.y"
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

  case 346:
#line 4428 "Gmsh.y"
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

  case 347:
#line 4445 "Gmsh.y"
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

  case 348:
#line 4462 "Gmsh.y"
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

  case 349:
#line 4479 "Gmsh.y"
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

  case 350:
#line 4491 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 351:
#line 4497 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 352:
#line 4503 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 353:
#line 4515 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 354:
#line 4519 "Gmsh.y"
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

  case 355:
#line 4529 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 356:
#line 4539 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 357:
#line 4540 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 358:
#line 4541 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 359:
#line 4546 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 360:
#line 4552 "Gmsh.y"
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

  case 361:
#line 4564 "Gmsh.y"
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

  case 362:
#line 4582 "Gmsh.y"
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

  case 363:
#line 4609 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 364:
#line 4610 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 365:
#line 4611 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 366:
#line 4612 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 367:
#line 4613 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 368:
#line 4614 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 369:
#line 4615 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 370:
#line 4616 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 371:
#line 4618 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 372:
#line 4624 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 373:
#line 4625 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 374:
#line 4626 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4627 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 376:
#line 4628 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 377:
#line 4629 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 378:
#line 4630 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 379:
#line 4631 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 380:
#line 4632 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 381:
#line 4633 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 382:
#line 4634 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 383:
#line 4635 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 384:
#line 4636 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 385:
#line 4637 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 386:
#line 4638 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 387:
#line 4639 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 388:
#line 4640 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 389:
#line 4641 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 390:
#line 4642 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 391:
#line 4643 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 392:
#line 4644 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 393:
#line 4645 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 394:
#line 4646 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 395:
#line 4647 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 396:
#line 4648 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4649 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 398:
#line 4650 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 399:
#line 4651 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 400:
#line 4652 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4653 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 402:
#line 4654 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 403:
#line 4655 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 404:
#line 4656 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 405:
#line 4657 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 406:
#line 4666 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 407:
#line 4667 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 408:
#line 4668 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 409:
#line 4669 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 410:
#line 4670 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 411:
#line 4671 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 412:
#line 4672 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 413:
#line 4673 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 414:
#line 4674 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 415:
#line 4675 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 416:
#line 4676 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 417:
#line 4681 "Gmsh.y"
    { init_Options(); ;}
    break;

  case 418:
#line 4683 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 419:
#line 4689 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 420:
#line 4691 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 421:
#line 4696 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 422:
#line 4702 "Gmsh.y"
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

  case 423:
#line 4722 "Gmsh.y"
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

  case 424:
#line 4740 "Gmsh.y"
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

  case 425:
#line 4758 "Gmsh.y"
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

  case 426:
#line 4770 "Gmsh.y"
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

  case 427:
#line 4780 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 428:
#line 4786 "Gmsh.y"
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

  case 429:
#line 4802 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 430:
#line 4808 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 431:
#line 4814 "Gmsh.y"
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

  case 432:
#line 4833 "Gmsh.y"
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

  case 433:
#line 4854 "Gmsh.y"
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

  case 434:
#line 4887 "Gmsh.y"
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

  case 435:
#line 4909 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 436:
#line 4914 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 437:
#line 4919 "Gmsh.y"
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

  case 438:
#line 4929 "Gmsh.y"
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

  case 439:
#line 4939 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 440:
#line 4944 "Gmsh.y"
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

  case 441:
#line 4955 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 442:
#line 4964 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 443:
#line 4969 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 444:
#line 4974 "Gmsh.y"
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

  case 445:
#line 5002 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_Options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 446:
#line 5009 "Gmsh.y"
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

  case 447:
#line 5025 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 448:
#line 5027 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 449:
#line 5032 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 450:
#line 5041 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 451:
#line 5043 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 452:
#line 5048 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 453:
#line 5050 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 454:
#line 5056 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 455:
#line 5060 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 456:
#line 5064 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 457:
#line 5068 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 458:
#line 5072 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 459:
#line 5079 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 460:
#line 5083 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 461:
#line 5087 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 462:
#line 5091 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 463:
#line 5098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 464:
#line 5103 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 465:
#line 5110 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 466:
#line 5115 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 467:
#line 5119 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 468:
#line 5124 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 469:
#line 5128 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 470:
#line 5136 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 471:
#line 5147 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 472:
#line 5151 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 473:
#line 5163 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 474:
#line 5171 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 475:
#line 5179 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 476:
#line 5186 "Gmsh.y"
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

  case 477:
#line 5196 "Gmsh.y"
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

  case 478:
#line 5219 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 479:
#line 5225 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 480:
#line 5231 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 481:
#line 5237 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 482:
#line 5243 "Gmsh.y"
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

  case 483:
#line 5254 "Gmsh.y"
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

  case 484:
#line 5265 "Gmsh.y"
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

  case 485:
#line 5276 "Gmsh.y"
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

  case 486:
#line 5288 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 487:
#line 5294 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 488:
#line 5300 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 489:
#line 5306 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 490:
#line 5311 "Gmsh.y"
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

  case 491:
#line 5321 "Gmsh.y"
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

  case 492:
#line 5331 "Gmsh.y"
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

  case 493:
#line 5341 "Gmsh.y"
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

  case 494:
#line 5354 "Gmsh.y"
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

  case 495:
#line 5366 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 496:
#line 5370 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 497:
#line 5374 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 498:
#line 5378 "Gmsh.y"
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

  case 499:
#line 5396 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 500:
#line 5404 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 501:
#line 5412 "Gmsh.y"
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

  case 502:
#line 5441 "Gmsh.y"
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

  case 503:
#line 5451 "Gmsh.y"
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

  case 504:
#line 5467 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 505:
#line 5478 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 506:
#line 5483 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 507:
#line 5487 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 508:
#line 5491 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 509:
#line 5503 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 510:
#line 5507 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 511:
#line 5519 "Gmsh.y"
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

  case 512:
#line 5536 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 513:
#line 5546 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 514:
#line 5550 "Gmsh.y"
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

  case 515:
#line 5565 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 516:
#line 5570 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 517:
#line 5577 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 518:
#line 5581 "Gmsh.y"
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

  case 519:
#line 5594 "Gmsh.y"
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

  case 520:
#line 5608 "Gmsh.y"
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

  case 521:
#line 5625 "Gmsh.y"
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

  case 522:
#line 5653 "Gmsh.y"
    { (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 523:
#line 5657 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 524:
#line 5665 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 525:
#line 5671 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 526:
#line 5677 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 527:
#line 5683 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 528:
#line 5692 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 529:
#line 5696 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 530:
#line 5700 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 531:
#line 5708 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 532:
#line 5714 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 533:
#line 5720 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 534:
#line 5728 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 535:
#line 5736 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 536:
#line 5743 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 537:
#line 5751 "Gmsh.y"
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

  case 538:
#line 5766 "Gmsh.y"
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

  case 539:
#line 5780 "Gmsh.y"
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

  case 540:
#line 5794 "Gmsh.y"
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

  case 541:
#line 5806 "Gmsh.y"
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

  case 542:
#line 5822 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 543:
#line 5831 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 544:
#line 5840 "Gmsh.y"
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

  case 545:
#line 5850 "Gmsh.y"
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

  case 546:
#line 5861 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 547:
#line 5869 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 548:
#line 5877 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 549:
#line 5881 "Gmsh.y"
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

  case 550:
#line 5900 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 551:
#line 5907 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 552:
#line 5913 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 553:
#line 5920 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 554:
#line 5927 "Gmsh.y"
    { init_Options(); ;}
    break;

  case 555:
#line 5929 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 556:
#line 5937 "Gmsh.y"
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

  case 557:
#line 5961 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 558:
#line 5963 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 559:
#line 5969 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 560:
#line 5974 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 561:
#line 5982 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 562:
#line 5991 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 563:
#line 6004 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 564:
#line 6007 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 565:
#line 6011 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 12927 "Gmsh.tab.cpp"
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


#line 6014 "Gmsh.y"


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

