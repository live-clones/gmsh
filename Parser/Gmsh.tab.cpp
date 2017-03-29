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
List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
  (char* c1, char* c2, char* c3);
int treat_Struct_FullName_dot_tSTRING_Float_getDim
  (char* c1, char* c2, char* c3);
char* treat_Struct_FullName_String
  (char* c1, char* c2, int type_var = 1, int index = 0,
   char* val_default = NULL, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = NULL, int type_treat = 0);
List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
  (char* c1, char* c2, char* c3);

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
#line 163 "Gmsh.y"
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
#line 727 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 740 "Gmsh.tab.cpp"

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
#define YYLAST   16106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  603
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2195

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
     640,   642,   646,   649,   651,   656,   659,   662,   663,   666,
     668,   672,   675,   678,   681,   684,   687,   689,   691,   695,
     697,   699,   703,   705,   707,   711,   713,   715,   719,   720,
     726,   727,   730,   738,   746,   754,   763,   772,   780,   788,
     800,   809,   817,   826,   835,   844,   854,   858,   863,   874,
     882,   890,   898,   906,   914,   922,   930,   938,   946,   954,
     963,   976,   985,   993,  1001,  1010,  1019,  1028,  1037,  1046,
    1055,  1061,  1073,  1079,  1089,  1099,  1104,  1114,  1124,  1126,
    1128,  1129,  1132,  1139,  1146,  1153,  1160,  1169,  1180,  1195,
    1212,  1225,  1240,  1255,  1270,  1285,  1294,  1303,  1310,  1315,
    1321,  1328,  1335,  1339,  1344,  1348,  1354,  1361,  1367,  1371,
    1375,  1380,  1386,  1391,  1397,  1401,  1407,  1415,  1423,  1427,
    1435,  1439,  1442,  1445,  1448,  1451,  1454,  1470,  1473,  1476,
    1479,  1482,  1485,  1502,  1514,  1521,  1530,  1539,  1550,  1552,
    1555,  1558,  1560,  1564,  1568,  1573,  1578,  1580,  1582,  1588,
    1600,  1614,  1615,  1623,  1624,  1638,  1639,  1655,  1656,  1663,
    1673,  1676,  1680,  1691,  1693,  1696,  1702,  1710,  1713,  1716,
    1720,  1723,  1727,  1730,  1734,  1744,  1751,  1753,  1755,  1757,
    1759,  1761,  1762,  1765,  1769,  1773,  1778,  1788,  1793,  1808,
    1809,  1813,  1814,  1816,  1817,  1820,  1821,  1824,  1825,  1828,
    1835,  1843,  1850,  1856,  1860,  1869,  1875,  1880,  1887,  1899,
    1911,  1930,  1949,  1962,  1975,  1988,  1999,  2010,  2021,  2032,
    2043,  2048,  2053,  2058,  2063,  2068,  2073,  2078,  2083,  2088,
    2091,  2095,  2102,  2104,  2106,  2108,  2111,  2117,  2125,  2136,
    2138,  2142,  2145,  2148,  2151,  2155,  2159,  2163,  2167,  2171,
    2175,  2179,  2183,  2187,  2191,  2195,  2199,  2203,  2207,  2211,
    2215,  2219,  2223,  2229,  2234,  2239,  2244,  2249,  2254,  2259,
    2264,  2269,  2274,  2279,  2286,  2291,  2296,  2301,  2306,  2311,
    2316,  2321,  2326,  2333,  2340,  2347,  2352,  2354,  2356,  2358,
    2360,  2362,  2364,  2366,  2368,  2370,  2372,  2374,  2375,  2382,
    2384,  2389,  2396,  2398,  2403,  2408,  2413,  2420,  2426,  2434,
    2439,  2444,  2451,  2456,  2460,  2463,  2469,  2475,  2479,  2485,
    2492,  2501,  2508,  2517,  2524,  2529,  2537,  2544,  2551,  2558,
    2563,  2570,  2575,  2576,  2579,  2580,  2583,  2584,  2592,  2594,
    2598,  2600,  2602,  2605,  2606,  2610,  2612,  2615,  2618,  2622,
    2626,  2638,  2648,  2656,  2664,  2666,  2670,  2672,  2674,  2677,
    2681,  2686,  2692,  2694,  2696,  2699,  2703,  2707,  2713,  2718,
    2721,  2724,  2727,  2730,  2734,  2738,  2742,  2746,  2763,  2780,
    2797,  2814,  2816,  2818,  2820,  2824,  2830,  2838,  2843,  2848,
    2853,  2860,  2867,  2876,  2885,  2890,  2905,  2910,  2915,  2917,
    2919,  2923,  2927,  2937,  2945,  2947,  2953,  2957,  2964,  2966,
    2970,  2972,  2974,  2979,  2984,  2988,  2994,  3001,  3010,  3017,
    3023,  3029,  3035,  3041,  3043,  3048,  3050,  3052,  3054,  3056,
    3061,  3068,  3073,  3080,  3086,  3094,  3099,  3104,  3109,  3118,
    3123,  3128,  3133,  3138,  3147,  3156,  3163,  3168,  3175,  3180,
    3182,  3187,  3192,  3193,  3200,  3205,  3208,  3213,  3218,  3220,
    3222,  3226,  3228,  3230,  3234,  3238,  3242,  3248,  3256,  3262,
    3268,  3277,  3279,  3281
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
     344,   239,   252,   348,     6,    -1,   358,   348,   242,   255,
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
     358,   247,   349,   273,     6,    -1,   358,   270,   341,     6,
      -1,   358,   271,     6,    -1,   358,   272,   273,   270,   341,
       6,    -1,   358,   272,   242,   344,   243,   273,   270,   341,
       6,    -1,   358,   240,   327,   241,   270,   327,     6,    -1,
     358,   240,   327,   241,   271,     6,    -1,   358,   238,   327,
     239,   270,   327,     6,    -1,   358,   238,   327,   239,   271,
       6,    -1,   358,     7,   349,     6,    -1,   358,   272,   273,
       7,    46,   272,   273,     6,    -1,   358,   272,   273,     7,
      46,   272,   353,   273,     6,    -1,   358,   272,   273,   214,
      46,   272,   353,   273,     6,    -1,   358,   244,     4,     7,
     349,     6,    -1,   358,   240,   327,   241,   244,     4,     7,
     349,     6,    -1,   358,   244,     4,   270,   327,     6,    -1,
     358,   240,   327,   241,   244,     4,   270,   327,     6,    -1,
     358,   244,     4,   271,     6,    -1,   358,   240,   327,   241,
     244,     4,   271,     6,    -1,   358,   244,   173,   244,     4,
       7,   345,     6,    -1,   358,   240,   327,   241,   244,   173,
     244,     4,     7,   345,     6,    -1,   358,   244,   174,     7,
     346,     6,    -1,   358,   240,   327,   241,   244,   174,     7,
     346,     6,    -1,   358,   184,     7,   327,     6,    -1,   184,
     240,   327,   241,     7,     4,     6,    -1,   184,   240,   327,
     241,   244,     4,     7,   327,     6,    -1,   184,   240,   327,
     241,   244,     4,     7,   349,     6,    -1,   184,   240,   327,
     241,   244,     4,     7,   242,   344,   243,     6,    -1,   184,
     240,   327,   241,   244,     4,     6,    -1,   129,   238,     4,
     239,   244,     4,     7,   327,     6,    -1,   129,   238,     4,
     239,   244,     4,     7,   349,     6,    -1,    -1,   247,    -1,
      -1,   276,   275,   358,    -1,   276,   275,   358,     7,   327,
      -1,    -1,   276,   275,   358,     7,   242,   341,   277,   282,
     243,    -1,    -1,   276,   275,   358,   272,   273,     7,   242,
     341,   278,   282,   243,    -1,   276,   275,   358,     7,   349,
      -1,    -1,   276,   275,   358,     7,   242,   349,   279,   286,
     243,    -1,    -1,   280,   275,   348,    -1,   327,     7,   349,
      -1,   281,   247,   327,     7,   349,    -1,   343,     7,   358,
     238,   239,    -1,    -1,   247,   284,    -1,    -1,   284,    -1,
     285,    -1,   284,   247,   285,    -1,     4,   341,    -1,     4,
      -1,     4,   242,   281,   243,    -1,     4,   349,    -1,     4,
     352,    -1,    -1,   247,   287,    -1,   288,    -1,   287,   247,
     288,    -1,     4,   327,    -1,     4,   349,    -1,   188,   349,
      -1,     4,   354,    -1,     4,   352,    -1,   327,    -1,   349,
      -1,   349,   247,   327,    -1,   327,    -1,   349,    -1,   349,
     247,   327,    -1,   327,    -1,   349,    -1,   349,   247,   327,
      -1,   327,    -1,   349,    -1,   349,   247,   327,    -1,    -1,
     176,    95,   242,   327,   243,    -1,    -1,   122,   338,    -1,
      91,   238,   327,   239,     7,   338,     6,    -1,    94,   238,
     327,   239,     7,   341,     6,    -1,    98,   238,   327,   239,
       7,   341,     6,    -1,    92,   238,   327,   239,     7,   341,
     294,     6,    -1,    93,   238,   327,   239,     7,   341,   294,
       6,    -1,   168,   238,   327,   239,     7,   341,     6,    -1,
     169,   238,   327,   239,     7,   341,     6,    -1,   170,   238,
     327,   239,     7,   341,   172,   341,   171,   327,     6,    -1,
     126,    94,   238,   327,   239,     7,   341,     6,    -1,   109,
     238,   327,   239,     7,   341,     6,    -1,    94,     4,   238,
     327,   239,     7,   341,     6,    -1,   122,    97,   238,   327,
     239,     7,   341,     6,    -1,    97,   238,   327,   239,     7,
     341,   293,     6,    -1,   123,    97,   238,   327,   239,     7,
     341,   293,     6,    -1,    13,    14,     6,    -1,    14,    97,
     327,     6,    -1,   112,    97,   238,   327,   239,     7,     5,
       5,     5,     6,    -1,    95,   238,   327,   239,     7,   341,
       6,    -1,    96,   238,   327,   239,     7,   341,     6,    -1,
     100,   238,   327,   239,     7,   341,     6,    -1,   103,   238,
     327,   239,     7,   341,     6,    -1,   107,   238,   327,   239,
       7,   341,     6,    -1,   108,   238,   327,   239,     7,   341,
       6,    -1,   101,   238,   327,   239,     7,   341,     6,    -1,
     102,   238,   327,   239,     7,   341,     6,    -1,   119,   238,
     327,   239,     7,   341,     6,    -1,   144,   238,   327,   239,
       7,   341,     6,    -1,   126,    97,   238,   327,   239,     7,
     341,     6,    -1,   126,    97,   238,   327,   239,     7,   341,
       4,   242,   340,   243,     6,    -1,    97,     4,   238,   327,
     239,     7,   341,     6,    -1,    99,   238,   327,   239,     7,
     341,     6,    -1,   118,   238,   327,   239,     7,   341,     6,
      -1,   123,   118,   238,   327,   239,     7,   341,     6,    -1,
     126,    99,   238,   327,   239,     7,   341,     6,    -1,   125,
      91,   238,   289,   239,   270,   341,     6,    -1,   125,    94,
     238,   290,   239,   270,   341,     6,    -1,   125,    97,   238,
     291,   239,   270,   341,     6,    -1,   125,    99,   238,   292,
     239,   270,   341,     6,    -1,   133,   338,   242,   297,   243,
      -1,   132,   242,   338,   247,   338,   247,   327,   243,   242,
     297,   243,    -1,   134,   338,   242,   297,   243,    -1,   135,
     242,   338,   247,   327,   243,   242,   297,   243,    -1,   135,
     242,   338,   247,   338,   243,   242,   297,   243,    -1,     4,
     242,   297,   243,    -1,   150,    94,   242,   344,   243,    97,
     242,   327,   243,    -1,   147,    94,   238,   327,   239,   242,
     344,   243,     6,    -1,   298,    -1,   296,    -1,    -1,   298,
     295,    -1,   298,    91,   242,   344,   243,     6,    -1,   298,
      94,   242,   344,   243,     6,    -1,   298,    97,   242,   344,
     243,     6,    -1,   298,    99,   242,   344,   243,     6,    -1,
     137,   122,   238,   327,   239,     7,   341,     6,    -1,   137,
      91,   238,   327,   239,     7,   242,   340,   243,     6,    -1,
     137,   122,   238,   327,   239,     7,   242,   338,   247,   338,
     247,   344,   243,     6,    -1,   137,   122,   238,   327,   239,
       7,   242,   338,   247,   338,   247,   338,   247,   344,   243,
       6,    -1,   137,    95,   238,   327,   239,     7,   242,   338,
     247,   344,   243,     6,    -1,   137,   101,   238,   327,   239,
       7,   242,   338,   247,   338,   247,   344,   243,     6,    -1,
     137,   102,   238,   327,   239,     7,   242,   338,   247,   338,
     247,   344,   243,     6,    -1,   137,   104,   238,   327,   239,
       7,   242,   338,   247,   338,   247,   344,   243,     6,    -1,
     137,   105,   238,   327,   239,     7,   242,   338,   247,   338,
     247,   344,   243,     6,    -1,   137,     4,   238,   327,   239,
       7,   341,     6,    -1,   137,     4,   238,   327,   239,     7,
       5,     6,    -1,   137,     4,   242,   327,   243,     6,    -1,
     148,   242,   298,   243,    -1,   131,   148,   242,   298,   243,
      -1,   148,   184,   240,   327,   241,     6,    -1,   148,     4,
     240,   327,   241,     6,    -1,   148,   358,     6,    -1,   148,
       4,     4,     6,    -1,   148,    84,     6,    -1,   173,   345,
     242,   298,   243,    -1,   131,   173,   345,   242,   298,   243,
      -1,   208,   327,   242,   298,   243,    -1,   189,     5,     6,
      -1,   190,     5,     6,    -1,   189,   242,   298,   243,    -1,
     131,   189,   242,   298,   243,    -1,   190,   242,   298,   243,
      -1,   131,   190,   242,   298,   243,    -1,   358,   349,     6,
      -1,    73,   238,   355,   239,     6,    -1,   358,   358,   240,
     327,   241,   348,     6,    -1,   358,   358,   358,   240,   327,
     241,     6,    -1,   358,   327,     6,    -1,   129,   238,     4,
     239,   244,     4,     6,    -1,   167,     4,     6,    -1,   182,
       6,    -1,   183,     6,    -1,    70,     6,    -1,    71,     6,
      -1,    64,     6,    -1,    64,   242,   327,   247,   327,   247,
     327,   247,   327,   247,   327,   247,   327,   243,     6,    -1,
      65,     6,    -1,    66,     6,    -1,    78,     6,    -1,    79,
       6,    -1,   114,     6,    -1,   115,   242,   344,   243,   242,
     344,   243,   242,   340,   243,   242,   327,   247,   327,   243,
       6,    -1,   187,   238,   242,   344,   243,   247,   349,   247,
     349,   239,     6,    -1,   175,   238,   327,     8,   327,   239,
      -1,   175,   238,   327,     8,   327,     8,   327,   239,    -1,
     175,     4,   176,   242,   327,     8,   327,   243,    -1,   175,
       4,   176,   242,   327,     8,   327,     8,   327,   243,    -1,
     177,    -1,   188,     4,    -1,   188,   349,    -1,   185,    -1,
     186,   358,     6,    -1,   186,   349,     6,    -1,   178,   238,
     327,   239,    -1,   179,   238,   327,   239,    -1,   180,    -1,
     181,    -1,   136,   338,   242,   298,   243,    -1,   136,   242,
     338,   247,   338,   247,   327,   243,   242,   298,   243,    -1,
     136,   242,   338,   247,   338,   247,   338,   247,   327,   243,
     242,   298,   243,    -1,    -1,   136,   338,   242,   298,   308,
     312,   243,    -1,    -1,   136,   242,   338,   247,   338,   247,
     327,   243,   242,   298,   309,   312,   243,    -1,    -1,   136,
     242,   338,   247,   338,   247,   338,   247,   327,   243,   242,
     298,   310,   312,   243,    -1,    -1,   136,   242,   298,   311,
     312,   243,    -1,   136,   242,   298,   243,   128,   109,   242,
     327,   243,    -1,   118,   341,    -1,   123,   118,   341,    -1,
     120,   242,   344,   243,   242,   344,   243,   242,   327,   243,
      -1,   313,    -1,   312,   313,    -1,   153,   242,   327,   243,
       6,    -1,   153,   242,   341,   247,   341,   243,     6,    -1,
     154,     6,    -1,   145,     6,    -1,   145,   327,     6,    -1,
     159,     6,    -1,   159,   161,     6,    -1,   160,     6,    -1,
     160,   161,     6,    -1,   155,   238,   327,   239,     7,   341,
     128,   327,     6,    -1,   128,     4,   240,   327,   241,     6,
      -1,   139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,
      -1,    -1,   148,     6,    -1,   131,   148,     6,    -1,   148,
     327,     6,    -1,   131,   148,   327,     6,    -1,   314,   242,
     298,   315,   243,   242,   298,   315,   243,    -1,   106,   238,
     348,   239,    -1,   314,   238,   327,   239,     7,   242,   298,
     315,   243,   242,   298,   315,   243,     6,    -1,    -1,   128,
       4,   327,    -1,    -1,     4,    -1,    -1,     7,   341,    -1,
      -1,     7,   327,    -1,    -1,   138,   341,    -1,   110,   111,
     341,     7,   327,     6,    -1,   124,    94,   342,     7,   327,
     318,     6,    -1,   124,    97,   342,   320,   319,     6,    -1,
     124,    99,   342,   320,     6,    -1,   162,   342,     6,    -1,
     151,    97,   242,   344,   243,     7,   327,     6,    -1,   145,
      97,   342,   321,     6,    -1,   145,    99,   342,     6,    -1,
     146,    97,   342,     7,   327,     6,    -1,   127,    94,   242,
     344,   243,     7,   242,   344,   243,   322,     6,    -1,   127,
      97,   242,   344,   243,     7,   242,   344,   243,   322,     6,
      -1,   127,    94,   242,   344,   243,     7,   242,   344,   243,
     132,   242,   338,   247,   338,   247,   327,   243,     6,    -1,
     127,    97,   242,   344,   243,     7,   242,   344,   243,   132,
     242,   338,   247,   338,   247,   327,   243,     6,    -1,   127,
      94,   242,   344,   243,     7,   242,   344,   243,   133,   338,
       6,    -1,   127,    97,   242,   344,   243,     7,   242,   344,
     243,   133,   338,     6,    -1,   127,    97,   327,   242,   344,
     243,     7,   327,   242,   344,   243,     6,    -1,    91,   242,
     344,   243,   176,    97,   242,   327,   243,     6,    -1,    94,
     242,   344,   243,   176,    97,   242,   327,   243,     6,    -1,
      91,   242,   344,   243,   176,    99,   242,   327,   243,     6,
      -1,    94,   242,   344,   243,   176,    99,   242,   327,   243,
       6,    -1,    97,   242,   344,   243,   176,    99,   242,   327,
     243,     6,    -1,   152,    97,   342,     6,    -1,   152,    94,
     342,     6,    -1,   116,    91,   342,     6,    -1,   116,    94,
     342,     6,    -1,   116,    97,   342,     6,    -1,   130,    94,
     341,     6,    -1,   126,    94,   341,     6,    -1,   126,    97,
     341,     6,    -1,   126,    99,   341,     6,    -1,   149,     6,
      -1,   149,     4,     6,    -1,   149,    91,   242,   344,   243,
       6,    -1,   197,    -1,   198,    -1,   199,    -1,   325,     6,
      -1,   325,   242,   341,   243,     6,    -1,   325,   242,   341,
     247,   341,   243,     6,    -1,   325,   238,   341,   239,   242,
     341,   247,   341,   243,     6,    -1,   328,    -1,   238,   327,
     239,    -1,   227,   327,    -1,   226,   327,    -1,   233,   327,
      -1,   327,   227,   327,    -1,   327,   226,   327,    -1,   327,
     228,   327,    -1,   327,   229,   327,    -1,   327,   231,   327,
      -1,   327,   232,   327,    -1,   327,   230,   327,    -1,   327,
     237,   327,    -1,   327,   220,   327,    -1,   327,   221,   327,
      -1,   327,   225,   327,    -1,   327,   224,   327,    -1,   327,
     219,   327,    -1,   327,   218,   327,    -1,   327,   217,   327,
      -1,   327,   216,   327,    -1,   327,   222,   327,    -1,   327,
     223,   327,    -1,   327,   215,   327,     8,   327,    -1,    16,
     272,   327,   273,    -1,    17,   272,   327,   273,    -1,    18,
     272,   327,   273,    -1,    19,   272,   327,   273,    -1,    20,
     272,   327,   273,    -1,    21,   272,   327,   273,    -1,    22,
     272,   327,   273,    -1,    23,   272,   327,   273,    -1,    24,
     272,   327,   273,    -1,    26,   272,   327,   273,    -1,    27,
     272,   327,   247,   327,   273,    -1,    28,   272,   327,   273,
      -1,    29,   272,   327,   273,    -1,    30,   272,   327,   273,
      -1,    31,   272,   327,   273,    -1,    32,   272,   327,   273,
      -1,    33,   272,   327,   273,    -1,    34,   272,   327,   273,
      -1,    35,   272,   327,   273,    -1,    36,   272,   327,   247,
     327,   273,    -1,    37,   272,   327,   247,   327,   273,    -1,
      38,   272,   327,   247,   327,   273,    -1,    25,   272,   327,
     273,    -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,
      12,    -1,   204,    -1,   205,    -1,   206,    -1,    75,    -1,
      76,    -1,    77,    -1,    -1,    83,   272,   327,   329,   282,
     273,    -1,   332,    -1,   195,   272,   348,   273,    -1,   195,
     272,   348,   247,   327,   273,    -1,   334,    -1,   358,   240,
     327,   241,    -1,   358,   238,   327,   239,    -1,   200,   238,
     334,   239,    -1,   200,   238,   334,   244,   335,   239,    -1,
     202,   238,   334,   330,   239,    -1,   202,   238,   334,   244,
     335,   330,   239,    -1,   201,   238,   349,   239,    -1,   245,
     358,   272,   273,    -1,   245,   334,   244,   335,   272,   273,
      -1,    86,   272,   358,   273,    -1,    86,   272,   273,    -1,
     358,   271,    -1,   358,   240,   327,   241,   271,    -1,   358,
     238,   327,   239,   271,    -1,   358,   244,   335,    -1,   358,
       9,   358,   244,   335,    -1,   358,   244,   335,   238,   327,
     239,    -1,   358,     9,   358,   244,   335,   238,   327,   239,
      -1,   358,   244,   335,   240,   327,   241,    -1,   358,     9,
     358,   244,   335,   240,   327,   241,    -1,   358,   240,   327,
     241,   244,     4,    -1,   358,   244,     4,   271,    -1,   358,
     240,   327,   241,   244,     4,   271,    -1,   191,   238,   348,
     247,   327,   239,    -1,    56,   238,   341,   247,   341,   239,
      -1,    57,   272,   348,   247,   348,   273,    -1,    55,   272,
     348,   273,    -1,    58,   272,   348,   247,   348,   273,    -1,
      63,   238,   355,   239,    -1,    -1,   247,   327,    -1,    -1,
     247,   348,    -1,    -1,    84,   334,   337,   333,   240,   283,
     241,    -1,   358,    -1,   358,     9,   358,    -1,     4,    -1,
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
     358,   272,   273,    -1,   358,   244,   335,   272,   273,    -1,
     358,     9,   358,   244,   335,   272,   273,    -1,    39,   240,
     358,   241,    -1,    39,   240,   343,   241,    -1,    39,   238,
     343,   239,    -1,    39,   272,   242,   344,   243,   273,    -1,
     358,   272,   242,   344,   243,   273,    -1,    40,   272,   327,
     247,   327,   247,   327,   273,    -1,    41,   272,   327,   247,
     327,   247,   327,   273,    -1,    42,   272,   348,   273,    -1,
      43,   272,   327,   247,   327,   247,   327,   247,   327,   247,
     327,   247,   327,   273,    -1,   196,   272,   343,   273,    -1,
      32,   272,   343,   273,    -1,   327,    -1,   343,    -1,   344,
     247,   327,    -1,   344,   247,   343,    -1,   242,   327,   247,
     327,   247,   327,   247,   327,   243,    -1,   242,   327,   247,
     327,   247,   327,   243,    -1,   358,    -1,     4,   244,   173,
     244,     4,    -1,   242,   347,   243,    -1,   358,   240,   327,
     241,   244,   174,    -1,   345,    -1,   347,   247,   345,    -1,
     349,    -1,   358,    -1,   358,   240,   327,   241,    -1,   358,
     238,   327,   239,    -1,   358,   244,   335,    -1,   358,     9,
     358,   244,   335,    -1,   358,   244,   335,   238,   327,   239,
      -1,   358,     9,   358,   244,   335,   238,   327,   239,    -1,
     358,   240,   327,   241,   244,     4,    -1,   125,    91,   242,
     327,   243,    -1,   125,    94,   242,   327,   243,    -1,   125,
      97,   242,   327,   243,    -1,   125,    99,   242,   327,   243,
      -1,     5,    -1,   209,   240,   358,   241,    -1,    67,    -1,
     207,    -1,    72,    -1,    74,    -1,   193,   238,   348,   239,
      -1,   192,   238,   348,   247,   348,   239,    -1,   194,   272,
     348,   273,    -1,   194,   272,   348,   247,   348,   273,    -1,
     203,   238,   334,   331,   239,    -1,   203,   238,   334,   244,
     335,   331,   239,    -1,    48,   272,   355,   273,    -1,    49,
     238,   348,   239,    -1,    50,   238,   348,   239,    -1,    51,
     238,   348,   247,   348,   247,   348,   239,    -1,    46,   272,
     355,   273,    -1,    60,   272,   348,   273,    -1,    61,   272,
     348,   273,    -1,    62,   272,   348,   273,    -1,    59,   272,
     327,   247,   348,   247,   348,   273,    -1,    54,   272,   348,
     247,   327,   247,   327,   273,    -1,    54,   272,   348,   247,
     327,   273,    -1,    47,   272,   348,   273,    -1,    47,   272,
     348,   247,   344,   273,    -1,    68,   272,   348,   273,    -1,
      69,    -1,    53,   272,   348,   273,    -1,    52,   272,   348,
     273,    -1,    -1,    88,   272,   349,   350,   286,   273,    -1,
      85,   272,   351,   273,    -1,   245,   327,    -1,   358,     9,
     245,   327,    -1,    46,   272,   354,   273,    -1,   355,    -1,
     354,    -1,   242,   355,   243,    -1,   348,    -1,   356,    -1,
     355,   247,   348,    -1,   355,   247,   356,    -1,   358,   238,
     239,    -1,   358,   244,   335,   238,   239,    -1,   358,     9,
     358,   244,   335,   238,   239,    -1,     4,   246,   242,   327,
     243,    -1,   357,   246,   242,   327,   243,    -1,   210,   240,
     348,   241,   246,   242,   327,   243,    -1,     4,    -1,   357,
      -1,   210,   240,   348,   241,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   265,   265,   266,   271,   273,   277,   278,   279,   280,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   318,   322,   329,   334,
     339,   353,   366,   379,   407,   421,   434,   447,   466,   471,
     472,   473,   474,   475,   479,   481,   486,   488,   494,   598,
     493,   616,   623,   634,   633,   651,   658,   669,   668,   685,
     702,   725,   724,   738,   739,   740,   741,   742,   746,   747,
     753,   753,   754,   754,   760,   761,   762,   763,   768,   774,
     836,   851,   880,   890,   895,   903,   908,   916,   925,   930,
     942,   959,   965,   974,   992,  1010,  1019,  1031,  1036,  1044,
    1064,  1087,  1098,  1106,  1128,  1151,  1189,  1210,  1222,  1236,
    1236,  1238,  1240,  1249,  1259,  1258,  1279,  1278,  1296,  1306,
    1305,  1319,  1321,  1329,  1335,  1340,  1366,  1368,  1371,  1373,
    1377,  1378,  1382,  1394,  1407,  1422,  1431,  1444,  1446,  1450,
    1451,  1456,  1464,  1473,  1481,  1495,  1513,  1517,  1524,  1532,
    1536,  1543,  1551,  1555,  1562,  1570,  1574,  1581,  1590,  1593,
    1600,  1603,  1610,  1634,  1650,  1666,  1703,  1743,  1759,  1775,
    1797,  1807,  1823,  1840,  1856,  1877,  1888,  1894,  1900,  1907,
    1938,  1953,  1975,  1998,  2021,  2044,  2068,  2092,  2115,  2140,
    2150,  2173,  2190,  2206,  2224,  2242,  2252,  2264,  2276,  2288,
    2305,  2321,  2337,  2352,  2369,  2386,  2421,  2443,  2467,  2468,
    2473,  2476,  2480,  2491,  2502,  2513,  2529,  2548,  2569,  2584,
    2600,  2618,  2669,  2690,  2712,  2735,  2840,  2856,  2891,  2902,
    2913,  2919,  2934,  2962,  2974,  2983,  2990,  3002,  3021,  3027,
    3033,  3040,  3047,  3054,  3066,  3139,  3157,  3174,  3189,  3222,
    3234,  3258,  3262,  3267,  3274,  3279,  3289,  3294,  3300,  3308,
    3312,  3316,  3325,  3389,  3405,  3422,  3439,  3461,  3483,  3518,
    3526,  3534,  3540,  3547,  3554,  3574,  3600,  3612,  3624,  3642,
    3660,  3679,  3678,  3703,  3702,  3729,  3728,  3753,  3752,  3775,
    3791,  3808,  3825,  3848,  3851,  3857,  3869,  3889,  3893,  3897,
    3901,  3905,  3909,  3913,  3917,  3926,  3939,  3940,  3941,  3942,
    3943,  3947,  3948,  3949,  3950,  3951,  3954,  3977,  3996,  4018,
    4021,  4037,  4040,  4057,  4060,  4066,  4069,  4076,  4079,  4086,
    4103,  4144,  4188,  4227,  4252,  4261,  4291,  4317,  4343,  4375,
    4402,  4428,  4454,  4480,  4506,  4528,  4534,  4540,  4546,  4552,
    4558,  4584,  4610,  4627,  4644,  4661,  4673,  4679,  4685,  4697,
    4701,  4711,  4722,  4723,  4724,  4728,  4734,  4746,  4764,  4792,
    4793,  4794,  4795,  4796,  4797,  4798,  4799,  4800,  4807,  4808,
    4809,  4810,  4811,  4812,  4813,  4814,  4815,  4816,  4817,  4818,
    4819,  4820,  4821,  4822,  4823,  4824,  4825,  4826,  4827,  4828,
    4829,  4830,  4831,  4832,  4833,  4834,  4835,  4836,  4837,  4838,
    4839,  4840,  4841,  4842,  4843,  4844,  4853,  4854,  4855,  4856,
    4857,  4858,  4859,  4860,  4861,  4862,  4863,  4868,  4867,  4875,
    4877,  4882,  4887,  4891,  4896,  4901,  4905,  4909,  4913,  4917,
    4923,  4939,  4944,  4950,  4956,  4975,  4996,  5029,  5033,  5038,
    5042,  5046,  5050,  5055,  5060,  5070,  5080,  5085,  5096,  5105,
    5110,  5115,  5143,  5144,  5150,  5151,  5157,  5156,  5179,  5181,
    5186,  5195,  5197,  5203,  5204,  5210,  5214,  5218,  5222,  5226,
    5233,  5237,  5241,  5245,  5252,  5257,  5264,  5269,  5273,  5278,
    5282,  5290,  5301,  5305,  5317,  5325,  5333,  5340,  5350,  5373,
    5379,  5385,  5391,  5397,  5408,  5419,  5430,  5441,  5447,  5453,
    5459,  5465,  5475,  5485,  5495,  5508,  5512,  5518,  5530,  5534,
    5538,  5542,  5560,  5568,  5576,  5605,  5615,  5631,  5642,  5647,
    5651,  5655,  5667,  5671,  5683,  5700,  5710,  5714,  5729,  5734,
    5741,  5745,  5750,  5764,  5781,  5785,  5790,  5794,  5799,  5807,
    5813,  5819,  5825,  5834,  5838,  5842,  5850,  5856,  5862,  5866,
    5874,  5882,  5889,  5899,  5904,  5909,  5924,  5938,  5952,  5964,
    5980,  5989,  5998,  6008,  6019,  6027,  6035,  6039,  6058,  6065,
    6071,  6078,  6086,  6085,  6095,  6119,  6121,  6127,  6132,  6134,
    6139,  6144,  6149,  6151,  6155,  6167,  6182,  6187,  6196,  6205,
    6214,  6226,  6229,  6233
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
  "tSTRING_Member", "Append", "AppendOrNot", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@15",
  "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
  "BracedOrNotRecursiveListOfStringExprVar",
  "BracedRecursiveListOfStringExprVar", "RecursiveListOfStringExprVar",
  "MultiStringExprVar", "StringIndex", "String__Index", 0
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
     284,   284,   285,   285,   285,   285,   285,   286,   286,   287,
     287,   288,   288,   288,   288,   288,   289,   289,   289,   290,
     290,   290,   291,   291,   291,   292,   292,   292,   293,   293,
     294,   294,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   297,   297,
     298,   298,   298,   298,   298,   298,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   300,   300,
     300,   300,   300,   300,   300,   301,   301,   302,   303,   303,
     303,   303,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   305,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   307,
     307,   308,   307,   309,   307,   310,   307,   311,   307,   307,
     307,   307,   307,   312,   312,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   314,   314,   314,   314,
     314,   315,   315,   315,   315,   315,   316,   316,   317,   318,
     318,   319,   319,   320,   320,   321,   321,   322,   322,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   324,
     324,   324,   325,   325,   325,   326,   326,   326,   326,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   329,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   330,   330,   331,   331,   333,   332,   334,   334,
     335,   336,   336,   337,   337,   338,   338,   338,   338,   338,
     339,   339,   339,   339,   340,   340,   341,   341,   341,   341,
     341,   341,   342,   342,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   344,   344,
     344,   344,   345,   345,   345,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   350,   349,   349,   351,   351,   352,   353,   353,
     354,   355,   355,   355,   355,   356,   356,   356,   357,   357,
     357,   358,   358,   358
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
       1,     3,     2,     1,     4,     2,     2,     0,     2,     1,
       3,     2,     2,     2,     2,     2,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     3,     0,     5,
       0,     2,     7,     7,     7,     8,     8,     7,     7,    11,
       8,     7,     8,     8,     8,     9,     3,     4,    10,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     8,
      12,     8,     7,     7,     8,     8,     8,     8,     8,     8,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,    14,    14,    14,    14,     8,     8,     6,     4,     5,
       6,     6,     3,     4,     3,     5,     6,     5,     3,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,     2,    15,     2,     2,     2,
       2,     2,    16,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       2,     3,    10,     1,     2,     5,     7,     2,     2,     3,
       2,     3,     2,     3,     9,     6,     1,     1,     1,     1,
       1,     0,     2,     3,     3,     4,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     6,
       7,     6,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,    10,    10,    10,    10,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     5,     7,     4,
       4,     6,     4,     3,     2,     5,     5,     3,     5,     6,
       8,     6,     8,     6,     4,     7,     6,     6,     6,     4,
       6,     4,     0,     2,     0,     2,     0,     7,     1,     3,
       1,     1,     2,     0,     3,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     3,     3,     3,     3,    16,    16,    16,
      16,     1,     1,     1,     3,     5,     7,     4,     4,     4,
       6,     6,     8,     8,     4,    14,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     8,     6,     5,
       5,     5,     5,     1,     4,     1,     1,     1,     1,     4,
       6,     4,     6,     5,     7,     4,     4,     4,     8,     4,
       4,     4,     4,     8,     8,     6,     4,     6,     4,     1,
       4,     4,     0,     6,     4,     2,     4,     4,     1,     1,
       3,     1,     1,     3,     3,     3,     5,     7,     5,     5,
       8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   307,   308,   309,   310,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,     0,   276,   277,     0,     0,     0,   271,     0,     0,
       0,     0,     0,   362,   363,   364,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   602,     0,   210,     0,     0,     0,     0,     0,   255,
       0,   257,   258,   253,   254,     0,   259,   260,   111,   121,
     601,   473,   468,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,     0,   416,   417,   419,
     420,   418,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   424,   425,   426,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,   422,   423,     0,     0,     0,     0,
       0,     0,   511,   512,     0,   513,   486,   369,   429,   432,
     290,   487,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,     0,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601,     0,     0,   210,     0,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,   492,     0,     0,
       0,     0,     0,   601,     0,     0,   534,     0,     0,     0,
       0,   251,   252,     0,   553,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   555,     0,
     579,   557,   558,     0,     0,     0,     0,     0,     0,   556,
       0,     0,     0,     0,   269,   270,     0,   210,     0,   210,
       0,     0,     0,   468,     0,     0,   210,   365,     0,     0,
      76,     0,    63,     0,     0,    67,    66,    65,    64,    69,
      68,    70,    71,     0,     0,     0,     0,     0,     0,   540,
     468,     0,   209,     0,   208,     0,   176,     0,     0,   540,
     541,     0,     0,   591,     0,   592,   541,   109,   109,     0,
     466,     0,     0,     0,     0,     0,   528,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,     0,     0,   500,     0,   501,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   372,     0,   371,   494,   373,     0,   488,
       0,     0,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,     0,   444,     0,     0,
       0,     0,     0,     0,   291,     0,   323,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,     0,   210,   210,     0,   477,   476,
       0,     0,     0,     0,   210,   210,     0,     0,     0,     0,
     287,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   325,     0,     0,     0,     0,     0,   234,
       0,     0,   232,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   333,   250,     0,     0,     0,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   272,     0,
     238,     0,   239,     0,     0,   371,     0,   210,     0,     0,
       0,     0,     0,     0,   311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    72,    73,     0,     0,   248,    38,   244,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,   211,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,   471,     0,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
       0,     0,     0,     0,     0,     0,   352,   353,   354,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   468,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   427,   443,
       0,     0,     0,     0,     0,     0,   503,   504,   505,   506,
       0,     0,     0,     0,     0,   462,     0,   370,   489,     0,
       0,   496,     0,   389,   388,   387,   386,   382,   383,   390,
     391,   385,   384,   375,   374,     0,   376,   495,   377,   380,
     378,   379,   381,   469,     0,     0,   470,   447,     0,   514,
       0,     0,     0,     0,     0,     0,     0,   321,     0,     0,
     146,   147,     0,   149,   150,     0,   152,   153,     0,   155,
     156,     0,   356,     0,   357,     0,   358,     0,     0,     0,
       0,   355,     0,   210,     0,     0,     0,     0,     0,   479,
     478,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,   233,     0,     0,   228,     0,     0,
       0,   351,   350,     0,     0,     0,   370,     0,     0,     0,
       0,     0,     0,     0,     0,   274,   275,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   582,     0,     0,     0,   464,
       0,     0,   240,   242,     0,   376,     0,   469,   447,   603,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,   370,     0,    63,     0,     0,     0,
       0,    79,     0,    63,    64,     0,     0,   469,     0,     0,
     447,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,    28,    26,    27,     0,     0,     0,     0,     0,
     470,   544,    29,     0,     0,   245,   593,   594,     0,   595,
     544,    74,   112,    75,   122,   472,   474,   128,     0,     0,
       0,     0,   530,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   415,   402,     0,   404,
     405,   406,   407,   408,   527,   409,   410,   411,     0,     0,
       0,   519,   518,   517,     0,     0,     0,   524,     0,   459,
       0,     0,     0,   461,   126,   442,     0,   498,     0,     0,
       0,     0,     0,   430,   526,   435,     0,   439,     0,     0,
       0,   490,     0,     0,   440,     0,     0,     0,     0,   434,
     433,   454,    70,    71,     0,     0,     0,     0,     0,     0,
     370,   319,   324,   322,     0,   332,     0,     0,     0,     0,
       0,     0,     0,     0,   370,   370,   370,     0,     0,     0,
       0,   229,     0,   241,   243,     0,     0,     0,   200,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,     0,     0,     0,     0,   569,     0,   576,
     565,   566,   567,     0,   581,   580,     0,     0,   570,   571,
     572,   578,   585,   584,     0,   137,     0,   559,     0,   561,
       0,     0,     0,   554,     0,   237,     0,     0,     0,     0,
       0,     0,   312,     0,     0,     0,   366,     0,   599,     0,
       0,     0,     0,   101,    63,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,    61,     0,    39,    40,    41,
      42,    43,     0,   434,   433,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
     542,     0,     0,     0,     0,     0,     0,     0,   133,     0,
     129,   130,     0,     0,     0,     0,     0,   160,   160,     0,
       0,     0,     0,     0,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,   463,   437,     0,     0,   497,   392,   491,   448,   446,
       0,   445,     0,     0,   515,     0,     0,     0,     0,     0,
       0,     0,     0,   331,     0,   148,     0,   151,     0,   154,
       0,   157,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,     0,     0,     0,     0,   298,     0,     0,
     297,     0,   300,     0,   302,     0,   288,   294,     0,     0,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
     337,     0,   231,   230,   361,     0,     0,    35,    36,     0,
       0,     0,     0,   535,     0,     0,     0,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   563,     0,   448,     0,   210,   313,     0,   314,   210,
       0,     0,   549,   550,   551,   552,     0,    86,     0,     0,
       0,     0,    84,    91,    93,     0,   538,     0,    99,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,    34,
     448,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,   545,     0,     0,
      32,     0,   545,   596,     0,   113,   118,     0,     0,     0,
     132,   135,   136,   467,     0,    77,    78,   162,     0,     0,
       0,     0,     0,     0,   163,     0,     0,   179,   180,     0,
       0,     0,     0,   164,   192,   181,   185,   186,   182,   183,
     184,   171,     0,     0,   403,   412,   413,   414,   520,     0,
       0,     0,   457,   458,   460,   127,   428,     0,     0,     0,
       0,   456,   431,   436,     0,   193,   441,    70,    71,     0,
     453,   449,   451,   521,   187,     0,     0,   158,     0,     0,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,   210,   210,     0,     0,
     299,   486,     0,     0,   301,   303,     0,     0,   282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
       0,     0,     0,     0,   167,   168,     0,     0,     0,     0,
     102,   106,     0,   577,     0,     0,   575,     0,   586,     0,
       0,   138,   139,   583,   560,   562,     0,     0,     0,     0,
       0,   311,   315,   311,     0,   367,    85,    63,     0,     0,
       0,     0,    83,     0,   536,     0,     0,     0,     0,     0,
       0,   589,   588,     0,     0,     0,     0,     0,   484,     0,
       0,   453,   246,   449,   247,   212,   213,   214,   215,     0,
       0,     0,     0,     0,     0,   548,   546,     0,     0,   114,
     119,     0,     0,     0,   528,   529,   131,     0,     0,   161,
     165,   166,   172,     0,     0,   191,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   438,     0,
       0,   516,   455,     0,   173,     0,   194,   320,   196,   197,
     198,   199,   170,     0,   189,   195,     0,     0,     0,     0,
       0,     0,   483,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   225,     0,     0,     0,     0,
       0,     0,     0,     0,   216,     0,     0,   334,    37,     0,
     533,     0,     0,   266,   265,     0,     0,     0,     0,     0,
       0,   141,   142,   145,   144,   143,     0,   564,     0,   600,
       0,     0,     0,     0,     0,    96,     0,     0,    97,   539,
       0,     0,     0,    88,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    46,     0,    33,     0,     0,   597,   126,
     137,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   522,   523,     0,     0,     0,
       0,     0,   450,   452,     0,   175,     0,   327,   327,     0,
     107,   108,   210,     0,   203,   204,   289,     0,   295,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
     207,   206,     0,     0,     0,     0,   103,   104,   568,   574,
     573,   140,     0,     0,   316,     0,    92,    94,     0,   100,
       0,    82,   590,    89,    90,    49,     0,     0,     0,     0,
     485,     0,     0,   450,   547,     0,     0,     0,   116,   587,
       0,   123,     0,   345,   347,   346,   348,     0,   349,   178,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,   305,
       0,     0,   283,     0,   217,     0,     0,     0,     0,     0,
       0,     0,   532,   267,     0,     0,   210,   368,     0,   537,
       0,    45,     0,     0,     0,    62,    47,     0,   115,   120,
     126,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   328,   338,     0,     0,   339,     0,   201,
       0,   296,     0,   279,     0,   210,     0,     0,     0,     0,
       0,     0,   169,   105,   263,   311,    98,     0,     0,     0,
       0,     0,     0,   124,   125,     0,     0,     0,     0,     0,
       0,   190,     0,   342,     0,   343,   344,   480,     0,     0,
     285,   220,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    59,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,   304,   284,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     222,   223,   224,     0,   218,   318,    50,     0,    57,     0,
     256,     0,   525,     0,     0,     0,     0,     0,     0,   286,
       0,     0,    51,     0,     0,   262,     0,     0,     0,     0,
       0,     0,   219,     0,     0,     0,     0,   507,   508,   509,
     510,     0,     0,    54,    52,     0,    55,     0,   340,   341,
       0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1035,   109,   110,  1016,  1866,  1872,
    1307,  1524,  2020,  2161,  1308,  2126,  2185,  1309,  2163,  1310,
    1311,  1528,   404,   557,   558,  1103,   111,   740,   427,  1879,
    2030,  1880,   428,  1753,  1382,  1339,  1340,  1341,  1486,  1691,
    1692,   879,   882,   885,   888,  1581,  1571,   721,   252,   413,
     414,   114,   115,   116,   117,   118,   119,   120,   121,   253,
    1204,  2054,  2117,   916,  1200,  1201,   254,   993,   255,   125,
    1412,  1164,   877,   930,  1991,   126,   127,   128,   129,   256,
     257,  1124,  1140,  1262,   258,   745,   259,   867,   744,   430,
     589,   292,  1727,   327,   328,   261,   530,   335,  1295,  1517,
     423,   419,  1255,   973,  1562,  1720,  1721,   958,   425,   131,
     383
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1847
static const yytype_int16 yypact[] =
{
   10909,    19,    73, 11059, -1847, -1847,   149,    97,   -60,   -88,
     -81,    29,   188,   197,   287,   320,   -53,   332,   355,   137,
     162,    12,  -153,  -153,   -14,   151,   170,    37,   175,   285,
      45,   304,   309,   315,   330,   342,   349,   376,   393,   398,
     420,   492,   571,   668,   440,   336,   447,  6024,   454,   475,
     658,   -55,   120,   573,   519,   -22,   488,   667,  -112,   498,
     138,   138,   527,   234,   380, -1847, -1847, -1847, -1847, -1847,
     528,   248,   679,   687,    20,    41,   706,   685,   395,   812,
     820,   827,  5298,   846,   631,   644,   654,     8,    39, -1847,
     677,   710, -1847, -1847,   845,   853,   637, -1847, 11256,   720,
   11286,    15,    21, -1847, -1847, -1847, 10739,   725, -1847, -1847,
   -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847,
   -1847, -1847, -1847,    -1, -1847, -1847, -1847, -1847,     7, -1847,
     915,   696,  5051,   333,   724,   965, 10739, 11226, 11226, -1847,
   10739, -1847, -1847, -1847, -1847, 11226, -1847, -1847, -1847, -1847,
     744,   734,   982, -1847, -1847, 11316,    12, 10739,  9178, 10739,
   10739,   776, 10739,  9178, 10739, 10739,   778, 10739,  9178, 10739,
   10739, 10739, 10739, 10739, 10739, 11226, 10739, 10739, 10739,  6260,
     800, -1847,  9178,  5298,  5298,  5298, 11226, -1847, -1847, -1847,
   -1847, -1847,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,   184,  -153,  -153,  -153,  -153,
    -153,   801,  -153,  -153,   807, -1847, -1847, -1847,  -153,  -153,
       1,    22,    23,    24,  6260,   874,   630,   810,  -153,  -153,
     811,   813,   814, -1847, -1847, -1847, 10739,  6496, 10739, 10739,
    6732,    12, -1847, -1847,   758, -1847,  4245, -1847, -1847, -1847,
   -1847, -1847,   134, 10739,  9178,   815,   818,  6968,  5298,  5298,
    5298,   819,   821,   822,   825,  7204,  7440,  7676,   766,  9495,
     994,  6260,   808,     8,   816,   823,   138,   138,   138, 10739,
   10739,   140, -1847,   232,   138,  9731,   314,   266,   830,   832,
     842,   843,   856,   857,   858, 10739,  5298,  5298,  5298,   863,
       6,  1077,   862, -1847,  1097,  1098, -1847,   866,   867,   869,
    5298,  5298,   873,   875,   876, -1847, 10739, -1847,  1108,  1114,
   10739, 10739, 10739,   185, 10739,   879, -1847,   946, 10739, 10739,
   10739, -1847, -1847, 10739, -1847,  -153,  -153,  -153,   886,   887,
     889,  -153,  -153,  -153,  -153,  -153,  -153,  -153, -1847,  -153,
   -1847, -1847, -1847,  -153,  -153,   890,   891,  -153,   892, -1847,
     893,  1125,  1126,   894, -1847, -1847,  1128, -1847,  1129, -1847,
    -153, 10739, 13753,   152, 11226, 10739, -1847, -1847,  6260,  6260,
   -1847,   895, 11316,   639,  1131, -1847, -1847, -1847, -1847, -1847,
   -1847, 10739, 10739,    34,  6260,  1134,   452,  1784,   899,  1136,
      46,   901, -1847,   902,  2014, 10739, -1847,  2029,  -183, -1847,
      91,  -106,  8655, -1847,   -83, -1847,    92,  -139,  -103,  1057,
   -1847,    12,   900,   903,  8050,  9178,  4284, -1847,   282, 14269,
   14294, 10739, 14319,   296, 14344, 14369, 10739, 14394,   394, 14419,
   14444, 14469, 14494, 14519, 14544,   907, 14569, 14594, 14619,  1141,
   10739,   464,  1143,  1145,  1146,   916, 10739, 10739, 10739, 10739,
   10739, 10739, 10739, 10739, 10739, 10739, 10739, 10739, 10739, 10739,
   10739, 10739,  9178, 10739, 10739, 10739, 10739, 10739, 10739,  9178,
    9178,   917, 10739, 10739, 11226, 10739, 11226,  6260, 11226, 11226,
   11226, 10739,    82, -1847,  1093, 10739, -1847,  1094, -1847,  1096,
   -1847,  1100,  6260,  5298,  5298,  5298,  5298, 11226, 11226,  9178,
      12, 11316,    12,   924,  9178,   924, -1847,   924, 14644, -1847,
     473,   918,    60, 10739, 10739, 10739, 10739, 10739, 10739, 10739,
   10739, 10739, 10739, 10739, 10739, 10739, 10739,  7912, 10739, 10739,
   10739, 10739, 10739,    12, 10739, 10739,  1161, -1847,   805, 14669,
     513, 10739, 10739, 10739, -1847,  1159,  1160,  1160,  9409,  9409,
    9409,  9409, 10739,  1162, 10739,  1181, 10739,  1182,  9178,  9178,
   13781,   953,  1188, -1847,   956, -1847, -1847,  -167, -1847, -1847,
    9764,  9995,   138,   138,   333,   333,  -144,  9731,  9731, 10739,
    5103,  -135, -1847, 10739, 10739, 10739, 10739, 10739, 10739, 10739,
   10739, 10739, 14694,  1189,  1193,  1194, 10739,  1196, 10739, -1847,
   10739,  5619, -1847, -1847,  9178,  9178,  9178,  1197,  1198, 10739,
   10739, 10739, 14719, -1847, -1847, 14744, 14769, 14794,  1027, 10070,
   -1847,   963,  4483, 14819, 14844, 13864, 11226, 11226, 11226, 11226,
   11226, 11226, 11226, 11226, 11226, 10739, 11226, 11226, 11226, 11226,
      10, 11316, 11226, 11226, 11226,    12,    12, -1847, -1847,  9178,
   -1847,  5855, -1847,  6091, 10739,   924, 10739, -1847,    12, 10739,
   10739,  1161,   966, 14869,  7979,   967,   515, 10739,  1202,   968,
     970,   971,   972, 10739, 14894, 13891,   346,   973,  1208,  1203,
   -1847, -1847, -1847,  9178,   186, -1847, -1847, -1847,    12, 10739,
   10739,  1161,   976, -1847,   588,    47,    53,   605,   980,   -44,
     530, -1847, 12796, -1847,    11,  9178,    12, 10739, 10739,  1215,
    1214,  9178, 10739,  1216, 11226,    12,  9808,  1215,  1217, -1847,
      12,  1221, 11226, 10739,   989,   981, -1847, 10739, 11316,  1222,
    9178,  1060,  9178,  1226,  1230, 14919,  1239,  1073,  1243,  1244,
   14944,  1245,  1078,  1249,  1250,  1252,  1253,  1254,  1255, -1847,
    1256,  1257,  1258, 10739, 14969,  1024, -1847, -1847, -1847,  1261,
   13837, 13837, 13837, 13837, 13837, 13837, 13837, 13837, 13837, 13837,
   13837, 10303, 13837, 13837, 13837, 13837,   954,   262, 13837, 13837,
   13837, 10387, 10611, 11311,  4284,  1029,  1028,   108,  9178, 11344,
   11377,   262, 11410,   262,  1023,  1026,  1031,    -5, 15869, -1847,
     262,  1032, 12825,  1033,  1034,  1039, -1847, -1847, -1847, -1847,
    1035,  -171,   262,   -85,  1044,  -121,   606,  1264, -1847,  1215,
     262,  4747,  4941,   757,  1279,   567,   567,   609,   609,   609,
     609,   609,   609,   522,   522,  9178,   358, -1847,   358,   358,
     924,   924,   924,  1040, 14994, 13918,    80,   461,  9178, -1847,
    1278,  1045, 15019, 15044, 15069, 10739,  6260,  1282,  1283,  1049,
   15869,  1043,  1053, 15869,  1046,  1055, 15869,  1048,  1058, 15869,
    1051, 15094, -1847, 15119, -1847, 15144, -1847,   613,   614,  9178,
    1052, -1847,  6327, -1847,  6563,  6799,   138, 10739, 10739, -1847,
   -1847,  1056,  1059,  9731,  4047,  1172,    42,   138,  7035, 15169,
   12854, 15194, 15219, 15244, 15269, 15294, 15319, 15344,  1294, 10739,
    1298, -1847, 10739, 15369, -1847, 13945, 13972, -1847,   615,   621,
     624, -1847, -1847, 13999, 14026, 11443, -1847,  1299,  1300,  1301,
    1065, 10739,  7271, 10739, 10739, -1847, -1847,    32,  -126,  -111,
    -126,  1071,  1074,  1067,   262,   262,  1068, 11476,   262,   262,
     262,   262, 10739,   262,  1303, -1847,  1069,  1079,   -18,   429,
    1080,   627, -1847, -1847, 13837,   358,  7507,  1075,   468,  1076,
    1316,  1176, 10039,  1082,  1084,  1321,  6260, 12883, -1847, 10739,
   10739, 10739, 10739,  2615,   350,    98, 11316, 10739,  1322,  1325,
      28, -1847,   629,  1284,  1285,  6260,    26,  1088, 15394, 14053,
     118, 10739,  9178,  9178,  9178,  9178, 10739,  1095,  1099,  1101,
    1102, -1847, -1847, -1847, -1847, 11226,   136,  1090, 15419, 14080,
   -1847,  1103, -1847,   176, 11509, -1847, -1847, -1847,  1104, -1847,
    1105, -1847,    59, -1847, -1847, 15869, -1847,  1334, 13837,   262,
     138,   718,  4284, -1847,  6260,  6260,  1335,  6260,   726,  6260,
    6260,  1337,  6260,  1246,  6260,  6260,  6260,  6260,  6260,  6260,
    6260,  6260,  6260,  2656,  1340,  9178, -1847, -1847, -1847, -1847,
   -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847, 10739, -1847,
   -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847, 10739, 10739,
   10739, -1847, -1847, -1847,   632, 10739, 10739, -1847, 10739, -1847,
    6260, 11226, 11226, -1847,  1106, -1847, 10739, -1847, 10739, 10739,
   10739, 10739, 10739, -1847, -1847, -1847,  1215, -1847,  1215, 10739,
    1110, -1847,  6260,  -153, -1847, 10739, 10739,   640,  1215,    80,
     -73, -1847, 10739, 10739,   262,   641,  6260,  9178,  1344,  1347,
    1348,  8027, -1847, -1847,  1350, -1847,   198, 10739,   198, 10739,
     198, 10739,   198, 10739,  1351,  1352,  1353,  1354,  1355,   643,
    1359, -1847,  7743, -1847, -1847,  -120, 11542, 11575, -1847, -1847,
   12912,  -129,  1248,  1361, 10123,  1124,  1363,  1132,    17,    25,
      -8, -1847,   -78, -1847,    42,  1360,  1365,  1366,  1367,  1368,
    1369,  1371,  1373,  1374,  6260, 15869, -1847,  2759,  1130,  1377,
    1381,  1383,  1295,  1387,  1398,  1402, 10739,  6260,  6260,  6260,
    1405, 11608, -1847,  5240,  1342,  1406,  1408, -1847,  9178, -1847,
   -1847, -1847, -1847, 11226, -1847, -1847, 10739, 11226, -1847, -1847,
   -1847, -1847, 15869, -1847,  1169,  1171, 11226, -1847, 11226, -1847,
    1215, 11226,  1177, -1847,  1175, -1847,  1215, 10739, 10739,  1184,
    1185, 10354, -1847,  2799,  1186,  6260, -1847,  1180, -1847, 12941,
   12970, 12999, 13028, -1847, -1847, 10739,  1423,    36, 10739,  1424,
    1425,  2885, -1847,  1426,     8,  1428,  1192,   262,  -153,  -153,
    1431, -1847,  1200,  1204,  1201, -1847,  1434, -1847, -1847, -1847,
   -1847, -1847,  1215,   365,   760, 10739, 14107,   646,   648,   673,
     675, 15444, 10739, 10739, 10739, 10739,  1438,   133,  1215, -1847,
    1205, 10739,  1439, 10739,  1215, 10431,  8148,   262,  4547,  1207,
    1199, -1847,  1444,  1445,    13,  1210,  1211,  1332,  1332,  6260,
    1450,  1218,  1219,  1451,  1456,  6260,  1288,  1223,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468, -1847,  1470,   680,
   13837, 13837, 13837, 13837,   262, 11641, 11674, 11707,  1237,   262,
     262,  1334,   262, 11740, 11773, 11806, 11839, 15469, 13837,  1240,
    1231, 15869, -1847,  1474,   262, 15869, 15869, -1847,   505, -1847,
    1478, -1847, 15494, 14134, -1847,   262,  1477,   681,  6260,  6260,
    6260,  1480,  1479, -1847,  6260, 15869,  6260, 15869,  6260, 15869,
    6260, 15869,  6260,  6260,  6260,  1247,  1251,  1481,   448, -1847,
   10739, 10739, 10739,  1271,  1272,  1273,  1277, -1847,  3073,  6260,
   -1847, 10739, -1847,  1484, -1847,  1485, -1847, -1847,  9731,   524,
    5552, -1847,  1280,  1281,  1286,  1287,  1289,  1290,  8384,  1486,
   -1847,  9178, -1847, -1847, -1847,  1291, 10739, -1847, -1847, 14161,
    1488,  1489,  1314, -1847, 10739, 10739, 10739, -1847,  1514,   457,
      67,  1292,  8320,  1293, 10739,    18,   262,  1297,   262,  1305,
   -1847, -1847, 11316,   563, 10739, -1847, -1847,  3115, -1847, -1847,
    1306,  1519, -1847, -1847, -1847, -1847,  3173, -1847,   397,  1302,
    1520,  3203, -1847, -1847, -1847,     8, -1847,   683, -1847, 10739,
     198,  1038,  1840, -1847,  1296, 10739, 10739,  6260,  1312, -1847,
     506,  1483,  1524, 15519,  1531,  1532,  1535,  1536,  1538,  1264,
   15544, 15569, 15594, 15619, -1847, -1847, 11226,  1307,  1522, 15644,
   -1847, 11872,  1309, -1847,  4805, 15869, -1847,  1548,  -153,  6732,
   -1847, -1847, -1847, -1847,  1334, -1847, -1847, -1847, 10739, 10739,
     138,  1569,  1570,  1571, -1847, 10739, 10739, -1847, -1847,  1572,
    1487,  1574, 10739, -1847, -1847, -1847, -1847, -1847, -1847, -1847,
   -1847, -1847,  1578,  1343, -1847, -1847, -1847, -1847, -1847, 10739,
   10739, 10739, -1847, -1847, -1847,  1199, -1847, 10739, 10739, 10739,
   10739, -1847, -1847, -1847,  1345, -1847, -1847, 10739, 10739,   262,
      80, -1847, -1847, -1847, -1847,  1346,  1580,  1288,  1581, 10739,
   -1847,  1583,  1584,  1585,  1586,  1587,   838,  1588,  9178,  9178,
   10739, -1847,  9409, 13057, 15669,  9114,   333,   333, 10739, 10739,
   -1847,   219,  1357, 15694, -1847, -1847, 13086,   -59, -1847,  1589,
    1591,  6260,   138,   138,   138,   138,   138,  5788,  1592, -1847,
     686, 10739,  3226,  1593, -1847, -1847,  6260,  9440,   682, 15719,
   -1847, -1847,  8620, -1847, 11226, 10739, -1847, 11226, 15869,  8706,
   11316,  1358, -1847, -1847, -1847, -1847,  1362,  1364, 10739, 10739,
   13115,  7979, -1847,  7979,  6260, -1847, -1847, 11316, 10739,  1594,
    1598,    28, -1847,  1600, -1847,     8, 14188,  6260, 11226,  1602,
     262, -1847,  1370,   262, 10739, 11905, 11938,   688, -1847, 10739,
   10739,   370, -1847,  1372, -1847, -1847, -1847, -1847, -1847,  1348,
    1351,  1352,  1353,  1604, 10739, -1847, -1847, 10739, 10662, -1847,
   -1847,  1376,  1840,   689,  4108,  1605, -1847, 13144, 13173,   508,
   -1847, -1847, -1847, 13202, 13231, -1847,  1378, -1847, 13260,  1608,
    6260, 13837, 13837, 11971, 12004, 12037, 12070, 12103, -1847, 15744,
   14215, -1847, -1847, 10739, -1847,  1609, -1847, 15869, -1847, -1847,
   -1847, -1847, -1847,  1380, -1847, -1847,   691,   694, 13809,  3321,
    1610,  1382, -1847, -1847, 10739,  1384,  1385, 13289, 14242,  1613,
    6260,  1616,  1388, 10739, -1847, -1847,   697,   -11,   124,   167,
     179,   226,  8942,   243, -1847,  1619, 13318, -1847, -1847,  1455,
   -1847, 10739, 10739, -1847, -1847,  9178,  3354,  1623,  1392, 13837,
     262, 15869, -1847, -1847, -1847, -1847,    18, -1847, 11316, -1847,
    1389,  1390,  1391,  1631,  3662, -1847,  1632,  1634, -1847, -1847,
    1394,  1635,   702, -1847,  1636,  1637,   178, 15869, 10739, 10739,
    1404,  6260,   704, 15869, 15769, -1847, 15794, 12136, -1847,  1106,
    1171,  6260,   262, -1847, 10739, 11316,    12,  1641,  1642,  1644,
    1645, 10739,  1646,  1647,   712, -1847, -1847, 10739, 10739, 10739,
   10739, 10739, -1847, -1847, 13347, -1847,  6260,   502,   548,  9178,
   -1847, -1847,   333,  9680, -1847, -1847, -1847,  1648, -1847,  1412,
    6260, -1847, 13376,  1655,  9178,   138,   138,   138,   138,   138,
   -1847, -1847, 10739, 13405, 13434,   713, -1847, -1847, -1847, -1847,
   -1847, -1847,  1427,  1420, -1847,  1657, -1847, -1847,     8, -1847,
    1491, -1847, -1847, -1847, -1847, -1847, 10739, 12169, 12202,  6260,
   -1847,  1662, 10739,  1429, -1847, 10739,  1432,  1435, -1847, -1847,
    4222, -1847,  1441, -1847, -1847, -1847, -1847, 13463, -1847, -1847,
    1440, 12235, 12268, 12301, 12334, 12367, -1847,   714,  1443,   138,
    6260,  1663,  1446,   138,  1671,   721,  1437, -1847, 10739, -1847,
    1677,  1558,  8200,  1447, -1847,   754,   251,   280,   305,   307,
     319,  3825, -1847, -1847,  1681,  1684, -1847, -1847,  1685, -1847,
    1452, 15869, 10739, 10739,   756, -1847, 15869, 12400, -1847, -1847,
    1106, 11316,  1453, -1847, 10739, 10739, 10739, 10739, 10739, 10739,
    1687,   138,    75, -1847, -1847,   138,   113, -1847,  1696, -1847,
   13492, -1847, 10739, -1847,    42, -1847,  1697,  9178,  9178,  9178,
    9178,  8942, -1847, -1847, -1847,  7979, -1847, 10739, 15819, 12433,
      52, 10739,  1473, -1847, -1847, 12466, 12499, 12532, 12565, 12598,
   12631, -1847,   322, -1847,   344, -1847, -1847, -1847,  3950,   543,
    9009, -1847,   762,   763,   768,   770,   347,   780,  1475,   781,
   -1847, 10739, -1847,  6260, 13521, -1847, 10739, 10739, 10739, 10739,
   10739, 10739,   138,   138, -1847, -1847, -1847,    42,  1698,  1699,
    1700,  1701,  9178,  1703,  1704,  1705,  1471, 15844,   786,  1711,
   13550, 13837, 12664, 12697, 12730, 12763,   352,   357,   559, -1847,
   -1847, -1847, -1847,   787, -1847, -1847, -1847, 11226, -1847,  1482,
   -1847,  1713, -1847, 10739, 10739, 10739, 10739, 10739, 10739, -1847,
    1714,   788, -1847,  1490,  6260, -1847, 13579, 13608, 13637, 13666,
   13695, 13724, -1847,  1715, 11226, 11226,   793, -1847, -1847, -1847,
   -1847,  1716,  1717, -1847, -1847,   794, -1847,  1719, -1847, -1847,
    1720, 11226, -1847, -1847, -1847
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1847, -1847, -1847, -1847,   400, -1847, -1847, -1847, -1847,  -339,
   -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847,
   -1847, -1847,  -642,  -124,  4008,  3010, -1847,  1308, -1847, -1847,
   -1847, -1847, -1847, -1847, -1846, -1847,   353,   169,  -142, -1847,
    -104, -1847, -1847, -1847, -1847,   119,   392,  1744,    -2,  -592,
    -261, -1847, -1847, -1847, -1847, -1847, -1847, -1847, -1847,  1745,
   -1847, -1847, -1847, -1847, -1200, -1195,  1747, -1692,  1748, -1847,
   -1847, -1847,  1187, -1847,  -156, -1847, -1847, -1847, -1847,  2041,
   -1847, -1847,   363,   267,  1754, -1847,     0,  -571, -1847, -1847,
      33, -1847, -1646,   321,   -95,  2200,  2230,  -276,    48, -1847,
     121,   -33, -1847, -1847,    69,   239, -1643,   -97,  1030, -1847,
      -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -549
static const yytype_int16 yytable[] =
{
     132,   113,   911,   912,  1449,  1447,   503,   584,   405,  1850,
     617,  1851,   333,   387,   150,  1816,   150,  1032,   152,  1567,
     376,   151,  1689,  1442,   310,     4,   378,   506,   508,   510,
    1301,  1444,   150,  1966,   600,   139,   282,   136,   696,  1235,
    1508,   161,   266,   337,   262,   315,  1844,   316,   424,   166,
     150,   161,   621,   266,  1007,   708,   724,   166,  2102,   592,
     593,   283,  1015,   267,   725,   371,  1336,   375,   701,   431,
     702,   314,   278,     5,  1027,   279,  1132,   284,   285,   262,
     906,  2083,   592,   593,   336,   153,   150,   154,   462,   463,
     464,   592,   593,   291,   293,   372,   296,   592,   593,   409,
     726,   735,   738,   913,   311,  1284,   592,   593,   739,  1882,
     988,   135,   917,   701,  1434,   702,   671,   553,   673,  2085,
    1193,   734,   432,  1138,  1894,   684,  1139,  1430,   701,   410,
     702,   412,   317,   730,   420,   420,  1238,  1194,   741,  1545,
    1020,   731,   426,   553,   739,  1195,  1196,  1197,   592,   593,
     137,  1198,  1199,   433,  1135,   262,   733,   138,  1041,  1136,
     262,   678,   399,   400,   734,   262,  1050,   592,   593,  1448,
    1193,  1400,   420,   565,   566,   567,   262,   504,  1443,   262,
     262,   262,   262,   420,  2072,   145,  1445,  1194,  1813,  1302,
    1303,  1304,  1305,  1013,   141,  1195,  1196,  1197,   507,   509,
     511,  1198,  1199,   142,   312,  1284,  1690,   697,   698,  1509,
    1510,   613,   614,   615,   268,   592,   593,   269,   107,   270,
     107,   701,   107,   702,   157,   627,   628,   533,   158,  1258,
     107,   262,  1033,  1034,  1123,  1446,  1924,   385,   107,   592,
     593,   386,   734,   505,   262,   388,   618,   262,   532,   389,
     334,   531,   134,   408,  1447,   972,   107,   377,   418,   421,
    1987,   262,   313,   379,   262,   262,   262,   262,  1143,  1306,
    1294,   140,   262,   262,   262,   162,  1236,   338,   262,   163,
     336,   399,   400,   167,   709,   162,   710,   168,  -541,  1023,
     711,   167,   107,   143,  2103,  1024,   455,   153,   153,   154,
     154,   592,   593,   262,   262,   262,   701,   465,   702,   395,
     396,   397,   398,  2024,   752,   399,   400,   262,   262,   587,
     588,   701,   902,   702,   904,   905,   144,   596,   601,   727,
     736,   728,   728,   399,   400,   729,   737,   411,   146,   592,
     593,   918,  1287,   399,   400,   306,   554,   307,   555,  1113,
     592,   593,   556,  1006,  1033,  1034,  1315,  1284,  1268,   688,
    -544,   147,  1285,  1288,   287,   288,   592,   593,   260,   399,
     400,  1925,   554,  2098,   555,  1327,   289,   148,   556,   952,
     290,   420,   594,   752,   297,   262,   262,   399,   400,   159,
     679,   133,   680,   592,   593,   134,   681,   395,   396,   397,
    1014,   262,   149,   817,  1707,   592,   593,   712,   160,   395,
     396,   397,   398,   164,  1926,  1332,   986,  1955,   826,   827,
     828,   829,   489,   752,   490,  1956,  1927,   183,   746,   638,
     184,   134,   262,   185,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   592,   593,  1641,  1642,   552,  2128,   592,   593,
     287,   288,  1809,  1681,  1682,    59,    60,    61,    62,   592,
     593,   298,   289,  1928,   595,   299,   295,   592,   593,   262,
      73,   300,   301,    76,   302,   303,   262,   807,   834,   320,
    1929,   420,   321,   420,   262,   420,   420,   426,  2057,   820,
     459,   701,   304,   702,   603,   682,   592,   593,   604,   262,
     262,   262,   262,   262,   420,   420,   262,   152,  2176,   152,
     833,   262,   835,   165,  1414,   751,  1416,  2058,  1418,   752,
    1420,   592,   593,   592,   593,   881,   884,   887,   890,   757,
     592,   593,   169,   752,   262,   592,   593,   170,   592,   593,
     863,   960,  2059,   171,  2060,   260,   602,   395,   396,   397,
     398,   395,   396,   397,   398,  1389,  2061,  1390,   172,  2112,
     592,   593,  1008,   592,   593,   262,   262,  1398,   592,   593,
     173,   399,   400,   592,   593,   399,   400,   174,   564,   550,
     551,  2113,   412,   412,  2122,   552,   573,   575,   577,  2157,
     399,   400,   582,   179,  2158,   399,   400,  -543,   395,   396,
     397,   398,  -548,   275,   175,   811,   276,   813,   277,   815,
     816,   262,   262,   262,  1028,   909,   910,  1029,   975,  1030,
     588,   176,   399,   400,  1988,  1989,   177,   762,   830,   831,
    1990,   752,  1182,   426,   420,   426,   420,   420,   420,   420,
     420,   420,  1193,   420,   420,   420,   420,   974,   178,   420,
     420,   420,   152,   980,   271,   979,   262,   272,   180,  1194,
     273,  1193,   274,  1260,   181,   987,  1261,  1195,  1196,  1197,
    1992,  1993,   182,  1198,  1199,   186,  1990,  1193,  1194,  1489,
    1832,   701,   263,   702,   703,  1493,  1195,  1196,  1197,  1152,
     262,  1153,  1198,  1199,  1194,  1017,  1267,   775,  1268,   685,
     686,   752,  1195,  1196,  1197,  1059,   838,   264,  1198,  1199,
     752,   513,   262,  1037,   514,   699,   280,   515,   262,   516,
     689,   426,  1048,   690,   592,   593,   691,  1052,   692,   420,
     286,  1530,  1151,  1617,  1730,  1618,  1699,   262,  -545,   262,
     676,   548,   549,   550,   551,   265,   871,  1547,   995,   552,
     752,   281,   996,  1552,   150,   344,   305,  1658,   959,   294,
     961,   962,   963,   964,   965,   966,   308,   968,   969,   970,
     971,   309,   319,   976,   977,   978,  2115,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
     318,  1698,  2159,  1699,   552,   262,   345,   346,   347,   348,
     349,   350,   351,   352,   353,  1345,   322,  1346,   814,   354,
     355,   356,   357,  1351,   323,  1352,   157,   358,   359,   360,
    1022,   324,   361,   564,   362,   545,   546,   676,   548,   549,
     550,   551,  1793,   170,  1794,   363,   552,  1025,   364,  1141,
     329,   341,   262,   752,  2089,  1046,  1177,  1178,  1221,   342,
     752,   752,   752,  1054,  1222,   262,  1708,  1223,   752,   330,
    1264,   752,  1297,   262,   752,  1374,   752,   343,  1717,   752,
    1286,  1289,   331,  1397,  1405,   393,  1427,   752,   752,  1535,
     752,  1536,   332,   752,  1447,   752,   262,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,   339,  1537,  2138,  1538,   552,
     752,   390,   752,  1593,  1625,  1833,  1714,   752,   752,  1825,
    1715,  1870,  1883,   752,  1907,  1871,  1884,  1908,   752,  1185,
    1923,   752,   391,  1447,  1871,  1952,  1191,  1961,   340,   734,
    1202,  1962,   365,   366,   367,  1980,  2014,  2040,   373,  1871,
     752,  1871,   533,   368,  2048,   384,   415,   369,   752,   370,
     107,   416,   429,  1290,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
     134,   431,   512,   262,   552,   399,   400,  2056,   581,  2070,
     386,   752,  -542,  1871,  1531,  2118,  2119,  1296,   578,   752,
     752,  2120,   262,  2121,   441,   752,   446,   752,  1516,   262,
     262,   262,   262,  2123,  2125,  1399,  1401,   752,  1962,  2149,
    2160,  2173,   420,  1871,   752,  2174,  2187,  2190,   460,   497,
    1871,  2191,   150,   344,   701,   500,   702,   868,   517,   520,
     583,   521,   522,   561,  1805,  1806,   562,   568,   585,   569,
     570,   262,   262,   571,   262,   586,   262,   262,   605,   262,
     606,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     607,   608,   262,   619,   345,   346,   347,   348,   349,   350,
     351,   352,   353,  1344,   609,   610,   611,   354,   355,   356,
     357,   616,   620,   622,   623,   358,   359,   360,   624,   625,
     361,   626,   362,   629,   633,   630,   631,   262,   420,   420,
     634,   640,   641,   363,   649,   650,   364,   651,   662,   663,
     665,   667,   668,   666,   670,   672,   669,   687,   693,   262,
     700,   706,   707,   133,   743,   713,   769,   747,   773,   776,
     748,   777,   778,   262,   262,   779,  1326,   821,   823,   808,
     824,   552,   839,   393,   825,   866,   875,   876,   892,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   750,   548,   549,   550,   551,   894,   896,  1399,
    1401,   552,   900,   701,   901,   702,   929,  1162,   903,   931,
     950,   932,   934,   941,   942,   953,   994,   989,   998,  1011,
     999,   262,  1000,  1001,  1002,  1010,  1021,  1009,  1026,  1040,
    1042,  1057,  1045,  1051,   262,   262,   262,  1053,  1056,  1060,
     365,   366,   367,  1064,  1701,   262,  1061,  1065,  1703,  1713,
     420,   368,  1379,  1380,   420,   369,  1067,   370,   107,  1068,
    1069,  1070,  1072,   420,  1073,   420,  1074,  1075,   420,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1085,  1086,  1111,  1112,
    1120,  1142,   262,  1121,  1126,  1128,  1129,   701,  1122,   702,
    1718,  1130,  1131,  1137,  1148,  1156,  1163,  1157,  1166,  1165,
    1167,   336,  1168,  1169,  1170,  1171,  1180,  1172,  1173,  1188,
    1192,  1214,  1189,  1556,  1216,  1561,  1227,  1228,  1229,  1230,
    1241,   420,  1254,  1242,  1243,  1246,  1256,  1277,  1257,  1266,
    1996,  1263,  1269,  1270,  1271,  1274,  1275,  1276,  1292,  1293,
    1298,  1299,  1312,  1322,  1328,   262,  1300,  1323,  1338,  1324,
    1325,  1331,  1349,  1335,  1355,  1357,   262,  1368,  1334,  1392,
    1476,  1408,   262,  1381,  1409,  1410,  1413,  1435,  1422,  1423,
    1424,  1425,  1426,  1428,  1481,  1436,  1439,  1450,  1483,  1440,
    1441,  1451,  1461,  1452,  1453,  1454,  1455,  1487,  1456,  1488,
    1457,  1458,  1490,  1462,  1709,  1347,  1348,  1463,  1350,  1464,
    1353,  1354,  1465,  1356,  1466,  1358,  1359,  1360,  1361,  1362,
    1363,  1364,  1365,  1366,  1467,   262,   262,   262,  1468,  1473,
    1478,   262,  1479,   262,  1484,   262,  1491,   262,  1485,   262,
     262,   262,  1492,  1501,  1722,  1722,  1494,  1495,  1499,  1507,
    1512,  1513,  1519,  1515,  1518,  1532,   262,  1523,  1525,  1859,
    1529,  1378,  1526,  1527,  1544,  1550,  1564,   262,  1563,  1548,
    1565,  1566,  1568,  1569,  1570,   262,  1574,  1577,   262,  1697,
    1575,  1576,  1578,  1393,  1580,  1582,  1583,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,  1602,  1406,  1139,  1613,
    1615,  1657,  1620,  1624,  1629,  1630,  1676,  1731,  1640,  1638,
    1654,  1655,  1669,  1639,  1674,  1675,  1782,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,   336,  1646,  1647,  1648,   552,  1649,   426,   426,
    1680,  1750,  1661,  1662,   262,  1705,  1745,  1711,  1663,  1664,
    1732,  1665,  1666,  1671,  1724,  1459,  1694,  1734,  1735,  1684,
    1687,  1736,  1737,   420,  1738,  1744,  1710,  1748,  1470,  1471,
    1472,   262,  1261,  1704,  1729,  1751,   262,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,  1760,  1761,  1762,  1765,   552,
    1767,  1477,  1766,  1769,  1778,  1770,  1784,  1786,  1783,  1788,
    1789,  1790,  1791,  1792,  1795,  1814,  1500,  1815,  1824,  1828,
    1855,  1847,  1856,  1759,  1810,  1846,  1858,  1782,  1863,  1800,
    1875,  1848,  1886,  1893,  -546,  1905,  1911,   734,  1881,  1918,
    1891,  1862,  1906,  1920,  1912,  1930,  1932,  1914,  1915,  1937,
    1921,  1938,  1943,  1944,  1945,   262,   262,  1946,  1950,  1948,
    1949,  1951,  1953,  1954,   412,   412,  1959,  1973,  1974,  1837,
    1975,  1976,  1978,  1979,  1999,  2000,  1842,  1845,   262,  1560,
    2002,  2004,  2016,  2017,   262,  2019,  2015,  1743,  2025,  2044,
    1573,  -547,  2018,   262,  1853,  2028,  1579,  2047,  2029,  2032,
    2049,   420,  2034,  2051,   420,  2041,  2052,  2063,  2045,  2055,
    2064,  2066,  2074,  2081,  2067,  1817,  1818,  1819,  1820,  1821,
    1823,   262,  2086,  2091,  2139,  2140,  2141,  2142,  1296,  2144,
    2145,  2146,   336,  2147,   262,   426,  2105,  2150,  2124,  2165,
    2172,  2183,  2188,  2189,  2164,  2192,  2193,  1546,  2099,  1626,
    1627,  1628,  2175,  1756,  1605,  1631,   742,  1632,  1967,  1633,
    1572,  1634,  1941,  1635,  1636,  1637,  1785,   112,   122,   426,
     123,   124,  1994,  1614,   878,  2065,  1696,   130,  1843,  1857,
    1652,  1723,     0,     0,  1047,     0,     0,   262,     0,     0,
       0,  1660,     0,     0,     0,     0,     0,     0,     0,  1668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     705,     0,     0,     0,  2090,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1838,     0,   262,  1840,     0,
       0,     0,     0,     0,     0,  1942,     0,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   344,     0,     0,  1728,     0,
       0,     0,  1971,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,  1749,     0,     0,   262,     0,
       0,     0,     0,  1972,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,     0,     0,     0,     0,   354,
     355,   356,   357,   262,     0,     0,   262,   358,   359,   360,
     412,     0,   361,     0,   362,     0,     0,   262,     0,     0,
       0,   262,     0,     0,     0,   363,     0,     0,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,  2006,  2007,
    2008,  2009,  2010,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1728,     0,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1829,  2073,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,  2042,     0,     0,  1852,  2046,     7,     8,     0,
       0,     0,   365,   366,   367,   723,     0,     0,  1861,     0,
       0,     0,     0,   368,     0,     0,     0,   369,     0,   370,
     107,     0,     0,     0,   262,   262,   262,   262,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2082,     0,     0,     0,  2084,     0,
       0,     0,  1718,     0,     0,     0,     0,     0,     0,     0,
       0,  1728,     0,     0,  2096,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,   714,    25,    26,   715,    28,
      29,   716,    31,   717,    33,    34,    35,    36,     0,   262,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,  1919,   718,    48,     0,     0,    50,   719,     0,    53,
     720,     0,     0,     0,   420,  2136,  2137,   382,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   420,   420,   407,     0,     0,     0,   417,     0,     0,
       0,   422,    84,    85,    86,     0,     0,     0,   420,     0,
       0,     0,  1960,     0,     0,     0,     0,     0,   434,   436,
     439,   440,  1968,   442,   436,   444,   445,     0,   447,   436,
     449,   450,   451,   452,   453,   454,     0,   456,   457,   458,
       0,     0,     0,   436,     0,     0,     0,  1728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2001,     0,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  2162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1728,     0,     0,     0,     0,     0,     0,   523,   525,   527,
     528,   436,     0,     0,     0,  2184,  2186,     0,     0,     0,
       0,     0,     0,     0,   559,   436,     0,     0,     0,     0,
       0,  2043,  2194,     0,     0,     0,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   591,     0,     0,     0,     0,   591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   437,     0,
       0,     0,     0,   437,     0,     0,     0,   632,   437,     0,
       0,   635,   636,   637,     0,   639,     0,     0,     0,   642,
     643,   644,   437,     0,   645,     0,     0,     0,   438,     0,
       0,     0,     0,   443,     0,     0,     0,     0,   448,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   461,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   675,     0,  1728,     0,   683,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   694,   695,     0,     0,     0,   526,     0,     0,
     437,     0,     0,     0,     0,     0,   722,     0,     0,     0,
       0,     0,     0,     0,   437,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   525,     0,     0,     0,
       0,     0,   755,     0,     0,  1728,     0,   760,     0,     0,
       0,     0,     0,     0,   560,     0,     0,     0,     0,     0,
       0,   774,     0,     0,     0,     0,     0,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
     793,   794,   795,   796,   798,   799,   800,   801,   802,   803,
     804,   804,     0,   809,   810,     0,   812,     0,     0,     0,
       0,     0,   818,     0,     0,     0,   822,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     804,     0,     0,     0,     0,   436,     0,     0,     0,     0,
       0,     0,     0,     0,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,   854,   856,   858,
     859,   860,   861,   862,     0,   864,   865,     0,     0,     0,
       0,     0,   872,   873,   874,     0,     0,     0,     0,   880,
     883,   886,   889,   891,     0,   893,     0,   895,     0,   436,
     436,  1283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,     0,   523,   675,
     914,     0,     0,     0,   919,   920,   921,   922,   923,   924,
     925,   926,   927,     0,     0,     0,     0,   933,     0,   935,
       0,   936,  1367,     0,     0,   436,   436,   436,     0,     0,
     943,   944,   945,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   797,     0,     0,     0,     0,     0,     0,   805,
     806,     0,     0,     0,     0,     0,   967,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     436,     0,     0,     0,     0,   984,     0,   985,     0,   832,
     864,   865,     0,     0,   437,     0,     0,     0,   997,     0,
       0,     0,     0,     0,  1003,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   436,     0,     0,   857,     0,     0,
    1018,  1019,     0,     0,   836,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1460,   436,     0,  1038,  1039,
       0,     0,   436,  1044,     0,     0,     0,  1038,   437,   437,
       0,     0,     0,     0,  1055,     0,     0,     0,  1058,     0,
       0,   856,     0,  1062,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1498,     0,     0,   897,   898,
       0,     0,     0,     0,  1083,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   437,   437,   437,     0,     0,     0,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,   436,
       0,     0,   552,     0,   938,   939,   940,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   437,
       0,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,  1514,     0,   552,     0,     0,   436,     0,     0,   981,
       0,     0,     0,   437,     0,     0,     0,     0,     0,   436,
       0,     0,     0,     0,     0,     0,  1161,     0,     0,     0,
       0,     0,     0,     0,     0,   437,     0,     0,     0,     0,
       0,   437,     0,  1012,     0,     0,     0,     0,     0,     0,
     436,     0,     0,     0,     0,     0,     0,     0,  1186,  1187,
     857,     0,  1063,     0,  1190,  1036,     0,     0,     0,     0,
       0,  1043,     0,     0,     0,     0,     0,     0,     0,     0,
    1215,     0,     0,  1217,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,  1231,     0,  1233,  1234,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   437,     0,
       0,     0,     0,  1252,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,  1273,     0,     0,   552,     0,  1114,     0,
    1279,  1280,  1281,  1282,     0,     0,     0,     0,  1291,     0,
       0,     0,     0,     0,     0,   437,     0,     0,     0,     0,
       0,     0,  1316,   436,   436,   436,   436,  1321,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1650,
       0,     0,     0,     0,     0,  1147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1155,   437,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,  1702,   552,     0,     0,     0,   436,     0,     0,  1179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1371,
    1372,  1373,     0,     0,     0,     0,  1375,  1376,     0,  1377,
       0,     0,     0,     0,     0,     0,     0,  1383,     0,  1384,
    1385,  1386,  1387,  1388,     0,     0,     0,     0,     0,  1706,
    1391,     0,     0,     0,     0,     0,  1395,  1396,     0,     0,
       0,     0,     0,  1402,  1403,     0,     0,     0,   436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1415,  1712,
    1417,     0,  1419,     0,  1421,     0,     0,     0,     0,     0,
       0,     0,   437,   437,   437,   437,     0,     0,     0,     0,
       0,     0,  1827,     0,     0,  1438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1317,  1318,  1319,  1320,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1469,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   436,
       0,     0,     0,     0,     0,   437,     0,  1482,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,  1402,  1403,
     552,     0,  1497,     0,     0,  1369,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1506,  1910,     0,  1511,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,  1533,   437,     0,     0,
    1936,     0,     0,  1540,  1541,  1542,  1543,     0,     0,     0,
       0,     0,  1549,     0,  1551,     0,  1549,  1555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1407,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,   704,     0,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,   437,     0,
     552,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,  1480,     0,
       0,  1643,  1644,  1645,     0,     0,     0,     0,     0,     0,
    1651,     0,  1653,     0,     0,     0,     0,     0,     0,  1656,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   436,     0,     0,     0,     0,  1672,     0,     0,
       0,     0,   819,     0,     0,  1677,  1678,  1679,     0,     0,
       0,     0,     0,     0,     0,  1688,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1700,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
    1716,     0,     0,     0,     0,     0,  1725,  1726,   869,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
    1754,     0,     0,     0,     0,     0,     0,     0,     0,  1757,
    1758,     0,     0,     0,     0,     0,  1763,  1764,     0,     0,
       0,     0,     0,  1768,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1771,  1772,  1773,     0,     0,     0,     0,     0,  1774,  1775,
    1776,  1777,     0,     0,     0,     0,     0,     0,  1779,  1780,
       0,   437,     0,     0,     0,     0,     0,     0,  1947,     0,
    1787,     0,     0,     0,     0,     0,     0,     0,     0,   436,
     436,  1798,     0,  1799,     0,     0,     0,     0,     0,  1807,
    1808,  1670,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   436,     0,
       0,     0,  1826,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1836,     0,     0,  1839,     0,     0,     0,
    1841,     0,     0,     0,     0,     0,     0,     0,     0,  1779,
    1780,     0,     0,     0,     0,     0,     0,     0,     0,  1854,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1755,
       0,     0,     0,     0,     0,  1867,     0,     0,     0,     0,
    1873,  1874,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1876,     0,     0,  1877,  1876,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,     0,  1099,  1100,  1101,  1102,     0,  1104,  1105,  1106,
    1107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1117,     0,  1119,  1904,     0,     0,     0,     0,     0,
    1125,  2062,     0,     0,     0,     0,     0,     0,   437,   437,
       0,  1133,  1134,     0,     0,  1913,     0,     0,     0,     0,
    1144,     0,     0,     0,  1922,     0,     0,     0,     0,     0,
       0,     0,     0,   525,     0,     0,     0,   437,  1796,  1797,
       0,     0,  1933,  1934,     0,     0,   436,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1957,
    1958,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1970,     0,     0,     0,     0,
       0,     0,  1977,     0,     0,     0,     0,     0,  1981,  1982,
    1983,  1984,  1985,     0,     0,     0,     0,     0,     0,     0,
     436,     0,     0,     0,     0,     0,  2114,     0,     0,     0,
       0,     0,     0,     0,     0,   436,     0,     0,  1237,  1239,
    1240,     0,     0,  2011,  1244,  1245,     0,     0,  1248,  1249,
    1250,  1251,     0,  1253,     0,     0,     0,     0,  1259,     0,
       0,     0,     0,     0,     0,     0,     0,  2021,     0,     0,
       0,     0,     0,  2026,     0,     0,  2027,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   526,     0,     0,     0,     0,     0,     0,     0,
     155,   156,     0,     0,     0,   437,     0,     0,     0,  2050,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,  2068,  2069,  1935,     0,     0,  1342,  1343,
       0,     0,     0,     0,     0,  2075,  2076,  2077,  2078,  2079,
    2080,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2088,     0,     0,     0,     0,   436,   436,
     436,   436,   436,     0,     0,     0,     0,     0,  1873,   437,
       0,     0,  2104,     0,     0,  1885,   533,     0,     0,     0,
       0,     0,     0,     0,   437,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1995,
     406,     0,  2127,     0,     0,     0,     0,  2130,  2131,  2132,
    2133,  2134,  2135,     0,  2005,     0,     0,     0,     0,     0,
       0,     0,     0,   436,  1404,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,  2166,  2167,  2168,  2169,  2170,  2171,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   491,   492,   493,   494,   495,   496,  2031,
     498,   499,     0,     0,     0,     0,   501,   502,     0,     0,
       0,     0,     0,     0,     0,     0,   518,   519,     0,     0,
       0,     0,     0,   533,     0,     0,     0,   437,   437,   437,
     437,   437,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,   946,  2092,  2093,  2094,
    2095,  2097,   533,     0,   907,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   437,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   750,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,  1557,     0,     0,
       0,     0,  2143,   646,   647,   648,     0,     0,     0,   652,
     653,   654,   655,   656,   657,   658,     0,   659,     0,     0,
       0,   660,   661,     0,     0,   664,     0,     0,     0,     0,
    1594,  1595,  1596,  1597,  1598,     0,     0,     0,   674,  1603,
    1604,     0,  1606,     0,     0,     0,     0,     0,  1612,     0,
       0,     0,     0,     0,  1616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1623,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,     0,     0,
    1683,   954,  1686,     0,     0,     0,  1693,     0,  1695,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   750,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1719,     0,     0,     0,     0,     0,     0,     0,     0,
     840,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     6,   344,     0,     0,     0,     0,   188,   189,   190,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,  1558,   346,   347,   348,   349,   350,   351,
     352,   353,   220,   221,   222,   223,   354,   355,   356,   357,
     224,     0,     0,     0,   358,   359,   360,     0,     0,   361,
       0,   362,   225,   226,   227,     0,     0,     0,     0,  1781,
     228,    21,   363,   229,     0,   364,     0,     0,   230,     0,
       0,   231,     0,     0,   232,     0,   233,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,    49,     0,     0,
     235,     0,   236,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1864,     0,     0,  1865,     0,     0,     0,     0,   237,   365,
     366,   367,   238,   239,     0,     0,     0,   240,   241,   242,
     368,   243,   244,   245,   369,  1145,   370,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,     0,     0,
     248,  1895,  1896,     0,     0,   326,     0,     0,     0,  1559,
       0,     0,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     6,
     344,     0,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,  1939,
    1940,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     220,   221,   222,   223,   354,   355,   356,   357,   224,     0,
       0,     0,   358,   359,   360,  1154,     0,   361,     0,   362,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
     363,   229,  1969,   364,     0,     0,   230,     0,     0,   231,
       0,     0,   232,     0,   233,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,    49,     0,     0,   235,     0,
     236,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,  1146,
       0,     0,    73,     0,     0,    76,     0,     0,     0,     0,
       0,     0,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   365,   366,   367,
     238,   239,     0,     0,     0,   240,   241,   242,   368,   243,
     244,   245,   369,     0,   370,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,     0,   248,     0,
       0,     0,     0,   326,     0,     0,     0,   250,     0,     0,
     251,     0,     0,     0,   187,   150,   344,     0,   392,     0,
    1337,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   380,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   220,   221,   222,   223,
     354,   355,   356,   357,   224,     0,     7,     8,   358,   359,
     360,     0,     0,   361,     0,   362,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,   363,   229,     0,   364,
       0,  2152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1394,     0,     0,     0,     0,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,   393,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   714,    25,    26,   715,    28,    29,
     716,    31,   717,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   718,    48,     0,     0,    50,   719,     0,    53,   720,
       0,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,   237,   365,   366,   367,   238,    70,  1475,     0,
       0,   240,   241,   242,   368,   243,   244,   245,   369,     0,
     370,   107,   395,   396,   397,   398,     0,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,   246,   381,     0,
       0,     0,     0,     0,   248,     0,   399,   400,     0,   401,
       0,   402,     0,     0,     0,   403,   251,     0,     0,     0,
       0,   187,     6,   325,     0,     0,  1521,  1522,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,   915,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,     0,   229,     0,     0,     0,     0,   230,
       0,     0,   231,     0,     0,   232,     0,   233,     0,     0,
       0,     0,     0,     0,    37,     0,  1619,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,    49,     0,
       0,   235,     0,   236,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,     0,   238,   239,     0,     0,     0,   240,   241,
     242,     0,   243,   244,   245,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,     0,     0,     0,     0,
       0,   248,     0,     0,     0,     0,   326,     0,     0,     0,
     250,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     6,  1659,     0,     0,
       0,     0,   188,   189,   190,     0,  1752,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,   229,     0,
       0,     0,     0,   230,     0,     0,   231,     0,     0,   232,
       0,   233,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,    49,     0,     0,   235,     0,   236,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
     714,    25,    26,   715,    28,    29,   716,    31,   717,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   718,    48,     0,
       0,    50,   719,   237,    53,   720,     0,   238,   239,     0,
       0,     0,   240,   241,   242,     0,   243,   244,   245,     0,
       0,     0,   107,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
       0,     0,     0,     0,     0,   248,     0,    84,    85,    86,
     326,   187,     6,     0,   250,     0,     0,   251,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   937,   225,   226,   227,     0,     0,     7,     8,
       0,   228,    21,     0,   229,     0,     0,     0,     0,   230,
       0,     0,   231,     0,     0,   232,     0,   233,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,    49,     0,
       0,   235,     0,   236,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,   714,    25,    26,   715,
      28,    29,   716,    31,   717,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,   718,    48,     0,     0,    50,   719,   237,
      53,   720,     0,   238,   239,     0,     0,     0,   240,   241,
     242,     0,   243,   244,   245,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   597,  1822,     0,     0,     0,     0,
       0,   248,     0,    84,    85,    86,   599,   187,     6,     0,
     290,   529,     0,   251,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   982,   225,
     226,   227,     0,     0,     7,     8,     0,   228,    21,     0,
     229,     0,     0,     0,     0,   230,     0,     0,   231,     0,
       0,   232,     0,   233,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,    49,     0,     0,   235,     0,   236,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,   714,    25,    26,   715,    28,    29,   716,    31,
     717,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   718,
      48,     0,     0,    50,   719,   237,    53,   720,     0,   238,
     239,     0,     0,     0,   240,   241,   242,     0,   243,   244,
     245,     0,     0,     0,   107,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,     0,     0,     0,     0,   248,     0,    84,
      85,    86,   249,   187,     6,     0,   250,     0,     0,   251,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   983,   225,   226,   227,     0,     0,
       7,     8,     0,   228,    21,     0,   229,     0,     0,     0,
       0,   230,     0,     0,   231,     0,     0,   232,     0,   233,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,     0,
      49,     0,     0,   235,     0,   236,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,   714,    25,
      26,   715,    28,    29,   716,    31,   717,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   718,    48,     0,     0,    50,
     719,   237,    53,   720,     0,   238,   239,     0,     0,     0,
     240,   241,   242,     0,   243,   244,   245,     0,     0,     0,
     107,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,     0,     0,
       0,     0,     0,   248,     0,    84,    85,    86,   326,   187,
       6,     0,   250,     0,     0,   251,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1181,   225,   226,   227,     0,     0,     7,     8,     0,   228,
      21,     0,   229,     0,     0,     0,     0,   230,     0,     0,
     231,     0,     0,   232,     0,   233,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,    49,     0,     0,   235,
       0,   236,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   714,    25,    26,   715,    28,    29,
     716,    31,   717,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   718,    48,     0,     0,    50,   719,   237,    53,   720,
       0,   238,   239,     0,     0,     0,   240,   241,   242,     0,
     243,   244,   245,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   435,     0,     0,     0,     0,     0,   248,
       0,    84,    85,    86,   326,   187,     6,     0,   524,     0,
       0,   251,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1183,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,   229,     0,
       0,     0,     0,   230,     0,     0,   231,     0,     0,   232,
       0,   233,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,    49,     0,     0,   235,     0,   236,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
     714,    25,    26,   715,    28,    29,   716,    31,   717,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   718,    48,     0,
       0,    50,   719,   237,    53,   720,     0,   238,   239,     0,
       0,     0,   240,   241,   242,     0,   243,   244,   245,     0,
       0,     0,   107,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   435,
       0,     0,     0,     0,     0,   248,     0,    84,    85,    86,
     326,   187,     6,     0,     0,   529,     0,   251,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1184,   225,   226,   227,     0,     0,     7,     8,
       0,   228,    21,     0,   229,     0,     0,     0,     0,   230,
       0,     0,   231,     0,     0,   232,     0,   233,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,    49,     0,
       0,   235,     0,   236,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,   714,    25,    26,   715,
      28,    29,   716,    31,   717,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,     0,     0,    42,     0,     0,
       0,     0,     0,   718,    48,     0,     0,    50,   719,   237,
      53,   720,     0,   238,   239,     0,     0,     0,   240,   241,
     242,     0,   243,   244,   245,     0,     0,     0,   107,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,     0,     0,     0,     0,
       0,   248,     0,    84,    85,    86,   563,   187,     6,     0,
     250,     0,     0,   251,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1203,   225,
     226,   227,     0,     0,     7,     8,     0,   228,    21,     0,
     229,     0,     0,     0,     0,   230,     0,     0,   231,     0,
       0,   232,     0,   233,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,    49,     0,     0,   235,     0,   236,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,   714,    25,    26,   715,    28,    29,   716,    31,
     717,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   718,
      48,     0,     0,    50,   719,   237,    53,   720,     0,   238,
     239,     0,     0,     0,   240,   241,   242,     0,   243,   244,
     245,     0,     0,     0,   107,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,     0,     0,     0,     0,   248,     0,    84,
      85,    86,   572,   187,     6,     0,   250,     0,     0,   251,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1232,   225,   226,   227,     0,     0,
       7,     8,     0,   228,    21,     0,   229,     0,     0,     0,
       0,   230,     0,     0,   231,     0,     0,   232,     0,   233,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,     0,
      49,     0,     0,   235,     0,   236,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,   714,    25,
      26,   715,    28,    29,   716,    31,   717,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   718,    48,     0,     0,    50,
     719,   237,    53,   720,     0,   238,   239,     0,     0,     0,
     240,   241,   242,     0,   243,   244,   245,     0,     0,     0,
     107,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,     0,     0,
       0,     0,     0,   248,     0,    84,    85,    86,   574,   187,
       6,     0,   250,     0,     0,   251,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1265,   225,   226,   227,     0,     0,     7,     8,     0,   228,
      21,     0,   229,     0,     0,     0,     0,   230,     0,     0,
     231,     0,     0,   232,     0,   233,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,    49,     0,     0,   235,
       0,   236,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,   714,    25,    26,   715,    28,    29,
     716,    31,   717,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   718,    48,     0,     0,    50,   719,   237,    53,   720,
       0,   238,   239,     0,     0,     0,   240,   241,   242,     0,
     243,   244,   245,     0,     0,     0,   107,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,     0,     0,     0,     0,     0,   248,
       0,    84,    85,    86,   576,   187,     6,     0,   250,     0,
       0,   251,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1429,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,   229,     0,
       0,     0,     0,   230,     0,     0,   231,     0,     0,   232,
       0,   233,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,    49,     0,     0,   235,     0,   236,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
     714,    25,    26,   715,    28,    29,   716,    31,   717,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   718,    48,     0,
       0,    50,   719,   237,    53,   720,     0,   238,   239,     0,
     991,     0,   240,   241,   242,     0,   243,   244,   245,     0,
       0,     0,   107,    70,     0,     0,     0,   992,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   435,
       0,     0,     0,     0,     0,   248,     0,    84,    85,    86,
     326,   187,   150,   344,   855,  1411,     0,   251,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     380,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   220,   221,   222,   223,   354,   355,   356,
     357,   224,     0,     7,     8,   358,   359,   360,     0,     0,
     361,     0,   362,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,   363,   229,     0,   364,     0,     0,     0,
       0,     0,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,   749,
       0,   714,    25,    26,   715,    28,    29,   716,    31,   717,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   718,    48,
       0,     0,    50,   719,     0,    53,   720,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     365,   366,   367,   238,    70,     0,     0,     0,   240,   241,
     242,   368,   243,   244,   245,   369,     0,   370,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,     0,     0,     0,   246,   381,     0,     0,     0,     0,
       0,   248,     0,     0,     0,     0,   326,   187,     6,     0,
    1554,     0,     0,   251,   188,   189,   190,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,  2053,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,     0,     0,     0,   228,    21,     0,
     229,     0,     0,     0,     0,   230,     0,     0,   231,     0,
       0,   232,     0,   233,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,    49,     0,     0,   235,     0,   236,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,   701,
       0,   702,     0,     0,     0,     0,     0,  1685,     0,     0,
       0,     0,     0,     0,     0,   237,     0,     0,     0,   238,
     239,     0,     0,     0,   240,   241,   242,     0,   243,   244,
     245,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,   326,   187,   150,   344,  1667,     0,     0,   251,
     188,   189,   190,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   380,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   220,   221,   222,   223,   354,
     355,   356,   357,   224,     0,     0,     0,   358,   359,   360,
       0,     0,   361,     0,   362,   225,   226,   227,     0,     0,
       0,     0,     0,   228,    21,   363,   229,     0,   364,   187,
     150,   344,     0,     0,     0,     0,   188,   189,   190,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   380,   209,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,  1558,   346,   347,   348,   349,   350,   351,   352,
     353,   220,   221,   222,   223,   354,   355,   356,   357,   224,
       0,     0,     0,   358,   359,   360,     0,     0,   361,     0,
     362,   225,   226,   227,     0,     0,     0,     0,     0,   228,
      21,   363,   229,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,   365,   366,   367,   238,     0,     0,     0,     0,
     240,   241,   242,   368,   243,   244,   245,   369,     0,   370,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   381,     0,     0,
       0,     0,     0,   248,     0,     0,     0,     0,   326,     0,
       0,     0,  1835,     0,     0,   251,     0,     0,     0,     0,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,   237,   365,   366,
     367,   238,   732,     0,     0,     0,   240,   241,   242,   368,
     243,   244,   245,   369,     0,   370,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   381,     0,     0,     0,     0,     0,   248,
       0,     0,     0,     0,   326,   187,     6,     0,  1718,     0,
       0,   251,   188,   189,   190,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,     7,     8,     0,   228,    21,     0,   229,     0,
       0,     0,     0,   230,     0,     0,   231,     0,     0,   232,
       0,   233,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,    49,     0,     0,   235,     0,   236,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
     714,    25,    26,   715,    28,    29,   716,    31,   717,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     0,
       0,    42,     0,     0,     0,     0,     0,   718,    48,     0,
       0,    50,   719,   237,    53,   720,     0,   238,   239,     0,
       0,     0,   240,   241,   242,     0,   243,   244,   245,     0,
       0,     0,   107,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597,  1822,
       0,     0,     0,     0,     0,   248,     0,    84,    85,    86,
     599,   187,     6,     0,   290,     0,     0,   251,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2116,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,     0,   229,     0,     0,     0,     0,   230,
       0,     0,   231,     0,     0,   232,     0,   233,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,    49,     0,
       0,   235,     0,   236,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,  1803,     0,     0,
       0,  1804,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,     0,   238,   239,     0,     0,     0,   240,   241,
     242,     0,   243,   244,   245,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   435,     0,     0,     0,     0,
       0,   248,   187,   150,   344,     0,   326,     0,     0,   188,
     189,   190,     0,   251,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   380,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   220,   221,   222,   223,   354,   355,
     356,   357,   224,     0,     0,     0,   358,   359,   360,     0,
       0,   361,     0,   362,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,   363,   229,     0,   364,   187,   150,
       0,     0,     0,     0,     0,   188,   189,   190,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   380,   209,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,     0,     0,     0,     0,     0,   228,    21,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   365,   366,   367,   238,     0,     0,     0,     0,   240,
     241,   242,   368,   243,   244,   245,   369,     0,   370,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   381,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,   326,     0,     0,
       0,     0,     0,     0,   251,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,  1830,     0,     0,   237,  1831,     0,     0,
     238,     0,     0,     0,     0,   240,   241,   242,     0,   243,
     244,   245,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   381,     0,     0,     0,     0,     0,   248,     0,
       0,     0,     0,   326,   187,   150,     0,   579,     0,     0,
     251,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   380,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,   187,   150,     0,   228,    21,     0,   229,   188,   189,
     190,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     380,   209,   210,   211,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,     0,     0,     0,     0,
       0,   228,    21,     0,   229,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,   237,  1997,     0,     0,   238,  1998,     0,     0,
       0,   240,   241,   242,     0,   243,   244,   245,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,   598,     0,
       0,     0,     0,     0,   248,     0,     0,     0,     0,   599,
       0,     0,     0,   290,     0,     0,   251,     0,     0,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,   237,
       0,   552,     0,   238,     0,     0,     0,     0,   240,   241,
     242,   907,   243,   244,   245,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   381,     0,     0,     0,     0,
       0,   248,   187,   150,     0,  1272,   326,  1049,     0,   188,
     189,   190,     0,   251,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   380,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,     0,   229,   187,   150,     0,  1437,
       0,     0,     0,   188,   189,   190,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   380,   209,   210,   211,   212,
     213,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,     0,     0,     0,     0,     0,   228,    21,     0,   229,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
     237,     0,   552,     0,   238,     0,     0,     0,     0,   240,
     241,   242,   908,   243,   244,   245,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   381,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,   326,     0,     0,
       0,     0,     0,     0,   251,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,   237,     0,     0,   951,   238,     0,
       0,     0,     0,   240,   241,   242,     0,   243,   244,   245,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     381,     0,     0,     0,     0,     0,   248,   187,   150,     0,
    1496,   326,     0,     0,   188,   189,   190,     0,   251,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   380,   209,   210,   211,
     212,   213,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,     0,     0,   187,   150,     0,   228,    21,     0,
     229,   188,   189,   190,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   380,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,     0,
       0,     0,     0,     0,   228,    21,     0,   229,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,   237,     0,     0,     0,   238,
    1098,     0,     0,     0,   240,   241,   242,     0,   243,   244,
     245,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   381,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,   251,
       0,     0,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,   237,     0,   552,     0,   238,     0,     0,     0,
       0,   240,   241,   242,  1108,   243,   244,   245,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   381,     0,
       0,     0,     0,     0,   248,   187,   150,     0,     0,   326,
    1553,     0,   188,   189,   190,     0,   251,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   380,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
       0,     0,   187,   150,     0,   228,    21,     0,   229,   188,
     189,   190,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   380,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,     0,
       0,     0,   228,    21,     0,   229,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,   237,     0,     0,     0,   238,  1109,     0,
       0,     0,   240,   241,   242,     0,   243,   244,   245,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   381,
       0,     0,     0,     0,     0,   248,     0,     0,     0,     0,
     326,  1878,     0,     0,     0,     0,     0,   251,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,   238,     0,     0,     0,     0,   240,
     241,   242,     0,   243,   244,   245,     0,     0,     0,   107,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   381,     0,     0,     0,
       0,     0,   248,    -4,    -4,    -4,     0,   326,     0,    -4,
      -4,     0,    -4,     0,   251,     0,     0,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,     9,    10,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,     0,    17,    18,     0,
      19,    20,     0,    21,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,    37,    38,    39,    40,    41,
       0,    42,     0,    43,    44,    45,    46,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    79,    80,    81,     0,     0,
       0,    82,     0,     0,     0,     0,    83,    84,    85,    86,
     150,   344,    87,     0,    88,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
     150,   344,     0,     0,     0,     0,     0,   106,     0,   107,
       0,     0,   345,   346,   347,   348,   349,   350,   351,   352,
     353,     0,     0,     0,     0,   354,   355,   356,   357,     0,
     374,   344,     0,   358,   359,   360,     0,     0,   361,     0,
     362,     0,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   363,     0,     0,   364,   354,   355,   356,   357,     0,
       0,   344,     0,   358,   359,   360,     0,     0,   361,     0,
     362,     0,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   363,     0,     0,   364,   354,   355,   356,   357,     0,
       0,   393,     0,   358,   359,   360,     0,     0,   361,     0,
     362,     0,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   363,     0,     0,   364,   354,   355,   356,   357,     0,
       0,     0,     0,   358,   359,   360,     0,     0,   361,     0,
     362,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,     0,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,   366,
     367,     0,     0,     0,     0,     0,     0,     0,     0,   368,
       0,     0,     0,   369,     0,   370,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,   366,
     367,     0,     0,     0,     0,     0,     0,     0,     0,   368,
       0,     0,     0,   369,     0,   370,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,   366,
     367,     0,     0,     0,     0,     0,     0,     0,     0,   368,
       0,     0,     0,   369,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,   366,
     367,     0,     0,     0,     0,     0,     0,     0,     0,   368,
       0,     0,     0,   369,     0,   370,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1115,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1116,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1118,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1226,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1247,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1333,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1431,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1432,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1474,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1599,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1600,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1601,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1607,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1608,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1609,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1610,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1747,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1868,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1869,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1897,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1898,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1899,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1900,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1901,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1965,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2022,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2023,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2035,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2036,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2037,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2038,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2039,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2071,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2101,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2106,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2107,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2108,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2109,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2110,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2111,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2153,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2154,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2155,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2156,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,  1031,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,  1127,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,  1206,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,  1278,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,  1433,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,  1502,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,  1503,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,  1504,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,  1505,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
    1801,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,  1812,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,  1849,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,  1887,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,  1888,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,  1889,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,  1890,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,  1892,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,  1916,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,  1931,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
    1986,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,  2003,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,  2012,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,  2013,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,  2033,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,  2087,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,  2129,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,  2151,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,     0,  2177,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,  2178,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,     0,     0,
    2179,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,  2180,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,     0,     0,  2181,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,     0,     0,  2182,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,     0,   677,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,     0,   899,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
       0,  1909,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,   701,     0,   702,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,   957,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,  1005,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,  1150,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,  1219,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,  1220,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,     0,     0,
    1224,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   676,   548,   549,   550,   551,     0,
       0,     0,     0,   552,     0,     0,     0,  1225,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   676,   548,   549,   550,   551,     0,     0,     0,     0,
     552,     0,     0,     0,  1314,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   676,   548,
     549,   550,   551,     0,     0,     0,     0,   552,     0,     0,
       0,  1330,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   676,   548,   549,   550,   551,
       0,     0,     0,     0,   552,     0,     0,     0,  1534,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,     0,     0,  1622,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   676,
     548,   549,   550,   551,     0,     0,     0,     0,   552,     0,
       0,     0,  1673,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   676,   548,   549,   550,
     551,     0,     0,     0,     0,   552,     0,     0,     0,  1860,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   676,   548,   549,   550,   551,     0,     0,
       0,     0,   552,     0,     0,     0,  1903,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     676,   548,   549,   550,   551,     0,     0,     0,     0,   552,
       0,     0,     0,  1917,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   753,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   754,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   756,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   758,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   759,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   761,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   763,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   764,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   765,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   766,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   767,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   768,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   770,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   771,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   772,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   837,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   870,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   928,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   946,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   947,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   948,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   949,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   955,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,   956,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,   990,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1004,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1066,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1071,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1084,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1149,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1158,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1159,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1160,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1174,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1175,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1176,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1205,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1207,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1208,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1209,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1210,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1211,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1212,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1213,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1218,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1313,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1329,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1539,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1611,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1621,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1733,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1739,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1740,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1741,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1742,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1746,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1802,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1811,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1834,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1902,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  1963,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  1964,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552,     0,  2100,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   676,   548,   549,   550,   551,     0,     0,     0,
       0,   552,     0,  2148,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   676,   548,   549,
     550,   551,     0,     0,     0,     0,   552
};

static const yytype_int16 yycheck[] =
{
       3,     3,   594,   595,  1204,  1200,     5,   283,   132,  1701,
       4,  1703,     4,     6,     4,  1661,     4,     6,    21,     6,
       5,    21,     4,     6,     4,     6,     5,     5,     5,     5,
       4,     6,     4,  1879,   295,     6,   148,    97,     4,     7,
       4,     4,    97,     4,    47,     4,  1689,     6,   145,     4,
       4,     4,   313,    97,   696,     9,   239,     4,     6,   226,
     227,   173,   704,   118,   247,    98,     7,   100,   239,     9,
     241,    74,    94,     0,   118,    97,   247,   189,   190,    82,
     247,     6,   226,   227,    87,   238,     4,   240,   183,   184,
     185,   226,   227,    60,    61,    98,    63,   226,   227,   132,
       9,     9,   241,   247,    84,     7,   226,   227,   247,  1752,
     681,    14,   247,   239,   243,   241,   377,     9,   379,     6,
     128,   247,   155,   244,  1770,   386,   247,   247,   239,   132,
     241,   133,    91,   239,   137,   138,   247,   145,   241,     6,
     711,   247,   145,     9,   247,   153,   154,   155,   226,   227,
     238,   159,   160,   156,   239,   158,   239,   238,   729,   244,
     163,     9,   235,   236,   247,   168,   737,   226,   227,   247,
     128,   244,   175,   268,   269,   270,   179,   176,   161,   182,
     183,   184,   185,   186,  2030,   238,   161,   145,   247,   163,
     164,   165,   166,     7,     6,   153,   154,   155,   176,   176,
     176,   159,   160,     6,   184,     7,   188,   173,   174,   173,
     174,   306,   307,   308,    94,   226,   227,    97,   210,    99,
     210,   239,   210,   241,   238,   320,   321,     8,   242,   247,
     210,   234,   221,   222,   239,   243,   247,   238,   210,   226,
     227,   242,   247,   242,   247,   238,   240,   250,   251,   242,
     242,   251,   246,   132,  1449,   245,   210,   242,   137,   138,
    1906,   264,   242,   242,   267,   268,   269,   270,   839,   243,
     242,   242,   275,   276,   277,   238,   244,   238,   281,   242,
     283,   235,   236,   238,   238,   238,   240,   242,   242,   242,
     244,   238,   210,     6,   242,   242,   175,   238,   238,   240,
     240,   226,   227,   306,   307,   308,   239,   186,   241,   211,
     212,   213,   214,  1959,   247,   235,   236,   320,   321,   286,
     287,   239,   583,   241,   585,   586,     6,   294,   295,   238,
     238,   240,   240,   235,   236,   244,   244,     4,     6,   226,
     227,   602,   244,   235,   236,    97,   238,    99,   240,   241,
     226,   227,   244,     7,   221,   222,   238,     7,   240,   392,
     242,     6,  1004,  1005,   226,   227,   226,   227,    47,   235,
     236,   247,   238,  2065,   240,   239,   238,   240,   244,   640,
     242,   384,   242,   247,     4,   388,   389,   235,   236,   238,
     238,   242,   240,   226,   227,   246,   244,   211,   212,   213,
     214,   404,   240,   500,     7,   226,   227,   410,   238,   211,
     212,   213,   214,   238,   247,   239,   677,   239,   513,   514,
     515,   516,   238,   247,   240,   247,   247,    91,   431,   244,
      94,   246,   435,    97,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   226,   227,     6,     7,   237,  2103,   226,   227,
     226,   227,   243,     6,     7,   132,   133,   134,   135,   226,
     227,    91,   238,   247,   242,    95,   242,   226,   227,   482,
     147,   101,   102,   150,   104,   105,   489,   490,   521,    94,
     247,   494,    97,   496,   497,   498,   499,   500,   247,   502,
     179,   239,   122,   241,   238,   384,   226,   227,   242,   512,
     513,   514,   515,   516,   517,   518,   519,   520,  2164,   522,
     520,   524,   522,   238,  1166,   243,  1168,   247,  1170,   247,
    1172,   226,   227,   226,   227,   568,   569,   570,   571,   243,
     226,   227,   238,   247,   547,   226,   227,   238,   226,   227,
     553,   648,   247,   238,   247,   234,   242,   211,   212,   213,
     214,   211,   212,   213,   214,  1136,   247,  1138,   238,   247,
     226,   227,   696,   226,   227,   578,   579,  1148,   226,   227,
     238,   235,   236,   226,   227,   235,   236,   238,   267,   231,
     232,   247,   594,   595,   247,   237,   275,   276,   277,   247,
     235,   236,   281,   111,   247,   235,   236,   242,   211,   212,
     213,   214,   242,    94,   238,   494,    97,   496,    99,   498,
     499,   624,   625,   626,    94,   592,   593,    97,   661,    99,
     597,   238,   235,   236,   132,   133,   238,   243,   517,   518,
     138,   247,   903,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   128,   656,   657,   658,   659,   660,   238,   662,
     663,   664,   665,   666,    91,   665,   669,    94,    97,   145,
      97,   128,    99,   244,     6,   678,   247,   153,   154,   155,
     132,   133,   242,   159,   160,   238,   138,   128,   145,  1260,
       8,   239,   238,   241,   242,  1266,   153,   154,   155,   238,
     703,   240,   159,   160,   145,   708,   238,   243,   240,   388,
     389,   247,   153,   154,   155,   748,   243,   242,   159,   160,
     247,    91,   725,   726,    94,   404,   238,    97,   731,    99,
      91,   734,   735,    94,   226,   227,    97,   740,    99,   742,
     242,  1312,   866,   238,   238,   240,   240,   750,   242,   752,
     228,   229,   230,   231,   232,    97,   243,  1328,   243,   237,
     247,    94,   247,  1334,     4,     5,   238,   243,   647,   242,
     649,   650,   651,   652,   653,   654,    97,   656,   657,   658,
     659,    94,    97,   662,   663,   664,   243,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      94,   238,   243,   240,   237,   808,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    97,     4,    99,   497,    59,
      60,    61,    62,    97,     4,    99,   238,    67,    68,    69,
     242,     4,    72,   512,    74,   226,   227,   228,   229,   230,
     231,   232,     4,   238,     6,    85,   237,   242,    88,   243,
       4,     6,   855,   247,  2054,   734,   243,   243,   243,     6,
     247,   247,   247,   742,   243,   868,  1508,   243,   247,   238,
     243,   247,   243,   876,   247,   243,   247,   240,  1520,   247,
    1004,  1005,   238,   243,   243,   125,   243,   247,   247,   243,
     247,   243,   238,   247,  2089,   247,   899,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   238,   243,  2117,   243,   237,
     247,     6,   247,   243,   243,   243,   243,   247,   247,   243,
     247,   243,   243,   247,   243,   247,   247,   243,   247,   906,
     243,   247,   246,  2138,   247,   243,   913,   243,   238,   247,
     917,   247,   192,   193,   194,   243,   243,   243,   238,   247,
     247,   247,     8,   203,   243,   240,   242,   207,   247,   209,
     210,     6,   238,  1006,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     246,     9,   118,   996,   237,   235,   236,   243,     4,   243,
     242,   247,   242,   247,   244,   243,   243,  1010,   242,   247,
     247,   243,  1015,   243,   238,   247,   238,   247,  1294,  1022,
    1023,  1024,  1025,   243,   243,  1149,  1150,   247,   247,   243,
     243,   243,  1035,   247,   247,   247,   243,   243,   238,   238,
     247,   247,     4,     5,   239,   238,   241,   242,   238,   238,
     242,   238,   238,   238,  1646,  1647,   238,   238,   242,   238,
     238,  1064,  1065,   238,  1067,   242,  1069,  1070,   238,  1072,
     238,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
     238,   238,  1085,     6,    46,    47,    48,    49,    50,    51,
      52,    53,    54,  1060,   238,   238,   238,    59,    60,    61,
      62,   238,   240,     6,     6,    67,    68,    69,   242,   242,
      72,   242,    74,   240,     6,   240,   240,  1120,  1121,  1122,
       6,   242,   176,    85,   238,   238,    88,   238,   238,   238,
     238,     6,     6,   240,     6,     6,   242,   242,     7,  1142,
       6,   242,     6,   242,    87,   243,   239,   247,     7,     6,
     247,     6,     6,  1156,  1157,   239,  1035,    64,    64,   242,
      64,   237,   244,   125,    64,     4,     7,     7,     6,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,     6,     6,  1313,
    1314,   237,   239,   239,     6,   241,     7,   876,   242,     6,
     173,     7,     6,     6,     6,   242,   239,   241,     6,     6,
     242,  1214,   242,   242,   242,     7,   240,   244,   238,     4,
       6,   240,     6,     6,  1227,  1228,  1229,     6,   239,     7,
     192,   193,   194,     7,  1495,  1238,   176,     7,  1499,  1515,
    1243,   203,  1121,  1122,  1247,   207,     7,   209,   210,   176,
       7,     7,     7,  1256,   176,  1258,     7,     7,  1261,     7,
       7,     7,     7,     7,     7,     7,   242,     6,   239,   241,
     247,     7,  1275,   247,   242,   242,   242,   239,   247,   241,
     242,   242,   247,   239,   244,     7,     4,   242,   239,     6,
     247,  1294,   239,   247,   239,   247,   244,   239,   247,   243,
     128,     7,   243,  1336,     6,  1338,     7,     7,     7,   244,
     239,  1314,     9,   239,   247,   247,   247,   996,   239,   244,
    1912,   241,   246,     7,   148,   243,   242,     6,     6,     4,
      46,    46,   244,   238,   244,  1338,  1015,   238,     4,   238,
     238,   238,     7,   238,     7,    99,  1349,     7,   244,   239,
       8,     7,  1355,   247,     7,     7,     6,   109,     7,     7,
       7,     7,     7,     4,  1243,     4,   242,     7,  1247,     6,
     238,     6,   242,     7,     7,     7,     7,  1256,     7,  1258,
       7,     7,  1261,     6,  1508,  1064,  1065,     6,  1067,     6,
    1069,  1070,    97,  1072,     7,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,     6,  1408,  1409,  1410,     6,     4,
       4,  1414,     4,  1416,   245,  1418,   239,  1420,   247,  1422,
    1423,  1424,   247,   243,  1521,  1522,   242,   242,   242,     6,
       6,     6,   240,     7,     6,  1314,  1439,     6,   238,  1715,
       6,  1120,   238,   242,     6,     6,   247,  1450,   241,   244,
       6,     6,   242,   242,   122,  1458,     6,     6,  1461,  1492,
     242,   242,     6,  1142,   176,   242,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     5,   239,  1156,   247,   239,
       6,  1448,     4,     6,     4,     6,   172,     4,     7,   242,
       6,     6,     6,   242,     6,     6,  1620,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,  1515,   242,   242,   242,   237,   240,  1521,  1522,
       6,  1554,   242,   242,  1527,     6,     4,     7,   242,   242,
       6,   242,   242,   242,   238,  1214,   239,     6,     6,   247,
     247,     6,     6,  1546,     6,   238,   244,   238,  1227,  1228,
    1229,  1554,   247,   247,   242,     7,  1559,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,     6,     6,     6,     6,   237,
       6,   239,    95,     5,   239,   242,     6,     6,   242,     6,
       6,     6,     6,     6,     6,     6,  1275,     6,     6,     6,
       6,   239,     4,  1570,   247,   247,     6,  1731,     6,  1642,
       6,   247,     7,     5,   242,     6,     6,   247,   242,     6,
     242,  1718,   242,     7,   242,     6,   171,   243,   243,     6,
     242,   239,   243,   243,   243,  1638,  1639,     6,   244,     7,
       6,     6,     6,     6,  1646,  1647,   242,     6,     6,  1682,
       6,     6,     6,     6,     6,   243,  1689,  1690,  1661,  1338,
    1921,     6,   242,     6,  1667,   174,   239,  1546,     6,     6,
    1349,   242,  1948,  1676,  1707,   243,  1355,     6,   243,   238,
     243,  1684,   242,     6,  1687,   242,   128,     6,   242,   242,
       6,     6,   239,     6,   242,  1662,  1663,  1664,  1665,  1666,
    1667,  1704,     6,     6,     6,     6,     6,     6,  1711,     6,
       6,     6,  1715,   242,  1717,  1718,   243,     6,   243,     6,
       6,     6,     6,     6,   242,     6,     6,  1327,  2067,  1408,
    1409,  1410,   242,  1564,  1381,  1414,   428,  1416,  1880,  1418,
    1348,  1420,  1846,  1422,  1423,  1424,  1627,     3,     3,  1752,
       3,     3,  1908,  1390,   567,  2016,  1489,     3,  1689,  1711,
    1439,  1522,    -1,    -1,   734,    -1,    -1,  1770,    -1,    -1,
      -1,  1450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1684,    -1,  1810,  1687,    -1,
      -1,    -1,    -1,    -1,    -1,  1848,    -1,    -1,    -1,  1822,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,  1527,    -1,
      -1,    -1,  1885,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1871,    -1,
      -1,    -1,    -1,    -1,    -1,  1554,    -1,    -1,  1881,    -1,
      -1,    -1,    -1,  1886,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,  1906,    -1,    -1,  1909,    67,    68,    69,
    1912,    -1,    72,    -1,    74,    -1,    -1,  1920,    -1,    -1,
      -1,  1924,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1948,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1959,    -1,  1925,  1926,
    1927,  1928,  1929,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1661,    -1,    -1,    -1,    -1,  1990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,  2031,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,  1989,    -1,    -1,  1704,  1993,    13,    14,    -1,
      -1,    -1,   192,   193,   194,     6,    -1,    -1,  1717,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,   209,
     210,    -1,    -1,    -1,  2057,  2058,  2059,  2060,  2061,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2041,    -1,    -1,    -1,  2045,    -1,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1770,    -1,    -1,  2061,    -1,    -1,    -1,    -1,    -1,
    2103,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,  2122,
      -1,   107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,  1810,   118,   119,    -1,    -1,   122,   123,    -1,   125,
     126,    -1,    -1,    -1,  2147,  2112,  2113,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,  2164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2174,  2175,   132,    -1,    -1,    -1,   136,    -1,    -1,
      -1,   140,   168,   169,   170,    -1,    -1,    -1,  2191,    -1,
      -1,    -1,  1871,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,  1881,   162,   163,   164,   165,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,  1906,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1920,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,  2147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1959,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,   250,    -1,    -1,    -1,  2174,  2175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,   264,    -1,    -1,    -1,    -1,
      -1,  1990,  2191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     289,   290,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,   326,   168,    -1,
      -1,   330,   331,   332,    -1,   334,    -1,    -1,    -1,   338,
     339,   340,   182,    -1,   343,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   381,    -1,  2103,    -1,   385,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,   402,    -1,    -1,    -1,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,   415,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,  2164,    -1,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,    -1,   492,   493,    -1,   495,    -1,    -1,    -1,
      -1,    -1,   501,    -1,    -1,    -1,   505,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,    -1,    -1,    -1,    -1,   524,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,    -1,   554,   555,    -1,    -1,    -1,
      -1,    -1,   561,   562,   563,    -1,    -1,    -1,    -1,   568,
     569,   570,   571,   572,    -1,   574,    -1,   576,    -1,   578,
     579,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,   597,   598,
     599,    -1,    -1,    -1,   603,   604,   605,   606,   607,   608,
     609,   610,   611,    -1,    -1,    -1,    -1,   616,    -1,   618,
      -1,   620,     6,    -1,    -1,   624,   625,   626,    -1,    -1,
     629,   630,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,   489,
     490,    -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     669,    -1,    -1,    -1,    -1,   674,    -1,   676,    -1,   519,
     679,   680,    -1,    -1,   524,    -1,    -1,    -1,   687,    -1,
      -1,    -1,    -1,    -1,   693,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   703,    -1,    -1,   547,    -1,    -1,
     709,   710,    -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   725,    -1,   727,   728,
      -1,    -1,   731,   732,    -1,    -1,    -1,   736,   578,   579,
      -1,    -1,    -1,    -1,   743,    -1,    -1,    -1,   747,    -1,
      -1,   750,    -1,   752,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,   578,   579,
      -1,    -1,    -1,    -1,   773,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   624,   625,   626,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   808,
      -1,    -1,   237,    -1,   624,   625,   626,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,     6,    -1,   237,    -1,    -1,   855,    -1,    -1,   669,
      -1,    -1,    -1,   703,    -1,    -1,    -1,    -1,    -1,   868,
      -1,    -1,    -1,    -1,    -1,    -1,   875,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   725,    -1,    -1,    -1,    -1,
      -1,   731,    -1,   703,    -1,    -1,    -1,    -1,    -1,    -1,
     899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   907,   908,
     750,    -1,   752,    -1,   913,   725,    -1,    -1,    -1,    -1,
      -1,   731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     929,    -1,    -1,   932,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   951,    -1,   953,   954,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   808,    -1,
      -1,    -1,    -1,   972,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   992,    -1,    -1,   237,    -1,   808,    -1,
     999,  1000,  1001,  1002,    -1,    -1,    -1,    -1,  1007,    -1,
      -1,    -1,    -1,    -1,    -1,   855,    -1,    -1,    -1,    -1,
      -1,    -1,  1021,  1022,  1023,  1024,  1025,  1026,   868,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,   855,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   868,   899,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,     6,   237,    -1,    -1,    -1,  1085,    -1,    -1,   899,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1098,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1108,
    1109,  1110,    -1,    -1,    -1,    -1,  1115,  1116,    -1,  1118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1126,    -1,  1128,
    1129,  1130,  1131,  1132,    -1,    -1,    -1,    -1,    -1,     6,
    1139,    -1,    -1,    -1,    -1,    -1,  1145,  1146,    -1,    -1,
      -1,    -1,    -1,  1152,  1153,    -1,    -1,    -1,  1157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1167,     6,
    1169,    -1,  1171,    -1,  1173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1022,  1023,  1024,  1025,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,  1194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1022,  1023,  1024,  1025,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1238,
      -1,    -1,    -1,    -1,    -1,  1085,    -1,  1246,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,  1267,  1268,
     237,    -1,  1271,    -1,    -1,  1085,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1285,     6,    -1,  1288,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,  1315,  1157,    -1,    -1,
       6,    -1,    -1,  1322,  1323,  1324,  1325,    -1,    -1,    -1,
      -1,    -1,  1331,    -1,  1333,    -1,  1335,  1336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1157,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,   406,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,  1238,    -1,
     237,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,  1238,    -1,
      -1,  1430,  1431,  1432,    -1,    -1,    -1,    -1,    -1,    -1,
    1439,    -1,  1441,    -1,    -1,    -1,    -1,    -1,    -1,  1448,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1461,    -1,    -1,    -1,    -1,  1466,    -1,    -1,
      -1,    -1,   502,    -1,    -1,  1474,  1475,  1476,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1494,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
    1519,    -1,    -1,    -1,    -1,    -1,  1525,  1526,   558,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1568,
    1569,    -1,    -1,    -1,    -1,    -1,  1575,  1576,    -1,    -1,
      -1,    -1,    -1,  1582,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1599,  1600,  1601,    -1,    -1,    -1,    -1,    -1,  1607,  1608,
    1609,  1610,    -1,    -1,    -1,    -1,    -1,    -1,  1617,  1618,
      -1,  1461,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
    1629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1638,
    1639,  1640,    -1,  1642,    -1,    -1,    -1,    -1,    -1,  1648,
    1649,  1461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1667,    -1,
      -1,    -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1682,    -1,    -1,  1685,    -1,    -1,    -1,
    1689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,
    1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1708,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1559,
      -1,    -1,    -1,    -1,    -1,  1724,    -1,    -1,    -1,    -1,
    1729,  1730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1744,    -1,    -1,  1747,  1748,
     780,   781,   782,   783,   784,   785,   786,   787,   788,   789,
     790,    -1,   792,   793,   794,   795,    -1,   797,   798,   799,
     800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   811,    -1,   813,  1783,    -1,    -1,    -1,    -1,    -1,
     820,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1638,  1639,
      -1,   831,   832,    -1,    -1,  1804,    -1,    -1,    -1,    -1,
     840,    -1,    -1,    -1,  1813,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1822,    -1,    -1,    -1,  1667,  1638,  1639,
      -1,    -1,  1831,  1832,    -1,    -1,  1835,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1868,
    1869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1884,    -1,    -1,    -1,    -1,
      -1,    -1,  1891,    -1,    -1,    -1,    -1,    -1,  1897,  1898,
    1899,  1900,  1901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1909,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,   958,   959,
     960,    -1,    -1,  1932,   964,   965,    -1,    -1,   968,   969,
     970,   971,    -1,   973,    -1,    -1,    -1,    -1,   978,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1956,    -1,    -1,
      -1,    -1,    -1,  1962,    -1,    -1,  1965,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,  1835,    -1,    -1,    -1,  1998,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,  2022,  2023,  1835,    -1,    -1,  1058,  1059,
      -1,    -1,    -1,    -1,    -1,  2034,  2035,  2036,  2037,  2038,
    2039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2052,    -1,    -1,    -1,    -1,  2057,  2058,
    2059,  2060,  2061,    -1,    -1,    -1,    -1,    -1,  2067,  1909,
      -1,    -1,  2071,    -1,    -1,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1909,
     132,    -1,  2101,    -1,    -1,    -1,    -1,  2106,  2107,  2108,
    2109,  2110,  2111,    -1,  1924,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2122,  1154,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,  2153,  2154,  2155,  2156,  2157,  2158,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     7,
     222,   223,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,  2057,  2058,  2059,
    2060,  2061,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,   239,  2057,  2058,  2059,
    2060,  2061,     8,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2122,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,   237,    -1,  1337,    -1,    -1,
      -1,    -1,  2122,   345,   346,   347,    -1,    -1,    -1,   351,
     352,   353,   354,   355,   356,   357,    -1,   359,    -1,    -1,
      -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
    1370,  1371,  1372,  1373,  1374,    -1,    -1,    -1,   380,  1379,
    1380,    -1,  1382,    -1,    -1,    -1,    -1,    -1,  1388,    -1,
      -1,    -1,    -1,    -1,  1394,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1480,     8,  1482,    -1,    -1,    -1,  1486,    -1,  1488,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,  1619,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,
     123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1720,    -1,    -1,  1723,    -1,    -1,    -1,    -1,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,     8,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,  1771,  1772,    -1,    -1,   238,    -1,    -1,    -1,   242,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,  1839,
    1840,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,   867,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,  1882,    88,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,   142,   143,     8,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,   242,    -1,    -1,
     245,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
    1052,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    13,    14,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,    88,
      -1,  2131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1143,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,   125,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,   118,   119,    -1,    -1,   122,   123,    -1,   125,   126,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   144,     8,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   235,   236,    -1,   238,
      -1,   240,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,  1298,  1299,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,  1398,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
     242,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,  1558,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,    -1,   242,    -1,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,    14,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,   118,   119,    -1,    -1,   122,   123,   191,
     125,   126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,   168,   169,   170,   238,     3,     4,    -1,
     242,   243,    -1,   245,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,
      76,    77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,    -1,   122,   123,   191,   125,   126,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,
     169,   170,   238,     3,     4,    -1,   242,    -1,    -1,   245,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,
      13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,   122,
     123,   191,   125,   126,    -1,   195,   196,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
     210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,     3,
       4,    -1,   242,    -1,    -1,   245,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    75,    76,    77,    -1,    -1,    13,    14,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,   118,   119,    -1,    -1,   122,   123,   191,   125,   126,
      -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   168,   169,   170,   238,     3,     4,    -1,   242,    -1,
      -1,   245,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,    -1,    -1,   243,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    75,    76,    77,    -1,    -1,    13,    14,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,   118,   119,    -1,    -1,   122,   123,   191,
     125,   126,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,   168,   169,   170,   238,     3,     4,    -1,
     242,    -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    75,
      76,    77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,    -1,   122,   123,   191,   125,   126,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   168,
     169,   170,   238,     3,     4,    -1,   242,    -1,    -1,   245,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    75,    76,    77,    -1,    -1,
      13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,    -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,   122,
     123,   191,   125,   126,    -1,   195,   196,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
     210,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,   168,   169,   170,   238,     3,
       4,    -1,   242,    -1,    -1,   245,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    75,    76,    77,    -1,    -1,    13,    14,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,   118,   119,    -1,    -1,   122,   123,   191,   125,   126,
      -1,   195,   196,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,   210,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   168,   169,   170,   238,     3,     4,    -1,   242,    -1,
      -1,   245,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
     131,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,     5,   242,   128,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    13,    14,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,   122,   123,    -1,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,   194,   195,   144,    -1,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,   238,     3,     4,    -1,
     242,    -1,    -1,   245,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,   243,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,   150,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,   239,
      -1,   241,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,   238,     3,     4,     5,   242,    -1,    -1,   245,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    -1,    88,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,    -1,    -1,   245,    -1,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,   191,   192,   193,
     194,   195,   247,    -1,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,   238,     3,     4,    -1,   242,    -1,
      -1,   245,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,    -1,   123,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,
      -1,   122,   123,   191,   125,   126,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   168,   169,   170,
     238,     3,     4,    -1,   242,    -1,    -1,   245,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,   201,
     202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,     3,     4,     5,    -1,   238,    -1,    -1,    10,
      11,    12,    -1,   245,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    88,     3,     4,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,   191,   247,    -1,    -1,
     195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,   204,
     205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,   238,     3,     4,    -1,   242,    -1,    -1,
     245,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,     3,     4,    -1,    83,    84,    -1,    86,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,   191,   243,    -1,    -1,   195,   247,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   242,    -1,    -1,   245,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   191,
      -1,   237,    -1,   195,    -1,    -1,    -1,    -1,   200,   201,
     202,   247,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,     3,     4,    -1,     6,   238,   239,    -1,    10,
      11,    12,    -1,   245,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
     191,    -1,   237,    -1,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,   247,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,   247,   195,    -1,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,     3,     4,    -1,
       6,   238,    -1,    -1,    10,    11,    12,    -1,   245,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,     3,     4,    -1,    83,    84,    -1,
      86,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,
     247,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,   191,    -1,   237,    -1,   195,    -1,    -1,    -1,
      -1,   200,   201,   202,   247,   204,   205,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,     3,     4,    -1,    -1,   238,
     239,    -1,    10,    11,    12,    -1,   245,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,     3,     4,    -1,    83,    84,    -1,    86,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   247,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
     238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,   200,
     201,   202,    -1,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,    64,    65,    66,    -1,   238,    -1,    70,
      71,    -1,    73,    -1,   245,    -1,    -1,    78,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,   106,   107,   108,   109,   110,
      -1,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,   123,   124,   125,   126,   127,    -1,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,     4,    -1,   156,   157,   158,    -1,    -1,
      -1,   162,    13,    14,    -1,    -1,   167,   168,   169,   170,
      -1,    -1,   173,    -1,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    44,    45,    -1,   197,   198,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,   210,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,   106,   107,   108,   109,   110,
      -1,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,   123,   124,   125,   126,   127,    -1,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
       4,     5,   173,    -1,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,   208,    -1,   210,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
       4,     5,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    85,    -1,    -1,    88,    59,    60,    61,    62,    -1,
      -1,     5,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    85,    -1,    -1,    88,    59,    60,    61,    62,    -1,
      -1,   125,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    85,    -1,    -1,    88,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,   209,   215,   216,   217,   218,
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
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   215,   216,   217,   218,   219,   220,   221,   222,   223,
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
     237,    -1,    -1,    -1,    -1,   242,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,   242,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,   242,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,   237,    -1,   239,    -1,   241,   215,
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
     332,   357,   358,   242,   246,    14,    97,   238,   238,     6,
     242,     6,     6,     6,     6,   238,     6,     6,   240,   240,
       4,   334,   358,   238,   240,   272,   272,   238,   242,   238,
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
     341,   343,   358,   238,   242,    97,    97,   118,    94,    97,
      99,    91,    94,    97,    99,    94,    97,    99,    94,    97,
     238,    94,   148,   173,   189,   190,   242,   226,   227,   238,
     242,   338,   339,   338,   242,   242,   338,     4,    91,    95,
     101,   102,   104,   105,   122,   238,    97,    99,    97,    94,
       4,    84,   184,   242,   358,     4,     6,    91,    94,    97,
      94,    97,     4,     4,     4,     5,   238,   341,   342,     4,
     238,   238,   238,     4,   242,   345,   358,     4,   238,   238,
     238,     6,     6,   240,     5,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    61,    62,    67,    68,
      69,    72,    74,    85,    88,   192,   193,   194,   203,   207,
     209,   349,   358,   238,     4,   349,     5,   242,     5,   242,
      32,   227,   327,   358,   240,   238,   242,     6,   238,   242,
       6,   246,     7,   125,   184,   211,   212,   213,   214,   235,
     236,   238,   240,   244,   270,   271,   272,   327,   348,   349,
     358,     4,   296,   297,   298,   242,     6,   327,   348,   349,
     358,   348,   327,   348,   355,   356,   358,   276,   280,   238,
     337,     9,   349,   358,   327,   227,   327,   343,   344,   327,
     327,   238,   327,   344,   327,   327,   238,   327,   344,   327,
     327,   327,   327,   327,   327,   348,   327,   327,   327,   341,
     238,   344,   342,   342,   342,   348,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   238,
     240,   272,   272,   272,   272,   272,   272,   238,   272,   272,
     238,   272,   272,     5,   176,   242,     5,   176,     5,   176,
       5,   176,   118,    91,    94,    97,    99,   238,   272,   272,
     238,   238,   238,   327,   242,   327,   343,   327,   327,   243,
     344,   334,   358,     8,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   237,     9,   238,   240,   244,   271,   272,   327,
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
       6,   298,     6,   298,   272,   327,   228,   242,     9,   238,
     240,   244,   348,   327,   298,   341,   341,   242,   349,    91,
      94,    97,    99,     7,   327,   327,     4,   173,   174,   341,
       6,   239,   241,   242,   273,     6,   242,     6,     9,   238,
     240,   244,   358,   243,    91,    94,    97,    99,   118,   123,
     126,   295,   327,     6,   239,   247,     9,   238,   240,   244,
     239,   247,   247,   239,   247,     9,   238,   244,   241,   247,
     275,   241,   275,    87,   336,   333,   358,   247,   247,   239,
     228,   243,   247,   239,   239,   327,   239,   243,   239,   239,
     327,   239,   243,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,     7,   327,   243,     6,     6,     6,   239,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   343,   327,   327,
     327,   327,   327,   327,   327,   343,   343,   358,   242,   327,
     327,   348,   327,   348,   341,   348,   348,   355,   327,   273,
     358,    64,   327,    64,    64,    64,   342,   342,   342,   342,
     348,   348,   343,   334,   349,   334,   344,   239,   243,   244,
     272,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   242,   327,   343,   327,   327,
     327,   327,   327,   358,   327,   327,     4,   335,   242,   273,
     239,   243,   327,   327,   327,     7,     7,   320,   320,   289,
     327,   349,   290,   327,   349,   291,   327,   349,   292,   327,
     349,   327,     6,   327,     6,   327,     6,   344,   344,   242,
     239,     6,   298,   242,   298,   298,   247,   247,   247,   338,
     338,   297,   297,   247,   327,   243,   311,   247,   298,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   239,     7,
     321,     6,     7,   327,     6,   327,   327,   243,   344,   344,
     344,     6,     6,   327,   327,   327,   239,   239,   239,   239,
     173,   247,   298,   242,     8,   239,   239,   241,   355,   348,
     355,   348,   348,   348,   348,   348,   348,   327,   348,   348,
     348,   348,   245,   351,   358,   349,   348,   348,   348,   334,
     358,   344,   243,   243,   327,   327,   298,   358,   335,   241,
     239,   131,   148,   315,   239,   243,   247,   327,     6,   242,
     242,   242,   242,   327,   239,   241,     7,   270,   271,   244,
       7,     6,   344,     7,   214,   270,   255,   358,   327,   327,
     335,   240,   242,   242,   242,   242,   238,   118,    94,    97,
      99,   243,     6,   221,   222,   252,   344,   358,   327,   327,
       4,   335,     6,   344,   327,     6,   348,   356,   358,   239,
     335,     6,   358,     6,   348,   327,   239,   240,   327,   349,
       7,   176,   327,   343,     7,     7,   239,     7,   176,     7,
       7,   239,     7,   176,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   327,   239,   242,     6,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   247,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   247,   247,
     247,   239,   241,   241,   344,   247,   247,   273,   247,   273,
     247,   247,   247,   239,   329,   273,   242,   243,   242,   242,
     242,   247,   247,   273,   273,   239,   244,   239,   244,   247,
     330,   243,     7,   335,   273,     8,     8,   344,   244,   239,
     241,   271,   238,   240,   272,   344,     7,   242,   239,   239,
     239,   327,   341,     4,   319,     6,   239,   247,   239,   247,
     239,   247,   239,   247,   239,   239,   239,   243,   243,   344,
     244,   243,   298,   243,   243,   338,   327,   327,   243,   243,
     327,   338,   128,   128,   145,   153,   154,   155,   159,   160,
     312,   313,   338,   243,   308,   239,   243,   239,   239,   239,
     239,   239,   239,   239,     7,   327,     6,   327,   239,   241,
     241,   243,   243,   243,   241,   241,   247,     7,     7,     7,
     244,   327,   243,   327,   327,     7,   244,   273,   247,   273,
     273,   239,   239,   247,   273,   273,   247,   247,   273,   273,
     273,   273,   327,   273,     9,   350,   247,   239,   247,   273,
     244,   247,   331,   241,   243,   243,   244,   238,   240,   246,
       7,   148,     6,   327,   243,   242,     6,   341,   243,   327,
     327,   327,   327,     6,     7,   270,   271,   244,   270,   271,
     349,   327,     6,     4,   242,   346,   358,   243,    46,    46,
     341,     4,   163,   164,   165,   166,   243,   258,   262,   265,
     267,   268,   244,   239,   241,   238,   327,   344,   344,   344,
     344,   327,   238,   238,   238,   238,   348,   239,   244,   239,
     241,   238,   239,   247,   244,   238,     7,   272,     4,   283,
     284,   285,   273,   273,   338,    97,    99,   341,   341,     7,
     341,    97,    99,   341,   341,     7,   341,    99,   341,   341,
     341,   341,   341,   341,   341,   341,   341,     6,     7,   344,
     327,   327,   327,   327,   243,   327,   327,   327,   341,   348,
     348,   247,   282,   327,   327,   327,   327,   327,   327,   335,
     335,   327,   239,   341,   272,   327,   327,   243,   335,   271,
     244,   271,   327,   327,   273,   243,   341,   344,     7,     7,
       7,   128,   318,     6,   270,   327,   270,   327,   270,   327,
     270,   327,     7,     7,     7,     7,     7,   243,     4,   243,
     247,   247,   247,   243,   243,   109,     4,     6,   327,   242,
       6,   238,     6,   161,     6,   161,   243,   313,   247,   312,
       7,     6,     7,     7,     7,     7,     7,     7,     7,   341,
       6,   242,     6,     6,     6,    97,     7,     6,     6,   327,
     341,   341,   341,     4,   247,     8,     8,   239,     4,     4,
     344,   348,   327,   348,   245,   247,   286,   348,   348,   335,
     348,   239,   247,   335,   242,   242,     6,   327,     6,   242,
     341,   243,   243,   243,   243,   243,   327,     6,     4,   173,
     174,   327,     6,     6,     6,     7,   345,   347,     6,   240,
     273,   272,   272,     6,   259,   238,   238,   242,   269,     6,
     335,   244,   348,   327,   241,   243,   243,   243,   243,   239,
     327,   327,   327,   327,     6,     6,   252,   335,   244,   327,
       6,   327,   335,   239,   242,   327,   349,   273,    46,   242,
     341,   349,   352,   241,   247,     6,     6,     6,   242,   242,
     122,   294,   294,   341,     6,   242,   242,     6,     6,   341,
     176,   293,   242,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   243,   273,   273,   273,   273,   273,   247,
     247,   247,   239,   273,   273,   284,   273,   247,   247,   247,
     247,   239,   273,   239,   330,     6,   273,   238,   240,   272,
       4,   239,   241,   273,     6,   243,   341,   341,   341,     4,
       6,   341,   341,   341,   341,   341,   341,   341,   242,   242,
       7,     6,     7,   327,   327,   327,   242,   242,   242,   240,
       6,   327,   341,   327,     6,     6,   327,   338,   243,     5,
     341,   242,   242,   242,   242,   242,   242,   242,   341,     6,
     344,   242,   327,   241,     6,     6,   172,   327,   327,   327,
       6,     6,     7,   273,   247,   247,   273,   247,   327,     4,
     188,   287,   288,   273,   239,   273,   331,   349,   238,   240,
     327,   298,     6,   298,   247,     6,     6,     7,   270,   271,
     244,     7,     6,   345,   243,   247,   327,   270,   242,   273,
     353,   354,   355,   353,   238,   327,   327,   340,   341,   242,
     238,     4,     6,   239,     6,     6,     6,     6,     6,   239,
     239,   239,   239,   348,   238,     4,   239,   247,   238,   341,
     349,     7,   272,   281,   327,   343,   285,   327,   327,   338,
       6,     6,     6,   327,   327,     6,    95,     6,   327,     5,
     242,   327,   327,   327,   327,   327,   327,   327,   239,   327,
     327,   273,   271,   242,     6,   293,     6,   327,     6,     6,
       6,     6,     6,     4,     6,     6,   344,   344,   327,   327,
     349,   243,   239,   243,   247,   297,   297,   327,   327,   243,
     247,   239,   243,   247,     6,     6,   340,   338,   338,   338,
     338,   338,   227,   338,     6,   243,   327,     6,     6,   341,
     243,   247,     8,   243,   239,   242,   327,   349,   348,   327,
     348,   327,   349,   352,   354,   349,   247,   239,   247,   243,
     315,   315,   341,   349,   327,     6,     4,   346,     6,   345,
     241,   341,   355,     6,   273,   273,   256,   327,   247,   247,
     243,   247,   257,   327,   327,     6,   327,   327,   239,   277,
     279,   242,   354,   243,   247,     7,     7,   243,   243,   243,
     243,   242,   243,     5,   340,   273,   273,   247,   247,   247,
     247,   247,   239,   241,   327,     6,   242,   243,   243,   242,
       6,     6,   242,   327,   243,   243,   243,   241,     6,   341,
       7,   242,   327,   243,   247,   247,   247,   247,   247,   247,
       6,   243,   171,   327,   327,   344,     6,     6,   239,   273,
     273,   288,   349,   243,   243,   243,     6,     6,     7,     6,
     244,     6,   243,     6,     6,   239,   247,   327,   327,   242,
     341,   243,   247,   239,   239,   247,   282,   286,   341,   273,
     327,   349,   358,     6,     6,     6,     6,   327,     6,     6,
     243,   327,   327,   327,   327,   327,   243,   340,   132,   133,
     138,   322,   132,   133,   322,   344,   297,   243,   247,     6,
     243,   341,   298,   243,     6,   344,   338,   338,   338,   338,
     338,   327,   243,   243,   243,   239,   242,     6,   345,   174,
     260,   327,   247,   247,   340,     6,   327,   327,   243,   243,
     278,     7,   238,   243,   242,   247,   247,   247,   247,   247,
     243,   242,   338,   341,     6,   242,   338,     6,   243,   243,
     327,     6,   128,   243,   309,   242,   243,   247,   247,   247,
     247,   247,     6,     6,     6,   298,     6,   242,   327,   327,
     243,   247,   282,   349,   239,   327,   327,   327,   327,   327,
     327,     6,   338,     6,   338,     6,     6,   243,   327,   312,
     298,     6,   344,   344,   344,   344,   338,   344,   315,   257,
     239,   247,     6,   242,   327,   243,   247,   247,   247,   247,
     247,   247,   247,   247,     6,   243,   243,   310,   243,   243,
     243,   243,   247,   243,   243,   243,   263,   327,   340,   243,
     327,   327,   327,   327,   327,   327,   338,   338,   312,     6,
       6,     6,     6,   344,     6,     6,     6,   242,   239,   243,
       6,   243,   273,   247,   247,   247,   247,   247,   247,   243,
     243,   261,   348,   266,   242,     6,   327,   327,   327,   327,
     327,   327,     6,   243,   247,   242,   340,   243,   243,   243,
     243,   243,   243,     6,   348,   264,   348,   243,     6,     6,
     243,   247,     6,     6,   348
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
#line 266 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 277 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 278 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 279 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 281 "Gmsh.y"
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
#line 299 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 300 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 301 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 302 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 303 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 304 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 305 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 306 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 307 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 308 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 310 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 311 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 312 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 319 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 323 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 330 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 335 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 340 "Gmsh.y"
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
#line 354 "Gmsh.y"
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
#line 367 "Gmsh.y"
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
#line 380 "Gmsh.y"
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
#line 408 "Gmsh.y"
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
#line 422 "Gmsh.y"
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
#line 435 "Gmsh.y"
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
#line 448 "Gmsh.y"
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
#line 466 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 480 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 482 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 487 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 489 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 494 "Gmsh.y"
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
#line 598 "Gmsh.y"
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
#line 608 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 617 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 624 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 634 "Gmsh.y"
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
#line 643 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 652 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 659 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 669 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 677 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 687 "Gmsh.y"
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
#line 706 "Gmsh.y"
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
#line 725 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 731 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 738 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 739 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 740 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 741 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 742 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 746 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 747 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 753 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 753 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 754 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 754 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 764 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 769 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 775 "Gmsh.y"
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
#line 837 "Gmsh.y"
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
#line 852 "Gmsh.y"
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
#line 881 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 891 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 896 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 904 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 909 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 917 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 926 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 931 "Gmsh.y"
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
#line 943 "Gmsh.y"
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
#line 960 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 966 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 975 "Gmsh.y"
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
#line 993 "Gmsh.y"
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
#line 1011 "Gmsh.y"
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
#line 1020 "Gmsh.y"
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
#line 1032 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1037 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
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

  case 100:
#line 1065 "Gmsh.y"
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
#line 1088 "Gmsh.y"
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
#line 1099 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1107 "Gmsh.y"
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
#line 1129 "Gmsh.y"
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
#line 1152 "Gmsh.y"
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
#line 1190 "Gmsh.y"
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
#line 1211 "Gmsh.y"
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
#line 1223 "Gmsh.y"
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
#line 1241 "Gmsh.y"
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
#line 1250 "Gmsh.y"
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
#line 1259 "Gmsh.y"
    { init_options(); ;}
    break;

  case 115:
#line 1261 "Gmsh.y"
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
#line 1279 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1281 "Gmsh.y"
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
#line 1297 "Gmsh.y"
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
#line 1306 "Gmsh.y"
    { init_options(); ;}
    break;

  case 120:
#line 1308 "Gmsh.y"
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
#line 1322 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 123:
#line 1330 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 124:
#line 1336 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 125:
#line 1341 "Gmsh.y"
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
#line 1383 "Gmsh.y"
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
#line 1395 "Gmsh.y"
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
#line 1408 "Gmsh.y"
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
#line 1423 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 136:
#line 1432 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        charOptions[key].push_back(v);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 141:
#line 1457 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 142:
#line 1465 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 143:
#line 1474 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 144:
#line 1482 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *s;
        List_Read((yyvsp[(2) - (2)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 145:
#line 1496 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *s;
        List_Read((yyvsp[(2) - (2)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 146:
#line 1514 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 147:
#line 1518 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 0, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 148:
#line 1525 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 149:
#line 1533 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 150:
#line 1537 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 1, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 151:
#line 1544 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 152:
#line 1552 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 153:
#line 1556 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 2, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 154:
#line 1563 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 155:
#line 1571 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 156:
#line 1575 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), 3, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 157:
#line 1582 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 158:
#line 1590 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 159:
#line 1594 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 160:
#line 1600 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 161:
#line 1604 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 162:
#line 1611 "Gmsh.y"
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

  case 163:
#line 1635 "Gmsh.y"
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

  case 164:
#line 1651 "Gmsh.y"
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

  case 165:
#line 1667 "Gmsh.y"
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

  case 166:
#line 1704 "Gmsh.y"
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

  case 167:
#line 1744 "Gmsh.y"
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

  case 168:
#line 1760 "Gmsh.y"
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

  case 169:
#line 1777 "Gmsh.y"
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

  case 170:
#line 1798 "Gmsh.y"
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

  case 171:
#line 1808 "Gmsh.y"
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

  case 172:
#line 1824 "Gmsh.y"
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

  case 173:
#line 1841 "Gmsh.y"
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

  case 174:
#line 1857 "Gmsh.y"
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

  case 175:
#line 1878 "Gmsh.y"
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

  case 176:
#line 1889 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 177:
#line 1895 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 178:
#line 1901 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1908 "Gmsh.y"
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

  case 180:
#line 1939 "Gmsh.y"
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

  case 181:
#line 1954 "Gmsh.y"
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

  case 182:
#line 1976 "Gmsh.y"
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

  case 183:
#line 1999 "Gmsh.y"
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

  case 184:
#line 2022 "Gmsh.y"
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

  case 185:
#line 2045 "Gmsh.y"
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

  case 186:
#line 2069 "Gmsh.y"
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

  case 187:
#line 2093 "Gmsh.y"
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

  case 188:
#line 2116 "Gmsh.y"
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

  case 189:
#line 2141 "Gmsh.y"
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

  case 190:
#line 2152 "Gmsh.y"
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

  case 191:
#line 2174 "Gmsh.y"
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

  case 192:
#line 2191 "Gmsh.y"
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

  case 193:
#line 2207 "Gmsh.y"
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

  case 194:
#line 2225 "Gmsh.y"
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

  case 195:
#line 2243 "Gmsh.y"
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

  case 196:
#line 2253 "Gmsh.y"
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

  case 197:
#line 2265 "Gmsh.y"
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

  case 198:
#line 2277 "Gmsh.y"
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

  case 199:
#line 2289 "Gmsh.y"
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

  case 200:
#line 2306 "Gmsh.y"
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

  case 201:
#line 2322 "Gmsh.y"
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

  case 202:
#line 2338 "Gmsh.y"
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

  case 203:
#line 2353 "Gmsh.y"
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

  case 204:
#line 2370 "Gmsh.y"
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

  case 205:
#line 2387 "Gmsh.y"
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

  case 206:
#line 2422 "Gmsh.y"
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

  case 207:
#line 2444 "Gmsh.y"
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

  case 208:
#line 2467 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 209:
#line 2468 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 210:
#line 2473 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 211:
#line 2477 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 212:
#line 2481 "Gmsh.y"
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

  case 213:
#line 2492 "Gmsh.y"
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

  case 214:
#line 2503 "Gmsh.y"
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

  case 215:
#line 2514 "Gmsh.y"
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

  case 216:
#line 2530 "Gmsh.y"
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

  case 217:
#line 2549 "Gmsh.y"
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

  case 218:
#line 2571 "Gmsh.y"
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

  case 219:
#line 2586 "Gmsh.y"
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

  case 220:
#line 2601 "Gmsh.y"
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

  case 221:
#line 2620 "Gmsh.y"
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

  case 222:
#line 2671 "Gmsh.y"
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

  case 223:
#line 2692 "Gmsh.y"
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

  case 224:
#line 2714 "Gmsh.y"
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

  case 225:
#line 2736 "Gmsh.y"
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

  case 226:
#line 2841 "Gmsh.y"
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

  case 227:
#line 2857 "Gmsh.y"
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

  case 228:
#line 2892 "Gmsh.y"
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

  case 229:
#line 2903 "Gmsh.y"
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

  case 230:
#line 2914 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 231:
#line 2920 "Gmsh.y"
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

  case 232:
#line 2935 "Gmsh.y"
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

  case 233:
#line 2963 "Gmsh.y"
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

  case 234:
#line 2975 "Gmsh.y"
    {
      nameSpaces.clear();
    ;}
    break;

  case 235:
#line 2984 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 236:
#line 2991 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 237:
#line 3003 "Gmsh.y"
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

  case 238:
#line 3022 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 239:
#line 3028 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 240:
#line 3034 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 241:
#line 3041 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3048 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 243:
#line 3055 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3067 "Gmsh.y"
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

  case 245:
#line 3140 "Gmsh.y"
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

  case 246:
#line 3158 "Gmsh.y"
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

  case 247:
#line 3175 "Gmsh.y"
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

  case 248:
#line 3190 "Gmsh.y"
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

  case 249:
#line 3223 "Gmsh.y"
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

  case 250:
#line 3235 "Gmsh.y"
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

  case 251:
#line 3259 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 252:
#line 3263 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 253:
#line 3268 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 254:
#line 3275 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 255:
#line 3280 "Gmsh.y"
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

  case 256:
#line 3290 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 257:
#line 3295 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 258:
#line 3301 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 259:
#line 3309 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 260:
#line 3313 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 261:
#line 3317 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 262:
#line 3327 "Gmsh.y"
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

  case 263:
#line 3390 "Gmsh.y"
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

  case 264:
#line 3406 "Gmsh.y"
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

  case 265:
#line 3423 "Gmsh.y"
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

  case 266:
#line 3440 "Gmsh.y"
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

  case 267:
#line 3462 "Gmsh.y"
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

  case 268:
#line 3484 "Gmsh.y"
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

  case 269:
#line 3519 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 270:
#line 3527 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 271:
#line 3535 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 272:
#line 3541 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 273:
#line 3548 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 274:
#line 3555 "Gmsh.y"
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

  case 275:
#line 3575 "Gmsh.y"
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

  case 276:
#line 3601 "Gmsh.y"
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

  case 277:
#line 3613 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 278:
#line 3625 "Gmsh.y"
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

  case 279:
#line 3643 "Gmsh.y"
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

  case 280:
#line 3661 "Gmsh.y"
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

  case 281:
#line 3679 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3685 "Gmsh.y"
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

  case 283:
#line 3703 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3709 "Gmsh.y"
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

  case 285:
#line 3729 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3735 "Gmsh.y"
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

  case 287:
#line 3753 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 288:
#line 3759 "Gmsh.y"
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

  case 289:
#line 3776 "Gmsh.y"
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

  case 290:
#line 3792 "Gmsh.y"
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

  case 291:
#line 3809 "Gmsh.y"
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

  case 292:
#line 3826 "Gmsh.y"
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

  case 293:
#line 3849 "Gmsh.y"
    {
    ;}
    break;

  case 294:
#line 3852 "Gmsh.y"
    {
    ;}
    break;

  case 295:
#line 3858 "Gmsh.y"
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

  case 296:
#line 3870 "Gmsh.y"
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

  case 297:
#line 3890 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 298:
#line 3894 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 299:
#line 3898 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 300:
#line 3902 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 301:
#line 3906 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3910 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 303:
#line 3914 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 304:
#line 3918 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 305:
#line 3927 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 306:
#line 3939 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 307:
#line 3940 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 308:
#line 3941 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 309:
#line 3942 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 310:
#line 3943 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 311:
#line 3947 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 312:
#line 3948 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 313:
#line 3949 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 314:
#line 3950 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 315:
#line 3951 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 316:
#line 3956 "Gmsh.y"
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

  case 317:
#line 3978 "Gmsh.y"
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

  case 318:
#line 3998 "Gmsh.y"
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

  case 319:
#line 4018 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 320:
#line 4022 "Gmsh.y"
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

  case 321:
#line 4037 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 322:
#line 4041 "Gmsh.y"
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

  case 323:
#line 4057 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 324:
#line 4061 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 325:
#line 4066 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 326:
#line 4070 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 327:
#line 4076 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 328:
#line 4080 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 329:
#line 4087 "Gmsh.y"
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

  case 330:
#line 4104 "Gmsh.y"
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

  case 331:
#line 4145 "Gmsh.y"
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

  case 332:
#line 4189 "Gmsh.y"
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

  case 333:
#line 4228 "Gmsh.y"
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

  case 334:
#line 4253 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 335:
#line 4262 "Gmsh.y"
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

  case 336:
#line 4292 "Gmsh.y"
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

  case 337:
#line 4318 "Gmsh.y"
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

  case 338:
#line 4345 "Gmsh.y"
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

  case 339:
#line 4377 "Gmsh.y"
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

  case 340:
#line 4404 "Gmsh.y"
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

  case 341:
#line 4430 "Gmsh.y"
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

  case 342:
#line 4456 "Gmsh.y"
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

  case 343:
#line 4482 "Gmsh.y"
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

  case 344:
#line 4508 "Gmsh.y"
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

  case 345:
#line 4529 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 346:
#line 4535 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 347:
#line 4541 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 348:
#line 4547 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 349:
#line 4553 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 350:
#line 4559 "Gmsh.y"
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

  case 351:
#line 4585 "Gmsh.y"
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

  case 352:
#line 4611 "Gmsh.y"
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

  case 353:
#line 4628 "Gmsh.y"
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

  case 354:
#line 4645 "Gmsh.y"
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

  case 355:
#line 4662 "Gmsh.y"
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

  case 356:
#line 4674 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 357:
#line 4680 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 358:
#line 4686 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 359:
#line 4698 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 360:
#line 4702 "Gmsh.y"
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

  case 361:
#line 4712 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 362:
#line 4722 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 363:
#line 4723 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 364:
#line 4724 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 365:
#line 4729 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 366:
#line 4735 "Gmsh.y"
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

  case 367:
#line 4747 "Gmsh.y"
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

  case 368:
#line 4765 "Gmsh.y"
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

  case 369:
#line 4792 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 370:
#line 4793 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 371:
#line 4794 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 372:
#line 4795 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 373:
#line 4796 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 374:
#line 4797 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 375:
#line 4798 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 376:
#line 4799 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 377:
#line 4801 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 378:
#line 4807 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 379:
#line 4808 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 380:
#line 4809 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 381:
#line 4810 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 382:
#line 4811 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 4812 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 384:
#line 4813 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 385:
#line 4814 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 386:
#line 4815 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 387:
#line 4816 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 388:
#line 4817 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 4818 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 4819 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 391:
#line 4820 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 392:
#line 4821 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 393:
#line 4822 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 394:
#line 4823 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 395:
#line 4824 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 396:
#line 4825 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 397:
#line 4826 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 398:
#line 4827 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4828 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4829 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4830 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 4831 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4832 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 404:
#line 4833 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4834 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 4835 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 4836 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 4837 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 409:
#line 4838 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 410:
#line 4839 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 4840 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 412:
#line 4841 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 413:
#line 4842 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 414:
#line 4843 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 415:
#line 4844 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 416:
#line 4853 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 417:
#line 4854 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 418:
#line 4855 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 419:
#line 4856 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 420:
#line 4857 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 421:
#line 4858 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 422:
#line 4859 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 423:
#line 4860 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 424:
#line 4861 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 425:
#line 4862 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 426:
#line 4863 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 427:
#line 4868 "Gmsh.y"
    { init_options(); ;}
    break;

  case 428:
#line 4870 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 429:
#line 4876 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 430:
#line 4878 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 431:
#line 4883 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 4888 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 433:
#line 4893 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 434:
#line 4898 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 435:
#line 4902 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 436:
#line 4906 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 437:
#line 4910 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 438:
#line 4914 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 439:
#line 4918 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 440:
#line 4924 "Gmsh.y"
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

  case 441:
#line 4940 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 442:
#line 4945 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 443:
#line 4951 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)nameSpaces[struct_namespace].size();
    ;}
    break;

  case 444:
#line 4957 "Gmsh.y"
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

  case 445:
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

  case 446:
#line 4997 "Gmsh.y"
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

  case 447:
#line 5030 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 448:
#line 5034 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 449:
#line 5039 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 450:
#line 5043 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 451:
#line 5047 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 452:
#line 5051 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 453:
#line 5056 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 454:
#line 5061 "Gmsh.y"
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

  case 455:
#line 5071 "Gmsh.y"
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

  case 456:
#line 5081 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 457:
#line 5086 "Gmsh.y"
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

  case 458:
#line 5097 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 459:
#line 5106 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 460:
#line 5111 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 461:
#line 5116 "Gmsh.y"
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

  case 462:
#line 5143 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 463:
#line 5145 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 464:
#line 5150 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 465:
#line 5152 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 466:
#line 5157 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (nameSpaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 467:
#line 5164 "Gmsh.y"
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

  case 468:
#line 5180 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 469:
#line 5182 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 470:
#line 5187 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 471:
#line 5196 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 472:
#line 5198 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 473:
#line 5203 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 474:
#line 5205 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 475:
#line 5211 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 476:
#line 5215 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 477:
#line 5219 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 478:
#line 5223 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 479:
#line 5227 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 480:
#line 5234 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 481:
#line 5238 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 482:
#line 5242 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 483:
#line 5246 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 484:
#line 5253 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 485:
#line 5258 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 486:
#line 5265 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 487:
#line 5270 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 488:
#line 5274 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 489:
#line 5279 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 490:
#line 5283 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 491:
#line 5291 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 492:
#line 5302 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 493:
#line 5306 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 494:
#line 5318 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 495:
#line 5326 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 496:
#line 5334 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 497:
#line 5341 "Gmsh.y"
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

  case 498:
#line 5351 "Gmsh.y"
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

  case 499:
#line 5374 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 500:
#line 5380 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 501:
#line 5386 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 502:
#line 5392 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 503:
#line 5398 "Gmsh.y"
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

  case 504:
#line 5409 "Gmsh.y"
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

  case 505:
#line 5420 "Gmsh.y"
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

  case 506:
#line 5431 "Gmsh.y"
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

  case 507:
#line 5443 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 508:
#line 5449 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 509:
#line 5455 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 510:
#line 5461 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 511:
#line 5466 "Gmsh.y"
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

  case 512:
#line 5476 "Gmsh.y"
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

  case 513:
#line 5486 "Gmsh.y"
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

  case 514:
#line 5496 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(double));
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

  case 515:
#line 5509 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 516:
#line 5513 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 517:
#line 5519 "Gmsh.y"
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

  case 518:
#line 5531 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 519:
#line 5535 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 520:
#line 5539 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 521:
#line 5543 "Gmsh.y"
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

  case 522:
#line 5561 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 523:
#line 5569 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 524:
#line 5577 "Gmsh.y"
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

  case 525:
#line 5606 "Gmsh.y"
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

  case 526:
#line 5616 "Gmsh.y"
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

  case 527:
#line 5632 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 528:
#line 5643 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 529:
#line 5648 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 530:
#line 5652 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 531:
#line 5656 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 532:
#line 5668 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 533:
#line 5672 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 534:
#line 5684 "Gmsh.y"
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

  case 535:
#line 5701 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 536:
#line 5711 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 537:
#line 5715 "Gmsh.y"
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

  case 538:
#line 5730 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 539:
#line 5735 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 540:
#line 5742 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 541:
#line 5746 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 542:
#line 5751 "Gmsh.y"
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

  case 543:
#line 5765 "Gmsh.y"
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

  case 544:
#line 5782 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 545:
#line 5786 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 546:
#line 5791 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 547:
#line 5795 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 548:
#line 5800 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 549:
#line 5808 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 550:
#line 5814 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 551:
#line 5820 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 552:
#line 5826 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 553:
#line 5835 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 554:
#line 5839 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 555:
#line 5843 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 556:
#line 5851 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 557:
#line 5857 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 558:
#line 5863 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 559:
#line 5867 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 560:
#line 5875 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 561:
#line 5883 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 562:
#line 5890 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 563:
#line 5900 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 564:
#line 5905 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 565:
#line 5910 "Gmsh.y"
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

  case 566:
#line 5925 "Gmsh.y"
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

  case 567:
#line 5939 "Gmsh.y"
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

  case 568:
#line 5953 "Gmsh.y"
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

  case 569:
#line 5965 "Gmsh.y"
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

  case 570:
#line 5981 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 571:
#line 5990 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 572:
#line 5999 "Gmsh.y"
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

  case 573:
#line 6009 "Gmsh.y"
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

  case 574:
#line 6020 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 575:
#line 6028 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 576:
#line 6036 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 577:
#line 6040 "Gmsh.y"
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

  case 578:
#line 6059 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 579:
#line 6066 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 580:
#line 6072 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 581:
#line 6079 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 582:
#line 6086 "Gmsh.y"
    { init_options(); ;}
    break;

  case 583:
#line 6088 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 584:
#line 6096 "Gmsh.y"
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

  case 585:
#line 6120 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 586:
#line 6122 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 587:
#line 6128 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 588:
#line 6133 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 589:
#line 6135 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 590:
#line 6140 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 591:
#line 6145 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 592:
#line 6150 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 593:
#line 6152 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 594:
#line 6156 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 595:
#line 6168 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add((yyval.l), &val_);
        }
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 596:
#line 6183 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 597:
#line 6188 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 598:
#line 6197 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 599:
#line 6206 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 600:
#line 6215 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 601:
#line 6227 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 602:
#line 6230 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 603:
#line 6234 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13848 "Gmsh.tab.cpp"
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


#line 6237 "Gmsh.y"


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
      std::string s = it->first + "[] = Str({";
      for(unsigned int i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += "});";
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
          out = s.value[index];
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
    if (type_var == 1) {
      std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
      if(nameSpaces.getTag(struct_namespace, struct_name, out)) {
        out = val_default;
        if (type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
      }
    }
    else {
      out = val_default;
      if (type_treat == 0) yymsg(0, "Unknown variable '%s(.)'", c2);
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

List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = NULL;
  const std::vector<double> * out_vector; double val_;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (nameSpaces.getMember_Vector
          (struct_namespace, struct_name, key_member, out_vector)) {
  case 0:
    out = List_Create(out_vector->size(), 1, sizeof(double));
    for(int i = 0; i < out_vector->size(); i++) {
      val_ = out_vector->at(i);
      List_Add(out, &val_);
    }
    break;
  case 1:
    yymsg(0, "Unknown Struct: %s", struct_name.c_str());
    out = val_default;
    break;
  case 2:
    out = val_default;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
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

List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = NULL;
  const std::vector<std::string> * out_vector; char * val_;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (nameSpaces.getMember_Vector
          (struct_namespace, struct_name, key_member, out_vector)) {
  case 0:
    out = List_Create(out_vector->size(), 1, sizeof(char *));
    for(int i = 0; i < out_vector->size(); i++) {
      val_ = strsave((char*)out_vector->at(i).c_str());
      List_Add(out, &val_);
    }
    break;
  case 1:
    yymsg(0, "Unknown Struct: %s", struct_name.c_str());
    out = val_default;
    break;
  case 2:
    out = val_default;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}

