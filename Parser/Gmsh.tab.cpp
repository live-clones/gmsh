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
#line 691 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 704 "Gmsh.tab.cpp"

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
#define YYLAST   13632

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  557
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2070

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
    2729,  2736,  2745,  2754,  2759,  2774,  2779,  2784,  2786,  2788,
    2792,  2796,  2806,  2814,  2816,  2822,  2826,  2833,  2835,  2839,
    2841,  2843,  2848,  2853,  2857,  2863,  2870,  2876,  2882,  2888,
    2894,  2896,  2901,  2903,  2905,  2907,  2912,  2919,  2924,  2931,
    2936,  2941,  2946,  2955,  2960,  2965,  2970,  2975,  2984,  2993,
    3000,  3005,  3012,  3017,  3019,  3024,  3029,  3030,  3037,  3042,
    3045,  3050,  3052,  3056,  3062,  3068,  3070,  3072
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     241,     0,    -1,   242,    -1,     1,     6,    -1,    -1,   242,
     243,    -1,   245,    -1,   246,    -1,   266,    -1,   115,   230,
     335,   231,     6,    -1,   284,    -1,   285,    -1,   289,    -1,
     290,    -1,   291,    -1,   292,    -1,   296,    -1,   305,    -1,
     306,    -1,   312,    -1,   313,    -1,   295,    -1,   294,    -1,
     293,    -1,   288,    -1,   315,    -1,   217,    -1,   217,   217,
      -1,    44,   230,   335,   231,     6,    -1,    45,   230,   335,
     231,     6,    -1,    44,   230,   335,   231,   244,   335,     6,
      -1,    44,   230,   335,   239,   331,   231,     6,    -1,    45,
     230,   335,   239,   331,   231,     6,    -1,    44,   230,   335,
     239,   331,   231,   244,   335,     6,    -1,   341,   335,   234,
     247,   235,     6,    -1,   154,     4,   232,   316,   233,     6,
      -1,   155,     4,   232,   316,   233,     6,    -1,   156,     4,
     232,   316,   239,   316,   233,     6,    -1,    -1,   247,   250,
      -1,   247,   254,    -1,   247,   257,    -1,   247,   259,    -1,
     247,   260,    -1,   316,    -1,   248,   239,   316,    -1,   316,
      -1,   249,   239,   316,    -1,    -1,    -1,     4,   251,   230,
     248,   231,   252,   234,   249,   235,     6,    -1,   335,    -1,
     253,   239,   335,    -1,    -1,   161,   230,   316,   239,   316,
     239,   316,   231,   255,   234,   253,   235,     6,    -1,   335,
      -1,   256,   239,   335,    -1,    -1,   162,   230,   316,   239,
     316,   239,   316,   239,   316,   231,   258,   234,   256,   235,
       6,    -1,   163,   234,   327,   235,   234,   327,   235,     6,
      -1,   163,   234,   327,   235,   234,   327,   235,   234,   327,
     235,   234,   327,   235,     6,    -1,    -1,   164,   261,   234,
     249,   235,     6,    -1,     7,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   228,    -1,   227,    -1,   230,    -1,
     232,    -1,   231,    -1,   233,    -1,    80,   232,   268,   233,
       6,    -1,    81,   232,   272,   233,     6,    -1,   319,     6,
      -1,    87,   264,   336,   239,   316,   265,     6,    -1,    88,
     264,   341,   239,   336,   265,     6,    -1,   341,   262,   328,
       6,    -1,   341,   263,     6,    -1,   341,   264,   265,   262,
     328,     6,    -1,   341,   264,   234,   331,   235,   265,   262,
     328,     6,    -1,   341,   232,   316,   233,   262,   316,     6,
      -1,   341,   232,   316,   233,   263,     6,    -1,   341,   230,
     316,   231,   262,   316,     6,    -1,   341,   230,   316,   231,
     263,     6,    -1,   341,     7,   336,     6,    -1,   341,   264,
     265,     7,    46,   264,   265,     6,    -1,   341,   264,   265,
       7,    46,   264,   339,   265,     6,    -1,   341,   264,   265,
     210,    46,   264,   339,   265,     6,    -1,   341,   236,     4,
       7,   336,     6,    -1,   341,   232,   316,   233,   236,     4,
       7,   336,     6,    -1,   341,   236,     4,   262,   316,     6,
      -1,   341,   232,   316,   233,   236,     4,   262,   316,     6,
      -1,   341,   236,     4,   263,     6,    -1,   341,   232,   316,
     233,   236,     4,   263,     6,    -1,   341,   236,   171,   236,
       4,     7,   332,     6,    -1,   341,   232,   316,   233,   236,
     171,   236,     4,     7,   332,     6,    -1,   341,   236,   172,
       7,   333,     6,    -1,   341,   232,   316,   233,   236,   172,
       7,   333,     6,    -1,   341,   182,     7,   316,     6,    -1,
     182,   232,   316,   233,     7,     4,     6,    -1,   182,   232,
     316,   233,   236,     4,     7,   316,     6,    -1,   182,   232,
     316,   233,   236,     4,     7,   336,     6,    -1,   182,   232,
     316,   233,   236,     4,     7,   234,   331,   235,     6,    -1,
     182,   232,   316,   233,   236,     4,     6,    -1,   127,   230,
       4,   231,   236,     4,     7,   316,     6,    -1,   127,   230,
       4,   231,   236,     4,     7,   336,     6,    -1,    -1,   239,
      -1,    -1,   268,   267,   341,    -1,   268,   267,   341,     7,
     316,    -1,    -1,   268,   267,   341,     7,   234,   328,   269,
     274,   235,    -1,    -1,   268,   267,   341,   264,   265,     7,
     234,   328,   270,   274,   235,    -1,   268,   267,   341,     7,
     336,    -1,    -1,   268,   267,   341,     7,   234,   336,   271,
     276,   235,    -1,    -1,   272,   267,   335,    -1,   316,     7,
     336,    -1,   273,   239,   316,     7,   336,    -1,   330,     7,
     341,   230,   231,    -1,    -1,   274,   275,    -1,   239,     4,
     328,    -1,   239,     4,   234,   273,   235,    -1,   239,     4,
     336,    -1,    -1,   276,   277,    -1,   239,     4,   316,    -1,
     239,     4,   336,    -1,   239,   186,   336,    -1,   239,     4,
     234,   339,   235,    -1,   316,    -1,   336,    -1,   336,   239,
     316,    -1,   316,    -1,   336,    -1,   336,   239,   316,    -1,
     316,    -1,   336,    -1,   336,   239,   316,    -1,   316,    -1,
     336,    -1,   336,   239,   316,    -1,    -1,   174,    93,   234,
     316,   235,    -1,    -1,   120,   325,    -1,    89,   230,   316,
     231,     7,   325,     6,    -1,    92,   230,   316,   231,     7,
     328,     6,    -1,    96,   230,   316,   231,     7,   328,     6,
      -1,    90,   230,   316,   231,     7,   328,   283,     6,    -1,
      91,   230,   316,   231,     7,   328,   283,     6,    -1,   166,
     230,   316,   231,     7,   328,     6,    -1,   167,   230,   316,
     231,     7,   328,     6,    -1,   168,   230,   316,   231,     7,
     328,   170,   328,   169,   316,     6,    -1,   124,    92,   230,
     316,   231,     7,   328,     6,    -1,   107,   230,   316,   231,
       7,   328,     6,    -1,    92,     4,   230,   316,   231,     7,
     328,     6,    -1,   120,    95,   230,   316,   231,     7,   328,
       6,    -1,    95,   230,   316,   231,     7,   328,   282,     6,
      -1,   121,    95,   230,   316,   231,     7,   328,   282,     6,
      -1,    13,    14,     6,    -1,    14,    95,   316,     6,    -1,
     110,    95,   230,   316,   231,     7,     5,     5,     5,     6,
      -1,    93,   230,   316,   231,     7,   328,     6,    -1,    94,
     230,   316,   231,     7,   328,     6,    -1,    98,   230,   316,
     231,     7,   328,     6,    -1,   101,   230,   316,   231,     7,
     328,     6,    -1,   105,   230,   316,   231,     7,   328,     6,
      -1,   106,   230,   316,   231,     7,   328,     6,    -1,    99,
     230,   316,   231,     7,   328,     6,    -1,   100,   230,   316,
     231,     7,   328,     6,    -1,   117,   230,   316,   231,     7,
     328,     6,    -1,   142,   230,   316,   231,     7,   328,     6,
      -1,   124,    95,   230,   316,   231,     7,   328,     6,    -1,
     124,    95,   230,   316,   231,     7,   328,     4,   234,   327,
     235,     6,    -1,    95,     4,   230,   316,   231,     7,   328,
       6,    -1,    97,   230,   316,   231,     7,   328,     6,    -1,
     116,   230,   316,   231,     7,   328,     6,    -1,   121,   116,
     230,   316,   231,     7,   328,     6,    -1,   124,    97,   230,
     316,   231,     7,   328,     6,    -1,   123,    89,   230,   278,
     231,   262,   328,     6,    -1,   123,    92,   230,   279,   231,
     262,   328,     6,    -1,   123,    95,   230,   280,   231,   262,
     328,     6,    -1,   123,    97,   230,   281,   231,   262,   328,
       6,    -1,   131,   325,   234,   286,   235,    -1,   130,   234,
     325,   239,   325,   239,   316,   235,   234,   286,   235,    -1,
     132,   325,   234,   286,   235,    -1,   133,   234,   325,   239,
     316,   235,   234,   286,   235,    -1,   133,   234,   325,   239,
     325,   235,   234,   286,   235,    -1,     4,   234,   286,   235,
      -1,   148,    92,   234,   331,   235,    95,   234,   316,   235,
      -1,   145,    92,   230,   316,   231,   234,   331,   235,     6,
      -1,   287,    -1,   285,    -1,    -1,   287,   284,    -1,   287,
      89,   234,   331,   235,     6,    -1,   287,    92,   234,   331,
     235,     6,    -1,   287,    95,   234,   331,   235,     6,    -1,
     287,    97,   234,   331,   235,     6,    -1,   135,   120,   230,
     316,   231,     7,   328,     6,    -1,   135,    89,   230,   316,
     231,     7,   234,   327,   235,     6,    -1,   135,   120,   230,
     316,   231,     7,   234,   325,   239,   325,   239,   331,   235,
       6,    -1,   135,   120,   230,   316,   231,     7,   234,   325,
     239,   325,   239,   325,   239,   331,   235,     6,    -1,   135,
      93,   230,   316,   231,     7,   234,   325,   239,   331,   235,
       6,    -1,   135,    99,   230,   316,   231,     7,   234,   325,
     239,   325,   239,   331,   235,     6,    -1,   135,   100,   230,
     316,   231,     7,   234,   325,   239,   325,   239,   331,   235,
       6,    -1,   135,   102,   230,   316,   231,     7,   234,   325,
     239,   325,   239,   331,   235,     6,    -1,   135,   103,   230,
     316,   231,     7,   234,   325,   239,   325,   239,   331,   235,
       6,    -1,   135,     4,   230,   316,   231,     7,   328,     6,
      -1,   135,     4,   230,   316,   231,     7,     5,     6,    -1,
     135,     4,   234,   316,   235,     6,    -1,   146,   234,   287,
     235,    -1,   146,   182,   232,   316,   233,     6,    -1,   146,
       4,   232,   316,   233,     6,    -1,   146,   341,     6,    -1,
     146,     4,     4,     6,    -1,   171,   332,   234,   287,   235,
      -1,   129,   171,   332,   234,   287,   235,    -1,   204,   316,
     234,   287,   235,    -1,   187,     5,     6,    -1,   188,     5,
       6,    -1,   187,   234,   287,   235,    -1,   129,   187,   234,
     287,   235,    -1,   188,   234,   287,   235,    -1,   129,   188,
     234,   287,   235,    -1,   341,   336,     6,    -1,    73,   230,
     339,   231,     6,    -1,   341,   341,   232,   316,   233,   335,
       6,    -1,   341,   341,   341,   232,   316,   233,     6,    -1,
     341,   316,     6,    -1,   127,   230,     4,   231,   236,     4,
       6,    -1,   165,     4,     6,    -1,   180,     6,    -1,   181,
       6,    -1,    70,     6,    -1,    71,     6,    -1,    64,     6,
      -1,    64,   234,   316,   239,   316,   239,   316,   239,   316,
     239,   316,   239,   316,   235,     6,    -1,    65,     6,    -1,
      66,     6,    -1,    77,     6,    -1,    78,     6,    -1,   112,
       6,    -1,   113,   234,   331,   235,   234,   331,   235,   234,
     327,   235,   234,   316,   239,   316,   235,     6,    -1,   185,
     230,   234,   331,   235,   239,   336,   239,   336,   231,     6,
      -1,   173,   230,   316,     8,   316,   231,    -1,   173,   230,
     316,     8,   316,     8,   316,   231,    -1,   173,     4,   174,
     234,   316,     8,   316,   235,    -1,   173,     4,   174,   234,
     316,     8,   316,     8,   316,   235,    -1,   175,    -1,   186,
       4,    -1,   186,   336,    -1,   183,    -1,   184,   341,     6,
      -1,   184,   336,     6,    -1,   176,   230,   316,   231,    -1,
     177,   230,   316,   231,    -1,   178,    -1,   179,    -1,   134,
     325,   234,   287,   235,    -1,   134,   234,   325,   239,   325,
     239,   316,   235,   234,   287,   235,    -1,   134,   234,   325,
     239,   325,   239,   325,   239,   316,   235,   234,   287,   235,
      -1,    -1,   134,   325,   234,   287,   297,   301,   235,    -1,
      -1,   134,   234,   325,   239,   325,   239,   316,   235,   234,
     287,   298,   301,   235,    -1,    -1,   134,   234,   325,   239,
     325,   239,   325,   239,   316,   235,   234,   287,   299,   301,
     235,    -1,    -1,   134,   234,   287,   300,   301,   235,    -1,
     134,   234,   287,   235,   126,   107,   234,   316,   235,    -1,
     116,   328,    -1,   121,   116,   328,    -1,   118,   234,   331,
     235,   234,   331,   235,   234,   316,   235,    -1,   302,    -1,
     301,   302,    -1,   151,   234,   316,   235,     6,    -1,   151,
     234,   328,   239,   328,   235,     6,    -1,   152,     6,    -1,
     143,     6,    -1,   143,   316,     6,    -1,   157,     6,    -1,
     157,   159,     6,    -1,   158,     6,    -1,   158,   159,     6,
      -1,   153,   230,   316,   231,     7,   328,   126,   316,     6,
      -1,   126,     4,   232,   316,   233,     6,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,    -1,   146,
       6,    -1,   146,   316,     6,    -1,   303,   234,   287,   304,
     235,   234,   287,   304,   235,    -1,   104,   230,   335,   231,
      -1,   303,   230,   316,   231,     7,   234,   287,   304,   235,
     234,   287,   304,   235,     6,    -1,    -1,   126,     4,   316,
      -1,    -1,     4,    -1,    -1,     7,   328,    -1,    -1,     7,
     316,    -1,    -1,   136,   328,    -1,   108,   109,   328,     7,
     316,     6,    -1,   122,    92,   329,     7,   316,   307,     6,
      -1,   122,    95,   329,   309,   308,     6,    -1,   122,    97,
     329,   309,     6,    -1,   160,   329,     6,    -1,   149,    95,
     234,   331,   235,     7,   316,     6,    -1,   143,    95,   329,
     310,     6,    -1,   143,    97,   329,     6,    -1,   144,    95,
     329,     7,   316,     6,    -1,   125,    92,   234,   331,   235,
       7,   234,   331,   235,   311,     6,    -1,   125,    95,   234,
     331,   235,     7,   234,   331,   235,   311,     6,    -1,   125,
      92,   234,   331,   235,     7,   234,   331,   235,   130,   234,
     325,   239,   325,   239,   316,   235,     6,    -1,   125,    95,
     234,   331,   235,     7,   234,   331,   235,   130,   234,   325,
     239,   325,   239,   316,   235,     6,    -1,   125,    92,   234,
     331,   235,     7,   234,   331,   235,   131,   325,     6,    -1,
     125,    95,   234,   331,   235,     7,   234,   331,   235,   131,
     325,     6,    -1,   125,    95,   316,   234,   331,   235,     7,
     316,   234,   331,   235,     6,    -1,    89,   234,   331,   235,
     174,    95,   234,   316,   235,     6,    -1,    92,   234,   331,
     235,   174,    95,   234,   316,   235,     6,    -1,    89,   234,
     331,   235,   174,    97,   234,   316,   235,     6,    -1,    92,
     234,   331,   235,   174,    97,   234,   316,   235,     6,    -1,
      95,   234,   331,   235,   174,    97,   234,   316,   235,     6,
      -1,   150,    95,   329,     6,    -1,   150,    92,   329,     6,
      -1,   114,    89,   329,     6,    -1,   114,    92,   329,     6,
      -1,   114,    95,   329,     6,    -1,   128,    92,   328,     6,
      -1,   124,    92,   328,     6,    -1,   124,    95,   328,     6,
      -1,   124,    97,   328,     6,    -1,   147,     6,    -1,   147,
       4,     6,    -1,   147,    89,   234,   331,   235,     6,    -1,
     195,    -1,   196,    -1,   197,    -1,   314,     6,    -1,   314,
     234,   328,   235,     6,    -1,   314,   234,   328,   239,   328,
     235,     6,    -1,   314,   230,   328,   231,   234,   328,   239,
     328,   235,     6,    -1,   317,    -1,   230,   316,   231,    -1,
     221,   316,    -1,   220,   316,    -1,   225,   316,    -1,   316,
     221,   316,    -1,   316,   220,   316,    -1,   316,   222,   316,
      -1,   316,   223,   316,    -1,   316,   224,   316,    -1,   316,
     229,   316,    -1,   316,   216,   316,    -1,   316,   217,   316,
      -1,   316,   219,   316,    -1,   316,   218,   316,    -1,   316,
     215,   316,    -1,   316,   214,   316,    -1,   316,   213,   316,
      -1,   316,   212,   316,    -1,   316,   211,   316,     8,   316,
      -1,    16,   264,   316,   265,    -1,    17,   264,   316,   265,
      -1,    18,   264,   316,   265,    -1,    19,   264,   316,   265,
      -1,    20,   264,   316,   265,    -1,    21,   264,   316,   265,
      -1,    22,   264,   316,   265,    -1,    23,   264,   316,   265,
      -1,    24,   264,   316,   265,    -1,    26,   264,   316,   265,
      -1,    27,   264,   316,   239,   316,   265,    -1,    28,   264,
     316,   265,    -1,    29,   264,   316,   265,    -1,    30,   264,
     316,   265,    -1,    31,   264,   316,   265,    -1,    32,   264,
     316,   265,    -1,    33,   264,   316,   265,    -1,    34,   264,
     316,   265,    -1,    35,   264,   316,   265,    -1,    36,   264,
     316,   239,   316,   265,    -1,    37,   264,   316,   239,   316,
     265,    -1,    38,   264,   316,   239,   316,   265,    -1,    25,
     264,   316,   265,    -1,     3,    -1,    10,    -1,    15,    -1,
      11,    -1,    12,    -1,   200,    -1,   201,    -1,   202,    -1,
      74,    -1,    75,    -1,    76,    -1,    -1,    82,   264,   316,
     318,   274,   265,    -1,   319,    -1,   193,   264,   335,   265,
      -1,   193,   264,   335,   239,   316,   265,    -1,   321,    -1,
     341,   232,   316,   233,    -1,   341,   230,   316,   231,    -1,
     198,   230,   341,   231,    -1,   199,   230,   336,   231,    -1,
     237,   341,   264,   265,    -1,   237,   341,     9,    -1,   237,
       9,    -1,   341,   263,    -1,   341,   232,   316,   233,   263,
      -1,   341,   230,   316,   231,   263,    -1,   341,   236,   322,
      -1,   341,     9,   341,   236,   322,    -1,   341,   232,   316,
     233,   236,     4,    -1,   341,   236,     4,   263,    -1,   341,
     232,   316,   233,   236,     4,   263,    -1,   189,   230,   335,
     239,   316,   231,    -1,    56,   230,   328,   239,   328,   231,
      -1,    57,   264,   335,   239,   335,   265,    -1,    55,   264,
     335,   265,    -1,    58,   264,   335,   239,   335,   265,    -1,
      63,   230,   339,   231,    -1,    -1,    83,   321,   324,   320,
     232,   316,   274,   233,    -1,   341,    -1,   341,     9,   341,
      -1,     4,    -1,    85,    -1,    85,   316,    -1,    -1,   230,
     323,   231,    -1,   326,    -1,   221,   325,    -1,   220,   325,
      -1,   325,   221,   325,    -1,   325,   220,   325,    -1,   234,
     316,   239,   316,   239,   316,   239,   316,   239,   316,   235,
      -1,   234,   316,   239,   316,   239,   316,   239,   316,   235,
      -1,   234,   316,   239,   316,   239,   316,   235,    -1,   230,
     316,   239,   316,   239,   316,   231,    -1,   328,    -1,   327,
     239,   328,    -1,   316,    -1,   330,    -1,   234,   235,    -1,
     234,   331,   235,    -1,   221,   234,   331,   235,    -1,   316,
     222,   234,   331,   235,    -1,   328,    -1,     5,    -1,   221,
     330,    -1,   316,   222,   330,    -1,   316,     8,   316,    -1,
     316,     8,   316,     8,   316,    -1,    89,   234,   316,   235,
      -1,    89,     5,    -1,    92,     5,    -1,    95,     5,    -1,
      97,     5,    -1,   123,    89,   329,    -1,   123,    92,   329,
      -1,   123,    95,   329,    -1,   123,    97,   329,    -1,    89,
     174,    64,   234,   316,   239,   316,   239,   316,   239,   316,
     239,   316,   239,   316,   235,    -1,    92,   174,    64,   234,
     316,   239,   316,   239,   316,   239,   316,   239,   316,   239,
     316,   235,    -1,    95,   174,    64,   234,   316,   239,   316,
     239,   316,   239,   316,   239,   316,   239,   316,   235,    -1,
      97,   174,    64,   234,   316,   239,   316,   239,   316,   239,
     316,   239,   316,   239,   316,   235,    -1,   285,    -1,   296,
      -1,   305,    -1,   341,   264,   265,    -1,    39,   232,   341,
     233,    -1,    39,   232,   330,   233,    -1,    39,   230,   330,
     231,    -1,    39,   264,   234,   331,   235,   265,    -1,   341,
     264,   234,   331,   235,   265,    -1,    40,   264,   316,   239,
     316,   239,   316,   265,    -1,    41,   264,   316,   239,   316,
     239,   316,   265,    -1,    42,   264,   335,   265,    -1,    43,
     264,   316,   239,   316,   239,   316,   239,   316,   239,   316,
     239,   316,   265,    -1,   194,   264,   330,   265,    -1,    32,
     264,   330,   265,    -1,   316,    -1,   330,    -1,   331,   239,
     316,    -1,   331,   239,   330,    -1,   234,   316,   239,   316,
     239,   316,   239,   316,   235,    -1,   234,   316,   239,   316,
     239,   316,   235,    -1,   341,    -1,     4,   236,   171,   236,
       4,    -1,   234,   334,   235,    -1,   341,   232,   316,   233,
     236,   172,    -1,   332,    -1,   334,   239,   332,    -1,   336,
      -1,   341,    -1,   341,   232,   316,   233,    -1,   341,   230,
     316,   231,    -1,   341,   236,   322,    -1,   341,     9,   341,
     236,   322,    -1,   341,   232,   316,   233,   236,     4,    -1,
     123,    89,   234,   316,   235,    -1,   123,    92,   234,   316,
     235,    -1,   123,    95,   234,   316,   235,    -1,   123,    97,
     234,   316,   235,    -1,     5,    -1,   205,   232,   341,   233,
      -1,    67,    -1,   203,    -1,    72,    -1,   191,   230,   335,
     231,    -1,   190,   230,   335,   239,   335,   231,    -1,   192,
     264,   335,   265,    -1,   192,   264,   335,   239,   335,   265,
      -1,    48,   264,   339,   265,    -1,    49,   230,   335,   231,
      -1,    50,   230,   335,   231,    -1,    51,   230,   335,   239,
     335,   239,   335,   231,    -1,    46,   264,   339,   265,    -1,
      60,   264,   335,   265,    -1,    61,   264,   335,   265,    -1,
      62,   264,   335,   265,    -1,    59,   264,   316,   239,   335,
     239,   335,   265,    -1,    54,   264,   335,   239,   316,   239,
     316,   265,    -1,    54,   264,   335,   239,   316,   265,    -1,
      47,   264,   335,   265,    -1,    47,   264,   335,   239,   331,
     265,    -1,    68,   264,   335,   265,    -1,    69,    -1,    53,
     264,   335,   265,    -1,    52,   264,   335,   265,    -1,    -1,
      86,   264,   336,   337,   276,   265,    -1,    84,   264,   338,
     265,    -1,   237,   316,    -1,   341,     9,   237,   316,    -1,
     335,    -1,   339,   239,   335,    -1,     4,   238,   234,   316,
     235,    -1,   340,   238,   234,   316,   235,    -1,     4,    -1,
     340,    -1,   206,   232,   335,   233,    -1
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
    2139,  2154,  2166,  2180,  2193,  2206,  2219,  2252,  2272,  2294,
    2295,  2300,  2303,  2307,  2318,  2329,  2340,  2356,  2375,  2396,
    2411,  2427,  2445,  2496,  2517,  2539,  2562,  2667,  2683,  2718,
    2729,  2735,  2750,  2778,  2795,  2802,  2814,  2833,  2839,  2845,
    2852,  2859,  2866,  2878,  2951,  2969,  2986,  3001,  3034,  3046,
    3070,  3074,  3079,  3086,  3091,  3101,  3106,  3112,  3120,  3124,
    3128,  3137,  3201,  3217,  3234,  3251,  3273,  3295,  3330,  3338,
    3346,  3352,  3359,  3366,  3386,  3412,  3424,  3436,  3452,  3468,
    3485,  3484,  3507,  3506,  3531,  3530,  3553,  3552,  3573,  3587,
    3602,  3617,  3638,  3641,  3647,  3659,  3679,  3683,  3687,  3691,
    3695,  3699,  3703,  3707,  3716,  3729,  3730,  3731,  3732,  3733,
    3737,  3738,  3739,  3742,  3760,  3777,  3794,  3797,  3813,  3816,
    3833,  3836,  3842,  3845,  3852,  3855,  3862,  3879,  3920,  3964,
    4003,  4028,  4037,  4067,  4093,  4119,  4151,  4178,  4204,  4230,
    4256,  4282,  4304,  4310,  4316,  4322,  4328,  4334,  4360,  4386,
    4403,  4420,  4437,  4449,  4455,  4461,  4473,  4477,  4487,  4498,
    4499,  4500,  4504,  4510,  4522,  4540,  4568,  4569,  4570,  4571,
    4572,  4573,  4574,  4575,  4576,  4583,  4584,  4585,  4586,  4587,
    4588,  4589,  4590,  4591,  4592,  4593,  4594,  4595,  4596,  4597,
    4598,  4599,  4600,  4601,  4602,  4603,  4604,  4605,  4606,  4607,
    4608,  4609,  4610,  4611,  4612,  4613,  4614,  4615,  4616,  4625,
    4626,  4627,  4628,  4629,  4630,  4631,  4632,  4633,  4634,  4635,
    4640,  4639,  4647,  4649,  4654,  4660,  4684,  4702,  4720,  4725,
    4731,  4747,  4753,  4759,  4778,  4799,  4832,  4856,  4860,  4865,
    4875,  4885,  4890,  4901,  4910,  4915,  4920,  4949,  4948,  4978,
    4980,  4985,  4994,  4996,  5002,  5003,  5009,  5013,  5017,  5021,
    5025,  5032,  5036,  5040,  5044,  5051,  5056,  5063,  5068,  5072,
    5077,  5081,  5089,  5100,  5104,  5116,  5124,  5132,  5139,  5149,
    5172,  5178,  5184,  5190,  5196,  5207,  5218,  5229,  5240,  5246,
    5252,  5258,  5264,  5274,  5284,  5294,  5307,  5319,  5323,  5327,
    5331,  5349,  5357,  5365,  5394,  5404,  5420,  5431,  5436,  5440,
    5444,  5456,  5460,  5472,  5489,  5499,  5503,  5518,  5523,  5530,
    5534,  5547,  5561,  5578,  5604,  5608,  5616,  5622,  5628,  5634,
    5643,  5647,  5651,  5659,  5665,  5671,  5679,  5687,  5694,  5702,
    5717,  5731,  5745,  5757,  5773,  5782,  5791,  5801,  5812,  5820,
    5828,  5832,  5851,  5858,  5864,  5871,  5879,  5878,  5888,  5912,
    5914,  5920,  5925,  5933,  5942,  5955,  5958,  5962
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
     275,   276,   276,   277,   277,   277,   277,   278,   278,   278,
     279,   279,   279,   280,   280,   280,   281,   281,   281,   282,
     282,   283,   283,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   285,   285,   285,   285,   285,   285,   285,   286,
     286,   287,   287,   287,   287,   287,   287,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   289,
     289,   289,   289,   289,   290,   290,   291,   292,   292,   292,
     292,   292,   292,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   294,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   296,   296,   296,
     297,   296,   298,   296,   299,   296,   300,   296,   296,   296,
     296,   296,   301,   301,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   303,   303,   303,   303,
     304,   304,   304,   305,   305,   306,   307,   307,   308,   308,
     309,   309,   310,   310,   311,   311,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   313,   313,   313,   314,
     314,   314,   315,   315,   315,   315,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   320,   319,   321,
     321,   322,   323,   323,   324,   324,   325,   325,   325,   325,
     325,   326,   326,   326,   326,   327,   327,   328,   328,   328,
     328,   328,   328,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   331,   331,   331,
     331,   332,   332,   332,   332,   333,   333,   334,   334,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   337,   336,   336,   338,
     338,   339,   339,   340,   340,   341,   341,   341
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
       6,     8,     8,     4,    14,     4,     4,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     4,     4,     3,     5,     6,     5,     5,     5,     5,
       1,     4,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     4,     2,
       4,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   555,     0,     0,     0,
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
       0,   556,     0,   201,     0,     0,     0,     0,     0,   244,
       0,   246,   247,   242,   243,     0,   248,   249,   111,   121,
     555,   444,   439,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,     0,   399,   400,   402,
     403,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   407,   408,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,   405,   406,     0,     0,     0,     0,     0,     0,
     482,   483,     0,   484,   457,   356,   412,   415,   279,   458,
     439,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   555,     0,   201,
       0,     0,   346,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,   463,     0,     0,     0,     0,     0,   555,
       0,     0,   503,     0,     0,     0,     0,   240,   241,     0,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,     0,   543,   524,     0,     0,
       0,     0,     0,   523,     0,     0,     0,     0,   258,   259,
       0,   201,     0,   201,     0,     0,     0,   439,     0,     0,
     201,   352,     0,     0,    76,     0,    63,     0,     0,    67,
      66,    65,    64,    69,    68,    70,    71,     0,     0,     0,
       0,     0,     0,   509,   439,     0,   200,     0,   199,     0,
     167,     0,     0,   509,   510,     0,     0,   551,     0,   109,
     109,     0,   437,     0,     0,     0,     0,     0,   497,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,     0,     0,   471,     0,   472,
       0,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,     0,   358,   465,   360,     0,   459,
       0,   422,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,   423,     0,     0,     0,     0,     0,     0,
     280,     0,   310,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   201,     0,   448,   447,     0,     0,     0,     0,   201,
     201,     0,     0,     0,     0,   276,     0,   201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,   222,   347,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,   239,     0,
       0,     0,     0,     0,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   261,     0,   227,     0,   228,     0,     0,   358,     0,
     201,     0,     0,     0,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    72,    73,     0,     0,   237,    38,   233,     0,
       0,     0,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,   202,     0,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,   442,     0,     0,   440,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,   339,   340,   341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
       0,     0,   357,   460,   421,     0,   467,     0,   374,   373,
     372,   371,   367,   368,   370,   369,   362,   361,     0,   363,
     466,   364,   365,   366,   440,     0,     0,   441,   426,     0,
     485,     0,     0,     0,     0,     0,     0,     0,   308,     0,
       0,   137,   138,     0,   140,   141,     0,   143,   144,     0,
     146,   147,     0,   343,     0,   344,     0,   345,     0,     0,
       0,     0,   342,   201,     0,     0,     0,     0,     0,   450,
     449,     0,     0,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   323,     0,     0,   223,     0,     0,   219,     0,     0,
       0,   338,   337,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,   229,   231,     0,   363,     0,   557,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
     357,     0,    63,     0,     0,     0,     0,    79,     0,    63,
      64,     0,     0,   440,     0,     0,   426,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   553,    28,    26,
       0,     0,     0,     0,     0,   441,   513,    29,     0,     0,
     234,   552,    74,   112,    75,   122,   443,   445,     0,     0,
       0,     0,     0,   499,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   398,   385,     0,
     387,   388,   389,   390,   391,   496,   392,   393,   394,     0,
       0,     0,   488,   487,   486,     0,     0,     0,   493,     0,
     434,     0,     0,     0,   436,   126,     0,   469,     0,     0,
       0,     0,     0,   413,   495,   418,   419,   461,     0,   420,
       0,     0,     0,     0,   417,   416,   429,     0,     0,     0,
       0,     0,   357,   306,   311,   309,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,   357,   357,   357,     0,
       0,     0,     0,     0,   230,   232,     0,     0,     0,   191,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,   322,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,   533,     0,
     540,   529,   530,   531,     0,   545,   544,     0,     0,   534,
     535,   536,   542,   549,   548,     0,   131,     0,   525,     0,
     527,   521,     0,   226,     0,   301,     0,     0,     0,   353,
       0,   554,     0,     0,     0,     0,   101,    63,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,    61,     0,
      39,    40,    41,    42,    43,     0,   417,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,   512,   511,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,   151,   151,     0,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   468,   375,   462,   427,
     425,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,   318,     0,   139,     0,   142,     0,   145,     0,   148,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,   286,     0,
     289,     0,   291,     0,   277,   283,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,   324,     0,
     221,   220,   348,     0,     0,    35,    36,     0,     0,     0,
       0,   504,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   302,   201,
       0,     0,   516,   517,   518,   519,     0,    86,     0,     0,
       0,     0,    84,    91,    93,     0,   507,     0,    99,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,    34,
     427,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,     0,   514,     0,    32,     0,
       0,   113,   118,     0,     0,    77,    78,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   170,   171,     0,
       0,     0,     0,   155,   183,   172,   176,   177,   173,   174,
     175,   162,     0,     0,   386,   395,   396,   397,   489,     0,
       0,     0,   432,   433,   435,     0,   411,   127,     0,     0,
       0,     0,   431,   414,   184,   428,   490,   178,     0,     0,
     149,     0,     0,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,     0,     0,     0,   201,
     201,     0,     0,   288,   457,     0,     0,   290,   292,     0,
       0,   271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,     0,     0,     0,     0,   158,   159,     0,
       0,     0,     0,   102,   106,     0,   541,     0,     0,   539,
       0,   550,     0,   547,   132,   526,   528,     0,   300,   300,
       0,   354,    85,    63,     0,     0,     0,     0,    83,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   455,     0,   428,   235,   236,   203,   204,   205,   206,
       0,     0,     0,     0,     0,   515,     0,   114,   119,     0,
     438,     0,     0,   152,   156,   157,   163,     0,     0,   182,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   430,     0,   164,     0,   185,   307,   187,
     188,   189,   190,   161,     0,   180,   186,     0,     0,     0,
       0,     0,     0,   454,   453,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   216,     0,     0,     0,
       0,     0,     0,     0,     0,   207,     0,     0,   321,    37,
       0,   502,     0,     0,   255,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    97,   508,     0,     0,    88,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    46,    33,     0,
     126,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,   492,     0,     0,   128,   130,     0,     0,     0,
       0,     0,   166,     0,   314,   314,     0,   107,   108,   201,
       0,   194,   195,   278,     0,   284,     0,     0,   201,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   197,     0,
       0,     0,     0,   103,   104,   532,   538,   537,     0,   133,
     134,   135,     0,     0,   303,     0,    92,    94,     0,   100,
       0,    82,    89,    90,    49,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,   116,   332,   334,   333,   335,
       0,   336,   169,     0,     0,     0,   497,   498,     0,     0,
       0,     0,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   452,     0,   294,     0,     0,   272,     0,
     208,     0,     0,     0,     0,     0,     0,     0,   501,   256,
       0,     0,     0,   201,   355,     0,   506,     0,    45,     0,
       0,     0,    62,    47,     0,   115,   120,   126,   150,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   325,     0,     0,   326,     0,   192,     0,
     285,     0,   268,     0,   201,     0,     0,     0,     0,     0,
       0,   160,   105,   136,   252,   300,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,   181,     0,   329,     0,   330,   331,   451,     0,
       0,   274,   211,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    59,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   273,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,   212,   213,   214,   215,     0,   209,
     305,    50,     0,    57,     0,   245,     0,   494,     0,     0,
       0,     0,     0,     0,   275,     0,     0,    51,     0,     0,
     251,     0,     0,     0,     0,     0,     0,   210,     0,     0,
       0,     0,   478,   479,   480,   481,     0,     0,    54,    52,
       0,    55,     0,   327,   328,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1000,   109,   110,   982,  1740,  1746,
    1250,  1444,  1887,  2036,  1251,  1999,  2060,  1252,  2038,  1253,
    1254,  1448,   398,   543,   544,  1064,   111,   718,   419,  1750,
    1897,  1751,   420,  1845,  1318,  1517,  1413,  1594,   850,   853,
     856,   859,  1491,  1481,   702,   250,   407,   408,   114,   115,
     116,   117,   118,   119,   120,   121,   251,  1155,  1923,  1990,
     886,  1151,  1152,   252,   959,   253,   125,  1340,  1116,   848,
     900,  1857,   126,   127,   128,   129,   254,   255,  1085,   256,
     723,   257,   838,   722,   422,   574,   289,  1620,   323,   324,
     259,   520,   331,  1238,  1437,   417,   413,  1206,   943,   418,
     131,   377
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1586
static const yytype_int16 yypact[] =
{
   10257,    61,    83, 10405, -1586, -1586,   -61,    21,   -50,   -69,
     -56,    34,   214,   223,   230,   331,   141,   398,   404,    87,
     213,    16,   -85,   -85,   -21,   222,   240,    27,   288,   295,
      39,   305,   311,   317,   345,   352,   406,   433,   457,   481,
     496,   373,   397,   708,   487,   711,   533,  5742,   551,   580,
     507,   -59,   588,   281,   679,   107,   607,   758,   -48,   623,
     353,   353,   624,   427,   655, -1586, -1586, -1586, -1586, -1586,
     636,    57,   774,   767,    15,    62,   786,   793,   262,   877,
     889,   902,  5058,   910,   694,   695,   696,    17,    30, -1586,
     707,   709, -1586, -1586,   938,   939,   714, -1586,  3714,   728,
    5162,    48,    51, -1586, -1586, -1586,  9687,   720, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586,   189, -1586, -1586, -1586, -1586,    56, -1586,
     957,   746,  4066,    60,   735,   965,  9687,  4157,  4157, -1586,
    9687, -1586, -1586, -1586, -1586,  4157, -1586, -1586, -1586, -1586,
     752,   747,   991, -1586, -1586,  5390,    16,  9687,  8250,  9687,
    9687,   771,  9687,  8250,  9687,  9687,   784,  9687,  8250,  9687,
    9687,  9687,  9687,  9687,  9687,  4157,  9687,  9687,  9687,  5970,
     794, -1586,  8250,  5058,  5058,  5058,  4157, -1586, -1586, -1586,
   -1586, -1586,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   142,   -85,   -85,   -85,   -85,
     -85,   796,   -85,   -85,   799, -1586, -1586, -1586,   -85,    41,
      37,    42,    45,  5970,   903,   561,   814,   -85,   -85,   832,
     845, -1586, -1586, -1586,  9687,  6198,  9687,  9687,  6426,    89,
   -1586, -1586,   848, -1586,  2595, -1586, -1586, -1586, -1586, -1586,
     108,  9687,  8250,   846,   861,  6654,  5058,  5058,  5058,   863,
     866,   868,   869,  6882,  7110,  7338,   849,  9092,  1096,  5970,
      17,   867,   870,   353,   353,   353,  9687,  9687,   -84, -1586,
     293,   353,  9161,   333,   234,   872,   873,   880,   882,   886,
     888,   890,  9687,  5058,  5058,  5058,   891,     6,   875, -1586,
    1105,  1113, -1586,   892,   895,   896,  5058,  5058,   893,   899,
     900, -1586,  9687, -1586,  1116,  1117,  9687,  9687,  9687,   446,
    9687,   901, -1586,   950,  9687,  9687,  9687, -1586, -1586,  9687,
   -1586,   -85,   -85,   -85,   907,   908,   909,   -85,   -85,   -85,
     -85,   -85,   -85,   -85, -1586,   -85, -1586, -1586,   -85,   -85,
     925,   926,   -85, -1586,   929,  1127,  1134,   923, -1586, -1586,
    1152, -1586,  1168, -1586,   -85,  9687, 11789,   119,  4157,  9687,
   -1586, -1586,  5970,  5970, -1586,   945,  5390,   621,  1173, -1586,
   -1586, -1586, -1586, -1586, -1586,  9687,  9687,    24,  5970,  1175,
     390,   478,   948,  1177,    20,   951, -1586,   952, 10581,  9687,
   -1586,   575,  -157, -1586,    67,  -115,  4268, -1586,   -75,  -161,
    -120,  1099, -1586,    16,   953,   954, 12183,  8250,  2738, -1586,
     178, 12204, 12225,  9687, 12246,   215, 12267, 12288,  9687, 12309,
     242, 12330, 12351, 12372, 12393, 12414, 12435,   958, 12456, 12477,
   12498,  1181,  9687,   387,  1184,  1190,  1191,   963,  9687,  9687,
    9687,  9687,  9687,  9687,  9687,  9687,  9687,  9687,  9687,  9687,
    9687,  9687,  9687,  9687,  8250,  9687,  9687,  9687,  9687,  9687,
    9687,  8250,  8250,   964,  9687,  9687,  4157,  9687,  4157,  5970,
    4157,  4157,  4157,  9687, -1586,  1135,  9687, -1586,  1137, -1586,
    1141, -1586,  1143,  5970,  5058,  5058,  5058,  5058,  4157,  4157,
    8250,    16,  5390,   979,  8250,   979, -1586,   979, 12519, -1586,
     416, -1586,    76,  9687,  9687,  9687,  9687,  9687,  9687,  9687,
    9687,  9687,  9687,  9687,  9687,  7566,  9687,  9687,  9687,    16,
    9687,  9687,  1205, -1586,   519, 12540,   484,  9687,  9687,  9687,
   -1586,  1203,  1206,  1206,  8869,  8869,  8869,  8869,  9687,  1208,
    9687,  1210,  9687,  1211,  8250,  8250, 11813,   981,  1212,   985,
   -1586, -1586,  -162, -1586, -1586,  4297,  4342,   353,   353,    60,
      60,  -140,  9161,  9161,  9687,  2621,  -112, -1586,  9687,  9687,
    9687,  9687,  9687,  9687,  9687,  9687,  9687, 12561,  1213,  1215,
    1216,  9687,  1218,  9687,  9687,  3072, -1586, -1586,  8250,  8250,
    8250,  1220,  1221,  9687,  9687,  9687, 12582, -1586, -1586, 12603,
   12624, 12645,  1051,  4511, -1586,   994,  2771, 12666, 12687, 11884,
    4157,  4157,  4157,  4157,  4157,  4157,  4157,  4157,  4157,  9687,
    4157,  4157,  4157,  4157,     4,  5390,  4157,  4157,  4157,    16,
   -1586, -1586,  8250, -1586,  3280, -1586,  3534,  9687,   979,  9687,
   -1586,  9687,  9687,   997, 12708, 10543,  1000,   573,  9687,  1226,
     999,  1001,  1002,  1003,  9687, 12729, 11907,   248,  1005,  1232,
    1236, -1586, -1586, -1586,  8250,   155, -1586, -1586, -1586,    16,
    9687,  9687,  1205,  1011, -1586,   286,    44,    50,   579,  1023,
     -46,   710, -1586,  3068, -1586,    88,  8250,    16,  9687,  9687,
    1251,  1250,  8250,  9687,  1255,  4157,  1256, -1586,    16,  1257,
    4157,  9687,  1033,  1037, -1586,  9687,  5390,  1264,  8250,  1098,
    8250,  1266,  1267, 12750,  1268,  1102,  1270,  1271, 12771,  1272,
    1106,  1274,  1278,  1279,  1280,  1283,  1284, -1586,  1285,  1286,
    1287,  9687, 12792,  1061, -1586, -1586, -1586,  1290, 11861, 11861,
   11861, 11861, 11861, 11861, 11861, 11861, 11861, 11861, 11861,  4761,
   11861, 11861, 11861, 11861,   220,   512, 11861, 11861, 11861,  5452,
    5680,  5908,  2738,  1066,  1065,     7,  8250,  6136,  6364,   512,
    6592,   512,  1062,  1077,  1078,    -6, 10401,  1084,  4601,  1089,
    1090,  1092, -1586, -1586, -1586, -1586,  1086,  -170,   512,  1069,
    1097,   576,  1320, -1586, -1586,   512,  3030,  3049,   396,   949,
     789,   789,   372,   372,   372,   372,   555,   555,  8250,   979,
   -1586,   979,   979,   979,  1093, 12813, 11930,   271, -1586,  8250,
   -1586,  1323,  1103, 12834, 12855, 12876,  9687,  5970,  1327,  1326,
    1109, 10401,  1111,  1121, 10401,  1114,  1123, 10401,  1118,  1124,
   10401,  1119, 12897, -1586, 12918, -1586, 12939, -1586,   581,   582,
    8250,  1108, -1586, -1586,  4310,  9715,   353,  9687,  9687, -1586,
   -1586,  1107,  1125,  9161,  3748,  1233,   -51,   353,  9754, 12960,
   10096, 12981, 13002, 13023, 13044, 13065, 13086, 13107,  1354,  9687,
    1356, -1586,  9687, 13128, -1586, 11953, 11976, -1586,   584,   595,
     596, -1586, -1586, 11999, 12022,  6820, -1586,  1358,  1359,  1360,
    1132,  9687,  9877,  9687,  9687, -1586, -1586,    53,   167,   183,
     167,  1138,  1140,  1133,   512,   512,  1139,  7048,   512,   512,
     512,   512,  9687,   512,  1364, -1586,  1142,  1145,   421,  1130,
     612, -1586, -1586, 11861,   979,  9915, -1586,  1367,  9390,  1144,
    1146,  1371,  5970, 11064, -1586,  9687,  9687,  9687,  9687,   837,
     336,    84,  5390,  9687,  1376,  1380,    47, -1586,   613,  1339,
    1341,  5970,    23,  1155, 13149, 12045,  1158,  9687,  8250,  8250,
    8250,  8250,  9687,  1163,  1164,  1165,  1167, -1586, -1586,  1182,
    4157,   298,  1162, 13170, 12068, -1586, -1586, -1586,   329,  7276,
   -1586, -1586, -1586,    66, -1586, -1586, 10401, -1586,  9687, 11861,
     512,   353,   685,  2738, -1586,  5970,  5970,  1393,  5970,   727,
    5970,  5970,  1412,  5970,  1324,  5970,  5970,  5970,  5970,  5970,
    5970,  5970,  5970,  5970,   930,  1413,  8250, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,  9687,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,  9687,
    9687,  9687, -1586, -1586, -1586,   614,  9687,  9687, -1586,  9687,
   -1586,  5970,  4157,  4157, -1586, -1586,  9687, -1586,  9687,  9687,
    9687,  9687,  9687, -1586, -1586, -1586, -1586, -1586,  5970, -1586,
    9687,  9687,   629,  1251,   271,   -24, -1586,   640,  5970,  8250,
    1415,  1417,  1418,  2473, -1586, -1586,  1420, -1586,   159,  9687,
     159,  9687,   159,  9687,   159,  9687,  1421,  1423,  1426,  1427,
    1428,   645,  1432, 10004, -1586, -1586,  -109,  7504,  7732, -1586,
   -1586, 11089,   239,  1330,  1436,  9464,  1193,  1435,  1217,    35,
      59,   675, -1586,  -106, -1586,   -51,  1438,  1437,  1439,  1441,
    1442,  1444,  1445,  1447,  1448,  5970, 10401, -1586,  1091,  1222,
    1451,  1452,  1454,  1347,  1456,  1455,  1458,  9687,  5970,  5970,
    5970,  1461,  7960, -1586,  3468,   518,  1465,  1466, -1586,  8250,
   -1586, -1586, -1586, -1586,  4157, -1586, -1586,  9687,  4157, -1586,
   -1586, -1586, -1586, 10401, -1586,  1229, -1586,  4157, -1586,  4157,
   -1586, -1586,  1248, -1586,  1237, -1586,  1194,  1254,  5970, -1586,
    1258, -1586, 11114, 11139, 11164, 11189, -1586, -1586,  9687,  1483,
      29,  9687,  1484,  1486,  1262, -1586,  1488,    17,  1491,  1269,
     512,   -85,   -85,  1492, -1586,  1273,  1277,  1265, -1586,  1494,
   -1586, -1586, -1586, -1586, -1586,  1251,  -124,   881, 12091,   648,
     659,   660,   665, 13191,  9687,  9687,  9687,  9687, -1586,  1496,
      90,  1251, -1586,  1275,  1498,  9687,  8473,   512, 10401,  1502,
    1504,    11,  1281,  1289,  1392,  1392,  5970,  1508,  1291,  1301,
    1512,  1514,  5970,  1362,  1303,  1534,  1535,  1536,  1538,  1539,
    1540,  1541,  1544,  1545, -1586,  1547,   666, 11861, 11861, 11861,
   11861,   512,  8188,  8500,  8812,  1322,   512,   512,   489,  8922,
    8991,  9034,  9119, 13212, 11861,  1548, 10401, 10401, -1586, -1586,
   -1586,  1551, -1586,   512,  1550,   668,  5970,  5970,  5970,  1553,
    1552, -1586,  5970, 10401,  5970, 10401,  5970, 10401,  5970, 10401,
    5970,  5970,  5970,  1325,  1328,  1556,   669, -1586,  9687,  9687,
    9687,  1331,  1332,  1334,  1337, -1586,  1462,  5970, -1586,  9687,
   -1586,  1554, -1586,  1558, -1586, -1586,  9161,   703,  5286, -1586,
    1336,  1340,  1343,  1344,  1345,  1346,  7794,  1565, -1586,  8250,
   -1586, -1586, -1586,  1348,  9687, -1586, -1586, 12114,  1567,  1569,
    1411, -1586,  9687,  9687,  9687, -1586,  1577,   699,   528,  1351,
    4097,  1363,  9687,   529,  1355,   512,  5390, -1586, -1586, -1586,
    1366,  1579, -1586, -1586, -1586, -1586,  1503, -1586,   349,  1365,
    1591,  1691, -1586, -1586, -1586,    17, -1586,   673, -1586,  9687,
     159,  1198,  4157, -1586,  1373,  9687,  9687,  5970,  1372, -1586,
    1375,  1603,  1605,  1606,  1607,  1608,  1609,  1610,  1320, 13233,
   13254, 13275, 13296, -1586, -1586,  4157, -1586,  1613, -1586,  9220,
    4573, 10401, -1586,  1612,   109, -1586, -1586, -1586,  9687,  9687,
     353,  1614,  1616,  1617, -1586,  9687,  9687, -1586, -1586,  1618,
    1532,  1620,  9687, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,  1622,  1395, -1586, -1586, -1586, -1586, -1586,  9687,
    9687,  9687, -1586, -1586, -1586,  1626, -1586, -1586,  9687,  9687,
    9687,  9687, -1586, -1586, -1586,   271, -1586, -1586,  1397,  1627,
    1362,  1628,  9687, -1586,  1629,  1630,  1631,  1632,  1633,   834,
    1634,  8250,  8250,  9687, -1586,  8869, 11214, 13317,  2986,    60,
      60,  9687,  9687, -1586,   110,  1403, 13338, -1586, -1586, 11239,
     -72, -1586,  1637,  1638,  5970,   353,   353,   353,   353,   353,
    5514,  1639, -1586,   676,  9687,  1765,  1641, -1586, -1586,  5970,
    3379,   170, 13359, -1586, -1586,  8557, -1586,  4157,  9687, -1586,
    4157, 10401,    28, -1586, -1586, -1586, -1586,  1409, 10543, 10543,
    5970, -1586, -1586,  5390,  9687,  1643,  1646,    47, -1586,  1647,
   -1586,    17, 12137,  5970,  1648,   167,   167,  9687,  9294,  9337,
     681, -1586,  9687,   357, -1586, -1586, -1586, -1586, -1586, -1586,
    1418,  1421,  1423,  1426,  1651, -1586,  9687, -1586, -1586,  1398,
   -1586, 11264, 11289,   368, -1586, -1586, -1586, 11314, 11339, -1586,
    1424, -1586, 11364,  1654,  5970, 11861, 11861,  9417,  4823,  9560,
    9719,  9847,  9974, -1586,  9687, -1586,  1655, -1586, 10401, -1586,
   -1586, -1586, -1586, -1586,  1429, -1586, -1586,   682,   683, 11837,
    1784,  1656,  1430, -1586, -1586,  9687,  1425,  1431, 11389, 12160,
    1659,  5970,  1645,  1433,  9687, -1586, -1586,   684,   -32,   176,
     182,   187,   191,  8022,   207, -1586,  1662, 11414, -1586, -1586,
    1518, -1586,  9687,  9687, -1586, -1586,  8250,  1939,  1666,  1459,
   11861,   512,  8785,  5390,  5390,  1457,  1460,  1463,  1683,  2088,
   -1586,  1686,  1688, -1586, -1586,  1467,  1690, -1586,  1693,  1698,
     341, 10401,  9687,  9687,  1471,  5970,   712, 10401, -1586, 10067,
   -1586, -1586,  5970,  1700,  1701,  1702,  1704,  9687,  1705,  1706,
     722, -1586, -1586,  9687,  6426, -1586, -1586,  9687,  9687,  9687,
    9687, 11439, -1586,  5970,    -5,   435,  8250, -1586, -1586,    60,
    4224, -1586, -1586, -1586,  1722, -1586,  1495,  5970, -1586, 11464,
    1723,  8250,   353,   353,   353,   353,   353, -1586, -1586,  9687,
   11489, 11514,   725, -1586, -1586, -1586, -1586, -1586,  4157, 10401,
   -1586, -1586,  1500,  1499, -1586,  1728, -1586, -1586,    17, -1586,
    1563, -1586, -1586, -1586, -1586,  9687, 10513, 10542,  5970, -1586,
    1730,  9687,  9687,   731,   733, -1586, -1586, -1586, -1586, -1586,
   11539, -1586, -1586,  1505, 10571,   744,  2434,  1731, 10600, 10629,
   10658, 10687, -1586,   754,  1506,   353,  5970,  1735,  1509,   353,
    1738,   756,  1510, -1586,  9687, -1586,  1740,  1611, 10042,  1513,
   -1586,   757,   227,   241,   252,   273,   276,  2122, -1586, -1586,
    1742,   763,  1744, -1586, -1586,  1745, -1586,  1520, 10401,  9687,
    9687,   764, -1586, 10401, 10716, -1586, -1586, -1586, -1586,  9687,
    9687, -1586,  9687,  5390,    16,  9687,  9687,  9687,  9687,  1749,
     353,    46, -1586, -1586,   353,   132, -1586,  1750, -1586, 11564,
   -1586,  9687, -1586,   -51, -1586,  1751,  8250,  8250,  8250,  8250,
    8022, -1586, -1586, -1586, -1586, 10543, -1586,  9687, 13380, 10745,
      49,  9687,   781, 10774, 10803,  2553, -1586,  1528, 10832, 10861,
   10890, 10919, -1586,   289, -1586,   303, -1586, -1586, -1586,  2367,
     719, 10131, -1586,   782,   806,   807,   828,   310,   829,  1524,
     830, -1586,  9687, -1586,  5970, 11589, -1586,  9687,  9687,  5390,
    1529,  9687,  9687,  9687,  9687,   353,   353, -1586, -1586, -1586,
     -51,  1756,  1757,  1758,  1762,  8250,  1763,  1766,  1768,  1542,
   13401,   835,  1769, 11614, 11861, -1586, -1586, 10948, 10977, 11006,
   11035,   313,   330,   739, -1586, -1586, -1586, -1586,   842, -1586,
   -1586, -1586,  4157, -1586,  1546, -1586,  1773, -1586,  9687,  9687,
    9687,  9687,  9687,  9687, -1586,  1775,   850, -1586,  1555,  5970,
   -1586, 11639, 11664, 11689, 11714, 11739, 11764, -1586,  1776,  4157,
    4157,   853, -1586, -1586, -1586, -1586,  1779,  1780, -1586, -1586,
     855, -1586,  1781, -1586, -1586,  1785,  4157, -1586, -1586, -1586
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1586, -1586, -1586, -1586,   522, -1586, -1586, -1586, -1586,  -144,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,  -655,  -129,  3824,  3060, -1586,  1374, -1586, -1586,
   -1586, -1586, -1586, -1586, -1255, -1586,    52, -1586, -1586, -1586,
   -1586, -1586,   265,   514,  1797,    -1,  -568,  -283, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586,  1798, -1586, -1586, -1586,
   -1586, -1151, -1150,  1799, -1585,  1801, -1586, -1586, -1586,  1253,
   -1586,    32, -1586, -1586, -1586, -1586,  1953, -1586, -1586,  1805,
   -1586,  1788,  -685, -1586, -1586,    26, -1586, -1549,   491,  -146,
    2622,  1188,  -275,   203, -1586,    31,    43, -1586, -1586,  -486,
   -1586,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -516
static const yytype_int16 yytable[] =
{
     132,  1375,   113,   399,  1377,   569,   795,   986,   150,   585,
     602,   881,   882,  1725,  1726,  1697,   539,  1477,   152,   307,
     150,   329,   973,  1474,   150,  1006,   605,  1244,   677,   689,
     981,   161,  1722,  1428,   333,   135,   264,   454,   455,   456,
     139,  1370,   497,   166,   260,   136,   494,   499,   161,   264,
     501,   150,  1954,   370,   166,  1973,   372,   265,   577,   578,
    1186,   682,   381,   683,   405,  1372,   311,     4,   312,  1092,
     993,   310,   716,  1276,   705,  1144,   707,   876,   717,   260,
     577,   578,   706,     5,   332,   814,   288,   290,   654,   293,
     656,  1227,  1145,   150,   998,   366,  1464,   665,   521,   883,
    1146,  1147,  1148,   393,   394,  1760,  1149,  1150,   577,   578,
    -512,   577,   578,   719,   577,   578,   711,   539,   523,   717,
     551,   552,   553,   280,   712,  1854,  1855,   887,   539,   404,
    1358,  1856,   406,  1376,   414,   414,   577,   578,  1956,   281,
     282,   365,   414,   369,   928,   153,   930,   154,   577,   578,
     579,   313,   303,   425,   304,   260,   714,   598,   599,   600,
     260,   137,   979,   402,   715,   260,  1227,  1694,   412,   415,
     611,   612,   414,   133,   138,   403,   260,   134,  1713,   260,
     260,   260,   260,   414,  1245,  1246,  1247,  1248,   577,   578,
      59,    60,    61,    62,  1371,   678,   679,   308,   424,   276,
    1429,  1430,   277,   393,   394,    73,   447,  1791,    76,   157,
     107,   498,  1331,   158,  1723,   495,   500,   457,  1373,   502,
     141,   107,   107,   107,  1853,  1084,   107,  1375,   523,   142,
     260,   577,   578,   715,   393,   394,   143,   540,   603,   541,
    1074,   942,   260,   542,   134,   260,   522,   393,   394,   309,
     690,   330,   691,   107,  -510,   972,   692,   162,  1249,   260,
     334,   163,   260,   260,   260,   260,   577,   578,   140,   167,
     260,   260,   260,   168,   162,   496,   260,   332,   989,  1891,
     167,  1237,   371,  1974,   990,   373,   382,   874,   875,  1187,
     383,   389,   390,   391,   392,   107,   153,   708,   154,   709,
     260,   260,   260,   710,   888,   999,   153,   999,   154,   572,
     573,   393,   394,   260,   260,  1228,  1231,   581,   586,   148,
    1230,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   393,   394,   144,   540,   538,
     541,   922,  1640,  1227,   542,  1690,   393,   394,  1515,   661,
    1969,   662,   577,   578,   316,   542,  1603,   317,   802,   803,
     804,   805,   389,   390,   391,   980,   389,   390,   391,   392,
     269,   145,   481,   270,   482,   414,   271,   955,   272,   260,
     260,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,   260,   577,   578,   682,   538,
     683,   693,   577,   578,   146,  1714,   715,   577,   578,   663,
     147,   577,   578,   729,   682,  1792,   683,   730,  1329,   379,
     724,  1793,  1189,   380,   260,  2001,  1794,   577,   578,   669,
    1795,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   728,   536,   537,   149,  1796,   577,   578,   538,
     735,   682,   159,   683,   730,   389,   390,   391,   392,   577,
     578,   577,   578,  1342,   588,  1344,  1926,  1346,   589,  1348,
     160,   260,   577,   578,  1362,   393,   394,   740,   260,   785,
    1927,   730,   179,   414,   686,   414,   260,   414,   414,   414,
    2051,  1928,   180,   577,   578,  1833,   577,   578,   393,   394,
     260,   260,   260,   260,   260,   414,   414,   260,   809,   577,
     578,   260,  1929,   577,   578,  1930,   157,   789,   164,   791,
     988,   793,   794,   577,   578,   165,  1404,   580,  1985,  1270,
     577,   578,   260,   577,   578,   169,   834,   730,   258,   806,
     807,   170,  1986,   389,   390,   391,   392,   171,   974,  1995,
     577,   578,  2032,   577,   578,   810,   389,   390,   391,   392,
    1274,   260,   260,   393,   394,  1858,  1859,   587,   730,  2033,
    1450,  1856,  1824,   284,   285,   172,   393,   394,   406,   406,
    1825,   704,   173,   286,   393,   394,  1466,   287,   577,   578,
    1133,  -515,   533,   534,   659,   536,   537,   852,   855,   858,
     861,   538,   263,   879,   880,   260,   260,   260,   573,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,   682,   753,   683,   684,   538,   730,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   174,   414,   414,   414,
     414,   944,  1942,   414,   414,   414,   949,   284,   285,   260,
     504,   813,   682,   505,   683,   730,   506,   286,   507,   294,
    1209,   292,   929,   175,   931,   932,   933,   934,   935,   936,
     451,   938,   939,   940,   941,  1544,  1545,   946,   947,   948,
     266,   260,   622,   267,   134,   268,   983,   176,   945,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,   260,  1002,  1584,  1585,   538,  1106,   260,
     670,   177,   414,   671,   181,  1013,   672,   414,   673,   842,
     682,   182,   683,   730,   258,   260,   178,   260,  1515,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,   682,   295,   683,  1011,   538,   296,  1405,
     682,  1015,   683,   839,   297,   298,   550,   299,   300,   682,
     682,   683,   683,   186,   559,   561,   563,   730,  1592,  1020,
     568,   273,  1960,  1604,   274,   301,   275,   659,   536,   537,
    1282,   261,  1283,   260,   538,  1613,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
     183,  1144,   994,   184,   538,   995,   185,   996,   961,   170,
    1375,  1097,   962,   991,   262,   730,  1129,  1130,  1145,  1172,
     730,   730,  1288,   730,  1289,   260,  1146,  1147,  1148,  1144,
    1173,  1174,  1149,  1150,   730,   730,   260,   278,  1674,  2013,
    1675,  1229,  1232,  1226,   260,  1144,  1145,  1212,  1240,  1311,
     279,   730,   730,   730,  1146,  1147,  1148,   283,   291,   306,
    1149,  1150,  1145,  1375,  1328,  1144,   302,   260,   730,   305,
    1146,  1147,  1148,   666,   667,  1333,  1149,  1150,   314,   730,
    1355,   318,  1145,  1454,   730,   150,   340,   730,   315,   680,
    1146,  1147,  1148,   319,  1455,  1456,  1149,  1150,   730,   730,
    1457,  1503,  1136,  1528,   730,   730,   320,   730,  1610,  1142,
    1374,  1706,  1611,  1153,   325,   730,  1744,  1774,  1775,  1790,
    1745,   730,   730,  1745,   326,   327,   328,   341,   342,   343,
     344,   345,   346,   347,   348,   349,  1304,   335,  1561,   336,
     350,   351,   352,   353,   337,   338,   339,  1830,   354,   355,
     356,  1831,   378,   357,  1988,  1615,  1616,  1843,   367,   260,
    1880,  1745,  1436,   384,   730,   358,  1895,   359,  1896,   409,
    1515,   410,  1592,  1239,  2034,  1330,  1332,   421,   260,  1901,
     792,  1686,  1687,  1902,   385,   260,   260,   260,   260,  1909,
     134,  1917,  1925,  1745,   550,   730,   730,   414,  1933,  1940,
     423,   433,   715,  1745,   387,   529,   530,   531,   532,   533,
     534,   659,   536,   537,   438,  1233,  1976,  1991,   538,   503,
    1515,   730,   260,   260,   452,   260,   489,   260,   260,   492,
     260,  1269,   260,   260,   260,   260,   260,   260,   260,   260,
     260,  1992,  1993,   260,   508,   730,   730,  1281,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,   511,  1994,  1996,  1998,   538,   730,   730,  1831,
    2024,   360,   361,   362,  1745,   512,   547,  2035,   260,   414,
     414,   730,   380,   564,   363,  2048,   364,   107,  2062,  2049,
    2065,   548,  1745,   554,  2066,   260,   555,  1388,   556,   557,
     567,   570,   590,   591,   571,   260,   260,   604,   393,   394,
     592,   606,   593,  1316,  1317,  -511,   594,  1451,   595,   607,
     596,   601,   617,   618,   625,   613,   608,  1330,  1332,   609,
     610,   614,   615,   650,  1598,   624,  1599,   633,   634,   635,
     651,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,   646,   647,   652,   653,   538,
    1609,   649,   260,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,   655,   260,   260,   260,   538,   668,
     674,   681,   687,   688,   721,   133,   260,   694,   751,   747,
     754,   414,   725,   726,   757,   414,   755,   756,   786,   797,
    1418,   799,   150,   340,   414,   800,   414,   801,   538,   837,
     846,  1862,   871,   847,   863,   260,   865,   867,   872,   873,
     899,   901,   920,   902,   904,  1409,   911,   912,   923,  1411,
     956,   960,   964,   965,   332,   966,   967,   968,  1414,   976,
    1415,   975,   977,   987,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   992,   414,  1005,  1007,   350,   351,   352,
     353,  1010,  1012,  1014,  1017,   354,   355,   356,  1434,  1018,
     357,  1021,  1022,  1025,  1026,  1028,  1029,  1030,  1031,  1033,
    1034,  1035,   358,   260,   359,  1036,  1037,  1038,  1452,   260,
    1039,  1040,  1041,  1042,  1043,  1046,  1047,  1072,  1073,  1605,
    1095,  1081,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,  1082,  1083,  1086,  1472,
     538,   387,  1881,  1088,  1089,  1091,  1090,  1098,  1096,  1103,
    1108,  1115,  1117,   260,   260,   260,  1734,  1109,  1114,   260,
    1118,   260,  1139,   260,  1132,   260,   430,   260,   260,   260,
    1119,   435,  1120,  1121,  1122,  1124,   440,  1123,  1125,  1143,
    1140,  1165,  1167,  1211,   260,  1178,  1179,  1180,  1181,  1192,
     453,  1193,  1194,  1205,  1214,   260,  1208,  1219,  1197,  1217,
    1218,  1207,  1235,   260,  1236,  1241,   260,  1242,   360,   361,
     362,  1255,  -513,  1264,  1265,  1266,  1663,  1267,  1271,  1268,
    1286,   363,  1560,   364,   107,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,  1292,
    1305,  1294,  1336,   538,  1337,  1338,  1341,  1367,  1350,   682,
    1351,   683,   332,  1352,  1353,  1354,  1356,  1363,   414,   414,
    1364,  1368,  1393,  1379,   260,  1378,  1380,  1369,  1381,  1382,
     546,  1383,  1384,  1220,  1385,  1386,  1389,  1390,  1391,  1597,
    1392,  1395,   414,  1394,  1396,  1401,  1412,   260,  1553,  1406,
    1407,  1417,  1243,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,  1416,  1419,  1427,
    1432,   538,  1433,  1421,  1663,  1435,  1634,  1438,  1443,  1447,
    1449,  1439,  1463,  1445,  1468,  1868,  1643,  1446,  1475,  1602,
    1476,  1467,  1480,  1638,  1484,  1478,  1284,  1285,  1487,  1287,
    1488,  1290,  1291,  1479,  1293,  1485,  1295,  1296,  1297,  1298,
    1299,  1300,  1301,  1302,  1303,  1486,  1490,  1492,   260,   260,
    1493,  1494,  1495,  1885,  1496,  1497,  1498,  1499,   406,   406,
    1500,  1501,  1502,  1512,  1524,  1525,  1527,  1532,  1533,  1541,
    1557,   260,  1542,  1543,  1558,  1549,  1550,   260,  1551,  1552,
    1564,  1572,  1315,  1577,  1565,  1578,   260,  1566,  1567,  1568,
    1569,  1579,  1574,  1583,   414,  1601,  1595,   414,  1681,  1325,
    1587,  1698,  1699,  1700,  1701,  1702,  1704,   260,  1607,  1334,
    1935,  1606,  1590,  1617,  1239,  1600,  1622,  1623,   332,  -514,
     260,  1624,  1625,  1626,  1627,  1628,  1629,  1635,  1719,  1639,
    1644,  1721,  1645,  1646,  1649,  1650,  1651,  1653,  1718,  1654,
    1658,  1664,  1752,  1665,  1667,  1669,  1670,  1671,  1672,  1673,
    1676,  1961,  1691,  1695,  1696,  1705,  1728,  1709,  1724,  1730,
    1731,   260,  1787,  1733,  1737,   260,  1387,  1748,  1757,  1759,
    1781,  1772,  1778,  1773,  1779,  1785,  1782,  1788,  1797,  1398,
    1399,  1400,  1804,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,  1799,   260,  1816,
    1805,   538,  1813,  1818,  1819,  1814,  1821,  1608,  1815,  1822,
     260,  1766,   811,  1820,  1823,  1828,  1836,  1837,  1838,  1420,
    1839,  1841,  1842,   260,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,  1865,  1870,
    1866,  1882,   538,  1883,  1884,  1886,  1892,  1921,  1904,  1899,
    1910,  1913,   260,  1914,  1916,  1918,  1920,  1924,  1932,   260,
    1934,  1936,   868,   869,  1937,  1952,  1957,  1962,  1980,  1997,
    2006,   260,  2014,  2015,  2016,  1810,  1811,  1812,  2017,  2019,
     260,  1708,  2020,   260,  2021,  2025,  2022,  1483,   406,  2040,
    2039,  2047,  2058,  1489,   260,  2063,  2064,  2067,   260,  2050,
    1777,  2068,  1465,  1970,   720,  1666,   908,   909,   910,  1482,
     112,   122,   123,  1834,   124,   414,   849,  1860,   130,   151,
    1732,     0,     0,     0,     0,   332,     0,     0,  1872,  1873,
    1874,  1875,  1876,     0,     0,   260,     0,  1529,  1530,  1531,
       0,     0,     0,  1534,     0,  1535,     0,  1536,     0,  1537,
     950,  1538,  1539,  1540,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,  1555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1563,
       0,     0,   978,     0,     0,     0,     0,  1571,     0,     0,
       0,  1911,     0,     0,     0,  1915,     0,     0,     0,     0,
       0,     0,     0,     0,  1001,     0,     0,     0,     0,     0,
    1008,  1947,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,   260,   260,   260,   260,   260,     0,     0,
       0,     0,     0,     0,     0,     0,  1953,     0,  1621,     0,
    1955,     0,     0,     0,     0,  1803,  1946,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1967,     0,     0,     0,
       0,  1637,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,     0,  1075,     0,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,   260,     0,   538,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,  2011,  2012,   538,     0,     0,  1102,     0,     0,   414,
       0,     0,  2005,     0,     0,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   414,   414,     0,     0,
       0,     0,     0,  2037,     0,  1621,     0,     0,  1131,   376,
       0,     0,     0,   414,     0,     0,     0,     0,     0,     0,
    1710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2059,  2061,     0,     0,     0,   401,     0,     0,     0,   411,
       0,  1727,     0,   416,  1817,     0,     0,  2069,     0,     0,
       0,     0,     0,     0,  1736,     0,     0,     0,     0,     0,
     426,   428,   431,   432,     0,   434,   428,   436,   437,     0,
     439,   428,   441,   442,   443,   444,   445,   446,  1931,   448,
     449,   450,     0,     0,     0,   428,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1621,     0,     0,     0,  1765,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,  1259,  1260,  1261,  1262,
       0,     0,  1786,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   513,   515,   517,
     518,   428,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   428,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,     0,     0,     0,  1306,     0,  1829,     0,     0,   575,
     576,     0,     0,  1835,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,     0,  1621,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,     0,     0,  1867,   619,
     620,   621,     0,   623,     0,     0,     0,   626,   627,   628,
       0,     0,   629,     0,     0,     0,     0,  1335,     0,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1621,
       0,     0,     0,     0,     0,     0,     0,     0,   658,     0,
       0,     0,   664,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,  1912,   675,   676,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   703,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1987,     0,     0,     0,  1408,     0,     0,
     515,     0,     0,     0,     0,     0,   733,     0,     0,     0,
       0,   738,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   752,     0,     0,     0,     0,
       0,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   776,   777,
     778,   779,   780,   781,   782,   782,     0,   787,   788,     0,
     790,  1903,   523,     0,     0,     0,   796,     0,     0,   798,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   782,     0,  1621,     0,   428,     0,     0,
       0,     0,     0,     0,     0,     0,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   829,   831,
     832,   833,     0,   835,   836,     0,     0,     0,     0,     0,
     843,   844,   845,     0,     0,     0,     0,   851,   854,   857,
     860,   862,     0,   864,     0,   866,     0,   428,   428,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1621,     0,     0,     0,     0,   513,   658,   884,     0,     0,
       0,   889,   890,   891,   892,   893,   894,   895,   896,   897,
       0,     0,     0,     0,   903,     0,   905,   906,     0,     0,
    1979,   428,   428,   428,     0,     0,   913,   914,   915,     0,
       0,     0,     0,     0,     0,     0,     0,  1573,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,   937,     0,     0,     0,   538,     0,     0,  1339,
       0,     0,     0,   523,     0,   428,     0,     0,     0,     0,
     953,     0,   954,     0,   835,   836,     0,     0,     0,     0,
       0,   963,     0,     0,     0,     0,     0,   969,     0,     0,
       0,     0,     0,     0,     7,     8,     0,   428,     0,     0,
       0,     0,     0,   984,   985,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   728,   536,   537,   428,
       0,  1003,  1004,   538,     0,   428,  1009,     0,     0,     0,
       0,     0,     0,     0,  1016,     0,     0,     0,  1019,     0,
       0,   829,     0,  1023,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1044,     0,     0,     0,     0,     0,
     695,    25,    26,   696,    28,    29,   697,    31,   698,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,  1677,
    1678,    42,     0,     0,     0,     0,     0,   699,    48,   428,
       0,    50,   700,     0,    53,   701,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,   924,
     429,   428,   538,     0,     0,   429,     0,    84,    85,    86,
     429,     0,   428,     0,     0,     0,     0,     0,     0,  1113,
       0,     0,     0,     0,   429,     0,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
       0,     0,     0,   428,   538,     0,     0,     0,     0,     0,
    1137,  1138,     0,     0,     0,     0,  1141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1166,     0,     0,  1168,   885,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   516,     0,     0,
     429,     0,     0,     0,  1182,     0,  1184,  1185,     0,     0,
       0,     0,     0,     0,   429,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1203,     0,     0,     0,     0,
       0,     0,     0,     0,  1802,     0,     0,     0,     0,     0,
       0,  1216,     0,     0,     0,     0,     0,     0,  1222,  1223,
    1224,  1225,     0,     0,     0,     0,  1234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1258,   428,   428,   428,   428,  1263,     0,     0,     0,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     728,   536,   537,     0,  1861,     0,     0,   538,     0,     0,
       0,  1278,     0,     0,     0,     0,     0,     0,     0,  1871,
       0,     0,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,   428,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1307,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1308,  1309,  1310,     0,     0,     0,     0,  1312,
    1313,     0,  1314,     0,     0,     0,     0,     0,  1100,  1319,
       0,  1320,  1321,  1322,  1323,  1324,     0,     0,     0,   516,
       0,     0,     0,  1326,  1327,     0,     0,  1101,     0,     0,
       0,     0,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1343,     0,  1345,     0,  1347,     0,  1349,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   775,     0,  1366,     0,
       0,     0,     0,   783,   784,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1963,  1964,  1965,  1966,  1968,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1397,     0,   808,     0,     0,     0,   429,     0,     0,     0,
       0,     0,   428,     0,     0,     0,     0,     0,     0,     0,
    1410,     0,     0,     0,     0,     0,     0,   830,     0,     0,
       0,   695,    25,    26,   696,    28,    29,   697,    31,   698,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,  1426,    42,  2018,  1431,     0,   429,   429,   699,    48,
       0,     0,    50,   700,     0,    53,   701,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,    70,   538,     0,  1459,  1460,  1461,
    1462,  1684,     0,     0,     0,  1685,     0,     0,  1469,  1471,
     429,   429,   429,     0,     0,     0,     0,     0,    84,    85,
      86,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,   429,     0,     0,     0,   538,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     7,     8,     0,     0,   538,     0,     0,
       0,     0,     0,   997,     0,     0,   429,   907,     0,     0,
       0,  1546,  1547,  1548,     0,     0,     0,     0,     0,     0,
    1554,     0,  1556,     0,     0,     0,     0,     0,   429,  1559,
       0,     0,     0,     0,   429,     0,     0,     0,     0,     0,
       0,     0,   428,     0,     0,     0,     0,  1575,     0,     0,
     830,     0,  1024,     0,     0,  1580,  1581,  1582,     0,     0,
       0,     0,     0,     0,     0,  1591,     0,     0,     0,   695,
      25,    26,   696,    28,    29,   697,    31,   698,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,  1612,     0,     0,     0,   699,    48,  1618,  1619,
      50,   700,     0,    53,   701,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,  1641,  1642,     0,     0,     0,     0,     0,  1647,  1648,
       0,     0,     0,     0,     0,  1652,    84,    85,    86,     0,
     429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     685,   429,  1655,  1656,  1657,     0,     0,     0,     0,     0,
       0,  1659,  1660,  1661,  1662,     0,  1403,     0,     0,     0,
       0,     0,     0,     0,     0,  1668,     0,     0,     0,     0,
       0,     0,   429,     0,   428,   428,  1679,     0,  1680,     0,
       0,     0,     0,     0,  1688,  1689,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   951,     0,     0,     0,     0,
       0,     0,     0,   428,     0,     0,     0,  1707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1717,     0,
       0,  1720,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,  1729,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1741,     0,     0,     0,     0,  1747,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1749,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,   840,     0,     0,     0,   538,     0,
     429,   429,   429,   429,  1711,     0,     0,  1771,  1712,     0,
       0,     0,     0,   695,    25,    26,   696,    28,    29,   697,
      31,   698,    33,    34,    35,    36,     0,     0,  1780,    38,
      39,    40,     0,     0,    42,     0,     0,  1789,     0,     0,
     699,    48,     0,     0,    50,   700,   515,    53,   701,     0,
       0,     0,     0,     0,     0,  1800,  1801,     0,   429,   428,
       0,     0,     0,     0,     0,  1809,    70,     0,     0,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,  1826,  1827,   538,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
    1840,     0,     0,     0,     0,     0,  1844,  1846,   150,   340,
    1848,  1849,  1850,  1851,     0,     0,     0,     0,     0,   428,
       0,   429,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,     0,     0,     0,     0,     0,
       0,     0,  1877,     0,     0,     0,     0,     0,     0,     0,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   952,
       0,     0,     0,   350,   351,   352,   353,     0,  1888,     0,
       0,   354,   355,   356,  1893,  1894,   357,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   358,     0,
     359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   429,     0,     0,     0,     0,     0,  1919,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,     0,
    1060,  1061,  1062,  1063,     0,  1065,  1066,  1067,  1068,     0,
       0,     0,  1938,  1939,     0,     0,   155,   156,     0,  1078,
       0,  1080,  1943,  1944,     0,  1945,     0,     0,  1948,  1949,
    1950,  1951,     0,     0,     0,     0,     0,  1093,  1094,     0,
       0,     0,     0,     0,  1959,  1099,     0,     0,     0,   428,
     428,   428,   428,   428,     0,     0,     0,     0,     0,     0,
    1747,     0,     0,     0,  1975,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   360,   361,   362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   363,     0,   364,
     107,     0,     0,     0,     0,  2000,     0,     0,     0,     0,
    2003,  2004,     0,     0,  2007,  2008,  2009,  2010,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   428,     0,
       0,     0,     0,     0,     0,     0,   400,     0,     0,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   916,
       0,  2041,  2042,  2043,  2044,  2045,  2046,   877,  1188,  1190,
    1191,     0,     0,     0,  1195,  1196,     0,     0,  1199,  1200,
    1201,  1202,     0,  1204,     0,     0,     0,     0,  1210,     0,
       0,   429,     0,     0,     0,     0,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   483,
     484,   485,   486,   487,   488,     0,   490,   491,     0,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,   509,   510,     0,     0,     0,     0,     0,     0,   187,
     150,   340,     0,   386,     0,     0,   188,   189,   190,  1279,
    1280,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   374,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   220,   221,   222,   223,   350,   351,   352,   353,   224,
       0,     0,     0,   354,   355,   356,     0,     0,   357,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     358,     0,   359,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   340,   429,   429,   630,   631,   632,     0,     0,
       0,   636,   637,   638,   639,   640,   641,   642,     0,   643,
       0,     0,   644,   645,     0,     0,   648,     0,     0,   387,
       0,     0,   429,     0,     0,     0,     0,     0,   657,     0,
       0,     0,     0,   341,   342,   343,   344,   345,   346,   347,
     348,   349,     0,     0,     0,     0,   350,   351,   352,   353,
       0,     0,     0,     0,   354,   355,   356,     0,     0,   357,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   358,     0,   359,     0,     0,     0,     0,   388,     0,
       0,     0,     0,     0,     0,   236,   360,   361,   362,   237,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   363,
       0,   364,   107,   389,   390,   391,   392,     0,     0,     0,
     387,     0,     0,     0,     0,     0,   244,   375,     0,     0,
       0,   246,     0,   393,   394,     0,   395,     0,   396,     0,
    1440,     0,   397,   249,     0,     0,     0,     0,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     7,     8,   516,   538,     0,   682,     0,
     683,     0,     0,     0,     0,     0,  1588,  1473,   429,     0,
       0,     0,     0,     0,     0,     0,   815,   360,   361,   362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     363,     0,   364,   107,     0,     0,     0,  1504,  1505,  1506,
    1507,  1508,     0,     0,     0,     0,  1513,  1514,  1516,     0,
       0,     0,     0,     0,  1523,     0,  1847,     0,     0,     0,
       0,     0,     0,  1526,     0,     0,     0,     0,   429,   695,
      25,    26,   696,    28,    29,   697,    31,   698,    33,    34,
      35,    36,     0,   429,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   699,    48,     0,     0,
      50,   700,     0,    53,   701,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,    70,   538,     0,     0,     0,     0,     0,  1863,
       0,     0,     0,  1864,     0,     0,     0,     0,  1586,     0,
    1589,     0,     0,  1593,     0,  1596,    84,    85,    86,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,  1614,     0,     0,     0,     0,     0,   713,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   877,     0,     0,     0,
       0,     0,     0,     0,     0,  1134,     0,     0,   429,   429,
     429,   429,   429,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,   187,     6,   340,     0,
       0,   878,     0,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   429,     0,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   220,   221,
     222,   223,   350,   351,   352,   353,   224,     0,     0,     0,
     354,   355,   356,     0,     0,   357,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   358,     0,   359,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,  1738,  1739,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,  1761,  1762,     0,    73,     0,
       0,    76,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     921,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   360,   361,   362,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,   363,     0,   364,   107,
    1806,  1807,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   322,     0,     0,     0,   248,     0,     0,
     249,     0,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,   187,     6,   340,     0,
     538,     0,     0,   188,   189,   190,  1087,  1277,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   220,   221,
     222,   223,   350,   351,   352,   353,   224,     0,     0,     0,
     354,   355,   356,     0,     0,   357,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   358,     0,   359,
       0,     0,   229,     0,     0,   230,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,    49,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1059,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   360,   361,   362,   237,   238,     0,     0,
       0,   239,   240,   241,   242,   243,   363,     0,   364,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,   246,     0,
       0,     0,     0,   322,     0,     0,     0,  1764,     0,     0,
     249,   187,     6,   321,  2027,  1441,  1442,     0,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,   368,   340,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,   341,   342,
     343,   344,   345,   346,   347,   348,   349,     0,     0,     0,
       0,   350,   351,   352,   353,     0,     0,     0,     0,   354,
     355,   356,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   358,   236,   359,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   322,   187,
       6,  1562,   248,     0,     0,   249,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,   360,   361,   362,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,   363,     0,   364,   228,    21,
       0,     0,     0,     0,     0,   229,     0,     0,   230,     0,
       0,   231,     0,   232,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,   340,     0,     0,     0,     0,
       0,     0,   233,     0,    49,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,   341,   342,   343,   344,
     345,   346,   347,   348,   349,     0,     0,     0,     0,   350,
     351,   352,   353,     0,     0,     0,     0,   354,   355,   356,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   358,   236,   359,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   245,     0,     0,
       0,   246,     0,     0,     0,     0,   322,   187,     6,     0,
     248,     0,     0,   249,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
     360,   361,   362,     0,     0,     0,     0,     0,   225,   226,
     227,     0,     0,   363,     0,   364,   228,    21,     0,     0,
       0,     0,     0,   229,     0,     0,   230,     0,     0,   231,
       0,   232,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,    49,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1069,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   582,  1703,     0,     0,     0,   246,
       0,     0,     0,     0,   584,   187,     6,     0,   287,   519,
       0,   249,   188,   189,   190,     0,     0,   191,   192,   193,
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
      76,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1070,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   245,     0,     0,     0,   246,     0,     0,
       0,     0,   247,   187,     6,     0,   248,     0,     0,   249,
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
      68,    69,     0,     0,     0,    73,     0,     0,    76,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1071,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,   238,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,     0,     0,     0,   246,     0,     0,     0,     0,
     322,   187,     6,     0,   248,     0,     0,   249,   188,   189,
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
       0,     0,     0,    73,     0,     0,    76,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1076,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   427,
       0,     0,     0,   246,     0,     0,     0,     0,   322,   187,
       6,     0,   514,     0,     0,   249,   188,   189,   190,     0,
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
       0,    73,     0,     0,    76,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1077,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   427,     0,     0,
       0,   246,     0,     0,     0,     0,   322,   187,     6,     0,
       0,   519,     0,   249,   188,   189,   190,     0,     0,   191,
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
       0,     0,    76,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1079,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,     0,     0,     0,   246,
       0,     0,     0,     0,   549,   187,     6,     0,   248,     0,
       0,   249,   188,   189,   190,     0,     0,   191,   192,   193,
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
      76,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   245,     0,     0,     0,   246,     0,     0,
       0,     0,   558,   187,     6,     0,   248,     0,     0,   249,
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
      68,    69,     0,     0,     0,    73,     0,     0,    76,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1198,     0,     0,
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
       0,     0,   225,   226,   227,     0,     0,     0,     0,     0,
     228,    21,     0,     0,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,   232,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,    49,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   237,   238,     0,     0,     0,   239,   240,   241,   242,
     243,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
       0,     0,     0,   246,     0,     0,     0,     0,   562,   187,
       6,     0,   248,     0,     0,   249,   188,   189,   190,     0,
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
       0,    73,     0,     0,    76,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,   237,
     238,     0,     0,     0,   239,   240,   241,   242,   243,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   427,     0,     0,
       0,   246,     0,     0,     0,     0,   322,   187,     6,     0,
     828,     0,     0,   249,   188,   189,   190,     0,     0,   191,
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
       0,     0,    76,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,   237,   238,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,     0,     0,     0,   246,
       0,     0,     0,     0,   322,   187,     6,     0,  1570,     0,
       0,   249,   188,   189,   190,     0,     0,   191,   192,   193,
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
      76,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,   238,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   582,  1703,     0,     0,     0,   246,     0,     0,
       0,     0,   584,   187,     6,     0,   287,     0,     0,   249,
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
      68,    69,     0,     0,     0,    73,     0,     0,    76,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1509,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,   237,   238,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   427,     0,     0,     0,   246,   187,   150,   340,     0,
     322,     0,     0,   188,   189,   190,     0,   249,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   374,   209,   210,   211,   212,
     213,   214,     0,     0,     0,     0,     0,     0,     0,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   220,   221,
     222,   223,   350,   351,   352,   353,   224,     0,     0,     0,
     354,   355,   356,     0,     0,   357,     0,   225,   226,   227,
       0,     0,     0,     0,     0,   228,    21,   358,     0,   359,
     187,   150,   340,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   374,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   220,   221,   222,   223,   350,   351,   352,   353,
     224,     0,     0,     0,   354,   355,   356,     0,     0,   357,
       0,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   358,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   360,   361,   362,   237,     0,     0,     0,
       0,   239,   240,   241,   242,   243,   363,     0,   364,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   375,     0,     0,     0,   246,     0,
       0,     0,     0,   322,     0,     0,     0,  1470,     0,     0,
     249,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1510,
       0,     0,     0,     0,     0,     0,   236,   360,   361,   362,
     237,     0,     0,     0,     0,   239,   240,   241,   242,   243,
     363,     0,   364,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   375,     0,
       0,     0,   246,     0,     0,     0,     0,   322,   187,   150,
     340,  1716,     0,     0,   249,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   374,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     220,   221,   222,   223,   350,   351,   352,   353,   224,     0,
       0,     0,   354,   355,   356,     0,     0,   357,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,   358,
       0,   359,   187,   150,   340,     0,     0,     0,     0,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   374,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   220,   221,   222,   223,   350,   351,
     352,   353,   224,     0,     0,     0,   354,   355,   356,     0,
       0,   357,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,   358,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   360,   361,   362,   237,     0,
       0,     0,     0,   239,   240,   241,   242,   243,   363,     0,
     364,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   375,     0,     0,     0,
     246,     0,     0,     0,     0,   322,     0,     0,     0,  1808,
       0,     0,   249,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1511,     0,     0,     0,     0,     0,     0,   236,   360,
     361,   362,   237,     0,     0,     0,     0,   239,   240,   241,
     242,   243,   363,     0,   364,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     375,     0,     0,     0,   246,   187,   150,     0,     0,   322,
       0,     0,   188,   189,   190,     0,   249,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   374,   209,   210,   211,   212,   213,
     214,     0,     0,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,   220,   221,   222,
     223,   538,     0,     0,     0,   224,     0,     0,     0,     0,
       0,  1518,     0,     0,   187,   150,   225,   226,   227,     0,
       0,   188,   189,   190,   228,    21,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   374,   209,   210,   211,   212,   213,   214,
       0,     0,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,   220,   221,   222,   223,
     538,     0,     0,     0,   224,     0,     0,     0,     0,     0,
    1519,     0,     0,     0,     0,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1520,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   237,     0,     0,     0,     0,
     239,   240,   241,   242,   243,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   375,     0,     0,     0,   246,     0,     0,
       0,     0,   322,     0,     0,     0,   565,     0,     0,   249,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     236,     0,     0,     0,   237,     0,     0,     0,  1521,   239,
     240,   241,   242,   243,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   582,   583,     0,     0,     0,   246,     0,     0,     0,
       0,   584,     0,   187,   150,   287,  1215,     0,   249,     0,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   374,   209,   210,   211,   212,   213,   214,     0,
       0,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,   220,   221,   222,   223,   538,
       0,     0,     0,   224,     0,     0,     0,     0,     0,  1636,
       0,     0,     0,     0,   225,   226,   227,   187,   150,     0,
    1365,     0,   228,    21,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   374,   209,   210,   211,
     212,   213,   214,     0,     0,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,   220,
     221,   222,   223,   538,     0,     0,     0,   224,     0,     0,
       0,     0,     0,  1742,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1743,     0,     0,   236,
       0,     0,     0,   237,     0,     0,     0,     0,   239,   240,
     241,   242,   243,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   375,     0,     0,     0,   246,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,   249,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,   236,     0,     0,  1763,   237,     0,     0,
       0,     0,   239,   240,   241,   242,   243,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   375,     0,     0,     0,   246,
     187,   150,     0,     0,   322,     0,     0,   188,   189,   190,
       0,   249,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   374,
     209,   210,   211,   212,   213,   214,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,     0,     0,     0,     7,     8,   228,
      21,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1767,
       0,     0,     0,     0,   695,    25,    26,   696,    28,    29,
     697,    31,   698,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   699,    48,     0,     0,    50,   700,     0,    53,   701,
       0,     0,     0,   695,    25,    26,   696,    28,    29,   697,
      31,   698,    33,    34,    35,    36,     0,    70,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     699,    48,     0,     0,    50,   700,   236,    53,   701,     0,
     237,    84,    85,    86,     0,   239,   240,   241,   242,   243,
       7,     8,     0,   107,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   375,     0,
       0,     0,   246,     0,     0,     0,     0,   322,     0,     0,
      84,    85,    86,     0,   249,     0,     0,     0,     7,     8,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1135,     0,     0,     0,     0,     0,     0,     0,  1768,     0,
       0,     0,     0,     0,     0,     0,   695,    25,    26,   696,
      28,    29,   697,    31,   698,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,     0,     0,    42,     0,  1154,
       0,     0,     0,   699,    48,     0,     0,    50,   700,     0,
      53,   701,     0,     0,   695,    25,    26,   696,    28,    29,
     697,    31,   698,    33,    34,    35,    36,     7,     8,    70,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   699,    48,     0,     0,    50,   700,     0,    53,   701,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    70,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,    84,    85,    86,     0,     0,  1769,     0,     0,     0,
       0,     0,     0,   695,    25,    26,   696,    28,    29,   697,
      31,   698,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,  1183,     0,    42,     0,     0,     0,     0,     0,
     699,    48,     0,     0,    50,   700,     0,    53,   701,     0,
       0,   695,    25,    26,   696,    28,    29,   697,    31,   698,
      33,    34,    35,    36,     7,     8,    70,    38,    39,    40,
    1213,     0,    42,     0,     0,     0,     0,     0,   699,    48,
       0,     0,    50,   700,     0,    53,   701,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,    84,    85,
      86,     0,     0,  1770,     0,     0,     0,     0,     0,     0,
     695,    25,    26,   696,    28,    29,   697,    31,   698,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,  1357,
       0,    42,     0,     0,     0,     0,     0,   699,    48,     0,
       0,    50,   700,     0,    53,   701,     0,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,    70,     0,     0,     0,  1922,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,    84,    85,    86,
       0,    -4,    -4,     0,     0,     0,  1832,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,    -4,    -4,    -4,     0,   538,     0,    -4,    -4,     0,
      -4,  1157,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
      -4,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,  1989,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,
      10,     0,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,     0,     0,     0,     0,     0,    11,
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
      99,   100,   101,   102,     7,     8,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   106,
       0,   107,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   695,    25,    26,   696,    28,    29,   697,    31,
     698,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   699,
      48,     0,     0,    50,   700,     0,    53,   701,     0,     0,
     695,    25,    26,   696,    28,    29,   697,    31,   698,    33,
      34,    35,    36,     0,     0,    70,    38,    39,    40,   958,
       0,    42,     0,     0,     0,     0,     0,   699,    48,     0,
       0,    50,   700,     0,    53,   701,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,    84,    85,    86,
       0,     0,  1889,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1890,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1900,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1905,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1906,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1907,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1908,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1941,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1972,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1977,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1978,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1981,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1982,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1983,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1984,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2028,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2029,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2030,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2031,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1221,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1361,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1422,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1423,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1424,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1425,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1682,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1693,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1753,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1754,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1755,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1756,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1758,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1783,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1798,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1852,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1869,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1878,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1879,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  1898,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  1958,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  2002,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  2026,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  2052,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  2053,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  2054,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  2055,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,  2056,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,     0,     0,  2057,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,     0,   660,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,     0,   870,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
       0,  1776,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   682,     0,   683,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,   927,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
     971,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,  1105,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,     0,     0,  1170,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,     0,     0,  1171,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
       0,     0,  1175,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,     0,     0,  1176,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,     0,     0,  1257,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,     0,
       0,  1273,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,     0,     0,  1453,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,     0,     0,  1576,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,     0,     0,
    1735,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,     0,     0,  1784,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,   727,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,   731,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,   732,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,   734,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   736,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   737,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     739,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,   741,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   742,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,   743,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,   744,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,   745,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,   746,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,   748,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   749,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   750,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     812,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,   841,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,   898,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,   916,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,   917,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,   918,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,   919,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,   925,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,   926,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,   957,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
     970,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1027,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  1032,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1045,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1104,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,  1110,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,  1111,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,  1112,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,  1126,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1127,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1128,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1156,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  1158,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1159,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1160,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,  1161,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,  1162,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,  1163,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,  1164,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1169,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1256,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1272,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  1458,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   659,   536,   537,     0,     0,     0,
       0,   538,     0,  1522,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   659,   536,   537,     0,     0,
       0,     0,   538,     0,  1630,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   659,   536,   537,     0,
       0,     0,     0,   538,     0,  1631,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   659,   536,   537,
       0,     0,     0,     0,   538,     0,  1632,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   659,   536,
     537,     0,     0,     0,     0,   538,     0,  1633,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   659,
     536,   537,     0,     0,     0,     0,   538,     0,  1683,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     659,   536,   537,     0,     0,     0,     0,   538,     0,  1692,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   659,   536,   537,     0,     0,     0,     0,   538,     0,
    1715,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   659,   536,   537,     0,     0,     0,     0,   538,
       0,  1971,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   659,   536,   537,     0,     0,     0,     0,
     538,     0,  2023
};

static const yytype_int16 yycheck[] =
{
       3,  1151,     3,   132,  1155,   280,   492,   692,     4,   292,
       4,   579,   580,  1598,  1599,  1564,     9,     6,    21,     4,
       4,     4,   677,  1278,     4,   710,   309,     4,     4,     9,
     685,     4,     4,     4,     4,    14,    95,   183,   184,   185,
       6,     6,     5,     4,    47,    95,     5,     5,     4,    95,
       5,     4,     6,     5,     4,     6,     5,   116,   220,   221,
       7,   231,     6,   233,     4,     6,     4,     6,     6,   239,
     116,    74,   233,     7,   231,   126,     9,   239,   239,    82,
     220,   221,   239,     0,    87,     9,    60,    61,   371,    63,
     373,     7,   143,     4,     6,    98,     6,   380,     9,   239,
     151,   152,   153,   227,   228,  1654,   157,   158,   220,   221,
     234,   220,   221,   233,   220,   221,   231,     9,     8,   239,
     266,   267,   268,   171,   239,   130,   131,   239,     9,   132,
     239,   136,   133,   239,   137,   138,   220,   221,     6,   187,
     188,    98,   145,   100,   630,   230,   632,   232,   220,   221,
     234,    89,    95,   156,    97,   158,   231,   303,   304,   305,
     163,   230,     7,   132,   239,   168,     7,   239,   137,   138,
     316,   317,   175,   234,   230,   132,   179,   238,     8,   182,
     183,   184,   185,   186,   161,   162,   163,   164,   220,   221,
     130,   131,   132,   133,   159,   171,   172,   182,   155,    92,
     171,   172,    95,   227,   228,   145,   175,   239,   148,   230,
     206,   174,   236,   234,   186,   174,   174,   186,   159,   174,
       6,   206,   206,   206,  1773,   231,   206,  1377,     8,     6,
     233,   220,   221,   239,   227,   228,     6,   230,   232,   232,
     233,   237,   245,   236,   238,   248,   249,   227,   228,   234,
     230,   234,   232,   206,   234,     7,   236,   230,   235,   262,
     230,   234,   265,   266,   267,   268,   220,   221,   234,   230,
     273,   274,   275,   234,   230,   234,   279,   280,   234,  1828,
     230,   234,   234,   234,   234,   234,   230,   570,   571,   236,
     234,   207,   208,   209,   210,   206,   230,   230,   232,   232,
     303,   304,   305,   236,   587,   217,   230,   217,   232,   283,
     284,   227,   228,   316,   317,   970,   971,   291,   292,   232,
     236,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   227,   228,     6,   230,   229,
     232,   624,   233,     7,   236,   235,   227,   228,   239,   230,
    1935,   232,   220,   221,    92,   236,     7,    95,   504,   505,
     506,   507,   207,   208,   209,   210,   207,   208,   209,   210,
      89,   230,   230,    92,   232,   378,    95,   660,    97,   382,
     383,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   398,   220,   221,   231,   229,
     233,   404,   220,   221,     6,   235,   239,   220,   221,   378,
       6,   220,   221,   235,   231,   239,   233,   239,  1103,   230,
     423,   239,   239,   234,   427,  1974,   239,   220,   221,   386,
     239,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   232,   239,   220,   221,   229,
     235,   231,   230,   233,   239,   207,   208,   209,   210,   220,
     221,   220,   221,  1118,   230,  1120,   239,  1122,   234,  1124,
     230,   474,   220,   221,   235,   227,   228,   235,   481,   482,
     239,   239,   109,   486,     6,   488,   489,   490,   491,   492,
    2039,   239,    95,   220,   221,  1750,   220,   221,   227,   228,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   220,
     221,   514,   239,   220,   221,   239,   230,   486,   230,   488,
     234,   490,   491,   220,   221,   230,     8,   234,   239,   231,
     220,   221,   535,   220,   221,   230,   539,   239,    47,   508,
     509,   230,   239,   207,   208,   209,   210,   230,   677,   239,
     220,   221,   239,   220,   221,   512,   207,   208,   209,   210,
     231,   564,   565,   227,   228,   130,   131,   234,   239,   239,
    1255,   136,   231,   220,   221,   230,   227,   228,   579,   580,
     239,     6,   230,   230,   227,   228,  1271,   234,   220,   221,
     873,   234,   220,   221,   222,   223,   224,   554,   555,   556,
     557,   229,    95,   577,   578,   608,   609,   610,   582,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   231,   235,   233,   234,   229,   239,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   230,   640,   641,   642,
     643,   644,  1897,   646,   647,   648,   649,   220,   221,   652,
      89,   235,   231,    92,   233,   239,    95,   230,    97,     4,
     239,   234,   631,   230,   633,   634,   635,   636,   637,   638,
     179,   640,   641,   642,   643,     6,     7,   646,   647,   648,
      92,   684,   236,    95,   238,    97,   689,   230,   645,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   706,   707,     6,     7,   229,   837,   712,
      89,   230,   715,    92,     6,   718,    95,   720,    97,   235,
     231,   234,   233,   239,   233,   728,   230,   730,   239,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   231,    89,   233,   715,   229,    93,   231,
     231,   720,   233,   234,    99,   100,   265,   102,   103,   231,
     231,   233,   233,   230,   273,   274,   275,   239,   239,   726,
     279,    92,  1923,  1428,    95,   120,    97,   222,   223,   224,
      95,   230,    97,   786,   229,  1440,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      89,   126,    92,    92,   229,    95,    95,    97,   235,   230,
    1960,   235,   239,   234,   234,   239,   235,   235,   143,   235,
     239,   239,    95,   239,    97,   828,   151,   152,   153,   126,
     235,   235,   157,   158,   239,   239,   839,   230,     4,  1990,
       6,   970,   971,     6,   847,   126,   143,   235,   235,   235,
      92,   239,   239,   239,   151,   152,   153,   234,   234,    92,
     157,   158,   143,  2013,   235,   126,   230,   870,   239,    95,
     151,   152,   153,   382,   383,   235,   157,   158,    92,   239,
     235,     4,   143,   235,   239,     4,     5,   239,    95,   398,
     151,   152,   153,     4,   235,   235,   157,   158,   239,   239,
     235,   235,   876,   235,   239,   239,     4,   239,   235,   883,
     235,   235,   239,   887,     4,   239,   235,   235,   235,   235,
     239,   239,   239,   239,   230,   230,   230,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     6,   230,   235,   230,
      59,    60,    61,    62,     6,     6,   232,   235,    67,    68,
      69,   239,   232,    72,   235,  1441,  1442,   235,   230,   962,
     235,   239,  1237,     6,   239,    84,   235,    86,   235,   234,
     239,     6,   239,   976,   235,  1104,  1105,   230,   981,   235,
     489,  1549,  1550,   239,   238,   988,   989,   990,   991,   235,
     238,   235,   235,   239,   503,   239,   239,  1000,   235,   235,
       9,   230,   239,   239,   123,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   230,   972,   235,   235,   229,   116,
     239,   239,  1025,  1026,   230,  1028,   230,  1030,  1031,   230,
    1033,  1000,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,
    1043,   235,   235,  1046,   230,   239,   239,  1021,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   230,   235,   235,   235,   229,   239,   239,   239,
     235,   190,   191,   192,   239,   230,   230,   235,  1081,  1082,
    1083,   239,   234,   234,   203,   235,   205,   206,   235,   239,
     235,   230,   239,   230,   239,  1098,   230,     6,   230,   230,
       4,   234,   230,   230,   234,  1108,  1109,   232,   227,   228,
     230,     6,   230,  1082,  1083,   234,   230,   236,   230,     6,
     230,   230,     6,     6,   174,   232,   234,  1256,  1257,   234,
     234,   232,   232,     6,  1417,   234,  1419,   230,   230,   230,
       6,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   230,   230,   234,     6,   229,
    1435,   232,  1165,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     6,  1178,  1179,  1180,   229,   234,
       7,     6,   234,     6,    85,   234,  1189,   235,     7,   231,
       6,  1194,   239,   239,   231,  1198,     6,     6,   234,    64,
       6,    64,     4,     5,  1207,    64,  1209,    64,   229,     4,
       7,  1779,   231,     7,     6,  1218,     6,     6,     6,   234,
       7,     6,   171,     7,     6,  1194,     6,     6,   234,  1198,
     233,   231,     6,   234,  1237,   234,   234,   234,  1207,     7,
    1209,   236,     6,   232,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   230,  1257,     4,     6,    59,    60,    61,
      62,     6,     6,     6,   231,    67,    68,    69,     6,   232,
      72,     7,   174,     7,     7,     7,   174,     7,     7,     7,
     174,     7,    84,  1286,    86,     7,     7,     7,  1257,  1292,
       7,     7,     7,     7,     7,   234,     6,   231,   233,  1428,
     231,   239,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   239,   239,   234,  1276,
     229,   123,  1808,   234,   234,   239,   234,     7,   231,   236,
       7,     4,     6,  1336,  1337,  1338,  1611,   234,   847,  1342,
     231,  1344,   235,  1346,   236,  1348,   158,  1350,  1351,  1352,
     239,   163,   231,   239,   231,   231,   168,   239,   239,   126,
     235,     7,     6,   233,  1367,     7,     7,     7,   236,   231,
     182,   231,   239,     9,     7,  1378,   231,     6,   239,   235,
     234,   239,     6,  1386,     4,    46,  1389,    46,   190,   191,
     192,   236,   234,   230,   230,   230,  1525,   230,   236,   217,
       7,   203,  1376,   205,   206,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,     7,
       7,    97,     7,   229,     7,     7,     6,   234,     7,   231,
       7,   233,  1435,     7,     7,     7,     4,   107,  1441,  1442,
       4,     6,    95,     6,  1447,     7,     7,   230,     7,     7,
     262,     7,     7,   962,     7,     7,   234,     6,     6,  1416,
       6,     6,  1465,     7,     6,     4,   237,  1470,     6,     4,
       4,   234,   981,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   239,   234,     6,
       6,   229,     6,   235,  1623,     7,  1465,     6,     6,   234,
       6,   232,     6,   230,     6,  1788,  1480,   230,     6,     6,
       6,   236,   120,  1470,     6,   234,  1025,  1026,     6,  1028,
       6,  1030,  1031,   234,  1033,   234,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,  1042,  1043,   234,   174,   234,  1541,  1542,
       6,     6,     6,  1818,     6,     6,     6,     6,  1549,  1550,
       6,     6,     5,   231,     6,     4,     6,     4,     6,   234,
       6,  1564,   234,     7,     6,   234,   234,  1570,   234,   232,
     234,     6,  1081,     6,   234,     6,  1579,   234,   234,   234,
     234,   170,   234,     6,  1587,     6,   231,  1590,  1545,  1098,
     239,  1565,  1566,  1567,  1568,  1569,  1570,  1600,     7,  1108,
    1883,   236,   239,   230,  1607,   239,   234,     4,  1611,   234,
    1613,     6,     6,     6,     6,     6,     6,     4,  1587,     7,
       6,  1590,     6,     6,     6,    93,     6,     5,  1585,   234,
       4,   234,   234,     6,     6,     6,     6,     6,     6,     6,
       6,  1924,   239,     6,     6,     6,  1603,     6,   239,     6,
       4,  1654,     7,     6,     6,  1658,  1165,     6,   234,     5,
     235,     6,     6,   234,   234,     6,   235,   234,     6,  1178,
    1179,  1180,     6,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   169,  1691,     6,
     231,   229,   235,     7,     6,   235,     6,     6,   235,     6,
    1703,  1658,   514,   236,     6,   234,     6,     6,     6,  1218,
       6,     6,     6,  1716,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     6,     6,
     235,   231,   229,   234,     6,   172,     6,   126,     7,   234,
     234,     6,  1745,   234,     6,   235,     6,   234,     6,  1752,
       6,     6,   564,   565,   234,     6,     6,     6,   230,   235,
     231,  1764,     6,     6,     6,  1722,  1723,  1724,     6,     6,
    1773,     6,     6,  1776,     6,     6,   234,  1286,  1779,     6,
     234,     6,     6,  1292,  1787,     6,     6,     6,  1791,   234,
       6,     6,  1270,  1937,   420,  1530,   608,   609,   610,  1285,
       3,     3,     3,  1751,     3,  1808,   553,  1775,     3,    21,
    1607,    -1,    -1,    -1,    -1,  1818,    -1,    -1,  1792,  1793,
    1794,  1795,  1796,    -1,    -1,  1828,    -1,  1336,  1337,  1338,
      -1,    -1,    -1,  1342,    -1,  1344,    -1,  1346,    -1,  1348,
     652,  1350,  1351,  1352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,  1367,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1378,
      -1,    -1,   684,    -1,    -1,    -1,    -1,  1386,    -1,    -1,
      -1,  1855,    -1,    -1,    -1,  1859,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   706,    -1,    -1,    -1,    -1,    -1,
     712,  1904,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,  1926,  1927,  1928,  1929,  1930,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1910,    -1,  1447,    -1,
    1914,    -1,    -1,    -1,    -1,     6,  1903,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1930,    -1,    -1,    -1,
      -1,  1470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1974,    -1,    -1,   786,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,  1995,    -1,   229,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,  1985,  1986,   229,    -1,    -1,   828,    -1,    -1,  2022,
      -1,    -1,  1979,    -1,    -1,    -1,    -1,   839,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2049,  2050,    -1,    -1,
      -1,    -1,    -1,  2022,    -1,  1564,    -1,    -1,   870,   106,
      -1,    -1,    -1,  2066,    -1,    -1,    -1,    -1,    -1,    -1,
    1579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2049,  2050,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
      -1,  1600,    -1,   140,     6,    -1,    -1,  2066,    -1,    -1,
      -1,    -1,    -1,    -1,  1613,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,     6,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1654,    -1,    -1,    -1,  1658,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   988,   989,   990,   991,
      -1,    -1,  1691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     277,    -1,    -1,    -1,  1046,    -1,  1745,    -1,    -1,   286,
     287,    -1,    -1,  1752,    -1,   292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,  1787,   326,
     327,   328,    -1,   330,    -1,    -1,    -1,   334,   335,   336,
      -1,    -1,   339,    -1,    -1,    -1,    -1,  1109,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,  1828,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,
      -1,    -1,   379,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,  1856,   395,   396,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,  1189,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,
      -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   452,    -1,    -1,    -1,    -1,
      -1,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,    -1,   484,   485,    -1,
     487,     7,     8,    -1,    -1,    -1,   493,    -1,    -1,   496,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   510,    -1,  1974,    -1,   514,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,    -1,   540,   541,    -1,    -1,    -1,    -1,    -1,
     547,   548,   549,    -1,    -1,    -1,    -1,   554,   555,   556,
     557,   558,    -1,   560,    -1,   562,    -1,   564,   565,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2039,    -1,    -1,    -1,    -1,   582,   583,   584,    -1,    -1,
      -1,   588,   589,   590,   591,   592,   593,   594,   595,   596,
      -1,    -1,    -1,    -1,   601,    -1,   603,   604,    -1,    -1,
       7,   608,   609,   610,    -1,    -1,   613,   614,   615,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1389,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   639,    -1,    -1,    -1,   229,    -1,    -1,   126,
      -1,    -1,    -1,     8,    -1,   652,    -1,    -1,    -1,    -1,
     657,    -1,   659,    -1,   661,   662,    -1,    -1,    -1,    -1,
      -1,   668,    -1,    -1,    -1,    -1,    -1,   674,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,   684,    -1,    -1,
      -1,    -1,    -1,   690,   691,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   706,
      -1,   708,   709,   229,    -1,   712,   713,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   721,    -1,    -1,    -1,   725,    -1,
      -1,   728,    -1,   730,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,   751,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,   105,   106,   107,  1541,
    1542,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,   786,
      -1,   120,   121,    -1,   123,   124,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,     8,
     158,   828,   229,    -1,    -1,   163,    -1,   166,   167,   168,
     168,    -1,   839,    -1,    -1,    -1,    -1,    -1,    -1,   846,
      -1,    -1,    -1,    -1,   182,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,   870,   229,    -1,    -1,    -1,    -1,    -1,
     877,   878,    -1,    -1,    -1,    -1,   883,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   899,    -1,    -1,   902,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
     248,    -1,    -1,    -1,   921,    -1,   923,   924,    -1,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   942,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,
      -1,   958,    -1,    -1,    -1,    -1,    -1,    -1,   965,   966,
     967,   968,    -1,    -1,    -1,    -1,   973,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     987,   988,   989,   990,   991,   992,    -1,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,  1776,    -1,    -1,   229,    -1,    -1,
      -1,  1018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,  1046,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1069,  1070,  1071,    -1,    -1,    -1,    -1,  1076,
    1077,    -1,  1079,    -1,    -1,    -1,    -1,    -1,     8,  1086,
      -1,  1088,  1089,  1090,  1091,  1092,    -1,    -1,    -1,   427,
      -1,    -1,    -1,  1100,  1101,    -1,    -1,     8,    -1,    -1,
      -1,    -1,  1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1119,    -1,  1121,    -1,  1123,    -1,  1125,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,  1145,    -1,
      -1,    -1,    -1,   481,   482,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1926,  1927,  1928,  1929,  1930,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1177,    -1,   510,    -1,    -1,    -1,   514,    -1,    -1,    -1,
      -1,    -1,  1189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1197,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,    -1,   105,   106,   107,
      -1,  1228,   110,  1995,  1231,    -1,   564,   565,   116,   117,
      -1,    -1,   120,   121,    -1,   123,   124,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,   142,   229,    -1,  1264,  1265,  1266,
    1267,   235,    -1,    -1,    -1,   239,    -1,    -1,  1275,  1276,
     608,   609,   610,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   652,    -1,    -1,    -1,   229,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    13,    14,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,   684,   235,    -1,    -1,
      -1,  1358,  1359,  1360,    -1,    -1,    -1,    -1,    -1,    -1,
    1367,    -1,  1369,    -1,    -1,    -1,    -1,    -1,   706,  1376,
      -1,    -1,    -1,    -1,   712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1389,    -1,    -1,    -1,    -1,  1394,    -1,    -1,
     728,    -1,   730,    -1,    -1,  1402,  1403,  1404,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
     110,    -1,  1439,    -1,    -1,    -1,   116,   117,  1445,  1446,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,   786,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1478,  1479,    -1,    -1,    -1,    -1,    -1,  1485,  1486,
      -1,    -1,    -1,    -1,    -1,  1492,   166,   167,   168,    -1,
     828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,   839,  1509,  1510,  1511,    -1,    -1,    -1,    -1,    -1,
      -1,  1518,  1519,  1520,  1521,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1532,    -1,    -1,    -1,    -1,
      -1,    -1,   870,    -1,  1541,  1542,  1543,    -1,  1545,    -1,
      -1,    -1,    -1,    -1,  1551,  1552,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1570,    -1,    -1,    -1,  1574,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1585,    -1,
      -1,  1588,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1617,    -1,    -1,    -1,    -1,  1622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1636,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   544,    -1,    -1,    -1,   229,    -1,
     988,   989,   990,   991,   235,    -1,    -1,  1664,   239,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,  1685,   105,
     106,   107,    -1,    -1,   110,    -1,    -1,  1694,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,  1703,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,  1712,  1713,    -1,  1046,  1716,
      -1,    -1,    -1,    -1,    -1,  1722,   142,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,  1742,  1743,   229,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1757,    -1,    -1,    -1,    -1,    -1,  1763,  1764,     4,     5,
    1767,  1768,  1769,  1770,    -1,    -1,    -1,    -1,    -1,  1776,
      -1,  1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,   235,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,  1825,    -1,
      -1,    67,    68,    69,  1831,  1832,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1189,    -1,    -1,    -1,    -1,    -1,  1864,   758,   759,
     760,   761,   762,   763,   764,   765,   766,   767,   768,    -1,
     770,   771,   772,   773,    -1,   775,   776,   777,   778,    -1,
      -1,    -1,  1889,  1890,    -1,    -1,    22,    23,    -1,   789,
      -1,   791,  1899,  1900,    -1,  1902,    -1,    -1,  1905,  1906,
    1907,  1908,    -1,    -1,    -1,    -1,    -1,   807,   808,    -1,
      -1,    -1,    -1,    -1,  1921,   815,    -1,    -1,    -1,  1926,
    1927,  1928,  1929,  1930,    -1,    -1,    -1,    -1,    -1,    -1,
    1937,    -1,    -1,    -1,  1941,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,   205,
     206,    -1,    -1,    -1,    -1,  1972,    -1,    -1,    -1,    -1,
    1977,  1978,    -1,    -1,  1981,  1982,  1983,  1984,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1995,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,
      -1,  2028,  2029,  2030,  2031,  2032,  2033,   239,   928,   929,
     930,    -1,    -1,    -1,   934,   935,    -1,    -1,   938,   939,
     940,   941,    -1,   943,    -1,    -1,    -1,    -1,   948,    -1,
      -1,  1389,    -1,    -1,    -1,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   222,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    12,  1019,
    1020,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,  1541,  1542,   341,   342,   343,    -1,    -1,
      -1,   347,   348,   349,   350,   351,   352,   353,    -1,   355,
      -1,    -1,   358,   359,    -1,    -1,   362,    -1,    -1,   123,
      -1,    -1,  1570,    -1,    -1,    -1,    -1,    -1,   374,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,   199,   200,   201,   202,   203,
      -1,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,   225,    -1,   227,   228,    -1,   230,    -1,   232,    -1,
    1240,    -1,   236,   237,    -1,    -1,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    13,    14,  1703,   229,    -1,   231,    -1,
     233,    -1,    -1,    -1,    -1,    -1,   239,  1277,  1716,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   522,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,    -1,   205,   206,    -1,    -1,    -1,  1307,  1308,  1309,
    1310,  1311,    -1,    -1,    -1,    -1,  1316,  1317,  1318,    -1,
      -1,    -1,    -1,    -1,  1324,    -1,  1764,    -1,    -1,    -1,
      -1,    -1,    -1,  1333,    -1,    -1,    -1,    -1,  1776,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,  1791,    -1,   105,   106,   107,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,   123,   124,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,   142,   229,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,  1408,    -1,
    1410,    -1,    -1,  1413,    -1,  1415,   166,   167,   168,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,  1441,    -1,    -1,    -1,    -1,    -1,   239,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,  1926,  1927,
    1928,  1929,  1930,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,   239,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,  1995,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,
      97,    -1,    -1,    -1,    -1,  1615,  1616,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,   139,   140,   141,  1655,  1656,    -1,   145,    -1,
      -1,   148,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,   198,   199,   200,   201,   202,   203,    -1,   205,   206,
    1720,  1721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,    -1,    -1,
     237,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     3,     4,     5,    -1,
     229,    -1,    -1,    10,    11,    12,   235,  1013,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,
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
      -1,    -1,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,   198,   199,   200,   201,   202,   203,    -1,   205,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,    -1,    -1,
     237,     3,     4,     5,  2004,  1241,  1242,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,   148,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,   189,    86,    -1,
      -1,   193,   194,    -1,    -1,    -1,   198,   199,   200,   201,
     202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,
       4,     5,   234,    -1,    -1,   237,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,   203,    -1,   205,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,
      -1,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   118,    -1,    -1,   121,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,   148,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,   189,    86,    -1,    -1,   193,
     194,    -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,    -1,
     234,    -1,    -1,   237,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    -1,    -1,   203,    -1,   205,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,   118,    -1,    -1,   121,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,   148,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   230,     3,     4,    -1,   234,   235,
      -1,   237,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     148,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,
     198,   199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   230,     3,     4,    -1,   234,    -1,    -1,   237,
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
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,     3,     4,    -1,   234,    -1,    -1,   237,    10,    11,
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
      -1,    -1,    -1,   145,    -1,    -1,   148,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,    -1,    -1,    -1,   198,   199,   200,   201,
     202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,
       4,    -1,   234,    -1,    -1,   237,    10,    11,    12,    -1,
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
      -1,   145,    -1,    -1,   148,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,
     194,    -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,    -1,
      -1,   235,    -1,   237,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   148,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   230,     3,     4,    -1,   234,    -1,
      -1,   237,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     148,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,
     198,   199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   230,     3,     4,    -1,   234,    -1,    -1,   237,
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
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,     3,     4,    -1,   234,    -1,    -1,   237,    10,    11,
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
      -1,    -1,    -1,   145,    -1,    -1,   148,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,    -1,    -1,    -1,   198,   199,   200,   201,
     202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,
       4,    -1,   234,    -1,    -1,   237,    10,    11,    12,    -1,
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
      -1,   145,    -1,    -1,   148,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,
     194,    -1,    -1,    -1,   198,   199,   200,   201,   202,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,    -1,
     234,    -1,    -1,   237,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   148,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   230,     3,     4,    -1,   234,    -1,
      -1,   237,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     148,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,
     198,   199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   230,     3,     4,    -1,   234,    -1,    -1,   237,
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
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,   148,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,     3,     4,     5,    -1,
     230,    -1,    -1,    10,    11,    12,    -1,   237,    15,    16,
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
      -1,   198,   199,   200,   201,   202,   203,    -1,   205,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,    -1,    -1,
     237,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,   199,   200,   201,   202,
     203,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,     3,     4,
       5,   234,    -1,    -1,   237,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    86,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,   199,   200,   201,   202,   203,    -1,
     205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   234,
      -1,    -1,   237,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,   199,   200,
     201,   202,   203,    -1,   205,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,   225,     3,     4,    -1,    -1,   230,
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
      -1,    -1,   230,    -1,    -1,    -1,   234,    -1,    -1,   237,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     189,    -1,    -1,    -1,   193,    -1,    -1,    -1,   239,   198,
     199,   200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   230,    -1,     3,     4,   234,     6,    -1,   237,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    55,    56,    57,    58,   229,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    74,    75,    76,     3,     4,    -1,
       6,    -1,    82,    83,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    55,
      56,    57,    58,   229,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    83,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,   189,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,   237,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,   239,   193,    -1,    -1,
      -1,    -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,   225,
       3,     4,    -1,    -1,   230,    -1,    -1,    10,    11,    12,
      -1,   237,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    13,    14,    82,
      83,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
     105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,   124,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   142,    -1,   105,
     106,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,   189,   123,   124,    -1,
     193,   166,   167,   168,    -1,   198,   199,   200,   201,   202,
      13,    14,    -1,   206,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,
     166,   167,   168,    -1,   237,    -1,    -1,    -1,    13,    14,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,   105,   106,   107,    -1,    -1,   110,    -1,   235,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    13,    14,   142,
     105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,   120,   121,    -1,   123,   124,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,   142,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   235,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,    -1,   123,   124,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    13,    14,   142,   105,   106,   107,
     235,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,    -1,   120,   121,    -1,   123,   124,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,   105,   106,   107,   235,
      -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,   142,    -1,    -1,    -1,   235,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,   166,   167,   168,
      -1,    44,    45,    -1,    -1,    -1,   239,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    64,    65,    66,    -1,   229,    -1,    70,    71,    -1,
      73,   235,    -1,    -1,    77,    78,    -1,    80,    81,    -1,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,   106,   107,   108,   235,   110,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,   121,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,     4,
      -1,   154,   155,   156,    -1,    -1,    -1,   160,    13,    14,
      -1,    -1,   165,   166,   167,   168,    -1,    -1,   171,    -1,
     173,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    44,
      45,    -1,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,   206,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    77,    78,    -1,    80,    81,    -1,    83,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,   106,   107,   108,    -1,   110,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    13,    14,    -1,   154,
     155,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,   171,    -1,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    13,    14,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,   206,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,   105,   106,
     107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,   120,   121,    -1,   123,   124,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   142,   105,   106,   107,   146,
      -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,   166,   167,   168,
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
      -1,    -1,    -1,    -1,    -1,    -1,   239,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,   234,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,   234,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,   234,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231,    -1,   233,   211,   212,   213,   214,   215,
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
      -1,   231,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,
     229,    -1,   231
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
     246,   266,   284,   285,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   303,   305,   306,   312,   313,   314,   315,
     319,   340,   341,   234,   238,    14,    95,   230,   230,     6,
     234,     6,     6,     6,     6,   230,     6,     6,   232,   232,
       4,   321,   341,   230,   232,   264,   264,   230,   234,   230,
     230,     4,   230,   234,   230,   230,     4,   230,   234,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   109,
      95,     6,   234,    89,    92,    95,   230,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    74,    75,    76,    82,    89,
      92,    95,    97,   116,   121,   123,   189,   193,   194,   198,
     199,   200,   201,   202,   220,   221,   225,   230,   234,   237,
     285,   296,   303,   305,   316,   317,   319,   321,   328,   330,
     341,   230,   234,    95,    95,   116,    92,    95,    97,    89,
      92,    95,    97,    92,    95,    97,    92,    95,   230,    92,
     171,   187,   188,   234,   220,   221,   230,   234,   325,   326,
     325,   234,   234,   325,     4,    89,    93,    99,   100,   102,
     103,   120,   230,    95,    97,    95,    92,     4,   182,   234,
     341,     4,     6,    89,    92,    95,    92,    95,     4,     4,
       4,     5,   230,   328,   329,     4,   230,   230,   230,     4,
     234,   332,   341,     4,   230,   230,   230,     6,     6,   232,
       5,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      59,    60,    61,    62,    67,    68,    69,    72,    84,    86,
     190,   191,   192,   203,   205,   336,   341,   230,     4,   336,
       5,   234,     5,   234,    32,   221,   316,   341,   232,   230,
     234,     6,   230,   234,     6,   238,     7,   123,   182,   207,
     208,   209,   210,   227,   228,   230,   232,   236,   262,   263,
     264,   316,   335,   336,   341,     4,   285,   286,   287,   234,
       6,   316,   335,   336,   341,   335,   316,   335,   339,   268,
     272,   230,   324,     9,   336,   341,   316,   221,   316,   330,
     331,   316,   316,   230,   316,   331,   316,   316,   230,   316,
     331,   316,   316,   316,   316,   316,   316,   335,   316,   316,
     316,   328,   230,   331,   329,   329,   329,   335,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   230,   232,   264,   264,   264,   264,   264,   264,   230,
     264,   264,   230,   264,     5,   174,   234,     5,   174,     5,
     174,     5,   174,   116,    89,    92,    95,    97,   230,   264,
     264,   230,   230,   316,   234,   316,   330,   316,   316,   235,
     331,     9,   341,     8,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   229,     9,
     230,   232,   236,   263,   264,   316,   331,   230,   230,   230,
     328,   329,   329,   329,   230,   230,   230,   230,   230,   328,
     230,   328,   230,   328,   234,   234,   316,     4,   328,   332,
     234,   234,   325,   325,   325,   316,   316,   220,   221,   234,
     234,   325,   220,   221,   230,   287,   325,   234,   230,   234,
     230,   230,   230,   230,   230,   230,   230,   316,   329,   329,
     329,   230,     4,   232,   232,   287,     6,     6,   234,   234,
     234,   329,   329,   232,   232,   232,   316,     6,     6,   316,
     316,   316,   236,   316,   234,   174,   316,   316,   316,   316,
     264,   264,   264,   230,   230,   230,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   230,   230,   264,   232,
       6,     6,   234,     6,   287,     6,   287,   264,   316,   222,
     234,   230,   232,   335,   316,   287,   328,   328,   234,   336,
      89,    92,    95,    97,     7,   316,   316,     4,   171,   172,
     328,     6,   231,   233,   234,   265,     6,   234,     6,     9,
     230,   232,   236,   341,   235,    89,    92,    95,    97,   116,
     121,   124,   284,   316,     6,   231,   239,     9,   230,   232,
     236,   231,   239,   239,   231,   239,   233,   239,   267,   233,
     267,    85,   323,   320,   341,   239,   239,   231,   222,   235,
     239,   231,   231,   316,   231,   235,   231,   231,   316,   231,
     235,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,     7,   316,   235,     6,     6,     6,   231,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   330,   316,   316,   316,   316,
     316,   316,   316,   330,   330,   341,   234,   316,   316,   335,
     316,   335,   328,   335,   335,   339,   316,    64,   316,    64,
      64,    64,   329,   329,   329,   329,   335,   335,   330,   341,
     336,   331,   231,   235,     9,   264,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   234,   316,
     330,   316,   316,   316,   341,   316,   316,     4,   322,   234,
     265,   231,   235,   316,   316,   316,     7,     7,   309,   309,
     278,   316,   336,   279,   316,   336,   280,   316,   336,   281,
     316,   336,   316,     6,   316,     6,   316,     6,   331,   331,
     234,   231,     6,   234,   287,   287,   239,   239,   239,   325,
     325,   286,   286,   239,   316,   235,   300,   239,   287,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   231,     7,
     310,     6,     7,   316,     6,   316,   316,   235,   331,   331,
     331,     6,     6,   316,   316,   316,   231,   231,   231,   231,
     171,   239,   287,   234,     8,   231,   231,   233,   339,   335,
     339,   335,   335,   335,   335,   335,   335,   316,   335,   335,
     335,   335,   237,   338,   341,   336,   335,   335,   335,   341,
     331,   235,   235,   316,   316,   287,   233,   231,   146,   304,
     231,   235,   239,   316,     6,   234,   234,   234,   234,   316,
     231,   233,     7,   262,   263,   236,     7,     6,   331,     7,
     210,   262,   247,   341,   316,   316,   322,   232,   234,   234,
     234,   234,   230,   116,    92,    95,    97,   235,     6,   217,
     244,   331,   341,   316,   316,     4,   322,     6,   331,   316,
       6,   335,     6,   341,     6,   335,   316,   231,   232,   316,
     336,     7,   174,   316,   330,     7,     7,   231,     7,   174,
       7,     7,   231,     7,   174,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   316,   231,   234,     6,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   239,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   239,
     239,   239,   231,   233,   233,   331,   239,   239,   265,   239,
     265,   239,   239,   239,   231,   318,   234,   235,   234,   234,
     234,   239,   239,   265,   265,   231,   231,   235,     7,   265,
       8,     8,   331,   236,   231,   233,   263,   331,     7,   234,
     231,   231,   231,   316,   328,     4,   308,     6,   231,   239,
     231,   239,   231,   239,   231,   239,   231,   231,   231,   235,
     235,   331,   236,   287,   235,   235,   325,   316,   316,   235,
     235,   316,   325,   126,   126,   143,   151,   152,   153,   157,
     158,   301,   302,   325,   235,   297,   231,   235,   231,   231,
     231,   231,   231,   231,   231,     7,   316,     6,   316,   231,
     233,   233,   235,   235,   235,   233,   233,   239,     7,     7,
       7,   236,   316,   235,   316,   316,     7,   236,   265,   239,
     265,   265,   231,   231,   239,   265,   265,   239,   239,   265,
     265,   265,   265,   316,   265,     9,   337,   239,   231,   239,
     265,   233,   235,   235,     7,     6,   316,   235,   234,     6,
     328,   235,   316,   316,   316,   316,     6,     7,   262,   263,
     236,   262,   263,   336,   316,     6,     4,   234,   333,   341,
     235,    46,    46,   328,     4,   161,   162,   163,   164,   235,
     250,   254,   257,   259,   260,   236,   231,   233,   316,   331,
     331,   331,   331,   316,   230,   230,   230,   230,   217,   335,
     231,   236,   231,   233,   231,   239,     7,   264,   316,   265,
     265,   325,    95,    97,   328,   328,     7,   328,    95,    97,
     328,   328,     7,   328,    97,   328,   328,   328,   328,   328,
     328,   328,   328,   328,     6,     7,   331,   316,   316,   316,
     316,   235,   316,   316,   316,   328,   335,   335,   274,   316,
     316,   316,   316,   316,   316,   328,   316,   316,   235,   322,
     263,   236,   263,   235,   328,   331,     7,     7,     7,   126,
     307,     6,   262,   316,   262,   316,   262,   316,   262,   316,
       7,     7,     7,     7,     7,   235,     4,   235,   239,   239,
     239,   235,   235,   107,     4,     6,   316,   234,     6,   230,
       6,   159,     6,   159,   235,   302,   239,   301,     7,     6,
       7,     7,     7,     7,     7,     7,     7,   328,     6,   234,
       6,     6,     6,    95,     7,     6,     6,   316,   328,   328,
     328,     4,   239,     8,     8,   231,     4,     4,   331,   335,
     316,   335,   237,   276,   335,   335,   239,   234,     6,   234,
     328,   235,   235,   235,   235,   235,   316,     6,     4,   171,
     172,   316,     6,     6,     6,     7,   332,   334,     6,   232,
     265,   264,   264,     6,   251,   230,   230,   234,   261,     6,
     322,   236,   335,   233,   235,   235,   235,   235,   231,   316,
     316,   316,   316,     6,     6,   244,   322,   236,     6,   316,
     234,   316,   336,   265,   274,     6,     6,     6,   234,   234,
     120,   283,   283,   328,     6,   234,   234,     6,     6,   328,
     174,   282,   234,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   235,   265,   265,   265,   265,   265,   239,
     239,   239,   231,   265,   265,   239,   265,   275,   239,   239,
     239,   239,   231,   265,     6,     4,   265,     6,   235,   328,
     328,   328,     4,     6,   328,   328,   328,   328,   328,   328,
     328,   234,   234,     7,     6,     7,   316,   316,   316,   234,
     234,   234,   232,     6,   316,   328,   316,     6,     6,   316,
     325,   235,     5,   328,   234,   234,   234,   234,   234,   234,
     234,   328,     6,   331,   234,   316,   233,     6,     6,   170,
     316,   316,   316,     6,     6,     7,   265,   239,   239,   265,
     239,   316,   239,   265,   277,   231,   265,   336,   287,   287,
     239,     6,     6,     7,   262,   263,   236,     7,     6,   332,
     235,   239,   316,   262,   265,   339,   339,   230,   316,   316,
     327,   328,   234,     4,     6,     6,     6,     6,     6,     6,
     231,   231,   231,   231,   335,     4,   239,   328,   336,     7,
     233,   316,   316,   325,     6,     6,     6,   316,   316,     6,
      93,     6,   316,     5,   234,   316,   316,   316,     4,   316,
     316,   316,   316,   263,   234,     6,   282,     6,   316,     6,
       6,     6,     6,     6,     4,     6,     6,   331,   331,   316,
     316,   336,   235,   231,   235,   239,   286,   286,   316,   316,
     235,   239,   231,   235,   239,     6,     6,   327,   325,   325,
     325,   325,   325,   221,   325,     6,   235,   316,     6,     6,
     328,   235,   239,     8,   235,   231,   234,   316,   336,   335,
     316,   335,     4,   186,   239,   304,   304,   328,   336,   316,
       6,     4,   333,     6,   332,   233,   328,     6,   265,   265,
     248,   316,   239,   239,   235,   239,   249,   316,     6,   316,
     269,   271,   234,   235,   235,   235,   235,   234,   235,     5,
     327,   265,   265,   239,   234,   328,   336,   239,   239,   239,
     239,   316,     6,   234,   235,   235,   234,     6,     6,   234,
     316,   235,   235,   235,   233,     6,   328,     7,   234,   316,
     235,   239,   239,   239,   239,   239,   239,     6,   235,   169,
     316,   316,   331,     6,     6,   231,   265,   265,   234,   316,
     336,   336,   336,   235,   235,   235,     6,     6,     7,     6,
     236,     6,     6,     6,   231,   239,   316,   316,   234,   328,
     235,   239,   239,   274,   276,   328,     6,     6,     6,     6,
     316,     6,     6,   235,   316,   273,   316,   330,   316,   316,
     316,   316,   235,   327,   130,   131,   136,   311,   130,   131,
     311,   331,   286,   235,   239,     6,   235,   328,   287,   235,
       6,   331,   325,   325,   325,   325,   325,   316,   235,   235,
     235,   339,   231,   234,     6,   332,   172,   252,   316,   239,
     239,   327,     6,   316,   316,   235,   235,   270,   235,   234,
     239,   235,   239,     7,     7,   239,   239,   239,   239,   235,
     234,   325,   328,     6,   234,   325,     6,   235,   235,   316,
       6,   126,   235,   298,   234,   235,   239,   239,   239,   239,
     239,     6,     6,   235,     6,   287,     6,   234,   316,   316,
     235,   239,   274,   316,   316,   316,   336,   341,   316,   316,
     316,   316,     6,   325,     6,   325,     6,     6,   235,   316,
     301,   287,     6,   331,   331,   331,   331,   325,   331,   304,
     249,   231,   239,     6,   234,   316,   235,   239,   239,     7,
     230,   239,   239,   239,   239,   239,   239,     6,   235,   235,
     299,   235,   235,   235,   235,   239,   235,   235,   235,   255,
     316,   327,   235,   316,   316,   336,   231,   316,   316,   316,
     316,   325,   325,   301,     6,     6,     6,     6,   331,     6,
       6,     6,   234,   231,   235,     6,   235,   265,   239,   239,
     239,   239,   239,   239,   235,   235,   253,   335,   258,   234,
       6,   316,   316,   316,   316,   316,   316,     6,   235,   239,
     234,   327,   235,   235,   235,   235,   235,   235,     6,   335,
     256,   335,   235,     6,     6,   235,   239,     6,     6,   335
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

  case 197:
#line 2253 "Gmsh.y"
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
#line 2273 "Gmsh.y"
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
#line 2294 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 200:
#line 2295 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 201:
#line 2300 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 202:
#line 2304 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 203:
#line 2308 "Gmsh.y"
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
#line 2319 "Gmsh.y"
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
#line 2330 "Gmsh.y"
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
#line 2341 "Gmsh.y"
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
#line 2357 "Gmsh.y"
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
#line 2376 "Gmsh.y"
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
#line 2398 "Gmsh.y"
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
#line 2413 "Gmsh.y"
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
#line 2428 "Gmsh.y"
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
#line 2447 "Gmsh.y"
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
#line 2498 "Gmsh.y"
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
#line 2519 "Gmsh.y"
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
#line 2541 "Gmsh.y"
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
#line 2563 "Gmsh.y"
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
#line 2668 "Gmsh.y"
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
#line 2684 "Gmsh.y"
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
#line 2719 "Gmsh.y"
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
#line 2730 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 221:
#line 2736 "Gmsh.y"
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
#line 2751 "Gmsh.y"
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
#line 2779 "Gmsh.y"
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
#line 2796 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 225:
#line 2803 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 226:
#line 2815 "Gmsh.y"
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
#line 2834 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 228:
#line 2840 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 229:
#line 2846 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 230:
#line 2853 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 231:
#line 2860 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 232:
#line 2867 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 233:
#line 2879 "Gmsh.y"
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
#line 2952 "Gmsh.y"
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
#line 2970 "Gmsh.y"
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
#line 2987 "Gmsh.y"
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
#line 3002 "Gmsh.y"
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
#line 3035 "Gmsh.y"
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
#line 3047 "Gmsh.y"
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
#line 3071 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 241:
#line 3075 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 242:
#line 3080 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 243:
#line 3087 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 244:
#line 3092 "Gmsh.y"
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
#line 3102 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 246:
#line 3107 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 247:
#line 3113 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 248:
#line 3121 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 249:
#line 3125 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 250:
#line 3129 "Gmsh.y"
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
#line 3139 "Gmsh.y"
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
#line 3202 "Gmsh.y"
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
#line 3218 "Gmsh.y"
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
#line 3235 "Gmsh.y"
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
#line 3252 "Gmsh.y"
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
#line 3274 "Gmsh.y"
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
#line 3296 "Gmsh.y"
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
#line 3331 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 259:
#line 3339 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 260:
#line 3347 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 261:
#line 3353 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 262:
#line 3360 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 263:
#line 3367 "Gmsh.y"
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
#line 3387 "Gmsh.y"
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
#line 3413 "Gmsh.y"
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
#line 3425 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 267:
#line 3437 "Gmsh.y"
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
#line 3453 "Gmsh.y"
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
#line 3469 "Gmsh.y"
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
#line 3485 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 271:
#line 3491 "Gmsh.y"
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
#line 3507 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 273:
#line 3513 "Gmsh.y"
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
#line 3531 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 275:
#line 3537 "Gmsh.y"
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
#line 3553 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 277:
#line 3559 "Gmsh.y"
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
#line 3574 "Gmsh.y"
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
#line 3588 "Gmsh.y"
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
#line 3603 "Gmsh.y"
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
#line 3618 "Gmsh.y"
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
#line 3639 "Gmsh.y"
    {
    ;}
    break;

  case 283:
#line 3642 "Gmsh.y"
    {
    ;}
    break;

  case 284:
#line 3648 "Gmsh.y"
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
#line 3660 "Gmsh.y"
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
#line 3680 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 287:
#line 3684 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 288:
#line 3688 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 289:
#line 3692 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 290:
#line 3696 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 291:
#line 3700 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 292:
#line 3704 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 293:
#line 3708 "Gmsh.y"
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
#line 3717 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 295:
#line 3729 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 296:
#line 3730 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 297:
#line 3731 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 298:
#line 3732 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 299:
#line 3733 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 300:
#line 3737 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 301:
#line 3738 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 302:
#line 3739 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 303:
#line 3744 "Gmsh.y"
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
#line 3761 "Gmsh.y"
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
#line 3779 "Gmsh.y"
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
#line 3794 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 307:
#line 3798 "Gmsh.y"
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
#line 3813 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 309:
#line 3817 "Gmsh.y"
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
#line 3833 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 311:
#line 3837 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 312:
#line 3842 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 313:
#line 3846 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 314:
#line 3852 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 315:
#line 3856 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 316:
#line 3863 "Gmsh.y"
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
#line 3880 "Gmsh.y"
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
#line 3921 "Gmsh.y"
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
#line 3965 "Gmsh.y"
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
#line 4004 "Gmsh.y"
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
#line 4029 "Gmsh.y"
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
#line 4038 "Gmsh.y"
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
#line 4068 "Gmsh.y"
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
#line 4094 "Gmsh.y"
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
#line 4121 "Gmsh.y"
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
#line 4153 "Gmsh.y"
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
#line 4180 "Gmsh.y"
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
#line 4206 "Gmsh.y"
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
#line 4232 "Gmsh.y"
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
#line 4258 "Gmsh.y"
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
#line 4284 "Gmsh.y"
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
#line 4305 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 333:
#line 4311 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 334:
#line 4317 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 335:
#line 4323 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 336:
#line 4329 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 337:
#line 4335 "Gmsh.y"
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
#line 4361 "Gmsh.y"
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
#line 4387 "Gmsh.y"
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
#line 4404 "Gmsh.y"
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
#line 4421 "Gmsh.y"
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
#line 4438 "Gmsh.y"
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
#line 4450 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 344:
#line 4456 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 345:
#line 4462 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 346:
#line 4474 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 347:
#line 4478 "Gmsh.y"
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
#line 4488 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 349:
#line 4498 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 350:
#line 4499 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 351:
#line 4500 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 352:
#line 4505 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 353:
#line 4511 "Gmsh.y"
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
#line 4523 "Gmsh.y"
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
#line 4541 "Gmsh.y"
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
#line 4568 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 357:
#line 4569 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 358:
#line 4570 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 359:
#line 4571 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 360:
#line 4572 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 361:
#line 4573 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 362:
#line 4574 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 363:
#line 4575 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 364:
#line 4577 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 365:
#line 4583 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 366:
#line 4584 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 367:
#line 4585 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 368:
#line 4586 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 369:
#line 4587 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 370:
#line 4588 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 371:
#line 4589 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 372:
#line 4590 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 373:
#line 4591 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 374:
#line 4592 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 375:
#line 4593 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 376:
#line 4594 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 377:
#line 4595 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 378:
#line 4596 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 379:
#line 4597 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 380:
#line 4598 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 381:
#line 4599 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 382:
#line 4600 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 383:
#line 4601 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 384:
#line 4602 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 385:
#line 4603 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 386:
#line 4604 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 387:
#line 4605 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 388:
#line 4606 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 389:
#line 4607 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 390:
#line 4608 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 391:
#line 4609 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 392:
#line 4610 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 393:
#line 4611 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 394:
#line 4612 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 395:
#line 4613 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 396:
#line 4614 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 397:
#line 4615 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 398:
#line 4616 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 399:
#line 4625 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 400:
#line 4626 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 401:
#line 4627 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 402:
#line 4628 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 403:
#line 4629 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 404:
#line 4630 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 405:
#line 4631 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 406:
#line 4632 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 407:
#line 4633 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 408:
#line 4634 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 409:
#line 4635 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 410:
#line 4640 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 411:
#line 4642 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 412:
#line 4648 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 413:
#line 4650 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 414:
#line 4655 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 415:
#line 4661 "Gmsh.y"
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
#line 4685 "Gmsh.y"
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
#line 4703 "Gmsh.y"
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
#line 4721 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 419:
#line 4726 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 420:
#line 4732 "Gmsh.y"
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
#line 4748 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 422:
#line 4754 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 423:
#line 4760 "Gmsh.y"
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
#line 4779 "Gmsh.y"
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
#line 4800 "Gmsh.y"
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
#line 4833 "Gmsh.y"
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
#line 4857 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 428:
#line 4861 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 429:
#line 4866 "Gmsh.y"
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
#line 4876 "Gmsh.y"
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
#line 4886 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 4891 "Gmsh.y"
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
#line 4902 "Gmsh.y"
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
#line 4911 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 435:
#line 4916 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 436:
#line 4921 "Gmsh.y"
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
#line 4949 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 438:
#line 4951 "Gmsh.y"
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
#line 4979 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 440:
#line 4981 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 441:
#line 4986 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 442:
#line 4995 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 443:
#line 4997 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 444:
#line 5002 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 445:
#line 5004 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 446:
#line 5010 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 447:
#line 5014 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 448:
#line 5018 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 449:
#line 5022 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 450:
#line 5026 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 451:
#line 5033 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 452:
#line 5037 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 453:
#line 5041 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 454:
#line 5045 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 455:
#line 5052 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 456:
#line 5057 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 457:
#line 5064 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 458:
#line 5069 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 459:
#line 5073 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 460:
#line 5078 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 461:
#line 5082 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 462:
#line 5090 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 463:
#line 5101 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 464:
#line 5105 "Gmsh.y"
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
#line 5117 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 466:
#line 5125 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 467:
#line 5133 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 468:
#line 5140 "Gmsh.y"
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
#line 5150 "Gmsh.y"
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
#line 5173 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 471:
#line 5179 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 472:
#line 5185 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 473:
#line 5191 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 474:
#line 5197 "Gmsh.y"
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
#line 5208 "Gmsh.y"
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
#line 5219 "Gmsh.y"
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
#line 5230 "Gmsh.y"
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
#line 5242 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 479:
#line 5248 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 480:
#line 5254 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 481:
#line 5260 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 482:
#line 5265 "Gmsh.y"
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
#line 5275 "Gmsh.y"
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
#line 5285 "Gmsh.y"
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
#line 5295 "Gmsh.y"
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
#line 5308 "Gmsh.y"
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
#line 5320 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 488:
#line 5324 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 489:
#line 5328 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 490:
#line 5332 "Gmsh.y"
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
#line 5350 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 492:
#line 5358 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 493:
#line 5366 "Gmsh.y"
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
#line 5395 "Gmsh.y"
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
#line 5405 "Gmsh.y"
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
#line 5421 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 497:
#line 5432 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 498:
#line 5437 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 5441 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 500:
#line 5445 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 501:
#line 5457 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 502:
#line 5461 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 503:
#line 5473 "Gmsh.y"
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

  case 504:
#line 5490 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 505:
#line 5500 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 506:
#line 5504 "Gmsh.y"
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

  case 507:
#line 5519 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 508:
#line 5524 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 509:
#line 5531 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 510:
#line 5535 "Gmsh.y"
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

  case 511:
#line 5548 "Gmsh.y"
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
#line 5562 "Gmsh.y"
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
#line 5579 "Gmsh.y"
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

  case 514:
#line 5605 "Gmsh.y"
    { (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c)); ;}
    break;

  case 515:
#line 5609 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 516:
#line 5617 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 517:
#line 5623 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 518:
#line 5629 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 519:
#line 5635 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 520:
#line 5644 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 521:
#line 5648 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 522:
#line 5652 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 523:
#line 5660 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 524:
#line 5666 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 525:
#line 5672 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 526:
#line 5680 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 527:
#line 5688 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 528:
#line 5695 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 529:
#line 5703 "Gmsh.y"
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

  case 530:
#line 5718 "Gmsh.y"
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

  case 531:
#line 5732 "Gmsh.y"
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

  case 532:
#line 5746 "Gmsh.y"
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

  case 533:
#line 5758 "Gmsh.y"
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

  case 534:
#line 5774 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 535:
#line 5783 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 536:
#line 5792 "Gmsh.y"
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

  case 537:
#line 5802 "Gmsh.y"
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

  case 538:
#line 5813 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 539:
#line 5821 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 540:
#line 5829 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 541:
#line 5833 "Gmsh.y"
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

  case 542:
#line 5852 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 543:
#line 5859 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 544:
#line 5865 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 545:
#line 5872 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 546:
#line 5879 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 547:
#line 5881 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 548:
#line 5889 "Gmsh.y"
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

  case 549:
#line 5913 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 550:
#line 5915 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 551:
#line 5921 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 552:
#line 5926 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 553:
#line 5934 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 554:
#line 5943 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 555:
#line 5956 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 556:
#line 5959 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 557:
#line 5963 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 12906 "Gmsh.tab.cpp"
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


#line 5966 "Gmsh.y"


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

